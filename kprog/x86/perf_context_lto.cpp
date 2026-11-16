// Trusted load-time native LTO: current-load functions, data and context ABI.
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/ADT/SmallPtrSet.h"
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
#include "bpf_function_bodies.hpp"
#include "runtime_bpf_callee.hpp"
#include <memory>
#include <functional>
using namespace llvm;

static cl::opt<std::string> Input(cl::Positional, cl::Required);
static cl::opt<std::string> Output("o", cl::Required);
static cl::opt<std::string> Kernel("kernel-btf", cl::Required);
static cl::opt<std::string> Symbol("symbol", cl::Required);
static cl::opt<unsigned> ProgType("prog-type", cl::init(BPF_PROG_TYPE_PERF_EVENT));
static cl::opt<std::string> FunctionBodies("bpf-function-bodies");
static cl::opt<std::string> ImmutableGlobals("immutable-globals");
static cl::opt<std::string> MapTypes("map-types");

struct NativeMapType {
  int64_t type = 0, inner = 0;
  bool operator==(const NativeMapType &Other) const {
    return type == Other.type && inner == Other.inner;
  }
};

static bool isMapLookup(const CallBase &Call) {
  auto *Callee = Call.getCalledOperand()->stripPointerCasts();
  if (auto *F = dyn_cast<Function>(Callee)) return F->getName() == "bpf_map_lookup_elem";
  auto *Cast = dyn_cast<ConstantExpr>(Callee);
  if (!Cast || Cast->getOpcode() != Instruction::IntToPtr) return false;
  auto *ID = dyn_cast<ConstantInt>(Cast->getOperand(0));
  return ID && ID->equalsInt(BPF_FUNC_map_lookup_elem);
}

static Expected<unsigned> lowerArrayLookups(Module &M, Function &Entry, StringRef Path) {
  if (Path.empty()) return 0;
  auto File = MemoryBuffer::getFile(Path);
  if (!File) return errorCodeToError(File.getError());
  auto Document = json::parse((*File)->getBuffer());
  if (!Document) return Document.takeError();
  auto *Object = Document->getAsObject();
  if (!Object) return native_bpf::failure("map types require an object");
  DenseMap<const Value *, NativeMapType> Known;
  SmallPtrSet<const Value *, 32> Active;
  for (auto &Item : *Object) {
    auto *Fields = Item.second.getAsObject();
    auto *Global = M.getNamedGlobal(Item.first);
    if (!Fields || !Global) continue;
    auto Type = Fields->getInteger("type"), Inner = Fields->getInteger("inner_type");
    if (!Type || !Inner) continue;
    Known[Global] = {*Type, *Inner};
    // These are handles rebound to kernel objects, not native map-definition
    // storage. Do not let later optimization read their C initializers.
    Global->setInitializer(nullptr);
    Global->setLinkage(GlobalValue::ExternalLinkage);
    Global->setDSOLocal(false);
  }
  std::function<NativeMapType(Value *)> Infer = [&](Value *V) -> NativeMapType {
    V = V->stripPointerCasts();
    if (auto Found = Known.find(V); Found != Known.end()) return Found->second;
    if (!Active.insert(V).second) return {};
    NativeMapType Type;
    auto Meet = [&](ArrayRef<Value *> Values) {
      NativeMapType Common;
      bool First = true;
      for (auto *Input : Values) {
        auto Current = Infer(Input);
        if (First) { Common = Current; First = false; }
        else if (!(Common == Current)) return NativeMapType{};
      }
      return Common;
    };
    if (auto *Phi = dyn_cast<PHINode>(V)) {
      SmallVector<Value *, 16> Inputs(Phi->incoming_values());
      Type = Meet(Inputs);
    } else if (auto *Select = dyn_cast<SelectInst>(V)) {
      Type = Meet({Select->getTrueValue(), Select->getFalseValue()});
    } else if (auto *Call = dyn_cast<CallBase>(V)) {
      if (Call->arg_size() == 2 && isMapLookup(*Call)) {
        auto Outer = Infer(Call->getArgOperand(0));
        if (Outer.type == BPF_MAP_TYPE_ARRAY_OF_MAPS || Outer.type == BPF_MAP_TYPE_HASH_OF_MAPS)
          Type.type = Outer.inner;
      }
    } else if (auto *Load = dyn_cast<LoadInst>(V)) {
      auto *GEP = dyn_cast<GEPOperator>(Load->getPointerOperand());
      // An inbounds element load from an immutable pointer table can return
      // only an element of that table. Every alternative must have one type.
      if (!Load->isVolatile() && !Load->isAtomic() && GEP && GEP->isInBounds() &&
          GEP->getNumIndices() == 2 && isa<ConstantInt>(GEP->getOperand(1)) &&
          cast<ConstantInt>(GEP->getOperand(1))->isZero()) {
        auto *Table = dyn_cast<GlobalVariable>(GEP->getPointerOperand());
        auto *Array = Table && Table->isConstant() && Table->hasInitializer()
                        ? dyn_cast<ConstantArray>(Table->getInitializer()) : nullptr;
        if (Array && Array->getType()->getElementType()->isPointerTy()) {
          SmallVector<Value *, 16> Inputs;
          for (auto &Element : Array->operands()) Inputs.push_back(Element.get());
          Type = Meet(Inputs);
        }
      }
    }
    Active.erase(V);
    Known[V] = Type;
    return Type;
  };
  SmallVector<Function *, 16> Functions{&Entry};
  SmallPtrSet<Function *, 16> Seen;
  SmallVector<CallBase *, 64> Calls;
  while (!Functions.empty()) {
    auto *F = Functions.pop_back_val();
    if (!Seen.insert(F).second || F->isDeclaration()) continue;
    for (auto &I : instructions(F)) if (auto *Call = dyn_cast<CallBase>(&I)) {
      if (isMapLookup(*Call) && Call->arg_size() == 2 && Call->getType()->isPointerTy() &&
          Call->getArgOperand(0)->getType()->isPointerTy() &&
          Call->getArgOperand(1)->getType()->isPointerTy() &&
          !isa<GlobalVariable>(Call->getArgOperand(0)->stripPointerCasts()) &&
          Infer(Call->getArgOperand(0)).type == BPF_MAP_TYPE_ARRAY)
        Calls.push_back(Call);
      else if (auto *Callee = Call->getCalledFunction()) Functions.push_back(Callee);
    }
  }
  if (Calls.empty()) return 0;
  std::unique_ptr<btf, decltype(&btf__free)> Types(btf__parse(Kernel.c_str(), nullptr), btf__free);
  if (!Types) return native_bpf::failure("cannot read array lookup kernel BTF");
  auto &C = M.getContext();
  auto *Ptr = PointerType::getUnqual(C);
  auto *Signature = FunctionType::get(Ptr, {Ptr, Ptr}, false);
  auto *Lookup = Function::Create(Signature, GlobalValue::InternalLinkage,
                                 "__native_link_typed_array_lookup", M);
  Lookup->addFnAttr(Attribute::NoInline);
  Lookup->addFnAttr(Attribute::NoUnwind);
  auto *Begin = BasicBlock::Create(C, "entry", Lookup);
  auto *Found = BasicBlock::Create(C, "found", Lookup);
  auto *Missing = BasicBlock::Create(C, "missing", Lookup);
  IRBuilder<> B(Begin);
  auto *Map = Lookup->getArg(0), *Key = Lookup->getArg(1);
  auto Load32 = [&](Value *Base, unsigned Offset) {
    auto *Load = B.CreateLoad(B.getInt32Ty(), B.CreateConstGEP1_64(B.getInt8Ty(), Base, Offset));
    Load->setAlignment(Align(1));
    return Load;
  };
  auto *Index = Load32(Key, 0);
  auto *Limit = Load32(Map, native_lto::offset(Types.get(), "bpf_map", "max_entries", true));
  B.CreateCondBr(B.CreateICmpULT(Index, Limit), Found, Missing);
  B.SetInsertPoint(Missing);
  B.CreateRet(ConstantPointerNull::get(Ptr));
  B.SetInsertPoint(Found);
  auto Base = native_lto::offset(Types.get(), "bpf_array", "map");
  auto *Mask = Load32(Map, native_lto::relative(Types.get(), "bpf_array", "index_mask", Base, true));
  auto *Stride = Load32(Map, native_lto::relative(Types.get(), "bpf_array", "elem_size", Base, true));
  auto *Offset = B.CreateMul(B.CreateZExt(B.CreateAnd(Index, Mask), B.getInt64Ty()),
                             B.CreateZExt(Stride, B.getInt64Ty()));
  auto *Values = B.CreateConstGEP1_64(B.getInt8Ty(), Map,
                 native_lto::relative(Types.get(), "bpf_array", "value", Base));
  B.CreateRet(B.CreateGEP(B.getInt8Ty(), Values, Offset));
  for (auto *Call : Calls) Call->setCalledFunction(Signature, Lookup);
  return Calls.size();
}

static Expected<unsigned> foldImmutableGlobals(Module &M, StringRef Path) {
  if (Path.empty()) return 0;
  auto Facts = MemoryBuffer::getFile(Path);
  if (!Facts) return errorCodeToError(Facts.getError());
  auto Document = json::parse((*Facts)->getBuffer());
  if (!Document) return Document.takeError();
  auto *Values = Document->getAsObject();
  if (!Values) return native_bpf::failure("immutable globals require an object");
  const auto &DL = M.getDataLayout();
  SmallVector<LoadInst *, 32> Loads;
  for (auto &F : M) for (auto &I : instructions(F))
    if (auto *L = dyn_cast<LoadInst>(&I)) Loads.push_back(L);
  unsigned Folded = 0;
  for (auto *L : Loads) {
    int64_t Offset = 0;
    auto *G = dyn_cast<GlobalVariable>(GetPointerBaseWithConstantOffset(
        L->getPointerOperand(), Offset, DL));
    // Aggregate layouts can differ between BPF and native. Only consume a
    // complete scalar whose native storage matches its bound DATASEC bytes.
    if (!G || Offset || L->isAtomic() || !G->getValueType()->isIntegerTy() ||
        G->getValueType() != L->getType() || L->getType()->getIntegerBitWidth() > 64) continue;
    auto Text = Values->getString(G->getName());
    const auto Width = DL.getTypeStoreSize(L->getType()).getFixedValue();
    if (!Text || Text->size() != Width * 2) continue;
    uint64_t Bits = 0;
    for (size_t I = 0; I < Width; ++I) {
      unsigned Byte;
      if (Text->substr(I * 2, 2).getAsInteger(16, Byte))
        return native_bpf::failure("malformed immutable scalar bytes");
      Bits |= uint64_t(Byte) << (8 * (DL.isLittleEndian() ? I : Width - I - 1));
    }
    L->replaceAllUsesWith(ConstantInt::get(L->getType(), Bits));
    L->eraseFromParent(); ++Folded;
  }
  return Folded;
}

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
    if (!Found) { errs() << "native LTO needs embedded LLVM IR in P\n"; return 1; }
  }
  auto M = parseIR(Buffer, Error, C);
  if (!M) { Error.print(argv[0], errs()); return 1; }
  if (!FunctionBodies.empty()) {
    auto Facts = MemoryBuffer::getFile(FunctionBodies);
    if (!Facts) { errs() << Facts.getError().message() << '\n'; return 1; }
    auto Document = json::parse((*Facts)->getBuffer());
    if (!Document) { errs() << toString(Document.takeError()) << '\n'; return 1; }
    unsigned index = 0;
    const auto callee_compiler = std::filesystem::path(argv[0]).parent_path() / "kprog-bpf-callee-ir";
    auto lower = [&](Function &function, ArrayRef<bpf_insn> code) -> llvm::Error {
      auto *entry = M->getFunction(Symbol);
      if (!entry) return native_bpf::failure("native LTO entry is missing: " + Symbol);
      return lowerRuntimeBpfCallee(function, code, *entry, callee_compiler,
                                   Output + ".callee." + std::to_string(index++));
    };
    if (auto E = native_bpf::materializeFunctions(*M, *Document, lower)) {
      errs() << toString(std::move(E)) << '\n'; return 1;
    }
  }
  auto *F = M->getFunction(Symbol);
  if (!F || F->isDeclaration() || F->arg_empty()) {
    errs() << "native LTO entry is missing: " << Symbol << '\n'; return 1;
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
  auto Folded = foldImmutableGlobals(*M, ImmutableGlobals);
  if (!Folded) { errs() << toString(Folded.takeError()) << '\n'; return 1; }
  if (!ImmutableGlobals.empty()) errs() << "immutable scalar loads folded: " << *Folded << '\n';
  LoopAnalysisManager LAM; FunctionAnalysisManager FAM;
  CGSCCAnalysisManager CGAM; ModuleAnalysisManager MAM;
  PassBuilder PB(Machine.get());
  PB.registerModuleAnalyses(MAM); PB.registerCGSCCAnalyses(CGAM);
  PB.registerFunctionAnalyses(FAM); PB.registerLoopAnalyses(LAM);
  PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
  // Embedded cc1 IR precedes promotion/inlining; expose its context uses first.
  PB.buildPerModuleDefaultPipeline(OptimizationLevel::O3).run(*M, MAM);
  try {
    unsigned Converted = 0;
    if (ProgType == BPF_PROG_TYPE_PERF_EVENT) {
      std::unique_ptr<btf, decltype(&btf__free)> Types(
        btf__parse(Kernel.c_str(), nullptr), btf__free);
      if (!Types) { errs() << "cannot read boot kernel BTF\n"; return 1; }
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
      Converted = Loads.size();
    }
    auto Arrays = lowerArrayLookups(*M, *F, MapTypes);
    if (!Arrays) { errs() << toString(Arrays.takeError()) << '\n'; return 1; }
    if (!MapTypes.empty()) errs() << "typed ARRAY lookups lowered: " << *Arrays << '\n';
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
    if (ProgType == BPF_PROG_TYPE_PERF_EVENT)
      errs() << "PERF_EVENT LTO converted loads: " << Converted << '\n';
  } catch (const std::exception &E) { errs() << E.what() << '\n'; return 1; }
}
