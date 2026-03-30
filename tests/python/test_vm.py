from __future__ import annotations

from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from runner.libs import vm


def test_write_guest_script_applies_requested_nofile_limit() -> None:
    script_path = vm.write_guest_script(["true"], nofile=65536)
    try:
        contents = script_path.read_text()
    finally:
        script_path.unlink(missing_ok=True)

    assert "ulimit -HSn 65536" in contents


def test_build_vm_shell_command_forwards_requested_nofile_limit() -> None:
    command = vm.build_vm_shell_command(
        kernel_image=Path("vendor/linux-framework/arch/x86/boot/bzImage"),
        command_text="true",
        timeout_seconds=30,
        vng_binary="runner/scripts/vng-wrapper.sh",
        nofile=65536,
    )

    assert "--nofile" in command
    nofile_index = command.index("--nofile")
    assert command[nofile_index + 1] == "65536"
