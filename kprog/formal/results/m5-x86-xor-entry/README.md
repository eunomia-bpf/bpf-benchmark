# Original XOR handler call through operand dispatch

The genuine eight-argument/nine-local handler entry, real width helper and
aux decoding now compose with both complete scalar-reader calls and original
XOR selection gates through arithmetic dispatch. This includes different
registers and equal registers with different lane shifts. The actual entry
allocation frame supplies all five post-entry header/word/tag observations
from caller observations. The complete input caller memory is preserved
beneath the allocated handler frame. Both helper results follow from their
complete checked executions.

The execution lengths are214/222/230/230 for byte/word/dword/qword inputs.
The scalar, non-RSP, non-stack-tag and valid shift premises are explicit.
The matched-register/lane zero shortcut remains separately proved in48.
XOR arithmetic, flags, writeback and native-state composition remain open;
instruction-family refinement continues with those components.

Focused175 jobs pass in3.03s, with one direct-import type/axiom query.
See the retained output and validation metadata. Limits stay at200000/512,
one worker and32GiB under shared timing. Raw attempts remain in
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.
