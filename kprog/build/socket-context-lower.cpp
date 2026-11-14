// Translate public entry contexts; application source and helper ctx stay intact.
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
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <algorithm>
#include <cstdlib>
#include <linux/bpf.h>
using namespace llvm;
[[noreturn]] static void fail(const Twine &Message) { errs()<<Message<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static cl::opt<std::string> Public("public-layout",cl::Required);
static cl::opt<std::string> Physical("physical-layout",cl::Required);
static cl::opt<bool> Native("native-codegen",cl::init(false));
static cl::opt<std::string> HelperNames("helper-names");
static cl::opt<std::string> FunctionBodies("bpf-function-bodies");
struct Rule { std::string Kind, Child; int64_t PublicOffset, PublicWidth, Offset, Width; SmallVector<int64_t,2> Pointers; bool PointerValue, Boolean; int64_t Mask, StoreMax; };
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
static void materializeFunctions(Module &M,StringRef Path) {
  auto Document=readJSON(Path);auto *Object=Document.getAsObject();
  auto *Functions=Object?Object->getObject("functions"):nullptr;
  if (!Functions) fail("BPF function bodies require a functions object");
  struct Body { Function *F; uint64_t Value; };
  SmallVector<Body,16> Bodies;
  for (auto &Entry:*Functions) {
    auto *F=M.getFunction(Entry.first);
    if (!F || !F->isDeclaration()) fail(Twine("BPF body needs an existing function declaration: ")+StringRef(Entry.first));
    auto Text=Entry.second.getAsString();
    if (!Text || Text->size()!=sizeof(bpf_insn)*4) fail("BPF constant leaf requires two complete instructions");
    bpf_insn Code[2]{};auto *Bytes=reinterpret_cast<unsigned char *>(Code);
    for (unsigned I=0;I<sizeof(Code);++I) {
      unsigned Byte;
      if (Text->substr(I*2,2).getAsInteger(16,Byte)) fail("malformed BPF function instruction hex");
      Bytes[I]=Byte;
    }
    bool Wide=Code[0].code==(BPF_ALU64|BPF_MOV|BPF_K);
    bool Narrow=Code[0].code==(BPF_ALU|BPF_MOV|BPF_K);
    if ((!Wide && !Narrow) || Code[0].dst_reg!=BPF_REG_0 || Code[0].src_reg || Code[0].off ||
        Code[1].code!=(BPF_JMP|BPF_EXIT) || Code[1].dst_reg || Code[1].src_reg || Code[1].off || Code[1].imm)
      fail(Twine("BPF function body is not an exact constant-return leaf: ")+StringRef(Entry.first));
    auto *Return=F->getReturnType();
    if ((!Return->isIntegerTy() || Return->getIntegerBitWidth()>64) && !Return->isPointerTy() && !Return->isVoidTy())
      fail("BPF scalar return has an incompatible native return type");
    Bodies.push_back({F,Wide?uint64_t(int64_t(Code[0].imm)):uint64_t(uint32_t(Code[0].imm))});
  }
  // Validate every body before modifying the module; unsupported code is never
  // replaced by an empty implementation or a partial generated result.
  for (auto Body:Bodies) {
    auto *Block=BasicBlock::Create(M.getContext(),"original_bpf_leaf",Body.F);
    Body.F->setLinkage(GlobalValue::InternalLinkage);
    Body.F->setDSOLocal(true);
    // A declaration's debug node is not a definition, and describes the C
    // declaration rather than the provided current-load BPF body.
    Body.F->setSubprogram(nullptr);
    IRBuilder<> B(Block);auto *Return=Body.F->getReturnType();
    if (Return->isVoidTy()) B.CreateRetVoid();
    else if (Return->isPointerTy()) B.CreateRet(B.CreateIntToPtr(B.getInt64(Body.Value),Return));
    else B.CreateRet(ConstantInt::get(Return,Body.Value));
  }
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
    Rule R{Kind.str(),O->getString("child")->str(),integer(F,"offset"),integer(F,"width"),integer(O,"offset"),integer(O,"width"),{},O->getBoolean("pointer_value").value_or(false),O->getBoolean("boolean").value_or(false),O->getInteger("mask").value_or(-1),O->getInteger("store_max_exclusive").value_or(-1)};
    for (auto &Pointer:*O->getArray("pointers")) {
      auto Offset=Pointer.getAsInteger(); if (!Offset) fail("invalid pointer offset");
      R.Pointers.push_back(*Offset);
    }
    Rules.push_back(std::move(R));
  }
  LLVMContext C; SMDiagnostic Error; auto M=parseIRFile(Input,Error,C);
  if (!M) { Error.print(argv[0],errs()); return 1; }
  if (!FunctionBodies.empty()) {
    if (!Native) fail("BPF function bodies require explicit native-codegen");
    materializeFunctions(*M,FunctionBodies);
  }
  const auto &DL=M->getDataLayout(); unsigned Count=0;
  for (auto &F:*M) {
    if (F.isDeclaration() || F.arg_empty()) continue;
    auto Section=F.getSection(); std::string Kind;
    if (Section.starts_with("cgroup/") && (Section.contains("connect") || Section.contains("sendmsg") || Section.contains("recvmsg") || Section.contains("peername") || Section.contains("sockname") || Section.starts_with("cgroup/bind"))) Kind="sock_addr";
    else if (Section.starts_with("cgroup/post_bind") || Section=="cgroup/sock" || Section=="cgroup/sock_create" || Section=="cgroup/sock_release") Kind="sock";
    else if (Section=="tc" || Section.starts_with("tc/") || Section=="classifier" || Section.starts_with("cgroup_skb/")) Kind="skb";
    else if (Section=="xdp" || Section.starts_with("xdp/")) Kind="xdp";
    if (Kind.empty()) continue;
    SmallVector<CallInst *,16> PointerCalls;
    for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallInst>(&I))
      if (auto *Asm=dyn_cast<InlineAsm>(Call->getCalledOperand()))
        if (!Asm->getAsmString().empty()) PointerCalls.push_back(Call);
    for (auto *Call:PointerCalls) {
      auto Text=cast<InlineAsm>(Call->getCalledOperand())->getAsmString();
      IRBuilder<> B(Call);
      auto PublicPointer=[&](Value *Context,int64_t Offset) -> Value * {
        auto *Load=B.CreateAlignedLoad(PointerType::getUnqual(C),B.CreateConstGEP1_64(B.getInt8Ty(),Context,Offset),Align(1));
        Load->setVolatile(true);
        // The BPF instruction has a four-byte public field but returns a pointer.
        Load->setMetadata("bpf.public.width",MDNode::get(C,ConstantAsMetadata::get(B.getInt64(4))));
        return Load;
      };
      Value *Replacement=nullptr;
      if (Text=="$0 = *(u32 *)($1 + $2)") {
        if (Call->arg_size()!=2 || !Call->getType()->isPointerTy()) fail("invalid BPF context-pointer asm");
        auto *Offset=dyn_cast<ConstantInt>(Call->getArgOperand(1));
        if (!Offset) fail("dynamic BPF context-pointer asm offset");
        Replacement=PublicPointer(Call->getArgOperand(0),Offset->getSExtValue());
      } else if (Text=="r1 = *(u32 *)($1 +0)\n\tr2 = *(u32 *)($1 +4)\n\t$0 = r2\n\t$0 -= r1\n\t") {
        if (Kind!="xdp" || Call->arg_size()!=1 || !Call->getType()->isIntegerTy()) fail("invalid XDP length asm");
        auto *Start=B.CreatePtrToInt(PublicPointer(Call->getArgOperand(0),0),B.getInt64Ty());
        auto *End=B.CreatePtrToInt(PublicPointer(Call->getArgOperand(0),4),B.getInt64Ty());
        Replacement=B.CreateZExtOrTrunc(B.CreateSub(End,Start),Call->getType());
      } else {
        bool Variable=Text=="r1 = *(u32 *)($2 +0)\n\tr2 = *(u32 *)($2 +4)\n\t$3 &= $5\n\tr1 += $3\n\t$1 = r1\n\tr1 += $4\n\tif r1 > r2 goto +2\n\t$0 = 0\n\tgoto +1\n\t$0 = $6\n\t";
        bool Two=Text=="r1 = *(u32 *)($2 +0)\n\tr2 = *(u32 *)($2 +4)\n\t$3 &= $4\n\tr1 += $3\n\t$1 = r1\n\tr1 += 2\n\tif r1 > r2 goto +2\n\t$0 = 0\n\tgoto +1\n\t$0 = $5\n\t";
        if (!Variable && !Two) continue;
        auto *Result=dyn_cast<StructType>(Call->getType());
        if (Kind!="xdp" || Call->arg_size()!=(Variable?5u:4u) || !Result || Result->getNumElements()!=2 ||
            !Result->getElementType(0)->isIntegerTy() || !Result->getElementType(1)->isPointerTy()) fail("invalid XDP bounds asm");
        auto *Start=B.CreatePtrToInt(PublicPointer(Call->getArgOperand(0),0),B.getInt64Ty());
        auto *End=B.CreatePtrToInt(PublicPointer(Call->getArgOperand(0),4),B.getInt64Ty());
        auto *Offset=B.CreateZExtOrTrunc(Call->getArgOperand(1),B.getInt64Ty());
        auto *Mask=B.CreateZExtOrTrunc(Call->getArgOperand(Variable?3:2),B.getInt64Ty());
        auto *Length=Variable?B.CreateZExtOrTrunc(Call->getArgOperand(2),B.getInt64Ty()):B.getInt64(2);
        auto *Address=B.CreateAdd(Start,B.CreateAnd(Offset,Mask));
        auto *Error=B.CreateZExtOrTrunc(Call->getArgOperand(Variable?4:3),Result->getElementType(0));
        auto *Status=B.CreateSelect(B.CreateICmpUGT(B.CreateAdd(Address,Length),End),Error,Constant::getNullValue(Error->getType()));
        Replacement=B.CreateInsertValue(PoisonValue::get(Result),Status,0);
        Replacement=B.CreateInsertValue(Replacement,B.CreateIntToPtr(Address,Result->getElementType(1)),1);
      }
      Call->replaceAllUsesWith(Replacement); Call->eraseFromParent();
    }
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
        if (Base!=Root) fail(Twine(F.getName())+": dynamic public context offset");
        Type *Ty=L?L->getType():S->getValueOperand()->getType();
        auto Width=DL.getTypeStoreSize(Ty).getFixedValue();
        if (auto *Node=I->getMetadata("bpf.public.width")) Width=mdconst::extract<ConstantInt>(Node->getOperand(0))->getZExtValue();
        const Rule *Match=nullptr;
        for (auto &R:Rules) if (R.Kind==View && Offset>=R.PublicOffset && Offset+Width<=uint64_t(R.PublicOffset+R.PublicWidth)) { Match=&R; break; }
        if (!Match || (!Ty->isIntegerTy() && !Ty->isPointerTy())) fail(Twine(F.getName())+": unmapped public context access at "+Twine(Offset));
        IRBuilder<> B(I); Value *Address=Root;
        for (auto P:Match->Pointers) Address=B.CreateAlignedLoad(PointerType::getUnqual(C),B.CreateConstGEP1_64(B.getInt8Ty(),Address,P),Align(1),"physical_socket");
        int64_t Delta=Offset-Match->PublicOffset;
        unsigned PhysicalWidth=Delta<Match->Width?std::min<uint64_t>(Width,Match->Width-Delta):0;
        if (Match->Boolean || Match->Mask>=0) {
          if (!L || Delta) fail("unsupported converted bitfield write or partial access");
          PhysicalWidth=Match->Width;
        }
        if (Match->PointerValue) {
          if (!L || Delta || Width!=Match->PublicWidth) fail("partial packet-pointer access");
          PhysicalWidth=Match->Width;
        }
        if (Ty->isPointerTy() && PhysicalWidth!=DL.getPointerTypeSize(Ty)) fail("context pointer width mismatch");
        Address=B.CreateConstGEP1_64(B.getInt8Ty(),Address,Match->Offset+Delta);
        Type *AccessType=Ty->isPointerTy()?Ty:IntegerType::get(C,PhysicalWidth?PhysicalWidth*8:8);
        if (L) {
          Value *V=Constant::getNullValue(Ty);
          if (PhysicalWidth) {
            auto *Load=B.CreateAlignedLoad(AccessType,Address,Align(1)); Load->setVolatile(L->isVolatile()); V=Load;
            if (Match->Boolean) V=B.CreateZExt(B.CreateICmpNE(V,Constant::getNullValue(V->getType())),Ty);
            if (Match->Mask>=0) V=B.CreateAnd(V,ConstantInt::get(V->getType(),Match->Mask));
            if (Match->PointerValue && Ty->isIntegerTy() && PhysicalWidth>Width) {
              SmallVector<Instruction *,4> Extensions;
              for (auto *User:L->users()) {
                auto *Ext=dyn_cast<ZExtInst>(User);
                if (!Ext || Ext->getType()!=V->getType()) fail("packet pointer used without full-width extension");
                Extensions.push_back(Ext);
              }
              for (auto *Ext:Extensions) { Ext->replaceAllUsesWith(V); Ext->eraseFromParent(); }
            }
            if (V->getType()!=Ty) V=B.CreateZExtOrTrunc(V,Ty);
          }
          L->replaceAllUsesWith(V);
          if (!Match->Child.empty()) Roots.push_back({V,Match->Child});
        } else if (PhysicalWidth) {
          Value *V=S->getValueOperand();
          if (Match->StoreMax>=0) {
            auto *Condition=B.CreateICmpULT(V,ConstantInt::get(V->getType(),Match->StoreMax));
            B.SetInsertPoint(SplitBlockAndInsertIfThen(Condition,I,false));
          }
          if (V->getType()!=AccessType) V=B.CreateTrunc(V,AccessType);
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
    // Public maps and data are runtime linker inputs. Preserve their symbol
    // identity: section+offset references would embed native initializers
    // instead of the original BPF data binding. Private constants and LLVM's
    // appending metadata stay local.
    for (auto &Global:M->globals())
      if (!Global.hasLocalLinkage() && !Global.hasAppendingLinkage()) Global.setDSOLocal(false);
    // The BPF frontend marks extern weak function addresses dso_local. Native
    // PIC must keep a nullable GOT slot so the loader's target-BTF binding can
    // supply either the genuine address or zero without folding the guard.
    for (auto &F:*M)
      if (F.isDeclaration() && F.hasAddressTaken()) F.setDSOLocal(false);
    // Retarget BPF frontend IR from the unchanged upstream source. Configuration
    // symbol-address asm remains an opaque address dependency, so native LLVM
    // cannot replace live loader-supplied config values with initializers.
    for (auto &F:*M) {
      F.removeFnAttr("target-cpu"); F.removeFnAttr("target-features"); F.removeFnAttr("target-abi");
      F.addFnAttr("disable-tail-calls","true");
      // BPF frontend IR can require a frame pointer. The native backend's
      // -fomit-frame-pointer does not override that existing IR attribute;
      // honor the native flag here before the linker recovers the BPF frame.
      F.addFnAttr("frame-pointer","none");
      // Driver frontend flags do not set attributes on an existing IR module.
      // Preserve the native linker's direct-branch contract when retargeting.
      F.addFnAttr("no-jump-tables","true");
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
          StringRef Tail=Text;
          if (Tail.consume_front("r1 = $0\n\tr2 = ") && Tail.consume_back(" ll\n\tr3 = $1\n\tcall 12\n\t")) {
            auto *Map=M->getNamedGlobal(Tail);
            if (!Map || Call->arg_size()!=2 || !Call->getType()->isVoidTy()) fail("invalid BPF static tail-call asm");
            auto *FT=FunctionType::get(Type::getInt64Ty(C),{Call->getArgOperand(0)->getType(),Map->getType(),Call->getArgOperand(1)->getType()},false);
            IRBuilder<> B(Call);
            B.CreateCall(M->getOrInsertFunction("bpf_tail_call",FT),{Call->getArgOperand(0),Map,Call->getArgOperand(1)});
            Call->eraseFromParent(); continue;
          }
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
