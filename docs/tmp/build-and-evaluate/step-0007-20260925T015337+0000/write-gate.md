# Targeted WRITE Gate

Date: 2026-09-25T02:38:00+00:00

The targeted paper edit touches only RQ2 in
`sections/5-evaluation-plan.tex` and the paper repository's evidence-status
README.  Its role is to add the accepted input-class observation after the RQ2
experimental requirements.  It does not alter the paper's four questions,
architecture, throughput table, abstract, introduction, or conclusion.

The maximum reader-facing claim is: in one retained Cilium policy startup, all
3,787 optimizer-reported applied-entry occurrences across 122 changed load
instances referenced workdir-local metadata naming a frozen
`.rodata.config` array.  Invalid before-image evidence remains only in the
parent evaluation/history and is not included in paper prose.

Verification checks the complete paper diff, LaTeX brace balance, whitespace,
references, and a full build when a TeX toolchain is available.  No new
citation, macro, label, package, table row, or figure is introduced.

The final verification installed the missing local TeX packages outside the
repository and ran:

```sh
latexmk -g -pdf -interaction=nonstopmode -halt-on-error main.tex
```

The complete six-page paper built successfully.  The log has no undefined
reference or citation warning; existing layout warnings remain non-fatal.  The
build changed no tracked generated file in the paper repository.
