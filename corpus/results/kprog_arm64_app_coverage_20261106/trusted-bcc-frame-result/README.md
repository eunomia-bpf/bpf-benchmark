# tcplife trusted-extern compiler frame

The current trusted ARM worker compiles the real tcplife native entry, but the generated BPF still accesses `r10 - 584`. This confirms that changing to the trusted extern interface does not remove the prior frame-size blocker. This check does not submit a program to the kernel or establish verifier acceptance.

Reproduce through the repository result Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-bcc-frame-check
```

The checker opens the original arm64 tcplife BPF ELF with libbpf and uses its actual pre-load map shapes. All nine map/readonly symbols have matching names, section, offset, size and bytes in the native ELF. Readonly variables retain their exact direct-value offsets, including zero. These are preparation facts, not kernel-pinned runtime facts; the perf-event map's pre-load max_entries remains zero as reported by libbpf. Real admission must obtain the live facts from the common service.

`summary.json` records the inputs, symbol checks and largest disassembled frame offset. `compiler-inputs.tar.gz` contains both original ELF inputs, fresh native-link output, generated C/BPF, disassembly and compiler command logs. `compiler-check.log.gz` retains the complete successful check. `setup-failure.log` retains an initial harness output-directory collision, fixed before the successful run. The temporary build directory was removed after archival. No simulator/header, native input, kernel or active QEMU input was modified.
