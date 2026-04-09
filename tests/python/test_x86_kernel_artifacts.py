from __future__ import annotations

from pathlib import Path

from runner.libs import x86_kernel_artifacts


def test_stage_virtme_modules_rewrites_virtme_alias_tree(tmp_path: Path, monkeypatch) -> None:
    kernel_dir = tmp_path / "linux-framework"
    modules_root = kernel_dir / ".virtme_mods.tmp" / "lib" / "modules" / "7.0.0-test"
    alias_root = kernel_dir / ".virtme_mods.tmp" / "lib" / "modules" / "0.0.0"
    (kernel_dir / "include" / "config").mkdir(parents=True)
    (kernel_dir / "include" / "config" / "kernel.release").write_text("7.0.0-test\n", encoding="utf-8")
    hostfs_parent = modules_root / "kernel"
    for module in x86_kernel_artifacts.VIRTME_HOSTFS_MODULES:
        target = hostfs_parent / module
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(f"{module}\n", encoding="utf-8")
    alias_module = alias_root / "kernel" / "fs" / "netfs" / "netfs.ko"
    alias_module.parent.mkdir(parents=True, exist_ok=True)
    alias_module.symlink_to(Path("../../../../../../../fs/netfs/netfs.ko"))
    (alias_root / "build").symlink_to(Path("../../../.."))
    (alias_root / "source").symlink_to(Path("../../../.."))

    def fake_run(command: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
        assert command[:3] == ["make", "-C", str(kernel_dir)]
        assert command[-1] == "modules_install"

    monkeypatch.setattr(x86_kernel_artifacts, "_run", fake_run)

    x86_kernel_artifacts._stage_virtme_modules(kernel_dir)

    staged_root = kernel_dir / ".virtme_mods" / "lib" / "modules"
    copied_alias = staged_root / "0.0.0" / "kernel" / "fs" / "netfs" / "netfs.ko"
    copied_release = staged_root / "7.0.0-test" / "kernel" / "fs" / "netfs" / "netfs.ko"

    assert copied_alias.is_file()
    assert not copied_alias.is_symlink()
    assert copied_alias.read_text(encoding="utf-8") == "fs/netfs/netfs.ko\n"
    assert copied_release.read_text(encoding="utf-8") == "fs/netfs/netfs.ko\n"
    assert not (staged_root / "0.0.0" / "build").exists()
    assert not (staged_root / "0.0.0" / "source").exists()
