from __future__ import annotations

from pathlib import Path
import sys

import yaml

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from corpus import modes


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


def test_attach_trigger_rejects_tetragon_custom_tracepoint_section() -> None:
    obj = _resolve_object("corpus/build/tetragon/bpf_execve_event.bpf.o")
    program = modes.find_program_in_object(obj, "event_execve")
    assert program is not None

    reason = modes.attach_trigger_unsupported_reason(obj, program)

    assert reason is not None
    assert "tracepoint/<category>/<name>" in reason
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
