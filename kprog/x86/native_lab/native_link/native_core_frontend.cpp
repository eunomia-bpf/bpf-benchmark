// Resolve native C CO-RE expressions before optimization, using libbpf's resolver.
#include <clang/AST/ASTContext.h>
#include <clang/AST/Attr.h>
#include <clang/AST/RecordLayout.h>
#include <clang/AST/ParentMapContext.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/ASTUnit.h>
#include <clang/Lex/Lexer.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/MemoryBuffer.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
extern "C" {
#include "btf.h"
#include "libbpf.h"
#include "relo_core.h"
int bpf_core_add_cands(struct bpf_core_cand *, size_t, const struct btf *, const char *, int, struct bpf_core_cand_list *);
}
using namespace clang;
static void require(bool v, const std::string &message) { if (!v) throw std::runtime_error(message); }

// Build source BTF from the actual native AST. Assign IDs before serializing,
// so recursive pointers and records keep their source identity and layout.
class SourceBTF {
  ASTContext &C;
  std::vector<QualType> Types;
  std::map<const void *, uint32_t> IDs;
  std::vector<char> Strings{0};
  std::map<std::string, uint32_t> StringIDs;
  std::vector<unsigned char> Data;
  uint32_t str(llvm::StringRef name) {
    if (name.empty()) return 0;
    auto found = StringIDs.find(name.str());
    if (found != StringIDs.end()) return found->second;
    uint32_t n = Strings.size();
    Strings.insert(Strings.end(), name.begin(), name.end()); Strings.push_back(0);
    return StringIDs[name.str()] = n;
  }
  template<class T> void put(const T &v) {
    auto *p = reinterpret_cast<const unsigned char *>(&v); Data.insert(Data.end(), p, p + sizeof(v));
  }
  void head(uint32_t name, unsigned kind, uint32_t size, unsigned count = 0, bool flag = false) {
    struct btf_type t{}; t.name_off = name; t.info = kind << 24 | count | (uint32_t(flag) << 31); t.size = size; put(t);
  }
public:
  explicit SourceBTF(ASTContext &context) : C(context) {}
  std::vector<const FieldDecl *> fields(const RecordDecl *r) {
    std::vector<const FieldDecl *> out;
    for (auto *f : r->fields()) if (!f->isZeroLengthBitField(C)) out.push_back(f);
    return out;
  }
  uint32_t id(QualType q) {
    q = q.getLocalUnqualifiedType(); const Type *t = q.getTypePtr();
    if (auto *e = dyn_cast<ElaboratedType>(t)) return id(e->getNamedType());
    if (auto *a = dyn_cast<AttributedType>(t)) return id(a->getModifiedType());
    if (auto *p = dyn_cast<ParenType>(t)) return id(p->getInnerType());
    if (auto *p = dyn_cast<TypeOfType>(t)) return id(p->getUnmodifiedType());
    if (auto *p = dyn_cast<TypeOfExprType>(t)) return id(p->getUnderlyingExpr()->getType());
    if (auto *p = dyn_cast<DecltypeType>(t)) return id(p->getUnderlyingType());
    if (!isa<TypedefType>(t)) { auto desugared = q.getSingleStepDesugaredType(C); if (desugared != q) return id(desugared); }
    if (t->isVoidType()) return 0;
    auto found = IDs.find(q.getAsOpaquePtr()); if (found != IDs.end()) return found->second;
    uint32_t n = Types.size() + 1; IDs[q.getAsOpaquePtr()] = n; Types.push_back(q);
    if (auto *a = dyn_cast<TypedefType>(t)) id(a->getDecl()->getUnderlyingType());
    else if (auto *p = dyn_cast<PointerType>(t)) id(p->getPointeeType());
    else if (auto *a = C.getAsArrayType(q)) { id(a->getElementType()); id(C.UnsignedIntTy); }
    else if (auto *r = t->getAs<RecordType>()) {
      if (auto *d = r->getDecl()->getDefinition()) for (auto *f : fields(d)) id(f->getType());
    } else if (auto *f = t->getAs<FunctionProtoType>()) {
      id(f->getReturnType()); for (auto p : f->param_types()) id(p);
    } else if (auto *f = t->getAs<FunctionNoProtoType>()) id(f->getReturnType());
    else if (auto *a = dyn_cast<AtomicType>(t)) id(a->getValueType());
    else require(t->isBuiltinType() || t->isEnumeralType(), "unsupported source BTF type: " + q.getAsString());
    return n;
  }
  uint32_t member(const FieldDecl *f) {
    auto fs = fields(f->getParent()->getDefinition());
    auto it = std::find(fs.begin(), fs.end(), f); require(it != fs.end(), "missing source BTF member");
    return it - fs.begin();
  }
  btf *build() {
    for (size_t i = 0; i < Types.size(); ++i) {
      QualType q = Types[i]; const Type *t = q.getTypePtr();
      if (auto *a = dyn_cast<TypedefType>(t)) head(str(a->getDecl()->getName()), BTF_KIND_TYPEDEF, id(a->getDecl()->getUnderlyingType()));
      else if (auto *p = dyn_cast<PointerType>(t)) head(0, BTF_KIND_PTR, id(p->getPointeeType()));
      else if (auto *a = C.getAsArrayType(q)) {
        uint64_t count = 0; if (auto *ca = dyn_cast<ConstantArrayType>(a)) count = ca->getSize().getZExtValue();
        else require(isa<IncompleteArrayType>(a), "variable source BTF array");
        require(count <= UINT32_MAX, "source BTF array too large");
        head(0, BTF_KIND_ARRAY, 0); struct btf_array x{id(a->getElementType()), id(C.UnsignedIntTy), uint32_t(count)}; put(x);
      } else if (auto *r = t->getAs<RecordType>()) {
        auto *d = r->getDecl()->getDefinition();
        if (!d) { head(str(r->getDecl()->getName()), BTF_KIND_FWD, 0, 0, r->getDecl()->isUnion()); continue; }
        auto fs = fields(d); bool bits = std::any_of(fs.begin(), fs.end(), [](auto *f) { return f->isBitField(); });
        auto &layout = C.getASTRecordLayout(d);
        head(str(d->getName()), d->isUnion() ? BTF_KIND_UNION : BTF_KIND_STRUCT, layout.getSize().getQuantity(), fs.size(), bits);
        for (auto *f : fs) {
          uint64_t off = layout.getFieldOffset(f->getFieldIndex()); unsigned width = f->isBitField() ? f->getBitWidthValue(C) : 0;
          require(off <= (bits ? 0xffffffU : UINT32_MAX) && width < 256, "unrepresentable source BTF bit field");
          btf_member x{str(f->getName()), id(f->getType()), uint32_t(off) | width << 24}; put(x);
        }
      } else if (auto *e = t->getAs<EnumType>()) {
        auto *d = e->getDecl()->getDefinition(); require(d != nullptr, "incomplete source enum");
        auto count = std::distance(d->enumerator_begin(), d->enumerator_end());
        bool wide = C.getTypeSize(q) > 32;
        head(str(d->getName()), wide ? BTF_KIND_ENUM64 : BTF_KIND_ENUM, C.getTypeSizeInChars(q).getQuantity(), count, d->getIntegerType()->isSignedIntegerType());
        for (auto *v : d->enumerators()) {
          auto value = v->getInitVal(); require(value.getBitWidth() <= 64, "source enum wider than 64 bits");
          uint64_t n = value.isSigned() ? uint64_t(value.getSExtValue()) : value.getZExtValue();
          if (wide) { struct btf_enum64 x{str(v->getName()), uint32_t(n), uint32_t(n >> 32)}; put(x); }
          else { struct btf_enum x{str(v->getName()), int32_t(n)}; put(x); }
        }
      } else if (auto *f = t->getAs<FunctionType>()) {
        auto *p = dyn_cast<FunctionProtoType>(f); unsigned count = p ? p->getNumParams() + p->isVariadic() : 0;
        head(0, BTF_KIND_FUNC_PROTO, id(f->getReturnType()), count);
        if (p) { for (auto a : p->param_types()) { btf_param x{0, id(a)}; put(x); } if (p->isVariadic()) { btf_param x{}; put(x); } }
      } else if (auto *a = dyn_cast<AtomicType>(t)) head(0, BTF_KIND_TYPEDEF, id(a->getValueType()));
      else {
        auto size = C.getTypeSizeInChars(q).getQuantity();
        if (t->isRealFloatingType()) head(str(q.getAsString()), BTF_KIND_FLOAT, size);
        else { require(t->isIntegerType() && size <= 16, "unsupported scalar BTF type"); head(str(q.getAsString()), BTF_KIND_INT, size); uint32_t enc = (uint32_t(t->isSignedIntegerType() ? BTF_INT_SIGNED : 0) | uint32_t(t->isBooleanType() ? BTF_INT_BOOL : 0)) << 24 | C.getTypeSize(q); put(enc); }
      }
    }
    btf_header h{}; h.magic = BTF_MAGIC; h.version = BTF_VERSION; h.hdr_len = sizeof(h); h.type_len = Data.size(); h.str_off = Data.size(); h.str_len = Strings.size();
    std::vector<unsigned char> raw; auto *p = reinterpret_cast<unsigned char *>(&h); raw.insert(raw.end(), p, p + sizeof(h)); raw.insert(raw.end(), Data.begin(), Data.end()); raw.insert(raw.end(), Strings.begin(), Strings.end());
    auto *out = btf__new(raw.data(), raw.size()); require(!libbpf_get_error(out), "could not build source BTF"); return out;
  }
};

struct PathSpec {
  QualType root;
  const Expr *base = nullptr;
  bool address = false;
  std::vector<unsigned> access;
  struct Dynamic { unsigned position; const Expr *index; };
  std::vector<Dynamic> dynamic;
};
struct Edit { unsigned begin, end; std::string replacement; };
class Frontend : public RecursiveASTVisitor<Frontend> {
  ASTContext &C;
  SourceManager &SM;
  SourceBTF Source;
  btf *Local = nullptr, *Target = nullptr;
  std::map<unsigned, std::vector<bpf_core_cand>> Candidates;
  std::vector<Expr *> Nodes;
  std::vector<Edit> Edits;
  std::vector<std::pair<unsigned, unsigned>> MetadataFields;
  std::string Buffer;
  unsigned Resolved = 0, Poisoned = 0;
  static const Expr *plain(const Expr *e) { return e->IgnoreParenImpCasts(); }
  bool marked(QualType q) const {
    auto *r = q->getAs<RecordType>(); if (!r) return false;
    auto *d = r->getDecl()->getDefinition(); if (!d) return false;
    for (auto *a : d->specific_attrs<AnnotateAttr>()) if (a->getAnnotation() == "kprog_core") return true;
    return false;
  }
  std::string callee(const CallExpr *call) const {
    auto *f = call->getDirectCallee(); return f ? f->getNameAsString() : "";
  }
  std::pair<unsigned, unsigned> range(const Expr *e) const {
    auto first = SM.getSpellingLoc(e->getBeginLoc());
    auto last = Lexer::getLocForEndOfToken(SM.getSpellingLoc(e->getEndLoc()), 0, SM, C.getLangOpts());
    require(SM.isWrittenInMainFile(first) && SM.isWrittenInMainFile(last), "CO-RE rewrite requires preprocessed compiler input");
    return {SM.getFileOffset(first), SM.getFileOffset(last)};
  }
  std::string text(const Expr *e, bool edits = true) const {
    auto [first, last] = range(e); std::string out; unsigned at = first;
    std::vector<const Edit *> selected;
    if (edits) for (auto &v : Edits) if (v.begin >= first && v.end <= last) selected.push_back(&v);
    std::sort(selected.begin(), selected.end(), [](auto *a, auto *b) { return a->begin != b->begin ? a->begin < b->begin : a->end > b->end; });
    for (auto *v : selected) {
      if (v->begin < at) continue;
      out += Buffer.substr(at, v->begin - at) + v->replacement; at = v->end;
    }
    return out + Buffer.substr(at, last - at);
  }
  void replace(const Expr *e, std::string s) {
    auto [first, last] = range(e); Edits.push_back({first, last, std::move(s)});
  }
  bool integer(const Expr *e, int64_t &value) const {
    Expr::EvalResult r; if (!e->EvaluateAsInt(r, C)) return false;
    auto v = r.Val.getInt(); require(v.getBitWidth() <= 64 || v.isSignedIntN(64), "CO-RE integer wider than 64 bits");
    value = v.getSExtValue(); return true;
  }
  PathSpec root(const Expr *base, bool address, QualType type) {
    PathSpec p; p.base = base; p.address = address; p.root = type; p.access.push_back(0); Source.id(type); return p;
  }
  PathSpec path(const Expr *input) {
    auto *e = plain(input);
    if (auto *u = dyn_cast<UnaryOperator>(e)) {
      if (u->getOpcode() == UO_AddrOf) return path(u->getSubExpr());
    }
    if (auto *m = dyn_cast<MemberExpr>(e)) {
      auto *field = dyn_cast<FieldDecl>(m->getMemberDecl()); require(field != nullptr, "CO-RE member is not a field");
      PathSpec p;
      if (m->isArrow()) p = root(m->getBase(), false, m->getBase()->getType()->getPointeeType());
      else if (isa<MemberExpr>(plain(m->getBase())) || isa<ArraySubscriptExpr>(plain(m->getBase()))) p = path(m->getBase());
      else p = root(m->getBase(), true, m->getBase()->getType());
      p.access.push_back(Source.member(field)); return p;
    }
    if (auto *a = dyn_cast<ArraySubscriptExpr>(e)) {
      auto *base = plain(a->getBase()); PathSpec p;
      bool array = C.getAsArrayType(base->getType());
      if (array) p = path(base);
      else { require(a->getBase()->getType()->isPointerType(), "CO-RE array has no pointer base"); p = root(a->getBase(), false, a->getBase()->getType()->getPointeeType()); }
      int64_t index = 0; bool constant = integer(a->getIdx(), index);
      require(!constant || (index >= 0 && uint64_t(index) <= UINT32_MAX), "CO-RE negative/large array index");
      unsigned pos = array ? p.access.size() : 0;
      if (array) p.access.push_back(constant ? unsigned(index) : 0); else p.access[0] = constant ? unsigned(index) : 0;
      if (!constant) p.dynamic.push_back({pos, a->getIdx()}); return p;
    }
    require(e->getType()->isRecordType() || e->getType()->isArrayType(), "CO-RE expression has no member path");
    return root(e, true, e->getType());
  }
  bool inAccess(const Expr *e) const {
    const Stmt *at = e;
    for (;;) {
      auto ps = C.getParents(*at); if (ps.size() != 1) return false;
      auto *parent = ps[0].get<Expr>(); if (!parent) return false;
      if (auto *call = dyn_cast<CallExpr>(parent)) {
        if (callee(call) == "__native_core_access") return true;
      }
      at = parent;
    }
  }
  bool inFieldInfo(const Expr *e) const {
    const Stmt *at = e;
    for (;;) {
      auto ps = C.getParents(*at); if (ps.size() != 1) return false;
      auto *parent = ps[0].get<Expr>(); if (!parent) return false;
      if (auto *call = dyn_cast<CallExpr>(parent)) if (callee(call) == "__native_core_field_info") return true;
      at = parent;
    }
  }
  bool memberMarked(const MemberExpr *m) const {
    QualType q = m->isArrow() ? m->getBase()->getType()->getPointeeType() : m->getBase()->getType();
    return marked(q) || inAccess(m);
  }
  bool arrayMarked(const Expr *e) const {
    e = plain(e);
    if (auto *m = dyn_cast<MemberExpr>(e)) return memberMarked(m);
    if (auto *a = dyn_cast<ArraySubscriptExpr>(e)) return arrayMarked(a->getBase());
    return inAccess(e);
  }
  bpf_core_relo_res calc(QualType type, const std::vector<unsigned> &access, unsigned kind) {
    unsigned id = Source.id(type); std::string spec;
    for (auto n : access) { if (!spec.empty()) spec += ':'; spec += std::to_string(n); }
    int off = btf__add_str(Local, spec.c_str()); require(off >= 0, "cannot add source CO-RE access string");
    auto it = Candidates.find(id);
    if (it == Candidates.end()) {
      const auto *t = btf__type_by_id(Local, id); require(t != nullptr, "missing local CO-RE root type");
      const char *name = btf__name_by_offset(Local, t->name_off);
      bpf_core_cand origin{Local, id}; bpf_core_cand_list found{};
      int rc = bpf_core_add_cands(&origin, bpf_core_essential_name_len(name), Target, "vmlinux", 1, &found);
      require(rc == 0, "CO-RE candidate search failed"); std::vector<bpf_core_cand> values;
      if (found.len) values.assign(found.cands, found.cands + found.len);
      free(found.cands); it = Candidates.emplace(id, std::move(values)).first;
    }
    bpf_core_relo r{}; r.type_id = id; r.access_str_off = off; r.kind = static_cast<bpf_core_relo_kind>(kind);
    auto &values = it->second; bpf_core_cand_list list{values.data(), int(values.size())}; bpf_core_spec scratch[3]{}; bpf_core_relo_res result{};
    int rc = bpf_core_calc_relo_insn("native-frontend", &r, Resolved, Local, &list, scratch, &result);
    require(rc == 0, "libbpf CO-RE relocation failed: " + std::to_string(rc)); values.resize(list.len); ++Resolved; Poisoned += result.poison;
    const auto *root = btf__type_by_id(Local, id);
    std::cout << "{\"kind\":" << kind << ",\"type\":\"" << btf__name_by_offset(Local, root->name_off) << "\",\"access\":\"" << spec << "\",\"orig_val\":" << result.orig_val << ",\"new_val\":" << result.new_val << ",\"poison\":" << (result.poison ? "true" : "false") << "}\n";
    return result;
  }
  std::string number(const bpf_core_relo_res &r, bool signedValue = false) const {
    if (r.poison) return "__native_core_poison()";
    return signedValue ? "((long long)(" + std::to_string(r.new_val) + "ULL))" : "(" + std::to_string(r.new_val) + "ULL)";
  }
  std::string address(PathSpec p) {
    auto r = calc(p.root, p.access, BPF_CORE_FIELD_BYTE_OFFSET);
    if (r.poison) return "((char *)(unsigned long)__native_core_poison())";
    std::string off = number(r);
    for (auto &dynamic : p.dynamic) {
      auto prefix = p.access; prefix.resize(dynamic.position + 1);
      auto stride = calc(p.root, dynamic.position ? prefix : std::vector<unsigned>{0}, dynamic.position ? BPF_CORE_FIELD_BYTE_SIZE : BPF_CORE_TYPE_SIZE);
      require(!stride.poison, "CO-RE dynamic array element size is unresolved");
      off += "+(" + text(dynamic.index) + ")*" + number(stride);
    }
    return "((char *)(" + std::string(p.address ? "&(" : "(") + text(p.base) + "))+(" + off + "))";
  }
  QualType typeArgument(const CallExpr *call) const {
    auto q = call->getArg(1)->getType(); require(q->isPointerType(), "CO-RE type marker requires a typed pointer"); return q->getPointeeType();
  }
  unsigned enumIndex(const CallExpr *call) const {
    auto *ref = dyn_cast<DeclRefExpr>(plain(call->getArg(2)));
    auto *value = ref ? dyn_cast<EnumConstantDecl>(ref->getDecl()) : nullptr;
    require(value != nullptr, "CO-RE enum argument is not an enumerator");
    auto *t = typeArgument(call)->getAs<EnumType>(); require(t != nullptr, "CO-RE enum marker has no enum type");
    unsigned i = 0; for (auto *v : t->getDecl()->getDefinition()->enumerators()) { if (v == value) return i; ++i; }
    throw std::runtime_error("CO-RE enum argument belongs to another type");
  }
  static bool marker(const std::string &name) {
    return name == "__native_core_field_info" || name == "__native_core_type_info" || name == "__native_core_enum_info" || name == "__native_core_access";
  }
public:
  Frontend(ASTContext &context, llvm::StringRef source, const char *kernel) : C(context), SM(C.getSourceManager()), Source(C), Buffer(source.str()) {
    Target = btf__parse(kernel, nullptr); require(!libbpf_get_error(Target), "cannot parse target kernel BTF");
  }
  ~Frontend() { btf__free(Local); btf__free(Target); }
  bool shouldTraversePostOrder() const { return true; }
  bool VisitCallExpr(CallExpr *call) {
    if (marker(callee(call))) Nodes.push_back(call); return true;
  }
  bool VisitMemberExpr(MemberExpr *m) { if (memberMarked(m)) Nodes.push_back(m); return true; }
  bool VisitArraySubscriptExpr(ArraySubscriptExpr *a) { if (arrayMarked(a)) Nodes.push_back(a); return true; }
  std::string run() {
    TraverseDecl(C.getTranslationUnitDecl());
    // Finish the graph before constructing BTF: no source type is synthesized
    // from a field's spelling, app name, program identity or a kernel guess.
    for (auto *e : Nodes) {
      if (auto *call = dyn_cast<CallExpr>(e)) {
        auto n = callee(call);
        if (n == "__native_core_field_info") path(call->getArg(1));
        else if (n != "__native_core_access") Source.id(typeArgument(call));
      } else path(e);
    }
    Local = Source.build();
    std::vector<const Expr *> bitfields;
    for (auto *e : Nodes) {
      if (auto *call = dyn_cast<CallExpr>(e)) {
        auto n = callee(call);
        if (n == "__native_core_access") { replace(e, text(call->getArg(0))); continue; }
        int64_t kind; require(integer(call->getArg(0), kind) && kind >= 0 && kind <= BPF_CORE_TYPE_MATCHES, "invalid CO-RE relocation kind");
        if (n == "__native_core_field_info") {
          MetadataFields.push_back(range(e));
          auto p = path(call->getArg(1)); replace(e, "((" + e->getType().getAsString() + ")" + number(calc(p.root, p.access, kind)) + ")");
        } else if (n == "__native_core_type_info") {
          replace(e, "((" + e->getType().getAsString() + ")" + number(calc(typeArgument(call), {0}, kind)) + ")");
        } else replace(e, "((" + e->getType().getAsString() + ")" + number(calc(typeArgument(call), {enumIndex(call)}, kind), true) + ")");
      } else {
        if (auto *m = dyn_cast<MemberExpr>(e)) {
          auto *f = dyn_cast<FieldDecl>(m->getMemberDecl());
          if (f && f->isBitField()) { bitfields.push_back(e); continue; }
        }
        auto parents = C.getParents(*e);
        auto *cast = parents.size() == 1 ? parents[0].get<ImplicitCastExpr>() : nullptr;
        if (cast && cast->getCastKind() == CK_LValueToRValue && !inFieldInfo(e)) {
          auto p = path(e); auto r = calc(p.root, p.access, BPF_CORE_FIELD_BYTE_OFFSET);
          require(r.poison || r.orig_sz == r.new_sz, "CO-RE direct load width change needs lowering");
        }
        replace(e, "(*(__typeof__(" + text(e, false) + ")*)" + address(path(e)) + ")");
      }
    }
    // A predicate can mention a bitfield without evaluating it. A surviving
    // direct bitfield access needs its complete load/shift lowering, not a
    // silent source-layout read. The initial frontend rejects that case.
    for (auto *e : bitfields) {
      auto [first, last] = range(e); bool covered = false;
      for (auto [begin, end] : MetadataFields) if (begin <= first && end >= last) { covered = true; break; }
      require(covered, "direct CO-RE bitfield access needs load/shift lowering");
    }
    std::sort(Edits.begin(), Edits.end(), [](auto &a, auto &b) { return a.begin != b.begin ? a.begin < b.begin : a.end > b.end; });
    std::string output = "extern unsigned long long __native_core_poison(void);\n"; unsigned at = 0;
    for (auto &v : Edits) {
      if (v.begin < at) continue;
      output += Buffer.substr(at, v.begin - at) + v.replacement; at = v.end;
    }
    output += Buffer.substr(at);
    std::cerr << "native-core: " << Resolved << " relocations, " << Poisoned << " poisoned, " << Edits.size() << " source expressions\n";
    return output;
  }
};

int main(int argc, char **argv) try {
  require(argc >= 4, "usage: native-core-frontend KERNEL_BTF INPUT_C OUTPUT_C [-- CLANG_PARSE_ARGS...]");
  auto source = llvm::MemoryBuffer::getFile(argv[2]); require(bool(source), "cannot read native compiler input");
  std::vector<std::string> args{"-x", "c", "-std=gnu11", "-Wno-unknown-attributes"};
  for (int i = 4; i < argc; ++i) if (std::string(argv[i]) != "--") args.emplace_back(argv[i]);
  auto ast = tooling::buildASTFromCodeWithArgs((*source)->getBuffer(), args, argv[2], "clang-18");
  require(ast && !ast->getDiagnostics().hasErrorOccurred(), "native compiler input failed semantic analysis");
  Frontend frontend(ast->getASTContext(), (*source)->getBuffer(), argv[1]);
  auto output = frontend.run(); std::ofstream out(argv[3], std::ios::binary); require(bool(out), "cannot open rewritten native compiler input");
  out << output; out.close(); require(bool(out), "cannot write rewritten native compiler input"); return 0;
} catch (const std::exception &e) { std::cerr << "native-core: " << e.what() << '\n'; return 1; }
