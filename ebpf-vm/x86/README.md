# x86 eBPF VM Prototype

This prototype asks one small question: can an eBPF program interpret a compact
x86-like instruction stream and pass the normal eBPF verifier?

The initial smoke case mirrors `micro/programs/simple.bpf.c`:

```c
*out = 12345678ULL;
```

The hardcoded verifier artifact represents this x86-like instruction sequence:

```text
mov rax, 12345678
ret
```

The BPF program interprets the hardcoded instruction stream, writes `rax` to the
first eight packet bytes, and returns `XDP_PASS`. The loader runs it with
`BPF_PROG_TEST_RUN` and checks that the output value is `12345678`.

The instruction sequence is hardcoded in the `.bpf.c` file, while all VM
machinery lives in headers.

The specialized artifact is the more relevant ReverseJIT direction. It uses a
single include plus a local instruction array inside the program entry:

```c
#include "x86_vm_bpf.h"

#define SIMPLE_X86_PROG_LEN 2

#define SIMPLE_X86_PROG_INIT                                                \
	{                                                                   \
		{ X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL },       \
		{ X86_OP_RET, 0, 0, 0, 0, 0 },                              \
	}

SEC("xdp")
int x86_vm_hardcoded_xdp(struct xdp_md *ctx)
{
	const struct x86_insn prog[SIMPLE_X86_PROG_LEN] = SIMPLE_X86_PROG_INIT;

	return X86_VM_RUN_XDP(ctx, prog, SIMPLE_X86_PROG_LEN);
}
```

The program is not a global variable and is not emitted as a `.rodata` map.
`x86_vm_bpf.h` includes the BPF entry helpers, result writer, and unrolled
interpreter runner. `x86_interp.h` contains the instruction semantics. LLVM
currently folds the two-instruction `simple` case into straight-line BPF that
writes `12345678` directly.

## Build And Run

```sh
make -C ebpf-vm/x86 run
```

This is a functional prototype, not a benchmark entrypoint.

If unprivileged BPF is disabled, build as the normal user and run the loader with
privilege:

```sh
make -C ebpf-vm/x86 build
sudo ebpf-vm/loader/target/debug/ebpf-vm-loader \
  --object ebpf-vm/x86/build/x86_vm_hardcoded.bpf.o \
  --program x86_vm_hardcoded_xdp \
  --case simple
```

Observed smoke result:

```text
case=simple retval=2 result=12345678 repeat=1 data_size_out=48
```

Object inspection for the hardcoded artifact:

```text
no .maps section
no .rodata section
xdp section size: 0xa0 bytes
```

Supported opcodes:

- `0x01`: `mov r64, imm64`
- `0x02`: `mov r64, r64`
- `0x03`: `add r64, imm64`
- `0x04`: `add r64, r64`
- `0x05`: `xor r32, r32` with x86 zero-extension semantics
- `0xff`: `ret`

Register numbers follow the usual x86 encoding order: `rax=0`, `rcx=1`,
`rdx=2`, `rbx=3`, `rsp=4`, `rbp=5`, `rsi=6`, `rdi=7`, `r8=8`, ... `r15=15`.
