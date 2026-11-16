2026-11-16T04:35:18Z

BCC tcp_v4_connect_ret B preparation fails before stock loading: libbpf cannot find BTF for extern count_v4.zero. Its native metadata binds that symbol to value offset0 of the captured map. Generated C declares the C identifier __x86_trusted_map_1 with asm name count_v4.zero and __ksym.

Actual B LLVM IR contains external global @count_v4.zero without a !dbg attachment, and an orphan DIGlobalVariable named __x86_trusted_map_1. Actual ELF has undefined count_v4.zero. BTF contains neither corresponding variable. The attached BTF dump/undefined-symbol list and full raw actual.bc/actual.ll/actual.bpf.o preserve this evidence. This is an asm-named extern/debug-BTF emission class, not a missing kernel function or source change.

A future fix must preserve explicit symbol identity and attach the correct variable metadata; positional matching of orphan debug declarations to globals would be ambiguous. No B compiler fix or stock acceptance is claimed here. Native continuation now covers this preparation failure, while the underlying BTF class remains open. Raw `/workspaces/kprog-raw/perf/20261116-btf-extern-observation`; source request is in the completed BCC checked archive.
