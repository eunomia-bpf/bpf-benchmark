from __future__ import annotations

import json
import os
import shlex
import sys
from dataclasses import dataclass
from functools import partial
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.cli_support import fail
from runner.libs.suite_args import join_csv, suite_args_from_env, suite_test_mode_from_args
from runner.libs.state_file import write_json_object


TARGETS_DIR = ROOT_DIR / "runner" / "targets"
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
            "RUN_NATIVE_REPOS_CSV": join_csv(list(a.native_repos)),
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

    @classmethod
    def from_json_text(cls, text: str) -> "RunConfig":
        raw = json.loads(text)
        if not isinstance(raw, dict): raise RuntimeError("run config JSON must contain an object")
        values: dict[str, str | list[str]] = {}
        for key, value in raw.items():
            if not isinstance(key, str): raise RuntimeError("run config JSON keys must be strings")
            values[key] = [str(item) for item in value] if isinstance(value, list) else ("" if value is None else str(value))
        return cls.from_mapping(values)


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


def _prefixed_env_or_default(env: dict[str, str], prefix: str, suffix: str, default: str = "") -> str:
    return _env_or_default(env, f"{prefix}_{suffix}", default)


def _target_default(target: dict[str, str], name: str) -> str:
    return target.get(f"TARGET_{name}_DEFAULT", "")


def _resolve_repo_path(path: str) -> str:
    if not path: return ""
    candidate = Path(path)
    return str(candidate) if candidate.is_absolute() else str((ROOT_DIR / candidate).resolve())


def _host_cpu_count() -> int: return max(os.cpu_count() or 1, 1)


def _resolve_cpu_spec(spec: str) -> str:
    if not spec or spec == "auto": return str(_host_cpu_count())
    if spec.startswith("auto:"):
        return str(max(int(_host_cpu_count() * float(spec.split(":", 1)[1] or "1")), 1))
    return spec
_COMMON_MANIFEST_INPUTS = {
    "PYTHON",
    "RUN_TOKEN",
    "RUNTIME_PYTHON",
}

_KVM_MANIFEST_INPUTS = {
    "BZIMAGE",
    "VM_CPUS",
    "VM_MEM",
    "VM_TEST_TIMEOUT",
    "VM_MICRO_TIMEOUT",
    "VM_CORPUS_TIMEOUT",
    "VM_E2E_TIMEOUT",
}

_AWS_MANIFEST_SUFFIXES = {
    "NAME_TAG",
    "INSTANCE_TYPE",
    "REMOTE_USER",
    "REMOTE_STAGE_DIR",
    "AMI_PARAM",
    "AMI_ID",
    "ROOT_VOLUME_GB",
    "KEY_NAME",
    "KEY_PATH",
    "SECURITY_GROUP_ID",
    "SUBNET_ID",
    "REGION",
    "PROFILE",
}


def _filtered_run_inputs(target_name: str, env: dict[str, str] | None) -> dict[str, str]:
    source_env = os.environ if env is None else env
    allowed = set(_COMMON_MANIFEST_INPUTS)
    if target_name == "x86-kvm":
        allowed.update(_KVM_MANIFEST_INPUTS)
    else:
        target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
        if aws_env_prefix := target.get("TARGET_AWS_ENV_PREFIX", ""):
            allowed.update(f"{aws_env_prefix}_{suffix}" for suffix in _AWS_MANIFEST_SUFFIXES)
    return {key: source_env[key] for key in allowed if key in source_env}


def _validate_test_mode(mode: str) -> None:
    if mode not in {"selftest", "negative", "test", "fuzz"}: _die(f"unsupported test mode: {mode}")
def _build_run_config_mapping(
    target_name: str,
    suite_name: str,
    *,
    env: dict[str, str] | None = None,
    suite_args: list[str] | None = None,
) -> dict[str, str | list[str]]:
    source_env = os.environ if env is None else env
    values = _filtered_run_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    suite = _load_assignment_file(SUITES_DIR / f"{suite_name}.env")
    run_test_mode = suite_test_mode_from_args(
        suite_name,
        list(suite_args) if suite_args is not None else suite_args_from_env(target_name, suite_name, env=source_env),
    )

    run_token = values.get("RUN_TOKEN", "").strip() or f"{target_name}_{suite_name}"
    (run_name_tag, run_instance_type, run_remote_user, run_remote_stage_dir,
     run_ami_param, run_ami_id, run_root_volume_gb,
     run_aws_key_name, run_aws_key_path, run_aws_security_group_id,
     run_aws_subnet_id, run_aws_region, run_aws_profile,
     run_vm_backend, run_vm_executable, run_vm_cpus, run_vm_mem, run_vm_kernel_image,
    ) = ("",) * 18
    run_bpftool_bin = "bpftool"
    run_native_repos = suite.get("SUITE_DEFAULT_NATIVE_REPOS", "")
    run_vm_timeout_seconds = suite.get("SUITE_DEFAULT_VM_TIMEOUT_SECONDS", "7200")
    run_host_python_bin = _env_or_default(values, "PYTHON", "python3")
    run_runtime_python_bin = _env_or_default(values, "RUNTIME_PYTHON", "python3")
    run_remote_python_bin = target.get("TARGET_REMOTE_PYTHON_DEFAULT", suite.get("SUITE_DEFAULT_REMOTE_PYTHON_BIN", ""))
    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix:
            _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        _penv = lambda suf, dflt="": _prefixed_env_or_default(values, aws_env_prefix, suf, dflt)
        _treq = lambda suf: _die(f"{aws_env_prefix}_{suf} is required for AWS targets")
        run_name_tag = _penv("NAME_TAG", _target_default(target, "NAME_TAG"))
        default_instance_type = _target_default(target, "INSTANCE_TYPE")
        if suite.get("SUITE_VM_CLASS", "") == "benchmark":
            default_instance_type = _target_default(target, "BENCH_INSTANCE_TYPE") or default_instance_type
        else:
            default_instance_type = _target_default(target, "TEST_INSTANCE_TYPE") or default_instance_type
        run_instance_type = _penv("INSTANCE_TYPE", default_instance_type)
        run_remote_user = _penv("REMOTE_USER", _target_default(target, "REMOTE_USER"))
        remote_stage_root = _penv("REMOTE_STAGE_DIR", _target_default(target, "REMOTE_STAGE_DIR")).rstrip("/")
        if not remote_stage_root:
            _die(f"AWS target {target_name} is missing TARGET_REMOTE_STAGE_DIR_DEFAULT")
        run_remote_stage_dir = f"{remote_stage_root}/{suite_name}/{run_token}" if suite_name else f"{remote_stage_root}/{run_token}"
        run_ami_param = _penv("AMI_PARAM", _target_default(target, "AMI_PARAM"))
        run_ami_id = _penv("AMI_ID")
        run_root_volume_gb = _penv("ROOT_VOLUME_GB", _target_default(target, "ROOT_VOLUME_GB"))
        run_aws_key_path = _penv("KEY_PATH", _target_default(target, "KEY_PATH"))
        if not run_aws_key_path: _treq("KEY_PATH")
        run_aws_key_name = _penv("KEY_NAME", _target_default(target, "KEY_NAME")) or Path(run_aws_key_path).stem
        if not run_aws_key_name: _die(f"{aws_env_prefix}_KEY_NAME could not be derived from {aws_env_prefix}_KEY_PATH")
        run_aws_security_group_id = _penv("SECURITY_GROUP_ID", _target_default(target, "SECURITY_GROUP_ID"))
        if not run_aws_security_group_id: _treq("SECURITY_GROUP_ID")
        run_aws_subnet_id = _penv("SUBNET_ID", _target_default(target, "SUBNET_ID"))
        if not run_aws_subnet_id: _treq("SUBNET_ID")
        run_aws_region = _penv("REGION", _target_default(target, "AWS_REGION"))
        if not run_aws_region: _treq("REGION")
        run_aws_profile = _penv("PROFILE", _target_default(target, "AWS_PROFILE"))
        if not run_aws_profile: _treq("PROFILE")
    elif target_name == "x86-kvm":
        run_vm_backend = target.get("TARGET_KVM_BACKEND", "")
        run_vm_executable = target.get("TARGET_KVM_EXECUTABLE", "")
        run_host_python_bin = _env_or_default(values, "PYTHON", target.get("TARGET_KVM_HOST_PYTHON_DEFAULT", "python3"))
        run_vm_kernel_image = _resolve_repo_path(_env_or_default(values, "BZIMAGE", target.get("TARGET_KVM_KERNEL_IMAGE_DEFAULT", "vendor/linux-framework/arch/x86/boot/bzImage")))
        if not run_vm_backend: _die("x86-kvm target is missing TARGET_KVM_BACKEND")
        if not run_vm_executable: _die("x86-kvm target is missing TARGET_KVM_EXECUTABLE")
        if not Path(run_vm_executable).is_absolute() and "/" in run_vm_executable:
            run_vm_executable = str((ROOT_DIR / run_vm_executable).resolve())
        _kenv = lambda k, dflt="": _env_or_default(values, k, dflt)
        suite_vm_class = suite.get("SUITE_VM_CLASS", "")
        if suite_vm_class == "test":
            run_vm_cpus = _kenv("VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_TEST_CPUS_SPEC", "auto:0.8")))
            run_vm_mem = _kenv("VM_MEM", target.get("TARGET_KVM_TEST_MEM", "16G"))
        elif suite_vm_class == "benchmark":
            run_vm_cpus = _kenv("VM_CPUS", _resolve_cpu_spec(target.get("TARGET_KVM_BENCH_CPUS_SPEC", "4")))
            run_vm_mem = _kenv("VM_MEM", target.get("TARGET_KVM_BENCH_MEM", "16G"))
        elif suite_vm_class:
            _die(f"unsupported KVM suite class: {suite_vm_class}")
    else:
        _die(f"unsupported target: {target_name}")

    if suite_name == "test":
        run_vm_timeout_seconds = _env_or_default(values, "VM_TEST_TIMEOUT", run_vm_timeout_seconds)
    elif suite_name == "micro":
        run_vm_timeout_seconds = _env_or_default(values, "VM_MICRO_TIMEOUT", run_vm_timeout_seconds)
    elif suite_name == "corpus":
        run_vm_timeout_seconds = _env_or_default(values, "VM_CORPUS_TIMEOUT", run_vm_timeout_seconds)
    elif suite_name == "e2e":
        run_vm_timeout_seconds = _env_or_default(values, "VM_E2E_TIMEOUT", run_vm_timeout_seconds)

    _validate_test_mode(run_test_mode)
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
    elif suite_name not in ("corpus", "e2e"):
        _die(f"unsupported suite: {suite_name}")

    arch = target.get("TARGET_ARCH", "").strip()
    return {
        "RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": arch,
        "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""), "RUN_SUITE_NAME": suite_name,
        "RUN_SUITE_NEEDS_RUNTIME_BTF": suite.get("SUITE_NEEDS_RUNTIME_BTF", "0"),
        "RUN_RUNTIME_CONTAINER_IMAGE": f"bpf-benchmark/runner-runtime:{arch}",
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
    suite_args: list[str] | None = None,
) -> RunConfig:
    return RunConfig.from_mapping(_build_run_config_mapping(target_name, suite_name, env=env, suite_args=suite_args))


def build_target_config(target_name: str, *, env: dict[str, str] | None = None) -> RunConfig:
    values = _filtered_run_inputs(target_name, env)
    target = _load_assignment_file(TARGETS_DIR / f"{target_name}.env")
    run_token = values.get("RUN_TOKEN", "").strip() or f"target_{target_name}"
    run_name_tag = run_aws_region = run_aws_profile = ""
    if target.get("TARGET_EXECUTOR", "") == "aws-ssh":
        aws_env_prefix = target.get("TARGET_AWS_ENV_PREFIX", "")
        if not aws_env_prefix: _die(f"AWS target {target_name} is missing TARGET_AWS_ENV_PREFIX")
        _penv = lambda suf, dflt="": _prefixed_env_or_default(values, aws_env_prefix, suf, dflt)
        run_name_tag = _penv("NAME_TAG", _target_default(target, "NAME_TAG"))
        run_aws_region = _penv("REGION", _target_default(target, "AWS_REGION"))
        if not run_aws_region: _die(f"{aws_env_prefix}_REGION is required for AWS targets")
        run_aws_profile = _penv("PROFILE", _target_default(target, "AWS_PROFILE"))
        if not run_aws_profile: _die(f"{aws_env_prefix}_PROFILE is required for AWS targets")
    return RunConfig.from_mapping({"RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
                                   "RUN_EXECUTOR": target.get("TARGET_EXECUTOR", ""), "RUN_SUITE_NAME": "",
                                   "RUN_TOKEN": run_token, "RUN_NAME_TAG": run_name_tag,
                                   "RUN_AWS_REGION": run_aws_region, "RUN_AWS_PROFILE": run_aws_profile})


def write_run_config_file(path: Path, config: RunConfig) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    write_json_object(path, config.to_mapping())


def read_run_config_file(path: Path) -> RunConfig:
    if not path.is_file():
        _die(f"run config is missing: {path}")
    return RunConfig.from_json_text(path.read_text(encoding="utf-8"))


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if not args: _die("usage: python -m runner.libs.run_contract <print-json|write-config|write-target-config> ...")
    action = args[0]
    if action == "print-json":
        if len(args) != 2: _die("usage: python -m runner.libs.run_contract print-json <config_path>")
        print(read_run_config_file(Path(args[1]).resolve()).to_json_text()); return
    if action == "write-config":
        if len(args) != 4: _die("usage: python -m runner.libs.run_contract write-config <target> <suite> <config_path>")
        write_run_config_file(Path(args[3]).resolve(), build_run_config(args[1], args[2])); return
    if action == "write-target-config":
        if len(args) != 3: _die("usage: python -m runner.libs.run_contract write-target-config <target> <config_path>")
        write_run_config_file(Path(args[2]).resolve(), build_target_config(args[1])); return
    _die(f"unsupported action: {action}")


if __name__ == "__main__":
    main()
