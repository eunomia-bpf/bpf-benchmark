# x86 Micro Proof TODO

Goal: generate one eBPF verifier artifact per `micro/programs/*.md` native x86
program, with the x86 instruction sequence hardcoded in the generated `.bpf.c`.

Rules:

- No `manifest.json`.
- Generated `.bpf.c` files include only `../x86_vm_bpf.h`, the instruction
  sequence, the XDP entry, and `X86_VM_LICENSE()`.
- Every generated instruction line must carry a source comment with the original
  native ASM address and text.
- Do not put the whole x86 program in a BPF stack array. Use per-instruction
  immediate macros so LLVM can constant-fold the verifier artifact.
- Unsupported x86 syntax is a bug to fix in the parser/interpreter, not metadata
  to hide.
- Each generated artifact must at least compile to BPF and load through the
  verifier. Runtime equivalence is a later proof obligation.

Checklist:

- [x] Refactor VM API to per-instruction macros with no `const struct x86_insn[]`
      stack array.
- [x] Add generator script in `ebpf-vm/x86/micro-prog/`.
- [x] Generate all micro `.bpf.c` proof artifacts from `## Native ASM`.
- [ ] Add enough x86 opcode encodings and parser support for every native ASM
      instruction found in the 29 micro programs.
- [ ] Build every generated BPF object.
- [ ] Load every generated BPF object with `BPF_PROG_TEST_RUN` to confirm verifier
      acceptance.
- [x] Record current verifier failures as concrete unsupported VM/parser defects.
- [ ] Replace the branchy generic interpreter expansion with generated per-op BPF
      semantics for large programs such as `bpf_local_call_fanout_dispatch`.
