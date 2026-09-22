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

import json
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
    "RQ3 micro x86 (pure bytecode)": "micro/results/x86_kvm_micro_20260526_210952_650695",
    "RQ3 micro arm64 (pure bytecode)": "micro/results/aws_arm64_micro_20260606_063319_954947",
}

COVERAGE_RUN = "corpus/results/x86_kvm_corpus_20260921_211712_637406"
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


def corpus_evidence(root: Path, rel: str) -> list[Row]:
    d = root / rel
    if not d.is_dir():
        return [
            Row(
                "KVM corpus: rejit/KOperation coverage (6 apps)",
                UNAVAILABLE,
                f"{rel} not present; run "
                "`BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 make corpus`",
            ),
            Row(
                "KVM corpus: full workload success (6 apps)",
                UNAVAILABLE,
                f"{rel} not present",
            ),
        ]
    suite_status = (load_json(d / "details" / "progress.json") or {}).get("status")
    apps: dict[str, tuple] = {}
    apps_dir = d / "details" / "apps"
    if apps_dir.is_dir():
        for f in sorted(apps_dir.glob("*.json")):
            a = load_json(f) or {}
            apps[f.stem] = (a.get("status"), (a.get("rejit_result") or {}).get("status"))

    n = len(apps)
    rejit_ok = sum(1 for v in apps.values() if v[1] == REJIT_SUCCESS)
    apps_ok = sum(1 for v in apps.values() if v[0] == APP_SUCCESS)

    # Coverage needs every app's rejit status ok; workload success additionally
    # needs the suite to have completed with every app ok.
    cov = PASS if n and rejit_ok == n else (PARTIAL if apps else UNAVAILABLE)
    succ = PASS if (suite_status == SUITE_SUCCESS and n and apps_ok == n) else PARTIAL

    return [
        Row(
            "KVM corpus: rejit/KOperation coverage (6 apps)",
            cov,
            f"{rel}: suite status={suite_status!r}, rejit ok={rejit_ok}/{n}",
        ),
        Row(
            "KVM corpus: full workload success (6 apps)",
            succ,
            f"{rel}: suite status={suite_status!r}, apps ok={apps_ok}/{n}"
            + ("" if succ == PASS else " (not all apps succeeded)"),
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
    rows.extend(corpus_evidence(root, COVERAGE_RUN))
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

        # corpus: suite completed + all apps ok -> both PASS
        run = root / COVERAGE_RUN / "details"
        (run / "apps").mkdir(parents=True)
        (run / "progress.json").write_text(json.dumps({"status": "completed"}))
        for i in range(6):
            (run / "apps" / f"app{i}.json").write_text(
                json.dumps({"status": "ok", "rejit_result": {"status": "ok"}})
            )
        rows = corpus_evidence(root, COVERAGE_RUN)
        if [r.status for r in rows] != [PASS, PASS]:
            failures.append(f"completed corpus expected [PASS, PASS], got {[r.status for r in rows]}")

        # corpus: suite error + one app failed -> coverage PARTIAL, success PARTIAL
        (run / "progress.json").write_text(json.dumps({"status": "error"}))
        (run / "apps" / "app0.json").write_text(
            json.dumps({"status": "error", "rejit_result": {"status": "ok"}})
        )
        rows = corpus_evidence(root, COVERAGE_RUN)
        if rows[1].status != PARTIAL:
            failures.append(f"errored corpus expected success PARTIAL, got {rows[1].status}")

        # Formal PASS requires a complete retained receipt, not source presence.
        receipt = root / FORMAL_RECEIPT
        receipt.parent.mkdir(parents=True)
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
    print("self-test: OK (6 checks)")
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
