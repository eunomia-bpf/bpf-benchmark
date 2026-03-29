from __future__ import annotations

import math
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs.results import summarize_corpus_batch_results


def _ok_invocation(exec_ns: int | None = None) -> dict:
    sample = {}
    if exec_ns is not None:
        sample["exec_ns"] = exec_ns
    return {"ok": True, "sample": sample}


def test_summarize_corpus_batch_results_headline_exec_geomean_is_applied_only() -> None:
    program_records = [
        {
            "repo": "demo",
            "canonical_object_name": "demo:obj1",
            "baseline_compile": {"ok": True, "sample": {"jited_prog_len": 100}},
            "rejit_compile": {"ok": True, "sample": {"jited_prog_len": 90, "rejit": {}}},
            "baseline_run": _ok_invocation(exec_ns=200),
            "rejit_run": _ok_invocation(exec_ns=100),
            "compile_passes_applied": ["p1"],
            "run_passes_applied": [],
            "applied_passes": ["p1"],
            "size_ratio": 100 / 90,
            "size_delta_pct": -10.0,
            "speedup_ratio": 2.0,
            "record_error": None,
            "comparison_exclusion_reason": None,
        },
        {
            "repo": "demo",
            "canonical_object_name": "demo:obj2",
            "baseline_compile": {"ok": True, "sample": {"jited_prog_len": 100}},
            "rejit_compile": {"ok": True, "sample": {"jited_prog_len": 80, "rejit": {}}},
            "baseline_run": _ok_invocation(exec_ns=400),
            "rejit_run": _ok_invocation(exec_ns=100),
            "compile_passes_applied": [],
            "run_passes_applied": [],
            "applied_passes": [],
            "size_ratio": 1.25,
            "size_delta_pct": -20.0,
            "speedup_ratio": 4.0,
            "record_error": None,
            "comparison_exclusion_reason": None,
        },
        {
            "repo": "demo",
            "canonical_object_name": "demo:obj3",
            "baseline_compile": {"ok": True, "sample": {"jited_prog_len": 100}},
            "rejit_compile": {"ok": True, "sample": {"jited_prog_len": 100, "rejit": {}}},
            "baseline_run": {"ok": True, "sample": {"exec_ns": 0, "result": 0}},
            "rejit_run": {"ok": True, "sample": {"exec_ns": 0, "result": 0}},
            "compile_passes_applied": [],
            "run_passes_applied": [],
            "applied_passes": [],
            "size_ratio": 1.0,
            "size_delta_pct": 0.0,
            "speedup_ratio": None,
            "record_error": None,
            "comparison_exclusion_reason": "app_native reported exec_ns=0 in baseline and REJIT",
        },
    ]

    summary = summarize_corpus_batch_results(program_records, [], effective_mode="vm")

    assert summary["measured_pairs"] == 3
    assert summary["comparable_pairs"] == 2
    assert summary["applied_comparable_pairs"] == 1
    assert math.isclose(summary["exec_ratio_geomean"], 2.0)
    assert math.isclose(summary["all_exec_ratio_geomean"], math.sqrt(8.0))
    assert summary["comparison_exclusion_reasons"] == {
        "app_native reported exec_ns=0 in baseline and REJIT": 1
    }

    repo_row = summary["by_repo"][0]
    assert repo_row["repo"] == "demo"
    assert repo_row["measured_pairs"] == 3
    assert repo_row["comparable_pairs"] == 2
    assert repo_row["applied_comparable_pairs"] == 1
    assert math.isclose(repo_row["exec_ratio_geomean"], 2.0)
    assert math.isclose(repo_row["all_exec_ratio_geomean"], math.sqrt(8.0))
