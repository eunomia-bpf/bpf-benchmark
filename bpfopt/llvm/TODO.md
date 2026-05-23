# bpfopt LLVM TODO

## Post-Lowering Repair Audit

- [x] Remove the tracked `src/main.cpp.bak` source backup.
- [x] Delete the semantic verifier repair layer after LLVM BPF codegen:
  range-copy retargeting, zero-extended signed-jump retargeting,
  mod/shift pointer bounds insertion, packet byte bounds insertion, and
  dead-ALU cleanup.
- [x] Remove the remaining memory-address canonicalization from post-lowering
  extraction until a verifier failure proves it is needed.
- [ ] If verifier coverage exposes the old `tmp = base; tmp += const;
  *(tmp + off)` issue, fix it in the LLVM BPF backend/MachineInstr path or in
  IR/lowering, not as a default post-lowering bytecode rewrite.
- [ ] Run verifier corpus coverage through the normal `make` entrypoint and
  capture every remaining failure as a fixture.
- [ ] Do not add a new post-lowering verifier repair without a minimal input
  bytecode, unrepaired O3 output, verifier log, and a documented reason it
  cannot live in IR or the BPF backend.
