# Native code now against the 2026-05-29 build

Operator 2026-11-15 ~22:59 UTC: "旧路线（编译过程里改写 IR，你后来禁止了）头文件路线 应该性能是一样的.  你要不要对比之前的版本?"

`compare_code.py` compares the executable sections (SHF_EXECINSTR PROGBITS, relocations unapplied) of every
`*.native.o` in the image payload `vendor/build/native-bpf/x86/stage/<app>` with the 2026-05-29 build kept at
`/workspaces/kprog-raw/paper-tree-untracked/vendor/build/native-bpf/x86/stage/<app>`, and Katran's timed
header-route object and the 2026-11-14 map-sink object with the 05-29 one. Output: `result.txt`.

Measured 2026-11-15T23:14:37Z:

- Katran balancer is byte-identical to 05-29 (xdp 7,965 B, .text 319 B); 3 of 4 Katran objects identical.
- BCC 7 of 8 identical (biosnoop 1,293 -> 1,307 B); Cilium 5 of 7 (bpf_xdp 23,964 -> 24,214 B, bpf_lxc same size, other bytes); OTel identical.
- Tracee 3 of 3 differ (1,615,175 -> 1,457,903 B); Tetragon's 88 objects are new after 05-29.
- The 2026-11-14 map-sink object (IR rewrite in the compile, removed on the operator's order) is 7,535 B and differs from 05-29.

So Katran's change from the 05-29 floor (1.113x, stats off) to about 1.03x comes after P: linker LTO, loader, kernel or the timing method.

## 2026-11-16: rebuilt on the header route, and what the flag set costs

Re-ran the comparison after rebuilding BCC, Cilium and OTel on the current header
route (`make -C vendor/bpf native-bcc|native-cilium|native-otel`, one flag set
from `vendor/bpf/Makefile:51`). Raw logs and pre-build checksums:
`/workspaces/kprog-raw/C/header-route-20261116/`.

Two corrections to the 2026-11-15 numbers above:

1. **`make native-otel` had not recompiled.** The 15 unit objects were from
   2026-11-15T06:06 under an older flag set; the target only re-ran `clang -r`
   over them, so the composite it installed was a relink, not a rebuild. After
   `rm` of the unit objects and a real recompile, OTel is **547,799 B** (not
   575,240 B identical): 1 of 30 executable sections is byte-identical to 05-29.
2. **Cilium's stage objects were the 2026-11-14 ones**, because the failed proof
   (`tail_ipv4_policy`, below) aborts the install step. The objects this build
   actually produced are at `vendor/build/native-bpf/x86/7.0.0-rc2+/native/cilium/`
   and compare as 4 of 7 identical: `bpf_host` 69,136 -> 69,056, `bpf_lxc`
   81,225 -> 81,110, `bpf_xdp` 23,964 -> 24,214; alignchecker, overlay, sock and
   wireguard identical.

### The size delta is the flag set, not the header route

05-29 compiled with three flags today's set does not have:
`-fno-jump-tables`, `-fno-optimize-sibling-calls`, `-mllvm
-switch-to-lookup=false` (plus `-DMICRO_NATIVE`). They were dropped in
`2f83ebd4b`. Measured by compiling the same source twice, flags otherwise
identical:

| source | today's set | `-fno-jump-tables` | `-mllvm -switch-to-lookup=false` | `-fno-optimize-sibling-calls` | `-DMICRO_NATIVE` |
|---|---|---|---|---|---|
| `otel/support/ebpf/native_stack_trace.ebpf.c` | 61,497 B | 62,701 B | 62,921 B | 61,497 B | 61,497 B |
| `cilium/bpf/bpf_host.c` (host options) | 69,056 B | — | — | — | **69,136 B = 05-29 byte-for-byte** |

So `bpf_host` reproduces the 05-29 object exactly once the three flags are back;
`-fno-optimize-sibling-calls` and `-DMICRO_NATIVE` change nothing here.
`bpf_lxc` with the same flags is the same size as 05-29 (81,225 B) but not the
same bytes, and `bpf_xdp` is 23,267 B against 05-29's 23,017 B either way —
those two still differ for a reason the flag set does not explain (the 05-29
build used `native_compat.h`, removed in `2f83ebd4b`, where today's uses
`core-compat.h` plus the BTF answers header, so the folded CO-RE reads can
differ per object).

The header route therefore matches the 05-29 codegen wherever the flag set is
restored; the operator's expectation that the two routes perform alike is not
contradicted by the objects, and the current size delta is a flag choice that
can be reversed in one line if it is wanted.

## 2026-11-16T08:46: re-run after the IR embedding

`vendor/bpf/Makefile` `b27e7c253` added `-Xclang -fembed-bitcode=all` to the one
flag set and rebuilt all six payloads. The comparison is unchanged, which is the
point of measuring it: an IR section must not move a single executable byte.

```
bcc: 7 of 8 code-identical, 8 001 -> 8 015 B
cilium: 4 of 7, 275 813 -> 275 868 B (bpf_xdp +250, bpf_host -80, bpf_lxc -115)
katran: 3 of 4, 9 887 -> 9 830 B (healthchecking 1 154 -> 1 097)
otelcol-ebpf-profiler: 0 of 1, 575 240 -> 547 799 B
tracee: 0 of 3, 1 615 175 -> 1 457 903 B
tetragon: only now, 88 objects
katran balancer vs 05-29: identical, .text 319 B, xdp 7 965 B
```

Identical to the 08:05 pre-flag numbers for every app, so embedding IR costs no
codegen. It also shows the comparison is stable across the rebuild rather than a
snapshot of one build's timestamps.

One correction to the breadth README, which quoted this table from memory as
"5 of 7 byte-identical, 276 063 now, only `bpf_xdp` grew": Cilium is **4 of 7**,
the total is **275 868**, and three objects differ — `bpf_xdp` +250 B,
`bpf_host` -80 B, `bpf_lxc` -115 B. Fixed in `db5ec653d`'s follow-up.
