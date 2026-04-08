from __future__ import annotations

from pathlib import Path

import pytest

from runner.libs import build_upstream_selftests


def test_load_selection_manifest_reads_tracked_contract(tmp_path: Path) -> None:
    manifest = tmp_path / "selection.tsv"
    manifest.write_text(
        "\n".join(
            [
                "# kind\tvalue\treason",
                "make_target\ttest_verifier\trequired",
                "source_exclude\tprogs/bpf_smc.c\tunsupported",
                "",
            ]
        ),
        encoding="utf-8",
    )

    selection = build_upstream_selftests.load_selection_manifest(manifest)

    assert selection.build_targets == ("test_verifier",)
    assert selection.source_excludes == ("progs/bpf_smc.c",)


def test_load_selection_manifest_rejects_duplicate_entries(tmp_path: Path) -> None:
    manifest = tmp_path / "selection.tsv"
    manifest.write_text(
        "\n".join(
            [
                "make_target\ttest_verifier\trequired",
                "make_target\ttest_verifier\tduplicate",
                "",
            ]
        ),
        encoding="utf-8",
    )

    with pytest.raises(SystemExit):
        build_upstream_selftests.load_selection_manifest(manifest)


def test_prepare_selected_source_dir_materializes_filtered_tree(tmp_path: Path) -> None:
    kernel_root = tmp_path / "linux"
    source_dir = kernel_root / "tools" / "testing" / "selftests" / "bpf"
    (source_dir / "progs").mkdir(parents=True)
    (source_dir / "prog_tests").mkdir(parents=True)
    (source_dir / "keep.txt").write_text("keep\n", encoding="utf-8")
    (source_dir / "progs" / "keep.c").write_text("keep\n", encoding="utf-8")
    (source_dir / "progs" / "drop.c").write_text("drop\n", encoding="utf-8")
    (source_dir / "prog_tests" / "drop_test.c").write_text("drop\n", encoding="utf-8")

    source_root = source_dir.parents[2]
    for path in (
        source_root / "build",
        source_root / "scripts",
        source_root / "lib",
        source_root / "include",
        source_root / "arch",
        source_root / "bpf",
        source_root / "testing" / "selftests" / "net",
        kernel_root / "include" / "linux",
        kernel_root / "arch" / "x86" / "include" / "asm",
        kernel_root / "kernel",
        kernel_root / "scripts",
    ):
        path.mkdir(parents=True, exist_ok=True)

    (kernel_root / "include" / "linux" / "kasan-checks.h").write_text("", encoding="utf-8")
    (
        kernel_root / "arch" / "x86" / "include" / "asm" / "alternative-macros.h"
    ).write_text("", encoding="utf-8")

    config = build_upstream_selftests.BuildConfig(
        source_dir=source_dir,
        output_dir=tmp_path / "out",
        vmlinux_btf=tmp_path / "vmlinux",
        jobs="1",
        llvm_suffix="",
        host_python_bin="python3",
        arch="x86_64",
        cross_compile="",
        sysroot_root="",
        pkgconfig_libdir="",
        toolchain_dir=tmp_path / "toolchain",
        generated_include_dir=tmp_path / "generated",
        kernel_source_root=kernel_root,
    )
    selection = build_upstream_selftests.SelectionManifest(
        build_targets=("test_verifier",),
        source_excludes=("progs/drop.c", "prog_tests/drop_test.c"),
    )

    selected_dir = build_upstream_selftests.prepare_selected_source_dir(config, selection)

    assert selected_dir != source_dir
    assert (selected_dir / "keep.txt").read_text(encoding="utf-8") == "keep\n"
    assert (selected_dir / "progs" / "keep.c").read_text(encoding="utf-8") == "keep\n"
    assert not (selected_dir / "progs" / "drop.c").exists()
    assert not (selected_dir / "prog_tests" / "drop_test.c").exists()
    assert (selected_dir.parent / "net").is_symlink()
    assert (selected_dir.parents[3] / "include").is_symlink()
