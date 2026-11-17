#!/usr/bin/env python3
"""Attribute tail-stub and outer source-instruction width changes from retained emissions."""
from collections import Counter,defaultdict
import json
from pathlib import Path
import struct
import sys
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
comparison=json.loads(Path('kprog/results/tail-short-encodings-20261117/comparison.json').read_text())

def relocations(folder):return list(struct.iter_unpack('<IIQ',(folder/'image.relocs').read_bytes()))
def sources(folder):
    result={}
    for line in (folder/'stderr').read_text().splitlines():
        if line.startswith('native-link-source-map '):
            row=json.loads(line.split(' ',1)[1]);key=(row['section'],row['symbol'],row['input_offset'])
            result[key]=row
    return result

def stub(data,field,short):
    prefix=bytes.fromhex('89d23956' if short else '89d23996')
    start=data.rfind(prefix,max(0,field-64),field)
    if start<0:return None
    branch=start+(5 if short else 8)
    opcode=bytes([0x76]) if short else bytes.fromhex('0f86')
    if data[branch:branch+len(opcode)]!=opcode:return None
    end=branch+(2 if short else 6)+struct.unpack_from('<b' if short else '<i',data,branch+len(opcode))[0]
    if not field+4<end<=len(data) or data[end-2:end]!=bytes.fromhex('ffe1'):return None
    return start,end,data[start:end]

def expected_short(old,field):
    slot=old.find(bytes.fromhex('488b8cd6'),field+4,field+30)
    branches=[8,field+8,slot+11]
    end=len(old)
    edits=[(site,site+6,bytes([old[site+1]-0x10,0])) for site in branches]
    edits.extend([(2,8,bytes.fromhex('3956')+old[4:5]),
        (end-16,end-9,bytes.fromhex('488b49')+old[end-13:end-12]),
        (end-9,end-2,bytes.fromhex('4883c1')+old[end-6:end-5])])
    edits.sort()
    def mapped(at):return at-sum(finish-start-len(replacement) for start,finish,replacement in edits if finish<=at)
    new=bytearray();cursor=0
    for start,finish,replacement in edits:new+=old[cursor:start]+replacement;cursor=finish
    new+=old[cursor:]
    for site in branches:
        at=mapped(site);new[at+1]=(len(new)-at-2)&255
    return bytes(new),mapped(field)

summary=defaultdict(Counter);reports=[]
for row in comparison['requests']:
    app=row['app'];c=summary[app];c.update(requests=1)
    record=dict(app=app,symbol=row['symbol'],capture=row['capture'],returncode=row['returncode'])
    if row['returncode']:
        record['error']='Current request failed; retained without byte attribution';reports.append(record);continue
    a,b=Path(row['before_output']),Path(row['after_output'])
    aa,bb=(a/'image.blob').read_bytes(),(b/'image.blob').read_bytes()
    old_fields=sorted(offset for offset,kind,_ in relocations(a) if kind==10)
    new_fields=sorted(offset for offset,kind,_ in relocations(b) if kind==10)
    tails=[]
    if len(old_fields)==len(new_fields):
        for old_field,new_field in zip(old_fields,new_fields):
            old,new=stub(aa,old_field,False),stub(bb,new_field,True)
            item=dict(old_field=old_field,new_field=new_field,recognized=bool(old and new))
            if old and new:
                candidate,candidate_field=expected_short(old[2],old_field-old[0])
                match=candidate==new[2] and candidate_field==new_field-new[0]
                item.update(old_start=old[0],new_start=new[0],old_bytes=len(old[2]),new_bytes=len(new[2]),
                    matches_preflight_encoding=match,counter_bytes_preserved=aa[old_field:old_field+4]==bb[new_field:new_field+4])
                c.update(stubs=1,stub_bytes_saved=len(old[2])-len(new[2]),matching_stubs=int(match))
            tails.append(item)
    old_sources,new_sources=sources(a),sources(b)
    reverse_old={r['output_offset']:key for key,r in old_sources.items()}
    changes=[]
    for key in sorted(old_sources.keys()&new_sources.keys()):
        old,new=old_sources[key],new_sources[key]
        if old['length']==new['length']:continue
        oi,ni=old['output_offset'],new['output_offset'];ol,nl=old['length'],new['length']
        ob,nb=aa[oi:oi+ol],bb[ni:ni+nl];kind='other';target_equal=None
        if ol==6 and nl==2 and ob[0]==15 and 0x80<=ob[1]<=0x8f and nb[0]==ob[1]-0x10:
            kind='conditional_rel32_to_rel8';ot=oi+6+struct.unpack_from('<i',ob,2)[0];nt=ni+2+struct.unpack_from('<b',nb,1)[0]
        elif ol==5 and nl==2 and ob[0]==0xe9 and nb[0]==0xeb:
            kind='jump_rel32_to_rel8';ot=oi+5+struct.unpack_from('<i',ob,1)[0];nt=ni+2+struct.unpack_from('<b',nb,1)[0]
        if kind!='other':
            target_key=reverse_old.get(ot)
            if target_key in new_sources:target_equal=nt==new_sources[target_key]['output_offset']
            elif ot==len(aa):target_equal=nt==len(bb)
        changes.append(dict(section=key[0],symbol=key[1],input_offset=key[2],old_offset=oi,new_offset=ni,
            old_bytes=ob.hex(),new_bytes=nb.hex(),bytes_saved=ol-nl,kind=kind,mapped_target_equal=target_equal))
        c.update(source_width_bytes_saved=ol-nl,source_width_changes=1)
        c.update({kind:1})
        if target_equal is False:c.update(mapped_target_mismatches=1)
    lost=old_sources.keys()-new_sources.keys();gained=new_sources.keys()-old_sources.keys()
    c.update(lost_source_rows=len(lost),gained_source_rows=len(gained),total_bytes_saved=len(aa)-len(bb))
    record.update(stubs=tails,source_width_changes=changes,lost_source_rows=[list(k) for k in sorted(lost)],
        gained_source_rows=[list(k) for k in sorted(gained)],total_bytes_saved=len(aa)-len(bb),
        attributed_bytes=sum(t.get('old_bytes',0)-t.get('new_bytes',0) for t in tails)+sum(i['bytes_saved'] for i in changes))
    reports.append(record)
result=dict(scope='Read-only actual paired blobs, kind10 relocations and retained source-map records. '
    'Source-map rows name retained source instructions only; synthetic/deleted/expanded rows are never guessed. '
    'Encoding identity and mapped target observations are not installed-size, timing or complete proof evidence.',
    summary={k:dict(v) for k,v in sorted(summary.items())},requests=reports)
(out/'layout-delta.json').write_text(json.dumps(result,indent=2)+'\n')
keys=('requests','stubs','matching_stubs','stub_bytes_saved','source_width_changes','source_width_bytes_saved',
    'conditional_rel32_to_rel8','jump_rel32_to_rel8','other','lost_source_rows','gained_source_rows','mapped_target_mismatches','total_bytes_saved')
lines=['app '+' '.join(keys)]+[app+' '+' '.join(str(c[k]) for k in keys) for app,c in sorted(summary.items())]
(out/'layout-delta-summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
