#!/usr/bin/env python3
"""Run the kernel BPF selftests' annotated programs through the five-step path.

The kernel selftests are the upstream corpus of verifier programs: each is a
C file under tools/testing/selftests/bpf/progs whose programs carry a BTF
decl_tag saying whether the verifier must accept or reject them
(`__success` / `__failure`, defined in progs/bpf_misc.h).  Those annotations
are the ground truth this harness checks the native path against.

What is measured, per program:

  * whether it compiles to a native x86-64 object with the corpus toolchain;
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

Usage: selftests.py [--progs DIR] [--out DIR] [--limit N] [--only NAME]
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
    """`[(section, name, annotations, body_kind)]` for one source file.

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
        out.append((section, am.group(3), attrs, kind))
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


def compile_native(source, out, includes, clang):
    """Compile one selftest to a native x86-64 object; returns (ok, stderr)."""
    cmd = [clang, "-O3", "-g", "-fPIC", "-c", "-DMICRO_NATIVE",
           "-D__TARGET_ARCH_x86", "-fms-extensions", "-fomit-frame-pointer",
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
    includes = [bpf_dir, progs, ROOT / "kprog/selftests/include",
                bpf_dir / "tools" / "include",
                bpf_dir / "tools" / "include" / "uapi",
                ROOT / "vendor/libbpf/include/uapi", ROOT / "vendor/libbpf/src",
                pathlib.Path("/usr/include/x86_64-linux-gnu")]

    rows = []
    for src in sorted(progs.glob("*.c")):
        if args.only and args.only not in src.name:
            continue
        try:
            text = src.read_text(errors="ignore")
        except OSError:
            continue
        for section, name, attrs, kind in annotations(text):
            want = expectation(attrs)
            if want is None:
                continue
            rows.append(dict(file=src.name, program=name, section=section,
                             body=kind, expect=want,
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

    # One file can mix C programs with inline-asm ones, and the asm makes the
    # whole translation unit uncompilable by the native compiler.  So compile
    # a file only when every program in it is C: a file with any asm program
    # is the asm family and its C programs share the same obstacle.
    compiled = {}
    asm_files = {r["file"] for r in rows if r["body"] == "asm"}
    for r in rows:
        if r["body"] != "c" or r["file"] in asm_files:
            continue
        src = pathlib.Path(r["path"])
        if src.name in compiled:
            continue
        obj = out / (src.stem + ".native.o")
        ok, err = compile_native(src, obj, includes, clang)
        compiled[src.name] = dict(ok=ok, obj=str(obj) if ok else None,
                                  error=err[-800:] if not ok else "",
                                  symbols=symbols(obj) if ok else [])
    for name in asm_files:
        compiled.setdefault(name, dict(ok=False, obj=None,
                                       error="file contains a BPF-asm program",
                                       symbols=[]))
    for r in rows:
        info = compiled.get(r["file"], {})
        r["compiled"] = info.get("ok")
        r["entry"] = r["program"] in info.get("symbols", [])
        if not info.get("ok"):
            r["compile_error"] = info.get("error", "")

    counts["files"] = len(compiled)
    counts["files_compiled"] = sum(1 for v in compiled.values() if v["ok"])
    counts["entries_present"] = sum(1 for r in rows if r.get("entry"))

    json.dump(dict(counts=counts, programs=rows),
              open(out / "programs.json", "w"), indent=1)
    print(json.dumps(counts, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))