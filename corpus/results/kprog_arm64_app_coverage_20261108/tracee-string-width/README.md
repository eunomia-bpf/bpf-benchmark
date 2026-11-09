Tracee string-offset width and verifier register relation

Actual original two-start source218ccbc34/747723132 baseline reaches sys_exit_submit B1367 bpf_probe_read_str. The existing bound narrows zero-extendedR1 to27899 while the helper address uses the originalR2 with range65535; its address grows to65677 on the32536byte map. This source changes only save_str_to_buf local offset fromu32 tou64, keeping both existing empty register operands and every condition/limit/helper argument/field update. The initial u16 field is promoted to the same runtime value, and all bounded arithmetic remains below2^32. A64/BPF frontends consume the same32file selected C tree. The64bit compiler operand carries the existing comparison and pointer arithmetic in one register width. Actual compilation and whole-app verifier outcomes follow their own receipts. Benchmark framework and kernel selftests retain published bytes. Runtime admission additions:0.

Actual paired Makeexit:0
