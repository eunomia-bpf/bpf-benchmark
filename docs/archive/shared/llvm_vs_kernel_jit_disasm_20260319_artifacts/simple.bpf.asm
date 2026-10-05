
/home/yunwei37/workspace/bpf-benchmark/micro/programs/simple.bpf.o:	file format elf64-bpf

Disassembly of section xdp:

0000000000000000 <simple_xdp>:
       0:	r0 = 0x0
       1:	r2 = *(u32 *)(r1 + 0x4)
       2:	r1 = *(u32 *)(r1 + 0x0)
       3:	if r1 > r2 goto +0x13 <LBB0_4>
       4:	r3 = r1
       5:	r3 += 0x8
       6:	if r3 > r2 goto +0x10 <LBB0_4>
       7:	r3 = r1
       8:	r3 += 0x48
       9:	if r3 > r2 goto +0xd <LBB0_4>
      10:	r2 = 0xbc
      11:	*(u8 *)(r1 + 0x2) = r2
      12:	r2 = 0x61
      13:	*(u8 *)(r1 + 0x1) = r2
      14:	r2 = 0x4e
      15:	*(u8 *)(r1 + 0x0) = r2
      16:	r2 = 0x0
      17:	*(u8 *)(r1 + 0x6) = r2
      18:	*(u8 *)(r1 + 0x5) = r2
      19:	*(u8 *)(r1 + 0x4) = r2
      20:	*(u8 *)(r1 + 0x3) = r2
      21:	*(u8 *)(r1 + 0x7) = r2
      22:	r0 = 0x2

00000000000000b8 <LBB0_4>:
      23:	exit
