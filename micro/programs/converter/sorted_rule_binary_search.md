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
    1040:	48 8d 3d c9 2f 00 00 	lea    rdi,[rip+0x2fc9]        # 4010 <__TMC_END__>
    1047:	48 8d 05 c2 2f 00 00 	lea    rax,[rip+0x2fc2]        # 4010 <__TMC_END__>
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
    1070:	48 8d 3d 99 2f 00 00 	lea    rdi,[rip+0x2f99]        # 4010 <__TMC_END__>
    1077:	48 8d 35 92 2f 00 00 	lea    rsi,[rip+0x2f92]        # 4010 <__TMC_END__>
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
    10b4:	80 3d 51 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f51],0x0        # 400c <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 29 2f 00 00 01 	mov    BYTE PTR [rip+0x2f29],0x1        # 400c <completed.0>
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
  20:	48 8b 57 00          	mov    rdx,QWORD PTR [rdi+0x0]
  24:	48 39 f2             	cmp    rdx,rsi
  27:	0f 87 dc 02 00 00    	ja     0x309
  2d:	48 89 d7             	mov    rdi,rdx
  30:	48 83 c7 08          	add    rdi,0x8
  34:	48 39 f7             	cmp    rdi,rsi
  37:	0f 87 cc 02 00 00    	ja     0x309
  3d:	48 89 d7             	mov    rdi,rdx
  40:	48 81 c7 90 01 00 00 	add    rdi,0x190
  47:	48 39 f7             	cmp    rdi,rsi
  4a:	0f 87 b9 02 00 00    	ja     0x309
  50:	48 0f b6 7a 09       	movzx  rdi,BYTE PTR [rdx+0x9]
  55:	48 c1 e7 08          	shl    rdi,0x8
  59:	48 0f b6 72 08       	movzx  rsi,BYTE PTR [rdx+0x8]
  5e:	48 09 f7             	or     rdi,rsi
  61:	48 0f b6 72 0a       	movzx  rsi,BYTE PTR [rdx+0xa]
  66:	48 c1 e6 10          	shl    rsi,0x10
  6a:	48 09 f7             	or     rdi,rsi
  6d:	48 0f b6 72 0b       	movzx  rsi,BYTE PTR [rdx+0xb]
  72:	48 c1 e6 18          	shl    rsi,0x18
  76:	48 09 f7             	or     rdi,rsi
  79:	48 c1 e7 20          	shl    rdi,0x20
  7d:	48 c1 ef 20          	shr    rdi,0x20
  81:	48 83 ff 20          	cmp    rdi,0x20
  85:	0f 85 7e 02 00 00    	jne    0x309
  8b:	48 0f b6 7a 0d       	movzx  rdi,BYTE PTR [rdx+0xd]
  90:	48 c1 e7 08          	shl    rdi,0x8
  94:	48 0f b6 72 0c       	movzx  rsi,BYTE PTR [rdx+0xc]
  99:	48 09 f7             	or     rdi,rsi
  9c:	48 0f b6 72 0e       	movzx  rsi,BYTE PTR [rdx+0xe]
  a1:	48 c1 e6 10          	shl    rsi,0x10
  a5:	48 09 f7             	or     rdi,rsi
  a8:	48 0f b6 72 0f       	movzx  rsi,BYTE PTR [rdx+0xf]
  ad:	48 c1 e6 18          	shl    rsi,0x18
  b1:	48 09 f7             	or     rdi,rsi
  b4:	48 c1 e7 20          	shl    rdi,0x20
  b8:	48 c1 ef 20          	shr    rdi,0x20
  bc:	48 83 ff 10          	cmp    rdi,0x10
  c0:	0f 85 43 02 00 00    	jne    0x309
  c6:	31 f6                	xor    esi,esi
  c8:	48 89 d7             	mov    rdi,rdx
  cb:	48 83 c7 17          	add    rdi,0x17
  cf:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
  d3:	48 89 d7             	mov    rdi,rdx
  d6:	48 81 c7 17 01 00 00 	add    rdi,0x117
  dd:	48 89 7d f0          	mov    QWORD PTR [rbp-0x10],rdi
  e1:	48 89 d7             	mov    rdi,rdx
  e4:	48 81 c7 16 01 00 00 	add    rdi,0x116
  eb:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  ef:	48 89 d7             	mov    rdi,rdx
  f2:	48 81 c7 15 01 00 00 	add    rdi,0x115
  f9:	48 89 7d e0          	mov    QWORD PTR [rbp-0x20],rdi
  fd:	48 89 d7             	mov    rdi,rdx
 100:	48 81 c7 14 01 00 00 	add    rdi,0x114
 107:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
 10b:	48 89 d7             	mov    rdi,rdx
 10e:	48 81 c7 13 01 00 00 	add    rdi,0x113
 115:	48 89 7d d0          	mov    QWORD PTR [rbp-0x30],rdi
 119:	48 89 d7             	mov    rdi,rdx
 11c:	48 81 c7 12 01 00 00 	add    rdi,0x112
 123:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
 127:	48 89 d7             	mov    rdi,rdx
 12a:	48 81 c7 11 01 00 00 	add    rdi,0x111
 131:	48 89 7d c0          	mov    QWORD PTR [rbp-0x40],rdi
 135:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 139:	48 89 d7             	mov    rdi,rdx
 13c:	48 81 c7 10 01 00 00 	add    rdi,0x110
 143:	31 c9                	xor    ecx,ecx
 145:	eb 0e                	jmp    0x155
 147:	48 83 c6 01          	add    rsi,0x1
 14b:	48 83 fe 10          	cmp    rsi,0x10
 14f:	0f 84 5f 01 00 00    	je     0x2b4
 155:	49 89 c8             	mov    r8,rcx
 158:	48 89 f1             	mov    rcx,rsi
 15b:	48 c1 e1 03          	shl    rcx,0x3
 15f:	48 89 fa             	mov    rdx,rdi
 162:	48 01 ca             	add    rdx,rcx
 165:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 16a:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
 16e:	48 01 c8             	add    rax,rcx
 171:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 176:	48 c1 e0 08          	shl    rax,0x8
 17a:	48 09 d0             	or     rax,rdx
 17d:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
 181:	48 01 ca             	add    rdx,rcx
 184:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 189:	48 c1 e2 10          	shl    rdx,0x10
 18d:	48 09 c2             	or     rdx,rax
 190:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
 194:	48 01 c8             	add    rax,rcx
 197:	48 0f b6 40 00       	movzx  rax,BYTE PTR [rax+0x0]
 19c:	48 c1 e0 18          	shl    rax,0x18
 1a0:	48 09 d0             	or     rax,rdx
 1a3:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
 1a7:	48 01 ca             	add    rdx,rcx
 1aa:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
 1af:	48 c1 e2 20          	shl    rdx,0x20
 1b3:	48 09 c2             	or     rdx,rax
 1b6:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 1ba:	48 01 c8             	add    rax,rcx
 1bd:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 1c1:	48 01 cb             	add    rbx,rcx
 1c4:	4c 8b 6d e0          	mov    r13,QWORD PTR [rbp-0x20]
 1c8:	49 01 cd             	add    r13,rcx
 1cb:	49 0f b6 4d 00       	movzx  rcx,BYTE PTR [r13+0x0]
 1d0:	48 c1 e1 28          	shl    rcx,0x28
 1d4:	48 09 d1             	or     rcx,rdx
 1d7:	48 0f b6 53 00       	movzx  rdx,BYTE PTR [rbx+0x0]
 1dc:	48 c1 e2 30          	shl    rdx,0x30
 1e0:	48 09 ca             	or     rdx,rcx
 1e3:	48 0f b6 48 00       	movzx  rcx,BYTE PTR [rax+0x0]
 1e8:	48 c1 e1 38          	shl    rcx,0x38
 1ec:	48 09 d1             	or     rcx,rdx
 1ef:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 1f3:	31 c0                	xor    eax,eax
 1f5:	45 31 ed             	xor    r13d,r13d
 1f8:	45 31 f6             	xor    r14d,r14d
 1fb:	eb 12                	jmp    0x20f
 1fd:	48 83 c3 08          	add    rbx,0x8
 201:	48 83 c0 01          	add    rax,0x1
 205:	48 83 f8 20          	cmp    rax,0x20
 209:	0f 84 8a 00 00 00    	je     0x299
 20f:	4d 89 f7             	mov    r15,r14
 212:	41 be 01 00 00 00    	mov    r14d,0x1
 218:	31 d2                	xor    edx,edx
 21a:	4d 85 ff             	test   r15,r15
 21d:	75 de                	jne    0x1fd
 21f:	48 0f b6 53 fd       	movzx  rdx,BYTE PTR [rbx-0x3]
 224:	48 c1 e2 20          	shl    rdx,0x20
 228:	4c 0f b6 73 fb       	movzx  r14,BYTE PTR [rbx-0x5]
 22d:	49 c1 e6 10          	shl    r14,0x10
 231:	49 09 d6             	or     r14,rdx
 234:	48 0f b6 53 fc       	movzx  rdx,BYTE PTR [rbx-0x4]
 239:	48 c1 e2 18          	shl    rdx,0x18
 23d:	4c 0f b6 7b fa       	movzx  r15,BYTE PTR [rbx-0x6]
 242:	49 c1 e7 08          	shl    r15,0x8
 246:	49 09 d7             	or     r15,rdx
 249:	4d 09 f7             	or     r15,r14
 24c:	48 0f b6 53 fe       	movzx  rdx,BYTE PTR [rbx-0x2]
 251:	48 c1 e2 28          	shl    rdx,0x28
 255:	49 09 d7             	or     r15,rdx
 258:	48 0f b6 53 00       	movzx  rdx,BYTE PTR [rbx+0x0]
 25d:	48 c1 e2 38          	shl    rdx,0x38
 261:	4c 0f b6 73 ff       	movzx  r14,BYTE PTR [rbx-0x1]
 266:	49 c1 e6 30          	shl    r14,0x30
 26a:	49 09 d6             	or     r14,rdx
 26d:	4d 09 f7             	or     r15,r14
 270:	48 0f b6 53 f9       	movzx  rdx,BYTE PTR [rbx-0x7]
 275:	49 09 d7             	or     r15,rdx
 278:	45 31 f6             	xor    r14d,r14d
 27b:	ba 01 00 00 00       	mov    edx,0x1
 280:	49 39 cf             	cmp    r15,rcx
 283:	0f 85 74 ff ff ff    	jne    0x1fd
 289:	41 be 01 00 00 00    	mov    r14d,0x1
 28f:	31 d2                	xor    edx,edx
 291:	49 89 c5             	mov    r13,rax
 294:	e9 64 ff ff ff       	jmp    0x1fd
 299:	48 83 c1 20          	add    rcx,0x20
 29d:	4c 31 c1             	xor    rcx,r8
 2a0:	48 85 d2             	test   rdx,rdx
 2a3:	0f 85 9e fe ff ff    	jne    0x147
 2a9:	4d 01 c5             	add    r13,r8
 2ac:	4c 89 e9             	mov    rcx,r13
 2af:	e9 93 fe ff ff       	jmp    0x147
 2b4:	48 89 cf             	mov    rdi,rcx
 2b7:	48 c1 ef 38          	shr    rdi,0x38
 2bb:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
 2bf:	40 88 7e 07          	mov    BYTE PTR [rsi+0x7],dil
 2c3:	48 89 cf             	mov    rdi,rcx
 2c6:	48 c1 ef 30          	shr    rdi,0x30
 2ca:	40 88 7e 06          	mov    BYTE PTR [rsi+0x6],dil
 2ce:	48 89 cf             	mov    rdi,rcx
 2d1:	48 c1 ef 28          	shr    rdi,0x28
 2d5:	40 88 7e 05          	mov    BYTE PTR [rsi+0x5],dil
 2d9:	48 89 cf             	mov    rdi,rcx
 2dc:	48 c1 ef 20          	shr    rdi,0x20
 2e0:	40 88 7e 04          	mov    BYTE PTR [rsi+0x4],dil
 2e4:	48 89 cf             	mov    rdi,rcx
 2e7:	48 c1 ef 18          	shr    rdi,0x18
 2eb:	40 88 7e 03          	mov    BYTE PTR [rsi+0x3],dil
 2ef:	48 89 cf             	mov    rdi,rcx
 2f2:	48 c1 ef 10          	shr    rdi,0x10
 2f6:	40 88 7e 02          	mov    BYTE PTR [rsi+0x2],dil
 2fa:	88 4e 00             	mov    BYTE PTR [rsi+0x0],cl
 2fd:	48 c1 e9 08          	shr    rcx,0x8
 301:	88 4e 01             	mov    BYTE PTR [rsi+0x1],cl
 304:	b8 02 00 00 00       	mov    eax,0x2
 309:	41 5f                	pop    r15
 30b:	41 5e                	pop    r14
 30d:	41 5d                	pop    r13
 30f:	5b                   	pop    rbx
 310:	c9                   	leave
 311:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   6:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   9:	31 c0                	xor    eax,eax
   b:	39 d1                	cmp    ecx,edx
   d:	0f 87 b5 00 00 00    	ja     0xc8
  13:	48 8d 71 08          	lea    rsi,[rcx+0x8]
  17:	48 39 d6             	cmp    rsi,rdx
  1a:	0f 87 a8 00 00 00    	ja     0xc8
  20:	48 8d b1 90 01 00 00 	lea    rsi,[rcx+0x190]
  27:	48 39 d6             	cmp    rsi,rdx
  2a:	0f 87 98 00 00 00    	ja     0xc8
  30:	83 79 08 20          	cmp    DWORD PTR [rcx+0x8],0x20
  34:	0f 85 80 00 00 00    	jne    0xba
  3a:	83 79 0c 10          	cmp    DWORD PTR [rcx+0xc],0x10
  3e:	75 7a                	jne    0xba
  40:	41 56                	push   r14
  42:	53                   	push   rbx
  43:	48 8d 51 17          	lea    rdx,[rcx+0x17]
  47:	31 c0                	xor    eax,eax
  49:	31 f6                	xor    esi,esi
  4b:	eb 1d                	jmp    0x6a
  4d:	0f 1f 00             	nop    DWORD PTR [rax]
  50:	48 83 c7 20          	add    rdi,0x20
  54:	48 31 c7             	xor    rdi,rax
  57:	4c 01 c0             	add    rax,r8
  5a:	45 84 db             	test   r11b,r11b
  5d:	48 0f 44 c7          	cmove  rax,rdi
  61:	48 ff c6             	inc    rsi
  64:	48 83 fe 10          	cmp    rsi,0x10
  68:	74 53                	je     0xbd
  6a:	48 8b bc f1 10 01 00 	mov    rdi,QWORD PTR [rcx+rsi*8+0x110]
  71:	00 
  72:	49 89 d1             	mov    r9,rdx
  75:	45 31 c0             	xor    r8d,r8d
  78:	31 db                	xor    ebx,ebx
  7a:	45 31 d2             	xor    r10d,r10d
  7d:	eb 1e                	jmp    0x9d
  7f:	4d 89 d0             	mov    r8,r10
  82:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
  89:	1f 84 00 00 00 00 00 
  90:	49 83 c1 08          	add    r9,0x8
  94:	49 ff c2             	inc    r10
  97:	49 83 fa 20          	cmp    r10,0x20
  9b:	74 b3                	je     0x50
  9d:	49 89 de             	mov    r14,rbx
  a0:	bb 01 00 00 00       	mov    ebx,0x1
  a5:	41 b3 01             	mov    r11b,0x1
  a8:	4d 85 f6             	test   r14,r14
  ab:	75 e3                	jne    0x90
  ad:	49 39 79 f9          	cmp    QWORD PTR [r9-0x7],rdi
  b1:	74 cc                	je     0x7f
  b3:	45 31 db             	xor    r11d,r11d
  b6:	31 db                	xor    ebx,ebx
  b8:	eb d6                	jmp    0x90
  ba:	31 c0                	xor    eax,eax
  bc:	c3                   	ret
  bd:	48 89 01             	mov    QWORD PTR [rcx],rax
  c0:	b8 02 00 00 00       	mov    eax,0x2
  c5:	5b                   	pop    rbx
  c6:	41 5e                	pop    r14
  c8:	c3                   	ret
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))
#define HC_LEA_ARCH_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    (HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) | (1ULL << 48))

static const struct bpf_insn program[] = {
    HC_INIT_X86_STACK(),
    HC_MOV64_IMM(BPF_REG_6, 0),
    HC_MOV64_IMM(BPF_REG_7, 0),
    HC_MOV64_IMM(BPF_REG_8, 0),
    HC_MOV64_IMM(BPF_REG_9, 0),
    /* 0x1100: mov    rcx,QWORD PTR [rdi] [context-abi: native xdp_md 64-bit field at off 0 maps to BPF XDP u32 ctx field at off 0] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 0),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RCX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1103: mov    rdx,QWORD PTR [rdi+0x8] [context-abi: native xdp_md 64-bit field at off 8 maps to BPF XDP u32 ctx field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    HC_KINSN(HC_X86_BPF_TO_ARCH_RR_PAYLOAD(HC_X86_RDX, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1107: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1109: cmp    rcx,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x110c: jbe    110f <sorted_rule_binary_search_xdp+0xf> [exact-bpf: jbe as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JLE | BPF_X, BPF_REG_6, BPF_REG_7, (4) - 1, 0),
    /* 0x110e: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
    /* 0x110f: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1113: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1116: ja     110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-9) - 1, 0),
    /* 0x1118: lea    rsi,[rcx+0x190] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_ARCH_PAYLOAD(HC_X86_RSI, HC_X86_RCX, 0, 0, 1, 0, 400), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x111f: cmp    rsi,rdx [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1122: ja     110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: ja as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_7, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JGT | BPF_X, BPF_REG_6, BPF_REG_7, (-16) - 1, 0),
    /* 0x1124: cmp    DWORD PTR [rcx+0x8],0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1128: jne    110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 8),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 32),
    /* 0x112a: cmp    DWORD PTR [rcx+0xc],0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x112e: jne    110e <sorted_rule_binary_search_xdp+0xe> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RCX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_6, 12),
    HC_RAW(BPF_JMP32 | BPF_JNE | BPF_K, BPF_REG_6, 0, (-24) - 1, 16),
    /* 0x1130: push   rbp [exact-kinsn: pushq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_PUSHQ),
    /* 0x1131: mov    rbp,rsp [exact-kinsn: movq frame-register kinsn] */
    HC_KINSN(HC_X86_FRAME_PAYLOAD(HC_X86_RBP, HC_X86_RSP), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1134: xor    eax,eax [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RAX, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1136: xor    edx,edx [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1138: nop    DWORD PTR [rax+rax*1+0x0] [padding: padding is not part of BPF semantics] */
    /* 0x1140: mov    rsi,QWORD PTR [rcx+rax*8+0x110] [exact-kinsn: indexed memory load via x86 SIB kinsn] */
    HC_KINSN(HC_X86_ARCH_SIB_PAYLOAD(HC_X86_RSI, HC_X86_RCX, HC_X86_RAX, 3, 272), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1148: xor    r8d,r8d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R8, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114b: xor    edi,edi [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x114d: xor    r9d,r9d [exact-kinsn: xor32 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R9, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_XORL),
    /* 0x1150: mov    r10d,r9d [exact-kinsn: mov32 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R10, HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x1153: mov    r11,rdi [exact-kinsn: mov64 register-to-register kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_R11, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1156: cmp    QWORD PTR [rcx+r8*8+0x10],rsi [exact-kinsn: cmpq SIB memory-source kinsn] */
    HC_KINSN(HC_X86_CMP_SIB_RR_PAYLOAD(HC_X86_RCX, HC_X86_R8, 3, 16, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_CMPQ),
    /* 0x115b: sete   r9b [exact-kinsn: setcc kinsn using module shadow flags] */
    HC_KINSN(HC_SETCC_STACK_PAYLOAD(HC_X86_R9), MICRO_HANDCRAFT_BPF_X86_SETE),
    /* 0x115f: cmove  rdi,r8 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_RDI, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_CMOVEQ),
    /* 0x1163: or     r9b,r10b [exact-kinsn: orb reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(HC_X86_R9, HC_X86_R10), MICRO_HANDCRAFT_BPF_X86_ORB),
    /* 0x1166: test   r10b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R10, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x116a: cmovne rdi,r11 [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_RDI, HC_X86_R11), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x116e: inc    r8 [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x1171: cmp    r8,0x20 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1175: jne    1150 <sorted_rule_binary_search_xdp+0x50> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_R8), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-20) - 1, 32),
    /* 0x1177: add    rdi,rdx [exact-kinsn: add64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDI, HC_X86_RDX), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117a: add    rsi,0x20 [exact-kinsn: add64 imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RSI, 32), MICRO_HANDCRAFT_BPF_X86_ADDQ),
    /* 0x117e: xor    rdx,rsi [exact-kinsn: xor64 reg kinsn] */
    HC_KINSN(HC_X86_ARCH_RR_PAYLOAD(HC_X86_RDX, HC_X86_RSI), MICRO_HANDCRAFT_BPF_X86_XORQ),
    /* 0x1181: test   r9b,0x1 [exact-kinsn: testb imm kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_R9, 1), MICRO_HANDCRAFT_BPF_X86_TESTB),
    /* 0x1185: cmovne rdx,rdi [exact-kinsn: cmov kinsn using module shadow flags] */
    HC_KINSN(HC_CMOV_ARCH_STACK_PAYLOAD(HC_X86_RDX, HC_X86_RDI), MICRO_HANDCRAFT_BPF_X86_CMOVNEQ),
    /* 0x1189: inc    rax [exact-kinsn: incq reg kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x118c: cmp    rax,0x10 [control-flow-operand: cmp folded into BPF branch] */
    /* 0x1190: jne    1140 <sorted_rule_binary_search_xdp+0x40> [exact-bpf: jne as ordinary BPF branch] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_6, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_6, 0, (-43) - 1, 16),
    /* 0x1192: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_X86_ARCH_STORE_PAYLOAD(HC_X86_RDX, HC_X86_RCX, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    /* 0x1195: mov    eax,0x2 [exact-kinsn: mov32 immediate kinsn] */
    HC_KINSN(HC_X86_ARCH_IMM_PAYLOAD(HC_X86_RAX, 2), MICRO_HANDCRAFT_BPF_X86_MOVL),
    /* 0x119a: pop    rbp [exact-kinsn: popq kinsn] */
    HC_KINSN(HC_REG_PAYLOAD(HC_X86_RBP), MICRO_HANDCRAFT_BPF_X86_POPQ),
    /* 0x119b: ret [abi-boundary: native ret materializes x86 rax to BPF r0 then exits] */
    HC_KINSN(HC_X86_ARCH_TO_BPF_RR_PAYLOAD(BPF_REG_0, HC_X86_RAX), MICRO_HANDCRAFT_BPF_X86_MOVQ),
    HC_EXIT(),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
