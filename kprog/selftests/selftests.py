#!/usr/bin/env python3
"""Run the kernel BPF selftests' annotated programs through the five-step path.

The kernel selftests are the upstream corpus of verifier programs: each is a
C file under tools/testing/selftests/bpf/progs whose programs carry a BTF
decl_tag saying whether the verifier must accept or reject them
(`__success` / `__failure`, defined in progs/bpf_misc.h).  Those annotations
are the ground truth this harness checks the native path against.

What is measured, per program:

  * whether it compiles to a native target-ISA object with the corpus toolchain;
  * whether the five-step path accepts it (specialize, link, bind, verifier
    load, JIT) and, if it does, whether the kernel runs it;
  * whether that outcome agrees with the annotation.

The comparison is the point: a `__failure` program that runs means the
native path accepted something the verifier must reject, and a `__success`
program rejected by the verifier means the native path lost a program the
kernel accepts.

Programs written as BPF inline assembly (`__naked` with an `asm volatile`
body) are counted but skipped: they are BPF bytecode text, not C, so the
native x86-64 compiler cannot express them.  They stay with the kernel's
own test_progs.

Usage: selftests.py [--arch x86|arm64] [--progs DIR] [--out DIR] [--limit N] [--only NAME]
"""

import argparse
import json
import os
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
DEFAULT_PROGS = (ROOT / "vendor/linux-framework/tools/testing/selftests/bpf/progs")


def annotations(text):
    """`[(section, name, annotations, body_kind, offset)]` per file.

    A program is a `SEC("...")` declaration followed by a run of
    `__annotation(...)` attributes and then the C declaration.  Everything
    between the section and the declaration belongs to that program, which
    is what keeps one program's annotations from bleeding into the next.
    """
    out = []
    ann_re = re.compile(
        r"((?:\s*__\w+(?:\((?:[^()]|\([^()]*\))*\))?)*)"
        r"\s*([A-Za-z_][\w \*]*?)\b([A-Za-z_]\w*)\s*\(([^)]*)\)\s*\{")
    for m in re.finditer(r'SEC\("([^"]*)"\)', text):
        section = m.group(1)
        if section == ".maps":
            continue
        tail = text[m.end():m.end() + 800]
        am = ann_re.match(tail)
        if not am:
            continue
        attrs = am.group(1)
        # A BPF inline-assembly program starts its body with `asm volatile`
        # whether or not it is declared `__naked`; anything else begins with
        # a C statement the native compiler can express.
        # The task's rule: a BPF inline-assembly program is the `__naked`
        # form, and it stays with the kernel's test_progs.  The body is
        # checked as well, because a handful of `asm volatile` programs
        # declare a normal C signature and only their body is BPF asm.
        body = re.sub(r"\s+", " ", tail[am.end():].lstrip())
        naked = re.search(r"__naked(?![\w])", attrs) is not None
        kind = ("asm" if naked or body.startswith("asm")
                or "__clobber" in body[:1200] else "c")
        # A program runs from its own `SEC(` to the next one's, which is
        # what a per-program compile comments out exactly.
        name = am.group(3)
        if name in {"BPF_PROG", "BPF_PROG2", "BPF_KPROBE",
                    "BPF_KRETPROBE", "BPF_KSYSCALL"}:
            name = am.group(4).split(",", 1)[0].strip()
        out.append((section, name, attrs, kind, m.start()))
    return out


def marker(attrs, name):
    """Whether the annotation run names exactly this marker.

    `__failure` must not match `__failure_unpriv`: the two say different
    things, and 77 upstream programs carry `__success __failure_unpriv`.
    """
    return re.search(r"%s(?![\w])" % re.escape(name), attrs) is not None


def expectation(attrs):
    """'success', 'failure' or None for one program's annotations."""
    if marker(attrs, "__failure"):
        return "failure"
    if marker(attrs, "__success"):
        return "success"
    return None


def only_program(source, head, keep, out_dir):
    """A copy of `source` with every program but `keep` compiled out.

    A program is a `SEC(...)` attribute and the function it annotates, so
    it occupies the text from the start of its `SEC` line to the `}` that
    closes its body at column zero.  Removing exactly those ranges leaves
    every global declaration between programs in place, which matters
    because a sibling program may declare a type the kept one uses.
    """
    text = pathlib.Path(source).read_text(errors="ignore")
    spans = []
    for _, name, _, _, offset in head:
        start = text.rfind("\n", 0, offset) + 1
        close = text.find("\n}\n", offset)
        spans.append((start, len(text) if close < 0 else close + 3, name))
    spans.sort()
    pieces, cut = [], 0
    for start, end, name in spans:
        if name == keep:
            continue
        pieces.append(text[cut:start])
        pieces.append("#if 0\n" + text[start:end] + "#endif\n")
        cut = end
    pieces.append(text[cut:])
    unit = "".join(pieces)
    # A leading `?` says a section may hold several programs; with the
    # others removed, libbpf cannot infer a type from the marked name, so
    # the kept program carries the plain section it maps to.
    marked = _section_of(head, keep)
    if marked.startswith("?"):
        unit = unit.replace('SEC("%s")' % marked, 'SEC("%s")' % marked[1:])
    wrapper = out_dir / (pathlib.Path(source).stem + "__" + keep + ".c")
    wrapper.write_text(unit)
    return wrapper


def _section_of(head, name):
    """The section a program declares."""
    for section, program, _, _, _ in head:
        if program == name:
            return section
    return ""


def compile_bpf(source, out, includes, clang, arch="x86"):
    """Compile one selftest to a BPF object, as an application loads it."""
    # `-c` keeps clang from invoking the host linker, which cannot relink a
    # BPF object (EM_BPF relocations).
    cmd = [clang, "-O2", "-g", "-target", "bpf", "-mcpu=v4", "-c",
           "-D__TARGET_ARCH_" + arch]
    for inc in includes:
        cmd += ["-I", str(inc)]
    # Keep the original source's type/header order. Add the upstream kfunc
    # declarations immediately after its real libbpf helper declarations.
    compatibility = pathlib.Path(out).parent / "resource-include"
    for header in ("bpf_helpers.h", "bpf/bpf_helpers.h"):
        wrapper = compatibility / header
        wrapper.parent.mkdir(parents=True, exist_ok=True)
        wrapper.write_text(
            '#include_next <%s>\n#include <stdbool.h>\n#include "%s"\n' %
            (header, DEFAULT_PROGS.parent / "bpf_kfuncs.h"))
    cmd[1:1] = ["-I", str(compatibility)]
    stub = pathlib.Path(out).with_suffix(".license.c")
    stub.write_text(
        '__attribute__((section("license"), used))\n'
        'char __only_license[] = "GPL";\n'
        '#include "%s"\n' % pathlib.Path(source).resolve())
    cmd += [str(stub), "-o", str(out)]
    done = subprocess.run(cmd, capture_output=True, text=True)
    return done.returncode == 0, done.stderr


def compile_native(source, out, includes, clang, arch="x86"):
    """Compile one selftest to a native target-ISA object; returns (ok, stderr)."""
    # The kernel calls a native program with the BPF stack, so the native
    # frame must live inside the red zone's shadow and may not clobber the
    # FP/SIMD registers the BPF ABI leaves to the JIT: the corpus compiles
    # its native objects with `-mno-red-zone` and `-mgeneral-regs-only`
    # for the same reason.
    arch_flags = {
        "x86": ["-mno-red-zone", "-mretpoline-external-thunk",
                "-mfunction-return=thunk-extern", "-fcf-protection=branch"],
        "arm64": ["--target=aarch64-linux-gnu", "-march=armv8.1-a+lse", "-mbranch-protection=bti",
                  "-mno-outline-atomics", "-ffixed-x18", "-ffixed-x26",
                  "-ffixed-x27", "-ffixed-x28", "-fno-optimize-sibling-calls",
                  "-mllvm", "-switch-to-lookup=false"],
    }[arch]
    cmd = [clang, "-O3", "-g", "-fPIC", "-c", "-DMICRO_NATIVE",
           "-D__TARGET_ARCH_" + arch, "-fms-extensions", "-fomit-frame-pointer",
           *arch_flags, "-mgeneral-regs-only",
           "-fno-stack-protector", "-fno-asynchronous-unwind-tables",
           "-fno-unwind-tables", "-fno-jump-tables"]
    for inc in includes:
        cmd += ["-I", str(inc)]
    cmd += [str(source), "-o", str(out)]
    done = subprocess.run(cmd, capture_output=True, text=True)
    return done.returncode == 0, done.stderr


def symbols(obj):
    """The GLOBAL FUNC symbols a native object defines."""
    done = subprocess.run(["readelf", "-sW", str(obj)], capture_output=True,
                          text=True)
    out = []
    for line in done.stdout.splitlines():
        f = line.split()
        if len(f) >= 8 and f[3] == "FUNC" and f[4] == "GLOBAL":
            out.append(f[7])
    return out


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--progs", default=str(DEFAULT_PROGS))
    ap.add_argument("--arch", default="x86")
    ap.add_argument("--out", default=str(ROOT / "kprog/selftests/build"))
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--only", default="")
    args = ap.parse_args(argv[1:])

    progs = pathlib.Path(args.progs)
    out = pathlib.Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    clang = os.environ.get("CLANG") or "/usr/lib/llvm-18/bin/clang"
    bpf_dir = progs.parent
    # vmlinux.h is dumped from the same kernel the harness runs against
    # (`bpftool btf dump ... format c`), because the selftests use kernel
    # types the vendored bcc header predates -- bpf_rb_root,
    # bpf_res_spin_lock and the arena helpers.
    includes = [bpf_dir, progs, (out / "include" if args.arch == "arm64"
                                  else ROOT / "kprog/selftests/include"),
                bpf_dir / "tools" / "include",
                bpf_dir / "tools" / "include" / "uapi",
                ROOT / "vendor/libbpf/include/uapi", ROOT / "vendor/libbpf/src",
                pathlib.Path({"x86": "/usr/include/x86_64-linux-gnu",
                              "arm64": "/usr/aarch64-linux-gnu/include"}[args.arch])]

    rows = []
    per_file = {}
    for src in sorted(progs.glob("*.c")):
        if args.only and args.only not in src.name:
            continue
        try:
            text = src.read_text(errors="ignore")
        except OSError:
            continue
        found = annotations(text)
        per_file[src.name] = found
        for section, name, attrs, kind, offset in found:
            want = expectation(attrs)
            if want is None:
                continue
            rows.append(dict(file=src.name, program=name, section=section,
                             body=kind, expect=want, offset=offset,
                             path=str(src)))
            if args.limit and len(rows) >= args.limit:
                break
        if args.limit and len(rows) >= args.limit:
            break

    counts = {"programs": len(rows)}
    for kind in ("c", "asm"):
        counts[kind] = sum(1 for r in rows if r["body"] == kind)
    for want in ("failure", "success"):
        counts[want] = sum(1 for r in rows if r["expect"] == want)

    # A file may mix C programs with inline-asm ones, and an asm body makes
    # the translation unit uncompilable by the native compiler.  Every
    # program is compiled from its own unit with the others commented out,
    # so a C program in a mixed file compiles and its asm siblings do not
    # take it with them.
    compiled = {}
    companions = {}
    for r in rows:
        if r["body"] != "c":
            continue
        src = pathlib.Path(r["path"])
        # Native compilation isolates each C entry. The complete original BPF
        # object supplies its program context, maps and complete BTF pointee
        # definitions; the direct producer disables every program's autoload.
        unit = only_program(src, per_file.get(src.name, []), r["program"],
                            out)
        obj = out / (src.stem + "__" + r["program"] + ".native.o")
        ok, err = compile_native(unit, obj, includes, clang, args.arch)
        bpf = out / (src.stem + ".bpf.o")
        if ok and src not in companions:
            companions[src] = compile_bpf(src, bpf, includes, clang, args.arch)
        bpf_ok, bpf_err = companions.get(src, (False, "native compile failed"))
        compiled[(src.name, r["program"])] = dict(
            ok=ok, obj=str(obj) if ok else None,
            bpf=str(bpf) if bpf_ok else None,
            error=err[-800:] if not ok else "",
            bpf_error=(bpf_err[-400:] if not bpf_ok else ""),
            symbols=symbols(obj) if ok else [])
    for r in rows:
        info = compiled.get((r["file"], r["program"]), {})
        r["compiled"] = info.get("ok")
        r["bpf_object"] = info.get("bpf")
        r["entry"] = r["program"] in info.get("symbols", [])
        if not info.get("ok"):
            r["compile_error"] = info.get("error", "")
        if info.get("ok") and not r["bpf_object"]:
            r["bpf_error"] = info.get("bpf_error", "")

    counts["files"] = len({k[0] for k in compiled})
    counts["files_compiled"] = len({k[0] for k, v in compiled.items()
                                    if v["ok"]})
    counts["programs_compiled"] = sum(1 for v in compiled.values() if v["ok"])
    counts["entries_present"] = sum(1 for r in rows if r.get("entry"))

    json.dump(dict(counts=counts, programs=rows),
              open(out / "programs.json", "w"), indent=1)
    print(json.dumps(counts, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))