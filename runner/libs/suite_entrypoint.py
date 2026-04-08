from __future__ import annotations

import os
import re
import shlex
import shutil
import subprocess
import sys
import tarfile
from dataclasses import dataclass
from datetime import datetime, timezone
from functools import partial
from pathlib import Path
from typing import cast

from runner.libs.cli_support import fail
from runner.libs.guest_prereqs import resolve_remote_workload_tool_bin, workload_tool_is_bundled
from runner.libs.kinsn import load_kinsn_modules
from runner.libs.run_contract import parse_manifest

_die = partial(fail, "suite-entrypoint")

def _parse_shell_argv(serialized: str) -> list[str]:
    text = serialized.strip()
    if not text:
        return []
    return shlex.split(text)


def _resolve_workspace_contract_path(workspace: Path, path: str) -> Path:
    candidate = Path(path)
    if candidate.is_absolute():
        return candidate
    return workspace / candidate


def _latest_result_dir(parent: Path, prefix: str) -> Path:
    matches = sorted(
        path
        for path in parent.iterdir()
        if path.is_dir() and path.name.startswith(f"{prefix}_")
    )
    if not matches:
        _die(f"result directory is missing for prefix {prefix}: {parent}")
    return matches[-1]


def _sanitize_artifact_token(value: str) -> str:
    token = re.sub(r"[^0-9A-Za-z]+", "_", value).strip("_")
    return token or "run"


def _copy_result_dir(source_dir: Path, destination_dir: Path) -> None:
    if not source_dir.is_dir():
        _die(f"result directory is missing: {source_dir}")
    destination_dir.mkdir(parents=True, exist_ok=True)
    target_dir = destination_dir / source_dir.name
    if target_dir.exists():
        shutil.rmtree(target_dir)
    shutil.copytree(source_dir, target_dir)


def _cross_runtime_ld_library_path(workspace: Path, target_arch: str) -> str:
    if target_arch != "arm64":
        return ""
    entries: list[str] = []
    for path in (
        workspace / "tests" / "unittest" / "build-arm64" / "lib",
        workspace / "tests" / "unittest" / "build" / "lib",
    ):
        if path.is_dir():
            entries.append(str(path))
    return ":".join(entries)


def _run_and_tee(command: list[str], *, cwd: Path, env: dict[str, str], log_path: Path) -> None:
    log_path.parent.mkdir(parents=True, exist_ok=True)
    with log_path.open("a", encoding="utf-8") as log_file:
        process = subprocess.Popen(
            command,
            cwd=cwd,
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
        )
        assert process.stdout is not None
        for line in process.stdout:
            log_file.write(line)
            sys.stderr.write(line)
        returncode = process.wait()
    if returncode != 0:
        rendered = " ".join(shlex.quote(part) for part in command)
        _die(f"command failed ({returncode}): {rendered}")


def _run_with_status(
    command: list[str],
    *,
    cwd: Path,
    env: dict[str, str],
    log_path: Path | None = None,
) -> bool:
    process = subprocess.Popen(
        command,
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


def _run_checked(command: list[str], *, cwd: Path, env: dict[str, str]) -> None:
    completed = subprocess.run(
        command,
        cwd=cwd,
        env=env,
        text=True,
        capture_output=False,
        check=False,
    )
    if completed.returncode != 0:
        rendered = " ".join(shlex.quote(part) for part in command)
        _die(f"command failed ({completed.returncode}): {rendered}")


def _require_executable(path: Path, description: str) -> Path:
    if not path.is_file() or not os.access(path, os.X_OK):
        _die(f"{description} is missing or not executable: {path}")
    return path


@dataclass
class SuiteEntrypoint:
    contract: dict[str, str | list[str]]
    workspace: Path
    manifest_path: Path
    archive_path: Path | None
    target_name: str
    suite_name: str
    target_arch: str
    executor: str
    python_bin: str
    bpftool_bin: str
    artifact_dir: Path
    remote_workload_tool_bin: Path | None
    bundled_workload_tools: list[str]
    workload_tools: list[str]
    corpus_argv: list[str]
    e2e_argv: list[str]

    def _required_contract(self, name: str) -> str:
        value = self.contract.get(name, "")
        if isinstance(value, list) or not str(value).strip():
            _die(f"manifest {name} is empty")
        return str(value).strip()

    def _optional_contract(self, name: str, default: str = "") -> str:
        value = self.contract.get(name, default)
        if isinstance(value, list):
            _die(f"manifest {name} must be scalar")
        return str(value).strip()

    def _csv_contract(self, name: str) -> list[str]:
        value = self.contract.get(name, "")
        if isinstance(value, list):
            return [token for token in value if token]
        return [token for token in str(value).split(",") if token]

    def _bool_contract(self, name: str, *, default: str = "0") -> bool:
        return self._optional_contract(name, default) == "1"

    @classmethod
    def from_contract(
        cls,
        workspace: Path,
        manifest_path: Path,
        archive_path: Path | None,
        contract: dict[str, str | list[str]],
    ) -> "SuiteEntrypoint":
        def required_scalar(name: str) -> str:
            value = contract.get(name, "")
            if isinstance(value, list) or not str(value).strip():
                _die(f"manifest {name} is empty")
            return str(value)

        def csv_value(name: str) -> list[str]:
            value = contract.get(name, "")
            if isinstance(value, list):
                tokens = value
            else:
                tokens = [token for token in str(value).split(",") if token]
            return [token for token in tokens if token]

        def argv_value(name: str) -> list[str]:
            value = contract.get(name, [])
            if isinstance(value, list):
                return list(value)
            return _parse_shell_argv(str(value))

        target_name = required_scalar("RUN_TARGET_NAME")
        suite_name = required_scalar("RUN_SUITE_NAME")
        target_arch = required_scalar("RUN_TARGET_ARCH")
        executor = required_scalar("RUN_EXECUTOR")
        python_bin = required_scalar("RUN_REMOTE_PYTHON_BIN")
        bpftool_bin = required_scalar("RUN_BPFTOOL_BIN")
        result_root = workspace / ".cache" / "suite-results"
        run_token = _sanitize_artifact_token(f"{target_name}_{suite_name}")
        stamp = datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")
        artifact_dir = result_root / f"{run_token}_{stamp}"
        workload_tools = csv_value("RUN_WORKLOAD_TOOLS_CSV")
        return cls(
            contract=contract,
            workspace=workspace,
            manifest_path=manifest_path,
            archive_path=archive_path,
            target_name=target_name,
            suite_name=suite_name,
            target_arch=target_arch,
            executor=executor,
            python_bin=python_bin,
            bpftool_bin=bpftool_bin,
            artifact_dir=artifact_dir,
            remote_workload_tool_bin=resolve_remote_workload_tool_bin(workspace, contract),
            bundled_workload_tools=csv_value("RUN_BUNDLED_WORKLOAD_TOOLS_CSV"),
            workload_tools=workload_tools,
            corpus_argv=argv_value("RUN_CORPUS_ARGV"),
            e2e_argv=argv_value("RUN_E2E_ARGV"),
        )

    def _runtime_env(self) -> dict[str, str]:
        env = os.environ.copy()
        env["PATH"] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
        current_path = os.environ.get("PATH", "")
        if current_path:
            env["PATH"] = f'{env["PATH"]}:{current_path}'
        if self.remote_workload_tool_bin and self.remote_workload_tool_bin.is_dir():
            env["PATH"] = f"{self.remote_workload_tool_bin}:{env['PATH']}"
        if self.target_arch == "arm64":
            arm_libbpf = self.workspace / "lib" / "libbpf.so.1"
            if arm_libbpf.is_file():
                env["BPFREJIT_LIBBPF_PATH"] = str(arm_libbpf)
        elif self.target_arch == "x86_64":
            x86_libbpf = self.workspace / ".cache" / "portable-libbpf" / "lib" / "libbpf.so.1"
            if x86_libbpf.is_file():
                env["BPFREJIT_LIBBPF_PATH"] = str(x86_libbpf)
        if self.executor == "aws-ssh":
            env["BPFREJIT_KERNEL_MODULES_ROOT"] = "/"
        env["PYTHONPATH"] = str(self.workspace)
        env["BPFTOOL_BIN"] = self.bpftool_bin
        if shutil.which(self.bpftool_bin, path=env["PATH"]) is None:
            _die(f"required command is missing: {self.bpftool_bin}")
        if shutil.which(self.python_bin, path=env["PATH"]) is None:
            _die(f"required command is missing: {self.python_bin}")
        return env

    def _test_unittest_build_dir(self) -> Path:
        return self.workspace / "tests" / "unittest" / ("build-arm64" if self.target_arch == "arm64" else "build")

    def _test_negative_build_dir(self) -> Path:
        return self.workspace / "tests" / "negative" / ("build-arm64" if self.target_arch == "arm64" else "build")

    def _test_kinsn_module_dir(self) -> Path:
        return self.workspace / "module" / ("arm64" if self.target_arch == "arm64" else "x86")

    def _expected_kinsn_modules(self) -> list[str]:
        module_dir = self._test_kinsn_module_dir()
        modules = sorted(
            path.stem
            for path in module_dir.glob("bpf_*.ko")
            if path.is_file() and path.stem != "bpf_barrier"
        )
        if not modules:
            _die(f"no kinsn modules found under {module_dir}")
        return modules

    def _resolve_test_daemon(self) -> Path:
        return _require_executable(
            self.workspace / "daemon" / "target" / "release" / "bpfrejit-daemon",
            "test daemon",
        )

    def _ensure_runner_binary(self) -> None:
        if not self._bool_contract("RUN_NEEDS_RUNNER_BINARY"):
            return
        _require_executable(self.workspace / "runner" / "build" / "micro_exec", "bundled runner binary")

    def _ensure_scx_artifacts(self) -> None:
        packages = self._csv_contract("RUN_SCX_PACKAGES_CSV")
        if not packages:
            return
        for package in packages:
            _require_executable(
                self.workspace / "runner" / "repos" / "scx" / "target" / "release" / package,
                "bundled scx binary",
            )
            object_path = self.workspace / "corpus" / "build" / "scx" / f"{package}_main.bpf.o"
            if not object_path.is_file():
                _die(f"bundled scx object is missing: {object_path}")

    def _ensure_bundled_repos(self) -> None:
        for repo in self._csv_contract("RUN_BUNDLED_REPOS_CSV"):
            repo_dir = self.workspace / "runner" / "repos" / repo
            if not repo_dir.is_dir():
                _die(f"bundled repo is missing: {repo_dir}")

    def _ensure_katran_bundle(self, env: dict[str, str]) -> None:
        if not self._bool_contract("RUN_NEEDS_KATRAN_BUNDLE"):
            return
        binary = _require_executable(
            self.workspace / "e2e" / "cases" / "katran" / "bin" / "katran_server_grpc",
            "bundled Katran server",
        )
        lib_dir = self.workspace / "e2e" / "cases" / "katran" / "lib"
        if not lib_dir.is_dir():
            _die("bundled Katran runtime lib dir is missing")
        env["KATRAN_SERVER_BINARY"] = str(binary)
        env["KATRAN_SERVER_LIB_DIR"] = str(lib_dir)

    def _ensure_upstream_selftests(self) -> None:
        output_dir = self.workspace / ".cache" / "upstream-bpf-selftests"
        _require_executable(output_dir / "test_verifier", "bundled upstream test_verifier")
        _require_executable(output_dir / "test_progs", "bundled upstream test_progs")
        kmods_dir = self.workspace / "upstream-selftests-kmods"
        if kmods_dir.is_dir():
            for module in kmods_dir.glob("*.ko"):
                shutil.copy2(module, output_dir / module.name)
        elif self.target_arch == "arm64":
            _die("bundled upstream selftest kmods are missing from the workspace")

    def _ensure_workload_tools(self, env: dict[str, str]) -> None:
        if not self.workload_tools:
            return
        for tool in self.workload_tools:
            if workload_tool_is_bundled(self.contract, tool):
                if self.remote_workload_tool_bin is None:
                    _die("manifest remote workload-tool bin is missing while workload tools are requested")
                bundled_tool = self.remote_workload_tool_bin / tool
                _require_executable(bundled_tool, "required bundled workload tool")
                continue
            if shutil.which(tool, path=env.get("PATH")) is None:
                _die(f"required workload tool is missing from both the remote tool bin and PATH: {tool}")

    def _ensure_bpf_stats_enabled(self) -> None:
        if not self._bool_contract("RUN_NEEDS_DAEMON_BINARY"):
            return
        bpf_stats_path = Path("/proc/sys/kernel/bpf_stats_enabled")
        if not os.access(bpf_stats_path, os.W_OK):
            _die("kernel bpf_stats_enabled sysctl is not writable")
        sysctl_bin = shutil.which("sysctl")
        if sysctl_bin:
            _run_checked([sysctl_bin, "-q", "-w", "kernel.bpf_stats_enabled=1"], cwd=self.workspace, env=os.environ.copy())
        else:
            bpf_stats_path.write_text("1\n", encoding="utf-8")
        if bpf_stats_path.read_text(encoding="utf-8").strip() != "1":
            _die("failed to enable kernel.bpf_stats_enabled=1")

    def _validate_test_contract(self) -> None:
        for name in (
            "RUN_TEST_FUZZ_ROUNDS",
            "RUN_TEST_SCX_PROG_SHOW_RACE_MODE",
            "RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS",
            "RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT",
            "RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE",
        ):
            self._required_contract(name)

    def _log_test_section(self, title: str) -> None:
        print("", file=sys.stderr)
        print("========================================", file=sys.stderr)
        print(f"  {title}", file=sys.stderr)
        print("========================================", file=sys.stderr)

    def _load_kinsn_modules(self) -> None:
        load_kinsn_modules(
            self._expected_kinsn_modules(),
            module_dir=self._test_kinsn_module_dir(),
        )

    def _discover_unittest_binaries(self) -> list[Path]:
        build_dir = self._test_unittest_build_dir()
        return sorted(
            path
            for path in build_dir.glob("rejit_*")
            if path.is_file() and os.access(path, os.X_OK)
        )

    def _run_unittest_suite(self, env: dict[str, str], *, log_path: Path | None = None) -> tuple[int, int]:
        self._log_test_section("Running tests/unittest/ suite (pre-built)")
        build_dir = self._test_unittest_build_dir()
        tests = self._discover_unittest_binaries()
        passed = 0
        failed = 0
        if not tests:
            print(f"ERROR: no rejit_* test binaries found in {build_dir}", file=sys.stderr)
            return 0, 1
        runtime_env = env.copy()
        runtime_env["BPFREJIT_PROGS_DIR"] = str(build_dir / "progs")
        runtime_env["BPFREJIT_DAEMON_PATH"] = str(self._resolve_test_daemon())
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        for test_binary in tests:
            print(f"--- {test_binary.name} ---", file=sys.stderr)
            if _run_with_status([str(test_binary), str(build_dir / "progs")], cwd=self.workspace, env=runtime_env, log_path=log_path):
                passed += 1
            else:
                failed += 1
                print(f"FAIL: {test_binary.name}", file=sys.stderr)
        return passed, failed

    def _run_negative_suite(
        self,
        env: dict[str, str],
        *,
        include_scx_race: bool,
        log_path: Path | None = None,
    ) -> tuple[int, int]:
        self._log_test_section("Running tests/negative/ adversarial suite")
        negative_build = self._test_negative_build_dir()
        runtime_env = env.copy()
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        passed = 0
        failed = 0
        tests: list[tuple[str, list[str], dict[str, str]]] = [
            ("adversarial_rejit", [str(negative_build / "adversarial_rejit")], runtime_env.copy()),
            (
                f"fuzz_rejit ({self._required_contract('RUN_TEST_FUZZ_ROUNDS')} rounds)",
                [str(negative_build / "fuzz_rejit"), self._required_contract("RUN_TEST_FUZZ_ROUNDS")],
                runtime_env.copy(),
            ),
        ]
        if include_scx_race:
            scx_env = runtime_env.copy()
            scx_env["SCX_RUNTIME_LD_LIBRARY_PATH"] = runtime_ld
            scx_command = [
                str(negative_build / "scx_prog_show_race"),
                str(self.workspace),
                "--mode",
                self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_MODE"),
                "--iterations",
                self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS"),
                "--load-timeout",
                self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT"),
            ]
            if self._bool_contract("RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE"):
                scx_command.append("--skip-probe")
            tests.append((f"scx_prog_show_race ({self._required_contract('RUN_TEST_SCX_PROG_SHOW_RACE_MODE')})", scx_command, scx_env))
        for label, command, command_env in tests:
            print(f"--- {label} ---", file=sys.stderr)
            if _run_with_status(command, cwd=self.workspace, env=command_env, log_path=log_path):
                passed += 1
            else:
                failed += 1
                print(f"FAIL: {label.split(' (')[0]}", file=sys.stderr)
        return passed, failed

    def _run_upstream_test_verifier(self) -> tuple[int, int]:
        upstream_dir = self.workspace / ".cache" / "upstream-bpf-selftests"
        verifier = upstream_dir / "test_verifier"
        if not verifier.is_file():
            print(f"SKIP: test_verifier not found at {verifier}", file=sys.stderr)
            return 0, 0
        self._log_test_section("Upstream test_verifier")
        if _run_with_status([str(verifier)], cwd=upstream_dir, env={"PATH": os.environ.get("PATH", "")}):
            return 1, 0
        print("FAIL: test_verifier", file=sys.stderr)
        return 0, 1

    def _run_upstream_test_progs(self) -> tuple[int, int]:
        upstream_dir = self.workspace / ".cache" / "upstream-bpf-selftests"
        test_progs = upstream_dir / "test_progs"
        if not test_progs.is_file():
            print(f"SKIP: test_progs not found at {test_progs}", file=sys.stderr)
            return 0, 0
        filter_tokens = self._csv_contract("RUN_UPSTREAM_TEST_PROGS_FILTERS")
        deny_tokens = self._csv_contract("RUN_UPSTREAM_TEST_PROGS_DENY")
        self._log_test_section(
            f"Upstream test_progs (filter: {' '.join(filter_tokens)}; deny: {' '.join(deny_tokens)})"
        )
        command = [str(test_progs)]
        for token in filter_tokens:
            command += ["-t", token]
        for token in deny_tokens:
            command += ["-d", token]
        if _run_with_status(command, cwd=upstream_dir, env={"PATH": os.environ.get("PATH", "")}):
            return 1, 0
        print("FAIL: test_progs", file=sys.stderr)
        return 0, 1

    def _run_kernel_selftest(self) -> tuple[int, int]:
        kernel_selftest = self.workspace / "tests" / "kernel" / "build" / "test_recompile"
        if not kernel_selftest.is_file():
            print(f"SKIP: test_recompile not found at {kernel_selftest}", file=sys.stderr)
            return 0, 0
        self._log_test_section("Kernel selftest (test_recompile)")
        if _run_with_status([str(kernel_selftest)], cwd=self.workspace, env=os.environ.copy()):
            return 1, 0
        print("FAIL: test_recompile", file=sys.stderr)
        return 0, 1

    def _print_test_summary(self, passed: int, failed: int, *, prefix: str = "RESULTS") -> None:
        print("", file=sys.stderr)
        print("========================================", file=sys.stderr)
        print(f"  {prefix}: {passed} passed, {failed} failed", file=sys.stderr)
        print("========================================", file=sys.stderr)

    def _run_selftest_mode(self, env: dict[str, str]) -> None:
        log_path = self.artifact_dir / "selftest.log"
        self._log_test_section("Loading kinsn modules")
        self._load_kinsn_modules()
        passed_a, failed_a = self._run_unittest_suite(env, log_path=log_path)
        passed_b, failed_b = self._run_negative_suite(env, include_scx_race=False, log_path=log_path)
        total_pass = passed_a + passed_b
        total_fail = failed_a + failed_b
        self._print_test_summary(total_pass, total_fail, prefix="vm-selftest")
        if total_fail:
            _die("vm-selftest failed")

    def _run_negative_mode(self, env: dict[str, str]) -> None:
        log_path = self.artifact_dir / "negative.log"
        passed, failed = self._run_negative_suite(env, include_scx_race=True, log_path=log_path)
        self._print_test_summary(passed, failed, prefix="vm-negative-test")
        if failed:
            _die("vm-negative-test failed")

    def _run_full_test_mode(self, env: dict[str, str]) -> None:
        self._ensure_upstream_selftests()
        total_pass = 0
        total_fail = 0
        passed, failed = self._run_kernel_selftest()
        total_pass += passed
        total_fail += failed
        passed, failed = self._run_upstream_test_verifier()
        total_pass += passed
        total_fail += failed
        self._log_test_section("Loading kinsn modules")
        self._load_kinsn_modules()
        passed, failed = self._run_unittest_suite(env)
        total_pass += passed
        total_fail += failed
        passed, failed = self._run_negative_suite(env, include_scx_race=True)
        total_pass += passed
        total_fail += failed
        passed, failed = self._run_upstream_test_progs()
        total_pass += passed
        total_fail += failed
        self._print_test_summary(total_pass, total_fail)
        if total_fail:
            _die("vm-test failed")
        print("vm-test: ALL PASSED", file=sys.stderr)
        _copy_result_dir(self.workspace / ".cache" / "upstream-bpf-selftests", self.artifact_dir)

    def _run_test_suite(self, env: dict[str, str]) -> None:
        self._validate_test_contract()
        self._ensure_scx_artifacts()
        mode = self._required_contract("RUN_TEST_MODE")
        if mode == "selftest":
            self._run_selftest_mode(env)
        elif mode == "negative":
            self._run_negative_mode(env)
        elif mode == "test":
            self._run_full_test_mode(env)
        else:
            _die(f"unsupported test mode: {mode}")

    def _run_micro_suite(self, env: dict[str, str]) -> None:
        self._ensure_runner_binary()
        runtime_env = env.copy()
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        output_json = self.workspace / "micro" / "results" / f"{self.target_name}_micro.json"
        command = [
            self.python_bin,
            str(self.workspace / "micro" / "driver.py"),
            "--runtime",
            "llvmbpf",
            "--runtime",
            "kernel",
            "--samples",
            self._required_contract("RUN_BENCH_SAMPLES"),
            "--warmups",
            self._required_contract("RUN_BENCH_WARMUPS"),
            "--inner-repeat",
            self._required_contract("RUN_BENCH_INNER_REPEAT"),
            "--output",
            str(output_json),
        ]
        _run_checked(command, cwd=self.workspace, env=runtime_env)
        _copy_result_dir(
            _latest_result_dir(self.workspace / "micro" / "results", _sanitize_artifact_token(f"{self.target_name}_micro")),
            self.artifact_dir,
        )

    def _run_corpus_suite(self, env: dict[str, str]) -> None:
        self._ensure_bundled_repos()
        self._ensure_scx_artifacts()
        runtime_env = env.copy()
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        self._ensure_katran_bundle(runtime_env)
        output_json = self.workspace / "corpus" / "results" / f"{self.target_name}_corpus.json"
        output_md = self.workspace / "corpus" / "results" / f"{self.target_name}_corpus.md"
        command = [
            self.python_bin,
            str(self.workspace / "corpus" / "driver.py"),
            "--daemon",
            str(self.workspace / "daemon" / "target" / "release" / "bpfrejit-daemon"),
            "--samples",
            self._required_contract("RUN_BENCH_SAMPLES"),
            "--output-json",
            str(output_json),
            "--output-md",
            str(output_md),
        ]
        workload_seconds = self._optional_contract("RUN_CORPUS_WORKLOAD_SECONDS")
        if workload_seconds:
            command += ["--workload-seconds", workload_seconds]
        for filter_name in self._csv_contract("RUN_CORPUS_FILTERS"):
            command += ["--filter", filter_name]
        command.extend(self.corpus_argv)
        _run_checked(command, cwd=self.workspace, env=runtime_env)
        _copy_result_dir(
            _latest_result_dir(self.workspace / "corpus" / "results", _sanitize_artifact_token(f"{self.target_name}_corpus")),
            self.artifact_dir,
        )

    def _run_e2e_case(self, case_name: str, env: dict[str, str]) -> None:
        runtime_env = env.copy()
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        command = [
            self.python_bin,
            str(self.workspace / "e2e" / "driver.py"),
            case_name,
            "--daemon",
            str(self.workspace / "daemon" / "target" / "release" / "bpfrejit-daemon"),
        ]
        if self._bool_contract("RUN_E2E_SMOKE"):
            command.append("--smoke")
        command.extend(self.e2e_argv)
        _run_checked(command, cwd=self.workspace, env=runtime_env)

    def _run_e2e_suite(self, env: dict[str, str]) -> None:
        self._ensure_bundled_repos()
        self._ensure_scx_artifacts()
        cases = self._required_contract("RUN_E2E_CASES")
        if cases == "all":
            all_env = env.copy()
            self._ensure_katran_bundle(all_env)
            self._run_e2e_case("all", all_env)
            for case_name in ("tracee", "tetragon", "bpftrace", "scx", "bcc", "katran"):
                _copy_result_dir(_latest_result_dir(self.workspace / "e2e" / "results", case_name), self.artifact_dir)
            return
        for case_name in [token for token in cases.split(",") if token]:
            case_env = env.copy()
            if case_name == "katran":
                self._ensure_katran_bundle(case_env)
            self._run_e2e_case(case_name, case_env)
            _copy_result_dir(_latest_result_dir(self.workspace / "e2e" / "results", case_name), self.artifact_dir)

    def run(self) -> None:
        env = self._runtime_env()
        self.artifact_dir.mkdir(parents=True, exist_ok=True)
        os.chdir(self.workspace)
        shutil.copy2(self.manifest_path, self.artifact_dir / "run-contract.env")
        self._ensure_bpf_stats_enabled()
        self._ensure_workload_tools(env)
        if self.suite_name == "test":
            self._run_test_suite(env)
        elif self.suite_name == "micro":
            self._run_micro_suite(env)
        elif self.suite_name == "corpus":
            self._run_corpus_suite(env)
        elif self.suite_name == "e2e":
            self._run_e2e_suite(env)
        else:
            _die(f"unsupported suite: {self.suite_name}")
        if self.archive_path is not None:
            self.archive_path.parent.mkdir(parents=True, exist_ok=True)
            with tarfile.open(self.archive_path, "w:gz") as tar:
                tar.add(self.artifact_dir, arcname=str(self.artifact_dir.relative_to(self.workspace)))
        print(f"ARTIFACT_DIR={self.artifact_dir.relative_to(self.workspace)}")


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {2, 3}:
        _die("usage: suite_entrypoint.py <workspace> <manifest_path> [archive_path]")
    workspace = Path(args[0]).resolve()
    manifest_path = Path(args[1]).resolve()
    archive_path = Path(args[2]).resolve() if len(args) == 3 and args[2] else None
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")
    if not workspace.is_dir():
        _die(f"workspace is missing: {workspace}")
    contract = parse_manifest(manifest_path)
    SuiteEntrypoint.from_contract(workspace, manifest_path, archive_path, cast(dict[str, str | list[str]], contract)).run()


if __name__ == "__main__":
    main()
