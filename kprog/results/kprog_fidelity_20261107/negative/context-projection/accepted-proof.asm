
/workspaces/.agent-state/kprog-lanes/F/context-artifact-inspect/accepted.bpf.o:	file format elf64-bpf

Disassembly of section xdp:

0000000000000000 <trusted_x86_x86_sim_xdp>:
       0:	61 12 00 00 00 00 00 00	r2 = *(u32 *)(r1 + 0x0)
       1:	7b 2a d8 ff 00 00 00 00	*(u64 *)(r10 - 0x28) = r2
       2:	61 11 04 00 00 00 00 00	r1 = *(u32 *)(r1 + 0x4)
       3:	7b 1a e0 ff 00 00 00 00	*(u64 *)(r10 - 0x20) = r1
       4:	7a 0a e8 ff 00 00 00 00	*(u64 *)(r10 - 0x18) = 0x0
       5:	7a 0a f0 ff 00 00 00 00	*(u64 *)(r10 - 0x10) = 0x0
       6:	62 0a f8 ff 00 00 00 00	*(u32 *)(r10 - 0x8) = 0x0
       7:	b7 90 01 00 02 00 00 00	<unknown>
       8:	b7 01 00 00 00 00 00 00	r1 = 0x0
       9:	b7 02 00 00 00 00 00 00	r2 = 0x0
      10:	bf a3 00 00 00 00 00 00	r3 = r10
      11:	07 03 00 00 d8 ff ff ff	r3 += -0x28
      12:	0f 32 00 00 00 00 00 00	r2 += r3
      13:	7b 12 00 00 00 00 00 00	*(u64 *)(r2 + 0x0) = r1
      14:	b4 00 00 00 02 00 00 00	w0 = 0x2
      15:	95 00 00 00 00 00 00 00	exit
