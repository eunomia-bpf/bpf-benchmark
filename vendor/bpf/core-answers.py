#!/usr/bin/env python3
"""Answer every CO-RE query an app's sources make, from the one kernel's BTF.

The native arm compiles the app's own C for x86-64. clang's CO-RE builtins
(`__builtin_preserve_field_info`, `__builtin_preserve_type_info`,
`__builtin_preserve_enum_value`) exist only for `-target bpf`, so an app that
asks about the target kernel's layout fails to compile at all. This script reads
the app's queries, resolves each against the sole kernel's BTF, and writes the
table that `core-compat.h` uses to answer them with constants.

Flavor types (`struct request___x`, ...) are source-side compatibility aliases.
Their layouts in the app's vmlinux.h are *not* the kernel's: `struct
request.disk` sits at byte 96 in this kernel while the flavor struct reports 0,
so every offset comes from the target BTF, never from the C compile.

A query is answered by matching its own text. `bpf_core_field_exists(t->__state)`
stringifies - before macro expansion, so the source spelling survives - to
`t->__state`, and the table maps that string to the BTF answer.
`__builtin_strcmp` constant-folds for a listed query; a new one reaches
`__kprog_core_unanswered()` and fails the compile. A silent default is what made
the image's biosnoop read `request+8` where this kernel has `request+96`.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path


def run(cmd: list[str], what: str) -> str:
    try:
        return subprocess.run(cmd, check=True, capture_output=True, text=True).stdout
    except subprocess.CalledProcessError as exc:
        sys.exit(f"core-answers: {what} failed: {exc.stderr.strip()}")


class Btf:
    """The target kernel's types, indexed by name."""

    def __init__(self, bpftool: Path, btf: Path):
        text = run([str(bpftool), "btf", "dump", "file", str(btf), "format", "raw"],
                   "btf dump")
        self.by_id: dict[int, dict] = {}
        self.by_name: dict[str, list[dict]] = {}
        cur = None
        for line in text.splitlines():
            # A header is `[id] KIND 'name'` followed by kind-specific attributes
            # (size=, vlen=, type_id=, nr_elems=, linkage=, ...) in any combination.
            m = re.match(r"^\[(\d+)\]\s+(\w+)\s+'(.*?)'(.*)$", line)
            if m:
                cur = {"id": int(m.group(1)), "kind": m.group(2), "name": m.group(3),
                       "size": (int(sz.group(1)) if (sz := re.search(r"\bsize=(\d+)", m.group(4))) else None),
                       "members": [],
                       "values": [], "type": None,
                       # An ARRAY entry carries no size=, only its element count.
                       "nr_elems": (int(nr.group(1)) if (nr := re.search(r"\bnr_elems=(\d+)", m.group(4))) else None)}
                # ARRAY/PTR/CONST/... name their target inline on the header line.
                if (tid := re.search(r"(?:^|\s)type_id=(\d+)", m.group(4))):
                    cur["type"] = int(tid.group(1))
                self.by_id[cur["id"]] = cur
                if cur["name"] and cur["kind"] in ("STRUCT", "UNION", "ENUM", "TYPEDEF"):
                    self.by_name.setdefault(cur["name"], []).append(cur)
                continue
            if cur is None:
                continue
            m = re.match(r"^\s+'(.*?)'\s+type_id=(\d+)\s+bits_offset=(-?\d+)", line)
            if m:
                cur["members"].append({"name": m.group(1), "type_id": int(m.group(2)),
                                       "bits": int(m.group(3))})
                continue
            m = re.match(r"^\s+'(.*?)'\s+val=(-?\d+)", line)
            if m:
                cur["values"].append({"name": m.group(1), "val": int(m.group(2))})
                continue
            m = re.match(r"^\s+type_id=(\d+)", line)
            if m:
                cur["type"] = int(m.group(1))

    def resolve(self, type_id: int | None) -> dict | None:
        """Follow typedef/const/volatile wrappers to the real type."""
        seen = set()
        while type_id is not None and type_id not in seen:
            seen.add(type_id)
            t = self.by_id.get(type_id)
            if t is None:
                return None
            if t["kind"] in ("TYPEDEF", "CONST", "VOLATILE", "RESTRICT", "TYPE_TAG"):
                type_id = t["type"]
                continue
            return t
        return None

    def struct(self, name: str) -> dict | None:
        for t in self.by_name.get(name, []):
            r = self.resolve(t["id"])
            if r and r["kind"] in ("STRUCT", "UNION"):
                return r
        return None

    def size_of(self, t: dict | None) -> int | None:
        """Byte size, including ARRAY (BTF stores no size for an array)."""
        if t is None:
            return None
        if t["kind"] == "ARRAY":
            inner = self.resolve(t["type"])
            n = t["nr_elems"]
            if inner is None or n is None or self.size_of(inner) is None:
                return None
            return self.size_of(inner) * n
        return t["size"]

    def type_named(self, name: str) -> dict | None:
        """Any type of this name, unwrapped: struct, union, enum or scalar typedef."""
        r = self.struct(name)
        if r:
            return r
        if name in self.by_name:
            return self.resolve(self.by_name[name][0]["id"])
        return None

    def _find(self, t: dict, name: str, base: int = 0,
              seen: frozenset[int] = frozenset()) -> tuple[dict | None, int]:
        """A member by name, descending into anonymous members (DEFINE_FLEX layout)."""
        for mem in t["members"]:
            if mem["name"] == name:
                return mem, base
        for mem in t["members"]:
            if mem["name"] != "(anon)":
                continue
            inner = self.resolve(mem["type_id"])
            if inner is None or inner["kind"] not in ("STRUCT", "UNION") or inner["id"] in seen:
                continue
            hit, off = self._find(inner, name, base + mem["bits"], seen | {inner["id"]})
            if hit is not None:
                return hit, off
        return None, 0

    def member(self, type_name: str, path: list[str]) -> tuple[dict, int] | None:
        """(member, absolute bit offset) for a dotted path, or None if absent."""
        t = self.struct(type_name)
        if t is None:
            return None
        base = 0
        for i, part in enumerate(path):
            part = re.sub(r"\[.*\]$", "", part)
            hit, anon_base = self._find(t, part)
            if hit is None:
                return None
            base += anon_base + hit["bits"]
            if i == len(path) - 1:
                return hit, base
            t = self.resolve(hit["type_id"])
            while t is not None and t["kind"] == "PTR":
                t = self.resolve(t["type"])
            if t is None or t["kind"] not in ("STRUCT", "UNION"):
                return None
        return None


MARKERS = ("field_exists", "field_size", "field_offset", "type_exists",
           "type_size", "type_matches", "enum_value_exists", "enum_value")

SCAN_HEADER = """\
/* Scan mode: core-compat.h answers each query with a call the AST carries the
 * field expression's resolved type and member names for. */
#define __KPROG_SCAN_ONLY__
#include "core-compat.h"
static int __kprog_scan(const char *kind, const char *query, ...);
"""


def _stripm(n: dict | None) -> dict | None:
    """Descend through implicit nodes to the expression that carries the type."""
    while isinstance(n, dict) and n.get("kind") not in ("MemberExpr", "DeclRefExpr",
                                                        "UnaryOperator", "CallExpr"):
        inner = n.get("inner") or []
        n = inner[0] if inner and isinstance(inner[0], dict) else None
    return n


def _literal(n: dict | None) -> str | None:
    """The value of a string literal, through the casts around it."""
    while isinstance(n, dict):
        if n.get("kind") == "StringLiteral":
            return n.get("value", "").strip('"')
        inner = n.get("inner") or []
        n = inner[0] if inner and isinstance(inner[0], dict) else None
    return None


def _callee(n: dict | None) -> dict | None:
    """The DeclRefExpr naming the called function."""
    while isinstance(n, dict) and n.get("kind") != "DeclRefExpr":
        inner = n.get("inner") or []
        n = inner[0] if inner and isinstance(inner[0], dict) else None
    return n


def _var_type(n: dict | None) -> str | None:
    """The declared type of the variable a field expression starts from."""
    while isinstance(n, dict):
        if n.get("kind") == "MemberExpr":
            n = (n.get("inner") or [None])[0]
            continue
        if n.get("kind") == "DeclRefExpr":
            return (n.get("referencedDecl") or {}).get("type", {}).get("qualType")
        inner = n.get("inner") or []
        n = inner[0] if inner and isinstance(inner[0], dict) else None
    return None


def _members(n: dict | None, acc: list[str]) -> list[str]:
    """Member names of a field expression, in the order the type nests them.

    `a->b->c` walks MemberExpr c, MemberExpr b, DeclRefExpr a, so the walk
    collects outermost first; BTF resolves a path from the base type outwards,
    and `b.member()` expects that order.
    """
    while isinstance(n, dict):
        if n.get("kind") == "MemberExpr":
            # An anonymous member has no name; BTF descends anonymous members
            # itself, so stepping through it is not part of the path.
            if n["name"]:
                acc.append(n["name"])
            n = (n.get("inner") or [None])[0]
            continue
        inner = n.get("inner") or []
        n = inner[0] if inner and isinstance(inner[0], dict) else None
    acc.reverse()
    return acc


def scan(sources: list[Path], clang: str, flags: list[str],
         work: Path) -> tuple[list[tuple[str, str]], list[tuple[Path, set[tuple[str, str]]]]]:
    """Every (kind, query text) the compiled sources ask, per translation unit."""
    header = work / "scan.h"
    header.write_text(SCAN_HEADER)
    found: set[tuple[str, str]] = set()
    per_tu: list[tuple[Path, set[tuple[str, str]]]] = []
    types: dict[tuple[str, str], tuple[str | None, list[str]]] = {}
    for src in sorted(p for p in sources if p.suffix == ".c"):
        out = subprocess.run([clang, "-Xclang", "-ast-dump=json", "-fsyntax-only", "-w",
                              "-include", str(header)] + flags + [str(src)],
                             capture_output=True, text=True)
        # clang emits the AST even when a later diagnostic fails the parse, and an
        # app may carry an error the scan does not depend on (Tetragon's BPF-register
        # asm, for one). A complete AST is what the scan needs.
        try:
            ast = json.loads(out.stdout)
        except json.JSONDecodeError:
            sys.exit(f"core-answers: {src} produced no JSON AST: {out.stderr.strip()[:2000]}")
        tu: set[tuple[str, str]] = set()
        stack = [ast]
        while stack:
            node = stack.pop()
            if isinstance(node, list):
                stack.extend(node)
                continue
            if not isinstance(node, dict):
                continue
            if node.get("kind") == "CallExpr":
                args = [a for a in (node.get("inner") or []) if isinstance(a, dict)]
                callee = _callee(args[0]) if args else None
                if callee and (callee.get("referencedDecl") or {}).get("name") == "__kprog_scan":
                    # __kprog_scan(kind, query, <field expression...>)
                    kind = _literal(args[1]) if len(args) > 1 else None
                    query = _literal(args[2]) if len(args) > 2 else None
                    if kind and query:
                        query = " ".join(query.split())
                        tu.add((kind, query))
                        if len(args) > 3:
                            types[(kind, query)] = (_var_type(args[3]), _members(args[3], []))
            stack.extend(node.get("inner") or [])
        if tu:
            (work / f"{Path(src).stem}.i").write_text(
                subprocess.run([clang, "-E", "-w", "-include", str(header)] + flags + [str(src)],
                               capture_output=True, text=True).stdout)
            per_tu.append((src, tu))
            found |= tu
    return sorted(found), per_tu, types


def split_flavor(arg: str) -> str:
    """Strip the `___x` / `___o` suffix libbpf uses to name a flavor type."""
    return re.sub(r"___[a-z]+(?=\s*(,|\)|$|->|\.))", "", arg)


def field_path(expr: str, decls: dict[str, str]) -> tuple[str, list[str]] | None:
    """`struct renamedata___x, old_mnt_userns` or `b->bi_bdev` -> (type, [fields]).

    libbpf reaches one expression two ways: a two-argument macro naming a type
    and field, or a one-argument expression over a variable. Both must map to
    the same BTF walk.
    """
    expr = expr.strip()
    while expr.startswith("(") and expr.endswith(")") and ")" not in expr[1:-1]:
        expr = expr[1:-1].strip()
    if "," in expr:
        type_part, field_part = expr.split(",", 1)
        name = type_part.split()[-1].strip("* ")
        return split_flavor(name), [p for p in re.split(r"\s*->\s*|\s*\.\s*", field_part.strip()) if p]
    # `((struct T *)0)->a.b`, `((struct T *)expr)->a`, `((typeof(T) *)0)->a`, or
    # a plain `var->a.b`. The cast names the type directly.
    m = re.match(r"^\(\s*\(\s*(?:typeof\s*\(\s*(.+?)\s*\)|struct\s+([A-Za-z_0-9]+)"
                 r"|union\s+([A-Za-z_0-9]+))\s*\*\s*\)\s*[^)]*\s*\)"
                 r"((?:\s*->\s*[A-Za-z_0-9]+|\s*\.\s*[A-Za-z_0-9]+"
                 r"|\s*\[[^\]]*\])+)$", expr)
    if m:
        spun = next(g for g in (m.group(1), m.group(2), m.group(3)) if g)
        return split_flavor(spun.split()[-1].strip("* ")), \
            [q for q in re.split(r"\s*->\s*|\s*\.\s*", m.group(4).strip()) if q]
    m = re.match(r"^([A-Za-z_0-9]+)((?:\s*->\s*[A-Za-z_0-9]+|\s*\.\s*[A-Za-z_0-9]+"
                 r"|\s*\[[^\]]*\])+)$", expr)
    if not m or m.group(1) not in decls:
        return None
    return split_flavor(decls[m.group(1)]), \
        [q for q in re.split(r"\s*->\s*|\s*\.\s*", m.group(2).strip()) if q]


DECL = re.compile(r"\b(?:struct|union)\s+([A-Za-z_0-9]+)\s*\*+\s*([A-Za-z_0-9]+)\s*(?=[=;,)\[])")


TYPEDEF_DECL = re.compile(r"(?:^|[;{}\s])([A-Za-z_0-9]+)\s*\*+\s*([A-Za-z_0-9]+)"
                           r"\s*(?=[=;,)\[])")

# A value (not pointer) local: `kernel_cap_t___older to = {0};`. Anchored so a
# continuation or comparison cannot match.
VALUE_DECL = re.compile(r"^\s*([A-Za-z_0-9]+)\s+([A-Za-z_0-9]+)\s*=", re.M)


_KEYWORDS = {"return", "if", "else", "while", "for", "switch", "case", "goto",
             "const", "unsigned", "signed", "static", "struct", "union", "enum",
             "register", "volatile", "typeof", "sizeof", "char", "int", "long",
             "short", "void", "_Bool", "bool"}


def declarations(sources: list[Path]) -> dict[str, str]:
    """Variable -> declared type name, from a translation unit's own text.

    Last declaration wins. In preprocessed text the kernel-wide `vmlinux.h`
    comes first and the app's own files last, so the innermost declaration -
    the function parameter or local that actually names the variable at the
    query site - overrides an earlier unrelated one. A file-scope
    `struct bpf_sock *sk;` in a UAPI header must not decide what a
    `struct sock *sk` parameter means.
    """
    out: dict[str, str] = {}
    for path in sources:
        text = path.read_text(errors="replace")
        for name, var in DECL.findall(text):
            out[var] = split_flavor(name)
        for name, var in TYPEDEF_DECL.findall(text):
            out[var] = split_flavor(name)
        for name, var in VALUE_DECL.findall(text):
            if name not in _KEYWORDS:
                out[var] = split_flavor(name)
    return out


def answer(btf: Btf, kind: str, arg: str, decls: dict[str, str],
           ast_type: tuple[str | None, list[str]] | None = None) -> tuple[int | None, str]:
    """(answer, what BTF says) for one query.

    `ast_type` is what clang resolved the field expression to: the declared
    type of the variable it starts from, and the member names. It is used in
    preference to reading declarations as text, because the same spelling can
    name different types in different translation units.
    """
    if kind in ("field_exists", "field_size", "field_offset"):
        fp = None
        if ast_type and ast_type[0] and ast_type[1]:
            base, members = ast_type
            base = re.sub(r"^(const|volatile|struct|union|enum)\s+", "", base)
            base = re.sub(r"\s*(\*|\[.*\])+$", "", base.strip())
            fp = (split_flavor(base), members)
        if fp is None:
            fp = field_path(arg, decls)
        if not fp:
            return None, "cannot tell which type the expression reads"
        type_name, path = fp
        hit = btf.member(type_name, path)
        if hit is None:
            return (0 if kind in ("field_exists", "field_size") else None), \
                f"{type_name}.{'.'.join(path)} absent in target BTF"
        mem, bits = hit
        if kind == "field_exists":
            return 1, f"{type_name}.{'.'.join(path)} -> bit {bits}"
        if kind == "field_offset":
            return bits // 8, f"{type_name}.{'.'.join(path)} -> bit {bits}"
        rt = btf.resolve(mem["type_id"])
        if rt is not None and rt["kind"] == "ARRAY" and not rt["nr_elems"]:
            # A flexible array (`T x[]`) has zero elements in BTF; indexing it
            # asks for one element, so answer with the element's own size.
            rt = btf.resolve(rt["type"])
        size = btf.size_of(rt)
        if size is None:
            return None, f"{type_name}.{'.'.join(path)} has no size"
        return size, f"{type_name}.{'.'.join(path)} -> {size} bytes"
    if kind in ("type_exists", "type_size", "type_matches"):
        # clang materialised the type as a pointer to it; its pointee is the
        # type the query names, whether written `struct T` or `typeof(*p)`.
        if ast_type and ast_type[0]:
            arg = ast_type[0]
        name = re.sub(r"\s*(\*|\[.*\])+$", "", arg.strip()).strip()
        # `typeof(*p)` survives as a type the app declared `p` for; ask the
        # declaration text for the pointee's own name.
        if (t := re.match(r"^typeof\s*\(\s*(?:\*\s*)?([A-Za-z_0-9]+)\s*\)$", name)):
            if t.group(1) not in decls:
                return None, f"typeof({name}): variable not declared in the app"
            name = decls[t.group(1)]
        name = split_flavor(re.sub(r"^(const|volatile|struct|union|enum)\s+", "", name.strip()))
        t = btf.type_named(name)
        if kind == "type_exists":
            return (1 if t else 0), f"type {name} -> {'present' if t else 'absent'}"
        size = btf.size_of(t)
        if size is None:
            return None, f"type {name} -> absent"
        return (2 if kind == "type_matches" else size), f"type {name} -> {size} bytes"
    parts = [p.strip() for p in arg.split(",", 1)]
    if len(parts) != 2:
        return None, "enum query needs a type and a value"
    t = btf.type_named(re.sub(r"^(struct|union|enum)\s+", "", parts[0].strip()))
    if t is None or t["kind"] != "ENUM":
        return (0 if kind == "enum_value_exists" else None), f"enum {parts[0]} absent"
    hit = next((v for v in t["values"] if v["name"] == parts[1]), None)
    if kind == "enum_value_exists":
        return (1 if hit else 0), f"enum {parts[0]}.{parts[1]} -> {'present' if hit else 'absent'}"
    if hit is None:
        return None, f"enum {parts[0]}.{parts[1]} absent"
    return hit["val"], f"enum {parts[0]}.{parts[1]} -> {hit['val']}"


TABLE_HEADER = """\
/* Generated by core-answers.py from the sole kernel's BTF. Do not edit.
 *
 * One entry per CO-RE query the app's sources make. `core-compat.h` stringifies
 * the query before macro expansion and looks it up here; a query with no entry
 * calls __kprog_core_unanswered() and fails the compile.
 */
"""


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--btf", required=True, type=Path, help="the sole kernel's vmlinux")
    ap.add_argument("--bpftool", type=Path,
                    default=Path("vendor/build/x86/bpftool/bin/bpftool"))
    ap.add_argument("--clang", default="clang-18")
    ap.add_argument("--cflags", default="", help="the app's compile flags, incl. -D and -I")
    ap.add_argument("--out", required=True, type=Path, help="table to write")
    ap.add_argument("--report", type=Path, help="JSON of every query and its answer")
    ap.add_argument("dirs", nargs="+", type=Path, help="source trees to scan")
    args = ap.parse_args()

    sources: list[Path] = []
    for d in args.dirs:
        sources += sorted(p for p in d.rglob("*") if p.suffix in (".c", ".h"))
    work = Path(tempfile.mkdtemp(prefix="core-answers-"))
    queries, per_tu, types = scan(sources, args.clang, args.cflags.split(), work)

    # An app that makes no CO-RE query still gets a table: every lookup macro
    # exists, so a query it starts to make fails the compile instead of
    # silently picking up a default.
    btf = Btf(args.bpftool, args.btf)
    report = []
    unresolved = []
    answered: dict[tuple[str, str], tuple[int, str]] = {}
    for tu, tu_queries in per_tu:
        # A variable's type belongs to the translation unit that names it: two
        # files may declare `pid` differently and only one of them asks this
        # query. The preprocessed text is what the compiler's own name lookup
        # sees, so read declarations from there.
        decls = declarations([work / f"{Path(tu).stem}.i"])
        for kind, arg in sorted(tu_queries):
            value, detail = answer(btf, kind, arg, decls, types.get((kind, arg)))
            if value is None:
                unresolved.append(f"{tu}: {kind}({arg}): {detail}")
                continue
            if (kind, arg) in answered and answered[(kind, arg)][0] != value:
                sys.exit(f"core-answers: {kind}({arg}) is {answered[(kind, arg)][0]} in "
                         f"{answered[(kind, arg)][1]} and {value} in {tu}; "
                         f"the answer table holds one entry per query text")
            answered[(kind, arg)] = (value, str(tu))
    if unresolved:
        sys.exit("core-answers: unresolved queries:\n  " + "\n  ".join(unresolved))

    report = [{"kind": k, "query": q, "answer": v, "tu": tu}
              for (k, q), (v, tu) in sorted(answered.items())]
    skb_cb = btf.member("sk_buff", ["cb"])[1] // 8
    qdisc_data = btf.member("qdisc_skb_cb", ["data"])[1] // 8
    qdisc_classid = btf.member("qdisc_skb_cb", ["tc_classid"])[1] // 8
    out = [TABLE_HEADER,
           f"#define __KPROG_SKB_PUBLIC_CB_OFFSET {skb_cb + qdisc_data}",
           f"#define __KPROG_SKB_TC_CLASSID_OFFSET {skb_cb + qdisc_classid}"]
    for kind in sorted({entry["kind"] for entry in report}):
        entries = [e for e in report if e["kind"] == kind]
        # Nested, fully parenthesised: a bare `a ? b : c ? d : e` chain reads as
        # `a ? b : (c ? d : e)` but the macro continuation hides that from the eye.
        lines = [f"#define __kprog_core_lookup_{kind}(text) \\"]
        for e in entries:
            lines.append(f'    (__builtin_strcmp((text), "{e["query"]}") == 0 '
                         f'? {e["answer"]} : \\')
        lines.append("     (__kprog_core_unanswered(), 0)"
                     + ")" * len(entries))
        out.append("\n".join(lines))
    for macro in ("field_exists", "field_size", "field_offset", "type_exists",
                  "type_size", "type_matches", "enum_value_exists", "enum_value"):
        out.append(f"#define bpf_core_{macro}(...) \\\n"
                   f"    __kprog_core_lookup_{macro}(__kprog_core_q(__VA_ARGS__))")

    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text("\n".join(out) + "\n")
    if args.report:
        args.report.write_text(json.dumps(report, indent=2) + "\n")
    print(f"core-answers: {len(report)} queries, all answered -> {args.out}")


if __name__ == "__main__":
    main()
