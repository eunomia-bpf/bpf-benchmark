
/workspaces/.agent-state/kprog-lanes/F/context-artifact-inspect/arm64.bpf.o:	file format elf64-bpf

Disassembly of section xdp:

0000000000000000 <trusted_arm64_arm64_sim_xdp>:
       0:	61 12 00 00 00 00 00 00	r2 = *(u32 *)(r1 + 0x0)
       1:	7b 2a d8 ff 00 00 00 00	*(u64 *)(r10 - 0x28) = r2
       2:	61 11 04 00 00 00 00 00	r1 = *(u32 *)(r1 + 0x4)
       3:	7b 1a e0 ff 00 00 00 00	*(u64 *)(r10 - 0x20) = r1
       4:	7a 0a e8 ff 00 00 00 00	*(u64 *)(r10 - 0x18) = 0x0
       5:	7a 0a f0 ff 00 00 00 00	*(u64 *)(r10 - 0x10) = 0x0
       6:	62 0a f8 ff 00 00 00 00	*(u32 *)(r10 - 0x8) = 0x0
       7:	bf a1 00 00 00 00 00 00	r1 = r10
       8:	07 01 00 00 d8 ff ff ff	r1 += -0x28
       9:	b7 02 00 00 00 00 00 00	r2 = 0x0
      10:	7b 21 00 00 00 00 00 00	*(u64 *)(r1 + 0x0) = r2
      11:	b4 00 00 00 02 00 00 00	w0 = 0x2
      12:	95 00 00 00 00 00 00 00	exit
