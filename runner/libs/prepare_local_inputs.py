from __future__ import annotations

import os
import shlex
import sys
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.aws_local_prep import run_local_prep as run_aws_local_prep
from runner.libs.cli_support import fail
from runner.libs.kvm_local_prep import run_local_prep as run_kvm_local_prep
from runner.libs.run_contract import parse_manifest

_die = partial(fail, "prepare-local-inputs")


def _csv_tokens(value: str) -> list[str]:
    return [token for token in value.split(",") if token]


def _base_env_from_contract(contract: dict[str, str | list[str]]) -> dict[str, str]:
    env: dict[str, str] = {}
    for name in ("PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL"):
        value = os.environ.get(name, "").strip()
        if value:
            env[name] = value
    for name, value in contract.items():
        env[name] = shlex.join(value) if isinstance(value, list) else value
    return env


def _suite_phases(env: dict[str, str]) -> list[str]:
    suite = env.get("RUN_SUITE_NAME", "").strip()
    test_mode = env.get("RUN_TEST_MODE", "test").strip() or "test"
    executor = env.get("RUN_EXECUTOR", "").strip()
    phases: list[str] = []
    if executor == "kvm":
        phases.append("base")
    if suite == "test":
        phases.append("runtime")
        if env.get("RUN_NEEDS_KINSN_MODULES", "0").strip() == "1":
            phases.append("kinsn")
        phases.append("test_outputs")
        if test_mode == "test":
            phases.append("upstream_selftests")
            if executor == "aws-ssh" and env.get("RUN_TARGET_ARCH", "").strip() == "arm64":
                phases.append("upstream_test_kmods")
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


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {2, 3}:
        _die("usage: prepare_local_inputs.py <manifest_path> <local_state_path> [remote_prep_state_path]")
    manifest_path = Path(args[0]).resolve()
    local_state_path = Path(args[1]).resolve()
    remote_prep_state_path = Path(args[2]).resolve() if len(args) == 3 and args[2] else None
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    contract = parse_manifest(manifest_path)
    env = _base_env_from_contract(contract)
    env["ROOT_DIR"] = str(ROOT_DIR)
    env["PYTHONPATH"] = f"{ROOT_DIR}{':' + env['PYTHONPATH'] if env.get('PYTHONPATH') else ''}"
    env["MANIFEST_PATH"] = str(manifest_path)
    env["LOCAL_STATE_PATH"] = str(local_state_path)
    host_python_bin = env.get("RUN_HOST_PYTHON_BIN", "").strip()
    if not host_python_bin:
        _die("manifest host python is missing")
    env["HOST_PYTHON_BIN"] = host_python_bin
    env["RUN_CONTRACT_PYTHON_BIN"] = host_python_bin
    phases = _suite_phases(env)

    executor = env.get("RUN_EXECUTOR", "").strip()
    if executor == "kvm":
        run_kvm_local_prep(
            manifest_path=manifest_path,
            local_state_path=local_state_path,
            env=env,
            phases=phases,
        )
        return
    if executor == "aws-ssh":
        if remote_prep_state_path is None:
            _die("AWS local prep requires an explicit remote-prep state path")
        if not remote_prep_state_path.is_file():
            _die(f"AWS remote-prep state is missing: {remote_prep_state_path}")
        run_aws_local_prep(
            manifest_path=manifest_path,
            local_state_path=local_state_path,
            remote_prep_state_path=remote_prep_state_path,
            env=env,
            phases=phases,
        )
        return
    _die(f"unsupported executor for local prep: {executor}")


if __name__ == "__main__":
    main()
