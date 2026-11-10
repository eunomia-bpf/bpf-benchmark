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

## 2. Tetragon manifest selection (152 carried-forward rows, 1 selection gap)

Census: 152 Tetragon rows ran on "previous census identity on current payload"
because the manifest's source_bytecode_len differs from their resident insn_cnt * 8,
and resident 31 (tg_kp_bprm_committing_creds) is `native_manifest_selection_gap`
because the payload carries no object for it.

### Where the length difference sits (measured)

* The manifest lengths equal the paired source build: for example
  generic_kprobe_event is 3312 bytes in the manifest, in
  /var/tmp/kprog-tmp/C/audit-recovery/paired-source/tetragon/bpf_generic_kprobe_v61.o
  and in the helper-call image's tetragon-bpf copy. Every one of the 152 rows' census
  object+symbol is a manifest record under the same program name.
* The census resident rows come from the 2026-11-08 Tetragon run
  (kprog_app_coverage_20261108/stack-spill-values/tetragon-stack-values), built from
  the earlier Tetragon objects: generic_kprobe_event 3368 bytes there.
* tetragon-current-selection.py applies the census selector (program name,
  source_bytecode_len = insn_cnt * 8, prog_type) to every Tetragon BPF_PROG_LOAD
  record in the JIT-arm shim logs of C's two whole-application runs on the paired
  image (application-remaining x86_kvm_corpus_20261110_041030_473940 and
  application-helper-run x86_kvm_corpus_20261110_132630_028096; logs in
  tetragon-selection/baseline-shim-logs.tar.gz). In both runs Tetragon loads all 16
  programs at exactly the manifest's length, with the census instance counts, and
  the selector picks exactly one candidate per load: the same object+symbol the
  census carried forward. The census outcomes of these 152 rows are therefore the
  current-manifest outcomes of the paired-image instances (35 installed, 117
  verifier rejected, unchanged). Helper and map-prefix selectors need xlated dumps
  and map ids, which these runs leave out; name, length and type already select
  one candidate for every application program.

| Program role | Native object | Census rows | Resident bytes (11-08) | Manifest = paired-image bytes | Candidates | Census outcome |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| generic_kprobe_event | bpf_generic_kprobe_v61 | 33 | 3368 | 3312 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_kprobe_output | bpf_multi_kprobe_v61 | 33 | 3016 | 2992 | 1 | installed |
| generic_kprobe_process_event | bpf_multi_kprobe_v61 | 33 | 32408 | 35008 | 1 | `verifier: invalid write to stack R10 off=N size=N` |
| generic_kprobe_process_filter | bpf_multi_kprobe_v61 | 33 | 23352 | 23128 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_retkprobe_event | bpf_generic_retkprobe_v61 | 9 | 26848 | 26416 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_rawtp_event | bpf_generic_rawtp_v61 | 1 | 3368 | 3312 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_rawtp_output | bpf_generic_rawtp_v61 | 1 | 3016 | 2992 | 1 | installed |
| generic_rawtp_process_event | bpf_generic_rawtp_v61 | 1 | 31312 | 33616 | 1 | `verifier: Rn type=scalar expected=func` |
| generic_rawtp_process_filter | bpf_generic_rawtp_v61 | 1 | 23352 | 23128 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_tracepoint_event | bpf_generic_tracepoint_v61 | 1 | 26744 | 26696 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_tracepoint_filter | bpf_generic_tracepoint_v61 | 1 | 23352 | 23128 | 1 | `verifier: Rn invalid mem access 'scalar'` |
| generic_tracepoint_output | bpf_generic_tracepoint_v61 | 1 | 3016 | 2992 | 1 | installed |
| generic_tracepoint_process_event | bpf_generic_tracepoint_v61 | 1 | 27928 | 28200 | 1 | `verifier: Rn type=scalar expected=func` |
| event_execve | bpf_execve_event_v61 | 1 | 22448 | 24624 | 1 | `verifier: invalid write to stack R10 off=N size=N` |
| execve_send | bpf_execve_event_v61 | 1 | 11296 | 11216 | 1 | `verifier: The sequence of N jumps is too complex.` |
| event_wake_up_new_task | bpf_fork_v511 | 1 | 10896 | 10872 | 1 | `verifier: Rn invalid mem access 'scalar'` |

Of the 618 Tetragon load records in the two runs, 576 select exactly one candidate
with the credential manifest below; the other 42 are libbpf and Tetragon feature
probes (unnamed, probe_*, uprobe_regs), which load unchanged.

### Credential commit (resident 31)

The helper-call producer (audit-recovery/native-inputs.py, payload of
65c73b03c/558b8851b) compiles Tetragon with native-only.mk from the committed archive
current-abi-app-payloads/tetragon/producer.tar.gz. That snapshot predates 5dbd5d481,
which added `compile_native bpf_execve_bprm_commit_creds ... "-D__LARGE_BPF_PROG
-D__V511_BPF_PROG"` to vendor/bpf/Makefile; apart from that line the snapshot's
compile list equals the HEAD recipe. tetragon-credential.py runs the same snapshot
with that one line and the same make arguments, plugin, linker and paired source
(tetragon-credential/producer-comparison.json):

* 63 native objects; the 62 shared with the helper-call payload are byte-identical,
  and the cel source library is byte-identical;
* the manifest (same writer options) keeps all 225 helper-call records and adds one:
  `bpf_execve_bprm_commit_creds.native.o`, program tg_kp_bprm_comm, symbol
  tg_kp_bprm_committing_creds, source_bytecode_len 2336, source_lacks_helper 174;
* resident 31 (2336 bytes) and both paired-image runs (2336 bytes) select it as the
  single candidate.

| Program | Census | Re-checked |
| --- | --- | --- |
| tg_kp_bprm_committing_creds (31) | native_manifest_selection_gap | installed |

Tetragon at this model: accepted 81 -> 82, native_manifest_selection_gap 1 -> 0;
every Tetragon row now has its native P selected by a current manifest. The
application image picks up the credential object when the helper-call producer
carries the 5dbd5d481 line; the whole-application replays keep
tg_kp_bprm_committing_creds on its BPF image until then.

Commands:

```
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/tetragon-credential.py
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/tetragon-current-selection.py \
  /var/tmp/kprog-tmp/replay-claude/tetragon-credential/payload/manifest.json tetragon-selection/credential.json \
  /var/tmp/kprog-tmp/C/audit-recovery/application-remaining/corpus-results/x86_kvm_corpus_20261110_041030_473940 \
  /var/tmp/kprog-tmp/C/audit-recovery/application-helper-run/corpus-results/x86_kvm_corpus_20261110_132630_028096
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/rerun.py rows tetragon-credential \
  --application tetragon/observer --producer /var/tmp/kprog-tmp/replay-claude/tetragon-credential/payload \
  --rows 31 --runtime /var/tmp/kprog-tmp/replay-claude/runtime-fix1 --workers 1
python3 -B corpus/results/kprog_app_coverage_20261110/census-followups/rerun.py publish tetragon-credential
```

The credential row ran on runtime-fix1, the loader of section 1.
