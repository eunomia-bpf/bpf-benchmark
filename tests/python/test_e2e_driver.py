from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import case_common
from e2e import driver as e2e_driver
from runner.libs.app_suite_schema import AppSpec, AppWorkload
from runner.libs import smoke_output_path


def test_resolve_primary_output_json_uses_smoke_path_for_default_output() -> None:
    spec = e2e_driver.CASE_SPECS["tracee"]
    args = argparse.Namespace(
        case="tracee",
        output_json=str(spec.default_output_json),
        smoke=True,
    )

    resolved = e2e_driver.resolve_primary_output_json(args, spec)

    assert resolved == smoke_output_path(spec.default_output_json.parent, "tracee").resolve()


def test_run_single_case_writes_primary_outputs(tmp_path: Path, monkeypatch) -> None:
    payload = {"status": "ok", "value": 7}
    case_common.reset_pending_result_metadata()

    def fake_run_case(args: argparse.Namespace) -> dict[str, object]:
        del args
        case_common._append_pending_kinsn_metadata(
            {
                "status": "completed",
                "requested_prog_ids": [7],
                "module_load": {
                    "loaded_modules": ["bpf_endian"],
                    "failed_modules": [],
                },
            }
        )
        return dict(payload)

    spec = e2e_driver.CaseSpec(
        run_case=fake_run_case,
        build_markdown=lambda result: f"value={result['value']}",
        build_report=lambda result: f"report={result['value']}",
        default_output_json=tmp_path / "dummy_authoritative_20260327.json",
        default_output_md=tmp_path / "dummy.md",
    )
    monkeypatch.setitem(e2e_driver.CASE_SPECS, "dummy", spec)

    args = argparse.Namespace(
        case="dummy",
        output_json=str(tmp_path / "dummy.json"),
        output_md=str(tmp_path / "dummy.md"),
        report_md=str(tmp_path / "dummy-report.md"),
        smoke=False,
    )

    result = e2e_driver._run_single_case(args, clear_existing=True)

    assert result["status"] == "ok"
    assert result["value"] == 7
    assert result["metadata"]["kinsn_modules"]["count"] == 1
    run_dir = next(tmp_path.glob("dummy_*"))
    written = json.loads((run_dir / "result.json").read_text())
    assert written["metadata"]["kinsn_modules"]["lifecycle_runs"][0]["requested_prog_ids"] == [7]
    assert (run_dir / "result.md").read_text() == "value=7\n"
    assert (run_dir / "report.md").read_text() == "report=7\n"


def test_run_single_case_raises_for_error_payload(tmp_path: Path, monkeypatch) -> None:
    payload = {"status": "error", "error_message": "boom", "value": 7}

    def fake_run_case(args: argparse.Namespace) -> dict[str, object]:
        del args
        return dict(payload)

    spec = e2e_driver.CaseSpec(
        run_case=fake_run_case,
        build_markdown=lambda result: f"status={result['status']}",
        build_report=lambda result: f"report={result['status']}",
        default_output_json=tmp_path / "dummy_authoritative_20260327.json",
        default_output_md=tmp_path / "dummy.md",
    )
    monkeypatch.setitem(e2e_driver.CASE_SPECS, "dummy-error", spec)

    args = argparse.Namespace(
        case="dummy-error",
        output_json=str(tmp_path / "dummy.json"),
        output_md=str(tmp_path / "dummy.md"),
        report_md=str(tmp_path / "dummy-report.md"),
        smoke=False,
    )

    try:
        e2e_driver._run_single_case(args, clear_existing=True)
    except RuntimeError as exc:
        assert str(exc) == "boom"
    else:
        raise AssertionError("error payload should fail the case")

    run_dir = next(tmp_path.glob("dummy_*"))
    assert json.loads((run_dir / "result.json").read_text()) == payload
    assert (run_dir / "result.md").read_text() == "status=error\n"
    assert (run_dir / "report.md").read_text() == "report=error\n"


def test_run_single_case_rejects_skipped_payload(tmp_path: Path, monkeypatch) -> None:
    payload = {"status": "skipped", "skip_reason": "not allowed"}

    def fake_run_case(args: argparse.Namespace) -> dict[str, object]:
        del args
        return dict(payload)

    spec = e2e_driver.CaseSpec(
        run_case=fake_run_case,
        build_markdown=lambda result: f"status={result['status']}",
        default_output_json=tmp_path / "dummy_authoritative_20260327.json",
        default_output_md=tmp_path / "dummy.md",
    )
    monkeypatch.setitem(e2e_driver.CASE_SPECS, "dummy-skipped", spec)

    args = argparse.Namespace(
        case="dummy-skipped",
        output_json=str(tmp_path / "dummy.json"),
        output_md=str(tmp_path / "dummy.md"),
        report_md=str(tmp_path / "dummy-report.md"),
        smoke=False,
    )

    with pytest.raises(RuntimeError, match="returned an invalid status: 'skipped'"):
        e2e_driver._run_single_case(args, clear_existing=True)

    run_dir = next(tmp_path.glob("dummy_*"))
    written = json.loads((run_dir / "result.json").read_text())
    assert written["status"] == "skipped"


def test_apply_case_defaults_switches_tetragon_config_from_tracee_default() -> None:
    args = argparse.Namespace(
        case="tetragon",
        output_json=str(e2e_driver.DEFAULT_OUTPUT_JSON),
        output_md=str(e2e_driver.DEFAULT_OUTPUT_MD),
        report_md=str(e2e_driver.DEFAULT_BPFTRACE_REPORT_MD),
        setup_script=str(e2e_driver.DEFAULT_TRACEE_SETUP_SCRIPT),
        config=str(e2e_driver.ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"),
    )

    e2e_driver.apply_case_defaults(args)

    assert args.config == str(e2e_driver.DEFAULT_TETRAGON_CONFIG)


def test_build_parser_leaves_rejit_passes_unset_by_default() -> None:
    args = e2e_driver.build_parser().parse_args(["tracee"])

    assert args.rejit_passes is None


def test_apply_suite_case_config_rewrites_bcc_config_from_shared_suite(tmp_path: Path) -> None:
    config_path = tmp_path / "bcc.yaml"
    config_path.write_text(
        yaml.safe_dump(
            {
                "tools": [
                    {
                        "name": "execsnoop",
                        "workload_kind": "exec_loop",
                        "expected_programs": 2,
                        "spawn_timeout_s": 15,
                    },
                    {
                        "name": "opensnoop",
                        "workload_kind": "file_open",
                        "expected_programs": 2,
                        "spawn_timeout_s": 15,
                    },
                ]
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )
    args = argparse.Namespace(
        case="bcc",
        config=str(config_path),
        tools=None,
    )
    suite_case_apps = {
        "bcc": [
            AppSpec(
                name="bcc/execsnoop",
                runner="bcc",
                workload=AppWorkload(corpus="exec_storm", e2e="exec_storm"),
                args={"tool": "execsnoop"},
            )
        ]
    }

    e2e_driver.apply_suite_case_config(args, suite_case_apps)

    rewritten = yaml.safe_load(Path(args.config).read_text(encoding="utf-8"))
    assert args.tools == ["execsnoop"]
    assert [entry["name"] for entry in rewritten["tools"]] == ["execsnoop"]
    assert rewritten["tools"][0]["workload_kind"] == "exec_storm"
    e2e_driver._cleanup_suite_temp_paths(args)


def test_build_run_metadata_prefers_effective_passes_from_payload(tmp_path: Path, monkeypatch) -> None:
    monkeypatch.setattr(e2e_driver, "benchmark_rejit_enabled_passes", lambda: ["map_inline", "const_prop", "dce"])

    args = argparse.Namespace(
        case="tracee",
        smoke=False,
        output_md=str(tmp_path / "tracee.md"),
        report_md=str(tmp_path / "tracee-report.md"),
        no_kinsn=False,
    )
    payload = {
        "selected_rejit_passes": ["map_inline", "const_prop", "dce"],
        "tracee": {
            "effective_enabled_passes_by_program": {
                "101": ["map_inline"],
            }
        },
    }

    metadata = e2e_driver.build_run_metadata(args, payload)

    assert metadata["selected_rejit_passes"] == ["map_inline"]
    assert metadata["requested_rejit_passes"] == ["map_inline", "const_prop", "dce"]
