# Execute the real kernel memcpy source-end and destination-end additions

The two actual kernel generic prologue words execute imported DPR shifted-register ADD with arbitrary physical source/destination/count, deriving X4=source+count and X5=destination+count with wrapping64 arithmetic. Their genuine fetched Reference steps share the same original Code and complete program, with derived second PC/fetch, no events/fault, unchanged memory/profile/history/monitors/thread and every field except PC/X4/X5. Final PC is generic origin+12. The input PC is explicitly generic origin+4, after its BTI landing pad; landing-pad/alternative execution and the following real comparison/pair-copy path continue as separate required bindings.

Focused build 77 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
