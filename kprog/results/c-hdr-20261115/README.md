# C-HDR: compile flags and compat headers instead of IR rewriting, 2026-11-15

Three IR-rewriting steps are gone (`2f83ebd4b` removed the tools). This is what
replaced them, what it produces, and what it measures. Commits: `723a69562`
(the mechanism), `0f16b77f1` (Cilium's native branches), `986a88d15` (OTel's
compat header, empty tables).

Operator's route, restated: "不允许放进编译过程, 不是用头文件兼容吗" and
"编译参数所有 app 统一". Upstream source stays as upstream wrote it; differences
live in compile flags and `-include` headers; after that only the linker changes.

## 1. The three removed steps and what answers them now

| removed step | what it rewrote | what answers it now |
|---|---|---|
| `socket-context-lower` (Katran) | app IR | the app's own `SEC()` context struct, read directly by `-march=native` code |
| `core-ir-lower` (BCC, planned Tracee/Tetragon) | `bpf_core_*` calls in IR | `vendor/bpf/core-compat.h`, force-included, dispatching on each query's own pre-expansion text to an answer computed from the sole kernel's BTF |
| `native-ir-prep` | target features in IR | `NATIVE_ARCH_CFLAGS` in `vendor/bpf/Makefile` |

## 2. One flag set for every app

`vendor/bpf/Makefile:44-49`:

```
-O3 -g -c -fomit-frame-pointer $(NATIVE_ARCH_CFLAGS) -fno-stack-protector \
  -fno-asynchronous-unwind-tables -fno-unwind-tables \
  -Wno-unknown-attributes -Wno-compare-distinct-pointer-types
```

`NATIVE_ARCH_CFLAGS` = `-march=native -mno-red-zone -mgeneral-regs-only` on x86.
`-fPIC`, `-fno-jump-tables` and `-fno-optimize-sibling-calls` are removed: all
optimizations on, per the operator's hard requirement.

## 3. CO-RE answers come from the sole kernel's BTF, before the compile

The app's own `vmlinux.h` carries the *app's* offsets, not this kernel's, and
`__builtin_preserve_access_index` under a native target is an identity. Measured
on the one kernel (`bpftool btf dump file build-x86/vmlinux`):

| field | BCC's flavor header | this kernel |
|---|---:|---:|
| `request_queue.disk` | 0 (`___x`) | 96 |
| `bio.bi_bdev` | 0 | 8 |
| `block_device.bd_disk` | 0 | 16 |
| `task_struct.__state` | 0 | 192 |

That is exactly the defect recorded as P0/D03-D04: the image's native biosnoop
read `request+8` for a field at 96.

`vendor/bpf/core-answers.py` resolves every query and writes one table per app:

| app | queries | table |
|---|---:|---|
| bcc | 5 | `answers/bcc.h` |
| tracee | 46 | `answers/tracee.h` |
| tetragon | 28 | `answers/tetragon.h` |
| katran | 0 | `answers/katran.h` (no rule needs it) |
| cilium | 0 spec | — (only `bpf_core_relo` struct names) |
| otel | 0 | `answers/otel.h` |

Verified answers against `bpftool btf dump … format c`: bcc `b->bi_bdev`→1;
tetragon `sk->sk_protocol`→2 (`struct sock.sk_protocol` is `short unsigned int`,
so `sock.h`'s `>>8` shift is not taken), `pid->numbers[0]`→16, `mm->user_ns`→1,
all eight `nsproxy->*`→1, `task->audit`→0, `task->pids`→0;
tracee `kernel_cap_t`→8, `struct sockaddr_un`→110, `typeof(*bufs)`→40,
`typeof(*sig_actions)`→32, `struct pid_link`→0.

**The scan reads clang's JSON AST, not source text.** The same spelling names
different types in different translation units: `sk` is `struct bpf_sock *` in a
UAPI function pointer and `struct sock *` in a probe signature, and `skb` likewise.
A text declaration map resolved `skb->active_extensions` to 0 in
`bpf_generic_retuprobe.c` and 1 in `bpf_generic_tracepoint.c`, and
`sk->sk_protocol` to 0 instead of 2. The base type now comes from the compiler's
own name lookup, and the member chain from its `MemberExpr` nodes (reversed to
base-outward, anonymous members skipped, which BTF descends). A query text that
resolves differently in two units is a hard error, never a guess.

A query without an entry calls `__kprog_core_unanswered()`, declared
`__attribute__((error(…)))`: the compile fails. Never a default. This is what
caught the six missing tetragon variant queries. `__builtin_choose_expr` does not
work here; the dispatch is `__builtin_strcmp` on the stringified query.

## 4. Vendored sources: `unifdef -U` kept the eBPF arm of split blocks

`2f83ebd4b` deleted the native arm of every `#ifdef MICRO_NATIVE` block, which
also left the *eBPF* text in the native compile: BPF-register asm (`call 8` with
"r0".."r5"), rodata-symbol asm (`%[size] = …`, `"%0 = CONFIG_x ll"`) and
`goto` around `%[size]`. Each affected block is now split on `#ifdef __bpf__`
(clang defines it only for the bpf target), so the eBPF text is unchanged.

| app | files changed | `#ifdef __bpf__` splits |
|---|---:|---:|
| tetragon | 13 | 13 |
| tracee | 3 | 6 |
| cilium | 6 | 15 |

Cilium also needed its native `struct __sk_buff` back (kernel entry ABI: `len`
112, `data_len` 116, `data` 208 …, from `linux/bpf.h`), and
`overloadable_skb.h`'s `#ifndef MICRO_NATIVE` guard, which an `-U` sweep deletes
the body of (the native struct has no `tc_classid`).

## 5. Acceptance: BCC biosnoop is instruction-identical to the proven reference

`bcc/libbpf-tools/biosnoop.bpf.c` compiled through the Makefile matches
`/var/tmp/carve/native-bcc/biosnoop.native.o` on `block_rq_complete`,
`block_rq_issue`, `block_rq_insert` and `blk_account_io_merge_bio`, except the
map-pointer materialisation form (reference `movq (%rip),%rax; movq $0x0,(%rax)`
vs `movq $0x0,(%rip)`, one instruction shorter per site) — a linker-side detail.

## 6. The table drives the code, and an uncovered query fails

- Flipping `task->thread_pid` from 1 to 0 in the table changes
  `bpf_fork.o`'s disassembly (9 446 320 → 9 456 280 bytes of text); the table is
  what decides.
- Removing the `task->thread_pid` entry makes the compile fail on the TU that
  asks it (`bpf_execve_event.c`).

## 7. Build state, all six apps compile

| app | objects | link |
|---|---:|---|
| katran | 4 | 4/4 `proof.ok` |
| bcc | 8 (+1 staged cf. 9 in image) | 8/8 `proof.ok` |
| cilium | 7 | 7/7 `proof.ok` |
| otel | 16 | stops: jump-table relocations (see §9) |
| tracee | 1 (+3 LSM) | stops: linker |
| tetragon | 88 | stops: linker |

Object sizes against the pre-`2f83ebd4b` reference
(`native-bpf/x86/7.3.0-070300rc3-generic/native/`), text bytes:

| app | new | old | change |
|---|---:|---:|---:|
| katran | 9 709 | 9 879 | −1.7% |
| bcc | 7 902 | 8 000 | −1.2% |
| cilium | 270 476 | 275 379 | −1.8% |

## 8. Code size against the JIT — the hard requirement is **not** met

`native` is the program's own text section; `jit` is the same program's
`jited_prog_len` from the same guest run
(`/workspaces/kprog-raw/C/limits/<app>/baseline.jit-lines.json`).

| app | programs | native | JIT | native/JIT |
|---|---:|---:|---:|---:|
| katran `balancer_ingress` | 1 | 7 857 | 13 641 | **0.576** |
| bcc `biosnoop` | 4 | 1 271 | 1 352 | 0.940 |
| tracee | 19 matched | 274 487 | 270 257 | 1.016 |

Per BCC program: `block_rq_issue` 0.864, `block_rq_complete` 1.030,
`block_rq_insert` 0.912, `blk_account_io_merge_bio` 0.975.

Katran is close to the paper's 0.54x; BCC and Tracee are not, and the
requirement is "native code size ≈ half the JIT's" for **every** app. Tracee's
tail-call programs are *larger* than their JIT: `lkm_seeker_modtree_loop_tail`
1.330, `lkm_seeker_proc_tail` 1.146, `lkm_seeker_kset_tail` 1.103. BCC's object
is only 8 programs against 21 JIT programs in the capture (partial pairing), so
its 0.940 is a subset, not an app total.

Not yet measured: OTel (`phase-profile.log` only) and Tetragon (same), and
Cilium has no capture in `limits/`. Cilium's `bpf_lxc` is a fair proxy from the
object alone: 75 922 new vs 81 075 old text bytes.

## 9. What blocks the remaining apps: the linker

PERF's `native-link` stops on:

1. **jump-table relocations** (OTel, consequence of removing `-fno-jump-tables`).
   `kprobe_unwind_hotspot` at 0x1560 is `leaq (%rip),%rcx` with reloc
   `R_X86_64_PC32 .rodata-0x4`, addend 0, **no symbol**; 0x1567
   `movslq (%rcx,%rax,4),%rdx`; 0x156b `addq %rcx,%rdx`; 0x1573 `jmpq *%rdx`.
   Four per symbol. Because the reloc names the bare section,
   `x86_readonly_relocs::control_targets()` returns an empty map, so
   `x86_helper_provenance::analyze()` fans every `IndirectBranch` out to all
   instructions, wiping register state at four points. 59 of OTel's 2 504
   indirect call sites then resolve. Verified directly against `a7383af15`.
2. **`.data.rel.ro` section spans** — pointer-initialised read-only tables
   (`R_X86_64_64` to real symbols) that the linker cannot slice per symbol.

Both are posted to `COORDINATION.md` with the byte-level evidence.

## 10. Timing

Not run in this window: CPUs 0-7 belong to the timing lock and the full six-app
round is the coordinator's freeze measurement. The per-call tables in
`kprog/results/limits-20261114/` are from the previous (pre-C-HDR) native
objects; they must be re-measured once the linker accepts the remaining three
apps, since the compile changed.