# B reads kernel memory through bpf_probe_read_kernel; jiffies_64 is a kernel datum (coordinator, 2026-11-25)

Operator 2026-11-25T05:51Z "别的包括之前的修了吗?", 09:48Z "也可以你来修一下一些东西".

## Cases

- Class G, "invalid mem access 'scalar'": 20 Tetragon and 9 Tracee requests of classfg-20261124T070800Z. B loads
  through a register whose tag is scalar (kernel memory reached through a pointer the verifier does not type).
  Classification per request: /workspaces/kprog-raw/coordinator/sa-20261125/class-g/classify-omp-five-20261120.txt.
- Cilium's 31 generation refusals of the 11-25 recheck, `use of undeclared identifier 'jiffies_64'`: P reads
  jiffies_64 through a GOT load (vendor/bpf/native-helpers.h's bpf_jiffies64), and the generator rendered every
  GOT load of a non-rodata, non-helper symbol as X86_OP_MOV_LOAD_MAP_PTR(&symbol), a map pointer B never declared.

## Change

1. kprog/x86/x86_sim_local_bpf.h (the class-G draft of /workspaces/kprog-raw/coordinator/sa-20261125/class-g):
   in the BPF build, a tagged load whose base tag is outside stack, ABI, packet, packet end, map pointer and map
   value reads through KPROG_X86_MEM_LOAD_FIXED, which is bpf_probe_read_kernel. Host and Clight builds read the
   same bytes directly. P's matching native loads carry the direct-native module's EX_TYPE_BPF fixup
   (kprog/perf/direct-native/bpf_x86_native_lab.c:131: skip the instruction, zero the destination), so a faulting
   address gives 0 on both sides, as bpf_probe_read_kernel gives.
2. kprog/helper_abi.py `KERNEL_DATA_SYMBOLS = {'jiffies_64'}`, the datum native-helpers.h reads; the x86 generator
   renders a GOT load of such a symbol as X86_OP_MOV_IMM of its address and declares it
   `extern const void jiffies_64 __ksym;`, which libbpf resolves from /proc/kallsyms. The following load reads
   it as kernel memory (change 1).

## Evidence so far

Offline full generation of Cilium request 12 (tail_handle_snat_fwd_ipv4), which failed with the undeclared
identifier: GENERATION OK (/workspaces/kprog-raw/coordinator/jiffies-20261125/out-cil-12). The stock verifier's
verdicts come from the Cilium, Tetragon and Tracee checked-corpus runs that follow; their counts go here.

## Cilium after the change (checked-corpus-20261125-kdata2, 11:29Z–11:39Z)

Cilium 64 requests: **19** installed checked-sim-c (recheck 16), 9 fell back at verification, 5 failed in
context-lower (OMP's 5a7fc6c8d, context-lower rebuilt 12:04Z after this run), and 31 fell back at
verification-preparation: the trusted loader refused B with "unbound trusted proof extern: jiffies_64". B now
declares jiffies_64 as an untyped ksym, and the loader bound only readonly data, trusted maps and kfuncs.
kprog/libnativeloader/src/native_loader_trusted.cpp now binds a BTF VAR of type void (an untyped ksym) to its
kallsyms address, as libbpf does, and asks kallsyms for the names in kKernelDataSymbols (jiffies_64). The
verifier statistics of the 19 accepted B: verification time median 969 us, max 3184 us; processed instructions
median 312, max 1355.

chain2.sh in this directory rebuilds kprog-ck/verified-loader once the kdata2 run (Tetragon, Tracee) has finished,
then reruns Cilium (checked-corpus-20261125-kdata3).

## Cilium kdata3 (13:27Z–13:38Z) and the modifier fix

Cilium 64 requests: **24** installed checked-sim-c, 9 fell back at verification, 0 failed (OMP's 5a7fc6c8d moved the
5 context-lower failures into the verified set). The 31 jiffies_64 requests still stopped at "unbound trusted proof
extern: jiffies_64": c0967c992 looked for a VAR of type 0, and clang declares `extern const void` as VAR -> CONST
(type 24) -> void. The loader now walks modifiers and typedefs down to void before taking the kallsyms address,
as libbpf decides an untyped ksym (libbpf's btf__resolve_type returns -EINVAL at void, so the walk is written out).
Checked on this request's B: VAR jiffies_64 -> type 24, kind CONST -> type 0. Verifier statistics of the 24 accepted
B: time median 1759 us, max 3211 us; processed instructions median 619, max 1355. chain4.sh rebuilds the verified
loader after kdata3 (Tetragon, Tracee) and reruns Cilium (checked-corpus-20261125-kdata4).

## Cilium kdata4 (15:20Z–15:31Z, verified loader with 2d308a86f)

Cilium 64 requests: **33** installed checked-sim-c (kdata3 24, kdata2 19, recheck 16). The "unbound trusted proof
extern: jiffies_64" refusals are gone: 9 jiffies_64 programs now install checked-sim-c, 17 reach the verifier and
5 (tail_handle_snat_fwd_ipv4 x3, tail_ipv4_policy x2) pass the verifier and fail in context-lower. The 26 verifier
rejections, by the line before "processed" in verify.stderr: 22 "R8 offset is outside of the packet" (a packet store
whose bounds check B does not carry to the verifier, e.g. `*(u8 *)(r8 +0) = r4` at off=22, r=0), 2 "only read is
supported", 2 "invalid mem access 'scalar'". Verifier statistics of the 33 accepted B: time median 2055 us, max
42660 us; processed instructions median 929, max 14369.

## Tetragon kdata4 (15:31Z–18:57Z)

Tetragon 83 requests: **33** installed checked-sim-c (classfg-20261124T070800Z: 13 of 85), 49 fell back at
verification, 1 at generation, 1 failed. Verifier rejections by the line before "processed": 34 "invalid write to
stack" (class F, B frame past 512 bytes), 12 "BPF program is too large" (over 1M processed instructions), 2
"invalid mem access 'scalar'" (class G, 20 on 11-24), 1 "sequence of jumps is too complex". Class G fell from 20
to 2 with the probe-read change. Verifier statistics of the 33 accepted B: time median 11086 us, max 19693 us;
processed instructions median 3570, max 7055.

## Cilium packet-bounds class, one case read (coordinator, 2026-11-25T20:2xZ)

tail_handle_ipv4_from_host, kdata4 request 12, verify.stderr: B reads the byte at packet offset 22 (the IPv4 TTL)
through a callee with `bpf_probe_read_kernel` on `pkt(off=22,r=0)`, then stores the decremented value with
`*(u8 *)(r8 +0) = r4` where r8 is `pkt(off=22,r=0)`; the verifier refuses the store ("invalid access to packet,
off=22 size=1 ... R8 offset is outside of the packet"). r=0 means no comparison with data_end reached this pointer in
B. P makes that comparison before the TTL update (Cilium's revalidate_data before ipv4_dec_ttl), so B lacks a
verifier-visible form of P's bounds check on this path. Most of the 22 are jiffies_64 programs that reached the
verifier for the first time in kdata4.

## Tracee kdata4 (18:57Z–02:0xZ)

Tracee 169 requests: **50** installed checked-sim-c (classfg-20261124T070800Z: 49), 114 fell back at verification, 5
at verification-preparation, 0 failed. Rejections: 98 "invalid write to stack" (class F), 10 "sequence of jumps is
too complex", 5 "source proof exceeds the BPF instruction limit" (the message of aef6e51ed), 2 + 1 ctx/sock type, 1
unbounded memory access, 1 too large. Class G "invalid mem access 'scalar'" (9 on 11-24) is gone. Verifier
statistics of the 50 accepted B: time median 892 us, max 461405 us; processed instructions median 342, max 110811.

## The five Cilium context-lower failures: one shape (omp 2026-11-26T08:5xZ)

All five fail with the same message from `kprog/build/socket-context-lower.cpp:168`,
`trusted_x86_x86_sim_xdp: dynamic public context offset`, and the installed compiler
reproduces it on the host:

```
context-lower <request>/generated/checked-simulator.linked.bc --public-layout ... --physical-layout ... -o out.bc
trusted_x86_x86_sim_xdp: dynamic public context offset
```

The pass walks every load and store, keeps the ones whose underlying object is the
function's first argument (`getUnderlyingObjects(Pointer)` contains `%0`), and then
requires `GetPointerBaseWithConstantOffset` to return `%0` itself. The offending
access has a run-time index:

```
%838 = getelementptr inbounds i8, ptr %0, i64 %812
%812 = add i64 %811, 8
%839 = load volatile i8, ptr %838, align 1
```

`%812` is a `switch` index built from the simulator's own stack addresses — the guest
x86 `movzx edi, WORD PTR [rax+0x8]` at `trusted_x86.bpf.c:805` (request 49) computes
its effective address as `ptrtoint(Packet) - ptrtoint(%78) + register`, and the
simulator adds that difference to `%0`. So the "context" pointer the pass sees is the
simulator's whole stack image addressed through the context argument, and the offset is
a run-time value that a constant-offset rule cannot name.

Two facts make this a bounded gap rather than a wrong-B defect:

- The verifier accepts all five. `verify.stderr` reports `processed` instructions and
  no rejection (e.g. request 16: `processed 81935 insns (limit 1000000)`), and
  `verify.stdout` records `{"phase":"verify","status":0}`; the failure is the checked
  simulator's context-lowering step, after B is proven.
- The five are the snat/fwd and policy tail-call targets (`tail_handle_snat_fwd_ipv4`
  ×3, `tail_ipv4_policy` ×2), so the class is one program family, not a scattering.

The recorded pass result stands: these five fall back to eBPF, which is what
`kdata4/run-codes.tsv` says. Widening the pass to rewrite a run-time context offset
would need a rule the current source does not have — `Match` is chosen by constant
`Offset` — and it is frozen, so the change belongs with whoever opens
`kprog/build/socket-context-lower.cpp`.
