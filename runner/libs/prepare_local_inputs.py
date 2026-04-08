from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.run_contract import load_manifest_environment


def _die(message: str) -> "NoReturn":
    print(f"[prepare-local-inputs][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _run_shell_action(script: str, *, env: dict[str, str]) -> None:
    completed = subprocess.run(
        ["/bin/bash", "-lc", script],
        cwd=ROOT_DIR,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _csv_tokens(value: str) -> list[str]:
    return [token for token in value.split(",") if token]


def _suite_phases(env: dict[str, str]) -> list[str]:
    suite = env.get("RUN_SUITE_NAME", "").strip()
    test_mode = env.get("RUN_TEST_MODE", "test").strip() or "test"
    phases: list[str] = ["base"]
    if suite == "test":
        phases.append("runtime")
        if env.get("RUN_NEEDS_KINSN_MODULES", "0").strip() == "1":
            phases.append("kinsn")
        phases.append("test_outputs")
        if test_mode == "test":
            phases.extend(["upstream_selftests", "upstream_test_kmods"])
        if _csv_tokens(env.get("RUN_SCX_PACKAGES_CSV", "").strip()):
            phases.append("scx")
        return phases
    if suite == "micro":
        return phases + ["runtime", "micro_programs"]
    if suite in {"corpus", "e2e"}:
        phases.append("runtime")
        if env.get("RUN_NEEDS_KINSN_MODULES", "0").strip() == "1":
            phases.append("kinsn")
        if _csv_tokens(env.get("RUN_FETCH_REPOS_CSV", "").strip()):
            phases.append("fetch_repos")
        if _csv_tokens(env.get("RUN_SCX_PACKAGES_CSV", "").strip()):
            phases.append("scx")
        if _csv_tokens(env.get("RUN_NATIVE_REPOS_CSV", "").strip()):
            phases.append("native")
        phases.append("benchmark_extra")
        if _csv_tokens(env.get("RUN_WORKLOAD_TOOLS_CSV", "").strip()):
            phases.append("workload_tools")
        return phases
    _die(f"unsupported suite for local prep orchestration: {suite}")


def _phase_mapping(*, executor: str) -> tuple[str, dict[str, str], str]:
    if executor == "kvm":
        mapping: dict[str, str] = {
            "base": "ensure_kvm_kernel_image_ready",
            "runtime": "prepare_kvm_runtime_artifacts",
            "kinsn": "prepare_kvm_kinsn_modules",
            "test_outputs": "prepare_kvm_test_outputs",
            "upstream_selftests": "prepare_kvm_upstream_selftests",
            "micro_programs": "prepare_kvm_micro_programs",
            "fetch_repos": "prepare_kvm_fetch_repos",
            "scx": "prepare_kvm_scx_artifacts",
            "native": "prepare_kvm_native_repo_artifacts",
            "workload_tools": "prepare_kvm_workload_tools",
        }
        return (
            """
set -euo pipefail
die() {
    printf '[prepare-local-inputs][ERROR] %s\n' "$*" >&2
    exit 1
}
source "$ROOT_DIR/runner/scripts/kvm_local_prep_lib.sh"
""",
            mapping,
            "kvm_finalize_local_prep",
        )
    if executor == "aws-ssh":
        mapping = {
            "runtime": "prepare_aws_runtime_artifacts",
            "kinsn": "prepare_aws_kinsn_modules",
            "test_outputs": "prepare_aws_test_outputs",
            "upstream_selftests": "prepare_aws_upstream_selftests",
            "upstream_test_kmods": "prepare_aws_upstream_test_kmods",
            "micro_programs": "prepare_aws_micro_programs",
            "fetch_repos": "prepare_aws_fetch_repos",
            "scx": "prepare_aws_scx_artifacts",
            "native": "prepare_aws_native_repo_artifacts",
            "workload_tools": "prepare_aws_workload_tools",
            "benchmark_extra": "prepare_aws_benchmark_extra",
        }
        return (
            """
set -euo pipefail
source "$ROOT_DIR/runner/scripts/aws_common_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_prep_paths_lib.sh"
source "$ROOT_DIR/runner/scripts/aws_local_prep_lib.sh"
""",
            mapping,
            "aws_finalize_local_prep",
        )
    _die(f"unsupported executor for local prep: {executor}")


def _run_shell_function(*, prelude: str, function_name: str, env: dict[str, str]) -> None:
    command = "\n".join((prelude.strip(), function_name)) + "\n"
    _run_shell_action(command, env=env)


def _run_local_prep_plan(*, executor: str, phases: list[str], env: dict[str, str]) -> None:
    script_prelude, phase_mapping, finalize_function = _phase_mapping(
        executor=executor,
    )
    if executor == "kvm":
        init_function = "kvm_prepare_local_init"
    elif executor == "aws-ssh":
        init_function = "aws_prepare_local_init"
    else:
        _die(f"unsupported executor for local prep: {executor}")
    _run_shell_function(prelude=script_prelude, function_name=init_function, env=env)
    for phase in phases:
        function_name = phase_mapping.get(phase)
        if function_name:
            _run_shell_function(prelude=script_prelude, function_name=function_name, env=env)
    _run_shell_function(prelude=script_prelude, function_name=finalize_function, env=env)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {2, 3}:
        _die("usage: prepare_local_inputs.py <manifest_path> <local_state_path> [remote_prep_state_path]")
    manifest_path = Path(args[0]).resolve()
    local_state_path = Path(args[1]).resolve()
    remote_prep_state_path = Path(args[2]).resolve() if len(args) == 3 and args[2] else None
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    load_manifest_environment(manifest_path)
    env = os.environ.copy()
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["PYTHONPATH"] = f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}"
    env["MANIFEST_PATH"] = str(manifest_path)
    env["LOCAL_STATE_PATH"] = str(local_state_path)
    host_python_bin = env.get("RUN_HOST_PYTHON_BIN", "").strip()
    if not host_python_bin:
        _die("manifest host python is missing")
    env["HOST_PYTHON_BIN"] = host_python_bin
    phases = _suite_phases(env)

    executor = env.get("RUN_EXECUTOR", "").strip()
    if executor == "kvm":
        _run_local_prep_plan(executor=executor, phases=phases, env=env)
        return
    if executor == "aws-ssh":
        if remote_prep_state_path is None:
            _die("AWS local prep requires an explicit remote-prep state path")
        if not remote_prep_state_path.is_file():
            _die(f"AWS remote-prep state is missing: {remote_prep_state_path}")
        env["ACTION"] = "run"
        env["AWS_REMOTE_PREP_STATE_PATH"] = str(remote_prep_state_path)
        _run_local_prep_plan(executor=executor, phases=phases, env=env)
        return
    _die(f"unsupported executor for local prep: {executor}")


if __name__ == "__main__":
    main()
