# Map identity repair for x86 native helper lowering

The x86 linker previously assigned an unresolved native map call to the first unused source-BPF lookup site. Native and BPF compiler orders differ. Katran's actual IPv4 LRU lookup was therefore rewritten as a percpu-array lookup with1024 entries. The lookup key starts with33554442 (`0a000002`), so the generated bounds comparison always returns NULL. The IPv6 sibling instead has the expected raw hash call; the first trace's absence of that call did not mean the IPv4 branch was skipped.

`actual-jit-lookup.json` and the two full disassemblies identify the actual loaded code. Before: IPv4 operation PC0x1bc5 starts `mov eax,[rsi]; cmp eax,1024; jae ...`. Fixed: the corresponding operation PC0x1b8c calls the original `bpf_map_lookup_elem` at0xffffffff9b4b9730 for the invocation's kernel. The native JIT image shrinks10261->10151 bytes. These are observed live bytes, not pre-patch templates.

## Change

Unresolved lookup maps retain their original generic helper rather than borrowing another source call's type. Missing a real generic helper target still fails explicitly. The same ordinal/first-unused guessing is removed for update calls; an unknown or unmatched map keeps the original map_update_elem call. Identity-matched lowering remains active. This is a general linker correction, with no benchmark-name condition, program exclusion, native source/input change, simulator guard or verifier exception.

The production patch is `current-candidate.patch`, based on the published source in `source-head.txt`. The runtime comparison applies the same selection changes to the exact existing frozen CLI source, preserving its older ABI implementation and isolating this repair. The base CLI SHA256 is52c077fcbedde58c508ffa65fbfaad9df474f4af25e58462a6e8bf1f77722c87; the patched runtime CLI is5aacff95f0a881283a1e3ce57f22bbccf3540f4dd98f8052cda40dc6ae4cd6b8. Image/kernel/source/lockfile hashes are recorded in provenance.json. Unpublished shared ABI/partial-write/SP work is excluded from the commit.

## Validation

| Check | Result |
|---|---|
| Four new regressions against old published selector | all4 fail;79 existing pass |
| Patched published-source native-link suite |83pass,0fail |
| Patched frozen runtime-source native-link suite |81pass,0fail |
| Release runtime CLI build |success |

The regressions catch dynamic lookup misclassification/consumption of named sites, missing generic target silently borrowing another target, and dynamic/unmatched updates borrowing another map's specialization. All existing tests remain.

One actual guest on CPUs12-15/8GiB runs the old and fixed images sequentially, with the same frozen kernel and upstream Katran startup. Each row below is100 fresh TCP ACK/VIP packets, flags0, initially empty fallback LRU:

| Image | Arm | Lowering disabled | Misses | VIP packets |
|---|---|---:|---:|---:|
| before | JIT |0|1|100|
| before | native |0|100|100|
| before | native |1|1|100|
| fixed | JIT |0|1|100|
| fixed | native |0|1|100|
| fixed | native |1|1|100|

All six rows retain the same40-byte key/16-byte value(pos1), XDP_TX3,84 output bytes and FNV647f2ff540c87b52ba. Both images' native arms record1 replacement and0 failures. The fixed lowering-ON path now hits after the first packet. This is functional evidence; no CPU12-15 duration is used for performance comparison.

The same fixed image starts the full actual Tetragon application in both arms, waits for upstream event-reader readiness and completes10,000 opens plus10,000 closes per arm. Inventories are289 JIT and405 native-side resident programs. All118 native replacements complete with0 loader failures and the same replacement-symbol counts as the prior image (33 each generic event/setup/output,9 ret-output plus the other10). All before/after program counters and collector logs are retained. Metadata/background activity also contributes to these program deltas; no whole-app event-count equivalence, timing gain or verified-path completion follows from this cohort check. The comparison remains unbound native; generation-bound six-app closure is still pending.

## Commands and raw evidence

```
python3 corpus/results/kprog_app_coverage_20261107/map-identity-v1/prepare.py tests-only
make -f corpus/results/kprog_app_coverage_20261107/Makefile map-identity-tests
python3 corpus/results/kprog_app_coverage_20261107/map-identity-v1/prepare.py fixed
make -f corpus/results/kprog_app_coverage_20261107/Makefile map-identity-tests map-identity-linker map-identity-image
make -f corpus/results/kprog_app_coverage_20261107/Makefile map-identity-functional
```

Preparation uses the two frozen source copies under lane C state, with original inputs and complete sources in `sources-and-checks.tar.gz`. `actual-raw.tar.gz` contains every app log, loaded JIT dump, key/value snapshot, work/counter record and matching linked cache for the final comparison. `lookup-trace-attempts.tar.gz` retains all earlier raw traces and failures: FileIO append seeks on tracefs failed EINVAL twice, raw os.open/write succeeded in v3, and v4 retained the two-gate ambiguity failure. The final comparison uses the exact successful v3 tracing implementation. None of those harness failures is counted as a program/verifier rejection.

Performance remeasurement is held until R's BCC verified-arm guest on CPUs0-7 has run and exited, as the coordinator requires. Only then will the new image get the existing exclusive-CPU0 per-run profile. No new profile is currently queued.

The prepared `perf-map-identity-profile` target selects the tested fixed image for the next measurement. It has not been launched or queued; the R verified-arm reservation remains in force.
