from __future__ import annotations

import argparse
import os
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


def csv_tokens(value: str) -> list[str]:
    return [token.strip() for token in str(value or "").split(",") if token.strip()]


def join_csv(tokens: list[str]) -> str:
    return ",".join(token for token in tokens if token)


def suite_args_from_env(
    target_name: str,
    suite_name: str,
    *,
    env: dict[str, str] | None = None,
) -> list[str]:
    values = dict(os.environ if env is None else env)
    args: list[str] = []

    if suite_name == "micro":
        args.extend([
            "--samples", _env(values, "SAMPLES", MICRO_BENCHMARK_DEFAULT_SAMPLES),
            "--warmups", _env(values, "WARMUPS", MICRO_BENCHMARK_DEFAULT_WARMUPS),
            "--inner-repeat", _env(values, "INNER_REPEAT", MICRO_BENCHMARK_DEFAULT_INNER_REPEAT),
        ])
        for bench in csv_tokens(_env(values, "BENCH")):
            args.extend(["--bench", bench])
        return args

    if suite_name == "corpus":
        args.extend(["--samples", _env(values, "SAMPLES", MICRO_BENCHMARK_DEFAULT_SAMPLES)])
        return args

    if suite_name == "test":
        args.extend([
            "--test-mode", _env(values, "TEST_MODE", "test").lower(),
            "--fuzz-rounds", _env(values, "FUZZ_ROUNDS", "1000"),
        ])
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
