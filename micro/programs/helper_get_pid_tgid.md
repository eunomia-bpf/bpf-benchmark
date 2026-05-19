# helper_get_pid_tgid

## Original C
```c
not captured
```

## Native ASM
```asm
not captured
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	53                   	push   rbx
   d:	31 c0                	xor    eax,eax
   f:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  13:	48 8b 5f 00          	mov    rbx,QWORD PTR [rdi+0x0]
  17:	48 89 df             	mov    rdi,rbx
  1a:	48 83 c7 08          	add    rdi,0x8
  1e:	48 39 f7             	cmp    rdi,rsi
  21:	77 56                	ja     0x79
  23:	e8 04 8a 18 d7       	call   0xffffffffd7188a2c
  28:	48 89 c7             	mov    rdi,rax
  2b:	48 c1 ef 38          	shr    rdi,0x38
  2f:	40 88 7b 07          	mov    BYTE PTR [rbx+0x7],dil
  33:	48 89 c7             	mov    rdi,rax
  36:	48 c1 ef 30          	shr    rdi,0x30
  3a:	40 88 7b 06          	mov    BYTE PTR [rbx+0x6],dil
  3e:	48 89 c7             	mov    rdi,rax
  41:	48 c1 ef 28          	shr    rdi,0x28
  45:	40 88 7b 05          	mov    BYTE PTR [rbx+0x5],dil
  49:	48 89 c7             	mov    rdi,rax
  4c:	48 c1 ef 20          	shr    rdi,0x20
  50:	40 88 7b 04          	mov    BYTE PTR [rbx+0x4],dil
  54:	48 89 c7             	mov    rdi,rax
  57:	48 c1 ef 18          	shr    rdi,0x18
  5b:	40 88 7b 03          	mov    BYTE PTR [rbx+0x3],dil
  5f:	48 89 c7             	mov    rdi,rax
  62:	48 c1 ef 10          	shr    rdi,0x10
  66:	40 88 7b 02          	mov    BYTE PTR [rbx+0x2],dil
  6a:	88 43 00             	mov    BYTE PTR [rbx+0x0],al
  6d:	48 c1 e8 08          	shr    rax,0x8
  71:	88 43 01             	mov    BYTE PTR [rbx+0x1],al
  74:	b8 02 00 00 00       	mov    eax,0x2
  79:	5b                   	pop    rbx
  7a:	c9                   	leave
  7b:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
