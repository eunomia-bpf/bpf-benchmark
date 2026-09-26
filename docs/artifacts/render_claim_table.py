#!/usr/bin/env python3
"""Render a human-readable artifact claim table from real result JSONs.

This is the evaluator-facing "results -> human-readable" step required by the
ATC "Reproduced" checklist. It reads only files that exist on disk, derives each
claim from the actual JSON fields, and reports PASS / PARTIAL / UNAVAILABLE with
explicit provenance. It never invents numbers and never treats a hard-coded plot
value as a reproduced result.

Usage:
    python3 docs/artifacts/render_claim_table.py [ROOT_DIR]
    python3 docs/artifacts/render_claim_table.py --self-test

--self-test runs focused assertions against temporary synthetic JSON (valid and
malformed) to catch wrong paths, empty datasets, and unparsable content. It
exits non-zero on failure.

Exit status of the normal run is 0 when the table was produced; UNAVAILABLE rows
are the point of the table, so they do not fail the run.
"""

from __future__ import annotations

import hashlib
import json
import math
import re
import statistics
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

PASS = "PASS"
PARTIAL = "PARTIAL"
UNAVAILABLE = "UNAVAILABLE"

# Status vocabulary observed in the shipped framework output:
#   progress.json / metadata.json : completed | error | running
#   details/result.json           : ok | ...
#   details/apps/<app>.json       : ok | error ; plus rejit_result.status
SUITE_SUCCESS = "completed"
APP_SUCCESS = "ok"
REJIT_SUCCESS = "ok"

# Corpus run types the retained-bytecode rows accept. x86 KVM and arm64 QEMU
# drive the same loader-interception protocol; the reconciled bytecode is raw
# `struct bpf_insn[]` (8 bytes per insn on both), so the row gates on the
# suite and the run's own records rather than on the executor architecture.
CORPUS_RUN_TYPES = {"x86_kvm_corpus", "arm64_qemu_corpus"}

MICRO_RESULTS = {
    "RQ1 micro x86 (run)": "micro/results/x86_kvm_micro_20260519_114214_364050",
    "RQ1 micro x86 (stock baseline)": "micro/results/x86_kvm_micro_20260526_210351_224315",
    "RQ1 micro arm64": "micro/results/aws_arm64_micro_20260606_001225_821028",
    "Section 3 pure-bytecode x86": "micro/results/x86_kvm_micro_20260526_210952_650695",
    "Section 3 pure-bytecode arm64": "micro/results/aws_arm64_micro_20260606_063319_954947",
    "RQ1 x86 historical load-time run A": "micro/results/x86_kvm_micro_20260514_031744_210343",
    "RQ1 x86 historical load-time run B": "micro/results/x86_kvm_micro_20260514_181806_133778",
    "RQ1 x86 historical 62-case population": "micro/results/x86_kvm_micro_20260429_035938_203074",
}

COVERAGE_RUN = "docs/artifacts/evidence/kvm-six-app-coverage"
SIX_APP_SUCCESS_RUN = "docs/artifacts/evidence/kvm-six-app-success"
SIX_APP_COMMAND = (
    "SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=7200 make corpus"
)
SMOKE_RUN = "docs/artifacts/evidence/kvm-katran-smoke"
SMOKE_COMMAND = (
    "BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 "
    "TIMEOUT=3000 make corpus"
)
FORMAL_RECEIPT = "docs/artifacts/evidence/formal-check.json"
FORMAL_LOG = "docs/artifacts/evidence/formal-check.log"
FORMAL_MAKEFILE = "native-sim/formal/Makefile"
# The formal check prints one `<label> host cross-check: OK (<N> cases)` line
# per cross-check program; the totals are the oracle-case counts they report.
FORMAL_CASES = re.compile(r"host cross-check: OK \((\d+) cases\)")
FORMAL_LOG_COMMIT = re.compile(r"\bcommit=([0-9a-f]{40})\b")
FORMAL_LOG_EXIT = re.compile(r"\bexit=(\d+)\b")


@dataclass
class Row:
    claim: str
    status: str
    evidence: str


def load_json(path: Path):
    try:
        with path.open() as fh:
            return json.load(fh)
    except Exception:
        return None


def micro_evidence(result_path: Path) -> tuple[str, str]:
    """Derive real evidence from a micro details/result.json."""
    data = load_json(result_path)
    if not isinstance(data, dict):
        return UNAVAILABLE, f"{result_path} missing or unparsable"
    benches = data.get("benchmarks")
    if not isinstance(benches, list) or not benches:
        return UNAVAILABLE, f"{result_path} has no benchmarks"

    checked = 0
    mismatches = 0
    ns_samples = 0
    missing_ns = 0
    for b in benches:
        if not isinstance(b, dict):
            continue
        expected = b.get("expected_result")
        for run in b.get("runs") or []:
            if not isinstance(run, dict):
                continue
            for s in run.get("samples") or []:
                if not isinstance(s, dict):
                    continue
                checked += 1
                if expected is not None and s.get("result") != expected:
                    mismatches += 1
                expected_retval = b.get("expected_retval")
                if expected_retval is not None and s.get("retval") != expected_retval:
                    mismatches += 1
                ns = s.get("exec_ns")
                if isinstance(ns, (int, float)):
                    ns_samples += 1
                else:
                    missing_ns += 1
    if checked == 0:
        return UNAVAILABLE, f"{result_path} has no samples"

    prov = (
        f"{result_path}: {len(benches)} benchmarks, {checked} samples, "
        f"exec_ns present={ns_samples}, correctness mismatches={mismatches}"
    )
    if mismatches == 0 and missing_ns == 0:
        return PASS, prov
    if mismatches == 0:
        return PARTIAL, prov + f" (missing exec_ns in {missing_ns} samples)"
    return PARTIAL, prov


def median_runtime_ns(data: dict, runtime: str) -> dict[str, float]:
    rows: dict[str, float] = {}
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            values = [
                sample.get("exec_ns")
                for sample in run.get("samples") or []
                if isinstance(sample, dict)
            ]
            if values and all(isinstance(value, (int, float)) and value > 0 for value in values):
                rows[bench["name"]] = statistics.median(values)
            break
    return rows


def median_native_bytes(data: dict, runtime: str) -> dict[str, float]:
    rows: dict[str, float] = {}
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            values = [
                (sample.get("code_size") or {}).get("native_code_bytes")
                for sample in run.get("samples") or []
                if isinstance(sample, dict)
            ]
            if values and all(isinstance(v, (int, float)) and v > 0 for v in values):
                rows[bench["name"]] = statistics.median(values)
            break
    return rows


def median_object_load_ns(data: dict, runtime: str) -> dict[str, float]:
    rows: dict[str, float] = {}
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            values = [
                (sample.get("phases_ns") or {}).get("object_load_ns")
                for sample in run.get("samples") or []
                if isinstance(sample, dict)
            ]
            if values and all(isinstance(v, (int, float)) and v > 0 for v in values):
                rows[bench["name"]] = statistics.median(values)
            break
    return rows

def median_object_compile_ns(data: dict, runtime: str) -> dict[str, float]:
    """Per-case median of the timed open+load region.

    The paper's load-overhead sentence (evaluation section 7.1: "covering
    verification and JIT") names the quantity the kernel runner records as
    ``sample.compile_ns = object_open_ns + object_load_ns`` (see
    runner/src/kernel_runner.cpp), i.e. both the ELF open and the
    verifier/JIT load. Bare ``object_load_ns`` excludes the open. Both are
    derived so the row can report the paper-matched quantity without
    redefining the retained field.
    """
    rows: dict[str, float] = {}
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            values = []
            for sample in run.get("samples") or []:
                if not isinstance(sample, dict):
                    values = []
                    break
                phases = sample.get("phases_ns") or {}
                opened = phases.get("object_open_ns")
                loaded = phases.get("object_load_ns")
                if not all(isinstance(v, (int, float)) and v > 0 for v in (opened, loaded)):
                    values = []
                    break
                values.append(opened + loaded)
            if values:
                rows[bench["name"]] = statistics.median(values)
            break
    return rows


def kop_applied_in_sample(sample: dict) -> int:
    count = 0
    for program in ((sample.get("rejit_result") or {}).get("per_program") or {}).values():
        for result in program.get("passes") or []:
            summary = result.get("bpfopt_summary") or {}
            if summary.get("pass") == "kop":
                count += int(summary.get("sites_applied") or 0)
    return count


def median_kop_applied(data: dict, runtime: str) -> dict[str, float]:
    rows: dict[str, float] = {}
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            counts = [kop_applied_in_sample(s)
                      for s in run.get("samples") or [] if isinstance(s, dict)]
            if counts:
                rows[bench["name"]] = statistics.median(counts)
            break
    return rows


def micro_run_provenance_ok(root: Path, rel: str, run_type: str, arch: str) -> bool:
    d = root / rel
    metadata = load_json(d / "metadata.json") or {}
    progress = load_json(d / "details/progress.json") or {}
    host = metadata.get("host") or {}
    return (
        metadata.get("status") == "completed"
        and progress.get("status") == "completed"
        and metadata.get("run_type") == run_type
        and metadata.get("suite") == "micro_staged_codegen"
        and arch in str(host.get("platform") or "")
        and host.get("kernel_version") == "7.0.0-rc2+"
    )


def micro_claim_rows(root: Path) -> list[Row]:
    """Calculate the paper's 27-case RQ1 ratios, separately from raw-file integrity."""
    x86 = load_json(root / MICRO_RESULTS["RQ1 micro x86 (run)"] / "details/result.json")
    stock = load_json(root / MICRO_RESULTS["RQ1 micro x86 (stock baseline)"] / "details/result.json")
    arm = load_json(root / MICRO_RESULTS["RQ1 micro arm64"] / "details/result.json")
    rows: list[Row] = []

    if isinstance(x86, dict) and isinstance(stock, dict):
        candidate = median_runtime_ns(x86, "kernel")
        baseline = median_runtime_ns(stock, "kernel")
        paper_cases = sorted((candidate.keys() & baseline.keys()) - {"simple", "simple_packet"})
        ratios = [baseline[name] / candidate[name] for name in paper_cases]
        if len(paper_cases) == 27 and ratios:
            value = math.exp(sum(math.log(ratio) for ratio in ratios) / len(ratios))
            provenance_ok = all(micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
                                for rel in (MICRO_RESULTS["RQ1 micro x86 (run)"],
                                            MICRO_RESULTS["RQ1 micro x86 (stock baseline)"]))
            status = PASS if f"{value:.3f}" == "1.242" and provenance_ok else PARTIAL
            rows.append(Row(
                "RQ1 x86 paper 27-case speedup (1.242x)",
                status,
                f"median stock/candidate exec_ns, geomean={value:.6f}x over "
                f"{len(paper_cases)} cases; excludes baseline-only simple and simple_packet; "
                f"run metadata/progress valid={provenance_ok}; "
                "historical git_sha=unknown; source: two RQ1 x86 result.json files",
            ))
        else:
            rows.append(Row("RQ1 x86 paper 27-case speedup (1.242x)", UNAVAILABLE,
                            f"matched non-baseline cases={len(paper_cases)}, expected 27"))
    else:
        rows.append(Row("RQ1 x86 paper 27-case speedup (1.242x)", UNAVAILABLE,
                        "RQ1 x86 candidate or stock result.json missing"))

    if isinstance(x86, dict) and isinstance(stock, dict):
        candidate_bytes = median_native_bytes(x86, "kernel")
        stock_bytes = median_native_bytes(stock, "kernel")
        names = sorted(candidate_bytes.keys() & stock_bytes.keys())
        if len(names) == 29:
            value = math.exp(sum(math.log(candidate_bytes[n] / stock_bytes[n]) for n in names) / len(names))
            provenance_ok = all(micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
                                for rel in (MICRO_RESULTS["RQ1 micro x86 (run)"],
                                            MICRO_RESULTS["RQ1 micro x86 (stock baseline)"]))
            rows.append(Row("RQ1 x86 generated code size (0.772x)",
                            PASS if f"{value:.3f}" == "0.772" and provenance_ok else PARTIAL,
                            f"geomean candidate/stock median native_code_bytes={value:.6f}x "
                            f"over {len(names)} cases; run metadata/progress valid={provenance_ok}"))
        else:
            rows.append(Row("RQ1 x86 generated code size (0.772x)", UNAVAILABLE,
                            f"matched code-size cases={len(names)}, expected 29"))
    else:
        rows.append(Row("RQ1 x86 generated code size (0.772x)", UNAVAILABLE,
                        "RQ1 x86 candidate or stock result.json missing"))

    if isinstance(arm, dict):
        kernel = median_runtime_ns(arm, "kernel")
        rejit = median_runtime_ns(arm, "kernel_rejit")
        applied_names = []
        for bench in arm.get("benchmarks") or []:
            if not isinstance(bench, dict) or bench.get("name") not in kernel.keys() & rejit.keys():
                continue
            for run in bench.get("runs") or []:
                if isinstance(run, dict) and run.get("runtime") == "kernel_rejit":
                    counts = [kop_applied_in_sample(sample) for sample in run.get("samples") or []]
                    if counts and statistics.median(counts) > 0:
                        applied_names.append(bench["name"])
                    break
        ratios = [kernel[name] / rejit[name] for name in applied_names]
        if len(applied_names) == 27 and ratios:
            value = math.exp(sum(math.log(ratio) for ratio in ratios) / len(ratios))
            provenance_ok = micro_run_provenance_ok(
                root, MICRO_RESULTS["RQ1 micro arm64"], "aws_arm64_micro", "aarch64"
            )
            status = PASS if f"{value:.3f}" == "1.222" and provenance_ok else PARTIAL
            rows.append(Row(
                "RQ1 arm64 27 KOperation-bearing cases (1.222x)",
                status,
                f"median kernel/kernel_rejit exec_ns, geomean={value:.6f}x over "
                f"{len(applied_names)} cases with median applied kop sites > 0; "
                f"run metadata/progress valid={provenance_ok}; "
                "historical git_sha=unknown; source: RQ1 arm64 result.json",
            ))
        else:
            rows.append(Row("RQ1 arm64 27 KOperation-bearing cases (1.222x)",
                            UNAVAILABLE, f"KOperation-bearing cases={len(applied_names)}, expected 27"))
    else:
        rows.append(Row("RQ1 arm64 27 KOperation-bearing cases (1.222x)",
                        UNAVAILABLE, "RQ1 arm64 result.json missing"))
    if isinstance(arm, dict):
        kernel_bytes = median_native_bytes(arm, "kernel")
        rejit_bytes = median_native_bytes(arm, "kernel_rejit")
        names = sorted(kernel_bytes.keys() & rejit_bytes.keys())
        if len(names) == 29:
            value = math.exp(sum(math.log(rejit_bytes[n] / kernel_bytes[n]) for n in names) / len(names))
            provenance_ok = micro_run_provenance_ok(
                root, MICRO_RESULTS["RQ1 micro arm64"], "aws_arm64_micro", "aarch64"
            )
            rows.append(Row("RQ1 arm64 generated code size (0.879x)",
                            PASS if f"{value:.3f}" == "0.879" and provenance_ok else PARTIAL,
                            f"geomean kernel_rejit/kernel median native_code_bytes={value:.6f}x "
                            f"over {len(names)} cases; run metadata/progress valid={provenance_ok}"))
        else:
            rows.append(Row("RQ1 arm64 generated code size (0.879x)", UNAVAILABLE,
                            f"matched code-size cases={len(names)}, expected 29"))
    else:
        rows.append(Row("RQ1 arm64 generated code size (0.879x)", UNAVAILABLE,
                        "RQ1 arm64 result.json missing"))
    load_rels = [
        MICRO_RESULTS["RQ1 x86 historical load-time run A"],
        MICRO_RESULTS["RQ1 x86 historical load-time run B"],
    ]
    historical_runs = [load_json(root / rel / "details/result.json") for rel in load_rels]
    population_rel = MICRO_RESULTS["RQ1 x86 historical 62-case population"]
    population = load_json(root / population_rel / "details/result.json")
    if all(isinstance(run, dict) for run in historical_runs) and isinstance(population, dict):
        population_names = {
            b["name"] for b in population.get("benchmarks") or []
            if isinstance(b, dict) and isinstance(b.get("name"), str)
        }
        estimates = []
        for rel, run in zip(load_rels, historical_runs):
            kernel_load = median_object_load_ns(run, "kernel")
            rejit_load = median_object_load_ns(run, "kernel_rejit")
            kernel_compile = median_object_compile_ns(run, "kernel")
            rejit_compile = median_object_compile_ns(run, "kernel_rejit")
            names = sorted(kernel_load.keys() & rejit_load.keys()
                           & kernel_compile.keys() & rejit_compile.keys()
                           & population_names)
            if len(names) != 62:
                estimates = []
                break
            value = math.exp(sum(math.log(rejit_load[n] / kernel_load[n]) for n in names) / 62)
            compile_value = math.exp(
                sum(math.log(rejit_compile[n] / kernel_compile[n]) for n in names) / 62)
            provenance_ok = micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
            estimates.append((rel, value, compile_value, provenance_ok))
        if len(estimates) == 2:
            detail = "; ".join(
                f"{rel.rsplit('/', 1)[-1]}=open+load {compile_value:.6f}x (rounds "
                f"{compile_value:.2f}x), bare object_load_ns {value:.6f}x (rounds "
                f"{value:.2f}x, provenance valid={provenance_ok})"
                for rel, value, compile_value, provenance_ok in estimates
            )
            matched = all(f"{compile_value:.2f}" == "0.99" and provenance_ok
                          for _, _, compile_value, provenance_ok in estimates)
            rows.append(Row(
                "RQ1 x86 62-case object-load overhead (paper 0.99x)",
                PASS if matched else PARTIAL,
                f"May14 ReJIT runs restricted to Apr29 62-name set (excludes katran_like); "
                f"status on the paper-matched open+load (compile_ns = object_open_ns + "
                f"object_load_ns, evaluation sec 7.1 'verification and JIT') quantity: "
                f"{detail}; open+load rounds to paper 0.99x={matched}; the bare "
                f"object_load_ns field rounds to 1.00x in both runs; "
                f"population={population_rel}/details/result.json",
            ))
        else:
            rows.append(Row("RQ1 x86 62-case object-load overhead (paper 0.99x)",
                            UNAVAILABLE, "historical Apr29-set matched cases are not 62 in both ReJIT runs"))
    else:
        rows.append(Row("RQ1 x86 62-case object-load overhead (paper 0.99x)",
                        UNAVAILABLE, f"historical ReJIT or population result.json missing: {load_rels}, {population_rel}"))
    return rows


# Fresh x86 paired load-time runs on the current 29-case micro generation. The
# paper's 62-name population is not reproducible (60 of its 62 names are absent
# from the current micro config), so these are their own generation: the row
# status is derived from the run's own open+load ratio (the quantity the paper's
# sec 7.1 sentence describes) against the paper's 0.99x threshold, never
# declared. Both quantities are reported; the bare object_load_ns field is
# also derived. Every run keeps its raw details/result.json. The third entry is
# the paper's own micro protocol (SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000); the
# first two are single-sample runs kept for continuity.
FRESH_LOADTIME_RUNS = (
    ("RQ1 x86 fresh paired object-load overhead (full-x86 policy)",
     "micro/results/x86_kvm_micro_20260924_231824_136293", "full-x86", ""),
    ("RQ1 x86 fresh paired object-load overhead (kop policy)",
     "micro/results/x86_kvm_micro_20260925_002201_525373", "kop", ""),
    ("RQ1 x86 repeated-sample paired object-load overhead (full-x86 policy)",
     "micro/results/x86_kvm_micro_20260926_105108_035832", "full-x86",
     "INNER_REPEAT=100000"),
)


def _paired_sample_count(data: dict, runtime: str) -> int:
    """Fewest per-case samples any case of `runtime` retained."""
    counts = []
    for bench in data.get("benchmarks") or []:
        if not isinstance(bench, dict):
            continue
        for run in bench.get("runs") or []:
            if not isinstance(run, dict) or run.get("runtime") != runtime:
                continue
            counts.append(sum(1 for sample in run.get("samples") or []
                              if isinstance(sample, dict)))
            break
    return min(counts) if counts else 0


def fresh_loadtime_rows(root: Path) -> list[Row]:
    rows: list[Row] = []
    for label, rel, policy, protocol in FRESH_LOADTIME_RUNS:
        data = load_json(root / rel / "details/result.json")
        if not isinstance(data, dict):
            rows.append(Row(label, UNAVAILABLE, f"fresh paired result.json missing: {rel}"))
            continue
        kernel_load = median_object_load_ns(data, "kernel")
        rejit_load = median_object_load_ns(data, "kernel_rejit")
        load_names = sorted(kernel_load.keys() & rejit_load.keys())
        kernel_compile = median_object_compile_ns(data, "kernel")
        rejit_compile = median_object_compile_ns(data, "kernel_rejit")
        names = sorted(load_names & kernel_compile.keys() & rejit_compile.keys())
        if not names:
            rows.append(Row(label, UNAVAILABLE,
                            f"no paired kernel/kernel_rejit object_open_ns+object_load_ns: {rel}"))
            continue
        load_value = math.exp(sum(math.log(rejit_load[n] / kernel_load[n]) for n in names) / len(names))
        value = math.exp(sum(math.log(rejit_compile[n] / kernel_compile[n]) for n in names) / len(names))
        provenance_ok = micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
        matched = f"{value:.2f}" == "0.99" and provenance_ok
        samples = min(_paired_sample_count(data, "kernel"),
                      _paired_sample_count(data, "kernel_rejit"))
        rows.append(Row(
            label,
            PASS if matched else PARTIAL,
            f"geomean kernel_rejit/kernel median open+load (compile_ns = object_open_ns + "
            f"object_load_ns)={value:.6f}x (rounds {value:.2f}x) over {len(names)} paired cases "
            f"({samples} sample{'s' if samples != 1 else ''}/case"
            f"{', ' + protocol if protocol else ''}); "
            f"bare object_load_ns geomean={load_value:.6f}x (rounds {load_value:.2f}x); "
            f"same-policy different-generation ReJIT policy={policy}; "
            f"run metadata/progress valid={provenance_ok}; rounds to paper 0.99x={matched}; "
            f"source={rel}/details/result.json",
        ))
    return rows


# The same two fresh runs also carry a within-run paired kernel/kernel_rejit
# exec_ns series with real applied kop sites, so they support the paper's RQ1
# exec-speedup quantity directly (same definition as the arm64 row): geomean
# stock/candidate median exec_ns over the 27 non-simple cases that applied kop
# sites. The paper's own 27-case population is a different generation, so the
# status only asserts the derivation, not a reproduction of 1.242x.
FRESH_EXEC_RUNS = (
    ("RQ1 x86 fresh paired exec speedup (full-x86 policy)",
     "micro/results/x86_kvm_micro_20260924_231824_136293", "full-x86"),
    ("RQ1 x86 fresh paired exec speedup (kop policy)",
     "micro/results/x86_kvm_micro_20260925_002201_525373", "kop"),
)


def fresh_exec_speedup_rows(root: Path) -> list[Row]:
    rows: list[Row] = []
    for label, rel, policy in FRESH_EXEC_RUNS:
        data = load_json(root / rel / "details/result.json")
        if not isinstance(data, dict):
            rows.append(Row(label, UNAVAILABLE, f"fresh paired result.json missing: {rel}"))
            continue
        stock = median_runtime_ns(data, "kernel")
        rejit = median_runtime_ns(data, "kernel_rejit")
        paper_cases = sorted((stock.keys() & rejit.keys()) - {"simple", "simple_packet"})
        applied = median_kop_applied(data, "kernel_rejit")
        bearing = [n for n in paper_cases if applied.get(n, 0) > 0]
        if len(bearing) != 27:
            rows.append(Row(label, UNAVAILABLE,
                            f"kop-bearing non-simple cases={len(bearing)}, expected 27: {rel}"))
            continue
        value = math.exp(sum(math.log(stock[n] / rejit[n]) for n in bearing) / len(bearing))
        provenance_ok = micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
        rows.append(Row(
            label,
            PASS if provenance_ok else PARTIAL,
            f"median kernel/kernel_rejit exec_ns, geomean={value:.6f}x over "
            f"{len(bearing)} kop-bearing non-simple cases (median applied kop sites > 0); "
            f"same-policy different-generation ReJIT policy={policy}; "
            f"run metadata/progress valid={provenance_ok}; single sample per runtime; "
            f"source={rel}/details/result.json",
        ))
    return rows


# The same two runs carry per-runtime native_code_bytes, so the paper's RQ1
# code-size quantity (geomean candidate/stock over all 29 cases) is derivable
# from them too. Fresh-generation values do not reproduce the paper's 0.772x.
FRESH_CODESIZE_RUNS = (
    ("RQ1 x86 fresh paired code size (full-x86 policy)",
     "micro/results/x86_kvm_micro_20260924_231824_136293", "full-x86"),
    ("RQ1 x86 fresh paired code size (kop policy)",
     "micro/results/x86_kvm_micro_20260925_002201_525373", "kop"),
)


def fresh_codesize_rows(root: Path) -> list[Row]:
    rows: list[Row] = []
    for label, rel, policy in FRESH_CODESIZE_RUNS:
        data = load_json(root / rel / "details/result.json")
        if not isinstance(data, dict):
            rows.append(Row(label, UNAVAILABLE, f"fresh paired result.json missing: {rel}"))
            continue
        stock = median_native_bytes(data, "kernel")
        rejit = median_native_bytes(data, "kernel_rejit")
        names = sorted(stock.keys() & rejit.keys())
        if not names:
            rows.append(Row(label, UNAVAILABLE, f"no paired kernel/kernel_rejit native_code_bytes: {rel}"))
            continue
        value = math.exp(sum(math.log(rejit[n] / stock[n]) for n in names) / len(names))
        provenance_ok = micro_run_provenance_ok(root, rel, "x86_kvm_micro", "x86_64")
        rows.append(Row(
            label,
            PASS if provenance_ok else PARTIAL,
            f"geomean kernel_rejit/kernel median native_code_bytes={value:.6f}x over "
            f"{len(names)} paired cases; same-policy different-generation ReJIT "
            f"policy={policy}; run metadata/progress valid={provenance_ok}; "
            f"source={rel}/details/result.json",
        ))
    return rows

CILIUM_RQ2 = "corpus/results/x86_kvm_corpus_20260604_100557_313063"
CILIUM_RQ4_ON = "corpus/results/x86_kvm_corpus_20260529_033517_489159"
CILIUM_RQ4_OFF = "corpus/results/x86_kvm_corpus_20260529_040554_604387"
# Fresh native-loader Cilium run: the June native-post run retained no shim
# log, so the paper's 113/22 loader counts cannot be recovered. This run
# retains details/shim-logs/cilium__agent.post_rejit.log plus the staged Cilium
# native manifest, so the loader decision counts are derived rather than
# declared. It is a separate fresh generation and never merged with 113/22.
CILIUM_NATIVE_POST_RUN = "corpus/results/x86_kvm_corpus_20260924_164153_955835"
NATIVE_EVIDENCE_DIR = "docs/artifacts/evidence/rq4-cilium-native-loader"
# Fresh isolated reruns of the four RQ3 Cilium single-pass policies. The June
# ladder retained no per-pass loadtime reports, so site counts were declared;
# these runs retain details/loadtime-reports/cilium__agent.jsonl.
CILIUM_SITE_ARMS = (
    ("RQ3 Cilium coverage-max applied sites", "corpus/results/x86_kvm_corpus_20260924_064817_392000", "kop_all_prefetch"),
    ("RQ3 Cilium no-prefetch applied sites", "corpus/results/x86_kvm_corpus_20260924_074900_275227", "kop_all_no_prefetch"),
    ("RQ3 Cilium no-bulk applied sites", "corpus/results/x86_kvm_corpus_20260924_085901_647044", "kop_all_no_bulk_prefetch"),
    ("RQ3 Cilium no-bulk/no-prefetch applied sites", "corpus/results/x86_kvm_corpus_20260924_095500_223221", "kop_all_no_bulk_no_prefetch"),
)
# Fresh rerun of the RQ2 Cilium run's own pass policy (`kop`), retained with
# its report stream so the RQ2 applied-site count is derived rather than
# declared. Note the fresh `kop` policy no longer enables bulk_memory.
CILIUM_RQ2_SITE_RUN = "corpus/results/x86_kvm_corpus_20260924_114427_040291"
# Fresh isolated reruns of the two RQ3 Katran ARM64 policies, retained with
# their report streams so the Katran applied-site counts are derived rather
# than declared. These run under local arm64 QEMU; the June runs used AWS.
KATRAN_SITE_ARMS = (
    ("RQ3 Katran conservative applied sites", "corpus/results/arm64_qemu_corpus_19700101_000011_781867",
     ["kop"]),
    ("RQ3 Katran coverage-max applied sites", "corpus/results/arm64_qemu_corpus_19700101_000011_741370",
     ["rotate", "extract", "endian_fusion", "bulk_memory", "prefetch", "cond_select", "ccmp"]),
)
# Controlled per-pass throughput causality from the May 2026 matched batch
# (`x86_kvm_corpus_20260522_*`). Per app the batch holds one `map_inline`-only
# run and two same-batch no-pass runs (`enabled_passes==[]`, mode=loadtime,
# status=skipped), all single-app `x86_kvm_corpus` with 3 baseline + 3
# post_rejit workload samples and `workload_seconds=60.0`. The no-pass runs are
# the restart-drift null: an optimized through-drift ratio is
# `MI median / control median`, and the two controls' own spread bounds how
# much of the raw ratio is attributable to the pass. These runs retain no
# per-step bytecode, so no site counts are claimed and the paper's June ratios
# are never merged with this generation.
CAUSALITY_WORKLOAD_SECONDS = 60.0
MAP_INLINE_CAUSALITY = (
    ("bcc/set", "corpus/results/x86_kvm_corpus_20260522_042759_209148",
     ("corpus/results/x86_kvm_corpus_20260522_040414_983443",
      "corpus/results/x86_kvm_corpus_20260522_041848_461647"), "bcc__set.json"),
    ("otelcol", "corpus/results/x86_kvm_corpus_20260522_050233_401368",
     ("corpus/results/x86_kvm_corpus_20260522_044521_899895",
      "corpus/results/x86_kvm_corpus_20260522_045359_622598"),
     "otelcol-ebpf-profiler__profiling.json"),
    ("cilium", "corpus/results/x86_kvm_corpus_20260522_054834_450402",
     ("corpus/results/x86_kvm_corpus_20260522_052646_166503",
      "corpus/results/x86_kvm_corpus_20260522_053738_559124"), "cilium__agent.json"),
    ("tetragon", "corpus/results/x86_kvm_corpus_20260522_070721_604229",
     ("corpus/results/x86_kvm_corpus_20260522_064657_150013",
      "corpus/results/x86_kvm_corpus_20260522_065609_372274"), "tetragon__observer.json"),
    ("katran", "corpus/results/x86_kvm_corpus_20260522_074136_764813",
     ("corpus/results/x86_kvm_corpus_20260522_072319_967424",
      "corpus/results/x86_kvm_corpus_20260522_073158_210866"), "katran.json"),
    ("tracee", "corpus/results/x86_kvm_corpus_20260522_081529_738968",
     ("corpus/results/x86_kvm_corpus_20260522_075613_925659",
      "corpus/results/x86_kvm_corpus_20260522_080555_505608"), "tracee__monitor.json"),
)

PPS = re.compile(r"\n\s*(\d+)pps\s+[0-9]+Mb/sec .* errors: (\d+)")


def corpus_app(
    root: Path, run: str, *, run_type: str, app_file: str,
    passes: list[str] | None = None, bpf_stats: bool | None = None,
    allow_suite_error: bool = False, workload_seconds: float = 180.0,
) -> dict | None:
    path = root / run
    metadata = load_json(path / "metadata.json") or {}
    progress = load_json(path / "details/progress.json") or {}
    app = load_json(path / "details/apps" / app_file)
    allowed = {"completed", "error"} if allow_suite_error else {"completed"}
    if (progress.get("status") not in allowed
            or metadata.get("status") not in allowed
            or metadata.get("run_type") != run_type
            or metadata.get("suite") != "corpus"
            or metadata.get("samples") != 3
            or metadata.get("workload_seconds") != workload_seconds
            or (passes is not None and (metadata.get("config") or {}).get("enabled_passes") != passes)
            or (bpf_stats is not None and metadata.get("bpf_stats") is not bpf_stats)
            or not isinstance(app, dict)
            or app.get("status") != "ok"
            or app.get("error")):
        return None
    return app


def cilium_app(
    root: Path, run: str, *, passes: list[str] | None = None,
    bpf_stats: bool | None = None, allow_suite_error: bool = False,
    workload_seconds: float = 180.0,
) -> dict | None:
    return corpus_app(root, run, run_type="x86_kvm_corpus", app_file="cilium__agent.json",
                      passes=passes, bpf_stats=bpf_stats,
                      allow_suite_error=allow_suite_error,
                      workload_seconds=workload_seconds)


def workload_pps(workload: dict) -> float:
    components = sum(workload_pps(c) for c in workload.get("components") or [])
    text = "\n" + (workload.get("stdout") or "") + "\n" + (workload.get("stderr") or "")
    return components + sum(float(match.group(1)) for match in PPS.finditer(text))


def phase_pps(app: dict, phase: str) -> list[float]:
    obj = app.get(phase) or {}
    return [workload_pps(w) for w in obj.get("workloads") or []]


def bpf_ns_per_run(app: dict, phase: str) -> float | None:
    obj = app.get(phase) or {}
    records = [
        record for record in (obj.get("bpf") or {}).values()
        if record.get("run_cnt_delta", 0) >= 100
    ]
    runs = sum(record.get("run_cnt_delta", 0) for record in records)
    elapsed = sum(record.get("run_time_ns_delta", 0) for record in records)
    return elapsed / runs if runs else None

# The May batch's workload stdout carries three different rate shapes, so the
# controlled-causality rows need a wider extractor than `workload_pps` (which
# only reads kernel-pktgen `pps ... errors:` lines and returns 0 for wrk and
# stress-ng). Each workload contributes at most one scalar: its own stdout/
# stderr if it carries a rate, otherwise the first component that does. No
# existing row's `phase_pps` semantics are touched.


WRK_REQUESTS_PER_SEC = re.compile(r"(?m)^\s*Requests/sec:\s+(\S+)")
STRESS_NG_METRC = re.compile(
    r"(?m)^stress-ng:\s+metrc:\s+\[\d+\]\s+\S+\s+"
    r"([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\s+([0-9.]+)\b"
)


def _rate_scalar(stdout: str | None, stderr: str | None) -> float | None:
    """One workload's throughput scalar: pktgen pps, wrk req/s, or bogo-ops."""
    text = "\n" + (stdout or "") + "\n" + (stderr or "")
    packets = sum(float(m.group(1)) for m in PPS.finditer(text))
    if packets:
        return packets
    requests = sum(float(m.group(1)) for m in WRK_REQUESTS_PER_SEC.finditer(text))
    if requests:
        return requests
    bogo = sum(float(m.group(1)) for m in STRESS_NG_METRC.finditer(text))
    return bogo or None


def workload_throughput(workload: dict) -> float | None:
    value = _rate_scalar(workload.get("stdout"), workload.get("stderr"))
    if value is not None:
        return value
    for component in workload.get("components") or []:
        value = _rate_scalar(component.get("stdout"), component.get("stderr"))
        if value is not None:
            return value
    return None


def phase_throughput(app: dict, phase: str) -> list[float | None]:
    obj = app.get(phase) or {}
    return [workload_throughput(w) for w in obj.get("workloads") or []]


def _throughput_ratio(app: dict) -> float | None:
    """Median post/baseline throughput ratio over 3+3 positive samples."""
    baseline = phase_throughput(app, "baseline")
    post = phase_throughput(app, "post_rejit")
    samples = baseline + post
    if len(baseline) != 3 or len(post) != 3:
        return None
    if any(value is None or value <= 0 for value in samples):
        return None
    return statistics.median(post) / statistics.median(baseline)


def loadtime_sites(path: Path) -> tuple[int, dict[str, int]] | None:
    """Sum per-pass sites_applied from a retained shim loadtime report stream.

    Returns None when the stream is absent or unparsable. The count is the same
    quantity docs/tmp/kop_all_force_eval_20260603.py sums over
    details/loadtime-reports/<stem>.jsonl.
    """
    try:
        lines = path.read_text().splitlines()
    except OSError:
        return None
    total = 0
    per_pass: dict[str, int] = {}
    seen = False
    for line in lines:
        if not line.strip():
            continue
        try:
            record = json.loads(line)
        except json.JSONDecodeError:
            return None
        seen = True
        report = record.get("report") or {}
        applied = int(report.get("sites_applied") or 0)
        name = record.get("step") or report.get("pass") or "<none>"
        total += applied
        per_pass[name] = per_pass.get(name, 0) + applied
    return (total, per_pass) if seen else None


def loadtime_sites_by_name(path: Path) -> dict[str, int] | None:
    """Sum per-program sites_applied from a retained shim loadtime report stream.

    The report `prog_name` is truncated to 15 characters by the shim, exactly
    as the `name` field of the application's own `baseline.bpf[*]` records, so
    the two are comparable. The join is still lossy: programs whose 15-char
    prefixes collide, or that the app never reported a counter for, appear as
    an unmatched residual. Returns None on absent/unparsable/empty input.
    """
    if not path.exists():
        return None
    by_name: dict[str, int] = {}
    seen = False
    for line in path.read_text().splitlines():
        if not line.strip():
            continue
        try:
            record = json.loads(line)
        except json.JSONDecodeError:
            return None
        seen = True
        report = record.get("report") or {}
        name = record.get("prog_name") or ""
        by_name[name] = by_name.get(name, 0) + int(report.get("sites_applied") or 0)
    return by_name if seen else None


def runtime_programs(path: Path, phase: str) -> list[dict] | None:
    """Per-program runtime counter records from a retained corpus app payload.

    Returns the `bpf` list under `phase` (`baseline`/`post_rejit`) when present.
    `bpf` may be either a dict keyed by program id or a list; both shapes are
    normalized to a list. None if the app payload or the phase is unusable.
    """
    data = load_json(path)
    if not isinstance(data, dict):
        return None
    bpf = (data.get(phase) or {}).get("bpf")
    if isinstance(bpf, dict):
        return list(bpf.values())
    if isinstance(bpf, list):
        return bpf
    return None


def native_loader_counts(path: Path) -> dict[str, int] | None:
    """Count loader decisions from a retained shim log.

    The shim emits one `BPF_PROG_LOAD type=` marker per intercepted load, and
    for each load it classifies exactly one of `native-loader replaced prog=`,
    `native-loader no manifest match pass-through for prog=`, or
    `native-loader skipped <kind> program`. Loads issued before the loader
    finishes initializing carry no decision line, so
    `loads != replaced + pass_through + skipped` in general; both sides are
    reported so the gap stays visible. Returns None when the log is absent or
    holds no load markers.
    """
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return None
    counts = {"loads": 0, "replaced": 0, "pass_through": 0, "skipped": 0}
    for line in text.splitlines():
        if "BPF_PROG_LOAD type=" in line:
            counts["loads"] += 1
        elif "native-loader replaced prog=" in line:
            counts["replaced"] += 1
        elif "native-loader no manifest match pass-through for prog=" in line:
            counts["pass_through"] += 1
        elif "native-loader skipped " in line and " program" in line:
            counts["skipped"] += 1
    return counts if counts["loads"] else None


def native_manifest_objects(path: Path) -> tuple[int, int] | None:
    """Return (object entries, distinct native objects) from a staged manifest.

    Only the manifest's own `objects` list is counted; the paper's
    `native_files` figure is not reproduced from this tree and is not derived.
    """
    data = load_json(path)
    if not isinstance(data, dict):
        return None
    objects = data.get("objects")
    if not isinstance(objects, list) or not objects:
        return None
    names = {o["native_object"] for o in objects
             if isinstance(o, dict) and o.get("native_object")}
    return len(objects), len(names)


def native_loader_rows(root: Path) -> list[Row]:
    """Derive RQ4 native-loader counts from the fresh retained native-post run.

    The June native-post run kept no shim log, so the paper's 113/22 loader
    split stays declared. This fresh run retains its post-phase shim log and
    the staged Cilium native manifest, so replacement and manifest-object
    counts are derived. They are a new host/toolchain generation and are never
    merged with the paper's 113/22/89.
    """
    rows: list[Row] = []
    log_rel = f"{NATIVE_EVIDENCE_DIR}/details/shim-logs/cilium__agent.post_rejit.log"
    run_ok = corpus_app(root, CILIUM_NATIVE_POST_RUN, run_type="x86_kvm_corpus",
                        app_file="cilium__agent.json", passes=[], bpf_stats=True,
                        workload_seconds=30.0)
    counts = native_loader_counts(root / log_rel)
    receipt = load_json(root / NATIVE_EVIDENCE_DIR / "receipt.json") or {}
    hashes = receipt.get("shim_log_files_sha256")
    log_ok = (
        isinstance(hashes, dict)
        and hashes.get("details/shim-logs/cilium__agent.post_rejit.log")
        == file_sha256(root / log_rel)
    ) if (root / log_rel).is_file() else False
    if run_ok is None or counts is None:
        rows.append(Row(
            "RQ4 native loader counts (113/22/89)", UNAVAILABLE,
            f"fresh native-post run or its post-phase shim log missing: "
            f"{CILIUM_NATIVE_POST_RUN}, {log_rel}"))
    else:
        undecided = (counts["loads"] - counts["replaced"]
                     - counts["pass_through"] - counts["skipped"])
        rows.append(Row(
            f"RQ4 native loader replacements ({counts['replaced']} fresh, {counts['loads']} loads)",
            PASS if counts["replaced"] > 0 and log_ok else PARTIAL,
            f"{log_rel}: {counts['loads']} intercepted loads, {counts['replaced']} replaced, "
            f"{counts['pass_through']} manifest pass-through, {counts['skipped']} feature-probe "
            f"skips, {undecided} loads carrying no decision line, receipt log hash valid={log_ok}; "
            f"the paper's 113/22 loader split remains declared because the June native-post run "
            f"retained no shim log",
        ))
    manifest = native_manifest_objects(root / NATIVE_EVIDENCE_DIR / "manifest.json")
    if manifest is None:
        rows.append(Row(
            "RQ4 Cilium native manifest objects (89)", UNAVAILABLE,
            f"retained staged manifest missing: {NATIVE_EVIDENCE_DIR}/manifest.json"))
    else:
        objects, names = manifest
        rows.append(Row(
            f"RQ4 Cilium native manifest objects ({objects} fresh)",
            PASS if objects == 89 else PARTIAL,
            f"{NATIVE_EVIDENCE_DIR}/manifest.json: {objects} object entries across {names} "
            f"distinct native objects; the paper's 89 stays declared, and the paper's "
            f"native-file count is not reproduced from this tree",
        ))
    return rows


def cilium_claim_rows(root: Path) -> list[Row]:
    """Derive selected RQ2/RQ4 Cilium claims from retained three-sample raw JSON."""
    rows: list[Row] = []
    rq2 = cilium_app(root, CILIUM_RQ2, passes=["kop"], bpf_stats=False)
    baseline = phase_pps(rq2, "baseline") if rq2 else []
    post = phase_pps(rq2, "post_rejit") if rq2 else []
    if len(baseline) == len(post) == 3 and min(baseline + post) > 0:
        ratio = statistics.median(post) / statistics.median(baseline)
        rows.append(Row(
            "RQ2 Cilium x86 throughput (1.074x)",
            PASS if f"{ratio:.3f}" == "1.074" else PARTIAL,
            f"post/baseline median pps={ratio:.6f}x, 3+3 samples; {CILIUM_RQ2}/details/apps/cilium__agent.json",
        ))
    else:
        rows.append(Row("RQ2 Cilium x86 throughput (1.074x)", UNAVAILABLE,
                        f"completed Cilium run with 3+3 positive pps samples missing: {CILIUM_RQ2}"))
    rq2_run = "RQ2 Cilium x86 applied sites (4086)"
    derived_rq2 = loadtime_sites(
        root / CILIUM_RQ2_SITE_RUN / "details/loadtime-reports/cilium__agent.jsonl")
    if derived_rq2 is None:
        rows.append(Row(rq2_run, UNAVAILABLE,
                        "original per-pass loadtime report is not retained; app JSON alone cannot prove site count"))
    else:
        total, per_pass = derived_rq2
        single = per_pass.get("kop") == total and total > 0
        rows.append(Row(
            f"RQ2 Cilium x86 applied sites ({total} fresh)",
            PASS if single else PARTIAL,
            f"the June run's own `kop` policy, rerun in {CILIUM_RQ2_SITE_RUN}: sum of "
            f"report.sites_applied = {total}, {per_pass}; the June 4086 count remains declared because "
            f"its report stream is gone and the fresh `kop` policy no longer enables bulk_memory",
        ))

    on = cilium_app(root, CILIUM_RQ4_ON, bpf_stats=True)
    off = cilium_app(root, CILIUM_RQ4_OFF, bpf_stats=False)
    on_meta = load_json(root / CILIUM_RQ4_ON / "metadata.json") or {}
    off_meta = load_json(root / CILIUM_RQ4_OFF / "metadata.json") or {}
    if (on_meta.get("config") or {}).get("enabled_passes") != (off_meta.get("config") or {}).get("enabled_passes"):
        on = off = None
    off_baseline = phase_pps(off, "baseline") if off else []
    off_post = phase_pps(off, "post_rejit") if off else []
    if len(off_baseline) == len(off_post) == 3 and min(off_baseline + off_post) > 0:
        ratio = statistics.median(off_post) / statistics.median(off_baseline)
        rows.append(Row(
            "RQ4 Cilium native/eBPF throughput (2.358x)",
            PASS if f"{ratio:.3f}" == "2.358" else PARTIAL,
            f"native/eBPF median pps={ratio:.6f}x, 3+3 samples; {CILIUM_RQ4_OFF}/details/apps/cilium__agent.json",
        ))
    else:
        rows.append(Row("RQ4 Cilium native/eBPF throughput (2.358x)", UNAVAILABLE,
                        f"completed Cilium run with 3+3 positive pps samples missing: {CILIUM_RQ4_OFF}"))
    ebpf_ns = bpf_ns_per_run(on, "baseline") if on else None
    native_ns = bpf_ns_per_run(on, "post_rejit") if on else None
    if ebpf_ns is not None and native_ns is not None:
        rows.append(Row(
            "RQ4 Cilium BPF cost (488.7 to 262.3 ns/run)",
            PASS if f"{ebpf_ns:.1f}" == "488.7" and f"{native_ns:.1f}" == "262.3" else PARTIAL,
            f"sum run_time_ns_delta / sum run_cnt_delta for records with >=100 runs: "
            f"{ebpf_ns:.3f} to {native_ns:.3f} ns/run; {CILIUM_RQ4_ON}/details/apps/cilium__agent.json",
        ))
    else:
        rows.append(Row("RQ4 Cilium BPF cost (488.7 to 262.3 ns/run)", UNAVAILABLE,
                        f"retained >=100-run BPF records missing: {CILIUM_RQ4_ON}"))
    rows.extend(native_loader_rows(root))
    for label, run, run_type, app_file, policy, sites, wl_claim, cost_claim in (
        ("RQ3 Cilium coverage-max throughput (1.114x)", "corpus/results/x86_kvm_corpus_20260605_145112_835705",
         "x86_kvm_corpus", "cilium__agent.json", "kop_all_prefetch", 4697, "1.114", "0.776"),
        ("RQ3 Cilium no-prefetch throughput (1.055x)", "corpus/results/x86_kvm_corpus_20260605_141420_746952",
         "x86_kvm_corpus", "cilium__agent.json", "kop_all_no_prefetch", 4086, "1.055", "0.871"),
        ("RQ3 Cilium no-bulk throughput (1.037x)", "corpus/results/x86_kvm_corpus_20260605_164411_317423",
         "x86_kvm_corpus", "cilium__agent.json", "kop_all_no_bulk_prefetch", 4136, "1.037", "0.918"),
        ("RQ3 Cilium no-bulk/no-prefetch throughput (0.999x)", "corpus/results/x86_kvm_corpus_20260605_160715_129437",
         "x86_kvm_corpus", "cilium__agent.json", "kop_all_no_bulk_no_prefetch", 3512, "0.999", "0.991"),
        ("RQ3 Katran conservative throughput (1.073x)", "corpus/results/aws_arm64_corpus_20260605_080836_924256",
         "aws_arm64_corpus", "katran.json", "kop", 21, "1.073", "0.941"),
        ("RQ3 Katran coverage-max throughput (0.995x)", "corpus/results/aws_arm64_corpus_20260605_094729_221231",
         "aws_arm64_corpus", "katran.json", None, 62, "0.995", "1.006"),
    ):
        app = corpus_app(root, run, run_type=run_type, app_file=app_file,
                         passes=[policy] if policy else None, bpf_stats=True,
                         allow_suite_error=True, workload_seconds=30.0)
        baseline = phase_pps(app, "baseline") if app else []
        post = phase_pps(app, "post_rejit") if app else []
        if len(baseline) == len(post) == 3 and min(baseline + post) > 0:
            ratio = statistics.mean(post) / statistics.mean(baseline)
            cost_b = bpf_ns_per_run(app, "baseline")
            cost_p = bpf_ns_per_run(app, "post_rejit")
            cost = cost_p / cost_b if cost_b and cost_p else None
            cost_str = "n/a" if cost is None else f"{cost:.6f}"
            ok = f"{ratio:.3f}" == wl_claim and (cost is None or f"{cost:.3f}" == cost_claim)
            rows.append(Row(label, PASS if ok else PARTIAL,
                            f"post/baseline mean pps={ratio:.6f}x, BPF cost ratio={cost_str}, "
                            f"{sites} sites (declared), 3+3 samples; "
                            f"{run}/details/apps/{app_file}; suite status=error"))
        else:
            rows.append(Row(label, UNAVAILABLE, f"verified samples missing: {run}"))
    rows.extend(cilium_site_rows(root))
    return rows


# Frozen May-batch causality values: per app, the raw `map_inline` median
# throughput ratio and the control-drift-corrected ratio (MI median / median of
# the two no-pass controls). There is no paper-declared single-pass causality
# constant, so these are declared from the matched batch itself and a row is
# PASS only when the derived value reproduces the declared one at the printed
# precision; any drift flips the row to PARTIAL rather than silently
# re-baselining.
MAP_INLINE_CAUSALITY_DECLARED = {
    "bcc/set": ("0.8318", "0.7921"),
    "otelcol": ("0.9984", "0.9983"),
    "cilium": ("0.8885", "0.9585"),
    "tetragon": ("1.0408", "1.0840"),
    "katran": ("1.0191", "1.0345"),
    "tracee": ("0.9243", "1.0114"),
}
MAP_INLINE_CAUSALITY_POOLED = "0.9751"


def map_inline_causality_rows(
    root: Path,
    apps=MAP_INLINE_CAUSALITY,
    declared=MAP_INLINE_CAUSALITY_DECLARED,
    pooled_declared: str = MAP_INLINE_CAUSALITY_POOLED,
) -> list[Row]:
    """Controlled per-pass throughput causality from the May matched batch.

    Each app contributes a raw ratio (its `map_inline` run's median post/
    baseline throughput) and a control-drift-corrected ratio (raw / median of
    the same batch's two no-pass `loadtime` runs). The controls pair an
    optimized and a plain restart of the same app at identical 60 s duration,
    so their spread measures how much of the raw ratio is restart drift rather
    than pass effect. No site counts are claimed: these runs retain no per-step
    bytecode, and the paper's June ratios are a separate generation.

    `apps`/`declared`/`pooled_declared` are injectable so `self_test` can drive
    the identical derivation over synthetic runs.
    """
    rows: list[Row] = []
    controlled: list[float] = []
    for app_label, mi_run, control_runs, app_file in apps:
        mi = corpus_app(root, mi_run, run_type="x86_kvm_corpus", app_file=app_file,
                        passes=["map_inline"], bpf_stats=True,
                        workload_seconds=CAUSALITY_WORKLOAD_SECONDS)
        raw = _throughput_ratio(mi) if mi else None
        control_ratios: list[float] = []
        for control_run in control_runs:
            control = corpus_app(root, control_run, run_type="x86_kvm_corpus",
                                 app_file=app_file, passes=[],
                                 workload_seconds=CAUSALITY_WORKLOAD_SECONDS)
            ratio = _throughput_ratio(control) if control else None
            if ratio is not None:
                control_ratios.append(ratio)
        label = f"map_inline per-pass causality {app_label}"
        if raw is None or not control_ratios:
            rows.append(Row(label, UNAVAILABLE,
                            f"matched map_inline run plus no-pass controls with 3+3 "
                            f"positive throughput samples missing: {mi_run}"))
            continue
        control_median = statistics.median(control_ratios)
        corrected = raw / control_median
        controlled.append(corrected)
        declared_raw, declared_corrected = declared[app_label]
        ok = (f"{raw:.4f}" == declared_raw
              and f"{corrected:.4f}" == declared_corrected)
        rows.append(Row(
            label, PASS if ok else PARTIAL,
            f"map_inline median throughput ratio={raw:.6f}x; no-pass controls "
            f"{['%.4f' % r for r in control_ratios]} (median {control_median:.6f}x); "
            f"control-corrected={corrected:.6f}x, 3+3 samples per run; "
            f"{mi_run}/details/apps/{app_file}",
        ))
    label = "map_inline per-pass causality pooled (6 apps)"
    if len(controlled) == len(apps):
        pooled = math.exp(sum(math.log(x) for x in controlled) / len(controlled))
        rows.append(Row(
            label, PASS if f"{pooled:.4f}" == pooled_declared else PARTIAL,
            f"geomean of per-app control-corrected ratios={pooled:.6f}x over "
            f"{len(controlled)} apps; null drift is the median of the two no-pass "
            f"loadtime controls in each app's matched May batch",
        ))
    else:
        rows.append(Row(label, UNAVAILABLE,
                        f"only {len(controlled)}/{len(apps)} apps produced "
                        f"a controlled ratio"))
    return rows

# Fresh provenance-complete Katran causality triplet: one `map_inline` run with
# two matched no-pass controls, each retaining its own make-console log. Unlike
# the May matched batch (which retains no per-step bytecode and no console
# logs), this dir carries both the rewrite reconciliation and the controlled
# throughput causality, so a single row can bind a measured pass effect to the
# bytecode change that produced it. The declared constants are frozen from this
# triplet; drift flips the row to PARTIAL rather than silently re-baselining.
KATRAN_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-katran-map-inline-fresh-causality"
)
KATRAN_FRESH_CAUSALITY_DECLARED = ("1.0751", "1.0754")


def _summed_pktgen_throughput(workload: dict) -> float | None:
    """One workload's throughput as the sum of its rate-bearing components.

    The fresh kernel-pktgen workload emits four components per phase in
    nondeterministic order, so `workload_throughput` (first rate-bearing
    component) would sample only one of them. Sum every component's scalar;
    fall back to the workload's own stdout/stderr when it carries the rate
    directly (the stress-ng workloads carry no components and emit their
    bogo-ops scalar in the workload-level stdout). `_rate_scalar` already
    accepts all three emitted shapes, so this is the shared extractor for
    every fresh causality triplet. Returns None when no rate is present.
    """
    total = 0.0
    found = False
    for component in workload.get("components") or []:
        value = _rate_scalar(component.get("stdout"), component.get("stderr"))
        if value:
            total += value
            found = True
    if not found:
        value = _rate_scalar(workload.get("stdout"), workload.get("stderr"))
        if value:
            total += value
            found = True
    return total if found else None


def _summed_phase_throughput(app: dict, phase: str) -> list[float | None]:
    obj = app.get(phase) or {}
    return [_summed_pktgen_throughput(w) for w in obj.get("workloads") or []]


def _summed_throughput_ratio(app: dict) -> float | None:
    """Median post/baseline summed rate scalar over 3+3 samples."""
    baseline = _summed_phase_throughput(app, "baseline")
    post = _summed_phase_throughput(app, "post_rejit")
    if len(baseline) != 3 or len(post) != 3:
        return None
    if any(value is None or value <= 0 for value in baseline + post):
        return None
    return statistics.median(post) / statistics.median(baseline)


def fresh_causality_rows(
    root: Path,
    *,
    app_stem: str,
    report_rel: str,
    label: str,
    evidence_dir: str,
    declared: tuple[str, str],
    metric_noun: str = "summed-pktgen",
    pass_name: str = "map_inline",
) -> list[Row]:
    """One app's fresh map_inline causality bound to its retained bytecode.

    One evidence dir carries a single-pass loadtime run (rewrite reconciliation
    plus throughput) and two matched no-pass controls. The row PASSes only when
    the optimized run's status records are completed/ok with `enabled_passes ==
    [pass_name]`, the retained per-step bytecode reconciles with the report
    stream, the receipt binds every retained file, both controls are
    `passes == []` loadtime skips at identical 3-sample/60 s shape, and the
    derived raw and control-corrected ratios reproduce the frozen declared
    constants. Any drift flips the row to PARTIAL.
    """
    base = root / evidence_dir
    meta = load_json(base / "metadata.json") or {}
    progress = load_json(base / "details/progress.json") or {}
    app = load_json(base / "details/apps" / f"{app_stem}.json") or {}
    receipt = load_json(base / "receipt.json") or {}
    run_ok = (
        meta.get("status") == SUITE_SUCCESS
        and meta.get("run_type") in CORPUS_RUN_TYPES
        and meta.get("suite") == "corpus"
        and meta.get("samples") == 3
        and meta.get("workload_seconds") == CAUSALITY_WORKLOAD_SECONDS
        and (meta.get("config") or {}).get("enabled_passes") == [pass_name]
        and progress.get("status") == SUITE_SUCCESS
        and app.get("status") == APP_SUCCESS
        and not app.get("error")
        and (app.get("rejit_result") or {}).get("status") == "ok"
    )
    counts = _retained_changed_bytecode(root, evidence_dir, report_rel)
    reconciled = counts is not None and (
        counts["changed"] > 0
        and counts["retained_changed_workdirs"] == counts["changed"]
        and counts["len_mismatches"] == 0
        and counts["changed_missing_bytecode"] == 0
        and counts["changed_not_differing"] == 0
    )
    files_ok = retained_files_valid(base, receipt.get("files_sha256"))

    control_ratios: list[float] = []
    controls_ok = True
    for control in ("nullA", "nullB"):
        cmeta = load_json(base / "controls" / control / "metadata.json") or {}
        capp = load_json(base / "controls" / control / "details/apps" / f"{app_stem}.json") or {}
        gate_ok = (
            cmeta.get("status") == SUITE_SUCCESS
            and cmeta.get("run_type") in CORPUS_RUN_TYPES
            and cmeta.get("suite") == "corpus"
            and cmeta.get("samples") == 3
            and cmeta.get("workload_seconds") == CAUSALITY_WORKLOAD_SECONDS
            and (cmeta.get("config") or {}).get("enabled_passes") == []
            and capp.get("status") == APP_SUCCESS
            and not capp.get("error")
            and (capp.get("rejit_result") or {}).get("status") == "skipped"
        )
        if not gate_ok:
            controls_ok = False
        ratio = _summed_throughput_ratio(capp)
        if ratio is not None:
            control_ratios.append(ratio)

    raw = _summed_throughput_ratio(app)
    declared_raw, declared_corrected = declared
    if raw is None or len(control_ratios) != 2:
        return [Row(
            label, UNAVAILABLE,
            f"fresh {pass_name} run plus two matched no-pass controls with 3+3 "
            f"positive {metric_noun} samples missing: {evidence_dir}",
        )]
    control_median = statistics.median(control_ratios)
    corrected = raw / control_median
    derived_ok = (
        f"{raw:.4f}" == declared_raw and f"{corrected:.4f}" == declared_corrected
    )
    status = PASS if (
        run_ok and reconciled and files_ok and controls_ok and derived_ok
    ) else PARTIAL
    return [Row(
        f"{label} ({counts['sites_applied']} sites)" if counts else label,
        status,
        f"{evidence_dir}: {pass_name} median {metric_noun} ratio={raw:.6f}x; "
        f"no-pass controls {['%.4f' % r for r in control_ratios]} "
        f"(median {control_median:.6f}x); control-corrected={corrected:.6f}x "
        f"(declared {declared_raw}/{declared_corrected}), 3+3 samples per run; "
        + (f"{counts['rows']} report rows, {counts['changed']} changed load "
           f"instances, {counts['sites_applied']} applied sites, insn "
           f"{counts['insn_before']}->{counts['insn_after']} "
           f"({counts['insn_after'] - counts['insn_before']:+d}); "
           f"bytecode retained for {counts['retained_changed_workdirs']}/"
           f"{counts['changed']} changed workdirs, "
           f"{counts['len_mismatches']} length mismatches, "
           f"{counts['changed_not_differing']} identical images; " if counts
           else "retained report stream missing; ")
        + f"run status valid={run_ok}, controls valid={controls_ok}, "
          f"receipt file hashes valid={files_ok}",
    )]


# Fresh provenance-complete Katran causality triplet: one `map_inline` run with
# two matched no-pass controls, each retaining its own make-console log. Unlike
# the May matched batch (which retains no per-step bytecode and no console
# logs), this dir carries both the rewrite reconciliation and the controlled
# throughput causality, so a single row can bind a measured pass effect to the
# bytecode change that produced it. The declared constants are frozen from this
# triplet; drift flips the row to PARTIAL rather than silently re-baselining.
def katran_fresh_causality_rows(
    root: Path,
    evidence_dir: str = KATRAN_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = KATRAN_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    return fresh_causality_rows(
        root,
        app_stem="katran",
        report_rel="details/loadtime-reports/katran.jsonl",
        label="RQ2 Katran fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
    )

CILIUM_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-cilium-map-inline-fresh-causality"
)
CILIUM_FRESH_CAUSALITY_DECLARED = ("1.0325", "0.9619")


def cilium_fresh_causality_rows(
    root: Path,
    evidence_dir: str = CILIUM_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = CILIUM_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    """Cilium fresh map_inline causality bound to its retained bytecode.

    Same shape as the Katran triplet (see `fresh_causality_rows`). The
    control-corrected sign agrees with the May Cilium batch's `0.9585`, which
    is an independent generation: Cilium's `map_inline` effect is within
    restart drift of neutral here, so the row's claim is the controlled
    measurement, not a speedup.
    """
    return fresh_causality_rows(
        root,
        app_stem="cilium__agent",
        report_rel="details/loadtime-reports/cilium__agent.jsonl",
        label="RQ2 Cilium fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
    )


# Fresh provenance-complete Tetragon causality triplet, same shape as Katran
# and Cilium (see `fresh_causality_rows`). Tetragon's fresh workload is a
# single stress-ng run with no components, so the derived throughput scalar is
# the workload-level `stress-ng: metrc:` bogo-ops column rather than a pktgen
# pps sum; the shared extractor's `_rate_scalar` fallback already covers that
# shape, and `metric_noun` keeps the row's wording accurate. The
# control-corrected sign agrees with the May Tetragon batch's independent
# `1.0840` (both above 1.0), so the effect is positive here too, but the two
# are separate generations and are never merged.
TETRAGON_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-tetragon-map-inline-fresh-causality"
)
TETRAGON_FRESH_CAUSALITY_DECLARED = ("1.0423", "1.0357")


def tetragon_fresh_causality_rows(
    root: Path,
    evidence_dir: str = TETRAGON_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = TETRAGON_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    """Tetragon fresh map_inline causality bound to its retained bytecode."""
    return fresh_causality_rows(
        root,
        app_stem="tetragon__observer",
        report_rel="details/loadtime-reports/tetragon__observer.jsonl",
        label="RQ2 Tetragon fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
        metric_noun="stress-ng metrc bogo-ops",
    )


# Fresh provenance-complete Tracee causality triplet, same shape as Tetragon
# (see `fresh_causality_rows`). Tracee's fresh workload is likewise a single
# stress-ng run with no components, so the derived scalar is the workload-level
# `stress-ng: metrc:` bogo-ops column. The control-corrected sign agrees with
# the May Tracee batch's independent `1.0114` (both above 1.0), but the two are
# separate generations and are never merged.
TRACEE_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-tracee-map-inline-fresh-causality"
)
TRACEE_FRESH_CAUSALITY_DECLARED = ("1.0110", "1.0152")


def tracee_fresh_causality_rows(
    root: Path,
    evidence_dir: str = TRACEE_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = TRACEE_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    """Tracee fresh map_inline causality bound to its retained bytecode."""
    return fresh_causality_rows(
        root,
        app_stem="tracee__monitor",
        report_rel="details/loadtime-reports/tracee__monitor.jsonl",
        label="RQ2 Tracee fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
        metric_noun="stress-ng metrc bogo-ops",
    )


# Fresh provenance-complete BCC causality triplet, the third on the
# component-less stress-ng shape (see `fresh_causality_rows`). BCC's fresh
# workload is a single stress-ng run with no components, so the derived scalar
# is the workload-level `stress-ng: metrc:` bogo-ops column. The May BCC batch
# reports an independent corrected `0.7921`; the two are separate generations
# and are never merged.
BCC_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-bcc-map-inline-fresh-causality"
)
BCC_FRESH_CAUSALITY_DECLARED = ("1.0107", "1.0075")


def bcc_fresh_causality_rows(
    root: Path,
    evidence_dir: str = BCC_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = BCC_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    """BCC fresh map_inline causality bound to its retained bytecode."""
    return fresh_causality_rows(
        root,
        app_stem="bcc__set",
        report_rel="details/loadtime-reports/bcc__set.jsonl",
        label="RQ2 BCC fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
        metric_noun="stress-ng metrc bogo-ops",
    )


# Fresh provenance-complete otelcol-ebpf-profiler causality triplet, the
# sixth and last app on the same stress-ng shape (see
# `fresh_causality_rows`). Unlike BCC/Tetragon/Tracee, otelcol's workload is
# composite: five interpreter sha256 workers plus one stress-ng cpu component.
# Only the stress-ng component carries a rate the shared extractor recognizes
# (its `stress-ng: metrc:` bogo-ops column); the interpreters' own
# `<lang> sha256 ops=N elapsed_s=T` stdout matches no shape, so the summed
# extractor's per-component sum yields the same metrc scalar the May batch
# derived. `metric_noun` names that shape. The May otelcol batch reports an
# independent corrected `0.9983`; the two are separate generations and are
# never merged.
OTELCOL_FRESH_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-otelcol-map-inline-fresh-causality"
)
OTELCOL_FRESH_CAUSALITY_DECLARED = ("1.0188", "1.0798")


def otelcol_fresh_causality_rows(
    root: Path,
    evidence_dir: str = OTELCOL_FRESH_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = OTELCOL_FRESH_CAUSALITY_DECLARED,
) -> list[Row]:
    """otelcol fresh map_inline causality bound to its retained bytecode."""
    return fresh_causality_rows(
        root,
        app_stem="otelcol-ebpf-profiler__profiling",
        report_rel="details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl",
        label="RQ2 otelcol fresh map_inline causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
        metric_noun="stress-ng metrc bogo-ops",
    )


# Fresh provenance-complete Tetragon `wide_mem` causality triplet, the first
# non-`map_inline` pass to get one. Same triplet shape and same evidence dir
# contract as the `map_inline` triplets (see `fresh_causality_rows`); only
# `pass_name` differs, so the single-pass prefilter, the report reconciliation
# and the control-corrected ratio all apply unchanged. Tetragon is the densest
# retained `wide_mem` producer of the six apps (616 applied sites over its
# retained report stream vs. 299 for Tracee and 65 for BCC), so a controlled
# measurement there has the most sites behind it. The workload is the same
# component-less stress-ng shape as the Tetragon `map_inline` triplet, so the
# derived scalar is the workload-level `stress-ng: metrc:` bogo-ops column.
WIDE_MEM_TETRAGON_CAUSALITY_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-tetragon-wide-mem-fresh-causality"
)
WIDE_MEM_TETRAGON_CAUSALITY_DECLARED = ("1.0", "1.0")


def wide_mem_tetragon_causality_rows(
    root: Path,
    evidence_dir: str = WIDE_MEM_TETRAGON_CAUSALITY_EVIDENCE_DIR,
    declared: tuple[str, str] = WIDE_MEM_TETRAGON_CAUSALITY_DECLARED,
) -> list[Row]:
    """Tetragon fresh wide_mem causality bound to its retained bytecode."""
    return fresh_causality_rows(
        root,
        app_stem="tetragon__observer",
        report_rel="details/loadtime-reports/tetragon__observer.jsonl",
        label="RQ2 Tetragon fresh wide_mem causality + retained bytecode",
        evidence_dir=evidence_dir,
        declared=declared,
        metric_noun="stress-ng metrc bogo-ops",
        pass_name="wide_mem",
    )


def cilium_site_rows(root: Path) -> list[Row]:
    """Derive RQ3 applied-site counts from retained shim loadtime reports.

    The June throughput ladder retained no per-pass reports, so these are fresh
    isolated runs of the identical single-pass policies; the derived count is
    the sum of report.sites_applied over details/loadtime-reports/<stem>.jsonl.
    """
    rows: list[Row] = []
    for label, run, policy in CILIUM_SITE_ARMS:
        path = root / run / "details/loadtime-reports/cilium__agent.jsonl"
        derived = loadtime_sites(path)
        app = corpus_app(root, run, run_type="x86_kvm_corpus", app_file="cilium__agent.json",
                         passes=[policy], bpf_stats=True, workload_seconds=30.0)
        baseline = phase_pps(app, "baseline") if app else []
        post = phase_pps(app, "post_rejit") if app else []
        ratio = statistics.mean(post) / statistics.mean(baseline) if len(baseline) == len(post) == 3 and min(baseline + post) > 0 else None
        cost_b = bpf_ns_per_run(app, "baseline") if app else None
        cost_p = bpf_ns_per_run(app, "post_rejit") if app else None
        cost = cost_p / cost_b if cost_b and cost_p else None
        if derived is None:
            rows.append(Row(label, UNAVAILABLE,
                            f"retained loadtime report missing: {run}/details/loadtime-reports/cilium__agent.jsonl"))
            continue
        total, per_pass = derived
        single = per_pass.get(policy) == total and total > 0
        ok = single and ratio is not None
        rows.append(Row(
            f"{label} ({total} sites, {ratio:.3f}x)" if ratio is not None
            else f"{label} ({total} sites)",
            PASS if ok else PARTIAL,
            f"sum of report.sites_applied over {run}/details/loadtime-reports/cilium__agent.jsonl "
            f"= {total} across {len(per_pass)} step(s) {per_pass}; fresh {policy} run: "
            + (f"post/baseline mean pps={ratio:.6f}x, BPF cost ratio={cost:.6f}" if cost is not None
               else "workload ratio unavailable")
            + f"; {run}/details/apps/cilium__agent.json",
        ))
    rows.append(corpus_divergence_row(root))
    rows.extend(katran_site_rows(root))
    return rows


def katran_site_rows(root: Path) -> list[Row]:
    """Derive RQ3 Katran ARM64 applied-site counts from fresh shim reports.

    The June ARM64 runs retained no per-pass reports, so these are fresh
    isolated local-QEMU reruns of the identical policies; the derived count is
    the sum of report.sites_applied over details/loadtime-reports/katran.jsonl.
    The policy is matched per step (the coverage-max list has one step per
    family), so the total spans several steps and is reported as PARTIAL.
    """
    rows: list[Row] = []
    for label, run, passes in KATRAN_SITE_ARMS:
        path = root / run / "details/loadtime-reports/katran.jsonl"
        derived = loadtime_sites(path)
        app = corpus_app(root, run, run_type="arm64_qemu_corpus", app_file="katran.json",
                         passes=passes, bpf_stats=True, workload_seconds=30.0)
        baseline = phase_pps(app, "baseline") if app else []
        post = phase_pps(app, "post_rejit") if app else []
        ratio = statistics.mean(post) / statistics.mean(baseline) if len(baseline) == len(post) == 3 and min(baseline + post) > 0 else None
        cost_b = bpf_ns_per_run(app, "baseline") if app else None
        cost_p = bpf_ns_per_run(app, "post_rejit") if app else None
        cost = cost_p / cost_b if cost_b and cost_p else None
        if derived is None:
            rows.append(Row(label, UNAVAILABLE,
                            f"retained loadtime report missing: {run}/details/loadtime-reports/katran.jsonl"))
            continue
        total, per_pass = derived
        rows.append(Row(
            f"{label} ({total} sites, {ratio:.3f}x)" if ratio is not None
            else f"{label} ({total} sites)",
            PASS if ratio is not None else PARTIAL,
            f"sum of report.sites_applied over {run}/details/loadtime-reports/katran.jsonl "
            f"= {total} across {len(per_pass)} step(s) {per_pass}; fresh local-QEMU run: "
            + (f"post/baseline mean pps={ratio:.6f}x, BPF cost ratio={cost:.6f}" if cost is not None
               else "workload ratio unavailable")
            + f"; {run}/details/apps/katran.json",
        ))
    return rows


# The Cilium report arms, each retaining both a shim loadtime report stream and
# the application's own per-program runtime counters. Sites applied to a
# tail-called program are billed at its directly attached caller, whose
# run_time_ns_delta already includes the descendant's cost (the tail call jumps
# inline and control does not return), so the split below is the qualified
# population's attribution, not a claim about self-applied sites.
CILIUM_ATTRIBUTION_ARMS = CILIUM_SITE_ARMS + (
    ("RQ2 Cilium x86 kop applied sites", CILIUM_RQ2_SITE_RUN, "kop"),
)


def cilium_attribution_rows(root: Path) -> list[Row]:
    """Attribute Cilium applied sites to callers versus tail-call descendants.

    Joins each arm's `report.prog_name` site counts against the application's
    own `baseline.bpf[*]` runtime counters by 15-char truncated name. Programs
    the app reported no counter for (or whose prefix collides) remain as an
    unmatched residual, so the split is reported alongside that residual and
    is never presented as total. Status asserts only that both streams parsed
    and the sites reconcile into directly-attached / zero-self / unmatched.
    """
    rows: list[Row] = []
    for label, run, policy in CILIUM_ATTRIBUTION_ARMS:
        rel = run.removeprefix("corpus/results/")
        report_path = root / run / "details/loadtime-reports/cilium__agent.jsonl"
        app_path = root / run / "details/apps/cilium__agent.json"
        sites = loadtime_sites_by_name(report_path)
        progs = runtime_programs(app_path, "baseline")
        if sites is None or progs is None:
            rows.append(Row(
                f"{label} attribution",
                UNAVAILABLE,
                f"retained report and/or app counters missing or unparsable: "
                f"{rel}/details/loadtime-reports/cilium__agent.jsonl, "
                f"{rel}/details/apps/cilium__agent.json",
            ))
            continue
        run_cnt: dict[str, int] = {}
        run_time: dict[str, int] = {}
        for prog in progs:
            name = prog.get("name") or ""
            run_cnt[name] = run_cnt.get(name, 0) + int(prog.get("run_cnt_delta") or 0)
            run_time[name] = run_time.get(name, 0) + int(prog.get("run_time_ns_delta") or 0)
        total = sum(sites.values())
        bearing = {n: s for n, s in sites.items() if s > 0}
        direct = sum(s for n, s in bearing.items() if run_cnt.get(n, 0) > 0)
        zero_self = sum(s for n, s in bearing.items() if n in run_cnt and run_cnt[n] == 0)
        unmatched = total - direct - zero_self
        direct_names = sorted(n for n in bearing if run_cnt.get(n, 0) > 0)
        zero_names = sorted(n for n in bearing if n in run_cnt and run_cnt[n] == 0)
        unmatched_names = sorted(n for n in bearing if n not in run_cnt)
        direct_runtime = sum(run_time.get(n, 0) for n in direct_names)
        reconciled = direct + zero_self + unmatched == total and total > 0
        rows.append(Row(
            f"{label} attribution (caller vs tail descendant)",
            PASS if reconciled else PARTIAL,
            f"sum of report.prog_name sites_applied over {rel}/details/loadtime-reports/"
            f"cilium__agent.jsonl = {total}; joined to baseline.bpf[*] runtime counters in "
            f"{rel}/details/apps/cilium__agent.json by 15-char name: directly attached "
            f"(run_cnt_delta>0) = {direct} sites on {len(direct_names)} programs {direct_names}, "
            f"zero-self (tail targets) = {zero_self} sites on {len(zero_names)} programs "
            f"{zero_names}, name-join residual = {unmatched} sites on {len(unmatched_names)} "
            f"names {unmatched_names}; callers' summed baseline run_time_ns_delta="
            f"{direct_runtime} already includes every tail descendant's cost "
            f"(policy={policy}); sites reconcile={reconciled}",
        ))
    return rows


# Fresh single-pass `map_inline` run for Cilium that retains, for every changed
# load instance, the per-step input AND output bytecode plus the optimizer
# report. The older RQ2 artifacts kept neither retained outputs nor before
# images, so their rewrite and throughput claims could not be re-derived; this
# run's raw before/after instruction counts and applied-site totals are derived
# from the retained streams instead of declared. It is a separate single-startup
# generation and is never merged with the paper's declared 4086 figure.
MAP_INLINE_EVIDENCE_DIR = "docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode"
# Katran arm64 retained-bytecode evidence dir (same overlay/hint policy path,
# local arm64 QEMU executor).
KATRAN_ARM64_MAP_INLINE_EVIDENCE_DIR = (
    "docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode"
)
KATRAN_MAP_INLINE_EVIDENCE_DIR = "docs/artifacts/evidence/rq2-katran-map-inline-retained-bytecode"
TRACEE_MAP_INLINE_EVIDENCE_DIR = "docs/artifacts/evidence/rq2-tracee-map-inline-retained-bytecode"
# Tetragon retained-bytecode evidence dir (default map_inline policy, six maps).
TETRAGON_MAP_INLINE_EVIDENCE_DIR = "docs/artifacts/evidence/rq2-tetragon-map-inline-retained-bytecode"


def _retained_changed_bytecode(
    root: Path,
    evidence_dir: str = MAP_INLINE_EVIDENCE_DIR,
    report_rel: str = "details/loadtime-reports/cilium__agent.jsonl",
) -> dict[str, int] | None:
    """Reconcile retained per-step bytecode with the report stream.

    Reads `details/loadtime-reports/cilium__agent.jsonl` and, for every changed
    workdir it names, the retained `input.step.0.bin` / `output.next.0.bin` and
    `report.0.json`. Returns None when either stream is absent or unparsable;
    otherwise the counts below, where a mismatch between a bin's raw
    `struct bpf_insn` length (8 bytes each) and the report's instruction count
    is counted in `len_mismatches`, and a changed workdir whose before/after
    bytecode is byte-identical is counted in `changed_not_differing`.
    """
    base = root / evidence_dir
    report = base / report_rel
    if not report.is_file():
        return None
    try:
        rows = [json.loads(line) for line in report.read_text().splitlines() if line.strip()]
    except Exception:
        return None
    if not rows:
        return None
    out = {
        "rows": len(rows), "changed": 0, "sites_applied": 0,
        "insn_before": 0, "insn_after": 0,
        "retained_changed_workdirs": 0, "changed_missing_bytecode": 0,
        "len_mismatches": 0, "changed_not_differing": 0,
    }
    for row in rows:
        rep = row.get("report")
        if not isinstance(rep, dict):
            return None
        before = int(rep.get("insn_count_before") or 0)
        after = int(rep.get("insn_count_after") or 0)
        applied = int(rep.get("sites_applied") or 0)
        out["insn_before"] += before
        out["insn_after"] += after
        out["sites_applied"] += applied
        if applied <= 0:
            continue
        out["changed"] += 1
        name = Path(row.get("workdir") or "").name
        wd = base / "details/loadtime-workdirs" / name
        inp, outp, rp = wd / "input.step.0.bin", wd / "output.next.0.bin", wd / "report.0.json"
        if not (inp.is_file() and outp.is_file() and rp.is_file()):
            out["changed_missing_bytecode"] += 1
            continue
        out["retained_changed_workdirs"] += 1
        if inp.stat().st_size != 8 * before or outp.stat().st_size != 8 * after:
            out["len_mismatches"] += 1
        if inp.read_bytes() == outp.read_bytes():
            out["changed_not_differing"] += 1
    return out


def _retained_bytecode_app_row(
    root: Path,
    evidence_dir: str,
    report_rel: str,
    label: str,
    unavailable_label: str,
    declared_note: str,
) -> list[Row]:
    """Derive RQ2 rewrite evidence from one app's retained per-step bytecode.

    Asserts only what the retained streams prove: for every changed load
    instance the report stream names, the retained input/output bytecode agree
    with the reported before/after instruction counts AND the two bytecode
    images differ. Status is PASS when the run's own status records are
    completed/ok, both streams reconcile with no mismatch, and the receipt
    binds the retained files; otherwise PARTIAL. `declared_note` is a format
    string with a `{sites}` field naming what stays declared.
    """
    base = root / evidence_dir
    counts = _retained_changed_bytecode(root, evidence_dir, report_rel)
    stem = Path(report_rel).stem
    meta = load_json(base / "metadata.json") or {}
    progress = load_json(base / "details/progress.json") or {}
    app = load_json(base / "details/apps" / f"{stem}.json") or {}
    receipt = load_json(base / "receipt.json") or {}
    run_ok = (
        meta.get("status") == SUITE_SUCCESS
        and meta.get("run_type") in CORPUS_RUN_TYPES
        and meta.get("suite") == "corpus"
        and progress.get("status") == SUITE_SUCCESS
        and app.get("status") == APP_SUCCESS
        and not app.get("error")
    )
    hashes = receipt.get("files_sha256")
    files_ok = retained_files_valid(base, hashes)
    if counts is None:
        return [Row(
            unavailable_label,
            UNAVAILABLE,
            f"retained report stream or per-step bytecode missing: "
            f"{evidence_dir}/{report_rel}",
        )]
    reconciled = (
        counts["changed"] > 0
        and counts["retained_changed_workdirs"] == counts["changed"]
        and counts["len_mismatches"] == 0
        and counts["changed_missing_bytecode"] == 0
        and counts["changed_not_differing"] == 0
    )
    status = PASS if (run_ok and reconciled and files_ok) else PARTIAL
    return [Row(
        f"RQ2 {label} retained map_inline bytecode ({counts['sites_applied']} sites)",
        status,
        f"{evidence_dir}/{report_rel}: "
        f"{counts['rows']} report rows, {counts['changed']} changed load instances, "
        f"{counts['sites_applied']} applied sites, insn {counts['insn_before']}->"
        f"{counts['insn_after']} ({counts['insn_after'] - counts['insn_before']:+d}); "
        f"per-step bytecode retained for {counts['retained_changed_workdirs']}/{counts['changed']} "
        f"changed workdirs with {counts['len_mismatches']} length mismatches and "
        f"{counts['changed_not_differing']} identical before/after images; "
        f"run status valid={run_ok}, receipt file hashes valid={files_ok}; "
        + declared_note.format(sites=counts["sites_applied"]),
    )]


def cilium_retained_bytecode_rows(root: Path) -> list[Row]:
    """RQ2 Cilium rewrite evidence (`.rodata.config` policy path)."""
    return _retained_bytecode_app_row(
        root,
        MAP_INLINE_EVIDENCE_DIR,
        "details/loadtime-reports/cilium__agent.jsonl",
        "Cilium",
        "RQ2 Cilium retained map_inline bytecode (4086 sites)",
        "the paper's 4086 remains declared and is not merged with the fresh {sites}",
    )


def katran_retained_bytecode_rows(root: Path) -> list[Row]:
    """RQ2 Katran rewrite evidence (overlay/hint policy path).

    The pre/post workload counters are reported only as raw `apps/katran.json`
    values elsewhere, not as a framework metric.
    """
    return _retained_bytecode_app_row(
        root,
        KATRAN_MAP_INLINE_EVIDENCE_DIR,
        "details/loadtime-reports/katran.jsonl",
        "Katran",
        "RQ2 Katran retained map_inline bytecode",
        "the paper's declared Katran site figures remain declared and are not "
        "merged with the fresh {sites}",
    )


def tracee_retained_bytecode_rows(root: Path) -> list[Row]:
    """RQ2 Tracee rewrite evidence (default `--map-values`/`--map-ids` policy).

    Tracee's run inlines two global config arrays across kprobe, raw_tracepoint
    and cgroup_skb program types; its workload is stress-ng rather than a
    packet generator, so no packet counters are involved.
    """
    return _retained_bytecode_app_row(
        root,
        TRACEE_MAP_INLINE_EVIDENCE_DIR,
        "details/loadtime-reports/tracee__monitor.jsonl",
        "Tracee",
        "RQ2 Tracee retained map_inline bytecode",
        "the paper's declared Tracee site figures remain declared and are not "
        "merged with the fresh {sites}",
    )


def tetragon_retained_bytecode_rows(root: Path) -> list[Row]:
    """RQ2 Tetragon rewrite evidence (default `--map-values`/`--map-ids` policy).

    Tetragon's run inlines six array maps (`tg_conf_map`, `policy_conf`,
    `policy_stats`, `cgroup_rate_opt`, `.rodata`, `config_map`) across kprobe,
    tracepoint, raw_tracepoint and socket_filter programs, including programs
    with two and three applied sites; its workload is stress-ng rather than a
    packet generator.
    """
    return _retained_bytecode_app_row(
        root,
        TETRAGON_MAP_INLINE_EVIDENCE_DIR,
        "details/loadtime-reports/tetragon__observer.jsonl",
        "Tetragon",
        "RQ2 Tetragon retained map_inline bytecode",
        "the paper's declared Tetragon site figures remain declared and are not "
        "merged with the fresh {sites}",
    )


def katran_arm64_retained_bytecode_rows(root: Path) -> list[Row]:
    """RQ2 Katran arm64 rewrite evidence (overlay/hint policy path).

    Same overlay/hint `map_inline` policy as the x86 Katran row, executed by
    the local arm64 QEMU corpus executor; the reconciled bytecode is raw
    `struct bpf_insn[]` (8 bytes per insn on both architectures).
    """
    return _retained_bytecode_app_row(
        root,
        KATRAN_ARM64_MAP_INLINE_EVIDENCE_DIR,
        "details/loadtime-reports/katran.jsonl",
        "Katran arm64",
        "RQ2 Katran arm64 retained map_inline bytecode",
        "the paper's declared Katran site figures remain declared and are not "
        "merged with the fresh arm64 {sites}",
    )


# Fresh ladder run dirs keyed by the same arm labels as CILIUM_JUNE_ARMS.
CILIUM_SITE_ARMS_ORDERED = tuple(
    (label.split("applied sites")[0].replace("RQ3 Cilium ", "").strip(), run, policy)
    for label, run, policy in CILIUM_SITE_ARMS
)

# June ladder run dirs by arm label, in the paper's coverage-narrowing order.
CILIUM_JUNE_ARMS = (
    ("coverage-max", "corpus/results/x86_kvm_corpus_20260605_145112_835705", "kop_all_prefetch"),
    ("no-prefetch", "corpus/results/x86_kvm_corpus_20260605_141420_746952", "kop_all_no_prefetch"),
    ("no-bulk", "corpus/results/x86_kvm_corpus_20260605_164411_317423", "kop_all_no_bulk_prefetch"),
    ("no-bulk/no-prefetch", "corpus/results/x86_kvm_corpus_20260605_160715_129437", "kop_all_no_bulk_no_prefetch"),
)


def _arm_ratio(root: Path, run: str, policy: str, allow_suite_error: bool) -> float | None:
    app = corpus_app(root, run, run_type="x86_kvm_corpus", app_file="cilium__agent.json",
                     passes=[policy], bpf_stats=True,
                     allow_suite_error=allow_suite_error, workload_seconds=30.0)
    baseline = phase_pps(app, "baseline") if app else []
    post = phase_pps(app, "post_rejit") if app else []
    if len(baseline) == len(post) == 3 and min(baseline + post) > 0:
        return statistics.mean(post) / statistics.mean(baseline)
    return None


def corpus_divergence_row(root: Path) -> Row:
    """Derive the June-vs-fresh RQ3 ladder ordering from retained raw JSON only.

    The fresh reruns are a different host/toolchain generation, so their site
    counts and throughput ordering need not reproduce the June ladder; this row
    derives both orderings and reports whether they agree.
    """
    fresh = {label: _arm_ratio(root, run, policy, allow_suite_error=False)
             for label, run, policy in CILIUM_SITE_ARMS_ORDERED}
    june = {label: _arm_ratio(root, run, policy, allow_suite_error=True)
            for label, run, policy in CILIUM_JUNE_ARMS}
    if any(v is None for v in fresh.values()) or any(v is None for v in june.values()):
        return Row("RQ3 Cilium June-vs-fresh ladder ordering", UNAVAILABLE,
                   "retained three-sample ratio missing for at least one ladder arm")
    fresh_order = [l for l, _ in sorted(fresh.items(), key=lambda kv: -kv[1])]
    june_order = [l for l, _ in sorted(june.items(), key=lambda kv: -kv[1])]
    agree = fresh_order == june_order
    return Row(
        "RQ3 Cilium June-vs-fresh ladder ordering" + ("" if agree else " (diverges)"),
        PASS if agree else PARTIAL,
        f"throughput-descending order by post/baseline mean pps, derived from retained app JSON: "
        f"June={june_order} " + "{" + ", ".join(f"{l}={june[l]:.4f}" for l in june_order) + "}; "
        f"fresh={fresh_order} " + "{" + ", ".join(f"{l}={fresh[l]:.4f}" for l in fresh_order) + "}",
    )


def file_sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def retained_files_valid(root: Path, hashes) -> bool | None:
    if not isinstance(hashes, dict) or not hashes:
        return None
    for rel, expected in hashes.items():
        candidate = Path(rel)
        if candidate.is_absolute() or ".." in candidate.parts:
            return False
        path = root / candidate
        if not path.is_file() or file_sha256(path) != expected:
            return False
    return True


def corpus_evidence(
    root: Path,
    rel: str,
    *,
    expected_apps: int,
    claim_label: str,
    required_command: str | None = None,
) -> list[Row]:
    d = root / rel
    claims = [
        f"KVM corpus: rejit/KOperation coverage ({claim_label})",
        f"KVM corpus: full workload success ({claim_label})",
    ]
    if not d.is_dir():
        command = required_command or (
            "BPFREJIT_CORPUS_APPS=katran SAMPLES=1 "
            "WORKLOAD_DURATION=10 TIMEOUT=3000 make corpus"
        )
        return [
            Row(claims[0], UNAVAILABLE, f"{rel} not present; run command: {command}"),
            Row(claims[1], UNAVAILABLE, f"{rel} not present"),
        ]

    suite_status = (load_json(d / "details" / "progress.json") or {}).get("status")
    apps: dict[str, tuple] = {}
    apps_dir = d / "details" / "apps"
    if apps_dir.is_dir():
        for f in sorted(apps_dir.glob("*.json")):
            a = load_json(f) or {}
            apps[f.stem] = (
                a.get("status"),
                (a.get("rejit_result") or {}).get("status"),
            )

    receipt_ok = True
    receipt_detail = ""
    receipt = load_json(d / "receipt.json")
    retained_ok = retained_files_valid(
        d, receipt.get("files_sha256") if isinstance(receipt, dict) else None
    )
    if retained_ok is not None:
        receipt_ok = retained_ok
        receipt_detail = f", retained hashes valid={retained_ok}"
    if required_command is not None:
        receipt = receipt or {}
        log_rel = receipt.get("log_file")
        log_path = d / log_rel if isinstance(log_rel, str) else None
        source_commit = receipt.get("source_commit")
        command_receipt_ok = (
            receipt.get("command") == required_command
            and receipt.get("exit_code") == 0
            and isinstance(source_commit, str)
            and len(source_commit) == 40
            and log_path is not None
            and log_path.is_file()
            and receipt.get("log_sha256") == file_sha256(log_path)
        )
        receipt_ok = receipt_ok and command_receipt_ok
        receipt_detail += f", command receipt valid={command_receipt_ok}"

    n = len(apps)
    rejit_ok = sum(1 for v in apps.values() if v[1] == REJIT_SUCCESS)
    apps_ok = sum(1 for v in apps.values() if v[0] == APP_SUCCESS)
    complete_set = n == expected_apps
    coverage_pass = complete_set and rejit_ok == n and receipt_ok
    workload_pass = (
        suite_status == SUITE_SUCCESS
        and complete_set
        and apps_ok == n
        and receipt_ok
    )
    cov = PASS if coverage_pass else (PARTIAL if apps else UNAVAILABLE)
    succ = PASS if workload_pass else (PARTIAL if apps else UNAVAILABLE)

    return [
        Row(
            claims[0],
            cov,
            f"{rel}: suite status={suite_status!r}, rejit ok={rejit_ok}/{n}, "
            f"expected apps={expected_apps}{receipt_detail}",
        ),
        Row(
            claims[1],
            succ,
            f"{rel}: suite status={suite_status!r}, apps ok={apps_ok}/{n}, "
            f"expected apps={expected_apps}{receipt_detail}"
            + ("" if succ == PASS else " (not a complete successful run)"),
        ),
    ]

def formal_log_counts(path: Path) -> dict[str, int] | None:
    """Count the check classes a retained `make -C native-sim/formal check` log ran.

    Each generator is invoked as `python3 generate_*_spec.py --check`, each
    refinement module as `lake env lean KProgFormal/<Module>.lean`, and each C
    host cross-check as `./build/test_*_host`, which prints
    `<label> host cross-check: OK (<N> cases)`. Returns None when the log is
    absent or ran none of them.
    """
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return None
    counts = {"generator_scripts": 0, "lean_module_commands": 0,
              "host_cross_checks": 0, "host_cross_check_cases": 0}
    for line in text.splitlines():
        stripped = line.strip()
        if stripped.endswith("--check"):
            counts["generator_scripts"] += 1
        elif "lake env lean " in stripped:
            counts["lean_module_commands"] += 1
        elif stripped.startswith("./build/test_"):
            counts["host_cross_checks"] += 1
        match = FORMAL_CASES.search(line)
        if match:
            counts["host_cross_check_cases"] += int(match.group(1))
    return counts if any(counts.values()) else None


def formal_makefile_counts(path: Path) -> dict[str, int] | None:
    """Count the check commands the formal Makefile at this commit enumerates.

    The Makefile is the authority on what `make -C native-sim/formal check`
    must run, so disagreement between it and a retained log means the log
    predates the current proof tree.
    """
    counts = formal_log_counts(path)
    if counts is None:
        return None
    return {k: v for k, v in counts.items() if k != "host_cross_check_cases"}


def formal_log_header(path: Path) -> tuple[str | None, int | None]:
    """Return the `commit=` and `exit=` values the retained log records."""
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return None, None
    commit = FORMAL_LOG_COMMIT.search(text)
    exit_code = FORMAL_LOG_EXIT.search(text)
    return (commit.group(1) if commit else None,
            int(exit_code.group(1)) if exit_code else None)


FORMAL_COUNT_KEYS = ("generator_scripts", "lean_module_commands", "host_cross_checks")


def formal_evidence(root: Path) -> tuple[str, str]:
    """Validate the retained formal-check receipt against its log and the tree.

    The receipt is the machine record, but it is only evidence for the checks
    the current tree enumerates: the retained log supplies the counts, the
    receipt must match them, and the formal Makefile at this commit must
    enumerate the same totals. A receipt left behind by an older proof tree
    therefore degrades to PARTIAL instead of silently passing.
    """
    receipt_path = root / FORMAL_RECEIPT
    data = load_json(receipt_path)
    if not isinstance(data, dict):
        return UNAVAILABLE, f"{FORMAL_RECEIPT} missing or unparsable"
    checks = data.get("checks") or {}
    log_block = data.get("log") or {}
    log_rel = log_block.get("path") or FORMAL_LOG
    log_path = root / log_rel
    log_counts = formal_log_counts(log_path)
    tree_counts = formal_makefile_counts(root / FORMAL_MAKEFILE)
    commit, log_exit = formal_log_header(log_path)
    hash_ok = bool(
        isinstance(log_block.get("sha256"), str)
        and log_path.is_file()
        and file_sha256(log_path) == log_block["sha256"]
    )
    commit_ok = commit is not None and commit == data.get("commit")
    counts_agree = bool(
        log_counts is not None
        and tree_counts is not None
        and all(checks.get(k) == log_counts[k] == tree_counts[k]
                for k in FORMAL_COUNT_KEYS)
    )
    cases_ok = bool(
        log_counts is not None
        and checks.get("host_cross_check_cases") == log_counts["host_cross_check_cases"]
    )
    base_ok = (
        data.get("command") == "make -C native-sim/formal check"
        and data.get("exit_code") == 0
        and checks.get("generated_contract_drift") is True
        and checks.get("lean_modules") is True
    )
    passed = bool(base_ok and hash_ok and commit_ok and counts_agree and cases_ok)
    if log_counts is None:
        log_detail = f"retained log {log_rel} missing or holds no check commands"
    else:
        log_detail = (
            f"retained log {log_rel}: {log_counts['generator_scripts']} --check "
            f"generators, {log_counts['lean_module_commands']} Lean module checks, "
            f"{log_counts['host_cross_checks']} host cross-checks "
        )
    if tree_counts is None:
        tree_detail = f"{FORMAL_MAKEFILE} missing or enumerates no check commands"
    else:
        tree_detail = (
            f"{FORMAL_MAKEFILE} enumerates "
            + "/".join(str(tree_counts[k]) for k in FORMAL_COUNT_KEYS)
            + " (generators/Lean/host)"
        )
    detail = (
        f"{FORMAL_RECEIPT}: exit_code={data.get('exit_code')!r}, "
        f"generated_contract_drift={checks.get('generated_contract_drift')!r}, "
        f"lean_modules={checks.get('lean_modules')!r}; "
        f"receipt counts="
        + "/".join(str(checks.get(k)) for k in FORMAL_COUNT_KEYS)
        + f", receipt counts agree with log and tree={counts_agree}, "
        f"receipt oracle cases={checks.get('host_cross_check_cases')!r} agree={cases_ok}; "
        f"{log_detail}; {tree_detail}; "
        f"receipt commit={data.get('commit')!r} == log commit={commit!r} -> {commit_ok}; "
        f"receipt log hash valid={hash_ok}"
    )
    return (PASS if passed else PARTIAL), detail


def build_rows(root: Path) -> list[Row]:
    rows: list[Row] = []
    for label, rel in MICRO_RESULTS.items():
        st, prov = micro_evidence(root / rel / "details" / "result.json")
        rows.append(Row(label, st, prov))
    rows.extend(micro_claim_rows(root))
    rows.extend(cilium_claim_rows(root))
    rows.extend(fresh_loadtime_rows(root))
    rows.extend(fresh_exec_speedup_rows(root))
    rows.extend(fresh_codesize_rows(root))
    rows.extend(cilium_attribution_rows(root))
    rows.extend(cilium_retained_bytecode_rows(root))
    rows.extend(katran_retained_bytecode_rows(root))
    rows.extend(tracee_retained_bytecode_rows(root))
    rows.extend(tetragon_retained_bytecode_rows(root))
    rows.extend(katran_arm64_retained_bytecode_rows(root))
    rows.extend(map_inline_causality_rows(root))
    rows.extend(katran_fresh_causality_rows(root))
    rows.extend(cilium_fresh_causality_rows(root))
    rows.extend(tetragon_fresh_causality_rows(root))
    rows.extend(tracee_fresh_causality_rows(root))
    rows.extend(bcc_fresh_causality_rows(root))
    rows.extend(otelcol_fresh_causality_rows(root))
    rows.extend(wide_mem_tetragon_causality_rows(root))
    rows.extend(corpus_evidence(
        root, COVERAGE_RUN, expected_apps=6, claim_label="6 apps"
    ))
    rows.extend(corpus_evidence(
        root,
        SIX_APP_SUCCESS_RUN,
        expected_apps=6,
        claim_label="6 apps success",
        required_command=SIX_APP_COMMAND,
    ))
    rows.extend(corpus_evidence(
        root,
        SMOKE_RUN,
        expected_apps=1,
        claim_label="Katran smoke",
        required_command=SMOKE_COMMAND,
    ))
    st, prov = formal_evidence(root)
    rows.append(Row("Semantic proofs: native emit == proof sequence", st, prov))
    return rows


def render(rows: list[Row], root: Path) -> None:
    width = max(len(r.claim) for r in rows)
    print(f"Artifact claim table (root: {root})")
    print("=" * (width + 40))
    print(f"{'CLAIM'.ljust(width)}  {'STATUS':<12} PROVENANCE")
    print("-" * (width + 40))
    for r in rows:
        print(f"{r.claim.ljust(width)}  {r.status:<12} {r.evidence}")
    print()
    print("PASS = evidence present and consistent; PARTIAL = evidence present but weaker")
    print("than the claim; UNAVAILABLE = regenerate using the PROVENANCE command.")
    print("This table is derived from the JSON files it names and never fabricates numbers.")
    print("OVERALL AE EVIDENCE: " + ("INCOMPLETE" if any(r.status != PASS for r in rows)
                                   else "all listed rows PASS; AEC badge decision remains external"))


def self_test() -> int:
    """Focused assertions using synthetic JSON: catches wrong paths/empty data."""
    failures: list[str] = []
    with tempfile.TemporaryDirectory() as tmp:
        root = Path(tmp)
        # valid micro result
        good = root / "micro/results/x86_kvm_micro_20260519_114214_364050/details"
        good.mkdir(parents=True)
        (good / "result.json").write_text(
            json.dumps(
                {
                    "suite": "micro_staged_codegen",
                    "benchmarks": [
                        {
                            "name": "simple",
                            "expected_result": 42,
                            "runs": [
                                {"mode": "kernel", "runtime": "kernel",
                                 "samples": [
                                     {"result": 42, "exec_ns": 7,
                                      "code_size": {"native_code_bytes": 101}},
                                     {"result": 42, "exec_ns": 9,
                                      "code_size": {"native_code_bytes": 101}},
                                 ]}
                            ],
                        }
                    ],
                }
            )
        )
        st, prov = micro_evidence(good / "result.json")
        if st != PASS:
            failures.append(f"valid micro expected PASS, got {st}: {prov}")

        # wrong path -> UNAVAILABLE
        st, _ = micro_evidence(root / "micro/results/nonexistent/details/result.json")
        if st != UNAVAILABLE:
            failures.append(f"missing path expected UNAVAILABLE, got {st}")

        # malformed JSON -> UNAVAILABLE
        bad = root / "bad/details"
        bad.mkdir(parents=True)
        (bad / "result.json").write_text("{not json")
        st, _ = micro_evidence(bad / "result.json")
        if st != UNAVAILABLE:
            failures.append(f"malformed json expected UNAVAILABLE, got {st}")

        # empty benchmarks -> UNAVAILABLE
        empty = root / "empty/details"
        empty.mkdir(parents=True)
        (empty / "result.json").write_text(json.dumps({"benchmarks": []}))
        st, _ = micro_evidence(empty / "result.json")
        if st != UNAVAILABLE:
            failures.append(f"empty benchmarks expected UNAVAILABLE, got {st}")

        # correctness mismatch -> PARTIAL (never PASS)
        mm = root / "mm/details"
        mm.mkdir(parents=True)
        (mm / "result.json").write_text(
            json.dumps({"benchmarks": [{"expected_result": 1,
                                        "runs": [{"samples": [{"result": 2, "exec_ns": 1}]}]}]})
        )
        st, _ = micro_evidence(mm / "result.json")
        if st != PARTIAL:
            failures.append(f"mismatch expected PARTIAL, got {st}")

        # Six-app coverage: all rejit statuses can pass while one workload fails.
        run = root / COVERAGE_RUN / "details"
        (run / "apps").mkdir(parents=True)
        (run / "progress.json").write_text(json.dumps({"status": "completed"}))
        for i in range(6):
            (run / "apps" / f"app{i}.json").write_text(
                json.dumps({"status": "ok", "rejit_result": {"status": "ok"}})
            )
        rows = corpus_evidence(
            root, COVERAGE_RUN, expected_apps=6, claim_label="6 apps"
        )
        if [r.status for r in rows] != [PASS, PASS]:
            failures.append(
                f"completed corpus expected [PASS, PASS], got {[r.status for r in rows]}"
            )

        (run / "progress.json").write_text(json.dumps({"status": "error"}))
        (run / "apps" / "app0.json").write_text(
            json.dumps({"status": "error", "rejit_result": {"status": "ok"}})
        )
        rows = corpus_evidence(
            root, COVERAGE_RUN, expected_apps=6, claim_label="6 apps"
        )
        if [r.status for r in rows] != [PASS, PARTIAL]:
            failures.append(
                "errored corpus with complete rejit coverage expected "
                f"[PASS, PARTIAL], got {[r.status for r in rows]}"
            )


        # Six-app success requires six ok apps + a matching exit-0 receipt.
        success = root / SIX_APP_SUCCESS_RUN
        (success / "details/apps").mkdir(parents=True)
        (success / "details/progress.json").write_text(
            json.dumps({"status": "completed"})
        )
        for i in range(6):
            (success / "details/apps" / f"app{i}.json").write_text(
                json.dumps({"status": "ok", "rejit_result": {"status": "ok"}})
            )
        (success / "make-corpus.log").write_text("six app run log")
        (success / "receipt.json").write_text(json.dumps({
            "command": SIX_APP_COMMAND,
            "exit_code": 0,
            "source_commit": "b" * 40,
            "log_file": "make-corpus.log",
            "log_sha256": file_sha256(success / "make-corpus.log"),
        }))
        rows = corpus_evidence(
            root,
            SIX_APP_SUCCESS_RUN,
            expected_apps=6,
            claim_label="6 apps success",
            required_command=SIX_APP_COMMAND,
        )
        if [r.status for r in rows] != [PASS, PASS]:
            failures.append(
                f"valid six-app success expected [PASS, PASS], got {[r.status for r in rows]}"
            )
        (success / "details/apps/app0.json").write_text(
            json.dumps({"status": "error", "rejit_result": {"status": "ok"}})
        )
        rows = corpus_evidence(
            root,
            SIX_APP_SUCCESS_RUN,
            expected_apps=6,
            claim_label="6 apps success",
            required_command=SIX_APP_COMMAND,
        )
        if [r.status for r in rows] != [PASS, PARTIAL]:
            failures.append(
                "one failed app under six-app success expected "
                f"[PASS, PARTIAL], got {[r.status for r in rows]}"
            )

        # Fresh smoke PASS requires raw success plus an exit-0, hash-bound receipt.
        smoke = root / SMOKE_RUN
        (smoke / "details/apps").mkdir(parents=True)
        (smoke / "details/progress.json").write_text(
            json.dumps({"status": "completed"})
        )
        (smoke / "details/apps/katran.json").write_text(
            json.dumps({"status": "ok", "rejit_result": {"status": "ok"}})
        )
        (smoke / "make-corpus.log").write_text("real run log")
        (smoke / "receipt.json").write_text(json.dumps({
            "command": SMOKE_COMMAND,
            "exit_code": 0,
            "source_commit": "a" * 40,
            "log_file": "make-corpus.log",
            "log_sha256": file_sha256(smoke / "make-corpus.log"),
        }))
        rows = corpus_evidence(
            root,
            SMOKE_RUN,
            expected_apps=1,
            claim_label="Katran smoke",
            required_command=SMOKE_COMMAND,
        )
        if [r.status for r in rows] != [PASS, PASS]:
            failures.append(
                f"valid smoke receipt expected [PASS, PASS], got {[r.status for r in rows]}"
            )
        receipt = load_json(smoke / "receipt.json")
        receipt["exit_code"] = 1
        (smoke / "receipt.json").write_text(json.dumps(receipt))
        rows = corpus_evidence(
            root,
            SMOKE_RUN,
            expected_apps=1,
            claim_label="Katran smoke",
            required_command=SMOKE_COMMAND,
        )
        if [r.status for r in rows] != [PARTIAL, PARTIAL]:
            failures.append(
                f"failed smoke receipt expected [PARTIAL, PARTIAL], got {[r.status for r in rows]}"
            )

        # Formal PASS requires a retained receipt that agrees with the log it
        # names and with the Makefile the current tree enumerates, so a receipt
        # left behind by an older proof tree degrades to PARTIAL.
        receipt = root / FORMAL_RECEIPT
        receipt.parent.mkdir(parents=True, exist_ok=True)
        fmake = root / FORMAL_MAKEFILE
        fmake.parent.mkdir(parents=True, exist_ok=True)
        synthetic_log = (
            "started=1970-01-01T00:00:00+00:00 commit=" + "a" * 40 + "\n"
            "python3 generate_one_spec.py --check\n"
            "python3 generate_two_spec.py --check\n"
            "lake env lean KProgFormal/One.lean\n"
            "./build/test_one_host\n"
            "one host cross-check: OK (11 cases)\n"
            "exit=0 ended=1970-01-01T00:00:01+00:00\n"
        )
        fmake.write_text(
            "check:\n"
            "\tpython3 generate_one_spec.py --check\n"
            "\tpython3 generate_two_spec.py --check\n"
            "\tlake env lean KProgFormal/One.lean\n"
            "\t./build/test_one_host\n"
        )
        good_formal = {
            "command": "make -C native-sim/formal check",
            "exit_code": 0,
            "commit": "a" * 40,
            "checks": {
                "generated_contract_drift": True,
                "lean_modules": True,
                "generator_scripts": 2,
                "lean_module_commands": 1,
                "host_cross_checks": 1,
                "host_cross_check_cases": 11,
            },
            "log": {"path": FORMAL_LOG},
        }
        log_path = root / FORMAL_LOG

        def write_formal(payload: dict) -> None:
            receipt.write_text(json.dumps(payload))

        def write_log(text: str) -> None:
            log_path.write_text(text)
            good_formal["log"]["sha256"] = file_sha256(log_path)

        # Consistent receipt + log + Makefile -> PASS.
        write_log(synthetic_log)
        write_formal(good_formal)
        st, prov = formal_evidence(root)
        if st != PASS:
            failures.append(f"consistent formal evidence expected PASS, got {st}: {prov}")

        # A log from an older proof tree (fewer checks) must not PASS even
        # though the receipt still claims to be complete.
        stale = synthetic_log.replace(
            "python3 generate_two_spec.py --check\n", ""
        ).replace("./build/test_one_host\n", "").replace(
            "one host cross-check: OK (11 cases)\n", ""
        )
        write_log(stale)
        write_formal(good_formal)
        st, prov = formal_evidence(root)
        if st != PARTIAL or "agree with log and tree=False" not in prov:
            failures.append(
                f"stale formal log expected PARTIAL with disagreement, got {st}: {prov}"
            )

        # A receipt whose recorded log hash no longer matches the log -> PARTIAL.
        write_log(synthetic_log)
        tampered = json.loads(json.dumps(good_formal))
        tampered["log"]["sha256"] = "0" * 64
        write_formal(tampered)
        st, prov = formal_evidence(root)
        if st != PARTIAL or "receipt log hash valid=False" not in prov:
            failures.append(
                f"stale formal log hash expected PARTIAL, got {st}: {prov}"
            )

        # A receipt whose commit disagrees with the log header -> PARTIAL.
        write_log(synthetic_log)
        wrong_commit = json.loads(json.dumps(good_formal))
        wrong_commit["commit"] = "b" * 40
        write_formal(wrong_commit)
        st, prov = formal_evidence(root)
        if st != PARTIAL or "-> False" not in prov:
            failures.append(
                f"formal commit mismatch expected PARTIAL, got {st}: {prov}"
            )

        # Non-zero exit -> PARTIAL.
        write_log(synthetic_log)
        write_formal({"command": "make -C native-sim/formal check", "exit_code": 1,
                      "commit": "a" * 40, "checks": good_formal["checks"],
                      "log": {"path": FORMAL_LOG,
                              "sha256": file_sha256(log_path)}})
        st, _ = formal_evidence(root)
        if st != PARTIAL:
            failures.append(f"failed formal receipt expected PARTIAL, got {st}")

        # RQ3 corpus rows: derivable PASS only when mean pps and BPF cost match.
        rq3 = root / "corpus/results/x86_kvm_corpus_20260605_145112_835705"
        (rq3 / "details/apps").mkdir(parents=True)
        (rq3 / "metadata.json").write_text(json.dumps({
            "status": "error", "run_type": "x86_kvm_corpus", "suite": "corpus",
            "samples": 3, "workload_seconds": 30.0, "bpf_stats": True,
            "config": {"enabled_passes": ["kop_all_prefetch"]},
        }))
        (rq3 / "details/progress.json").write_text(json.dumps({"status": "error"}))
        def _wl(pps: int) -> dict:
            return {"workloads": [{"stdout": f"\n{pps}pps 1000Mb/sec (1000000000bps) errors: 0\n"}] * 3}

        bpf = {"p0": {"run_cnt_delta": 1000, "run_time_ns_delta": 1000 * 1000}}
        bpf_post = {"p0": {"run_cnt_delta": 1000, "run_time_ns_delta": 1000 * 776}}
        (rq3 / "details/apps/cilium__agent.json").write_text(json.dumps({
            "status": "ok", "baseline": {**_wl(1000), "bpf": bpf},
            "post_rejit": {**_wl(1114), "bpf": bpf_post},
        }))
        rows = [r for r in cilium_claim_rows(root) if r.claim.startswith("RQ3 Cilium coverage-max throughput")]
        if len(rows) != 1 or rows[0].status != PASS:
            failures.append(
                "RQ3 coverage-max row expected PASS, got "
                f"{[(r.claim, r.status) for r in rows]}"
            )
        (rq3 / "details/apps/cilium__agent.json").write_text(json.dumps({
            "status": "ok", "baseline": {**_wl(1000), "bpf": bpf},
            "post_rejit": {**_wl(1200), "bpf": bpf_post},
        }))
        rows = [r for r in cilium_claim_rows(root) if r.claim.startswith("RQ3 Cilium coverage-max throughput")]
        if len(rows) != 1 or rows[0].status != PARTIAL:
            failures.append(
                "RQ3 coverage-max with wrong ratio expected PARTIAL, got "
                f"{[(r.claim, r.status) for r in rows]}"
            )

        # RQ3 applied-site rows: derivable only from a retained loadtime report.
        arm = root / "corpus/results/x86_kvm_corpus_20260924_064817_392000"
        reports = arm / "details/loadtime-reports"
        reports.mkdir(parents=True)
        (arm / "details/apps").mkdir(parents=True)
        (arm / "metadata.json").write_text(json.dumps({
            "status": "completed", "run_type": "x86_kvm_corpus", "suite": "corpus",
            "samples": 3, "workload_seconds": 30.0, "bpf_stats": True,
            "config": {"enabled_passes": ["kop_all_prefetch"]},
        }))
        (arm / "details/progress.json").write_text(json.dumps({"status": "completed"}))
        (arm / "details/apps/cilium__agent.json").write_text(json.dumps({
            "status": "ok", "baseline": {**_wl(1000), "bpf": bpf},
            "post_rejit": {**_wl(1114), "bpf": bpf_post},
        }))
        site_rows = [r for r in cilium_site_rows(root) if r.claim.startswith("RQ3 Cilium coverage-max")]
        if len(site_rows) != 1 or site_rows[0].status != UNAVAILABLE:
            failures.append(
                "RQ3 site row without report expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in site_rows]}"
            )
        (reports / "cilium__agent.jsonl").write_text("\n".join(json.dumps({
            "step": "kop_all_prefetch", "step_index": 0,
            "report": {"pass": "kop", "sites_applied": sites},
        }) for sites in (2000, 1017)) + "\n")
        site_rows = [r for r in cilium_site_rows(root) if r.claim.startswith("RQ3 Cilium coverage-max")]
        if len(site_rows) != 1 or site_rows[0].status != PASS or "3017 sites" not in site_rows[0].claim:
            failures.append(
                "RQ3 site row with matching single-step report expected PASS/3017, got "
                f"{[(r.claim, r.status) for r in site_rows]}"
            )
        (reports / "cilium__agent.jsonl").write_text(
            json.dumps({"step": "kop_all_prefetch", "report": {"pass": "kop", "sites_applied": 10}})
            + "\n"
            + json.dumps({"step": "other_step", "report": {"pass": "kop", "sites_applied": 10}})
            + "\n"
        )
        site_rows = [r for r in cilium_site_rows(root) if r.claim.startswith("RQ3 Cilium coverage-max")]
        if len(site_rows) != 1 or site_rows[0].status != PARTIAL:
            failures.append(
                "RQ3 site row spanning two steps expected PARTIAL, got "
                f"{[(r.claim, r.status) for r in site_rows]}"
            )

        # RQ2 applied-site row: derived from the fresh `kop` rerun's report.
        rq2_arm = root / CILIUM_RQ2_SITE_RUN / "details/loadtime-reports"
        rq2_rows = [r for r in cilium_claim_rows(root) if r.claim.startswith("RQ2 Cilium x86 applied sites")]
        if len(rq2_rows) != 1 or rq2_rows[0].status != UNAVAILABLE:
            failures.append(
                "RQ2 site row without report expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in rq2_rows]}"
            )
        rq2_arm.mkdir(parents=True)
        (rq2_arm / "cilium__agent.jsonl").write_text(json.dumps({
            "step": "kop", "report": {"pass": "kop", "sites_applied": 2988}}) + "\n")
        rq2_rows = [r for r in cilium_claim_rows(root) if r.claim.startswith("RQ2 Cilium x86 applied sites")]
        if len(rq2_rows) != 1 or rq2_rows[0].status != PASS or "2988 fresh" not in rq2_rows[0].claim:
            failures.append(
                "RQ2 site row with retained `kop` report expected PASS/2988, got "
                f"{[(r.claim, r.status) for r in rq2_rows]}"
            )

        # Caller-vs-tail-descendant attribution rows: derivable only when both
        # the report stream and the app's own counters are retained and parse.
        (reports / "cilium__agent.jsonl").unlink()
        attr_rows = [r for r in cilium_attribution_rows(root)
                     if r.claim.startswith("RQ3 Cilium coverage-max applied sites attribution")]
        if len(attr_rows) != 1 or attr_rows[0].status != UNAVAILABLE:
            failures.append(
                "attribution row without report expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in attr_rows]}"
            )
        (arm / "details/apps/cilium__agent.json").write_text(json.dumps({
            "status": "ok",
            "baseline": {"bpf": [
                {"name": "cil_from_contai", "run_cnt_delta": 900,
                 "run_time_ns_delta": 900_000},
                {"name": "tail_nodeport_n", "run_cnt_delta": 0,
                 "run_time_ns_delta": 0},
            ]},
        }))
        (reports / "cilium__agent.jsonl").write_text("\n".join(json.dumps({
            "prog_name": name, "report": {"sites_applied": sites},
        }) for name, sites in (
            ("cil_from_contai", 300), ("tail_nodeport_n", 500),
            ("orphan_prefix", 40),
        )) + "\n")
        attr_rows = [r for r in cilium_attribution_rows(root)
                     if r.claim.startswith("RQ3 Cilium coverage-max applied sites attribution")]
        if (len(attr_rows) != 1 or attr_rows[0].status != PASS
                or "directly attached (run_cnt_delta>0) = 300" not in attr_rows[0].evidence
                or "zero-self (tail targets) = 500" not in attr_rows[0].evidence
                or "name-join residual = 40" not in attr_rows[0].evidence
                or "sites reconcile=True" not in attr_rows[0].evidence):
            failures.append(
                "attribution row expected PASS/300/500/40, got "
                f"{[(r.claim, r.status, r.evidence) for r in attr_rows]}"
            )
        (reports / "cilium__agent.jsonl").write_text("{not json\n")
        attr_rows = [r for r in cilium_attribution_rows(root)
                     if r.claim.startswith("RQ3 Cilium coverage-max applied sites attribution")]
        if len(attr_rows) != 1 or attr_rows[0].status != UNAVAILABLE:
            failures.append(
                "attribution row with unparsable report expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in attr_rows]}"
            )

        # RQ3 Katran applied-site rows: derived from the fresh arm64 arm report.
        kat_label = KATRAN_SITE_ARMS[0][1]
        kat_rows = [r for r in katran_site_rows(root) if r.claim.startswith("RQ3 Katran conservative")]
        if len(kat_rows) != 1 or kat_rows[0].status != UNAVAILABLE:
            failures.append(
                "RQ3 Katran site row without report expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in kat_rows]}"
            )
        kat_dir = root / kat_label / "details/loadtime-reports"
        kat_dir.mkdir(parents=True)
        (kat_dir / "katran.jsonl").write_text(json.dumps({
            "step": "kop", "report": {"pass": "kop", "sites_applied": 21}}) + "\n")
        kat_rows = [r for r in katran_site_rows(root) if r.claim.startswith("RQ3 Katran conservative")]
        if len(kat_rows) != 1 or kat_rows[0].status != PARTIAL or "21 sites" not in kat_rows[0].claim:
            failures.append(
                "RQ3 Katran site row with report but no app JSON expected PARTIAL/21, got "
                f"{[(r.claim, r.status) for r in kat_rows]}"
            )

        # RQ4 native-loader rows: derived from the fresh retained shim log.
        nat_rows = native_loader_rows(root)
        if len(nat_rows) != 2 or any(r.status != UNAVAILABLE for r in nat_rows):
            failures.append(
                "RQ4 native rows without shim log expected UNAVAILABLE, got "
                f"{[(r.claim, r.status) for r in nat_rows]}"
            )
        nat_run = root / CILIUM_NATIVE_POST_RUN
        (nat_run / "details/apps").mkdir(parents=True)
        (nat_run / "metadata.json").write_text(json.dumps({
            "status": "completed", "run_type": "x86_kvm_corpus", "suite": "corpus",
            "samples": 3, "workload_seconds": 30.0, "bpf_stats": True,
            "config": {"enabled_passes": []},
        }))
        (nat_run / "details/progress.json").write_text(json.dumps({"status": "completed"}))
        (nat_run / "details/apps/cilium__agent.json").write_text(json.dumps({
            "status": "ok", "baseline": {**_wl(1000), "bpf": bpf},
            "post_rejit": {**_wl(2358), "bpf": bpf_post},
        }))
        nat_log = root / NATIVE_EVIDENCE_DIR / "details/shim-logs/cilium__agent.post_rejit.log"
        nat_log.parent.mkdir(parents=True)
        nat_log.write_text("\n".join([
            "BPF_PROG_LOAD type=1 (socket_filter) name= insn_cnt=2",
            "BPF_PROG_LOAD type=6 (xdp) name=bpf_xdp insn_cnt=40",
            "native-loader replaced prog=bpf_xdp original_fd=7 native_object=bpf_xdp.native.o",
            "BPF_PROG_LOAD type=3 (sched_cls) name=probe insn_cnt=23",
            "native-loader skipped feature probe program name=probe insn_cnt=23",
        ]) + "\n")
        nat_rows = native_loader_rows(root)
        first = nat_rows[0]
        if (len(nat_rows) != 2 or first.status != PARTIAL
                or first.claim != "RQ4 native loader replacements (1 fresh, 3 loads)"
                or "1 loads carrying no decision line" not in first.evidence):
            failures.append(
                "RQ4 native loader row without receipt expected PARTIAL/1 fresh/3 loads, got "
                f"{[(r.claim, r.status) for r in nat_rows]} {first.evidence!r}"
            )
        (root / NATIVE_EVIDENCE_DIR / "receipt.json").write_text(json.dumps({
            "shim_log_files_sha256": {
                "details/shim-logs/cilium__agent.post_rejit.log": file_sha256(nat_log),
            },
        }))
        nat_rows = native_loader_rows(root)
        first = nat_rows[0]
        if first.status != PASS or "receipt log hash valid=True" not in first.evidence:
            failures.append(
                "RQ4 native loader row with matching receipt hash expected PASS, got "
                f"{(first.status, first.evidence)!r}"
            )
        (root / NATIVE_EVIDENCE_DIR / "receipt.json").write_text(json.dumps({
            "shim_log_files_sha256": {
                "details/shim-logs/cilium__agent.post_rejit.log": "0" * 64,
            },
        }))
        first = native_loader_rows(root)[0]
        if first.status != PARTIAL or "receipt log hash valid=False" not in first.evidence:
            failures.append(
                "RQ4 native loader row with stale receipt hash expected PARTIAL, got "
                f"{(first.status, first.evidence)!r}"
            )
        (root / NATIVE_EVIDENCE_DIR / "manifest.json").write_text(json.dumps({
            "objects": [{"native_object": "bpf_xdp.native.o"},
                        {"native_object": "bpf_xdp.native.o"},
                        {"native_object": "bpf_host.native.o"}],
        }))
        nat_rows = native_loader_rows(root)
        second = nat_rows[1]
        if (second.status != PARTIAL
                or second.claim != "RQ4 Cilium native manifest objects (3 fresh)"
                or "2 distinct native objects" not in second.evidence):
            failures.append(
                "RQ4 manifest row with synthetic 3-object manifest expected PARTIAL/3 fresh, got "
                f"{[(r.claim, r.status) for r in nat_rows]} {second.evidence!r}"
            )
        # RQ1 62-case object-load row: status is derived from the open+load
        # ratio (the paper's sec 7.1 quantity) the two historical ReJIT runs
        # produce over the population name set, while the bare object_load_ns
        # ratio is reported alongside it.
        hist_rel = MICRO_RESULTS["RQ1 x86 historical load-time run A"]
        hist_rel_b = MICRO_RESULTS["RQ1 x86 historical load-time run B"]
        pop_rel = MICRO_RESULTS["RQ1 x86 historical 62-case population"]
        names = [f"case{i}" for i in range(62)]
        (root / pop_rel / "details").mkdir(parents=True, exist_ok=True)
        (root / pop_rel / "details/result.json").write_text(json.dumps(
            {"benchmarks": [{"name": n} for n in names]}))

        def write_hist(rel: str, rejit_open_ns: int, rejit_load_ns: int) -> None:
            d = root / rel
            (d / "details").mkdir(parents=True, exist_ok=True)
            (d / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_micro",
                "suite": "micro_staged_codegen",
                "host": {"platform": "x86_64", "kernel_version": "7.0.0-rc2+"},
            }))
            (d / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            benches = []
            for n in names:
                benches.append({"name": n, "runs": [
                    {"runtime": "kernel", "samples": [
                        {"phases_ns": {"object_open_ns": 100, "object_load_ns": 1000}}]},
                    {"runtime": "kernel_rejit", "samples": [
                        {"phases_ns": {"object_open_ns": rejit_open_ns,
                                       "object_load_ns": rejit_load_ns}}]},
                ]})
            (d / "details/result.json").write_text(json.dumps({"benchmarks": benches}))

        def object_load_row() -> Row:
            return next(r for r in micro_claim_rows(root)
                        if r.claim.startswith("RQ1 x86 62-case object-load overhead"))

        # open+load 1089/1100 = 0.99x while the bare load field is 1000/1000 =
        # 1.00x: the paper-matched quantity passes and both are reported.
        write_hist(hist_rel, 89, 1000)
        write_hist(hist_rel_b, 89, 1000)
        row = object_load_row()
        if (row.status != PASS or "rounds to paper 0.99x=True" not in row.evidence
                or "bare object_load_ns 1.000000x" not in row.evidence):
            failures.append(
                f"62-case row with 0.99x open+load ratios expected PASS, got {(row.status, row.evidence)!r}")

        # open+load 1100/1100 = 1.00x: the paper-matched quantity diverges.
        write_hist(hist_rel_b, 100, 1000)
        row = object_load_row()
        if row.status != PARTIAL or "rounds to paper 0.99x=False" not in row.evidence:
            failures.append(
                f"62-case row with a 1.00x run expected PARTIAL, got {(row.status, row.evidence)!r}")

        # Fresh paired load-time row: status derives from the run's own
        # open+load ratio against the paper's 0.99x threshold, with the bare
        # object_load_ns ratio reported beside it.
        fresh_rel, fresh_policy = FRESH_LOADTIME_RUNS[0][1], FRESH_LOADTIME_RUNS[0][2]

        def write_fresh(rejit_open_ns: int, rejit_load_ns: int) -> None:
            d = root / fresh_rel
            (d / "details").mkdir(parents=True, exist_ok=True)
            (d / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_micro",
                "suite": "micro_staged_codegen",
                "host": {"platform": "x86_64", "kernel_version": "7.0.0-rc2+"},
            }))
            (d / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            benches = [{"name": "caseA", "runs": [
                {"runtime": "kernel", "samples": [
                    {"phases_ns": {"object_open_ns": 100, "object_load_ns": 1000}}]},
                {"runtime": "kernel_rejit", "samples": [
                    {"phases_ns": {"object_open_ns": rejit_open_ns,
                                   "object_load_ns": rejit_load_ns}}]},
            ]}]
            (d / "details/result.json").write_text(json.dumps({"benchmarks": benches}))

        def fresh_row() -> Row:
            return next(r for r in fresh_loadtime_rows(root)
                        if r.claim == FRESH_LOADTIME_RUNS[0][0])

        write_fresh(89, 1000)
        row = fresh_row()
        if (row.status != PASS or "rounds to paper 0.99x=True" not in row.evidence
                or f"policy={fresh_policy}" not in row.evidence
                or "bare object_load_ns geomean=1.000000x" not in row.evidence):
            failures.append(
                f"fresh row with 0.99x open+load ratio expected PASS, got {(row.status, row.evidence)!r}")

        write_fresh(100, 1160)
        row = fresh_row()
        if row.status != PARTIAL or "rounds to paper 0.99x=False" not in row.evidence:
            failures.append(
                f"fresh row with 1.16x ratio expected PARTIAL, got {(row.status, row.evidence)!r}")

        # A run retaining no object_open_ns cannot support the paper-matched
        # quantity even though the bare field is present.
        write_fresh(0, 1000)
        row = fresh_row()
        if row.status != UNAVAILABLE or "no paired" not in row.evidence:
            failures.append(
                f"fresh row without object_open_ns expected UNAVAILABLE, got {(row.status, row.evidence)!r}")

        # Repeated-sample row: the paper-protocol run (3 samples/case). Each
        # case's value must be the median over its samples, so one outlier
        # sample cannot move the row; the reported sample count comes from the
        # run itself.
        rep_rel = FRESH_LOADTIME_RUNS[2][1]
        rep_policy = FRESH_LOADTIME_RUNS[2][2]
        d = root / rep_rel
        (d / "details").mkdir(parents=True, exist_ok=True)
        (d / "metadata.json").write_text(json.dumps({
            "status": "completed", "run_type": "x86_kvm_micro",
            "suite": "micro_staged_codegen",
            "host": {"platform": "x86_64", "kernel_version": "7.0.0-rc2+"},
        }))
        (d / "details/progress.json").write_text(json.dumps({"status": "completed"}))
        (d / "details/result.json").write_text(json.dumps({"benchmarks": [
            {"name": "caseA", "runs": [
                {"runtime": "kernel", "samples": [
                    {"phases_ns": {"object_open_ns": 100, "object_load_ns": 1000}},
                    {"phases_ns": {"object_open_ns": 100, "object_load_ns": 1000}},
                    {"phases_ns": {"object_open_ns": 100, "object_load_ns": 1000}}]},
                {"runtime": "kernel_rejit", "samples": [
                    {"phases_ns": {"object_open_ns": 99, "object_load_ns": 990}},
                    {"phases_ns": {"object_open_ns": 99, "object_load_ns": 9000}},
                    {"phases_ns": {"object_open_ns": 99, "object_load_ns": 990}}]},
            ]}]}))
        row = next(r for r in fresh_loadtime_rows(root)
                   if r.claim == FRESH_LOADTIME_RUNS[2][0])
        if (row.status != PASS or "3 samples/case" not in row.evidence
                or "object_load_ns)=0.990000x" not in row.evidence
                or f"policy={rep_policy}" not in row.evidence):
            failures.append(
                f"repeated-sample row expected PASS/median 0.990000x/3 samples, got "
                f"{(row.status, row.evidence)!r}")

        # Fresh paired exec-speedup row: same run, derived from the paired
        # exec_ns series restricted to the 27 non-simple kop-bearing cases.
        def write_fresh_exec(rejit_ns: int, kop_sites: int) -> None:
            d = root / fresh_rel
            (d / "details").mkdir(parents=True, exist_ok=True)
            (d / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_micro",
                "suite": "micro_staged_codegen",
                "host": {"platform": "x86_64", "kernel_version": "7.0.0-rc2+"},
            }))
            (d / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            names = [f"c{i}" for i in range(27)] + ["simple", "simple_packet"]
            benches = []
            for n in names:
                benches.append({"name": n, "runs": [
                    {"runtime": "kernel", "samples": [
                        {"phases_ns": {"object_load_ns": 1000}, "exec_ns": 1000}]},
                    {"runtime": "kernel_rejit", "samples": [
                        {"phases_ns": {"object_load_ns": 1000}, "exec_ns": rejit_ns,
                         "rejit_result": {"per_program": {"1": {"passes": [
                             {"bpfopt_summary": {"pass": "kop", "sites_applied": kop_sites}}]}}}}]},
                ]})
            (d / "details/result.json").write_text(json.dumps({"benchmarks": benches}))

        def fresh_exec_row() -> Row:
            return next(r for r in fresh_exec_speedup_rows(root)
                        if r.claim == FRESH_EXEC_RUNS[0][0])

        write_fresh_exec(1000, 5)
        row = fresh_exec_row()
        if (row.status != PASS or "27 kop-bearing" not in row.evidence
                or f"policy={fresh_policy}" not in row.evidence):
            failures.append(
                f"fresh exec row with 27 bearing cases expected PASS, got {(row.status, row.evidence)!r}")

        write_fresh_exec(2000, 5)
        row = fresh_exec_row()
        if row.status != PASS or "geomean=0.500000x" not in row.evidence:
            failures.append(
                f"fresh exec row with 0.5x speedup expected PASS/0.500000x, got {(row.status, row.evidence)!r}")

        write_fresh_exec(1000, 0)
        row = fresh_exec_row()
        if row.status != UNAVAILABLE or "expected 27" not in row.evidence:
            failures.append(
                f"fresh exec row with no applied sites expected UNAVAILABLE, got {(row.status, row.evidence)!r}")

        # Fresh paired code-size row: same run, derived from the paired
        # native_code_bytes series over all 29 cases.
        def write_fresh_codesize(rejit_bytes: int) -> None:
            d = root / fresh_rel
            (d / "details").mkdir(parents=True, exist_ok=True)
            (d / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_micro",
                "suite": "micro_staged_codegen",
                "host": {"platform": "x86_64", "kernel_version": "7.0.0-rc2+"},
            }))
            (d / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            benches = [{"name": "caseA", "runs": [
                {"runtime": "kernel", "samples": [
                    {"code_size": {"native_code_bytes": 1000}, "exec_ns": 1000}]},
                {"runtime": "kernel_rejit", "samples": [
                    {"code_size": {"native_code_bytes": rejit_bytes}, "exec_ns": 1000}]},
            ]}]
            (d / "details/result.json").write_text(json.dumps({"benchmarks": benches}))

        def fresh_codesize_row() -> Row:
            return next(r for r in fresh_codesize_rows(root)
                        if r.claim == FRESH_CODESIZE_RUNS[0][0])

        write_fresh_codesize(500)
        row = fresh_codesize_row()
        if (row.status != PASS or "median native_code_bytes=0.500000x" not in row.evidence
                or f"policy={fresh_policy}" not in row.evidence):
            failures.append(
                f"fresh code-size row with 0.5x expected PASS/0.500000x, got {(row.status, row.evidence)!r}")

        write_fresh_codesize(0)
        row = fresh_codesize_row()
        if row.status != UNAVAILABLE or "no paired kernel/kernel_rejit native_code_bytes" not in row.evidence:
            failures.append(
                f"fresh code-size row with no bytes expected UNAVAILABLE, got {(row.status, row.evidence)!r}")

        # Retained map_inline bytecode row: PASS requires the report stream and
        # the per-step bytecode to reconcile, so a missing evidence dir is
        # UNAVAILABLE and a tampered length or identical before/after image
        # degrades the row to PARTIAL.
        ev = root / MAP_INLINE_EVIDENCE_DIR

        def write_map_inline(applied: int, before: int, after: int,
                             bytecode: str = "differing") -> None:
            if ev.exists():
                import shutil as _sh
                _sh.rmtree(ev)
            (ev / "details/apps").mkdir(parents=True)
            (ev / "details/loadtime-reports").mkdir(parents=True)
            wd = ev / "details/loadtime-workdirs/loadtime_1_0"
            wd.mkdir(parents=True)
            (ev / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_corpus",
                "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
            (ev / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            (ev / "details/apps/cilium__agent.json").write_text(json.dumps({
                "status": "ok", "error": ""}))
            (ev / "details/loadtime-reports/cilium__agent.jsonl").write_text(json.dumps({
                "prog_name": "p", "workdir": "/run/details/loadtime-workdirs/loadtime_1_0",
                "report": {"insn_count_before": before, "insn_count_after": after,
                           "sites_applied": applied}}) + "\n")
            (wd / "report.0.json").write_text(json.dumps({
                "insn_count_before": before, "insn_count_after": after,
                "sites_applied": applied}))
            (wd / "input.step.0.bin").write_bytes(b"\x00" * (8 * before))
            if bytecode == "identical":
                out = b"\x00" * (8 * before)
            else:
                out = b"\x00" * (8 * after)
            (wd / "output.next.0.bin").write_bytes(out)
            (ev / "receipt.json").write_text(json.dumps({
                "files_sha256": {"metadata.json": file_sha256(ev / "metadata.json")}}))

        def map_inline_row() -> Row:
            return cilium_retained_bytecode_rows(root)[0]

        write_map_inline(applied=7, before=10, after=4)
        row = map_inline_row()
        if row.status != PASS or "7 applied sites" not in row.evidence:
            failures.append(
                f"valid retained bytecode expected PASS/7 sites, got {(row.status, row.evidence)!r}")
        if "insn 10->4 (-6)" not in row.evidence:
            failures.append(
                f"retained bytecode expected derived insn delta, got {row.evidence!r}")

        import shutil as _sh
        _sh.rmtree(ev)
        row = map_inline_row()
        if row.status != UNAVAILABLE:
            failures.append(
                f"missing retained bytecode expected UNAVAILABLE, got {(row.status, row.evidence)!r}")

        write_map_inline(applied=7, before=10, after=4, bytecode="identical")
        row = map_inline_row()
        if row.status != PARTIAL or "1 identical before/after images" not in row.evidence:
            failures.append(
                f"identical before/after expected PARTIAL, got {(row.status, row.evidence)!r}")

        write_map_inline(applied=7, before=10, after=4, bytecode="short")
        (ev / "details/loadtime-workdirs/loadtime_1_0/input.step.0.bin").write_bytes(b"\x00" * 8)
        row = map_inline_row()
        if row.status != PARTIAL or "1 length mismatches" not in row.evidence:
            failures.append(
                f"bytecode length mismatch expected PARTIAL, got {(row.status, row.evidence)!r}")

        # Katran retained bytecode row: same derivation over the katran report
        # stream, so a mismatched length or identical image must degrade it.
        kev = root / KATRAN_MAP_INLINE_EVIDENCE_DIR

        def write_katran_map_inline(before: int, after: int,
                                    bytecode: str = "differing") -> None:
            if kev.exists():
                import shutil as _sh
                _sh.rmtree(kev)
            (kev / "details/apps").mkdir(parents=True)
            (kev / "details/loadtime-reports").mkdir(parents=True)
            wd = kev / "details/loadtime-workdirs/loadtime_2_0"
            wd.mkdir(parents=True)
            (kev / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_corpus",
                "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
            (kev / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            (kev / "details/apps/katran.json").write_text(json.dumps({
                "status": "ok", "error": ""}))
            (kev / "details/loadtime-reports/katran.jsonl").write_text(json.dumps({
                "prog_name": "balancer_ingres",
                "workdir": "/run/details/loadtime-workdirs/loadtime_2_0",
                "report": {"insn_count_before": before, "insn_count_after": after,
                           "sites_applied": 16}}) + "\n")
            (wd / "report.0.json").write_text(json.dumps({
                "insn_count_before": before, "insn_count_after": after,
                "sites_applied": 16}))
            (wd / "input.step.0.bin").write_bytes(b"\x00" * (8 * before))
            out = (b"\x00" * (8 * before) if bytecode == "identical"
                   else b"\x00" * (8 * after))
            (wd / "output.next.0.bin").write_bytes(out)
            (kev / "receipt.json").write_text(json.dumps({
                "files_sha256": {"metadata.json": file_sha256(kev / "metadata.json")}}))

        def katran_row() -> Row:
            return katran_retained_bytecode_rows(root)[0]

        write_katran_map_inline(before=2542, after=2272)
        row = katran_row()
        if row.status != PASS or "16 applied sites" not in row.evidence:
            failures.append(
                f"valid Katran retained bytecode expected PASS/16 sites, got {(row.status, row.evidence)!r}")
        if "insn 2542->2272 (-270)" not in row.evidence:
            failures.append(
                f"Katran retained bytecode expected derived insn delta, got {row.evidence!r}")

        write_katran_map_inline(before=2542, after=2272, bytecode="identical")
        row = katran_row()
        if row.status != PARTIAL or "1 identical before/after images" not in row.evidence:
            failures.append(
                f"Katran identical before/after expected PARTIAL, got {(row.status, row.evidence)!r}")

        write_katran_map_inline(before=2542, after=2272)
        (kev / "details/loadtime-workdirs/loadtime_2_0/input.step.0.bin").write_bytes(b"\x00" * 8)
        row = katran_row()
        if row.status != PARTIAL or "1 length mismatches" not in row.evidence:
            failures.append(
                f"Katran bytecode length mismatch expected PARTIAL, got {(row.status, row.evidence)!r}")

        # Tracee retained bytecode row: same shared derivation over the tracee
        # report stream, so a multi-instance stream must aggregate and a
        # mismatch must degrade it.
        tev = root / TRACEE_MAP_INLINE_EVIDENCE_DIR

        def write_tracee_map_inline(instances: list[tuple[int, int]],
                                    bytecode: str = "differing") -> None:
            if tev.exists():
                import shutil as _sh
                _sh.rmtree(tev)
            (tev / "details/apps").mkdir(parents=True)
            (tev / "details/loadtime-reports").mkdir(parents=True)
            lines = []
            for index, (before, after) in enumerate(instances):
                wd = tev / f"details/loadtime-workdirs/loadtime_3_{index}"
                wd.mkdir(parents=True)
                lines.append(json.dumps({
                    "prog_name": f"prog_{index}",
                    "workdir": f"/run/details/loadtime-workdirs/loadtime_3_{index}",
                    "report": {"insn_count_before": before,
                               "insn_count_after": after, "sites_applied": 1}}))
                (wd / "report.0.json").write_text(json.dumps({
                    "insn_count_before": before, "insn_count_after": after,
                    "sites_applied": 1}))
                (wd / "input.step.0.bin").write_bytes(b"\x00" * (8 * before))
                out = (b"\x00" * (8 * before) if bytecode == "identical"
                       else b"\x00" * (8 * after))
                (wd / "output.next.0.bin").write_bytes(out)
            (tev / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_corpus",
                "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
            (tev / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            (tev / "details/apps/tracee__monitor.json").write_text(json.dumps({
                "status": "ok", "error": ""}))
            (tev / "details/loadtime-reports/tracee__monitor.jsonl").write_text(
                "\n".join(lines) + "\n")
            (tev / "receipt.json").write_text(json.dumps({
                "files_sha256": {"metadata.json": file_sha256(tev / "metadata.json")}}))

        def tracee_row() -> Row:
            return tracee_retained_bytecode_rows(root)[0]

        write_tracee_map_inline([(579, 416), (482, 353)])
        row = tracee_row()
        if row.status != PASS or "2 applied sites" not in row.evidence:
            failures.append(
                f"valid Tracee retained bytecode expected PASS/2 sites, got {(row.status, row.evidence)!r}")
        if "insn 1061->769 (-292)" not in row.evidence:
            failures.append(
                f"Tracee retained bytecode expected aggregated insn delta, got {row.evidence!r}")

        write_tracee_map_inline([(579, 416), (482, 353)], bytecode="identical")
        row = tracee_row()
        if row.status != PARTIAL or "2 identical before/after images" not in row.evidence:
            failures.append(
                f"Tracee identical before/after expected PARTIAL, got {(row.status, row.evidence)!r}")

        write_tracee_map_inline([(579, 416), (482, 353)])
        (tev / "details/loadtime-workdirs/loadtime_3_1/input.step.0.bin").write_bytes(b"\x00" * 8)
        row = tracee_row()
        if row.status != PARTIAL or "1 length mismatches" not in row.evidence:
            failures.append(
                f"Tracee bytecode length mismatch expected PARTIAL, got {(row.status, row.evidence)!r}")

        # Tetragon retained bytecode row: same shared derivation over the
        # tetragon report stream, including a multi-site program.
        gev = root / TETRAGON_MAP_INLINE_EVIDENCE_DIR

        def write_tetragon_map_inline(instances: list[tuple[int, int, int]],
                                      bytecode: str = "differing") -> None:
            if gev.exists():
                import shutil as _sh
                _sh.rmtree(gev)
            (gev / "details/apps").mkdir(parents=True)
            (gev / "details/loadtime-reports").mkdir(parents=True)
            lines = []
            for index, (before, after, sites) in enumerate(instances):
                wd = gev / f"details/loadtime-workdirs/loadtime_4_{index}"
                wd.mkdir(parents=True)
                lines.append(json.dumps({
                    "prog_name": f"prog_{index}",
                    "workdir": f"/run/details/loadtime-workdirs/loadtime_4_{index}",
                    "report": {"insn_count_before": before,
                               "insn_count_after": after, "sites_applied": sites}}))
                (wd / "report.0.json").write_text(json.dumps({
                    "insn_count_before": before, "insn_count_after": after,
                    "sites_applied": sites}))
                (wd / "input.step.0.bin").write_bytes(b"\x00" * (8 * before))
                out = (b"\x00" * (8 * before) if bytecode == "identical"
                       else b"\x00" * (8 * after))
                (wd / "output.next.0.bin").write_bytes(out)
            (gev / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": "x86_kvm_corpus",
                "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
            (gev / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            (gev / "details/apps/tetragon__observer.json").write_text(json.dumps({
                "status": "ok", "error": ""}))
            (gev / "details/loadtime-reports/tetragon__observer.jsonl").write_text(
                "\n".join(lines) + "\n")
            (gev / "receipt.json").write_text(json.dumps({
                "files_sha256": {"metadata.json": file_sha256(gev / "metadata.json")}}))

        def tetragon_row() -> Row:
            return tetragon_retained_bytecode_rows(root)[0]

        write_tetragon_map_inline([(400, 300, 1), (200, 120, 2), (100, 90, 3)])
        row = tetragon_row()
        if row.status != PASS or "6 applied sites" not in row.evidence:
            failures.append(
                f"valid Tetragon retained bytecode expected PASS/6 sites, got {(row.status, row.evidence)!r}")
        if "insn 700->510 (-190)" not in row.evidence:
            failures.append(
                f"Tetragon retained bytecode expected aggregated insn delta, got {row.evidence!r}")

        write_tetragon_map_inline([(400, 300, 1), (200, 120, 2), (100, 90, 3)],
                                  bytecode="identical")
        row = tetragon_row()
        if row.status != PARTIAL or "3 identical before/after images" not in row.evidence:
            failures.append(
                f"Tetragon identical before/after expected PARTIAL, got {(row.status, row.evidence)!r}")

        write_tetragon_map_inline([(400, 300, 1), (200, 120, 2), (100, 90, 3)])
        (gev / "details/loadtime-workdirs/loadtime_4_2/input.step.0.bin").write_bytes(b"\x00" * 8)
        row = tetragon_row()
        if row.status != PARTIAL or "1 length mismatches" not in row.evidence:
            failures.append(
                f"Tetragon bytecode length mismatch expected PARTIAL, got {(row.status, row.evidence)!r}")

        # Katran arm64 retained bytecode row: identical derivation over an
        # arm64_qemu_corpus run, proving the accepted-run-type set is honoured.
        kev = root / KATRAN_ARM64_MAP_INLINE_EVIDENCE_DIR

        def write_katran_arm64_map_inline(instances: list[tuple[int, int]],
                                          bytecode: str = "differing",
                                          run_type: str = "arm64_qemu_corpus") -> None:
            if kev.exists():
                import shutil as _sh
                _sh.rmtree(kev)
            (kev / "details/apps").mkdir(parents=True)
            (kev / "details/loadtime-reports").mkdir(parents=True)
            lines = []
            for index, (before, after) in enumerate(instances):
                wd = kev / f"details/loadtime-workdirs/loadtime_5_{index}"
                wd.mkdir(parents=True)
                lines.append(json.dumps({
                    "prog_name": f"prog_{index}",
                    "workdir": f"/run/details/loadtime-workdirs/loadtime_5_{index}",
                    "report": {"insn_count_before": before,
                               "insn_count_after": after, "sites_applied": 16}}))
                (wd / "report.0.json").write_text(json.dumps({
                    "insn_count_before": before, "insn_count_after": after,
                    "sites_applied": 16}))
                (wd / "input.step.0.bin").write_bytes(b"\x00" * (8 * before))
                out = (b"\x00" * (8 * before) if bytecode == "identical"
                       else b"\x00" * (8 * after))
                (wd / "output.next.0.bin").write_bytes(out)
            (kev / "metadata.json").write_text(json.dumps({
                "status": "completed", "run_type": run_type,
                "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
            (kev / "details/progress.json").write_text(json.dumps({"status": "completed"}))
            (kev / "details/apps/katran.json").write_text(json.dumps({
                "status": "ok", "error": ""}))
            (kev / "details/loadtime-reports/katran.jsonl").write_text(
                "\n".join(lines) + "\n")
            (kev / "receipt.json").write_text(json.dumps({
                "files_sha256": {"metadata.json": file_sha256(kev / "metadata.json")}}))

        def katran_arm64_row() -> Row:
            return katran_arm64_retained_bytecode_rows(root)[0]

        write_katran_arm64_map_inline([(2542, 2272)])
        row = katran_arm64_row()
        if row.status != PASS or "16 applied sites" not in row.evidence:
            failures.append(
                f"arm64 Katran retained bytecode expected PASS/16 sites, got {(row.status, row.evidence)!r}")
        if "insn 2542->2272 (-270)" not in row.evidence:
            failures.append(
                f"arm64 Katran retained bytecode expected aggregated insn delta, got {row.evidence!r}")

        write_katran_arm64_map_inline([(2542, 2272)], run_type="x86_kvm_corpus")
        row = katran_arm64_row()
        if row.status != PASS:
            failures.append(
                f"arm64 Katran row must also accept x86_kvm_corpus, got {(row.status, row.evidence)!r}")

        write_katran_arm64_map_inline([(2542, 2272)])
        (kev / "metadata.json").write_text(json.dumps({
            "status": "completed", "run_type": "aws_arm64_corpus",
            "suite": "corpus", "samples": 1, "workload_seconds": 30.0}))
        row = katran_arm64_row()
        if row.status != PARTIAL or "run status valid=False" not in row.evidence:
            failures.append(
                f"arm64 Katran row must reject an unknown run type, got {(row.status, row.evidence)!r}")

        # Wide throughput extractor: the May batch's three stdout shapes must
        # each yield a scalar, otherwise the cilium/otel/stress-ng apps would
        # silently read as zero and drop out of the causality rows.
        if workload_throughput(
                {"stdout": "\n2000000pps 1000Mb/sec (1000000000bps) errors: 0\n"}) != 2000000.0:
            failures.append("pktgen pps workload must yield its packet rate")
        if workload_throughput(
                {"stdout": "Requests/sec:    149.20\n"}) != 149.20:
            failures.append("wrk workload must yield its Requests/sec rate")
        if workload_throughput({"components": [{"stdout": (
                "stress-ng: metrc: [123] cpu  118837.0  60.0  59.99  0.0  1980.6  1980.94\n")}]}) != 118837.0:
            failures.append("nested stress-ng component must yield bogo_ops_total")

        # Controlled map_inline causality rows: the same derivation over
        # synthetic matched runs, driven through the injectable app list. The
        # declared constants are the frozen May-batch values, so a synthetic
        # run that reproduces them must PASS and any gate mutation must flip it.
        capp = "causality__app.json"

        def write_causality_run(run: str, *, baseline_pps: int = 1000,
                                post_pps: int = 1000, passes=("map_inline",),
                                samples: int = 3, bpf_stats: bool = True,
                                workload_seconds: float = 60.0,
                                status: str = "completed", app_status: str = "ok") -> str:
            base = root / run
            (base / "details/apps").mkdir(parents=True, exist_ok=True)
            (base / "metadata.json").write_text(json.dumps({
                "status": status, "run_type": "x86_kvm_corpus", "suite": "corpus",
                "samples": samples, "workload_seconds": workload_seconds,
                "bpf_stats": bpf_stats,
                "config": {"enabled_passes": list(passes)}}))
            (base / "details/progress.json").write_text(json.dumps({"status": status}))
            (base / "details/apps" / capp).write_text(json.dumps({
                "status": app_status, "error": "",
                "baseline": {"workloads": [{"stdout": f"\n{baseline_pps}pps 1000Mb/sec (1000000000bps) errors: 0\n"}] * 3},
                "post_rejit": {"workloads": [{"stdout": f"\n{post_pps}pps 1000Mb/sec (1000000000bps) errors: 0\n"}] * 3}}))
            return run

        mi_run = write_causality_run("mi")
        ctl_a = write_causality_run("ctl_a", passes=())
        ctl_b = write_causality_run("ctl_b", passes=())
        causal_apps = (("synthetic", mi_run, (ctl_a, ctl_b), capp),)
        causal_declared = {"synthetic": ("1.0000", "1.0000")}

        def causality_rows() -> list[Row]:
            return map_inline_causality_rows(root, causal_apps, causal_declared, "1.0000")

        def causality_row() -> Row:
            return causality_rows()[0]

        rows = causality_rows()
        if rows[0].status != PASS or "control-corrected=1.000000x" not in rows[0].evidence:
            failures.append(
                f"valid matched causality expected PASS/1.000000x, got {(rows[0].status, rows[0].evidence)!r}")
        if len(rows) != 2 or rows[1].status != PASS or "geomean of per-app control-corrected" not in rows[1].evidence:
            failures.append(
                f"single-app causality must pool to a PASS geomean row, got {rows[1:]!r}")

        # A drifting post-phase must not silently re-baseline: the ratio moves,
        # the declared constant does not, so the row degrades to PARTIAL.
        write_causality_run("mi", post_pps=900)
        row = causality_row()
        if row.status != PARTIAL or "0.900000x; no-pass controls" not in row.evidence:
            failures.append(
                f"drifted causality expected PARTIAL/0.9x, got {(row.status, row.evidence)!r}")
        write_causality_run("mi")
        if causality_row().status != PASS:
            failures.append("restored causality run must return to PASS")

        # The map_inline run must be exactly the `map_inline` policy and 3
        # samples/60 s; a no-pass or short run is not the measured arm.
        write_causality_run("mi", passes=("kop",))
        row = causality_row()
        if row.status != UNAVAILABLE or "matched map_inline run" not in row.evidence:
            failures.append(
                f"non-map_inline causality run expected UNAVAILABLE, got {(row.status, row.evidence)!r}")
        write_causality_run("mi", samples=2)
        if causality_row().status != UNAVAILABLE:
            failures.append("causality run with samples!=3 must be UNAVAILABLE")
        # The measured arm is only comparable to the controls at the identical
        # 60 s workload duration and with BPF stats enabled, so a run at another
        # duration or without bpf_stats must not be admitted as the arm.
        write_causality_run("mi", workload_seconds=30.0)
        if causality_row().status != UNAVAILABLE:
            failures.append("causality run at a different duration must be UNAVAILABLE")
        write_causality_run("mi", bpf_stats=False)
        if causality_row().status != UNAVAILABLE:
            failures.append("causality run without bpf_stats must be UNAVAILABLE")
        write_causality_run("mi")
        # The null must itself be a no-pass run; controls carrying the pass
        # would make the drift correction absorb the effect it is meant to remove.
        write_causality_run("ctl_a", passes=("map_inline",), post_pps=900)
        write_causality_run("ctl_b", passes=("map_inline",), post_pps=900)
        if causality_row().status != UNAVAILABLE:
            failures.append("causality controls must be no-pass loadtime runs")
        write_causality_run("ctl_a", passes=())
        write_causality_run("ctl_b", passes=())
        if causality_row().status != PASS:
            failures.append("restored causality controls must return to PASS")

        # Fresh causality triplets: one map_inline run carrying both retained
        # per-step bytecode and two matched no-pass controls, for Katran and
        # now Cilium, which share the generic row builder. The synthetic pktgen
        # workload splits each phase into two components so the fixture
        # exercises the summed-component extractor; the injected declared
        # constants match the synthetic ratios, and every gate mutation must
        # flip the row off PASS. The Cilium case additionally asserts that the
        # app stem/report path are honored rather than hardcoded to Katran.
        causal_ev = KATRAN_FRESH_CAUSALITY_EVIDENCE_DIR
        causal_declared = ("1.0750", "1.0750")
        cilium_ev = CILIUM_FRESH_CAUSALITY_EVIDENCE_DIR
        cilium_declared = ("0.9000", "0.9000")
        tetragon_ev = TETRAGON_FRESH_CAUSALITY_EVIDENCE_DIR
        tetragon_declared = ("0.8000", "0.8000")

        def wl(total: int) -> dict:
            half = total // 2
            def comp(pps: int) -> dict:
                return {"stdout": f"\n{pps}pps 1000Mb/sec (1000000000bps) errors: 0\n"}
            return {"components": [comp(half), comp(total - half)]}

        def metrc_wl(total: int) -> dict:
            """A component-less stress-ng workload: the rate is its own stdout.

            `_rate_scalar` sums the metrc row's first numeric column (bogo
            ops), exactly as it does for the shipped May causality rows.
            """
            half = total // 2
            line = ("stress-ng: metrc: [1] cpu            {n}      60.00      1.00 "
                    "     0.50      1.00      1.00\n")
            return {"components": [],
                    "stdout": line.format(n=half) + line.format(n=total - half)}

        def write_fresh_causality(
            *, ev: str = causal_ev, stem: str = "katran",
            mi_post: int = 1075, mi_status: str = "completed",
            mi_passes=("map_inline",), app_status: str = "ok",
            mi_rejit: str = "ok", ctl_a_post: int = 1001, ctl_b_post: int = 999,
            ctl_a_passes=(), ctl_b_passes=(), ctl_rejit: str = "skipped",
            retain_bytecode: bool = True, receipt_hashes: bool = True,
            wl_factory=wl,
        ) -> None:
            base = root / ev
            import shutil
            if base.exists():
                shutil.rmtree(base)
            def write_dir(rel: str, *, post: int, passes, rejit: str,
                          status: str, app_st: str) -> None:
                d = base / rel
                (d / "details/apps").mkdir(parents=True, exist_ok=True)
                (d / "metadata.json").write_text(json.dumps({
                    "status": status, "run_type": "x86_kvm_corpus",
                    "suite": "corpus", "samples": 3, "workload_seconds": 60.0,
                    "bpf_stats": True, "config": {"enabled_passes": list(passes)}}))
                (d / "details/progress.json").write_text(json.dumps({"status": status}))
                (d / "details/apps" / f"{stem}.json").write_text(json.dumps({
                    "status": app_st, "error": "",
                    "rejit_result": {"mode": "loadtime", "status": rejit},
                    "baseline": {"workloads": [wl_factory(1000)] * 3},
                    "post_rejit": {"workloads": [wl_factory(post)] * 3}}))
            write_dir("", post=mi_post, passes=mi_passes, rejit=mi_rejit,
                      status=mi_status, app_st=app_status)
            write_dir("controls/nullA", post=ctl_a_post, passes=ctl_a_passes,
                      rejit=ctl_rejit, status="completed", app_st="ok")
            write_dir("controls/nullB", post=ctl_b_post, passes=ctl_b_passes,
                      rejit=ctl_rejit, status="completed", app_st="ok")
            rows = [
                {"prog_type": "xdp", "workdir": "/wd/loadtime_1_0",
                 "report": {"insn_count_before": 2542, "insn_count_after": 2272,
                            "sites_matched": 16, "sites_applied": 16}},
            ] + [
                {"prog_type": "socket_filter", "workdir": f"/wd/loadtime_1_{i}",
                 "report": {"insn_count_before": 2, "insn_count_after": 2,
                            "sites_matched": 0, "sites_applied": 0}}
                for i in range(1, 6)
            ]
            (base / "details/loadtime-reports").mkdir(parents=True, exist_ok=True)
            (base / "details/loadtime-reports" / f"{stem}.jsonl").write_text(
                "\n".join(json.dumps(r) for r in rows) + "\n")
            if retain_bytecode:
                wd = base / "details/loadtime-workdirs/loadtime_1_0"
                wd.mkdir(parents=True, exist_ok=True)
                (wd / "input.step.0.bin").write_bytes(b"\x01" * (8 * 2542))
                (wd / "output.next.0.bin").write_bytes(b"\x02" * (8 * 2272))
                (wd / "report.0.json").write_text(json.dumps(rows[0]["report"]))
            if receipt_hashes:
                files = {
                    str(p.relative_to(base)): file_sha256(p)
                    for p in sorted(base.rglob("*"))
                    if p.is_file() and p.name != "receipt.json"
                }
                (base / "receipt.json").write_text(json.dumps({"files_sha256": files}))
            else:
                (base / "receipt.json").write_text(json.dumps({"files_sha256": {}}))

        def fresh_row() -> Row:
            return katran_fresh_causality_rows(root, causal_ev, causal_declared)[0]

        def cilium_row() -> Row:
            return cilium_fresh_causality_rows(root, cilium_ev, cilium_declared)[0]

        def tetragon_row() -> Row:
            return tetragon_fresh_causality_rows(root, tetragon_ev, tetragon_declared)[0]

        write_fresh_causality()
        row = fresh_row()
        if row.status != PASS or "control-corrected=1.075000x" not in row.evidence:
            failures.append(
                f"valid fresh causality expected PASS/1.075000x, got {(row.status, row.evidence)!r}")
        write_fresh_causality(mi_post=1200)
        if fresh_row().status != PARTIAL:
            failures.append("fresh causality must degrade on throughput drift")
        write_fresh_causality(ctl_a_passes=("map_inline",))
        if fresh_row().status != PARTIAL:
            failures.append("fresh causality controls must be no-pass runs")
        write_fresh_causality(mi_passes=("kop",))
        if fresh_row().status != UNAVAILABLE and fresh_row().status != PARTIAL:
            failures.append("fresh causality must require the map_inline pass")
        write_fresh_causality(retain_bytecode=False)
        if fresh_row().status != PARTIAL:
            failures.append("fresh causality must require retained bytecode")
        write_fresh_causality(receipt_hashes=False)
        if fresh_row().status != PARTIAL:
            failures.append("fresh causality must require receipt file hashes")
        write_fresh_causality()
        if fresh_row().status != PASS:
            failures.append("restored fresh causality must return to PASS")

        # The Cilium row reuses the generic builder with its own app stem and
        # report path: a Cilium triplet must not be satisfied by Katran files.
        write_fresh_causality(ev=cilium_ev, stem="cilium__agent",
                              mi_post=900, ctl_a_post=1000, ctl_b_post=1000)
        row = cilium_row()
        if row.status != PASS or "control-corrected=0.900000x" not in row.evidence:
            failures.append(
                f"valid Cilium fresh causality expected PASS/0.900000x, got {(row.status, row.evidence)!r}")
        if cilium_ev not in row.evidence:
            failures.append("Cilium fresh causality must report its own evidence dir")
        write_fresh_causality(ev=cilium_ev, stem="katran",
                              mi_post=900, ctl_a_post=1000, ctl_b_post=1000)
        if cilium_row().status != UNAVAILABLE:
            failures.append("Cilium fresh causality must require the Cilium app record")
        write_fresh_causality(ev=cilium_ev, stem="cilium__agent",
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        if cilium_row().status != PARTIAL:
            failures.append("Cilium fresh causality must degrade on constant drift")
        write_fresh_causality(ev=cilium_ev, stem="cilium__agent",
                              mi_post=900, ctl_a_post=1000, ctl_b_post=1000)
        if cilium_row().status != PASS:
            failures.append("restored Cilium fresh causality must return to PASS")

        # The Tetragon row exercises the component-less workload shape: its
        # rate lives in the workload's own stdout as `stress-ng: metrc:`
        # bogo-ops, which `_summed_pktgen_throughput` reaches only through its
        # workload-level fallback. A pktgen-component-only extractor would
        # return None here and degrade the row to UNAVAILABLE.
        write_fresh_causality(ev=tetragon_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_post=800,
                              ctl_a_post=1000, ctl_b_post=1000)
        row = tetragon_row()
        if row.status != PASS or "control-corrected=0.800000x" not in row.evidence:
            failures.append(
                f"valid Tetragon fresh causality expected PASS/0.800000x, got {(row.status, row.evidence)!r}")
        if "stress-ng metrc bogo-ops" not in row.evidence:
            failures.append("Tetragon fresh causality must name its rate shape")
        write_fresh_causality(ev=tetragon_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_post=820,
                              ctl_a_post=1000, ctl_b_post=1000)
        if tetragon_row().status != PARTIAL:
            failures.append("Tetragon fresh causality must degrade on drift")
        write_fresh_causality(ev=tetragon_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_post=800,
                              ctl_a_post=1000, ctl_b_post=1000)
        if tetragon_row().status != PASS:
            failures.append("restored Tetragon fresh causality must return to PASS")

        # The Tracee row is the same component-less `metrc` shape as Tetragon,
        # so the new-class coinage is already covered; this case asserts that
        # the row is gated on Tracee's own app stem/report path rather than
        # inheriting another app's files, and that it names its rate shape.
        tracee_ev = TRACEE_FRESH_CAUSALITY_EVIDENCE_DIR
        tracee_declared = ("0.7000", "0.7000")

        def tracee_row() -> Row:
            return tracee_fresh_causality_rows(root, tracee_ev, tracee_declared)[0]

        write_fresh_causality(ev=tracee_ev, stem="tracee__monitor",
                              wl_factory=metrc_wl, mi_post=700,
                              ctl_a_post=1000, ctl_b_post=1000)
        row = tracee_row()
        if row.status != PASS or "control-corrected=0.700000x" not in row.evidence:
            failures.append(
                f"valid Tracee fresh causality expected PASS/0.700000x, got {(row.status, row.evidence)!r}")
        if "stress-ng metrc bogo-ops" not in row.evidence:
            failures.append("Tracee fresh causality must name its rate shape")
        write_fresh_causality(ev=tracee_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_post=700,
                              ctl_a_post=1000, ctl_b_post=1000)
        if tracee_row().status != UNAVAILABLE:
            failures.append("Tracee fresh causality must require the Tracee app record")
        write_fresh_causality(ev=tracee_ev, stem="tracee__monitor",
                              wl_factory=metrc_wl, mi_post=700,
                              ctl_a_post=1000, ctl_b_post=1000)
        if tracee_row().status != PASS:
            failures.append("restored Tracee fresh causality must return to PASS")

        # The BCC row is likewise the component-less `metrc` shape; this case
        # asserts the fifth app is gated on its own app stem/report path, so a
        # BCC triplet cannot be satisfied by any other app's files.
        bcc_ev = BCC_FRESH_CAUSALITY_EVIDENCE_DIR
        bcc_declared = ("0.8500", "0.8500")

        def bcc_row() -> Row:
            return bcc_fresh_causality_rows(root, bcc_ev, bcc_declared)[0]

        write_fresh_causality(ev=bcc_ev, stem="bcc__set",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        row = bcc_row()
        if row.status != PASS or "control-corrected=0.850000x" not in row.evidence:
            failures.append(
                f"valid BCC fresh causality expected PASS/0.850000x, got {(row.status, row.evidence)!r}")
        if "stress-ng metrc bogo-ops" not in row.evidence:
            failures.append("BCC fresh causality must name its rate shape")
        write_fresh_causality(ev=bcc_ev, stem="tracee__monitor",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        if bcc_row().status != UNAVAILABLE:
            failures.append("BCC fresh causality must require the BCC app record")
        write_fresh_causality(ev=bcc_ev, stem="bcc__set",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        if bcc_row().status != PASS:
            failures.append("restored BCC fresh causality must return to PASS")

        # The otelcol row is the sixth app and the same `metrc` shape; this
        # case asserts it is gated on its own app stem/report path, so its
        # triplet cannot be satisfied by any other app's files.
        otelcol_ev = OTELCOL_FRESH_CAUSALITY_EVIDENCE_DIR
        otelcol_declared = ("0.8500", "0.8500")

        def otelcol_row() -> Row:
            return otelcol_fresh_causality_rows(root, otelcol_ev, otelcol_declared)[0]

        write_fresh_causality(ev=otelcol_ev, stem="otelcol-ebpf-profiler__profiling",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        row = otelcol_row()
        if row.status != PASS or "control-corrected=0.850000x" not in row.evidence:
            failures.append(
                f"valid otelcol fresh causality expected PASS/0.850000x, got {(row.status, row.evidence)!r}")
        if "stress-ng metrc bogo-ops" not in row.evidence:
            failures.append("otelcol fresh causality must name its rate shape")
        write_fresh_causality(ev=otelcol_ev, stem="bcc__set",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        if otelcol_row().status != UNAVAILABLE:
            failures.append("otelcol fresh causality must require the otelcol app record")
        write_fresh_causality(ev=otelcol_ev, stem="otelcol-ebpf-profiler__profiling",
                              wl_factory=metrc_wl, mi_post=850,
                              ctl_a_post=1000, ctl_b_post=1000)
        if otelcol_row().status != PASS:
            failures.append("restored otelcol fresh causality must return to PASS")


        # The wide_mem Tetragon row exercises the parameterized pass gate: the
        # same triplet builder must accept a `wide_mem` enabled_passes list and
        # reject a `map_inline` one, so a wide_mem triplet cannot be satisfied
        # by a map_inline run's records.
        wm_ev = WIDE_MEM_TETRAGON_CAUSALITY_EVIDENCE_DIR
        wm_declared = ("1.0000", "1.0000")

        def wide_mem_row() -> Row:
            return wide_mem_tetragon_causality_rows(root, wm_ev, wm_declared)[0]

        write_fresh_causality(ev=wm_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_passes=("wide_mem",),
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        row = wide_mem_row()
        if row.status != PASS or "wide_mem median" not in row.evidence:
            failures.append(
                f"valid wide_mem causality expected PASS/wide_mem, got {(row.status, row.evidence)!r}")
        if "control-corrected=1.000000x" not in row.evidence:
            failures.append("wide_mem causality must report its corrected ratio")
        write_fresh_causality(ev=wm_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_passes=("map_inline",),
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        if wide_mem_row().status != PARTIAL:
            failures.append("wide_mem causality must reject a map_inline run")
        write_fresh_causality(ev=wm_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_passes=("wide_mem",),
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        if wide_mem_row().status != PASS:
            failures.append("restored wide_mem causality must return to PASS")
        # The row must be gated on Tetragon's own app stem, not on whatever
        # record the evidence dir happens to hold.
        write_fresh_causality(ev=wm_ev, stem="katran",
                              wl_factory=metrc_wl, mi_passes=("wide_mem",),
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        if wide_mem_row().status != UNAVAILABLE:
            failures.append("wide_mem causality must require the tetragon app record")
        write_fresh_causality(ev=wm_ev, stem="tetragon__observer",
                              wl_factory=metrc_wl, mi_passes=("wide_mem",),
                              mi_post=1000, ctl_a_post=1000, ctl_b_post=1000)
        if wide_mem_row().status != PASS:
            failures.append("restored wide_mem causality must return to PASS")
    if failures:
        for f in failures:
            print("SELF-TEST FAIL:", f, file=sys.stderr)
        return 1
    print("self-test: OK (13 evidence classes)")
    return 0


def main() -> int:
    args = [a for a in sys.argv[1:]]
    if "--self-test" in args:
        return self_test()
    root = Path(args[0]).resolve() if args else Path(__file__).resolve().parents[2]
    render(build_rows(root), root)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
