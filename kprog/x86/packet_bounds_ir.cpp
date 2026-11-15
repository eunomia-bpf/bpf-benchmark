// Express the simulator's existing packet length predicates as pointer bounds
// for the stock BPF backend/verifier. This changes no application predicate.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/Analysis/InstructionSimplify.h"
#include "llvm/Analysis/ConstantFolding.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <linux/bpf.h>
#include <cstddef>
using namespace llvm;
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static bool tied_identity(CallInst *call,InlineAsm *assembly) {
  return assembly->getAsmString().empty() && assembly->getConstraintString()=="=r,0" &&
      call->arg_size()==1 && call->getType()==call->getArgOperand(0)->getType();
}
// A tied empty asm with an integer constant emits no operation and returns
// exactly those bits. Propagate newly exposed integer constants through pure
// constant expressions to their next identity, so chains reach a fixed point.
// Live operands, pointer identities, clobbers and real assembly stay opaque.
static unsigned fold_constant_identities(Module &module) {
  SmallSetVector<Instruction *,32> pending;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    if (instruction.getType()->isIntegerTy()) pending.insert(&instruction);
  }
  unsigned identities=0;
  while (!pending.empty()) {
    auto *instruction=pending.pop_back_val();
    ConstantInt *constant=nullptr;
    if (auto *call=dyn_cast<CallInst>(instruction)) {
      auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
      if (assembly && tied_identity(call,assembly) && !assembly->isAlignStack() &&
          !assembly->canThrow())
        constant=dyn_cast<ConstantInt>(call->getArgOperand(0));
      if (constant) ++identities;
    } else if (isa<BinaryOperator,CastInst,CmpInst,SelectInst,PHINode>(instruction)) {
      constant=dyn_cast_or_null<ConstantInt>(
          ConstantFoldInstruction(instruction,module.getDataLayout()));
    }
    if (!constant) continue;
    for (auto *user:instruction->users())
      if (auto *next=dyn_cast<Instruction>(user))
        if (next!=instruction && next->getType()->isIntegerTy()) pending.insert(next);
    instruction->replaceAllUsesWith(constant);instruction->eraseFromParent();
  }
  return identities;
}
static Value *origin(Value *value) {
  while (true) {
    if (auto *extension=dyn_cast<ZExtInst>(value)) { value=extension->getOperand(0); continue; }
    if (auto *call=dyn_cast<CallInst>(value))
      if (auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand()))
        if (tied_identity(call,assembly)) {
          value=call->getArgOperand(0); continue;
        }
    return value;
  }
}
static bool field(Value *value,Function &function,int64_t offset) {
  auto *load=dyn_cast<LoadInst>(origin(value));
  if (!load || !load->getType()->isIntegerTy(32)) return false;
  int64_t actual=0;
  auto *base=GetPointerBaseWithConstantOffset(load->getPointerOperand(),actual,function.getParent()->getDataLayout());
  return base==function.getArg(0) && actual==offset;
}
static Value *context_origin(Value *value) {
  while (auto *call=dyn_cast<CallInst>(value)) {
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (!assembly || !tied_identity(call,assembly)) break;
    value=call->getArgOperand(0);
  }
  return value;
}
// Tracing contexts contain scalar register values. Keep the original context
// operand and put a proven constant displacement in the memory instruction.
// An opaque identity used by the simulator can otherwise make LLVM allocate
// ctx+K as a separate pointer, which the stock verifier treats differently.
static unsigned canonical_context_loads(Module &module) {
  unsigned count=0;
  for (auto &function:module) {
    if (function.isDeclaration() || function.arg_empty() ||
        !function.getArg(0)->getType()->isPointerTy()) continue;
    auto section=function.getSection();
    if (section!="kprobe" && !section.starts_with("kprobe/")) continue;
    SmallVector<LoadInst *,16> loads;
    for (auto &instruction:instructions(function))
      if (auto *load=dyn_cast<LoadInst>(&instruction)) loads.push_back(load);
    for (auto *load:loads) {
      if (load->isAtomic() || !load->getType()->isIntegerTy()) continue;
      unsigned width=load->getType()->getIntegerBitWidth();
      if (width!=8 && width!=16 && width!=32 && width!=64) continue;
      int64_t offset=0;
      auto *base=GetPointerBaseWithConstantOffset(context_origin(load->getPointerOperand()),
          offset,module.getDataLayout());
      if (context_origin(base)!=function.getArg(0) || offset < -32768 || offset > 32767) continue;
      std::string displacement=offset<0?" - "+std::to_string(-offset):" + "+std::to_string(offset);
      std::string assembly="$0 = *(u"+std::to_string(width)+" *)($1"+displacement+")";
      auto *wide=Type::getInt64Ty(module.getContext());
      auto *signature=FunctionType::get(wide,{function.getArg(0)->getType()},false);
      auto *operation=InlineAsm::get(signature,assembly,"=r,r,~{memory}",load->isVolatile());
      IRBuilder<> builder(load);builder.SetCurrentDebugLocation(load->getDebugLoc());
      Value *result=builder.CreateCall(operation,{function.getArg(0)},"ctx_load");
      if (width!=64) result=builder.CreateTrunc(result,load->getType());
      load->replaceAllUsesWith(result);load->eraseFromParent();++count;
    }
  }
  return count;
}
// Private unknown choices have no observable read effect. Dropping an unused
// choice projects the same possible observable states; live reads stay distinct.
static unsigned remove_unused_private_inputs(Module &module) {
  SmallVector<LoadInst *,16> unused;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *load=dyn_cast<LoadInst>(&instruction);
    if (!load || !load->use_empty() || !load->isVolatile() || load->isAtomic() ||
        !load->getType()->isIntegerTy(64)) continue;
    int64_t offset=0;
    auto *base=GetPointerBaseWithConstantOffset(load->getPointerOperand(),offset,module.getDataLayout());
    auto *global=dyn_cast<GlobalVariable>(base);
    if (offset==0 && global && global->isDeclaration() &&
        global->getName()=="kprog_unspecified_input" && global->getSection()==".ksyms")
      unused.push_back(load);
  }
  for (auto *load:unused) load->eraseFromParent();
  return unused.size();
}
// Variable-location intrinsics have no execution effect. Constant folding of a
// large simulated block can leave millions of adjacent dbg.value instructions;
// LLVM18's getStableDebugLoc scans to the next non-debug instruction for each.
// Keep instruction locations, function/type/global metadata and BTF, but omit
// these variable updates before B machine-code selection. The checked native
// compiler still receives the unchanged original frontend IR.
static unsigned remove_debug_variable_intrinsics(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &block:function)
    for (auto it=block.begin();it!=block.end();) {
      auto &instruction=*it++;
      if (isa<DbgVariableIntrinsic>(instruction)) {
        instruction.eraseFromParent();++count;
      }
    }
  return count;
}
// A PHI incoming value is observed on its own edge. For example, a preserved
// sign flag on a pointer==NULL edge is exactly zero. Fold that expression at
// the PHI so the BPF backend can discard arithmetic on the nullable pointer.
// Other edges retain their original expression and the comparison stays live.
static unsigned fold_equality_edges(Module &module) {
  unsigned count=0;
  const SimplifyQuery query(module.getDataLayout());
  for (auto &function:module) for (auto &block:function) for (auto &phi:block.phis()) {
    for (unsigned index=0;index<phi.getNumIncomingValues();++index) {
      auto *branch=dyn_cast<BranchInst>(phi.getIncomingBlock(index)->getTerminator());
      if (!branch || !branch->isConditional() ||
          branch->getSuccessor(0)==branch->getSuccessor(1)) continue;
      auto *compare=dyn_cast<ICmpInst>(branch->getCondition());
      if (!compare || !compare->isEquality()) continue;
      unsigned edge=compare->getPredicate()==ICmpInst::ICMP_EQ?0:1;
      if (branch->getSuccessor(edge)!=&block) continue;
      Value *value=compare->getOperand(0),*constant=compare->getOperand(1);
      if (isa<Constant>(value)) std::swap(value,constant);
      if (!isa<ConstantInt>(constant) && !isa<ConstantPointerNull>(constant)) continue;
      auto *incoming=phi.getIncomingValue(index);
      auto *folded=simplifyWithOpReplaced(incoming,value,constant,query,false);
      if (folded && isa<Constant>(folded) && folded!=incoming) {
        phi.setIncomingValue(index,folded);++count;
      }
    }
  }
  return count;
}
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext context;SMDiagnostic error;auto module=parseIRFile(Input,error,context);
  if (!module) { error.print(argv[0],errs());return 1; }
  unsigned constants=fold_constant_identities(*module);
  unsigned unused=remove_unused_private_inputs(*module);
  unsigned contexts=canonical_context_loads(*module);
  unsigned debug_variables=remove_debug_variable_intrinsics(*module);
  unsigned equality_edges=fold_equality_edges(*module);
  unsigned count=0;
  for (auto &function:*module) {
    if (function.isDeclaration() || function.arg_empty()) continue;
    auto section=function.getSection();int64_t data,end;
    if (section=="xdp" || section.starts_with("xdp/")) {
      data=offsetof(xdp_md,data);end=offsetof(xdp_md,data_end);
    } else if (section=="tc" || section.starts_with("tc/") || section.starts_with("cgroup_skb/")) {
      data=offsetof(__sk_buff,data);end=offsetof(__sk_buff,data_end);
    } else continue;
    SmallVector<ICmpInst *,8> comparisons;
    for (auto &instruction:instructions(function)) if (auto *compare=dyn_cast<ICmpInst>(&instruction)) comparisons.push_back(compare);
    for (auto *compare:comparisons) {
      auto *difference=dyn_cast<BinaryOperator>(compare->getOperand(0));
      auto *constant=dyn_cast<ConstantInt>(compare->getOperand(1));
      if (!difference || difference->getOpcode()!=Instruction::Sub || !constant || !constant->getType()->isIntegerTy(64) ||
          !field(difference->getOperand(0),function,end) || !field(difference->getOperand(1),function,data)) continue;
      auto predicate=compare->getPredicate();auto size=constant->getValue();
      bool signed_compare=ICmpInst::isSigned(predicate);
      if (signed_compare && size.isNegative()) continue;
      bool inverse=predicate==ICmpInst::ICMP_SGE || predicate==ICmpInst::ICMP_UGE || predicate==ICmpInst::ICMP_SGT || predicate==ICmpInst::ICMP_UGT;
      bool inclusive=predicate==ICmpInst::ICMP_SLE || predicate==ICmpInst::ICMP_ULE || predicate==ICmpInst::ICMP_SGT || predicate==ICmpInst::ICMP_UGT;
      if (!inverse && !inclusive && predicate!=ICmpInst::ICMP_SLT && predicate!=ICmpInst::ICMP_ULT) continue;
      if (inclusive) { if (size.isMaxValue()) continue; ++size; }
      IRBuilder<> builder(compare);builder.SetCurrentDebugLocation(compare->getDebugLoc());
      auto *start=difference->getOperand(1),*finish=difference->getOperand(0);
      auto *bound=builder.CreateAdd(start,ConstantInt::get(context,size),"packet_bound");
      // The original scalar predicate retains wrap/overflow behavior. On an
      // ordered packet span <=PTRDIFF_MAX, accepting it already implies
      // start+K<=end. Express that same fact in the verifier's pointer form;
      // no numeric comparison of a packet pointer against ULONG_MAX is needed.
      auto *original=builder.CreateICmp(predicate,difference,constant);
      auto *original_reject=inverse?builder.CreateNot(original):original;
      auto *reject=builder.CreateOr(original_reject,builder.CreateICmpUGT(bound,finish));
      compare->replaceAllUsesWith(inverse?builder.CreateNot(reject):reject);
      compare->eraseFromParent();++count;
    }
  }
  if (verifyModule(*module,&errs())) return 1;
  std::error_code ec;ToolOutputFile output(Output,ec,sys::fs::OF_None);
  if (ec) { errs()<<ec.message()<<'\n';return 1; }
  WriteBitcodeToFile(*module,output.os());output.keep();output.os().flush();
  if (output.os().has_error()) { errs()<<"write packet bounds IR failed\n";return 1; }
  errs()<<"packet length predicates lowered="<<count<<'\n';
  errs()<<"unused private inputs removed="<<unused<<'\n';
  errs()<<"constant context loads canonicalized="<<contexts<<'\n';
  errs()<<"debug variable intrinsics removed="<<debug_variables<<'\n';
  errs()<<"equality-edge PHI expressions folded="<<equality_edges<<'\n';
  errs()<<"tied integer constant identities folded="<<constants<<'\n';
}
