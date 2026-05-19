# tc_packet_checksum_fold

## Original C
```c
#include "common.h"

#define TC_CHECKSUM_MAX_ROUNDS 32U
#define TC_CHECKSUM_MAX_WORDS 512U
#define TC_CHECKSUM_INPUT_SIZE (8U + TC_CHECKSUM_MAX_WORDS * 2U)

static __always_inline int bench_checksum(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (rounds != TC_CHECKSUM_MAX_ROUNDS || word_count != TC_CHECKSUM_MAX_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, TC_CHECKSUM_MAX_WORDS * 2U)) {
        return -1;
    }

    for (u32 round = 0; round < TC_CHECKSUM_MAX_ROUNDS; round++) {
        u32 sum = 0;
        for (u32 i = 0; i < TC_CHECKSUM_MAX_WORDS; i++) {
            sum += micro_read_u16_le(data, 8 + i * 2U);
            sum = (sum & 0xFFFFU) + (sum >> 16);
        }
        sum = (sum & 0xFFFFU) + (sum >> 16);
        /*
         * The same checksum value is folded into four 16-bit lanes. With 32
         * rounds each lane toggles eight times, so the final accumulator is
         * intentionally zero even though the staged input is non-zero.
         */
        acc ^= (u64)(~sum & 0xFFFFU) << ((round & 3U) * 16U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_TC_BENCH(
    tc_packet_checksum_fold_prog,
    bench_checksum,
    tc_packet_checksum_fold_input_value,
    TC_CHECKSUM_INPUT_SIZE)
```

## Native ASM
```asm
Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 c1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fc1]        # 3fd0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

Disassembly of section .plt.got:

0000000000001030 <__cxa_finalize@plt>:
    1030:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1036:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000001040 <deregister_tm_clones>:
    1040:	48 8d 3d c1 2f 00 00 	lea    rdi,[rip+0x2fc1]        # 4008 <completed.0>
    1047:	48 8d 05 ba 2f 00 00 	lea    rax,[rip+0x2fba]        # 4008 <completed.0>
    104e:	48 39 f8             	cmp    rax,rdi
    1051:	74 15                	je     1068 <deregister_tm_clones+0x28>
    1053:	48 8b 05 6e 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f6e]        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    105a:	48 85 c0             	test   rax,rax
    105d:	74 09                	je     1068 <deregister_tm_clones+0x28>
    105f:	ff e0                	jmp    rax
    1061:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1068:	c3                   	ret
    1069:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001070 <register_tm_clones>:
    1070:	48 8d 3d 91 2f 00 00 	lea    rdi,[rip+0x2f91]        # 4008 <completed.0>
    1077:	48 8d 35 8a 2f 00 00 	lea    rsi,[rip+0x2f8a]        # 4008 <completed.0>
    107e:	48 29 fe             	sub    rsi,rdi
    1081:	48 89 f0             	mov    rax,rsi
    1084:	48 c1 ee 3f          	shr    rsi,0x3f
    1088:	48 c1 f8 03          	sar    rax,0x3
    108c:	48 01 c6             	add    rsi,rax
    108f:	48 d1 fe             	sar    rsi,1
    1092:	74 14                	je     10a8 <register_tm_clones+0x38>
    1094:	48 8b 05 3d 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f3d]        # 3fd8 <_ITM_registerTMCloneTable@Base>
    109b:	48 85 c0             	test   rax,rax
    109e:	74 08                	je     10a8 <register_tm_clones+0x38>
    10a0:	ff e0                	jmp    rax
    10a2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    10a8:	c3                   	ret
    10a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010b0 <__do_global_dtors_aux>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	80 3d 4d 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f4d],0x0        # 4008 <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 25 2f 00 00 01 	mov    BYTE PTR [rip+0x2f25],0x1        # 4008 <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001100 <tc_packet_checksum_fold_prog>:
    1100:	48 8b 87 d0 00 00 00 	mov    rax,QWORD PTR [rdi+0xd0]
    1107:	81 7f 70 0f 04 00 00 	cmp    DWORD PTR [rdi+0x70],0x40f
    110e:	77 0d                	ja     111d <tc_packet_checksum_fold_prog+0x1d>
    1110:	48 c7 00 ff ff ff ff 	mov    QWORD PTR [rax],0xffffffffffffffff
    1117:	b8 02 00 00 00       	mov    eax,0x2
    111c:	c3                   	ret
    111d:	83 78 08 20          	cmp    DWORD PTR [rax+0x8],0x20
    1121:	75 ed                	jne    1110 <tc_packet_checksum_fold_prog+0x10>
    1123:	81 78 0c 00 02 00 00 	cmp    DWORD PTR [rax+0xc],0x200
    112a:	75 e4                	jne    1110 <tc_packet_checksum_fold_prog+0x10>
    112c:	31 d2                	xor    edx,edx
    112e:	31 f6                	xor    esi,esi
    1130:	b9 13 00 00 00       	mov    ecx,0x13
    1135:	31 ff                	xor    edi,edi
    1137:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    113e:	00 00 
    1140:	44 0f b7 44 08 fd    	movzx  r8d,WORD PTR [rax+rcx*1-0x3]
    1146:	41 01 f8             	add    r8d,edi
    1149:	41 0f b7 f8          	movzx  edi,r8w
    114d:	41 c1 e8 10          	shr    r8d,0x10
    1151:	41 01 f8             	add    r8d,edi
    1154:	0f b7 7c 08 ff       	movzx  edi,WORD PTR [rax+rcx*1-0x1]
    1159:	44 01 c7             	add    edi,r8d
    115c:	44 0f b7 c7          	movzx  r8d,di
    1160:	c1 ef 10             	shr    edi,0x10
    1163:	44 01 c7             	add    edi,r8d
    1166:	48 83 c1 04          	add    rcx,0x4
    116a:	48 81 f9 13 04 00 00 	cmp    rcx,0x413
    1171:	75 cd                	jne    1140 <tc_packet_checksum_fold_prog+0x40>
    1173:	89 f9                	mov    ecx,edi
    1175:	c1 e9 10             	shr    ecx,0x10
    1178:	01 f9                	add    ecx,edi
    117a:	f7 d1                	not    ecx
    117c:	0f b7 f9             	movzx  edi,cx
    117f:	89 d1                	mov    ecx,edx
    1181:	c1 e1 04             	shl    ecx,0x4
    1184:	48 d3 e7             	shl    rdi,cl
    1187:	48 31 fe             	xor    rsi,rdi
    118a:	ff c2                	inc    edx
    118c:	83 fa 20             	cmp    edx,0x20
    118f:	75 9f                	jne    1130 <tc_packet_checksum_fold_prog+0x30>
    1191:	48 89 30             	mov    QWORD PTR [rax],rsi
    1194:	31 c0                	xor    eax,eax
    1196:	c3                   	ret

Disassembly of section .fini:

0000000000001198 <_fini>:
    1198:	f3 0f 1e fa          	endbr64
    119c:	48 83 ec 08          	sub    rsp,0x8
    11a0:	48 83 c4 08          	add    rsp,0x8
    11a4:	c3                   	ret
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
   d:	41 55                	push   r13
   f:	48 8b 57 50          	mov    rdx,QWORD PTR [rdi+0x50]
  13:	48 8b b7 d0 00 00 00 	mov    rsi,QWORD PTR [rdi+0xd0]
  1a:	48 39 d6             	cmp    rsi,rdx
  1d:	77 1b                	ja     0x3a
  1f:	48 89 f1             	mov    rcx,rsi
  22:	48 83 c1 08          	add    rcx,0x8
  26:	48 39 d1             	cmp    rcx,rdx
  29:	77 0f                	ja     0x3a
  2b:	48 89 f1             	mov    rcx,rsi
  2e:	48 81 c1 10 04 00 00 	add    rcx,0x410
  35:	48 39 d1             	cmp    rcx,rdx
  38:	76 18                	jbe    0x52
  3a:	41 b8 ff ff ff ff    	mov    r8d,0xffffffff
  40:	44 89 47 30          	mov    DWORD PTR [rdi+0x30],r8d
  44:	b8 02 00 00 00       	mov    eax,0x2
  49:	44 89 47 34          	mov    DWORD PTR [rdi+0x34],r8d
  4d:	41 5d                	pop    r13
  4f:	5b                   	pop    rbx
  50:	c9                   	leave
  51:	c3                   	ret
  52:	48 0f b6 56 09       	movzx  rdx,BYTE PTR [rsi+0x9]
  57:	c1 e2 08             	shl    edx,0x8
  5a:	48 0f b6 4e 08       	movzx  rcx,BYTE PTR [rsi+0x8]
  5f:	09 ca                	or     edx,ecx
  61:	48 0f b6 4e 0a       	movzx  rcx,BYTE PTR [rsi+0xa]
  66:	c1 e1 10             	shl    ecx,0x10
  69:	09 ca                	or     edx,ecx
  6b:	48 0f b6 4e 0b       	movzx  rcx,BYTE PTR [rsi+0xb]
  70:	c1 e1 18             	shl    ecx,0x18
  73:	09 ca                	or     edx,ecx
  75:	83 fa 20             	cmp    edx,0x20
  78:	75 c0                	jne    0x3a
  7a:	48 0f b6 56 0d       	movzx  rdx,BYTE PTR [rsi+0xd]
  7f:	c1 e2 08             	shl    edx,0x8
  82:	48 0f b6 4e 0c       	movzx  rcx,BYTE PTR [rsi+0xc]
  87:	09 ca                	or     edx,ecx
  89:	48 0f b6 4e 0e       	movzx  rcx,BYTE PTR [rsi+0xe]
  8e:	c1 e1 10             	shl    ecx,0x10
  91:	09 ca                	or     edx,ecx
  93:	48 0f b6 4e 0f       	movzx  rcx,BYTE PTR [rsi+0xf]
  98:	c1 e1 18             	shl    ecx,0x18
  9b:	09 ca                	or     edx,ecx
  9d:	81 fa 00 02 00 00    	cmp    edx,0x200
  a3:	75 95                	jne    0x3a
  a5:	31 c9                	xor    ecx,ecx
  a7:	31 d2                	xor    edx,edx
  a9:	45 31 c0             	xor    r8d,r8d
  ac:	31 db                	xor    ebx,ebx
  ae:	48 89 f0             	mov    rax,rsi
  b1:	4c 01 c0             	add    rax,r8
  b4:	4c 0f b6 68 10       	movzx  r13,BYTE PTR [rax+0x10]
  b9:	48 0f b6 40 11       	movzx  rax,BYTE PTR [rax+0x11]
  be:	c1 e0 08             	shl    eax,0x8
  c1:	44 09 e8             	or     eax,r13d
  c4:	01 d8                	add    eax,ebx
  c6:	89 c3                	mov    ebx,eax
  c8:	c1 eb 10             	shr    ebx,0x10
  cb:	25 ff ff 00 00       	and    eax,0xffff
  d0:	01 d8                	add    eax,ebx
  d2:	49 83 c0 02          	add    r8,0x2
  d6:	89 c3                	mov    ebx,eax
  d8:	49 81 f8 00 04 00 00 	cmp    r8,0x400
  df:	74 02                	je     0xe3
  e1:	eb cb                	jmp    0xae
  e3:	41 89 c0             	mov    r8d,eax
  e6:	41 c1 e8 10          	shr    r8d,0x10
  ea:	41 01 c0             	add    r8d,eax
  ed:	41 83 f0 ff          	xor    r8d,0xffffffff
  f1:	41 81 e0 ff ff 00 00 	and    r8d,0xffff
  f8:	89 d0                	mov    eax,edx
  fa:	c1 e0 04             	shl    eax,0x4
  fd:	83 e0 30             	and    eax,0x30
 100:	c4 42 f9 f7 c0       	shlx   r8,r8,rax
 105:	49 31 c8             	xor    r8,rcx
 108:	83 c2 01             	add    edx,0x1
 10b:	4c 89 c1             	mov    rcx,r8
 10e:	83 fa 20             	cmp    edx,0x20
 111:	74 02                	je     0x115
 113:	eb 94                	jmp    0xa9
 115:	44 89 47 30          	mov    DWORD PTR [rdi+0x30],r8d
 119:	31 c0                	xor    eax,eax
 11b:	49 c1 e8 20          	shr    r8,0x20
 11f:	e9 25 ff ff ff       	jmp    0x49
```

## llvmbpf JIT ASM
```asm
not captured
```
