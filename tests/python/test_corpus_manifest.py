from __future__ import annotations

from pathlib import Path
import sys

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import corpus as corpus_lib


def test_macro_corpus_manifest_uses_only_new_measurements() -> None:
    manifest_path = Path(__file__).resolve().parents[2] / "corpus" / "config" / "macro_corpus.yaml"
    manifest_text = manifest_path.read_text(encoding="utf-8")
    manifest = yaml.safe_load(manifest_text)
    objects = manifest.get("objects")
    assert isinstance(objects, list)
    assert objects
    assert "attach_trigger" not in manifest_text
    assert "compile-only" not in manifest_text
    assert "attach_group:" not in manifest_text
    assert manifest.get("build", {}).get("runner_binary") is None
    runtimes = manifest.get("runtimes")
    assert runtimes == [{"name": "kernel", "label": "kernel eBPF", "mode": "kernel"}]

    for entry in objects:
        assert isinstance(entry, dict)
        assert entry.get("measurement") in {"app_native", "test_run"}
        assert "test_method" not in entry
        assert "trigger" not in entry
        assert "attach_group" not in entry
        assert "io_mode" not in entry
        assert "raw_packet" not in entry
        assert "input_size" not in entry
        assert "trigger_timeout_seconds" not in entry
        programs = entry.get("programs")
        assert isinstance(programs, list)
        assert programs
        for program in programs:
            assert isinstance(program, dict)
            if "measurement" in program:
                assert program["measurement"] in {"app_native", "test_run"}
            assert "test_method" not in program
            assert "trigger" not in program
            assert "attach_group" not in program
            assert "io_mode" not in program
            assert "raw_packet" not in program
            assert "input_size" not in program
            assert "trigger_timeout_seconds" not in program


def test_load_targets_from_yaml_resolves_measurements_and_repo_loader(tmp_path: Path) -> None:
    object_path = tmp_path / "tracee.bpf.o"
    object_path.write_text("placeholder", encoding="utf-8")
    manifest_path = tmp_path / "macro.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 2,
                "repos": {
                    "tracee": {
                        "loader": "app-native",
                        "loader_binary": "e2e/cases/tracee/bin/tracee",
                        "loader_args": ["--install-path", "/tmp/tracee"],
                    }
                },
                "objects": [
                    {
                        "source": str(object_path),
                        "repo": "tracee",
                        "measurement": "app_native",
                        "programs": [
                            {
                                "name": "tracepoint__raw_syscalls__sys_enter",
                                "prog_type": "raw_tracepoint",
                                "section": "raw_tracepoint/sys_enter",
                            },
                            {
                                "name": "cgroup_skb_ingress",
                                "measurement": "test_run",
                                "prog_type": "cgroup_skb",
                                "section": "cgroup_skb/ingress",
                            },
                        ],
                    }
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )

    objects, summary = corpus_lib.load_targets_from_yaml(
        manifest_path,
        corpus_build_report={
            "path": tmp_path / "build-report.json",
            "summary": {},
            "available_objects": {str(object_path.resolve())},
            "supplemented_existing": 0,
        },
    )

    assert summary["selected_objects"] == 1
    assert summary["selected_programs"] == 2
    assert summary["selected_programs_by_measurement"] == {
        "app_native": 1,
        "test_run": 1,
    }
    assert objects[0].measurement == "app_native"
    assert objects[0].loader == "app-native"
    assert objects[0].loader_binary == "e2e/cases/tracee/bin/tracee"
    assert objects[0].loader_args == ("--install-path", "/tmp/tracee")
    assert objects[0].programs[0].measurement == "app_native"
    assert objects[0].programs[1].measurement == "test_run"


def test_load_targets_from_yaml_rejects_object_only_entries(tmp_path: Path) -> None:
    object_path = tmp_path / "demo.bpf.o"
    object_path.write_text("placeholder", encoding="utf-8")
    manifest_path = tmp_path / "macro.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 2,
                "objects": [
                    {
                        "source": str(object_path),
                        "repo": "demo",
                        "measurement": "app_native",
                        "programs": [],
                    }
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )

    with pytest.raises(SystemExit, match="has no programs"):
        corpus_lib.load_targets_from_yaml(
            manifest_path,
            corpus_build_report={
                "path": tmp_path / "build-report.json",
                "summary": {},
                "available_objects": {str(object_path.resolve())},
                "supplemented_existing": 0,
            },
        )


def test_load_targets_from_yaml_fails_when_selected_object_is_missing_from_build_report(
    tmp_path: Path,
) -> None:
    object_path = tmp_path / "demo.bpf.o"
    object_path.write_text("placeholder", encoding="utf-8")
    manifest_path = tmp_path / "macro.yaml"
    manifest_path.write_text(
        yaml.safe_dump(
            {
                "schema_version": 2,
                "objects": [
                    {
                        "source": str(object_path),
                        "repo": "demo",
                        "measurement": "test_run",
                        "programs": [
                            {
                                "name": "demo_prog",
                                "prog_type": "xdp",
                                "section": "xdp",
                            }
                        ],
                    }
                ],
            },
            sort_keys=False,
        ),
        encoding="utf-8",
    )

    with pytest.raises(SystemExit, match="missing from the build report"):
        corpus_lib.load_targets_from_yaml(
            manifest_path,
            corpus_build_report={
                "path": tmp_path / "build-report.json",
                "summary": {},
                "available_objects": set(),
                "supplemented_existing": 0,
            },
        )
