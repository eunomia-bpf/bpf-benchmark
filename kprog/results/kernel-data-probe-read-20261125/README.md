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
