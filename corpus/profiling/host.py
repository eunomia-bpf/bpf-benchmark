"""Host controller for Cilium JIT and whole-program native profiling."""

from __future__ import annotations

import json
import os
import re
import shlex
import shutil
import signal
import subprocess
import sys
from datetime import datetime, timezone
from pathlib import Path
from typing import Sequence

from corpus.profiling.perf_control import PerfCollector


ROOT = Path(__file__).resolve().parents[2]
RESULT_ROOT = ROOT / "corpus" / "results"
RUNTIME_IMAGE_TAR = ROOT / ".cache" / "container-images" / "x86_64-runner-runtime.image.tar"
RUNTIME_KERNEL_IMAGE = (
    ROOT / "vendor" / "build" / "x86" / "linux" / "arch" / "x86" / "boot" / "bzImage"
)
PERF_CANDIDATES = (
    Path("/usr/lib/linux-hwe-6.14-tools-6.14.0-37/perf"),
    Path("/usr/lib/linux-tools-6.8.0-146/perf"),
)
ARM_PHASE = {"jit": "baseline", "kprog": "post_rejit"}
PMU_EVENTS = (
    "cpu-cycles",
    "instructions",
    "branch-instructions",
    "branch-misses",
    "cache-misses",
)


def _utc_stamp() -> str:
    return datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")


def _resolve_perf() -> Path:
    configured = os.environ.get("CILIUM_PROFILE_PERF", "").strip()
    candidates = (Path(configured),) if configured else PERF_CANDIDATES
    for candidate in candidates:
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return candidate.resolve()
    raise RuntimeError("no executable real perf binary was found")


def _parse_cpu_list(text: str) -> set[int]:
    cpus: set[int] = set()
    for token in text.strip().split(","):
        token = token.strip()
        if not token:
            continue
        if "-" in token:
            first, last = token.split("-", 1)
            start, end = int(first), int(last)
            if start > end:
                raise ValueError(f"invalid CPU range: {token}")
            cpus.update(range(start, end + 1))
        else:
            cpus.add(int(token))
    if not cpus:
        raise ValueError("CPU list is empty")
    return cpus


def _validate_cpu_allocation(cpu_list: str) -> None:
    selected = _parse_cpu_list(cpu_list)
    assigned = set(range(0, 8))
    if selected != assigned:
        raise RuntimeError(
            f"CILIUM_PROFILE_CPUS must select timing CPUs 0-7, got {cpu_list}"
        )


def _resolve_pmu(
    cpu_list: str, devices_root: Path = Path("/sys/bus/event_source/devices")
) -> str:
    selected = _parse_cpu_list(cpu_list)
    matches: list[str] = []
    for pmu in ("cpu_core", "cpu_atom", "cpu"):
        cpus_path = devices_root / pmu / "cpus"
        if not cpus_path.is_file():
            continue
        available = _parse_cpu_list(cpus_path.read_text(encoding="utf-8"))
        if selected <= available:
            matches.append(pmu)
    if len(matches) != 1:
        raise RuntimeError(
            f"CPU set {cpu_list} must map to exactly one PMU; matches={matches}"
        )
    return matches[0]


def _ldd_dependencies(binary: Path) -> list[Path]:
    completed = subprocess.run(
        ["ldd", str(binary)], check=True, capture_output=True, text=True
    )
    dependencies: set[Path] = set()
    for line in completed.stdout.splitlines():
        match = re.search(r"=>\s+(/\S+)", line)
        if match is None:
            match = re.match(r"\s*(/\S+)\s+\(", line)
        if match is not None:
            dependency = Path(match.group(1))
            if not dependency.is_file():
                raise RuntimeError(f"perf dependency is missing: {dependency}")
            # Preserve the loader-visible SONAME path (for example
            # libm.so.6), while copy2 dereferences the host symlink.
            dependencies.add(dependency)
    if not dependencies:
        raise RuntimeError(f"ldd found no dependencies for {binary}")
    return sorted(dependencies)


def _stage_perf_runtime(perf: Path, destination: Path) -> None:
    if destination.exists():
        raise RuntimeError(f"perf staging path already exists: {destination}")
    files = [perf, *_ldd_dependencies(perf)]
    for source in files:
        relative = (
            Path("usr/lib/linux-tools/perf")
            if source == perf
            else source.relative_to("/")
        )
        target = destination / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, target)


def _stage_profile_code(destination: Path) -> None:
    """Stage guest-only code through the already-mounted result directory."""
    package = destination / "corpus" / "profiling"
    package.mkdir(parents=True, exist_ok=False)
    source = ROOT / "corpus" / "profiling"
    for name in ("__init__.py", "guest.py", "perf_control.py"):
        shutil.copy2(source / name, package / name)


def _stage_guest_script(path: Path, command: Sequence[str]) -> None:
    if path.exists():
        raise RuntimeError(f"guest launch script already exists: {path}")
    path.write_text(
        "#!/bin/sh\nset -eu\nexec " + shlex.join(str(part) for part in command) + "\n",
        encoding="utf-8",
    )
    path.chmod(0o700)


def _running_guests() -> list[int]:
    pids: list[int] = []
    for entry in Path("/proc").iterdir():
        if not entry.name.isdigit():
            continue
        try:
            executable = (entry / "exe").resolve(strict=True)
        except (FileNotFoundError, PermissionError, ProcessLookupError):
            continue
        if _is_qemu_executable(executable):
            pids.append(int(entry.name))
    return sorted(pids)


def _is_qemu_executable(executable: Path) -> bool:
    return executable.name.startswith("qemu-system-")


def _preflight_runtime_artifacts() -> None:
    missing = [
        str(path.relative_to(ROOT))
        for path in (RUNTIME_IMAGE_TAR, RUNTIME_KERNEL_IMAGE)
        if not path.is_file()
    ]
    if missing:
        raise RuntimeError(
            "validated KVM runtime artifacts are missing (agent 1 must build them): "
            + ", ".join(missing)
        )


def _progress_marker(line: str, phase: str) -> str | None:
    stripped = line.strip()
    if not stripped.startswith("{"):
        return None
    try:
        payload = json.loads(stripped)
    except json.JSONDecodeError:
        return None
    if payload.get("app") != "cilium/agent" or payload.get("phase") != phase:
        return None
    event = str(payload.get("event") or "")
    marker_events = {
        "profile_measurement_start": "measurement_start",
        "profile_measurement_done": "measurement_done",
    }
    return marker_events.get(event)


def _stat_command(
    perf: Path, pmu: str, cpus: str, output_dir: Path
) -> tuple[list[str], Path, Path]:
    control = output_dir / "host-stat.control.fifo"
    ack = output_dir / "host-stat.ack.fifo"
    command = ["sudo", "-n", str(perf), "stat", "-a", "-C", cpus]
    for event in PMU_EVENTS:
        command.extend(("-e", f"{pmu}/{event}/G"))
    command.extend(
        (
            "--delay=-1",
            f"--control=fifo:{control},{ack}",
            "-x,",
            "-o",
            str(output_dir / "host-perf-stat.csv"),
        )
    )
    return command, control, ack


def _make_command(
    *,
    cpus: str,
    guest_script: Path,
) -> list[str]:
    return [
        "taskset",
        "-c",
        cpus,
        "make",
        "-o",
        "x86-runner-runtime-image-tar",
        "__profile-cilium-vm",
        "PLATFORM=kvm",
        "ARCH=x86",
        f"VM_CPU_PIN={cpus}",
        "VM_CPUS=8",
        "VM_MEM=64G",
        f"CILIUM_PROFILE_GUEST_SCRIPT={guest_script}",
    ]


def _guest_make_command(
    *, arm: str, duration: int, output_dir: Path, perf_root: Path, code_root: Path
) -> list[str]:
    return [
        "make",
        "-C",
        str(ROOT),
        "__runtime-vm-profile-cilium",
        "PLATFORM=kvm",
        "ARCH=x86",
        "BPFREJIT_CORPUS_APPS=cilium/agent",
        f"WORKLOAD_DURATION={duration}",
        "SAMPLES=1",
        "WARMUPS=0",
        "BPFREJIT_CORPUS_BPF_STATS=1",
        "TIMEOUT=1800",
        f"CILIUM_PROFILE_ARM={arm}",
        f"CILIUM_PROFILE_OUTPUT_DIR={output_dir}",
        f"CILIUM_PROFILE_PERF_ROOT={perf_root}",
        f"CILIUM_PROFILE_CODE_ROOT={code_root}",
    ]


def _corpus_runs() -> set[Path]:
    return {path.resolve() for path in RESULT_ROOT.glob("x86_kvm_corpus_*") if path.is_dir()}


def _run_arm(
    *,
    arm: str,
    duration: int,
    cpus: str,
    perf: Path,
    perf_root: Path,
    code_root: Path,
    root: Path,
    run_id: str,
    order: str,
    position: int,
) -> Path:
    phase = ARM_PHASE[arm]
    output_dir = root / run_id
    output_dir.mkdir(parents=True, exist_ok=False)
    pmu = _resolve_pmu(cpus)
    stat_command, stat_control, stat_ack = _stat_command(perf, pmu, cpus, output_dir)
    guest_script = code_root / f"run-{run_id.replace('/', '-')}.sh"
    guest_make_command = _guest_make_command(
        arm=arm,
        duration=duration,
        output_dir=output_dir,
        perf_root=perf_root,
        code_root=code_root,
    )
    _stage_guest_script(guest_script, guest_make_command)
    make_command = _make_command(
        cpus=cpus,
        guest_script=guest_script,
    )
    metadata: dict[str, object] = {
        "arm": arm,
        "run_id": run_id,
        "order": order,
        "position": position,
        "phase": phase,
        "host_cpu_set": cpus,
        "host_pmu": pmu,
        "vm_cpus": 8,
        "vm_memory": "64G",
        "workload_duration_seconds": duration,
        "make_command": make_command,
        "guest_make_command": guest_make_command,
        "host_perf_command": stat_command,
        "git_head": subprocess.check_output(
            ["git", "rev-parse", "HEAD"], cwd=ROOT, text=True
        ).strip(),
        "host_kernel": subprocess.check_output(["uname", "-a"], text=True).strip(),
        "perf_version": subprocess.check_output(
            [str(perf), "--version"], text=True
        ).strip(),
        "started_at": datetime.now(timezone.utc).isoformat(),
    }
    metadata_path = output_dir / "commands.json"
    metadata_path.write_text(
        json.dumps(metadata, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    stat_collector = PerfCollector(
        command=stat_command,
        control_fifo=stat_control,
        ack_fifo=stat_ack,
        stderr_path=output_dir / "host-perf.stderr.log",
        use_sudo_for_signals=True,
    )
    before = _corpus_runs()
    make_log = (output_dir / "make.log").open("w", encoding="utf-8")
    make_process: subprocess.Popen[str] | None = None
    marker_count = 0
    try:
        stat_collector.start()
        make_process = subprocess.Popen(
            make_command,
            cwd=ROOT,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
            start_new_session=True,
        )
        assert make_process.stdout is not None
        for line in make_process.stdout:
            sys.stdout.write(line)
            sys.stdout.flush()
            make_log.write(line)
            make_log.flush()
            event = _progress_marker(line, phase)
            if event == "measurement_start":
                stat_collector.enable()
                marker_count += 1
            elif event == "measurement_done":
                stat_collector.disable()
                marker_count += 1
        returncode = make_process.wait()
        if returncode != 0:
            raise RuntimeError(f"Cilium {arm} profiling make exited {returncode}")
        if marker_count != 2:
            raise RuntimeError(
                f"Cilium {arm} emitted {marker_count} selected-phase markers, expected 2"
            )
        stat_collector.finish()
        new_runs = _corpus_runs() - before
        if len(new_runs) != 1:
            raise RuntimeError(
                f"Cilium {arm} produced {len(new_runs)} corpus run directories, expected 1"
            )
        corpus_run = new_runs.pop()
        metadata["finished_at"] = datetime.now(timezone.utc).isoformat()
        metadata["make_returncode"] = returncode
        metadata["corpus_run"] = str(corpus_run.relative_to(ROOT))
        metadata_path.write_text(
            json.dumps(metadata, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )
        return corpus_run
    except BaseException as exc:
        metadata["failed_at"] = datetime.now(timezone.utc).isoformat()
        metadata["error"] = f"{type(exc).__name__}: {exc}"
        metadata_path.write_text(
            json.dumps(metadata, indent=2, sort_keys=True) + "\n",
            encoding="utf-8",
        )
        stat_collector.abort()
        raise
    finally:
        if make_process is not None and make_process.poll() is None:
            os.killpg(make_process.pid, signal.SIGTERM)
            try:
                make_process.wait(timeout=30)
            except subprocess.TimeoutExpired:
                os.killpg(make_process.pid, signal.SIGKILL)
                make_process.wait(timeout=10)
        make_log.close()


def _parse_arms(raw: str) -> list[str]:
    normalized = raw.strip().lower()
    if normalized == "all":
        return ["jit", "kprog"]
    arms = [item.strip() for item in normalized.split(",") if item.strip()]
    unknown = sorted(set(arms) - set(ARM_PHASE))
    if not arms or unknown or len(arms) != len(set(arms)):
        raise RuntimeError(
            "CILIUM_PROFILE_ARM must be all or a unique comma-separated subset of "
            f"{sorted(ARM_PHASE)}; unknown={unknown}"
        )
    return arms


def _profile_plan(arms: Sequence[str], order: str) -> list[dict[str, object]]:
    normalized = order.strip().lower()
    if len(arms) == 1:
        if normalized not in {"both", "single"}:
            raise RuntimeError("single-arm profiling requires CILIUM_PROFILE_ORDER=single")
        arm = arms[0]
        return [{"run_id": f"single/01-{arm}", "order": "single", "position": 1, "arm": arm}]
    if list(arms) != ["jit", "kprog"]:
        raise RuntimeError("counterbalanced profiling requires both jit and kprog arms")
    orders = {
        "both": (("jit-kprog", ("jit", "kprog")), ("kprog-jit", ("kprog", "jit"))),
        "jit-kprog": (("jit-kprog", ("jit", "kprog")),),
        "kprog-jit": (("kprog-jit", ("kprog", "jit")),),
    }
    if normalized not in orders:
        raise RuntimeError(
            "CILIUM_PROFILE_ORDER must be both, jit-kprog, or kprog-jit"
        )
    plan: list[dict[str, object]] = []
    for order_name, ordered_arms in orders[normalized]:
        for position, arm in enumerate(ordered_arms, start=1):
            plan.append(
                {
                    "run_id": f"{order_name}/{position:02d}-{arm}",
                    "order": order_name,
                    "position": position,
                    "arm": arm,
                }
            )
    return plan


def _resolve_profile_root(configured: str) -> Path:
    profile_root = (
        Path(configured).resolve()
        if configured
        else RESULT_ROOT / f"cilium_profile_{_utc_stamp()}"
    )
    try:
        relative = profile_root.relative_to(RESULT_ROOT)
    except ValueError as exc:
        raise RuntimeError(
            f"CILIUM_PROFILE_OUTPUT_DIR must be below {RESULT_ROOT}"
        ) from exc
    if relative == Path("."):
        raise RuntimeError("CILIUM_PROFILE_OUTPUT_DIR cannot be corpus/results itself")
    return profile_root


def main(argv: Sequence[str] | None = None) -> int:
    if argv:
        raise RuntimeError("Cilium profiling accepts Make variables only")
    guests = _running_guests()
    if guests:
        raise RuntimeError(f"refusing to profile while QEMU guests are running: {guests}")
    if os.geteuid() == 0:
        raise RuntimeError("run make profile-cilium as the workspace user")
    _preflight_runtime_artifacts()
    duration = int(os.environ.get("CILIUM_PROFILE_DURATION", "60"))
    if duration <= 0:
        raise RuntimeError("CILIUM_PROFILE_DURATION must be positive")
    cpus = os.environ.get("CILIUM_PROFILE_CPUS", "0-7").strip()
    _validate_cpu_allocation(cpus)
    arms = _parse_arms(os.environ.get("CILIUM_PROFILE_ARM", "all"))
    plan = _profile_plan(arms, os.environ.get("CILIUM_PROFILE_ORDER", "both"))
    configured_output = os.environ.get("CILIUM_PROFILE_OUTPUT_DIR", "").strip()
    profile_root = _resolve_profile_root(configured_output)
    profile_root.mkdir(parents=True, exist_ok=False)
    perf = _resolve_perf()
    perf_root = profile_root / ".perf-tools"
    code_root = profile_root / ".profile-code"
    try:
        _stage_perf_runtime(perf, perf_root)
        _stage_profile_code(code_root)
        runs: list[dict[str, object]] = []
        for planned in plan:
            arm = str(planned["arm"])
            corpus_run = _run_arm(
                arm=arm,
                duration=duration,
                cpus=cpus,
                perf=perf,
                perf_root=perf_root,
                code_root=code_root,
                root=profile_root,
                run_id=str(planned["run_id"]),
                order=str(planned["order"]),
                position=int(planned["position"]),
            )
            runs.append(
                {
                    **planned,
                    "profile_dir": str(planned["run_id"]),
                    "corpus_run": str(corpus_run.relative_to(ROOT)),
                }
            )
            (profile_root / "profile-runs.json").write_text(
                json.dumps(runs, indent=2, sort_keys=True) + "\n",
                encoding="utf-8",
            )
        (profile_root / "profile-runs.json").write_text(
            json.dumps(
                runs,
                indent=2,
                sort_keys=True,
            )
            + "\n",
            encoding="utf-8",
        )
    finally:
        if perf_root.exists():
            shutil.rmtree(perf_root)
        if code_root.exists():
            shutil.rmtree(code_root)
    subprocess.run(
        [
            sys.executable,
            str(ROOT / "analysis" / "cilium_profile_report.py"),
            "--profile-root",
            str(profile_root),
            "--perf",
            str(perf),
        ],
        cwd=ROOT,
        check=True,
    )
    print(profile_root.relative_to(ROOT))
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, RuntimeError, subprocess.SubprocessError, ValueError) as exc:
        print(f"cilium profile: {exc}", file=sys.stderr)
        raise SystemExit(1)
