// Lower public PERF_EVENT context loads after native inlining. Calls retain ctx.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/JSON.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/Verifier.h"
using namespace llvm;

static cl::opt<std::string> Input(cl::Positional, cl::Required);
static cl::opt<std::string> Output("o", cl::Required);
static cl::opt<std::string> Layout("layout", cl::Required);

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv);
  auto File = MemoryBuffer::getFile(Layout);
  if (!File) { errs() << File.getError().message() << '\n'; return 1; }
  auto Parsed = json::parse((*File)->getBuffer());
  if (!Parsed) { errs() << toString(Parsed.takeError()) << '\n'; return 1; }
  auto *Object = Parsed->getAsObject();
  if (!Object) { errs() << "layout must be an object\n"; return 1; }
  auto Field = [&](StringRef Name) -> int64_t {
    auto Value = Object->getInteger(Name);
    if (!Value) report_fatal_error(Twine("missing layout field ") + Name);
    return *Value;
  };
  int64_t RegSize = Field("regs_size"), RegOffset = Field("ctx_regs");
  int64_t DataOffset = Field("ctx_data"), Period = Field("data_period");
  int64_t Addr = Field("data_addr");
  LLVMContext C;
  SMDiagnostic Error;
  auto M = parseIRFile(Input, Error, C);
  if (!M) { Error.print(argv[0], errs()); return 1; }
  auto &DL = M->getDataLayout();
  unsigned Count = 0;
  for (auto &F : *M) {
    if (F.isDeclaration() || !F.getSection().starts_with("perf_event")) continue;
    if (F.arg_empty()) { errs() << "PERF_EVENT entry needs ctx\n"; return 1; }
    auto *Ctx = F.getArg(0);
    SmallVector<LoadInst *, 32> Loads;
    for (auto &I : instructions(F))
      if (auto *L = dyn_cast<LoadInst>(&I))
        if (getUnderlyingObject(L->getPointerOperand()) == Ctx) Loads.push_back(L);
    for (auto *L : Loads) {
      int64_t Offset = 0;
      auto *Base = GetPointerBaseWithConstantOffset(L->getPointerOperand(), Offset, DL);
      if (Base != Ctx) {
        errs() << F.getName() << ": dynamic public context access\n"; return 1;
      }
      auto Width = DL.getTypeStoreSize(L->getType()).getFixedValue();
      int64_t PointerOffset, FieldOffset;
      if (Offset >= 0 && Offset + Width <= uint64_t(RegSize)) {
        PointerOffset = RegOffset; FieldOffset = Offset;
      } else if (Offset >= RegSize && Offset + Width <= uint64_t(RegSize + 8)) {
        PointerOffset = DataOffset; FieldOffset = Period + Offset - RegSize;
      } else if (Offset >= RegSize + 8 && Offset + Width <= uint64_t(RegSize + 16)) {
        PointerOffset = DataOffset; FieldOffset = Addr + Offset - RegSize - 8;
      } else {
        errs() << F.getName() << ": public context offset " << Offset << '\n'; return 1;
      }
      IRBuilder<> B(L);
      auto *Slot = B.CreateConstGEP1_64(B.getInt8Ty(), Ctx, PointerOffset);
      auto *Physical = B.CreateLoad(PointerType::getUnqual(C), Slot, "physical_ctx_view");
      auto *Address = B.CreateConstGEP1_64(B.getInt8Ty(), Physical, FieldOffset);
      L->setOperand(0, Address);
      // Original metadata describes the public object, whose layout has changed.
      L->setMetadata(LLVMContext::MD_tbaa, nullptr);
      ++Count;
    }
    // The physical view reads memory reached through pointers stored in ctx.
    if (!Loads.empty())
      F.setMemoryEffects(F.getMemoryEffects() | MemoryEffects::readOnly());
  }
  if (verifyModule(*M, &errs())) return 1;
  std::error_code EC;
  ToolOutputFile Out(Output, EC, sys::fs::OF_None);
  if (EC) { errs() << EC.message() << '\n'; return 1; }
  WriteBitcodeToFile(*M, Out.os());
  Out.keep();
  errs() << "PERF_EVENT public context loads lowered: " << Count << '\n';
}
