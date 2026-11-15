#!/bin/sh
# Read the live .rodata.var map while OTel runs.
#
# native_stack_trace.ebpf.c declares task_stack_offset and stack_ptregs_offset as
# BPF_RODATA_VAR(u32, ..., 0) in section .rodata.var, "set during load time". The loader
# fills that section as a map. If the native replacement reads a frozen copy of the zeros
# instead of this map, get_task_pt_regs() computes task+0 and every sample fails the
# usermode test -- which is the 74M UnwindNativeErrReadKernelModeRegs signature.
for cid in $(docker ps -q 2>/dev/null); do
    docker exec "$cid" sh -c 'command -v otelcol-ebpf-profiler >/dev/null' 2>/dev/null || continue
    bt=/usr/local/bin/bpftool
    docker exec "$cid" $bt map dump name .rodata.var 2>&1 | head -20
    exit 0
done
exit 1
