# Published x86 shifts versus CPU and canonical reference

All192 supported SHL/SHR/SAR/ROL forms agree with the real x86-64 CPU and
V's canonical native-byte reference on196,608 states. Each form has1024
cases; per-form counts are in `forms.tsv` and `reference-forms.tsv`.

| Family | Forms | Cases | CPU/C differences | CPU/reference differences | C/reference differences |
| --- | ---: | ---: | ---: | ---: | ---: |
| SHL |48|49,152|0|0|0|
| SHR |48|49,152|0|0|0|
| SAR |48|49,152|0|0|0|
| ROL |48|49,152|0|0|0|
| Existing auxiliary observers |42|43,008|0|not replayed here|not replayed here|

The auxiliary observers are36 conditional branches, one JMP, one CALL and
four REP MOVS blocks. Total CPU/C coverage is234forms/239,616cases/zero
differences. Only the192 shift forms were selected for this canonical
replay; no broader reference-coverage closure is claimed.

Four operand widths, immediate boundary counts and CL counts are covered.
The existing harness cycles all64 arithmetic-flag input combinations,
starts with boundary values then deterministic random values, and compares
all16 GPRs, XMM0,64 stack bytes and256 external-memory bytes. Defined flags
are compared: AF after nonzero shifts, OF for counts above1 and CF outside
the shift width are not architecturally defined. Count-zero preservation
and width-specific masking are checked by the canonical step. These
register-only reference requests must produce no fault or memory event,
unchanged bytes and exactly the observed next PC. This is serialization of
V's canonical decoder/step, not another instruction interpreter.

Production snapshot789b1d9c6c0f04f5668df6b88f200e4ae0487944 is archived in
`producer-source.tar.gz`; every archived source blob was compared to that
published commit with zero differences. It excludes C's concurrent stack
prototype. Canonical source335ea332aefe535fc1395139a820227fb64e6047 and its
built executable are archived separately. Frozen generated code, static CPU
binary, host/seed metadata and all logs are retained. Build/CPU/reference
stages each exited0. No production semantics were changed for this run.

The first attempted matrix mistakenly added classical ROR, which the
production encoder explicitly rejects (`unsupported mnemonic: ror al,0x0`).
`first-ror-rejected/` retains that source, exact build diagnostic and stages.
It never reached CPU execution and is not a mismatch or an accepted unsafe
program. The successful run removes that unsupported test addition. RORX
is separate; V's later canonical ROR support does not add a production ROR
handler.

Commands through bws.sh, from `/workspaces/repository`:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-shifts-published build cpu reference
```

Use `OUT=/absolute/new-directory` for a fresh CPU run/replay; the directory
must be different from a retained result. The executable reference restores
from `reference.gz`; its build log and pinned formal sources are included.
The selected canonical reference consumes the SAME newly generated states
as the successful CPU/C comparison, not the old816-form trace retired by
the disk cleanup. After publication/no readers, this run's435,142,680-byte
raw trace is also deleted per coordinator instruction. Its SHA256 is in
`trace-retention.json`. Summaries, exact source/binaries and empty mismatch
files remain; a future CPU invocation generates a new run (ASLR can differ).
