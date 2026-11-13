// Resolve the BPF frontend's CO-RE globals using the original ELF and libbpf.
#include "llvm/BinaryFormat/Dwarf.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/JSON.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"
extern "C" {
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include "relo_core.h"
}
#include <cstdlib>
#include <memory>
#include <map>
#include <vector>
using namespace llvm;
[[noreturn]] static void fail(const Twine &S) { errs()<<S<<'\n'; std::exit(1); }
static cl::opt<std::string> Input(cl::Positional,cl::Required);
static cl::opt<std::string> Output("o",cl::Required);
static cl::opt<std::string> Local("local-bpf",cl::Required);
static cl::opt<std::string> Target("target-btf",cl::Required);
static cl::opt<std::string> Report("report",cl::Required);
using BTF = std::unique_ptr<btf,decltype(&btf__free)>;
static BTF readBTF(StringRef Path) {
  btf *B=btf__parse(Path.str().c_str(),nullptr);
  if (!B || libbpf_get_error(B)) fail(Twine("parse BTF: ")+Path);
  return BTF(B,btf__free);
}
static unsigned kind(const DIType *D) {
  if (!D) fail("CO-RE global lacks a debug root type");
  switch (D->getTag()) {
    case dwarf::DW_TAG_structure_type: return BTF_KIND_STRUCT;
    case dwarf::DW_TAG_union_type: return BTF_KIND_UNION;
    case dwarf::DW_TAG_enumeration_type: return BTF_KIND_ENUM;
    case dwarf::DW_TAG_typedef: return BTF_KIND_TYPEDEF;
    case dwarf::DW_TAG_base_type: return BTF_KIND_INT;
    default: fail("CO-RE root debug kind is not a named aggregate/enum/typedef");
  }
}
static StringRef essence(StringRef S) { return S.take_front(bpf_core_essential_name_len(S.str().c_str())); }
static uint64_t number(StringRef S) {
  if (S.starts_with("-")) {
    int64_t Signed;
    if (S.getAsInteger(10,Signed)) fail("malformed signed CO-RE value");
    return uint64_t(Signed);
  }
  uint64_t N;
  if (S.getAsInteger(10,N)) fail(Twine("malformed CO-RE numeric component: ")+S);
  return N;
}
static bool directMemory(Value *Root) {
  SmallVector<Value *,16> Work{Root};SmallPtrSet<Value *,32> Seen;
  while (!Work.empty()) {
    auto *V=Work.pop_back_val();if (!Seen.insert(V).second) continue;
    for (auto *U:V->users()) {
      if (auto *L=dyn_cast<LoadInst>(U)) {
        if (L->getPointerOperand()==V) return true;
      } else if (auto *S=dyn_cast<StoreInst>(U)) {
        if (S->getPointerOperand()==V) return true;
      } else if (auto *Call=dyn_cast<CallInst>(U)) {
        auto *F=Call->getCalledFunction();
        if (F && F->getName().starts_with("llvm.bpf.passthrough.")) Work.push_back(Call);
      } else if (isa<GetElementPtrInst>(U) || isa<CastInst>(U) || isa<BinaryOperator>(U) || isa<PHINode>(U) || isa<SelectInst>(U))
        Work.push_back(U);
    }
  }
  return false;
}
int main(int argc,char **argv) {
  cl::ParseCommandLineOptions(argc,argv);
  auto L=readBTF(Local), T=readBTF(Target);
  LLVMContext C; SMDiagnostic Error; auto M=parseIRFile(Input,Error,C);
  if (!M) { Error.print(argv[0],errs()); return 1; }
  json::Array Rows;
  std::map<unsigned,std::vector<bpf_core_cand>> CandidateCache;
  SmallVector<GlobalVariable *,32> Globals;
  for (auto &G:M->globals())
    if (G.hasAttribute("btf_ama") || G.hasAttribute("btf_type_id")) Globals.push_back(&G);
  for (auto *G:Globals) {
    StringRef Name=G->getName();
    if (!Name.starts_with("llvm."))
      fail(Twine("unhandled BPF CO-RE global encoding: ")+Name);
    auto *D=dyn_cast_or_null<DIType>(G->getMetadata("llvm.preserve.access.index"));
    unsigned BKind=kind(D);
    StringRef Default,AccessSpec;
    unsigned K;
    bool TypeId=G->hasAttribute("btf_type_id");
    if (TypeId) {
      if (!Name.starts_with("llvm.btf_type_id.")) fail("malformed BPF type-ID global");
      auto Parts=Name.drop_front(17).split('$');
      number(Parts.first);
      K=number(Parts.second);AccessSpec="0";
      if (K!=BPF_CORE_TYPE_ID_LOCAL && K!=BPF_CORE_TYPE_ID_TARGET) fail("invalid BPF type-ID relocation kind");
    } else {
      auto TypeAndRest=Name.drop_front(5).split(':');
      auto KindAndRest=TypeAndRest.second.split(':');
      auto DefaultAndSpec=KindAndRest.second.split('$');
      if (TypeAndRest.first.empty() || DefaultAndSpec.second.empty()) fail("malformed BPF CO-RE global");
      if (D->getName()!=TypeAndRest.first) fail("CO-RE debug root/name mismatch");
      K=number(KindAndRest.first);Default=DefaultAndSpec.first;AccessSpec=DefaultAndSpec.second;
      if (K>BPF_CORE_TYPE_MATCHES) fail("unknown CO-RE relocation kind");
    }
    std::vector<unsigned> LocalIds;
    for (unsigned Id=1;Id<btf__type_cnt(L.get());++Id) {
      const auto *BT=btf__type_by_id(L.get(),Id);
      if ((btf_kind(BT)==BKind || (BKind==BTF_KIND_ENUM && btf_is_enum64(BT))) &&
          D->getName()==btf__name_by_offset(L.get(),BT->name_off)) LocalIds.push_back(Id);
    }
    if (LocalIds.size()!=1) fail(Twine("local BTF root absent or ambiguous: ")+D->getName());
    unsigned Id=LocalIds.front();
    if (auto *DC=dyn_cast<DICompositeType>(D)) {
      const auto *BT=btf__type_by_id(L.get(),Id);
      if (DC->getSizeInBits()!=uint64_t(BT->size)*8) fail("local BTF and IR root sizes differ");
      if (btf_is_composite(BT)) {
        auto Elements=DC->getElements();
        if (Elements.size()!=btf_vlen(BT)) fail("local BTF and IR member counts differ");
        for (unsigned I=0;I<Elements.size();++I) {
          auto *Field=dyn_cast<DIDerivedType>(Elements[I]);
          if (!Field || Field->getTag()!=dwarf::DW_TAG_member ||
              Field->getName()!=btf__name_by_offset(L.get(),btf_members(BT)[I].name_off) ||
              Field->getOffsetInBits()!=btf_member_bit_offset(BT,I))
            fail("local BTF and IR member layout differ");
        }
      }
    }
    int Access=btf__add_str(L.get(),AccessSpec.str().c_str());
    if (Access<0) fail("add CO-RE access string failed");
    bpf_core_relo R{};R.type_id=Id;R.access_str_off=Access;R.kind=bpf_core_relo_kind(K);
    auto [Position,Inserted]=CandidateCache.try_emplace(Id);
    auto &Candidates=Position->second;
    if (Inserted) for (unsigned N=1;N<btf__type_cnt(T.get());++N) {
        const auto *BT=btf__type_by_id(T.get(),N);
        if (essence(D->getName())!=essence(btf__name_by_offset(T.get(),BT->name_off))) continue;
        int Compatible=bpf_core_types_are_compat(L.get(),Id,T.get(),N);
        if (Compatible<0) fail("CO-RE candidate compatibility failed");
        if (Compatible) Candidates.push_back({T.get(),N});
    }
    bpf_core_cand_list List{Candidates.data(),int(Candidates.size())};
    bpf_core_spec Specs[3]{};bpf_core_relo_res Result{};
    int RC=bpf_core_calc_relo_insn("native-ir",&R,Rows.size(),L.get(),&List,Specs,&Result);
    if (RC) fail(Twine("CO-RE relocation failed: ")+Name+" rc="+Twine(RC));
    Candidates.resize(List.len);
    if (!TypeId && Result.validate && Result.orig_val!=number(Default))
      fail(Twine("local BTF default value differs from IR: ")+Name);
    bool Resize=false;
    if (!Result.poison && K==BPF_CORE_FIELD_BYTE_OFFSET && Result.orig_sz!=Result.new_sz) {
      int Original=btf__resolve_type(L.get(),Result.orig_type_id);
      if (Original<0) fail("resolve source field type failed");
      const auto *OT=btf__type_by_id(L.get(),Original);
      bool Scalar=btf_is_int(OT) || btf_is_enum(OT) || btf_is_enum64(OT) || btf_is_ptr(OT);
      if (Scalar) for (auto *U:G->users()) if (directMemory(U)) Resize=true;
    }
    json::Object Row{{"global",Name.str()},{"kind",int64_t(K)},{"local_type_id",int64_t(Id)},
                     {"original",int64_t(Result.orig_val)},{"resolved",int64_t(Result.new_val)},
                     {"poison",Result.poison},{"matching_candidates",List.len},
                     {"original_field_bytes",int64_t(Result.orig_sz)},{"target_field_bytes",int64_t(Result.new_sz)},
                     {"native_access_resize_pending",Resize}};
    SmallVector<LoadInst *,16> Loads;
    for (auto *U:G->users()) {
      auto *Load=dyn_cast<LoadInst>(U);
      if (!Load || Load->getPointerOperand()!=G || !Load->getType()->isIntegerTy() || Load->isAtomic())
        fail("CO-RE global has a non-load use");
      Loads.push_back(Load);
    }
    for (auto *Load:Loads) {
      Value *Value;
      if (Result.poison || Resize) {
        auto Fn=M->getOrInsertFunction(std::string(Resize?"__kprog_core_resize_":"__kprog_core_unresolved_")+std::to_string(Rows.size()),
                                      FunctionType::get(Load->getType(),false));
        Value=IRBuilder<>(Load).CreateCall(Fn);
      } else Value=ConstantInt::get(Load->getType(),Result.new_val);
      Load->replaceAllUsesWith(Value);Load->eraseFromParent();
    }
    G->eraseFromParent();Rows.push_back(std::move(Row));
  }
  // Fold the frontend's identity markers so resolved guards can eliminate dead
  // missing-field references just as the original BPF load does.
  SmallVector<CallInst *,32> Identity;
  for (auto &F:*M) for (auto &I:instructions(F)) if (auto *Call=dyn_cast<CallInst>(&I))
    if (auto *Fn=Call->getCalledFunction()) if (Fn->getName().starts_with("llvm.bpf.passthrough.")) Identity.push_back(Call);
  for (auto *Call:Identity) {
    if (Call->arg_size()!=2 || Call->getType()!=Call->getArgOperand(1)->getType()) fail("invalid BPF passthrough signature");
    Call->replaceAllUsesWith(Call->getArgOperand(1));Call->eraseFromParent();
  }
  LoopAnalysisManager LAM;FunctionAnalysisManager FAM;CGSCCAnalysisManager CGAM;ModuleAnalysisManager MAM;
  PassBuilder PB;PB.registerModuleAnalyses(MAM);PB.registerCGSCCAnalyses(CGAM);
  PB.registerFunctionAnalyses(FAM);PB.registerLoopAnalyses(LAM);PB.crossRegisterProxies(LAM,FAM,CGAM,MAM);
  auto Pipeline=PB.buildPerModuleDefaultPipeline(OptimizationLevel::O2);Pipeline.run(*M,MAM);
  std::error_code EC;
  ToolOutputFile ReportFile(Report,EC,sys::fs::OF_Text);
  if (EC) fail(EC.message());
  ReportFile.os()<<formatv("{0:2}",json::Value(std::move(Rows)))<<'\n';ReportFile.keep();
  for (auto &F:*M) if (!F.use_empty()) {
    if (F.getName().starts_with("__kprog_core_unresolved_")) fail(Twine("reachable unresolved CO-RE relocation: ")+F.getName());
    if (F.getName().starts_with("__kprog_core_resize_")) fail(Twine("native scalar access resizing remains required: ")+F.getName());
  }
  if (verifyModule(*M,&errs())) return 1;
  ToolOutputFile Out(Output,EC,sys::fs::OF_None);if (EC) fail(EC.message());
  WriteBitcodeToFile(*M,Out.os());Out.keep();
  errs()<<"resolved CO-RE globals="<<Globals.size()<<"\n";
}
