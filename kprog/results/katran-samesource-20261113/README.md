# Katran from untouched upstream source (C5)

What this records: Katran's native objects can be built from the **unmodified upstream
source**, with the one behaviour-changing difference — the XDP/TC context layout — moved out
of the source and into a lowering step, and two of the three shipped programs come out
byte-identical to what the image ships today.

## The difference that mattered

Katran's three manifest programs read exactly four context fields:

| program | section | fields |
|---|---|---|
| `balancer_ingress` | `xdp` | `data`, `data_end` |
| `healthcheck_encap` | `tc` | `mark` (and `len`) |
| `xdp_root` | `xdp` | none |

The eBPF arm compiles against the UAPI mirror (`struct xdp_md` with `__u32 data; __u32
data_end; ...`, `struct __sk_buff` with `__u32 len; ... __u32 mark;`), and the kernel
converts each field access to a load from the physical struct
(`net/core/filter.c: xdp_convert_ctx_access`, `skb_convert_ctx_access`). A native build
must make the same conversion, because at run time the register holds the physical
`struct xdp_buff *` / `struct sk_buff *`.

Today's native object does it by redefining both structs under `#ifdef MICRO_NATIVE` inside
`vendor/bpf/katran/katran/lib/linux_includes/bpf.h`. Compiling the untouched upstream
sources with the same native flags instead gives the mirror offsets:

| program | shipped (physical) | untouched source, direct |
|---|---|---|
| `balancer_ingress` | `mov (%rdi),%r12 ; mov 0x8(%rdi),%r15` | `mov (%rdi),%r12d ; mov 0x4(%rdi),%r15d` |
| `healthcheck_encap` | `mov 0xa8(%rdi),%eax` | `mov 0x8(%rdi),%eax` |

## The route

1. Frontend = the eBPF arm's own (`vendor/Makefile:32` verbatim: host-target IR, then
   `llc -march=bpf` in that arm), on untouched upstream source and headers, with `-fPIC`
   added (`-fPIC` is what keeps the `.maps` globals non-`dso_local`, which is what makes
   the map reference lower to a `GOTPCRELX` load — the form the loader patches — instead of
   a `PC32` address):

       clang-18 -I<katran> -I<katran>/katran/lib/linux_includes -DDEBUG -D__KERNEL__ \
         -Wno-unused-value -Wno-pointer-sign -Wno-compare-distinct-pointer-types \
         -O2 -emit-llvm -c -g -fPIC <upstream .c> -o x.bc

2. `kprog/perf/native-context/build-x86/socket-context-lower` (lane perf's tool), driven by
   lane perf's own `packet-public-layout.json` / `packet-physical-layout.json`
   (`make -f kprog/perf/native-context/Makefile packet-context-check`, commit 1f74ce814;
   lane perf chose route (b) at 2026-11-13T08:11:30Z, so none of their files are edited
   here). Those tables cover the fields Katran needs with the same offsets mine did. The
   tool replaces each public context access with the physical one, using exactly the
   verifier's conversion:

       balancer.bc          -> 14 accesses lowered
       healthchecking_ipip  -> 4
       xdp_root             -> 0

   `public-layout.json` / `physical-layout.json` here are the tables it was given, copied
   verbatim from lane perf's packet-context build. Public offsets come from the untouched
   UAPI header; physical offsets from the sole kernel's BTF (`xdp_buff.data` 0, `data_end`
   8, `data_meta` 16; `sk_buff.len` 112, `mark` 168).

3. x86 codegen. Two details matter for native and both are in the command:

   * the IR carries `"target-features"="+sse,+sse2"`, which overrides
     `-mgeneral-regs-only` and makes `llvm.memset`/`memcpy` expand to `movdqa`/`pxor`
     (~82 SSE instructions). Native code stays SIMD-free (todo S14), so the attribute is
     stripped before codegen. The shipped object has 0 SSE instructions.
   * the target triple is overridden to `x86_64-linux-gnu`, as the socket experiment does.

## Result

Linked with the tree's `native-link --mode proof`, against the shipped objects:

| program | shipped | from untouched source | |
|---|---|---|---|
| `healthcheck_encap` | 1360 B | 1360 B | **byte-identical** |
| `xdp_root` | 888 B | 888 B | **byte-identical** |
| `balancer_ingress` | 11176 B | 11000 B | context loads identical; 1567 differing instruction lines |

For `balancer_ingress` the differing lines are scheduling/register-allocation differences of
the IR round trip (`mov $0x1,%eax; call *%rax` vs `mov $0x1,%r13d; call *%r13`, retimed
adds, and the branch displacements that follow), not context accesses: the first two
instructions are the same physical loads as shipped.

Also checked, and it matters for the same-source rule: compiling the three objects
**directly** against the untouched upstream headers with the native flags gives code sections
identical in size to the shipped ones (balancer 448/448, healthchecking_ipip 128/128,
xdp_root 128/128 AX bytes) and differs only in `.debug_str`/`.debug_str_offsets`. So for
Katran the only real source-level difference is the context struct, and the other two files
the source audit lists (`healthchecking.c`, `healthchecking_helpers.h`) are not in the
shipped manifest at all.

## Not yet done

- A `vendor/bpf/Makefile` rule with the switch (default build byte-identical) — waits on the
  rule-table question in COORDINATION with lane perf, whose tool this is.
- A functional guest run comparing both arms' packet counts and drops.