# Stock-path receipt review, 2026-11-09

The 48-case tables below come from the S17 guest runs. The S18 closure section
records the later integration runs and the complete raw collection.

| ISA | Cases | Executed controls | Verifier rejection | Generation rejection | Accepted load-only |
| --- | ---: | ---: | ---: | ---: | ---: |
| x86-64 | 48 | 10 | 34 | 1 | 3 |
| AArch64 | 48 | 4 | 33 | 4 | 7 |

Both tables record zero negative native executions. Accepted load-only cases
remain explicit in the tables. Finite suite observations support regression
coverage; universal O1/O2/O4 and compiler correspondence retain their separate
proof obligations.

The tables correspond by case, stage and return code to saved outcomes:
x86 uses `S17/run/x86-current/outcomes.json`; ARM uses
`S17/run/arm64-final/outcomes.json`. Private output root:
`/var/tmp/kprog-tmp/S17`. Saved outcome JSON SHA256 values:

- x86: f1ca403e43cb6bbcfc0ac52245e5ad9a72fa396459e0a0f0ed3427640e924580
- ARM: 4a5074a3eb51d39823618da1937d2777c983560e8b036bba661b5649c0634857

Kernel source identity: `35ea2cde39fc88b01f2f49b2a357e7cf7102e4c8`, present
in `origin/kprog-no-kinsn`. `kernel/bpf/verifier.c` blob is
`159b25f8269ddfd6f66edabbca06e3822e56a330` at both that commit and
`c23719abc330`. The kernel diff against that base totals eight files,
467 insertions and one deletion. Changes occupy the x86 and ARM JIT and fault
paths, shared native header, BTF include, core and syscall handoff.

Published stock receipts through `21ee8db8d` are ancestors of `origin/master`.
They retain credential outcomes (`678ca954e`), first-frame observations
(`ca3f85146`) and ARM controls (`21ee8db8d`). The single-attempt loader source
is published as `d140d92ab`.

Observed table differences against the paired kinsn receipts:

- Both ISAs: `uninitialized_stack` is accepted load-only with privileged
  stock `allow_uninit_stack` semantics; the paired kinsn receipt records
  verifier rejection. The credential receipt records acceptance with
  CAP_BPF plus CAP_PERFMON and stack-initialization rejection with CAP_BPF
  alone. Original privileged acceptance remains in history.
- x86: `valid_r12_preserved` executes; its comparison column identifies it
  as an additional positive control. All other paired stages agree.
- ARM: every other paired stage agrees.

Stock-path integration differs structurally through ordinary B admission,
shared armed-image ownership/subprogram error, architecture-native JIT emission
and the matching fault paths. The verifier source keeps the base identity.
The loader supplies the diagnostic buffer on its first load attempt.

The published ARM controls record small-program retval 2, live/NULL BTF values
4294967295/0, ordinary subprogram load success, and armed-subprogram EOPNOTSUPP
with one raw load. Saved ARM injected-relocation-error service output records
load failure after verifier processing, as described in the S17 10:01 notice.

The saved x86 tail control records stock/native retval 2, 34 invocations and
33 transfers on each route, with JIT stack depth 0 and pop 0. Successful-transfer
frame-predicate composition remains the S11 O4 obligation.

## S18 closure

`integration-cases.tsv` holds one row per integration case and
`final-summary.json` holds the full collection summary.

| Case | Fixture exit | Client exit | Service status | Armed raw loads | Verifier completed | Native TEST_RUN |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| x86-physical-tail-frame | 0 | 0 | 0 | 1 | 1 | 1 |
| x86-multi-once | 0 | 1 | -5 | 1 | 0 | 0 |
| x86-jit-error | 0 | 1 | -5 | 1 | 1 | 0 |
| arm64-multi-once | 0 | 1 | -5 | 1 | 0 | 0 |
| arm64-jit-error | 0 | 1 | -5 | 1 | 1 | 0 |

Physical tail frame (`f360991d1`, x86): the guest records retval 2, R12=1, RSP=1
and RBP=1 across 34 invocations and 33 transfers. The earlier exit 1 came from
the probe compiler assigning retval to EBP between the call and the after
snapshot; the focused fixture keeps RBP as the frame pointer.

x86 JIT error (`970e4b205`): `fixtures/jit-error.patch` appends one relocation
record with offset chunk length minus 1 (5 of 6), kind 1, target 1, after the
loader's chunk filter. In the guest, kernel return probes record
`bpf_native_relocate` returning -34 (ERANGE) and the armed `BPF_PROG_LOAD`
returning -524 after the verifier completes. The client exits 1 with empty
stdout, the service records status -5 with `prog_id` absent, and
`bpf_prog_test_run_xdp` fires 0 times. The unmodified loader in the same guest
records relocate 0, retval 2 and one TEST_RUN, which shows the probes observe
the success path. ARM's `arm64-jit-error-kernel` run returns the same 524 with
one armed load; its raw output is in `s18-load-error-raw.tar.gz`.

Load count: the loader process issues three `BPF_PROG_LOAD` calls in both the
control and the injected run. Two are libbpf capability probes (socket-filter
type, 2 instructions, names empty and `libbpf_nametest`) that return descriptors
before the single arm event. Exactly one load follows the arm event; it carries
the 16 MiB log buffer and is the armed load. The `stock-armed-load-attempt=1`
counter used on both ISAs counts that armed load.

Earlier injections are retained in `s18-jit-error-raw.tar.gz`. Offset 0 fits
the rel32 arithmetic and installs a changed P. Offsets at and one below the blob
length were added ahead of `chunk_reloc_bytes`, which keeps only slots inside
the chunk, and both runs installed the program with retval 2.

Collector (`fc443b4d4`): each receipt reads its single request record and the
archive that record names. The earlier glob expected a failure archive where the
x86 fixture had written a success archive. From `loader-once/kinsn`, a link to
the live shared tree, the archive takes the headers the loader includes. The
final run exits 0 with 2278 members reread from the 11.4 MB archive at
`/var/tmp/kprog-tmp/S18/collected/current-raw.tar.gz`. Its 48-case rows and
outcome files match the earlier publication.

End-to-end stock-path acceptance now rests on the universal proof composition:
successful-tail, compiler and O1/O2/O4, held by V and the S11 ledger. The rows
above are finite runtime receipts for the listed runs.
