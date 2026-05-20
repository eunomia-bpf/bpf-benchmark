from __future__ import annotations

import argparse
import json
import os
import shutil
import subprocess
import sys
from functools import partial
from pathlib import Path
from typing import Sequence

import yaml

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.input_generators import materialize_input
from runner.libs.kinsn import load_kinsn_modules
from runner.libs.results import parse_last_json_line
from runner.libs.workspace_layout import (
    inside_runtime_image,
    kinsn_module_dir,
    runner_binary_path,
    stage2_program_root,
    test_negative_build_dir,
    test_unittest_build_dir,
)
from runner.suites._common import (
    base_suite_runtime_env,
    common_env_args,
    ensure_bpf_stats_enabled,
    env_int,
    env_str,
    env_with_suite_runtime_ld,
    resolve_executable,
    resolve_workspace_path,
    run_checked,
    suite_main_setup,
)

_die = partial(fail, "test-suite")


def _parse_args(argv: list[str] | None = None) -> argparse.Namespace:
    if argv or (argv is None and sys.argv[1:]):
        _die("test suite takes env only; run through Make")
    args = common_env_args(str(ROOT_DIR), _die)
    args.artifact_dir = env_str("TEST_ARTIFACT_DIR")
    args.run_contract_json = env_str("RUN_CONTRACT_JSON")
    args.run_contract_path = env_str("RUN_CONTRACT_PATH")
    args.test_mode = env_str("TEST_MODE", "test")
    args.fuzz_rounds = env_int("FUZZ_ROUNDS", 1000, _die, positive=True)
    if args.test_mode not in {"selftest", "negative", "test", "fuzz"}:
        _die(f"unsupported test mode: {args.test_mode}")
    return args


def _runtime_env(workspace: Path, args: argparse.Namespace) -> dict[str, str]:
    return base_suite_runtime_env(workspace, args, "test", _die)


def _run_with_status(
    command: Sequence[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path | None = None,
) -> bool:
    process = subprocess.Popen(
        list(command),
        cwd=cwd,
        env=env,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
    )
    assert process.stdout is not None
    log_file = None
    if log_path is not None:
        log_path.parent.mkdir(parents=True, exist_ok=True)
        log_file = log_path.open("a", encoding="utf-8")
    try:
        for line in process.stdout:
            if log_file is not None:
                log_file.write(line)
            sys.stderr.write(line)
    finally:
        if log_file is not None:
            log_file.close()
    return process.wait() == 0


def _expected_kinsn_modules(workspace: Path, target_arch: str) -> list[str]:
    module_dir = kinsn_module_dir(workspace, target_arch)
    modules = sorted(
        path.stem
        for path in module_dir.glob("bpf_*.ko")
        if path.is_file()
    )
    if not modules:
        _die(f"no kinsn modules found under {module_dir}")
    return modules


def _load_kinsn_modules(workspace: Path, target_arch: str) -> None:
    load_kinsn_modules(
        _expected_kinsn_modules(workspace, target_arch),
        module_dir=kinsn_module_dir(workspace, target_arch),
    )


def _discover_unittest_binaries(workspace: Path, target_arch: str) -> list[Path]:
    build_dir = test_unittest_build_dir(workspace, target_arch)
    return sorted(
        path
        for path in build_dir.glob("rejit_*")
        if path.is_file() and os.access(path, os.X_OK)
    )


def _log_test_section(title: str) -> None:
    print(f"\n========================================\n  {title}\n========================================", file=sys.stderr)


def _run_unittest_suite(workspace: Path, args: argparse.Namespace, env: dict[str, str], *, log_path: Path | None = None) -> None:
    _log_test_section("Running tests/unittest/ suite (pre-built)")
    build_dir = test_unittest_build_dir(workspace, args.target_arch)
    tests = _discover_unittest_binaries(workspace, args.target_arch)
    if not tests:
        _die(f"no rejit_* test binaries found in {build_dir}")
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    for test_binary in tests:
        print(f"--- {test_binary.name} ---", file=sys.stderr)
        if not _run_with_status(
            [str(test_binary), str(build_dir / "progs")],
            cwd=workspace,
            env=runtime_env,
            log_path=log_path,
        ):
            _die(f"{test_binary.name} failed")


def _fuzz_rounds_text(args: argparse.Namespace) -> str:
    return str(args.fuzz_rounds)


def _run_negative_suite(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    *,
    include_adversarial: bool = True,
    include_fuzz: bool = True,
    log_path: Path | None = None,
) -> None:
    _log_test_section("Running tests/negative/ adversarial suite")
    negative_build = test_negative_build_dir(workspace, args.target_arch)
    runtime_env, _ = env_with_suite_runtime_ld(workspace, args.target_arch, env)
    tests: list[tuple[str, list[str], dict[str, str]]] = []
    if include_adversarial:
        tests.append(("adversarial_rejit", [str(negative_build / "adversarial_rejit")], runtime_env.copy()))
    if include_fuzz:
        tests.append(
            (
                f"fuzz_rejit ({_fuzz_rounds_text(args)} rounds)",
                [str(negative_build / "fuzz_rejit"), _fuzz_rounds_text(args)],
                runtime_env.copy(),
            )
        )
    for label, command, command_env in tests:
        print(f"--- {label} ---", file=sys.stderr)
        if not _run_with_status(command, cwd=workspace, env=command_env, log_path=log_path):
            _die(f"{label.split(' (')[0]} failed")


def _run_kernel_selftest(workspace: Path, env: dict[str, str]) -> None:
    kernel_selftest = workspace / "tests" / "kernel" / "build" / "test_recompile"
    if not kernel_selftest.is_file():
        print(f"SKIP: test_recompile not found at {kernel_selftest}", file=sys.stderr)
        return
    _log_test_section("Kernel selftest (test_recompile)")
    if not _run_with_status([str(kernel_selftest)], cwd=workspace, env=env):
        _die("test_recompile failed")


def _parse_single_runner_sample(stdout: str, label: str) -> dict:
    try:
        payload = parse_last_json_line(stdout, label=label)
    except RuntimeError as exc:
        _die(str(exc))
        raise AssertionError("unreachable")
    if isinstance(payload, dict):
        return payload
    if isinstance(payload, list) and len(payload) == 1 and isinstance(payload[0], dict):
        return payload[0]
    _die(f"{label} returned unexpected JSON shape")
    raise AssertionError("unreachable")


def _run_arm64_native_lab_smoke(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    *,
    log_path: Path | None = None,
) -> None:
    if args.target_arch != "arm64":
        return

    runner_binary = runner_binary_path(workspace, args.target_arch)
    blob = stage2_program_root(workspace, args.target_arch) / "native_lab_smoke" / \
        "arm64_native_lab_xdp_result.blob"
    if not runner_binary.is_file() or not os.access(runner_binary, os.X_OK):
        _die(f"runner artifact is missing or not executable: {runner_binary}")
    if not blob.is_file():
        _die(f"arm64 native_lab smoke blob is missing: {blob}")

    _log_test_section("arm64 native_lab smoke")
    command = [
        str(runner_binary),
        "run-native-lab",
        "--program", str(blob),
        "--io-mode", "staged",
        "--input-size", "64",
        "--inner-repeat", "1",
    ]
    completed = subprocess.run(
        command,
        cwd=workspace,
        env=env,
        capture_output=True,
        text=True,
        check=False,
    )
    if log_path is not None:
        with log_path.open("a", encoding="utf-8") as log_file:
            log_file.write(completed.stdout)
            log_file.write(completed.stderr)
    sys.stderr.write(completed.stdout)
    sys.stderr.write(completed.stderr)
    if completed.returncode != 0:
        _die(f"arm64 native_lab smoke failed with exit {completed.returncode}")

    sample = _parse_single_runner_sample(completed.stdout, "arm64 native_lab smoke")
    if sample.get("result") != 12345678 or sample.get("retval") != 2:
        _die(
            "arm64 native_lab smoke returned unexpected result: "
            f"result={sample.get('result')} retval={sample.get('retval')}"
        )


def _run_arm64_simulator_proof_smoke(
    workspace: Path,
    args: argparse.Namespace,
    env: dict[str, str],
    *,
    log_path: Path | None = None,
) -> None:
    if args.target_arch != "arm64":
        return

    runner_binary = runner_binary_path(workspace, args.target_arch)
    proof_dir = stage2_program_root(workspace, args.target_arch) / "arm64_sim_proofs"
    if not runner_binary.is_file() or not os.access(runner_binary, os.X_OK):
        _die(f"runner artifact is missing or not executable: {runner_binary}")

    _log_test_section("arm64 simulator proof smoke")
    config = yaml.safe_load((workspace / "micro" / "config" / "micro_pure_jit.yaml").read_text(encoding="utf-8"))
    defaults = config.get("benchmark_defaults", {})
    default_io_mode = str(defaults.get("io_mode", "staged"))
    default_retval = int(defaults.get("expected_retval", 2))
    for item in config["benchmarks"]:
        name = item["name"]
        proof_obj = proof_dir / f"{name}.bpf.o"
        if not proof_obj.is_file():
            _die(f"arm64 simulator proof object is missing: {proof_obj}")
        input_path, _meta = materialize_input(str(item["input_generator"]), force=False)
        label = f"arm64 simulator proof smoke/{name}"
        command = [
            str(runner_binary),
            "test-run",
            "--program", str(proof_obj),
            "--program-name", f"{name}_arm64_sim_xdp",
            "--memory", str(input_path),
            "--io-mode", str(item.get("io_mode", default_io_mode)),
            "--input-size", str(int(item.get("kernel_input_size", 0))),
            "--inner-repeat", "1",
        ]
        completed = subprocess.run(
            command,
            cwd=workspace,
            env=env,
            capture_output=True,
            text=True,
            check=False,
        )
        if log_path is not None:
            with log_path.open("a", encoding="utf-8") as log_file:
                log_file.write(completed.stdout)
                log_file.write(completed.stderr)
        sys.stderr.write(completed.stdout)
        sys.stderr.write(completed.stderr)
        if completed.returncode != 0:
            _die(f"{label} failed with exit {completed.returncode}")

        sample = _parse_single_runner_sample(completed.stdout, label)
        expected_result = int(item["expected_result"])
        expected_retval = int(item.get("expected_retval", default_retval))
        if sample.get("result") != expected_result or sample.get("retval") != expected_retval:
            _die(
                f"{label} returned unexpected result: "
                f"result={sample.get('result')} retval={sample.get('retval')} "
                f"expected_result={expected_result} expected_retval={expected_retval}"
            )


def _artifact_dir(workspace: Path, args: argparse.Namespace) -> Path:
    if args.artifact_dir:
        return resolve_workspace_path(workspace, args.artifact_dir)
    token = args.run_token or f"{args.target_name}_test"
    return workspace / "tests" / "results" / token


def _prepare_test_artifacts(workspace: Path, args: argparse.Namespace) -> Path:
    artifact_dir = _artifact_dir(workspace, args)
    artifact_dir.mkdir(parents=True, exist_ok=True)
    contract_path = artifact_dir / "run-contract.json"
    if args.run_contract_path:
        shutil.copy2(resolve_workspace_path(workspace, args.run_contract_path), contract_path)
    elif args.run_contract_json:
        try:
            payload = json.loads(args.run_contract_json)
        except json.JSONDecodeError as exc:
            _die(f"invalid run contract JSON: {exc}")
            raise AssertionError("unreachable")
        contract_path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    return artifact_dir


def _run_selftest_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "selftest.log"
    _log_test_section("Loading kinsn modules")
    _load_kinsn_modules(workspace, args.target_arch)
    _run_arm64_native_lab_smoke(workspace, args, env, log_path=log_path)
    _run_arm64_simulator_proof_smoke(workspace, args, env, log_path=log_path)
    _run_unittest_suite(workspace, args, env, log_path=log_path)
    _run_negative_suite(workspace, args, env, log_path=log_path)


def _run_negative_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "negative.log"
    _run_negative_suite(workspace, args, env, log_path=log_path)


def _run_fuzz_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str], artifact_dir: Path) -> None:
    log_path = artifact_dir / "fuzz.log"
    _run_negative_suite(
        workspace, args, env,
        include_adversarial=False, include_fuzz=True,
        log_path=log_path,
    )


def _run_test_mode(workspace: Path, args: argparse.Namespace, env: dict[str, str]) -> None:
    _run_kernel_selftest(workspace, env)
    _log_test_section("Loading kinsn modules")
    _load_kinsn_modules(workspace, args.target_arch)
    _run_arm64_native_lab_smoke(workspace, args, env)
    _run_arm64_simulator_proof_smoke(workspace, args, env)
    _run_unittest_suite(workspace, args, env)
    _run_negative_suite(workspace, args, env)


def _mode_needs_bpf_stats(mode: str) -> bool:
    return mode in {"selftest", "test"}


def _run_test_suite(workspace: Path, args: argparse.Namespace) -> None:
    env = _runtime_env(workspace, args)
    python_bin = args.python_bin or sys.executable
    resolve_executable(python_bin, path_value=env["PATH"], description="Python binary", die=_die)
    resolve_executable(args.bpftool_bin, path_value=env["PATH"], description="bpftool binary", die=_die)

    artifact_dir = _prepare_test_artifacts(workspace, args)
    os.chdir(workspace)
    if inside_runtime_image() and shutil.which("ip", path=env["PATH"]) is not None:
        run_checked(["ip", "link", "set", "lo", "up"], cwd=workspace, env=env, die=_die)
    if _mode_needs_bpf_stats(args.test_mode):
        ensure_bpf_stats_enabled(workspace, _die)

    if args.test_mode == "selftest":
        _run_selftest_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "negative":
        _run_negative_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "fuzz":
        _run_fuzz_mode(workspace, args, env, artifact_dir)
    elif args.test_mode == "test":
        _run_test_mode(workspace, args, env)
    else:
        _die(f"unsupported test mode: {args.test_mode}")


def main(argv: list[str] | None = None) -> None:
    args = _parse_args(argv)
    workspace = suite_main_setup(args, str(ROOT_DIR), _die)
    _run_test_suite(workspace, args)


if __name__ == "__main__":
    main()
