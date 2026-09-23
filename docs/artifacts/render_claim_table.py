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

MICRO_RESULTS = {
    "RQ1 micro x86 (run)": "micro/results/x86_kvm_micro_20260519_114214_364050",
    "RQ1 micro x86 (stock baseline)": "micro/results/x86_kvm_micro_20260526_210351_224315",
    "RQ1 micro arm64": "micro/results/aws_arm64_micro_20260606_001225_821028",
    "Section 3 pure-bytecode x86": "micro/results/x86_kvm_micro_20260526_210952_650695",
    "Section 3 pure-bytecode arm64": "micro/results/aws_arm64_micro_20260606_063319_954947",
    "RQ1 x86 historical load-time run": "micro/results/x86_kvm_micro_20260514_031744_210343",
    "RQ1 x86 historical 62-case population": "micro/results/x86_kvm_micro_20260429_035938_203074",
}

COVERAGE_RUN = "docs/artifacts/evidence/kvm-six-app-coverage"
SMOKE_RUN = "docs/artifacts/evidence/kvm-katran-smoke"
SMOKE_COMMAND = (
    "BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 "
    "TIMEOUT=3000 make corpus"
)
FORMAL_RECEIPT = "docs/artifacts/evidence/formal-check.json"


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


def kop_applied_in_sample(sample: dict) -> int:
    count = 0
    for program in ((sample.get("rejit_result") or {}).get("per_program") or {}).values():
        for result in program.get("passes") or []:
            summary = result.get("bpfopt_summary") or {}
            if summary.get("pass") == "kop":
                count += int(summary.get("sites_applied") or 0)
    return count


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
    load_rel = MICRO_RESULTS["RQ1 x86 historical load-time run"]
    historical = load_json(root / load_rel / "details/result.json")
    population_rel = MICRO_RESULTS["RQ1 x86 historical 62-case population"]
    population = load_json(root / population_rel / "details/result.json")
    if isinstance(historical, dict) and isinstance(population, dict):
        kernel_load = median_object_load_ns(historical, "kernel")
        rejit_load = median_object_load_ns(historical, "kernel_rejit")
        population_names = {
            b["name"] for b in population.get("benchmarks") or []
            if isinstance(b, dict) and isinstance(b.get("name"), str)
        }
        names = sorted(kernel_load.keys() & rejit_load.keys() & population_names)
        if len(names) == 62:
            value = math.exp(sum(math.log(rejit_load[n] / kernel_load[n]) for n in names) / len(names))
            provenance_ok = micro_run_provenance_ok(root, load_rel, "x86_kvm_micro", "x86_64")
            rows.append(Row(
                "RQ1 x86 62-case object-load overhead (paper 0.99x)",
                PARTIAL,
                f"May14 ReJIT run restricted to Apr29 62-name set (excludes katran_like): {value:.6f}x over 62; "
                f"rounds to {value:.2f}x, not paper 0.99x; "
                f"run metadata/progress valid={provenance_ok}; "
                f"{load_rel}/details/result.json; population={population_rel}/details/result.json",
            ))
        else:
            rows.append(Row("RQ1 x86 62-case object-load overhead (paper 0.99x)",
                            UNAVAILABLE, f"historical Apr29-set matched cases={len(names)}, expected 62"))
    else:
        rows.append(Row("RQ1 x86 62-case object-load overhead (paper 0.99x)",
                        UNAVAILABLE, f"historical ReJIT or population result.json missing: {load_rel}, {population_rel}"))
    return rows


CILIUM_RQ2 = "corpus/results/x86_kvm_corpus_20260604_100557_313063"
CILIUM_RQ4_ON = "corpus/results/x86_kvm_corpus_20260529_033517_489159"
CILIUM_RQ4_OFF = "corpus/results/x86_kvm_corpus_20260529_040554_604387"
PPS = re.compile(r"\n\s*(\d+)pps\s+[0-9]+Mb/sec .* errors: (\d+)")


def cilium_app(
    root: Path, run: str, *, passes: list[str] | None = None,
    bpf_stats: bool | None = None, allow_suite_error: bool = False,
    workload_seconds: float = 180.0,
) -> dict | None:
    path = root / run
    metadata = load_json(path / "metadata.json") or {}
    progress = load_json(path / "details/progress.json") or {}
    app = load_json(path / "details/apps/cilium__agent.json")
    allowed = {"completed", "error"} if allow_suite_error else {"completed"}
    if (progress.get("status") not in allowed
            or metadata.get("status") not in allowed
            or metadata.get("run_type") != "x86_kvm_corpus"
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
    rows.append(Row("RQ2 Cilium x86 applied sites (4086)", UNAVAILABLE,
                    "original per-pass loadtime report is not retained; app JSON alone cannot prove site count"))

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
    rows.append(Row("RQ4 native loader counts (113/22/89)", UNAVAILABLE,
                    "loader match/replacement raw logs are not retained in the selected Cilium JSON"))
    full_run = "corpus/results/x86_kvm_corpus_20260605_145112_835705"
    limited_run = "corpus/results/x86_kvm_corpus_20260605_160715_129437"
    for label, run, policy, claimed in (
        ("RQ3 Cilium full policy throughput (1.114x)", full_run, "kop_all_prefetch", "1.114"),
        ("RQ3 Cilium no-bulk/no-prefetch throughput (0.999x)", limited_run,
         "kop_all_no_bulk_no_prefetch", "0.999"),
    ):
        app = cilium_app(root, run, passes=[policy], bpf_stats=True,
                         allow_suite_error=True, workload_seconds=30.0)
        baseline = phase_pps(app, "baseline") if app else []
        post = phase_pps(app, "post_rejit") if app else []
        if len(baseline) == len(post) == 3 and min(baseline + post) > 0:
            ratio = statistics.mean(post) / statistics.mean(baseline)
            rows.append(Row(label, PASS if f"{ratio:.3f}" == claimed else PARTIAL,
                            f"post/baseline mean pps={ratio:.6f}x, 3+3 Cilium samples; "
                            f"{run}/details/apps/cilium__agent.json; full suite status=error"))
        else:
            rows.append(Row(label, UNAVAILABLE, f"verified Cilium samples missing: {run}"))
    rows.append(Row("RQ3 prose: 3512 sites paired with 1.114x", UNAVAILABLE,
                    "raw 1.114x is full policy, while no-bulk/no-prefetch is 0.999x; "
                    "the per-pass site reports are not retained, so the prose pairing is unverified"))
    return rows


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

def formal_evidence(receipt_path: Path) -> tuple[str, str]:
    """Validate a retained receipt from the complete formal-check command."""
    data = load_json(receipt_path)
    if not isinstance(data, dict):
        return UNAVAILABLE, f"{receipt_path} missing or unparsable"
    checks = data.get("checks") or {}
    passed = (
        data.get("command") == "make -C native-sim/formal check"
        and data.get("exit_code") == 0
        and checks.get("generated_contract_drift") is True
        and checks.get("lean_modules") is True
        and checks.get("host_cross_checks") == 25
    )
    detail = (
        f"{receipt_path}: exit_code={data.get('exit_code')!r}, "
        f"generated_contract_drift={checks.get('generated_contract_drift')!r}, "
        f"lean_modules={checks.get('lean_modules')!r}, "
        f"host_cross_checks={checks.get('host_cross_checks')!r}"
    )
    return (PASS if passed else PARTIAL), detail


def build_rows(root: Path) -> list[Row]:
    rows: list[Row] = []
    for label, rel in MICRO_RESULTS.items():
        st, prov = micro_evidence(root / rel / "details" / "result.json")
        rows.append(Row(label, st, prov))
    rows.extend(micro_claim_rows(root))
    rows.extend(cilium_claim_rows(root))
    rows.extend(corpus_evidence(
        root, COVERAGE_RUN, expected_apps=6, claim_label="6 apps"
    ))
    rows.extend(corpus_evidence(
        root,
        SMOKE_RUN,
        expected_apps=1,
        claim_label="Katran smoke",
        required_command=SMOKE_COMMAND,
    ))
    st, prov = formal_evidence(root / FORMAL_RECEIPT)
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

        # Formal PASS requires a complete retained receipt, not source presence.
        receipt = root / FORMAL_RECEIPT
        receipt.parent.mkdir(parents=True, exist_ok=True)
        receipt.write_text(json.dumps({
            "command": "make -C native-sim/formal check",
            "exit_code": 0,
            "checks": {
                "generated_contract_drift": True,
                "lean_modules": True,
                "host_cross_checks": 25,
            },
        }))
        st, _ = formal_evidence(receipt)
        if st != PASS:
            failures.append(f"valid formal receipt expected PASS, got {st}")
        receipt.write_text(json.dumps({"command": "make -C native-sim/formal check", "exit_code": 1}))
        st, _ = formal_evidence(receipt)
        if st != PARTIAL:
            failures.append(f"failed formal receipt expected PARTIAL, got {st}")

    if failures:
        for f in failures:
            print("SELF-TEST FAIL:", f, file=sys.stderr)
        return 1
    print("self-test: OK (8 evidence classes)")
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
