# Actual ARM64 conditional-select path call

`Arm64SelectPathCall.lean` executes the actual successor of condition site35: two caller steps, the real linked Numeric path helper26, then three steps to return, resume and select the original pointer/tag branch128 or numeric branch129. All eight conditional-select codes and every byte-width ABI value are covered. The uint opcode and uchar width undergo their real unsigned casts to ulong. Binding99 is checked against the existing linked source world.

The 31-step certificate preserves the whole memory, environment and caller continuation and changes only result temporary162. `execute_condition` composes the earlier real NZCV loads/EQ call/normalization35 with this certificate into66 steps, deriving opcode/width observations through the earlier temporary frame. The fixture's plain CSEL28/width8 reaches the actual pointer/tag source branch. Both selected suffixes remain live and untouched: this does not yet execute the selected raw/tag readers or writer, complete the handler or establish the seventh native call.

Focused build254 passed; all five public type/axiom queries passed with the same 200000-heartbeat/512-depth limits, CPU17, one worker and32GiB. The receipt records exact source/dependency/query hashes, timings and retained failed attempts. The only build correction unfolds the existing boolean type conversion during caller resume. No new axiom, native oracle, runtime, benchmark or performance-path change was introduced.

Next preserve the selected raw/tag pair, including source2's actual STACK4 coordinate, through the original pointer writer and imported native CSEL transition. M5/O1/O2/O4 and M6 remain open; complete ISA families remain zero.
