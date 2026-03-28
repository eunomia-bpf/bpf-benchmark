from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from daemon.tests import static_verify


def test_parse_enabled_passes_deduplicates_and_trims() -> None:
    assert static_verify.parse_enabled_passes(" map_inline, const_prop ,map_inline,,dce ") == [
        "map_inline",
        "const_prop",
        "dce",
    ]


def test_build_static_batch_job_includes_enabled_passes() -> None:
    entry = static_verify.ObjectEntry(object_path=Path("/tmp/object.bpf.o"))
    entry.manifest_kinds = ["macro"]
    entry.target_names = ["tetragon_execve"]
    entry.program_names = ["execve_rate", "event_execve"]
    entry.sections = ["tracepoint/sys_execve"]
    entry.prog_types = ["tracepoint"]

    job = static_verify.build_static_batch_job(
        entry=entry,
        object_index=7,
        daemon_socket=Path("/tmp/rejit.sock"),
        enabled_passes=["map_inline"],
    )

    assert job["type"] == "static_verify_object"
    assert job["enabled_passes"] == ["map_inline"]
