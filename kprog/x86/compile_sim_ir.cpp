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
using namespace llvm;
[[noreturn]] static void fail(const Twine &s) { errs()<<s<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
#define HELPER_NAME(name) "bpf_" #name
static const char *HelperNames[] = {__BPF_FUNC_MAPPER(HELPER_NAME)};
#undef HELPER_NAME

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
  Regex load("^\\$0 = \\*\\(u(8|16|32|64) \\*\\)\\(\\$([0-9]+) ([+-]) (\\$[0-9]+|[0-9]+)\\)$");
  Regex store("^\\*\\(u(8|16|32|64) \\*\\)\\(\\$([0-9]+) ([+-]) (\\$[0-9]+|[0-9]+)\\) = \\$([0-9]+)$");
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
      SmallVector<StringRef,8> match;
      bool is_load=load.match(text,&match);
      if (is_load || store.match(text,&match)) {
        auto integer=[](StringRef s) { unsigned v; if (s.getAsInteger(10,v)) fail("invalid simulator asm operand"); return v; };
        auto operand=[&](StringRef s) -> Value * {
          unsigned index=integer(s); unsigned outputs=is_load?1:0;
          if (index<outputs || index-outputs>=call->arg_size()) fail("simulator asm operand is absent");
          return call->getArgOperand(index-outputs);
        };
        auto *base=operand(match[2]);
        if (!base->getType()->isPointerTy()) base=b.CreateIntToPtr(base,b.getPtrTy());
        StringRef displacement=match[4];
        Value *offset=displacement.consume_front("$")?b.CreateSExtOrTrunc(operand(displacement),b.getInt64Ty()):b.getInt64(integer(displacement));
        if (match[3]=="-") offset=b.CreateNeg(offset);
        auto *address=b.CreateGEP(b.getInt8Ty(),base,offset);
        auto *type=b.getIntNTy(integer(match[1]));
        if (is_load) {
          auto *value=b.CreateAlignedLoad(type,address,Align(1)); value->setVolatile(true);
          result=b.CreateZExtOrTrunc(value,call->getType());
        } else {
          auto *value=b.CreateZExtOrTrunc(operand(match[5]),type);
          b.CreateAlignedStore(value,address,Align(1))->setVolatile(true);
        }
      } else if (text.starts_with("$0 = ") && text.ends_with(" ll")) {
        auto name=text.drop_front(5).drop_back(3); auto *global=m->getNamedGlobal(name);
        if (!global || !call->getType()->isPointerTy() || !call->arg_empty()) fail("invalid simulator symbol address");
        result=global;
      } else fail("untranslated simulator BPF assembly: "+text);
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
