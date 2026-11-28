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
        if t["kind"] == "PTR":
            return 8  # Both supported native targets use the kernel's 64-bit pointer ABI.
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
        if n.get("kind") in ("CStyleCastExpr", "CallExpr"):
            q = n.get("type", {}).get("qualType", "")
            if "*" in q and ("struct " in q or "union " in q):
                return q
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


def source_layout(ast: dict, text: str) -> tuple[dict[str, int], dict[str, int]]:
    """Clang's own source field offsets; no app C is rewritten."""
    layouts = {}
    for match in re.finditer(r"Type: ([^\n]+).*?\bSize:(\d+).*?FieldOffsets: \[([^]]*)\]", text, re.S):
        offsets = tuple(int(x.strip()) for x in match[3].split(",") if x.strip())
        layouts[match[1].strip()] = (int(match[2]) // 8, offsets)
    fields, sizes, records, aliases = {}, {q: v[0] for q, v in layouts.items()}, [], {}
    stack = [ast]
    while stack:
        node = stack.pop()
        if not isinstance(node, dict):
            continue
        if node.get("kind") == "RecordDecl" and node.get("completeDefinition"):
            records.append(node)
        if node.get("kind") == "TypedefDecl":
            t = node.get("type", {})
            aliases[node["name"]] = t.get("desugaredQualType", t.get("qualType", ""))
        stack.extend(node.get("inner") or [])
    for node in records:
        children = [x for x in node.get("inner", []) if x.get("kind") == "FieldDecl"]
        name = node.get("name")
        if name:
            matches = [layouts.get(node.get("tagUsed", "struct") + " " + name)]
        else:
            loc = node.get("loc", {})
            loc = loc.get("expansionLoc", loc)
            suffix = ":" + str(loc.get("line")) + ":" + str(loc.get("col")) + ")"
            matches = [value for key, value in layouts.items() if key.endswith(suffix)]
        matches = [value for value in matches if value and len(value[1]) == len(children)]
        offsets = {value[1] for value in matches}
        if len(offsets) != 1:
            continue  # Only an actual address query using this field needs an answer.
        for field, bits in zip(children, offsets.pop()):
            fields[field["id"]] = bits
    sizes.update({"char": 1, "signed char": 1, "unsigned char": 1, "_Bool": 1,
                  "short": 2, "unsigned short": 2, "int": 4, "unsigned int": 4,
                  "long": 8, "unsigned long": 8, "long long": 8,
                  "unsigned long long": 8, "float": 4, "double": 8})
    for name in aliases:
        q, seen = name, set()
        while q in aliases and q not in seen:
            seen.add(q)
            q = aliases[q]
        if q in sizes:
            sizes[name] = sizes[q]
    return fields, sizes


def source_access(node: dict, fields: dict[str, int], sizes: dict[str, int]):
    """Constant source offset and array strides for a preserved address."""
    original = node
    while original.get("kind") == "ImplicitCastExpr":
        original = (original.get("inner") or [{}])[0]
    qtype = original.get("type", {}).get("qualType", "")
    if not ("*" in qtype or "[" in qtype):
        return None
    bits, arrays, crossings = 0, [], []
    current = node
    while isinstance(current, dict):
        children = current.get("inner") or []
        if current.get("kind") == "MemberExpr":
            offset = fields.get(current.get("referencedMemberDecl"))
            if offset is None or offset % 8:
                return None
            bits += offset
            base = children[0] if children else {}
            while base.get("kind") in ("ImplicitCastExpr", "ParenExpr"):
                base = (base.get("inner") or [{}])[0]
            if current.get("isArrow") and base.get("kind") == "MemberExpr":
                local = source_access({"kind": "UnaryOperator",
                    "type": {"qualType": "void *"}, "inner": [base]}, fields, sizes)
                if local is None:
                    return None
                crossings.append((_members(base, []), local[0]))
        if current.get("kind") == "ArraySubscriptExpr":
            elem = current.get("type", {})
            q = elem.get("desugaredQualType", elem.get("qualType", ""))
            q = re.sub(r"\b(const|volatile|restrict)\b", "", q).strip()
            stride = 8 if q.endswith("*") else sizes.get(q)
            index = children[1] if len(children) > 1 else {}
            while index.get("kind") in ("ImplicitCastExpr", "ParenExpr", "ConstantExpr"):
                index = (index.get("inner") or [{}])[0]
            number = int(index["value"]) if index.get("kind") == "IntegerLiteral" else None
            arrays.append((_members(children[0], []), stride, number))
        current = children[0] if children else None
    return bits // 8, arrays, crossings


def scan(sources: list[Path], clang: str, flags: list[str],
         work: Path) -> tuple[list[tuple[str, str]], list[tuple[Path, set[tuple[str, str]]]], dict]:
    """Every (kind, query text) the compiled sources ask, per translation unit."""
    header = work / "scan.h"
    header.write_text(SCAN_HEADER)
    found: set[tuple[str, str]] = set()
    per_tu: list[tuple[Path, set[tuple[str, str]]]] = []
    types: dict[tuple[str, str, str], list[tuple]] = {}
    for src in sorted(p for p in sources if p.suffix == ".c"):
        out = subprocess.run([clang, "-Xclang", "-ast-dump=json", "-fsyntax-only", "-w",
                              "-include", str(header)] + flags + [str(src)],
                             capture_output=True, text=True)
        # An incomplete AST can silently omit queries after a parse error.
        if out.returncode:
            sys.exit(f"core-answers: query scan failed for {src}: {out.stderr}")
        try:
            ast = json.loads(out.stdout)
        except json.JSONDecodeError:
            sys.exit(f"core-answers: {src} produced no JSON AST: {out.stderr.strip()[:2000]}")
        tu: set[tuple[str, str]] = set()
        layout = None
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
                if callee and (callee.get("referencedDecl") or {}).get("name") in ("__kprog_scan", "__kprog_scan_access"):
                    # __kprog_scan(kind, query, <field expression...>)
                    kind = _literal(args[1]) if len(args) > 1 else None
                    query = _literal(args[2]) if len(args) > 2 else None
                    if kind and query:
                        query = " ".join(query.split())
                        tu.add((kind, query))
                        if len(args) > 3:
                            extra = None
                            if kind == "access_delta":
                                if layout is None:
                                    dumped = subprocess.run([clang, "-Xclang", "-fdump-record-layouts-complete",
                                        "-Xclang", "-fdump-record-layouts-simple", "-fsyntax-only", "-w",
                                        "-include", str(header)] + flags + [str(src)],
                                        capture_output=True, text=True)
                                    if dumped.returncode:
                                        sys.exit(f"core-answers: source layout failed: {dumped.stderr}")
                                    layout = source_layout(ast, dumped.stdout)
                                extra = source_access(args[3], *layout)
                            entry = (_var_type(args[3]), _members(args[3], []), extra)
                            values = types.setdefault((str(src), kind, query), [])
                            if entry not in values:
                                values.append(entry)
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
           ast_type: tuple | None = None) -> tuple[int | None, str]:
    """(answer, what BTF says) for one query.

    `ast_type` is what clang resolved the field expression to: the declared
    type of the variable it starts from, and the member names. It is used in
    preference to reading declarations as text, because the same spelling can
    name different types in different translation units.
    """
    if kind in ("field_exists", "field_size", "field_offset", "access_delta"):
        fp = None
        if ast_type and ast_type[0] and ast_type[1]:
            base, members = ast_type[:2]
            base = re.sub(r"^(?:(?:const|volatile|struct|union|enum)\s+)+", "", base)
            base = re.sub(r"\s*(\*|\[.*\])+$", "", base.strip())
            fp = (split_flavor(base), members)
        if kind == "access_delta" and ast_type and not ast_type[1]:
            return 0, "address has no CO-RE field access"
        if fp is None:
            fp = field_path(re.sub(r"^&\s*", "", arg) if kind == "access_delta" else arg, decls)
        if not fp:
            return None, "cannot tell which type the expression reads"
        type_name, path = fp
        hit = btf.member(type_name, path)
        if hit is None and kind == "access_delta":
            return "(__kprog_core_unanswered(), 0)", f"{type_name}.{'.'.join(path)} poisoned by absent target field"
        if hit is None:
            return (0 if kind in ("field_exists", "field_size") else None), \
                f"{type_name}.{'.'.join(path)} absent in target BTF"
        mem, bits = hit
        if kind == "access_delta":
            local = ast_type[2] if ast_type and len(ast_type) > 2 else None
            if local is None:
                return None, f"{type_name}.{'.'.join(path)} source address layout unavailable"
            source_offset, arrays, crossings = local
            for prefix, source_prefix in crossings:
                target_prefix = btf.member(type_name, prefix)
                if target_prefix is None or target_prefix[1] // 8 != source_prefix:
                    return None, f"{type_name}.{'.'.join(prefix)} nested pointer load also needs relocation"
            delta = bits // 8 - source_offset
            for prefix, source_stride, index in arrays:
                indexed = btf.member(type_name, prefix)
                element = btf.resolve(indexed[0]["type_id"]) if indexed else None
                if element and element["kind"] in ("ARRAY", "PTR"):
                    element = btf.resolve(element["type"])
                target_stride = btf.size_of(element)
                if index == 0:
                    continue
                if source_stride is None or target_stride is None:
                    return None, f"{type_name}.{'.'.join(prefix)} array stride unavailable"
                if source_stride != target_stride:
                    if index is None:
                        return None, f"{type_name}.{'.'.join(prefix)} dynamic array stride changes"
                    delta += index * (target_stride - source_stride)
            return delta, f"{type_name}.{'.'.join(path)} target{bits // 8}-source{source_offset}"
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
        name = split_flavor(re.sub(r"^(?:(?:const|volatile|struct|union|enum)\s+)+", "", name.strip()))
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
    ap.add_argument("dirs", nargs="+", type=Path, help="source files or trees to scan")
    args = ap.parse_args()

    sources: list[Path] = []
    for d in args.dirs:
        sources += [d] if d.is_file() else sorted(p for p in d.rglob("*") if p.suffix in (".c", ".h"))
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
            for ast_type in types.get((str(tu), kind, arg), [None]):
                value, detail = answer(btf, kind, arg, decls, ast_type)
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
            lines.append(f'    (__builtin_strcmp((text), {json.dumps(e["query"])}) == 0 '
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
