# Saved x86 hardware replay after canonical MOVX refinement

**551 forms / 564224 cases checked: zero CPU/reference differences.** The same
saved simulator trace retains10240 differences in ten stack-address rows.
Compared with x86-control-reference/,26 forms /26624 cases newly agree:
22 MOVSX/MOVZX/MOVSXD register and memory forms, CDQE and three POPCNT forms.
The exact additions are in added-forms.txt; no prior form was removed.
248 encodings remain explicitly rejected by this frozen canonical decoder or
await its block interface. Their exact bytes, first input and diagnostic are
in reference-unavailable.jsonl.gz; they are not counted as passing.

The input is the identical799-form /818176-case real x86 host CPU trace from
x86-full-conditions/. This replay does not rerun the CPU, regenerate random
states, or substitute a Python ISA interpreter. Every checked response comes
from lane V's compiled Lean reference. Full GPRs, defined arithmetic flags,
SIMD, architectural stack bytes and all observed memory bytes are compared.
The only composite paths admitted are the same finite byte-extent witnesses
already described in x86-control-reference/README.md.

```sh
taskset -c 20-23 make -C kprog/fidelity reference-build
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/x86-movx-reference reference
```

The replay returns1 for the retained model differences and remaining decoder
work. reference-forms.tsv records the count and outcome for all799 forms;
reference-mismatches.jsonl.gz retains every mismatch input and CPU/model/
reference output. The executable and exact canonical source are archived as
reference.gz and canonical-source.tar.gz. source-provenance.txt records the
publication HEAD and the empty canonical-source diff. Production observer
source/binary and CPU provenance remain in x86-full-conditions/. V's published
MOVX full formal check is84897937a; this increment changes no production or
canonical semantics. Actual high-byte MOVX forms are the next observer-bank
extension and are not silently included in these26 older forms.
