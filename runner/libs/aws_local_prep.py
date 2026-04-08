from __future__ import annotations

import os
import shutil
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.aws_kernel_artifacts import (
    build_paths_from_prep,
    ensure_arm64_kinsn_modules_ready,
    ensure_arm64_upstream_test_kmods_ready,
    ensure_x86_kinsn_modules_ready,
)
from runner.libs.local_prep_common import (
    build_micro_program_outputs,
    build_native_repo_artifacts,
    build_scx_artifacts,
    build_x86_daemon_binary,
    build_x86_repo_tests,
    build_x86_runner_binary,
    build_x86_upstream_selftests,
    csv_append_unique,
    csv_tokens,
    die,
    finalize_staged_bundle,
    fetch_selected_repos,
    require_file_contains,
    require_nonempty_dir,
    require_path,
    run_local_prep_phases,
    run_command,
    stage_x86_workload_tools,
    x86_bundle_inputs,
)
from runner.libs.portable_runtime import build_x86_portable_libbpf, bundle_arm64_portable_binary
from runner.libs.state_file import merge_state, read_state, write_state


class AWSPrep:
    def __init__(
        self,
        *,
        env: dict[str, str],
        manifest_path: Path,
        local_state_path: Path,
        remote_prep_state_path: Path,
    ) -> None:
        self.env = dict(env)
        self.manifest_path = manifest_path
        self.local_state_path = local_state_path
        self.remote_prep_state_path = remote_prep_state_path
        self.run_token = self.env.get("RUN_TOKEN", "").strip()
        self.target_name = self.env.get("RUN_TARGET_NAME", "").strip()
        self.target_arch = self.env.get("RUN_TARGET_ARCH", "").strip()
        self.host_python_bin = self.env.get("RUN_HOST_PYTHON_BIN", "").strip()
        if not self.run_token:
            die("manifest RUN_TOKEN is empty for AWS local prep")
        if not self.target_name:
            die("manifest RUN_TARGET_NAME is empty for AWS local prep")
        if not self.host_python_bin:
            die("manifest host python is missing")
        self.target_cache_dir = ROOT_DIR / ".cache" / self.target_name
        self.run_prep_root = self.target_cache_dir / "runs" / self.run_token
        self.artifact_dir = self.run_prep_root / "artifacts"
        self.results_dir = self.target_cache_dir / "results"
        self.promote_root = self.run_prep_root / "bundle-inputs"
        self.bundle_inputs_path = self.run_prep_root / "bundle-inputs.json"
        self.stage_root = self.run_prep_root / "workspace"
        self.bundle_tar = self.run_prep_root / "bundle.tar.gz"
        self.local_repo_root = self.promote_root / "runner" / "repos"
        self.micro_programs_generated_dir = self.promote_root / "micro" / "programs"
        self.test_artifacts_root = self.promote_root / "test-artifacts"
        self.x86_portable_libbpf_root = self.promote_root / "portable-libbpf"
        self.x86_runner_build_dir = self.promote_root / "runner" / "build"
        self.x86_runner = self.x86_runner_build_dir / "micro_exec"
        self.x86_daemon_target_dir = self.promote_root / "daemon" / "target"
        self.x86_daemon = self.x86_daemon_target_dir / "release" / "bpfrejit-daemon"
        self.x86_unittest_dir = self.test_artifacts_root / "unittest" / "build"
        self.x86_negative_dir = self.test_artifacts_root / "negative" / "build"
        self.x86_upstream_selftests_dir = self.test_artifacts_root / "upstream-bpf-selftests"
        self.x86_kinsn_stage_dir = self.test_artifacts_root / "kinsn-modules" / "x86"
        self.arm64_crossbuild_root = self.run_prep_root / "arm64-cross"
        self.arm64_crossbuild_output_dir = self.promote_root
        self.arm64_crossbuild_build_root = self.arm64_crossbuild_root / "build"
        self.arm64_crossbuild_cargo_home = self.arm64_crossbuild_root / "cargo-home"
        self.arm64_unittest_dir = self.test_artifacts_root / "unittest" / "build-arm64"
        self.arm64_negative_dir = self.test_artifacts_root / "negative" / "build-arm64"
        self.arm64_upstream_selftests_dir = self.test_artifacts_root / "upstream-bpf-selftests"
        self.arm64_upstream_test_kmods_dir = self.test_artifacts_root / "upstream-selftests-kmods"
        self.arm64_kinsn_stage_dir = self.test_artifacts_root / "kinsn-modules" / "arm64"
        self.arm64_host_runner_root = self.run_prep_root / "arm64-runner-host-cross"
        self.arm64_host_runner_build_dir = self.arm64_host_runner_root / "build"
        self.arm64_host_runner_output_dir = self.arm64_host_runner_root / "output"
        self.arm64_host_runner_binary = self.arm64_host_runner_output_dir / "micro_exec"
        self.arm64_host_daemon_root = self.run_prep_root / "arm64-daemon-host-cross"
        self.arm64_host_daemon_target_dir = self.arm64_host_daemon_root / "target"
        self.arm64_host_daemon_output_dir = self.arm64_host_daemon_root / "output"
        self.arm64_host_daemon_binary = self.arm64_host_daemon_output_dir / "bpfrejit-daemon"
        self.arm64_host_daemon_cargo_home = self.arm64_host_daemon_root / "cargo-home"
        self.arm64_host_scx_root = self.run_prep_root / "arm64-scx-host-cross"
        self.arm64_host_scx_build_root = self.arm64_host_scx_root / "build"
        self.arm64_host_scx_cargo_home = self.arm64_host_scx_root / "cargo-home"
        self.arm64_cross_runner = self.arm64_crossbuild_output_dir / "runner" / "build" / "micro_exec"
        self.arm64_cross_runner_real = self.arm64_crossbuild_output_dir / "runner" / "build" / "micro_exec.real"
        self.arm64_cross_daemon = self.arm64_crossbuild_output_dir / "daemon" / "build" / "bpfrejit-daemon"
        self.arm64_cross_daemon_real = self.arm64_crossbuild_output_dir / "daemon" / "build" / "bpfrejit-daemon.real"
        self.arm64_cross_lib_dir = self.arm64_crossbuild_output_dir / "lib"
        self.arm64_katran_server_binary = self.arm64_crossbuild_output_dir / "katran" / "bin" / "katran_server_grpc"
        self.arm64_katran_server_lib_dir = self.arm64_crossbuild_output_dir / "katran" / "lib"
        self.arm64_worktree_dir = ROOT_DIR / ".worktrees" / "linux-framework-arm64-src"
        self.arm64_host_cache_root = ROOT_DIR / ".cache" / "arm64-host"
        self.arm64_aws_build_dir = self.target_cache_dir / "kernel-build"
        self.arm64_aws_base_config = self.target_cache_dir / "config-al2023-arm64"
        self.arm64_setup_artifact_root = self.target_cache_dir / "setup-artifacts"
        self.arm64_sysroot_root = self.arm64_host_cache_root / "sysroot"
        self.arm64_sysroot_lock_file = self.arm64_host_cache_root / "sysroot.lock"
        self.arm64_sysroot_remote_host = self.env.get("ARM64_SYSROOT_REMOTE_HOST", "").strip()
        self.arm64_sysroot_remote_user = self.env.get("ARM64_SYSROOT_REMOTE_USER", "").strip()
        self.arm64_sysroot_ssh_key_path = self.env.get("ARM64_SYSROOT_SSH_KEY_PATH", "").strip()
        self.x86_setup_artifact_root = self.target_cache_dir / "setup-artifacts" / "x86"
        self.docker_bin = "docker"
        self.arm64_docker_platform = self.env.get("ARM64_DOCKER_PLATFORM", "linux/arm64").strip() or "linux/arm64"
        self.arm64_crossbuild_dockerfile = (ROOT_DIR / "runner" / "docker" / "arm64-crossbuild.Dockerfile").resolve()
        self.arm64_crossbuild_context = (ROOT_DIR / "runner" / "docker").resolve()
        self.arm64_crossbuild_image = "bpf-benchmark-arm64-crossbuild:latest"
        self.arm64_crossbuild_stamp = (ROOT_DIR / ".cache" / "arm64-crossbuild-image.stamp").resolve()
        self.arm64_crossbuild_lock = (ROOT_DIR / ".cache" / "arm64-crossbuild-image.lock").resolve()
        self.remote_state: dict[str, str] = {}
        self.bundled_workload_tools_csv = ""
        self.local_workload_tool_root = ""

    def init(self) -> None:
        shutil.rmtree(self.run_prep_root, ignore_errors=True)
        self.promote_root.mkdir(parents=True, exist_ok=True)
        self.remote_state = read_state(self.remote_prep_state_path)
        self._configure_arm64_sysroot_contract()

    def _env_with_paths(self, **extra: str) -> dict[str, str]:
        run_env = dict(self.env)
        run_env.update(
            {
                "ROOT_DIR": str(ROOT_DIR),
                "MANIFEST_PATH": str(self.manifest_path),
                "LOCAL_STATE_PATH": str(self.local_state_path),
                "AWS_REMOTE_PREP_STATE_PATH": str(self.remote_prep_state_path),
                "ACTION": "run",
                "RUN_CONTRACT_PYTHON_BIN": self.host_python_bin,
                "HOST_PYTHON_BIN": self.host_python_bin,
                "ARM64_HOST_PYTHON_BIN": self.host_python_bin,
                "TARGET_CACHE_DIR": str(self.target_cache_dir),
                "RUN_PREP_ROOT": str(self.run_prep_root),
                "ARTIFACT_DIR": str(self.artifact_dir),
                "RESULTS_DIR": str(self.results_dir),
                "MICRO_PROGRAMS_GENERATED_DIR": str(self.micro_programs_generated_dir),
                "X86_PORTABLE_LIBBPF_ROOT": str(self.x86_portable_libbpf_root),
                "X86_RUNNER_BUILD_DIR": str(self.x86_runner_build_dir),
                "X86_RUNNER": str(self.x86_runner),
                "X86_DAEMON_TARGET_DIR": str(self.x86_daemon_target_dir),
                "X86_DAEMON": str(self.x86_daemon),
                "X86_TEST_UNITTEST_BUILD_DIR": str(self.x86_unittest_dir),
                "X86_TEST_NEGATIVE_BUILD_DIR": str(self.x86_negative_dir),
                "X86_UPSTREAM_SELFTEST_DIR": str(self.x86_upstream_selftests_dir),
                "X86_KINSN_MODULE_STAGE_DIR": str(self.x86_kinsn_stage_dir),
                "ARM64_CROSSBUILD_ROOT": str(self.arm64_crossbuild_root),
                "ARM64_CROSSBUILD_OUTPUT_DIR": str(self.arm64_crossbuild_output_dir),
                "ARM64_CROSSBUILD_BUILD_ROOT": str(self.arm64_crossbuild_build_root),
                "ARM64_CROSSBUILD_CARGO_HOME": str(self.arm64_crossbuild_cargo_home),
                "ARM64_TEST_ARTIFACTS_ROOT": str(self.test_artifacts_root),
                "ARM64_TEST_UNITTEST_BUILD_DIR": str(self.arm64_unittest_dir),
                "ARM64_TEST_NEGATIVE_BUILD_DIR": str(self.arm64_negative_dir),
                "ARM64_UPSTREAM_SELFTEST_DIR": str(self.arm64_upstream_selftests_dir),
                "ARM64_UPSTREAM_TEST_KMODS_DIR": str(self.arm64_upstream_test_kmods_dir),
                "ARM64_KINSN_MODULE_STAGE_DIR": str(self.arm64_kinsn_stage_dir),
                "ARM64_HOST_RUNNER_BUILD_DIR": str(self.arm64_host_runner_build_dir),
                "ARM64_HOST_RUNNER_OUTPUT_DIR": str(self.arm64_host_runner_output_dir),
                "ARM64_HOST_RUNNER_BINARY": str(self.arm64_host_runner_binary),
                "ARM64_HOST_DAEMON_TARGET_DIR": str(self.arm64_host_daemon_target_dir),
                "ARM64_HOST_DAEMON_OUTPUT_DIR": str(self.arm64_host_daemon_output_dir),
                "ARM64_HOST_DAEMON_BINARY": str(self.arm64_host_daemon_binary),
                "ARM64_HOST_DAEMON_CARGO_HOME": str(self.arm64_host_daemon_cargo_home),
                "ARM64_HOST_SCX_BUILD_ROOT": str(self.arm64_host_scx_build_root),
                "ARM64_HOST_SCX_CARGO_HOME": str(self.arm64_host_scx_cargo_home),
                "ARM64_SOURCE_REPO_ROOT": str(self.local_repo_root),
                "ARM64_CROSS_RUNNER": str(self.arm64_cross_runner),
                "ARM64_CROSS_RUNNER_REAL": str(self.arm64_cross_runner_real),
                "ARM64_CROSS_DAEMON": str(self.arm64_cross_daemon),
                "ARM64_CROSS_DAEMON_REAL": str(self.arm64_cross_daemon_real),
                "ARM64_CROSS_LIB_DIR": str(self.arm64_cross_lib_dir),
                "ARM64_KATRAN_SERVER_BINARY": str(self.arm64_katran_server_binary),
                "ARM64_KATRAN_SERVER_LIB_DIR": str(self.arm64_katran_server_lib_dir),
                "ARM64_WORKTREE_DIR": str(self.arm64_worktree_dir),
                "ARM64_AWS_BUILD_DIR": str(self.arm64_aws_build_dir),
                "ARM64_AWS_BASE_CONFIG": str(self.arm64_aws_base_config),
                "ARM64_SETUP_ARTIFACT_ROOT": str(self.arm64_setup_artifact_root),
                "ARM64_SYSROOT_ROOT": str(self.arm64_sysroot_root),
                "ARM64_SYSROOT_LOCK_FILE": str(self.arm64_sysroot_lock_file),
                "ARM64_SYSROOT_REMOTE_HOST": self.arm64_sysroot_remote_host,
                "ARM64_SYSROOT_REMOTE_USER": self.arm64_sysroot_remote_user,
                "ARM64_SYSROOT_SSH_KEY_PATH": self.arm64_sysroot_ssh_key_path,
            }
        )
        run_env.update(extra)
        return run_env

    def _configure_arm64_sysroot_contract(self) -> None:
        if self.target_arch != "arm64":
            return
        if self.arm64_sysroot_remote_host:
            if not self.arm64_sysroot_remote_user:
                die("ARM64 sysroot source requires ARM64_SYSROOT_REMOTE_USER")
            if not self.arm64_sysroot_ssh_key_path:
                die("ARM64 sysroot source requires ARM64_SYSROOT_SSH_KEY_PATH")
            return
        state_host = self.remote_state.get("STATE_SYSROOT_REMOTE_HOST", "").strip()
        if not state_host:
            return
        remote_user = self.remote_state.get("STATE_SYSROOT_REMOTE_USER", "").strip()
        key_path = self.remote_state.get("STATE_SYSROOT_SSH_KEY_PATH", "").strip()
        if not remote_user:
            die("ARM64 sysroot source requires STATE_SYSROOT_REMOTE_USER from remote prep")
        if not key_path:
            die("ARM64 sysroot source requires STATE_SYSROOT_SSH_KEY_PATH from remote prep")
        self.arm64_sysroot_remote_host = state_host
        self.arm64_sysroot_remote_user = remote_user
        self.arm64_sysroot_ssh_key_path = key_path

    def _run_host_python_module(self, module: str, mode: str, **extra_env: str) -> None:
        run_command(
            [self.host_python_bin, "-m", module, mode],
            env=self._env_with_paths(**extra_env),
        )

    def _container_path(self, path: Path) -> str:
        resolved = path.resolve()
        try:
            relative = resolved.relative_to(ROOT_DIR)
        except ValueError as exc:
            die(f"ARM64 container path must stay inside repo root: {resolved} ({exc})")
        return str(Path("/workspace") / relative)

    def _ensure_arm64_crossbuild_image(self) -> None:
        if self.arm64_crossbuild_stamp.is_file() and self.arm64_crossbuild_stamp.stat().st_mtime >= self.arm64_crossbuild_dockerfile.stat().st_mtime:
            return
        self.arm64_crossbuild_stamp.parent.mkdir(parents=True, exist_ok=True)
        run_command(
            [
                "flock",
                str(self.arm64_crossbuild_lock),
                self.docker_bin,
                "buildx",
                "build",
                "--load",
                "--platform",
                self.arm64_docker_platform,
                "-f",
                str(self.arm64_crossbuild_dockerfile),
                "-t",
                self.arm64_crossbuild_image,
                str(self.arm64_crossbuild_context),
            ],
            env=self._env_with_paths(),
        )
        self.arm64_crossbuild_stamp.touch()

    def _run_arm64_container_build(
        self,
        *,
        runtime_targets_csv: str = "",
        llvmbpf_setting: str = "OFF",
        bench_repos_csv: str = "",
    ) -> None:
        self._ensure_arm64_crossbuild_image()
        run_command(
            [
                self.docker_bin,
                "run",
                "--rm",
                "--platform",
                self.arm64_docker_platform,
                "-v",
                f"{ROOT_DIR}:/workspace",
                "-w",
                "/workspace",
                "-e",
                "HOME=/tmp/codex",
                "-e",
                f"CARGO_HOME={self._container_path(self.arm64_crossbuild_cargo_home)}",
                "-e",
                f"HOST_UID={os.getuid()}",
                "-e",
                f"HOST_GID={os.getgid()}",
                "-e",
                f"ARM64_SOURCE_REPO_ROOT={self._container_path(self.local_repo_root)}",
                "-e",
                f"ARM64_CROSSBUILD_OUTPUT_DIR={self._container_path(self.arm64_crossbuild_output_dir)}",
                "-e",
                f"ARM64_CROSSBUILD_BUILD_ROOT={self._container_path(self.arm64_crossbuild_build_root)}",
                "-e",
                f"ARM64_CROSSBUILD_JOBS={self.env.get('ARM64_CROSSBUILD_JOBS', '4').strip() or '4'}",
                "-e",
                f"ARM64_CROSSBUILD_RUNTIME_TARGETS={runtime_targets_csv}",
                "-e",
                f"ARM64_CROSSBUILD_ENABLE_LLVMBPF={llvmbpf_setting}",
                "-e",
                f"ARM64_PREBUILT_DAEMON_BINARY={self._container_path(self.arm64_host_daemon_binary)}",
                "-e",
                f"ARM64_CROSSBUILD_BENCH_REPOS={bench_repos_csv}",
                "-e",
                f"ARM64_CROSSBUILD_ONLY_BENCH={'1' if bench_repos_csv else '0'}",
                self.arm64_crossbuild_image,
                "python3",
                "-m",
                "runner.libs.arm64_container_build",
            ],
            env=self._env_with_paths(),
        )

    def prepare_runtime_artifacts(self) -> None:
        if self.target_arch == "x86_64":
            if self.env.get("RUN_NEEDS_RUNNER_BINARY", "0").strip() == "1":
                build_x86_runner_binary(build_dir=self.x86_runner_build_dir, env=self._env_with_paths())
            if self.env.get("RUN_NEEDS_DAEMON_BINARY", "0").strip() == "1":
                build_x86_daemon_binary(daemon_target_dir=self.x86_daemon_target_dir, env=self._env_with_paths())
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for runtime prep: {self.target_arch}")
        self._prepare_arm64_runtime_artifacts()

    def _prepare_arm64_runtime_artifacts(self) -> None:
        runtime_targets: list[str] = []
        llvmbpf_setting = "ON" if self.env.get("RUN_SUITE_NEEDS_LLVMBPF", "0").strip() == "1" else "OFF"
        if self.env.get("RUN_NEEDS_RUNNER_BINARY", "0").strip() == "1":
            runtime_targets.append("runner")
        if self.env.get("RUN_NEEDS_DAEMON_BINARY", "0").strip() == "1":
            runtime_targets.append("daemon")
        if not runtime_targets:
            return
        runtime_targets_csv = ",".join(runtime_targets)
        use_host_runner_cross = llvmbpf_setting != "ON" and "runner" in runtime_targets
        daemon_enabled = "daemon" in runtime_targets
        common_env = {
            "ARM64_SYSROOT_ROOT": str(self.arm64_sysroot_root),
            "ARM64_SYSROOT_LOCK_FILE": str(self.arm64_sysroot_lock_file),
            "ARM64_SYSROOT_REMOTE_HOST": self.arm64_sysroot_remote_host,
            "ARM64_SYSROOT_REMOTE_USER": self.arm64_sysroot_remote_user,
            "ARM64_SYSROOT_SSH_KEY_PATH": self.arm64_sysroot_ssh_key_path,
        }
        if runtime_targets == ["daemon"]:
            self._run_host_python_module(
                "runner.libs.arm64_host_build",
                "daemon",
                ARM64_HOST_DAEMON_TARGET_DIR=str(self.arm64_host_daemon_target_dir),
                ARM64_HOST_DAEMON_OUTPUT_DIR=str(self.arm64_host_daemon_output_dir),
                ARM64_HOST_DAEMON_BINARY=str(self.arm64_host_daemon_binary),
                ARM64_HOST_DAEMON_CARGO_HOME=str(self.arm64_host_daemon_cargo_home),
                **common_env,
            )
            bundle_arm64_portable_binary(
                input_binary=self.arm64_host_daemon_binary,
                real_output=self.arm64_cross_daemon_real,
                wrapper_output=self.arm64_cross_daemon,
                lib_output_dir=self.arm64_cross_lib_dir,
                sysroot_root=self.arm64_sysroot_root,
                sysroot_lock_file=self.arm64_sysroot_lock_file,
                remote_host=self.arm64_sysroot_remote_host,
                remote_user=self.arm64_sysroot_remote_user,
                ssh_key_path=self.arm64_sysroot_ssh_key_path,
            )
            require_file_contains(self.arm64_cross_daemon_real, "ARM aarch64", "ARM64 daemon binary")
            require_nonempty_dir(self.arm64_cross_lib_dir, "ARM64 runtime lib dir")
            return
        if use_host_runner_cross:
            self._run_host_python_module(
                "runner.libs.arm64_host_build",
                "runner",
                ARM64_HOST_RUNNER_BUILD_DIR=str(self.arm64_host_runner_build_dir),
                ARM64_HOST_RUNNER_OUTPUT_DIR=str(self.arm64_host_runner_output_dir),
                ARM64_HOST_RUNNER_BINARY=str(self.arm64_host_runner_binary),
                MICRO_EXEC_ENABLE_LLVMBPF="OFF",
                **common_env,
            )
            bundle_arm64_portable_binary(
                input_binary=self.arm64_host_runner_binary,
                real_output=self.arm64_cross_runner_real,
                wrapper_output=self.arm64_cross_runner,
                lib_output_dir=self.arm64_cross_lib_dir,
                sysroot_root=self.arm64_sysroot_root,
                sysroot_lock_file=self.arm64_sysroot_lock_file,
                remote_host=self.arm64_sysroot_remote_host,
                remote_user=self.arm64_sysroot_remote_user,
                ssh_key_path=self.arm64_sysroot_ssh_key_path,
            )
            require_file_contains(self.arm64_cross_runner_real, "ARM aarch64", "ARM64 runner binary")
            if daemon_enabled:
                self._run_host_python_module(
                    "runner.libs.arm64_host_build",
                    "daemon",
                    ARM64_HOST_DAEMON_TARGET_DIR=str(self.arm64_host_daemon_target_dir),
                    ARM64_HOST_DAEMON_OUTPUT_DIR=str(self.arm64_host_daemon_output_dir),
                    ARM64_HOST_DAEMON_BINARY=str(self.arm64_host_daemon_binary),
                    ARM64_HOST_DAEMON_CARGO_HOME=str(self.arm64_host_daemon_cargo_home),
                    **common_env,
                )
                bundle_arm64_portable_binary(
                    input_binary=self.arm64_host_daemon_binary,
                    real_output=self.arm64_cross_daemon_real,
                    wrapper_output=self.arm64_cross_daemon,
                    lib_output_dir=self.arm64_cross_lib_dir,
                    sysroot_root=self.arm64_sysroot_root,
                    sysroot_lock_file=self.arm64_sysroot_lock_file,
                    remote_host=self.arm64_sysroot_remote_host,
                    remote_user=self.arm64_sysroot_remote_user,
                    ssh_key_path=self.arm64_sysroot_ssh_key_path,
                )
                require_file_contains(self.arm64_cross_daemon_real, "ARM aarch64", "ARM64 daemon binary")
            require_nonempty_dir(self.arm64_cross_lib_dir, "ARM64 runtime lib dir")
            return
        if daemon_enabled:
            self._run_host_python_module(
                "runner.libs.arm64_host_build",
                "daemon",
                ARM64_HOST_DAEMON_TARGET_DIR=str(self.arm64_host_daemon_target_dir),
                ARM64_HOST_DAEMON_OUTPUT_DIR=str(self.arm64_host_daemon_output_dir),
                ARM64_HOST_DAEMON_BINARY=str(self.arm64_host_daemon_binary),
                ARM64_HOST_DAEMON_CARGO_HOME=str(self.arm64_host_daemon_cargo_home),
                **common_env,
            )
        self._run_arm64_container_build(
            runtime_targets_csv=runtime_targets_csv,
            llvmbpf_setting=llvmbpf_setting,
        )
        if "runner" in runtime_targets:
            require_file_contains(self.arm64_cross_runner_real, "ARM aarch64", "ARM64 runner binary")
        if "daemon" in runtime_targets:
            require_file_contains(self.arm64_cross_daemon_real, "ARM aarch64", "ARM64 daemon binary")
        require_nonempty_dir(self.arm64_cross_lib_dir, "ARM64 runtime lib dir")

    def prepare_kinsn_modules(self) -> None:
        if self.target_arch == "x86_64":
            ensure_x86_kinsn_modules_ready(build_paths_from_prep(self))
            return
        if self.target_arch == "arm64":
            state_kernel_release = self.remote_state.get("STATE_KERNEL_RELEASE", "").strip()
            ensure_arm64_kinsn_modules_ready(build_paths_from_prep(self), state_kernel_release=state_kernel_release)
            return
        die(f"unsupported AWS target arch for kinsn prep: {self.target_arch}")

    def prepare_test_outputs(self) -> None:
        if self.target_arch == "x86_64":
            build_x86_repo_tests(
                unittest_build_dir=self.x86_unittest_dir,
                negative_build_dir=self.x86_negative_dir,
                env=self._env_with_paths(),
                test_mode=self.env.get("RUN_TEST_MODE", "test").strip() or "test",
            )
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for test artifact prep: {self.target_arch}")
        self._run_host_python_module(
            "runner.libs.arm64_host_build",
            "repo-tests",
            VMLINUX_BTF=str(self.arm64_aws_build_dir / "vmlinux"),
            ARM64_TEST_MODE=self.env.get("RUN_TEST_MODE", "test").strip() or "test",
            ARM64_TEST_ARTIFACTS_ROOT=str(self.test_artifacts_root),
            ARM64_TEST_UNITTEST_BUILD_DIR=str(self.arm64_unittest_dir),
            ARM64_TEST_NEGATIVE_BUILD_DIR=str(self.arm64_negative_dir),
            ARM64_TEST_DAEMON_OUTPUT_DIR=str(self.test_artifacts_root / "daemon"),
            ARM64_TEST_PREBUILT_DAEMON_BINARY=str(self.arm64_host_daemon_binary),
            ARM64_HOST_DAEMON_TARGET_DIR=str(self.arm64_host_daemon_target_dir),
            ARM64_HOST_DAEMON_OUTPUT_DIR=str(self.arm64_host_daemon_output_dir),
            ARM64_HOST_DAEMON_BINARY=str(self.arm64_host_daemon_binary),
            ARM64_HOST_DAEMON_CARGO_HOME=str(self.arm64_host_daemon_cargo_home),
            UPSTREAM_SELFTEST_LLVM_SUFFIX=self.env.get("RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX", "").strip(),
            ARM64_UPSTREAM_SELFTEST_OUTPUT_DIR=str(self.arm64_upstream_selftests_dir),
            ARM64_SYSROOT_ROOT=str(self.arm64_sysroot_root),
            ARM64_SYSROOT_LOCK_FILE=str(self.arm64_sysroot_lock_file),
            ARM64_SYSROOT_REMOTE_HOST=self.arm64_sysroot_remote_host,
            ARM64_SYSROOT_REMOTE_USER=self.arm64_sysroot_remote_user,
            ARM64_SYSROOT_SSH_KEY_PATH=self.arm64_sysroot_ssh_key_path,
        )
        if (self.env.get("RUN_TEST_MODE", "test").strip() or "test") != "negative":
            require_file_contains(self.arm64_unittest_dir / "rejit_kinsn", "ARM aarch64", "ARM64 unittest binary")
        require_file_contains(self.arm64_negative_dir / "adversarial_rejit", "ARM aarch64", "ARM64 negative binary")
        if (self.env.get("RUN_TEST_MODE", "test").strip() or "test") == "test":
            require_file_contains(self.arm64_upstream_selftests_dir / "test_verifier", "ARM aarch64", "ARM64 upstream test_verifier")
            require_file_contains(self.arm64_upstream_selftests_dir / "test_progs", "ARM aarch64", "ARM64 upstream test_progs")

    def prepare_upstream_selftests(self) -> None:
        if self.target_arch == "x86_64":
            build_x86_upstream_selftests(
                output_dir=self.x86_upstream_selftests_dir,
                host_python_bin=self.host_python_bin,
                env=self._env_with_paths(),
                llvm_suffix=self.env.get("RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX", "").strip(),
            )
            return
        if self.target_arch == "arm64":
            return
        die(f"unsupported AWS target arch for upstream selftest prep: {self.target_arch}")

    def prepare_upstream_test_kmods(self) -> None:
        if self.target_arch == "x86_64":
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for upstream test kmods prep: {self.target_arch}")
        state_kernel_release = self.remote_state.get("STATE_KERNEL_RELEASE", "").strip()
        ensure_arm64_upstream_test_kmods_ready(build_paths_from_prep(self), kernel_release=state_kernel_release)

    def prepare_micro_programs(self) -> None:
        build_micro_program_outputs(output_dir=self.micro_programs_generated_dir, env=self._env_with_paths())

    def prepare_fetch_repos(self) -> None:
        fetch_selected_repos(
            repo_root=self.local_repo_root,
            repo_csv=self.env.get("RUN_FETCH_REPOS_CSV", "").strip(),
            host_python_bin=self.host_python_bin,
            env=self._env_with_paths(),
        )

    def prepare_scx_artifacts(self) -> None:
        package_csv = self.env.get("RUN_SCX_PACKAGES_CSV", "").strip()
        if not package_csv:
            return
        if self.target_arch == "x86_64":
            build_scx_artifacts(
                repo_root=self.local_repo_root,
                promote_root=self.promote_root,
                package_csv=package_csv,
                host_python_bin=self.host_python_bin,
                env=self._env_with_paths(),
                arch_signature="x86-64",
            )
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for scx prep: {self.target_arch}")
        require_nonempty_dir(self.local_repo_root / "scx", "sealed scx source repo")
        self._run_host_python_module(
            "runner.libs.arm64_host_build",
            "scx",
            ARM64_SCX_SOURCE_REPO_ROOT=str(self.local_repo_root),
            ARM64_SCX_PROMOTE_ROOT=str(self.arm64_crossbuild_output_dir),
            ARM64_HOST_SCX_BUILD_ROOT=str(self.arm64_host_scx_build_root),
            ARM64_HOST_SCX_CARGO_HOME=str(self.arm64_host_scx_cargo_home),
            ARM64_SCX_PACKAGES=package_csv,
            ARM64_SYSROOT_ROOT=str(self.arm64_sysroot_root),
            ARM64_SYSROOT_LOCK_FILE=str(self.arm64_sysroot_lock_file),
            ARM64_SYSROOT_REMOTE_HOST=self.arm64_sysroot_remote_host,
            ARM64_SYSROOT_REMOTE_USER=self.arm64_sysroot_remote_user,
            ARM64_SYSROOT_SSH_KEY_PATH=self.arm64_sysroot_ssh_key_path,
        )
        for package in csv_tokens(package_csv):
            require_file_contains(
                self.arm64_crossbuild_output_dir / "runner" / "repos" / "scx" / "target" / "release" / package,
                "ARM aarch64",
                f"ARM64 scx binary {package}",
            )
            require_path(
                self.arm64_crossbuild_output_dir / "corpus" / "build" / "scx" / f"{package}_main.bpf.o",
                f"ARM64 scx object {package}_main.bpf.o",
            )

    def prepare_native_repo_artifacts(self) -> None:
        native_repo_csv = self.env.get("RUN_NATIVE_REPOS_CSV", "").strip()
        if not native_repo_csv:
            return
        if self.target_arch == "x86_64":
            build_native_repo_artifacts(
                repo_root=self.local_repo_root,
                promote_root=self.promote_root,
                native_repo_csv=native_repo_csv,
                host_python_bin=self.host_python_bin,
                env=self._env_with_paths(),
            )
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for native repo prep: {self.target_arch}")
        self._run_arm64_container_build(bench_repos_csv=native_repo_csv)
        for repo in csv_tokens(native_repo_csv):
            if repo == "bcc":
                require_nonempty_dir(
                    self.arm64_crossbuild_output_dir / "runner" / "repos" / "bcc" / "libbpf-tools" / ".output",
                    "ARM64 BCC output dir",
                )
                require_nonempty_dir(
                    self.arm64_crossbuild_output_dir / "corpus" / "build" / "bcc" / "libbpf-tools",
                    "ARM64 staged BCC build dir",
                )
            elif repo == "katran":
                require_path(self.arm64_katran_server_binary, "ARM64 Katran server")
                require_nonempty_dir(self.arm64_katran_server_lib_dir, "ARM64 Katran lib dir")
                require_nonempty_dir(self.arm64_crossbuild_output_dir / "corpus" / "build" / "katran", "ARM64 staged Katran build dir")
            elif repo == "tracee":
                require_path(self.arm64_crossbuild_output_dir / "corpus" / "build" / "tracee" / "bin" / "tracee", "ARM64 Tracee binary")
                require_path(self.arm64_crossbuild_output_dir / "corpus" / "build" / "tracee" / "tracee.bpf.o", "ARM64 Tracee BPF object")
            elif repo == "tetragon":
                require_path(self.arm64_crossbuild_output_dir / "corpus" / "build" / "tetragon" / "bin" / "tetragon", "ARM64 Tetragon binary")
            else:
                die(f"unsupported ARM64 native repo prebuild: {repo}")

    def prepare_workload_tools(self) -> None:
        requested_csv = self.env.get("RUN_WORKLOAD_TOOLS_CSV", "").strip()
        if not requested_csv:
            return
        if self.target_arch == "x86_64":
            bundled_csv, tool_root = stage_x86_workload_tools(
                requested_csv=requested_csv,
                output_root=self.promote_root / "workload-tools",
            )
            self.bundled_workload_tools_csv = bundled_csv
            self.local_workload_tool_root = tool_root
            return
        if self.target_arch != "arm64":
            die(f"unsupported AWS target arch for workload-tool prep: {self.target_arch}")
        bundled_csv = ""
        for tool in csv_tokens(requested_csv):
            if tool in {"wrk", "sysbench", "hackbench"}:
                bundled_csv = csv_append_unique(bundled_csv, tool)
        if not bundled_csv:
            self.bundled_workload_tools_csv = ""
            self.local_workload_tool_root = ""
            return
        self._run_host_python_module(
            "runner.libs.arm64_host_build",
            "workload-tools",
            ARM64_WORKLOAD_TOOLS_BUILD_ROOT=str(self.run_prep_root / "arm64-workload-tools-host"),
            ARM64_WORKLOAD_TOOLS_OUTPUT_ROOT=str(self.arm64_crossbuild_output_dir),
            ARM64_WORKLOAD_TOOLS_LIST=bundled_csv,
            ARM64_SYSROOT_ROOT=str(self.arm64_sysroot_root),
            ARM64_SYSROOT_LOCK_FILE=str(self.arm64_sysroot_lock_file),
            ARM64_SYSROOT_REMOTE_HOST=self.arm64_sysroot_remote_host,
            ARM64_SYSROOT_REMOTE_USER=self.arm64_sysroot_remote_user,
            ARM64_SYSROOT_SSH_KEY_PATH=self.arm64_sysroot_ssh_key_path,
        )
        local_tool_root = self.arm64_crossbuild_output_dir / "workload-tools"
        require_nonempty_dir(local_tool_root / "bin", "ARM64 bundled workload tool bin dir")
        for tool in csv_tokens(bundled_csv):
            require_path(local_tool_root / "bin" / tool, f"ARM64 bundled workload tool wrapper {tool}")
            require_file_contains(local_tool_root / "bin" / f"{tool}.real", "ARM aarch64", f"ARM64 bundled workload tool binary {tool}")
        self.bundled_workload_tools_csv = bundled_csv
        self.local_workload_tool_root = str(local_tool_root)

    def prepare_benchmark_extra(self) -> None:
        if self.target_arch == "arm64":
            return
        if self.target_arch != "x86_64":
            die(f"unsupported AWS target arch for benchmark extra prep: {self.target_arch}")
        build_x86_portable_libbpf(self.x86_portable_libbpf_root)
        require_nonempty_dir(self.x86_portable_libbpf_root / "lib", "portable x86 libbpf dir")
        require_path(self.x86_portable_libbpf_root / "lib" / "libbpf.so.1", "portable x86 libbpf soname")

    def _write_bundle_inputs(self) -> None:
        write_state(
            self.bundle_inputs_path,
            {
                "RUN_LOCAL_REPO_ROOT": str(self.local_repo_root),
                "RUN_BUNDLED_WORKLOAD_TOOLS_CSV": self.bundled_workload_tools_csv,
            },
        )
        if self.local_workload_tool_root:
            merge_state(self.bundle_inputs_path, {"RUN_LOCAL_WORKLOAD_TOOL_ROOT": self.local_workload_tool_root})
        if self.micro_programs_generated_dir.exists():
            merge_state(self.bundle_inputs_path, {"MICRO_PROGRAMS_GENERATED_DIR": str(self.micro_programs_generated_dir)})
        if self.env.get("RUN_NEEDS_KINSN_MODULES", "0").strip() == "1":
            module_dir = self.arm64_kinsn_stage_dir if self.target_arch == "arm64" else self.x86_kinsn_stage_dir
            merge_state(self.bundle_inputs_path, {"RUN_KINSN_MODULE_DIR": str(module_dir)})
        merge_state(
            self.bundle_inputs_path,
            x86_bundle_inputs(
                promote_root=self.promote_root,
                local_repo_root=self.local_repo_root,
                test_artifacts_root=self.test_artifacts_root,
                portable_libbpf_root=self.x86_portable_libbpf_root,
            ),
        )
        merge_state(
            self.bundle_inputs_path,
            {
                "ARM64_CROSS_RUNNER": str(self.arm64_cross_runner),
                "ARM64_CROSS_RUNNER_REAL": str(self.arm64_cross_runner_real),
                "ARM64_CROSS_DAEMON": str(self.arm64_cross_daemon),
                "ARM64_CROSS_DAEMON_REAL": str(self.arm64_cross_daemon_real),
                "ARM64_CROSS_LIB_DIR": str(self.arm64_cross_lib_dir),
                "ARM64_TEST_UNITTEST_BUILD_DIR": str(self.arm64_unittest_dir),
                "ARM64_TEST_NEGATIVE_BUILD_DIR": str(self.arm64_negative_dir),
                "ARM64_UPSTREAM_SELFTEST_DIR": str(self.arm64_upstream_selftests_dir),
                "ARM64_UPSTREAM_TEST_KMODS_DIR": str(self.arm64_upstream_test_kmods_dir),
                "ARM64_NATIVE_BUILD_ROOT": str(self.arm64_crossbuild_output_dir / "corpus" / "build"),
                "ARM64_SCX_BINARY_ROOT": str(self.arm64_crossbuild_output_dir / "runner" / "repos" / "scx" / "target" / "release"),
                "ARM64_SCX_OBJECT_ROOT": str(self.arm64_crossbuild_output_dir / "corpus" / "build" / "scx"),
                "ARM64_KATRAN_SERVER_BINARY": str(self.arm64_katran_server_binary),
                "ARM64_KATRAN_SERVER_LIB_DIR": str(self.arm64_katran_server_lib_dir),
            },
        )

    def finalize(self) -> None:
        self._write_bundle_inputs()
        finalize_staged_bundle(
            manifest_path=self.manifest_path,
            bundle_inputs_path=self.bundle_inputs_path,
            stage_root=self.stage_root,
            bundle_tar=self.bundle_tar,
            local_state_path=self.local_state_path,
            host_python_bin=self.host_python_bin,
            env=self._env_with_paths(),
            executor_name="AWS",
        )


def run_local_prep(
    *,
    manifest_path: Path,
    local_state_path: Path,
    remote_prep_state_path: Path,
    env: dict[str, str],
    phases: list[str],
) -> None:
    prep = AWSPrep(
        env=env,
        manifest_path=manifest_path,
        local_state_path=local_state_path,
        remote_prep_state_path=remote_prep_state_path,
    )
    prep.init()
    phase_handlers = {
        "runtime": prep.prepare_runtime_artifacts,
        "kinsn": prep.prepare_kinsn_modules,
        "test_outputs": prep.prepare_test_outputs,
        "upstream_selftests": prep.prepare_upstream_selftests,
        "upstream_test_kmods": prep.prepare_upstream_test_kmods,
        "micro_programs": prep.prepare_micro_programs,
        "fetch_repos": prep.prepare_fetch_repos,
        "scx": prep.prepare_scx_artifacts,
        "native": prep.prepare_native_repo_artifacts,
        "workload_tools": prep.prepare_workload_tools,
        "benchmark_extra": prep.prepare_benchmark_extra,
    }
    run_local_prep_phases(phases=phases, phase_handlers=phase_handlers, executor_name="aws-ssh")
    prep.finalize()
