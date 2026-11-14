// Explicit offline specialization from the upstream loader's variable dump.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/InlineAsm.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Support/Base64.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/JSON.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include <cstdlib>
using namespace llvm;
[[noreturn]] static void fail(const Twine &Message) { errs()<<Message<<'\n';std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Constants("constants",cl::Required);
static cl::opt<std::string> Report("report",cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  LLVMContext C;SMDiagnostic Error;auto M=parseIRFile(Input,Error,C);
  if (!M) { Error.print(argv[0],errs());return 1; }
  auto File=MemoryBuffer::getFile(Constants);
  if (!File) fail(Twine("read constants: ")+File.getError().message());
  auto Parsed=json::parse((*File)->getBuffer());
  if (!Parsed) fail(Twine("parse constants: ")+toString(Parsed.takeError()));
  auto *Root=Parsed->getAsObject();auto *Variables=Root?Root->getObject("variables"):nullptr;
  if (!Variables || Variables->empty()) fail("constants need a nonempty upstream variables object");
  SmallVector<CallInst *,32> Addresses;
  for (auto &F:*M) for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallInst>(&I))
    if (auto *Asm=dyn_cast<InlineAsm>(Call->getCalledOperand())) {
      StringRef Text=Asm->getAsmString();
      if (Text.consume_front("$0 = ") && Text.consume_back(" ll") && Variables->get(Text)) {
        if (!Call->getType()->isPointerTy() || Call->arg_size() || Asm->getConstraintString()!="=r")
          fail("unsupported configurable address asm");
        Addresses.push_back(Call);
      }
    }
  for (auto *Call:Addresses) {
    auto Text=cast<InlineAsm>(Call->getCalledOperand())->getAsmString();
    auto *Global=M->getNamedGlobal(StringRef(Text).drop_front(5).drop_back(3));
    if (!Global) fail("configurable asm references absent global");
    Call->replaceAllUsesWith(Global);Call->eraseFromParent();
  }
  SmallPtrSet<GlobalVariable *,32> Frozen;
  json::Array Records;
  for (auto &[Name,Value]:*Variables) {
    auto Encoded=Value.getAsString();
    if (!Encoded) fail(Twine("configurable bytes are not base64: ")+Name.str());
    auto *Global=M->getNamedGlobal(Name.str());
    if (!Global || Global->getSection()!=".rodata.config")
      fail(Twine("configurable global absent or not in .rodata.config: ")+Name.str());
    std::vector<char> Bytes;
    if (auto Error=decodeBase64(*Encoded,Bytes)) fail(Twine("decode configurable ")+Name.str()+": "+toString(std::move(Error)));
    auto Size=M->getDataLayout().getTypeAllocSize(Global->getValueType());
    if (Size.isScalable() || Size.getFixedValue()!=Bytes.size())
      fail(Twine("configurable byte length differs from IR type: ")+Name.str());
    auto *Data=ConstantDataArray::getString(C,StringRef(Bytes.data(),Bytes.size()),false);
    auto *Copy=new GlobalVariable(*M,Data->getType(),true,GlobalValue::PrivateLinkage,Data,"kprog_frozen_"+Name.str());
    Copy->setSection(".rodata.kprog_frozen");Copy->setAlignment(Global->getAlign().valueOrOne());
    Global->replaceAllUsesWith(Copy);Frozen.insert(Copy);
    Records.push_back(json::Object{{"name",Name.str()},{"bytes",int64_t(Bytes.size())}});
  }
  unsigned Loads=0;
  for (auto &F:*M) for (auto &I:instructions(F)) if (auto *Load=dyn_cast<LoadInst>(&I))
    if (auto *Global=dyn_cast<GlobalVariable>(getUnderlyingObject(Load->getPointerOperand())))
      if (Frozen.contains(Global)) {
        if (Load->isAtomic()) fail("atomic configurable loads are unsupported");
        Load->setVolatile(false);++Loads;
      }
  if (verifyModule(*M,&errs())) return 1;
  std::error_code EC;ToolOutputFile Out(Output,EC,sys::fs::OF_None);
  if (EC) fail(EC.message());
  WriteBitcodeToFile(*M,Out.os());Out.keep();Out.os().flush();
  if (Out.os().has_error()) fail("write frozen data IR failed");
  ToolOutputFile Log(Report,EC,sys::fs::OF_Text);if (EC) fail(EC.message());
  json::Object Result{{"input",Input.getValue()},{"constants",Constants.getValue()},
    {"variables",std::move(Records)},{"address_asm_rewritten",int64_t(Addresses.size())},
    {"loads_from_captured_bytes",int64_t(Loads)},
    {"scope","Offline compiler specialization. Runtime integration must supply the original load generation's frozen values; this output is not selected by an application manifest."}};
  Log.os()<<formatv("{0:2}\n",json::Value(std::move(Result)));Log.keep();Log.os().flush();
  if (Log.os().has_error()) fail("write frozen data report failed");
}
