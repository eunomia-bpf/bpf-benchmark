// Lower BPF arithmetic/memory/branch asm before native backend selection.
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <cstdlib>
using namespace llvm;
[[noreturn]] static void fail(const Twine &S) { errs()<<S<<'\n';std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static Constant *immediate(Type *Ty,StringRef Text) {
  uint64_t N;
  if (Text.getAsInteger(0,N) || N>UINT32_MAX) fail("invalid BPF arithmetic immediate");
  return ConstantInt::get(Ty,uint64_t(int64_t(int32_t(N))),true);
}
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext C;SMDiagnostic Error;auto M=parseIRFile(Input,Error,C);
  if (!M) { Error.print(argv[0],errs());return 1; }
  SmallVector<CallBase *,32> Calls;
  for (auto &F:*M) for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallBase>(&I))
    if (isa<InlineAsm>(Call->getCalledOperand()) || (Call->getCalledFunction() && Call->getCalledFunction()->getName().starts_with("llvm.bpf.compare."))) Calls.push_back(Call);
  unsigned Count=0;
  for (auto *Call:Calls) {
    if (auto *F=Call->getCalledFunction()) {
      auto *Predicate=Call->arg_size()==3?dyn_cast<ConstantInt>(Call->getArgOperand(0)):nullptr;
      if (!Predicate || !CmpInst::isIntPredicate(CmpInst::Predicate(Predicate->getZExtValue())) ||
          !Call->getType()->isIntegerTy(1) || !Call->getArgOperand(1)->getType()->isIntegerTy() ||
          Call->getArgOperand(1)->getType()!=Call->getArgOperand(2)->getType()) fail("invalid BPF comparison intrinsic");
      IRBuilder<> B(Call);B.SetCurrentDebugLocation(Call->getDebugLoc());
      Call->replaceAllUsesWith(B.CreateICmp(CmpInst::Predicate(Predicate->getZExtValue()),Call->getArgOperand(1),Call->getArgOperand(2)));
      Call->eraseFromParent();++Count;continue;
    }
    auto *Asm=cast<InlineAsm>(Call->getCalledOperand());StringRef Text=Asm->getAsmString();
    StringRef Constraint=Asm->getConstraintString();IRBuilder<> B(Call);B.SetCurrentDebugLocation(Call->getDebugLoc());
    Value *Result=nullptr;
    if (auto *Branch=dyn_cast<CallBrInst>(Call)) {
      if (Text!="if $0 < 0 goto ${2:l}\n;if $0 < 32736 goto ${1:l}\n;" || Constraint!="r,!i,!i" ||
          Branch->arg_size()!=1 || !Branch->getArgOperand(0)->getType()->isIntegerTy(64) || Branch->getNumIndirectDests()!=2)
        fail("unlowered BPF asm-goto");
      auto *Good=Branch->getIndirectDest(0),*Negative=Branch->getIndirectDest(1),*Default=Branch->getDefaultDest();
      auto *Parent=Branch->getParent();auto *Next=BasicBlock::Create(C,"bpf_size_bound",Parent->getParent(),Default);
      // BPF '<' is unsigned; signed branches use 's<'. Keep both source tests.
      B.CreateCondBr(B.CreateICmpULT(Branch->getArgOperand(0),B.getInt64(0)),Negative,Next);
      IRBuilder<> NB(Next);NB.CreateCondBr(NB.CreateICmpULT(Branch->getArgOperand(0),NB.getInt64(32736)),Good,Default);
      SmallPtrSet<BasicBlock *,4> Destinations{Good,Negative,Default};
      for (auto *Destination:Destinations) for (auto &Phi:Destination->phis()) {
        auto *Incoming=Phi.getIncomingValueForBlock(Parent);
        while (Phi.getBasicBlockIndex(Parent)>=0) Phi.removeIncomingValue(unsigned(Phi.getBasicBlockIndex(Parent)),false);
        if (Destination==Negative) Phi.addIncoming(Incoming,Parent);
        if (Destination==Good) Phi.addIncoming(Incoming,Next);
        if (Destination==Default) Phi.addIncoming(Incoming,Next);
      }
      Branch->eraseFromParent();++Count;continue;
    }
    auto *CI=dyn_cast<CallInst>(Call);if (!CI) fail("unsupported BPF inline-asm call kind");
    if ((Text=="$0 &= $1 ;\n" || Text=="$0 &= $1;\n") && Constraint=="=r,i,0") {
      if (CI->arg_size()!=2 || !CI->getType()->isIntegerTy() || CI->getArgOperand(1)->getType()!=CI->getType()) fail("invalid tied BPF mask");
      auto *Mask=dyn_cast<ConstantInt>(CI->getArgOperand(0));if (!Mask) fail("nonconstant BPF immediate mask");
      if (!Mask->getValue().isSignedIntN(32) && !Mask->getValue().isIntN(32)) fail("BPF mask exceeds immediate encoding");
      Result=B.CreateAnd(CI->getArgOperand(1),ConstantInt::get(CI->getType(),int64_t(int32_t(Mask->getSExtValue())),true));
    } else if (Text=="if $0 s< -4095 goto +1\nif $0 s<= 0 goto +1\n$0 = -1\n" && Constraint=="=r,0") {
      if (CI->arg_size()!=1 || (CI->getType()!=B.getInt32Ty() && CI->getType()!=B.getInt64Ty()) ||
          CI->getArgOperand(0)->getType()!=CI->getType()) fail("invalid BPF errno range asm");
      // The asm compares full BPF registers, including a zero-extended 32-bit
      // input. In the real LSM object LDXW feeds these signed 64-bit jumps.
      auto *InputValue=CI->getArgOperand(0);
      auto *Register=B.CreateZExtOrTrunc(InputValue,B.getInt64Ty());
      auto *InRange=B.CreateAnd(B.CreateICmpSGE(Register,B.getInt64(-4095)),B.CreateICmpSLE(Register,B.getInt64(0)));
      Result=B.CreateSelect(InRange,InputValue,ConstantInt::getSigned(CI->getType(),-1));
    } else if (Text=="if $2 != 8 goto +2\n*(u64 *)($0 + $3) = $1\ngoto +8\nif $2 != 4 goto +2\n*(u32 *)($0 + $3) = $1\ngoto +5\nif $2 != 2 goto +2\n*(u16 *)($0 + $3) = $1\ngoto +2\nif $2 != 1 goto +1\n*(u8 *)($0 + $3) = $1\n" && Constraint=="=r,=r,=r,i,0,1,2") {
      auto *ST=dyn_cast<StructType>(CI->getType());
      if (CI->arg_size()!=4 || !ST || ST->getNumElements()!=3 || !ST->getElementType(0)->isPointerTy() ||
          ST->getElementType(1)!=B.getInt64Ty() || ST->getElementType(2)!=B.getInt8Ty() ||
          !isa<ConstantInt>(CI->getArgOperand(0)) || CI->getArgOperand(0)->getType()->getIntegerBitWidth()>64 ||
          CI->getArgOperand(1)->getType()!=ST->getElementType(0) || CI->getArgOperand(2)->getType()!=B.getInt64Ty() ||
          CI->getArgOperand(3)->getType()!=B.getInt8Ty()) fail("invalid BPF width-selected store");
      auto *Parent=CI->getParent();
      auto *Continue=Parent->splitBasicBlock(CI,"bpf_store_done");
      Parent->getTerminator()->eraseFromParent();
      IRBuilder<> Test(Parent);Test.SetCurrentDebugLocation(CI->getDebugLoc());
      auto *Address=Test.CreateGEP(B.getInt8Ty(),CI->getArgOperand(1),Test.CreateSExtOrTrunc(CI->getArgOperand(0),Test.getInt64Ty()));
      for (unsigned Width:{8,4,2,1}) {
        auto *Store=BasicBlock::Create(C,"bpf_store",Parent->getParent(),Continue);
        auto *Next=Width==1?Continue:BasicBlock::Create(C,"bpf_store_size",Parent->getParent(),Continue);
        Test.CreateCondBr(Test.CreateICmpEQ(CI->getArgOperand(3),Test.getInt8(Width)),Store,Next);
        IRBuilder<> Write(Store);Write.SetCurrentDebugLocation(CI->getDebugLoc());
        auto *Value=Write.CreateTruncOrBitCast(CI->getArgOperand(2),Write.getIntNTy(Width*8));
        Write.CreateAlignedStore(Value,Address,Align(1))->setVolatile(true);Write.CreateBr(Continue);
        Test.SetInsertPoint(Next);
      }
      B.SetInsertPoint(CI);
      Result=B.CreateInsertValue(PoisonValue::get(ST),CI->getArgOperand(1),0);
      Result=B.CreateInsertValue(Result,CI->getArgOperand(2),1);
      Result=B.CreateInsertValue(Result,CI->getArgOperand(3),2);
    } else if (Text=="$0 &= 0xfff;\nr1 = *(u64 *)$1;\nr1 += $0;\n*(u32 *)(r1 + 0) = $2;\n" && Constraint=="=r,=*m,=r,0,*m,2,~{r1}") {
      auto *ST=dyn_cast<StructType>(CI->getType());
      if (CI->arg_size()!=4 || !ST || ST->getNumElements()!=2 || !ST->getElementType(0)->isIntegerTy(32) ||
          !ST->getElementType(1)->isIntegerTy(32) || !CI->getArgOperand(0)->getType()->isPointerTy() ||
          CI->getArgOperand(1)->getType()!=B.getInt32Ty() || CI->getArgOperand(3)->getType()!=B.getInt32Ty()) fail("invalid bounded BPF store");
      auto *Offset=B.CreateAnd(CI->getArgOperand(1),B.getInt32(0xfff));
      auto *Buffer=B.CreateAlignedLoad(PointerType::getUnqual(C),CI->getArgOperand(0),Align(1));Buffer->setVolatile(true);
      auto *Address=B.CreateGEP(B.getInt8Ty(),Buffer,B.CreateZExt(Offset,B.getInt64Ty()));
      B.CreateAlignedStore(CI->getArgOperand(3),Address,Align(1))->setVolatile(true);
      Result=B.CreateInsertValue(PoisonValue::get(ST),Offset,0);
      Result=B.CreateInsertValue(Result,CI->getArgOperand(3),1);
    } else if (Text=="$1 = *(u64 *)($0 + $2)\n" && Constraint=="=r,=r,i,0,1") {
      auto *ST=dyn_cast<StructType>(CI->getType());
      if (CI->arg_size()!=3 || !ST || ST->getNumElements()!=2 || !ST->getElementType(0)->isPointerTy() ||
          !ST->getElementType(1)->isIntegerTy(64) || !isa<ConstantInt>(CI->getArgOperand(0)) ||
          CI->getArgOperand(1)->getType()!=ST->getElementType(0)) fail("invalid BPF register load");
      auto *Address=B.CreateGEP(B.getInt8Ty(),CI->getArgOperand(1),CI->getArgOperand(0));
      auto *Load=B.CreateAlignedLoad(B.getInt64Ty(),Address,Align(1));Load->setVolatile(true);
      Result=B.CreateInsertValue(PoisonValue::get(ST),CI->getArgOperand(1),0);Result=B.CreateInsertValue(Result,Load,1);
    } else if (Text.starts_with("$0 &= ") && Text.contains(";\nif $0 < ") && Constraint=="=r,0") {
      if (CI->arg_size()!=1 || !CI->getType()->isIntegerTy() || CI->getArgOperand(0)->getType()!=CI->getType()) fail("invalid BPF bounded mask");
      auto Parts=Text.drop_front(6).split(";\nif $0 < ");
      auto Bound=Parts.second.split(" goto +1\n;$0 = ");
      if (!Bound.second.ends_with(";\n") || Bound.first!=Bound.second.drop_back(2)) fail("invalid BPF bound assignment");
      auto *V=B.CreateAnd(CI->getArgOperand(0),immediate(CI->getType(),Parts.first));
      auto *Limit=immediate(CI->getType(),Bound.first);Result=B.CreateSelect(B.CreateICmpULT(V,Limit),V,Limit);
    } else if (Text.starts_with("$0 &= ") && Text.ends_with(";\n") && Constraint=="=r,0") {
      if (CI->arg_size()!=1 || !CI->getType()->isIntegerTy() || CI->getArgOperand(0)->getType()!=CI->getType()) fail("invalid literal BPF mask");
      Result=B.CreateAnd(CI->getArgOperand(0),immediate(CI->getType(),Text.drop_front(6).drop_back(2)));
    } else continue; // Context/config/tail-call forms belong to context lowering.
    CI->replaceAllUsesWith(Result);CI->eraseFromParent();++Count;
  }
  if (verifyModule(*M,&errs())) return 1;
  std::error_code EC;ToolOutputFile Out(Output,EC,sys::fs::OF_None);if (EC) fail(EC.message());
  WriteBitcodeToFile(*M,Out.os());Out.keep();Out.os().flush();if (Out.os().has_error()) fail("write lowered asm failed");
  errs()<<"BPF asm/compare forms lowered="<<Count<<'\n';
}
