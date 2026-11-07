# Complete pure micro suite on the current x86 producer

The common kernel-owned native-only service completes all29 workloads from
micro/config/micro_pure_jit.yaml on the adopted producer epoch. Each workload
has one fresh generated/compiled/verifier-accepted/bound request and one sample
per JIT and native_proof arm. All58 samples match their full64-bit expected
result and expected action; all29 request hashes match the kernel native bytes.

| Programs | Generated | Compiled | Accepted/bound | Failed | Matching samples |
| ---: | ---: | ---: | ---: | ---: | ---: |
|29|29|29|29|0|58/58|

Actual result: micro/results/x86_kvm_micro_20261107_215009_047184.
The run uses the existing8GiB/4vCPU guest on host20-23, SAMPLES=1,
WARMUPS=0, INNER_REPEAT=1. The recorded source epoch includes binary readonly
extraction, finite affine helper origins, consistent slot joins, wrapping RSP
LEA and provenance-selected partial writes. Launch source hashes retain their
exact values through collection; driver and collector each exit0. This
functional suite records matching results; R's timing recipe supplies runtime
performance measurements.

Command, using the retained driver and cached image:

```sh
taskset -c20-23 sh /workspaces/.agent-state/kprog-lanes/C/micro-wrapping-epoch/run.sh
```

run.sh invokes the repository make __runtime-vm-micro target through the
existing guest. runtime.json contains the command inputs, source hashes,
per-request native identities, and every result/action sample.
runtime-raw.tar.gz retains the actual result directory, driver, source snapshots,
kernel log and memory snapshot. runtime-service.tar.gz retains all29 terminal
request archives and fresh generated artifacts. runtime-driver.log.gz retains
the complete outer log. Universal ISA/token/link/binding laws supply the safety
argument, with these observations supporting the actual execution path.
