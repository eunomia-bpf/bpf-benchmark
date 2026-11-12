# Probe-read candidate contract comparison, 2026-11-12

This is a source comparison of lane C's build-only candidate
`vendor/bpf/native_specialize_probe_reads.py`. It adds no execution results.
The serial resident census continues with model d0890b14f and its retained
helper calls. Repairs in the native specialization rule belong to lane C;
the request was posted in COORDINATION.md at 18:03:50 UTC.

## Emitted read behavior

The candidate's `BODY` template emits:

```c
if ((unsigned long)from == 0)
    return -14;
__builtin_memcpy(dst, from, size);
return 0;
```

Its `checked` substitution is a comment containing the source expression.
There is no helper invocation in the emitted body. Returning on a null
source leaves the destination unchanged. Other addresses receive an ordinary
copy and success return, without the kernel helper's nofault access or
address-domain handling. The template comments and module documentation say
unhandled cases delegate to the helper; the emitted code has no such path.

The sole kernel, vendor/linux-framework at 74d1097af561, implements
`bpf_probe_read_kernel_common` in `include/linux/bpf.h:3381` as:

```c
int ret = -EFAULT;
if (IS_ENABLED(CONFIG_BPF_EVENTS))
    ret = copy_from_kernel_nofault(dst, unsafe_ptr, size);
if (unlikely(ret < 0))
    memset(dst, 0, size);
return ret;
```

`bpf_probe_read_user_common` in `kernel/trace/bpf_trace.c:173` likewise calls
`copy_from_user_nofault` and zeroes all destination bytes on a negative return.
`copy_from_kernel_nofault` in `mm/maccess.c:29` returns `-ERANGE` when its
address-domain predicate fails, uses nofault loads with page faults disabled,
and returns `-EFAULT` through its fault label. These observable return values
and destination effects need preservation by a shared lowering rule. No
claim about a particular address faulting in an executed candidate is made.

## Helper identifiers and source attribution

The candidate maps 112 to `bpf_probe_read_kernel` and 113 to
`bpf_probe_read_user`. The kernel UAPI helper list at
`include/uapi/linux/bpf.h:6018` defines 112 as `probe_read_user` and 113 as
`probe_read_kernel`. Both IDs enter the same replacement body, so the reversed
labels currently affect the report and would also misdirect any helper-specific
repair using that dictionary.

`replace()` assigns `base, offset = source_address(source)` but never uses
either result. It emits `(const void *)({source})` with the original source
expression, and the generated function receives `const void *from`. The
claimed separate typed-operand lowering is absent from this implementation.
Whether emitted B retains a usable pointer type must be established from B
and verifier state; a C `void *` cast by itself does not establish type loss.

The documentation's example at
`vendor/bpf/tetragon/bpf/process/generic_calls.h:923` calls `write_user_arg`.
Its input `val` is declared `unsigned long`. Under `__V61_BPF_PROG`,
`write_user_arg` offloads a write through `write_offload`; the other definition
calls `probe_write_user(addr, &value, sizeof(value))`. This example concerns a
write request using an integer address and supplies no read-pointer provenance
evidence for the proposed read lowering.

## Requested shared repair

Lane C was asked to preserve helper read/error effects, correct the ID names,
and align the emitted operand handling and source explanation with the actual
implementation. Its builder integration is a separate lane-owned change.
No kernel, image, base, benchmark setting, B-model source, or census input
changed for this comparison. Application loaded/verified/run counts remain
those recorded in the actual run receipts.
