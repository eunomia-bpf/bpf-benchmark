#!/usr/bin/env python3
"""Record native helper call/evaluation sites from actual fixture IR."""
import json
from pathlib import Path
import re
import sys
raw=Path(sys.argv[1]);lines=(raw/'actual.ll').read_text().splitlines();functions={}
for name in ['actual_header_lookup','actual_header_probe','actual_header_trace']:
    start=next(i for i,l in enumerate(lines) if l.startswith('define ') and '@'+name+'(' in l)
    end=next(i for i in range(start+1,len(lines)) if lines[i]=='}')
    body=lines[start:end+1]
    calls=[line.strip() for line in body if ' call ' in line and '@llvm.' not in line and 'asm sideeffect' not in line]
    functions[name]=dict(body=body,next_key_calls=sum('@next_key(' in l for l in calls),
                         fp_loads=sum(bool(re.search(r'\bload i64, ptr\b',l)) for l in body),
                         actual_calls=calls,id_barriers=[l.strip() for l in body if 'asm sideeffect' in l])
report=dict(raw=str(raw),functions=functions,
            scope='Actual header native IR; field-load fixture follows the real tracemgmt.h:312 expression. '
                  'This records compiler behavior and helper-call presence, separate from app frequency or timing.')
(raw/'ir-observations.json').write_text(json.dumps(report,indent=2)+'\n')
for name,row in functions.items():
    print(name,'next_key calls',row['next_key_calls'],'field loads',row['fp_loads'],'actual calls',len(row['actual_calls']))
