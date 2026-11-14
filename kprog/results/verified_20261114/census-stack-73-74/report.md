# Two further stock-verifier stack rejections

The existing retained-producer census completed Tracee body73/request19,
trace_ret_vfs_writev_tail, at22:54:52Z: eight-byte fp-536 write rejected after
4922 processed instructions/356 states. Body74/request20,
trace_ret_arch_prctl, completed23:04:09Z: four-byte fp-728 write rejected
after3685 instructions/260 states. Both complete request archives and all
failure logs remain under the persistent raw paths in requests.json.

The queue now has20 completed rows. Relative to the body72 receipt, these
add two attempts/bodies: cumulative70 attempts/65 distinct bodies, latest26
installed/35 verifier-rejected/4 compile-failed. This is the old retained
producer and a load-only census; no application execution or equal-work
success is claimed. The optional scalar-group mechanism has only focused
kernel acceptance; its real-main annotation failure remains open. These
new stack observations do not establish that packing alone can fix them.
Target-BTF CO-RE integration stays ahead of further spill work.
