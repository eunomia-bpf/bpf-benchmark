#!/usr/bin/env python3
"""Summarize the native_lab vs kernel BPF JIT comparison.

Reads the JSONL output of run_all_micro.sh and prints a per-program
table plus a geometric-mean ratio summary. Per CLAUDE.md, this script
lives outside the benchmark framework and does no in-framework
aggregation; it operates on the raw sample_result payloads emitted by
micro_exec.

A program is *measurable* only when both runtimes produced matching
(`result`, `retval`) tuples. Programs whose context layout makes the
native compilation see a different memory image than the kernel BPF
runtime (currently `tc_*` and `cgroup_skb_*`) report MISMATCH and are
excluded from the geomean.
"""
import json
import math
import statistics
import sys
from pathlib import Path

DEFAULT = Path(__file__).resolve().parent.parent / "results" / "all_micro.jsonl"


def main() -> int:
    path = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT
    by_prog: dict[str, dict[str, dict]] = {}
    for line in path.read_text().splitlines():
        if not line.strip():
            continue
        rec = json.loads(line)
        prog = rec["program"]
        rt = rec["runtime"]
        by_prog.setdefault(prog, {})[rt] = rec

    print(f"{'program':<46s}  {'native_lab':>12s}  {'kernel_jit':>12s}  "
          f"{'ratio':>8s}  status")
    print("-" * 92)
    ratios = []
    mismatches: list[str] = []
    errors: list[str] = []
    skipped = 0
    for prog, rts in sorted(by_prog.items()):
        nl = rts.get("native_lab", {})
        kj = rts.get("kernel_jit", {})
        if "skip" in nl or "skip" in kj:
            print(f"{prog:<46s}  {'SKIP':>12s}  {'SKIP':>12s}")
            skipped += 1
            continue
        if "error" in nl or "error" in kj:
            err = nl.get("error") or kj.get("error")
            print(f"{prog:<46s}  ERROR ({err})")
            errors.append(prog)
            continue
        nl_ns = nl.get("exec_ns", 0)
        kj_ns = kj.get("exec_ns", 0)
        result_ok = nl.get("result") == kj.get("result") and \
                    nl.get("retval") == kj.get("retval")
        status = "OK" if result_ok else "MISMATCH"
        if not result_ok:
            mismatches.append(prog)
        if nl_ns == 0 or kj_ns == 0:
            print(f"{prog:<46s}  {nl_ns:>12d}  {kj_ns:>12d}  "
                  f"{'-':>8s}  {status}")
            continue
        ratio = nl_ns / kj_ns
        if result_ok:
            ratios.append(ratio)
        print(f"{prog:<46s}  {nl_ns:>12d}  {kj_ns:>12d}  "
              f"{ratio:>8.3f}  {status}")

    print()
    if ratios:
        gmean = math.exp(statistics.mean(math.log(r) for r in ratios))
        wins = sum(1 for r in ratios if r < 1.0)
        losses = sum(1 for r in ratios if r > 1.0)
        ties = sum(1 for r in ratios if r == 1.0)
        print(f"Per-program ratio (native_lab / kernel_jit), validated runs only:")
        print(f"  geomean = {gmean:.4f}x  ({'native_lab faster' if gmean < 1 else 'kernel_jit faster'})")
        print(f"  range   = {min(ratios):.3f} .. {max(ratios):.3f}")
        print(f"  wins (native_lab faster) = {wins}")
        print(f"  losses (kernel_jit faster) = {losses}")
        print(f"  ties = {ties}")
        print(f"  programs validated = {len(ratios)}")
    if mismatches:
        print()
        print(f"Excluded from geomean (output identity check failed):")
        for p in mismatches:
            print(f"  {p}")
        print("  -- typically tc/cgroup_skb programs whose kernel ctx is")
        print("     `struct sk_buff` (data/data_end at deep offsets), but")
        print("     the userspace MICRO_NATIVE build assumed xdp_md-style")
        print("     offsets 0/8. Both runtimes execute; only their views of")
        print("     ctx diverge, so the comparison is not apples-to-apples.")
    if errors:
        print()
        print(f"Errored: {len(errors)} ({', '.join(errors)})")
    if skipped:
        print()
        print(f"Skipped: {skipped}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
