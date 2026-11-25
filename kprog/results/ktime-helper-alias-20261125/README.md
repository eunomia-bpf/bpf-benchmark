# B calls bpf_ktime_get_ns where P calls ktime_get_mono_fast_ns (coordinator, 2026-11-25)

Operator 2026-11-25T05:51Z: "别的包括之前的修了吗?"

## What failed

In the 11-25 checked-corpus recheck (/workspaces/kprog-raw/verified/checked-corpus-20261125-recheck) 16 requests
fell back to direct-native at generation with "unsupported unresolved call target": BCC 11, Katran 1, OTel 4.
Every one of them is a call to `ktime_get_mono_fast_ns` (R_X86_64_PLT32). P makes that call by its kernel name
since vendor/bpf/native-helpers.h bound bpf_ktime_get_ns to it (3aa496416, 2026-11-21); the B generator accepted
only `bpf_*` helper names (kprog/helper_abi.py is_helper_symbol), so each such program left the verified path.

## Change

kprog/helper_abi.py: `KERNEL_FUNCTION_HELPERS = {'ktime_get_mono_fast_ns': 'bpf_ktime_get_ns'}`, the same pairing
native-helpers.h states. kprog/x86/micro-prog/generate_micro_sim_proofs.py parse_asm_text maps a call
relocation through it, so B issues X86_OP_CALL_HELPER bpf_ktime_get_ns where P calls the function. The kernel's
bpf_ktime_get_ns body is `return ktime_get_mono_fast_ns();` (kernel/bpf/helpers.c), so the call B makes and the
call P makes return the same clock.

## Evidence

Offline full generation (`fullgen.py`: native-link, render, clang, llc; CPUs 16-23) on the archived requests,
work dir /workspaces/kprog-raw/coordinator/ktime-alias-20261125:

- before the change, BCC request 12 (sys_exit): `unsupported unresolved call target in call 3a <sys_exit+0x3a>`
  (before.log);
- after it, all 16: GENERATION OK (BCC 4, 7, 8, 12, 13, 14, 15, 19, 20, 23, 24; Katran 1; OTel 2, 12, 13, 14),
  each with its trusted_x86.bpf.o under out-*/.

The stock verifier's verdict on these B programs comes from the next checked-corpus run in the guest.

## Remaining generation case

Cilium's 31 generation refusals are `use of undeclared identifier 'jiffies_64'`: P reads jiffies_64 directly
(native-helpers.h's bpf_jiffies64) and B renders the address as X86_OP_MOV_LOAD_MAP_PTR(&jiffies_64). That case
went to OMP with this diagnosis (COORDINATION 2026-11-25T06:0xZ).

## Guest result (2026-11-25T09:47Z–09:51Z)

`make -C kprog/libnativeloader checked-corpus-all CHECKED_APPS='bcc/set katran'` on the image rebuilt from
840780870 (which restores `--results`), output /workspaces/kprog-raw/verified/checked-corpus-20261125-ktime2:
BCC 25 requests, **24** installed checked-sim-c, 1 fell back at verification, 0 failed (11-25 recheck: 14/25,
11 generation fallbacks). BCC finished at 09:51:05, before the class-G and jiffies change of
kprog/results/kernel-data-probe-read-20261125 reached the tree (09:51:47); Katran ran after it.
