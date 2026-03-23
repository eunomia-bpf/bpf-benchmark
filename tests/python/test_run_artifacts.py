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


def test_write_run_artifact_replaces_previous_managed_runs(tmp_path: Path) -> None:
    results_dir = tmp_path / "results"
    results_dir.mkdir()

    first_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:12+00:00"},
        detail_payloads={"result.json": {"ok": True}},
    )
    assert first_dir.is_dir()

    preserved_dir = results_dir / "archive"
    preserved_dir.mkdir()

    second_dir = write_run_artifact(
        results_dir=results_dir,
        run_type="vm_micro",
        metadata={"generated_at": "2026-03-23T10:11:13+00:00"},
    )

    assert not first_dir.exists()
    assert preserved_dir.exists()
    assert second_dir.is_dir()

    payload = json.loads((second_dir / "metadata.json").read_text())
    assert payload["artifact_kind"] == ARTIFACT_KIND
    assert payload["artifact_version"] == ARTIFACT_VERSION


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


def test_repo_relative_path_returns_string() -> None:
    path = Path.cwd() / "micro" / "results" / "dev" / "vm_micro.json"
    assert repo_relative_path(path).endswith("micro/results/dev/vm_micro.json")


def test_artifact_timestamp_parses_generated_at() -> None:
    assert artifact_timestamp("2026-03-23T10:11:12+00:00") == "20260323_101112"


def test_artifact_entrypoints_compile() -> None:
    repo_root = Path(__file__).resolve().parents[2]
    for relative_path in (
        "micro/driver.py",
        "corpus/driver.py",
        "corpus/modes.py",
        "e2e/run.py",
        "e2e/cases/bpftrace/case.py",
        "e2e/cases/tetragon/case.py",
        "e2e/cases/katran/case.py",
    ):
        py_compile.compile(str(repo_root / relative_path), doraise=True)
