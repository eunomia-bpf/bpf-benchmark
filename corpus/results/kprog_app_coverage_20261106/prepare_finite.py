"""Pin the source/header inputs for the next application-artifact census."""
import json
from pathlib import Path
import re
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
PHASE=HERE/(sys.argv[2] if len(sys.argv)>2 else 'finite')
if sys.argv[1]=='prepare':
    PHASE.mkdir(exist_ok=True)
    snapshot=PHASE/'simulator'
    if snapshot.exists():
        raise SystemExit('finite snapshot already exists; resume recorded generation/compilation instead of overwriting it')
    def copy(path):
        relative=path.relative_to(ROOT)
        target=snapshot/relative
        if target.exists(): return
        target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(path.read_bytes())
        for include in re.findall(r'^#include "([^\"]+)"',path.read_text(),re.M):
            child=(path.parent/include).resolve()
            if child.is_file(): copy(child)
    copy(ROOT/'kprog/x86/x86_sim_local_bpf.h')
    for path in [ROOT/'kprog/helper_abi.py',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py',
                 ROOT/'kprog/x86/run_app_sim_smoke.py',ROOT/'kprog/x86/micro-prog/x86_abi.py',*list((ROOT/'kprog/x86/micro-prog').glob('generated_*.py'))]:
        target=snapshot/path.relative_to(ROOT)
        target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(path.read_bytes())
    target=snapshot/'vendor/libbpf/src/bpf_helper_defs.h'
    target.parent.mkdir(parents=True,exist_ok=True)
    target.write_bytes((ROOT/'vendor/libbpf/src/bpf_helper_defs.h').read_bytes())
    rows=[json.loads(p.read_text()) for p in (HERE/'finite-targets').glob('*.json')]
    assert len(rows)==1136
    pinned = {}
    if PHASE.name != 'finite':
        records = [json.loads(line) for line in (HERE/'finite/programs.jsonl').read_text().splitlines()]
        pinned = {(Path(r['proof']).parent.name,Path(r['proof']).name):
                  Path(r['source']).parent/'proof-objects'/(r['name']+'.proof.o') for r in records}
    for row in rows:
        source = (pinned[row['app'],Path(row['object']).name] if pinned else
                  Path(row.get('replacement_object',row['object'])))
        if not source.is_file(): raise FileNotFoundError(source)
        target=PHASE/'input'/row['app']/source.name
        target.parent.mkdir(parents=True,exist_ok=True)
        target.symlink_to(source)
    print('frozen simulator/includes/generator and linked all1136 inputs')
elif sys.argv[1]=='freeze':
    rows=[json.loads(line) for line in (PHASE/'programs.jsonl').read_text().splitlines()]
    count=0
    for row in rows:
        if row['stage']=='generate' and row['ok']:
            source=Path(row['source'])
            text=source.read_text().replace('#include "../x86_sim_local_bpf.h"',
                f'#include "{PHASE}/simulator/kprog/x86/x86_sim_local_bpf.h"')
            source.write_text(text)
            count+=1
    print('pinned compiler headers for',count,'generated sources')
else:
    raise SystemExit('expected prepare or freeze')
