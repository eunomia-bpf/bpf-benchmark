## Error origin (daemon code location)

The direct error is in `daemon/src/bpf.rs:87-90`:

```rust
pub(crate) fn probe_target_json(targets: &[KinsnProbeTarget]) -> Result<TargetJson> {
    if targets.is_empty() {
        bail!("target probing requested with no kinsn targets");
    }
```

The per-program wrapper text comes from `daemon/src/commands.rs:521-523`, inside `run_program_steps()`:

```rust
if referenced.contains(VAR_TARGET) {
    let probed = bpf::probe_target_json(kinsn_probes)
        .with_context(|| format!("probe target kinsns for prog {prog_id}"))?;
```

So the full corpus error:

```text
probe target kinsns for prog X: target probing requested with no kinsn targets
```

means `run_program_steps()` decided a target file was needed, but the daemon socket request carried an empty `kinsn_probes` list.

The provided JSON confirms the failure happens before any pass runs. In `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_181800_910016/details/apps/bcc__set.json`, all 21 `rejit_result.per_program` entries have:

- `status: "error"`
- `passes: []`
- `error_message: "probe target kinsns for prog ...: target probing requested with no kinsn targets"`

## Trigger condition analysis

This is not a BR-specific explicit probe. It is daemon default behavior for any execution plan whose step command text contains `${TARGET}`.

The trigger chain is:

1. `runner/libs/rejit_plan.py:88-97` builds `kinsn_probes` as the union of every enabled pass YAML `kinsns:` entry.
2. The BR pass set is `noop,wide_mem,const_prop,dce,bounds_check_merge,skb_load_bytes_spec`.
3. Those pass YAML files declare no `kinsns:` entries, so `build_kinsn_probes()` returns `[]`.
4. Current `runner/config/passes/dce/default.yaml:5-6` still invokes:

```yaml
command: |
  timeout 6000 bpfopt --pass dce --input ${INPUT} --output ${OUTPUT} --report ${REPORT} --prog-type ${PROG_TYPE} --target ${TARGET}
```

5. `daemon/src/commands.rs:908-917` scans all step commands with `collect_referenced_vars()` and records `TARGET` if any command contains `${TARGET}`.
6. Because DCE references `${TARGET}`, `run_program_steps()` calls `bpf::probe_target_json(kinsn_probes)`.
7. `kinsn_probes` is empty, so `daemon/src/bpf.rs:88-89` bails.

The smallest reproducing shape is therefore not "BR" in the abstract. It is any plan with:

- at least one step command referencing `${TARGET}`
- no enabled pass YAML contributing `kinsns:`

For example, `noop,dce` would have the same failure with the current DCE YAML. A BR list without the DCE target placeholder would not hit this daemon path.

The current DCE target placeholder was introduced by non-daemon commit `cd2a9117` (`Fix const propagation and DCE target configuration issues`, 2026-05-10), which changed `runner/config/passes/dce/default.yaml` from no target argument to `--target ${TARGET}`. That commit is not shown by `git log -- daemon/`, but it is the direct config-side trigger.

## Why BR but not noop-only

`noop` alone does not reference `${TARGET}` in `runner/config/passes/noop/default.yaml`, so `collect_referenced_vars()` does not include `TARGET`, and the daemon never calls `probe_target_json()`.

The isolated kinsn runs and `prefetch` do reference `${TARGET}`, but they also declare `kinsns:` in their pass YAML. For example:

- `prefetch` declares `bpf_prefetch`
- `rotate` declares `bpf_rotate64` and `bpf_rotate32`
- the 5-pass kinsn set contributes rotate/select/extract/endian/bulk-memory kinsn probes

Those runs call the same daemon target-probing path, but with a non-empty `kinsn_probes` list, so `probe_target_json()` proceeds to kernel BTF probing.

The BR pass set is the broken corner because it has no kinsn-class pass but, through DCE's YAML command, still requests `${TARGET}`.

Note: `docs/evaluation-05-07-2026.md:253-260` also reports BR at 0.0% success, but its documented dominant failure is `bpfopt_failed[const_prop]`, not this daemon-side empty-kinsn probe failure. The May 12 `bcc__set.json` failure is earlier: pass count is zero for every program.

## Recent daemon commits

`git log --date=short --pretty='%h %cd %s' --since='2026-05-07' --until='2026-05-12 23:59:59' -- daemon/` returns:

```text
7f746d15 2026-05-09 Remove bpfprof and kernel-sys, refactor bpfopt and daemon
6a5ca536 2026-05-08 Add results and metadata for x86 KVM corpus run
cc780ce5 2026-05-08 Add progress and result metadata for x86 KVM corpus runs
2fdbc3e6 2026-05-08 feat: Conduct architecture audit for bpfopt pass and implement improvements
de58ebe0 2026-05-08 Add corpus results and update daemon command configurations
476b1c98 2026-05-08 Add timing metrics for bpfopt CLI and BPF_PROG_REJIT syscall in PassDetail
```

Related daemon history just before that range:

```text
56549b8a 2026-05-05 Move pass metadata into bpfopt list-passes --json (-LoC)
d2e90290 2026-05-05 Replace daemon optimize protocol with execute_plan step executor
1da6c2dc 2026-05-05 Refactor BPF execution plan steps to use structured StepSpec
a91d5753 2026-05-05 Probe all endian load kinsns
cff84bff 2026-05-01 fix: restore call_offset and BTF module fds in target probing and fd_array
```

The most relevant daemon-side change is `56549b8a`: it removed the daemon's hardcoded `KINSN_PROBE_TARGETS` and made `probe_target_json()` consume caller-supplied `KinsnProbeTarget` metadata. That commit also added the empty-target bail. The later execute-plan/YAML path now lets a command request `${TARGET}` while supplying no kinsn probes.

## Bug verdict (daemon defect | by-design)

Verdict: daemon defect, with a config/plan-contract trigger. BR itself is not by-design broken.

The BR set contains bytecode-only passes and should be able to run without kinsn target probing. Current `bpfopt` metadata also says DCE does not need target metadata: `bpfopt/crates/bpfopt/src/passes/mod.rs:125` registers `dce` with `META_NONE`, and `bpfopt/crates/bpfopt/src/passes/dce.rs:15-17` ignores `PassContext`.

The immediate trigger is therefore the stale or incorrect DCE YAML `--target ${TARGET}`. The daemon-side defect is that target-file preparation is coupled to "probe kinsns" instead of to the actual target JSON content needed by the step. An empty kinsn list is a valid situation for non-kinsn bytecode passes if they only need arch/features, and it should not abort the whole program before pass 0.

This is not a ReJIT legality issue, not a kernel limitation, and not evidence that the BR pass-set should be disabled.

## Suggested fix (code-level, no apply)

Minimum unblocker:

- Remove `--target ${TARGET}` from `runner/config/passes/dce/default.yaml` unless DCE actually consumes target metadata. This matches current `bpfopt` pass metadata (`META_NONE`) and current DCE implementation, and it prevents BR from entering the daemon target-probe path at all.

Daemon-side hardening:

- In `daemon/src/bpf.rs`, add a target-construction helper that treats empty probe requests as a platform-only target, not as kinsn probing:

```rust
pub(crate) fn target_json_for_probes(targets: &[KinsnProbeTarget]) -> Result<TargetJson> {
    if targets.is_empty() {
        return Ok(TargetJson {
            arch: detect_arch(),
            features: detect_features(),
            kinsns: BTreeMap::new(),
        });
    }
    probe_target_json(targets)
}
```

- Keep `probe_target_json()` fail-fast for actual probing misuse, or make it private so callers use `target_json_for_probes()`.
- Change `daemon/src/commands.rs:522` to call the new helper when `${TARGET}` is referenced:

```rust
let probed = bpf::target_json_for_probes(kinsn_probes)
    .with_context(|| format!("prepare target.json for prog {prog_id}"))?;
```

- Preserve bpfopt-side kinsn validation. If a real kinsn pass has a broken YAML entry with missing `kinsns:`, bpfopt should still fail with its required-kinsn check after reading an empty target, instead of daemon failing before any pass detail exists.

Plan/config validation:

- Add a runner config validation check: if a pass command references `${TARGET}` but its YAML has no `kinsns:`, require an explicit marker such as `target_kind: platform` or reject the config. This catches accidental kinsn YAML drift while still allowing intentional arch/features-only target consumers.
- Add a focused regression test for the empty-probe target helper: empty `kinsn_probes` should produce `TargetJson { arch, features, kinsns: {} }` without kernel BTF probing. A separate config validation test should cover `dce/default.yaml` so BR cannot regress into a daemon pre-pass failure.
