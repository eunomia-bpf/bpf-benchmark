from __future__ import annotations

import os
import shutil
import stat
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import NoReturn


ROOT_DIR = Path(__file__).resolve().parents[2]
SELECTION_FILE = ROOT_DIR / "runner" / "config" / "upstream_selftests_selection.tsv"


def _die(message: str) -> NoReturn:
    print(f"[build-upstream-selftests][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def _env_required(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        _die(f"{name} is required")
    return value


def _env_optional(name: str, *, default: str = "") -> str:
    return os.environ.get(name, default).strip()


def _require_file(path: Path, description: str) -> None:
    if not path.is_file():
        _die(f"{description} is missing: {path}")


def _require_dir(path: Path, description: str) -> None:
    if not path.is_dir():
        _die(f"{description} is missing: {path}")


def _resolve_llvm_tool(base: str, suffix: str) -> str:
    candidates: list[str] = []
    if suffix:
        candidates.extend((f"{base}-{suffix}", f"{base}{suffix}"))
    candidates.append(base)
    for candidate in candidates:
        resolved = shutil.which(candidate)
        if resolved:
            return resolved
    _die(f"required LLVM tool is missing: {base}")


def _normalize_kernel_arch(arch: str) -> str:
    mapping = {
        "aarch64": "arm64",
        "x86_64": "x86",
        "amd64": "x86",
    }
    return mapping.get(arch, arch)


def _write_executable(path: Path, content: str) -> None:
    path.write_text(content, encoding="utf-8")
    mode = path.stat().st_mode
    path.chmod(mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)


@dataclass(frozen=True)
class SelectionManifest:
    build_targets: tuple[str, ...]
    source_excludes: tuple[str, ...]


@dataclass(frozen=True)
class BuildConfig:
    source_dir: Path
    output_dir: Path
    vmlinux_btf: Path
    jobs: str
    llvm_suffix: str
    host_python_bin: str
    arch: str
    cross_compile: str
    sysroot_root: str
    pkgconfig_libdir: str
    toolchain_dir: Path
    generated_include_dir: Path
    kernel_source_root: Path

    @property
    def cross_mode(self) -> bool:
        return bool(self.cross_compile)

    @classmethod
    def from_env(cls) -> "BuildConfig":
        source_dir = Path(_env_required("UPSTREAM_SELFTEST_SOURCE_DIR")).resolve()
        output_dir = Path(_env_required("UPSTREAM_SELFTEST_OUTPUT_DIR")).resolve()
        vmlinux_btf = Path(_env_required("VMLINUX_BTF")).resolve()
        _require_dir(source_dir, "selftest source dir")
        _require_file(vmlinux_btf, "VMLINUX_BTF")
        kernel_source_root = source_dir.parents[3]
        return cls(
            source_dir=source_dir,
            output_dir=output_dir,
            vmlinux_btf=vmlinux_btf,
            jobs=_env_optional("JOBS", default="1") or "1",
            llvm_suffix=_env_optional("UPSTREAM_SELFTEST_LLVM_SUFFIX"),
            host_python_bin=_env_optional("UPSTREAM_SELFTEST_HOST_PYTHON_BIN", default="python3") or "python3",
            arch=_env_optional("UPSTREAM_SELFTEST_ARCH"),
            cross_compile=_env_optional("UPSTREAM_SELFTEST_CROSS_COMPILE"),
            sysroot_root=_env_optional("UPSTREAM_SELFTEST_SYSROOT_ROOT"),
            pkgconfig_libdir=_env_optional("UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR"),
            toolchain_dir=Path(
                _env_optional(
                    "UPSTREAM_SELFTEST_TOOLCHAIN_DIR",
                    default=str(output_dir / "toolchain"),
                )
            ).resolve(),
            generated_include_dir=(output_dir / "build-include").resolve(),
            kernel_source_root=kernel_source_root.resolve(),
        )


def load_selection_manifest(path: Path = SELECTION_FILE) -> SelectionManifest:
    _require_file(path, "selection manifest")
    seen: set[tuple[str, str]] = set()
    build_targets: list[str] = []
    source_excludes: list[str] = []
    for line_no, raw_line in enumerate(path.read_text(encoding="utf-8").splitlines(), start=1):
        if not raw_line or raw_line.startswith("#"):
            continue
        parts = raw_line.split("\t")
        if len(parts) != 3 or not all(parts):
            _die(
                f"invalid selection entry at {path}:{line_no}; expected "
                "<kind><TAB><value><TAB><reason>"
            )
        kind, value, _reason = parts
        key = (kind, value)
        if key in seen:
            _die(f"duplicate selection entry at {path}:{line_no}: {kind} {value}")
        seen.add(key)
        if kind == "make_target":
            build_targets.append(value)
        elif kind == "source_exclude":
            source_excludes.append(value)
        else:
            _die(f"unknown selection kind at {path}:{line_no}: {kind}")
    if not build_targets:
        _die(f"selection manifest defines no build targets: {path}")
    return SelectionManifest(tuple(build_targets), tuple(source_excludes))


def prepare_cross_toolchain(config: BuildConfig) -> None:
    if not config.cross_mode:
        return
    if not config.arch:
        _die("UPSTREAM_SELFTEST_ARCH is required in cross mode")
    if not config.cross_compile:
        _die("UPSTREAM_SELFTEST_CROSS_COMPILE is required in cross mode")
    if not config.sysroot_root:
        _die("UPSTREAM_SELFTEST_SYSROOT_ROOT is required in cross mode")
    if not config.pkgconfig_libdir:
        _die("UPSTREAM_SELFTEST_PKGCONFIG_LIBDIR is required in cross mode")

    cross_cc = shutil.which(f"{config.cross_compile}gcc")
    cross_cxx = shutil.which(f"{config.cross_compile}g++")
    cross_ld = shutil.which(f"{config.cross_compile}ld")
    cross_ar = shutil.which(f"{config.cross_compile}ar")
    if not cross_cc:
        _die(f"missing cross compiler: {config.cross_compile}gcc")
    if not cross_cxx:
        _die(f"missing cross compiler: {config.cross_compile}g++")
    if not cross_ld:
        _die(f"missing cross linker: {config.cross_compile}ld")
    if not cross_ar:
        _die(f"missing cross archiver: {config.cross_compile}ar")

    shutil.rmtree(config.toolchain_dir, ignore_errors=True)
    config.toolchain_dir.mkdir(parents=True, exist_ok=True)

    _write_executable(
        config.toolchain_dir / "cc",
        f'#!/usr/bin/env bash\nexec "{cross_cc}" --sysroot="{config.sysroot_root}" "$@"\n',
    )
    _write_executable(
        config.toolchain_dir / "cxx",
        f'#!/usr/bin/env bash\nexec "{cross_cxx}" --sysroot="{config.sysroot_root}" "$@"\n',
    )
    _write_executable(
        config.toolchain_dir / "ld",
        f'#!/usr/bin/env bash\nexec "{cross_ld}" --sysroot="{config.sysroot_root}" "$@"\n',
    )
    _write_executable(
        config.toolchain_dir / "pkg-config",
        "\n".join(
            (
                "#!/usr/bin/env bash",
                f'export PKG_CONFIG_SYSROOT_DIR="{config.sysroot_root}"',
                f'export PKG_CONFIG_LIBDIR="{config.pkgconfig_libdir}"',
                'exec pkg-config "$@"',
                "",
            )
        ),
    )


def prepare_generated_include_dir(config: BuildConfig) -> None:
    kernel_arch = _normalize_kernel_arch(config.arch or os.uname().machine)
    shutil.rmtree(config.generated_include_dir, ignore_errors=True)
    (config.generated_include_dir / "linux").mkdir(parents=True, exist_ok=True)
    shutil.copy2(
        config.kernel_source_root / "include" / "linux" / "kasan-checks.h",
        config.generated_include_dir / "linux" / "kasan-checks.h",
    )
    alt_header = (
        config.kernel_source_root
        / "arch"
        / kernel_arch
        / "include"
        / "asm"
        / "alternative-macros.h"
    )
    if alt_header.is_file():
        (config.generated_include_dir / "asm").mkdir(parents=True, exist_ok=True)
        shutil.copy2(
            alt_header,
            config.generated_include_dir / "asm" / "alternative-macros.h",
        )


def _copy_or_link(entry: Path, destination: Path) -> None:
    if entry.is_symlink():
        destination.parent.mkdir(parents=True, exist_ok=True)
        os.symlink(os.readlink(entry), destination)
        return
    if entry.is_dir():
        destination.mkdir(parents=True, exist_ok=True)
        return
    destination.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(entry, destination)


def prepare_selected_source_dir(config: BuildConfig, selection: SelectionManifest) -> Path:
    if not selection.source_excludes:
        return config.source_dir

    selected_root = Path(f"{config.output_dir}.source-tree")
    selected_dir = selected_root / "tools" / "testing" / "selftests" / "bpf"
    source_root = config.source_dir.parents[2]
    selftests_root = source_root / "testing" / "selftests"
    kernel_root = config.source_dir.parents[3]

    excluded = set(selection.source_excludes)
    for rel_path in excluded:
        if not (config.source_dir / rel_path).exists():
            _die(f"selection manifest excludes missing upstream selftest source: {rel_path}")

    shutil.rmtree(selected_root, ignore_errors=True)
    (selected_root / "tools" / "testing" / "selftests").mkdir(parents=True, exist_ok=True)

    symlinks = {
        selected_root / "include": kernel_root / "include",
        selected_root / "arch": kernel_root / "arch",
        selected_root / "kernel": kernel_root / "kernel",
        selected_root / "scripts": kernel_root / "scripts",
        selected_root / "tools" / "build": source_root / "build",
        selected_root / "tools" / "scripts": source_root / "scripts",
        selected_root / "tools" / "lib": source_root / "lib",
        selected_root / "tools" / "include": source_root / "include",
        selected_root / "tools" / "arch": source_root / "arch",
        selected_root / "tools" / "bpf": source_root / "bpf",
    }
    for link_path, target_path in symlinks.items():
        link_path.parent.mkdir(parents=True, exist_ok=True)
        os.symlink(target_path, link_path)

    for entry in selftests_root.iterdir():
        if entry.name == "bpf":
            continue
        os.symlink(entry, selected_root / "tools" / "testing" / "selftests" / entry.name)

    selected_dir.mkdir(parents=True, exist_ok=True)
    for entry in sorted(config.source_dir.rglob("*")):
        rel_path = entry.relative_to(config.source_dir).as_posix()
        if rel_path in excluded:
            continue
        _copy_or_link(entry, selected_dir / rel_path)

    for rel_path in excluded:
        if (selected_dir / rel_path).exists():
            _die(f"selected upstream selftest exclusion leaked into selected source view: {rel_path}")
    return selected_dir


def sanitize_generated_vmlinux_header(header_path: Path) -> None:
    _require_file(header_path, "generated vmlinux header")
    targets = (
        "bpf_arena_alloc_pages(",
        "bpf_arena_free_pages(",
        "bpf_arena_reserve_pages(",
        "bpf_path_d_path(",
    )
    filtered = [
        line
        for line in header_path.read_text(encoding="utf-8").splitlines()
        if not any(target in line for target in targets)
    ]
    header_path.write_text("\n".join(filtered) + "\n", encoding="utf-8")


def _make_args(config: BuildConfig, source_dir: Path) -> list[str]:
    clang_bin = _resolve_llvm_tool("clang", config.llvm_suffix)
    cxx_bin = _resolve_llvm_tool("clang++", config.llvm_suffix)
    ld_bin = _resolve_llvm_tool("ld.lld", config.llvm_suffix)
    host_ar_bin = _resolve_llvm_tool("llvm-ar", config.llvm_suffix)
    llc_bin = _resolve_llvm_tool("llc", config.llvm_suffix)
    llvm_config = _resolve_llvm_tool("llvm-config", config.llvm_suffix)
    llvm_objcopy = _resolve_llvm_tool("llvm-objcopy", config.llvm_suffix)
    llvm_strip = _resolve_llvm_tool("llvm-strip", config.llvm_suffix)

    args = [
        "make",
        "-C",
        str(source_dir),
        f"-j{config.jobs}",
        "LLVM=1",
        f"CLANG={clang_bin}",
        f"LLC={llc_bin}",
        f"LLVM_CONFIG={llvm_config}",
        f"LLVM_OBJCOPY={llvm_objcopy}",
        f"LLVM_STRIP={llvm_strip}",
        f"HOSTCC={clang_bin}",
        f"HOSTCXX={cxx_bin}",
        f"HOSTLD={ld_bin}",
        f"HOSTAR={host_ar_bin}",
        f"VMLINUX_BTF={config.vmlinux_btf}",
        f"OUTPUT={config.output_dir}",
        "TEST_KMODS=",
        "SKIP_DOCS=1",
    ]
    include_flag = f"-I{config.generated_include_dir}"
    if config.cross_mode:
        prepare_cross_toolchain(config)
        args.extend(
            [
                f"ARCH={config.arch}",
                f"CROSS_COMPILE={config.cross_compile}",
                f"CC={config.toolchain_dir / 'cc'}",
                f"CXX={config.toolchain_dir / 'cxx'}",
                f"LD={config.toolchain_dir / 'ld'}",
                f"AR={config.cross_compile}ar",
                f"PKG_CONFIG={config.toolchain_dir / 'pkg-config'}",
                f"USERCFLAGS={include_flag}",
                (
                    "EXTRA_CFLAGS="
                    f"{include_flag} -D__GLIBC_USE_DEPRECATED_SCANF=1 "
                    "-D__GLIBC_USE_C2X_STRTOL=0"
                ),
            ]
        )
    else:
        args.extend(
            [
                f"CC={clang_bin}",
                f"CXX={cxx_bin}",
                f"LD={ld_bin}",
                f"AR={host_ar_bin}",
                f"USERCFLAGS={include_flag}",
                f"EXTRA_CFLAGS={include_flag}",
            ]
        )
    return args


def _run_checked(command: list[str]) -> None:
    completed = subprocess.run(command, text=True, check=False)
    if completed.returncode != 0:
        rendered = " ".join(command)
        _die(f"command failed ({completed.returncode}): {rendered}")


def build_upstream_selftests(config: BuildConfig, selection: SelectionManifest) -> None:
    print(f"[build-upstream-selftests] selection manifest: {SELECTION_FILE}")
    print(
        "[build-upstream-selftests] build targets: "
        + " ".join(selection.build_targets)
    )
    if selection.source_excludes:
        print(
            "[build-upstream-selftests] source excludes: "
            + " ".join(selection.source_excludes)
        )

    shutil.rmtree(config.output_dir, ignore_errors=True)
    config.output_dir.mkdir(parents=True, exist_ok=True)
    prepare_generated_include_dir(config)
    source_dir = prepare_selected_source_dir(config, selection)
    make_args = _make_args(config, source_dir)

    generated_header = config.output_dir / "tools" / "include" / "vmlinux.h"
    _run_checked(make_args + [str(generated_header)])
    sanitize_generated_vmlinux_header(generated_header)
    _run_checked(make_args + list(selection.build_targets))


def main(argv: list[str] | None = None) -> None:
    if argv not in (None, []):
        _die("usage: python -m runner.libs.build_upstream_selftests")
    config = BuildConfig.from_env()
    selection = load_selection_manifest()
    build_upstream_selftests(config, selection)


if __name__ == "__main__":
    main()
