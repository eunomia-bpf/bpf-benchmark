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
IMPLEMENTED_REPOS = ("bcc", "libbpf-bootstrap", "xdp-tools", "xdp-tutorial", "scx")
BPF_ELF_MACHINE = 247


@dataclass(frozen=True)
class RepoBuildResult:
    name: str
    stage_dir: Path
    object_count: int
    binary_count: int
    verify_command: tuple[str, ...]
    verify_ok: bool


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
        raise SystemExit(f"repo checkout missing for `{name}`: {path} (run `make corpus-fetch` first)")
    return path


def run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    printable = " ".join(command)
    where = f" (cwd={cwd})" if cwd else ""
    print(f"[run] {printable}{where}")
    completed = subprocess.run(command, cwd=cwd, env=env, text=True, check=False)
    if completed.returncode != 0:
        raise SystemExit(completed.returncode)


def try_run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> bool:
    printable = " ".join(command)
    where = f" (cwd={cwd})" if cwd else ""
    print(f"[run] {printable}{where}")
    completed = subprocess.run(command, cwd=cwd, env=env, text=True, check=False)
    return completed.returncode == 0


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
            raise SystemExit(f"staging collision for {dst}: {other} vs {src}")
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
    completed = subprocess.run(command, capture_output=True, text=True, timeout=30, check=False)
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


def find_cached_vmlinux_header() -> Path:
    candidates = [
        REPO_ROOT / "corpus" / "build" / "real_world_code_size" / "libbpf-bootstrap" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "bcc" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "katran" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "cilium" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "linux-selftests" / "vmlinux.h",
        REPO_ROOT / "corpus" / "build" / "manual-test" / "vmlinux.h",
    ]
    for candidate in candidates:
        if candidate.is_file():
            return candidate
    raise SystemExit(
        "missing cached vmlinux.h for native corpus builds; "
        "run the generic corpus object builder first or provide a staged vmlinux.h under corpus/build/"
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
        raise SystemExit(f"missing staged scx objects after build: {', '.join(missing)}")

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
    )


BUILDERS: dict[str, Callable[[Path, int], RepoBuildResult]] = {
    "bcc": build_bcc,
    "libbpf-bootstrap": build_libbpf_bootstrap,
    "xdp-tools": build_xdp_tools,
    "xdp-tutorial": build_xdp_tutorial,
    "scx": build_scx,
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
        result = BUILDERS[name](stage_dir, args.jobs)
        results.append(result)
        verify_status = "ok" if result.verify_ok else "failed"
        print(
            f"[done] {name}: {result.object_count} object(s), "
            f"{result.binary_count} binar(ies), verify={verify_status}"
        )

    print("\nNative corpus build summary")
    for result in results:
        verify_status = "ok" if result.verify_ok else "failed"
        verify_cmd = " ".join(result.verify_command)
        print(
            f"- {result.name}: objects={result.object_count}, binaries={result.binary_count}, "
            f"verify={verify_status}, stage={result.stage_dir}, command=`{verify_cmd}`"
        )

    failed = [result.name for result in results if not result.verify_ok]
    if failed:
        print(f"\nverification failed for: {', '.join(failed)}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
