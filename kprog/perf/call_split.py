#!/usr/bin/env python3
"""Cycle counts for the parts of one native micro program.

The published program is untouched.  A private copy wraps the pieces of its
entry in `rdtsc` pairs, so a run reports the cycles in the packet setup, in
the benchmark body (the program's own computation) and in the result write.
The body's internal call sites are the ones the plan inventory counts; this
splits the entry around the body call, which is what separates computation
from the rest.

`--program` writes the copy; `--build` compiles it with the same flags the
published native objects use; `--run` reports the tallies.
"""

import argparse
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]
PROGRAMS = ROOT / "micro/programs"
BUILD = PROGRAMS / "build-x86"

SITES = """
#include <stdio.h>
#include <unistd.h>

volatile unsigned long long site_cycles[3];
/* The counter write is a compiler barrier, so the body is not hoisted
 * across the marker that is supposed to bound it. */
#define MARK(slot, start)                                                 \
    do {                                                                  \
        unsigned long long __now = __builtin_ia32_rdtsc();                \
        site_cycles[slot] += __now - (start);                             \
        __asm__ __volatile__("" ::: "memory");                            \
        (start) = __now;                                                  \
    } while (0)
#define SITE_SETUP 0
#define SITE_BODY 1
#define SITE_WRITE 2

__attribute__((destructor)) static void __report_site_cycles(void)
{
    unsigned long long total = site_cycles[0] + site_cycles[1] +
                               site_cycles[2];
    if (!total)
        return;
    dprintf(2, "site-cycles setup=%llu body=%llu write=%llu total=%llu\\n",
            site_cycles[0], site_cycles[1], site_cycles[2], total);
}
"""

CLANG = "/usr/lib/llvm-18/bin/clang"
FLAGS = [
    "-Wall", "-Wextra", "-O3", "-g", "-fPIC", "-shared", "-fno-plt",
    "-DMICRO_NATIVE", "-fomit-frame-pointer", "-march=native",
    "-mno-red-zone", "-mgeneral-regs-only", "-fno-stack-protector",
    "-fno-asynchronous-unwind-tables", "-fno-unwind-tables",
    "-fno-jump-tables", "-mllvm", "-switch-to-lookup=false",
    "-I/usr/include/x86_64-linux-gnu",
]


def instrument(source, out_dir, body_only=False):
    """A copy of one program whose entry is split by cycle counters."""
    out_dir.mkdir(parents=True, exist_ok=True)
    text = (PROGRAMS / source).read_text()
    if body_only:
        # One span, around the benchmark call alone: the rest of the entry
        # is what the run does not spend inside the body.
        text = text.replace(
            "    if (bench_",
            "    { unsigned long long __b0 = __builtin_ia32_rdtsc();\n"
            "    if (bench_", 1)
        text = text.replace(
            "    micro_write_u64_le(data, result);",
            "    site_cycles[SITE_BODY] += "
            "__builtin_ia32_rdtsc() - __b0; }\n"
            "    micro_write_u64_le(data, result);", 1)
        if "SITE_BODY" not in text:
            return None
        unit = out_dir / source
        unit.write_text(SITES + text)
        return unit
    # The three spans are the entry's own phases; the body call is the
    # benchmark, and the write is the result store.
    text = text.replace(
        "    u64 result = 0;",
        "    u64 result = 0;\n"
        "    unsigned long long __t0;\n"
        "    __t0 = __builtin_ia32_rdtsc();")
    text = text.replace(
        "    if (bench_",
        "    MARK(SITE_SETUP, __t0);\n"
        "    if (bench_")
    text = text.replace(
        "    micro_write_u64_le(data, result);",
        "    MARK(SITE_BODY, __t0);\n"
        "    { unsigned long long __w = __builtin_ia32_rdtsc();\n"
        "      micro_write_u64_le(data, result);\n"
        "      site_cycles[SITE_WRITE] += "
        "__builtin_ia32_rdtsc() - __w; }")
    if "SITE_SETUP" not in text or "SITE_WRITE" not in text:
        return None
    unit = out_dir / source
    unit.write_text(SITES + text)
    return unit


def build(unit, out, arch_dir):
    command = [CLANG, *FLAGS, "-I", str(PROGRAMS), "-I", str(arch_dir),
               "-I", str(unit.parent), "-o", str(out), str(unit)]
    done = subprocess.run(command, capture_output=True, text=True)
    return done.returncode == 0, done.stderr


def run(library, bpf, memory, repeat):
    """Run through the staged runner, which supplies the program's input.

    The runner dlopens the library in its own process and the destructor
    prints the tallies on stderr, so the input is the program's own and the
    counters cover exactly the repeats the runner made.
    """
    command = ["./runner/build-llvmbpf/micro_exec", "run-native",
               "--program", bpf, "--native-program", str(library),
               "--inner-repeat", str(repeat)]
    if memory:
        command += ["--memory", memory, "--io-mode", "packet"]
    done = subprocess.run(command, capture_output=True, text=True)
    return done.stderr


def main(argv):
    ap = argparse.ArgumentParser()
    ap.add_argument("--program", default="katran_lb_consistent_hash_select"
                                        ".bpf.c")
    ap.add_argument("--symbol", default="katran_lb_consistent_hash_select_xdp")
    ap.add_argument("--memory", default="",
                    help="generated input; defaults to the program's own")
    ap.add_argument("--repeat", default="10000")
    ap.add_argument("--spans", default="three", choices=("three", "body"),
                    help="three spans, or the body alone")
    ap.add_argument("--out-dir", default=str(ROOT / "kprog/perf/measure"))
    args = ap.parse_args(argv[1:])
    out_dir = pathlib.Path(args.out_dir)
    unit = instrument(args.program, out_dir,
                      body_only=args.spans == "body")
    if unit is None:
        print("the entry did not carry the spans to instrument",
              file=sys.stderr)
        return 1
    library = out_dir / (pathlib.Path(args.program).name
                       .replace(".bpf.c", "") + ".native.so")
    ok, err = build(unit, library, BUILD)
    if not ok:
        print(err[-800:], file=sys.stderr)
        return 1
    print(library)
    base = pathlib.Path(args.program).name.replace(".bpf.c", "")
    bpf = str(BUILD / (base + ".bpf.o"))
    memory = args.memory or str(
        ROOT / "micro/generated-inputs" / (base + ".mem"))
    if not pathlib.Path(memory).exists():
        memory = ""
    print(run(library, bpf, memory, args.repeat).strip())
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))