C for R, BCC frozen-rodata P candidate. Native producer be9dee5a8d61d72f5d5b910dee0ff83a992e59de carries paired complete8-object BCC payloads under /var/tmp/kprog-tmp/C/bcc-readonly-config/{control,candidate}/bcc with full manifests. syscount native control f75d9ddc53bdd5484d1760f9b16b058ae133aa2f8831b07a058be649ae01465d equals the prior O3 ELF. Candidate d43869064ee2a5fe85f2000a01c8f6c4ac4bbf3c5409cba7a066b90905262977 specializes only six stable readonly config fields before P submission: measure_latency1; filter_cg/count_by_process/filter_failed/filter_errno/filter_pid0. Frozen9f3855f6f bcc_set.py selects syscount -L -i1; original syscount.c parser/defaults populate those same fields before libbpf load. P executable bytes540->233, instructions173->78, conditional branches23->6, RIP memory ops17->6; actual dynamic shares and throughput remain R observations. Other seven native objects preserve original bytes and every application program stays in the manifest.

Stage candidate *.native.o and manifest.json at /artifacts/user/native-bpf/x86_64/bcc/ in R's restored05-29 image, retain its existing phase/arm/stats controls, and use the existing target:

```sh
make -C /workspaces/repository __runtime-vm-corpus PLATFORM=kvm ARCH=x86 RUNTIME_CONTAINER_IMAGE="$R_IMAGE_WITH_C_P" SAMPLES=3 WORKLOAD_DURATION=180
```

The paired control payload and immutable raw.tar.gz provide the comparison and reproduction inputs. B uses the actual optimized P and source maps; kernel emission retains its existing same-copy path. R compares actual events/syscall work/BPF run counts and workload throughput against JIT. This payload binds the frozen configuration; a corresponding P compile carries another configuration. Original38 and full application/runtime outcomes retain their separate evidence.

Actual sys_enter/sys_exit service inputs from the running canonical cohort supply metadata for compiler replay. Current emitted-B compile exit0, completed entries[]. Exact public model source and all generated/compiler output accompany compiled-b.tar.gz.
