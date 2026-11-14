# Next completed census observations

The ongoing canonical resident census completed three further request rows
after the published 13-row queue prefix: body68 has a stack-access rejection,
body69 installed, and body70 has a context-access rejection. `outcomes.csv`
and `requests.json` retain their application, request, completion clock and
full persistent archive paths. These are load-only observations from the
retained producer; whole-application execution retains its separate work item.

Body70 provides a concrete context-access failure class: the generated B loads
the original context pointer from its stack, adds constant80, then accesses
offset0 through that modified pointer. The stock verifier reports
`dereference of modified ctx ptr R7 off=80 disallowed` after13,303 processed
instructions. Its complete loader diagnostic and generation metadata are
retained alongside this report. The program type is KPROBE. The next compiler
investigation is canonical representation of context-relative loads, with
the shared simulator C remaining under FORMAL's ownership.

The raw journal and every request archive remain under
`/workspaces/kprog-raw/perf/20261114-census-resume/control`. This small receipt
adds failure evidence; the prior cumulative census receipt remains the
published aggregate until its next complete suffix collection.
