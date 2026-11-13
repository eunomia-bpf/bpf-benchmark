// Resolve native C CO-RE query expressions and flavored fields against BTF.
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Lex/Lexer.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace clang;
static std::string essence(std::string Name) { return Name.substr(0, Name.find("___")); }
struct View {
  unsigned Id = 0, Pointers = 0, Bits = 0;
  uint64_t Offset = 0;
  explicit operator bool() const { return Id != 0; }
};
struct Edit { unsigned Begin, End; std::string Text; };

class Lower : public RecursiveASTVisitor<Lower> {
  ASTContext &C;
  const btf *B;
  std::string Code;
  std::vector<Edit> Edits;
  unsigned Queries = 0, Accesses = 0;
  bool Failed = false;

  unsigned strip(unsigned Id) const {
    while (Id) {
      const auto *T = btf__type_by_id(B, Id);
      if (!btf_is_mod(T) && !btf_is_typedef(T) && !btf_is_type_tag(T)) break;
      Id = T->type;
    }
    return Id;
  }
  View named(const std::string &Name, unsigned Kind) const {
    int Id = btf__find_by_name_kind(B, essence(Name).c_str(), Kind);
    return {Id > 0 ? unsigned(Id) : 0};
  }
  View fromType(QualType Q) const {
    Q = Q.getUnqualifiedType();
    if (auto *T = Q->getAs<TypedefType>()) {
      auto V = named(T->getDecl()->getNameAsString(), BTF_KIND_TYPEDEF);
      if (V) return V;
      return {};
    }
    if (Q->isPointerType()) {
      auto V = fromType(Q->getPointeeType());
      ++V.Pointers;
      return V;
    }
    if (auto *T = Q->getAs<RecordType>())
      return named(T->getDecl()->getNameAsString(), T->getDecl()->isUnion() ? BTF_KIND_UNION : BTF_KIND_STRUCT);
    if (auto *T = Q->getAs<EnumType>()) {
      auto V = named(T->getDecl()->getNameAsString(), BTF_KIND_ENUM);
      return V ? V : named(T->getDecl()->getNameAsString(), BTF_KIND_ENUM64);
    }
    return {};
  }
  View pointee(View V) const {
    if (!V) return {};
    if (V.Pointers) { --V.Pointers; return V; }
    auto *T = btf__type_by_id(B, strip(V.Id));
    if (btf_is_ptr(T)) return {T->type};
    if (btf_is_array(T)) return {btf_array(T)->type};
    return {};
  }
  View member(View Parent, llvm::StringRef Name) const {
    if (!Parent || Parent.Pointers) return {};
    auto *T = btf__type_by_id(B, strip(Parent.Id));
    if (!btf_is_composite(T)) return {};
    auto *Fields = btf_members(T);
    for (unsigned I = 0; I < btf_vlen(T); ++I) {
      llvm::StringRef FieldName = btf__name_by_offset(B, Fields[I].name_off);
      uint64_t Offset = btf_member_bit_offset(T, I);
      if (FieldName == Name)
        return {Fields[I].type, 0, btf_member_bitfield_size(T, I), Offset};
      if (FieldName.empty()) {
        auto V = member({Fields[I].type}, Name);
        if (V) { V.Offset += Offset; return V; }
      }
    }
    return {};
  }
  View resolve(const Expr *E) const {
    E = E->IgnoreParenImpCasts();
    if (auto *M = dyn_cast<MemberExpr>(E)) {
      auto Parent = resolve(M->getBase());
      if (M->isArrow()) Parent = pointee(Parent);
      return member(Parent, M->getMemberNameInfo().getAsString());
    }
    if (auto *A = dyn_cast<ArraySubscriptExpr>(E)) return pointee(resolve(A->getBase()));
    if (auto *U = dyn_cast<UnaryOperator>(E)) {
      if (U->getOpcode() == UO_Deref) return pointee(resolve(U->getSubExpr()));
      if (U->getOpcode() == UO_AddrOf) { auto V = resolve(U->getSubExpr()); ++V.Pointers; return V; }
    }
    return fromType(E->getType());
  }
  std::pair<unsigned, unsigned> range(const Expr *E) const {
    auto &SM = C.getSourceManager();
    auto R = CharSourceRange::getTokenRange(E->getSourceRange());
    R = Lexer::makeFileCharRange(R, SM, C.getLangOpts());
    if (R.isInvalid() || !SM.isWrittenInMainFile(R.getBegin())) return {0, 0};
    return {SM.getFileOffset(R.getBegin()), SM.getFileOffset(R.getEnd())};
  }
  std::string render(unsigned Begin, unsigned End) const {
    std::vector<Edit> Children;
    for (const auto &E : Edits)
      if (E.Begin >= Begin && E.End <= End) Children.push_back(E);
    std::sort(Children.begin(), Children.end(), [](const Edit &A, const Edit &B) {
      return A.Begin < B.Begin || (A.Begin == B.Begin && A.End > B.End);
    });
    std::string Result;
    unsigned At = Begin;
    for (const auto &E : Children) {
      if (E.Begin < At) continue;
      Result += Code.substr(At, E.Begin - At) + E.Text;
      At = E.End;
    }
    return Result + Code.substr(At, End - At);
  }
  std::string render(const Expr *E) const { auto R = range(E); return render(R.first, R.second); }
  void replace(const Expr *E, std::string Text) {
    auto R = range(E);
    if (R.first == R.second) { Failed = true; return; }
    // A parent expression supersedes all edits within its source interval.
    Edits.erase(std::remove_if(Edits.begin(), Edits.end(), [&](const Edit &Child) {
      return Child.Begin >= R.first && Child.End <= R.second;
    }), Edits.end());
    Edits.push_back({R.first, R.second, std::move(Text)});
  }
  int64_t size(View V) const {
    if (!V) return -1;
    return V.Pointers ? C.getTypeSize(C.VoidPtrTy) / 8 : btf__resolve_size(B, V.Id);
  }

public:
  Lower(ASTContext &Context, const btf *Target, std::string Source)
      : C(Context), B(Target), Code(std::move(Source)) {}
  bool shouldTraversePostOrder() const { return true; }
  bool VisitCallExpr(CallExpr *Call) {
    auto *Fn = Call->getDirectCallee();
    if (!Fn || Call->getNumArgs() != 1) return true;
    std::string Name = Fn->getNameAsString();
    if (Name.rfind("__kprog_core_", 0) != 0 || Name.find("missing") != std::string::npos) return true;
    auto *Arg = Call->getArg(0)->IgnoreParenImpCasts();
    auto V = resolve(Arg);
    std::string Value;
    if (Name == "__kprog_core_field_exists") Value = V ? "1UL" : "0UL";
    else if (Name == "__kprog_core_type_exists") Value = pointee(V) ? "1UL" : "0UL";
    else if (Name == "__kprog_core_field_size" || Name == "__kprog_core_type_size") {
      auto N = size(Name == "__kprog_core_type_size" ? pointee(V) : V);
      Value = N >= 0 ? std::to_string(N) + "UL" : "__kprog_core_missing_value()";
    } else if (Name == "__kprog_core_enum_exists" || Name == "__kprog_core_enum_value") {
      auto *Cast = dyn_cast<ExplicitCastExpr>(Arg);
      auto *Ref = Cast ? dyn_cast<DeclRefExpr>(Cast->getSubExpr()->IgnoreParenImpCasts()) : nullptr;
      auto *Enumerator = Ref ? dyn_cast<EnumConstantDecl>(Ref->getDecl()) : nullptr;
      if (!Enumerator) { llvm::errs() << "CO-RE enum query requires an enumerator\n"; Failed = true; return true; }
      std::string Wanted = essence(Enumerator->getNameAsString());
      bool Found = false;
      uint64_t Number = 0;
      if (V) {
        auto *T = btf__type_by_id(B, strip(V.Id));
        if (btf_is_enum(T) || btf_is_enum64(T))
          for (unsigned I = 0; I < btf_vlen(T); ++I) {
            unsigned NameOff = btf_is_enum(T) ? btf_enum(T)[I].name_off : btf_enum64(T)[I].name_off;
            if (Wanted != btf__name_by_offset(B, NameOff)) continue;
            Found = true;
            Number = btf_is_enum(T) ? uint64_t(int64_t(btf_enum(T)[I].val)) : btf_enum64_value(&btf_enum64(T)[I]);
          }
      }
      Value = Name == "__kprog_core_enum_exists" ? (Found ? "1UL" : "0UL") :
              Found ? std::to_string(Number) + "ULL" : "__kprog_core_missing_value()";
    } else { llvm::errs() << "unknown CO-RE query " << Name << '\n'; Failed = true; return true; }
    replace(Call, "(" + Value + ")");
    ++Queries;
    return true;
  }
  bool VisitMemberExpr(MemberExpr *M) {
    auto *Field = dyn_cast<FieldDecl>(M->getMemberDecl());
    if (!Field || Field->getParent()->getName().find("___") == llvm::StringRef::npos) return true;
    auto R = range(M);
    if (R.first == R.second) return true;
    std::string Original = Code.substr(R.first, R.second - R.first);
    auto V = resolve(M);
    if (!V) {
      // Code generation diagnoses this marker if it survives existence folding.
      replace(M, "(*(__typeof__(" + Original + ") *)__kprog_core_missing_field())");
    } else {
      std::string Base = render(M->getBase());
      std::string Address = "((char *)" + std::string(M->isArrow() ? "(" : "&(") + Base + ") + " + std::to_string(V.Offset / 8) + ")";
      if (V.Bits) {
        unsigned Width = 1;
        while (Width * 8 < V.Bits + V.Offset % 8) Width *= 2;
        if (Width > 8) { llvm::errs() << "CO-RE bitfield exceeds 64-bit storage\n"; Failed = true; return true; }
        auto *T = btf__type_by_id(B, strip(V.Id));
        bool Signed = btf_is_int(T) && (btf_int_encoding(T) & BTF_INT_SIGNED);
        std::string Shifted = "(__v >> " + std::to_string(V.Offset % 8) + ")";
        std::string Value = Signed ? "(((long long)(" + Shifted + " << " + std::to_string(64 - V.Bits) + ")) >> " + std::to_string(64 - V.Bits) + ")" :
                            "(" + Shifted + " & (0xffffffffffffffffULL >> " + std::to_string(64 - V.Bits) + "))";
        replace(M, "({ unsigned long long __v = 0; __builtin_memcpy(&__v, " + Address + ", " + std::to_string(Width) + "); (" + M->getType().getAsString() + ")" + Value + "; })");
      } else replace(M, "(*(__typeof__(" + Original + ") *)" + Address + ")");
    }
    ++Accesses;
    return true;
  }
  bool write(llvm::StringRef Output) {
    if (Failed) return false;
    std::error_code EC;
    llvm::raw_fd_ostream Out(Output, EC, llvm::sys::fs::OF_Text);
    if (EC) { llvm::errs() << EC.message() << '\n'; return false; }
    Out << render(0, Code.size());
    llvm::errs() << "CO-RE queries=" << Queries << " flavored accesses=" << Accesses << '\n';
    return true;
  }
};

int main(int argc, char **argv) {
  if (argc != 4) { llvm::errs() << "usage: core-flavor-lower INPUT.i OUTPUT.i KERNEL_BTF\n"; return 1; }
  auto Source = llvm::MemoryBuffer::getFile(argv[1]);
  if (!Source) { llvm::errs() << Source.getError().message() << '\n'; return 1; }
  btf *B = btf__parse_elf(argv[3], nullptr);
  if (!B || libbpf_get_error(B)) { llvm::errs() << "parse target BTF failed\n"; return 1; }
  auto AST = tooling::buildASTFromCodeWithArgs((*Source)->getBuffer(),
      {"-xc", "-fms-extensions", "-Wno-deprecated-non-prototype", "-Wno-unknown-attributes"}, argv[1]);
  if (!AST || AST->getDiagnostics().hasErrorOccurred()) { btf__free(B); return 1; }
  Lower Pass(AST->getASTContext(), B, (*Source)->getBuffer().str());
  Pass.TraverseDecl(AST->getASTContext().getTranslationUnitDecl());
  bool OK = Pass.write(argv[2]);
  btf__free(B);
  return OK ? 0 : 1;
}
