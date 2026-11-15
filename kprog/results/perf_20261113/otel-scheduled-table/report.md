# Actual OTel scheduled relative-table dependency

Read-only measurement 2026-11-15, current canonical header-route object at
vendor/build/native-bpf/x86/7.0.0-rc2+/native/otel/otelcol-ebpf-profiler.native.o.
SHA and full symbol disassembly are retained here; no second object build or
source copy was made. Command: objdump -dr -Mintel
--disassemble=kprobe_unwind_hotspot <object>.

The actual sequence is:

```
1560 lea rcx,[rip+0]     R_X86_64_PC32 .rodata+0x6c
1567 movsxd rdx,DWORD PTR [rcx+rax*4]
156b add rdx,rcx
156e mov eax,1
1573 jmp rdx
```

The strict adjacent-four matcher in x86_readonly_relocs.rs and
x86_relative_tables.py misses the scheduled MOV. Rust already handles an ELF
section symbol as RelocationTarget::Symbol; absence of that handling is not
the demonstrated cause. The source table base is 0x70 after the PC32 bias in
this current object, correcting the earlier handoff's zero-addend description.

A wider window followed by dispatch on RAX at the JMP would be wrong: EAX=1
has overwritten the index. Dispatching at LEA directly to the case bodies
would skip the observable MOV. The fix must capture finite code identity
before the overwrite and retain scheduled effects, or perform an equivalent
proven dependency transformation. Base/result/flag liveness and external CFG
entries remain relevant. Existing CODE capabilities provide the needed value
namespace without adding an ISA opcode. No matcher/lowering fix, app load or
performance result is claimed in this receipt.
