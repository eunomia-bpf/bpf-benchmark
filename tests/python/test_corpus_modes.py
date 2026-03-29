from __future__ import annotations

from pathlib import Path
import sys

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
