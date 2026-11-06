"""Report every real BCC selected-proof attempt and preserve validation logs."""
from collections import Counter
import csv
import json
from pathlib import Path
import shutil

HERE=Path(__file__).resolve().parent
out=HERE/'memory-extension';out.mkdir(exist_ok=True)
phases=['bcc-real-entries-v8','bcc-real-entries-v9','bcc-tag-word','bcc-packed-tags','bcc-packed-tags-v2']
rows=[];table=['| Phase | Generated | Compiled | Verifier accepted | Verifier rejected | Map preparation failed | Object open failed |',
              '| --- | ---: | ---: | ---: | ---: | ---: | ---: |']
for phase in phases:
    path=HERE/phase;counts=Counter()
    for line in (path/'programs.jsonl').read_text().splitlines():
        source=json.loads(line);name=source['name']
        compiled=json.loads((path/'compile'/(name+'.json')).read_text())
        rc=int((path/'verify'/(name+'.rc')).read_text())
        log=path/'verify'/(name+'.verifier.log')
        error=(path/'verify'/(name+'.stderr')).read_text()
        status='verifier_accepted' if rc==0 else ('verifier_rejected' if log.is_file() and log.stat().st_size else
                'map_preparation_failed' if 'failed to create' in error else 'object_open_failed')
        counts['generated']+=int(source['ok']);counts['compiled']+=int(compiled['returncode']==0);counts[status]+=1
        rows.append(dict(phase=phase,original_id=source['original_id'],name=source['original_symbol'],
            type=source['program_type'],generated=source['ok'],compile_rc=compiled['returncode'],load_rc=rc,status=status))
    table.append('| '+phase+' | '+' | '.join(str(counts[key]) for key in
        ['generated','compiled','verifier_accepted','verifier_rejected','map_preparation_failed','object_open_failed'])+' |')
with (out/'bcc-proof-attempts.csv').open('w') as target:
    writer=csv.DictWriter(target,fieldnames=list(rows[0]),lineterminator='\n');writer.writeheader();writer.writerows(rows)
(out/'bcc-table.md').write_text('\n'.join(table)+'\n')
logs=['memory-tags-packed','stack-store-packed','helper-packed-check','abi-memory-final-v2',
      'memory-final-micro-build','memory-final-micro','memory-final-stage2','memory-return-final']
for name in logs: shutil.copy2(Path('/workspaces/.agent-state/kprog-lanes/A')/(name+'.log'),out/(name+'.log'))
shutil.copy2('/workspaces/.agent-state/kprog-lanes/V/check-helper-packed-full-2.log',out/'formal-full.log')
shutil.copy2('/workspaces/.agent-state/kprog-lanes/V/check-helper-packed-full-2.exit',out/'formal-full.exit')
print('\n'.join(table))
