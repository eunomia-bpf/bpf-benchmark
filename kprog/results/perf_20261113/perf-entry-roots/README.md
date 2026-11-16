2026-11-16T09:01:39Z

Section program entries have two independent lifetime boundaries in embedded
frontend IR. LLVM module linking drops unused internal definitions, and runtime
O3 drops an unused internal entry before the context compiler finds it. The
original ELF still contains these programs. OTel's aggregate lost ten perf_*
entries; actual go_labels unit IR also failed the old runtime tool.

The IR linker preserves explicitly sectioned program definitions as external
roots before ordinary LLVM module linking. Ordinary internal helpers remain
private. vendor/bpf/Makefile uses it only for the embedded aggregate module;
machine-object aggregation and every app's native compile flags stay unchanged.
The runtime compiler also preserves the selected entry before both O3 pipelines.

Existing public-context and production-loader checks each pass256 cases. The
added static-entry fixture passes256 contexts; the old tool fails actual
perf_go_labels unit IR. The actual combined OTel unit IR now retains all11
perf_* entries (including native_tracer_entry), and perf_go_labels context
conversion plus native-link proof succeeds. This is selected-entry source
correctness evidence, not app unwind-counter parity or a performance result.

Full current six-app replay and coherent image publication follow this subset.
Raw: /workspaces/kprog-raw/perf/20261116-perf-entry-roots. The source and entry
metadata are not inferred from application names. No benchmark, image definition
or workload changed.
