from __future__ import annotations

from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from micro import driver


def test_build_micro_batch_job_includes_enabled_passes() -> None:
    job = driver.build_micro_batch_job(
        job_id="demo",
        runtime_mode="kernel-rejit",
        program=Path("/tmp/demo.bpf.o"),
        io_mode="staged",
        repeat=1,
        daemon_socket="/tmp/rejit.sock",
        enabled_passes=["map_inline", "const_prop"],
    )

    assert job["enabled_passes"] == ["map_inline", "const_prop"]


def test_build_micro_batch_job_preserves_explicit_empty_enabled_passes() -> None:
    job = driver.build_micro_batch_job(
        job_id="demo-empty",
        runtime_mode="kernel-rejit",
        program=Path("/tmp/demo.bpf.o"),
        io_mode="staged",
        repeat=1,
        daemon_socket="/tmp/rejit.sock",
        enabled_passes=[],
    )

    assert "enabled_passes" in job
    assert job["enabled_passes"] == []
