from __future__ import annotations

from pathlib import Path

from runner.libs import vm


def test_build_vng_command_invokes_python_wrappers_via_host_python(tmp_path: Path) -> None:
    kernel = tmp_path / "bzImage"
    kernel.write_text("kernel\n", encoding="utf-8")
    wrapper = tmp_path / "vng-wrapper.py"
    wrapper.write_text("#!/usr/bin/env python3\n", encoding="utf-8")

    command = vm.build_vng_command(
        kernel_path=kernel,
        exec_path="/tmp/guest.sh",
        cpus=2,
        mem="4G",
        vm_executable=wrapper,
        action="vm-corpus",
        machine_backend="vng",
        machine_lock_scope="vm_global",
        machine_name="x86-kvm",
        machine_arch="x86_64",
    )

    lock_sep = command.index("--")
    wrapped = command[lock_sep + 1 :]
    assert wrapped[:2] == [vm.sys.executable, str(wrapper)]
    assert "--run" in wrapped
