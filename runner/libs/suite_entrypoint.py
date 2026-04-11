from __future__ import annotations

import os
import json
import shlex
import shutil
import subprocess
import sys
from dataclasses import dataclass
from functools import partial
from pathlib import Path
from typing import Sequence

from runner.libs.cli_support import fail
from runner.libs.guest_prereqs import runtime_path_value
from runner.libs.kinsn import load_kinsn_modules
from runner.libs.prereq_contract import active_python_bin, inside_runtime_container, runtime_container_enabled
from runner.libs.run_contract import RunConfig, read_run_config_file
from runner.libs.workspace_layout import (
    daemon_binary_path,
    kernel_modules_root,
    kinsn_module_dir,
    micro_program_root,
    native_repo_targets,
    repo_artifact_root,
    runner_binary_path,
    scx_targets,
    test_negative_build_dir,
    test_unittest_build_dir,
    workload_tools_root,
)

_die = partial(fail, "suite-entrypoint")


def _append_bind_mount(command: list[str], source: Path, target: Path | None = None, *, readonly: bool = False) -> None:
    if not source.exists():
        return
    destination = target or source
    suffix = ":ro" if readonly else ""
    command.extend(["-v", f"{source}:{destination}{suffix}"])


def _run_in_runtime_container(workspace: Path, config: RunConfig) -> None:
    runtime = config.remote.container_runtime or "docker"
    image = config.remote.runtime_container_image
    python_bin = config.remote.runtime_python_bin or "python3"
    if not image:
        _die("run config RUN_RUNTIME_CONTAINER_IMAGE is empty")
    command = [runtime, "run", "--rm", "--privileged", "--pid=host", "--network=host", "--ipc=host",
               "-e", "BPFREJIT_INSIDE_RUNTIME_CONTAINER=1", "-e", f"PYTHONPATH={workspace}",
               "-e", "HOME=/root", "-v", f"{workspace}:{workspace}", "-w", str(workspace)]
    _append_bind_mount(command, Path("/sys"))
    _append_bind_mount(command, Path("/sys/fs/bpf"))
    _append_bind_mount(command, Path("/sys/kernel/debug"))
    _append_bind_mount(command, Path("/lib/modules"), readonly=True)
    _append_bind_mount(command, Path("/boot"), readonly=True)
    command.extend([image, python_bin, "-m", "runner.libs.suite_entrypoint",
                    str(workspace), "--config-json", config.to_json_text()])
    completed = subprocess.run(command, cwd=workspace, text=True, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def _argv_option_value(argv: Sequence[str], option: str) -> str:
    for index, token in enumerate(argv):
        if token == option:
            if index + 1 >= len(argv):
                _die(f"missing value for {option}")
            return str(argv[index + 1]).strip()
        if token.startswith(option + "="):
            return token.split("=", 1)[1].strip()
    return ""


def _cross_runtime_ld_library_path(workspace: Path, target_arch: str) -> str:
    if target_arch != "arm64":
        return ""
    entries: list[str] = []
    for path in (workspace / "tests" / "unittest" / "build-arm64" / "lib",):
        if path.is_dir():
            entries.append(str(path))
    return ":".join(entries)


def _suite_runtime_ld_library_path(workspace: Path, target_arch: str) -> str:
    repo_root = repo_artifact_root(workspace, target_arch)
    workload_root = workload_tools_root(workspace, target_arch)
    candidates = [repo_root / "katran" / "lib64", repo_root / "katran" / "lib",
                  repo_root / "tracee" / "lib", repo_root / "bcc" / "libbpf-tools" / "lib",
                  workload_root / "lib", workload_root / "lib" / "luajit"]
    entries = [str(p) for p in candidates if p.is_dir()]
    for extra in (_cross_runtime_ld_library_path(workspace, target_arch), os.environ.get("LD_LIBRARY_PATH", "").strip()):
        if extra: entries.extend(e for e in extra.split(":") if e)
    ordered: list[str] = []
    for entry in entries:
        if entry and entry not in ordered: ordered.append(entry)
    return ":".join(ordered)


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
    config: RunConfig
    workspace: Path
    config_path: Path | None
    target_name: str
    suite_name: str
    target_arch: str
    executor: str
    python_bin: str
    bpftool_bin: str
    artifact_dir: Path | None
    corpus_argv: list[str]
    e2e_argv: list[str]

    def _required_contract(self, name: str) -> str:
        try:
            return self.config.required(name)
        except RuntimeError as exc:
            _die(str(exc))

    def _bool_contract(self, name: str, *, default: str = "0") -> bool:
        return self.config.scalar(name, default) == "1"

    def _artifact_dir_required(self) -> Path:
        if self.artifact_dir is None:
            _die(f"suite {self.suite_name} does not define a local artifact directory")
        return self.artifact_dir

    @classmethod
    def from_config(
        cls,
        workspace: Path,
        config: RunConfig,
        config_path: Path | None = None,
    ) -> "SuiteEntrypoint":
        target_name = config.identity.target_name
        suite_name = config.identity.suite_name
        target_arch = config.identity.target_arch
        executor = config.identity.executor
        run_token = config.identity.token
        python_bin = active_python_bin(config)
        if not python_bin:
            _die("run config RUN_REMOTE_PYTHON_BIN is empty")
        bpftool_bin = config.remote.bpftool_bin
        if not bpftool_bin:
            _die("run config RUN_BPFTOOL_BIN is empty")
        artifact_dir = None
        if suite_name == "test":
            artifact_dir = workspace / "tests" / "results" / run_token
        return cls(
            config=config,
            workspace=workspace,
            config_path=config_path,
            target_name=target_name,
            suite_name=suite_name,
            target_arch=target_arch,
            executor=executor,
            python_bin=python_bin,
            bpftool_bin=bpftool_bin,
            artifact_dir=artifact_dir,
            corpus_argv=config.argv("RUN_CORPUS_ARGV"),
            e2e_argv=config.argv("RUN_E2E_ARGV"),
        )

    def _runtime_env(self) -> dict[str, str]:
        env: dict[str, str] = {name: v for name in ("HOME", "USER", "LOGNAME", "TERM", "TMPDIR", "LANG", "LC_ALL", "LC_CTYPE", "SHELL")
                               if (v := os.environ.get(name, "").strip())}
        if not env.get("TMPDIR"):
            runtime_tmpdir = Path("/var/tmp/bpfrejit-runtime") / self._required_contract("RUN_TOKEN")
            runtime_tmpdir.mkdir(parents=True, exist_ok=True)
            runtime_tmpdir.chmod(0o1777)
            env["TMPDIR"] = str(runtime_tmpdir)
        else:
            Path(env["TMPDIR"]).mkdir(parents=True, exist_ok=True)
            Path(env["TMPDIR"]).chmod(0o1777)
        env.setdefault("TMP", env["TMPDIR"])
        env.setdefault("TEMP", env["TMPDIR"])
        env["BPFREJIT_RUNTIME_TMPDIR"] = env["TMPDIR"]
        env["PATH"] = runtime_path_value(self.workspace, self.config)
        if runtime_ld := _suite_runtime_ld_library_path(self.workspace, self.target_arch):
            env["LD_LIBRARY_PATH"] = runtime_ld
        workload_tool_bin = self.workspace / ".cache" / "workload-tools" / self.target_arch / "bin"
        if workload_tool_bin.is_dir():
            env["BPFREJIT_WORKLOAD_TOOL_BIN_DIR"] = str(workload_tool_bin)
        env["BPFREJIT_REPO_ARTIFACT_ROOT"] = str(repo_artifact_root(self.workspace, self.target_arch))
        env["BPFREJIT_REMOTE_PYTHON_BIN"] = self.python_bin
        kernel_modules_dir = kernel_modules_root(self.workspace, self.target_arch, self.executor)
        if not kernel_modules_dir.is_dir():
            _die(f"kernel module artifact root is missing: {kernel_modules_dir}")
        env["BPFREJIT_KERNEL_MODULES_ROOT"] = str(kernel_modules_dir)
        rejit_passes = (_argv_option_value(self.corpus_argv, "--rejit-passes") if self.suite_name == "corpus"
                        else _argv_option_value(self.e2e_argv, "--rejit-passes") if self.suite_name == "e2e" else "")
        if rejit_passes:
            env["BPFREJIT_BENCH_PASSES"] = rejit_passes
        env["PYTHONPATH"] = str(self.workspace)
        env["BPFTOOL_BIN"] = self.bpftool_bin
        if shutil.which(self.bpftool_bin, path=env["PATH"]) is None:
            _die(f"required command is missing: {self.bpftool_bin}")
        if shutil.which(self.python_bin, path=env["PATH"]) is None:
            _die(f"required command is missing: {self.python_bin}")
        return env

    def _env_with_cross_runtime_ld(self, env: dict[str, str]) -> tuple[dict[str, str], str]:
        runtime_env = env.copy()
        runtime_ld = _cross_runtime_ld_library_path(self.workspace, self.target_arch)
        if runtime_ld:
            runtime_env["LD_LIBRARY_PATH"] = runtime_ld
        return runtime_env, runtime_ld

    def _expected_kinsn_modules(self) -> list[str]:
        module_dir = kinsn_module_dir(self.workspace, self.target_arch)
        modules = sorted(
            path.stem
            for path in module_dir.glob("bpf_*.ko")
            if path.is_file() and path.stem != "bpf_barrier"
        )
        if not modules:
            _die(f"no kinsn modules found under {module_dir}")
        return modules

    def _resolve_daemon_binary(self) -> Path:
        candidate = daemon_binary_path(self.workspace, self.target_arch)
        if candidate.is_file() and os.access(candidate, os.X_OK):
            return candidate
        _die(f"daemon artifact is missing or not executable: {candidate}")

    def _ensure_runner_binary(self) -> None:
        if not self._bool_contract("RUN_NEEDS_RUNNER_BINARY"):
            return
        _require_executable(
            runner_binary_path(self.workspace, self.target_arch),
            "runner artifact",
        )

    def _ensure_scx_artifacts(self) -> None:
        packages = self.config.csv("RUN_SCX_PACKAGES_CSV")
        if not packages:
            return
        for target in scx_targets(self.workspace, self.target_arch, packages):
            if target.name.endswith(".bpf.o"):
                if not target.is_file():
                    _die(f"scx artifact object is missing: {target}")
                continue
            _require_executable(target, "scx artifact")

    def _ensure_katran_artifacts(self) -> None:
        if "katran" not in self.config.csv("RUN_NATIVE_REPOS_CSV"):
            return
        katran_targets = native_repo_targets(self.workspace, self.target_arch, ["katran"])
        for target in katran_targets:
            if target.name == "katran_server_grpc":
                _require_executable(target, "Katran server artifact")
                continue
            if not target.is_file():
                _die(f"Katran artifact is missing: {target}")
        katran_root = repo_artifact_root(self.workspace, self.target_arch) / "katran"
        katran_lib_root = katran_root / "lib"
        if not katran_lib_root.is_dir():
            _die(f"Katran runtime library artifact directory is missing: {katran_lib_root}")

    def _ensure_bpf_stats_enabled(self) -> None:
        if not self._bool_contract("RUN_NEEDS_DAEMON_BINARY"): return
        bpf_stats_path = Path("/proc/sys/kernel/bpf_stats_enabled")
        sysctl_bin = shutil.which("sysctl")
        command_prefix: list[str] = []
        if os.geteuid() != 0:
            sudo_bin = shutil.which("sudo")
            if sudo_bin is None: _die("kernel bpf_stats_enabled requires root or sudo")
            command_prefix = [sudo_bin]
        if sysctl_bin:
            _run_checked([*command_prefix, sysctl_bin, "-q", "-w", "kernel.bpf_stats_enabled=1"],
                         cwd=self.workspace, env={"PATH": os.environ.get("PATH", "") or "/usr/sbin:/usr/bin:/sbin:/bin"})
        else:
            _run_checked([*command_prefix, "sh", "-c", "printf '1\\n' > /proc/sys/kernel/bpf_stats_enabled"],
                         cwd=self.workspace, env=os.environ.copy())
        if bpf_stats_path.read_text(encoding="utf-8").strip() != "1": _die("failed to enable kernel.bpf_stats_enabled=1")

    def _validate_test_contract(self) -> None:
        for name in ("RUN_TEST_FUZZ_ROUNDS", "RUN_TEST_SCX_PROG_SHOW_RACE_MODE",
                     "RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS", "RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT",
                     "RUN_TEST_SCX_PROG_SHOW_RACE_SKIP_PROBE"):
            self._required_contract(name)

    def _log_test_section(self, title: str) -> None:
        print(f"\n========================================\n  {title}\n========================================", file=sys.stderr)

    def _load_kinsn_modules(self) -> None:
        load_kinsn_modules(
            self._expected_kinsn_modules(),
            module_dir=kinsn_module_dir(self.workspace, self.target_arch),
        )

    def _discover_unittest_binaries(self) -> list[Path]:
        build_dir = test_unittest_build_dir(self.workspace, self.target_arch)
        return sorted(
            path
            for path in build_dir.glob("rejit_*")
            if path.is_file() and os.access(path, os.X_OK)
        )

    def _run_unittest_suite(self, env: dict[str, str], *, log_path: Path | None = None) -> tuple[int, int]:
        self._log_test_section("Running tests/unittest/ suite (pre-built)")
        build_dir = test_unittest_build_dir(self.workspace, self.target_arch)
        tests = self._discover_unittest_binaries()
        if not tests:
            print(f"ERROR: no rejit_* test binaries found in {build_dir}", file=sys.stderr)
            return 0, 1
        runtime_env, _ = self._env_with_cross_runtime_ld(env)
        runtime_env["BPFREJIT_PROGS_DIR"] = str(build_dir / "progs")
        runtime_env["BPFREJIT_DAEMON_PATH"] = str(self._resolve_daemon_binary())
        passed = failed = 0
        for test_binary in tests:
            print(f"--- {test_binary.name} ---", file=sys.stderr)
            if _run_with_status([str(test_binary), str(build_dir / "progs")], cwd=self.workspace, env=runtime_env, log_path=log_path):
                passed += 1
            else:
                failed += 1; print(f"FAIL: {test_binary.name}", file=sys.stderr)
        return passed, failed

    def _run_negative_suite(
        self,
        env: dict[str, str],
        *,
        include_scx_race: bool,
        log_path: Path | None = None,
    ) -> tuple[int, int]:
        self._log_test_section("Running tests/negative/ adversarial suite")
        negative_build = test_negative_build_dir(self.workspace, self.target_arch)
        runtime_env, runtime_ld = self._env_with_cross_runtime_ld(env)
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
            scx_env = {**runtime_env, "SCX_RUNTIME_LD_LIBRARY_PATH": runtime_ld}
            scx_command = [str(negative_build / "scx_prog_show_race"), str(self.workspace),
                           "--mode", self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_MODE"),
                           "--iterations", self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_ITERATIONS"),
                           "--load-timeout", self._required_contract("RUN_TEST_SCX_PROG_SHOW_RACE_LOAD_TIMEOUT")]
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

    def _run_kernel_selftest(self) -> tuple[int, int]:
        kernel_selftest = self.workspace / "tests" / "kernel" / "build" / "test_recompile"
        if not kernel_selftest.is_file():
            print(f"SKIP: test_recompile not found at {kernel_selftest}", file=sys.stderr); return 0, 0
        self._log_test_section("Kernel selftest (test_recompile)")
        if _run_with_status([str(kernel_selftest)], cwd=self.workspace, env=self._runtime_env()): return 1, 0
        print("FAIL: test_recompile", file=sys.stderr); return 0, 1

    def _print_test_summary(self, passed: int, failed: int, *, prefix: str = "RESULTS") -> None:
        print(f"\n========================================\n  {prefix}: {passed} passed, {failed} failed\n========================================", file=sys.stderr)

    def _run_selftest_mode(self, env: dict[str, str]) -> None:
        log_path = self._artifact_dir_required() / "selftest.log"
        self._log_test_section("Loading kinsn modules"); self._load_kinsn_modules()
        pa, fa = self._run_unittest_suite(env, log_path=log_path)
        pb, fb = self._run_negative_suite(env, include_scx_race=False, log_path=log_path)
        self._print_test_summary(pa + pb, fa + fb, prefix="vm-selftest")
        if fa + fb: _die("vm-selftest failed")

    def _run_negative_mode(self, env: dict[str, str]) -> None:
        log_path = self._artifact_dir_required() / "negative.log"
        passed, failed = self._run_negative_suite(env, include_scx_race=True, log_path=log_path)
        self._print_test_summary(passed, failed, prefix="vm-negative-test")
        if failed: _die("vm-negative-test failed")

    def _run_full_test_mode(self, env: dict[str, str]) -> None:
        total_pass = total_fail = 0
        p, f = self._run_kernel_selftest(); total_pass += p; total_fail += f
        self._log_test_section("Loading kinsn modules"); self._load_kinsn_modules()
        p, f = self._run_unittest_suite(env); total_pass += p; total_fail += f
        p, f = self._run_negative_suite(env, include_scx_race=True); total_pass += p; total_fail += f
        self._print_test_summary(total_pass, total_fail)
        if total_fail: _die("vm-test failed")
        print("vm-test: ALL PASSED", file=sys.stderr)

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
        runtime_env, _ = self._env_with_cross_runtime_ld(env)
        runtime_env["BPFREJIT_MICRO_PROGRAM_DIR"] = str(micro_program_root(self.workspace, self.target_arch))
        runtime_env["BPFREJIT_MICRO_RUNNER_BINARY"] = str(runner_binary_path(self.workspace, self.target_arch))
        output_json = self.workspace / "micro" / "results" / f"{self.target_name}_micro.json"
        command = [self.python_bin, str(self.workspace / "micro" / "driver.py"),
                   "--runtime", "llvmbpf", "--runtime", "kernel",
                   "--samples", self._required_contract("RUN_BENCH_SAMPLES"),
                   "--warmups", self._required_contract("RUN_BENCH_WARMUPS"),
                   "--inner-repeat", self._required_contract("RUN_BENCH_INNER_REPEAT"),
                   "--output", str(output_json)]
        _run_checked(command, cwd=self.workspace, env=runtime_env)

    def _run_corpus_suite(self, env: dict[str, str]) -> None:
        self._ensure_scx_artifacts()
        runtime_env, _ = self._env_with_cross_runtime_ld(env)
        self._ensure_katran_artifacts()
        output_json = self.workspace / "corpus" / "results" / f"{self.target_name}_corpus.json"
        output_md = self.workspace / "corpus" / "results" / f"{self.target_name}_corpus.md"
        command = [self.python_bin, str(self.workspace / "corpus" / "driver.py"),
                   "--daemon", str(self._resolve_daemon_binary()),
                   "--samples", self._required_contract("RUN_BENCH_SAMPLES"),
                   "--output-json", str(output_json), "--output-md", str(output_md)]
        if workload_seconds := self.config.scalar("RUN_CORPUS_WORKLOAD_SECONDS"):
            command += ["--workload-seconds", workload_seconds]
        for filter_name in self.config.csv("RUN_CORPUS_FILTERS"):
            command += ["--filter", filter_name]
        command.extend(self.corpus_argv)
        _run_checked(command, cwd=self.workspace, env=runtime_env)

    def _run_e2e_case(self, case_name: str, env: dict[str, str]) -> None:
        runtime_env, _ = self._env_with_cross_runtime_ld(env)
        command = [self.python_bin, str(self.workspace / "e2e" / "driver.py"),
                   case_name, "--daemon", str(self._resolve_daemon_binary())]
        if self._bool_contract("RUN_E2E_SMOKE"):
            command.append("--smoke")
        command.extend(self.e2e_argv)
        _run_checked(command, cwd=self.workspace, env=runtime_env)

    def _run_e2e_suite(self, env: dict[str, str]) -> None:
        self._ensure_scx_artifacts()
        cases = self._required_contract("RUN_E2E_CASES")
        if cases == "all":
            all_env = env.copy()
            self._ensure_katran_artifacts()
            self._run_e2e_case("all", all_env)
            return
        for case_name in [token for token in cases.split(",") if token]:
            case_env = env.copy()
            if case_name == "katran":
                self._ensure_katran_artifacts()
            self._run_e2e_case(case_name, case_env)

    def run(self) -> None:
        if runtime_container_enabled(self.config) and not inside_runtime_container():
            _run_in_runtime_container(self.workspace, self.config)
            return
        env = self._runtime_env()
        os.chdir(self.workspace)
        if inside_runtime_container() and shutil.which("ip", path=env["PATH"]) is not None:
            _run_checked(["ip", "link", "set", "lo", "up"], cwd=self.workspace, env=env)
        if self.suite_name == "test":
            artifact_dir = self._artifact_dir_required()
            artifact_dir.mkdir(parents=True, exist_ok=True)
            if self.config_path is not None:
                shutil.copy2(self.config_path, artifact_dir / "run-contract.json")
            else:
                (artifact_dir / "run-contract.json").write_text(
                    json.dumps(self.config.to_mapping(), indent=2, sort_keys=True) + "\n",
                    encoding="utf-8",
                )
        self._ensure_bpf_stats_enabled()
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


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {2, 3}:
        _die("usage: suite_entrypoint.py <workspace> <config_path>|--config-json <json>")
    workspace = Path(args[0]).resolve()
    if not workspace.is_dir():
        _die(f"workspace is missing: {workspace}")
    if len(args) == 3:
        if args[1] != "--config-json":
            _die("usage: suite_entrypoint.py <workspace> <config_path>|--config-json <json>")
        config = RunConfig.from_json_text(args[2])
        SuiteEntrypoint.from_config(workspace, config).run()
        return
    config_path = Path(args[1]).resolve()
    if not config_path.is_file():
        _die(f"run config is missing: {config_path}")
    SuiteEntrypoint.from_config(workspace, read_run_config_file(config_path), config_path).run()


if __name__ == "__main__":
    main()
