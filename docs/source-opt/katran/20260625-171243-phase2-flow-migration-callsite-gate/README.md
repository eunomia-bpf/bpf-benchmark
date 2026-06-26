# katran diagnostic: flow-migration callsite gate

Status: diagnostic-rejected

This branch tested moving the UDP flow-migration `dst/proto/flag` guard to the
call site while keeping the down-real map lookup inside
`check_udp_flow_migration()`.

Diagnostic result:
- Clean `balancer.bpf.o` xdp section: `0x4870`.
- Phase2 attempt 1 xdp section: `0x4798`.
- This diagnostic xdp section: `0x47c8`.

Decision:
- Not promoted to a formal `make corpus` run because it was larger than the
  accepted phase2 attempt 1 object.
- Not counted as a phase2 performance attempt.
- Build log: `build.log`.
