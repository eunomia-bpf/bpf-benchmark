# bpftrace_string_search_prefix_scan

## Original C
```c
#include "common.h"

#define BPFTRACE_HAYSTACK_SIZE 96U
#define BPFTRACE_NEEDLE_SIZE 8U
#define BPFTRACE_SCAN_LIMIT (BPFTRACE_HAYSTACK_SIZE - BPFTRACE_NEEDLE_SIZE + 1U)
#define BPFTRACE_STRING_INPUT_SIZE (8U + BPFTRACE_HAYSTACK_SIZE + BPFTRACE_NEEDLE_SIZE)

static __always_inline u32 bpftrace_bounded_strlen(const u8 *data, u32 base)
{
    u32 len = 0;

    for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
        if (data[base + index] == 0) {
            break;
        }
        len++;
    }
    return len;
}

static __always_inline int
bench_bpftrace_string_search_prefix_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BPFTRACE_STRING_INPUT_SIZE)) {
        return -1;
    }

    u32 haystack_len = micro_read_u32_le(data, 0U);
    u32 declared_needle_len = micro_read_u32_le(data, 4U);
    u32 needle_base = 8U + BPFTRACE_HAYSTACK_SIZE;
    u32 needle_len = bpftrace_bounded_strlen(data, needle_base);
    if (haystack_len > BPFTRACE_HAYSTACK_SIZE ||
        declared_needle_len != needle_len ||
        needle_len == 0U) {
        return -1;
    }

    u64 acc = 0xD1B54A32D192ED03ULL;
    u32 found = BPFTRACE_HAYSTACK_SIZE;
    for (u32 pos = 0; pos < BPFTRACE_SCAN_LIMIT; pos++) {
        u32 diff = 0;

        if (pos + needle_len > haystack_len) {
            continue;
        }
        for (u32 index = 0; index < BPFTRACE_NEEDLE_SIZE; index++) {
            if (index < needle_len) {
                diff |= (u32)data[8U + pos + index] ^ data[needle_base + index];
            }
        }
        if (diff == 0U) {
            found = pos;
            break;
        }
    }

    if (found != BPFTRACE_HAYSTACK_SIZE) {
        acc += (u64)(found + 1U) * (u64)(needle_len + 3U);
        acc ^= micro_rotl64(((u64)needle_len << 32U) | found, 3U);
    } else {
        acc ^= 0x9E3779B97F4A7C15ULL;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bpftrace_string_search_prefix_scan_xdp,
    bench_bpftrace_string_search_prefix_scan,
    bpftrace_string_search_prefix_scan_input_value,
    BPFTRACE_STRING_INPUT_SIZE)
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

0000000000001100 <bpftrace_string_search_prefix_scan_xdp>:
    1100:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    1103:	48 8b 57 08          	mov    rdx,QWORD PTR [rdi+0x8]
    1107:	31 c0                	xor    eax,eax
    1109:	48 39 d1             	cmp    rcx,rdx
    110c:	0f 87 b6 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    1112:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1116:	48 39 d6             	cmp    rsi,rdx
    1119:	0f 87 a9 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    111f:	48 8d 71 78          	lea    rsi,[rcx+0x78]
    1123:	48 39 d6             	cmp    rsi,rdx
    1126:	0f 87 9c 01 00 00    	ja     12c8 <bpftrace_string_search_prefix_scan_xdp+0x1c8>
    112c:	53                   	push   rbx
    112d:	8b 79 08             	mov    edi,DWORD PTR [rcx+0x8]
    1130:	0f b6 51 70          	movzx  edx,BYTE PTR [rcx+0x70]
    1134:	31 c0                	xor    eax,eax
    1136:	41 b8 00 00 00 00    	mov    r8d,0x0
    113c:	84 d2                	test   dl,dl
    113e:	74 62                	je     11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1140:	80 79 71 00          	cmp    BYTE PTR [rcx+0x71],0x0
    1144:	74 2e                	je     1174 <bpftrace_string_search_prefix_scan_xdp+0x74>
    1146:	80 79 72 00          	cmp    BYTE PTR [rcx+0x72],0x0
    114a:	74 30                	je     117c <bpftrace_string_search_prefix_scan_xdp+0x7c>
    114c:	80 79 73 00          	cmp    BYTE PTR [rcx+0x73],0x0
    1150:	74 32                	je     1184 <bpftrace_string_search_prefix_scan_xdp+0x84>
    1152:	80 79 74 00          	cmp    BYTE PTR [rcx+0x74],0x0
    1156:	74 34                	je     118c <bpftrace_string_search_prefix_scan_xdp+0x8c>
    1158:	80 79 75 00          	cmp    BYTE PTR [rcx+0x75],0x0
    115c:	74 36                	je     1194 <bpftrace_string_search_prefix_scan_xdp+0x94>
    115e:	80 79 76 00          	cmp    BYTE PTR [rcx+0x76],0x0
    1162:	74 38                	je     119c <bpftrace_string_search_prefix_scan_xdp+0x9c>
    1164:	80 79 77 01          	cmp    BYTE PTR [rcx+0x77],0x1
    1168:	41 b8 08 00 00 00    	mov    r8d,0x8
    116e:	41 83 d8 00          	sbb    r8d,0x0
    1172:	eb 2e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1174:	41 b8 01 00 00 00    	mov    r8d,0x1
    117a:	eb 26                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    117c:	41 b8 02 00 00 00    	mov    r8d,0x2
    1182:	eb 1e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1184:	41 b8 03 00 00 00    	mov    r8d,0x3
    118a:	eb 16                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    118c:	41 b8 04 00 00 00    	mov    r8d,0x4
    1192:	eb 0e                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    1194:	41 b8 05 00 00 00    	mov    r8d,0x5
    119a:	eb 06                	jmp    11a2 <bpftrace_string_search_prefix_scan_xdp+0xa2>
    119c:	41 b8 06 00 00 00    	mov    r8d,0x6
    11a2:	83 ff 60             	cmp    edi,0x60
    11a5:	0f 87 1c 01 00 00    	ja     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11ab:	8b 71 0c             	mov    esi,DWORD PTR [rcx+0xc]
    11ae:	44 39 c6             	cmp    esi,r8d
    11b1:	0f 85 10 01 00 00    	jne    12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11b7:	84 d2                	test   dl,dl
    11b9:	0f 84 08 01 00 00    	je     12c7 <bpftrace_string_search_prefix_scan_xdp+0x1c7>
    11bf:	48 b8 16 91 d8 ae 8b 	movabs rax,0x4f82338baed89116
    11c6:	33 82 4f 
    11c9:	41 89 f9             	mov    r9d,edi
    11cc:	44 8d 56 03          	lea    r10d,[rsi+0x3]
    11d0:	48 bf 03 ed 92 d1 32 	movabs rdi,0xd1b54a32d192ed03
    11d7:	4a b5 d1 
    11da:	4c 01 d7             	add    rdi,r10
    11dd:	45 31 c0             	xor    r8d,r8d
    11e0:	eb 27                	jmp    1209 <bpftrace_string_search_prefix_scan_xdp+0x109>
    11e2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nop WORD PTR [rax+rax*1+0x0]
    11e9:	1f 84 00 00 00 00 00 
    11f0:	45 84 db             	test   r11b,r11b
    11f3:	0f 84 af 00 00 00    	je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8>
    11f9:	49 ff c0             	inc    r8
    11fc:	4c 01 d7             	add    rdi,r10
    11ff:	49 83 f8 59          	cmp    r8,0x59
    1203:	0f 84 b6 00 00 00    	je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf>
    1209:	4e 8d 1c 06          	lea    r11,[rsi+r8*1]
    120d:	4d 39 cb             	cmp    r11,r9
    1210:	77 e7                	ja     11f9 <bpftrace_string_search_prefix_scan_xdp+0xf9>
    1212:	48 85 f6             	test   rsi,rsi
    1215:	0f 84 8d 00 00 00    	je     12a8 <bpftrace_string_search_prefix_scan_xdp+0x1a8>
    121b:	46 0f b6 5c 01 10    	movzx  r11d,BYTE PTR [rcx+r8*1+0x10]
    1221:	41 30 d3             	xor    r11b,dl
    1224:	83 fe 02             	cmp    esi,0x2
    1227:	72 c7                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1229:	0f b6 59 71          	movzx  ebx,BYTE PTR [rcx+0x71]
    122d:	42 32 5c 01 11       	xor    bl,BYTE PTR [rcx+r8*1+0x11]
    1232:	41 08 db             	or     r11b,bl
    1235:	83 fe 03             	cmp    esi,0x3
    1238:	72 b6                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    123a:	0f b6 59 72          	movzx  ebx,BYTE PTR [rcx+0x72]
    123e:	42 32 5c 01 12       	xor    bl,BYTE PTR [rcx+r8*1+0x12]
    1243:	41 08 db             	or     r11b,bl
    1246:	83 fe 04             	cmp    esi,0x4
    1249:	72 a5                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    124b:	0f b6 59 73          	movzx  ebx,BYTE PTR [rcx+0x73]
    124f:	42 32 5c 01 13       	xor    bl,BYTE PTR [rcx+r8*1+0x13]
    1254:	41 08 db             	or     r11b,bl
    1257:	83 fe 05             	cmp    esi,0x5
    125a:	72 94                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    125c:	0f b6 59 74          	movzx  ebx,BYTE PTR [rcx+0x74]
    1260:	42 32 5c 01 14       	xor    bl,BYTE PTR [rcx+r8*1+0x14]
    1265:	41 08 db             	or     r11b,bl
    1268:	83 fe 06             	cmp    esi,0x6
    126b:	72 83                	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    126d:	0f b6 59 75          	movzx  ebx,BYTE PTR [rcx+0x75]
    1271:	42 32 5c 01 15       	xor    bl,BYTE PTR [rcx+r8*1+0x15]
    1276:	41 08 db             	or     r11b,bl
    1279:	83 fe 07             	cmp    esi,0x7
    127c:	0f 82 6e ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1282:	0f b6 59 76          	movzx  ebx,BYTE PTR [rcx+0x76]
    1286:	42 32 5c 01 16       	xor    bl,BYTE PTR [rcx+r8*1+0x16]
    128b:	41 08 db             	or     r11b,bl
    128e:	83 fe 08             	cmp    esi,0x8
    1291:	0f 82 59 ff ff ff    	jb     11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    1297:	0f b6 59 77          	movzx  ebx,BYTE PTR [rcx+0x77]
    129b:	42 32 5c 01 17       	xor    bl,BYTE PTR [rcx+r8*1+0x17]
    12a0:	41 08 db             	or     r11b,bl
    12a3:	e9 48 ff ff ff       	jmp    11f0 <bpftrace_string_search_prefix_scan_xdp+0xf0>
    12a8:	49 83 f8 60          	cmp    r8,0x60
    12ac:	74 11                	je     12bf <bpftrace_string_search_prefix_scan_xdp+0x1bf>
    12ae:	48 c1 e6 20          	shl    rsi,0x20
    12b2:	4c 01 c6             	add    rsi,r8
    12b5:	48 c1 c6 03          	rol    rsi,0x3
    12b9:	48 31 f7             	xor    rdi,rsi
    12bc:	48 89 f8             	mov    rax,rdi
    12bf:	48 89 01             	mov    QWORD PTR [rcx],rax
    12c2:	b8 02 00 00 00       	mov    eax,0x2
    12c7:	5b                   	pop    rbx
    12c8:	c3                   	ret

Disassembly of section .fini:

00000000000012cc <_fini>:
    12cc:	f3 0f 1e fa          	endbr64
    12d0:	48 83 ec 08          	sub    rsp,0x8
    12d4:	48 83 c4 08          	add    rsp,0x8
    12d8:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec 10 00 00 00 	sub    rsp,0x10
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 f7             	cmp    rdi,rsi
  27:	0f 87 ce 02 00 00    	ja     0x2fb
  2d:	48 89 fa             	mov    rdx,rdi
  30:	48 83 c2 08          	add    rdx,0x8
  34:	48 39 f2             	cmp    rdx,rsi
  37:	0f 87 be 02 00 00    	ja     0x2fb
  3d:	48 89 fa             	mov    rdx,rdi
  40:	48 83 c2 78          	add    rdx,0x78
  44:	48 39 f2             	cmp    rdx,rsi
  47:	0f 87 ae 02 00 00    	ja     0x2fb
  4d:	48 0f b6 77 70       	movzx  rsi,BYTE PTR [rdi+0x70]
  52:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
  55:	85 f6                	test   esi,esi
  57:	0f 84 9e 02 00 00    	je     0x2fb
  5d:	48 0f b6 57 09       	movzx  rdx,BYTE PTR [rdi+0x9]
  62:	c1 e2 08             	shl    edx,0x8
  65:	48 0f b6 4f 08       	movzx  rcx,BYTE PTR [rdi+0x8]
  6a:	09 ca                	or     edx,ecx
  6c:	48 0f b6 4f 0a       	movzx  rcx,BYTE PTR [rdi+0xa]
  71:	c1 e1 10             	shl    ecx,0x10
  74:	09 ca                	or     edx,ecx
  76:	48 0f b6 4f 0b       	movzx  rcx,BYTE PTR [rdi+0xb]
  7b:	c1 e1 18             	shl    ecx,0x18
  7e:	09 ca                	or     edx,ecx
  80:	bb 01 00 00 00       	mov    ebx,0x1
  85:	48 0f b6 4f 71       	movzx  rcx,BYTE PTR [rdi+0x71]
  8a:	85 c9                	test   ecx,ecx
  8c:	74 59                	je     0xe7
  8e:	bb 02 00 00 00       	mov    ebx,0x2
  93:	48 0f b6 4f 72       	movzx  rcx,BYTE PTR [rdi+0x72]
  98:	85 c9                	test   ecx,ecx
  9a:	74 4b                	je     0xe7
  9c:	bb 03 00 00 00       	mov    ebx,0x3
  a1:	48 0f b6 4f 73       	movzx  rcx,BYTE PTR [rdi+0x73]
  a6:	85 c9                	test   ecx,ecx
  a8:	74 3d                	je     0xe7
  aa:	bb 04 00 00 00       	mov    ebx,0x4
  af:	48 0f b6 4f 74       	movzx  rcx,BYTE PTR [rdi+0x74]
  b4:	85 c9                	test   ecx,ecx
  b6:	74 2f                	je     0xe7
  b8:	bb 05 00 00 00       	mov    ebx,0x5
  bd:	48 0f b6 4f 75       	movzx  rcx,BYTE PTR [rdi+0x75]
  c2:	85 c9                	test   ecx,ecx
  c4:	74 21                	je     0xe7
  c6:	bb 06 00 00 00       	mov    ebx,0x6
  cb:	48 0f b6 4f 76       	movzx  rcx,BYTE PTR [rdi+0x76]
  d0:	85 c9                	test   ecx,ecx
  d2:	74 13                	je     0xe7
  d4:	bb 07 00 00 00       	mov    ebx,0x7
  d9:	48 0f b6 4f 77       	movzx  rcx,BYTE PTR [rdi+0x77]
  de:	85 c9                	test   ecx,ecx
  e0:	74 05                	je     0xe7
  e2:	bb 08 00 00 00       	mov    ebx,0x8
  e7:	83 fa 60             	cmp    edx,0x60
  ea:	0f 87 0b 02 00 00    	ja     0x2fb
  f0:	4c 0f b6 6f 0d       	movzx  r13,BYTE PTR [rdi+0xd]
  f5:	41 c1 e5 08          	shl    r13d,0x8
  f9:	4c 0f b6 77 0c       	movzx  r14,BYTE PTR [rdi+0xc]
  fe:	4c 0f b6 7f 0e       	movzx  r15,BYTE PTR [rdi+0xe]
 103:	44 89 e9             	mov    ecx,r13d
 106:	44 09 f1             	or     ecx,r14d
 109:	41 c1 e7 10          	shl    r15d,0x10
 10d:	4c 0f b6 47 0f       	movzx  r8,BYTE PTR [rdi+0xf]
 112:	44 09 f9             	or     ecx,r15d
 115:	41 c1 e0 18          	shl    r8d,0x18
 119:	44 09 c1             	or     ecx,r8d
 11c:	39 d9                	cmp    ecx,ebx
 11e:	0f 85 d7 01 00 00    	jne    0x2fb
 124:	8b 75 f8             	mov    esi,DWORD PTR [rbp-0x8]
 127:	85 f6                	test   esi,esi
 129:	0f 84 cc 01 00 00    	je     0x2fb
 12f:	45 01 f8             	add    r8d,r15d
 132:	45 01 e8             	add    r8d,r13d
 135:	45 01 f0             	add    r8d,r14d
 138:	31 db                	xor    ebx,ebx
 13a:	45 89 c5             	mov    r13d,r8d
 13d:	41 83 c5 03          	add    r13d,0x3
 141:	49 be 03 ed 92 d1 32 	movabs r14,0xd1b54a32d192ed03
 148:	4a b5 d1 
 14b:	4c 89 e8             	mov    rax,r13
 14e:	4c 01 f0             	add    rax,r14
 151:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 155:	eb 2b                	jmp    0x182
 157:	41 81 e6 ff 00 00 00 	and    r14d,0xff
 15e:	45 85 f6             	test   r14d,r14d
 161:	0f 84 16 01 00 00    	je     0x27d
 167:	4c 01 e8             	add    rax,r13
 16a:	49 be 16 91 d8 ae 8b 	movabs r14,0x4f82338baed89116
 171:	33 82 4f 
 174:	48 83 c3 01          	add    rbx,0x1
 178:	48 83 fb 59          	cmp    rbx,0x59
 17c:	0f 84 26 01 00 00    	je     0x2a8
 182:	4d 89 c6             	mov    r14,r8
 185:	49 01 de             	add    r14,rbx
 188:	49 39 d6             	cmp    r14,rdx
 18b:	77 da                	ja     0x167
 18d:	85 c9                	test   ecx,ecx
 18f:	0f 84 e8 00 00 00    	je     0x27d
 195:	49 89 ff             	mov    r15,rdi
 198:	49 01 df             	add    r15,rbx
 19b:	49 0f b6 77 10       	movzx  rsi,BYTE PTR [r15+0x10]
 1a0:	44 8b 75 f8          	mov    r14d,DWORD PTR [rbp-0x8]
 1a4:	41 31 f6             	xor    r14d,esi
 1a7:	83 f9 02             	cmp    ecx,0x2
 1aa:	72 ab                	jb     0x157
 1ac:	49 0f b6 77 11       	movzx  rsi,BYTE PTR [r15+0x11]
 1b1:	4c 0f b6 7f 71       	movzx  r15,BYTE PTR [rdi+0x71]
 1b6:	41 31 f7             	xor    r15d,esi
 1b9:	45 09 fe             	or     r14d,r15d
 1bc:	83 f9 03             	cmp    ecx,0x3
 1bf:	72 96                	jb     0x157
 1c1:	49 89 ff             	mov    r15,rdi
 1c4:	49 01 df             	add    r15,rbx
 1c7:	49 0f b6 77 12       	movzx  rsi,BYTE PTR [r15+0x12]
 1cc:	4c 0f b6 6f 72       	movzx  r13,BYTE PTR [rdi+0x72]
 1d1:	41 31 f5             	xor    r13d,esi
 1d4:	45 09 ee             	or     r14d,r13d
 1d7:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1db:	83 f9 04             	cmp    ecx,0x4
 1de:	0f 82 73 ff ff ff    	jb     0x157
 1e4:	49 0f b6 77 13       	movzx  rsi,BYTE PTR [r15+0x13]
 1e9:	4c 0f b6 6f 73       	movzx  r13,BYTE PTR [rdi+0x73]
 1ee:	41 31 f5             	xor    r13d,esi
 1f1:	45 09 ee             	or     r14d,r13d
 1f4:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 1f8:	83 f9 05             	cmp    ecx,0x5
 1fb:	0f 82 56 ff ff ff    	jb     0x157
 201:	49 89 ff             	mov    r15,rdi
 204:	49 01 df             	add    r15,rbx
 207:	49 0f b6 77 14       	movzx  rsi,BYTE PTR [r15+0x14]
 20c:	4c 0f b6 6f 74       	movzx  r13,BYTE PTR [rdi+0x74]
 211:	41 31 f5             	xor    r13d,esi
 214:	45 09 ee             	or     r14d,r13d
 217:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 21b:	83 f9 06             	cmp    ecx,0x6
 21e:	0f 82 33 ff ff ff    	jb     0x157
 224:	49 0f b6 77 15       	movzx  rsi,BYTE PTR [r15+0x15]
 229:	4c 0f b6 6f 75       	movzx  r13,BYTE PTR [rdi+0x75]
 22e:	41 31 f5             	xor    r13d,esi
 231:	45 09 ee             	or     r14d,r13d
 234:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 238:	83 f9 07             	cmp    ecx,0x7
 23b:	0f 82 16 ff ff ff    	jb     0x157
 241:	49 89 ff             	mov    r15,rdi
 244:	49 01 df             	add    r15,rbx
 247:	49 0f b6 77 16       	movzx  rsi,BYTE PTR [r15+0x16]
 24c:	4c 0f b6 6f 76       	movzx  r13,BYTE PTR [rdi+0x76]
 251:	41 31 f5             	xor    r13d,esi
 254:	45 09 ee             	or     r14d,r13d
 257:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 25b:	83 f9 08             	cmp    ecx,0x8
 25e:	0f 82 f3 fe ff ff    	jb     0x157
 264:	49 0f b6 77 17       	movzx  rsi,BYTE PTR [r15+0x17]
 269:	4c 0f b6 6f 77       	movzx  r13,BYTE PTR [rdi+0x77]
 26e:	41 31 f5             	xor    r13d,esi
 271:	45 09 ee             	or     r14d,r13d
 274:	4c 8b 6d f0          	mov    r13,QWORD PTR [rbp-0x10]
 278:	e9 da fe ff ff       	jmp    0x157
 27d:	49 be 16 91 d8 ae 8b 	movabs r14,0x4f82338baed89116
 284:	33 82 4f 
 287:	48 83 fb 60          	cmp    rbx,0x60
 28b:	74 1b                	je     0x2a8
 28d:	48 c1 e1 20          	shl    rcx,0x20
 291:	48 01 d9             	add    rcx,rbx
 294:	48 89 ce             	mov    rsi,rcx
 297:	48 c1 ee 3d          	shr    rsi,0x3d
 29b:	48 c1 e1 03          	shl    rcx,0x3
 29f:	48 09 f1             	or     rcx,rsi
 2a2:	48 31 c8             	xor    rax,rcx
 2a5:	49 89 c6             	mov    r14,rax
 2a8:	44 88 77 00          	mov    BYTE PTR [rdi+0x0],r14b
 2ac:	4c 89 f6             	mov    rsi,r14
 2af:	48 c1 ee 38          	shr    rsi,0x38
 2b3:	40 88 77 07          	mov    BYTE PTR [rdi+0x7],sil
 2b7:	4c 89 f6             	mov    rsi,r14
 2ba:	48 c1 ee 30          	shr    rsi,0x30
 2be:	40 88 77 06          	mov    BYTE PTR [rdi+0x6],sil
 2c2:	4c 89 f6             	mov    rsi,r14
 2c5:	48 c1 ee 28          	shr    rsi,0x28
 2c9:	40 88 77 05          	mov    BYTE PTR [rdi+0x5],sil
 2cd:	4c 89 f6             	mov    rsi,r14
 2d0:	48 c1 ee 20          	shr    rsi,0x20
 2d4:	40 88 77 04          	mov    BYTE PTR [rdi+0x4],sil
 2d8:	4c 89 f6             	mov    rsi,r14
 2db:	48 c1 ee 18          	shr    rsi,0x18
 2df:	40 88 77 03          	mov    BYTE PTR [rdi+0x3],sil
 2e3:	4c 89 f6             	mov    rsi,r14
 2e6:	48 c1 ee 10          	shr    rsi,0x10
 2ea:	40 88 77 02          	mov    BYTE PTR [rdi+0x2],sil
 2ee:	49 c1 ee 08          	shr    r14,0x8
 2f2:	44 88 77 01          	mov    BYTE PTR [rdi+0x1],r14b
 2f6:	b8 02 00 00 00       	mov    eax,0x2
 2fb:	41 5f                	pop    r15
 2fd:	41 5e                	pop    r14
 2ff:	41 5d                	pop    r13
 301:	5b                   	pop    rbx
 302:	c9                   	leave
 303:	c3                   	ret
```

## llvmbpf JIT ASM
```asm
not captured
```
