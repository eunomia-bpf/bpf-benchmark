from __future__ import annotations

from pathlib import Path
import sys
import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import vm


def test_write_guest_script_applies_requested_nofile_limit() -> None:
    script_path = vm.write_guest_script(["true"], nofile=65536)
    try:
        contents = script_path.read_text()
    finally:
        script_path.unlink(missing_ok=True)

    assert "ulimit -HSn 65536" in contents


def test_build_vng_command_accepts_explicit_machine_contract() -> None:
    command = vm.build_vng_command(
        kernel_path=Path("vendor/linux-framework/arch/x86/boot/bzImage"),
        exec_path="/tmp/guest-script.sh",
        cpus=4,
        mem="8G",
        vm_executable=Path("runner/scripts/vng-wrapper.sh"),
        action="vm-test",
        machine_backend="vng",
        machine_lock_scope="vm_global",
        machine_name="x86-kvm",
        machine_arch="x86_64",
    )

    assert "--lock-scope" in command
    assert "--machine-name" in command
    assert "--backend" in command
    assert "--arch" in command
    assert "--target" not in command
    assert str(Path("runner/scripts/vng-wrapper.sh").resolve()) in command


def test_build_vng_command_requires_explicit_vng_backend() -> None:
    with pytest.raises(ValueError, match="only supports vng"):
        vm.build_vng_command(
            kernel_path=Path("vendor/linux-framework/arch/x86/boot/bzImage"),
            exec_path="/tmp/guest-script.sh",
            vm_executable=Path("runner/scripts/vng-wrapper.sh"),
            action="vm-test",
            machine_backend="ssh",
            machine_lock_scope="vm_global",
            machine_name="x86-kvm",
            machine_arch="x86_64",
        )


def test_build_vng_command_uses_explicit_machine_contract_only() -> None:
    command = vm.build_vng_command(
        kernel_path=Path("vendor/linux-framework/arch/x86/boot/bzImage"),
        exec_path="/tmp/guest-script.sh",
        vm_executable=Path("runner/scripts/vng-wrapper.sh"),
        action="vm-test",
        machine_backend="vng",
        machine_lock_scope="vm_global",
        machine_name="x86-kvm",
        machine_arch="x86_64",
    )

    assert "--target" not in command
    assert "--lock-scope" in command
    assert "--machine-name" in command
    assert "--backend" in command
