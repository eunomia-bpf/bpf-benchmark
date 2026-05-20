from __future__ import annotations

import json
import os
import shlex
from dataclasses import dataclass
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail


SUITES_DIR = ROOT_DIR / "runner" / "suites"

_die = partial(fail, "run-contract")


@dataclass(frozen=True)
class RunIdentity:
    target_name: str
    target_arch: str
    executor: str
    suite_name: str
    token: str


@dataclass(frozen=True)
class SuiteRequirements:
    needs_runtime_btf: str = "0"


@dataclass(frozen=True)
class ArtifactRequirements:
    native_repos: tuple[str, ...] = ()


@dataclass(frozen=True)
class RemoteConfig:
    user: str = ""
    stage_dir: str = ""
    python_bin: str = ""
    runtime_python_bin: str = "python3"
    runtime_container_image: str = ""
    bpftool_bin: str = "bpftool"


@dataclass(frozen=True)
class AwsConfig:
    name_tag: str = ""
    instance_type: str = ""
    ami_param: str = ""
    ami_id: str = ""
    root_volume_gb: str = ""
    key_name: str = ""
    key_path: str = ""
    security_group_id: str = ""
    subnet_id: str = ""
    region: str = ""
    profile: str = ""


@dataclass(frozen=True)
class KvmConfig:
    backend: str = ""
    executable: str = ""
    cpus: str = ""
    mem: str = ""
    host_python_bin: str = "python3"
    kernel_image: str = ""
    timeout_seconds: str = ""


@dataclass(frozen=True)
class RunConfig:
    identity: RunIdentity
    suite: SuiteRequirements
    artifacts: ArtifactRequirements
    remote: RemoteConfig
    aws: AwsConfig
    kvm: KvmConfig

    def to_mapping(self) -> dict[str, str | list[str]]:
        arch = self.identity.target_arch.strip()
        i, s, a, r, aw, kv = self.identity, self.suite, self.artifacts, self.remote, self.aws, self.kvm
        return {
            "RUN_TARGET_NAME": i.target_name, "RUN_TARGET_ARCH": arch,
            "RUN_EXECUTOR": i.executor, "RUN_SUITE_NAME": i.suite_name, "RUN_TOKEN": i.token,
            "RUN_SUITE_NEEDS_RUNTIME_BTF": s.needs_runtime_btf,
            "RUN_NAME_TAG": aw.name_tag, "RUN_INSTANCE_TYPE": aw.instance_type,
            "RUN_REMOTE_USER": r.user, "RUN_REMOTE_STAGE_DIR": r.stage_dir,
            "RUN_AMI_PARAM": aw.ami_param, "RUN_AMI_ID": aw.ami_id,
            "RUN_ROOT_VOLUME_GB": aw.root_volume_gb,
            "RUN_AWS_KEY_NAME": aw.key_name, "RUN_AWS_KEY_PATH": aw.key_path,
            "RUN_AWS_SECURITY_GROUP_ID": aw.security_group_id, "RUN_AWS_SUBNET_ID": aw.subnet_id,
            "RUN_AWS_REGION": aw.region, "RUN_AWS_PROFILE": aw.profile,
            "RUN_VM_BACKEND": kv.backend, "RUN_VM_EXECUTABLE": kv.executable,
            "RUN_VM_CPUS": kv.cpus, "RUN_VM_MEM": kv.mem,
            "RUN_HOST_PYTHON_BIN": kv.host_python_bin, "RUN_VM_KERNEL_IMAGE": kv.kernel_image,
            "RUN_VM_TIMEOUT_SECONDS": kv.timeout_seconds,
            "RUN_REMOTE_PYTHON_BIN": r.python_bin, "RUN_RUNTIME_PYTHON_BIN": r.runtime_python_bin,
            "RUN_RUNTIME_CONTAINER_IMAGE": r.runtime_container_image,
            "RUN_NATIVE_REPOS_CSV": ",".join(token for token in a.native_repos if token),
            "RUN_BPFTOOL_BIN": r.bpftool_bin,
        }

    def scalar(self, name: str, default: str = "") -> str:
        value = self.to_mapping().get(name, default)
        if isinstance(value, list):
            return shlex.join(str(token) for token in value)
        return str(value).strip()

    def required(self, name: str) -> str:
        value = self.scalar(name)
        if not value:
            raise RuntimeError(f"run config {name} is empty")
        return value

    def env(self) -> dict[str, str]:
        env: dict[str, str] = {}
        for name in (
            "PATH", "HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL",
            "BUILDKIT_PROGRESS", "JOBS", "NPROC", "IMAGE_BUILD_JOBS", "ARM64_IMAGE_BUILD_JOBS",
        ):
            value = os.environ.get(name, "").strip()
            if value:
                env[name] = value
        for name, value in self.to_mapping().items():
            env[name] = shlex.join(value) if isinstance(value, list) else str(value)
        return env

    def to_json_text(self) -> str:
        return json.dumps(self.to_mapping(), sort_keys=True, separators=(",", ":"))

    @classmethod
    def from_mapping(cls, values: dict[str, str | list[str]]) -> "RunConfig":
        def scalar(name: str, default: str = "") -> str:
            value = values.get(name, default)
            if isinstance(value, list):
                return shlex.join(str(token) for token in value)
            return str(value).strip()

        def csv(name: str) -> tuple[str, ...]:
            value = values.get(name, "")
            tokens = value if isinstance(value, list) else str(value).split(",")
            return tuple(str(token).strip() for token in tokens if str(token).strip())

        return cls(
            identity=RunIdentity(target_name=scalar("RUN_TARGET_NAME"), target_arch=scalar("RUN_TARGET_ARCH"),
                                 executor=scalar("RUN_EXECUTOR"), suite_name=scalar("RUN_SUITE_NAME"), token=scalar("RUN_TOKEN")),
            suite=SuiteRequirements(needs_runtime_btf=scalar("RUN_SUITE_NEEDS_RUNTIME_BTF", "0")),
            artifacts=ArtifactRequirements(native_repos=csv("RUN_NATIVE_REPOS_CSV")),
            remote=RemoteConfig(user=scalar("RUN_REMOTE_USER"), stage_dir=scalar("RUN_REMOTE_STAGE_DIR"),
                                python_bin=scalar("RUN_REMOTE_PYTHON_BIN"),
                                runtime_python_bin=scalar("RUN_RUNTIME_PYTHON_BIN", "python3"),
                                runtime_container_image=scalar("RUN_RUNTIME_CONTAINER_IMAGE"),
                                bpftool_bin=scalar("RUN_BPFTOOL_BIN", "bpftool")),
            aws=AwsConfig(name_tag=scalar("RUN_NAME_TAG"), instance_type=scalar("RUN_INSTANCE_TYPE"),
                          ami_param=scalar("RUN_AMI_PARAM"), ami_id=scalar("RUN_AMI_ID"),
                          root_volume_gb=scalar("RUN_ROOT_VOLUME_GB"), key_name=scalar("RUN_AWS_KEY_NAME"),
                          key_path=scalar("RUN_AWS_KEY_PATH"), security_group_id=scalar("RUN_AWS_SECURITY_GROUP_ID"),
                          subnet_id=scalar("RUN_AWS_SUBNET_ID"), region=scalar("RUN_AWS_REGION"), profile=scalar("RUN_AWS_PROFILE")),
            kvm=KvmConfig(backend=scalar("RUN_VM_BACKEND"), executable=scalar("RUN_VM_EXECUTABLE"),
                          cpus=scalar("RUN_VM_CPUS"), mem=scalar("RUN_VM_MEM"),
                          host_python_bin=scalar("RUN_HOST_PYTHON_BIN", "python3"),
                          kernel_image=scalar("RUN_VM_KERNEL_IMAGE"), timeout_seconds=scalar("RUN_VM_TIMEOUT_SECONDS")),
        )

def _load_assignment_file(path: Path) -> dict[str, str]:
    if not path.is_file(): _die(f"missing required file: {path}")
    data: dict[str, str] = {}
    for line_no, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        line = raw_line.strip()
        if not line or line.startswith("#"): continue
        if "=" not in line: _die(f"unsupported assignment in {path}:{line_no}: {raw_line}")
        key, value = line.split("=", 1); key = key.strip()
        if not key or not key.replace("_", "").isalnum() or key[0].isdigit():
            _die(f"invalid assignment key in {path}:{line_no}: {key!r}")
        data[key] = value.strip()
    return data


def _env_or_default(env: dict[str, str], name: str, default: str = "") -> str:
    return env.get(name, "").strip() or default


def _required_env(env: dict[str, str], name: str) -> str:
    value = _env_or_default(env, name)
    if not value:
        _die(f"{name} is required; run benchmark targets through Make")
    return value


def _validate_test_mode(mode: str) -> None:
    if mode not in {"selftest", "negative", "test", "fuzz"}: _die(f"unsupported test mode: {mode}")
def _build_run_config_mapping(
    target_name: str,
    suite_name: str,
    *,
    env: dict[str, str] | None = None,
) -> dict[str, str | list[str]]:
    source_env = os.environ if env is None else env
    suite = _load_assignment_file(SUITES_DIR / f"{suite_name}.env")
    run_test_mode = (source_env.get("TEST_MODE", "").strip().lower() or "test") if suite_name == "test" else "test"

    _validate_test_mode(run_test_mode)
    run_target_name = _env_or_default(source_env, "RUN_TARGET_NAME", target_name)
    if run_target_name != target_name:
        _die(f"RUN_TARGET_NAME={run_target_name!r} does not match requested target {target_name!r}")
    run_executor = _required_env(source_env, "RUN_EXECUTOR")
    run_remote_python_bin = _required_env(source_env, "RUN_REMOTE_PYTHON_BIN")
    run_runtime_python_bin = _required_env(source_env, "RUN_RUNTIME_PYTHON_BIN")
    run_bpftool_bin = _required_env(source_env, "RUN_BPFTOOL_BIN")
    run_token = _required_env(source_env, "RUN_TOKEN")
    run_native_repos = _env_or_default(source_env, "RUN_NATIVE_REPOS_CSV")
    run_vm_timeout_seconds = _env_or_default(source_env, "TIMEOUT", suite.get("SUITE_DEFAULT_VM_TIMEOUT_SECONDS", ""))
    run_host_python_bin = _env_or_default(source_env, "PYTHON", "python3")
    run_name_tag = run_instance_type = run_remote_user = run_remote_stage_dir = ""
    run_ami_param = run_ami_id = run_root_volume_gb = ""
    run_aws_key_name = run_aws_key_path = run_aws_security_group_id = ""
    run_aws_subnet_id = run_aws_region = run_aws_profile = ""
    run_vm_backend = run_vm_executable = run_vm_cpus = run_vm_mem = run_vm_kernel_image = ""
    if run_executor == "aws-ssh":
        for name in (
            "RUN_NAME_TAG",
            "RUN_INSTANCE_TYPE",
            "RUN_REMOTE_USER",
            "RUN_REMOTE_STAGE_DIR",
            "RUN_AMI_PARAM",
            "RUN_ROOT_VOLUME_GB",
            "RUN_AWS_KEY_NAME",
            "RUN_AWS_KEY_PATH",
            "RUN_AWS_SECURITY_GROUP_ID",
            "RUN_AWS_SUBNET_ID",
            "RUN_AWS_REGION",
            "RUN_AWS_PROFILE",
            "RUN_RUNTIME_CONTAINER_IMAGE",
        ):
            _required_env(source_env, name)
        run_name_tag = _env_or_default(source_env, "RUN_NAME_TAG")
        run_instance_type = _env_or_default(source_env, "RUN_INSTANCE_TYPE")
        run_remote_user = _env_or_default(source_env, "RUN_REMOTE_USER")
        run_remote_stage_dir = _env_or_default(source_env, "RUN_REMOTE_STAGE_DIR")
        run_ami_param = _env_or_default(source_env, "RUN_AMI_PARAM")
        run_ami_id = _env_or_default(source_env, "RUN_AMI_ID")
        run_root_volume_gb = _env_or_default(source_env, "RUN_ROOT_VOLUME_GB")
        run_aws_key_name = _env_or_default(source_env, "RUN_AWS_KEY_NAME")
        run_aws_key_path = _env_or_default(source_env, "RUN_AWS_KEY_PATH")
        run_aws_security_group_id = _env_or_default(source_env, "RUN_AWS_SECURITY_GROUP_ID")
        run_aws_subnet_id = _env_or_default(source_env, "RUN_AWS_SUBNET_ID")
        run_aws_region = _env_or_default(source_env, "RUN_AWS_REGION")
        run_aws_profile = _env_or_default(source_env, "RUN_AWS_PROFILE")
    elif run_executor == "kvm":
        run_vm_backend = _env_or_default(source_env, "RUN_VM_BACKEND")
        run_vm_executable = _env_or_default(source_env, "RUN_VM_EXECUTABLE")
        run_vm_cpus = _env_or_default(source_env, "RUN_VM_CPUS")
        run_vm_mem = _env_or_default(source_env, "RUN_VM_MEM")
        run_vm_kernel_image = _env_or_default(source_env, "RUN_VM_KERNEL_IMAGE")
    elif run_executor != "local-docker":
        _die(f"unsupported executor: {run_executor}")

    if not run_remote_python_bin:
        _die(f"suite {suite_name} is missing remote python contract")
    if not run_bpftool_bin:
        _die(f"suite {suite_name} is missing RUN_BPFTOOL_BIN")

    if suite_name == "test":
        run_native_repos = ""
        if run_test_mode == "selftest":
            pass
        elif run_test_mode == "fuzz":
            pass
        elif run_test_mode != "test":
            _die(f"unsupported test mode: {run_test_mode}")
    elif suite_name == "micro":
        run_native_repos = ""
    elif suite_name != "corpus":
        _die(f"unsupported suite: {suite_name}")

    arch = _required_env(source_env, "RUN_TARGET_ARCH")
    return {
        "RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": arch,
        "RUN_EXECUTOR": run_executor, "RUN_SUITE_NAME": suite_name,
        "RUN_SUITE_NEEDS_RUNTIME_BTF": _env_or_default(source_env, "RUN_SUITE_NEEDS_RUNTIME_BTF", suite.get("SUITE_NEEDS_RUNTIME_BTF", "0")),
        "RUN_RUNTIME_CONTAINER_IMAGE": _env_or_default(source_env, "RUN_RUNTIME_CONTAINER_IMAGE"),
        "RUN_TOKEN": run_token,
        "RUN_NAME_TAG": run_name_tag, "RUN_INSTANCE_TYPE": run_instance_type,
        "RUN_REMOTE_USER": run_remote_user, "RUN_REMOTE_STAGE_DIR": run_remote_stage_dir,
        "RUN_AMI_PARAM": run_ami_param, "RUN_AMI_ID": run_ami_id,
        "RUN_ROOT_VOLUME_GB": run_root_volume_gb,
        "RUN_AWS_KEY_NAME": run_aws_key_name, "RUN_AWS_KEY_PATH": run_aws_key_path,
        "RUN_AWS_SECURITY_GROUP_ID": run_aws_security_group_id, "RUN_AWS_SUBNET_ID": run_aws_subnet_id,
        "RUN_AWS_REGION": run_aws_region, "RUN_AWS_PROFILE": run_aws_profile,
        "RUN_VM_BACKEND": run_vm_backend, "RUN_VM_EXECUTABLE": run_vm_executable,
        "RUN_VM_CPUS": run_vm_cpus, "RUN_VM_MEM": run_vm_mem,
        "RUN_HOST_PYTHON_BIN": run_host_python_bin, "RUN_VM_KERNEL_IMAGE": run_vm_kernel_image,
        "RUN_VM_TIMEOUT_SECONDS": run_vm_timeout_seconds,
        "RUN_REMOTE_PYTHON_BIN": run_remote_python_bin, "RUN_RUNTIME_PYTHON_BIN": run_runtime_python_bin,
        "RUN_NATIVE_REPOS_CSV": run_native_repos,
        "RUN_BPFTOOL_BIN": run_bpftool_bin,
    }


def build_run_config(
    target_name: str,
    suite_name: str,
    *,
    env: dict[str, str] | None = None,
) -> RunConfig:
    return RunConfig.from_mapping(_build_run_config_mapping(target_name, suite_name, env=env))


def build_target_config(target_name: str, *, env: dict[str, str] | None = None) -> RunConfig:
    source_env = os.environ if env is None else env
    run_target_name = _env_or_default(source_env, "RUN_TARGET_NAME", target_name)
    if run_target_name != target_name:
        _die(f"RUN_TARGET_NAME={run_target_name!r} does not match requested target {target_name!r}")
    return RunConfig.from_mapping({
        "RUN_TARGET_NAME": target_name,
        "RUN_TARGET_ARCH": _required_env(source_env, "RUN_TARGET_ARCH"),
        "RUN_EXECUTOR": _required_env(source_env, "RUN_EXECUTOR"),
        "RUN_SUITE_NAME": "",
        "RUN_TOKEN": _required_env(source_env, "RUN_TOKEN"),
        "RUN_NAME_TAG": _required_env(source_env, "RUN_NAME_TAG"),
        "RUN_REMOTE_USER": _env_or_default(source_env, "RUN_REMOTE_USER"),
        "RUN_AWS_KEY_PATH": _env_or_default(source_env, "RUN_AWS_KEY_PATH"),
        "RUN_AWS_REGION": _required_env(source_env, "RUN_AWS_REGION"),
        "RUN_AWS_PROFILE": _required_env(source_env, "RUN_AWS_PROFILE"),
    })
