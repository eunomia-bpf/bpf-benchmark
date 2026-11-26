# Original Clight JCC label targets and reconstructed continuations

Both JCC targets are extracted from the actual original function body. Kernel-checked source equalities compare those cached targets with imported Clight.findLabel on the full source and callCont. The actual local fallthrough resumes Sskip in its inner loop; the taken target resumes the original next labelled body with the genuine remaining suffix. Both actual goto transitions use CC.Step.goto and retain the same heap, original environment and saved temps. Source nodes are cached one at a time at the original proof caps.

Focused build 472 and 6 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
