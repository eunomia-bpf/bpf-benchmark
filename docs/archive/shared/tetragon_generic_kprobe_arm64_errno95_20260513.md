# tetragon generic_kprobe ARM64 errno 95 root cause (2026-05-13)

## Verdict

The unsupported feature is ARM64 tail-call poke/update support for PROG_ARRAY direct-tail-call descriptors during `BPF_PROG_REJIT`; there is no userspace-only bytecode rewrite that makes noop ReJIT of the affected live tetragon tail-call targets succeed.

## Methodology

- Read `docs/kernel-jit-optimization-plan.md` once for project constraints.
- Used the ARM64 result at `corpus/results/aws_arm64_corpus_20260513_221545_067112/details/apps/tetragon__observer.json`.
- Used `bpfopt/testbin/tetragon_observer/*/input_step0.bin` and `output_step0.bin` for representative decoded bytecode. The noop step is byte-identical for sampled entries; for example `337_generic_kprobe_setup_event`, `338_generic_kprobe_process_event`, and `340_generic_kprobe_filter_arg` have matching input/output SHA256 pairs.
- Cross-referenced `corpus/build/tetragon/bpf_generic_kprobe.o` symbols to map the recurring generic-kprobe bytecode shapes (`setup_event`, `process_event`, `process_filter`, `filter_arg`, `actions`, `output`, `event`).
- Decoded raw `struct bpf_insn` fields from testbin binaries and checked helper IDs, pseudo-call source registers, map references, kfunc calls, kinsn calls, atomics, and MEMSX loads.
- Cross-referenced ARM64 JIT and `BPF_PROG_REJIT` kernel paths in `vendor/linux-framework`.

The ARM64 JSON truncates every generic kprobe BPF program name to `generic_kprobe_`, so full suffixes below are inferred by matching instruction-count/bytecode shape against testbin and the Tetragon object symbols.

## Bytecode diff

Representative decoded testbin shapes:

| Shape | ARM64 result behavior | insns | tail_call helper | bpf_loop | for_each_map_elem | dynptr helpers | bpf2bpf calls | kfunc calls | kinsn calls | atomics | MEMSX |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `337_generic_kprobe_setup_event` | ok shape | 255 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `341_generic_kprobe_event` | ok shape | 400 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| `338_generic_kprobe_process_event` | error shape | 3582 | 2 | 2 | 0 | 0 | 4 | 0 | 0 | 1 | 0 |
| `340_generic_kprobe_filter_arg` | error shape | 2109 | 3 | 0 | 0 | 0 | 19 | 0 | 0 | 0 | 0 |
| `342_generic_kprobe_actions` | mixed shape | 1021 | 1 | 0 | 0 | 0 | 3 | 0 | 0 | 4 | 0 |
| `343_generic_kprobe_output` | mixed shape | 380 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 2 | 0 |
| `344_generic_kprobe_process_filter` | mixed shape | 2174 | 1 | 1 | 0 | 0 | 0 | 4 | 0 | 1 | 0 |

What this rules out:

- Not `bpf_for_each_map_elem()` or dynptr helpers: sampled generic-kprobe shapes have zero.
- Not kinsn calls: sampled noop bytecode has zero `CALL src_reg=BPF_PSEUDO_KINSN_CALL`.
- Not MEMSX: sampled shapes have zero.
- Not atomics alone: some atomics pass, and the always-failing 2109-insn shape has none.
- Not kfunc calls alone: the kfunc-call process-filter shape has both ok and error outcomes.
- Not `bpf_loop()` alone: process-event uses it and fails, but process-filter uses it and has mixed ok/error outcomes.

The strongest negative evidence is that the same xlated bytecode-sized families have both outcomes in the ARM64 result:

| ARM64 fingerprint | ok | error |
| --- | ---: | ---: |
| `insns=380 bytes_xlated=3128` | 7 | 26 |
| `insns=1021 bytes_xlated=8752` | 13 | 20 |
| `insns=2174 bytes_xlated=17928` | 17 | 16 |

So the failure is not a pure target-bytecode instruction class. It depends on live PROG_ARRAY tail-call state: whether the program being ReJIT'd is currently a tail-call target whose callers have registered tail-call poke descriptors.

## Kernel-side error path

ARM64 JIT source has one explicit bytecode-adjacent `-EOPNOTSUPP` path at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1210-1214`: missing ARM64 kinsn native emit for `BPF_PSEUDO_KINSN_CALL`. The sampled noop bytecode has zero kinsn calls, so this does not match the tetragon noop failures.

The matching path is the ReJIT tail-call target repoke path:

- `vendor/linux-framework/kernel/bpf/verifier.c:24151-24179` rewrites `BPF_FUNC_tail_call` to `BPF_JMP | BPF_TAIL_CALL` and, when capable and not blinded/poisoned, creates a `BPF_POKE_REASON_TAIL_CALL` descriptor.
- `vendor/linux-framework/kernel/bpf/syscall.c:3332-3384` implements `bpf_prog_rejit_poke_target_phase()`, scans every `BPF_MAP_TYPE_PROG_ARRAY`, and calls `map->ops->map_poke_run()` when a map slot points at the program being ReJIT'd.
- `vendor/linux-framework/kernel/bpf/syscall.c:3832-3841` calls that target phase before and after swapping the JIT image.
- `vendor/linux-framework/kernel/bpf/arraymap.c:1153` calls `bpf_arch_poke_desc_update()` for matching stable tail-call poke descriptors.
- `vendor/linux-framework/kernel/bpf/arraymap.c:1101-1105` provides the weak default `bpf_arch_poke_desc_update()` that returns `-EOPNOTSUPP`.
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:4114-4160` implements `bpf_arch_poke_desc_update()` for x86. There is no corresponding ARM64 implementation in `vendor/linux-framework/arch/arm64`, so ARM64 uses the weak `-EOPNOTSUPP` default.

That matches errno 95 after a successful verifier pass: ReJIT verifies and JITs the candidate, then fails while trying to unpoke/repoke live direct tail-call edges for a PROG_ARRAY target.

## Userspace fix options

- **bpfopt avoidance:** No. The observed run is noop-only and `input_step0.bin == output_step0.bin` for sampled programs. Avoiding optimization sites does not avoid the kernel target repoke phase.
- **Daemon-side bytecode translation:** No robust userspace-only fix. Rewriting a target program's bytecode cannot change the caller programs' existing `poke_tab` descriptors. Rewriting caller tail calls to avoid descriptors would also break `bpf_prog_rejit_update_poke_tab()` shape matching against existing poke descriptors, and it changes tail-call lowering semantics in a live app.
- **Temporarily clearing/restoring PROG_ARRAY slots:** Not a valid benchmark framework fix. It mutates application map state, changes live behavior during the workload, races with the app, and still bypasses the real observed ReJIT contract.
- **Pass policy skip:** Not valid. Noop already fails, and skipping affected programs or adding per-app/per-program exclusions violates the no-ReJIT-filtering rule.
- **Kernel-side implementation:** An ARM64 `bpf_arch_poke_desc_update()` or a kernel ReJIT behavior change would address the kernel limitation in principle, but kernel patches are explicitly forbidden for this investigation.

## Recommendation

Document this as a known ARM64 ReJIT limitation for live PROG_ARRAY tail-call targets in tetragon generic kprobe chains. Keep recording the `errno 95` failures naturally in corpus results; do not add filters or pass-policy exclusions. For paper analysis, treat the failures as unsupported ARM64 tail-call-poke ReJIT cases rather than bpfopt noop/pass failures.
