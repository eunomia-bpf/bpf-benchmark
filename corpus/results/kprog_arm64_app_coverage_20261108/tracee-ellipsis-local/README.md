Paired ARM Tracee existing ellipsis offset clamp

The original d920fbca5 paired ARM runtime7c9fe02ed reaches JIT syscall__execve_enter B2155: probe_read_str receives maxoffset65672 with4096bytes against32536byte event_data_map. The existing ellipsis clamp is carried through a u32 local and empty register asm; identical cap and field writeback feed the same helper. Full selected C tree is identical for native/JIT; prior checked string offset and four size barriers remain. Native O3 and original JIT flags/canonical ARM cross-library paths are retained. Actual Makeexit:0.

Source-change patch/ledger follow successful paired compilation. Kernel selftests/safety source stay published. Runtime admission additions:0.
