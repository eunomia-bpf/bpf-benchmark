// Translate the checked simulator's BPF-target IR to the native compiler IR.
// The source and its map/helper identities remain service-owned throughout.
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
using namespace llvm;
[[noreturn]] static void fail(const Twine &s) { errs()<<s<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
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
  auto address=[&](StringRef base,StringRef sign,StringRef displacement) {
    auto *pointer=read(base); if (!pointer->getType()->isPointerTy()) pointer=b.CreateIntToPtr(pointer,b.getPtrTy());
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
    f.addFnAttr("frame-pointer","none"); f.addFnAttr("no-jump-tables","true");
    f.addFnAttr("disable-tail-calls","true");
    for (auto &i:instructions(f)) if (auto *call=dyn_cast<CallInst>(&i)) calls.push_back(call);
  }
  unsigned lowered=0;
  for (auto *call:calls) {
    call->setTailCallKind(CallInst::TCK_None);
    if (auto *expr=dyn_cast<ConstantExpr>(call->getCalledOperand())) {
      auto *id=expr->getOpcode()==Instruction::IntToPtr?dyn_cast<ConstantInt>(expr->getOperand(0)):nullptr;
      if (!id || id->getZExtValue()>=std::size(HelperNames)) fail("unknown simulator helper target");
      call->setCalledFunction(m->getOrInsertFunction(HelperNames[id->getZExtValue()],call->getFunctionType()));
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
    if (text.empty()) continue; // Preserve the actual compiler barrier.
    if (text=="call -1" && call->arg_empty() && call->getType()->isVoidTy()) {
      // The simulator's unresolved-dispatch arm is a verifier error if reachable.
      // Keep a faulting arm in native code; never supply an invented call target.
      b.CreateCall(Intrinsic::getDeclaration(m.get(),Intrinsic::trap));
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
  if (verifyModule(*m,&errs())) return 1;
  std::error_code ec; ToolOutputFile out(Output,ec,sys::fs::OF_None);
  if (ec) fail(ec.message());
  WriteBitcodeToFile(*m,out.os()); out.keep(); out.os().flush();
  if (out.os().has_error()) fail("write native simulator IR failed");
  errs()<<"native simulator operations lowered="<<lowered<<'\n';
}
