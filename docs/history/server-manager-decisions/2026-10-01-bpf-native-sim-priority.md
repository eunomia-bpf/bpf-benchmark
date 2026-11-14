# BPF benchmark duty prioritizes NativeSim proof

- Date: 2026-10-01
- Scope: `services/agent-duties` BPF benchmark duty prompt and retained CLI command
- Status: deployed; retained Agent resumed NativeSim work, proof increment pending

## User request and approval

> “不需要继续复现 KOP, 你应该去做 nativesimulate?”

This directs the existing BPF Workspace Agent away from additional KOP reproduction and toward the already-established NativeSim x86/ARM semantic-simulation and proof goal. It does not add a Workspace, runner, model, schedule, permission, or resource limit.

## Defaults and decisions

| ID | Setting | Upstream/current default | Proposed value | Reason | Risk | Decision |
| --- | --- | --- | --- | --- | --- | --- |
| BPF-1 | `bpf-benchmark-supervisor` prompt goal | No upstream prompt default; current duty asks for Make-backed benchmark and KVM evidence | Continue the existing NativeSim x86/ARM semantic simulation, machine-checked proof, and paper; no further KOP reproduction unless requested | The old prompt would repeatedly resume the now-deprioritized KOP experiment | The KOP sweep remains incomplete; retained raw evidence must be reported as partial, not silently promoted to a full sweep | Approved by the user words above |
| BPF-2 | BPF duty OMP command | Bare `omp` from the shared Workspace installer | Existing executable `/workspaces/.agent-state/bpf-benchmark-supervisor/bin/omp` on the retained Workspace PVC | The native installer returned HTTP 403 after the lab reboot, so the bare command is unavailable even though this retained binary reports `omp/18.1.19` | The path depends on the existing project PVC; if that retained binary is removed, the duty fails until the shared installer recovers | Existing-behavior repair under the operator's standing repair direction |

## Evidence and implementation

At 07:24:51 UTC the retained OMP session `01a08f97-2aa3-7177-adaf-d7b90ba3f92f` ended naturally after leaving a six-pass KOP shell chain running. The chain completed `cond_select` and began `bulk_memory`. At approximately 07:28 UTC the outer supervisor sent SIGTERM only to the verified chain parent (`launch.sh`); the active `bulk_memory` child continued until the separately approved lab reboot interrupted it, and no later sub-passes launched. The 07:30 CronJob still used the old prompt and resumed the original OMP session. After its outstanding tools completed, that OMP process received SIGINT at 07:32 UTC; its runner logged exit 130 and the CronJob retried the old prompt. No project source or raw result was deleted.

The same duty row now carries the exact user quote in `admission.yunwei37.com/user-words` and this record in `approval-ref`. The schedule, target Workspace, runner, OMP session directory, model selection, and all other duty rows are unchanged. After the installer failure, its command was changed to the executable already retained on this Workspace PVC; no binary was copied or installed.

The old-prompt 07:30 Job recorded six failed attempts during the lab's separately approved, orderly two-reboot NHI trial. It had no active Pod; the webhook required this record and the same quote as annotations before its deletion. A single bounded handoff Job copied from the now-updated CronJob template was attempted and then removed after six `coder ssh` failures during the second reboot. The 07:50 normal Job failed for the same reason and was removed. The 08:00 and 08:10 normal Jobs found the Workspace Pod `Running`, but Coder still reported `agent is shutting down` while envbuilder reinstalled the development image after reboot. The Pod's previous-container log then showed the native OMP installer failing with HTTP 403 and `envbuilder` exiting 22; a separate infrastructure owner repaired the shared installer in commit `8f8a072e`, allowing startup to continue when that optional install fails. The normal CronJob remains the sole schedule; its runner lock prevents two writers. No project source or raw result was deleted.

## Validation and rollback

The prompt delta and this record were committed and pushed as `1cd504f6` on `main`. The local rendered manifest and shell syntax check passed (`45` shell programs, `bad=0`); full `audit-iac.py` was blocked by concurrent, unrelated LiteLLM model-list drift and another temporarily unindexed record, rather than this duty. Flux applied a later source revision containing `1cd504f6`; the live BPF CronJob's prompt and both approval annotations matched the committed values. The original BPF repository remained on `master` at `aa6cbac83`; its session journal and completed `cond_select` raw result survived the first reboot, and `git fsck --connectivity-only --no-reflogs` exited zero. The `bulk_memory` tree was interrupted by the approved host reboot and is partial.

The retained-CLI command and this record were then committed and pushed as `c6dc556c`. Flux applied `main@sha1:c6dc556ce34de839e1a3bb5973e2c9b05472eaa7` to `agent-duties`, and the live CronJob had the exact new command and prompt. After the separately owned Coder startup repair was applied as `a7b98d2b`, the BPF Workspace Pod reached Ready and its retained `omp` executable reported `omp/18.1.19`. At 08:27:20 UTC, original OMP session `01a08f97-2aa3-7177-adaf-d7b90ba3f92f` recorded the new NativeSim user event. Its subsequent assistant turn verified the old KOP chain was absent and read `docs/implementation.md`, which identifies `kprog / native-sim semantic-refinement proof` as the active line. The tool call IDs and corresponding results are present in the same journal. This proves goal consumption and the start of project inspection, but not a new proof increment.

Pending: real NativeSim source/proof changes, machine-check result, scoped project commit/push, and paper progress. A successful CronJob or model call alone does not prove these outcomes. Roll back, if requested, with a forward-only commit restoring the previous prompt and command in this same duty row; do not erase the retained raw KOP results.
