from __future__ import annotations

from pathlib import Path
import sys
from types import SimpleNamespace

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from micro import driver
from runner.libs.catalog import CatalogRuntime


def test_build_runner_command_uses_run_llvmbpf_for_llvmbpf_runtime() -> None:
    runtime = CatalogRuntime(
        name="llvmbpf",
        label="llvmbpf LLVM JIT",
        mode="llvmbpf",
        backend="llvmbpf",
        policy_mode="stock",
    )
    benchmark = SimpleNamespace(
        program_object=Path("/tmp/demo.bpf.o"),
        program_names=("demo_xdp",),
        io_mode="staged",
        kernel_input_size=64,
    )

    command = driver.build_runner_command(
        runner_binary=Path("/tmp/micro_exec"),
        benchmark=benchmark,
        runtime=runtime,
        repeat=200,
        memory_file=Path("/tmp/demo.bin"),
        perf_counters=False,
        perf_scope="full_repeat_raw",
        cpu=None,
    )

    assert command[:2] == ["/tmp/micro_exec", "run-llvmbpf"]
    assert "--program-name" in command
    assert "--memory" in command
    assert "--repeat" in command


def test_select_runtimes_rejects_rejit_policy_modes() -> None:
    runtime = CatalogRuntime(
        name="kernel-rejit",
        label="kernel eBPF + REJIT",
        mode="kernel-rejit",
        backend="kernel",
        policy_mode="rejit",
    )
    suite = SimpleNamespace(
        defaults=SimpleNamespace(runtimes=("kernel-rejit",)),
        runtime_aliases={},
        runtimes=(runtime,),
    )

    with pytest.raises(SystemExit, match="stock runtimes"):
        driver.select_runtimes(None, suite)
