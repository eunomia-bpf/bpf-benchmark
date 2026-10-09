# Part A: source reconstruction and native-code identity

This is a reconstruction, not a recovered measured-source certification. The inventory selects 16 measurements between May 14 and June 6, plus an April 29 population anchor. No June 8 collection is directly selected by the inventory; figure/document dates are not run dates. The snapshot commit in the inventory and the September artifact tag are not collection commits.

For each run, the chronological candidate is the reachable repository commit with the latest UTC committer timestamp before `started_at`. Its kernel gitlink is read with `git ls-tree`. `data/commit-pins.json` also records last module, architecture module, selector, runner, micro-source and LLVM changes, the first commit retaining the raw metadata, and source changes across that interval. Timestamp order does not establish which checkout/build/image was used; merges, WIP, stale binaries and kernel deployment can differ. Recorded `unknown` values remain unknown. Source confidence is low for an exact HEAD; kernel confidence is medium for the inferred lineage and low for the precise binary.

| Run (all times UTC; abbreviated directory) | Latest committed candidate | Inferred kernel gitlink | Reconstructed replay snapshot if different |
| --- | --- | --- | --- |
| x86_kvm_micro_20260429_035938_203074 | `18326325bb58` | `a1b8bade169f` | same candidate |
| x86_kvm_micro_20260514_031744_210343 | `6273b6497908` | `81cb8848bace` | same candidate |
| x86_kvm_micro_20260514_181806_133778 | `fed5531cd05c` | `81cb8848bace` | same candidate |
| x86_kvm_micro_20260519_114214_364050 | `6063cc301444` | `6f0caf14e995` | same candidate |
| aws_arm64_micro_20260520_052452_727433 | `08aba8625570` | `6f0caf14e995` | same candidate |
| aws_arm64_micro_20260523_091516_610343 | `14867b6a71cb` | `8e116c79d104` | same candidate |
| x86_kvm_micro_20260526_210351_224315 | `16e4d39d76ed` | `8e116c79d104` | same candidate |
| x86_kvm_micro_20260526_210952_650695 | `16e4d39d76ed` | `8e116c79d104` | same candidate |
| x86_kvm_corpus_20260529_033517_489159 | `9f3855f6fa1c` | `8e116c79d104` | same candidate |
| x86_kvm_corpus_20260529_040554_604387 | `9f3855f6fa1c` | `8e116c79d104` | same candidate |
| x86_kvm_corpus_20260604_070210_639497 | `9af5cf074873` | `8e116c79d104` | same candidate |
| x86_kvm_corpus_20260604_100557_313063 | `e9956b814b38` | `8e116c79d104` | same candidate |
| x86_kvm_corpus_20260604_232313_992341 | `9e43757a2f4b` | `8e116c79d104` | `fbbd216a28a4` |
| x86_kvm_corpus_20260605_004607_636479 | `9e43757a2f4b` | `8e116c79d104` | `fbbd216a28a4` |
| aws_arm64_corpus_20260605_080836_924256 | `0b530196cb73` | `8e116c79d104` | `d01056165269` |
| aws_arm64_corpus_20260605_094729_221231 | `0b530196cb73` | `8e116c79d104` | `d01056165269` |
| aws_arm64_micro_20260606_001225_821028 | `cc070f4d6830` | `8e116c79d104` | `06f80a8955ab` |

The two May 14 runs retain daemon startup/shutdown logs and LEA/ReJIT sample reports. May 19 and May 26 retain `kernel` samples, not a complete compiler-command or selector log. The x86 code-size comparison spans those two source/kernel generations: the candidate is May 19 and stock baseline is May 26. Their bytecode sizes differ as well as their JIT lengths; the retained sizes alone cannot attribute every difference to a particular selector. The LLVM gitlinks are respectively `dec3d9f8436e66ef70e9e61dfc3b8c7b7391ba95` and `3663de5d5a4593d24f45b3d379e67ed242ed1452`.

Kernel transitions: `81cb8848bacea3595befa0d5bdea842f976dee41` (May 3, poke update error handling) is the pre-May-16 gitlink; `6f0caf14e9955724083d752b32ad0a5833d3c26b` (May 17, kinsn pseudo-instruction/verifier support) is the May 19/20 candidate; `8e116c79d1043f8e4dadd708f3a1ee5a26d19246` (May 23 06:31 UTC, final instruction pointer in emitter callbacks) is the later candidate. May 14/19/20/23/26 and June 6 micro hosts report `7.0.0-rc2+`; April 29 reports `7.0.0-rc2`. That generic release string cannot distinguish these commits. Corpus metadata does not save a kernel release; its kernel pin is inferred from history, not recorded by the app run.

May 29 module evidence: all 15 x86 modules including `bpf_x86_stack` and `bpf_x86_native_lab` are resident. The snapshot’s Makefile builds that list. The module `lsmod` allocation sizes (e.g. native lab 40960, rotate 16384 bytes) are retained, but are neither ELF sizes nor emitted JIT images. June 4 has 14 expected modules and omits stack, consistent with the June 3 module snapshot. June 5 ARM has 11 modules including EXTR/LDR/LDP/REV and native lab. Matching names narrows architecture/generation, not exact emitter bytes.

Reconstruction warnings: the tuned June 4/5 Cilium YAML first appears in `fbbd216a28a4` at June 5 03:32 UTC, after both measurements. Its `bulk_memory=disable` policy is a plausible WIP snapshot; chronology-only HEAD lacks it. ARM June 5’s first retaining commit `d01056165269` adds the selector/policy forms alongside the runs. June 6’s first retaining commit `06f80a8955ab` adds byte-load selector recovery alongside the raw micro result. These are useful replay snapshots with inferred policies; they are not observed measured HEADs. Missing original Cilium 4086/3512 site-report sidecars and Katran 21/62 reports cannot bind those counts to a source revision. Report paths in app JSON point to files not retained in those run directories.

The June 6 micro sample reports *are* retained. Across its three samples, calls are EXTR_X 387, LDR_W 198, UBFM_X 144, LDRH 114, REV16_W 39, STP_X 21, REV_W 15 and LDP_X 6. The reports specify LLVM all=disable and bytecode prefetch=disable with other bytecode families enabled. This is much stronger selector evidence than module names. Extracted pass reports are in `data/micro-site-reports.csv`; program errors (including untracked programs with no passes) are in `data/micro-program-errors.csv`.

`data/paper-code-size-comparison.csv` reconstructs all 29 per-benchmark median size ratios: x86 `0.7718068807314803`, ARM `0.8791161563071921`. The 27-case runtime population must not silently replace this size population. All per-sample `jited_prog_len`, `xlated_prog_len`, `native_code_bytes` and bytecode sizes are in `data/micro-code-sizes.csv`.

## What can prove byte identity

No full historical JIT/native `.bin` image or disassembly is retained in these selected result directories. Micro sizes and corpus per-program `bytes_jited`/`bytes_xlated` can falsify an identity claim when different, but matching them cannot prove byte equality. Module names, site counts and `lsmod` allocation sizes are even weaker. The October op comparison retains emitted callback bytes for its *October* baseline/current revisions; it does not substitute for the missing May/June full-program images. Its 33 growing operations and changed ROLW/REV16/EXTR emissions also prevent assuming the fixed emitters reproduce all old sequences.

Use a fresh exported source snapshot of the supplied commit and every recorded gitlink, matching historical compiler/options, inputs, policy and kernel configuration; do not replace files in the dirty working tree. Run through the snapshot’s existing `PLATFORM=aws ARCH=x86 make micro` (or ARM equivalent), never a local guest on this host. The May 19 candidate compiler choice is not recorded, so replay must establish it rather than assume stock clang versus kinsn LLVM. Record the actual source/kernel/toolchain and image build commands with candidate results.

A concrete check on the generated result is:

```bash
python3 check-code-identity.py \
  --reference /workspaces/repository/micro/results/x86_kvm_micro_20260519_114214_364050 \
  --candidate /path/to/generated/run \
  --reference-runtime kernel --candidate-runtime kernel \
  --commit <full-source-commit> --source-repo /path/to/exported/git-checkout
```

For the ARM candidate select reference `aws_arm64_micro_20260606_001225_821028`, reference runtime `kernel_rejit`, and candidate runtime appropriate to the replay. Corpus inventory uses `baseline` or `post_rejit` and a name/type/size multiset because IDs change and names repeat. The supplied commit is explicitly an asserted label unless tied by build metadata; the optional source checkout check only checks HEAD, not which binaries were actually used. No clean-tree measurement gate is imposed.

For actual byte equality, retrieve the missing original raw JIT images or original runtime image/kernel/modules and reconstruct them. During each app-owned startup, dump `bpftool prog dump jited id <id> file <stable-program-key>.bin` before teardown, alongside program/map/link identity and load attributes. Use a stable key including endpoint/attachment and section, not only truncated program name. Add `--reference-dumps <old-dir> --candidate-dumps <new-dir>` to compare every binary byte and filename; the check requires nonempty directories and reports mismatches. Full raw identity needs equal relocated addresses/CPU JIT options/constant-blinding environment; excluding documented relocation slots proves normalized instruction equality only. If the old bytes cannot be recovered, report “size signature matches; byte identity unproven,” and retain that limit. This check does not discard measured results.

