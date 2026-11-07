
/workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/bcc-memory-v35/native/bcc_opensnoop_tracepoint__syscalls__sys_exit_openat.proof.o:	file format elf64-littleaarch64

Disassembly of section .text:

0000000000000000 <tracepoint__syscalls__sys_exit_openat>:
       0: d10643ff     	sub	sp, sp, #0x190
       4: a9167bfd     	stp	x29, x30, [sp, #0x160]
       8: a91757f6     	stp	x22, x21, [sp, #0x170]
       c: a9184ff4     	stp	x20, x19, [sp, #0x180]
      10: aa0003f3     	mov	x19, x0
      14: 9100a3e0     	add	x0, sp, #0x28
      18: 2a1f03e1     	mov	w1, wzr
      1c: 52802702     	mov	w2, #0x138              // =312
      20: 94000036     	bl	0xf8 <__kprog_memset>
      24: 94000000     	bl	0x24 <tracepoint__syscalls__sys_exit_openat+0x24>
		0000000000000024:  R_AARCH64_CALL26	bpf_get_current_pid_tgid
      28: b9000fe0     	str	w0, [sp, #0xc]
      2c: 90000000     	adrp	x0, 0x0 <tracepoint__syscalls__sys_exit_openat>
		000000000000002c:  R_AARCH64_ADR_GOT_PAGE	start
      30: 910033e1     	add	x1, sp, #0xc
      34: f9400000     	ldr	x0, [x0]
		0000000000000034:  R_AARCH64_LD64_GOT_LO12_NC	start
      38: 94000000     	bl	0x38 <tracepoint__syscalls__sys_exit_openat+0x38>
		0000000000000038:  R_AARCH64_CALL26	bpf_map_lookup_elem
      3c: b4000520     	cbz	x0, 0xe0 <tracepoint__syscalls__sys_exit_openat+0xe0>
      40: 90000008     	adrp	x8, 0x0 <tracepoint__syscalls__sys_exit_openat>
		0000000000000040:  R_AARCH64_ADR_GOT_PAGE	targ_failed
      44: b9401274     	ldr	w20, [x19, #0x10]
      48: f9400108     	ldr	x8, [x8]
		0000000000000048:  R_AARCH64_LD64_GOT_LO12_NC	targ_failed
      4c: 39400108     	ldrb	w8, [x8]
      50: 34000048     	cbz	w8, 0x58 <tracepoint__syscalls__sys_exit_openat+0x58>
      54: 36f803f4     	tbz	w20, #0x1f, 0xd0 <tracepoint__syscalls__sys_exit_openat+0xd0>
      58: aa0003f5     	mov	x21, x0
      5c: 94000000     	bl	0x5c <tracepoint__syscalls__sys_exit_openat+0x5c>
		000000000000005c:  R_AARCH64_CALL26	bpf_get_current_pid_tgid
      60: d360fc08     	lsr	x8, x0, #32
      64: b90033e8     	str	w8, [sp, #0x30]
      68: 94000000     	bl	0x68 <tracepoint__syscalls__sys_exit_openat+0x68>
		0000000000000068:  R_AARCH64_CALL26	bpf_get_current_uid_gid
      6c: 9100a3f6     	add	x22, sp, #0x28
      70: b90037e0     	str	w0, [sp, #0x34]
      74: 52800201     	mov	w1, #0x10               // =16
      78: 9100a2c0     	add	x0, x22, #0x28
      7c: 94000000     	bl	0x7c <tracepoint__syscalls__sys_exit_openat+0x7c>
		000000000000007c:  R_AARCH64_CALL26	bpf_get_current_comm
      80: f94002a2     	ldr	x2, [x21]
      84: 9100e2c0     	add	x0, x22, #0x38
      88: 52801fe1     	mov	w1, #0xff               // =255
      8c: 94000000     	bl	0x8c <tracepoint__syscalls__sys_exit_openat+0x8c>
		000000000000008c:  R_AARCH64_CALL26	bpf_probe_read_user_str
      90: b9400aa8     	ldr	w8, [x21, #0x8]
      94: 910043e1     	add	x1, sp, #0x10
      98: aa1303e0     	mov	x0, x19
      9c: 52800302     	mov	w2, #0x18               // =24
      a0: 290723f4     	stp	w20, w8, [sp, #0x38]
      a4: 52802003     	mov	w3, #0x100              // =256
      a8: 94000000     	bl	0xa8 <tracepoint__syscalls__sys_exit_openat+0xa8>
		00000000000000a8:  R_AARCH64_CALL26	bpf_get_stack
      ac: a941a7e8     	ldp	x8, x9, [sp, #0x18]
      b0: 90000001     	adrp	x1, 0x0 <tracepoint__syscalls__sys_exit_openat>
		00000000000000b0:  R_AARCH64_ADR_GOT_PAGE	events
      b4: 9100a3e3     	add	x3, sp, #0x28
      b8: aa1303e0     	mov	x0, x19
      bc: 12800002     	mov	w2, #-0x1               // =-1
      c0: 52802704     	mov	w4, #0x138              // =312
      c4: a90427e8     	stp	x8, x9, [sp, #0x40]
      c8: f9400021     	ldr	x1, [x1]
		00000000000000c8:  R_AARCH64_LD64_GOT_LO12_NC	events
      cc: 94000000     	bl	0xcc <tracepoint__syscalls__sys_exit_openat+0xcc>
		00000000000000cc:  R_AARCH64_CALL26	bpf_perf_event_output
      d0: 90000000     	adrp	x0, 0x0 <tracepoint__syscalls__sys_exit_openat>
		00000000000000d0:  R_AARCH64_ADR_GOT_PAGE	start
      d4: 910033e1     	add	x1, sp, #0xc
      d8: f9400000     	ldr	x0, [x0]
		00000000000000d8:  R_AARCH64_LD64_GOT_LO12_NC	start
      dc: 94000000     	bl	0xdc <tracepoint__syscalls__sys_exit_openat+0xdc>
		00000000000000dc:  R_AARCH64_CALL26	bpf_map_delete_elem
      e0: a9584ff4     	ldp	x20, x19, [sp, #0x180]
      e4: 2a1f03e0     	mov	w0, wzr
      e8: a95757f6     	ldp	x22, x21, [sp, #0x170]
      ec: a9567bfd     	ldp	x29, x30, [sp, #0x160]
      f0: 910643ff     	add	sp, sp, #0x190
      f4: 14000007     	b	0x110 <__native_link_arm64_ret_trampoline>

00000000000000f8 <__kprog_memset>:
      f8: aa0003e3     	mov	x3, x0
      fc: b4000082     	cbz	x2, 0x10c <__kprog_memset+0x14>
     100: 38001461     	strb	w1, [x3], #0x1
     104: f1000442     	subs	x2, x2, #0x1
     108: 54ffffc1     	b.ne	0x100 <__kprog_memset+0x8>
     10c: d65f03c0     	ret

0000000000000110 <__native_link_arm64_ret_trampoline>:
     110: aa0003e7     	mov	x7, x0
