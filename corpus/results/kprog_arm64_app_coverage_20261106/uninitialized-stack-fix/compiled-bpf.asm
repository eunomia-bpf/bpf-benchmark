
corpus/results/kprog_arm64_app_coverage_20261106/uninitialized-stack-fix/objects/uninitialized_stack.bpf.o:	file format elf64-bpf

Disassembly of section xdp:

0000000000000000 <uninitialized_stack_arm64_sim_xdp>:
       0:	79 a0 f8 ff 00 00 00 00	r0 = *(u64 *)(r10 - 0x8)
       1:	95 00 00 00 00 00 00 00	exit
