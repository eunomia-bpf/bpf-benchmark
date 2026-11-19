
/workspaces/kprog-raw/perf/constant-alu32-20261119/candidate-20261119T1131Z/fixture.o:	file format elf64-bpf

Disassembly of section .text:

0000000000000000 <constant8>:
       0:	b4 00 00 00 08 00 00 00	w0 = 0x8
       1:	95 00 00 00 00 00 00 00	exit

0000000000000010 <constant4>:
       2:	b4 00 00 00 04 00 00 00	w0 = 0x4
       3:	95 00 00 00 00 00 00 00	exit

0000000000000020 <constant_negative>:
       4:	b4 00 00 00 ff ff ff ff	w0 = -0x1
       5:	95 00 00 00 00 00 00 00	exit

0000000000000030 <constant_high>:
       6:	b4 00 00 00 00 00 00 80	w0 = -0x80000000
       7:	95 00 00 00 00 00 00 00	exit

0000000000000040 <live>:
       8:	bc 10 00 00 00 00 00 00	w0 = w1
       9:	bc 00 00 00 00 00 00 00	w0 = w0
      10:	95 00 00 00 00 00 00 00	exit

0000000000000058 <memory_clobber>:
      11:	b4 00 00 00 08 00 00 00	w0 = 0x8
      12:	bc 00 00 00 00 00 00 00	w0 = w0
      13:	95 00 00 00 00 00 00 00	exit

0000000000000070 <wide>:
      14:	b7 00 00 00 08 00 00 00	r0 = 0x8
      15:	bf 00 00 00 00 00 00 00	r0 = r0
      16:	95 00 00 00 00 00 00 00	exit
