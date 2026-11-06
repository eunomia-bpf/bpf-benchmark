# x86 six-flag CPU and canonical replay: 745 forms

The hardware matrix executes 745 forms × 1024 boundary/random states
(762880 cases) on this host's x86-64 CPU. It initializes and captures CF,
PF, AF, ZF, SF and OF, cycling all 64 combinations, and compares all observed
GPRs, XMM0, flags, stack bytes and the 256-byte memory window. The generator
uses the production encoder and its captured production headers. Undefined
flags follow the architectural per-instruction/per-count masks; AF is undefined
for nonzero ordinary shifts and logical operations, IMUL defines CF/OF, and
ANDN/BZHI do not define PF/AF. No defined flag is removed to obtain agreement.

The initial hardware run records 10240 differences across ten numeric stack
address rows. The reference command executes the hardware observer again, at
its actual new stack address: that run records 11264 differences across eleven
rows. The additional row is `lea rax, [rsp+16]`, whose production flag effect
contains the absolute stack address's low-byte parity. These are the existing
stack-address representation findings, including raw absolute-register
observations. There is no newly observed non-stack arithmetic/flag difference.
`forms.tsv` and `mismatches.jsonl.gz` record the latter run. Both command logs
are retained. These runs use different actual stack addresses and are reported
separately rather than merging their counts.

| Hardware difference row | Cases | Differences |
| --- | ---: | ---: |
| `mov rax, rsp` | 1024 | 1024 |
| `mov eax, esp` | 1024 | 1024 |
| `lea rax, [rsp+16]` | 1024 | 1024 |
| `cmp rsp, 0` | 1024 | 1024 |
| `mov rsp, rax` | 1024 | 1024 |
| `mov esp, eax` | 1024 | 1024 |
| `add rsp, 16` | 1024 | 1024 |
| `push rsp` | 1024 | 1024 |
| `pop rsp` | 1024 | 1024 |
| `push sp` | 1024 | 1024 |
| `pop sp` | 1024 | 1024 |

The canonical replay checks 320 forms / 327680 cases against the
**identical saved hardware states**, with **zero CPU/reference differences**
and 10240 simulator/reference differences on the ten supported stack-address
rows. 425 forms have no admitted canonical replay in this snapshot;
38 are control composites requiring the explicit path interface and the others
lack a canonical encoding rule. `reference-forms.tsv` records every form and
its exact decoder diagnostic. No missing form is counted as passing. Canonical
source and its tested executable are frozen, including the explicitly recorded
uncommitted source overlay in `reference-provenance.txt`.

Pure register operations omit memory cells only from JSON serialization. The
replay still compares the entire actual CPU/C memory and stack, and requires
no reference memory events, fault or output cells on those requests. Memory
operations retain the complete mapped cells. This changes request size, not
instruction semantics or the comparison mask.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- timeout 900 make -C kprog/fidelity run BUILD=build-x86-six-flags OUT=../results/kprog_fidelity_20261106/differential/x86-six-flags
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/differential/x86-six-flags freeze reference
```

Both commands return nonzero because they preserve these findings and the
missing canonical forms. The reference command has no timeout/fallback to
claim success. To replay the existing trace, invoke the same reference target
with `--reuse-trace` added to its explicit command. `harness-artifacts.tar.gz`
contains the static executable, actual generated C/native assembly, production
header/import snapshot and observer/replay sources. `native-code.json` retains
actual byte spans/PCs; compressed JSONL retains every mismatch's complete input,
CPU/C output, memory and (for reference failures) canonical state. The saved
trace remains available for current replay. `canonical-source.tar.gz` and
`reference.gz` preserve the exact reference snapshot, independently of later V
canonical coverage increments.

This is the preceding twelve-condition CMOV/SET matrix. The 799-form sibling
adds every condition admitted by the active production table. The
`pre-reference-*` archives here were captured after this reference invocation
and duplicate its raw report; the initial run count is retained in its command
log. The 799-form sibling preserves its initial report separately.

The archived generated C/assembly and snapshot are the actual 745-form inputs.
The accompanying generator/replay scripts were captured at publication after
the 799-form table/serialization update; regeneration with that generator gives
the expanded matrix. Rebuilding the archived generated C preserves this run.
