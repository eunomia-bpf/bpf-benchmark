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
