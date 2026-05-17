# x86 eBPF VM Prototype

This prototype asks one small question: can an eBPF program interpret a compact
x86-like instruction stream and pass the normal eBPF verifier?

The initial smoke case mirrors `micro/programs/simple.bpf.c`:

```c
*out = 12345678ULL;
```

The Rust loader builds a packet containing:

```text
mov rax, 12345678
ret
```

The BPF program interprets the packet instruction stream, writes `rax` to the
first eight packet bytes, and returns `XDP_PASS`. The loader runs it with
`BPF_PROG_TEST_RUN` and checks that the output value is `12345678`.

## Build And Run

```sh
make -C ebpf-vm/x86 run
```

This is a functional prototype, not a benchmark entrypoint.

## Input ABI

Packet layout:

```text
0x00..0x07: output slot, overwritten with little-endian rax
0x08..0x0b: magic "XVM1"
0x0c..0x0d: instruction count
0x0e..0x0f: reserved
0x10..    : fixed 16-byte instruction records
```

Instruction record:

```text
byte 0: opcode
byte 1: dst register
byte 2: src register
byte 3: flags/reserved
byte 4..7: reserved / future branch offset
byte 8..15: little-endian immediate
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
