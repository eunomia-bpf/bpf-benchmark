	.file	"linker.c"
	.text
.Ltext0:
	.file 0 "/home/yunwei37/workspace/bpf-benchmark/vendor/libbpf/src" "linker.c"
	.p2align 4
	.type	init_sec, @function
init_sec:
.LVL0:
.LFB169:
	.file 1 "linker.c"
	.loc 1 1141 1 view -0
	.cfi_startproc
	.loc 1 1142 2 view .LVU1
	.loc 1 1143 2 view .LVU2
	.loc 1 1144 2 view .LVU3
	.loc 1 1145 2 view .LVU4
	.loc 1 1147 2 view .LVU5
	.loc 1 1149 30 is_stmt 0 view .LVU6
	movzbl	21(%rdx), %eax
	.loc 1 1147 18 view .LVU7
	movl	$0, 48(%rsi)
	.loc 1 1148 2 is_stmt 1 view .LVU8
	.loc 1 1148 19 is_stmt 0 view .LVU9
	movq	$0, 16(%rsi)
	.loc 1 1149 2 is_stmt 1 view .LVU10
	.loc 1 1149 21 is_stmt 0 view .LVU11
	movb	%al, 12(%rsi)
	.loc 1 1152 2 is_stmt 1 view .LVU12
	.loc 1 1152 5 is_stmt 0 view .LVU13
	testb	%al, %al
	je	.L18
	.loc 1 1153 10 view .LVU14
	xorl	%eax, %eax
	.loc 1 1194 1 view .LVU15
	ret
	.p2align 4,,10
	.p2align 3
.L18:
	.loc 1 1141 1 view .LVU16
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdx, %rbp
	.loc 1 1155 2 is_stmt 1 view .LVU17
	.loc 1 1141 1 is_stmt 0 view .LVU18
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	.loc 1 1155 8 view .LVU19
	movq	16(%rdi), %rdi
.LVL1:
	.loc 1 1155 8 view .LVU20
	call	elf_newscn@PLT
.LVL2:
	.loc 1 1155 8 view .LVU21
	movq	%rax, %r15
.LVL3:
	.loc 1 1156 2 is_stmt 1 view .LVU22
	.loc 1 1156 5 is_stmt 0 view .LVU23
	testq	%rax, %rax
	je	.L5
	.loc 1 1158 2 is_stmt 1 view .LVU24
	.loc 1 1158 9 is_stmt 0 view .LVU25
	movq	%rax, %rdi
	call	elf_newdata@PLT
.LVL4:
	.loc 1 1158 9 view .LVU26
	movq	%rax, %r12
.LVL5:
	.loc 1 1159 2 is_stmt 1 view .LVU27
	.loc 1 1159 5 is_stmt 0 view .LVU28
	testq	%rax, %rax
	je	.L5
	.loc 1 1161 2 is_stmt 1 view .LVU29
	.loc 1 1161 9 is_stmt 0 view .LVU30
	movq	%r15, %rdi
	call	elf64_getshdr@PLT
.LVL6:
	.loc 1 1161 9 view .LVU31
	movq	%rax, %r13
.LVL7:
	.loc 1 1162 2 is_stmt 1 view .LVU32
	.loc 1 1162 5 is_stmt 0 view .LVU33
	testq	%rax, %rax
	je	.L5
	.loc 1 1165 2 is_stmt 1 view .LVU34
	.loc 1 1165 15 is_stmt 0 view .LVU35
	movq	%r15, 24(%rbx)
	.loc 1 1166 2 is_stmt 1 view .LVU36
	.loc 1 1168 21 is_stmt 0 view .LVU37
	movq	%r15, %rdi
	.loc 1 1166 16 view .LVU38
	movq	%rax, 32(%rbx)
	.loc 1 1167 2 is_stmt 1 view .LVU39
	.loc 1 1167 16 is_stmt 0 view .LVU40
	movq	%r12, 40(%rbx)
	.loc 1 1168 2 is_stmt 1 view .LVU41
	.loc 1 1168 21 is_stmt 0 view .LVU42
	call	elf_ndxscn@PLT
.LVL8:
	.loc 1 1170 13 view .LVU43
	movq	0(%rbp), %rsi
	movq	56(%r14), %rdi
	.loc 1 1168 19 discriminator 1 view .LVU44
	movq	%rax, 16(%rbx)
	.loc 1 1170 2 is_stmt 1 view .LVU45
	.loc 1 1170 13 is_stmt 0 view .LVU46
	call	strset__add_str@PLT
.LVL9:
	.loc 1 1171 2 is_stmt 1 view .LVU47
	.loc 1 1171 5 is_stmt 0 view .LVU48
	testl	%eax, %eax
	js	.L1
	.loc 1 1174 2 is_stmt 1 view .LVU49
	.loc 1 1175 2 view .LVU50
	.loc 1 1175 25 is_stmt 0 view .LVU51
	movq	40(%rbp), %rdx
	.loc 1 1174 16 view .LVU52
	movd	%eax, %xmm0
	.loc 1 1176 32 view .LVU53
	movq	8(%rdx), %rax
.LVL10:
	.loc 1 1174 16 view .LVU54
	movd	4(%rdx), %xmm1
	.loc 1 1177 16 view .LVU55
	movq	$0, 32(%r13)
	.loc 1 1182 16 view .LVU56
	movq	$0, 40(%r13)
	.loc 1 1176 17 view .LVU57
	movq	%rax, 8(%r13)
	.loc 1 1187 24 view .LVU58
	movq	48(%rbp), %rax
	.loc 1 1174 16 view .LVU59
	punpckldq	%xmm1, %xmm0
.LVL11:
	.loc 1 1184 36 view .LVU60
	movdqu	48(%rdx), %xmm2
	.loc 1 1174 16 view .LVU61
	movq	%xmm0, 0(%r13)
	.loc 1 1176 2 is_stmt 1 view .LVU62
	.loc 1 1177 2 view .LVU63
	.loc 1 1182 2 view .LVU64
	.loc 1 1183 2 view .LVU65
	.loc 1 1184 2 view .LVU66
	.loc 1 1187 30 is_stmt 0 view .LVU67
	movl	8(%rax), %edx
	.loc 1 1184 36 view .LVU68
	movups	%xmm2, 48(%r13)
	.loc 1 1185 2 is_stmt 1 view .LVU69
	.loc 1 1187 2 view .LVU70
	.loc 1 1190 31 is_stmt 0 view .LVU71
	movq	32(%rax), %rax
	.loc 1 1187 15 view .LVU72
	movl	%edx, 8(%r12)
	.loc 1 1188 2 is_stmt 1 view .LVU73
	.loc 1 1188 15 is_stmt 0 view .LVU74
	movq	$0, 16(%r12)
	.loc 1 1189 2 is_stmt 1 view .LVU75
	.loc 1 1189 14 is_stmt 0 view .LVU76
	movq	$0, (%r12)
	.loc 1 1190 2 is_stmt 1 view .LVU77
	.loc 1 1191 14 is_stmt 0 view .LVU78
	movq	$0, 24(%r12)
	.loc 1 1190 16 view .LVU79
	movq	%rax, 32(%r12)
	.loc 1 1191 2 is_stmt 1 view .LVU80
	.loc 1 1193 2 view .LVU81
	.loc 1 1153 10 is_stmt 0 view .LVU82
	xorl	%eax, %eax
.LVL12:
.L1:
	.loc 1 1194 1 view .LVU83
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
.LVL13:
	.loc 1 1194 1 view .LVU84
	popq	%rbp
	.cfi_def_cfa_offset 40
.LVL14:
	.loc 1 1194 1 view .LVU85
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
.LVL15:
	.loc 1 1194 1 view .LVU86
	popq	%r15
	.cfi_def_cfa_offset 8
.LVL16:
	.loc 1 1194 1 view .LVU87
	ret
.LVL17:
	.p2align 4,,10
	.p2align 3
.L5:
	.cfi_restore_state
	.loc 1 1157 10 view .LVU88
	movl	$-12, %eax
	jmp	.L1
	.cfi_endproc
.LFE169:
	.size	init_sec, .-init_sec
	.p2align 4
	.type	add_dst_sec, @function
add_dst_sec:
.LVL18:
.LFB151:
	.loc 1 312 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 313 2 view .LVU90
	.loc 1 312 1 is_stmt 0 view .LVU91
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.loc 1 314 25 view .LVU92
	movl	48(%r13), %eax
	.loc 1 313 18 view .LVU93
	movq	40(%rdi), %rdi
.LVL19:
	.loc 1 314 2 is_stmt 1 view .LVU94
	.loc 1 314 57 is_stmt 0 discriminator 1 view .LVU95
	leal	1(%rax), %ebx
	testl	%eax, %eax
	movl	$2, %eax
	movslq	%ebx, %rbx
	cmove	%rax, %rbx
.LVL20:
	.loc 1 316 2 is_stmt 1 view .LVU96
.LBB354:
.LBI354:
	.file 2 "libbpf_internal.h"
	.loc 2 208 21 view .LVU97
.LBB355:
	.loc 2 210 2 view .LVU98
	.loc 2 213 2 view .LVU99
	.loc 2 213 6 is_stmt 0 view .LVU100
	movl	$160, %eax
	mulq	%rbx
	jo	.L23
	movq	%rsi, %r12
	.loc 2 220 9 view .LVU101
	movq	%rax, %rsi
.LVL21:
	.loc 2 220 9 view .LVU102
	movq	%rax, %rbp
	.loc 2 220 2 is_stmt 1 view .LVU103
	.loc 2 220 9 is_stmt 0 view .LVU104
	call	realloc@PLT
.LVL22:
	.loc 2 220 9 view .LVU105
	movq	%rax, %r14
.LVL23:
	.loc 2 220 9 view .LVU106
.LBE355:
.LBE354:
	.loc 1 317 2 is_stmt 1 view .LVU107
	.loc 1 317 5 is_stmt 0 view .LVU108
	testq	%rax, %rax
	je	.L23
	.loc 1 321 2 is_stmt 1 view .LVU109
	.loc 1 321 53 is_stmt 0 view .LVU110
	movslq	48(%r13), %rax
.LVL24:
.LBB356:
.LBB357:
	.file 3 "/usr/include/x86_64-linux-gnu/bits/string_fortified.h"
	.loc 3 59 10 discriminator 1 view .LVU111
	movq	%rbp, %rcx
.LBE357:
.LBE356:
	.loc 1 321 45 view .LVU112
	movq	%rbx, %rdx
	.loc 1 321 14 view .LVU113
	leaq	(%rax,%rax,4), %rdi
	salq	$5, %rdi
.LVL25:
.LBB362:
.LBI356:
	.loc 3 57 1 is_stmt 1 view .LVU114
.LBB358:
	.loc 3 59 3 view .LVU115
	.loc 3 59 10 is_stmt 0 discriminator 1 view .LVU116
	cmpq	%rbp, %rdi
	cmovnb	%rdi, %rcx
.LBE358:
.LBE362:
	.loc 1 321 45 view .LVU117
	subq	%rax, %rdx
.LBB363:
.LBB359:
	.loc 3 59 10 discriminator 1 view .LVU118
	xorl	%esi, %esi
.LBE359:
.LBE363:
	.loc 1 321 2 view .LVU119
	leaq	(%rdx,%rdx,4), %rdx
.LBB364:
.LBB360:
	.loc 3 59 10 discriminator 1 view .LVU120
	subq	%rdi, %rcx
.LBE360:
.LBE364:
	.loc 1 321 2 view .LVU121
	salq	$5, %rdx
	.loc 1 321 14 view .LVU122
	addq	%r14, %rdi
.LVL26:
.LBB365:
.LBB361:
	.loc 3 59 10 discriminator 1 view .LVU123
	call	__memset_chk@PLT
.LVL27:
	.loc 3 59 10 discriminator 1 view .LVU124
.LBE361:
.LBE365:
	.loc 1 323 2 is_stmt 1 view .LVU125
	.loc 1 326 21 is_stmt 0 view .LVU126
	leaq	(%rbx,%rbx,4), %rax
	.loc 1 324 18 view .LVU127
	movl	%ebx, 48(%r13)
	.loc 1 327 20 view .LVU128
	subl	$1, %ebx
.LVL28:
	.loc 1 326 21 view .LVU129
	salq	$5, %rax
	.loc 1 323 15 view .LVU130
	movq	%r14, 40(%r13)
	.loc 1 324 2 is_stmt 1 view .LVU131
	.loc 1 326 2 view .LVU132
	.loc 1 328 18 is_stmt 0 view .LVU133
	movq	%r12, %rdi
	.loc 1 326 6 view .LVU134
	leaq	-160(%r14,%rax), %rbp
.LVL29:
	.loc 1 327 2 is_stmt 1 view .LVU135
	.loc 1 327 20 is_stmt 0 view .LVU136
	movl	%ebx, 8(%rbp)
	.loc 1 328 2 is_stmt 1 view .LVU137
	.loc 1 328 18 is_stmt 0 view .LVU138
	call	strdup@PLT
.LVL30:
	.loc 1 328 16 discriminator 1 view .LVU139
	movq	%rax, 0(%rbp)
	.loc 1 329 2 is_stmt 1 view .LVU140
	.loc 1 329 5 is_stmt 0 view .LVU141
	testq	%rax, %rax
	je	.L23
	.loc 1 333 1 view .LVU142
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbp, %rax
	popq	%rbp
	.cfi_def_cfa_offset 32
.LVL31:
	.loc 1 333 1 view .LVU143
	popq	%r12
	.cfi_def_cfa_offset 24
.LVL32:
	.loc 1 333 1 view .LVU144
	popq	%r13
	.cfi_def_cfa_offset 16
.LVL33:
	.loc 1 333 1 view .LVU145
	popq	%r14
	.cfi_def_cfa_offset 8
.LVL34:
	.loc 1 333 1 view .LVU146
	ret
.LVL35:
.L23:
	.cfi_restore_state
	.loc 1 318 10 view .LVU147
	xorl	%ebp, %ebp
	.loc 1 333 1 view .LVU148
	popq	%rbx
	.cfi_def_cfa_offset 40
	movq	%rbp, %rax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
.LVL36:
	.loc 1 333 1 view .LVU149
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE151:
	.size	add_dst_sec, .-add_dst_sec
	.p2align 4
	.type	add_src_sec, @function
add_src_sec:
.LVL37:
.LFB160:
	.loc 1 643 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 644 2 view .LVU151
	.loc 1 643 1 is_stmt 0 view .LVU152
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movq	%rdi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.loc 1 645 22 view .LVU153
	movl	64(%r14), %eax
	.loc 1 644 18 view .LVU154
	movq	56(%rdi), %rdi
.LVL38:
	.loc 1 645 2 is_stmt 1 view .LVU155
	.loc 1 645 51 is_stmt 0 discriminator 1 view .LVU156
	leal	1(%rax), %ebx
	testl	%eax, %eax
	movl	$2, %eax
	movslq	%ebx, %rbx
	cmove	%rax, %rbx
.LVL39:
	.loc 1 647 2 is_stmt 1 view .LVU157
.LBB366:
.LBI366:
	.loc 2 208 21 view .LVU158
.LBB367:
	.loc 2 210 2 view .LVU159
	.loc 2 213 2 view .LVU160
	.loc 2 213 6 is_stmt 0 view .LVU161
	movq	%rbx, %r13
	movq	%rbx, %rax
	salq	$6, %r13
	shrq	$58, %rax
	jne	.L37
	movq	%rsi, %r12
	.loc 2 220 2 is_stmt 1 view .LVU162
	.loc 2 220 9 is_stmt 0 view .LVU163
	movq	%r13, %rsi
.LVL40:
	.loc 2 220 9 view .LVU164
	call	realloc@PLT
.LVL41:
	.loc 2 220 9 view .LVU165
	movq	%rax, %rbp
.LVL42:
	.loc 2 220 9 view .LVU166
.LBE367:
.LBE366:
	.loc 1 648 2 is_stmt 1 view .LVU167
	.loc 1 648 5 is_stmt 0 view .LVU168
	testq	%rax, %rax
	je	.L37
	.loc 1 652 2 is_stmt 1 view .LVU169
	.loc 1 652 47 is_stmt 0 view .LVU170
	movslq	64(%r14), %rax
.LVL43:
.LBB368:
.LBB369:
	.loc 3 59 10 discriminator 1 view .LVU171
	movq	%r13, %rcx
.LBE369:
.LBE368:
	.loc 1 652 42 view .LVU172
	movq	%rbx, %rdx
	.loc 1 652 14 view .LVU173
	movq	%rax, %rdi
	salq	$6, %rdi
.LVL44:
.LBB374:
.LBI368:
	.loc 3 57 1 is_stmt 1 view .LVU174
.LBB370:
	.loc 3 59 3 view .LVU175
	.loc 3 59 10 is_stmt 0 discriminator 1 view .LVU176
	cmpq	%r13, %rdi
	cmovnb	%rdi, %rcx
.LBE370:
.LBE374:
	.loc 1 652 42 view .LVU177
	subq	%rax, %rdx
.LBB375:
.LBB371:
	.loc 3 59 10 discriminator 1 view .LVU178
	xorl	%esi, %esi
.LBE371:
.LBE375:
	.loc 1 652 2 view .LVU179
	salq	$6, %rdx
.LVL45:
.LBB376:
.LBB372:
	.loc 3 59 10 discriminator 1 view .LVU180
	subq	%rdi, %rcx
.LBE372:
.LBE376:
	.loc 1 652 14 view .LVU181
	addq	%rbp, %rdi
.LVL46:
.LBB377:
.LBB373:
	.loc 3 59 10 discriminator 1 view .LVU182
	call	__memset_chk@PLT
.LVL47:
	.loc 3 59 10 discriminator 1 view .LVU183
.LBE373:
.LBE377:
	.loc 1 654 2 is_stmt 1 view .LVU184
	.loc 1 655 15 is_stmt 0 view .LVU185
	movl	%ebx, 64(%r14)
	.loc 1 657 6 view .LVU186
	leaq	-64(%rbp,%r13), %rax
	.loc 1 658 20 view .LVU187
	subl	$1, %ebx
.LVL48:
	.loc 1 654 12 view .LVU188
	movq	%rbp, 56(%r14)
	.loc 1 655 2 is_stmt 1 view .LVU189
	.loc 1 657 2 view .LVU190
.LVL49:
	.loc 1 658 2 view .LVU191
	.loc 1 658 20 is_stmt 0 view .LVU192
	movl	%ebx, 8(%rax)
	.loc 1 659 2 is_stmt 1 view .LVU193
	.loc 1 659 16 is_stmt 0 view .LVU194
	movq	%r12, (%rax)
	.loc 1 661 2 is_stmt 1 view .LVU195
.LVL50:
	.loc 1 662 1 is_stmt 0 view .LVU196
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
.LVL51:
	.loc 1 662 1 view .LVU197
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
.LVL52:
	.loc 1 662 1 view .LVU198
	ret
.LVL53:
.L37:
	.cfi_restore_state
	.loc 1 662 1 view .LVU199
	popq	%rbx
	.cfi_def_cfa_offset 40
.LVL54:
	.loc 1 649 10 view .LVU200
	xorl	%eax, %eax
	.loc 1 662 1 view .LVU201
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
.LVL55:
	.loc 1 662 1 view .LVU202
	ret
	.cfi_endproc
.LFE160:
	.size	add_src_sec, .-add_src_sec
	.p2align 4
	.type	check_btf_type_id, @function
check_btf_type_id:
.LVL56:
.LFB165:
	.loc 1 1064 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 1064 1 is_stmt 0 view .LVU204
	endbr64
	.loc 1 1065 2 is_stmt 1 view .LVU205
	.loc 1 1064 1 is_stmt 0 view .LVU206
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	.loc 1 1064 1 view .LVU207
	movq	%rdi, %rax
	movq	%rsi, %rdi
.LVL57:
	.loc 1 1067 2 is_stmt 1 view .LVU208
	.loc 1 1067 6 is_stmt 0 view .LVU209
	movl	(%rax), %ebx
	.loc 1 1067 18 view .LVU210
	call	btf__type_cnt@PLT
.LVL58:
	.loc 1 1070 9 view .LVU211
	cmpl	%eax, %ebx
	.loc 1 1071 1 view .LVU212
	popq	%rbx
	.cfi_def_cfa_offset 8
	.loc 1 1070 9 view .LVU213
	sbbl	%eax, %eax
	notl	%eax
	andl	$-22, %eax
	.loc 1 1071 1 view .LVU214
	ret
	.cfi_endproc
.LFE165:
	.size	check_btf_type_id, .-check_btf_type_id
	.p2align 4
	.type	check_btf_str_off, @function
check_btf_str_off:
.LVL59:
.LFB166:
	.loc 1 1074 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 1074 1 is_stmt 0 view .LVU216
	endbr64
	.loc 1 1075 2 is_stmt 1 view .LVU217
	.loc 1 1074 1 is_stmt 0 view .LVU218
	movq	%rdi, %rax
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	.loc 1 1074 1 view .LVU219
	movq	%rsi, %rdi
.LVL60:
	.loc 1 1076 2 is_stmt 1 view .LVU220
	.loc 1 1078 2 view .LVU221
	.loc 1 1078 6 is_stmt 0 view .LVU222
	movl	(%rax), %esi
.LVL61:
	.loc 1 1078 6 view .LVU223
	call	btf__str_by_offset@PLT
.LVL62:
	.loc 1 1080 2 is_stmt 1 view .LVU224
	.loc 1 1083 9 is_stmt 0 view .LVU225
	cmpq	$1, %rax
	sbbl	%eax, %eax
.LVL63:
	.loc 1 1084 1 view .LVU226
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	.loc 1 1083 9 view .LVU227
	andl	$-22, %eax
	.loc 1 1084 1 view .LVU228
	ret
	.cfi_endproc
.LFE166:
	.size	check_btf_str_off, .-check_btf_str_off
	.p2align 4
	.type	add_btf_ext_rec, @function
add_btf_ext_rec:
.LVL64:
.LFB199:
	.loc 1 2614 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 2615 2 view .LVU230
	.loc 1 2617 2 view .LVU231
	.loc 1 2614 1 is_stmt 0 view .LVU232
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	.loc 1 2617 8 view .LVU233
	movq	0(%rbp), %rcx
.LBB378:
.LBB379:
	.loc 2 213 6 view .LVU234
	movl	8(%rbp), %eax
.LBE379:
.LBE378:
	.loc 1 2617 8 view .LVU235
	movq	16(%rdi), %rdi
.LVL65:
.LBB382:
.LBI378:
	.loc 2 208 21 is_stmt 1 view .LVU236
.LBB380:
	.loc 2 210 2 view .LVU237
	.loc 2 213 2 view .LVU238
.LBE380:
.LBE382:
	.loc 1 2617 8 is_stmt 0 view .LVU239
	leaq	1(%rcx), %rdx
.LVL66:
.LBB383:
.LBB381:
	.loc 2 213 6 view .LVU240
	mulq	%rdx
.LVL67:
	.loc 2 213 6 view .LVU241
	jo	.L58
	movq	%rsi, %r12
	.loc 2 220 9 view .LVU242
	movq	%rax, %rsi
.LVL68:
	.loc 2 220 9 view .LVU243
	movq	%rax, %rbx
	.loc 2 220 2 is_stmt 1 view .LVU244
	.loc 2 220 9 is_stmt 0 view .LVU245
	call	realloc@PLT
.LVL69:
	.loc 2 220 9 view .LVU246
.LBE381:
.LBE383:
	.loc 1 2618 2 is_stmt 1 view .LVU247
	.loc 1 2618 5 is_stmt 0 view .LVU248
	testq	%rax, %rax
	je	.L58
	.loc 1 2620 2 is_stmt 1 view .LVU249
	.loc 1 2622 37 is_stmt 0 view .LVU250
	movl	8(%rbp), %esi
	.loc 1 2622 27 view .LVU251
	movq	0(%rbp), %rdx
	.loc 1 2620 17 view .LVU252
	movq	%rax, 16(%rbp)
	.loc 1 2622 2 is_stmt 1 view .LVU253
	.loc 1 2622 27 is_stmt 0 view .LVU254
	imulq	%rsi, %rdx
.LBB384:
.LBB385:
	.loc 3 29 10 discriminator 1 view .LVU255
	cmpq	%rbx, %rdx
.LBE385:
.LBE384:
	.loc 1 2622 6 view .LVU256
	leaq	(%rax,%rdx), %rdi
.LVL70:
	.loc 1 2623 2 is_stmt 1 view .LVU257
.LBB388:
.LBI384:
	.loc 3 26 1 view .LVU258
.LBB386:
	.loc 3 29 3 view .LVU259
	.loc 3 29 10 is_stmt 0 discriminator 1 view .LVU260
	cmovnb	%rdx, %rbx
	movq	%rbx, %rcx
	subq	%rdx, %rcx
	movq	%rsi, %rdx
	movq	%r12, %rsi
.LVL71:
	.loc 3 29 10 discriminator 1 view .LVU261
	call	__memcpy_chk@PLT
.LVL72:
	.loc 3 29 10 discriminator 1 view .LVU262
.LBE386:
.LBE388:
	.loc 1 2625 19 view .LVU263
	addq	$1, 0(%rbp)
	.loc 1 2628 1 view .LVU264
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
.LBB389:
.LBB387:
	.loc 3 29 10 discriminator 1 view .LVU265
	movq	%rax, %rdi
.LVL73:
	.loc 3 29 10 discriminator 1 view .LVU266
.LBE387:
.LBE389:
	.loc 1 2625 2 is_stmt 1 view .LVU267
	.loc 1 2627 2 view .LVU268
	.loc 1 2628 1 is_stmt 0 view .LVU269
	popq	%rbp
	.cfi_def_cfa_offset 16
.LVL74:
	.loc 1 2628 1 view .LVU270
	popq	%r12
	.cfi_def_cfa_offset 8
.LVL75:
	.loc 1 2628 1 view .LVU271
	movq	%rdi, %rax
	ret
.LVL76:
.L58:
	.cfi_restore_state
	.loc 1 2619 10 view .LVU272
	xorl	%edi, %edi
	.loc 1 2628 1 view .LVU273
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
.LVL77:
	.loc 1 2628 1 view .LVU274
	movq	%rdi, %rax
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE199:
	.size	add_btf_ext_rec, .-add_btf_ext_rec
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"union"
.LC1:
	.string	"struct"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"libbpf: global '%s': incompatible forward declaration names '%s' and '%s'\n"
	.align 8
.LC3:
	.string	"libbpf: global '%s': incompatible %s forward declaration and concrete kind %s\n"
	.align 8
.LC4:
	.string	"libbpf: global '%s': incompatible BTF kinds %s and %s\n"
	.align 8
.LC5:
	.string	"libbpf: global '%s': incompatible %s names '%s' and '%s'\n"
	.align 8
.LC6:
	.string	"libbpf: global '%s': incompatible %s '%s' size %u and %u\n"
	.align 8
.LC7:
	.string	"libbpf: global '%s': incompatible func '%s' linkage\n"
	.align 8
.LC8:
	.string	"libbpf: global '%s': incompatible var '%s' linkage\n"
	.align 8
.LC9:
	.string	"libbpf: global '%s': incompatible number of %s fields %u and %u\n"
	.align 8
.LC10:
	.string	"libbpf: global '%s': incompatible field #%d names '%s' and '%s'\n"
	.align 8
.LC11:
	.string	"libbpf: global '%s': incompatible field #%d ('%s') offsets\n"
	.align 8
.LC12:
	.string	"libbpf: global '%s': incompatible number of %s params %u and %u\n"
	.align 8
.LC13:
	.string	"libbpf: global '%s': unsupported BTF kind %s\n"
	.text
	.p2align 4
	.type	glob_sym_btf_matches, @function
glob_sym_btf_matches:
.LVL78:
.LFB183:
	.loc 1 1485 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 1485 1 is_stmt 0 view .LVU276
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	.loc 1 1550 2 discriminator 1 view .LVU277
	leaq	.L85(%rip), %r13
	.loc 1 1485 1 view .LVU278
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%r8, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdx, %rbx
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	leaq	60(%rsp), %rax
	.loc 1 1485 1 view .LVU279
	movl	%ecx, 60(%rsp)
	movq	%rax, 8(%rsp)
	leaq	56(%rsp), %rax
	movl	%r9d, 56(%rsp)
	movq	%rax, (%rsp)
	movq	%rdi, 16(%rsp)
	movl	%esi, %edi
.LVL79:
	.loc 1 1485 1 view .LVU280
	movl	%ecx, %esi
.LVL80:
	.loc 1 1485 1 view .LVU281
	movl	%edi, %r15d
.LVL81:
.L65:
	.loc 1 1486 2 is_stmt 1 view .LVU282
	.loc 1 1487 2 view .LVU283
	.loc 1 1488 2 view .LVU284
	.loc 1 1489 2 view .LVU285
	.loc 1 1492 2 view .LVU286
	.loc 1 1493 2 view .LVU287
	.loc 1 1493 7 is_stmt 0 view .LVU288
	movq	8(%rsp), %rdx
	movq	%rbx, %rdi
	call	skip_mods_and_typedefs@PLT
.LVL82:
	.loc 1 1494 7 view .LVU289
	movq	(%rsp), %rdx
	movl	56(%rsp), %esi
	movq	%rbp, %rdi
	.loc 1 1493 7 view .LVU290
	movq	%rax, %r14
.LVL83:
	.loc 1 1494 2 is_stmt 1 view .LVU291
	.loc 1 1494 7 is_stmt 0 view .LVU292
	call	skip_mods_and_typedefs@PLT
.LVL84:
.LBB390:
.LBB391:
.LBB392:
.LBB393:
	.file 4 "btf.h"
	.loc 4 415 9 view .LVU293
	movl	4(%r14), %ecx
.LBE393:
.LBE392:
.LBE391:
.LBE390:
	.loc 1 1494 7 view .LVU294
	movq	%rax, %rdx
.LVL85:
	.loc 1 1497 2 is_stmt 1 view .LVU295
	.loc 1 1497 5 is_stmt 0 view .LVU296
	testb	%r15b, %r15b
	jne	.L66
.LVL86:
.LBB404:
.LBI390:
	.loc 4 475 20 is_stmt 1 view .LVU297
.LBB400:
	.loc 4 477 2 view .LVU298
.LBB397:
.LBI392:
	.loc 4 413 21 view .LVU299
.LBB394:
	.loc 4 415 2 view .LVU300
.LBE394:
.LBE397:
.LBE400:
.LBE404:
.LBB405:
.LBB406:
.LBB407:
.LBB408:
	.loc 4 415 9 is_stmt 0 view .LVU301
	movzbl	7(%rdx), %esi
.LBE408:
.LBE407:
.LBE406:
.LBE405:
.LBB415:
.LBB401:
.LBB398:
.LBB395:
	movl	%ecx, %eax
.LVL87:
	.loc 4 415 9 view .LVU302
	shrl	$24, %eax
.LBE395:
.LBE398:
.LBE401:
.LBE415:
.LBB416:
.LBB413:
.LBB411:
.LBB409:
	andl	$31, %esi
.LBE409:
.LBE411:
.LBE413:
.LBE416:
.LBB417:
.LBB402:
.LBB399:
.LBB396:
	andl	$31, %eax
.LVL88:
	.loc 4 415 9 view .LVU303
.LBE396:
.LBE399:
.LBE402:
.LBE417:
.LBB418:
.LBI405:
	.loc 4 475 20 is_stmt 1 view .LVU304
.LBB414:
	.loc 4 477 2 view .LVU305
.LBB412:
.LBI407:
	.loc 4 413 21 view .LVU306
.LBB410:
	.loc 4 415 2 view .LVU307
	.loc 4 415 2 is_stmt 0 view .LVU308
.LBE410:
.LBE412:
	.loc 4 477 21 discriminator 1 view .LVU309
	cmpw	$7, %si
	sete	%r8b
.LBE414:
.LBE418:
.LBB419:
.LBB403:
	cmpw	$7, %ax
	sete	%dil
.LBE403:
.LBE419:
	.loc 1 1497 13 discriminator 2 view .LVU310
	cmpb	%dil, %r8b
	jne	.L131
.L67:
	.loc 1 1524 2 is_stmt 1 view .LVU311
.LVL89:
.LBB420:
.LBI420:
	.loc 4 413 21 view .LVU312
.LBB421:
	.loc 4 415 2 view .LVU313
	.loc 4 415 2 is_stmt 0 view .LVU314
.LBE421:
.LBE420:
.LBB424:
.LBI424:
	.loc 4 413 21 is_stmt 1 view .LVU315
.LBB425:
	.loc 4 415 2 view .LVU316
	.loc 4 415 2 is_stmt 0 view .LVU317
.LBE425:
.LBE424:
	.loc 1 1524 5 discriminator 2 view .LVU318
	cmpw	%si, %ax
	jne	.L132
	.loc 1 1530 2 is_stmt 1 view .LVU319
	.loc 1 1530 2 is_stmt 0 discriminator 1 view .LVU320
	movzwl	%ax, %esi
	movl	$545008, %edi
	xorl	%r12d, %r12d
	btq	%rsi, %rdi
	jc	.L133
.LVL90:
	.loc 1 1550 2 is_stmt 1 view .LVU321
.LBB428:
.LBI428:
	.loc 4 413 21 view .LVU322
.LBB429:
	.loc 4 415 2 view .LVU323
	.loc 4 415 2 is_stmt 0 view .LVU324
.LBE429:
.LBE428:
	.loc 1 1550 2 discriminator 1 view .LVU325
	cmpw	$19, %ax
	ja	.L83
.LVL91:
.L134:
	.loc 1 1550 2 discriminator 1 view .LVU326
	movzwl	%ax, %eax
	movslq	0(%r13,%rax,4), %rax
	addq	%r13, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L85:
	.long	.L73-.L85
	.long	.L84-.L85
	.long	.L91-.L85
	.long	.L90-.L85
	.long	.L89-.L85
	.long	.L89-.L85
	.long	.L84-.L85
	.long	.L73-.L85
	.long	.L83-.L85
	.long	.L83-.L85
	.long	.L83-.L85
	.long	.L83-.L85
	.long	.L88-.L85
	.long	.L87-.L85
	.long	.L86-.L85
	.long	.L83-.L85
	.long	.L84-.L85
	.long	.L83-.L85
	.long	.L83-.L85
	.long	.L84-.L85
	.text
.LVL92:
	.p2align 4,,10
	.p2align 3
.L66:
.LBB431:
.LBB426:
	.loc 4 415 9 view .LVU327
	movzbl	7(%rax), %esi
.LBE426:
.LBE431:
.LBB432:
.LBB422:
	movl	%ecx, %eax
.LVL93:
	.loc 4 415 9 view .LVU328
	shrl	$24, %eax
.LBE422:
.LBE432:
.LBB433:
.LBB427:
	andl	$31, %esi
.LBE427:
.LBE433:
.LBB434:
.LBB423:
	andl	$31, %eax
	jmp	.L67
	.p2align 4,,10
	.p2align 3
.L133:
	.loc 4 415 9 view .LVU329
.LBE423:
.LBE434:
	.loc 1 1538 8 view .LVU330
	movl	(%r14), %esi
	movq	%rbx, %rdi
	movq	%rdx, 24(%rsp)
	.loc 1 1538 3 is_stmt 1 view .LVU331
	.loc 1 1538 8 is_stmt 0 view .LVU332
	call	btf__str_by_offset@PLT
.LVL94:
	.loc 1 1539 8 view .LVU333
	movq	24(%rsp), %rdx
	movq	%rbp, %rdi
	.loc 1 1538 8 view .LVU334
	movq	%rax, %r12
.LVL95:
	.loc 1 1539 3 is_stmt 1 view .LVU335
	.loc 1 1539 8 is_stmt 0 view .LVU336
	movl	(%rdx), %esi
	call	btf__str_by_offset@PLT
.LVL96:
	.loc 1 1540 7 view .LVU337
	movq	%r12, %rdi
	movq	%rax, %rsi
	.loc 1 1539 8 view .LVU338
	movq	%rax, 32(%rsp)
.LVL97:
	.loc 1 1540 3 is_stmt 1 view .LVU339
	.loc 1 1540 7 is_stmt 0 view .LVU340
	call	strcmp@PLT
.LVL98:
	.loc 1 1540 6 discriminator 1 view .LVU341
	testl	%eax, %eax
	jne	.L82
.LBB435:
.LBB436:
.LBB437:
	.loc 4 415 9 view .LVU342
	movl	4(%r14), %ecx
	movq	24(%rsp), %rdx
.LVL99:
	.loc 4 415 9 view .LVU343
.LBE437:
.LBE436:
.LBE435:
	.loc 1 1550 2 is_stmt 1 view .LVU344
.LBB442:
	.loc 4 413 21 view .LVU345
.LBB430:
	.loc 4 415 2 view .LVU346
	.loc 4 415 9 is_stmt 0 view .LVU347
	movl	%ecx, %eax
	shrl	$24, %eax
	andl	$31, %eax
.LBE430:
.LBE442:
	.loc 1 1550 2 discriminator 1 view .LVU348
	cmpw	$19, %ax
	jbe	.L134
.LVL100:
	.p2align 4,,10
	.p2align 3
.L83:
	.loc 1 1670 3 view .LVU349
	movq	%r14, %rdi
	call	btf_kind_str@PLT
.LVL101:
	.loc 1 1670 3 discriminator 1 view .LVU350
	movq	16(%rsp), %rdx
	leaq	.LC13(%rip), %rsi
	xorl	%edi, %edi
	.loc 1 1670 3 view .LVU351
	movq	%rax, %rcx
	.loc 1 1670 3 discriminator 1 view .LVU352
	xorl	%eax, %eax
	call	libbpf_print@PLT
.LVL102:
	.loc 1 1670 3 is_stmt 1 discriminator 2 view .LVU353
	.loc 1 1672 3 view .LVU354
.L69:
	.loc 1 1503 11 is_stmt 0 view .LVU355
	xorl	%eax, %eax
	jmp	.L64
.LVL103:
	.p2align 4,,10
	.p2align 3
.L84:
	.loc 1 1559 9 view .LVU356
	movl	8(%r14), %ebx
.LVL104:
	.loc 1 1559 21 view .LVU357
	movl	8(%rdx), %ebp
.LVL105:
	.loc 1 1559 9 view .LVU358
	movq	%r12, %r15
.LVL106:
	.loc 1 1559 9 view .LVU359
	movq	%r14, %r12
	.loc 1 1559 3 is_stmt 1 view .LVU360
	.loc 1 1559 6 is_stmt 0 view .LVU361
	cmpl	%ebp, %ebx
	jne	.L135
.LVL107:
.L73:
	.loc 1 1503 11 view .LVU362
	movl	$1, %eax
.L64:
	.loc 1 1674 1 view .LVU363
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.LVL108:
	.p2align 4,,10
	.p2align 3
.L89:
	.cfi_restore_state
.LBB443:
	.loc 1 1607 6 view .LVU364
	movq	%r14, %r12
	movq	%rdx, %r14
.LVL109:
	.loc 1 1605 3 is_stmt 1 view .LVU365
	.loc 1 1607 3 view .LVU366
	.loc 1 1607 6 is_stmt 0 view .LVU367
	testb	%r15b, %r15b
	je	.L73
	.loc 1 1610 3 is_stmt 1 view .LVU368
.LVL110:
.LBB444:
.LBI444:
	.loc 4 418 21 view .LVU369
.LBB445:
	.loc 4 420 2 view .LVU370
	.loc 4 420 2 is_stmt 0 view .LVU371
.LBE445:
.LBE444:
.LBB446:
.LBI446:
	.loc 4 418 21 is_stmt 1 view .LVU372
.LBB447:
	.loc 4 420 2 view .LVU373
	.loc 4 420 9 is_stmt 0 view .LVU374
	movl	4(%rdx), %r13d
.LVL111:
	.loc 4 420 9 view .LVU375
.LBE447:
.LBE446:
	.loc 1 1611 4 discriminator 2 view .LVU376
	movzwl	%cx, %r8d
	.loc 1 1610 6 discriminator 2 view .LVU377
	cmpw	%cx, %r13w
	jne	.L136
	.loc 1 1616 3 is_stmt 1 view .LVU378
.LVL112:
	.loc 1 1617 3 view .LVU379
.LBB448:
.LBI448:
	.loc 4 615 34 view .LVU380
.LBB449:
	.loc 4 617 2 view .LVU381
	.loc 4 617 9 is_stmt 0 view .LVU382
	leaq	12(%r12), %r13
.LVL113:
	.loc 4 617 9 view .LVU383
.LBE449:
.LBE448:
	.loc 1 1618 3 is_stmt 1 view .LVU384
.LBB450:
.LBI450:
	.loc 4 615 34 view .LVU385
.LBB451:
	.loc 4 617 2 view .LVU386
	.loc 4 617 9 is_stmt 0 view .LVU387
	addq	$12, %r14
.LVL114:
	.loc 4 617 9 view .LVU388
.LBE451:
.LBE450:
	.loc 1 1619 3 is_stmt 1 view .LVU389
	.loc 1 1619 17 discriminator 1 view .LVU390
	testl	%r8d, %r8d
	je	.L73
	.loc 1 1619 10 is_stmt 0 view .LVU391
	movl	%r8d, 8(%rsp)
	movq	%rbp, %rax
	xorl	%r15d, %r15d
.LVL115:
	.loc 1 1619 10 view .LVU392
	movq	%r13, %rbp
.LVL116:
	.loc 1 1619 10 view .LVU393
	movq	%rbx, (%rsp)
	movq	%rax, %r13
.LVL117:
.L99:
	.loc 1 1620 4 is_stmt 1 view .LVU394
	.loc 1 1620 9 is_stmt 0 view .LVU395
	movl	0(%rbp), %esi
	movq	(%rsp), %rdi
	call	btf__str_by_offset@PLT
.LVL118:
	.loc 1 1621 9 view .LVU396
	movl	(%r14), %esi
	movq	%r13, %rdi
	.loc 1 1620 9 view .LVU397
	movq	%rax, %r12
.LVL119:
	.loc 1 1621 4 is_stmt 1 view .LVU398
	.loc 1 1621 9 is_stmt 0 view .LVU399
	call	btf__str_by_offset@PLT
.LVL120:
	.loc 1 1622 8 view .LVU400
	movq	%r12, %rdi
	movq	%rax, %rsi
	.loc 1 1621 9 view .LVU401
	movq	%rax, %rbx
.LVL121:
	.loc 1 1622 4 is_stmt 1 view .LVU402
	.loc 1 1622 8 is_stmt 0 view .LVU403
	call	strcmp@PLT
.LVL122:
	.loc 1 1622 7 discriminator 1 view .LVU404
	testl	%eax, %eax
	jne	.L137
	.loc 1 1627 4 is_stmt 1 view .LVU405
	.loc 1 1627 7 is_stmt 0 view .LVU406
	movl	8(%r14), %eax
	cmpl	%eax, 8(%rbp)
	jne	.L138
	.loc 1 1632 4 is_stmt 1 view .LVU407
	.loc 1 1632 9 is_stmt 0 view .LVU408
	movl	4(%rbp), %ecx
	movl	4(%r14), %r9d
	movq	%r13, %r8
	movl	$1, %esi
	movq	(%rsp), %rdx
	movq	16(%rsp), %rdi
	call	glob_sym_btf_matches
.LVL123:
	.loc 1 1632 7 discriminator 1 view .LVU409
	testb	%al, %al
	je	.L69
	.loc 1 1619 31 is_stmt 1 discriminator 2 view .LVU410
	.loc 1 1619 17 is_stmt 0 discriminator 1 view .LVU411
	movl	8(%rsp), %eax
	.loc 1 1619 23 discriminator 2 view .LVU412
	addl	$1, %r15d
.LVL124:
	.loc 1 1619 29 discriminator 2 view .LVU413
	addq	$12, %rbp
.LVL125:
	.loc 1 1619 35 discriminator 2 view .LVU414
	addq	$12, %r14
.LVL126:
	.loc 1 1619 17 is_stmt 1 discriminator 1 view .LVU415
	cmpl	%eax, %r15d
	jne	.L99
	jmp	.L73
.LVL127:
	.p2align 4,,10
	.p2align 3
.L88:
	.loc 1 1619 17 is_stmt 0 discriminator 1 view .LVU416
.LBE443:
	.loc 1 1581 3 is_stmt 1 view .LVU417
	.loc 1 1582 3 view .LVU418
.LBB452:
.LBI452:
	.loc 2 254 37 view .LVU419
	.loc 2 256 2 view .LVU420
.LBB453:
.LBI453:
	.loc 4 418 21 view .LVU421
.LBB454:
	.loc 4 420 2 view .LVU422
	.loc 4 420 2 is_stmt 0 view .LVU423
.LBE454:
.LBE453:
.LBE452:
	.loc 1 1583 3 is_stmt 1 view .LVU424
	.loc 1 1581 14 is_stmt 0 discriminator 1 view .LVU425
	testw	%cx, %cx
	sete	%cl
.LVL128:
	.loc 1 1582 14 discriminator 1 view .LVU426
	cmpw	$0, 4(%rdx)
	sete	%al
	.loc 1 1583 6 view .LVU427
	cmpb	%al, %cl
	jne	.L139
.LVL129:
.L104:
.LBB455:
	.loc 1 1657 3 is_stmt 1 view .LVU428
	.loc 1 1657 11 is_stmt 0 view .LVU429
	movl	8(%r14), %esi
	.loc 1 1658 11 view .LVU430
	movl	8(%rdx), %eax
	.loc 1 1657 7 view .LVU431
	movl	%esi, 60(%rsp)
	.loc 1 1658 3 is_stmt 1 view .LVU432
	.loc 1 1659 3 view .LVU433
.LVL130:
.L92:
	.loc 1 1659 3 is_stmt 0 view .LVU434
.LBE455:
	.loc 1 1601 7 view .LVU435
	movl	%eax, 56(%rsp)
	jmp	.L65
.LVL131:
	.p2align 4,,10
	.p2align 3
.L90:
	.loc 1 1576 3 is_stmt 1 view .LVU436
	.loc 1 1576 22 is_stmt 0 discriminator 1 view .LVU437
	movl	12(%r14), %esi
	.loc 1 1577 22 discriminator 1 view .LVU438
	movl	12(%rdx), %eax
	.loc 1 1576 7 discriminator 1 view .LVU439
	movl	%esi, 60(%rsp)
	.loc 1 1577 3 is_stmt 1 view .LVU440
	.loc 1 1578 3 view .LVU441
	jmp	.L92
	.p2align 4,,10
	.p2align 3
.L91:
	.loc 1 1570 3 view .LVU442
.LVL132:
	.loc 1 1571 3 view .LVU443
	.loc 1 1571 11 is_stmt 0 view .LVU444
	movl	8(%r14), %esi
	.loc 1 1572 11 view .LVU445
	movl	8(%rdx), %eax
	.loc 1 1570 9 view .LVU446
	xorl	%r15d, %r15d
	.loc 1 1571 7 view .LVU447
	movl	%esi, 60(%rsp)
	.loc 1 1572 3 is_stmt 1 view .LVU448
	.loc 1 1573 3 view .LVU449
	jmp	.L92
.LVL133:
	.p2align 4,,10
	.p2align 3
.L86:
	.loc 1 1593 3 view .LVU450
	.loc 1 1594 3 view .LVU451
	.loc 1 1595 3 view .LVU452
	.loc 1 1593 14 is_stmt 0 discriminator 1 view .LVU453
	movl	12(%r14), %eax
	.loc 1 1594 14 discriminator 1 view .LVU454
	movl	12(%rdx), %esi
	.loc 1 1593 14 discriminator 1 view .LVU455
	testl	%eax, %eax
	sete	%cl
	.loc 1 1594 14 discriminator 1 view .LVU456
	testl	%esi, %esi
	sete	%al
	.loc 1 1595 6 view .LVU457
	cmpb	%al, %cl
	je	.L104
	.loc 1 1596 4 view .LVU458
	movq	16(%rsp), %rdx
.LVL134:
	.loc 1 1596 4 view .LVU459
	xorl	%eax, %eax
	movq	%r12, %rcx
	xorl	%edi, %edi
	leaq	.LC8(%rip), %rsi
.LVL135:
	.loc 1 1596 4 view .LVU460
	call	libbpf_print@PLT
.LVL136:
	.loc 1 1596 4 is_stmt 1 discriminator 1 view .LVU461
	.loc 1 1597 4 view .LVU462
	.loc 1 1503 11 is_stmt 0 view .LVU463
	xorl	%eax, %eax
	jmp	.L64
.LVL137:
	.p2align 4,,10
	.p2align 3
.L87:
.LBB464:
	.loc 1 1639 3 is_stmt 1 view .LVU464
	.loc 1 1641 3 view .LVU465
.LBB456:
.LBI456:
	.loc 4 418 21 view .LVU466
.LBB457:
	.loc 4 420 2 view .LVU467
	.loc 4 420 2 is_stmt 0 view .LVU468
.LBE457:
.LBE456:
.LBB458:
.LBI458:
	.loc 4 418 21 is_stmt 1 view .LVU469
.LBB459:
	.loc 4 420 2 view .LVU470
	.loc 4 420 9 is_stmt 0 view .LVU471
	movl	4(%rdx), %eax
.LVL138:
	.loc 4 420 9 view .LVU472
	movzwl	%cx, %r8d
.LBE459:
.LBE458:
	.loc 1 1641 6 discriminator 2 view .LVU473
	cmpw	%cx, %ax
	jne	.L140
	.loc 1 1647 3 is_stmt 1 view .LVU474
.LVL139:
	.loc 1 1648 3 view .LVU475
.LBB460:
.LBI460:
	.loc 4 642 33 view .LVU476
.LBB461:
	.loc 4 644 2 view .LVU477
	.loc 4 644 9 is_stmt 0 view .LVU478
	leaq	12(%r14), %r12
.LVL140:
	.loc 4 644 9 view .LVU479
.LBE461:
.LBE460:
	.loc 1 1649 3 is_stmt 1 view .LVU480
.LBB462:
.LBI462:
	.loc 4 642 33 view .LVU481
.LBB463:
	.loc 4 644 2 view .LVU482
	.loc 4 644 9 is_stmt 0 view .LVU483
	leaq	12(%rdx), %r10
.LVL141:
	.loc 4 644 9 view .LVU484
.LBE463:
.LBE462:
	.loc 1 1650 3 is_stmt 1 view .LVU485
	.loc 1 1650 17 discriminator 1 view .LVU486
	testl	%r8d, %r8d
	je	.L104
	.loc 1 1652 9 is_stmt 0 view .LVU487
	movzbl	%r15b, %eax
	movq	%rdx, 40(%rsp)
	movl	%eax, 24(%rsp)
	leal	-1(%r8), %eax
	leaq	20(%rdx,%rax,8), %rax
	movq	%r14, 32(%rsp)
	movq	%r10, %r14
.LVL142:
	.loc 1 1652 9 view .LVU488
	movb	%r15b, 55(%rsp)
	movq	%r12, %r15
.LVL143:
	.loc 1 1652 9 view .LVU489
	movq	%rax, %r12
.LVL144:
.L103:
	.loc 1 1652 4 is_stmt 1 view .LVU490
	.loc 1 1652 9 is_stmt 0 view .LVU491
	movl	4(%r15), %ecx
	movl	4(%r14), %r9d
	movq	%rbp, %r8
	movq	%rbx, %rdx
	movl	24(%rsp), %esi
	movq	16(%rsp), %rdi
	call	glob_sym_btf_matches
.LVL145:
	.loc 1 1652 7 discriminator 1 view .LVU492
	testb	%al, %al
	je	.L69
	.loc 1 1650 31 is_stmt 1 discriminator 2 view .LVU493
.LVL146:
	.loc 1 1650 35 is_stmt 0 discriminator 2 view .LVU494
	addq	$8, %r14
.LVL147:
	.loc 1 1650 29 discriminator 2 view .LVU495
	addq	$8, %r15
.LVL148:
	.loc 1 1650 17 is_stmt 1 discriminator 1 view .LVU496
	cmpq	%r14, %r12
	jne	.L103
	movq	32(%rsp), %r14
.LVL149:
	.loc 1 1650 17 is_stmt 0 discriminator 1 view .LVU497
	movq	40(%rsp), %rdx
	movzbl	55(%rsp), %r15d
.LVL150:
	.loc 1 1650 17 discriminator 1 view .LVU498
	jmp	.L104
.LVL151:
	.p2align 4,,10
	.p2align 3
.L135:
	.loc 1 1650 17 discriminator 1 view .LVU499
.LBE464:
	.loc 1 1560 4 is_stmt 1 view .LVU500
	.loc 1 1560 4 view .LVU501
	movq	%r12, %rdi
	call	btf_kind_str@PLT
.LVL152:
	.loc 1 1560 4 is_stmt 0 discriminator 1 view .LVU502
	subq	$8, %rsp
	.cfi_def_cfa_offset 136
	movq	%r15, %r8
	xorl	%edi, %edi
	pushq	%rbp
	.cfi_def_cfa_offset 144
	movq	32(%rsp), %rdx
	.loc 1 1560 4 view .LVU503
	movq	%rax, %rcx
	.loc 1 1560 4 discriminator 1 view .LVU504
	movl	%ebx, %r9d
	xorl	%eax, %eax
	leaq	.LC6(%rip), %rsi
	call	libbpf_print@PLT
.LVL153:
	.loc 1 1560 4 is_stmt 1 discriminator 2 view .LVU505
	.loc 1 1562 4 view .LVU506
	.loc 1 1562 11 is_stmt 0 view .LVU507
	popq	%rdi
	.cfi_def_cfa_offset 136
	.loc 1 1503 11 view .LVU508
	xorl	%eax, %eax
	.loc 1 1562 11 view .LVU509
	popq	%r8
	.cfi_def_cfa_offset 128
	jmp	.L64
.LVL154:
	.p2align 4,,10
	.p2align 3
.L136:
.LBB465:
	.loc 1 1611 4 discriminator 2 view .LVU510
	movq	%r12, %rdi
	movl	%r8d, (%rsp)
	.loc 1 1611 4 is_stmt 1 view .LVU511
	.loc 1 1611 4 view .LVU512
	.loc 1 1611 4 is_stmt 0 discriminator 2 view .LVU513
	call	btf_kind_str@PLT
.LVL155:
	.loc 1 1611 4 discriminator 3 view .LVU514
	movl	(%rsp), %r8d
	movq	16(%rsp), %rdx
	xorl	%edi, %edi
	.loc 1 1611 4 discriminator 2 view .LVU515
	movq	%rax, %rcx
	.loc 1 1611 4 discriminator 3 view .LVU516
	movzwl	%r13w, %r9d
	leaq	.LC9(%rip), %rsi
	xorl	%eax, %eax
	call	libbpf_print@PLT
.LVL156:
	.loc 1 1611 4 is_stmt 1 discriminator 4 view .LVU517
	.loc 1 1613 4 view .LVU518
.LBE465:
	.loc 1 1503 11 is_stmt 0 view .LVU519
	xorl	%eax, %eax
	jmp	.L64
.LVL157:
	.p2align 4,,10
	.p2align 3
.L132:
	.loc 1 1525 3 view .LVU520
	movq	%rdx, %rdi
	call	btf_kind_str@PLT
.LVL158:
	.loc 1 1525 3 discriminator 1 view .LVU521
	movq	%r14, %rdi
	.loc 1 1525 3 view .LVU522
	movq	%rax, %rbx
.LVL159:
	.loc 1 1525 3 discriminator 1 view .LVU523
	call	btf_kind_str@PLT
.LVL160:
	.loc 1 1525 3 discriminator 2 view .LVU524
	movq	16(%rsp), %rdx
	movq	%rbx, %r8
	xorl	%edi, %edi
	.loc 1 1525 3 discriminator 1 view .LVU525
	movq	%rax, %rcx
	.loc 1 1525 3 discriminator 2 view .LVU526
	leaq	.LC4(%rip), %rsi
	xorl	%eax, %eax
	call	libbpf_print@PLT
.LVL161:
	.loc 1 1525 3 is_stmt 1 discriminator 3 view .LVU527
	.loc 1 1527 3 view .LVU528
	.loc 1 1503 11 is_stmt 0 view .LVU529
	xorl	%eax, %eax
	jmp	.L64
.LVL162:
	.p2align 4,,10
	.p2align 3
.L137:
.LBB466:
	.loc 1 1623 5 view .LVU530
	movq	16(%rsp), %rdx
	xorl	%eax, %eax
	movq	%rbx, %r9
	.loc 1 1623 5 is_stmt 1 view .LVU531
	.loc 1 1623 5 view .LVU532
	movq	%r12, %r8
	movl	%r15d, %ecx
	leaq	.LC10(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL163:
	.loc 1 1623 5 discriminator 1 view .LVU533
	.loc 1 1625 5 view .LVU534
.LBE466:
	.loc 1 1503 11 is_stmt 0 view .LVU535
	xorl	%eax, %eax
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L138:
.LBB467:
	.loc 1 1628 5 is_stmt 1 view .LVU536
	.loc 1 1628 5 view .LVU537
	movq	16(%rsp), %rdx
	xorl	%eax, %eax
	movq	%r12, %r8
	movl	%r15d, %ecx
	leaq	.LC11(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL164:
	.loc 1 1628 5 discriminator 1 view .LVU538
	.loc 1 1630 5 view .LVU539
.LBE467:
	.loc 1 1503 11 is_stmt 0 view .LVU540
	xorl	%eax, %eax
	jmp	.L64
.LVL165:
	.p2align 4,,10
	.p2align 3
.L131:
	.loc 1 1498 8 view .LVU541
	movq	%r14, %r12
	movq	%rbx, %rdi
	movq	%rdx, %r14
.LVL166:
	.loc 1 1498 3 is_stmt 1 view .LVU542
	.loc 1 1498 8 is_stmt 0 view .LVU543
	movl	(%r12), %esi
	call	btf__str_by_offset@PLT
.LVL167:
	.loc 1 1499 8 view .LVU544
	movl	(%r14), %esi
	movq	%rbp, %rdi
	.loc 1 1498 8 view .LVU545
	movq	%rax, %rbx
.LVL168:
	.loc 1 1499 3 is_stmt 1 view .LVU546
	.loc 1 1499 8 is_stmt 0 view .LVU547
	call	btf__str_by_offset@PLT
.LVL169:
	.loc 1 1500 7 view .LVU548
	movq	%rbx, %rdi
	movq	%rax, %rsi
	.loc 1 1499 8 view .LVU549
	movq	%rax, %rbp
.LVL170:
	.loc 1 1500 3 is_stmt 1 view .LVU550
	.loc 1 1500 7 is_stmt 0 view .LVU551
	call	strcmp@PLT
.LVL171:
	.loc 1 1500 6 discriminator 1 view .LVU552
	testl	%eax, %eax
	jne	.L141
	.loc 1 1506 3 is_stmt 1 view .LVU553
.LVL172:
.LBB468:
.LBI435:
	.loc 4 475 20 view .LVU554
	.loc 4 477 2 view .LVU555
.LBB440:
.LBI436:
	.loc 4 413 21 view .LVU556
.LBB438:
	.loc 4 415 2 view .LVU557
	.loc 4 415 9 is_stmt 0 view .LVU558
	movl	4(%r12), %esi
.LBE438:
.LBE440:
.LBE468:
.LBB469:
.LBB470:
.LBB471:
	movl	4(%r14), %ecx
.LBE471:
.LBE470:
.LBE469:
.LBB476:
.LBB441:
.LBB439:
	movl	%esi, %eax
	shrl	$24, %eax
	andl	$31, %eax
.LVL173:
	.loc 4 415 9 view .LVU559
.LBE439:
.LBE441:
.LBE476:
	.loc 1 1506 6 discriminator 1 view .LVU560
	cmpw	$7, %ax
	je	.L142
	.loc 1 1514 4 is_stmt 1 view .LVU561
.LVL174:
.LBB477:
.LBI477:
	.loc 4 423 20 view .LVU562
.LBB478:
	.loc 4 425 2 view .LVU563
	.loc 4 425 2 is_stmt 0 view .LVU564
.LBE478:
.LBE477:
	.loc 1 1514 7 discriminator 1 view .LVU565
	testl	%ecx, %ecx
	jns	.L76
	.loc 1 1514 22 discriminator 1 view .LVU566
	cmpw	$5, %ax
	je	.L73
.L77:
	.loc 1 1518 4 is_stmt 1 view .LVU567
	.loc 1 1518 4 view .LVU568
	movq	%r12, %rdi
	call	btf_kind_str@PLT
.LVL175:
.LBB479:
.LBI479:
	.loc 4 423 20 view .LVU569
.LBB480:
	.loc 4 425 2 view .LVU570
	.loc 4 425 2 is_stmt 0 view .LVU571
.LBE480:
.LBE479:
	.loc 1 1518 4 discriminator 1 view .LVU572
	movl	4(%r14), %r9d
	.loc 1 1518 4 view .LVU573
	movq	%rax, %r8
	.loc 1 1518 4 discriminator 1 view .LVU574
	testl	%r9d, %r9d
.L130:
	.loc 1 1518 4 discriminator 1 view .LVU575
	leaq	.LC0(%rip), %rax
	leaq	.LC1(%rip), %rcx
	.loc 1 1518 4 discriminator 4 view .LVU576
	movq	16(%rsp), %rdx
	.loc 1 1518 4 discriminator 1 view .LVU577
	cmovs	%rax, %rcx
	.loc 1 1518 4 discriminator 4 view .LVU578
	leaq	.LC3(%rip), %rsi
	xorl	%eax, %eax
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL176:
	.loc 1 1503 11 view .LVU579
	xorl	%eax, %eax
	jmp	.L64
.LVL177:
.L82:
	.loc 1 1541 4 view .LVU580
	movq	%r14, %rdi
	call	btf_kind_str@PLT
.LVL178:
	.loc 1 1541 4 discriminator 1 view .LVU581
	movq	32(%rsp), %r9
	movq	%r12, %r8
	xorl	%edi, %edi
	movq	16(%rsp), %rdx
	.loc 1 1541 4 view .LVU582
	movq	%rax, %rcx
	.loc 1 1541 4 discriminator 1 view .LVU583
	leaq	.LC5(%rip), %rsi
	xorl	%eax, %eax
	call	libbpf_print@PLT
.LVL179:
	.loc 1 1541 4 is_stmt 1 discriminator 2 view .LVU584
	.loc 1 1543 4 view .LVU585
	.loc 1 1503 11 is_stmt 0 view .LVU586
	xorl	%eax, %eax
	jmp	.L64
.LVL180:
.L76:
	.loc 1 1516 4 is_stmt 1 view .LVU587
	.loc 1 1516 23 is_stmt 0 discriminator 1 view .LVU588
	cmpw	$4, %ax
	jne	.L77
	jmp	.L73
.L142:
	.loc 1 1507 4 is_stmt 1 view .LVU589
.LVL181:
.LBB481:
.LBI481:
	.loc 4 423 20 view .LVU590
.LBB482:
	.loc 4 425 2 view .LVU591
	.loc 4 425 2 is_stmt 0 view .LVU592
.LBE482:
.LBE481:
.LBB483:
.LBB474:
.LBB472:
	.loc 4 415 9 view .LVU593
	shrl	$24, %ecx
	andl	$31, %ecx
.LBE472:
.LBE474:
.LBE483:
	.loc 1 1507 7 discriminator 1 view .LVU594
	testl	%esi, %esi
	jns	.L71
.LVL182:
.LBB484:
.LBI469:
	.loc 4 453 20 is_stmt 1 view .LVU595
	.loc 4 455 2 view .LVU596
.LBB475:
.LBI470:
	.loc 4 413 21 view .LVU597
.LBB473:
	.loc 4 415 2 view .LVU598
	.loc 4 415 2 is_stmt 0 view .LVU599
.LBE473:
.LBE475:
.LBE484:
	.loc 1 1507 22 discriminator 1 view .LVU600
	cmpw	$5, %cx
	je	.L73
.L72:
	.loc 1 1511 4 is_stmt 1 view .LVU601
	.loc 1 1511 4 view .LVU602
	movq	%r14, %rdi
	call	btf_kind_str@PLT
.LVL183:
.LBB485:
.LBI485:
	.loc 4 423 20 view .LVU603
.LBB486:
	.loc 4 425 2 view .LVU604
	.loc 4 425 2 is_stmt 0 view .LVU605
.LBE486:
.LBE485:
	.loc 1 1511 4 discriminator 1 view .LVU606
	movl	4(%r12), %r10d
	.loc 1 1511 4 view .LVU607
	movq	%rax, %r8
	.loc 1 1511 4 discriminator 1 view .LVU608
	testl	%r10d, %r10d
	jmp	.L130
.LVL184:
.L140:
.LBB487:
	.loc 1 1642 4 discriminator 2 view .LVU609
	movq	%r14, %rdi
	movl	%r8d, (%rsp)
	.loc 1 1642 4 is_stmt 1 view .LVU610
	.loc 1 1642 4 view .LVU611
	.loc 1 1642 4 is_stmt 0 discriminator 2 view .LVU612
	movl	%eax, %r15d
.LVL185:
	.loc 1 1642 4 discriminator 2 view .LVU613
	call	btf_kind_str@PLT
.LVL186:
	.loc 1 1642 4 discriminator 3 view .LVU614
	movl	(%rsp), %r8d
	movq	16(%rsp), %rdx
	xorl	%edi, %edi
	.loc 1 1642 4 discriminator 2 view .LVU615
	movq	%rax, %rcx
	.loc 1 1642 4 discriminator 3 view .LVU616
	movzwl	%r15w, %r9d
	leaq	.LC12(%rip), %rsi
	xorl	%eax, %eax
	call	libbpf_print@PLT
.LVL187:
	.loc 1 1642 4 is_stmt 1 discriminator 4 view .LVU617
	.loc 1 1644 4 view .LVU618
.LBE487:
	.loc 1 1503 11 is_stmt 0 view .LVU619
	xorl	%eax, %eax
	jmp	.L64
.LVL188:
.L139:
	.loc 1 1584 4 view .LVU620
	movq	16(%rsp), %rdx
.LVL189:
	.loc 1 1584 4 view .LVU621
	xorl	%eax, %eax
	movq	%r12, %rcx
	xorl	%edi, %edi
	leaq	.LC7(%rip), %rsi
	call	libbpf_print@PLT
.LVL190:
	.loc 1 1584 4 is_stmt 1 discriminator 1 view .LVU622
	.loc 1 1585 4 view .LVU623
	.loc 1 1503 11 is_stmt 0 view .LVU624
	xorl	%eax, %eax
	jmp	.L64
.LVL191:
.L141:
	.loc 1 1501 4 is_stmt 1 view .LVU625
	.loc 1 1501 4 view .LVU626
	movq	16(%rsp), %rdx
	xorl	%eax, %eax
	movq	%rbp, %r8
	movq	%rbx, %rcx
	leaq	.LC2(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL192:
	.loc 1 1501 4 discriminator 1 view .LVU627
	.loc 1 1503 4 view .LVU628
	.loc 1 1503 11 is_stmt 0 view .LVU629
	xorl	%eax, %eax
	jmp	.L64
.L71:
	.loc 1 1509 4 is_stmt 1 view .LVU630
	.loc 1 1509 23 is_stmt 0 discriminator 1 view .LVU631
	cmpw	$4, %cx
	jne	.L72
	jmp	.L73
	.cfi_endproc
.LFE183:
	.size	glob_sym_btf_matches, .-glob_sym_btf_matches
	.section	.rodata.str1.1
.LC14:
	.string	"type"
.LC15:
	.string	"key_size"
.LC16:
	.string	"key type"
.LC17:
	.string	"inner map"
.LC18:
	.string	"value_size"
.LC19:
	.string	"value type"
.LC20:
	.string	"pinning"
.LC21:
	.string	"max_entries"
.LC22:
	.string	"map_flags"
.LC23:
	.string	"numa_node"
.LC24:
	.string	"%s.inner"
	.section	.rodata.str1.8
	.align 8
.LC25:
	.string	"libbpf: global '%s': map %s mismatch\n"
	.text
	.p2align 4
	.type	map_defs_match, @function
map_defs_match:
.LVL193:
.LFB184:
	.loc 1 1683 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 1683 1 is_stmt 0 view .LVU633
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$168, %rsp
	.cfi_def_cfa_offset 224
	.loc 1 1686 5 view .LVU634
	movq	%fs:40, %rax
	movq	%rax, 152(%rsp)
	movl	4(%r9), %eax
	.loc 1 1683 1 view .LVU635
	movq	224(%rsp), %r12
	.loc 1 1686 5 view .LVU636
	cmpl	%eax, 4(%rdx)
	jne	.L155
	.loc 1 1692 5 view .LVU637
	movl	12(%r9), %eax
	movq	%rdx, %rbx
	movq	%r9, %rbp
	.loc 1 1692 2 is_stmt 1 view .LVU638
	.loc 1 1692 5 is_stmt 0 view .LVU639
	cmpl	%eax, 12(%rdx)
	je	.L169
	.loc 1 1693 10 view .LVU640
	leaq	.LC15(%rip), %rcx
.LVL194:
	.loc 1 1693 10 view .LVU641
	jmp	.L144
.LVL195:
	.p2align 4,,10
	.p2align 3
.L155:
	.loc 1 1687 10 view .LVU642
	leaq	.LC14(%rip), %rcx
.LVL196:
.L144:
	.loc 1 1760 2 is_stmt 1 view .LVU643
	.loc 1 1760 2 view .LVU644
	movq	%rdi, %rdx
	xorl	%eax, %eax
	leaq	.LC25(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL197:
	.loc 1 1760 2 discriminator 1 view .LVU645
	.loc 1 1761 2 view .LVU646
	.loc 1 1761 9 is_stmt 0 view .LVU647
	xorl	%eax, %eax
.LVL198:
.L143:
	.loc 1 1762 1 view .LVU648
	movq	152(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L170
	addq	$168, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.LVL199:
	.p2align 4,,10
	.p2align 3
.L169:
	.cfi_restore_state
	.loc 1 1762 1 view .LVU649
	movq	%rcx, %r14
	.loc 1 1696 2 is_stmt 1 view .LVU650
	.loc 1 1696 16 is_stmt 0 view .LVU651
	movl	8(%rdx), %ecx
.LVL200:
	.loc 1 1696 44 view .LVU652
	movl	8(%r9), %r9d
	.loc 1 1696 30 view .LVU653
	testl	%ecx, %ecx
	setne	%dl
.LVL201:
	.loc 1 1696 30 view .LVU654
	testl	%r9d, %r9d
	setne	%al
	.loc 1 1696 5 view .LVU655
	cmpb	%al, %dl
	jne	.L149
	.loc 1 1696 5 view .LVU656
	movq	%rsi, %r13
	movq	%r8, %r15
	.loc 1 1700 2 is_stmt 1 view .LVU657
	.loc 1 1700 5 is_stmt 0 view .LVU658
	testb	$2, (%rbx)
	jne	.L146
.LVL202:
.L148:
	.loc 1 1709 2 is_stmt 1 view .LVU659
	.loc 1 1709 5 is_stmt 0 view .LVU660
	movl	20(%rbp), %eax
	cmpl	%eax, 20(%rbx)
	je	.L171
	.loc 1 1710 10 view .LVU661
	leaq	.LC18(%rip), %rcx
	jmp	.L144
.LVL203:
	.p2align 4,,10
	.p2align 3
.L146:
	.loc 1 1701 11 view .LVU662
	movq	%rsi, %rdx
	movl	$1, %esi
.LVL204:
	.loc 1 1701 11 view .LVU663
	movq	%rdi, 8(%rsp)
	call	glob_sym_btf_matches
.LVL205:
	.loc 1 1701 7 discriminator 1 view .LVU664
	movq	8(%rsp), %rdi
	testb	%al, %al
	jne	.L148
.LVL206:
	.p2align 4,,10
	.p2align 3
.L149:
	.loc 1 1697 10 view .LVU665
	leaq	.LC16(%rip), %rcx
	jmp	.L144
.LVL207:
	.p2align 4,,10
	.p2align 3
.L171:
	.loc 1 1713 2 is_stmt 1 view .LVU666
	.loc 1 1713 16 is_stmt 0 view .LVU667
	movl	16(%rbx), %ecx
	.loc 1 1713 46 view .LVU668
	movl	16(%rbp), %r9d
	.loc 1 1713 32 view .LVU669
	testl	%ecx, %ecx
	setne	%dl
	testl	%r9d, %r9d
	setne	%al
	.loc 1 1713 5 view .LVU670
	cmpb	%al, %dl
	jne	.L158
	.loc 1 1717 2 is_stmt 1 view .LVU671
	.loc 1 1717 5 is_stmt 0 view .LVU672
	testb	$8, (%rbx)
	jne	.L150
.L152:
	.loc 1 1725 2 is_stmt 1 view .LVU673
	.loc 1 1725 5 is_stmt 0 view .LVU674
	movl	24(%rbp), %eax
	cmpl	%eax, 24(%rbx)
	je	.L172
	.loc 1 1726 10 view .LVU675
	leaq	.LC21(%rip), %rcx
	jmp	.L144
	.p2align 4,,10
	.p2align 3
.L158:
	.loc 1 1714 10 view .LVU676
	leaq	.LC19(%rip), %rcx
	jmp	.L144
	.p2align 4,,10
	.p2align 3
.L172:
	.loc 1 1729 2 is_stmt 1 view .LVU677
	.loc 1 1729 5 is_stmt 0 view .LVU678
	movl	28(%rbp), %eax
	cmpl	%eax, 28(%rbx)
	jne	.L160
	.loc 1 1733 2 is_stmt 1 view .LVU679
	.loc 1 1733 5 is_stmt 0 view .LVU680
	movl	32(%rbp), %eax
	cmpl	%eax, 32(%rbx)
	jne	.L161
	.loc 1 1737 2 is_stmt 1 view .LVU681
	.loc 1 1737 5 is_stmt 0 view .LVU682
	movl	36(%rbp), %eax
	cmpl	%eax, 36(%rbx)
	jne	.L162
	.loc 1 1742 2 is_stmt 1 view .LVU683
	.loc 1 1742 15 is_stmt 0 view .LVU684
	movl	(%rbx), %edx
	.loc 1 1742 44 view .LVU685
	movl	0(%rbp), %eax
	xorl	%edx, %eax
	.loc 1 1742 5 view .LVU686
	testb	$2, %ah
	jne	.L163
	.loc 1 1747 2 is_stmt 1 view .LVU687
	.loc 1 1757 9 is_stmt 0 view .LVU688
	movl	$1, %eax
	.loc 1 1747 5 view .LVU689
	andb	$2, %dh
	je	.L143
.LBB488:
	.loc 1 1748 3 is_stmt 1 view .LVU690
	.loc 1 1750 3 view .LVU691
.LVL208:
.LBB489:
.LBI489:
	.file 5 "/usr/include/x86_64-linux-gnu/bits/stdio2.h"
	.loc 5 51 1 view .LVU692
.LBB490:
	.loc 5 54 3 view .LVU693
	.loc 5 54 10 is_stmt 0 discriminator 1 view .LVU694
	leaq	16(%rsp), %rbx
.LVL209:
	.loc 5 54 10 discriminator 1 view .LVU695
	movq	%rdi, %r9
	movl	$128, %ecx
	xorl	%eax, %eax
	leaq	.LC24(%rip), %r8
	movl	$2, %edx
	movl	$128, %esi
	movq	%rbx, %rdi
	call	__snprintf_chk@PLT
.LVL210:
	.loc 5 54 10 discriminator 1 view .LVU696
.LBE490:
.LBE489:
	.loc 1 1752 3 is_stmt 1 view .LVU697
	.loc 1 1752 10 is_stmt 0 view .LVU698
	xorl	%ecx, %ecx
	movq	%r14, %rdx
	movq	%r12, %r9
	pushq	%rax
	.cfi_def_cfa_offset 232
	movq	%r15, %r8
	movq	%r13, %rsi
	movq	%rbx, %rdi
	pushq	$0
	.cfi_def_cfa_offset 240
	call	map_defs_match
.LVL211:
	popq	%rdx
	.cfi_def_cfa_offset 232
	popq	%rcx
	.cfi_def_cfa_offset 224
	jmp	.L143
.LVL212:
	.p2align 4,,10
	.p2align 3
.L150:
	.loc 1 1752 10 view .LVU699
.LBE488:
	.loc 1 1718 11 view .LVU700
	movq	%r15, %r8
	movq	%r13, %rdx
	movl	$1, %esi
	movq	%rdi, 8(%rsp)
	call	glob_sym_btf_matches
.LVL213:
	.loc 1 1718 7 discriminator 1 view .LVU701
	movq	8(%rsp), %rdi
	testb	%al, %al
	jne	.L152
	jmp	.L149
.L160:
	.loc 1 1730 10 view .LVU702
	leaq	.LC22(%rip), %rcx
	jmp	.L144
.L161:
	.loc 1 1734 10 view .LVU703
	leaq	.LC23(%rip), %rcx
	jmp	.L144
.L162:
	.loc 1 1738 10 view .LVU704
	leaq	.LC20(%rip), %rcx
	jmp	.L144
.L163:
	.loc 1 1743 10 view .LVU705
	leaq	.LC17(%rip), %rcx
	jmp	.L144
.LVL214:
.L170:
	.loc 1 1762 1 view .LVU706
	call	__stack_chk_fail@PLT
.LVL215:
	.cfi_endproc
.LFE184:
	.size	map_defs_match, .-map_defs_match
	.p2align 4
	.type	bpf_linker__free.part.0, @function
bpf_linker__free.part.0:
.LVL216:
.LFB210:
	.loc 1 190 6 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 197 2 view .LVU708
	.loc 1 190 6 is_stmt 0 view .LVU709
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	.loc 1 197 2 view .LVU710
	movq	(%rdi), %rdi
.LVL217:
	.loc 1 197 2 view .LVU711
	call	free@PLT
.LVL218:
	.loc 1 199 2 is_stmt 1 view .LVU712
	.loc 1 199 12 is_stmt 0 view .LVU713
	movq	16(%rbp), %rdi
	.loc 1 199 5 view .LVU714
	testq	%rdi, %rdi
	je	.L174
	.loc 1 200 3 is_stmt 1 view .LVU715
	call	elf_end@PLT
.LVL219:
.L174:
	.loc 1 202 2 view .LVU716
	.loc 1 202 12 is_stmt 0 view .LVU717
	movl	8(%rbp), %edi
	.loc 1 202 5 view .LVU718
	testl	%edi, %edi
	js	.L175
	.loc 1 202 22 discriminator 1 view .LVU719
	cmpb	$0, 112(%rbp)
	jne	.L183
.L175:
	.loc 1 205 2 is_stmt 1 view .LVU720
	movq	56(%rbp), %rdi
	call	strset__free@PLT
.LVL220:
	.loc 1 207 2 view .LVU721
	movq	80(%rbp), %rdi
	call	btf__free@PLT
.LVL221:
	.loc 1 208 2 view .LVU722
	movq	88(%rbp), %rdi
	call	btf_ext__free@PLT
.LVL222:
	.loc 1 210 2 view .LVU723
	.loc 1 210 16 discriminator 1 view .LVU724
	cmpl	$1, 48(%rbp)
	jle	.L176
	movl	$160, %r13d
	.loc 1 210 9 is_stmt 0 view .LVU725
	movl	$1, %r12d
.LVL223:
	.p2align 4,,10
	.p2align 3
.L177:
.LBB491:
	.loc 1 211 3 is_stmt 1 view .LVU726
	.loc 1 211 19 is_stmt 0 view .LVU727
	movq	40(%rbp), %rbx
.LBE491:
	.loc 1 210 36 discriminator 3 view .LVU728
	addl	$1, %r12d
.LVL224:
.LBB492:
	.loc 1 211 19 view .LVU729
	addq	%r13, %rbx
.LVL225:
	.loc 1 213 3 is_stmt 1 view .LVU730
.LBE492:
	.loc 1 210 16 is_stmt 0 discriminator 1 view .LVU731
	addq	$160, %r13
.LBB493:
	.loc 1 213 3 view .LVU732
	movq	(%rbx), %rdi
	call	free@PLT
.LVL226:
	.loc 1 214 3 is_stmt 1 view .LVU733
	movq	56(%rbx), %rdi
	call	free@PLT
.LVL227:
	.loc 1 215 3 view .LVU734
	movq	80(%rbx), %rdi
	call	free@PLT
.LVL228:
	.loc 1 217 3 view .LVU735
	movq	104(%rbx), %rdi
	call	free@PLT
.LVL229:
	.loc 1 218 3 view .LVU736
	movq	128(%rbx), %rdi
	call	free@PLT
.LVL230:
	.loc 1 219 3 view .LVU737
	movq	152(%rbx), %rdi
	call	free@PLT
.LVL231:
.LBE493:
	.loc 1 210 36 discriminator 3 view .LVU738
	.loc 1 210 16 discriminator 1 view .LVU739
	cmpl	48(%rbp), %r12d
	jl	.L177
.LVL232:
.L176:
	.loc 1 221 2 view .LVU740
	movq	40(%rbp), %rdi
	call	free@PLT
.LVL233:
	.loc 1 223 2 view .LVU741
	movq	104(%rbp), %rdi
	call	free@PLT
.LVL234:
	.loc 1 224 2 view .LVU742
	.loc 1 225 1 is_stmt 0 view .LVU743
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	.loc 1 224 2 view .LVU744
	movq	%rbp, %rdi
	.loc 1 225 1 view .LVU745
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
.LVL235:
	.loc 1 225 1 view .LVU746
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	.loc 1 224 2 view .LVU747
	jmp	free@PLT
.LVL236:
	.p2align 4,,10
	.p2align 3
.L183:
	.cfi_restore_state
	.loc 1 203 3 is_stmt 1 view .LVU748
	call	close@PLT
.LVL237:
	jmp	.L175
	.cfi_endproc
.LFE210:
	.size	bpf_linker__free.part.0, .-bpf_linker__free.part.0
	.p2align 4
	.type	emit_elf_data_sec.constprop.0, @function
emit_elf_data_sec.constprop.0:
.LVL238:
.LFB211:
	.loc 1 2820 12 view -0
	.cfi_startproc
	.loc 1 2823 2 view .LVU750
	.loc 1 2824 2 view .LVU751
	.loc 1 2825 2 view .LVU752
	.loc 1 2826 2 view .LVU753
	.loc 1 2828 2 view .LVU754
	.loc 1 2820 12 is_stmt 0 view .LVU755
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rdx, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rcx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.loc 1 2828 13 view .LVU756
	movq	56(%rdi), %rdi
.LVL239:
	.loc 1 2828 13 view .LVU757
	call	strset__add_str@PLT
.LVL240:
	.loc 1 2828 13 view .LVU758
	movl	%eax, %ebx
.LVL241:
	.loc 1 2829 2 is_stmt 1 view .LVU759
	.loc 1 2829 5 is_stmt 0 view .LVU760
	testl	%eax, %eax
	js	.L184
	.loc 1 2832 2 is_stmt 1 view .LVU761
	.loc 1 2832 8 is_stmt 0 view .LVU762
	movq	16(%r13), %rdi
	call	elf_newscn@PLT
.LVL242:
	.loc 1 2832 8 view .LVU763
	movq	%rax, %r14
.LVL243:
	.loc 1 2833 2 is_stmt 1 view .LVU764
	.loc 1 2833 5 is_stmt 0 view .LVU765
	testq	%rax, %rax
	je	.L187
	.loc 1 2835 2 is_stmt 1 view .LVU766
	.loc 1 2835 9 is_stmt 0 view .LVU767
	movq	%rax, %rdi
	call	elf_newdata@PLT
.LVL244:
	.loc 1 2835 9 view .LVU768
	movq	%rax, %r13
.LVL245:
	.loc 1 2836 2 is_stmt 1 view .LVU769
	.loc 1 2836 5 is_stmt 0 view .LVU770
	testq	%rax, %rax
	je	.L187
	.loc 1 2838 2 is_stmt 1 view .LVU771
	.loc 1 2838 9 is_stmt 0 view .LVU772
	movq	%r14, %rdi
	call	elf64_getshdr@PLT
.LVL246:
	.loc 1 2839 2 is_stmt 1 view .LVU773
	.loc 1 2839 5 is_stmt 0 view .LVU774
	testq	%rax, %rax
	je	.L188
	.loc 1 2842 2 is_stmt 1 view .LVU775
	.loc 1 2848 21 is_stmt 0 view .LVU776
	movdqa	.LC26(%rip), %xmm0
	.loc 1 2842 16 view .LVU777
	movl	%ebx, (%rax)
	.loc 1 2843 2 is_stmt 1 view .LVU778
	.loc 1 2857 9 is_stmt 0 view .LVU779
	xorl	%ebx, %ebx
.LVL247:
	.loc 1 2843 16 view .LVU780
	movl	$1, 4(%rax)
	.loc 1 2844 2 is_stmt 1 view .LVU781
	.loc 1 2844 17 is_stmt 0 view .LVU782
	movq	$0, 8(%rax)
	.loc 1 2845 2 is_stmt 1 view .LVU783
	.loc 1 2845 16 is_stmt 0 view .LVU784
	movq	%rbp, 32(%rax)
	.loc 1 2846 2 is_stmt 1 view .LVU785
	.loc 1 2847 2 view .LVU786
	.loc 1 2846 16 is_stmt 0 view .LVU787
	movq	$0, 40(%rax)
	.loc 1 2848 2 is_stmt 1 view .LVU788
	.loc 1 2849 2 view .LVU789
	.loc 1 2848 21 is_stmt 0 view .LVU790
	movups	%xmm0, 48(%rax)
	.loc 1 2851 2 is_stmt 1 view .LVU791
	.loc 1 2851 15 is_stmt 0 view .LVU792
	movl	$0, 8(%r13)
	.loc 1 2852 2 is_stmt 1 view .LVU793
	.loc 1 2852 15 is_stmt 0 view .LVU794
	movq	%rbp, 16(%r13)
	.loc 1 2853 2 is_stmt 1 view .LVU795
	.loc 1 2853 14 is_stmt 0 view .LVU796
	movq	%r12, 0(%r13)
	.loc 1 2854 2 is_stmt 1 view .LVU797
	.loc 1 2854 16 is_stmt 0 view .LVU798
	movq	$8, 32(%r13)
	.loc 1 2855 2 is_stmt 1 view .LVU799
	.loc 1 2855 14 is_stmt 0 view .LVU800
	movq	$0, 24(%r13)
	.loc 1 2857 2 is_stmt 1 view .LVU801
.LVL248:
.L184:
	.loc 1 2858 1 is_stmt 0 view .LVU802
	movl	%ebx, %eax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
.LVL249:
	.loc 1 2858 1 view .LVU803
	popq	%r12
	.cfi_def_cfa_offset 24
.LVL250:
	.loc 1 2858 1 view .LVU804
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.LVL251:
	.p2align 4,,10
	.p2align 3
.L187:
	.cfi_restore_state
	.loc 1 2834 10 view .LVU805
	movl	$-12, %ebx
.LVL252:
	.loc 1 2834 10 view .LVU806
	jmp	.L184
.LVL253:
.L188:
	.loc 1 2840 10 view .LVU807
	movl	$-22, %ebx
.LVL254:
	.loc 1 2840 10 view .LVU808
	jmp	.L184
	.cfi_endproc
.LFE211:
	.size	emit_elf_data_sec.constprop.0, .-emit_elf_data_sec.constprop.0
	.p2align 4
	.type	emit_btf_ext_data.part.0.isra.0, @function
emit_btf_ext_data.part.0.isra.0:
.LVL255:
.LFB212:
	.loc 1 2941 12 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 2952 2 view .LVU810
	.loc 1 2941 12 is_stmt 0 view .LVU811
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rcx, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	.loc 1 2941 12 view .LVU812
	movq	%rsi, %rbx
	movq	%rdx, %rsi
.LVL256:
	.loc 1 2952 12 view .LVU813
	call	btf__add_str@PLT
.LVL257:
	.loc 1 2953 2 is_stmt 1 view .LVU814
	.loc 1 2953 5 is_stmt 0 view .LVU815
	testl	%eax, %eax
	js	.L195
	.loc 1 2956 2 is_stmt 1 view .LVU816
.LVL258:
	.loc 1 2957 2 view .LVU817
	.loc 1 2961 35 is_stmt 0 view .LVU818
	movl	8(%rbp), %r12d
.LBB496:
.LBB497:
	.loc 3 29 10 discriminator 1 view .LVU819
	movq	16(%rbp), %rsi
.LBE497:
.LBE496:
	.loc 1 2957 25 view .LVU820
	movl	%eax, (%rbx)
	.loc 1 2958 2 is_stmt 1 view .LVU821
	.loc 1 2959 6 is_stmt 0 view .LVU822
	leaq	8(%rbx), %rdi
	.loc 1 2958 31 view .LVU823
	movq	0(%rbp), %rax
.LVL259:
	.loc 1 2961 5 view .LVU824
	imulq	%rax, %r12
	.loc 1 2958 21 view .LVU825
	movl	%eax, 4(%rbx)
	.loc 1 2959 2 is_stmt 1 view .LVU826
.LVL260:
	.loc 1 2961 2 view .LVU827
	.loc 1 2962 2 view .LVU828
.LBB499:
.LBI496:
	.loc 3 26 1 view .LVU829
.LBB498:
	.loc 3 29 3 view .LVU830
	.loc 3 29 10 is_stmt 0 discriminator 1 view .LVU831
	movq	%r12, %rdx
	call	memcpy@PLT
.LVL261:
	.loc 3 29 10 discriminator 1 view .LVU832
.LBE498:
.LBE499:
	.loc 1 2963 2 is_stmt 1 view .LVU833
	.loc 1 2965 2 view .LVU834
	.loc 1 2963 6 is_stmt 0 view .LVU835
	leaq	(%rax,%r12), %rax
.LVL262:
	.loc 1 2965 13 view .LVU836
	subl	%ebx, %eax
.LVL263:
.L193:
	.loc 1 2966 1 view .LVU837
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
.LVL264:
	.loc 1 2966 1 view .LVU838
	popq	%rbp
	.cfi_def_cfa_offset 16
.LVL265:
	.loc 1 2966 1 view .LVU839
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.LVL266:
	.p2align 4,,10
	.p2align 3
.L195:
	.cfi_restore_state
	.loc 1 2954 10 view .LVU840
	movl	$-12, %eax
.LVL267:
	.loc 1 2954 10 view .LVU841
	jmp	.L193
	.cfi_endproc
.LFE212:
	.size	emit_btf_ext_data.part.0.isra.0, .-emit_btf_ext_data.part.0.isra.0
	.section	.rodata.str1.8
	.align 8
.LC27:
	.string	"libbpf: sec %s types mismatch\n"
	.align 8
.LC28:
	.string	"libbpf: sec %s flags mismatch\n"
	.align 8
.LC29:
	.string	"libbpf: sec %s entsize mismatch\n"
	.text
	.p2align 4
	.type	secs_match.part.0.isra.0, @function
secs_match.part.0.isra.0:
.LFB213:
	.loc 1 1211 13 is_stmt 1 view -0
	.cfi_startproc
.LVL268:
	.loc 1 1216 2 view .LVU843
	.loc 1 1211 13 is_stmt 0 view .LVU844
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	.loc 1 1216 5 view .LVU845
	movl	4(%rdx), %eax
	cmpl	%eax, 4(%rsi)
	jne	.L204
	.loc 1 1220 2 is_stmt 1 view .LVU846
	.loc 1 1220 5 is_stmt 0 view .LVU847
	movq	8(%rdx), %rax
	cmpq	%rax, 8(%rsi)
	jne	.L205
	.loc 1 1224 2 is_stmt 1 view .LVU848
	.loc 1 1224 5 is_stmt 0 view .LVU849
	movq	56(%rdx), %rcx
	.loc 1 1214 10 view .LVU850
	movl	$1, %eax
	.loc 1 1224 5 view .LVU851
	cmpq	%rcx, 56(%rsi)
	jne	.L206
	.loc 1 1230 1 view .LVU852
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L205:
	.cfi_restore_state
	.loc 1 1221 3 is_stmt 1 view .LVU853
	.loc 1 1221 3 view .LVU854
	movq	%rdi, %rdx
	xorl	%eax, %eax
	leaq	.LC28(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL269:
	.loc 1 1221 3 discriminator 1 view .LVU855
	.loc 1 1222 3 view .LVU856
	.loc 1 1218 10 is_stmt 0 view .LVU857
	xorl	%eax, %eax
.L207:
	.loc 1 1230 1 view .LVU858
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L204:
	.cfi_restore_state
	.loc 1 1217 3 is_stmt 1 view .LVU859
	.loc 1 1217 3 view .LVU860
	movq	%rdi, %rdx
	xorl	%eax, %eax
	leaq	.LC27(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL270:
	.loc 1 1217 3 discriminator 1 view .LVU861
	.loc 1 1218 3 view .LVU862
	.loc 1 1218 10 is_stmt 0 view .LVU863
	xorl	%eax, %eax
	jmp	.L207
	.p2align 4,,10
	.p2align 3
.L206:
	.loc 1 1225 3 is_stmt 1 view .LVU864
	.loc 1 1225 3 view .LVU865
	movq	%rdi, %rdx
	xorl	%eax, %eax
	leaq	.LC29(%rip), %rsi
	xorl	%edi, %edi
	call	libbpf_print@PLT
.LVL271:
	.loc 1 1225 3 discriminator 1 view .LVU866
	.loc 1 1226 3 view .LVU867
	.loc 1 1218 10 is_stmt 0 view .LVU868
	xorl	%eax, %eax
	jmp	.L207
	.cfi_endproc
.LFE213:
	.size	secs_match.part.0.isra.0, .-secs_match.part.0.isra.0
	.p2align 4
	.type	extend_sec, @function
extend_sec:
.LVL272:
.LFB175:
	.loc 1 1260 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 1261 2 view .LVU870
	.loc 1 1262 2 view .LVU871
	.loc 1 1263 2 view .LVU872
	.loc 1 1264 2 view .LVU873
	.loc 1 1269 2 view .LVU874
	.loc 1 1269 5 is_stmt 0 view .LVU875
	cmpb	$0, 21(%rdx)
	jne	.L230
	.loc 1 1260 1 view .LVU876
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdx, %r14
	.loc 1 1278 2 is_stmt 1 view .LVU877
	.loc 1 1260 1 is_stmt 0 view .LVU878
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	.loc 1 1278 5 view .LVU879
	cmpb	$0, 12(%rsi)
	jne	.L210
.LVL273:
.L214:
	.loc 1 1284 2 is_stmt 1 view .LVU880
	.loc 1 1284 17 is_stmt 0 view .LVU881
	movq	32(%rbx), %rcx
.LVL274:
	.loc 1 1285 2 is_stmt 1 view .LVU882
	.loc 1 1285 17 is_stmt 0 view .LVU883
	movq	40(%r14), %rsi
.LVL275:
	.loc 1 1286 2 is_stmt 1 view .LVU884
	.loc 1 1288 2 view .LVU885
	.loc 1 1288 5 is_stmt 0 view .LVU886
	movl	$1, %eax
	movq	48(%rcx), %rbp
	.loc 1 1294 15 view .LVU887
	movq	32(%rsi), %r15
	.loc 1 1288 5 view .LVU888
	testq	%rbp, %rbp
	cmove	%rax, %rbp
	movq	48(%rsi), %rax
	cmpq	%rax, %rbp
	cmovb	%rax, %rbp
.LVL276:
	.loc 1 1291 2 is_stmt 1 view .LVU889
	.loc 1 1291 21 is_stmt 0 view .LVU890
	movslq	48(%rbx), %rax
	.loc 1 1291 15 view .LVU891
	xorl	%edx, %edx
	.loc 1 1291 42 view .LVU892
	leaq	-1(%rbp,%rax), %r12
	.loc 1 1291 15 view .LVU893
	movq	%r12, %rax
	divq	%rbp
	subq	%rdx, %r12
.LVL277:
	.loc 1 1294 2 is_stmt 1 view .LVU894
	.loc 1 1294 15 is_stmt 0 view .LVU895
	addq	%r12, %r15
.LVL278:
	.loc 1 1296 2 is_stmt 1 view .LVU896
	.loc 1 1296 5 is_stmt 0 view .LVU897
	cmpl	$8, 4(%rsi)
	jne	.L233
.LVL279:
.L212:
	.loc 1 1324 2 is_stmt 1 view .LVU898
	.loc 1 1326 5 is_stmt 0 view .LVU899
	movq	40(%rbx), %rax
	.loc 1 1324 14 view .LVU900
	movl	%r15d, 48(%rbx)
	.loc 1 1325 2 is_stmt 1 view .LVU901
	.loc 1 1325 21 is_stmt 0 view .LVU902
	movq	%r15, 32(%rcx)
	.loc 1 1326 2 is_stmt 1 view .LVU903
	.loc 1 1326 20 is_stmt 0 view .LVU904
	movq	%r15, 16(%rax)
	.loc 1 1328 2 is_stmt 1 view .LVU905
	.loc 1 1328 26 is_stmt 0 view .LVU906
	movq	%rbp, 48(%rcx)
	.loc 1 1329 2 is_stmt 1 view .LVU907
	.loc 1 1329 21 is_stmt 0 view .LVU908
	movq	%rbp, 32(%rax)
	.loc 1 1331 2 is_stmt 1 view .LVU909
	.loc 1 1270 10 is_stmt 0 view .LVU910
	xorl	%eax, %eax
	.loc 1 1331 15 view .LVU911
	movl	%r12d, 16(%r14)
	.loc 1 1333 2 is_stmt 1 view .LVU912
.LVL280:
.L208:
	.loc 1 1334 1 is_stmt 0 view .LVU913
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
.LVL281:
	.loc 1 1334 1 view .LVU914
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
.LVL282:
	.loc 1 1334 1 view .LVU915
	popq	%r14
	.cfi_def_cfa_offset 16
.LVL283:
	.loc 1 1334 1 view .LVU916
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.LVL284:
	.p2align 4,,10
	.p2align 3
.L233:
	.cfi_restore_state
	.loc 1 1297 3 is_stmt 1 view .LVU917
	.loc 1 1297 9 is_stmt 0 view .LVU918
	movq	56(%rbx), %rdi
	movq	%r15, %rsi
.LVL285:
	.loc 1 1297 9 view .LVU919
	call	realloc@PLT
.LVL286:
	.loc 1 1310 3 is_stmt 1 view .LVU920
	.loc 1 1310 6 is_stmt 0 view .LVU921
	testq	%rax, %rax
	jne	.L221
	testq	%r12, %r12
	jne	.L220
.L221:
	.loc 1 1312 3 is_stmt 1 view .LVU922
	.loc 1 1315 60 is_stmt 0 view .LVU923
	movslq	48(%rbx), %rdx
.LBB516:
.LBB517:
	.loc 3 59 10 discriminator 1 view .LVU924
	movq	%r15, %rcx
.LBE517:
.LBE516:
	.loc 1 1312 17 view .LVU925
	movq	%rax, 56(%rbx)
	.loc 1 1315 3 is_stmt 1 view .LVU926
.LVL287:
.LBB522:
.LBI516:
	.loc 3 57 1 view .LVU927
.LBB518:
	.loc 3 59 3 view .LVU928
.LBE518:
.LBE522:
	.loc 1 1315 3 is_stmt 0 view .LVU929
	movq	%r12, %rsi
.LBB523:
.LBB519:
	.loc 3 59 10 discriminator 1 view .LVU930
	cmpq	%r15, %rdx
.LBE519:
.LBE523:
	.loc 1 1315 3 view .LVU931
	leaq	(%rax,%rdx), %rdi
.LVL288:
.LBB524:
.LBB520:
	.loc 3 59 10 discriminator 1 view .LVU932
	cmovnb	%rdx, %rcx
.LBE520:
.LBE524:
	.loc 1 1315 3 view .LVU933
	subq	%rdx, %rsi
.LVL289:
.LBB525:
.LBB521:
	.loc 3 59 10 discriminator 1 view .LVU934
	subq	%rdx, %rcx
	movq	%rsi, %rdx
	xorl	%esi, %esi
.LVL290:
	.loc 3 59 10 discriminator 1 view .LVU935
	call	__memset_chk@PLT
.LVL291:
	.loc 3 59 10 discriminator 1 view .LVU936
.LBE521:
.LBE525:
	.loc 1 1317 3 is_stmt 1 view .LVU937
.LBB526:
.LBI526:
	.loc 3 26 1 view .LVU938
.LBB527:
	.loc 3 29 3 view .LVU939
.LBE527:
.LBE526:
	.loc 1 1317 49 is_stmt 0 view .LVU940
	movq	48(%r14), %rdx
	.loc 1 1317 3 view .LVU941
	movq	40(%r14), %rax
	movq	56(%rbx), %rdi
.LBB530:
.LBB528:
	.loc 3 29 10 discriminator 1 view .LVU942
	movq	(%rdx), %rsi
	movq	32(%rax), %rdx
.LBE528:
.LBE530:
	.loc 1 1317 3 view .LVU943
	addq	%r12, %rdi
.LVL292:
.LBB531:
.LBB529:
	.loc 3 29 10 discriminator 1 view .LVU944
	call	memcpy@PLT
.LVL293:
	.loc 3 29 10 discriminator 1 view .LVU945
.LBE529:
.LBE531:
	.loc 1 1320 3 is_stmt 1 view .LVU946
	.loc 1 1320 6 is_stmt 0 view .LVU947
	cmpb	$0, 32(%r13)
	movq	32(%rbx), %rcx
	je	.L212
.LVL294:
.LBB532:
.LBI532:
	.loc 1 1241 13 is_stmt 1 view .LVU948
.LBB533:
	.loc 1 1243 2 view .LVU949
	.loc 1 1243 11 is_stmt 0 discriminator 1 view .LVU950
	cmpb	$0, 12(%rbx)
	jne	.L212
.LBB534:
.LBI534:
	.loc 1 1241 13 is_stmt 1 view .LVU951
.LVL295:
.LBB535:
	.loc 1 1245 2 view .LVU952
	.loc 1 1245 46 is_stmt 0 view .LVU953
	cmpl	$1, 4(%rcx)
	jne	.L212
	.loc 1 1245 46 discriminator 1 view .LVU954
	testb	$4, 8(%rcx)
	je	.L212
.LVL296:
	.loc 1 1245 46 discriminator 1 view .LVU955
.LBE535:
.LBE534:
.LBE533:
.LBE532:
	.loc 1 1321 4 is_stmt 1 view .LVU956
	.loc 1 1321 58 is_stmt 0 view .LVU957
	movq	40(%r14), %rdx
	.loc 1 1321 4 view .LVU958
	movq	56(%rbx), %rax
.LBB536:
.LBB537:
	.loc 1 1251 28 view .LVU959
	movslq	32(%rdx), %rdx
.LBE537:
.LBE536:
	.loc 1 1321 4 view .LVU960
	addq	%r12, %rax
.LVL297:
.LBB551:
.LBI536:
	.loc 1 1249 13 is_stmt 1 view .LVU961
.LBB550:
	.loc 1 1251 2 view .LVU962
	.loc 1 1251 28 is_stmt 0 view .LVU963
	shrq	$3, %rdx
.LVL298:
	.loc 1 1252 2 is_stmt 1 view .LVU964
	.loc 1 1253 2 view .LVU965
	.loc 1 1255 2 view .LVU966
	.loc 1 1255 16 discriminator 1 view .LVU967
	testl	%edx, %edx
	jle	.L212
	movl	%edx, %edx
	.loc 1 1255 16 is_stmt 0 discriminator 1 view .LVU968
	leaq	(%rax,%rdx,8), %rsi
.LVL299:
	.p2align 4,,10
	.p2align 3
.L219:
	.loc 1 1256 3 is_stmt 1 view .LVU969
.LBB538:
.LBI538:
	.loc 2 635 20 view .LVU970
.LBB539:
	.loc 2 637 2 view .LVU971
	.loc 2 639 2 view .LVU972
	.loc 2 640 2 view .LVU973
.LBB540:
.LBB541:
	.file 6 "/usr/include/x86_64-linux-gnu/bits/byteswap.h"
	.loc 6 52 10 is_stmt 0 view .LVU974
	movl	4(%rax), %edx
.LBE541:
.LBE540:
	.loc 2 639 16 view .LVU975
	rolb	$4, 1(%rax)
.LVL300:
	.loc 2 641 2 is_stmt 1 view .LVU976
.LBB544:
.LBI544:
	.loc 6 34 1 view .LVU977
.LBB545:
	.loc 6 37 3 view .LVU978
	.loc 6 37 3 is_stmt 0 view .LVU979
.LBE545:
.LBE544:
	.loc 2 641 12 discriminator 1 view .LVU980
	rolw	$8, 2(%rax)
	.loc 2 642 2 is_stmt 1 view .LVU981
.LVL301:
.LBB546:
.LBI540:
	.loc 6 49 1 view .LVU982
.LBB542:
	.loc 6 52 3 view .LVU983
.LBE542:
.LBE546:
.LBE539:
.LBE538:
	.loc 1 1255 37 is_stmt 0 discriminator 3 view .LVU984
	addq	$8, %rax
.LVL302:
.LBB549:
.LBB548:
.LBB547:
.LBB543:
	.loc 6 52 10 view .LVU985
	bswap	%edx
.LVL303:
	.loc 6 52 10 view .LVU986
.LBE543:
.LBE547:
	.loc 2 642 12 discriminator 1 view .LVU987
	movl	%edx, -4(%rax)
.LVL304:
	.loc 2 642 12 discriminator 1 view .LVU988
.LBE548:
.LBE549:
	.loc 1 1255 31 is_stmt 1 discriminator 3 view .LVU989
	.loc 1 1255 16 discriminator 1 view .LVU990
	cmpq	%rax, %rsi
	jne	.L219
	jmp	.L212
.LVL305:
	.p2align 4,,10
	.p2align 3
.L210:
	.loc 1 1255 16 is_stmt 0 discriminator 1 view .LVU991
.LBE550:
.LBE551:
	.loc 1 1279 3 is_stmt 1 view .LVU992
	.loc 1 1279 9 is_stmt 0 view .LVU993
	call	init_sec
.LVL306:
	.loc 1 1280 3 is_stmt 1 view .LVU994
	.loc 1 1280 6 is_stmt 0 view .LVU995
	testl	%eax, %eax
	je	.L214
	jmp	.L208
.LVL307:
	.p2align 4,,10
	.p2align 3
.L230:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	.loc 1 1270 10 view .LVU996
	xorl	%eax, %eax
	.loc 1 1334 1 view .LVU997
	ret
.LVL308:
.L220:
	.cfi_def_cfa_offset 64
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	.loc 1 1311 11 view .LVU998
	movl	$-12, %eax
.LVL309:
	.loc 1 1311 11 view .LVU999
	jmp	.L208
	.cfi_endproc
.LFE175:
	.size	extend_sec, .-extend_sec
	.p2align 4
	.type	add_new_sym.isra.0, @function
add_new_sym.isra.0:
.LVL310:
.LFB215:
	.loc 1 335 19 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 337 2 view .LVU1001
	.loc 1 337 40 is_stmt 0 view .LVU1002
	leaq	(%rsi,%rsi,4), %rax
	.loc 1 335 19 view .LVU1003
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	.loc 1 337 40 view .LVU1004
	salq	$5, %rax
	.loc 1 335 19 view .LVU1005
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	movq	%rdx, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	.loc 1 337 18 view .LVU1006
	leaq	(%rdi,%rax), %rbp
.LVL311:
	.loc 1 338 2 is_stmt 1 view .LVU1007
	.loc 1 339 2 view .LVU1008
	.loc 1 339 9 is_stmt 0 view .LVU1009
	movabsq	$-6148914691236517205, %rax
	.loc 1 335 19 view .LVU1010
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	.loc 1 339 25 view .LVU1011
	movslq	48(%rbp), %rdx
.LVL312:
	.loc 1 341 9 view .LVU1012
	movq	56(%rbp), %rdi
	.loc 1 339 9 view .LVU1013
	mulq	%rdx
	shrq	$4, %rdx
	.loc 1 341 9 view .LVU1014
	leaq	1(%rdx), %rcx
	.loc 1 339 9 view .LVU1015
	movq	%rdx, %r13
.LVL313:
	.loc 1 341 2 is_stmt 1 view .LVU1016
.LBB556:
.LBI556:
	.loc 2 208 21 view .LVU1017
.LBB557:
	.loc 2 210 2 view .LVU1018
	.loc 2 213 2 view .LVU1019
	.loc 2 213 6 is_stmt 0 view .LVU1020
	movl	$24, %edx
.LVL314:
	.loc 2 213 6 view .LVU1021
	movq	%rcx, %rax
	mulq	%rdx
	jo	.L239
	.loc 2 220 9 view .LVU1022
	movq	%rax, %rsi
	movq	%rax, %rbx
	.loc 2 220 2 is_stmt 1 view .LVU1023
	.loc 2 220 9 is_stmt 0 view .LVU1024
	call	realloc@PLT
.LVL315:
	.loc 2 220 9 view .LVU1025
	movq	%rax, %r14
.LVL316:
	.loc 2 220 9 view .LVU1026
.LBE557:
.LBE556:
	.loc 1 342 2 is_stmt 1 view .LVU1027
	.loc 1 342 5 is_stmt 0 view .LVU1028
	testq	%rax, %rax
	je	.L239
	.loc 1 345 2 is_stmt 1 view .LVU1029
	.loc 1 345 13 is_stmt 0 view .LVU1030
	leaq	0(%r13,%r13,2), %rdx
	salq	$3, %rdx
.LBB558:
.LBB559:
	.loc 3 59 10 discriminator 1 view .LVU1031
	cmpq	%rdx, %rbx
.LBE559:
.LBE558:
	.loc 1 345 6 view .LVU1032
	leaq	(%rax,%rdx), %rdi
.LVL317:
	.loc 1 346 2 is_stmt 1 view .LVU1033
.LBB562:
.LBI558:
	.loc 3 57 1 view .LVU1034
.LBB560:
	.loc 3 59 3 view .LVU1035
	.loc 3 59 10 is_stmt 0 discriminator 1 view .LVU1036
	cmovb	%rdx, %rbx
	xorl	%esi, %esi
	movq	%rbx, %rcx
	subq	%rdx, %rcx
	movl	$24, %edx
	call	__memset_chk@PLT
.LVL318:
	.loc 3 59 10 discriminator 1 view .LVU1037
.LBE560:
.LBE562:
	.loc 1 349 17 view .LVU1038
	addl	$24, 48(%rbp)
.LBB563:
.LBB561:
	.loc 3 59 10 discriminator 1 view .LVU1039
	movq	%rax, %rdi
.LVL319:
	.loc 3 59 10 discriminator 1 view .LVU1040
.LBE561:
.LBE563:
	.loc 1 348 2 is_stmt 1 view .LVU1041
	.loc 1 350 8 is_stmt 0 view .LVU1042
	movq	32(%rbp), %rax
	.loc 1 348 19 view .LVU1043
	movq	%r14, 56(%rbp)
	.loc 1 349 2 is_stmt 1 view .LVU1044
	.loc 1 350 2 view .LVU1045
	.loc 1 350 24 is_stmt 0 view .LVU1046
	addq	$24, 32(%rax)
	.loc 1 351 2 is_stmt 1 view .LVU1047
	.loc 1 351 8 is_stmt 0 view .LVU1048
	movq	40(%rbp), %rax
	.loc 1 351 23 view .LVU1049
	addq	$24, 16(%rax)
	.loc 1 353 2 is_stmt 1 view .LVU1050
	.loc 1 353 5 is_stmt 0 view .LVU1051
	testq	%r12, %r12
	je	.L234
	.loc 1 354 3 is_stmt 1 view .LVU1052
	.loc 1 354 12 is_stmt 0 view .LVU1053
	movq	%r13, (%r12)
.LVL320:
.L234:
	.loc 1 357 1 view .LVU1054
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rdi, %rax
	popq	%rbp
	.cfi_def_cfa_offset 32
.LVL321:
	.loc 1 357 1 view .LVU1055
	popq	%r12
	.cfi_def_cfa_offset 24
.LVL322:
	.loc 1 357 1 view .LVU1056
	popq	%r13
	.cfi_def_cfa_offset 16
.LVL323:
	.loc 1 357 1 view .LVU1057
	popq	%r14
	.cfi_def_cfa_offset 8
	.loc 1 357 1 view .LVU1058
	ret
.LVL324:
.L239:
	.cfi_restore_state
	.loc 1 343 10 view .LVU1059
	xorl	%edi, %edi
	.loc 1 357 1 view .LVU1060
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
.LVL325:
	.loc 1 357 1 view .LVU1061
	movq	%rdi, %rax
	popq	%r12
	.cfi_def_cfa_offset 24
.LVL326:
	.loc 1 357 1 view .LVU1062
	popq	%r13
	.cfi_def_cfa_offset 16
.LVL327:
	.loc 1 357 1 view .LVU1063
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE215:
	.size	add_new_sym.isra.0, .-add_new_sym.isra.0
	.section	.rodata.str1.8
	.align 8
.LC30:
	.string	"libbpf: failed to create ELF object: %s\n"
	.align 8
.LC31:
	.string	"libbpf: failed to create ELF header: %s\n"
	.section	.rodata.str1.1
.LC33:
	.string	""
.LC34:
	.string	".strtab"
	.section	.rodata.str1.8
	.align 8
.LC35:
	.string	"libbpf: failed to create STRTAB section: %s\n"
	.align 8
.LC36:
	.string	"libbpf: failed to create STRTAB data: %s\n"
	.section	.rodata.str1.1
.LC37:
	.string	".symtab"
	.section	.rodata.str1.8
	.align 8
.LC38:
	.string	"libbpf: failed to create SYMTAB section: %s\n"
	.align 8
.LC39:
	.string	"libbpf: failed to create SYMTAB data: %s\n"
	.text
	.p2align 4
	.type	init_output_elf, @function
init_output_elf:
.LVL328:
.LFB153:
	.loc 1 360 1 is_stmt 1 view -0
	.cfi_startproc
	.loc 1 361 2 view .LVU1065
	.loc 1 362 2 view .LVU1066
	.loc 1 363 2 view .LVU1067
	.loc 1 365 2 view .LVU1068
	.loc 1 360 1 is_stmt 0 view .LVU1069
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	.loc 1 365 16 view .LVU1070
	xorl	%edx, %edx
	movl	$3, %esi
	.loc 1 360 1 view .LVU1071
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	.loc 1 360 1 view .LVU1072
	movq	%rdi, %rbx
	.loc 1 365 16 view .LVU1073
	movl	8(%rdi), %edi
.LVL329:
	.loc 1 365 16 view .LVU1074
	call	elf_begin@PLT
.LVL330:
	.loc 1 365 14 discriminator 1 view .LVU1075
	movq	%rax, 16(%rbx)
	.loc 1 366 2 is_stmt 1 view .LVU1076
	.loc 1 366 5 is_stmt 0 view .LVU1077
	testq	%rax, %rax
	je	.L273
	movq	%rax, %rdi
	.loc 1 372 2 is_stmt 1 view .LVU1078
	.loc 1 372 20 is_stmt 0 view .LVU1079
	call	elf64_newehdr@PLT
.LVL331:
	.loc 1 372 18 discriminator 1 view .LVU1080
	movq	%rax, 24(%rbx)
	.loc 1 373 2 is_stmt 1 view .LVU1081
	.loc 1 373 5 is_stmt 0 view .LVU1082
	testq	%rax, %rax
	je	.L274
	.loc 1 378 2 is_stmt 1 view .LVU1083
	.loc 1 379 2 view .LVU1084
	.loc 1 381 36 is_stmt 0 view .LVU1085
	movb	$0, 5(%rax)
	.loc 1 385 24 view .LVU1086
	movl	$2147483647, %edi
	movl	$1, %edx
	leaq	.LC33(%rip), %rsi
	.loc 1 379 26 view .LVU1087
	movl	$16187393, 16(%rax)
	.loc 1 381 2 is_stmt 1 view .LVU1088
	.loc 1 385 2 view .LVU1089
	.loc 1 385 24 is_stmt 0 view .LVU1090
	call	strset__new@PLT
.LVL332:
	.loc 1 385 22 discriminator 1 view .LVU1091
	movq	%rax, 56(%rbx)
	.loc 1 386 2 is_stmt 1 view .LVU1092
	.loc 1 385 24 is_stmt 0 view .LVU1093
	movq	%rax, %rdi
	.loc 1 386 6 view .LVU1094
	call	libbpf_get_error@PLT
.LVL333:
	.loc 1 386 5 discriminator 1 view .LVU1095
	testq	%rax, %rax
	jne	.L275
	.loc 1 389 2 is_stmt 1 view .LVU1096
	.loc 1 389 8 is_stmt 0 view .LVU1097
	leaq	.LC34(%rip), %rsi
	movq	%rbx, %rdi
	call	add_dst_sec
.LVL334:
	movq	%rax, %rbp
.LVL335:
	.loc 1 390 2 is_stmt 1 view .LVU1098
	.loc 1 390 5 is_stmt 0 view .LVU1099
	testq	%rax, %rax
	je	.L259
	.loc 1 393 2 is_stmt 1 view .LVU1100
	.loc 1 393 13 is_stmt 0 view .LVU1101
	movq	16(%rbx), %rdi
	call	elf_newscn@PLT
.LVL336:
	.loc 1 393 11 discriminator 1 view .LVU1102
	movq	%rax, 24(%rbp)
	.loc 1 394 2 is_stmt 1 view .LVU1103
	.loc 1 393 13 is_stmt 0 view .LVU1104
	movq	%rax, %rdi
	.loc 1 394 5 view .LVU1105
	testq	%rax, %rax
	je	.L276
	.loc 1 399 2 is_stmt 1 view .LVU1106
	.loc 1 399 14 is_stmt 0 view .LVU1107
	call	elf64_getshdr@PLT
.LVL337:
	.loc 1 399 12 discriminator 1 view .LVU1108
	movq	%rax, 32(%rbp)
	.loc 1 400 2 is_stmt 1 view .LVU1109
	.loc 1 400 5 is_stmt 0 view .LVU1110
	testq	%rax, %rax
	je	.L251
	.loc 1 403 2 is_stmt 1 view .LVU1111
	.loc 1 403 14 is_stmt 0 view .LVU1112
	movq	24(%rbp), %rdi
	call	elf_newdata@PLT
.LVL338:
	.loc 1 403 12 discriminator 1 view .LVU1113
	movq	%rax, 40(%rbp)
	.loc 1 404 2 is_stmt 1 view .LVU1114
	.loc 1 404 5 is_stmt 0 view .LVU1115
	testq	%rax, %rax
	je	.L277
	.loc 1 409 2 is_stmt 1 view .LVU1116
	.loc 1 409 12 is_stmt 0 view .LVU1117
	movq	0(%rbp), %rsi
	movq	56(%rbx), %rdi
	call	strset__add_str@PLT
.LVL339:
	movl	%eax, %r12d
.LVL340:
	.loc 1 410 2 is_stmt 1 view .LVU1118
	.loc 1 410 5 is_stmt 0 view .LVU1119
	testl	%eax, %eax
	js	.L249
	.loc 1 413 2 is_stmt 1 view .LVU1120
	.loc 1 413 17 is_stmt 0 view .LVU1121
	movq	24(%rbp), %rdi
	call	elf_ndxscn@PLT
.LVL341:
	.loc 1 414 30 view .LVU1122
	movq	24(%rbx), %rdx
	.loc 1 428 8 view .LVU1123
	leaq	.LC37(%rip), %rsi
	movq	%rbx, %rdi
	.loc 1 413 15 discriminator 1 view .LVU1124
	movq	%rax, 16(%rbp)
	.loc 1 414 2 is_stmt 1 view .LVU1125
	.loc 1 414 30 is_stmt 0 view .LVU1126
	movw	%ax, 62(%rdx)
	.loc 1 415 2 is_stmt 1 view .LVU1127
	.loc 1 415 25 is_stmt 0 view .LVU1128
	movq	%rax, 64(%rbx)
	.loc 1 417 2 is_stmt 1 view .LVU1129
	.loc 1 417 5 is_stmt 0 view .LVU1130
	movq	32(%rbp), %rax
	.loc 1 417 21 view .LVU1131
	movl	%r12d, (%rax)
	.loc 1 418 2 is_stmt 1 view .LVU1132
	.loc 1 418 21 is_stmt 0 view .LVU1133
	movl	$3, 4(%rax)
	.loc 1 419 2 is_stmt 1 view .LVU1134
	.loc 1 419 22 is_stmt 0 view .LVU1135
	movq	$32, 8(%rax)
	.loc 1 420 2 is_stmt 1 view .LVU1136
	.loc 1 420 23 is_stmt 0 view .LVU1137
	movq	$0, 24(%rax)
	.loc 1 421 2 is_stmt 1 view .LVU1138
	.loc 1 422 2 view .LVU1139
	.loc 1 421 21 is_stmt 0 view .LVU1140
	movq	$0, 40(%rax)
	.loc 1 423 2 is_stmt 1 view .LVU1141
	.loc 1 423 26 is_stmt 0 view .LVU1142
	movq	$1, 48(%rax)
	.loc 1 424 2 is_stmt 1 view .LVU1143
	.loc 1 424 35 is_stmt 0 view .LVU1144
	movl	$0, 48(%rbp)
	.loc 1 424 21 view .LVU1145
	movq	$0, 32(%rax)
	.loc 1 425 2 is_stmt 1 view .LVU1146
	.loc 1 425 24 is_stmt 0 view .LVU1147
	movq	$0, 56(%rax)
	.loc 1 428 2 is_stmt 1 view .LVU1148
	.loc 1 428 8 is_stmt 0 view .LVU1149
	call	add_dst_sec
.LVL342:
	movq	%rax, %rbp
.LVL343:
	.loc 1 429 2 is_stmt 1 view .LVU1150
	.loc 1 429 5 is_stmt 0 view .LVU1151
	testq	%rax, %rax
	je	.L259
	.loc 1 432 2 is_stmt 1 view .LVU1152
	.loc 1 432 13 is_stmt 0 view .LVU1153
	movq	16(%rbx), %rdi
	call	elf_newscn@PLT
.LVL344:
	.loc 1 432 11 discriminator 1 view .LVU1154
	movq	%rax, 24(%rbp)
	.loc 1 433 2 is_stmt 1 view .LVU1155
	.loc 1 432 13 is_stmt 0 view .LVU1156
	movq	%rax, %rdi
	.loc 1 433 5 view .LVU1157
	testq	%rax, %rax
	je	.L278
	.loc 1 438 2 is_stmt 1 view .LVU1158
	.loc 1 438 14 is_stmt 0 view .LVU1159
	call	elf64_getshdr@PLT
.LVL345:
	.loc 1 438 12 discriminator 1 view .LVU1160
	movq	%rax, 32(%rbp)
	.loc 1 439 2 is_stmt 1 view .LVU1161
	.loc 1 439 5 is_stmt 0 view .LVU1162
	testq	%rax, %rax
	je	.L251
	.loc 1 442 2 is_stmt 1 view .LVU1163
	.loc 1 442 14 is_stmt 0 view .LVU1164
	movq	24(%rbp), %rdi
	call	elf_newdata@PLT
.LVL346:
	.loc 1 442 12 discriminator 1 view .LVU1165
	movq	%rax, 40(%rbp)
	.loc 1 443 2 is_stmt 1 view .LVU1166
	.loc 1 443 5 is_stmt 0 view .LVU1167
	testq	%rax, %rax
	je	.L279
	.loc 1 448 2 is_stmt 1 view .LVU1168
	.loc 1 450 12 is_stmt 0 view .LVU1169
	movq	0(%rbp), %rsi
	movq	56(%rbx), %rdi
	.loc 1 448 20 view .LVU1170
	movl	$11, 8(%rax)
	.loc 1 450 2 is_stmt 1 view .LVU1171
	.loc 1 450 12 is_stmt 0 view .LVU1172
	call	strset__add_str@PLT
.LVL347:
	movl	%eax, %r12d
.LVL348:
	.loc 1 451 2 is_stmt 1 view .LVU1173
	.loc 1 451 5 is_stmt 0 view .LVU1174
	testl	%eax, %eax
	js	.L249
	.loc 1 454 2 is_stmt 1 view .LVU1175
	.loc 1 454 17 is_stmt 0 view .LVU1176
	movq	24(%rbp), %rdi
	call	elf_ndxscn@PLT
.LVL349:
	.loc 1 461 21 view .LVU1177
	movq	64(%rbx), %rdx
	.loc 1 466 26 view .LVU1178
	movdqa	.LC40(%rip), %xmm0
	.loc 1 454 15 discriminator 1 view .LVU1179
	movq	%rax, 16(%rbp)
	.loc 1 455 2 is_stmt 1 view .LVU1180
	.loc 1 455 25 is_stmt 0 view .LVU1181
	movq	%rax, 72(%rbx)
	.loc 1 457 2 is_stmt 1 view .LVU1182
	.loc 1 457 5 is_stmt 0 view .LVU1183
	movq	32(%rbp), %rax
	.loc 1 457 21 view .LVU1184
	movl	%r12d, (%rax)
	.loc 1 458 2 is_stmt 1 view .LVU1185
	.loc 1 461 21 is_stmt 0 view .LVU1186
	movl	%edx, 40(%rax)
	.loc 1 458 21 view .LVU1187
	movl	$2, 4(%rax)
	.loc 1 459 2 is_stmt 1 view .LVU1188
	.loc 1 459 22 is_stmt 0 view .LVU1189
	movq	$0, 8(%rax)
	.loc 1 460 2 is_stmt 1 view .LVU1190
	.loc