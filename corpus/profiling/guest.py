"""Profile one Cilium arm while preserving corpus.driver's lifecycle."""

from __future__ import annotations

import json
import os
import platform
import shutil
import subprocess
from pathlib import Path
from typing import Sequence

from corpus import driver
from corpus.profiling.perf_control import PerfCollector
from runner.libs import resolve_bpftool_binary


_ARMS = frozenset({"jit", "kprog"})
_SYMBOL_SETTINGS = {
    Path("/proc/sys/kernel/kptr_restrict"): "0",
    Path("/proc/sys/net/core/bpf_jit_kallsyms"): "1",
}
_SAMPLE_PERIOD_CYCLES = 7_400_000


def _required_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        raise RuntimeError(f"{name} is required")
    return value


def _perf_command(perf_root: Path, work_dir: Path) -> list[str]:
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
    control = work_dir / "guest-perf.control.fifo"
    ack = work_dir / "guest-perf.ack.fifo"
    return [
        str(loader),
        "--library-path",
        ":".join(library_dirs),
        str(perf),
        "record",
        "-a",
        "-e",
        "cycles:k",
        "-c",
        str(_SAMPLE_PERIOD_CYCLES),
        "--call-graph",
        "fp",
        "-j",
        "any_call,any_ret,k,save_type",
        "--sample-cpu",
        "--delay=-1",
        f"--control=fifo:{control},{ack}",
        "-o",
        str(work_dir / "guest.perf.data"),
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
    for filename, arguments in (
        ("guest-bpf-programs.json", ("prog", "show")),
        ("guest-bpf-net.json", ("net", "show")),
    ):
        completed = subprocess.run(
            [bpftool, "-j", *arguments],
            check=True,
            capture_output=True,
            text=True,
        )
        payload = json.loads(completed.stdout)
        (output_dir / filename).write_text(
            json.dumps(payload, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )


def _configure_arm(arm: str) -> str:
    os.environ.pop("BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY", None)
    if arm == "jit":
        os.environ["SKIP_REJIT"] = "norejit"
        os.environ.pop("BPFREJIT_BENCH_PASSES", None)
        os.environ.pop("BPFREJIT_SHIM_NATIVE_LOADER", None)
        return "baseline"
    os.environ.pop("SKIP_REJIT", None)
    if arm == "kprog":
        os.environ.pop("BPFREJIT_BENCH_PASSES", None)
        os.environ["BPFREJIT_SHIM_NATIVE_LOADER"] = "post"
    else:
        raise RuntimeError(f"unsupported Cilium profile arm: {arm}")
    return "post_rejit"


def _publish_perf_data(local_data: Path, result_data: Path) -> None:
    if not local_data.is_file():
        raise RuntimeError("perf record completed without guest-local perf data")
    local_size = local_data.stat().st_size
    if local_size == 0:
        raise RuntimeError(f"perf record produced empty data: {local_data}")
    if result_data.exists():
        raise RuntimeError(f"refusing to replace perf data: {result_data}")
    temporary = result_data.with_name(result_data.name + ".tmp")
    if temporary.exists():
        raise RuntimeError(f"refusing to replace temporary perf data: {temporary}")
    try:
        shutil.copy2(local_data, temporary)
        copied_size = temporary.stat().st_size
        if copied_size != local_size:
            raise RuntimeError(
                f"incomplete perf-data copy: expected {local_size} bytes, "
                f"copied {copied_size}"
            )
        temporary.replace(result_data)
    except BaseException as copy_error:
        try:
            temporary.unlink(missing_ok=True)
        except BaseException as cleanup_error:
            raise ExceptionGroup(
                "perf-data publication and temporary-file cleanup both failed",
                [copy_error, cleanup_error],
            ) from None
        raise


def _run_driver_then_publish(local_data: Path, result_data: Path) -> int:
    result = driver.main([])
    # The selected wrapper emits profile_measurement_done before driver.main
    # returns. Publishing only here keeps the large 9p copy outside that gate.
    _publish_perf_data(local_data, result_data)
    return result


def _print_profile_marker(event: str, phase: str) -> None:
    print(
        json.dumps(
            {"event": event, "app": "cilium/agent", "phase": phase},
            sort_keys=True,
        ),
        flush=True,
    )


def _measure_stop_and_capture(
    measure: object,
    kwargs: dict[str, object],
    collector: PerfCollector,
    output_dir: Path,
    phase: str,
) -> dict[str, object]:
    if not callable(measure):
        raise TypeError("measurement callback is not callable")
    result = measure(**kwargs)
    _print_profile_marker("profile_measurement_done", phase)
    collector.disable()
    # pktgen and its symbols only exist after the workload has started.  Keep
    # the module loaded but stop sampling before taking this audit snapshot.
    _capture_symbols(output_dir)
    return result


def _profile_driver(arm: str, output_dir: Path, perf_root: Path) -> int:
    selected_phase = _configure_arm(arm)
    output_dir.mkdir(parents=True, exist_ok=True)
    work_dir = Path("/var/tmp") / f"bpf-benchmark-cilium-profile-{os.getpid()}-{arm}"
    if work_dir.exists():
        raise RuntimeError(f"guest-local profile work directory exists: {work_dir}")
    work_dir.mkdir(mode=0o700)
    local_perf_root = work_dir / "perf-runtime"
    try:
        shutil.copytree(perf_root, local_perf_root)
    except BaseException:
        shutil.rmtree(work_dir)
        raise
    local_data = work_dir / "guest.perf.data"
    result_data = output_dir / "guest.perf.data"
    original_measure = driver._measure_app_phase_with_stats
    measurement_index = 0

    def profiled_measure(**kwargs: object) -> dict[str, object]:
        nonlocal measurement_index
        phase = "baseline" if measurement_index == 0 else "post_rejit"
        measurement_index += 1
        if phase != selected_phase:
            return original_measure(**kwargs)

        command = _perf_command(local_perf_root, work_dir)
        collector = PerfCollector(
            command=command,
            control_fifo=work_dir / "guest-perf.control.fifo",
            ack_fifo=work_dir / "guest-perf.ack.fifo",
            stderr_path=output_dir / "guest-perf.stderr.log",
        )
        metadata = {
            "arm": arm,
            "phase": phase,
            "perf_command": command,
            "sample_event": "cycles:k",
            "sample_period_cycles": _SAMPLE_PERIOD_CYCLES,
            "call_graph": "frame-pointer with LBR call/return branch stack",
            "perf_data": str(output_dir / "guest.perf.data"),
        }
        (output_dir / "guest-profile.json").write_text(
            json.dumps(metadata, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )
        try:
            collector.start()
            collector.enable()
            _print_profile_marker("profile_measurement_start", phase)
            result = _measure_stop_and_capture(
                original_measure, kwargs, collector, output_dir, phase
            )
            collector.finish()
            if not local_data.is_file():
                raise RuntimeError("perf record completed without guest-local perf data")
        except BaseException:
            collector.abort()
            raise
        return result

    driver._measure_app_phase_with_stats = profiled_measure
    try:
        return _run_driver_then_publish(local_data, result_data)
    finally:
        driver._measure_app_phase_with_stats = original_measure
        shutil.rmtree(work_dir)


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
