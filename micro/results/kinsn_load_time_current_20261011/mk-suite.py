import sys
import yaml

src = "/home/yunwei37/workspace/codex-runs/agent3-kinsn-load-20261009/src-paper62/micro/config/micro_pure_jit.yaml"
out = sys.argv[1]
retvals = {}
if len(sys.argv) > 2:
    for line in open(sys.argv[2]):
        name, value = line.split()
        retvals[name] = int(value)
m = yaml.safe_load(open(src))
names = [l.strip() for l in open("paper-62.txt") if l.strip()]
by = {b["name"]: b for b in m["benchmarks"]}
lines = [
    "# 62-program population of the paper load-time claim (Apr29/May14 runs), taken from",
    "# bpf-benchmark fed5531cd micro/config/micro_pure_jit.yaml (the manifest of the May14 campaigns).",
    "# Objects in ./programs were built from the same fed5531cd sources with clang-18 -O2 -g and have",
    "# the same instruction counts as the May14 loads.  Changes for the current runner: the old input",
    "# generators no longer exist, so input_generator and expected_result are dropped (programs run on",
    "# a zero-filled input of kernel_input_size bytes; load time does not depend on input), and",
    "# expected_retval is the zero-input return value observed in the pilot run (-1 = unknown).",
    "suite_name: micro_staged_codegen_paper62",
    "paths:",
    "  program_dir: micro/results/kinsn_load_time_current_20261011/programs",
    "build:",
    "  runner_binary: runner/build/micro_exec",
    "benchmark_defaults:",
    "  io_mode: staged",
    "runtimes:",
    "  - name: kernel",
    "  - name: kernel_rejit",
    "benchmarks:",
]
for n in names:
    b = by[n]
    lines.append(f"  - name: {n}")
    lines.append(f"    base_name: {b['base_name']}")
    if b.get("io_mode"):
        lines.append(f"    io_mode: {b['io_mode']}")
    lines.append(f"    kernel_input_size: {b['kernel_input_size']}")
    lines.append(f"    expected_retval: {retvals.get(n, -1)}")
    lines.append(f"    tags: [{', '.join(b['tags'])}]")
open(out, "w").write("\n".join(lines) + "\n")
y = yaml.safe_load(open(out))
print(out, len(y["benchmarks"]))
