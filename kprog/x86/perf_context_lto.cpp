// Trusted load-time conversion of PERF_EVENT public loads to the boot kernel ABI.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/BinaryFormat/Magic.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "../libnativeloader/src/native_loader_lto.hpp"
#include <memory>
using namespace llvm;

static cl::opt<std::string> Input(cl::Positional, cl::Required);
static cl::opt<std::string> Output("o", cl::Required);
static cl::opt<std::string> Kernel("kernel-btf", cl::Required);
static cl::opt<std::string> Symbol("symbol", cl::Required);

int main(int argc, char **argv) {
  cl::ParseCommandLineOptions(argc, argv);
  LLVMContext C;
  SMDiagnostic Error;
  auto File = MemoryBuffer::getFile(Input);
  if (!File) { errs() << File.getError().message() << '\n'; return 1; }
  auto Buffer = (*File)->getMemBufferRef();
  if (identify_magic(Buffer.getBuffer()) == file_magic::elf_relocatable) {
    auto Object = object::ObjectFile::createObjectFile(Buffer);
    if (!Object) { errs() << toString(Object.takeError()) << '\n'; return 1; }
    bool Found = false;
    for (auto Section : (*Object)->sections()) {
      auto Name = Section.getName();
      if (!Name) { errs() << toString(Name.takeError()) << '\n'; return 1; }
      if (*Name != ".llvmbc") continue;
      auto Bytes = Section.getContents();
      if (!Bytes) { errs() << toString(Bytes.takeError()) << '\n'; return 1; }
      Buffer = MemoryBufferRef(*Bytes, Input); Found = true; break;
    }
    if (!Found) { errs() << "PERF_EVENT LTO needs embedded LLVM IR in P\n"; return 1; }
  }
  auto M = parseIR(Buffer, Error, C);
  if (!M) { Error.print(argv[0], errs()); return 1; }
  auto *F = M->getFunction(Symbol);
  if (!F || F->isDeclaration() || F->arg_empty()) {
    errs() << "PERF_EVENT LTO entry is missing: " << Symbol << '\n'; return 1;
  }
  // A static ELF entry is still the selected public program boundary. Keep
  // its ABI and body alive through both module optimization pipelines.
  F->setLinkage(GlobalValue::ExternalLinkage);
  F->setDSOLocal(true);
  InitializeNativeTarget(); InitializeNativeTargetAsmPrinter(); InitializeNativeTargetAsmParser();
  std::string TargetError;
  auto *Target = TargetRegistry::lookupTarget(M->getTargetTriple(), TargetError);
  if (!Target) { errs() << TargetError << '\n'; return 1; }
  TargetOptions Options;
  std::unique_ptr<TargetMachine> Machine(Target->createTargetMachine(
      M->getTargetTriple(), sys::getHostCPUName(), "", Options,
      Reloc::PIC_, std::nullopt, CodeGenOptLevel::Aggressive));
  M->setDataLayout(Machine->createDataLayout());
  LoopAnalysisManager LAM; FunctionAnalysisManager FAM;
  CGSCCAnalysisManager CGAM; ModuleAnalysisManager MAM;
  PassBuilder PB(Machine.get());
  PB.registerModuleAnalyses(MAM); PB.registerCGSCCAnalyses(CGAM);
  PB.registerFunctionAnalyses(FAM); PB.registerLoopAnalyses(LAM);
  PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
  // Embedded cc1 IR precedes promotion/inlining; expose its context uses first.
  PB.buildPerModuleDefaultPipeline(OptimizationLevel::O3).run(*M, MAM);
  std::unique_ptr<btf, decltype(&btf__free)> Types(
      btf__parse(Kernel.c_str(), nullptr), btf__free);
  if (!Types) { errs() << "cannot read boot kernel BTF\n"; return 1; }
  try {
    auto Regs = native_lto::field(Types.get(), "bpf_perf_event_data", "regs");
    auto Period = native_lto::field(Types.get(), "bpf_perf_event_data", "sample_period");
    auto Addr = native_lto::field(Types.get(), "bpf_perf_event_data", "addr");
    int64_t RegSize = btf__resolve_size(Types.get(), Regs.type_id);
    if (RegSize < 0) throw std::runtime_error("cannot resolve PERF_EVENT registers size");
    auto RegPointer = native_lto::offset(Types.get(), "bpf_perf_event_data_kern", "regs");
    auto DataPointer = native_lto::offset(Types.get(), "bpf_perf_event_data_kern", "data");
    auto DataPeriod = native_lto::offset(Types.get(), "perf_sample_data", "period");
    auto DataAddr = native_lto::offset(Types.get(), "perf_sample_data", "addr");
    const auto &DL = M->getDataLayout();
    auto *Ctx = F->getArg(0);
    SmallVector<LoadInst *, 32> Loads;
    for (auto &I : instructions(F))
      if (auto *L = dyn_cast<LoadInst>(&I))
        if (getUnderlyingObject(L->getPointerOperand()) == Ctx) Loads.push_back(L);
    for (auto *L : Loads) {
      int64_t Offset = 0;
      auto *Base = GetPointerBaseWithConstantOffset(L->getPointerOperand(), Offset, DL);
      int64_t Width = DL.getTypeStoreSize(L->getType()).getFixedValue();
      int64_t PointerOffset, FieldOffset;
      if (Base != Ctx) throw std::runtime_error("dynamic PERF_EVENT public offset");
      if (Offset >= Regs.offset && Offset + Width <= Regs.offset + RegSize) {
        PointerOffset = RegPointer; FieldOffset = Offset - Regs.offset;
      } else if (Offset >= Period.offset && Offset + Width <= Period.offset + 8) {
        PointerOffset = DataPointer; FieldOffset = DataPeriod + Offset - Period.offset;
      } else if (Offset >= Addr.offset && Offset + Width <= Addr.offset + 8) {
        PointerOffset = DataPointer; FieldOffset = DataAddr + Offset - Addr.offset;
      } else throw std::runtime_error("unmapped PERF_EVENT public offset " + std::to_string(Offset));
      IRBuilder<> B(L);
      auto *Slot = B.CreateConstGEP1_64(B.getInt8Ty(), Ctx, PointerOffset);
      auto *View = B.CreateLoad(PointerType::getUnqual(C), Slot, "physical_perf_context");
      L->setOperand(0, B.CreateConstGEP1_64(B.getInt8Ty(), View, FieldOffset));
      L->setMetadata(LLVMContext::MD_tbaa, nullptr);
    }
    // Helper and tail-call operands still name the original physical context.
    F->setMemoryEffects(MemoryEffects::unknown());
    F->removeParamAttr(0, Attribute::Dereferenceable);
    F->removeParamAttr(0, Attribute::DereferenceableOrNull);
    if (verifyModule(*M, &errs())) return 1;
    std::error_code EC;
    ToolOutputFile Out(Output, EC, sys::fs::OF_None);
    if (EC) { errs() << EC.message() << '\n'; return 1; }
    PB.buildPerModuleDefaultPipeline(OptimizationLevel::O3).run(*M, MAM);
    legacy::PassManager Codegen;
    if (Machine->addPassesToEmitFile(Codegen, Out.os(), nullptr, CodeGenFileType::ObjectFile)) {
      errs() << "target cannot emit a native object\n"; return 1;
    }
    Codegen.run(*M); Out.keep();
    errs() << "PERF_EVENT LTO converted loads: " << Loads.size() << '\n';
  } catch (const std::exception &E) { errs() << E.what() << '\n'; return 1; }
}
