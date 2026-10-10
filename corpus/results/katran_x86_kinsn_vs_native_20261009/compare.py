#!/usr/bin/env python3
"""Katran on x86-64 KVM: kinsn versus whole-program native, from retained runs.

Throughput: sender packets per second, summed over the pktgen threads of each
sample (the last "<n>pps" of each thread's output), median of post over median
of baseline. BPF cost: run_time_ns_delta / run_cnt_delta of balancer_ingress.
Run from the repository root.
"""
import json
import re
import statistics
import sys
from pathlib import Path

RUNS = [
    # (label, statistics-off run for throughput, statistics-on run for cost)
    ("kinsn full policy", "x86_kvm_corpus_20260604_110614_563901", "x86_kvm_corpus_20260604_080246_742228"),
    ("kinsn no bulk", "x86_kvm_corpus_20260605_004607_636479", "x86_kvm_corpus_20260604_232313_992341"),
    ("native whole program", "x86_kvm_corpus_20260529_064444_673720", "x86_kvm_corpus_20260529_061439_040837"),
    ("native whole program", "x86_kvm_corpus_20260527_015711_134639", "x86_kvm_corpus_20260527_005602_704153"),
]


def app(run):
    return json.loads((Path("corpus/results") / run / "details/apps/katran.json").read_text())


def pps(workload):
    total = 0
    for comp in workload.get("components", []):
        found = re.findall(r"(\d+)pps", comp.get("stdout", ""))
        if found:
            total += int(found[-1])
    return total


def cost(arm):
    progs = arm.get("bpf", {}).values()
    cnt = sum(p.get("run_cnt_delta", 0) for p in progs)
    t = sum(p.get("run_time_ns_delta", 0) for p in progs)
    return t / cnt if cnt else None


def main():
    print("| Arm | Throughput runs | Baseline pps (median) | Post pps (median) | Throughput ratio | Cost run | ns/run JIT -> post | Speedup per run |")
    print("|---|---|---:|---:|---:|---|---|---:|")
    for label, tput_run, cost_run in RUNS:
        t = app(tput_run)
        base = [pps(w) for w in t["baseline"]["workloads"]]
        post = [pps(w) for w in t["post_rejit"]["workloads"]]
        ratio = statistics.median(post) / statistics.median(base)
        c = app(cost_run)
        cb, cp = cost(c["baseline"]), cost(c["post_rejit"])
        speed = cb / cp if cb and cp else float("nan")
        print(f"| {label} | {tput_run} | {statistics.median(base):,.0f} | {statistics.median(post):,.0f} | {ratio:.3f}x | {cost_run} | {cb:.1f} -> {cp:.1f} | {speed:.2f}x |")
    return 0


if __name__ == "__main__":
    sys.exit(main())
