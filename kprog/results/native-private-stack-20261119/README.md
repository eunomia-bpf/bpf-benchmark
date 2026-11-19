# Native private-arena normalization

packet_bounds_ir.cpp:108-135 already treats the simulator's private stack arena
as ordinary Mem storage in B. The native compiler reuses the earlier frontend,
so it misses this normalization. Actual Tetragon request6 reports 93,924 such
accesses in B; native still sees their volatile forms. This prevents ordinary
scalar replacement and dead-store elimination in the native LTO pipeline.

The prepared native patch transfers exactly that existing rule: every underlying
object must be a local alloca of union.x86_sim_stack_mem. Real context/global
storage, mixed local/external origins, other local types and atomics retain their
volatility. No program check, B change, packet-bounds lowering or helper policy.

The fixture exercises those scope boundaries with actual LLVM conversion and
native execution. Baseline mode checks the current missed normalization. Source
application/build waits for the running Tetragon job's image SH lease to end.
