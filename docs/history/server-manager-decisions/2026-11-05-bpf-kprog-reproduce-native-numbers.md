# BPF NativeSim duty reproduces the early native numbers first

- Date: 2026-11-05 (America/Los_Angeles); deployed 2026-11-06 UTC
- Scope: `services/agent-duties/duties.yaml`, prompt of `bpf-benchmark-supervisor`
- Status: deployed

## User request and approval

About the early numbers the kprog paper quotes (x86 KVM six-app native/eBPF
geomean 1.349x, arm64 AWS 1.056x, micro 1.478x and 1.429x), the operator asked:

> “这个能不能复现? 早期和现在应该没有实质性的差异吧”

When told that an October audit had called most of the application numbers
invalid, the operator objected that suspicion alone does not make a number
invalid, and said:

> “不能说可疑就说不成立吧??? 总之你要去复现?”

The second quote approves this change. Earlier in the same conversation the
operator said “改，给我草稿” to a wider redirect and “不要加这种额外要求” about a
draft sentence that constrained what counts as an increment; neither the wider
redirect nor any such constraint is part of this change.

## Defaults and decisions

| ID | Setting | Current value | New value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-4 | `bpf-benchmark-supervisor` prompt | Continue the NativeSim proof goal; no paper edits | Keep the paper ban. Reproduce the early x86 micro and six-app corpus numbers first, with the 2026-05-29 recipe and with the current code, recording per app and arm how much work each arm did, then continue the existing goal. The arm64 AWS rerun waits for the operator. | Operator words above. The October 11 audit (`corpus/results/lpc_kprog_numbers_audit_20261011/`) found direct evidence only for Cilium (rebuilt old source reproduced about 2.30x while its native arm policy-dropped nearly all packets). It inferred OTel, could not decide Tetragon or Katran, and found BCC and Tracee consistent. Only reruns that record the work done can settle the rest. | About a day of serial KVM timing on `lab`; other Workspaces on `lab` add host noise, which is recorded rather than removed | Approved by "总之你要去复现?" |

The schedule, Workspace, runner, retained OMP session and model are unchanged.

## Evidence and implementation

The Workspace runs on `lab` (Intel Core Ultra 9 285K, 24 CPUs, 125 GiB,
`/dev/kvm`). The 2026-10-09 Cilium rerun in
`corpus/results/cilium_native_lab_20261009/` already builds the 2026-05-29
recipe (`artifacts.mk`, commit `9f3855f6fa1c`). It also observes inventory,
counters and drops through task-local hooks without changing the corpus runner.
The prompt points the agent at that method. Only the prompt and the two
admission annotations of this duty row change. The OMP run in progress keeps
its prompt until it ends.

## Validation and rollback

Validation: the live CronJob carries the new prompt after Flux applies the
commit. The next run's journal shows the reproduction as its first work, and
new `micro/results` and `corpus/results` directories appear in the Workspace.

Rollback: a forward-only commit that restores the prompt from
`2026-11-05-bpf-kprog-no-paper-edits.md` in this same duty row.
