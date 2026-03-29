from __future__ import annotations

import argparse
from pathlib import Path
import sys

import pytest
import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from corpus import modes
from runner.libs import corpus as corpus_lib


def _manifest_entry_by_source(source: str) -> dict:
    manifest = yaml.safe_load(modes.DEFAULT_MACRO_CORPUS_YAML.read_text())
    objects = manifest.get("objects")
    assert isinstance(objects, list)
    for entry in objects:
        if isinstance(entry, dict) and entry.get("source") == source:
            return entry
    raise AssertionError(f"manifest entry not found: {source}")


def _resolve_object(source: str) -> modes.ResolvedObject:
    entry = _manifest_entry_by_source(source)
    return modes.resolve_manifest_object(entry, index=1)


def _synthetic_guest_batch_object(name: str) -> modes.ResolvedObject:
    program = modes.ResolvedProgram(
        source=f"corpus/build/demo/{name}.bpf.o",
        object_path=f"corpus/build/demo/{name}.bpf.o",
        object_abs_path=f"/tmp/{name}.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath=f"{name}.bpf.o",
        canonical_object_name=f"demo:{name}.bpf.o",
        object_basename=f"{name}.bpf.o",
        short_name=f"demo:{name}.bpf.o:{name}_prog",
        program_name=f"{name}_prog",
        canonical_name=f"demo:{name}.bpf.o:{name}_prog",
        fixture_path=None,
        test_method="test_run",
        prog_type_name="xdp",
        section_name="xdp",
        io_mode="context",
        raw_packet=False,
        input_size=0,
        memory_path=None,
        trigger=None,
        trigger_timeout_seconds=None,
        compile_loader=None,
        attach_group=None,
        rejit_enabled=True,
    )
    return modes.ResolvedObject(
        source=f"corpus/build/demo/{name}.bpf.o",
        object_path=f"corpus/build/demo/{name}.bpf.o",
        object_abs_path=f"/tmp/{name}.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath=f"{name}.bpf.o",
        canonical_name=f"demo:{name}.bpf.o",
        object_basename=f"{name}.bpf.o",
        short_name=f"demo:{name}.bpf.o",
        fixture_path=None,
        compile_loader=None,
        shared_state_policy="reset_maps",
        allow_object_only_result=False,
        test_method="test_run",
        programs=(program,),
    )


def _synthetic_attach_program(
    section_name: str,
    *,
    program_name: str = "attach_prog",
    prog_type_name: str = "kprobe",
) -> tuple[modes.ResolvedObject, modes.ResolvedProgram]:
    program = modes.ResolvedProgram(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_object_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name=f"demo:demo.bpf.o:{program_name}",
        program_name=program_name,
        canonical_name=f"demo:demo.bpf.o:{program_name}",
        fixture_path=None,
        test_method="attach_trigger",
        prog_type_name=prog_type_name,
        section_name=section_name,
        io_mode="context",
        raw_packet=False,
        input_size=0,
        memory_path=None,
        trigger=None,
        trigger_timeout_seconds=None,
        compile_loader=None,
        attach_group=program_name,
        rejit_enabled=True,
    )
    obj = modes.ResolvedObject(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name="demo:demo.bpf.o",
        fixture_path=None,
        compile_loader=None,
        shared_state_policy="reset_maps",
        allow_object_only_result=False,
        test_method="attach_trigger",
        programs=(program,),
    )
    return obj, program


def test_attach_trigger_rejects_tetragon_custom_tracepoint_section() -> None:
    obj = _resolve_object("corpus/build/tetragon/bpf_execve_event.bpf.o")
    program = modes.find_program_in_object(obj, "event_execve")
    assert program is not None

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is not None
    assert "auto-triggerable kernel event hook" in reason
    assert "tracepoint/sys_execve" in reason


def test_attach_trigger_follows_attach_group_for_execve_rate() -> None:
    obj = _resolve_object("corpus/build/tetragon/bpf_execve_event.bpf.o")
    program = modes.find_program_in_object(obj, "execve_rate")
    assert program is not None
    assert program.attach_group == "event_execve"

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is not None
    assert "tracepoint/sys_execve" in reason


def test_attach_trigger_accepts_standard_tracepoint_section() -> None:
    obj = _resolve_object("corpus/build/bcc/libbpf-tools/execsnoop.bpf.o")
    program = modes.find_program_in_object(obj, "tracepoint__syscalls__sys_enter_execve")
    assert program is not None

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is None


def test_attach_trigger_accepts_kprobe_section() -> None:
    obj, program = _synthetic_attach_program(
        "kprobe/do_sys_openat2",
        prog_type_name="kprobe",
    )

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is None


def test_attach_trigger_accepts_raw_tracepoint_section() -> None:
    obj, program = _synthetic_attach_program(
        "raw_tp/sched_switch",
        prog_type_name="raw_tracepoint",
    )

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is None


def test_attach_trigger_accepts_fentry_section() -> None:
    obj, program = _synthetic_attach_program(
        "fentry/tcp_v4_connect",
        prog_type_name="tracing",
    )

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is None


def test_build_test_run_batch_job_preserves_explicit_empty_enabled_passes() -> None:
    job = modes.build_test_run_batch_job(
        job_id="empty-passes",
        execution="serial",
        runtime="kernel-rejit",
        object_path=Path("/tmp/demo.bpf.o"),
        program_name=None,
        attach_program_name=None,
        io_mode="context",
        raw_packet=False,
        memory_path=None,
        input_size=0,
        repeat=1,
        warmup_repeat=0,
        btf_custom_path=None,
        compile_only=True,
        daemon_socket="/tmp/rejit.sock",
        enabled_passes=[],
    )

    assert "enabled_passes" in job
    assert job["enabled_passes"] == []


def test_comparison_exclusion_reason_labels_unsupported_attach_trigger() -> None:
    obj = _resolve_object("corpus/build/tetragon/bpf_execve_event.bpf.o")
    program = modes.find_program_in_object(obj, "execve_rate")
    assert program is not None

    baseline_record = {"ok": True, "sample": {"exec_ns": 0, "result": 0}}
    rejit_record = {"ok": True, "sample": {"exec_ns": 0, "result": 0}}

    reason = corpus_lib.comparison_exclusion_reason(
        obj=obj,
        program=program,
        baseline_record=baseline_record,
        rejit_record=rejit_record,
    )

    assert reason is not None
    assert reason.startswith("attach_trigger measurement unsupported:")


def test_comparison_exclusion_reason_for_supported_attach_trigger_reports_zero_run_cnt() -> None:
    obj, program = _synthetic_attach_program(
        "kprobe/do_sys_openat2",
        prog_type_name="kprobe",
    )

    baseline_record = {"ok": True, "sample": {"exec_ns": 0, "result": 0}}
    rejit_record = {"ok": True, "sample": {"exec_ns": 0, "result": 0}}

    reason = corpus_lib.comparison_exclusion_reason(
        obj=obj,
        program=program,
        baseline_record=baseline_record,
        rejit_record=rejit_record,
    )

    assert reason == "attach_trigger did not fire the target program in baseline or REJIT (run_cnt_delta=0)"


def test_build_object_batch_plan_v2_uses_group_scoped_load_program_names() -> None:
    program_main = modes.ResolvedProgram(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_object_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name="demo:demo.bpf.o:tp_main",
        program_name="tp_main",
        canonical_name="demo:demo.bpf.o:tp_main",
        fixture_path=None,
        test_method="attach_trigger",
        prog_type_name="tracepoint",
        section_name="tracepoint/syscalls/sys_enter_execve",
        io_mode="context",
        raw_packet=False,
        input_size=0,
        memory_path=None,
        trigger="true",
        trigger_timeout_seconds=30,
        compile_loader=None,
        attach_group="tp_main",
        rejit_enabled=True,
    )
    program_helper = modes.ResolvedProgram(
        **{
            **program_main.__dict__,
            "short_name": "demo:demo.bpf.o:tp_helper",
            "program_name": "tp_helper",
            "canonical_name": "demo:demo.bpf.o:tp_helper",
            "section_name": "tracepoint/syscalls/sys_enter_execve",
        }
    )
    program_solo = modes.ResolvedProgram(
        **{
            **program_main.__dict__,
            "short_name": "demo:demo.bpf.o:solo",
            "program_name": "solo",
            "canonical_name": "demo:demo.bpf.o:solo",
            "test_method": "test_run",
            "prog_type_name": "xdp",
            "section_name": "xdp",
            "trigger": None,
            "trigger_timeout_seconds": None,
            "attach_group": None,
        }
    )
    obj = modes.ResolvedObject(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name="demo:demo.bpf.o",
        fixture_path=None,
        compile_loader=None,
        shared_state_policy="reset_maps",
        allow_object_only_result=False,
        test_method="attach_trigger",
        programs=(program_main, program_helper, program_solo),
    )

    spec, _refs = corpus_lib.build_object_batch_plan_v2(
        objects=[obj],
        repeat=1,
        warmup_repeat=0,
        btf_custom_path=None,
        daemon_socket="/tmp/rejit.sock",
        enabled_passes=["demo-pass"],
    )

    prepare_jobs = [
        job for job in spec["jobs"] if job["type"] == "test_run" and job["compile_only"] and job["id"].endswith(":prepare")
    ]
    load_sets = {tuple(job.get("load_program_names") or ()) for job in prepare_jobs}

    assert ("tp_main", "tp_helper") in load_sets
    assert ("solo",) in load_sets


def test_build_object_batch_plan_v2_uses_program_scoped_rejit_passes() -> None:
    program_xdp = modes.ResolvedProgram(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_object_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name="demo:demo.bpf.o:xdp_fast",
        program_name="xdp_fast",
        canonical_name="demo:demo.bpf.o:xdp_fast",
        fixture_path=None,
        test_method="test_run",
        prog_type_name="xdp",
        section_name="xdp",
        io_mode="context",
        raw_packet=False,
        input_size=0,
        memory_path=None,
        trigger=None,
        trigger_timeout_seconds=None,
        compile_loader=None,
        attach_group=None,
        rejit_enabled=True,
    )
    program_kprobe = modes.ResolvedProgram(
        **{
            **program_xdp.__dict__,
            "short_name": "demo:demo.bpf.o:kprobe_slow",
            "program_name": "kprobe_slow",
            "canonical_name": "demo:demo.bpf.o:kprobe_slow",
            "prog_type_name": "kprobe",
            "section_name": "kprobe/do_sys_openat2",
        }
    )
    obj = modes.ResolvedObject(
        source="corpus/build/demo/demo.bpf.o",
        object_path="corpus/build/demo/demo.bpf.o",
        object_abs_path="/tmp/demo.bpf.o",
        repo="demo",
        source_name="demo",
        family="demo",
        category="test",
        level="unit",
        description=None,
        hypothesis=None,
        tags=(),
        object_relpath="demo.bpf.o",
        canonical_name="demo:demo.bpf.o",
        object_basename="demo.bpf.o",
        short_name="demo:demo.bpf.o",
        fixture_path=None,
        compile_loader=None,
        shared_state_policy="reset_maps",
        allow_object_only_result=False,
        test_method="test_run",
        programs=(program_xdp, program_kprobe),
    )

    spec, _refs = corpus_lib.build_object_batch_plan_v2(
        objects=[obj],
        repeat=1,
        warmup_repeat=0,
        btf_custom_path=None,
        daemon_socket="/tmp/rejit.sock",
        program_enabled_passes={
            program_xdp.canonical_name: ["map_inline", "dce"],
            program_kprobe.canonical_name: ["const_prop"],
        },
    )

    jobs_by_id = {job["id"]: job for job in spec["jobs"]}
    xdp_compile = jobs_by_id["object-0001:program-0001:rejit-compile"]
    xdp_run = jobs_by_id["object-0001:program-0001:rejit-run"]
    kprobe_compile = jobs_by_id["object-0001:program-0002:rejit-compile"]
    kprobe_run = jobs_by_id["object-0001:program-0002:rejit-run"]

    assert xdp_compile["enabled_passes"] == ["map_inline", "dce"]
    assert xdp_compile["load_program_names"] == ["xdp_fast"]
    assert "prepared_key" in xdp_compile
    assert "prepared_ref" not in xdp_compile
    assert xdp_run["enabled_passes"] == ["map_inline", "dce"]
    assert xdp_run["prepared_ref"] == xdp_compile["prepared_key"]

    assert kprobe_compile["enabled_passes"] == ["const_prop"]
    assert kprobe_compile["load_program_names"] == ["kprobe_slow"]
    assert "prepared_key" in kprobe_compile
    assert "prepared_ref" not in kprobe_compile
    assert kprobe_run["enabled_passes"] == ["const_prop"]
    assert kprobe_run["prepared_ref"] == kprobe_compile["prepared_key"]


def test_run_objects_locally_batch_splits_resource_exhausted_batches(
    monkeypatch,
    tmp_path: Path,
) -> None:
    objects = [
        _synthetic_guest_batch_object("alpha"),
        _synthetic_guest_batch_object("beta"),
        _synthetic_guest_batch_object("gamma"),
    ]
    batch_object_counts: list[int] = []
    daemon_events: list[tuple[str, object]] = []

    def fake_start_daemon_server(_daemon: Path):
        daemon_events.append(("start", "daemon"))
        return ("proc", tmp_path / "daemon.sock", "sock-dir", tmp_path / "daemon.out", tmp_path / "daemon.err")

    def fake_stop_daemon_server(proc, socket_path, socket_dir):
        daemon_events.append(("stop", (proc, socket_path, socket_dir)))

    def fake_resolve_program_enabled_passes_map(**_kwargs):
        return {
            obj.programs[0].canonical_name: ["map_inline"]
            for obj in objects
        }

    def _successful_batch_result(spec_payload: dict[str, object]) -> dict[str, object]:
        jobs: list[dict[str, object]] = []
        for raw_job in spec_payload["jobs"]:
            assert isinstance(raw_job, dict)
            runtime = str(raw_job.get("runtime") or "")
            compile_only = bool(raw_job.get("compile_only"))
            is_rejit = runtime.endswith("rejit")
            jobs.append(
                {
                    "id": raw_job["id"],
                    "type": "test_run",
                    "execution": raw_job["execution"],
                    "runtime": runtime,
                    "ok": True,
                    "error": "",
                    "wall_time_ns": 1,
                    "samples": [
                        {
                            "compile_ns": 10,
                            "exec_ns": 0 if compile_only else (8 if is_rejit else 10),
                            "jited_prog_len": 48 if is_rejit else 64,
                            "xlated_prog_len": 24 if is_rejit else 32,
                            "rejit": {
                                "requested": is_rejit,
                                "applied": is_rejit,
                                "passes_applied": ["map_inline"] if is_rejit else [],
                            },
                        }
                    ],
                }
            )
        return {
            "ok": True,
            "completed_with_job_errors": False,
            "returncode": 0,
            "timed_out": False,
            "duration_seconds": 1.0,
            "stdout": "",
            "stderr": "",
            "error": None,
            "result": {"jobs": jobs},
            "progress": None,
        }

    def fake_run_batch_runner(_runner, *, spec_payload, **_kwargs):
        assert isinstance(spec_payload, dict)
        jobs = spec_payload["jobs"]
        assert isinstance(jobs, list)
        object_count = len({str(job.get("program")) for job in jobs if isinstance(job, dict)})
        batch_object_counts.append(object_count)
        if object_count == 3:
            first_prepare = next(
                str(job["id"])
                for job in jobs
                if isinstance(job, dict) and job.get("prepared_key")
            )
            return {
                "ok": True,
                "completed_with_job_errors": True,
                "returncode": 2,
                "timed_out": False,
                "duration_seconds": 1.0,
                "stdout": "",
                "stderr": "",
                "error": None,
                "result": {
                    "jobs": [
                        {
                            "id": first_prepare,
                            "type": "test_run",
                            "execution": "serial",
                            "runtime": "kernel",
                            "ok": False,
                            "error": "bpf_object__load failed: Cannot allocate memory",
                            "wall_time_ns": 1,
                            "samples": [],
                        }
                    ]
                },
                "progress": None,
            }
        return _successful_batch_result(spec_payload)

    monkeypatch.setattr(corpus_lib, "_start_daemon_server", fake_start_daemon_server)
    monkeypatch.setattr(corpus_lib, "_stop_daemon_server", fake_stop_daemon_server)
    monkeypatch.setattr(
        corpus_lib,
        "resolve_program_enabled_passes_map",
        fake_resolve_program_enabled_passes_map,
    )
    monkeypatch.setattr(corpus_lib, "run_batch_runner", fake_run_batch_runner)

    object_records, program_records, batch_result = corpus_lib.run_objects_locally_batch(
        objects=objects,
        runner=tmp_path / "micro_exec",
        daemon=tmp_path / "bpfrejit-daemon",
        repeat=3,
        warmup_repeat=1,
        timeout_seconds=30,
        execution_mode="vm",
        btf_custom_path=tmp_path / "vmlinux",
        benchmark_config={},
        batch_size=3,
    )

    assert batch_object_counts == [3, 1, 2]
    assert [event[0] for event in daemon_events] == ["start", "stop"]
    assert [record["canonical_object_name"] for record in object_records] == [
        obj.canonical_name for obj in objects
    ]
    assert [record["canonical_name"] for record in program_records] == [
        obj.programs[0].canonical_name for obj in objects
    ]
    assert batch_result["ok"] is True
    assert batch_result["completed_with_job_errors"] is False
    batch_summary = batch_result["result"]["batch_summary"]
    assert batch_summary["requested_batch_size"] == 3
    assert batch_summary["attempted_batch_sizes"] == [3, 1, 2]
    assert batch_summary["effective_batch_sizes"] == [1, 2]
    assert len(batch_summary["retry_splits"]) == 1


def test_guest_batch_failure_headline_prefers_batch_stderr_over_generic_exit_code() -> None:
    headline = modes._guest_batch_failure_headline(
        batch_result={
            "error": "batch runner exited with code 1",
            "stderr": (
                "libbpf: loaded kernel BTF from '/sys/kernel/btf/vmlinux'\n"
                "RLIMIT_NOFILE hard limit 4096 is below required corpus batch minimum 65536"
            ),
            "returncode": 1,
        },
        built_records=[],
    )

    assert headline == "RLIMIT_NOFILE hard limit 4096 is below required corpus batch minimum 65536"


def test_run_guest_batch_mode_reuses_single_daemon_session_for_all_objects(
    monkeypatch,
    tmp_path: Path,
) -> None:
    obj_alpha = _synthetic_guest_batch_object("alpha")
    obj_beta = _synthetic_guest_batch_object("beta")
    batch_calls: list[dict[str, object]] = []
    persisted_records: list[list[str]] = []
    emitted_events: list[tuple[str, dict[str, object]]] = []

    def fake_run_objects_locally_batch(**kwargs):
        batch_calls.append(kwargs)
        return (
            [
                {"canonical_object_name": obj_alpha.canonical_name, "status": "ok", "error": None},
                {"canonical_object_name": obj_beta.canonical_name, "status": "ok", "error": None},
            ],
            [
                {
                    "canonical_object_name": obj_alpha.canonical_name,
                    "canonical_name": obj_alpha.programs[0].canonical_name,
                    "baseline_compile": {"ok": True},
                    "rejit_compile": {"ok": True},
                    "baseline_run": {"ok": True},
                    "rejit_run": {"ok": True},
                },
                {
                    "canonical_object_name": obj_beta.canonical_name,
                    "canonical_name": obj_beta.programs[0].canonical_name,
                    "baseline_compile": {"ok": True},
                    "rejit_compile": {"ok": True},
                    "baseline_run": {"ok": True},
                    "rejit_run": {"ok": True},
                },
            ],
            {
                "ok": True,
                "completed_with_job_errors": False,
                "returncode": 0,
                "timed_out": False,
                "duration_seconds": 1.0,
                "stdout": "",
                "stderr": "",
                "error": None,
                "result": {"jobs": []},
                "progress": None,
            },
        )

    monkeypatch.setattr(modes, "guest_info_payload", lambda: {"kernel_release": "test-kernel"})
    monkeypatch.setattr(modes, "load_guest_batch_targets", lambda _path: [obj_alpha, obj_beta])
    monkeypatch.setattr(modes, "run_objects_locally_batch", fake_run_objects_locally_batch)
    monkeypatch.setattr(
        modes,
        "write_guest_batch_records",
        lambda _path, records: persisted_records.append(
            [item["object_record"]["canonical_object_name"] for item in records]
        ),
    )
    monkeypatch.setattr(
        modes,
        "emit_guest_event",
        lambda kind, **payload: emitted_events.append((kind, payload)),
    )

    args = argparse.Namespace(
        guest_target_json=str(tmp_path / "targets.json"),
        runner=str(tmp_path / "runner"),
        daemon=str(tmp_path / "daemon"),
        btf_custom_path=str(tmp_path / "btf"),
        guest_result_json=str(tmp_path / "guest-result.json"),
        repeat=3,
        batch_size=7,
        timeout=45,
        benchmark_config={},
    )

    assert modes.run_guest_batch_mode(args) == 0
    assert len(batch_calls) == 1
    assert batch_calls[0]["objects"] == [obj_alpha, obj_beta]
    assert batch_calls[0]["batch_size"] == 7
    assert persisted_records == [
        [],
        [obj_alpha.canonical_name],
        [obj_alpha.canonical_name, obj_beta.canonical_name],
    ]
    assert [kind for kind, _payload in emitted_events] == [
        "guest_info",
        "program_progress",
        "program_progress",
    ]


def test_run_guest_batch_mode_exits_on_batch_job_errors(monkeypatch, tmp_path: Path) -> None:
    obj_alpha = _synthetic_guest_batch_object("alpha")
    persisted_records: list[list[str]] = []

    monkeypatch.setattr(modes, "guest_info_payload", lambda: {"kernel_release": "test-kernel"})
    monkeypatch.setattr(modes, "load_guest_batch_targets", lambda _path: [obj_alpha])
    monkeypatch.setattr(
        modes,
        "run_objects_locally_batch",
        lambda **_kwargs: (
            [{"canonical_object_name": obj_alpha.canonical_name, "status": "error", "error": "daemon serve rc=42"}],
            [
                {
                    "canonical_object_name": obj_alpha.canonical_name,
                    "canonical_name": obj_alpha.programs[0].canonical_name,
                    "baseline_compile": {"ok": True},
                    "rejit_compile": {"ok": False, "error": "daemon serve rc=42"},
                }
            ],
            {
                "ok": True,
                "completed_with_job_errors": True,
                "returncode": 2,
                "timed_out": False,
                "duration_seconds": 1.0,
                "stdout": "",
                "stderr": "",
                "error": None,
                "result": {"jobs": []},
                "progress": None,
            },
        ),
    )
    monkeypatch.setattr(
        modes,
        "write_guest_batch_records",
        lambda _path, records: persisted_records.append(
            [item["object_record"]["canonical_object_name"] for item in records]
        ),
    )
    monkeypatch.setattr(modes, "emit_guest_event", lambda *_args, **_kwargs: None)

    args = argparse.Namespace(
        guest_target_json=str(tmp_path / "targets.json"),
        runner=str(tmp_path / "runner"),
        daemon=str(tmp_path / "daemon"),
        btf_custom_path=str(tmp_path / "btf"),
        guest_result_json=str(tmp_path / "guest-result.json"),
        repeat=3,
        timeout=45,
        benchmark_config={},
    )

    with pytest.raises(SystemExit, match="guest batch completed with job errors: demo:alpha.bpf.o: daemon serve rc=42"):
        modes.run_guest_batch_mode(args)
    assert persisted_records == [
        [],
        [obj_alpha.canonical_name],
    ]
