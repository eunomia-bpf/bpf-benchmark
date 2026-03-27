#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Iterable

from elftools.elf.elffile import ELFFile


SCRIPT_DIR = Path(__file__).resolve().parent
RUNNER_DIR = SCRIPT_DIR.parent
REPO_ROOT = RUNNER_DIR.parent
RUNNER_REPOS_DIR = RUNNER_DIR / "repos"
CORPUS_BUILD_ROOT = REPO_ROOT / "corpus" / "build"
IMPLEMENTED_REPOS = (
    "bcc",
    "libbpf-bootstrap",
    "xdp-tools",
    "xdp-tutorial",
    "scx",
    "katran",
    "tracee",
    "tetragon",
    "cilium",
    "bpftrace",
)
BPF_ELF_MACHINE = 247
CILIUM_BPF_TARGETS = (
    "bpf_lxc.o",
    "bpf_overlay.o",
    "bpf_sock.o",
    "bpf_host.o",
    "bpf_wireguard.o",
    "bpf_xdp.o",
    "bpf_alignchecker.o",
)


class CommandError(RuntimeError):
    pass


@dataclass(frozen=True)
class RepoBuildResult:
    name: str
    stage_dir: Path
    object_count: int
    binary_count: int
    verify_command: tuple[str, ...]
    verify_ok: bool
    status: str
    message: str = ""


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Build corpus repos with their native build systems.")
    parser.add_argument("--repo", action="append", dest="repos", help="Build only the selected repo.")
    parser.add_argument("--jobs", type=int, default=max(1, os.cpu_count() or 1), help="Parallel build jobs.")
    parser.add_argument(
        "--build-root",
        default=str(CORPUS_BUILD_ROOT),
        help="Unified corpus build output directory.",
    )
    return parser.parse_args()


def repo_checkout(name: str) -> Path:
    path = RUNNER_REPOS_DIR / name
    if not path.exists():
        raise CommandError(f"repo checkout missing for `{name}`: {path} (run `make corpus-fetch` first)")
    return path


def printable_command(command: list[str]) -> str:
    return " ".join(command)


def run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    where = f" (cwd={cwd})" if cwd else ""
    print(f"[run] {printable_command(command)}{where}")
    completed = subprocess.run(command, cwd=cwd, env=env, text=True, check=False)
    if completed.returncode != 0:
        raise CommandError(f"command failed with exit code {completed.returncode}: {printable_command(command)}")


def capture(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> subprocess.CompletedProcess[str]:
    where = f" (cwd={cwd})" if cwd else ""
    print(f"[run] {printable_command(command)}{where}")
    return subprocess.run(command, cwd=cwd, env=env, text=True, capture_output=True, check=False)


def try_run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> bool:
    where = f" (cwd={cwd})" if cwd else ""
    print(f"[run] {printable_command(command)}{where}")
    completed = subprocess.run(command, cwd=cwd, env=env, text=True, check=False)
    return completed.returncode == 0


def summarize_process_output(completed: subprocess.CompletedProcess[str]) -> str:
    lines = [
        line.strip()
        for text in (completed.stdout, completed.stderr)
        for line in text.splitlines()
        if line.strip()
    ]
    for line in lines:
        lowered = line.lower()
        if "please install" in lowered:
            return line
        if "fatal error:" in lowered or " error:" in lowered:
            return line
        if "inconsistent vendoring" in lowered:
            return line
        if "missing:" in lowered:
            return line
    interesting = [
        line for line in lines if any(token in line.lower() for token in ("error", "fatal", "failed", "missing"))
    ]
    if interesting:
        return interesting[0]
    if lines:
        return lines[-1]
    return f"command failed with exit code {completed.returncode}"


def stage_file(src: Path, dst: Path) -> None:
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)


def stage_many(files: Iterable[Path], dest_fn: Callable[[Path], Path]) -> int:
    staged = 0
    seen: dict[Path, Path] = {}
    for src in sorted({path.resolve() for path in files if path.is_file()}):
        dst = dest_fn(src).resolve()
        other = seen.get(dst)
        if other is not None and other != src:
            raise CommandError(f"staging collision for {dst}: {other} vs {src}")
        seen[dst] = src
        stage_file(src, dst)
        staged += 1
    return staged


def is_executable_file(path: Path) -> bool:
    return path.is_file() and os.access(path, os.X_OK)


def is_bpf_object(path: Path) -> bool:
    try:
        with path.open("rb") as handle:
            machine = ELFFile(handle).header["e_machine"]
    except Exception:
        return False
    if isinstance(machine, int):
        return machine == BPF_ELF_MACHINE
    return str(machine) in {"EM_BPF", "Linux BPF", str(BPF_ELF_MACHINE)}


def verify_binary(command: list[str]) -> bool:
    if not command:
        return True
    try:
        completed = subprocess.run(command, capture_output=True, text=True, timeout=30, check=False)
    except OSError:
        return False
    output = f"{completed.stdout}\n{completed.stderr}".lower()
    if completed.returncode == 0:
        return True
    return "usage" in output or "--help" in output


def clean_stage_dir(path: Path) -> None:
    shutil.rmtree(path, ignore_errors=True)
    path.mkdir(parents=True, exist_ok=True)


def remove_staged_temp_objects(path: Path) -> None:
    for pattern in ("*.tmp.o", "*.tmp.bpf.o", "*.bpf.tmp.o"):
        for candidate in path.rglob(pattern):
            if candidate.is_file():
                candidate.unlink()


def clang_bpf_sys_includes(clang: str = "clang") -> list[str]:
    completed = subprocess.run(
        [clang, "-v", "-E", "-"],
        input="",
        capture_output=True,
        text=True,
        check=False,
    )
    if completed.returncode != 0:
        return []

    collecting = False
    includes: list[str] = []
    for raw_line in completed.stderr.splitlines():
        line = raw_line.rstrip()
        if "#include <...> search starts here:" in line:
            collecting = True
            continue
        if not collecting:
            continue
        if "End of search list." in line:
            break
        candidate = line.strip()
        if candidate.startswith("/"):
            includes.extend(["-idirafter", candidate])
    return includes


def locate_cached_vmlinux_header() -> Path | None:
    prioritized = [
        REPO_ROOT / "corpus" / "build" / "real_world_code_size" / "libbpf-bootstrap" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "bcc" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "katran" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "cilium" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "linux-selftests" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "manual-test" / "vmlinux.h",
    ]
    for candidate in prioritized:
        if candidate.is_file():
            return candidate
    build_root = REPO_ROOT / "corpus" / "build"
    if build_root.is_dir():
        for candidate in sorted(build_root.rglob("vmlinux.h")):
            if candidate.is_file():
                return candidate
    return None


def find_cached_vmlinux_header() -> Path:
    candidate = locate_cached_vmlinux_header()
    if candidate is not None:
        return candidate
    raise CommandError(
        "missing cached vmlinux.h for native corpus builds; "
        "run the generic corpus object builder first or provide a staged vmlinux.h under corpus/build/"
    )


def bpf_stage_relative(path: Path) -> Path:
    if path.name.endswith(".bpf.o"):
        return path
    if path.suffix == ".o":
        return path.with_suffix(".bpf.o")
    return path.with_name(path.name + ".bpf.o")


def summarize_items(items: list[str], *, limit: int = 3) -> str:
    if not items:
        return ""
    if len(items) <= limit:
        return "; ".join(items)
    return "; ".join(items[:limit]) + f"; +{len(items) - limit} more"


def bpf_object_path_from_source(path: Path) -> Path:
    if path.name.endswith(".bpf.c"):
        return path.with_name(path.name.removesuffix(".c") + ".o")
    if path.suffix == ".c":
        return path.with_suffix(".o")
    return bpf_stage_relative(path)


def build_failure_result(name: str, stage_dir: Path, message: str) -> RepoBuildResult:
    stage_dir.mkdir(parents=True, exist_ok=True)
    return RepoBuildResult(
        name=name,
        stage_dir=stage_dir,
        object_count=0,
        binary_count=0,
        verify_command=(),
        verify_ok=False,
        status="failed",
        message=message,
    )


def bcc_binaries(tool_dir: Path) -> list[Path]:
    binaries: list[Path] = []
    for obj in sorted((tool_dir / ".output").glob("*.bpf.o")):
        name = obj.name.removesuffix(".bpf.o")
        candidate = tool_dir / name
        if is_executable_file(candidate):
            binaries.append(candidate)
    return binaries


def build_bcc(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("bcc")
    tool_dir = repo_dir / "libbpf-tools"
    bpftool = RUNNER_DIR / "build" / "vendor" / "bpftool" / "bootstrap" / "bpftool"
    clang_value = " ".join(["clang", *clang_bpf_sys_includes()])
    if not bpftool.is_file():
        run(["make", "-C", str(RUNNER_DIR), "vendor_bpftool"])
    clean_stage_dir(stage_root)
    run(
        [
            "make",
            f"-j{jobs}",
            f"LIBBPF_SRC={REPO_ROOT / 'vendor' / 'libbpf' / 'src'}",
            f"BPFTOOL={bpftool}",
            f"CLANG={clang_value}",
            "USE_BLAZESYM=0",
        ],
        cwd=tool_dir,
    )

    object_paths = sorted((tool_dir / ".output").glob("*.bpf.o"))
    binary_paths = bcc_binaries(tool_dir)
    object_count = stage_many(object_paths, lambda src: stage_root / "libbpf-tools" / src.name)
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "bindsnoop"), "-h")
    return RepoBuildResult(
        name="bcc",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def libbpf_bootstrap_wrapper() -> str:
    return """include $(CURDIR)/Makefile

BPF_APP_STEMS := $(patsubst %.bpf.c,%,$(notdir $(wildcard *.bpf.c)))

define LIBBPF_BOOTSTRAP_EXPLICIT_BPF_RULE
$(OUTPUT)/$(1).bpf.o: $(1).bpf.c $(LIBBPF_OBJ) $(wildcard $(1).h) $(VMLINUX) | $(OUTPUT) $(BPFTOOL)
\t$(call msg,BPF,$$@)
\t$(Q)$(CLANG) -g -O2 -target bpf -D__TARGET_ARCH_$(ARCH) \\
\t\t     $(INCLUDES) $(CLANG_BPF_SYS_INCLUDES) \\
\t\t     -c $$(filter %.c,$$^) -o $$(patsubst %.bpf.o,%.tmp.bpf.o,$$@)
\t$(Q)$(BPFTOOL) gen object $$@ $$(patsubst %.bpf.o,%.tmp.bpf.o,$$@)
endef

$(foreach app,$(BPF_APP_STEMS),$(eval $(call LIBBPF_BOOTSTRAP_EXPLICIT_BPF_RULE,$(app))))
"""


def build_libbpf_bootstrap(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("libbpf-bootstrap")
    example_dir = repo_dir / "examples" / "c"
    bpftool = RUNNER_DIR / "build" / "vendor" / "bpftool" / "bootstrap" / "bpftool"
    vmlinux = find_cached_vmlinux_header()
    if not bpftool.is_file():
        run(["make", "-C", str(RUNNER_DIR), "vendor_bpftool"])

    clean_stage_dir(stage_root)
    with tempfile.TemporaryDirectory(prefix="libbpf-bootstrap-wrapper-") as temp_dir:
        wrapper = Path(temp_dir) / "Makefile.wrapper"
        wrapper.write_text(libbpf_bootstrap_wrapper())
        common_args = [
            "make",
            "-f",
            str(wrapper),
            f"-j{jobs}",
            f"LIBBPF_SRC={REPO_ROOT / 'vendor' / 'libbpf' / 'src'}",
            f"BPFTOOL={bpftool}",
            f"VMLINUX={vmlinux}",
            "CARGO=",
        ]
        run([*common_args, "clean"], cwd=example_dir)
        run([*common_args, "all"], cwd=example_dir)

    object_paths = sorted(
        path for path in (example_dir / ".output").glob("*.bpf.o") if not path.name.endswith(".tmp.bpf.o")
    )
    binary_paths = []
    for obj in object_paths:
        candidate = example_dir / obj.name.removesuffix(".bpf.o")
        if is_executable_file(candidate):
            binary_paths.append(candidate)

    object_count = stage_many(object_paths, lambda src: stage_root / "examples" / "c" / src.name)
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "bootstrap"), "-h")
    return RepoBuildResult(
        name="libbpf-bootstrap",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def build_xdp_tools(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("xdp-tools")
    bpftool = RUNNER_DIR / "build" / "vendor" / "bpftool" / "bootstrap" / "bpftool"
    if not bpftool.is_file():
        run(["make", "-C", str(RUNNER_DIR), "vendor_bpftool"])
    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}", f"BPFTOOL={bpftool}"], cwd=repo_dir)

    object_paths = sorted(repo_dir.rglob("*.bpf.o"))
    binary_candidates = [
        repo_dir / "xdp-filter" / "xdp-filter",
        repo_dir / "xdp-loader" / "xdp-loader",
        repo_dir / "xdp-dump" / "xdpdump",
        repo_dir / "xdp-bench" / "xdp-bench",
        repo_dir / "xdp-forward" / "xdp-forward",
        repo_dir / "xdp-monitor" / "xdp-monitor",
        repo_dir / "xdp-trafficgen" / "xdp-trafficgen",
    ]
    binary_paths = [path for path in binary_candidates if is_executable_file(path)]

    object_count = stage_many(object_paths, lambda src: stage_root / src.name)
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.relative_to(repo_dir))
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "xdp-loader" / "xdp-loader"), "--help")
    return RepoBuildResult(
        name="xdp-tools",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def tutorial_binary_dirs(repo_dir: Path) -> list[Path]:
    dirs = []
    for makefile in sorted(repo_dir.glob("*/Makefile")):
        if makefile.parent.name in {"common", "lib"}:
            continue
        dirs.append(makefile.parent)
    return dirs


def build_xdp_tutorial(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("xdp-tutorial")
    xdp_tools_dir = repo_checkout("xdp-tools")
    loader_dir = xdp_tools_dir / "xdp-loader"

    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}"], cwd=xdp_tools_dir)
    run(["make", f"-j{jobs}", f"LOADER_DIR={loader_dir}"], cwd=repo_dir)
    for extra_dir in ("advanced03-AF_XDP", "experiment01-tailgrow"):
        ok = try_run(["make", f"-j{jobs}", f"LOADER_DIR={loader_dir}"], cwd=repo_dir / extra_dir)
        if not ok:
            print(f"[warn] xdp-tutorial extra lesson failed and was skipped: {extra_dir}")

    object_paths = [path for path in sorted(repo_dir.rglob("*.o")) if is_bpf_object(path)]
    object_count = stage_many(
        object_paths,
        lambda src: stage_root / src.relative_to(repo_dir).with_suffix(".bpf.o"),
    )

    binary_paths: list[Path] = []
    for build_dir in tutorial_binary_dirs(repo_dir):
        for candidate in sorted(build_dir.iterdir()):
            if candidate.name == "Makefile" or candidate.suffix in {".o", ".c", ".h", ".mk", ".sh", ".py"}:
                continue
            if is_executable_file(candidate):
                binary_paths.append(candidate)
    binary_count = stage_many(
        binary_paths,
        lambda src: stage_root / "bin" / src.parent.relative_to(repo_dir) / src.name,
    )
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "packet01-parsing" / "xdp-loader"), "--help")
    return RepoBuildResult(
        name="xdp-tutorial",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def build_scx(stage_root: Path, jobs: int) -> RepoBuildResult:
    del jobs
    repo_dir = repo_checkout("scx")
    clean_stage_dir(stage_root)
    run([sys.executable, str(RUNNER_DIR / "scripts" / "build_scx_artifacts.py"), "--force"], cwd=REPO_ROOT)

    object_names = (
        "scx_bpfland_main.bpf.o",
        "scx_flash_main.bpf.o",
        "scx_lavd_main.bpf.o",
        "scx_rusty_main.bpf.o",
    )
    missing = [name for name in object_names if not (stage_root / name).is_file()]
    if missing:
        raise CommandError(f"missing staged scx objects after build: {', '.join(missing)}")

    binary_names = ("scx_bpfland", "scx_flash", "scx_lavd", "scx_rusty")
    binary_paths = [repo_dir / "target" / "release" / name for name in binary_names]
    binary_count = stage_many(
        [path for path in binary_paths if is_executable_file(path)],
        lambda src: stage_root / "bin" / src.name,
    )
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "scx_rusty"), "--help")
    return RepoBuildResult(
        name="scx",
        stage_dir=stage_root,
        object_count=len(object_names),
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def build_katran(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("katran")
    lib_dir = repo_dir / "katran" / "lib"
    clean_stage_dir(stage_root)
    with tempfile.TemporaryDirectory(prefix="katran-bpf-build-") as temp_dir:
        work_dir = Path(temp_dir)
        (work_dir / "include").mkdir(parents=True, exist_ok=True)
        (work_dir / "katran" / "lib").mkdir(parents=True, exist_ok=True)
        (work_dir / "bpf").mkdir(parents=True, exist_ok=True)
        stage_file(lib_dir / "Makefile-bpf", work_dir / "Makefile")
        shutil.copytree(lib_dir / "bpf", work_dir / "katran" / "lib" / "bpf")
        shutil.copytree(lib_dir / "linux_includes", work_dir / "katran" / "lib" / "linux_includes")
        for header in (lib_dir / "linux_includes").iterdir():
            if header.is_file():
                stage_file(header, work_dir / "include" / header.name)
        run(["make", f"-j{jobs}", "CLANG=clang", "LLC=llc"], cwd=work_dir)
        object_paths = sorted(path for path in (work_dir / "bpf").glob("*.o") if is_bpf_object(path))
        object_count = stage_many(object_paths, lambda src: stage_root / bpf_stage_relative(Path(src.name)))

    remove_staged_temp_objects(stage_root)
    return RepoBuildResult(
        name="katran",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=0,
        verify_command=(),
        verify_ok=True,
        status="ok",
    )


def build_tracee(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("tracee")
    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}", "bpf", "tracee", "evt", "traceectl", "lsm-check"], cwd=repo_dir)

    dist_dir = repo_dir / "dist"
    object_paths = [dist_dir / "tracee.bpf.o", *(dist_dir / "lsm_support").glob("*.bpf.o")]
    binary_candidates = [
        dist_dir / "tracee",
        dist_dir / "evt",
        dist_dir / "traceectl",
        dist_dir / "lsm-check",
    ]
    binary_paths = [path for path in binary_candidates if is_executable_file(path)]

    object_count = stage_many(
        [path for path in object_paths if path.is_file()],
        lambda src: stage_root / bpf_stage_relative(src.relative_to(dist_dir)),
    )
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "tracee"), "--help")
    return RepoBuildResult(
        name="tracee",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def build_tetragon(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("tetragon")
    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}", "tetragon-bpf", "LOCAL_CLANG=1", f"JOBS={jobs}"], cwd=repo_dir)

    objects_dir = repo_dir / "bpf" / "objs"
    object_paths = sorted(path for path in objects_dir.glob("*.o") if is_bpf_object(path))
    object_count = stage_many(object_paths, lambda src: stage_root / bpf_stage_relative(Path(src.name)))

    binary_paths: list[Path] = []
    if (repo_dir / "cmd" / "tetragon").exists() and (repo_dir / "cmd" / "tetra").exists():
        ok = try_run(
            ["make", f"-j{jobs}", "tetragon", "tetra", "EXTRA_GO_BUILD_FLAGS=-mod=mod"],
            cwd=repo_dir,
        )
        if ok:
            binary_paths = [path for path in (repo_dir / "tetragon", repo_dir / "tetra") if is_executable_file(path)]
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "tetragon"), "--help") if binary_paths else ()
    return RepoBuildResult(
        name="tetragon",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)) if verify_cmd else True,
        status="ok",
    )


def build_cilium(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("cilium")
    bpf_dir = repo_dir / "bpf"
    clean_stage_dir(stage_root)
    run(["make", "clean"], cwd=bpf_dir)
    run(["make", f"-j{jobs}", *CILIUM_BPF_TARGETS], cwd=bpf_dir)

    object_paths = sorted(path for path in bpf_dir.glob("*.o") if is_bpf_object(path))
    object_count = stage_many(object_paths, lambda src: stage_root / bpf_stage_relative(Path(src.name)))
    remove_staged_temp_objects(stage_root)

    return RepoBuildResult(
        name="cilium",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=0,
        verify_command=(),
        verify_ok=True,
        status="ok",
    )


def build_bpftrace(stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout("bpftrace")
    clean_stage_dir(stage_root)

    messages: list[str] = []
    binary_paths: list[Path] = []
    with tempfile.TemporaryDirectory(prefix="bpftrace-build-") as build_dir:
        configure = capture(
            [
                "cmake",
                "-S",
                str(repo_dir),
                "-B",
                build_dir,
                "-DBUILD_TESTING=OFF",
                "-DENABLE_MAN=OFF",
                "-DENABLE_SKB_OUTPUT=OFF",
                "-DUSE_SYSTEM_LIBBPF=ON",
            ]
        )
        if configure.returncode == 0:
            build = capture(["cmake", "--build", build_dir, "-j", str(jobs)])
            if build.returncode == 0:
                candidate = Path(build_dir) / "src" / "bpftrace"
                if is_executable_file(candidate):
                    binary_paths.append(candidate)
            else:
                messages.append(f"userspace build failed: {summarize_process_output(build)}")
        else:
            messages.append(f"userspace configure failed: {summarize_process_output(configure)}")

    stdlib_dir = repo_dir / "src" / "stdlib"
    cached_vmlinux = locate_cached_vmlinux_header()
    stdlib_failures: list[str] = []
    stdlib_objects: list[Path] = []
    common_clang_flags = ["clang", "-target", "bpf", "-g", "-O2", "-I", str(stdlib_dir / "include"), *clang_bpf_sys_includes()]
    with tempfile.TemporaryDirectory(prefix="bpftrace-stdlib-") as temp_dir:
        temp_root = Path(temp_dir)
        for source in sorted(stdlib_dir.rglob("*.bpf.c")):
            relative = source.relative_to(stdlib_dir)
            output = temp_root / bpf_object_path_from_source(relative)
            output.parent.mkdir(parents=True, exist_ok=True)

            needs_vmlinux = source.name in {"task.bpf.c", "vma.bpf.c", "usdt.bpf.c"}
            if needs_vmlinux and cached_vmlinux is None:
                stdlib_failures.append(f"{relative.as_posix()}: requires cached vmlinux.h")
                continue

            command = list(common_clang_flags)
            if needs_vmlinux and cached_vmlinux is not None:
                command.extend(["-I", str(cached_vmlinux.parent)])
            command.extend(["-c", str(source), "-o", str(output)])
            completed = capture(command)
            if completed.returncode == 0 and is_bpf_object(output):
                stdlib_objects.append(output)
                continue
            stdlib_failures.append(f"{relative.as_posix()}: {summarize_process_output(completed)}")

        object_count = stage_many(stdlib_objects, lambda src: stage_root / "stdlib" / src.relative_to(temp_root))

    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    message_parts = []
    if messages:
        message_parts.append(summarize_items(messages, limit=2))
    if stdlib_failures:
        message_parts.append(f"stdlib compile issues: {summarize_items(stdlib_failures, limit=2)}")
    message = "; ".join(part for part in message_parts if part)

    status = "ok"
    if message and (object_count > 0 or binary_count > 0):
        status = "partial"
    if object_count == 0 and binary_count == 0:
        status = "failed"

    verify_cmd = (str(stage_root / "bin" / "bpftrace"), "--help") if binary_count else ()
    return RepoBuildResult(
        name="bpftrace",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)) if verify_cmd else True,
        status=status,
        message=message,
    )


BUILDERS: dict[str, Callable[[Path, int], RepoBuildResult]] = {
    "bcc": build_bcc,
    "libbpf-bootstrap": build_libbpf_bootstrap,
    "xdp-tools": build_xdp_tools,
    "xdp-tutorial": build_xdp_tutorial,
    "scx": build_scx,
    "katran": build_katran,
    "tracee": build_tracee,
    "tetragon": build_tetragon,
    "cilium": build_cilium,
    "bpftrace": build_bpftrace,
}


def main() -> int:
    args = parse_args()
    build_root = Path(args.build_root).resolve()
    build_root.mkdir(parents=True, exist_ok=True)

    requested = args.repos or list(IMPLEMENTED_REPOS)
    unknown = sorted(set(requested) - set(IMPLEMENTED_REPOS))
    if unknown:
        raise SystemExit(
            "unsupported native corpus repo selection: "
            + ", ".join(unknown)
            + f" (supported: {', '.join(IMPLEMENTED_REPOS)})"
        )

    results: list[RepoBuildResult] = []
    for name in requested:
        stage_dir = build_root / name
        print(f"[repo] {name}")
        try:
            result = BUILDERS[name](stage_dir, args.jobs)
        except Exception as exc:
            result = build_failure_result(name, stage_dir, str(exc))
        results.append(result)
        verify_status = "n/a" if not result.verify_command else ("ok" if result.verify_ok else "failed")
        suffix = f", note={result.message}" if result.message else ""
        print(
            f"[done] {name}: status={result.status}, {result.object_count} object(s), "
            f"{result.binary_count} binar(ies), verify={verify_status}{suffix}"
        )

    print("\nNative corpus build summary")
    for result in results:
        verify_status = "n/a" if not result.verify_command else ("ok" if result.verify_ok else "failed")
        verify_cmd = " ".join(result.verify_command) if result.verify_command else "n/a"
        message = f", note={result.message}" if result.message else ""
        print(
            f"- {result.name}: status={result.status}, objects={result.object_count}, binaries={result.binary_count}, "
            f"verify={verify_status}, stage={result.stage_dir}, command=`{verify_cmd}`{message}"
        )

    failed = [result.name for result in results if result.status == "failed"]
    partial = [result.name for result in results if result.status == "partial"]
    if partial:
        print(f"\npartial native build results for: {', '.join(partial)}", file=sys.stderr)
    if failed:
        print(f"\nnon-fatal native build failures for: {', '.join(failed)}", file=sys.stderr)
    if len(results) == 1 and failed:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
