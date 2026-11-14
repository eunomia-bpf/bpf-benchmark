# Further tracing-context rejection: body72

The ongoing census completed `trace_ret_vfs_writev`, request18/body72, at
21:33:08Z. Stock rejects `*(u32 *)(r7+0)` when r7 carries original ctx+80,
after13303 processed instructions. This is the same concrete representation
class already observed for body70, whose generic context-load compiler
replay is queued after the active OTel application. This observation does
not require another long duplicate frontend replay.

`request.json` retains the full persistent failure-archive path/size and
completion clocks; `diagnostic-tail.txt` preserves the failing instructions.
The full journal/archive remains raw evidence. The queue now has18 completed
rows, adding one attempt/body to the prior receipt: cumulative68 attempts /
63 distinct bodies, latest26 installed /33 verifier rejected /4 compile
failed. The old retained producer is still in use; these are load-only
outcomes, with no application or equal-work certification.
