# Current production RORX CPU and canonical check

Consume published 2b1ab2c29's shared RORX handler using the existing native
instruction generator, observer and production encoder. The selection adapter
adds exactly one pair-filter line after the original generator constructs its
complete matrix; all four existing RORX forms remain in order. Native code,
random states, defined flag masks, state/memory observation and canonical ISA
are unchanged. No production source is edited.

The independent warm build-x86-rorx directory preserves the active 1144-form
reference reader's build-x86 inputs. It compiles only the affected forms rather
than another complete matrix. The completed result has been independently reviewed below.

~~~sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-rorx-current/Makefile reference
~~~

The command generates the selected harness through the existing generator,
then uses the standard fidelity Make build and frozen c110 canonical reference.
Exact launch source and actual compiled inputs are archived separately.

## Complete result

The Make build/native CPU/reference job exits **0**. All **4 forms x 1024 =
4096 states** have **zero CPU/C, CPU/reference and C/reference differences**;
zero forms are unavailable. forms.tsv and reference-forms.tsv retain every
count, and all three compressed counterexample/unavailable streams are empty.
The forms are register-source and memory-source RORX at32/64-bit widths with
immediate7. The two register forms execute the new direct shared C macro;
the two memory forms retain the existing generic memory route as controls.

The exact compiled header matches C’s published2b1ab2c29/47fb5565 snapshot.
All 91 actual compilation files and 82 copied production source files are
independently checked against their archive hashes and that Git publication.
The static executable SHA256 is 613cb2637e315b9dd20c2f9d42e2d8b75a8867d6568d0f4510b930ab16aa8069.
The reference is the same frozen c110 executable; no canonical model was
created or changed. selection-review.json proves that the only generator
source delta is one post-construction pair filter. Native state seeding,
observer code and defined-flag/memory masks are untouched. The original
7438360-byte state trace remains in this Workspace, with its layout and SHA
recorded in summary.json. Any later physical source drift is explicit.

## Retained initial selection error

The first adapter selected X86_OP_RORX alone, omitting the separate memory
opcode. Its two register forms completed2048 CPU/C/reference cases with zero
differences, then the F collector correctly failed the expected-four-form
completeness assertion. attempt-register-only.tar.gz retains all 110 original
raw/source/static/control files, independently verified against their hashes.
The corrected predicate includes both RORX opcodes and still requires exactly
four forms. No result, flag or memory oracle was weakened to pass the retry.

This is focused evidence for the published RORX change, separate from the
1144-form4fe CMP replay still awaiting its terminal review. It is not coverage
of every register alias, immediate, encoding, whole ISA/ABI or all29 micro
acceptance. The C lane owns the remaining actual application admission work.
