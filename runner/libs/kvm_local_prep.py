from __future__ import annotations

import shutil
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs.local_prep_common import (
    build_micro_program_outputs,
    build_native_repo_artifacts,
    build_scx_artifacts,
    build_x86_daemon_binary,
    build_x86_repo_tests,
    build_x86_runner_binary,
    build_x86_upstream_selftests,
    die,
    fetch_selected_repos,
    make_runner,
    run_command,
    stage_x86_workload_tools,
)
from runner.libs.state_file import merge_state, write_state


class KVMPrep:
    def __init__(self, *, env: dict[str, str], manifest_path: Path, local_state_path: Path) -> None:
        self.env = env
        self.manifest_path = manifest_path
        self.local_state_path = local_state_path
        self.run_token = env.get("RUN_TOKEN", "").strip()
        if not self.run_token:
            die("manifest RUN_TOKEN is empty for KVM local prep")
        self.host_python_bin = env.get("RUN_HOST_PYTHON_BIN", "").strip()
        if not self.host_python_bin:
            die("manifest host python is missing")
        self.promote_root = ROOT_DIR / ".cache" / "kvm-staged" / self.run_token / "prep"
        self.test_artifacts_root = self.promote_root / "test-artifacts"
        self.bundle_inputs_path = ROOT_DIR / ".cache" / "kvm-staged" / self.run_token / "bundle-inputs.json"
        self.stage_root = ROOT_DIR / ".cache" / "kvm-staged" / self.run_token / "workspace"
        self.bundle_tar = ROOT_DIR / ".cache" / "kvm-staged" / f"{self.run_token}.tar.gz"
        self.local_repo_root = self.promote_root / "runner" / "repos"
        self.micro_programs_generated_dir = self.promote_root / "micro" / "programs"
        self.bundled_workload_tools_csv = ""
        self.local_workload_tool_root = ""

    def init(self) -> None:
        shutil.rmtree(self.promote_root, ignore_errors=True)
        self.promote_root.mkdir(parents=True, exist_ok=True)

    def _make_runner(self, *targets: str, **extra_env: str) -> None:
        make_runner(*targets, env=self.env, **extra_env)

    def ensure_kernel_image_ready(self) -> None:
        self._make_runner("kernel-image")

    def prepare_runtime_artifacts(self) -> None:
        if self.env.get("RUN_NEEDS_RUNNER_BINARY", "0").strip() == "1":
            build_x86_runner_binary(build_dir=self.promote_root / "runner" / "build", env=self.env)
        if self.env.get("RUN_NEEDS_DAEMON_BINARY", "0").strip() == "1":
            build_x86_daemon_binary(daemon_target_dir=self.promote_root / "daemon" / "target", env=self.env)

    def prepare_kinsn_modules(self) -> None:
        self._make_runner(
            "kinsn-modules-build",
            KINSN_MODULE_OUTPUT_DIR=str(self.test_artifacts_root / "kinsn-modules" / "x86"),
        )

    def prepare_test_outputs(self) -> None:
        build_x86_repo_tests(
            unittest_build_dir=self.test_artifacts_root / "unittest" / "build",
            negative_build_dir=self.test_artifacts_root / "negative" / "build",
            env=self.env,
            test_mode=self.env.get("RUN_TEST_MODE", "test").strip() or "test",
        )

    def prepare_upstream_selftests(self) -> None:
        build_x86_upstream_selftests(
            output_dir=self.test_artifacts_root / "upstream-bpf-selftests",
            host_python_bin=self.host_python_bin,
            env=self.env,
            llvm_suffix=self.env.get("RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX", "").strip(),
        )

    def prepare_micro_programs(self) -> None:
        build_micro_program_outputs(output_dir=self.micro_programs_generated_dir, env=self.env)

    def prepare_fetch_repos(self) -> None:
        fetch_selected_repos(
            repo_root=self.local_repo_root,
            repo_csv=self.env.get("RUN_FETCH_REPOS_CSV", "").strip(),
            host_python_bin=self.host_python_bin,
            env=self.env,
        )

    def prepare_scx_artifacts(self) -> None:
        package_csv = self.env.get("RUN_SCX_PACKAGES_CSV", "").strip()
        if not package_csv:
            return
        build_scx_artifacts(
            repo_root=self.local_repo_root,
            promote_root=self.promote_root,
            package_csv=package_csv,
            host_python_bin=self.host_python_bin,
            env=self.env,
            arch_signature="x86-64",
        )

    def prepare_native_repo_artifacts(self) -> None:
        build_native_repo_artifacts(
            repo_root=self.local_repo_root,
            promote_root=self.promote_root,
            native_repo_csv=self.env.get("RUN_NATIVE_REPOS_CSV", "").strip(),
            host_python_bin=self.host_python_bin,
            env=self.env,
        )

    def prepare_workload_tools(self) -> None:
        bundled_csv, tool_root = stage_x86_workload_tools(
            requested_csv=self.env.get("RUN_WORKLOAD_TOOLS_CSV", "").strip(),
            output_root=self.promote_root / "workload-tools",
        )
        self.bundled_workload_tools_csv = bundled_csv
        self.local_workload_tool_root = tool_root

    def _write_bundle_inputs(self) -> None:
        write_state(self.bundle_inputs_path, {})
        merge_state(
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
            merge_state(
                self.bundle_inputs_path,
                {"RUN_KINSN_MODULE_DIR": str(self.test_artifacts_root / "kinsn-modules" / "x86")},
            )
        portable_libbpf_root = self.promote_root / "portable-libbpf"
        values = {
            "X86_RUNNER": str(self.promote_root / "runner" / "build" / "micro_exec"),
            "X86_DAEMON": str(self.promote_root / "daemon" / "target" / "release" / "bpfrejit-daemon"),
            "X86_TEST_UNITTEST_BUILD_DIR": str(self.test_artifacts_root / "unittest" / "build"),
            "X86_TEST_NEGATIVE_BUILD_DIR": str(self.test_artifacts_root / "negative" / "build"),
            "X86_UPSTREAM_SELFTEST_DIR": str(self.test_artifacts_root / "upstream-bpf-selftests"),
            "X86_NATIVE_BUILD_ROOT": str(self.promote_root / "corpus" / "build"),
            "X86_SCX_BINARY_ROOT": str(self.local_repo_root / "scx" / "target" / "release"),
            "X86_SCX_OBJECT_ROOT": str(self.promote_root / "corpus" / "build" / "scx"),
            "X86_KATRAN_SERVER_BINARY": str(self.promote_root / "corpus" / "build" / "katran" / "bin" / "katran_server_grpc"),
            "X86_KATRAN_SERVER_LIB_DIR": str(self.promote_root / "corpus" / "build" / "katran" / "lib"),
        }
        if (portable_libbpf_root / "lib").is_dir():
            values["X86_PORTABLE_LIBBPF_ROOT"] = str(portable_libbpf_root)
        merge_state(self.bundle_inputs_path, values)

    def finalize(self) -> None:
        self._write_bundle_inputs()
        self.stage_root.parent.mkdir(parents=True, exist_ok=True)
        self.bundle_tar.parent.mkdir(parents=True, exist_ok=True)
        run_command(
            [
                self.host_python_bin,
                "-m",
                "runner.libs.build_remote_bundle",
                str(self.manifest_path),
                str(self.bundle_inputs_path),
                str(self.stage_root),
                str(self.bundle_tar),
            ],
            env=self.env,
        )
        if not self.bundle_tar.is_file():
            die(f"staged KVM bundle tar is missing: {self.bundle_tar}")
        write_state(self.local_state_path, {"RUN_BUNDLE_TAR": str(self.bundle_tar)})


def run_local_prep(*, manifest_path: Path, local_state_path: Path, env: dict[str, str], phases: list[str]) -> None:
    prep = KVMPrep(env=env, manifest_path=manifest_path, local_state_path=local_state_path)
    prep.init()
    phase_handlers = {
        "base": prep.ensure_kernel_image_ready,
        "runtime": prep.prepare_runtime_artifacts,
        "kinsn": prep.prepare_kinsn_modules,
        "test_outputs": prep.prepare_test_outputs,
        "upstream_selftests": prep.prepare_upstream_selftests,
        "micro_programs": prep.prepare_micro_programs,
        "fetch_repos": prep.prepare_fetch_repos,
        "scx": prep.prepare_scx_artifacts,
        "native": prep.prepare_native_repo_artifacts,
        "workload_tools": prep.prepare_workload_tools,
    }
    for phase in phases:
        handler = phase_handlers.get(phase)
        if handler is None:
            die(f"no local-prep phase mapping for kvm:{phase}")
        handler()
    prep.finalize()
