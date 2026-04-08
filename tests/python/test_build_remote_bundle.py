from __future__ import annotations

import json
import subprocess
from pathlib import Path

from runner.libs import aws_local_prep, build_remote_bundle


def _git(repo: Path, *args: str) -> str:
    completed = subprocess.run(
        ["git", *args],
        cwd=repo,
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    return completed.stdout


def test_copy_git_snapshot_seals_sparse_checkout(tmp_path: Path) -> None:
    source = tmp_path / "source"
    source.mkdir()
    _git(source, "init")
    _git(source, "config", "user.email", "test@example.com")
    _git(source, "config", "user.name", "Test User")
    (source / "keep").mkdir()
    (source / "excluded").mkdir()
    (source / "keep" / "a.txt").write_text("keep\n", encoding="utf-8")
    (source / "excluded" / "b.txt").write_text("excluded\n", encoding="utf-8")
    _git(source, "add", ".")
    _git(source, "commit", "-m", "init")

    sparse = tmp_path / "sparse"
    _git(tmp_path, "clone", str(source), str(sparse))
    _git(sparse, "sparse-checkout", "init", "--cone")
    _git(sparse, "sparse-checkout", "set", "keep")
    assert (sparse / "keep" / "a.txt").is_file()
    assert not (sparse / "excluded" / "b.txt").exists()

    dest = tmp_path / "snapshot"
    build_remote_bundle._copy_git_snapshot(sparse, dest)

    assert (dest / "keep" / "a.txt").read_text(encoding="utf-8") == "keep\n"
    assert (dest / "excluded" / "b.txt").read_text(encoding="utf-8") == "excluded\n"


def test_write_bundle_manifest_pins_katran_runtime_to_staged_native_tree(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=e2e",
                "RUN_TARGET_ARCH=x86_64",
                "RUN_NEEDS_KATRAN_BUNDLE=1",
                "",
            ]
        ),
        encoding="utf-8",
    )
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(json.dumps({}) + "\n", encoding="utf-8")
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")

    bundle_dir.mkdir()
    builder.write_bundle_manifest()
    rendered = (bundle_dir / "run-contract.env").read_text(encoding="utf-8")

    assert "RUN_KATRAN_SERVER_BINARY=corpus/build/katran/bin/katran_server_grpc" in rendered
    assert "RUN_KATRAN_SERVER_LIB_DIR=corpus/build/katran/lib" in rendered


def test_write_bundle_manifest_pins_bcc_tools_dir_to_staged_native_tree(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=corpus",
                "RUN_TARGET_ARCH=x86_64",
                "RUN_NATIVE_REPOS_CSV=bcc",
                "",
            ]
        ),
        encoding="utf-8",
    )
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(json.dumps({}) + "\n", encoding="utf-8")
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")

    bundle_dir.mkdir()
    builder.write_bundle_manifest()
    rendered = (bundle_dir / "run-contract.env").read_text(encoding="utf-8")

    assert "RUN_BCC_TOOLS_DIR=corpus/build/bcc/libbpf-tools/.output" in rendered


def test_stage_target_runtime_keeps_arm64_daemon_wrapper_on_execution_path(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=corpus",
                "RUN_TARGET_ARCH=arm64",
                "RUN_NEEDS_DAEMON_BINARY=1",
                "RUN_NEEDS_RUNNER_BINARY=0",
                "",
            ]
        ),
        encoding="utf-8",
    )
    wrapper = tmp_path / "bpfrejit-daemon"
    real = tmp_path / "bpfrejit-daemon.real"
    runtime_lib_dir = tmp_path / "lib"
    wrapper.write_text("#!/usr/bin/env bash\nexec \"$0.real\" \"$@\"\n", encoding="utf-8")
    wrapper.chmod(0o755)
    real.write_text("arm64-binary\n", encoding="utf-8")
    runtime_lib_dir.mkdir()
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(
        json.dumps(
            {
                "ARM64_CROSS_DAEMON": str(wrapper),
                "ARM64_CROSS_DAEMON_REAL": str(real),
                "ARM64_CROSS_LIB_DIR": str(runtime_lib_dir),
            }
        )
        + "\n",
        encoding="utf-8",
    )
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")
    bundle_dir.mkdir()

    builder.stage_target_runtime()

    assert (bundle_dir / "daemon" / "target" / "release" / "bpfrejit-daemon").read_text(encoding="utf-8") == wrapper.read_text(encoding="utf-8")
    assert (bundle_dir / "daemon" / "target" / "release" / "bpfrejit-daemon.real").read_text(encoding="utf-8") == "arm64-binary\n"


def test_arm64_prepare_test_outputs_passes_arch_specific_llvm_suffix(monkeypatch, tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    local_state = tmp_path / "local-state.json"
    remote_state = tmp_path / "remote-state.json"
    remote_state.write_text("{}\n", encoding="utf-8")
    prep = aws_local_prep.AWSPrep(
        env={
            "RUN_TOKEN": "run.aws-arm64.test.llvm",
            "RUN_TARGET_NAME": "aws-arm64",
            "RUN_TARGET_ARCH": "arm64",
            "RUN_HOST_PYTHON_BIN": "python3",
            "RUN_TEST_MODE": "negative",
            "RUN_UPSTREAM_SELFTEST_LLVM_SUFFIX": "-20",
        },
        manifest_path=manifest,
        local_state_path=local_state,
        remote_prep_state_path=remote_state,
    )
    seen: dict[str, str] = {}

    def fake_run_host_python_module(module: str, mode: str, **extra_env: str) -> None:
        seen["module"] = module
        seen["mode"] = mode
        seen["llvm_suffix"] = extra_env.get("ARM64_UPSTREAM_SELFTEST_LLVM_SUFFIX", "")
        seen["legacy_suffix"] = extra_env.get("UPSTREAM_SELFTEST_LLVM_SUFFIX", "")

    monkeypatch.setattr(prep, "_run_host_python_module", fake_run_host_python_module)
    monkeypatch.setattr(aws_local_prep, "require_file_contains", lambda *args, **kwargs: None)

    prep.prepare_test_outputs()

    assert seen["module"] == "runner.libs.arm64_host_build"
    assert seen["mode"] == "repo-tests"
    assert seen["llvm_suffix"] == "-20"
    assert seen["legacy_suffix"] == ""


def test_stage_scx_wraps_arm64_scheduler_binary(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=corpus",
                "RUN_TARGET_ARCH=arm64",
                "RUN_SCX_PACKAGES_CSV=scx_rusty",
                "",
            ]
        ),
        encoding="utf-8",
    )
    binary_root = tmp_path / "scx-bin"
    object_root = tmp_path / "scx-obj"
    binary_root.mkdir()
    object_root.mkdir()
    (binary_root / "scx_rusty").write_text("arm64-scx\n", encoding="utf-8")
    (binary_root / "scx_rusty").chmod(0o755)
    (object_root / "scx_rusty_main.bpf.o").write_text("obj\n", encoding="utf-8")
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(
        json.dumps(
            {
                "ARM64_SCX_BINARY_ROOT": str(binary_root),
                "ARM64_SCX_OBJECT_ROOT": str(object_root),
            }
        )
        + "\n",
        encoding="utf-8",
    )
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")
    bundle_dir.mkdir()

    builder.stage_scx()

    wrapper = bundle_dir / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty"
    wrapped_binary = bundle_dir / "runner" / "repos" / "scx" / "target" / "release" / "scx_rusty.bin"
    assert "ld-linux-aarch64.so.1" in wrapper.read_text(encoding="utf-8")
    assert wrapped_binary.read_text(encoding="utf-8") == "arm64-scx\n"


def test_stage_kvm_kernel_module_tree_copies_virtme_modules(monkeypatch, tmp_path: Path) -> None:
    fake_root = tmp_path / "repo"
    modules_root = fake_root / "vendor" / "linux-framework" / ".virtme_mods" / "lib" / "modules" / "7.0.0-test"
    modules_root.mkdir(parents=True)
    (modules_root / "modules.dep").write_text("test\n", encoding="utf-8")
    monkeypatch.setattr(build_remote_bundle, "ROOT_DIR", fake_root)

    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=corpus",
                "RUN_TARGET_ARCH=x86_64",
                "RUN_EXECUTOR=kvm",
                "",
            ]
        ),
        encoding="utf-8",
    )
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(json.dumps({}) + "\n", encoding="utf-8")
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")
    bundle_dir.mkdir()

    builder.stage_kvm_kernel_module_tree()

    copied = bundle_dir / "vendor" / "linux-framework" / ".virtme_mods" / "lib" / "modules" / "7.0.0-test" / "modules.dep"
    assert copied.read_text(encoding="utf-8") == "test\n"


def test_stage_native_repo_build_dirs_keeps_tracee_binary_unwrapped(tmp_path: Path) -> None:
    manifest = tmp_path / "run-contract.env"
    manifest.write_text(
        "\n".join(
            [
                "RUN_SUITE_NAME=corpus",
                "RUN_TARGET_ARCH=x86_64",
                "RUN_NATIVE_REPOS_CSV=tracee",
                "",
            ]
        ),
        encoding="utf-8",
    )
    native_root = tmp_path / "native"
    tracee_bin_dir = native_root / "tracee" / "bin"
    tracee_bin_dir.mkdir(parents=True)
    tracee_binary = tracee_bin_dir / "tracee"
    tracee_binary.write_text("tracee\n", encoding="utf-8")
    tracee_binary.chmod(0o755)
    bundle_inputs = tmp_path / "bundle-inputs.json"
    bundle_inputs.write_text(json.dumps({"X86_NATIVE_BUILD_ROOT": str(native_root)}) + "\n", encoding="utf-8")
    bundle_dir = tmp_path / "bundle"
    builder = build_remote_bundle.BundleBuilder(manifest, bundle_inputs, bundle_dir, tmp_path / "bundle.tar.gz")
    bundle_dir.mkdir()

    builder.stage_native_repo_build_dirs()

    staged_binary = bundle_dir / "corpus" / "build" / "tracee" / "bin" / "tracee"
    assert staged_binary.read_text(encoding="utf-8") == "tracee\n"
    assert not staged_binary.with_name("tracee.bin").exists()
