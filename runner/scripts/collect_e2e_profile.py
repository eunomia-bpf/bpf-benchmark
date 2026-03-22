#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from typing import Any, Callable, Mapping, Sequence

if __package__ in {None, ""}:
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import ROOT_DIR, prepare_bpftool_environment, write_json  # noqa: E402
from runner.libs.metrics import enable_bpf_stats  # noqa: E402
from runner.libs.profiler import DEFAULT_DAEMON, profile_programs  # noqa: E402
from runner.libs.workload import WorkloadResult  # noqa: E402

from e2e.cases.tracee.case import (  # noqa: E402
    DEFAULT_CONFIG as DEFAULT_TRACEE_CONFIG,
    DEFAULT_RUNNER as DEFAULT_TRACEE_RUNNER,
    DEFAULT_DAEMON as DEFAULT_TRACEE_SCANNER,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TRACEE_SETUP_SCRIPT,
    DEFAULT_TRACEE_OBJECT,
    ManualLibbpf as TraceeManualLibbpf,
    ManualTraceeSession,
    TraceeAgentSession,
    build_tracee_commands,
    ensure_artifacts as ensure_tracee_artifacts,
    load_config as load_tracee_config,
    resolve_tracee_binary,
    run_setup_script as run_tracee_setup,
    run_workload as run_tracee_workload,
    select_manual_programs,
)
from e2e.cases.tetragon.case import (  # noqa: E402
    DEFAULT_DURATION_S as DEFAULT_TETRAGON_DURATION_S,
    DEFAULT_EXECVE_OBJECT,
    DEFAULT_KPROBE_OBJECT,
    DEFAULT_LOAD_TIMEOUT_S as DEFAULT_TETRAGON_LOAD_TIMEOUT_S,
    DEFAULT_RUNNER as DEFAULT_TETRAGON_RUNNER,
    DEFAULT_DAEMON as DEFAULT_TETRAGON_SCANNER,
    DEFAULT_SETUP_SCRIPT as DEFAULT_TETRAGON_SETUP_SCRIPT,
    DEFAULT_SMOKE_DURATION_S as DEFAULT_TETRAGON_SMOKE_DURATION_S,
    DEFAULT_WORKLOADS as DEFAULT_TETRAGON_WORKLOADS,
    Libbpf as TetragonLibbpf,
    ManualProgramSession,
    RuntimeStatsHandle,
    TetragonAgentSession,
    build_manual_targets,
    ensure_artifacts as ensure_tetragon_artifacts,
    resolve_tetragon_binary,
    run_setup_script as run_tetragon_setup,
    run_workload as run_tetragon_workload,
    write_tetragon_policies,
)
from e2e.cases.katran.case import (  # noqa: E402
    CLIENT_NS,
    DEFAULT_DURATION_S as DEFAULT_KATRAN_DURATION_S,
    DEFAULT_KATRAN_OBJECT,
    DEFAULT_PROGRAM_NAME as DEFAULT_KATRAN_PROGRAM_NAME,
    DEFAULT_RUNNER as DEFAULT_KATRAN_RUNNER,
    DEFAULT_DAEMON as DEFAULT_KATRAN_SCANNER,
    DEFAULT_SETUP_SCRIPT as DEFAULT_KATRAN_SETUP_SCRIPT,
    DEFAULT_SMOKE_DURATION_S as DEFAULT_KATRAN_SMOKE_DURATION_S,
    DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS,
    DEFAULT_SMOKE_PACKET_REPEAT,
    DEFAULT_SMOKE_WARMUP_DURATION_S,
    DEFAULT_SMOKE_WRK_CONNECTIONS,
    DEFAULT_SMOKE_WRK_THREADS,
    DEFAULT_MIN_MEASUREMENT_REQUESTS,
    DEFAULT_PACKET_REPEAT,
    DEFAULT_WARMUP_DURATION_S,
    DEFAULT_WRK_CONNECTIONS,
    DEFAULT_WRK_THREADS,
    KatranDirectSession,
    KatranDsrTopology,
    NamespaceHttpServer,
    REAL_NS,
    ROOT_DIR as KATRAN_ROOT_DIR,
    TOPOLOGY_SETTLE_S,
    VIP_IP,
    VIP_PORT,
    bpftool_binary as katran_bpftool_binary,
    configure_katran_maps,
    ensure_artifacts as ensure_katran_artifacts,
    measure_phase as measure_katran_phase,
    resolve_katran_server_binary,
    run_setup_script as run_katran_setup,
    wrk_binary,
)

try:  # noqa: E402
    from runner.libs.inventory import discover_object_programs
except ModuleNotFoundError:  # noqa: E402
    sys.path.insert(0, str(ROOT_DIR / "micro"))
    from runner.libs.inventory import discover_object_programs


def utc_now() -> str:
    return datetime.now(timezone.utc).isoformat()


def as_result_dict(result: WorkloadResult) -> dict[str, Any]:
    return result.to_dict()


def duration_plan(total_duration_s: float, item_count: int) -> list[int]:
    if item_count <= 0:
        return []
    total = max(1, int(round(float(total_duration_s))))
    if item_count <= 1:
        return [total]
    if total < item_count:
        return [total] + [0] * (item_count - 1)
    base = total // item_count
    remainder = total % item_count
    plan = []
    for index in range(item_count):
        plan.append(base + (1 if index < remainder else 0))
    return plan


def run_profiled_workloads(
    workload_specs: Sequence[Any],
    total_duration_s: float,
    *,
    runner: Callable[[Any, int], WorkloadResult],
    name_getter: Callable[[Any], str],
) -> list[dict[str, Any]]:
    records: list[dict[str, Any]] = []
    durations = duration_plan(total_duration_s, len(workload_specs))
    for spec, planned_duration_s in zip(workload_specs, durations, strict=False):
        if planned_duration_s <= 0:
            continue
        result = runner(spec, int(planned_duration_s))
        records.append(
            {
                "name": name_getter(spec),
                "requested_duration_s": int(planned_duration_s),
                "result": as_result_dict(result),
            }
        )
    return records


def tracee_name(spec: Any) -> str:
    if isinstance(spec, Mapping):
        return str(spec.get("name") or spec.get("kind") or "tracee-workload")
    return str(spec)


def tetragon_name(spec: Any) -> str:
    return str(getattr(spec, "name", None) or getattr(spec, "kind", None) or "tetragon-workload")


def add_common_profile_args(parser: argparse.ArgumentParser) -> None:
    parser.add_argument("--duration", type=float, help="Profiling window in seconds.")
    parser.add_argument("--output-json", required=True, help="Output JSON path.")
    parser.add_argument(
        "--daemon",
        default=str(DEFAULT_DAEMON),
        help="Path to bpfrejit-daemon used for live enumerate.",
    )
    parser.add_argument("--no-sites", action="store_true", help="Skip live enumerate site census collection.")
    parser.add_argument("--no-perf", action="store_true", help="Skip perf stat collection.")
    parser.add_argument("--perf-events", default="cycles,instructions,branches,branch-misses")
    parser.add_argument("--perf-max-workers", type=int, default=8)
    parser.add_argument("--skip-setup", action="store_true", help="Skip workload-specific setup.sh.")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Collect runtime BPF profiles for E2E workloads.")
    subparsers = parser.add_subparsers(dest="case", required=True)

    tracee = subparsers.add_parser("tracee", help="Collect a Tracee profile.")
    add_common_profile_args(tracee)
    tracee.add_argument("--config", default=str(DEFAULT_TRACEE_CONFIG))
    tracee.add_argument("--setup-script", default=str(DEFAULT_TRACEE_SETUP_SCRIPT))
    tracee.add_argument("--tracee-object", default=str(DEFAULT_TRACEE_OBJECT))
    tracee.add_argument("--runner", default=str(DEFAULT_TRACEE_RUNNER))
    tracee.add_argument("--tracee-binary")
    tracee.add_argument("--load-timeout", type=int, default=20)
    tracee.add_argument("--smoke", action="store_true", help="Use smoke duration from the Tracee config when --duration is omitted.")
    tracee.add_argument("--force-direct", action="store_true", help="Force manual fallback instead of Tracee daemon mode.")
    tracee.add_argument("--tracee-extra-arg", action="append", default=[])

    tetragon = subparsers.add_parser("tetragon", help="Collect a Tetragon profile.")
    add_common_profile_args(tetragon)
    tetragon.add_argument("--setup-script", default=str(DEFAULT_TETRAGON_SETUP_SCRIPT))
    tetragon.add_argument("--runner", default=str(DEFAULT_TETRAGON_RUNNER))
    tetragon.add_argument("--execve-object", default=str(DEFAULT_EXECVE_OBJECT))
    tetragon.add_argument("--kprobe-object", default=str(DEFAULT_KPROBE_OBJECT))
    tetragon.add_argument("--tetragon-binary")
    tetragon.add_argument("--load-timeout", type=int, default=DEFAULT_TETRAGON_LOAD_TIMEOUT_S)
    tetragon.add_argument("--force-direct", action="store_true", help="Force manual fallback instead of daemon mode.")
    tetragon.add_argument("--smoke", action="store_true", help="Use smoke defaults when --duration is omitted.")

    katran = subparsers.add_parser("katran", help="Collect a Katran profile.")
    add_common_profile_args(katran)
    katran.add_argument("--setup-script", default=str(DEFAULT_KATRAN_SETUP_SCRIPT))
    katran.add_argument("--runner", default=str(DEFAULT_KATRAN_RUNNER))
    katran.add_argument("--katran-object", default=str(DEFAULT_KATRAN_OBJECT))
    katran.add_argument("--katran-server-binary")
    katran.add_argument("--katran-iface", default="katran0")
    katran.add_argument("--katran-router-peer-iface")
    katran.add_argument("--katran-packet-repeat", type=int)
    katran.add_argument("--katran-use-wrk", action="store_true")
    katran.add_argument("--katran-wrk-connections", type=int)
    katran.add_argument("--katran-wrk-threads", type=int)
    katran.add_argument("--katran-warmup-duration", type=float)
    katran.add_argument("--smoke", action="store_true", help="Use smoke defaults when --duration is omitted.")
    return parser


def parse_csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value).split(",") if token.strip()]


def profiler_options(args: argparse.Namespace) -> dict[str, Any]:
    return {
        "daemon_binary": Path(args.daemon).resolve(),
        "include_sites": not bool(args.no_sites),
        "collect_perf": not bool(args.no_perf),
        "perf_events": parse_csv_tokens(args.perf_events),
        "perf_max_workers": max(1, int(args.perf_max_workers)),
    }


def run_tracee_collection(args: argparse.Namespace) -> dict[str, Any]:
    runner_binary = Path(args.runner).resolve()
    daemon_binary = Path(args.daemon).resolve()
    tracee_object = Path(args.tracee_object).resolve()
    config_path = Path(args.config).resolve()
    setup_script = Path(args.setup_script).resolve()
    ensure_tracee_artifacts(runner_binary, daemon_binary)
    config = load_tracee_config(config_path)
    setup_result = {"returncode": 0, "tracee_binary": None, "stdout_tail": "", "stderr_tail": ""}
    if not args.skip_setup:
        setup_result = run_tracee_setup(setup_script)
    if args.duration is not None:
        duration_s = float(args.duration)
    elif bool(args.smoke) and bool(config.get("smoke_duration_s")):
        duration_s = float(config.get("smoke_duration_s"))
    else:
        duration_s = float(config.get("measurement_duration_s") or 30.0)

    with enable_bpf_stats():
        tracee_binary = None if args.force_direct else resolve_tracee_binary(args.tracee_binary, setup_result)
        if tracee_binary:
            commands = build_tracee_commands(tracee_binary, list(config.get("events") or []), args.tracee_extra_arg or [])
            with TraceeAgentSession(commands, load_timeout=int(args.load_timeout)) as session:
                workload_records: list[dict[str, Any]] = []

                def activity(window_s: float) -> None:
                    workload_records.extend(
                        run_profiled_workloads(
                            list(config.get("workloads") or []),
                            window_s,
                            runner=run_tracee_workload,
                            name_getter=tracee_name,
                        )
                    )

                profile = profile_programs(
                    list(session.program_fds.keys()) or [int(program["id"]) for program in session.programs],
                    duration_s=duration_s,
                    prog_fds=session.program_fds,
                    activity=activity,
                    metadata={"case": "tracee", "mode": "tracee_daemon", "config": str(config_path)},
                    **profiler_options(args),
                )
                return {
                    "generated_at": utc_now(),
                    "case": "tracee",
                    "mode": "tracee_daemon",
                    "duration_s": duration_s,
                    "config": str(config_path),
                    "setup": setup_result,
                    "tracee_binary": tracee_binary,
                    "tracee_launch_command": session.command_used,
                    "tracee_programs": session.programs,
                    "workloads": workload_records,
                    "agent_snapshot": session.collector_snapshot(),
                    "profile": profile,
                }

        inventory = discover_object_programs(runner_binary, tracee_object)
        selected = select_manual_programs(inventory)
        with ManualTraceeSession(TraceeManualLibbpf(), tracee_object, selected) as session:
            workload_records: list[dict[str, Any]] = []

            def activity(window_s: float) -> None:
                workload_records.extend(
                    run_profiled_workloads(
                        list(config.get("workloads") or []),
                        window_s,
                        runner=run_tracee_workload,
                        name_getter=tracee_name,
                    )
                )

            prog_ids = [int(handle.prog_id) for handle in session.program_handles.values()]
            prog_fds = {int(handle.prog_id): int(handle.prog_fd) for handle in session.program_handles.values()}
            profile = profile_programs(
                prog_ids,
                duration_s=duration_s,
                prog_fds=prog_fds,
                activity=activity,
                metadata={"case": "tracee", "mode": "manual_fallback", "config": str(config_path)},
                **profiler_options(args),
            )
            return {
                "generated_at": utc_now(),
                "case": "tracee",
                "mode": "manual_fallback",
                "duration_s": duration_s,
                "config": str(config_path),
                "setup": setup_result,
                "tracee_binary": None,
                "tracee_programs": [
                    {"name": entry.name, "section_name": entry.section_name}
                    for entry in selected
                ],
                "workloads": workload_records,
                "profile": profile,
            }


def run_tetragon_collection(args: argparse.Namespace) -> dict[str, Any]:
    runner_binary = Path(args.runner).resolve()
    daemon_binary = Path(args.daemon).resolve()
    execve_object = Path(args.execve_object).resolve()
    kprobe_object = Path(args.kprobe_object).resolve()
    setup_script = Path(args.setup_script).resolve()
    ensure_tetragon_artifacts(runner_binary, daemon_binary)
    setup_result = {
        "returncode": 0,
        "tetragon_binary": None,
        "tetra_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_tetragon_setup(setup_script)
    duration_s = float(
        args.duration
        if args.duration is not None
        else (DEFAULT_TETRAGON_SMOKE_DURATION_S if bool(args.smoke) else DEFAULT_TETRAGON_DURATION_S)
    )
    libbpf = TetragonLibbpf()

    with RuntimeStatsHandle(libbpf):
        tetragon_binary = None if args.force_direct else resolve_tetragon_binary(args.tetragon_binary, setup_result)
        if tetragon_binary:
            with tempfile.TemporaryDirectory(prefix="tetragon-profile-policies-") as tempdir:
                policy_dir = Path(tempdir)
                policy_paths = write_tetragon_policies(policy_dir)
                command = [tetragon_binary, "--tracing-policy-dir", str(policy_dir)]
                try:
                    with TetragonAgentSession(command, int(args.load_timeout)) as session:
                        workload_records: list[dict[str, Any]] = []

                        def activity(window_s: float) -> None:
                            workload_records.extend(
                                run_profiled_workloads(
                                    list(DEFAULT_TETRAGON_WORKLOADS),
                                    window_s,
                                    runner=run_tetragon_workload,
                                    name_getter=tetragon_name,
                                )
                            )

                        profile = profile_programs(
                            [int(program["id"]) for program in session.programs],
                            duration_s=duration_s,
                            activity=activity,
                            metadata={"case": "tetragon", "mode": "tetragon_daemon"},
                            **profiler_options(args),
                        )
                        return {
                            "generated_at": utc_now(),
                            "case": "tetragon",
                            "mode": "tetragon_daemon",
                            "duration_s": duration_s,
                            "setup": setup_result,
                            "tetragon_binary": tetragon_binary,
                            "tetragon_launch_command": command,
                            "policy_dir": str(policy_dir),
                            "policy_paths": [str(path) for path in policy_paths],
                            "tetragon_programs": session.programs,
                            "workloads": workload_records,
                            "agent_logs": session.collector_snapshot(),
                            "profile": profile,
                        }
                except Exception as exc:
                    fallback_reason = str(exc)
                else:
                    fallback_reason = ""
        else:
            fallback_reason = ""

        opened: list[ManualProgramSession] = []
        from contextlib import ExitStack

        with ExitStack() as stack:
            for spec in build_manual_targets(execve_object, kprobe_object):
                opened.append(stack.enter_context(ManualProgramSession(libbpf, spec)))
            workload_records: list[dict[str, Any]] = []

            def activity(window_s: float) -> None:
                workload_records.extend(
                    run_profiled_workloads(
                        list(DEFAULT_TETRAGON_WORKLOADS),
                        window_s,
                        runner=run_tetragon_workload,
                        name_getter=tetragon_name,
                    )
                )

            profile = profile_programs(
                [int(session.prog_id or 0) for session in opened if int(session.prog_id or 0) > 0],
                duration_s=duration_s,
                activity=activity,
                metadata={"case": "tetragon", "mode": "manual_fallback"},
                **profiler_options(args),
            )
            payload = {
                "generated_at": utc_now(),
                "case": "tetragon",
                "mode": "manual_fallback",
                "duration_s": duration_s,
                "setup": setup_result,
                "tetragon_binary": None,
                "tetragon_programs": [session.metadata() for session in opened],
                "workloads": workload_records,
                "profile": profile,
            }
            if fallback_reason:
                payload["fallback_reason"] = fallback_reason
            return payload


def run_katran_collection(args: argparse.Namespace) -> dict[str, Any]:
    prepare_bpftool_environment()
    resolved_bpftool = katran_bpftool_binary()
    if Path(resolved_bpftool).exists():
        os.environ["PATH"] = f"{Path(resolved_bpftool).parent}:{os.environ.get('PATH', '')}"
        os.environ["BPFTOOL_BIN"] = resolved_bpftool

    runner_binary = Path(args.runner).resolve()
    daemon_binary = Path(args.daemon).resolve()
    katran_object = Path(args.katran_object).resolve()
    setup_script = Path(args.setup_script).resolve()
    ensure_katran_artifacts(runner_binary, daemon_binary)
    duration_s = float(
        args.duration
        if args.duration is not None
        else (DEFAULT_KATRAN_SMOKE_DURATION_S if bool(args.smoke) else DEFAULT_KATRAN_DURATION_S)
    )
    wrk_connections = max(
        1,
        int(args.katran_wrk_connections or (DEFAULT_SMOKE_WRK_CONNECTIONS if args.smoke else DEFAULT_WRK_CONNECTIONS)),
    )
    wrk_threads = max(
        1,
        int(args.katran_wrk_threads or (DEFAULT_SMOKE_WRK_THREADS if args.smoke else DEFAULT_WRK_THREADS)),
    )
    warmup_duration_s = float(
        args.katran_warmup_duration or (DEFAULT_SMOKE_WARMUP_DURATION_S if args.smoke else DEFAULT_WARMUP_DURATION_S)
    )
    traffic_iterations = max(
        1,
        int(args.katran_packet_repeat or (DEFAULT_SMOKE_PACKET_REPEAT if args.smoke else DEFAULT_PACKET_REPEAT)),
    )
    minimum_requests = max(
        traffic_iterations,
        DEFAULT_SMOKE_MIN_MEASUREMENT_REQUESTS if args.smoke else DEFAULT_MIN_MEASUREMENT_REQUESTS,
    )
    use_wrk_driver = bool(args.katran_use_wrk and wrk_binary() is not None)
    setup_result = {
        "returncode": 0,
        "katran_server_binary": None,
        "stdout_tail": "",
        "stderr_tail": "",
    }
    if not args.skip_setup:
        setup_result = run_katran_setup(setup_script)
    server_binary = resolve_katran_server_binary(args.katran_server_binary, setup_result)

    with enable_bpf_stats():
        with KatranDsrTopology(args.katran_iface, router_peer_iface=args.katran_router_peer_iface) as topology:
            with NamespaceHttpServer(REAL_NS, VIP_IP, VIP_PORT) as http_server:
                with KatranDirectSession(
                    object_path=katran_object,
                    program_name=DEFAULT_KATRAN_PROGRAM_NAME,
                    iface=args.katran_iface,
                    attach=True,
                    bpftool=resolved_bpftool,
                ) as session:
                    if session.attach_error:
                        raise RuntimeError(f"failed to attach Katran XDP program: {session.attach_error}")
                    map_config = configure_katran_maps(session)
                    time.sleep(TOPOLOGY_SETTLE_S)
                    workload_records: list[dict[str, Any]] = []

                    def activity(window_s: float) -> None:
                        workload_records.append(
                            measure_katran_phase(
                                index=0,
                                phase_name="profile",
                                session=session,
                                traffic_iterations=traffic_iterations,
                                duration_s=max(1, int(round(window_s))),
                                minimum_requests=minimum_requests,
                                warmup_request_count=0 if use_wrk_driver else max(traffic_iterations, 100),
                                warmup_duration_s=warmup_duration_s,
                                use_wrk_driver=use_wrk_driver,
                                wrk_connections=wrk_connections,
                                wrk_threads=wrk_threads,
                            )
                        )

                    profile = profile_programs(
                        [int(session.prog_id)],
                        duration_s=duration_s,
                        activity=activity,
                        metadata={
                            "case": "katran",
                            "mode": "katran_dsr_direct_map",
                            "client_namespace": CLIENT_NS,
                            "vip": f"{VIP_IP}:{VIP_PORT}",
                        },
                        **profiler_options(args),
                    )
                    return {
                        "generated_at": utc_now(),
                        "case": "katran",
                        "mode": "katran_dsr_direct_map",
                        "duration_s": duration_s,
                        "setup": setup_result,
                        "katran_server_binary": server_binary,
                        "katran_object": str(katran_object),
                        "live_program": session.metadata(),
                        "topology": topology.metadata(),
                        "http_server": http_server.metadata(),
                        "map_config": map_config,
                        "workloads": workload_records,
                        "profile": profile,
                    }


def main(argv: list[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    if args.case == "tracee":
        payload = run_tracee_collection(args)
    elif args.case == "tetragon":
        payload = run_tetragon_collection(args)
    elif args.case == "katran":
        payload = run_katran_collection(args)
    else:
        raise SystemExit(f"unsupported case: {args.case}")
    write_json(Path(args.output_json).resolve(), payload)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
