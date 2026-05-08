	.text
	.intel_syntax noprefix
	.file	"balancer.bpf.c"
	.section	.rodata.cst16,"aM",@progbits,16
	.p2align	4, 0x0                          # -- Begin function balancer_ingress
.LCPI0_0:
	.quad	1                               # 0x1
	.zero	8
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3, 0x0
.LCPI0_1:
	.quad	1                               # 0x1
	.text
	.globl	balancer_ingress
	.p2align	4, 0x90
	.type	balancer_ingress,@function
balancer_ingress:                       # @balancer_ingress
	.cfi_startproc
# %bb.0:
	mov	ecx, dword ptr [rdi]
	mov	edx, dword ptr [rdi + 4]
	lea	rsi, [rcx + 14]
	mov	eax, 1
	cmp	rsi, rdx
	ja	.LBB0_354
# %bb.1:
	push	rbp
	.cfi_def_cfa_offset 16
	push	r15
	.cfi_def_cfa_offset 24
	push	r14
	.cfi_def_cfa_offset 32
	push	r13
	.cfi_def_cfa_offset 40
	push	r12
	.cfi_def_cfa_offset 48
	push	rbx
	.cfi_def_cfa_offset 56
	sub	rsp, 168
	.cfi_def_cfa_offset 224
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	.cfi_offset rbp, -16
	mov	dword ptr [rsp + 92], 528
	lea	rsi, [rip + stats]
	lea	r8, [rsp + 92]
	#APP
	#NO_APP
	test	rsi, rsi
	je	.LBB0_353
# %bb.2:
	sub	rdx, rcx
	vpbroadcastq	xmm2, qword ptr [rip + .LCPI0_1] # xmm2 = [1,1]
	vpinsrq	xmm3, xmm2, rdx, 1
	vpaddq	xmm0, xmm3, xmmword ptr [rsi]
	vmovdqu	xmmword ptr [rsi], xmm0
	movzx	ecx, word ptr [rcx + 12]
	cmp	ecx, 56710
	je	.LBB0_6
# %bb.3:
	cmp	ecx, 8
	jne	.LBB0_349
# %bb.4:
	mov	edx, dword ptr [rdi]
	mov	esi, dword ptr [rdi + 4]
	vpxor	xmm0, xmm0, xmm0
	vmovdqu	ymmword ptr [rsp + 48], ymm0
	vmovdqu	ymmword ptr [rsp + 32], ymm0
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp + 96], xmm0
	mov	dword ptr [rsp + 112], 0
	mov	dword ptr [rsp + 152], 0
	lea	r8, [rdx + 34]
	cmp	r8, rsi
	ja	.LBB0_5
# %bb.8:
	movzx	ecx, byte ptr [rdx + 14]
	and	cl, 15
	cmp	cl, 5
	jne	.LBB0_5
# %bb.9:
	movzx	ecx, byte ptr [rdx + 15]
	mov	byte ptr [rsp + 77], cl
	movzx	r9d, byte ptr [rdx + 23]
	mov	byte ptr [rsp + 68], r9b
	movzx	r10d, word ptr [rdx + 20]
	test	r10d, 65343
	jne	.LBB0_5
# %bb.20:
	movzx	ebp, word ptr [rdx + 16]
	cmp	r9b, 1
	jne	.LBB0_32
# %bb.21:
	lea	rcx, [rdx + 42]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.40:
	movzx	r9d, byte ptr [r8]
	cmp	r9d, 3
	je	.LBB0_96
# %bb.41:
	mov	ecx, 2
	cmp	r9d, 8
	jne	.LBB0_346
# %bb.42:
	mov	byte ptr [rdx + 34], 0
	add	word ptr [rdx + 36], 8
	movzx	ecx, bp
	mov	byte ptr [rdx + 22], 64
	vmovsd	xmm0, qword ptr [rdx + 26]      # xmm0 = mem[0],zero
	vshufps	xmm0, xmm0, xmm0, 225           # xmm0 = xmm0[1,0,2,3]
	vmovlps	qword ptr [rdx + 26], xmm0
	movzx	esi, word ptr [rdx + 14]
	movzx	edi, word ptr [rdx + 18]
	add	rdi, rsi
	add	rdi, rcx
	vpmovzxwq	ymm0, qword ptr [rdx + 26] # ymm0 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	movzx	ecx, word ptr [rdx + 22]
	vextracti128	xmm1, ymm0, 1
	vpaddq	xmm0, xmm0, xmm1
	vpshufd	xmm1, xmm0, 238                 # xmm1 = xmm0[2,3,2,3]
	vpaddq	xmm0, xmm0, xmm1
	vmovq	rsi, xmm0
	add	r10, rcx
	add	r10, rdi
	add	r10, rsi
	mov	rcx, r10
	shr	rcx, 16
	movzx	esi, r10w
	add	rsi, rcx
	cmp	r10, 65536
	cmovb	rsi, r10
	jmp	.LBB0_43
.LBB0_6:
	mov	edx, dword ptr [rdi]
	mov	esi, dword ptr [rdi + 4]
	vpxor	xmm0, xmm0, xmm0
	vmovdqu	ymmword ptr [rsp + 48], ymm0
	vmovdqu	ymmword ptr [rsp + 32], ymm0
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp + 96], xmm0
	mov	dword ptr [rsp + 112], 0
	mov	dword ptr [rsp + 152], 0
	lea	r8, [rdx + 54]
	cmp	r8, rsi
	ja	.LBB0_5
# %bb.11:
	movzx	r9d, byte ptr [rdx + 20]
	mov	byte ptr [rsp + 68], r9b
	movzx	ecx, byte ptr [rdx + 14]
	shl	cl, 4
	mov	byte ptr [rsp + 77], cl
	movzx	r10d, byte ptr [rdx + 15]
	shr	r10b, 4
	or	r10b, cl
	mov	byte ptr [rsp + 77], r10b
	cmp	r9d, 44
	je	.LBB0_5
# %bb.12:
	movzx	ebp, word ptr [rdx + 18]
	cmp	r9d, 58
	jne	.LBB0_17
# %bb.13:
	lea	rcx, [rdx + 62]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.23:
	movzx	r9d, byte ptr [r8]
	cmp	r9d, 1
	je	.LBB0_53
# %bb.24:
	cmp	r9d, 2
	je	.LBB0_50
# %bb.25:
	mov	ecx, 2
	cmp	r9d, 128
	jne	.LBB0_346
.LBB0_26:
	mov	byte ptr [rdx + 54], -127
	dec	word ptr [rdx + 56]
	mov	byte ptr [rdx + 21], 64
	vmovups	xmm0, xmmword ptr [rdx + 22]
	vmovaps	xmmword ptr [rsp], xmm0
	vmovups	xmm0, xmmword ptr [rdx + 38]
	vmovups	xmmword ptr [rdx + 22], xmm0
	vmovdqa	xmm0, xmmword ptr [rsp]
	vmovdqu	xmmword ptr [rdx + 38], xmm0
	movzx	ecx, word ptr [rdx + 10]
	mov	word ptr [rsp + 24], cx
	mov	ecx, dword ptr [rdx + 6]
	mov	dword ptr [rsp + 20], ecx
	mov	ecx, dword ptr [rdx]
	mov	dword ptr [rdx + 6], ecx
	movzx	ecx, word ptr [rdx + 4]
	mov	word ptr [rdx + 10], cx
	mov	ecx, dword ptr [rsp + 20]
	mov	dword ptr [rdx], ecx
	movzx	ecx, word ptr [rsp + 24]
	jmp	.LBB0_44
.LBB0_17:
	vmovups	xmm0, xmmword ptr [rdx + 22]
	vmovaps	xmmword ptr [rsp + 32], xmm0
	vmovdqu	xmm0, xmmword ptr [rdx + 38]
	vmovdqa	xmmword ptr [rsp + 48], xmm0
	cmp	r9b, 1
	jne	.LBB0_27
# %bb.18:
	lea	rcx, [rdx + 62]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.35:
	movzx	r9d, byte ptr [r8]
	cmp	r9d, 3
	je	.LBB0_81
# %bb.36:
	mov	ecx, 2
	cmp	r9d, 8
	jne	.LBB0_346
# %bb.37:
	mov	byte ptr [rdx + 34], 0
	add	word ptr [rdx + 36], 8
	mov	byte ptr [rdx + 22], 64
	vmovsd	xmm0, qword ptr [rdx + 26]      # xmm0 = mem[0],zero
	vshufps	xmm0, xmm0, xmm0, 225           # xmm0 = xmm0[1,0,2,3]
	vmovlps	qword ptr [rdx + 26], xmm0
	vpmovzxwq	ymm0, qword ptr [rdx + 14] # ymm0 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	vpmovzxwq	ymm1, qword ptr [rdx + 26] # ymm1 = mem[0],zero,zero,zero,mem[1],zero,zero,zero,mem[2],zero,zero,zero,mem[3],zero,zero,zero
	movzx	ecx, word ptr [rdx + 22]
	vextracti128	xmm2, ymm0, 1
	vpaddq	xmm0, xmm0, xmm2
	vpshufd	xmm2, xmm0, 238                 # xmm2 = xmm0[2,3,2,3]
	vpaddq	xmm0, xmm0, xmm2
	vmovq	rsi, xmm0
	vextracti128	xmm0, ymm1, 1
	vpaddq	xmm0, xmm1, xmm0
	vpshufd	xmm1, xmm0, 238                 # xmm1 = xmm0[2,3,2,3]
	vpaddq	xmm0, xmm0, xmm1
	vmovq	rdi, xmm0
	add	rdi, rsi
	add	rdi, rcx
	mov	rcx, rdi
	shr	rcx, 16
	movzx	esi, di
	add	rsi, rcx
	cmp	rdi, 65536
	cmovb	rsi, rdi
.LBB0_43:
	mov	rcx, rsi
	shr	rcx, 16
	movzx	edi, si
	add	rdi, rcx
	cmp	rsi, 65536
	cmovb	rdi, rsi
	mov	rcx, rdi
	shr	rcx, 16
	movzx	esi, di
	add	ecx, esi
	cmp	rdi, 65536
	cmovb	ecx, edi
	mov	esi, ecx
	shr	esi, 16
	add	esi, ecx
	not	esi
	mov	word ptr [rdx + 24], si
	movzx	ecx, word ptr [rdx + 10]
	mov	word ptr [rsp + 4], cx
	mov	ecx, dword ptr [rdx + 6]
	mov	dword ptr [rsp], ecx
	mov	ecx, dword ptr [rdx]
	mov	dword ptr [rdx + 6], ecx
	movzx	ecx, word ptr [rdx + 4]
	mov	word ptr [rdx + 10], cx
	mov	ecx, dword ptr [rsp]
	mov	dword ptr [rdx], ecx
	movzx	ecx, word ptr [rsp + 4]
.LBB0_44:
	mov	word ptr [rdx + 4], cx
	mov	ecx, 3
	cmp	ecx, 1
	jne	.LBB0_347
	jmp	.LBB0_350
.LBB0_27:
	xor	r10d, r10d
.LBB0_28:
	mov	ecx, 2
	cmp	r9b, 17
	je	.LBB0_38
# %bb.29:
	movzx	r11d, r9b
	cmp	r11d, 6
	jne	.LBB0_346
# %bb.30:
	lea	r11, [rdx + 102]
	test	r10b, 1
	cmove	r11, r8
	lea	rbx, [r11 + 20]
	cmp	rbx, rsi
	ja	.LBB0_5
# %bb.55:
	movzx	r14d, word ptr [r11 + 12]
	mov	ebx, r10d
	test	r14d, 512
	je	.LBB0_57
# %bb.56:
	mov	ebx, r10d
	or	bl, 2
	mov	byte ptr [rsp + 76], bl
	movzx	r14d, word ptr [r11 + 12]
.LBB0_57:
	test	r14d, 1024
	je	.LBB0_59
# %bb.58:
	or	bl, 4
	mov	byte ptr [rsp + 76], bl
	jmp	.LBB0_59
.LBB0_32:
	mov	ecx, dword ptr [rdx + 26]
	mov	dword ptr [rsp + 32], ecx
	mov	ecx, dword ptr [rdx + 30]
	mov	dword ptr [rsp + 48], ecx
	cmp	r9b, 58
	jne	.LBB0_45
# %bb.33:
	lea	rcx, [rdx + 42]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.90:
	movzx	r9d, byte ptr [r8]
	cmp	r9d, 1
	je	.LBB0_138
# %bb.91:
	cmp	r9d, 2
	je	.LBB0_135
# %bb.92:
	mov	ecx, 2
	cmp	r9d, 128
	jne	.LBB0_346
# %bb.93:
	lea	rdi, [rdx + 62]
	mov	ecx, 1
	cmp	rdi, rsi
	jbe	.LBB0_26
	jmp	.LBB0_346
.LBB0_38:
	lea	r11, [rdx + 102]
	test	r10b, 1
	cmove	r11, r8
	lea	rbx, [r11 + 8]
	cmp	rbx, rsi
	ja	.LBB0_5
.LBB0_59:
	test	r10b, 1
	jne	.LBB0_61
# %bb.60:
	movzx	r10d, word ptr [r11]
	mov	word ptr [rsp + 64], r10w
	movzx	r10d, word ptr [r11 + 2]
	jmp	.LBB0_62
.LBB0_45:
	xor	r10d, r10d
.LBB0_46:
	mov	ecx, 2
	cmp	r9b, 17
	je	.LBB0_94
# %bb.47:
	movzx	r11d, r9b
	cmp	r11d, 6
	jne	.LBB0_346
# %bb.48:
	lea	r11, [rdx + 62]
	test	r10b, 1
	cmove	r11, r8
	lea	rbx, [r11 + 20]
	cmp	rbx, rsi
	ja	.LBB0_5
# %bb.105:
	movzx	r14d, word ptr [r11 + 12]
	mov	ebx, r10d
	test	r14d, 512
	je	.LBB0_107
# %bb.106:
	mov	ebx, r10d
	or	bl, 2
	mov	byte ptr [rsp + 76], bl
	movzx	r14d, word ptr [r11 + 12]
.LBB0_107:
	test	r14d, 1024
	je	.LBB0_109
# %bb.108:
	or	bl, 4
	mov	byte ptr [rsp + 76], bl
	jmp	.LBB0_109
.LBB0_50:
	mov	dword ptr [rsp], 524
	lea	rcx, [rip + stats]
	mov	r9, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.51:
	inc	qword ptr [rcx]
	mov	r9d, dword ptr [rdx + 58]
	bswap	r9d
	cmp	r9d, 1279
	ja	.LBB0_53
# %bb.52:
	inc	qword ptr [rcx + 8]
.LBB0_53:
	lea	rcx, [rdx + 102]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.80:
	movzx	r9d, byte ptr [rdx + 68]
	mov	byte ptr [rsp + 68], r9b
	movzx	r10d, byte ptr [rsp + 76]
	or	r10b, 1
	mov	byte ptr [rsp + 76], r10b
	vmovups	xmm0, xmmword ptr [rdx + 86]
	vmovaps	xmmword ptr [rsp + 32], xmm0
	vmovdqu	xmm0, xmmword ptr [rdx + 70]
	vmovdqa	xmmword ptr [rsp + 48], xmm0
	jmp	.LBB0_28
.LBB0_61:
	movzx	r10d, word ptr [r11 + 2]
	mov	word ptr [rsp + 64], r10w
	movzx	r10d, word ptr [r11]
.LBB0_62:
	mov	word ptr [rsp + 66], r10w
	vmovdqa	xmm0, xmmword ptr [rsp + 48]
	vmovdqa	xmmword ptr [rsp + 96], xmm0
	mov	word ptr [rsp + 112], r10w
	mov	byte ptr [rsp + 114], r9b
	lea	r12, [rip + vip_map]
	lea	r9, [rsp + 96]
	#APP
	#NO_APP
	test	r12, r12
	je	.LBB0_87
.LBB0_63:
	mov	r9, rsi
	sub	r9, rdx
	mov	ecx, 1
	cmp	r9, 1514
	jg	.LBB0_346
# %bb.64:
	mov	dword ptr [rsp + 148], 512
	lea	r14, [rip + stats]
	lea	rcx, [rsp + 148]
	#APP
	#NO_APP
	test	r14, r14
	je	.LBB0_5
# %bb.65:
	inc	qword ptr [r14]
	test	byte ptr [r12], 1
	je	.LBB0_67
# %bb.66:
	mov	word ptr [rsp + 64], 0
.LBB0_67:
	mov	r9d, dword ptr [r12 + 4]
	mov	dword ptr [rsp + 156], r9d
	#APP
	#NO_APP
	and	ecx, 127
	mov	dword ptr [rsp + 144], ecx
	lea	r15, [rip + lru_mapping]
	lea	rcx, [rsp + 144]
	#APP
	#NO_APP
	test	r15, r15
	jne	.LBB0_70
# %bb.68:
	mov	dword ptr [rsp], 515
	lea	rcx, [rip + stats]
	mov	r10, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.69:
	inc	qword ptr [rcx]
	lea	r15, [rip + fallback_cache]
.LBB0_70:
	test	byte ptr [r12], 4
	je	.LBB0_172
# %bb.71:
	test	byte ptr [rsp + 76], 1
	jne	.LBB0_143
# %bb.72:
	mov	dword ptr [rsp + 20], 0
	lea	rcx, [rip + quic_stats_map]
	lea	r10, [rsp + 20]
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.73:
	add	rdx, 102
	test	byte ptr [rsp + 76], 1
	cmove	rdx, r8
	lea	r8, [rdx + 9]
	cmp	r8, rsi
	ja	.LBB0_171
# %bb.74:
	movzx	r10d, byte ptr [rdx + 8]
	test	r10b, r10b
	js	.LBB0_153
# %bb.75:
	add	rdx, 17
	cmp	rdx, rsi
	ja	.LBB0_171
.LBB0_76:
	vmovdqa	xmm4, xmm2
	vmovdqa	xmm1, xmm3
	mov	rsi, rdi
	movzx	r10d, byte ptr [r8]
	mov	edx, r10d
	shr	edx, 6
	cmp	edx, 3
	je	.LBB0_165
# %bb.77:
	cmp	edx, 2
	je	.LBB0_164
# %bb.78:
	cmp	edx, 1
	mov	eax, 1
	mov	rdi, rsi
	vmovdqa	xmm3, xmm1
	vmovdqa	xmm2, xmm4
	jne	.LBB0_171
# %bb.79:
	and	r10d, 63
	shl	r10d, 10
	movzx	eax, byte ptr [r8 + 1]
	lea	eax, [r10 + 4*rax]
	movzx	edi, byte ptr [r8 + 2]
	shr	dil, 6
	jmp	.LBB0_166
.LBB0_81:
	cmp	byte ptr [rdx + 55], 4
	jne	.LBB0_85
# %bb.82:
	mov	dword ptr [rsp], 525
	lea	r9, [rip + stats]
	mov	r10, rsp
	#APP
	#NO_APP
	test	r9, r9
	je	.LBB0_5
# %bb.83:
	inc	qword ptr [r9]
	cmp	byte ptr [rdx + 60], 4
	ja	.LBB0_85
# %bb.84:
	inc	qword ptr [r9 + 8]
.LBB0_85:
	lea	r9, [rdx + 82]
	cmp	r9, rsi
	ja	.LBB0_5
# %bb.102:
	movzx	ecx, byte ptr [rcx]
	and	cl, 15
	cmp	cl, 5
	jne	.LBB0_5
# %bb.103:
	movzx	r9d, byte ptr [rdx + 71]
	mov	byte ptr [rsp + 68], r9b
	movzx	r10d, byte ptr [rsp + 76]
	or	r10b, 1
	mov	byte ptr [rsp + 76], r10b
	mov	ecx, dword ptr [rdx + 78]
	mov	dword ptr [rsp + 32], ecx
	mov	ecx, dword ptr [rdx + 74]
	mov	dword ptr [rsp + 48], ecx
	jmp	.LBB0_28
.LBB0_87:
	mov	word ptr [rsp + 112], 0
	lea	r12, [rip + vip_map]
	#APP
	#NO_APP
	test	r12, r12
	je	.LBB0_346
# %bb.88:
	test	byte ptr [r12], -120
	jne	.LBB0_63
# %bb.89:
	mov	word ptr [rsp + 66], 0
	jmp	.LBB0_63
.LBB0_94:
	lea	r11, [rdx + 62]
	test	r10b, 1
	cmove	r11, r8
	lea	rbx, [r11 + 8]
	cmp	rbx, rsi
	ja	.LBB0_5
.LBB0_109:
	test	r10b, 1
	jne	.LBB0_111
# %bb.110:
	movzx	r10d, word ptr [r11]
	mov	word ptr [rsp + 64], r10w
	movzx	r10d, word ptr [r11 + 2]
	jmp	.LBB0_112
.LBB0_96:
	cmp	byte ptr [rdx + 35], 4
	jne	.LBB0_100
# %bb.97:
	mov	dword ptr [rsp], 525
	lea	r9, [rip + stats]
	mov	r10, rsp
	#APP
	#NO_APP
	test	r9, r9
	je	.LBB0_5
# %bb.98:
	inc	qword ptr [r9]
	cmp	byte ptr [rdx + 40], 4
	ja	.LBB0_100
# %bb.99:
	inc	qword ptr [r9 + 8]
.LBB0_100:
	lea	r9, [rdx + 62]
	cmp	r9, rsi
	ja	.LBB0_5
# %bb.133:
	movzx	ecx, byte ptr [rcx]
	and	cl, 15
	cmp	cl, 5
	jne	.LBB0_5
# %bb.134:
	movzx	r9d, byte ptr [rdx + 51]
	mov	byte ptr [rsp + 68], r9b
	movzx	r10d, byte ptr [rsp + 76]
	or	r10b, 1
	mov	byte ptr [rsp + 76], r10b
	mov	ecx, dword ptr [rdx + 58]
	mov	dword ptr [rsp + 32], ecx
	mov	ecx, dword ptr [rdx + 54]
	mov	dword ptr [rsp + 48], ecx
	jmp	.LBB0_46
.LBB0_111:
	movzx	r10d, word ptr [r11 + 2]
	mov	word ptr [rsp + 64], r10w
	movzx	r10d, word ptr [r11]
.LBB0_112:
	mov	word ptr [rsp + 66], r10w
	mov	r11d, dword ptr [rsp + 48]
	mov	dword ptr [rsp + 96], r11d
	mov	word ptr [rsp + 112], r10w
	mov	byte ptr [rsp + 114], r9b
	lea	r13, [rip + vip_map]
	lea	r9, [rsp + 96]
	#APP
	#NO_APP
	test	r13, r13
	je	.LBB0_130
.LBB0_113:
	mov	r9, rsi
	sub	r9, rdx
	mov	ecx, 1
	cmp	r9, 1514
	jg	.LBB0_346
# %bb.114:
	mov	dword ptr [rsp + 148], 512
	lea	r15, [rip + stats]
	lea	rcx, [rsp + 148]
	#APP
	#NO_APP
	test	r15, r15
	je	.LBB0_5
# %bb.115:
	inc	qword ptr [r15]
	test	byte ptr [r13], 1
	je	.LBB0_117
# %bb.116:
	mov	word ptr [rsp + 64], 0
.LBB0_117:
	mov	r9d, dword ptr [r13 + 4]
	mov	dword ptr [rsp + 156], r9d
	#APP
	#NO_APP
	and	ecx, 127
	mov	dword ptr [rsp + 144], ecx
	lea	r12, [rip + lru_mapping]
	lea	rcx, [rsp + 144]
	#APP
	#NO_APP
	test	r12, r12
	jne	.LBB0_120
# %bb.118:
	mov	dword ptr [rsp], 515
	lea	rcx, [rip + stats]
	mov	r10, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.119:
	inc	qword ptr [rcx]
	lea	r12, [rip + fallback_cache]
.LBB0_120:
	test	byte ptr [r13], 4
	mov	qword ptr [rsp + 160], rdi      # 8-byte Spill
	vmovdqa	xmmword ptr [rsp + 128], xmm3   # 16-byte Spill
	je	.LBB0_281
# %bb.121:
	test	byte ptr [rsp + 76], 1
	jne	.LBB0_149
# %bb.122:
	mov	dword ptr [rsp + 20], 0
	lea	rcx, [rip + quic_stats_map]
	lea	rax, [rsp + 20]
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_344
# %bb.123:
	add	rdx, 62
	test	byte ptr [rsp + 76], 1
	cmove	rdx, r8
	lea	rdi, [rdx + 9]
	cmp	rdi, rsi
	ja	.LBB0_280
# %bb.124:
	movzx	eax, byte ptr [rdx + 8]
	test	al, al
	js	.LBB0_158
# %bb.125:
	add	rdx, 17
	cmp	rdx, rsi
	ja	.LBB0_280
.LBB0_126:
	movzx	edx, byte ptr [rdi]
	mov	eax, edx
	shr	eax, 6
	cmp	eax, 3
	je	.LBB0_259
# %bb.127:
	cmp	eax, 2
	je	.LBB0_258
# %bb.128:
	cmp	eax, 1
	jne	.LBB0_280
# %bb.129:
	and	edx, 63
	shl	edx, 10
	movzx	esi, byte ptr [rdi + 1]
	lea	esi, [rdx + 4*rsi]
	movzx	edx, byte ptr [rdi + 2]
	shr	dl, 6
	jmp	.LBB0_260
.LBB0_130:
	mov	word ptr [rsp + 112], 0
	lea	r13, [rip + vip_map]
	#APP
	#NO_APP
	test	r13, r13
	je	.LBB0_346
# %bb.131:
	test	byte ptr [r13], -120
	jne	.LBB0_113
# %bb.132:
	mov	word ptr [rsp + 66], 0
	jmp	.LBB0_113
.LBB0_135:
	mov	dword ptr [rsp], 524
	lea	rcx, [rip + stats]
	mov	r9, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.136:
	inc	qword ptr [rcx]
	mov	r9d, dword ptr [rdx + 38]
	bswap	r9d
	cmp	r9d, 1279
	ja	.LBB0_138
# %bb.137:
	inc	qword ptr [rcx + 8]
.LBB0_138:
	lea	rcx, [rdx + 82]
	cmp	rcx, rsi
	ja	.LBB0_5
# %bb.142:
	lea	rcx, [rsp + 48]
	movzx	r9d, byte ptr [rdx + 48]
	mov	byte ptr [rsp + 68], r9b
	movzx	r10d, byte ptr [rsp + 76]
	or	r10b, 1
	mov	byte ptr [rsp + 76], r10b
	vmovups	xmm0, xmmword ptr [rdx + 66]
	vmovaps	xmmword ptr [rsp + 32], xmm0
	vmovdqu	xmm0, xmmword ptr [rdx + 50]
	vmovdqu	xmmword ptr [rcx], xmm0
	jmp	.LBB0_46
.LBB0_143:
	mov	dword ptr [rsp], 523
	lea	rcx, [rip + stats]
	mov	rsi, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.144:
	inc	qword ptr [rcx]
	movzx	edx, byte ptr [rdx + 55]
	add	dl, -3
	cmp	dl, 1
	ja	.LBB0_172
# %bb.145:
	inc	qword ptr [rcx + 8]
	movzx	r10d, word ptr [rsp + 64]
	test	byte ptr [rsp + 76], 2
	je	.LBB0_173
	jmp	.LBB0_192
.LBB0_149:
	mov	dword ptr [rsp], 523
	lea	rax, [rip + stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.150:
	inc	qword ptr [rax]
	movzx	ecx, byte ptr [rdx + 35]
	or	ecx, 2
	cmp	ecx, 3
	jne	.LBB0_281
# %bb.151:
	inc	qword ptr [rax + 8]
	jmp	.LBB0_281
.LBB0_153:
	lea	r8, [rdx + 22]
	cmp	r8, rsi
	ja	.LBB0_171
# %bb.154:
	test	r10b, 32
	jne	.LBB0_162
# %bb.155:
	inc	qword ptr [rcx + 8]
	mov	dword ptr [rsp], r9d
	lea	rax, [rip + server_id_stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_157
# %bb.156:
	inc	qword ptr [rax]
.LBB0_157:
	mov	eax, 1
	movzx	r10d, word ptr [rsp + 64]
	test	byte ptr [rsp + 76], 2
	je	.LBB0_173
	jmp	.LBB0_192
.LBB0_158:
	lea	rdi, [rdx + 22]
	cmp	rdi, rsi
	ja	.LBB0_280
# %bb.159:
	test	al, 32
	jne	.LBB0_254
# %bb.160:
	inc	qword ptr [rcx + 8]
	mov	dword ptr [rsp], r9d
	lea	rax, [rip + server_id_stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_281
# %bb.161:
	inc	qword ptr [rax]
	jmp	.LBB0_281
.LBB0_162:
	cmp	byte ptr [rdx + 13], 7
	mov	eax, 1
	jbe	.LBB0_171
# %bb.163:
	add	rdx, 14
	mov	r8, rdx
	jmp	.LBB0_76
.LBB0_164:
	movzx	edi, byte ptr [r8 + 1]
	shl	edi, 16
	movzx	eax, byte ptr [r8 + 2]
	shl	eax, 8
	or	eax, edi
	movzx	edi, byte ptr [r8 + 3]
	jmp	.LBB0_166
.LBB0_165:
	movzx	eax, byte ptr [r8 + 1]
	shl	eax, 24
	movzx	edi, byte ptr [r8 + 2]
	shl	edi, 16
	or	edi, eax
	movzx	eax, byte ptr [r8 + 3]
	shl	eax, 8
	or	eax, edi
	movzx	edi, byte ptr [r8 + 4]
.LBB0_166:
	movzx	r8d, dil
	or	r8, rax
	test	r8d, r8d
	mov	eax, 1
	mov	rdi, rsi
	vmovdqa	xmm3, xmm1
	vmovdqa	xmm2, xmm4
	jle	.LBB0_171
# %bb.167:
	mov	rax, rcx
	cmp	rdx, 3
	je	.LBB0_183
# %bb.168:
	cmp	edx, 2
	je	.LBB0_182
# %bb.169:
	cmp	edx, 1
	jne	.LBB0_184
# %bb.170:
	add	rax, 56
	jmp	.LBB0_185
.LBB0_171:
	inc	qword ptr [rcx]
.LBB0_172:
	movzx	r10d, word ptr [rsp + 64]
	test	byte ptr [rsp + 76], 2
	jne	.LBB0_192
.LBB0_173:
	test	byte ptr [r12], 2
	jne	.LBB0_192
# %bb.174:
	lea	rdx, [rsp + 32]
	mov	rcx, r15
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_192
# %bb.175:
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_181
# %bb.176:
	#APP

	rdtsc

	#NO_APP
	mov	rdx, rax
	sub	rdx, qword ptr [rcx + 8]
	movabs	rsi, 30000000000
	cmp	rdx, rsi
	jbe	.LBB0_180
# %bb.177:
	xor	edx, edx
	mov	eax, 1
	jmp	.LBB0_193
.LBB0_180:
	mov	qword ptr [rcx + 8], rax
	mov	eax, 1
.LBB0_181:
	mov	ecx, dword ptr [rcx]
	mov	dword ptr [rsp], ecx
	mov	dword ptr [rsp + 72], ecx
	lea	rdx, [rip + reals]
	mov	rcx, rsp
	#APP
	#NO_APP
	jmp	.LBB0_193
.LBB0_182:
	add	rax, 64
	jmp	.LBB0_185
.LBB0_183:
	add	rax, 72
	jmp	.LBB0_185
.LBB0_184:
	add	rax, 48
.LBB0_185:
	inc	qword ptr [rax]
	mov	dword ptr [rsp + 28], r8d
	lea	rax, [rip + server_id_map]
	lea	rdx, [rsp + 28]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_191
# %bb.186:
	mov	eax, dword ptr [rax]
	mov	dword ptr [rsp + 28], eax
	test	eax, eax
	je	.LBB0_191
# %bb.187:
	mov	dword ptr [rsp + 72], eax
	lea	rdx, [rip + reals]
	lea	rax, [rsp + 28]
	#APP
	#NO_APP
	test	rdx, rdx
	je	.LBB0_256
# %bb.188:
	lea	rdi, [rsp + 32]
	mov	rax, r15
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_265
# %bb.189:
	mov	edi, dword ptr [rsp + 72]
	cmp	dword ptr [rax], edi
	jne	.LBB0_268
# %bb.190:
	inc	qword ptr [rcx + 80]
	jmp	.LBB0_364
.LBB0_191:
	inc	qword ptr [rcx + 16]
	mov	qword ptr [rcx + 24], r8
	inc	qword ptr [rcx]
	mov	eax, 1
	mov	rdi, rsi
	vmovdqa	xmm3, xmm1
	vmovdqa	xmm2, xmm4
	movzx	r10d, word ptr [rsp + 64]
	test	byte ptr [rsp + 76], 2
	je	.LBB0_173
.LBB0_192:
	xor	edx, edx
.LBB0_193:
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_204
# %bb.194:
	test	byte ptr [r12 + 1], 2
	je	.LBB0_204
# %bb.195:
	mov	dword ptr [rsp], 514
	lea	rcx, [rip + stats]
	mov	rsi, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_204
# %bb.196:
	#APP

	rdtsc

	#NO_APP
	mov	rsi, rax
	sub	rsi, qword ptr [rcx + 8]
	cmp	rsi, 1000000001
	jb	.LBB0_198
# %bb.197:
	mov	qword ptr [rcx], 1
	mov	qword ptr [rcx + 8], rax
	mov	eax, 1
	jmp	.LBB0_199
.LBB0_198:
	mov	rax, qword ptr [rcx]
	inc	rax
	mov	qword ptr [rcx], rax
	cmp	rax, 125001
	mov	eax, 1
	jae	.LBB0_204
.LBB0_199:
	lea	rcx, [rip + vip_to_down_reals_map]
	lea	rsi, [rsp + 96]
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_204
# %bb.200:
	lea	rsi, [rsp + 72]
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_204
# %bb.201:
	mov	dword ptr [rsp], 527
	lea	rax, [rip + stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_203
# %bb.202:
	inc	qword ptr [rax]
.LBB0_203:
	mov	eax, 1
	jmp	.LBB0_212
.LBB0_204:
	test	rdx, rdx
	je	.LBB0_212
.LBB0_205:
	lea	rsi, [rip + ctl_array]
	lea	rcx, [rsp + 152]
	#APP
	#NO_APP
	mov	ecx, 1
	test	rsi, rsi
	je	.LBB0_346
# %bb.206:
	lea	r8, [rip + stats]
	lea	r9, [rsp + 156]
	#APP
	#NO_APP
	test	r8, r8
	je	.LBB0_346
# %bb.207:
	rol	bp, 8
	movzx	r9d, bp
	vpinsrq	xmm0, xmm2, r9, 1
	vpaddq	xmm1, xmm0, xmmword ptr [r8]
	vmovdqu	xmmword ptr [r8], xmm1
	lea	r9, [rsp + 72]
	lea	r8, [rip + reals_stats]
	#APP
	#NO_APP
	test	r8, r8
	je	.LBB0_346
# %bb.208:
	vpaddq	xmm0, xmm0, xmmword ptr [r8]
	vmovdqu	xmmword ptr [r8], xmm0
	mov	word ptr [rsp + 64], r10w
	test	byte ptr [rdx + 16], 1
	jne	.LBB0_242
# %bb.209:
	mov	r8d, dword ptr [rsp + 32]
	mov	eax, -20
	#APP
	#NO_APP
	mov	eax, dword ptr [rdi]
	mov	edi, dword ptr [rdi + 4]
	lea	r9, [rax + 14]
	cmp	r9, rdi
	ja	.LBB0_249
# %bb.210:
	lea	r9, [rax + 34]
	cmp	r9, rdi
	ja	.LBB0_249
# %bb.211:
	mov	r11d, r10d
	rol	r11w, 8
	shl	r11d, 16
	and	r8d, -65536
	xor	r8d, r11d
	lea	ecx, [r8 + 4268]
	movzx	edi, word ptr [rsi + 4]
	mov	word ptr [rax + 4], di
	mov	esi, dword ptr [rsi]
	mov	dword ptr [rax], esi
	mov	esi, dword ptr [rax + 20]
	mov	dword ptr [rax + 6], esi
	movzx	esi, word ptr [rax + 24]
	mov	word ptr [rax + 10], si
	mov	word ptr [rax + 12], 8
	movzx	esi, byte ptr [rsp + 77]
	mov	edx, dword ptr [rdx]
	mov	byte ptr [rax + 14], 69
	add	ebp, 20
	rol	bp, 8
	mov	byte ptr [rax + 15], sil
	mov	word ptr [rax + 16], bp
	mov	dword ptr [rax + 18], 0
	mov	dword ptr [rax + 30], edx
	mov	dword ptr [rax + 26], ecx
	mov	word ptr [rax + 22], 1088
	movzx	ecx, word ptr [rax + 14]
	movzx	esi, bp
	movzx	edi, word ptr [rax + 22]
	add	rdi, rcx
	shr	r8d, 16
	add	r8, rdi
	movzx	ecx, dx
	add	rcx, r8
	add	rcx, rsi
	movzx	edx, word ptr [rax + 32]
	add	rcx, rdx
	add	rcx, 4268
	mov	rdx, rcx
	shr	rdx, 16
	movzx	esi, cx
	add	rsi, rdx
	cmp	rcx, 65536
	cmovb	rsi, rcx
	mov	rcx, rsi
	shr	rcx, 16
	movzx	edx, si
	add	rdx, rcx
	cmp	rsi, 65536
	cmovb	rdx, rsi
	mov	rcx, rdx
	shr	rcx, 16
	movzx	esi, dx
	add	ecx, esi
	cmp	rdx, 65536
	cmovb	ecx, edx
	mov	edx, ecx
	shr	edx, 16
	add	edx, ecx
	not	edx
	mov	word ptr [rax + 24], dx
	mov	ecx, 3
	jmp	.LBB0_253
.LBB0_212:
	cmp	byte ptr [rsp + 68], 6
	jne	.LBB0_215
# %bb.213:
	mov	dword ptr [rsp], 513
	lea	rcx, [rip + stats]
	mov	rdx, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_5
# %bb.214:
	xor	eax, eax
	test	byte ptr [rsp + 76], 2
	sete	al
	inc	qword ptr [rcx + 8*rax]
.LBB0_215:
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp], xmm0
	mov	dword ptr [rsp + 20], 514
	lea	rcx, [rip + stats]
	lea	rax, [rsp + 20]
	#APP
	#NO_APP
	mov	r13b, 1
	test	rcx, rcx
	je	.LBB0_218
# %bb.216:
	#APP

	rdtsc

	#NO_APP
	mov	rbx, rax
	sub	rax, qword ptr [rcx + 8]
	cmp	rax, 1000000001
	jb	.LBB0_219
# %bb.217:
	mov	qword ptr [rcx], 1
	mov	qword ptr [rcx + 8], rbx
	jmp	.LBB0_220
.LBB0_218:
	xor	ebx, ebx
	jmp	.LBB0_221
.LBB0_219:
	mov	rax, qword ptr [rcx]
	inc	rax
	mov	qword ptr [rcx], rax
	cmp	rax, 125000
	ja	.LBB0_221
.LBB0_220:
	xor	r13d, r13d
.LBB0_221:
	mov	dword ptr [rsp + 88], r10d      # 4-byte Spill
	vmovdqa	xmmword ptr [rsp + 128], xmm3   # 16-byte Spill
	mov	qword ptr [rsp + 160], rdi      # 8-byte Spill
	test	byte ptr [r12], 8
	je	.LBB0_223
# %bb.222:
	movzx	eax, word ptr [rsp + 66]
	mov	word ptr [rsp + 64], ax
	vmovdqa	xmmword ptr [rsp + 32], xmm0
.LBB0_223:
	lea	rdi, [rsp + 32]
	vzeroupper
	call	jhash
	mov	esi, dword ptr [rsp + 64]
	mov	edi, eax
	call	jhash_2words
	mov	ecx, eax
	mov	edx, 4294901761
	imul	rdx, rcx
	shr	rdx, 48
	mov	ecx, edx
	shl	ecx, 16
	or	ecx, edx
	sub	eax, ecx
	mov	ecx, dword ptr [r12 + 4]
	mov	edx, ecx
	shl	edx, 16
	add	edx, ecx
	add	edx, eax
	mov	dword ptr [rsp + 28], edx
	lea	rax, [rip + ch_rings]
	lea	rcx, [rsp + 28]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.224:
	mov	eax, dword ptr [rax]
	mov	dword ptr [rsp + 28], eax
	test	eax, eax
	je	.LBB0_245
# %bb.225:
	mov	dword ptr [rsp + 72], eax
	lea	rdx, [rip + reals]
	lea	rax, [rsp + 28]
	#APP
	#NO_APP
	test	rdx, rdx
	je	.LBB0_247
# %bb.226:
	movzx	eax, byte ptr [r12]
	and	al, 2
	shr	al
	or	r13b, al
	jne	.LBB0_231
# %bb.227:
	test	byte ptr [rsp + 76], 4
	jne	.LBB0_231
# %bb.228:
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_230
# %bb.229:
	mov	qword ptr [rsp + 8], rbx
.LBB0_230:
	mov	eax, dword ptr [rsp + 28]
	mov	dword ptr [rsp], eax
	xor	eax, eax
	lea	rcx, [rsp + 32]
	mov	rsi, rsp
	#APP
	#NO_APP
.LBB0_231:
	mov	dword ptr [rsp], 0
	lea	rax, [rip + vip_miss_stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.232:
	mov	esi, dword ptr [rax]
	mov	cl, 1
	cmp	esi, dword ptr [rsp + 96]
	jne	.LBB0_236
# %bb.233:
	mov	esi, dword ptr [rax + 4]
	cmp	esi, dword ptr [rsp + 100]
	jne	.LBB0_236
# %bb.234:
	mov	esi, dword ptr [rax + 8]
	cmp	esi, dword ptr [rsp + 104]
	jne	.LBB0_236
# %bb.235:
	mov	ecx, dword ptr [rax + 12]
	cmp	ecx, dword ptr [rsp + 108]
	setne	cl
.LBB0_236:
	movzx	edi, word ptr [rax + 16]
	movzx	r8d, word ptr [rsp + 112]
	movzx	esi, byte ptr [rsp + 114]
	mov	byte ptr [rax + 18], sil
	test	cl, cl
	jne	.LBB0_241
# %bb.237:
	cmp	di, r8w
	jne	.LBB0_241
# %bb.238:
	test	sil, sil
	je	.LBB0_241
# %bb.239:
	mov	eax, dword ptr [rsp + 72]
	mov	dword ptr [rsp + 20], eax
	lea	rax, [rip + lru_miss_stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.240:
	inc	dword ptr [rax]
.LBB0_241:
	inc	qword ptr [r14 + 8]
	mov	eax, 1
	mov	rdi, qword ptr [rsp + 160]      # 8-byte Reload
	vmovdqa	xmm3, xmmword ptr [rsp + 128]   # 16-byte Reload
	vpbroadcastq	xmm2, qword ptr [rip + .LCPI0_1] # xmm2 = [1,1]
	mov	r10d, dword ptr [rsp + 88]      # 4-byte Reload
	jmp	.LBB0_205
.LBB0_242:
	mov	eax, -40
	#APP
	#NO_APP
	mov	eax, dword ptr [rdi]
	mov	edi, dword ptr [rdi + 4]
	lea	r8, [rax + 14]
	cmp	r8, rdi
	ja	.LBB0_251
# %bb.243:
	lea	r8, [rax + 54]
	cmp	r8, rdi
	ja	.LBB0_251
# %bb.244:
	movzx	ecx, word ptr [rsi + 4]
	mov	word ptr [rax + 4], cx
	mov	ecx, dword ptr [rsi]
	mov	dword ptr [rax], ecx
	mov	ecx, dword ptr [rax + 40]
	mov	dword ptr [rax + 6], ecx
	movzx	ecx, word ptr [rax + 44]
	mov	word ptr [rax + 10], cx
	mov	word ptr [rax + 12], -8826
	movzx	ecx, word ptr [rsp + 64]
	xor	ecx, dword ptr [rsp + 44]
	add	ebp, 40
	movzx	esi, byte ptr [rsp + 77]
	mov	word ptr [rax + 16], 0
	mov	edi, esi
	shr	dil, 4
	or	dil, 96
	mov	byte ptr [rax + 14], dil
	shl	sil, 4
	mov	byte ptr [rax + 15], sil
	rol	bp, 8
	mov	word ptr [rax + 20], 16425
	mov	word ptr [rax + 18], bp
	mov	qword ptr [rax + 22], 1
	mov	dword ptr [rax + 30], 0
	mov	dword ptr [rax + 34], ecx
	vmovdqu	xmm0, xmmword ptr [rdx]
	vmovdqu	xmmword ptr [rax + 38], xmm0
	mov	ecx, 3
	jmp	.LBB0_253
.LBB0_245:
	mov	dword ptr [rsp + 20], 521
	lea	rax, [rip + stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	jne	.LBB0_341
	jmp	.LBB0_344
.LBB0_247:
	mov	dword ptr [rsp + 20], 521
	lea	rax, [rip + stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	jne	.LBB0_343
	jmp	.LBB0_344
.LBB0_249:
	mov	dword ptr [rsp], 519
	lea	rax, [rip + stats]
	mov	rdx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_253
# %bb.250:
	inc	qword ptr [rax]
	jmp	.LBB0_253
.LBB0_251:
	mov	dword ptr [rsp], 519
	lea	rax, [rip + stats]
	mov	rdx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_253
# %bb.252:
	inc	qword ptr [rax + 8]
.LBB0_253:
	mov	eax, 1
	cmp	ecx, 1
	jne	.LBB0_347
	jmp	.LBB0_350
.LBB0_254:
	cmp	byte ptr [rdx + 13], 7
	jbe	.LBB0_280
# %bb.255:
	add	rdx, 14
	mov	rdi, rdx
	jmp	.LBB0_126
.LBB0_256:
	inc	qword ptr [rcx + 40]
	mov	eax, 1
	vmovdqa	xmm3, xmm1
.LBB0_5:
	mov	ecx, 1
.LBB0_346:
	cmp	ecx, 1
	je	.LBB0_350
.LBB0_347:
	cmp	ecx, 3
	jne	.LBB0_349
# %bb.348:
	mov	dword ptr [rsp + 92], 529
	mov	ecx, 3
	jmp	.LBB0_351
.LBB0_349:
	mov	dword ptr [rsp + 92], 531
	mov	ecx, 2
	jmp	.LBB0_351
.LBB0_258:
	movzx	edx, byte ptr [rdi + 1]
	shl	edx, 16
	movzx	esi, byte ptr [rdi + 2]
	shl	esi, 8
	or	esi, edx
	movzx	edx, byte ptr [rdi + 3]
	jmp	.LBB0_260
.LBB0_259:
	movzx	edx, byte ptr [rdi + 1]
	shl	edx, 24
	movzx	r8d, byte ptr [rdi + 2]
	shl	r8d, 16
	or	r8d, edx
	movzx	esi, byte ptr [rdi + 3]
	shl	esi, 8
	or	esi, r8d
	movzx	edx, byte ptr [rdi + 4]
.LBB0_260:
	movzx	edx, dl
	or	rdx, rsi
	test	edx, edx
	jle	.LBB0_280
# %bb.261:
	cmp	rax, 3
	je	.LBB0_271
# %bb.262:
	cmp	eax, 2
	je	.LBB0_270
# %bb.263:
	cmp	eax, 1
	jne	.LBB0_272
# %bb.264:
	mov	rax, rcx
	add	rax, 56
	jmp	.LBB0_273
.LBB0_265:
	mov	dword ptr [rsp], 514
	lea	rdi, [rip + stats]
	mov	rax, rsp
	#APP
	#NO_APP
	test	rdi, rdi
	je	.LBB0_363
# %bb.266:
	#APP

	rdtsc

	#NO_APP
	mov	r8, rax
	sub	r8, qword ptr [rdi + 8]
	cmp	r8, 1000000001
	jb	.LBB0_360
# %bb.267:
	mov	qword ptr [rdi], 1
	mov	qword ptr [rdi + 8], rax
	jmp	.LBB0_362
.LBB0_268:
	mov	dword ptr [rax], edi
	inc	qword ptr [rcx + 88]
	mov	dword ptr [rsp], r9d
	lea	rax, [rip + server_id_stats]
	mov	rdi, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_364
# %bb.269:
	inc	qword ptr [rax + 8]
	jmp	.LBB0_364
.LBB0_270:
	mov	rax, rcx
	add	rax, 64
	jmp	.LBB0_273
.LBB0_271:
	mov	rax, rcx
	add	rax, 72
	jmp	.LBB0_273
.LBB0_272:
	mov	rax, rcx
	add	rax, 48
.LBB0_273:
	inc	qword ptr [rax]
	mov	dword ptr [rsp + 28], edx
	lea	rax, [rip + server_id_map]
	lea	rsi, [rsp + 28]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_279
# %bb.274:
	mov	eax, dword ptr [rax]
	mov	dword ptr [rsp + 28], eax
	test	eax, eax
	je	.LBB0_279
# %bb.275:
	mov	dword ptr [rsp + 72], eax
	lea	rdx, [rip + reals]
	lea	rax, [rsp + 28]
	#APP
	#NO_APP
	test	rdx, rdx
	je	.LBB0_359
# %bb.276:
	lea	rsi, [rsp + 32]
	mov	rax, r12
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_365
# %bb.277:
	mov	esi, dword ptr [rsp + 72]
	cmp	dword ptr [rax], esi
	jne	.LBB0_368
# %bb.278:
	inc	qword ptr [rcx + 80]
	jmp	.LBB0_374
.LBB0_279:
	inc	qword ptr [rcx + 16]
	mov	qword ptr [rcx + 24], rdx
.LBB0_280:
	inc	qword ptr [rcx]
.LBB0_281:
	movzx	eax, word ptr [rsp + 64]
	mov	dword ptr [rsp + 88], eax       # 4-byte Spill
	test	byte ptr [rsp + 76], 2
	jne	.LBB0_287
# %bb.282:
	test	byte ptr [r13], 2
	jne	.LBB0_287
# %bb.283:
	lea	rax, [rsp + 32]
	mov	rcx, r12
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_287
# %bb.284:
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_291
# %bb.285:
	#APP

	rdtsc

	#NO_APP
	mov	rdx, rax
	sub	rdx, qword ptr [rcx + 8]
	movabs	rsi, 30000000000
	cmp	rdx, rsi
	jbe	.LBB0_290
.LBB0_287:
	xor	edx, edx
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_302
.LBB0_293:
	test	byte ptr [r13 + 1], 2
	je	.LBB0_302
# %bb.294:
	mov	dword ptr [rsp], 514
	lea	rcx, [rip + stats]
	mov	rax, rsp
	#APP
	#NO_APP
	test	rcx, rcx
	je	.LBB0_302
# %bb.295:
	#APP

	rdtsc

	#NO_APP
	mov	rsi, rax
	sub	rsi, qword ptr [rcx + 8]
	cmp	rsi, 1000000001
	jb	.LBB0_297
# %bb.296:
	mov	qword ptr [rcx], 1
	mov	qword ptr [rcx + 8], rax
	jmp	.LBB0_298
.LBB0_297:
	mov	rax, qword ptr [rcx]
	inc	rax
	mov	qword ptr [rcx], rax
	cmp	rax, 125001
	jae	.LBB0_302
.LBB0_298:
	lea	rax, [rip + vip_to_down_reals_map]
	lea	rcx, [rsp + 96]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_302
# %bb.299:
	lea	rcx, [rsp + 72]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_302
# %bb.300:
	mov	dword ptr [rsp], 527
	lea	rax, [rip + stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_310
# %bb.301:
	inc	qword ptr [rax]
	jmp	.LBB0_310
.LBB0_290:
	mov	qword ptr [rcx + 8], rax
.LBB0_291:
	mov	eax, dword ptr [rcx]
	mov	dword ptr [rsp], eax
	mov	dword ptr [rsp + 72], eax
	lea	rdx, [rip + reals]
	mov	rax, rsp
	#APP
	#NO_APP
	cmp	byte ptr [rsp + 68], 17
	je	.LBB0_293
.LBB0_302:
	test	rdx, rdx
	je	.LBB0_310
.LBB0_303:
	lea	rsi, [rip + ctl_array]
	lea	rax, [rsp + 152]
	#APP
	#NO_APP
	mov	ecx, 1
	test	rsi, rsi
	je	.LBB0_345
# %bb.304:
	lea	rax, [rip + stats]
	lea	rdi, [rsp + 156]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_345
# %bb.305:
	mov	edi, ebp
	rol	di, 8
	movzx	r8d, di
	vpbroadcastq	xmm0, qword ptr [rip + .LCPI0_1] # xmm0 = [1,1]
	vpinsrq	xmm0, xmm0, r8, 1
	vpaddq	xmm1, xmm0, xmmword ptr [rax]
	vmovdqu	xmmword ptr [rax], xmm1
	lea	r8, [rsp + 72]
	lea	rax, [rip + reals_stats]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_345
# %bb.306:
	vpaddq	xmm0, xmm0, xmmword ptr [rax]
	vmovdqu	xmmword ptr [rax], xmm0
	mov	eax, dword ptr [rsp + 88]       # 4-byte Reload
	mov	word ptr [rsp + 64], ax
	test	byte ptr [rdx + 16], 1
	jne	.LBB0_337
# %bb.307:
	mov	r8d, dword ptr [rsp + 32]
	mov	eax, -20
	mov	r9, qword ptr [rsp + 160]       # 8-byte Reload
	#APP
	#NO_APP
	mov	eax, dword ptr [r9]
	mov	r9d, dword ptr [r9 + 4]
	lea	r10, [rax + 14]
	cmp	r10, r9
	ja	.LBB0_355
# %bb.308:
	lea	r10, [rax + 34]
	cmp	r10, r9
	ja	.LBB0_355
# %bb.309:
	mov	ecx, dword ptr [rsp + 88]       # 4-byte Reload
	rol	cx, 8
	shl	ecx, 16
	and	r8d, -65536
	xor	r8d, ecx
	lea	ecx, [r8 + 4268]
	movzx	r9d, word ptr [rsi + 4]
	mov	word ptr [rax + 4], r9w
	mov	esi, dword ptr [rsi]
	mov	dword ptr [rax], esi
	mov	esi, dword ptr [rax + 20]
	mov	dword ptr [rax + 6], esi
	movzx	esi, word ptr [rax + 24]
	mov	word ptr [rax + 10], si
	mov	word ptr [rax + 12], 8
	movzx	esi, byte ptr [rsp + 77]
	mov	edx, dword ptr [rdx]
	mov	byte ptr [rax + 14], 69
	add	edi, 20
	rol	di, 8
	mov	byte ptr [rax + 15], sil
	mov	word ptr [rax + 16], di
	mov	dword ptr [rax + 18], 0
	mov	dword ptr [rax + 30], edx
	mov	dword ptr [rax + 26], ecx
	mov	word ptr [rax + 22], 1088
	movzx	ecx, word ptr [rax + 14]
	movzx	esi, di
	movzx	edi, word ptr [rax + 22]
	add	rdi, rcx
	shr	r8d, 16
	add	r8, rdi
	movzx	ecx, dx
	add	rcx, r8
	add	rcx, rsi
	movzx	edx, word ptr [rax + 32]
	add	rcx, rdx
	add	rcx, 4268
	mov	rdx, rcx
	shr	rdx, 16
	movzx	esi, cx
	add	rsi, rdx
	cmp	rcx, 65536
	cmovb	rsi, rcx
	mov	rcx, rsi
	shr	rcx, 16
	movzx	edx, si
	add	rdx, rcx
	cmp	rsi, 65536
	cmovb	rdx, rsi
	mov	rcx, rdx
	shr	rcx, 16
	movzx	esi, dx
	add	ecx, esi
	cmp	rdx, 65536
	cmovb	ecx, edx
	mov	edx, ecx
	shr	edx, 16
	add	edx, ecx
	not	edx
	mov	word ptr [rax + 24], dx
	mov	ecx, 3
	jmp	.LBB0_345
.LBB0_310:
	cmp	byte ptr [rsp + 68], 6
	jne	.LBB0_313
# %bb.311:
	mov	dword ptr [rsp], 513
	lea	rax, [rip + stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.312:
	xor	ecx, ecx
	test	byte ptr [rsp + 76], 2
	sete	cl
	inc	qword ptr [rax + 8*rcx]
.LBB0_313:
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp], xmm0
	mov	dword ptr [rsp + 20], 514
	lea	rcx, [rip + stats]
	lea	rax, [rsp + 20]
	#APP
	#NO_APP
	mov	r14b, 1
	test	rcx, rcx
	je	.LBB0_316
# %bb.314:
	#APP

	rdtsc

	#NO_APP
	mov	rbx, rax
	sub	rax, qword ptr [rcx + 8]
	cmp	rax, 1000000001
	jb	.LBB0_317
# %bb.315:
	mov	qword ptr [rcx], 1
	mov	qword ptr [rcx + 8], rbx
	jmp	.LBB0_318
.LBB0_316:
	xor	ebx, ebx
	jmp	.LBB0_319
.LBB0_317:
	mov	rax, qword ptr [rcx]
	inc	rax
	mov	qword ptr [rcx], rax
	cmp	rax, 125000
	ja	.LBB0_319
.LBB0_318:
	xor	r14d, r14d
.LBB0_319:
	test	byte ptr [r13], 8
	jne	.LBB0_321
# %bb.320:
	mov	edi, dword ptr [rsp + 32]
	jmp	.LBB0_322
.LBB0_321:
	movzx	eax, word ptr [rsp + 66]
	mov	word ptr [rsp + 64], ax
	vmovdqa	xmmword ptr [rsp + 32], xmm0
	xor	edi, edi
.LBB0_322:
	mov	esi, dword ptr [rsp + 64]
	vzeroupper
	call	jhash_2words
	mov	ecx, eax
	mov	edx, 4294901761
	imul	rdx, rcx
	shr	rdx, 48
	mov	ecx, edx
	shl	ecx, 16
	or	ecx, edx
	sub	eax, ecx
	mov	ecx, dword ptr [r13 + 4]
	mov	edx, ecx
	shl	edx, 16
	add	edx, ecx
	add	edx, eax
	mov	dword ptr [rsp + 28], edx
	lea	rax, [rip + ch_rings]
	lea	rcx, [rsp + 28]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.323:
	mov	eax, dword ptr [rax]
	mov	dword ptr [rsp + 28], eax
	test	eax, eax
	je	.LBB0_340
# %bb.324:
	mov	dword ptr [rsp + 72], eax
	lea	rdx, [rip + reals]
	lea	rax, [rsp + 28]
	#APP
	#NO_APP
	test	rdx, rdx
	je	.LBB0_342
# %bb.325:
	movzx	eax, byte ptr [r13]
	and	al, 2
	shr	al
	or	r14b, al
	jne	.LBB0_330
# %bb.326:
	test	byte ptr [rsp + 76], 4
	jne	.LBB0_330
# %bb.327:
	cmp	byte ptr [rsp + 68], 17
	jne	.LBB0_329
# %bb.328:
	mov	qword ptr [rsp + 8], rbx
.LBB0_329:
	mov	eax, dword ptr [rsp + 28]
	mov	dword ptr [rsp], eax
	xor	eax, eax
	lea	rcx, [rsp + 32]
	mov	rsi, rsp
	#APP
	#NO_APP
.LBB0_330:
	mov	dword ptr [rsp], 0
	lea	rax, [rip + vip_miss_stats]
	mov	rcx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.331:
	mov	r8d, dword ptr [rax]
	movzx	esi, word ptr [rax + 16]
	movzx	edi, word ptr [rsp + 112]
	movzx	ecx, byte ptr [rsp + 114]
	cmp	r8d, dword ptr [rsp + 96]
	mov	byte ptr [rax + 18], cl
	jne	.LBB0_336
# %bb.332:
	cmp	si, di
	jne	.LBB0_336
# %bb.333:
	test	cl, cl
	je	.LBB0_336
# %bb.334:
	mov	eax, dword ptr [rsp + 72]
	mov	dword ptr [rsp + 20], eax
	lea	rax, [rip + lru_miss_stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
# %bb.335:
	inc	dword ptr [rax]
.LBB0_336:
	inc	qword ptr [r15 + 8]
	jmp	.LBB0_303
.LBB0_337:
	mov	eax, -40
	mov	rdi, qword ptr [rsp + 160]      # 8-byte Reload
	#APP
	#NO_APP
	mov	eax, dword ptr [rdi]
	mov	edi, dword ptr [rdi + 4]
	lea	r8, [rax + 14]
	cmp	r8, rdi
	ja	.LBB0_357
# %bb.338:
	lea	r8, [rax + 54]
	cmp	r8, rdi
	ja	.LBB0_357
# %bb.339:
	movzx	ecx, word ptr [rsi + 4]
	mov	word ptr [rax + 4], cx
	mov	ecx, dword ptr [rsi]
	mov	dword ptr [rax], ecx
	mov	ecx, dword ptr [rax + 40]
	mov	dword ptr [rax + 6], ecx
	movzx	ecx, word ptr [rax + 44]
	mov	word ptr [rax + 10], cx
	mov	word ptr [rax + 12], -8826
	movzx	ecx, word ptr [rsp + 64]
	xor	ecx, dword ptr [rsp + 32]
	movzx	esi, byte ptr [rsp + 77]
	mov	word ptr [rax + 16], 0
	mov	edi, esi
	shr	dil, 4
	or	dil, 96
	mov	byte ptr [rax + 14], dil
	shl	sil, 4
	mov	byte ptr [rax + 15], sil
	mov	word ptr [rax + 20], 16388
	mov	word ptr [rax + 18], bp
	mov	qword ptr [rax + 22], 1
	mov	dword ptr [rax + 30], 0
	mov	dword ptr [rax + 34], ecx
	vmovdqu	xmm0, xmmword ptr [rdx]
	vmovdqu	xmmword ptr [rax + 38], xmm0
	mov	ecx, 3
	jmp	.LBB0_345
.LBB0_340:
	mov	dword ptr [rsp + 20], 521
	lea	rax, [rip + stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
.LBB0_341:
	inc	qword ptr [rax + 8]
	jmp	.LBB0_344
.LBB0_342:
	mov	dword ptr [rsp + 20], 521
	lea	rax, [rip + stats]
	lea	rcx, [rsp + 20]
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_344
.LBB0_343:
	inc	qword ptr [rax]
.LBB0_344:
	mov	ecx, 1
.LBB0_345:
	mov	eax, 1
	vmovdqa	xmm3, xmmword ptr [rsp + 128]   # 16-byte Reload
	cmp	ecx, 1
	jne	.LBB0_347
.LBB0_350:
	mov	dword ptr [rsp + 92], 530
	mov	ecx, 1
.LBB0_351:
	lea	rdx, [rip + stats]
	lea	rsi, [rsp + 92]
	#APP
	#NO_APP
	test	rdx, rdx
	je	.LBB0_353
# %bb.352:
	vpaddq	xmm0, xmm3, xmmword ptr [rdx]
	vmovdqu	xmmword ptr [rdx], xmm0
	mov	eax, ecx
.LBB0_353:
	add	rsp, 168
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	r12
	.cfi_def_cfa_offset 40
	pop	r13
	.cfi_def_cfa_offset 32
	pop	r14
	.cfi_def_cfa_offset 24
	pop	r15
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	.cfi_restore rbx
	.cfi_restore r12
	.cfi_restore r13
	.cfi_restore r14
	.cfi_restore r15
	.cfi_restore rbp
.LBB0_354:
	vzeroupper
	ret
.LBB0_355:
	.cfi_def_cfa_offset 224
	.cfi_offset rbx, -56
	.cfi_offset rbp, -16
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	mov	dword ptr [rsp], 519
	lea	rax, [rip + stats]
	mov	rdx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_345
# %bb.356:
	inc	qword ptr [rax]
	jmp	.LBB0_345
.LBB0_357:
	mov	dword ptr [rsp], 519
	lea	rax, [rip + stats]
	mov	rdx, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_345
# %bb.358:
	inc	qword ptr [rax + 8]
	jmp	.LBB0_345
.LBB0_359:
	inc	qword ptr [rcx + 40]
	jmp	.LBB0_344
.LBB0_360:
	mov	rax, qword ptr [rdi]
	inc	rax
	mov	qword ptr [rdi], rax
	cmp	rax, 125001
	jae	.LBB0_363
.LBB0_362:
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp], xmm0
	mov	eax, dword ptr [rsp + 72]
	mov	dword ptr [rsp], eax
	xor	eax, eax
	lea	rdi, [rsp + 32]
	mov	r8, rsp
	#APP
	#NO_APP
.LBB0_363:
	inc	qword ptr [rcx + 96]
.LBB0_364:
	inc	qword ptr [rcx + 32]
	movzx	r10d, word ptr [rsp + 64]
	mov	eax, 1
	mov	rdi, rsi
	vmovdqa	xmm3, xmm1
	vmovdqa	xmm2, xmm4
	jmp	.LBB0_205
.LBB0_365:
	mov	dword ptr [rsp], 514
	lea	rsi, [rip + stats]
	mov	rax, rsp
	#APP
	#NO_APP
	test	rsi, rsi
	je	.LBB0_373
# %bb.366:
	#APP

	rdtsc

	#NO_APP
	mov	rdi, rax
	sub	rdi, qword ptr [rsi + 8]
	cmp	rdi, 1000000001
	jb	.LBB0_370
# %bb.367:
	mov	qword ptr [rsi], 1
	mov	qword ptr [rsi + 8], rax
	jmp	.LBB0_372
.LBB0_368:
	mov	dword ptr [rax], esi
	inc	qword ptr [rcx + 88]
	mov	dword ptr [rsp], r9d
	lea	rax, [rip + server_id_stats]
	mov	rsi, rsp
	#APP
	#NO_APP
	test	rax, rax
	je	.LBB0_374
# %bb.369:
	inc	qword ptr [rax + 8]
	jmp	.LBB0_374
.LBB0_370:
	mov	rax, qword ptr [rsi]
	inc	rax
	mov	qword ptr [rsi], rax
	cmp	rax, 125001
	jae	.LBB0_373
.LBB0_372:
	vpxor	xmm0, xmm0, xmm0
	vmovdqa	xmmword ptr [rsp], xmm0
	mov	eax, dword ptr [rsp + 72]
	mov	dword ptr [rsp], eax
	xor	eax, eax
	lea	rsi, [rsp + 32]
	mov	rdi, rsp
	#APP
	#NO_APP
.LBB0_373:
	inc	qword ptr [rcx + 96]
.LBB0_374:
	inc	qword ptr [rcx + 32]
	movzx	eax, word ptr [rsp + 64]
	mov	dword ptr [rsp + 88], eax       # 4-byte Spill
	jmp	.LBB0_303
.Lfunc_end0:
	.size	balancer_ingress, .Lfunc_end0-balancer_ingress
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90                         # -- Begin function jhash_2words
	.type	jhash_2words,@function
jhash_2words:                           # @jhash_2words
	.cfi_startproc
# %bb.0:
	add	edi, -525483785
	add	esi, -525483785
	mov	eax, esi
	xor	eax, -525483785
	rorx	ecx, esi, 18
	sub	eax, ecx
	xor	edi, eax
	rorx	ecx, eax, 21
	sub	edi, ecx
	xor	esi, edi
	rorx	ecx, edi, 7
	sub	esi, ecx
	xor	eax, esi
	rorx	ecx, esi, 16
	sub	eax, ecx
	xor	edi, eax
	rorx	ecx, eax, 28
	sub	edi, ecx
	xor	esi, edi
	rorx	ecx, edi, 18
	sub	esi, ecx
	xor	eax, esi
	rorx	ecx, esi, 8
	sub	eax, ecx
	ret
.Lfunc_end1:
	.size	jhash_2words, .Lfunc_end1-jhash_2words
	.cfi_endproc
                                        # -- End function
	.p2align	4, 0x90                         # -- Begin function jhash
	.type	jhash,@function
jhash:                                  # @jhash
	.cfi_startproc
# %bb.0:
	mov	eax, dword ptr [rdi]
	mov	ecx, dword ptr [rdi + 4]
	lea	edx, [rcx - 559038209]
	mov	esi, dword ptr [rdi + 8]
	sub	eax, esi
	lea	r8d, [rsi - 559038209]
	rorx	r8d, r8d, 28
	xor	r8d, eax
	sub	edx, r8d
	rorx	eax, r8d, 26
	xor	eax, edx
	add	ecx, esi
	add	ecx, -1118076418
	add	r8d, ecx
	lea	esi, [rax + r8]
	sub	ecx, eax
	rorx	r9d, eax, 24
	xor	r9d, ecx
	sub	r8d, r9d
	rorx	edx, r9d, 16
	xor	edx, r8d
	add	r9d, esi
	sub	esi, edx
	rorx	ecx, edx, 13
	xor	ecx, esi
	add	edx, r9d
	lea	eax, [rcx + rdx]
	sub	r9d, ecx
	rorx	ecx, ecx, 28
	xor	ecx, r9d
	movzx	esi, byte ptr [rdi + 15]
	shl	esi, 24
	movzx	r8d, byte ptr [rdi + 14]
	shl	r8d, 16
	add	r8d, esi
	movzx	r9d, byte ptr [rdi + 13]
	shl	r9d, 8
	add	r9d, r8d
	movzx	esi, byte ptr [rdi + 12]
	add	esi, r9d
	add	esi, edx
	xor	ecx, eax
	rorx	edx, eax, 18
	sub	ecx, edx
	xor	esi, ecx
	rorx	edx, ecx, 21
	sub	esi, edx
	xor	eax, esi
	rorx	edx, esi, 7
	sub	eax, edx
	xor	ecx, eax
	rorx	edx, eax, 16
	sub	ecx, edx
	xor	esi, ecx
	rorx	edx, ecx, 28
	sub	esi, edx
	xor	eax, esi
	rorx	edx, esi, 18
	sub	eax, edx
	rorx	edx, eax, 8
	xor	eax, ecx
	sub	eax, edx
	ret
.Lfunc_end2:
	.size	jhash, .Lfunc_end2-jhash
	.cfi_endproc
                                        # -- End function
	.type	stats,@object                   # @stats
	.bss
	.globl	stats
	.p2align	3, 0x0
stats:
	.zero	40
	.size	stats, 40

	.type	_license,@object                # @_license
	.data
	.globl	_license
_license:
	.asciz	"GPL"
	.size	_license, 4

	.type	ctl_array,@object               # @ctl_array
	.bss
	.globl	ctl_array
	.p2align	3, 0x0
ctl_array:
	.zero	40
	.size	ctl_array, 40

	.type	vip_map,@object                 # @vip_map
	.globl	vip_map
	.p2align	3, 0x0
vip_map:
	.zero	40
	.size	vip_map, 40

	.type	fallback_cache,@object          # @fallback_cache
	.globl	fallback_cache
	.p2align	3, 0x0
fallback_cache:
	.zero	40
	.size	fallback_cache, 40

	.type	lru_mapping,@object             # @lru_mapping
	.globl	lru_mapping
	.p2align	3, 0x0
lru_mapping:
	.zero	40
	.size	lru_mapping, 40

	.type	ch_rings,@object                # @ch_rings
	.globl	ch_rings
	.p2align	3, 0x0
ch_rings:
	.zero	40
	.size	ch_rings, 40

	.type	reals,@object                   # @reals
	.globl	reals
	.p2align	3, 0x0
reals:
	.zero	40
	.size	reals, 40

	.type	reals_stats,@object             # @reals_stats
	.globl	reals_stats
	.p2align	3, 0x0
reals_stats:
	.zero	40
	.size	reals_stats, 40

	.type	lru_miss_stats,@object          # @lru_miss_stats
	.globl	lru_miss_stats
	.p2align	3, 0x0
lru_miss_stats:
	.zero	40
	.size	lru_miss_stats, 40

	.type	vip_miss_stats,@object          # @vip_miss_stats
	.globl	vip_miss_stats
	.p2align	3, 0x0
vip_miss_stats:
	.zero	40
	.size	vip_miss_stats, 40

	.type	quic_stats_map,@object          # @quic_stats_map
	.globl	quic_stats_map
	.p2align	3, 0x0
quic_stats_map:
	.zero	40
	.size	quic_stats_map, 40

	.type	stable_rt_stats,@object         # @stable_rt_stats
	.globl	stable_rt_stats
	.p2align	3, 0x0
stable_rt_stats:
	.zero	40
	.size	stable_rt_stats, 40

	.type	decap_vip_stats,@object         # @decap_vip_stats
	.globl	decap_vip_stats
	.p2align	3, 0x0
decap_vip_stats:
	.zero	40
	.size	decap_vip_stats, 40

	.type	server_id_map,@object           # @server_id_map
	.globl	server_id_map
	.p2align	3, 0x0
server_id_map:
	.zero	40
	.size	server_id_map, 40

	.type	tpr_stats_map,@object           # @tpr_stats_map
	.globl	tpr_stats_map
	.p2align	3, 0x0
tpr_stats_map:
	.zero	40
	.size	tpr_stats_map, 40

	.type	server_id_stats,@object         # @server_id_stats
	.globl	server_id_stats
	.p2align	3, 0x0
server_id_stats:
	.zero	40
	.size	server_id_stats, 40

	.type	vip_to_down_reals_map,@object   # @vip_to_down_reals_map
	.globl	vip_to_down_reals_map
	.p2align	3, 0x0
vip_to_down_reals_map:
	.zero	40
	.size	vip_to_down_reals_map, 40

	.ident	"Ubuntu clang version 18.1.3 (1ubuntu1)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym balancer_ingress
	.addrsig_sym stats
	.addrsig_sym _license
	.addrsig_sym ctl_array
	.addrsig_sym vip_map
	.addrsig_sym fallback_cache
	.addrsig_sym lru_mapping
	.addrsig_sym ch_rings
	.addrsig_sym reals
	.addrsig_sym reals_stats
	.addrsig_sym lru_miss_stats
	.addrsig_sym vip_miss_stats
	.addrsig_sym quic_stats_map
	.addrsig_sym stable_rt_stats
	.addrsig_sym decap_vip_stats
	.addrsig_sym server_id_map
	.addrsig_sym tpr_stats_map
	.addrsig_sym server_id_stats
	.addrsig_sym vip_to_down_reals_map
