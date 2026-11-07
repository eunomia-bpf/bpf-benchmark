# Synchronized ARM immediate-alias contract replay

A's published f9b20a904 contract bundle supplies the exact three candidate C
headers compiled by this observer. Across ADD, SUB, AND, ORR and EOR at both
32-bit and 64-bit widths, numeric labels 3, 4 and 6 preserve the original AUX,
operands, widths and immediate bits. Both raw and direct entry APIs agree with
QEMU architectural execution and V's canonical reference.

| Native operation | Widths | Alias labels | Routes | Groups | Cases | QEMU/C/reference differences |
| --- | --- | --- | --- | ---: | ---: | --- |
| ADD | 32, 64 | 3, 4, 6 | raw, direct | 12 | 12,288 | 0 / 0 / 0 |
| SUB | 32, 64 | 3, 4, 6 | raw, direct | 12 | 12,288 | 0 / 0 / 0 |
| AND | 32, 64 | 3, 4, 6 | raw, direct | 12 | 12,288 | 0 / 0 / 0 |
| ORR | 32, 64 | 3, 4, 6 | raw, direct | 12 | 12,288 | 0 / 0 / 0 |
| EOR | 32, 64 | 3, 4, 6 | raw, direct | 12 | 12,288 | 0 / 0 / 0 |

The 60 route/form groups complete 61,440 observations with zero differences
and zero forms awaiting reference. All 61,440 memory observations retain their
input bytes. observations.tsv records every form's opcode, AUX, width, route,
case count and differences. The existing fixed-seed stream, boundary input
states, observer and comparison masks retain their launch definitions.

The synchronized contract interprets ADD_IMM(3), SUB_IMM(4) and ALU_IMM(6) as
generic immediate aliases: AUX supplies the arithmetic/logical operation.
These finite native observations cover five actual immediate operation
selections. A's published immediate_alias_dispatch theorem supplies its
universal alias relation. The compiled-B, ABI and native-link obligations
continue in the shared universal proof work.

## Source and artifacts

All 91 actual-compilation archive files match their manifest. Its 79 production
include files comprise 76 exact launch Git inputs and three exact A candidate
headers. Every captured field recreates the production encoder output, with
the intended numeric opcode substitution. All six variants for each of the
ten native forms use identical actual native bytes; this includes 30 matching
raw/direct pairs.

The direct selector retains 69 mappings and all shared body text. Labels 3/4
select existing body 4, matching ALU_IMM. candidate-changes.json records the
source identities and this selector relation. The launch source-drift map is
empty; production headers retain their captured baseline through this run.

| Artifact | SHA-256 |
| --- | --- |
| Candidate input bundle | 1f26e955931593fbad76e7b1a8ca3da5be0d5251f615e95b165655d240fb73e1 |
| Static ARM observer | f18fbcd9d4c3bd5249bac8773eed408e1de827c1076eee11c5a339b9e2388c5b |
| Canonical reference | c110b03a98238272fe72124a4c92e0095b8c759a750891e37ad31f8b81084d96 |
| Raw-equivalent trace | d3ec7d8b96b6bfdd2fda194b69658047f20fd19dc1b8254201cabf506c4f9aa0 |
| Compressed trace | 5fc8114be3e1e94d9fafc8a8b0aee8f232904a1d7d151995e35a74342babaffe |

launch-inputs.tar.gz retains the full launch inputs, A bundle and job wrapper.
actual-compiled-inputs.tar.gz retains the actual generated source/include
closure and bindings. cpu-differential-arm64.gz is the exact static observer.
The Workspace stores the full 111,575,064-byte trace losslessly in a
36,183,410-byte cpu-states.bin.zst. Its decompressed SHA was checked before
replacing the owned raw copy; review.py independently streams and hashes the
compressed trace. trace-storage.json records both identities.

The launch Git is ffcb825a1bcf5a272eb3ba0a57f8d6211b5af0c2. The detached job
3718339 completed comparison at 2026-11-07T20:34:42.942578+00:00, closed with
exit 0 after lossless trace storage, and retained production_adoption as
owner_sync_pending. A/V synchronize production integration with application
source epochs. The captured ARM replay totals retain that launch-era adoption
boundary. The default 807-form hardware handoff retains its production epoch;
this static observer records the synchronized private candidate epoch.

## Commands

From /workspaces/repository, the launch source epoch uses:

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/arm64-contract-aliases/Makefile reference
taskset -c 16-19 python3 kprog/results/kprog_fidelity_20261107/differential/arm64-contract-aliases/review.py
~~~

The captured job wrapper additionally compresses the closed trace and writes
trace-storage.json before completing. The review checks archived hashes, exact
candidate and production source identities, all encoded/native-byte variants,
per-form results and the complete decompressed observation stream. Candidate
headers come from the candidate archive captured inside launch-inputs.tar.gz,
with its exact original digest verified before reading the three headers.
This retains the observed source epoch as the shared A bundle advances.
It writes summary.json and observations.tsv. Existing canonical source/executable
archives are shared with the c110b03a replay cohorts.

A's later 1f0f20eb bundle retains byte-identical versions of the three C headers
used here. The recorded 61,440 observations retain their captured f9b20a904
source identity; the additional universal-model work retains A/V ownership.


## Production source adoption

A's f0517e4931be058ddd8ce0d0df87612ee3ffb250 integrates the generic alias
mechanism. The current [replay input ledger](../replay-inputs/README.md)
joins these existing61,440 QEMU/C/reference observations to the adopted source:
all72 compiled C headers match, and the current encoder reproduces all60
numeric route/form bindings across ten native forms. The79-source archive
retains seven Python inputs, including two producer files with recorded
old/current identities. Five Python inputs match directly. All91 archived
files retain their original hashes, and all30 raw/direct pairs retain their
native bytes. The ledger records the full correspondence and source pins.

The original summary's owner_sync_pending value describes this observer's
20:34 launch/completion epoch. The later shared-source adoption and its
current producer-field checks are recorded separately in inputs.json under
arm64-contract-aliases.production_source_correspondence. The ledger's ARM
numeric domain now has67 sampled tokens plus one explicit-monitor observation.
The static observer, reference, trace, comparison masks and original counts
retain their captured identities. The existing16-19 ledger command performs
the current source-adoption reconciliation.
