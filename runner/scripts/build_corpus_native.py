#!/usr/bin/env python3
from __future__ import annotations

import argparse
import os
import platform
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Iterable

from elftools.elf.elffile import ELFFile

from runner.libs.runner_artifacts import build_vendor_bpftool


SCRIPT_DIR = Path(__file__).resolve().parent
RUNNER_DIR = SCRIPT_DIR.parent
REPO_ROOT = RUNNER_DIR.parent
CORPUS_BUILD_ROOT = REPO_ROOT / "corpus" / "build"
ACTIVE_BUILD_ROOT = CORPUS_BUILD_ROOT
ACTIVE_VMLINUX_BTF: Path | None = None
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
        "--repo-root",
        default=str(RUNNER_DIR / "repos"),
        help="Corpus repo checkout root.",
    )
    parser.add_argument(
        "--build-root",
        default=str(CORPUS_BUILD_ROOT),
        help="Stable native build cache root.",
    )
    parser.add_argument(
        "--stage-root",
        default="",
        help="Per-run staged output directory. Defaults to --build-root.",
    )
    parser.add_argument(
        "--vmlinux-btf",
        default="",
        help="Explicit vmlinux BTF file used to generate a shared cached vmlinux.h for native repo builds.",
    )
    return parser.parse_args()


def repo_checkout(repo_root: Path, name: str) -> Path:
    path = repo_root / name
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


def ensure_vendor_bpftool() -> Path:
    vendor_build_root = ACTIVE_BUILD_ROOT / "_runner-vendor"
    return build_vendor_bpftool(build_dir=vendor_build_root, env=os.environ.copy())


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


def stage_file_or_symlink(src: Path, dst: Path) -> None:
    dst.parent.mkdir(parents=True, exist_ok=True)
    if src.is_symlink():
        if dst.exists() or dst.is_symlink():
            dst.unlink()
        target = os.readlink(src)
        target_path = Path(target)
        if target_path.is_absolute():
            sibling_target = src.parent / target_path.name
            if sibling_target.exists():
                target = sibling_target.name
        os.symlink(target, dst)
        return
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


def git_path_is_pristine(repo_root: Path, pathspec: str) -> bool:
    completed = subprocess.run(
        [
            "git",
            "-C",
            str(repo_root),
            "status",
            "--porcelain=v1",
            "--untracked-files=all",
            "--",
            pathspec,
        ],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    if completed.returncode != 0:
        raise CommandError(completed.stderr.strip() or f"failed to inspect git status for {pathspec}")
    return not completed.stdout.strip()


def iter_git_tracked_paths(repo_root: Path, pathspec: str) -> list[Path]:
    completed = subprocess.run(
        ["git", "-C", str(repo_root), "ls-files", "-z", "--", pathspec],
        check=False,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=False,
    )
    if completed.returncode != 0:
        message = completed.stderr.decode("utf-8", errors="replace").strip() or f"failed to list tracked files under {pathspec}"
        raise CommandError(message)
    return [
        repo_root / rel.decode("utf-8", errors="replace").strip()
        for rel in completed.stdout.split(b"\0")
        if rel
    ]


def is_bpf_object(path: Path) -> bool:
    try:
        with path.open("rb") as handle:
            machine = ELFFile(handle).header["e_machine"]
    except Exception:
        return False
    if isinstance(machine, int):
        return machine == BPF_ELF_MACHINE
    return str(machine) in {"EM_BPF", "Linux BPF", str(BPF_ELF_MACHINE)}


def verify_binary(command: list[str], *, env: dict[str, str] | None = None) -> bool:
    if not command:
        return True
    try:
        completed = subprocess.run(command, capture_output=True, text=True, timeout=30, check=False, env=env)
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


def clang_system_include_paths(clang: str = "clang") -> list[str]:
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
            includes.append(candidate)
    return includes


def clang_bpf_sys_includes(clang: str = "clang") -> list[str]:
    includes: list[str] = []
    for path in clang_system_include_paths(clang):
        includes.extend(["-idirafter", path])
    return includes


def ensure_cached_vmlinux_header(vmlinux_btf: Path) -> Path:
    vmlinux_btf = vmlinux_btf.resolve()
    if not vmlinux_btf.is_file():
        raise CommandError(f"missing explicit vmlinux BTF: {vmlinux_btf}")
    cache_dir = ACTIVE_BUILD_ROOT / "_shared"
    cache_dir.mkdir(parents=True, exist_ok=True)
    header_path = cache_dir / "vmlinux.h"
    stamp_path = cache_dir / "vmlinux.h.source"
    source_signature = f"{vmlinux_btf}:{vmlinux_btf.stat().st_size}:{vmlinux_btf.stat().st_mtime_ns}"
    if header_path.is_file() and stamp_path.is_file() and stamp_path.read_text().strip() == source_signature:
        return header_path

    bpftool = ensure_vendor_bpftool()
    print(f"[run] {bpftool} btf dump file {vmlinux_btf} format c > {header_path}")
    with header_path.open("w", encoding="utf-8") as handle:
        completed = subprocess.run(
            [str(bpftool), "btf", "dump", "file", str(vmlinux_btf), "format", "c"],
            stdout=handle,
            stderr=subprocess.PIPE,
            text=True,
            check=False,
        )
    if completed.returncode != 0:
        raise CommandError(completed.stderr.strip() or f"failed to generate cached vmlinux.h from {vmlinux_btf}")
    stamp_path.write_text(source_signature + "\n", encoding="utf-8")
    return header_path


def locate_cached_vmlinux_header() -> Path | None:
    if ACTIVE_VMLINUX_BTF is not None:
        return ensure_cached_vmlinux_header(ACTIVE_VMLINUX_BTF)
    prioritized = [
        ACTIVE_BUILD_ROOT / "bcc" / "vmlinux.h",
        ACTIVE_BUILD_ROOT / "katran" / "vmlinux.h",
        ACTIVE_BUILD_ROOT / "cilium" / "vmlinux.h",
        ACTIVE_BUILD_ROOT / "linux-selftests" / "vmlinux.h",
        ACTIVE_BUILD_ROOT / "manual-test" / "vmlinux.h",
    ]
    for candidate in prioritized:
        if candidate.is_file():
            return candidate
    build_root = ACTIVE_BUILD_ROOT
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


def bpftrace_target_arch_define() -> str:
    machine = platform.machine().lower()
    arch_map = {
        "x86_64": "x86",
        "amd64": "x86",
        "aarch64": "arm64",
        "arm64": "arm64",
        "armv7l": "arm",
        "armv6l": "arm",
        "riscv64": "riscv",
        "s390x": "s390",
        "ppc64le": "powerpc",
        "ppc64": "powerpc",
        "loongarch64": "loongarch",
    }
    target = arch_map.get(machine)
    if target is None:
        raise CommandError(f"unsupported host architecture for bpftrace stdlib build: {machine}")
    return f"__TARGET_ARCH_{target}"


def resolve_bpftrace_llvm_cmake_dirs() -> tuple[Path, Path]:
    supported_majors = ("18", "19", "20", "21", "22")
    llvm_prefixes = (Path("/usr/lib"), Path("/lib"))
    clang_prefixes = (Path("/usr/lib/cmake"), Path("/lib/cmake"))
    for major in supported_majors:
        llvm_dir = next((prefix / f"llvm-{major}" / "cmake" for prefix in llvm_prefixes if (prefix / f"llvm-{major}" / "cmake").is_dir()), None)
        clang_dir = next((prefix / f"clang-{major}" for prefix in clang_prefixes if (prefix / f"clang-{major}").is_dir()), None)
        if llvm_dir is not None and clang_dir is not None:
            return llvm_dir, clang_dir
    raise CommandError("missing supported LLVM/Clang CMake packages for bpftrace userspace build (need 18-22)")


def prepare_bpftrace_vmlinux_header(cached_vmlinux: Path, *, temp_root: Path) -> Path:
    text = cached_vmlinux.read_text()
    filtered_lines = [
        line
        for line in text.splitlines()
        if "bpf_iter_task_vma_new(struct bpf_iter_task_vma *it" not in line
        and "bpf_iter_task_vma_next(struct bpf_iter_task_vma *it)" not in line
        and "bpf_iter_task_vma_destroy(struct bpf_iter_task_vma *it)" not in line
    ]
    staged_header = temp_root / "include" / "vmlinux.h"
    staged_header.parent.mkdir(parents=True, exist_ok=True)
    staged_header.write_text("\n".join(filtered_lines) + "\n")
    return staged_header


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


def build_bcc(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "bcc")
    tool_dir = repo_dir / "libbpf-tools"
    bpftool = ensure_vendor_bpftool()
    clang_value = " ".join(["clang", *clang_bpf_sys_includes()])
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
    staged_output_dir = stage_root / "libbpf-tools" / ".output"
    object_count = stage_many(object_paths, lambda src: staged_output_dir / src.name)
    binary_count = stage_many(binary_paths, lambda src: staged_output_dir / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(staged_output_dir / "bindsnoop"), "-h")
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


def build_libbpf_bootstrap(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "libbpf-bootstrap")
    example_dir = repo_dir / "examples" / "c"
    bpftool = ensure_vendor_bpftool()
    vmlinux = find_cached_vmlinux_header()

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


def build_xdp_tools(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "xdp-tools")
    bpftool = ensure_vendor_bpftool()
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


def build_xdp_tutorial(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "xdp-tutorial")
    xdp_tools_dir = repo_checkout(repo_root, "xdp-tools")
    loader_dir = xdp_tools_dir / "xdp-loader"
    extra_cflags = "-Wno-error=macro-redefined -Wno-macro-redefined"

    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}"], cwd=xdp_tools_dir)
    run(
        [
            "make",
            f"-j{jobs}",
            f"LOADER_DIR={loader_dir}",
            f"EXTRA_CFLAGS={extra_cflags}",
        ],
        cwd=repo_dir,
    )
    for extra_dir in ("advanced03-AF_XDP", "experiment01-tailgrow"):
        run(
            [
                "make",
                f"-j{jobs}",
                f"LOADER_DIR={loader_dir}",
                f"EXTRA_CFLAGS={extra_cflags}",
            ],
            cwd=repo_dir / extra_dir,
        )

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


def build_scx(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "scx")
    clean_stage_dir(stage_root)
    stage_root = stage_root.resolve()
    if stage_root.name != "scx" or stage_root.parent.name != "build" or stage_root.parent.parent.name != "corpus":
        raise CommandError(
            "scx stage root must follow <promote-root>/corpus/build/scx; "
            f"got {stage_root}"
        )
    promote_root = stage_root.parents[2]
    run(
        [
            "make",
            "-C",
            str(REPO_ROOT),
            "__scx-build",
            f"PYTHON={sys.executable}",
            f"JOBS={max(1, jobs)}",
            f"SCX_REPO_ROOT={repo_root}",
            f"SCX_PROMOTE_ROOT={promote_root}",
        ],
        cwd=REPO_ROOT,
    )
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


def build_katran(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "katran")
    lib_dir = repo_dir / "katran" / "lib"
    helper_root = REPO_ROOT / "e2e" / "cases" / "katran"
    helper_binary = helper_root / "bin" / "katran_server_grpc"
    helper_lib_root = helper_root / "lib"
    clang = str(os.environ.get("CLANG", "clang")).strip() or "clang"
    llc = str(os.environ.get("LLC", "llc")).strip() or "llc"
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
        run(["make", f"-j{jobs}", f"CLANG={clang}", f"LLC={llc}"], cwd=work_dir)
        object_paths = sorted(path for path in (work_dir / "bpf").glob("*.o") if is_bpf_object(path))
        object_count = stage_many(object_paths, lambda src: stage_root / bpf_stage_relative(Path(src.name)))

    if not git_path_is_pristine(REPO_ROOT, "e2e/cases/katran/bin"):
        raise CommandError("x86 Katran helper bin dir has local modifications and cannot be staged")
    if not git_path_is_pristine(REPO_ROOT, "e2e/cases/katran/lib"):
        raise CommandError("x86 Katran helper lib dir has local modifications and cannot be staged")
    tracked_binary_paths = iter_git_tracked_paths(REPO_ROOT, "e2e/cases/katran/bin/katran_server_grpc")
    if tracked_binary_paths != [helper_binary]:
        raise CommandError(f"x86 Katran server helper must be git-tracked: {helper_binary}")
    if not helper_binary.is_file() or not os.access(helper_binary, os.X_OK):
        raise CommandError(f"missing shared Katran server helper: {helper_binary}")
    if not helper_lib_root.is_dir():
        raise CommandError(f"missing shared Katran runtime lib dir: {helper_lib_root}")
    stage_file_or_symlink(helper_binary, stage_root / "bin" / helper_binary.name)
    for path in sorted(iter_git_tracked_paths(REPO_ROOT, "e2e/cases/katran/lib")):
        stage_file_or_symlink(path, stage_root / "lib" / path.name)

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


def build_tracee(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "tracee")
    clean_stage_dir(stage_root)
    build_env = os.environ.copy()
    goflags = build_env.get("GOFLAGS", "").strip()
    build_env["GOFLAGS"] = (
        f"{goflags} -buildvcs=false".strip()
        if "-buildvcs=false" not in goflags.split()
        else goflags
    )
    run(
        ["make", f"-j{jobs}", "bpf", "tracee", "evt", "traceectl", "lsm-check"],
        cwd=repo_dir,
        env=build_env,
    )

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


def build_tetragon(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "tetragon")
    clean_stage_dir(stage_root)
    run(["make", f"-j{jobs}", "tetragon-bpf", "LOCAL_CLANG=1", f"JOBS={jobs}"], cwd=repo_dir)

    objects_dir = repo_dir / "bpf" / "objs"
    object_paths = sorted(path for path in objects_dir.glob("*.o") if is_bpf_object(path))
    # Tetragon resolves these objects by their original basename at runtime
    # (for example bpf_alignchecker.o), so preserve the upstream filenames.
    object_count = stage_many(object_paths, lambda src: stage_root / src.name)

    if not (repo_dir / "cmd" / "tetragon").is_dir():
        raise CommandError(
            f"tetragon checkout is missing cmd/tetragon under {repo_dir}; "
            "fetch the repo without a sparse tree that omits the userspace agent"
        )
    run(["make", f"-j{jobs}", "tetragon", "EXTRA_GO_BUILD_FLAGS=-mod=mod"], cwd=repo_dir)
    binary_paths = [path for path in (repo_dir / "tetragon",) if is_executable_file(path)]
    if not binary_paths:
        raise CommandError(f"Tetragon build completed without producing {repo_dir / 'tetragon'}")
    binary_count = stage_many(binary_paths, lambda src: stage_root / "bin" / src.name)
    remove_staged_temp_objects(stage_root)

    verify_cmd = (str(stage_root / "bin" / "tetragon"), "--help")
    return RepoBuildResult(
        name="tetragon",
        stage_dir=stage_root,
        object_count=object_count,
        binary_count=binary_count,
        verify_command=verify_cmd,
        verify_ok=verify_binary(list(verify_cmd)),
        status="ok",
    )


def build_cilium(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "cilium")
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


def build_bpftrace(repo_root: Path, stage_root: Path, jobs: int) -> RepoBuildResult:
    repo_dir = repo_checkout(repo_root, "bpftrace")
    clean_stage_dir(stage_root)
    llvm_dir, clang_dir = resolve_bpftrace_llvm_cmake_dirs()
    llvm_major = llvm_dir.parent.name.removeprefix("llvm-")
    clang_binary = f"clang-{llvm_major}"
    if shutil.which(clang_binary) is None:
        clang_binary = "clang"
    system_include_paths = f'\\\"{":".join(clang_system_include_paths(clang_binary))}\\\"'
    run(["git", "submodule", "update", "--init", "--depth", "1", "libbpf"], cwd=repo_dir)

    messages: list[str] = []
    binary_count = 0
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
                f"-DLLVM_DIR={llvm_dir}",
                f"-DClang_DIR={clang_dir}",
                f"-DSYSTEM_INCLUDE_PATHS={system_include_paths}",
            ]
        )
        if configure.returncode == 0:
            build = capture(["cmake", "--build", build_dir, "-j", str(jobs)])
            if build.returncode == 0:
                candidate = Path(build_dir) / "src" / "bpftrace"
                if is_executable_file(candidate):
                    binary_count = stage_many([candidate], lambda src: stage_root / "bin" / src.name)
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
        bpftrace_vmlinux = (
            prepare_bpftrace_vmlinux_header(cached_vmlinux, temp_root=temp_root)
            if cached_vmlinux is not None
            else None
        )
        for source in sorted(stdlib_dir.rglob("*.bpf.c")):
            relative = source.relative_to(stdlib_dir)
            relative_posix = relative.as_posix()
            output = temp_root / bpf_object_path_from_source(relative)
            output.parent.mkdir(parents=True, exist_ok=True)

            needs_vmlinux = source.name in {"task.bpf.c", "vma.bpf.c", "usdt.bpf.c"}
            if needs_vmlinux and cached_vmlinux is None:
                stdlib_failures.append(f"{relative.as_posix()}: requires cached vmlinux.h")
                continue

            command = list(common_clang_flags)
            if relative_posix == "usdt/usdt.bpf.c":
                command.append(f"-D{bpftrace_target_arch_define()}")
                if bpftrace_vmlinux is not None:
                    command.extend(["-include", str(bpftrace_vmlinux)])
            if needs_vmlinux and bpftrace_vmlinux is not None:
                command.extend(["-I", str(bpftrace_vmlinux.parent)])
            command.extend(["-c", str(source), "-o", str(output)])
            completed = capture(command)
            if completed.returncode == 0 and is_bpf_object(output):
                stdlib_objects.append(output)
                continue
            stdlib_failures.append(f"{relative.as_posix()}: {summarize_process_output(completed)}")

        object_count = stage_many(stdlib_objects, lambda src: stage_root / "stdlib" / src.relative_to(temp_root))

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


BUILDERS: dict[str, Callable[[Path, Path, int], RepoBuildResult]] = {
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
    global ACTIVE_BUILD_ROOT, ACTIVE_VMLINUX_BTF
    args = parse_args()
    repo_root = Path(args.repo_root).resolve()
    build_root = Path(args.build_root).resolve()
    stage_root = Path(args.stage_root).resolve() if args.stage_root else build_root
    ACTIVE_BUILD_ROOT = build_root
    ACTIVE_VMLINUX_BTF = Path(args.vmlinux_btf).resolve() if args.vmlinux_btf else None
    build_root.mkdir(parents=True, exist_ok=True)
    stage_root.mkdir(parents=True, exist_ok=True)

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
        stage_dir = stage_root / name
        print(f"[repo] {name}")
        try:
            result = BUILDERS[name](repo_root, stage_dir, args.jobs)
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
        print(f"\nfatal native build failures for: {', '.join(failed)}", file=sys.stderr)
    if partial or failed:
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
