# verifier_scalar_memory_access: where the scalar base comes from

Census class `verifier: Rn invalid mem access 'scalar'` of the master-grouped
resident census (model 46659115e): 230 instances, 116 bodies (Tracee 104 bodies,
Tetragon 11, Cilium 1). B's state representation stays as it is; this directory
records the measured origin of every rejected access and what each representation
option would take. The choice belongs to the operator.

`origin.py <outcomes.json.gz> rows.json` reads each body's verifier log, takes the
rejected instruction and walks the log backwards from its base register through
register copies and constant arithmetic to the instruction that produced the value.
rows.json holds one row per body (instances = census members of that body).

| Origin of the scalar base | Instances | Bodies | Applications (instances) |
| --- | ---: | ---: | --- |
| return value of `bpf_get_current_task` (P reads `task_struct` fields directly) | 154 | 82 | Tracee 75, Tetragon 79 |
| pointer read through another scalar pointer | 48 | 6 | Tetragon 43, Cilium 3, Tracee 2 |
| pointer loaded from ctx (tracepoint/kprobe arguments) | 17 | 17 | Tracee 17 |
| pointer loaded from a map value | 6 | 6 | Tracee 6 |
| pointer loaded from a stack slot without a pointer tag | 5 | 5 | Tracee 4, Tetragon 1 |

Accesses: 187 instances (113 bodies) are loads; 43 instances (3 Tetragon bodies:
generic_kprobe_actions 33, generic_retkprobe 9, generic_rawtp 1) are one-byte
stores through a pointer that B read back from memory as a scalar.

Example (tracepoint__sched__sched_process_exec, Tracee):

```
43: (85) call bpf_get_current_task#35   ; R0=scalar()
...
82: (07) r3 += 4                        ; R3=scalar(id=9+4)
...
102: (61) r2 = *(u32 *)(r3 +0)
R3 invalid mem access 'scalar'
```

## What the model does today

A native load whose base register carries the SCALAR tag goes through
X86_SIM_L_READ_RECOVERY_AT: when the address is below 4096 or an unspecified input
bit is set, the destination becomes 0 (the native fault-recovery path); otherwise B
performs the raw load at that address, and the stock verifier rejects a load through
a scalar. Every row above stops at that raw load or store.

## Options

1. **Keep the representation (current).** The 230 instances stay rejected.
   Nothing changes.

2. **Read SCALAR-tagged bases through `bpf_probe_read_kernel` in B.** In the
   non-recovered branch of every memory-reading handler (MOV_LOAD, ALU_MEM,
   CMP_MEM, MOVX, ...) B copies `width` bytes from the address into a stack
   temporary with the helper and uses that value. The verifier accepts a scalar
   source address for this helper (tracing program types, and every type under
   CAP_PERFMON). Coverage: all 187 load instances, every origin class. The 43 store
   instances stay rejected (no helper writes kernel memory). Faithfulness needs the
   native load to return exactly what the helper returns: the same bytes when the
   address is readable and 0 with execution continuing when it faults, that is an
   exception-table fixup on each such native load that zeroes the destination; the
   recovered branch already models the zero result. Work: the handlers'
   scalar-base path in x86_sim_local_bpf.h (and the arm64 model), O1 re-proof of
   those handlers (V), the extable fixup in native-link and the kernel if it is not
   already emitted for these loads, and one helper call per such load in B
   (verifier instruction count grows; P is unchanged).

3. **Typed task pointer.** B obtains the task through
   `bpf_get_current_task_btf` (PTR_TO_BTF_ID task_struct) and a new register tag
   carries that type; field loads become verifier-checked BTF accesses (PROBE_MEM,
   0 on fault). Coverage: at most the 154 `bpf_get_current_task` instances, and
   only where every load offset and width matches a `task_struct` member
   (btf_struct_access rejects reads that straddle members); the ctx, map-value and
   stack origins (28) and the stores (43) stay rejected. Work: a new tag and BTF
   type tracking in the register file, generator support for the typed helper, the
   same extable fixup on P as option 2, and O1 re-proof.

4. **Produce P with helper reads.** The producer of P keeps the source's
   `bpf_probe_read_kernel` calls as helper calls instead of lowering them to
   direct loads; B already represents helper calls, so the model and kernel stay as
   they are. Coverage: the loads that come from probe-read sites in the source
   (Tracee's and Tetragon's CO-RE reads); direct dereferences in the source stay
   rejected. Cost lands on the optimization track: one helper call per read in P.

Options 2 and 3 change B's representation and need the operator's decision;
option 4 is a producer choice on lane C's track.
