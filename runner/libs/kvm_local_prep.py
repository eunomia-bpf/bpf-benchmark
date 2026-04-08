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
    finalize_staged_bundle,
    fetch_selected_repos,
    run_local_prep_phases,
    stage_x86_workload_tools,
    x86_bundle_inputs,
)
from runner.libs.portable_runtime import build_x86_portable_libbpf
from runner.libs.state_file import merge_state, write_state
from runner.libs.x86_kernel_artifacts import ensure_kvm_kernel_ready, stage_kinsn_modules


class KVMPrep:
    def __init__(self, *, env: dict[str, str], manifest_path: Path, local_state_path: Path) -> None:
        self.env = env
        self.manifest_path = manifest_path
        self.local_state_path = local_state_path
        self.target_name = env.get("RUN_TARGET_NAME", "").strip() or "x86-kvm"
        self.run_token = env.get("RUN_TOKEN", "").strip()
        if not self.run_token:
            die("manifest RUN_TOKEN is empty for KVM local prep")
        self.host_python_bin = env.get("RUN_HOST_PYTHON_BIN", "").strip()
        if not self.host_python_bin:
            die("manifest host python is missing")
        self.target_cache_dir = ROOT_DIR / ".cache" / self.target_name
        self.run_prep_root = self.target_cache_dir / "runs" / self.run_token
        self.promote_root = self.run_prep_root / "bundle-inputs"
        self.test_artifacts_root = self.promote_root / "test-artifacts"
        self.bundle_inputs_path = self.run_prep_root / "bundle-inputs.json"
        self.stage_root = self.run_prep_root / "workspace"
        self.bundle_tar = self.run_prep_root / "bundle.tar.gz"
        self.local_repo_root = self.promote_root / "runner" / "repos"
        self.micro_programs_generated_dir = self.promote_root / "micro" / "programs"
        self.bundled_workload_tools_csv = ""
        self.local_workload_tool_root = ""

    def init(self) -> None:
        shutil.rmtree(self.run_prep_root, ignore_errors=True)
        self.promote_root.mkdir(parents=True, exist_ok=True)

    def ensure_kernel_image_ready(self) -> None:
        kernel_image = self.env.get("RUN_VM_KERNEL_IMAGE", "").strip()
        if not kernel_image:
            die("manifest RUN_VM_KERNEL_IMAGE is empty for KVM local prep")
        jobs = int((self.env.get("JOBS", "").strip() or "0") or 0) or None
        ensure_kvm_kernel_ready(
            jobs=jobs,
            bzimage=(ROOT_DIR / kernel_image).resolve() if not kernel_image.startswith("/") else Path(kernel_image).resolve(),
        )

    def prepare_runtime_artifacts(self) -> None:
        if self.env.get("RUN_NEEDS_RUNNER_BINARY", "0").strip() == "1":
            build_x86_runner_binary(build_dir=self.promote_root / "runner" / "build", env=self.env)
        if self.env.get("RUN_NEEDS_DAEMON_BINARY", "0").strip() == "1":
            build_x86_daemon_binary(daemon_target_dir=self.promote_root / "daemon" / "target", env=self.env)

    def prepare_kinsn_modules(self) -> None:
        output_dir = self.test_artifacts_root / "kinsn-modules" / "x86"
        stage_kinsn_modules(output_dir=output_dir)

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

    def prepare_benchmark_extra(self) -> None:
        build_x86_portable_libbpf(self.promote_root / "portable-libbpf")

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
        merge_state(
            self.bundle_inputs_path,
            x86_bundle_inputs(
                promote_root=self.promote_root,
                local_repo_root=self.local_repo_root,
                test_artifacts_root=self.test_artifacts_root,
                portable_libbpf_root=self.promote_root / "portable-libbpf",
            ),
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
            env=self.env,
            executor_name="KVM",
        )


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
        "benchmark_extra": prep.prepare_benchmark_extra,
        "workload_tools": prep.prepare_workload_tools,
    }
    run_local_prep_phases(phases=phases, phase_handlers=phase_handlers, executor_name="kvm")
    prep.finalize()
