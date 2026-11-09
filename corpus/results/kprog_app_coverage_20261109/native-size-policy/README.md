# Native size-oriented compilation before submission

Whole BCC and Katran native producers compile with Os from their published C and helper ABI, including the existing generic division pass. Canonical production flags keep O3. The prior973fabf0a O3 control has identical source dependency hashes. Actual12/12native objects compile successfully; executable sections total17815bytes at O3 and16443bytes at Os, a7.70%reduction. Whole five-step loading, matching work and R timing follow the existing detached queue.

| Native object | O3 executable bytes | Os executable bytes | Change |
| --- | ---: | ---: | ---: |
| bcc/biosnoop.native.o | 1293 | 1208 | -85 |
| bcc/capable.native.o | 646 | 647 | +1 |
| bcc/opensnoop.native.o | 824 | 830 | +6 |
| bcc/runqlat.native.o | 1477 | 1249 | -228 |
| bcc/syscount.native.o | 540 | 529 | -11 |
| bcc/tcpconnect.native.o | 1540 | 1374 | -166 |
| bcc/tcplife.native.o | 1494 | 1054 | -440 |
| bcc/vfsstat.native.o | 148 | 148 | +0 |
| katran/balancer.native.o | 8250 | 7879 | -371 |
| katran/healthchecking.native.o | 1154 | 1121 | -33 |
| katran/healthchecking_ipip.native.o | 381 | 336 | -45 |
| katran/xdp_root.native.o | 68 | 68 | +0 |

The BCC hot syscount entries shrink112to110bytes at sys_enter and428to419bytes at sys_exit. The combined2.04%code-size change identifies a small static opportunity in these hot entries. Katran balancer shrinks8250to7879bytes across executable sections; its XDP section shrinks7931to7575bytes. BCC tcplife accounts for440bytes and runqlat228bytes of the aggregate reduction. Per-section counts and immutable object hashes accompany section-comparison.json and summary.json. Instruction count, dynamic call frequency and throughput retain separate meanings.

The next structural opportunity is pre-submit helper/map lowering, guided by R's actual runtime attribution. Required-bound application loading reads the original native ELF and submits those bytes in native_submit. The trusted worker's existing link schema resolves its helper ABI and keeps the submitted instruction bodies. Its array/hash/LRU lowering plan is used by the unbound path. Moving an equivalent optimization into the ELF producer before submission gives B the actual optimized P and preserves the same-copy JIT design. Existing map/function relocations carry the physical bindings; simulator and universal link semantics cover the resulting operations. producer-boundary.json records exact current source hashes and observation locations. Kernel step(e) and benchmark workload retain their existing definitions.

The active canonical SMAP BCC/Katran cohort2776127 precedes native Os controller2805722. The latter refreshes its retained producer cache and captures the canonical runtime/source epoch for the application replay. Original38 b44ff4ff79b551f208055d1b39ec2c49543ccd76 records9valid executions,28verifier rejections,1generation frontier and risky native executions0. R owns restored2026-05-29 timing against JIT; actual matching-work receipts supply the subsequent Timing request. Compiler commands, source dependencies and complete objects remain in raw.tar.gz. Runtime admission additions0.
