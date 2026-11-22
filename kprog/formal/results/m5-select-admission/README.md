# Seventh native fetch admission

The actual six imported MOV/MOVK/ADD/register-ADD/MUL/CMP steps transport the
original seventh fetch at PC+24 to the reached machine. The proof derives its
PC, error state and unchanged program from the same fetched/decoded predecessors.
It assumes no fetch or error premise at a constructed successor. Input-view
setup carries the same result through the real provider/native binding.

All operations use the existing external ISA steps and state writers. This
proof supplies admission to CSEL; it does not substitute a local decoder or
instruction body. Focused271 and two public queries pass at original limits,
CPU17, one worker and32GiB under the shared timing lock. Initial PC/flag
simplification diagnostics remain in raw data. M5/M6, full handlers and
O1/O2/O4 remain open, completed ISA families0.

Raw: /workspaces/kprog-raw/formal/m5-select-call/20261122T115647Z.
