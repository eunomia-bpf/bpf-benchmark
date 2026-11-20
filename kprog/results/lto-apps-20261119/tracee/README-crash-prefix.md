# Tracee re-run on the pre-3b5fa4b40 image: full coverage, then a guest panic

Re-run started 2026-11-20T16:51:34Z after the base loader was rebuilt (run
x86_kvm_corpus_20261120_165324_723747, recipe `APP=tracee/monitor`, 3 x 180 s per arm, stats on). The post arm
installed **169 of 169** programs (`native-loader replaced prog=` 169 times), then the guest died:

```
[ 5870.276824] BUG: unable to handle page fault for address: ffffd391900d6398
[ 5870.278402] #PF: supervisor write access in kernel mode
[ 5870.287186] RIP: 0010:bpf_trace_run2+0xb9/0x1d0
[ 5870.281016] CPU: 2 ... PID: 14108 Comm: tracee
```

That is the same oops the coordinator isolated
(`kprog-raw/coordinator/tracee-crash-20261120T163726Z`): register RBX holds the program's ctx argument after the
program returned, which is 0e4f2da6f's gs-load form for `get_current_task(_btf)`/`get_smp_processor_id`. Fixed
forward in 3b5fa4b40 (named helper calls again). This run predates that commit, so it measures the loader fix
only and ends in the known crash; the arm is re-run on the 3b5fa4b40 image.

What it does establish: with the base loader rebuilt, Tracee's coverage is **169 of 169** (against 29 of 169
before), so the `current_task`/`cpu_number` GOT failures are gone. `make` reports Error 255 from the panic.

Raw: /workspaces/kprog-raw/omp/lto-tracee-crash-20261120T1653Z (run log and the crashed run's details).
