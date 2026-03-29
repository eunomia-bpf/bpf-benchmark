# llvmbpf Round-Trip POC Report (2026-03-29)

## Question

Can we take BPF bytecode, lift it with `llvmbpf`, lower it back with the LLVM BPF backend, and still pass kernel verifier on `BPF_PROG_LOAD`?

## Short Answer

- `identity` round-trip does **not** currently work with the vendored `llvmbpf` IR as-is.
- `llvmbpf lift -> opt -O0 -> llc -march=bpf` crashes inside LLVM BPF instruction selection.
- `llvmbpf lift -> opt -O2 -> llc -march=bpf -> raw BPF -> BPF_PROG_LOAD` **does work** for a minimal XDP program.
- So the minimal POC result is: **round-trip is feasible, but not as a no-op identity pipeline. It requires LLVM optimization to canonicalize the lifted IR before the BPF backend can lower it.**

## Scope And Caveat

- I used `micro/programs/simple.bpf.o` as the source program because it is small and has no map relocations.
- The vendored CLI is `vendor/llvmbpf/cli/bpftime-vm`.
- This CLI lifts from an eBPF ELF via libbpf program iteration. It does **not** accept a raw kernel-dumped `xlated` bytecode blob on stdin.
- Because of that limitation, this POC starts from the ELF code section rather than `bpftool prog dump xlated`.
- Verifier validation was done in the VM via direct `BPF_PROG_LOAD` syscall on raw instruction bytes, which is explicitly allowed by the task.

## Files Produced

- Script: `docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_roundtrip_poc.py`
- Host summary: `docs/tmp/20260329/llvmbpf_roundtrip_poc/host_prepare_summary.json`
- Guest summary: `docs/tmp/20260329/llvmbpf_roundtrip_poc/guest_verify_summary.json`
- Lifted IR: `docs/tmp/20260329/llvmbpf_roundtrip_poc/lifted_simple.ll`
- O2 round-trip object: `docs/tmp/20260329/llvmbpf_roundtrip_poc/roundtrip_simple_O2_v3.o`
- Raw original bytecode: `docs/tmp/20260329/llvmbpf_roundtrip_poc/original_simple_xdp.bin`
- Raw round-trip bytecode: `docs/tmp/20260329/llvmbpf_roundtrip_poc/roundtrip_simple_O2.bin`

## Environment

- Repo root: `/home/yunwei37/workspace/bpf-benchmark`
- Host LLVM: 18.1.3
- Guest kernel: `7.0.0-rc2+`
- Guest validation path: `make vm-shell ... python3 ... guest-verify`

## Step 1: llvmbpf CLI

The repo already vendors `llvmbpf` under `vendor/llvmbpf`, so no external clone was needed.

Build commands:

```bash
cmake -S vendor/llvmbpf -B docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_build \
  -DBUILD_LLVM_AOT_CLI=ON -DCMAKE_BUILD_TYPE=Release \
  -DLLVM_DIR=/usr/lib/llvm-18/lib/cmake/llvm
make -C docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_build -j4 bpftime-vm-cli
```

Built CLI:

```text
docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_build/cli/bpftime-vm
```

CLI note:

- `bpftime-vm --help` is not implemented in this vendored CLI.
- Running it with no arguments prints usage and exits with code `1`.
- Usage text is captured in `docs/tmp/20260329/llvmbpf_roundtrip_poc/bpftime_vm_usage.stderr.log`.

## Step 2: Source Program

I used:

```text
micro/programs/simple.bpf.o
```

Canonical build entry:

```bash
make -C micro programs
```

Reason:

- It is a tiny XDP program.
- No map relocations.
- Good enough to isolate the lift/lower question from relocation complexity.

Original disassembly excerpt:

```text
0000000000000000 <simple_xdp>:
       0: r0 = 0x0
       1: r2 = *(u32 *)(r1 + 0x4)
       2: r1 = *(u32 *)(r1 + 0x0)
       ...
      22: r0 = 0x2
      23: exit
```

## Step 3: Lift To LLVM IR

Command:

```bash
docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_build/cli/bpftime-vm \
  build micro/programs/simple.bpf.o \
  -o docs/tmp/20260329/llvmbpf_roundtrip_poc \
  -emit-llvm \
  > docs/tmp/20260329/llvmbpf_roundtrip_poc/lifted_simple.ll
```

Observed:

- Lift succeeded.
- The lifted IR contains a synthesized VM-style frame/register model.
- It also contains a `callStack`/`callItemCnt` path and an `indirectbr`, even for this simple single-function program.

Relevant lifted IR excerpt:

```llvm
%callStack = alloca ptr, i32 320, align 8
%callItemCnt = alloca i64, align 8
...
indirectbr ptr %63, []
```

## Step 4: Identity Attempt

Commands:

```bash
llvm-as lifted_simple.ll -o lifted_simple.bc
opt -O0 lifted_simple.ll -o optO0_simple.bc
llc -march=bpf -mcpu=v3 -filetype=obj optO0_simple.bc -o roundtrip_simple_O0_v3.o
```

Result:

- `llvm-as` succeeded.
- `opt -O0` succeeded.
- `llc` failed with `SIGABRT`.

Failure excerpt:

```text
LLVM ERROR: Cannot select: ... ch = brind ...
In function: bpf_main
```

Interpretation:

- The lifted IR is not directly consumable by the LLVM BPF backend in this form.
- The immediate blocker is the `indirectbr`/`brind`-style control flow that survives the raw lift.

## Step 5: O2 Canonicalization

Commands:

```bash
opt -O2 lifted_simple.ll -o optO2_simple.bc
llc -march=bpf -mcpu=v3 -filetype=obj optO2_simple.bc -o roundtrip_simple_O2_v3.o
```

Result:

- Both commands succeeded.
- The output object is `ELF 64-bit relocatable, eBPF`.

Section summary:

```text
.text size: 192 bytes
```

Instruction count:

- Original raw `xdp` section: `192 bytes / 24 insns`
- Round-trip O2 `.text` section: `192 bytes / 24 insns`

Round-trip disassembly excerpt:

```text
0000000000000000 <bpf_main>:
       0: r0 = 0x0
       1: r2 = *(u32 *)(r1 + 0x0)
       2: r1 = *(u32 *)(r1 + 0x4)
       ...
      22: r0 = 0x2
      23: exit
```

The generated bytecode is not textually identical to the original, but it is the same size and semantically equivalent for this case.

## Step 6: Verifier Validation In VM

I dumped raw instruction bytes:

```bash
llvm-objcopy --dump-section xdp=original_simple_xdp.bin micro/programs/simple.bpf.o
llvm-objcopy --dump-section .text=roundtrip_simple_O2.bin roundtrip_simple_O2_v3.o
```

Then I loaded both binaries inside the VM using direct `BPF_PROG_LOAD` from:

```text
docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_roundtrip_poc.py guest-verify
```

VM command:

```bash
make vm-shell VM_COMMAND='python3 /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/llvmbpf_roundtrip_poc/llvmbpf_roundtrip_poc.py guest-verify --orig-bin /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/llvmbpf_roundtrip_poc/original_simple_xdp.bin --roundtrip-bin /home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260329/llvmbpf_roundtrip_poc/roundtrip_simple_O2.bin'
```

Verifier result:

```json
{
  "original": {
    "insn_cnt": 24,
    "status": "ok",
    "verifier_log": "processed 27 insns (limit 1000000) max_states_per_insn 0 total_states 2 peak_states 2 mark_read 0\n"
  },
  "roundtrip_o2": {
    "insn_cnt": 24,
    "status": "ok",
    "verifier_log": "processed 27 insns (limit 1000000) max_states_per_insn 0 total_states 2 peak_states 2 mark_read 0\n"
  }
}
```

This is the core positive result:

- The round-tripped bytecode produced after `llvmbpf lift -> opt -O2 -> LLVM BPF backend` **does pass the kernel verifier**.

## Final Conclusion

For this minimal XDP program:

- `BPF bytecode -> llvmbpf lift -> LLVM IR -> opt -O2 -> llc -march=bpf -> BPF bytecode -> BPF_PROG_LOAD`
  is **successful**.
- `identity` lowering without meaningful optimization is **not** successful with the current lifted IR shape.

So the precise answer is:

- **Yes, round-trip through verifier is possible.**
- **No, not as a strict identity/no-opt pipeline with the current vendored llvmbpf IR.**

## Why Identity Fails

The specific failure is not a verifier rejection. It fails earlier in codegen:

- `llvmbpf` emits VM-style control-flow scaffolding.
- That IR retains an `indirectbr` path.
- LLVM's BPF backend crashes trying to select it.
- `opt -O2` is sufficient here to simplify the IR into a form the BPF backend can lower.

## What I Did Not Attempt

- I did **not** do the `map_lookup_elem -> constant` edit from Step 8.
- I stopped there because the base `identity` path already fails before verifier, so the first blocker is clearly the lifted IR shape.
- I also intentionally avoided map-relocation handling in this POC so the result stays focused on the lift/lower/verifier question.

## Next Useful Follow-Ups

- Use a map-using test case and add explicit relocation patching in the guest loader so helper/map paths can be validated too.
- Minimize the exact pass set required to remove `indirectbr`; `-O2` works, but it is broader than necessary.
- Investigate whether `llvmbpf` can emit a backend-friendly IR mode for BPF re-lowering without VM call-stack scaffolding.
