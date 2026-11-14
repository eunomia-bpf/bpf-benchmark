// Express the simulator's existing packet length predicates as pointer bounds
// for the stock BPF backend/verifier. This changes no application predicate.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/InlineAsm.h"
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
static Value *origin(Value *value) {
  while (true) {
    if (auto *extension=dyn_cast<ZExtInst>(value)) { value=extension->getOperand(0); continue; }
    if (auto *call=dyn_cast<CallInst>(value))
      if (auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand()))
        if (assembly->getAsmString().empty() && call->arg_size()==1 && call->getType()==call->getArgOperand(0)->getType()) {
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
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext context;SMDiagnostic error;auto module=parseIRFile(Input,error,context);
  if (!module) { error.print(argv[0],errs());return 1; }
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
}
