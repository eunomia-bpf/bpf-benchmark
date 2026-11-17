#!/usr/bin/env python3
"""Read actual tail-counter relocations; quantify short encodings without patching code."""
from collections import Counter,defaultdict
import json
from pathlib import Path
import struct
import sys
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/inline-helper-labels-20261117/host-20261117T204206Z-2750151/replay/replay.json')
j=json.loads(source.read_text());rows=[];summary=defaultdict(Counter)
for request in j['requests']:
    c=summary[request['app']];c.update(requests=1)
    if request['returncode']:
        rows.append(dict(app=request['app'],symbol=request['symbol'],returncode=request['returncode']))
        continue
    folder=Path(request['output']);data=(folder/'image.blob').read_bytes()
    for offset,kind,target in struct.iter_unpack('<IIQ',(folder/'image.relocs').read_bytes()):
        if kind!=10:continue
        c.update(tail_sites=1)
        row=dict(app=request['app'],symbol=request['symbol'],output=str(folder),counter_field=offset,counter_target=target)
        start=data.rfind(bytes.fromhex('89d23996'),max(0,offset-64),offset)
        first=start+8
        counter_load=data[offset-3:offset]
        second=offset+8
        slot=data.find(bytes.fromhex('488b8cd6'),offset+4,offset+30)
        third=slot+11
        shape=(start>=0 and data[first:first+2]==bytes.fromhex('0f86')
            and counter_load in (bytes.fromhex('488b80'),bytes.fromhex('488b85'))
            and data[offset+4:second]==bytes.fromhex('48833821')
            and data[second:second+2]==bytes.fromhex('0f83')
            and slot>=0 and data[slot+8:third]==bytes.fromhex('4885c9')
            and data[third:third+2]==bytes.fromhex('0f84'))
        row['recognized_shape']=shape
        if not shape:
            row['context_hex']=data[max(0,offset-40):offset+80].hex();rows.append(row);continue
        branches=[first,second,third]
        targets=[site+6+struct.unpack_from('<i',data,site+2)[0] for site in branches]
        end=targets[0]
        valid=(targets==[end]*3 and third+6<=end<=len(data) and data[end-2:end]==bytes.fromhex('ffe1'))
        row.update(start=start,end=end,branch_targets=targets,recognized_end=valid)
        if not valid:rows.append(row);continue
        # Compact all three Jcc instructions together: calculate each new source
        # and the new common miss target after removing four bytes per branch.
        end_short=end-12
        displacements=[end_short-(site-4*n+2) for n,site in enumerate(branches)]
        short=all(-128<=disp<=127 for disp in displacements)
        max_entries=struct.unpack_from('<i',data,start+4)[0]
        func_sequence=data[end-16:end-9]
        entry_sequence=data[end-9:end-2]
        compact_func=func_sequence[:3]==bytes.fromhex('488b89') and -128<=struct.unpack_from('<i',func_sequence,3)[0]<=127
        compact_entry=entry_sequence[:3]==bytes.fromhex('4881c1') and -128<=struct.unpack_from('<i',entry_sequence,3)[0]<=127
        saved=(12 if short else 0)+(3 if -128<=max_entries<=127 else 0)+(3 if compact_func else 0)+(3 if compact_entry else 0)
        row.update(stub_bytes=end-start,branches=[s-start for s in branches],short_displacements=displacements,
            all_three_jcc_fit_rel8=short,max_entries_displacement=max_entries,
            prog_function_disp8=compact_func,tail_entry_imm8=compact_entry,
            encoding_opportunity_bytes=saved,counter_slot_bytes=data[offset:offset+4].hex(),
            stub_hex=data[start:end].hex())
        c.update(recognized=1,stub_bytes=end-start,jcc_rel8_sites=int(short),jcc_bytes=12 if short else 0,
            cmp_disp8_sites=int(-128<=max_entries<=127),func_disp8_sites=int(compact_func),entry_imm8_sites=int(compact_entry),
            encoding_opportunity_bytes=saved)
        rows.append(row)
result=dict(scope='Read-only retained code shapes. No native code generated, transformed or executed, no production change. '
    'Byte opportunities are static request-set observations, not installed savings, hot frequencies or speedups. '
    'The kind10 counter relocation remains a 4-byte displacement; it is excluded from compaction.',
    source=str(source),index_errors=j['index_errors'],summary={app:dict(c) for app,c in sorted(summary.items())},sites=rows)
(out/'inventory.json').write_text(json.dumps(result,indent=2)+'\n')
keys=('requests','tail_sites','recognized','stub_bytes','jcc_rel8_sites','jcc_bytes','cmp_disp8_sites','func_disp8_sites','entry_imm8_sites','encoding_opportunity_bytes')
lines=['app '+' '.join(keys)]+[app+' '+' '.join(str(c[k]) for k in keys) for app,c in sorted(summary.items())]
(out/'summary.txt').write_text('\n'.join(lines)+'\n');print('\n'.join(lines))
