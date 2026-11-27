# Execute fetched LDRB with the actual initialized read and zero-extended X3

Real word39400023 is kernel-decoded as LDRB W3,[X1]. The mature imported checked load consumes the exact checked1-byte read result, writes the zero-extended byte to X3 and advances actual PC by4. Original fetch/error gating derives stepi_checked; Reference.AArch64.step emits precisely the appended initialized read and preserves earlier access history in the complete machine. X1 is not written. Actual memory/profile/other fields of the read result survive; the original source reader supplies the same read/error/history observations next.

Focused build 397 and 3 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
