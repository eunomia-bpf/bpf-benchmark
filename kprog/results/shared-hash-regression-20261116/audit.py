"""Retained hash code and LRU caller audit; no runtime cost claim."""
import json
from pathlib import Path
import struct
import subprocess
import sys

ROOT=Path('/workspaces/repository')
raw=Path(sys.argv[1])
retained=Path('/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication')
revision='f45bb2485'
source='kprog/x86/native_lab/native_link/src/x86.rs'
def history(commit,path):
    return subprocess.check_output(['git','show',commit+':'+path],cwd=ROOT,text=True)
def function(text,name):
    start=text.index('fn '+name+'(')
    brace=text.index('{',start); depth=0
    for end in range(brace,len(text)):
        depth+=(text[end]=='{')-(text[end]=='}')
        if not depth:return text[start:end+1]
old=history(revision+'^',source); new=history(revision,source)
caller='build_x86_lookup_call_postprocess'
rows=[]
for app,index in [('katran',114),('otelcol-ebpf-profiler',130)]:
    base=retained/str(index)
    plan=json.loads((base/'0.link-plan.json').read_text())
    target=next(m['target_addr'] for m in plan['lookup_maps'] if m['kind']=='hash')
    relocs=list(struct.iter_unpack('<IIQ',(base/'0.relocs').read_bytes()))
    fallback=next(at for at,kind,address in relocs if kind==1 and address==target)
    blob=(base/'0.blob').read_bytes()
    # The retained copied routine ends in CALL raw; add rsp,8; RET. Its length
    # is the 2444 B removed in the corresponding eleven-program size delta.
    end=fallback+10; start=end-2444
    code=blob[start:end]
    assert code[-10:-5]==bytes([0xe8,0,0,0,0]) and code[-5:]==bytes.fromhex('4883c408c3')
    sites=[]
    for line in (base/'0.abi').read_text().splitlines():
        if line.startswith('load_site\t'):
            at,length,destination=map(int,line.split('\t')[1].split(','))
            if start<=at<end:sites.append([at-start,length,destination])
    (raw/(app+'.copied-hash.bin')).write_bytes(code)
    (raw/(app+'.copied-hash-sites.json')).write_text(json.dumps(sites,indent=2)+'\n')
    rows.append(dict(app=app,reference=str(base/'0.blob'),range=[start,end],bytes=len(code),
        fallback_offset=fallback-start,load_sites=len(sites),
        lru_maps=[m for m in plan['lookup_maps'] if m['kind']=='lru_hash'],
        explicit_ref_cmp_encodings=sum(blob.count(bytes.fromhex(s)) for s in ['80b82300000000','80782300']),
        explicit_ref_store_encodings=sum(blob.count(bytes.fromhex(s)) for s in ['c6802300000001','c6402301'])))
result=dict(scope=__doc__,source_revision=revision,
    lru_postprocess_text_equal=function(old,caller)==function(new,caller),
    native_postprocess_file=source,kernel_file='vendor/linux-framework/kernel/bpf/hashtab.c',
    kernel_observation='Raw __htab_map_lookup_elem returns htab_elem without ref marking; JIT generator and LRU map ops mark ref in their caller paths.',
    copied_bodies_equal=(raw/'katran.copied-hash.bin').read_bytes()==(raw/'otelcol-ebpf-profiler.copied-hash.bin').read_bytes(),
    programs=rows,
    conclusion='f45 preserves the native LRU caller sequence. Retained Katran has no explicit typed LRU ref sequence; its dynamic LRU lookups use generic map ops, which mark ref. Actual guest path/cost comparison remains required.')
(raw/'audit.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
