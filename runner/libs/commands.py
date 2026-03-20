from __future__ import annotations

from pathlib import Path
from typing import Sequence


def _append_path_option(command: list[str], flag: str, value: Path | str | None) -> None:
    if value is not None:
        command.extend([flag, str(value)])


def _append_bool_option(command: list[str], flag: str, enabled: bool) -> None:
    if enabled:
        command.append(flag)


def build_runner_command(
    runner_binary: Path | str,
    subcommand: str,
    *,
    program: Path | str,
    program_name: str | None = None,
    memory: Path | str | None = None,
    btf_custom_path: Path | str | None = None,
    directive_blob: Path | str | None = None,
    policy: str | None = None,
    policy_file: Path | str | None = None,
    policy_blob: Path | str | None = None,
    io_mode: str | None = None,
    raw_packet: bool = False,
    repeat: int | None = None,
    input_size: int | None = None,
    opt_level: int | None = None,
    no_cmov: bool = False,
    disabled_passes: Sequence[str] = (),
    log_passes: bool = False,
    perf_counters: bool = False,
    perf_scope: str | None = None,
    dump_jit: bool = False,
    dump_xlated: Path | str | None = None,
    compile_only: bool = False,
    manual_load: bool = False,
    recompile_cmov: bool = False,
    recompile_wide: bool = False,
    recompile_rotate: bool = False,
    recompile_rotate_rorx: bool = False,
    recompile_lea: bool = False,
    recompile_all: bool = False,
    recompile_v5: bool = False,
    skip_families: Sequence[str] = (),
) -> list[str]:
    command = [
        str(runner_binary),
        subcommand,
        "--program",
        str(program),
    ]
    if program_name is not None:
        command.extend(["--program-name", program_name])
    if io_mode is not None:
        command.extend(["--io-mode", io_mode])
    if repeat is not None:
        command.extend(["--repeat", str(max(1, repeat))])
    _append_path_option(command, "--memory", memory)
    if input_size is not None and input_size > 0:
        command.extend(["--input-size", str(input_size)])
    _append_path_option(command, "--btf-custom-path", btf_custom_path)
    _append_path_option(command, "--directive-blob", directive_blob)
    if policy is not None:
        command.extend(["--policy", policy])
    _append_path_option(command, "--policy-file", policy_file)
    _append_path_option(command, "--policy-blob", policy_blob)
    if opt_level is not None:
        command.extend(["--opt-level", str(opt_level)])
    for disabled_pass in disabled_passes:
        command.extend(["--llvm-disable-pass", disabled_pass])
    if perf_counters:
        command.append("--perf-counters")
        command.extend(["--perf-scope", perf_scope or "full_repeat_raw"])
    _append_bool_option(command, "--raw-packet", raw_packet)
    _append_bool_option(command, "--no-cmov", no_cmov)
    _append_bool_option(command, "--llvm-log-passes", log_passes)
    _append_bool_option(command, "--dump-jit", dump_jit)
    _append_path_option(command, "--dump-xlated", dump_xlated)
    _append_bool_option(command, "--compile-only", compile_only)
    _append_bool_option(command, "--manual-load", manual_load)
    _append_bool_option(command, "--recompile-v5", recompile_v5)
    _append_bool_option(command, "--recompile-cmov", recompile_cmov)
    _append_bool_option(command, "--recompile-wide", recompile_wide)
    _append_bool_option(command, "--recompile-rotate", recompile_rotate)
    _append_bool_option(command, "--recompile-rotate-rorx", recompile_rotate_rorx)
    _append_bool_option(command, "--recompile-lea", recompile_lea)
    _append_bool_option(command, "--recompile-all", recompile_all)
    if skip_families:
        command.extend(["--skip-families", ",".join(str(family) for family in skip_families)])
    return command


def maybe_prepend_sudo(command: Sequence[str], *, enabled: bool) -> list[str]:
    if not enabled:
        return list(command)
    return ["sudo", "-n", *command]


def build_list_programs_command(runner_binary: Path | str, program: Path | str) -> list[str]:
    return build_runner_command(runner_binary, "list-programs", program=program)


def build_scanner_command(
    scanner_binary: Path | str,
    xlated_path: Path | str,
    *,
    json_output: bool = False,
) -> list[str]:
    command = [str(scanner_binary), "scan", "--xlated", str(xlated_path), "--all", "--v5"]
    if json_output:
        command.append("--json")
    return command


def build_micro_benchmark_command(
    runner_binary: Path | str,
    *,
    runtime_mode: str,
    program: Path | str,
    io_mode: str,
    repeat: int,
    memory: Path | str | None = None,
    input_size: int | None = None,
    policy: str | None = None,
    policy_file: Path | str | None = None,
    perf_counters: bool = False,
    perf_scope: str = "full_repeat_raw",
    require_sudo: bool = False,
    blind_apply: bool = False,
) -> list[str]:
    if runtime_mode == "llvmbpf":
        command = build_runner_command(
            runner_binary,
            "run-llvmbpf",
            program=program,
            io_mode=io_mode,
            repeat=repeat,
            memory=memory,
            input_size=input_size,
            perf_counters=perf_counters,
            perf_scope=perf_scope,
        )
        return maybe_prepend_sudo(command, enabled=perf_counters)

    if runtime_mode == "kernel":
        command = build_runner_command(
            runner_binary,
            "run-kernel",
            program=program,
            io_mode=io_mode,
            repeat=repeat,
            memory=memory,
            input_size=input_size,
            perf_counters=perf_counters,
            perf_scope=perf_scope,
        )
        return maybe_prepend_sudo(command, enabled=require_sudo)

    if runtime_mode in {"kernel-recompile", "kernel_recompile"}:
        if blind_apply and (policy is not None or policy_file is not None):
            raise RuntimeError("blind_apply cannot be combined with policy or policy_file")
        command = build_runner_command(
            runner_binary,
            "run-kernel",
            program=program,
            io_mode=io_mode,
            repeat=repeat,
            memory=memory,
            input_size=input_size,
            policy=policy,
            policy_file=policy_file,
            perf_counters=perf_counters,
            perf_scope=perf_scope,
            recompile_v5=blind_apply,
            recompile_all=blind_apply,
        )
        return maybe_prepend_sudo(command, enabled=require_sudo)

    raise RuntimeError(f"unsupported runtime mode: {runtime_mode}")


__all__ = [
    "build_list_programs_command",
    "build_micro_benchmark_command",
    "build_runner_command",
    "build_scanner_command",
    "maybe_prepend_sudo",
]
