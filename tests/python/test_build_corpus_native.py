from __future__ import annotations

from pathlib import Path

from runner.scripts import build_corpus_native


def test_ensure_cached_vmlinux_header_uses_explicit_btf(monkeypatch, tmp_path: Path) -> None:
    build_root = tmp_path / "build-root"
    build_root.mkdir(parents=True)
    vmlinux_btf = tmp_path / "vmlinux"
    vmlinux_btf.write_text("btf\n", encoding="utf-8")
    bpftool = tmp_path / "bpftool"
    bpftool.write_text("", encoding="utf-8")

    seen: list[list[str]] = []

    def fake_bpftool() -> Path:
        return bpftool

    class Result:
        returncode = 0
        stderr = ""

    def fake_run(command: list[str], *, stdout, stderr, text, check):  # type: ignore[no-untyped-def]
        seen.append(command)
        stdout.write("/* generated */\n")
        return Result()

    monkeypatch.setattr(build_corpus_native, "ACTIVE_BUILD_ROOT", build_root)
    monkeypatch.setattr(build_corpus_native, "ensure_vendor_bpftool", fake_bpftool)
    monkeypatch.setattr(build_corpus_native.subprocess, "run", fake_run)

    header = build_corpus_native.ensure_cached_vmlinux_header(vmlinux_btf)

    assert header == build_root / "_shared" / "vmlinux.h"
    assert header.read_text(encoding="utf-8") == "/* generated */\n"
    assert seen == [[str(bpftool), "btf", "dump", "file", str(vmlinux_btf), "format", "c"]]

    seen.clear()
    cached = build_corpus_native.ensure_cached_vmlinux_header(vmlinux_btf)
    assert cached == header
    assert seen == []


def test_locate_cached_vmlinux_header_prefers_explicit_btf(monkeypatch, tmp_path: Path) -> None:
    build_root = tmp_path / "build-root"
    (build_root / "bcc").mkdir(parents=True)
    stale = build_root / "bcc" / "vmlinux.h"
    stale.write_text("stale\n", encoding="utf-8")
    explicit = tmp_path / "explicit-vmlinux.h"
    explicit.write_text("fresh\n", encoding="utf-8")

    monkeypatch.setattr(build_corpus_native, "ACTIVE_BUILD_ROOT", build_root)
    monkeypatch.setattr(build_corpus_native, "ACTIVE_VMLINUX_BTF", tmp_path / "vmlinux")
    monkeypatch.setattr(build_corpus_native, "ensure_cached_vmlinux_header", lambda path: explicit)

    assert build_corpus_native.locate_cached_vmlinux_header() == explicit
