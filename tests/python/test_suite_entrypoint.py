from __future__ import annotations

from pathlib import Path

from runner.libs.suite_entrypoint import SuiteEntrypoint


def test_runtime_env_sets_bcc_tools_dir_and_kvm_kernel_modules_root(tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    manifest_path = workspace / "run-contract.env"
    manifest_path.write_text("", encoding="utf-8")

    bcc_tools_dir = workspace / "corpus" / "build" / "bcc" / "libbpf-tools" / ".output"
    bcc_tools_dir.mkdir(parents=True)
    kernel_modules_root = workspace / "vendor" / "linux-framework" / ".virtme_mods" / "lib" / "modules" / "7.0.0-test"
    kernel_modules_root.mkdir(parents=True)
    tracee_lib_dir = workspace / "corpus" / "build" / "tracee" / "lib"
    tracee_lib_dir.mkdir(parents=True)

    contract: dict[str, str | list[str]] = {
        "RUN_TARGET_NAME": "x86-kvm",
        "RUN_SUITE_NAME": "corpus",
        "RUN_TARGET_ARCH": "x86_64",
        "RUN_EXECUTOR": "kvm",
        "RUN_REMOTE_PYTHON_BIN": "python3",
        "RUN_BPFTOOL_BIN": "bash",
        "RUN_WORKLOAD_TOOLS_CSV": "",
        "RUN_BCC_TOOLS_DIR": "corpus/build/bcc/libbpf-tools/.output",
        "RUN_NATIVE_REPOS_CSV": "tracee",
    }

    entrypoint = SuiteEntrypoint.from_contract(workspace, manifest_path, None, contract)
    env = entrypoint._runtime_env()

    assert env["BCC_TOOLS_DIR"] == str(bcc_tools_dir)
    assert env["BPFREJIT_KERNEL_MODULES_ROOT"] == str(workspace / "vendor" / "linux-framework" / ".virtme_mods")
    assert str(tracee_lib_dir) in env["LD_LIBRARY_PATH"].split(":")
