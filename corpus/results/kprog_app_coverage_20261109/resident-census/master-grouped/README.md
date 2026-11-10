# Resident census at the current model

All 549 resident x86-64 instances, model 46659115e (model sources identical to the matched runtime model af422c391). Load-only: B is generated, compiled and submitted to the stock verifier; native execution requests: 0.

**Interim table:** 123 of 246 native bodies have outcomes; 123 instances are still running and appear as `pending`.

| Application | Instances | Generated | Compiled | Verifier accepted | Verifier rejected | Failure classes (instances) | Best verified-path row | 4f5 census accepted |
| --- | ---: | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| BCC | 25 | 25 | 25 | 25 | 0 | - | 25 | 7 |
| Katran | 1 | 1 | 1 | 0 | 1 | `verifier: value N makes fp pointer be out of bounds` 1 | 1 | 0 |
| Cilium | 72 | 0 | 0 | 0 | 0 | `generation_failed: KeyError: 0 at section = SECTIONS[context['prog_type']]` 72 | 14 | 0 |
| OTel | 13 | 2 | 2 | 2 | 0 | `generation_failed: KeyError: 0 at section = SECTIONS[context['prog_type']]` 11 | 2 | 0 |
| Tracee | 151 | 29 | 9 | 0 | 9 | `pending` 121; `compiler: translation unit is too large for Clang to process: ran out of source locations` 20; `verifier: Rn invalid mem access 'scalar'` 9; `generation_failed: ValueError: unresolved finite indirect target at 0xN: call   QWORD PTR [rsp+0xN]` 1 | 5 | 0 |
| Tetragon | 287 | 284 | 284 | 81 | 203 | `verifier: Rn invalid mem access 'scalar'` 123; `verifier: invalid write to stack R10 off=N size=N` 77; `pending` 2; `verifier: The sequence of N jumps is too complex.` 1; `native_manifest_selection_gap` 1; `verifier: math between fp pointer and register with unbounded min value is not allowed` 1; `verifier: Rn type=scalar expected=func` 1 | 4 | 0 |
| Total | 549 | 341 | 321 | 108 | 213 | | 51 | 7 |

Best verified-path rows are the 2026-11-08 and 2026-11-09 05:18 application installations. The 4f5 column is the 2026-11-09 census at model 4f5b7ae6d (grouped-static/all-instances.json): generated 287, compiled 253, accepted 7, rejected 235.

## Failure classes

Verifier rejections are named by the verifier's own final error line, with numbers and register indices normalized. Other stages keep the committed corpus_resident_verifier label; where that label is only the stage name, the stage's first error line names the class. instances.json keeps both the committed label (driver_class) and this class.

| Class | Instances | Bodies | BCC | Katran | Cilium | OTel | Tracee | Tetragon |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `verifier: Rn invalid mem access 'scalar'` | 132 | 20 | 0 | 0 | 0 | 0 | 9 | 123 |
| `pending` | 123 | 0 | 0 | 0 | 0 | 0 | 121 | 2 |
| `installed` | 108 | 36 | 25 | 0 | 0 | 2 | 0 | 81 |
| `generation_failed: KeyError: 0 at section = SECTIONS[context['prog_type']]` | 83 | 37 | 0 | 0 | 72 | 11 | 0 | 0 |
| `verifier: invalid write to stack R10 off=N size=N` | 77 | 5 | 0 | 0 | 0 | 0 | 0 | 77 |
| `compiler: translation unit is too large for Clang to process: ran out of source locations` | 20 | 20 | 0 | 0 | 0 | 0 | 20 | 0 |
| `verifier: value N makes fp pointer be out of bounds` | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 |
| `generation_failed: ValueError: unresolved finite indirect target at 0xN: call   QWORD PTR [rsp+0xN]` | 1 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| `verifier: The sequence of N jumps is too complex.` | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| `native_manifest_selection_gap` | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
| `verifier: math between fp pointer and register with unbounded min value is not allowed` | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |
| `verifier: Rn type=scalar expected=func` | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 |

## Largest remaining class

`verifier: Rn invalid mem access 'scalar'`: 132 instances in 20 native bodies. Representative output:

* Tetragon generic_kprobe_process_filter (resident 100, 33 instances):

  ```
  144: (bf) r1 = r3                     ; R1=32 R3=32
  145: (07) r1 += -296                  ; R1=-264
  146: (61) r2 = *(u32 *)(r0 +0)
  R0 invalid mem access 'scalar'
  ```
* Tetragon generic_kprobe_actions (resident 104, 33 instances):

  ```
  8193: (0f) r1 += r2                   ; R1=scalar() R2=scalar(id=105)
  8194: (b7) r2 = 0                     ; R2=0
  8195: (73) *(u8 *)(r1 +0) = r2
  R1 invalid mem access 'scalar'
  ```
* Tetragon generic_kprobe_event (resident 101, 33 instances):

  ```
  349: (bf) r1 = r3                     ; R1=40 R3=40
  350: (07) r1 += -184                  ; R1=-144
  351: (79) r2 = *(u64 *)(r0 +0)
  R0 invalid mem access 'scalar'
  ```

## Inputs and method

* Resident rows and source resources: A's prepared 549-instance set (/var/tmp/kprog-tmp/A/large-stack-observation/inputs/run-inventory.json); fresh collection over the same coverage archives reproduces every row field.
* Native P: the payloads of the current-model six-app replay, built with the restored compiler flags (no external thunks). Selection uses corpus_resident_census.collect on their manifests. Every manifest selection equals the previous census object+symbol. The Tetragon manifest selects nothing for 153 residents (bytecode-length mismatch against the paired source); 152 of them use the previous census object+symbol in the current payload, and one (credential-commit) has no object in the payload. by_selection in result.json separates these rows.
* Grouping: SHA256 of the native-link proof ELF (--mode proof --preserve-entry-abi), as in grouped-static. One representative per body through corpus_resident_groups.shard; the outcome is weighted by body membership.
* Model source: this batch used a read-only export of the committed model files at 46659115e, bound over the repository paths by the committed driver (inputs/source). Under the operator rule of 2026-11-10 an exported source copy counts as a separate tree: the batch kept it until it finished, the copy was then removed, and publication reads /workspaces/repository directly.
* Runtime: af422c391 replay kernel, bpf_kprog_stock module, loader and native-link copies. Workers on host CPUs 8-19, one guest vCPU, 4G guest memory. Host Clang for one large Tracee B source reaches 10-14 GiB; after six concurrent compiles brought host MemAvailable to 4 GiB, the six in-flight compiles were stopped, their worker records discarded and their bodies resubmitted. From then on the existing KPROG_REAL_CLANG hook routes the same clang binary and argv through a bounded number of concurrent compiles: first three in total at MemAvailable >= 24 GiB, then three for B sources above 400000 bytes plus three for smaller sources, then four large plus three small at MemAvailable >= 28 GiB. At 03:43 UTC, on the coordinator request for the 64G timing guest on CPUs 0-7, the two youngest of four large compiles were stopped and their bodies resubmitted; bin/slot-holder holds two of the four large slots (at most two large compiles) and new compiles start at MemAvailable >= 40 GiB. Worker counts over the run: six two-CPU, four three-CPU, six two-CPU, eight sharing CPUs 8-19, then fourteen sharing CPUs 8-19 with the other applications and the smallest Tracee bodies queued ahead of the large Tracee bodies. Scheduling changes affect run time only; each compile uses the same compiler and argv.
* Files: result.json (summary, per-body records), instances.json (549 rows), outcomes.json.gz (complete representative outcomes with every diagnostic byte), requests.tar.gz (raw request archives), run-raw.tar.gz (inputs, logs, commands), provenance.json (hashes and model identity), census.py (controller). Ordered .partNNN files concatenate to the named stream.
