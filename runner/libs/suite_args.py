from __future__ import annotations

import argparse
import os
import shlex
from functools import partial
from pathlib import Path

from runner.libs.cli_support import fail
from runner.libs.state_file import read_json_object, write_json_object


_die = partial(fail, "suite-args")
MICRO_BENCHMARK_DEFAULT_SAMPLES = "1"
MICRO_BENCHMARK_DEFAULT_WARMUPS = "0"
MICRO_BENCHMARK_DEFAULT_INNER_REPEAT = "10"


def _env(env: dict[str, str], name: str, default: str = "") -> str:
    return str(env.get(name, "")).strip() or default


def _aws_prefix(target_name: str) -> str:
    if target_name == "aws-arm64":
        return "AWS_ARM64"
    if target_name == "aws-x86":
        return "AWS_X86"
    return ""


def _prefixed_env(env: dict[str, str], prefix: str, suffix: str, default: str = "") -> str:
    return _env(env, f"{prefix}_{suffix}", default)


def csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value or "").split(",") if token.strip()]


def join_csv(tokens: list[str]) -> str:
    return ",".join(token for token in tokens if token)


def _merge_csv_and_repeated(csv_value: str, repeated_values: list[str] | None) -> str:
    merged: list[str] = []
    for token in [*csv_tokens(csv_value), *(repeated_values or [])]:
        normalized = str(token).strip()
        if normalized and normalized not in merged:
            merged.append(normalized)
    return join_csv(merged)


def _append_value(args: list[str], option: str, value: str) -> None:
    if str(value).strip():
        args.extend([option, str(value).strip()])


def _append_shell_args(args: list[str], value: str) -> None:
    if str(value).strip():
        args.append("--")
        args.extend(shlex.split(str(value)))


def _benchmark_defaults(target_name: str, env: dict[str, str]) -> tuple[str, str, str]:
    prefix = _aws_prefix(target_name)
    if prefix:
        return (
            _prefixed_env(env, prefix, "BENCH_SAMPLES", MICRO_BENCHMARK_DEFAULT_SAMPLES),
            _prefixed_env(env, prefix, "BENCH_WARMUPS", MICRO_BENCHMARK_DEFAULT_WARMUPS),
            _prefixed_env(env, prefix, "BENCH_INNER_REPEAT", MICRO_BENCHMARK_DEFAULT_INNER_REPEAT),
        )
    return (
        _env(env, "SAMPLES", MICRO_BENCHMARK_DEFAULT_SAMPLES),
        _env(env, "WARMUPS", MICRO_BENCHMARK_DEFAULT_WARMUPS),
        _env(env, "INNER_REPEAT", MICRO_BENCHMARK_DEFAULT_INNER_REPEAT),
    )


def suite_args_from_env(
    target_name: str,
    suite_name: str,
    *,
    env: dict[str, str] | None = None,
) -> list[str]:
    values = dict(os.environ if env is None else env)
    prefix = _aws_prefix(target_name)
    samples, warmups, inner_repeat = _benchmark_defaults(target_name, values)
    args: list[str] = []

    if suite_name == "micro":
        args.extend(["--samples", samples, "--warmups", warmups, "--inner-repeat", inner_repeat])
        for bench in csv_tokens(_env(values, "BENCH")):
            args.extend(["--bench", bench])
        return args

    if suite_name == "corpus":
        if prefix:
            workload_seconds = _prefixed_env(values, prefix, "CORPUS_WORKLOAD_SECONDS")
            extra_args = _prefixed_env(values, prefix, "CORPUS_ARGS")
        else:
            samples = _env(values, "SAMPLES") or _env(values, "VM_CORPUS_SAMPLES", "30")
            workload_seconds = _env(values, "VM_CORPUS_WORKLOAD_SECONDS")
            extra_args = _env(values, "VM_CORPUS_ARGS")
        args.extend(["--samples", samples])
        _append_value(args, "--corpus-workload-seconds", workload_seconds)
        _append_shell_args(args, extra_args)
        return args

    if suite_name == "e2e":
        if prefix:
            smoke = _prefixed_env(values, prefix, "E2E_SMOKE", "0")
            extra_args = _prefixed_env(values, prefix, "E2E_ARGS")
        else:
            smoke = _env(values, "E2E_SMOKE", "0")
            extra_args = _env(values, "E2E_ARGS")
        if smoke == "1":
            args.append("--e2e-smoke")
        _append_shell_args(args, extra_args)
        return args

    if suite_name == "test":
        mode = _prefixed_env(values, prefix, "TEST_MODE", "test") if prefix else _env(values, "TEST_MODE", "test")
        args.extend(
            [
                "--test-mode",
                str(mode).strip().lower(),
                "--fuzz-rounds",
                _env(values, "FUZZ_ROUNDS", "1000"),
                "--scx-prog-show-race-mode",
                _env(values, "SCX_PROG_SHOW_RACE_MODE", "bpftool-loop"),
                "--scx-prog-show-race-iterations",
                _env(values, "SCX_PROG_SHOW_RACE_ITERATIONS", "20"),
                "--scx-prog-show-race-load-timeout",
                _env(values, "SCX_PROG_SHOW_RACE_LOAD_TIMEOUT", "20"),
            ]
        )
        if _env(values, "SCX_PROG_SHOW_RACE_SKIP_PROBE", "0") == "1":
            args.append("--scx-prog-show-race-skip-probe")
        return args

    _die(f"unsupported suite: {suite_name}")
    raise AssertionError("unreachable")


def suite_test_mode_from_args(suite_name: str, suite_args: list[str]) -> str:
    if suite_name != "test":
        return "test"
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument("--test-mode", default="test")
    ns, _unknown = parser.parse_known_args(suite_args)
    return str(ns.test_mode).strip().lower()


def write_suite_args_file(path: Path, suite_args: list[str]) -> None:
    write_json_object(path, {"args": list(suite_args)})


def read_suite_args_file(path: Path) -> list[str]:
    raw = read_json_object(path)
    value = raw.get("args", [])
    if not isinstance(value, list):
        _die(f"suite args JSON must contain an args list: {path}")
    return [str(item) for item in value]
