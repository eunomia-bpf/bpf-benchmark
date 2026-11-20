// Translate the checked simulator's BPF-target IR to the native compiler IR.
// The source and its map/helper identities remain service-owned throughout.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Regex.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <linux/bpf.h>
#include <cstdlib>
#include <map>
#include <set>
using namespace llvm;
[[noreturn]] static void fail(const Twine &s) { errs()<<s<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static cl::list<std::string> ArrayMaps("array-map");
static cl::opt<std::string> HelperList("helper-list");
#define HELPER_NAME(name) "bpf_" #name
static const char *HelperNames[] = {__BPF_FUNC_MAPPER(HELPER_NAME)};
#undef HELPER_NAME

// Simulator byte-lane asm is straight-line BPF register code. Translate its
// loads/stores/combines together, preserving every lane and temporary output.
static Value *memoryAsm(CallInst *call, StringRef text, IRBuilder<> &b) {
  auto integer=[](StringRef s) { unsigned v; if (s.getAsInteger(10,v)) fail("invalid simulator asm operand"); return v; };
  auto *aggregate=dyn_cast<StructType>(call->getType());
  unsigned outputs=aggregate?aggregate->getNumElements():(call->getType()->isVoidTy()?0:1);
  std::map<unsigned,Value *> regs;
  for (unsigned i=0;i<call->arg_size();++i) regs.emplace(outputs+i,call->getArgOperand(i));
  auto read=[&](StringRef token) -> Value * {
    if (!token.consume_front("$")) return b.getInt64(integer(token));
    auto value=regs.find(integer(token));
    if (value==regs.end()) fail("simulator asm reads an undefined register");
    return value->second;
  };
  auto bits=[&](Value *v) -> Value * { return v->getType()->isPointerTy()?b.CreatePtrToInt(v,b.getInt64Ty()):b.CreateZExtOrTrunc(v,b.getInt64Ty()); };
  // Keep the base in a register. A simulator register read that is not
  // present yields a constant null pointer, and the backend folds
  // `gep i8, ptr null, i64 112` into the absolute operand `mov 0x70,%rsi`,
  // which native-link refuses (no base, no index, no RIP): guest displacement
  // is not a host address. Semantics are unchanged, the load still addresses
  // base+displacement, and a base already in a register keeps that register.
  auto stable=[&](Value *v) -> Value * {
    // The public entry context is already a runtime pointer argument. Keep
    // its root visible so context-lower can translate its offsets and widths.
    // Synthetic constant-null register bases still need the barrier below.
    if (auto *arg=dyn_cast<Argument>(v); arg && arg->getType()->isPointerTy() &&
        arg->getArgNo()==0 && arg->getParent()->hasSection() &&
        !arg->getParent()->hasLocalLinkage()) return v;
    auto *type=FunctionType::get(b.getInt64Ty(),{b.getInt64Ty()},false);
    auto *base=b.CreateCall(InlineAsm::get(type,"","=r,0",true),{bits(v)});
    return b.CreateIntToPtr(base,b.getPtrTy());
  };
  auto address=[&](StringRef base,StringRef sign,StringRef displacement) {
    auto *pointer=stable(read(base));
    auto *offset=bits(read(displacement)); if (sign=="-") offset=b.CreateNeg(offset);
    return b.CreateGEP(b.getInt8Ty(),pointer,offset);
  };
  Regex load("^(\\$[0-9]+) = \\*\\(u(8|16|32|64) \\*\\)\\((\\$[0-9]+) ([+-]) (\\$[0-9]+|[0-9]+)\\)$");
  Regex store("^\\*\\(u(8|16|32|64) \\*\\)\\((\\$[0-9]+) ([+-]) (\\$[0-9]+|[0-9]+)\\) = (\\$[0-9]+)$");
  Regex move("^(\\$[0-9]+) = (\\$[0-9]+)$");
  Regex combine("^(\\$[0-9]+) (<<=|>>=|\\$?\\|=) (\\$[0-9]+|[0-9]+)$");
  SmallVector<StringRef,16> lines; text.split(lines,'\n',-1,false);
  for (auto line:lines) {
    SmallVector<StringRef,8> match;
    if (load.match(line,&match)) {
      auto *value=b.CreateAlignedLoad(b.getIntNTy(integer(match[2])),address(match[3],match[4],match[5]),Align(1));
      value->setVolatile(true); regs[integer(match[1].drop_front())]=bits(value);
    } else if (store.match(line,&match)) {
      auto *value=b.CreateTruncOrBitCast(bits(read(match[5])),b.getIntNTy(integer(match[1])));
      b.CreateAlignedStore(value,address(match[2],match[3],match[4]),Align(1))->setVolatile(true);
    } else if (move.match(line,&match)) regs[integer(match[1].drop_front())]=read(match[2]);
    else if (combine.match(line,&match)) {
      auto *left=bits(read(match[1])), *right=bits(read(match[3]));
      regs[integer(match[1].drop_front())]=match[2]=="<<="?b.CreateShl(left,right):match[2]==">>="?b.CreateLShr(left,right):b.CreateOr(left,right);
    } else fail("untranslated simulator BPF assembly: "+line);
  }
  auto output=[&](unsigned index,Type *type) -> Value * {
    auto value=regs.find(index); if (value==regs.end()) fail("simulator asm output is undefined");
    if (type->isPointerTy()) return value->second->getType()->isPointerTy()?value->second:b.CreateIntToPtr(bits(value->second),type);
    return b.CreateZExtOrTrunc(bits(value->second),type);
  };
  if (!outputs) return nullptr;
  if (!aggregate) return output(0,call->getType());
  Value *result=PoisonValue::get(aggregate);
  for (unsigned i=0;i<outputs;++i) result=b.CreateInsertValue(result,output(i,aggregate->getElementType(i)),i);
  return result;
}

// The same private arena has ordinary Mem semantics in the checked B pass
// (packet_bounds_ir.cpp). Context/global/atomic accesses retain volatility.
static unsigned normalizePrivateStack(Module &module) {
  unsigned count=0;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *load=dyn_cast<LoadInst>(&instruction);
    auto *store=dyn_cast<StoreInst>(&instruction);
    Value *pointer=nullptr;
    if (load && load->isVolatile() && !load->isAtomic()) pointer=load->getPointerOperand();
    if (store && store->isVolatile() && !store->isAtomic()) pointer=store->getPointerOperand();
    if (!pointer) continue;
    SmallVector<const Value *,4> objects;
    getUnderlyingObjects(pointer,objects);
    if (objects.empty()) continue;
    bool privateStack=true;
    for (auto *object:objects) {
      auto *local=dyn_cast<AllocaInst>(object);
      auto *type=local?dyn_cast<StructType>(local->getAllocatedType()):nullptr;
      if (!type || type->getName()!="union.x86_sim_stack_mem") {
        privateStack=false;break;
      }
    }
    if (!privateStack) continue;
    if (load) load->setVolatile(false);else store->setVolatile(false);
    ++count;
  }
  return count;
}

// A private unknown choice of the simulator (kprog_unspecified_input) is any
// value: B reads it from a map, so the verifier checks every value. The native
// code may take any one of them, so each read becomes a frozen undefined value:
// an unused read leaves no code and a used one leaves no memory access.
static unsigned freezeUnspecifiedInputs(Module &module) {
  SmallVector<LoadInst *,64> loads;
  for (auto &function:module) for (auto &instruction:instructions(function)) {
    auto *load=dyn_cast<LoadInst>(&instruction);
    if (!load || !load->isVolatile() || load->isAtomic() || !load->getType()->isIntegerTy(64)) continue;
    int64_t offset=0;
    auto *base=GetPointerBaseWithConstantOffset(load->getPointerOperand(),offset,module.getDataLayout());
    auto *global=dyn_cast<GlobalVariable>(base);
    if (offset==0 && global && global->isDeclaration() &&
        global->getName()=="kprog_unspecified_input" && global->getSection()==".ksyms")
      loads.push_back(load);
  }
  for (auto *load:loads) {
    IRBuilder<> b(load);
    load->replaceAllUsesWith(b.CreateFreeze(PoisonValue::get(load->getType()),"unspecified"));
    load->eraseFromParent();
  }
  return loads.size();
}

int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext c; SMDiagnostic error; auto m=parseIRFile(Input,error,c);
  if (!m) { error.print(argv[0],errs()); return 1; }
  // BPF frontend DSOLocal is not a native linkage decision. These externs are
  // the actual kernel map/helper capabilities, resolved by the native linker.
  for (auto &g:m->globals()) if (!g.hasLocalLinkage()) g.setDSOLocal(false);
  SmallVector<CallInst *,32> calls;
  for (auto &f:*m) {
    if (!f.hasLocalLinkage()) f.setDSOLocal(false);
    f.removeFnAttr("target-cpu"); f.removeFnAttr("target-features"); f.removeFnAttr("target-abi");
    f.addFnAttr("frame-pointer","none");
    f.removeFnAttr("no-jump-tables");
    f.removeFnAttr("disable-tail-calls");
    for (auto &i:instructions(f)) if (auto *call=dyn_cast<CallInst>(&i)) calls.push_back(call);
  }
  unsigned lowered=0;
  std::set<std::string> inlinedHelpers;
  for (auto *call:calls) {
    call->setTailCallKind(CallInst::TCK_None);
    if (auto *expr=dyn_cast<ConstantExpr>(call->getCalledOperand())) {
      auto *id=expr->getOpcode()==Instruction::IntToPtr?dyn_cast<ConstantInt>(expr->getOperand(0)):nullptr;
      if (!id || id->getZExtValue()>=std::size(HelperNames)) fail("unknown simulator helper target");
      StringRef name = HelperNames[id->getZExtValue()];
      if (id->equalsInt(BPF_FUNC_map_lookup_elem))
        if (auto *map=dyn_cast<GlobalVariable>(call->getArgOperand(0)->stripPointerCasts())) {
          for (const auto &array:ArrayMaps)
            if (map->getName()==array) name="__kprog_array_lookup";
        }
      if (id->equalsInt(BPF_FUNC_probe_read_user)) name="__kprog_probe_read_user";
      if (id->equalsInt(BPF_FUNC_probe_read_kernel)) name="__kprog_probe_read_kernel";
      if (name.starts_with("__kprog_")) inlinedHelpers.insert(name.str());
      call->setCalledFunction(m->getOrInsertFunction(name,call->getFunctionType()));
      ++lowered; continue;
    }
    if (auto *callee=call->getCalledFunction()) {
      if (callee->getName().starts_with("llvm.bpf.passthrough.")) {
        call->replaceAllUsesWith(call->getArgOperand(1)); call->eraseFromParent(); ++lowered;
      } else if (callee->getName().starts_with("llvm.bpf.")) fail("untranslated simulator BPF intrinsic: "+callee->getName());
      continue;
    }
    auto *assembly=dyn_cast<InlineAsm>(call->getCalledOperand());
    if (!assembly) continue; // Actual indirect function calls keep their target.
    StringRef text=assembly->getAsmString(); IRBuilder<> b(call);
    b.SetCurrentDebugLocation(call->getDebugLoc()); Value *result=nullptr;
    if (text=="# kprog_numeric") {
      // Clang places explicit inputs before the tied read/write input.
      result=call->getArgOperand(0);
    } else if (text.empty()) {
      if (!call->getType()->isIntegerTy() || call->arg_size()!=1 ||
          call->getArgOperand(0)->getType()!=call->getType() ||
          assembly->getConstraintString()!="=r,0" || assembly->isAlignStack() ||
          assembly->canThrow()) continue;
      // Match the B pass's concrete register bits. The original call snapshot
      // excludes the stable address bases emitted later by memoryAsm.
      result=b.CreateFreeze(call->getArgOperand(0),"register_bits");
    } else if ((text=="call -1" || text=="r0 = 0; *(u64 *)(r0 + 0) = r0; exit;") &&
        call->arg_empty() && call->getType()->isVoidTy()) {
      // The service invokes native compilation only after stock B acceptance.
      // These invalid B paths were proved unreachable; expose that fact to
      // native optimization instead of retaining verifier-only runtime traps.
      b.CreateAssumption(b.getFalse());
    } else if (text=="$0 = $0" && call->arg_size()==1 && call->getArgOperand(0)->getType()==call->getType()) {
      result=call->getArgOperand(0);
    } else {
      if (text.starts_with("$0 = ") && text.ends_with(" ll")) {
        auto name=text.drop_front(5).drop_back(3); auto *global=m->getNamedGlobal(name);
        if (!global || !call->getType()->isPointerTy() || !call->arg_empty()) fail("invalid simulator symbol address");
        result=global;
      } else result=memoryAsm(call,text,b);
    }
    if (result) call->replaceAllUsesWith(result);
    call->eraseFromParent(); ++lowered;
  }
  m->setTargetTriple("x86_64-unknown-linux-gnu");
  m->setDataLayout("e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128");
  errs()<<"native private stack accesses normalized="<<normalizePrivateStack(*m)<<'\n';
  errs()<<"native unspecified inputs frozen="<<freezeUnspecifiedInputs(*m)<<'\n';
  if (verifyModule(*m,&errs())) return 1;
  std::error_code ec; ToolOutputFile out(Output,ec,sys::fs::OF_None);
  if (ec) fail(ec.message());
  WriteBitcodeToFile(*m,out.os()); out.keep(); out.os().flush();
  if (out.os().has_error()) fail("write native simulator IR failed");
  if (!HelperList.empty()) {
    ToolOutputFile helpers(HelperList,ec,sys::fs::OF_Text);
    if (ec) fail(ec.message());
    for (const auto &name:inlinedHelpers) helpers.os()<<name<<'\n';
    helpers.keep(); helpers.os().flush();
    if (helpers.os().has_error()) fail("write native simulator helper list failed");
  }
  errs()<<"native simulator operations lowered="<<lowered<<'\n';
}
