"""Test full-width verifier-visible tag slots on every real BCC entry."""
import json
from pathlib import Path
import shutil
import sys
import coverage

phase=Path(sys.argv[1]).resolve();phase.mkdir()
original=phase.parent/'bcc-real-entries-v9'
for name in ['native','sources','simulator','formal']:
    shutil.copytree(original/name,phase/name)
rows=coverage.records(original)
for row in rows:
    row['source']=str(phase/'sources'/Path(row['source']).name)
    row['proof']=str(phase/'native'/Path(row['proof']).name)
(phase/'programs.jsonl').write_text(''.join(json.dumps(row)+'\n' for row in rows))
shutil.copy2(original/'pairing.json',phase/'pairing-original.json')
p=phase/'simulator/arm64_sim_local_bpf.h';text=p.read_text()
needle='__u8 __a64_stack_tag['
if text.count(needle)!=2: raise RuntimeError('both stack declarations must be present')
variant=sys.argv[2] if len(sys.argv)>2 else 'word'
if variant=='word':
    text=text.replace(needle,'__u64 __a64_stack_tag[')
elif variant=='packed':
    import re
    text=re.sub(r'__u8 __a64_stack_tag\[(.*?)\] = \{\};',
        r'__u8 __a64_stack_tag[((\1)+7U)&~7U] __attribute__((aligned(8))) = {};',text)
    token='__a64_stack_tag['
    # Convert semantic tag reads/writes, preserving every packed byte value.
    cursor=0
    while True:
        start=text.find(token,cursor)
        if start<0: break
        if text[max(0,start-5):start].endswith('__u8 '):
            cursor=start+len(token);continue
        end=text.index(']',start)
        index=text[start+len(token):end]
        after=end+1
        while after<len(text) and text[after] in ' \t\r\n\\':after+=1
        if text[after]=='=':
            stop=text.index(';',after)
            value=text[after+1:stop].strip()
            text=text[:start]+f'ARM64_SIM_L_TAG_SET({index}, ({value}))'+text[stop:]
            cursor=start+len('ARM64_SIM_L_TAG_SET(')
        else:
            replacement=f'ARM64_SIM_L_TAG_GET({index})'
            text=text[:start]+replacement+text[end+1:];cursor=start+len(replacement)
    marker='#ifdef ARM64_SIM_ENABLE_STACK'
    at=text.index(marker)
    helpers=r"""
typedef __u64 arm64_sim_tag_word __attribute__((may_alias));
#define ARM64_SIM_L_TAG_WORD_PTR(INDEX) ((volatile arm64_sim_tag_word *)(void *)&__a64_stack_tag[(__u32)(INDEX)&~7U])
#define ARM64_SIM_L_TAG_GET(INDEX) ({ __u32 __ti=(INDEX); (__u8)(*ARM64_SIM_L_TAG_WORD_PTR(__ti) >> ((__ti&7U)*8U)); })
#define ARM64_SIM_L_TAG_SET(INDEX, TAG) do { __u32 __ti=(INDEX); __u32 __ts=(__ti&7U)*8U; volatile arm64_sim_tag_word *__tp=ARM64_SIM_L_TAG_WORD_PTR(__ti); __u64 __tv=*__tp; *__tp=(__tv&~(255ULL<<__ts))|((__u64)(__u8)(TAG)<<__ts); } while (0)
"""
    text=text[:at]+helpers+text[at:]
    production=(coverage.ROOT/'kprog/arm64/arm64_sim_local_bpf.h').read_text()
    begin='#define ARM64_SIM_L_HELPER_ARG_PTR(REG)';end='#define ARM64_SIM_L_STORE_Q0_STACK'
    text=text[:text.index(begin)]+production[production.index(begin):production.index(end)]+text[text.index(end):]
    # A raw context is distinct from the generated XDP0/SKB1 projections.
    at=text.index('#define ARM64_SIM_ENTRY_RAW(');end=text.index('#define ARM64_SIM_L_READ_REG(',at)
    text=text[:at]+text[at:end].replace('__a64_sim_abi_kind = 0;','__a64_sim_abi_kind = 2;')+text[end:]
    text=text.replace('__a64_mrt_value_tag = KPROG_ABI_LOAD_TAG(',
        '__a64_mrt_value_tag = __a64_sim_abi_kind == 2 ? ARM64_SIM_TAG_ABI : KPROG_ABI_LOAD_TAG(')
else:
    raise ValueError(variant)
p.write_text(text)
print(f'same23 real BCC entries; shadow tag slot storage variant={variant}')
