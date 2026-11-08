Paired ARM Tracee existing ellipsis offset clamp

The original d920fbca5 paired ARM runtime7c9fe02ed reaches JIT syscall__execve_enter B2155: probe_read_str receives maxoffset65672 with4096bytes against32536byte event_data_map. The existing ellipsis clamp is carried through a u32 local and empty register asm; identical cap and field writeback feed the same helper. Full selected C tree is identical for native/JIT; prior checked string offset and four size barriers remain. Native O3 and original JIT flags/canonical ARM cross-library paths are retained. Actual Makeexit:0.

Source-change patch/ledger follow successful paired compilation. Kernel selftests/safety source stay published. Runtime admission additions:0.

Compiler trialfe7f824ff: native/JIT/embedded binary all build at exit0. Canonical source follows C shared20096bb3c update_min repair, which covers every existing clamp through one shared register operand. The [private local-offset patch](../kprog_app_source_changes/tracee-ellipsis-local-compiler-trial.patch) records this alternative compiler trial; its before/after/full-source and output bytes remain archived. The full application successor uses the shared20096 source. Closed private duplicates are retired after published byte matches.
