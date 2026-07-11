#!/usr/bin/env python3
"""Generate the two §6.2 evaluation bar charts.

Reads corpus/results/x86_kvm_corpus_* dirs, picks the most recent run that
matches each condition's pass list / config (and single-app union for the
post-fix conditions), computes:

  fig 1 — per-program geomean (Method B, §6.2.1)
  fig 2 — app-side workload throughput ratio (§6.2.2)

Both use the same layout: 6 app groups × N condition bars per group, with a
horizontal reference line at 1.0.

Re-run anytime to pick up new run dirs; missing cells render as gaps.

Usage:  python analysis/plot_eval.py [--out docs/tmp]
"""
from __future__ import annotations

import argparse
import json
import math
import re
from pathlib import Path
from statistics import mean

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np

RESULTS = Path("/home/yunwei37/workspace/bpf-benchmark/corpus/results")
APPS = [
    "bcc/set",
    "cilium/agent",
    "katran",
    "otelcol-ebpf-profiler/profiling",
    "tetragon/observer",
    "tracee/monitor",
]
APP_SHORT = {a: a.split("/")[0] if "/" in a else a for a in APPS}
APP_SHORT["otelcol-ebpf-profiler/profiling"] = "otel"

# Condition → (label, pass_csv | None, extra_filter | None)
# extra_filter: lambda(metadata) → bool   for skip_rejit / warmups=3 distinction
CONDITIONS = [
    ("noop ReJIT",
     "noop", lambda m: not m.get("skip_rejit") and (m.get("warmups") or 0) == 0),
    ("noop + map_inline",
     "noop,map_inline", None),
    ("prefetch",
     "prefetch", None),
    ("5-pass kop",
     "rotate,cond_select,extract,endian_fusion,bulk_memory", None),
    ("6-pass kop+prefetch",
     "rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch", None),
    ("BR (bytecode-rewrite)",
     "noop,wide_mem,const_prop,dce,bounds_check_merge,skb_load_bytes_spec", None),
]


# ─── data helpers ───────────────────────────────────────────────────────

def stress_ng_bogo(stdout: str) -> int:
    return sum(int(m.group(2)) for m in re.finditer(
        r"stress-ng: metrc.*\[\d+\]\s+(\S+)\s+(\d+)\s+([\d.]+)", stdout))


def parse_workload(w: dict, app: str) -> float:
    if app in ("bcc/set", "tetragon/observer", "tracee/monitor"):
        return stress_ng_bogo(w.get("stdout") or "")
    if app == "katran":
        out = w.get("stdout") or ""
        m = re.search(r"(\d+)\s+requests in", out)
        if m:
            return int(m.group(1))
        try:
            return json.loads(out or "{}").get("request_count") or 0
        except Exception:
            return 0
    if app == "cilium/agent":
        for c in w.get("components") or []:
            m = re.search(r"Requests/sec:\s*([\d.]+)", c.get("stdout") or "")
            if m:
                return float(m.group(1))
        return 0
    if app.startswith("otelcol"):
        tot = 0
        for c in w.get("components") or []:
            err = c.get("stderr") or ""
            mm = re.findall(r"sha256 ops=(\d+)", err)
            if mm:
                tot += int(mm[-1])
            else:
                m2 = re.search(r"cpu\s+(\d+)\s+30\.", c.get("stdout") or "")
                if m2:
                    tot += int(m2.group(1))
        return tot
    return 0


def total_size_ratio(payload: dict, key: str) -> float | None:
    """key in {bytes_jited, bytes_xlated}. Sum across all programs in payload."""
    b = (payload.get("baseline") or {}).get("bpf") or {}
    p = (payload.get("post_rejit") or {}).get("bpf") or {}
    bsum = sum(int(bb.get(key) or 0) for bb in b.values())
    psum = sum(int(pp.get(key) or 0) for pp in p.values())
    if bsum <= 0 or psum <= 0:
        return None
    return psum / bsum


def per_program_ratios(payload: dict, min_runs: int = 100) -> list[float]:
    b = (payload.get("baseline") or {}).get("bpf") or {}
    p = (payload.get("post_rejit") or {}).get("bpf") or {}
    out: list[float] = []
    for pid in set(b) & set(p):
        bb, pp = b[pid], p[pid]
        br = int(bb.get("run_cnt_delta") or 0)
        bt = int(bb.get("run_time_ns_delta") or 0)
        pr = int(pp.get("run_cnt_delta") or 0)
        pt = int(pp.get("run_time_ns_delta") or 0)
        if br <= 0 or pr <= 0 or bt <= 0 or pt <= 0:
            continue
        if min(br, pr) < min_runs:
            continue
        out.append((pt / pr) / (bt / br))
    return out


def geomean(xs: list[float]) -> float | None:
    return math.exp(sum(math.log(x) for x in xs) / len(xs)) if xs else None


def app_workload_ratio(payload: dict, app: str) -> float | None:
    b = [parse_workload(w, app) for w in (payload.get("baseline") or {}).get("workloads") or []]
    p = [parse_workload(w, app) for w in (payload.get("post_rejit") or {}).get("workloads") or []]
    b = [x for x in b if x]
    p = [x for x in p if x]
    if not b or not p:
        return None
    return mean(p) / mean(b)


# ─── condition → app dirs resolution ────────────────────────────────────

def find_dirs_for(condition_idx: int) -> dict[str, Path]:
    """Return {app: latest payload dir} for this condition.

    For multi-pass conditions where full-suite runs exist, prefer those. Otherwise
    use single-app reruns. Returns latest match per app.

    skip_rejit / warmups are stored in details/result.json (not metadata.json),
    so we read both.
    """
    label, pass_csv, extra = CONDITIONS[condition_idx]
    candidates_by_app: dict[str, list[tuple[float, Path, Path]]] = {a: [] for a in APPS}
    for d in sorted(RESULTS.glob("x86_kvm_corpus_2026050[78]_*")):
        meta_path = d / "metadata.json"
        if not meta_path.is_file():
            continue
        try:
            m = json.loads(meta_path.read_text())
        except Exception:
            continue
        cfg = m.get("config") or {}
        passes = ",".join(cfg.get("enabled_passes") or [])
        if passes != pass_csv:
            continue
        # Pull skip_rejit / warmups from details/result.json since metadata
        # doesn't carry them. Default to {skip_rejit: False, warmups: 0} if
        # that file is missing or doesn't have them (older schema).
        runtime_flags = {"skip_rejit": False, "warmups": 0}
        rj = d / "details" / "result.json"
        if rj.is_file():
            try:
                rd = json.loads(rj.read_text())
                runtime_flags = {
                    "skip_rejit": bool(rd.get("skip_rejit")),
                    "warmups": int(rd.get("warmups") or 0),
                }
            except Exception:
                pass
        merged = {**m, **runtime_flags}
        if extra is not None and not extra(merged):
            continue
        ts = m.get("started_at") or ""
        apps_dir = d / "details" / "apps"
        if not apps_dir.is_dir():
            continue
        for f in apps_dir.glob("*.json"):
            app_name = f.name.replace("__", "/").replace(".json", "")
            if app_name in candidates_by_app:
                candidates_by_app[app_name].append((ts, d, f))
    out: dict[str, Path] = {}
    for app, lst in candidates_by_app.items():
        if not lst:
            continue
        lst.sort(key=lambda t: t[0])
        out[app] = lst[-1][2]
    return out


def collect() -> dict:
    """Return data[app][condition_idx] = (per_prog_geomean, workload_ratio)."""
    data = {a: {} for a in APPS}
    for ci, _ in enumerate(CONDITIONS):
        dirs = find_dirs_for(ci)
        for app, pl_path in dirs.items():
            try:
                payload = json.loads(pl_path.read_text())
            except Exception:
                continue
            if (payload.get("baseline") or {}).get("bpf") is None:
                continue
            ratios = per_program_ratios(payload)
            g = geomean(ratios)
            wr = app_workload_ratio(payload, app)
            sj = total_size_ratio(payload, "bytes_jited")
            data[app][ci] = (g, wr, len(ratios), sj)
    return data


# ─── plotting ───────────────────────────────────────────────────────────

def render(data: dict, key: int, title: str, ylabel: str, out: Path,
           ymin: float = 0.5, ymax: float | None = None) -> None:
    """key=0 → per-program geomean ; key=1 → workload ratio ; key=3 → bytes_jited."""
    n_apps = len(APPS)
    n_conds = len(CONDITIONS)
    cmap = plt.get_cmap("tab10", n_conds)

    fig, ax = plt.subplots(figsize=(13, 5.5))
    bar_w = 0.8 / n_conds
    x = np.arange(n_apps)
    for ci, (cond_label, _, _) in enumerate(CONDITIONS):
        heights = []
        for app in APPS:
            cell = data.get(app, {}).get(ci)
            heights.append(cell[key] if cell and len(cell) > key and cell[key] is not None else float("nan"))
        offset = (ci - n_conds / 2 + 0.5) * bar_w
        ax.bar(
            x + offset, heights, bar_w,
            label=cond_label, color=cmap(ci), edgecolor="black", linewidth=0.4,
        )
        for xi, h in zip(x + offset, heights):
            if h == h:  # not nan
                ax.text(xi, h + 0.01, f"{h:.2f}", ha="center", va="bottom",
                        fontsize=6, rotation=90)

    ax.axhline(1.0, color="black", linewidth=0.8, linestyle="--", alpha=0.6)
    ax.set_xticks(x)
    ax.set_xticklabels([APP_SHORT[a] for a in APPS])
    ax.set_ylabel(ylabel)
    ax.set_title(title)
    vals = [data.get(a, {}).get(ci, (None,)*4)[key]
            for a in APPS for ci in range(n_conds)
            if data.get(a, {}).get(ci) and len(data[a][ci]) > key
               and data[a][ci][key] is not None]
    if ymax is not None:
        upper = ymax
    else:
        upper = max(1.6, max(vals) * 1.05) if vals else 1.6
    ax.set_ylim(ymin, upper)
    ax.grid(True, axis="y", alpha=0.25)
    ax.legend(loc="upper left", bbox_to_anchor=(1.0, 1.0), fontsize=8, frameon=False)
    plt.tight_layout()
    plt.savefig(out, dpi=130)
    plt.close(fig)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path,
                    default=Path("/home/yunwei37/workspace/bpf-benchmark/docs/tmp"))
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)

    data = collect()
    render(data, 0, "BpfReJIT — per-program geomean (post / baseline) by condition",
           "post / baseline (lower = faster after ReJIT)", args.out / "eval_per_program_geomean.png")
    render(data, 1, "BpfReJIT — app-side workload throughput ratio (post / baseline)",
           "post / baseline (higher = more app work after ReJIT)", args.out / "eval_app_workload.png")
    render(data, 3, "BpfReJIT — bytes_jited ratio (post / baseline) by condition",
           "post / baseline (lower = smaller machine code after ReJIT)",
           args.out / "eval_size_jited.png", ymin=0.96, ymax=1.04)

    # Also dump the data table to stdout for inspection.
    print(f"{'App':<35}", *(f"{c[0][:18]:>20}" for c in CONDITIONS), sep="")
    for app in APPS:
        row1 = [f"{(data[app].get(ci, (None,None,0))[0] or float('nan')):>20.3f}" for ci, _ in enumerate(CONDITIONS)]
        print(f"{app:<35} (prog) ", *row1)
        row2 = [f"{(data[app].get(ci, (None,None,0))[1] or float('nan')):>20.3f}" for ci, _ in enumerate(CONDITIONS)]
        print(f"{app:<35} (wkld) ", *row2)


if __name__ == "__main__":
    main()
