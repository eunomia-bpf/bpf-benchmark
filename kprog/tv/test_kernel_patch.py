"""Catch --batch auto-reversing an applied patch and partial conflict mutation."""
from pathlib import Path
import subprocess
import tempfile

from apply_kernel_patch import apply

here = Path(__file__).resolve().parent
base = subprocess.run(["git", "show", "HEAD:kernel/bpf/verifier.c"],
                      cwd=here.parents[1] / "vendor/linux-framework",
                      check=True, capture_output=True).stdout
patch = (here / "native-proof-regions.patch").read_bytes()
with tempfile.TemporaryDirectory() as directory:
    kernel = Path(directory)
    source = kernel / "kernel/bpf/verifier.c"
    source.parent.mkdir(parents=True)
    source.write_bytes(base)
    header = kernel / "include/linux/bpf.h"
    header.parent.mkdir(parents=True)
    header.write_bytes(subprocess.run(["git", "show", "HEAD:include/linux/bpf.h"],
        cwd=here.parents[1] / "vendor/linux-framework", check=True, capture_output=True).stdout)
    for name in ("include/linux/bpf_verifier.h", "kernel/bpf/core.c", "kernel/bpf/syscall.c", "arch/x86/net/bpf_jit_comp.c",
                 "arch/arm64/net/bpf_jit_comp.c"):
        target = kernel / name
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(subprocess.run(["git", "show", "HEAD:" + name],
            cwd=here.parents[1] / "vendor/linux-framework", check=True, capture_output=True).stdout)
    apply(kernel, patch)
    assert (kernel / "include/linux/bpf_native_input.h").read_bytes() == (
        here.parents[1] / "kinsn/module/include/native_lab_input.h").read_bytes()
    modified = source.read_bytes()
    assert modified != base
    assert b"env->allow_uninit_stack = false;" in modified
    apply(kernel, patch)
    assert source.read_bytes() == modified, "second apply reversed the kernel fix"
    conflict = modified.replace(b"if (op == BPF_EXIT) {", b"if (op == BPF_JA) {", 1)
    source.write_bytes(conflict)
    try:
        apply(kernel, patch)
    except SystemExit as error:
        assert "conflicts" in str(error)
    else:
        raise AssertionError("conflicting kernel source was accepted")
    assert source.read_bytes() == conflict, "conflict partially changed the source"
print("kernel patch idempotence/conflict regressions: PASS")
