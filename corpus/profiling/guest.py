"""Profile one Cilium arm while preserving corpus.driver's lifecycle."""

from __future__ import annotations

import json
import os
import platform
import shutil
import subprocess
from pathlib import Path
from typing import Mapping, Sequence

from corpus import driver
from corpus.profiling.perf_control import PerfCollector
from runner.libs import resolve_bpftool_binary


_ARMS = frozenset({"jit", "kinsn", "kprog"})
_SYMBOL_SETTINGS = {
    Path("/proc/sys/kernel/kptr_restrict"): "0",
    Path("/proc/sys/net/core/bpf_jit_kallsyms"): "1",
}


def _required_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        raise RuntimeError(f"{name} is required")
    return value


def _perf_command(perf_root: Path, output_dir: Path) -> list[str]:
    if platform.machine() not in {"x86_64", "amd64"}:
        raise RuntimeError("Cilium call-graph profiling currently requires x86_64")
    loader = perf_root / "lib64" / "ld-linux-x86-64.so.2"
    perf = perf_root / "usr" / "lib" / "linux-tools" / "perf"
    if not loader.is_file() or not perf.is_file():
        raise RuntimeError(f"staged perf runtime is incomplete under {perf_root}")
    library_dirs = sorted(
        {str(path.parent) for path in perf_root.rglob("*.so*") if path.is_file()}
    )
    if not library_dirs:
        raise RuntimeError(f"staged perf runtime has no libraries under {perf_root}")
    control = output_dir / "guest-perf.control.fifo"
    ack = output_dir / "guest-perf.ack.fifo"
    return [
        str(loader),
        "--library-path",
        ":".join(library_dirs),
        str(perf),
        "record",
        "-a",
        "-e",
        "cpu-clock",
        "-c",
        "1000000",
        "--call-graph",
        "fp",
        "--sample-cpu",
        "--delay=-1",
        f"--control=fifo:{control},{ack}",
        "-o",
        str(output_dir / "guest.perf.data"),
    ]


def _enable_symbolization() -> None:
    for path, value in _SYMBOL_SETTINGS.items():
        if not path.is_file():
            raise RuntimeError(f"required symbolization control is missing: {path}")
        path.write_text(value + "\n", encoding="utf-8")
        if path.read_text(encoding="utf-8").strip() != value:
            raise RuntimeError(f"failed to set {path}={value}")


def _capture_symbols(output_dir: Path) -> None:
    kallsyms = Path("/proc/kallsyms").read_text(encoding="utf-8")
    if " bpf_prog_" not in kallsyms:
        raise RuntimeError(
            "/proc/kallsyms has no bpf_prog symbols; JIT symbolization is unavailable"
        )
    (output_dir / "guest.kallsyms").write_text(kallsyms, encoding="utf-8")
    (output_dir / "guest.modules").write_text(
        Path("/proc/modules").read_text(encoding="utf-8"), encoding="utf-8"
    )
    bpftool = resolve_bpftool_binary()
    completed = subprocess.run(
        [bpftool, "-j", "prog", "show"],
        check=True,
        capture_output=True,
        text=True,
    )
    payload = json.loads(completed.stdout)
    (output_dir / "guest-bpf-programs.json").write_text(
        json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


def _configure_arm(arm: str) -> str:
    os.environ.pop("BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY", None)
    if arm == "jit":
        os.environ["SKIP_REJIT"] = "norejit"
        os.environ.pop("BPFREJIT_BENCH_PASSES", None)
        os.environ.pop("BPFREJIT_SHIM_NATIVE_LOADER", None)
        return "baseline"
    os.environ.pop("SKIP_REJIT", None)
    if arm == "kinsn":
        os.environ["BPFREJIT_BENCH_PASSES"] = "default"
        os.environ.pop("BPFREJIT_SHIM_NATIVE_LOADER", None)
    elif arm == "kprog":
        os.environ.pop("BPFREJIT_BENCH_PASSES", None)
        os.environ["BPFREJIT_SHIM_NATIVE_LOADER"] = "post"
    else:
        raise RuntimeError(f"unsupported Cilium profile arm: {arm}")
    return "post_rejit"


def _profile_driver(arm: str, output_dir: Path, perf_root: Path) -> int:
    selected_phase = _configure_arm(arm)
    output_dir.mkdir(parents=True, exist_ok=True)
    original_measure = driver._measure_app_phase_with_stats
    measurement_index = 0

    def profiled_measure(**kwargs: object) -> dict[str, object]:
        nonlocal measurement_index
        phase = "baseline" if measurement_index == 0 else "post_rejit"
        measurement_index += 1
        if phase != selected_phase:
            return original_measure(**kwargs)

        _capture_symbols(output_dir)
        command = _perf_command(perf_root, output_dir)
        collector = PerfCollector(
            command=command,
            control_fifo=output_dir / "guest-perf.control.fifo",
            ack_fifo=output_dir / "guest-perf.ack.fifo",
            stderr_path=output_dir / "guest-perf.stderr.log",
        )
        metadata = {
            "arm": arm,
            "phase": phase,
            "perf_command": command,
            "sample_event": "cpu-clock",
            "sample_period_ns": 1_000_000,
            "call_graph": "frame-pointer",
        }
        (output_dir / "guest-profile.json").write_text(
            json.dumps(metadata, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )
        try:
            collector.start()
            collector.enable()
            result = original_measure(**kwargs)
            collector.disable()
            collector.finish()
        except BaseException:
            collector.abort()
            raise
        if not (output_dir / "guest.perf.data").is_file():
            raise RuntimeError("perf record completed without guest.perf.data")
        return result

    driver._measure_app_phase_with_stats = profiled_measure
    try:
        return driver.main([])
    finally:
        driver._measure_app_phase_with_stats = original_measure


def main(argv: Sequence[str] | None = None) -> int:
    if argv:
        raise RuntimeError("Cilium profiling accepts environment variables only")
    arm = _required_env("CILIUM_PROFILE_ARM")
    if arm not in _ARMS:
        raise RuntimeError(f"CILIUM_PROFILE_ARM must be one of {sorted(_ARMS)}")
    output_dir = Path(_required_env("CILIUM_PROFILE_OUTPUT_DIR")).resolve()
    perf_root = Path(_required_env("CILIUM_PROFILE_PERF_ROOT")).resolve()
    if shutil.which("bpftool") is None and not Path("/usr/local/bin/bpftool").is_file():
        raise RuntimeError("bpftool is required for Cilium profiling")
    # JIT symbols are registered when programs load, so this must precede
    # driver.main() and Cilium startup rather than only the perf snapshot.
    _enable_symbolization()
    return _profile_driver(arm, output_dir, perf_root)


if __name__ == "__main__":
    raise SystemExit(main())
