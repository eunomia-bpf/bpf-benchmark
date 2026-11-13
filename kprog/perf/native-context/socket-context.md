# Upstream socket-context compiler experiment

This optional host target compiles the unchanged
`vendor/repos/cilium/bpf/bpf_sock.c` with its upstream headers through the BPF
frontend. The same LLVM input produces a BPF object and, after context lowering,
an x86 native object. It does not select the runtime manifest or replace the
default native build.

```sh
make -f kprog/perf/native-context/Makefile socket-context-check socket-context-errors upstream-socket-proof
```

Outputs go to `/var/tmp/kprog-tmp/perf/socket-context`; retain evidence under
`/workspaces` before another experiment changes those outputs. The explicit
`UPSTREAM_SOCKET_FEATURES` argument controls frontend flags. Its current default
is an IPv4 compiler exercise, not the frozen running Cilium configuration. Match
the actual application's generated configuration before any application-level
comparison.

`socket-public-layout.c` reads Cilium's public context layout;
`socket-physical-layout.c` reads the sole kernel's BTF-generated header. Its
field rules mirror `sock_addr_convert_ctx_access` and
`bpf_sock_convert_ctx_access` in that kernel's `net/core/filter.c`, including
nested pointers, smaller physical fields and port-store truncation. Original
helper context pointers remain unchanged. The executable fixture catches
public-layout reads against physical storage, adjacent-field corruption,
nested socket access, and stale store-only function attributes.

Native retargeting preserves upstream memory barriers and turns configuration
symbol-address asm into opaque native address dependencies. Helper IDs become
named external calls using the linker's existing canonical names; map globals
retain symbol relocations for loader binding. These avoid branch-sensitive
helper-address inference and section-relative map-address folding.

The final target runs the existing linker's offline `proof` mode for every
cgroup entry and retains all outputs and diagnostics. This checks ELF/linker
integration; it neither submits programs to the verifier nor certifies program
behavior. No candidate from this experiment has run inside Cilium yet. Other
context kinds, CO-RE, the exact runtime configuration, original-program helper
target deployment, application decisions and timing remain part of P1j/P1h.
