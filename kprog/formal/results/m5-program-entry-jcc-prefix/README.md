# Original JCC width selector and context read to the real condition call

The original post-memcpy JCC constant comparison32<=64 enters its original nested loop. The actual ctx.mark field load at offset8 reaches the real condition Scall with precisely the original nested continuations. The checked source executes13 internal transitions and preserves the reached heap and saved temps outside t136/t161.

Focused build 471 and 1 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
