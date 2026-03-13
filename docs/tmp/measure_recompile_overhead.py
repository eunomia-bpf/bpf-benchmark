#!/usr/bin/env python3

import csv
import json
import math
import os
import pathlib
import statistics
import subprocess
import tempfile
import time


REPO_ROOT = pathlib.Path("/home/yunwei37/workspace/bpf-benchmark")
SCANNER = REPO_ROOT / "scanner/build/bpf-jit-scanner"
MICRO_DIR = REPO_ROOT / "micro/programs"
CORPUS_DIR = REPO_ROOT / "corpus/build"
FIXED_RESULTS = REPO_ROOT / "micro/results/kernel_recompile_v2_fixed_authoritative_20260312.json"

OUT_DIR = REPO_ROOT / "docs/tmp"
MICRO_CSV = OUT_DIR / "recompile_overhead_scanner_micro.csv"
CORPUS_CSV = OUT_DIR / "recompile_overhead_scanner_corpus_sample.csv"
CORPUS_INV_JSON = OUT_DIR / "recompile_overhead_corpus_inventory.json"
RECOMPILE_CSV = OUT_DIR / "recompile_overhead_recompile_latency.csv"
BLOB_CSV = OUT_DIR / "recompile_overhead_blob_sizes.csv"
SUMMARY_JSON = OUT_DIR / "recompile_overhead_summary.json"

SCANNER_REPEATS = 11
CORPUS_SAMPLE_SIZE = 50


def median(values):
    return statistics.median(values) if values else None


def run_scan(path, program_name=None, output_blob=None, capture_json=True):
    cmd = [str(SCANNER), "scan", str(path), "--all", "--v5", "--json"]
    if program_name:
        cmd.extend(["--program-name", program_name])
    if output_blob:
        cmd.extend(["--output", str(output_blob)])

    start = time.perf_counter_ns()
    completed = subprocess.run(
        cmd,
        check=True,
        stdout=subprocess.PIPE if capture_json else subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        text=True,
    )
    end = time.perf_counter_ns()
    payload = json.loads(completed.stdout) if capture_json else None
    return {
        "elapsed_ns": end - start,
        "payload": payload,
    }


def measure_scan(path, program_name=None, repeats=SCANNER_REPEATS):
    metadata = run_scan(path, program_name=program_name, capture_json=True)

    # Warm the binary and page cache once before recording medians.
    run_scan(path, program_name=program_name, capture_json=False)

    timings_ns = []
    for _ in range(repeats):
        sample = run_scan(path, program_name=program_name, capture_json=False)
        timings_ns.append(sample["elapsed_ns"])

    payload = metadata["payload"]
    summary = payload["summary"]
    program = payload["program"]
    return {
        "object_path": str(path),
        "program_name": program["name"],
        "insn_cnt": int(program["insn_cnt"]),
        "num_sites": int(summary["total_sites"]),
        "cmov_sites": int(summary["cmov_sites"]),
        "wide_sites": int(summary["wide_sites"]),
        "rotate_sites": int(summary["rotate_sites"]),
        "lea_sites": int(summary["lea_sites"]),
        "extract_sites": int(summary["extract_sites"]),
        "bitfield_sites": int(summary["bitfield_sites"]),
        "zero_ext_sites": int(summary["zero_ext_sites"]),
        "endian_sites": int(summary["endian_sites"]),
        "branch_flip_sites": int(summary["branch_flip_sites"]),
        "scan_times_ns": timings_ns,
        "scan_time_ns_median": int(median(timings_ns)),
        "scan_time_ms_median": median([ns / 1_000_000.0 for ns in timings_ns]),
    }


def write_csv(path, rows, fieldnames):
    with path.open("w", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def choose_stratified_sample(entries, sample_size):
    valid = sorted(entries, key=lambda row: (row["insn_cnt"], row["object_path"]))
    if len(valid) <= sample_size:
        return valid

    buckets = {}
    for row in valid:
        bucket = int(math.floor(math.log2(max(int(row["insn_cnt"]), 1))))
        buckets.setdefault(bucket, []).append(row)

    bucket_order = sorted(buckets)
    quotas = {bucket: 0 for bucket in bucket_order}
    chosen = 0
    while chosen < sample_size:
        progressed = False
        for bucket in bucket_order:
            rows = buckets[bucket]
            if quotas[bucket] >= len(rows):
                continue
            quotas[bucket] += 1
            chosen += 1
            progressed = True
            if chosen >= sample_size:
                break
        if not progressed:
            break

    selected = []
    for bucket in bucket_order:
        rows = buckets[bucket]
        quota = quotas[bucket]
        if quota == 0:
            continue
        if quota == 1:
            selected.append(rows[len(rows) // 2])
            continue
        for index in range(quota):
            row_index = round(index * (len(rows) - 1) / (quota - 1))
            selected.append(rows[row_index])

    selected = sorted(selected, key=lambda row: (row["insn_cnt"], row["object_path"]))
    deduped = []
    seen = set()
    for row in selected:
        key = (row["object_path"], row["program_name"])
        if key in seen:
            continue
        seen.add(key)
        deduped.append(row)

    if len(deduped) > sample_size:
        deduped = deduped[:sample_size]
    return deduped


def scan_corpus_inventory():
    entries = []
    for path in sorted(CORPUS_DIR.rglob("*.bpf.o")):
        try:
            sample = measure_scan(path, repeats=1)
        except subprocess.CalledProcessError:
            continue
        entries.append(
            {
                "object_path": sample["object_path"],
                "program_name": sample["program_name"],
                "insn_cnt": sample["insn_cnt"],
                "num_sites": sample["num_sites"],
            }
        )
    return entries


def measure_blob(path, label, program_name=None):
    with tempfile.TemporaryDirectory(prefix="recompile-overhead-") as tmp_dir:
        blob_path = pathlib.Path(tmp_dir) / "policy.bin"
        result = run_scan(path, program_name=program_name, output_blob=blob_path, capture_json=True)
        payload = result["payload"]
        return {
            "label": label,
            "object_path": str(path),
            "program_name": payload["program"]["name"],
            "insn_cnt": int(payload["program"]["insn_cnt"]),
            "num_sites": int(payload["summary"]["total_sites"]),
            "blob_bytes": blob_path.stat().st_size,
            "scan_elapsed_ms": result["elapsed_ns"] / 1_000_000.0,
        }


def select_blob_targets(corpus_inventory):
    inventory_by_path = {row["object_path"]: row for row in corpus_inventory}
    candidates = [
        {
            "label": "small-default",
            "path": REPO_ROOT / "corpus/build/xdp-tools/xdp_basic.bpf.o",
            "program_name": None,
        },
        {
            "label": "medium-katran",
            "path": REPO_ROOT / "corpus/build/katran/balancer.bpf.o",
            "program_name": "balancer_ingress",
        },
        {
            "label": "large-tracee",
            "path": REPO_ROOT / "corpus/build/tracee/tracee.bpf.o",
            "program_name": "cgroup_skb_egress",
        },
        {
            "label": "very-large-selftests",
            "path": REPO_ROOT / "corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o",
            "program_name": "balancer_ingress",
        },
        {
            "label": "calico-reference",
            "path": REPO_ROOT / "corpus/build/calico/from_hep_debug.bpf.o",
            "program_name": "calico_tc_main",
        },
    ]

    rows = []
    for target in candidates:
        if not target["path"].exists():
            continue
        rows.append(measure_blob(target["path"], target["label"], program_name=target["program_name"]))
    return rows


def extract_run_by_runtime(benchmark, runtime):
    for run in benchmark["runs"]:
        if run["runtime"] == runtime:
            return run
    raise KeyError(f"missing runtime {runtime!r} in benchmark {benchmark['name']}")


def recompile_syscall_ns(sample):
    phases = sample["phases_ns"]
    return (
        int(sample["compile_ns"])
        - int(phases["object_open_ns"])
        - int(phases["object_load_ns"])
    )


def extract_recompile_latency():
    with FIXED_RESULTS.open() as handle:
        suite = json.load(handle)

    rows = []
    benchmark_summary = []
    for benchmark in suite["benchmarks"]:
        stock = extract_run_by_runtime(benchmark, "kernel")
        recomp = extract_run_by_runtime(benchmark, "kernel-recompile")

        stock_compile = [int(sample["compile_ns"]) for sample in stock["samples"]]
        stock_load = [int(sample["phases_ns"]["object_load_ns"]) for sample in stock["samples"]]

        recomp_samples = recomp["samples"]
        attempted = [sample for sample in recomp_samples if sample["recompile"]["syscall_attempted"]]
        applied = [sample for sample in attempted if sample["recompile"]["applied"]]

        summary_row = {
            "benchmark": benchmark["name"],
            "category": benchmark["category"],
            "family": benchmark["family"],
            "level": benchmark["level"],
            "stock_compile_ns_median": int(median(stock_compile)),
            "stock_object_load_ns_median": int(median(stock_load)),
            "recompile_attempted": bool(attempted),
            "recompile_applied": bool(applied),
            "recompile_policy_bytes_median": int(median([int(sample["recompile"]["policy_bytes"]) for sample in applied])) if applied else 0,
            "recompile_total_sites_median": int(median([int(sample["recompile"]["total_sites"]) for sample in applied])) if applied else 0,
            "recompile_syscall_ns_median": int(median([recompile_syscall_ns(sample) for sample in applied])) if applied else 0,
        }
        benchmark_summary.append(summary_row)

        for sample in applied:
            rows.append(
                {
                    "benchmark": benchmark["name"],
                    "category": benchmark["category"],
                    "family": benchmark["family"],
                    "level": benchmark["level"],
                    "compile_ns": int(sample["compile_ns"]),
                    "object_open_ns": int(sample["phases_ns"]["object_open_ns"]),
                    "object_load_ns": int(sample["phases_ns"]["object_load_ns"]),
                    "recompile_syscall_ns": recompile_syscall_ns(sample),
                    "policy_bytes": int(sample["recompile"]["policy_bytes"]),
                    "recompile_total_sites": int(sample["recompile"]["total_sites"]),
                    "xlated_prog_len": int(sample["xlated_prog_len"]),
                    "jited_prog_len": int(sample["jited_prog_len"]),
                }
            )

    return rows, benchmark_summary


def main():
    micro_objects = sorted(MICRO_DIR.glob("*.bpf.o"))
    micro_rows = [measure_scan(path) for path in micro_objects]

    corpus_inventory = scan_corpus_inventory()
    sample_inventory = choose_stratified_sample(corpus_inventory, CORPUS_SAMPLE_SIZE)
    corpus_rows = [
        measure_scan(pathlib.Path(row["object_path"]))
        for row in sample_inventory
    ]

    blob_rows = select_blob_targets(corpus_inventory)
    recompile_rows, benchmark_summary = extract_recompile_latency()

    write_csv(
        MICRO_CSV,
        [
            {
                **{k: v for k, v in row.items() if k != "scan_times_ns"},
                "scan_times_ns_json": json.dumps(row["scan_times_ns"]),
            }
            for row in micro_rows
        ],
        [
            "object_path",
            "program_name",
            "insn_cnt",
            "num_sites",
            "cmov_sites",
            "wide_sites",
            "rotate_sites",
            "lea_sites",
            "extract_sites",
            "bitfield_sites",
            "zero_ext_sites",
            "endian_sites",
            "branch_flip_sites",
            "scan_time_ns_median",
            "scan_time_ms_median",
            "scan_times_ns_json",
        ],
    )
    write_csv(
        CORPUS_CSV,
        [
            {
                **{k: v for k, v in row.items() if k != "scan_times_ns"},
                "scan_times_ns_json": json.dumps(row["scan_times_ns"]),
            }
            for row in corpus_rows
        ],
        [
            "object_path",
            "program_name",
            "insn_cnt",
            "num_sites",
            "cmov_sites",
            "wide_sites",
            "rotate_sites",
            "lea_sites",
            "extract_sites",
            "bitfield_sites",
            "zero_ext_sites",
            "endian_sites",
            "branch_flip_sites",
            "scan_time_ns_median",
            "scan_time_ms_median",
            "scan_times_ns_json",
        ],
    )
    with CORPUS_INV_JSON.open("w") as handle:
        json.dump(
            {
                "corpus_inventory": corpus_inventory,
                "selected_sample": sample_inventory,
            },
            handle,
            indent=2,
        )
    write_csv(
        RECOMPILE_CSV,
        recompile_rows,
        [
            "benchmark",
            "category",
            "family",
            "level",
            "compile_ns",
            "object_open_ns",
            "object_load_ns",
            "recompile_syscall_ns",
            "policy_bytes",
            "recompile_total_sites",
            "xlated_prog_len",
            "jited_prog_len",
        ],
    )
    write_csv(
        BLOB_CSV,
        blob_rows,
        [
            "label",
            "object_path",
            "program_name",
            "insn_cnt",
            "num_sites",
            "blob_bytes",
            "scan_elapsed_ms",
        ],
    )

    summary = {
        "scanner_repeats": SCANNER_REPEATS,
        "micro_count": len(micro_rows),
        "corpus_inventory_count": len(corpus_inventory),
        "corpus_sample_count": len(corpus_rows),
        "micro_scan_time_ms_median_all": median([row["scan_time_ms_median"] for row in micro_rows]),
        "corpus_scan_time_ms_median_all": median([row["scan_time_ms_median"] for row in corpus_rows]),
        "recompile_benchmarks_total": len(benchmark_summary),
        "recompile_benchmarks_applied": sum(1 for row in benchmark_summary if row["recompile_applied"]),
        "recompile_syscall_ns_median_applied": int(median([row["recompile_syscall_ns_median"] for row in benchmark_summary if row["recompile_applied"]])),
        "recompile_policy_bytes_median_applied": int(median([row["recompile_policy_bytes_median"] for row in benchmark_summary if row["recompile_applied"]])),
        "benchmark_summary": benchmark_summary,
    }
    with SUMMARY_JSON.open("w") as handle:
        json.dump(summary, handle, indent=2)

    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
