# Kernel `BPF_PROG_JIT_RECOMPILE` Self-Tests

Build the suite with:

```sh
make -C tests/kernel
```

Run the tests with root privileges on the framework kernel:

```sh
sudo tests/kernel/build/test_recompile
```

Notes:

- The suite loads XDP programs with libbpf and invokes `BPF_PROG_JIT_RECOMPILE` directly.
- BPF policy blobs are created with `memfd_create()` and sealing, matching the kernel UAPI.
- The running kernel must include the BpfReJIT `BPF_PROG_JIT_RECOMPILE` implementation from `vendor/linux-framework`.
