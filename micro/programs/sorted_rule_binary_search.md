# sorted_rule_binary_search

## Original C
```c
#include "common.h"

#define BINARY_SEARCH_MAX_DATA_LEN 32U
#define BINARY_SEARCH_MAX_QUERY_LEN 16U
#define BINARY_SEARCH_INPUT_SIZE \
    (8U + (BINARY_SEARCH_MAX_DATA_LEN + BINARY_SEARCH_MAX_QUERY_LEN) * 8U)

static __always_inline int bench_sorted_rule_binary_search(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 data_len = micro_read_u32_le(data, 0);
    u32 query_len = micro_read_u32_le(data, 4);
    u32 data_bytes;
    u32 query_bytes;
    u32 query_offset;
    u64 acc = 0;

    if (data_len != BINARY_SEARCH_MAX_DATA_LEN || query_len != BINARY_SEARCH_MAX_QUERY_LEN) {
        return -1;
    }

    data_bytes = BINARY_SEARCH_MAX_DATA_LEN * 8U;
    query_bytes = BINARY_SEARCH_MAX_QUERY_LEN * 8U;
    query_offset = 8 + data_bytes;

    if (!micro_has_bytes(len, 8, data_bytes + query_bytes)) {
        return -1;
    }

    for (u32 i = 0; i < BINARY_SEARCH_MAX_QUERY_LEN; i++) {
        u64 target = micro_read_u64_le(data, query_offset + i * 8);
        u64 found = 0;
        u64 index = 0;
        for (u32 j = 0; j < BINARY_SEARCH_MAX_DATA_LEN; j++) {
            u64 current = micro_read_u64_le(data, 8 + j * 8);
            if (!found && current == target) {
                found = 1;
                index = j;
            }
        }
        if (found) {
            acc += index;
        } else {
            acc ^= target + BINARY_SEARCH_MAX_DATA_LEN;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    sorted_rule_binary_search_xdp,
    bench_sorted_rule_binary_search,
    sorted_rule_binary_search_input_value,
    BINARY_SEARCH_INPUT_SIZE)
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

0000000000001100 <sorted_rule_binary_search_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	76 01                	jbe    110f <sorted_rule_binary_search_xdp+0xf>
    110e:	c3                   	ret
    110f:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1113:	48 39 d6             	cmp    rsi,rdx
    1116:	77 f6                	ja     110e <sorted_rule_binary_search_xdp+0xe>
    1118:	48 8d b1 90 01 00 00 	lea    rsi,[rcx+0x190]
    111f:	48 39 d6             	cmp    rsi,rdx
    1122:	77 ea                	ja     110e <sorted_rule_binary_search_xdp+0xe>
    1124:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
    1128:	75 e4                	jne    110e <sorted_rule_binary_search_xdp+0xe>
    112a:	83 79 0c 10          	cmp    DWORD PTR [rcx+0xc],0x10
    112e:	75 de                	jne    110e <sorted_rule_binary_search_xdp+0xe>
    1130:	31 c0                	xor    eax,eax
    1132:	31 d2                	xor    edx,edx
    1134:	66 66 66 2e 0f 1f 84 	data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    113b:	00 00 00 00 00 
    1140:	48 8b b4 c1 10 01 00 	mov    rsi,QWORD PTR [rcx+rax*8+0x110]
    1147:	00 
    1148:	45 31 c0             	xor    r8d,r8d
    114b:	31 ff                	xor    edi,edi
    114d:	45 31 c9             	xor    r9d,r9d
    1150:	45 89 ca             	mov    r10d,r9d
    1153:	49 89 fb             	mov    r11,rdi
    1156:	4a 39 74 c1 10       	cmp    QWORD PTR [rcx+r8*8+0x10],rsi
    115b:	41 0f 94 c1          	sete   r9b
    115f:	49 0f 44 f8          	cmove  rdi,r8
    1163:	45 08 d1             	or     r9b,r10b
    1166:	41 f6 c2 01          	test   r10b,0x1
    116a:	49 0f 45 fb          	cmovne rdi,r11
    116e:	49 ff c0             	inc    r8
    1171:	49 83 f8 20          	cmp    r8,0x20
    1175:	75 d9                	jne    1150 <sorted_rule_binary_search_xdp+0x50>
    1177:	48 01 d7             	add    rdi,rdx
    117a:	48 83 c6 20          	add    rsi,0x20
    117e:	48 31 f2             	xor    rdx,rsi
    1181:	41 f6 c1 01          	test   r9b,0x1
    1185:	48 0f 45 d7          	cmovne rdx,rdi
    1189:	48 ff c0             	inc    rax
    118c:	48 83 f8 10          	cmp    rax,0x10
    1190:	75 ae                	jne    1140 <sorted_rule_binary_search_xdp+0x40>
    1192:	48 89 11             	mov    QWORD PTR [rcx],rdx
    1195:	b8 02 00 00 00       	mov    eax,0x2
    119a:	c3                   	ret

Disassembly of section .fini:

000000000000119c <_fini>:
    119c:	f3 0f 1e fa          	endbr64
    11a0:	48 83 ec 08          	sub    rsp,0x8
    11a4:	48 83 c4 08          	add    rsp,0x8
    11a8:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 48 00 00 00 	sub    rsp,0x48
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 f7             	cmp    rdi,rsi
  27:	0f 87 ba 02 00 00    	ja     0x2e7
  2d:	48 89 fa             	mov    rdx,rdi
  30:	48 83 c2 08          	add    rdx,0x8
  34:	48 39 f2             	cmp    rdx,rsi
  37:	0f 87 aa 02 00 00    	ja     0x2e7
  3d:	48 89 fa             	mov    rdx,rdi
  40:	48 81 c2 90 01 00 00 	add    rdx,0x190
  47:	48 39 f2             	cmp    rdx,rsi
  4a:	0f 87 97 02 00 00    	ja     0x2e7
  50:	48 0f b6 77 09       	movzx  rsi,BYTE PTR [rdi+0x9]
  55:	c1 e6 08             	shl    esi,0x8
  58:	48 0f b6 57 08       	movzx  rdx,BYTE PTR [rdi+0x8]
  5d:	09 d6                	or     esi,edx
  5f:	48 0f b6 57 0a       	movzx  rdx,BYTE PTR [rdi+0xa]
  64:	c1 e2 10             	shl    edx,0x10
  67:	09 d6                	or     esi,edx
  69:	48 0f b6 57 0b       	movzx  rdx,BYTE PTR [rdi+0xb]
  6e:	c1 e2 18             	shl    edx,0x18
  71:	09 d6                	or     esi,edx
  73:	83 fe 20             	cmp    esi,0x20
  76:	0f 85 6b 02 00 00    	jne    0x2e7
  7c:	48 0f b6 77 0d       	movzx  rsi,BYTE PTR [rdi+0xd]
  81:	c1 e6 08             	shl    esi,0x8
  84:	48 0f b6 57 0c       	movzx  rdx,BYTE PTR [rdi+0xc]
  89:	09 d6                	or     esi,edx
  8b:	48 0f b6 57 0e       	movzx  rdx,BYTE PTR [rdi+0xe]
  90:	c1 e2 10             	shl    edx,0x10
  93:	09 d6                	or     esi,edx
  95:	48 0f b6 57 0f       	movzx  rdx,BYTE PTR [rdi+0xf]
  9a:	c1 e2 18             	shl    edx,0x18
  9d:	09 d6                	or     esi,edx
  9f:	83 fe 10             	cmp    esi,0x10
  a2:	0f 85 3f 02 00 00    	jne    0x2e7
  a8:	31 f6                	xor    esi,esi
  aa:	48 89 fa             	mov    rdx,rdi
  ad:	48 83 c2 17          	add    rdx,0x17
  b1:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
  b5:	48 89 fa             	mov    rdx,rdi
  b8:	48 81 c2 17 01 00 00 	add    rdx,0x117
  bf:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
  c3:	48 89 fa             	mov    rdx,rdi
  c6:	48 81 c2 16 01 00 00 	add    rdx,0x116
  cd:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  d1:	48 89 fa             	mov    rdx,rdi
  d4:	48 81 c2 15 01 00 00 	add    rdx,0x115
  db:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
  df:	48 89 fa             	mov    rdx,rdi
  e2:	48 81 c2 14 01 00 00 	add    rdx,0x114
  e9:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
  ed:	48 89 fa             	mov    rdx,rdi
  f0:	48 81 c2 13 01 00 00 	add    rdx,0x113
  f7:	48 89 55 d0          	mov    QWORD PTR [rbp-0x30],rdx
  fb:	48 89 fa             	mov    rdx,rdi
  fe:	48 81 c2 12 01 00 00 	add    rdx,0x112
 105:	48 89 55 c8          	mov    QWORD PTR [rbp-0x38],rdx
 109:	48 89 fa             	mov    rdx,rdi
 10c:	48 81 c2 11 01 00 00 	add    rdx,0x111
 113:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 117:	48 89 fa             	mov    rdx,rdi
 11a:	48 81 c2 10 01 00 00 	add    rdx,0x110
 121:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 125:	31 c9                	xor    ecx,ecx
 127:	eb 0e                	jmp    0x137
 129:	48 83 c6 01          	add    rsi,0x1
 12d:	48 83 fe 10          	cmp    rsi,0x10
 131:	0f 84 5f 01 00 00    	je     0x296
 137:	49 89 c8             	mov    r8,rcx
 13a:	48 89 f1             	mov    rcx,rsi
 13d:	48 c1 e1 03          	shl    rcx,0x3
 141:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 145:	48 01 ca             	add    rdx,rcx
 148:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 14d:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
 151:	48 01 c8             	add    rax,rcx
 154:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 159:	48 c1 e0 08          	shl    rax,0x8
 15d:	48 09 d0             	or     rax,rdx
 160:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
 164:	48 01 ca             	add    rdx,rcx
 167:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 16c:	48 c1 e2 10          	shl    rdx,0x10
 170:	48 09 c2             	or     rdx,rax
 173:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
 177:	48 01 c8             	add    rax,rcx
 17a:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 17f:	48 c1 e0 18          	shl    rax,0x18
 183:	48 09 d0             	or     rax,rdx
 186:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 18a:	48 01 ca             	add    rdx,rcx
 18d:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 191:	48 01 cb             	add    rbx,rcx
 194:	4c 8b 6d e0          	mov    r13,QWORD PTR [rbp-0x20]
 198:	49 01 cd             	add    r13,rcx
 19b:	4c 8b 75 d8          	mov    r14,QWORD PTR [rbp-0x28]
 19f:	49 01 ce             	add    r14,rcx
 1a2:	49 0f b6 4e 00       	movzx  rcx,BYTE PTR [r14+0x0]
 1a7:	48 c1 e1 20          	shl    rcx,0x20
 1ab:	48 09 c1             	or     rcx,rax
 1ae:	49 0f b6 45 00       	movzx  rax,BYTE PTR [r13+0x0]
 1b3:	48 c1 e0 28          	shl    rax,0x28
 1b7:	48 09 c8             	or     rax,rcx
 1ba:	48 0f b6 5b 00       	movzx  rbx,BYTE PTR [rbx+0x0]
 1bf:	48 c1 e3 30          	shl    rbx,0x30
 1c3:	48 09 c3             	or     rbx,rax
 1c6:	48 0f b6 4a 00       	movzx  rcx,BYTE PTR [rdx+0x0]
 1cb:	48 c1 e1 38          	shl    rcx,0x38
 1cf:	48 09 d9             	or     rcx,rbx
 1d2:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 1d6:	31 c0                	xor    eax,eax
 1d8:	45 31 ed             	xor    r13d,r13d
 1db:	31 d2                	xor    edx,edx
 1dd:	eb 12                	jmp    0x1f1
 1df:	48 83 c3 08          	add    rbx,0x8
 1e3:	48 83 c0 01          	add    rax,0x1
 1e7:	48 83 f8 20          	cmp    rax,0x20
 1eb:	0f 84 8a 00 00 00    	je     0x27b
 1f1:	49 89 d6             	mov    r14,rdx
 1f4:	45 31 ff             	xor    r15d,r15d
 1f7:	ba 01 00 00 00       	mov    edx,0x1
 1fc:	4d 85 f6             	test   r14,r14
 1ff:	75 de                	jne    0x1df
 201:	48 0f b6 53 fd       	movzx  rdx,BYTE PTR [rbx-0x3]
 206:	48 c1 e2 20          	shl    rdx,0x20
 20a:	4c 0f b6 7b fb       	movzx  r15,BYTE PTR [rbx-0x5]
 20f:	49 c1 e7 10          	shl    r15,0x10
 213:	49 09 d7             	or     r15,rdx
 216:	48 0f b6 53 fc       	movzx  rdx,BYTE PTR [rbx-0x4]
 21b:	48 c1 e2 18          	shl    rdx,0x18
 21f:	4c 0f b6 73 fa       	movzx  r14,BYTE PTR [rbx-0x6]
 224:	49 c1 e6 08          	shl    r14,0x8
 228:	49 09 d6             	or     r14,rdx
 22b:	4d 09 fe             	or     r14,r15
 22e:	48 0f b6 53 fe       	movzx  rdx,BYTE PTR [rbx-0x2]
 233:	48 c1 e2 28          	shl    rdx,0x28
 237:	49 09 d6             	or     r14,rdx
 23a:	48 0f b6 53 00       	movzx  rdx,BYTE PTR [rbx+0x0]
 23f:	48 c1 e2 38          	shl    rdx,0x38
 243:	4c 0f b6 7b ff       	movzx  r15,BYTE PTR [rbx-0x1]
 248:	49 c1 e7 30          	shl    r15,0x30
 24c:	49 09 d7             	or     r15,rdx
 24f:	4d 09 fe             	or     r14,r15
 252:	48 0f b6 53 f9       	movzx  rdx,BYTE PTR [rbx-0x7]
 257:	49 09 d6             	or     r14,rdx
 25a:	31 d2                	xor    edx,edx
 25c:	41 bf 01 00 00 00    	mov    r15d,0x1
 262:	49 39 ce             	cmp    r14,rcx
 265:	0f 85 74 ff ff ff    	jne    0x1df
 26b:	45 31 ff             	xor    r15d,r15d
 26e:	ba 01 00 00 00       	mov    edx,0x1
 273:	49 89 c5             	mov    r13,rax
 276:	e9 64 ff ff ff       	jmp    0x1df
 27b:	48 83 c1 20          	add    rcx,0x20
 27f:	4c 31 c1             	xor    rcx,r8
 282:	45 85 ff             	test   r15d,r15d
 285:	0f 85 9e fe ff ff    	jne    0x129
 28b:	4d 01 c5             	add    r13,r8
 28e:	4c 89 e9             	mov    rcx,r13
 291:	e9 93 fe ff ff       	jmp    0x129
 296:	88 4f 00             	mov    BYTE PTR [rdi+0x0],cl
 299:	48 89 ce             	mov    rsi,rcx
 29c:	48 c1 ee 38          	shr    rsi,0x38
 2a0:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 2a4:	48 89 ce             	mov    rsi,rcx
 2a7:	48 c1 ee 30          	shr    rsi,0x30
 2ab:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 2af:	48 89 ce             	mov    rsi,rcx
 2b2:	48 c1 ee 28          	shr    rsi,0x28
 2b6:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 2ba:	48 89 ce             	mov    rsi,rcx
 2bd:	48 c1 ee 20          	shr    rsi,0x20
 2c1:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 2c5:	48 89 ce             	mov    rsi,rcx
 2c8:	48 c1 ee 18          	shr    rsi,0x18
 2cc:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 2d0:	48 89 ce             	mov    rsi,rcx
 2d3:	48 c1 ee 10          	shr    rsi,0x10
 2d7:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 2db:	48 c1 e9 08          	shr    rcx,0x8
 2df:	88 4f 01             	mov    BYTE PTR [rdi+0x1],cl
 2e2:	b8 02 00 00 00       	mov    eax,0x2
 2e7:	41 5f                	pop    r15
 2e9:	41 5e                	pop    r14
 2eb:	41 5d                	pop    r13
 2ed:	5b                   	pop    rbx
 2ee:	c9                   	leave
 2ef:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
