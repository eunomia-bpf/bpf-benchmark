# Census follow-ups on the verified path

Fixes for the non-verifier failure classes of the master-grouped resident census
(corpus/results/kprog_app_coverage_20261109/resident-census/master-grouped, model
46659115e, 187 of 549 accepted). Each fix is followed by a resubmission of the
affected census bodies with rerun.py: the census inputs (native object, source BPF
object, kernel, native-link, stock module), driver and model from
/workspaces/repository, one guest vCPU, 4G guest memory, host CPUs 8-19. Load-only;
native execution requests: 0. result.json in each directory lists every member
instance with its census row and its re-checked row; raw.tar.gz holds the request
archives, guest/service/compiler logs and commands.

## 1. Cilium cilium_nodeport map binding (6 instances, 2 bodies)

Census class: `load_failed: raw proof map name has ambiguous original identities:
cilium_nodeport`.

Cause: relocate_source_map_proof binds every B map operand to the original map id
from the trusted map list; bind_raw_proof_maps then looked up each operand in the
original program's maps in list order and stopped with "ambiguous" as soon as two
other maps with the same 15-byte kernel name came before the operand's own id.
Cilium's cilium_nodeport_neigh6 (62), cilium_nodeport_neigh4 (63) and
cilium_nodeport_nat_buffer (78) share the kernel name cilium_nodeport.

Fix (3676dab5f, kprog/libnativeloader/src/native_loader.cpp): the operand's exact
map id selects first; the name match runs as before when that id is absent. Checks
added: 0. An unmodified build of the same source with C's af422c391 loader
configuration is byte-identical to the af422c391 runtime loader and
libnative_loader.so, so the resubmission runtime differs from the census runtime by
this change alone (build: build-loader.sh <build-dir>).

| Program | Instances | Census | Re-checked |
| --- | ---: | --- | --- |
| tail_handle_ipv4 (309, 318, 349) | 3 | load_failed (cilium_nodeport) | installed |
| tail_handle_ipv4_cont (293, 324, 351) | 3 | load_failed (cilium_nodeport) | `verifier: Rn offset is outside of the packet` |

tail_handle_ipv4_cont now reaches the stock verifier, which stops at B instruction
16017, a 4-byte packet load at a variable offset of 26-1046 bytes with packet range
r=0. Cilium at this model: accepted 58 -> 61, verifier rejected 8 -> 11,
load_failed 6 -> 0.

Command:

```
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/rerun.py run cilium-nodeport \
  --runtime /var/tmp/kprog-tmp/replay-claude/runtime-fix1 --bodies fa75fd93aee6c87e 3836a48a1ba6af6a --workers 2
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/rerun.py publish cilium-nodeport
```
