// Translate public socket contexts; application source and helper ctx stay intact.
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
#include "llvm/Support/JSON.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <algorithm>
#include <cstdlib>
using namespace llvm;
[[noreturn]] static void fail(const Twine &Message) { errs()<<Message<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static cl::opt<std::string> Public("public-layout",cl::Required);
static cl::opt<std::string> Physical("physical-layout",cl::Required);
static cl::opt<bool> Native("native-codegen",cl::init(false));
static cl::opt<std::string> HelperNames("helper-names");
struct Rule { std::string Kind, Child; int64_t PublicOffset, PublicWidth, Offset, Width; SmallVector<int64_t,2> Pointers; };
static json::Value readJSON(StringRef Path) {
  auto File=MemoryBuffer::getFile(Path);
  if (!File) fail(Twine("read layout: ")+File.getError().message());
  auto Parsed=json::parse((*File)->getBuffer());
  if (!Parsed) fail(Twine("parse layout: ")+toString(Parsed.takeError()));
  return std::move(*Parsed);
}
static int64_t integer(json::Object *O,StringRef K) {
  if (!O) fail("expected layout object");
  auto V=O->getInteger(K); if (!V) fail(Twine("missing integer ")+K); return *V;
}
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  auto P=readJSON(Public), T=readJSON(Physical);
  auto *Fields=P.getAsObject(); auto *Targets=T.getAsArray();
  if (!Fields || !Targets) fail("socket layout schema");
  SmallVector<Rule,32> Rules;
  for (auto &V:*Targets) {
    auto *O=V.getAsObject();
    if (!O || !O->getString("kind") || !O->getString("field") || !O->getString("child") || !O->getArray("pointers"))
      fail("socket rule schema");
    auto Kind=*O->getString("kind"), Field=*O->getString("field");
    auto *Group=Fields->getObject(Kind); if (!Group) fail("missing public socket kind");
    auto *F=Group->getObject(Field);
    Rule R{Kind.str(),O->getString("child")->str(),integer(F,"offset"),integer(F,"width"),integer(O,"offset"),integer(O,"width"),{}};
    for (auto &Pointer:*O->getArray("pointers")) {
      auto Offset=Pointer.getAsInteger(); if (!Offset) fail("invalid pointer offset");
      R.Pointers.push_back(*Offset);
    }
    Rules.push_back(std::move(R));
  }
  LLVMContext C; SMDiagnostic Error; auto M=parseIRFile(Input,Error,C);
  if (!M) { Error.print(argv[0],errs()); return 1; }
  const auto &DL=M->getDataLayout(); unsigned Count=0;
  for (auto &F:*M) {
    if (F.isDeclaration() || F.arg_empty()) continue;
    auto Section=F.getSection(); std::string Kind;
    if (Section.starts_with("cgroup/") && (Section.contains("connect") || Section.contains("sendmsg") || Section.contains("recvmsg") || Section.contains("peername") || Section.contains("sockname") || Section.starts_with("cgroup/bind"))) Kind="sock_addr";
    else if (Section.starts_with("cgroup/post_bind") || Section=="cgroup/sock" || Section=="cgroup/sock_create" || Section=="cgroup/sock_release") Kind="sock";
    if (Kind.empty()) continue;
    SmallVector<Instruction *,32> Memory;
    for (auto &I:instructions(F)) if (isa<LoadInst>(I) || isa<StoreInst>(I)) Memory.push_back(&I);
    SmallVector<std::pair<Value *,std::string>,4> Roots{{F.getArg(0),Kind}};
    for (unsigned RootIndex=0;RootIndex<Roots.size();++RootIndex) {
      auto [Root,View]=Roots[RootIndex];
      for (auto *I:Memory) {
        auto *L=dyn_cast<LoadInst>(I); auto *S=dyn_cast<StoreInst>(I);
        Value *Pointer=L?L->getPointerOperand():S->getPointerOperand();
        SmallVector<const Value *,4> Origins; getUnderlyingObjects(Pointer,Origins);
        if (!is_contained(Origins,Root)) continue;
        int64_t Offset=0; auto *Base=GetPointerBaseWithConstantOffset(Pointer,Offset,DL);
        if (Base!=Root) fail(Twine(F.getName())+": dynamic socket context offset");
        Type *Ty=L?L->getType():S->getValueOperand()->getType();
        auto Width=DL.getTypeStoreSize(Ty).getFixedValue();
        const Rule *Match=nullptr;
        for (auto &R:Rules) if (R.Kind==View && Offset>=R.PublicOffset && Offset+Width<=uint64_t(R.PublicOffset+R.PublicWidth)) { Match=&R; break; }
        if (!Match || (!Ty->isIntegerTy() && !Ty->isPointerTy())) fail(Twine(F.getName())+": unmapped socket access at "+Twine(Offset));
        IRBuilder<> B(I); Value *Address=Root;
        for (auto P:Match->Pointers) Address=B.CreateAlignedLoad(PointerType::getUnqual(C),B.CreateConstGEP1_64(B.getInt8Ty(),Address,P),Align(1),"physical_socket");
        int64_t Delta=Offset-Match->PublicOffset;
        unsigned PhysicalWidth=Delta<Match->Width?std::min<uint64_t>(Width,Match->Width-Delta):0;
        if (Ty->isPointerTy() && PhysicalWidth!=Width) fail("socket pointer width mismatch");
        Address=B.CreateConstGEP1_64(B.getInt8Ty(),Address,Match->Offset+Delta);
        Type *AccessType=Ty->isPointerTy()?Ty:IntegerType::get(C,PhysicalWidth?PhysicalWidth*8:8);
        if (L) {
          Value *V=Constant::getNullValue(Ty);
          if (PhysicalWidth) { auto *Load=B.CreateAlignedLoad(AccessType,Address,Align(1)); Load->setVolatile(L->isVolatile()); V=Load; if (V->getType()!=Ty) V=B.CreateZExtOrTrunc(V,Ty); }
          L->replaceAllUsesWith(V);
          if (!Match->Child.empty()) Roots.push_back({V,Match->Child});
        } else if (PhysicalWidth) {
          Value *V=S->getValueOperand(); if (V->getType()!=AccessType) V=B.CreateTrunc(V,AccessType);
          auto *Store=B.CreateAlignedStore(V,Address,Align(1)); Store->setVolatile(S->isVolatile());
        }
        // Erase after all roots have been analyzed: nested sk roots can still
        // appear in the saved access list and must retain their original type.
        ++Count;
      }
      for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallBase>(&I)) {
        for (auto &Operand:Call->args()) {
          auto *Pointer=Operand.get(); if (!Pointer->getType()->isPointerTy()) continue;
          SmallVector<const Value *,4> Origins; getUnderlyingObjects(Pointer,Origins);
          if (!is_contained(Origins,Root)) continue;
          int64_t Offset=0; auto *Base=GetPointerBaseWithConstantOffset(Pointer,Offset,DL);
          auto *Callee=Call->getCalledFunction();
          if (Base!=Root || Offset!=0 || (Callee && (!Callee->isDeclaration() || Callee->getName().starts_with("llvm.mem"))))
            fail(Twine(F.getName())+": socket field address escapes into an unlowered call");
        }
      }
    }
    // Original accesses are identified again from their roots after replacements.
    // Replaced loads now have no users; their original stores must also go.
    for (auto *I:Memory) {
      Value *Pointer=isa<LoadInst>(I)?cast<LoadInst>(I)->getPointerOperand():cast<StoreInst>(I)->getPointerOperand();
      bool Context=false; for (auto &[Root,View]:Roots) if (getUnderlyingObject(Pointer)==Root) Context=true;
      if (Context) I->eraseFromParent();
    }
    F.setMemoryEffects(MemoryEffects::unknown());
    F.removeParamAttr(0,Attribute::ReadOnly); F.removeParamAttr(0,Attribute::WriteOnly);
    F.removeParamAttr(0,Attribute::Dereferenceable); F.removeParamAttr(0,Attribute::DereferenceableOrNull);
  }
  if (Native) {
    if (HelperNames.empty()) fail("native codegen requires canonical helper names");
    auto HelperTable=readJSON(HelperNames); auto *Helpers=HelperTable.getAsObject();
    if (!Helpers) fail("invalid canonical helper-name object");
    // Map addresses are supplied by the intercepted loader, so keep their
    // symbol identity in PIC relocations rather than folding to section+offset.
    for (auto &Global:M->globals())
      if (Global.getSection()==".maps") Global.setDSOLocal(false);
    // Retarget BPF frontend IR from the unchanged upstream source. Configuration
    // symbol-address asm remains an opaque address dependency, so native LLVM
    // cannot replace live loader-supplied config values with initializers.
    for (auto &F:*M) {
      F.removeFnAttr("target-cpu"); F.removeFnAttr("target-features"); F.removeFnAttr("target-abi");
      F.addFnAttr("disable-tail-calls","true");
      SmallVector<CallInst *,16> Calls;
      for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallInst>(&I)) Calls.push_back(Call);
      for (auto *Call:Calls) {
        Call->setTailCallKind(CallInst::TCK_None);
        // ELF function relocations carry helper identity across arbitrary CFG
        // and register allocation. Do not recover it from a linear register scan.
        if (auto *Expr=dyn_cast<ConstantExpr>(Call->getCalledOperand())) {
          if (Expr->getOpcode()!=Instruction::IntToPtr) fail("unknown constant call target");
          auto *Id=dyn_cast<ConstantInt>(Expr->getOperand(0));
          if (!Id) fail("helper call target is not a constant ID");
          auto Name=Helpers->getString(std::to_string(Id->getZExtValue()));
          if (!Name) fail(Twine("unknown helper ID ")+Twine(Id->getZExtValue()));
          Call->setCalledFunction(M->getOrInsertFunction(*Name,Call->getFunctionType()));
        }
        if (auto *Asm=dyn_cast<InlineAsm>(Call->getCalledOperand())) {
          StringRef Text=Asm->getAsmString();
          if (Text.empty()) continue; // Native memory compiler barrier too.
          if (!Text.consume_front("$0 = ") || !Text.consume_back(" ll"))
            fail(Twine(F.getName())+": unlowered BPF inline asm: "+Asm->getAsmString());
          auto *Global=M->getNamedGlobal(Text);
          if (!Global || !Call->getType()->isPointerTy() || !Call->arg_empty())
            fail("invalid configuration symbol-address asm");
          auto *FT=FunctionType::get(Call->getType(),{Global->getType()},false);
          IRBuilder<> B(Call);
          auto *Address=B.CreateCall(FT,InlineAsm::get(FT,"","=r,0",true),{Global});
          Call->replaceAllUsesWith(Address); Call->eraseFromParent();
        } else if (auto *Callee=Call->getCalledFunction()) {
          if (Callee->getName().starts_with("llvm.bpf.passthrough.")) {
            Call->replaceAllUsesWith(Call->getArgOperand(1)); Call->eraseFromParent();
          } else if (Callee->getName().starts_with("llvm.bpf."))
            fail(Twine("unlowered BPF intrinsic: ")+Callee->getName());
        }
      }
    }
    M->setTargetTriple("x86_64-unknown-linux-gnu");
    M->setDataLayout("e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128");
  }
  if (verifyModule(*M,&errs())) return 1;
  std::error_code EC; ToolOutputFile Out(Output,EC,sys::fs::OF_None);
  if (EC) { errs()<<EC.message()<<'\n'; return 1; }
  WriteBitcodeToFile(*M,Out.os()); Out.keep(); errs()<<"socket context accesses lowered: "<<Count<<'\n';
}
