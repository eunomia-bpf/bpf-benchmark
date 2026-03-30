from __future__ import annotations

import json
import py_compile
from pathlib import Path

from runner.libs.run_artifacts import (
    ARTIFACT_KIND,
    ARTIFACT_VERSION,
    artifact_timestamp,
    create_run_artifact_dir,
    derive_run_type,
    externalize_sample_daemon_debug,
    load_latest_result_for_output,
    repo_relative_path,
    result_root_for_output,
    update_run_artifact,
    write_run_artifact,
)


def test_derive_run_type_strips_timestamp_suffixes() -> None:
    assert derive_run_type(Path("/tmp/vm_micro_authoritative_20260323.json"), "fallback") == "vm_micro"
    assert derive_run_type(Path("/tmp/tracee_20260323_101112.json"), "fallback") == "tracee"


def test_result_root_for_output_uses_parent_of_dev_dir(tmp_path: Path) -> None:
    output = tmp_path / "results" / "dev" / "vm_micro.json"
    output.parent.mkdir(parents=True)
    assert result_root_for_output(output) == tmp_path / "results"


def test_write_run_artifact_preserves_previous_metadata_and_prunes_old_details_by_default(tmp_path: Path) -> None:
    results_dir = tmp_path / "results"
    results_dir.mkdir()

    first_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:12+00:00"},
        detail_payloads={"result.json": {"ok": True}},
    )
    assert first_dir.is_dir()
    assert (first_dir / "details" / "result.json").is_file()

    preserved_dir = results_dir / "archive"
    preserved_dir.mkdir()

    second_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:13+00:00"},
    )

    assert first_dir.exists()
    assert not (first_dir / "details").exists()
    assert preserved_dir.exists()
    assert second_dir.is_dir()

    payload = json.loads((second_dir / "metadata.json").read_text())
    assert payload["artifact_kind"] == ARTIFACT_KIND
    assert payload["artifact_version"] == ARTIFACT_VERSION


def test_write_run_artifact_can_explicitly_replace_previous_managed_runs(tmp_path: Path) -> None:
    results_dir = tmp_path / "results"
    results_dir.mkdir()

    first_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:12+00:00"},
    )
    assert first_dir.is_dir()

    preserved_dir = results_dir / "archive"
    preserved_dir.mkdir()

    second_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:13+00:00"},
        clear_existing=True,
    )

    assert not first_dir.exists()
    assert preserved_dir.exists()
    assert second_dir.is_dir()


def test_create_run_artifact_dir_can_skip_clear_existing(tmp_path: Path) -> None:
    results_dir = tmp_path / "results"

    first_dir = create_run_artifact_dir(
        results_dir=results_dir,
        run_type="tracee",
        generated_at="2026-03-23T10:11:12+00:00",
    )
    update_run_artifact(
        run_dir=first_dir,
        run_type="tracee",
        metadata={"generated_at": "2026-03-23T10:11:12+00:00"},
    )

    second_dir = create_run_artifact_dir(
        results_dir=results_dir,
        run_type="tetragon",
        generated_at="2026-03-23T10:11:13+00:00",
        clear_existing=False,
    )

    assert first_dir.exists()
    assert second_dir.exists()


def test_externalize_sample_daemon_debug_moves_large_payload_to_detail() -> None:
    sample = {
        "iteration_index": 2,
        "result": 7,
        "rejit": {
            "applied": True,
            "verifier_retries": 1,
            "daemon_response": {"debug": {"verifier_log": {"log": "ok"}}},
        },
    }

    detail = externalize_sample_daemon_debug(
        benchmark_name="branch_dense",
        runtime_name="kernel-rejit",
        sample_index=2,
        sample=sample,
    )

    assert detail is not None
    relative_path, detail_payload, index_entry = detail
    assert relative_path == "daemon_debug/branch_dense__kernel_rejit__iter02.json"
    assert sample["rejit"]["daemon_debug_ref"] == "details/daemon_debug/branch_dense__kernel_rejit__iter02.json"
    assert "daemon_response" not in sample["rejit"]
    assert detail_payload["daemon_response"] == {"debug": {"verifier_log": {"log": "ok"}}}
    assert index_entry["path"] == "details/daemon_debug/branch_dense__kernel_rejit__iter02.json"


def test_repo_relative_path_returns_string() -> None:
    path = Path.cwd() / "micro" / "results" / "dev" / "vm_micro.json"
    assert repo_relative_path(path).endswith("micro/results/dev/vm_micro.json")


def test_artifact_timestamp_parses_generated_at() -> None:
    assert artifact_timestamp("2026-03-23T10:11:12+00:00") == "20260323_101112"


def test_load_latest_result_for_output_reads_completed_artifact_payload(tmp_path: Path) -> None:
    output_path = tmp_path / "results" / "llvmbpf_vs_kernel.json"
    run_dir = write_run_artifact(
        results_dir=output_path.parent,
        run_type=derive_run_type(output_path, "pure_jit"),
        metadata={
            "generated_at": "2026-03-29T06:46:43+00:00",
            "status": "completed",
            "started_at": "2026-03-29T06:46:43+00:00",
            "last_updated_at": "2026-03-29T06:47:01+00:00",
        },
        detail_payloads={"result.json": {"benchmarks": [], "suite": "micro"}},
    )

    payload = load_latest_result_for_output(output_path, fallback_run_type="pure_jit")

    assert payload == {"benchmarks": [], "suite": "micro"}
    assert run_dir.name == "llvmbpf_vs_kernel_20260329_064643"


def test_load_latest_result_for_output_rejects_incomplete_artifact(tmp_path: Path) -> None:
    output_path = tmp_path / "results" / "llvmbpf_vs_kernel.json"
    write_run_artifact(
        results_dir=output_path.parent,
        run_type=derive_run_type(output_path, "pure_jit"),
        metadata={
            "generated_at": "2026-03-29T06:46:43+00:00",
            "status": "error",
            "started_at": "2026-03-29T06:46:43+00:00",
            "last_updated_at": "2026-03-29T06:47:01+00:00",
            "error_message": "micro batch runner failed",
        },
    )

    try:
        load_latest_result_for_output(output_path, fallback_run_type="pure_jit")
    except RuntimeError as exc:
        assert "did not complete" in str(exc)
        assert "micro batch runner failed" in str(exc)
    else:
        raise AssertionError("expected RuntimeError for incomplete artifact")


def test_artifact_entrypoints_compile() -> None:
    repo_root = Path(__file__).resolve().parents[2]
    for relative_path in (
        "micro/driver.py",
        "corpus/driver.py",
        "corpus/orchestrator.py",
        "e2e/run.py",
        "e2e/cases/bpftrace/case.py",
        "e2e/cases/tetragon/case.py",
        "e2e/cases/katran/case.py",
    ):
        py_compile.compile(str(repo_root / relative_path), doraise=True)
