# Inline-memory binding batch observations

One offline collector reconciles T's published generic memory-binding regression
at 697bea0ea4326472119c137b306d298621a9a218. It reads all three retained service
batches, including the two earlier producer failures. All eight terminal requests
have equal kernel-owned native bytes, worker copy bytes and receipt SHA256.
Kernel source IDs and every successful load reply agree with their service
records. Archive membership and terminal records match exactly in each batch.

| Service batch suffix | Requests | Bound | Producer refusal | Verifier refusal |
| --- | ---: | ---: | ---: | ---: |
| 1794086879500039835 | 2 | 1 | 1 | 0 |
| 1794086994366839654 | 2 | 1 | 1 | 0 |
| 1794087098395487377 | 4 | 3 | 0 | 1 |

The three batches retain distinct execution epochs and their original native
inputs. Counts describe requests and preserve repeated IDs across those epochs.
terminal-outcomes.tsv records each request, byte identity, stage and generated
copy/fill count. failures.jsonl.gz preserves the complete producer/verifier
diagnostics and commands from all three failed requests.

## Final memory and transport outcomes

The final batch's three native executions use fresh generation and binding.
Their client IDs, service IDs, native object hashes, generated macro counts and
published terminal receipts agree. Each returned 2 with prebuilt_proof=false.

| Copy/fill bytes | Source ID | Native ID | Observed return |
| ---: | ---: | ---: | ---: |
| 8 | 6 | 11 | 2 |
| 32 | 14 | 19 | 2 |
| 96 | 22 | 27 | 2 |

The final unsafe-address control generates a verifier refusal before native
execution. The exact diagnostic is:

~~~text
46: (73) *(u8 *)(r2 +0) = r9
R2 invalid mem access 'scalar'
processed 47 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
~~~

The final batch therefore has three successful native executions, one unsafe
verifier refusal and zero unsafe accepts. The transport command has 18 individually labeled outcomes: 16 expected
refusals and two PASS lines. Its final suite summary contributes one further
PASS line. The source metadata records all 19 outcome lines together; summary.json
keeps that reported count alongside the 18 individual outcomes and one summary.
The collector confirms the closing puts statement in the pinned C source.
Exact labels, errno values and record kinds are in transport-outcomes.tsv.

## Source and binary identities

The collector verifies 13 production source SHA values against their published
Git blobs, plus the metadata, raw archive, raw log and existing shared service
archive parser: 17 pinned inputs in summary.json. It reuses the parser from the
published application-batch reader at 919dd020.

Ten tested artifacts retain their raw archive hashes. The captured common
group header includes the two documented extra blank lines; its remaining
lines match the publication. The exact observed and published hashes remain
in source_observations. The captured module SHA is
c3842be1caa33ad9f2b9516f33bb6742dc96f3662dda5f1ce106bc68fa6e56a8.

Each final request's nine-field source/binary vector equals the published
runtime-source record, and all four final vectors agree. These are literal
service-reported file identities. Kernel/worker native byte identity and the
client/load reply identities are checked directly from the original artifacts.

This finite generic mechanism regression supports the shared memcpy/memset
target-binding correction. V/T develop universal memory, compiler, token and
binding laws; C owns complete Tetragon application replay. Earlier negative
suite epochs retain their own source pins and counts.

## Reproduction

Run from /workspaces/repository through bws.sh:

~~~sh
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/negative/inline-memory-batches/collect.py
~~~

The collector reads immutable published blobs and writes these batch observations.
It preserves original application/runtime inputs and launches zero guests.
The initial collector reached its control-count assertion after also reading
the enclosing memory-suite PASS summary. collection-attempt.tar.gz retains that
source and diagnostic. The final collector reads the exact transport-command
segment and exits 0. Original runtime and diagnostic bytes retain their values.
