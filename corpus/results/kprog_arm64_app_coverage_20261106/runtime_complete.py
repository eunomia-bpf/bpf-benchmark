"""Preserve the completed real BCC baseline and its native-start failure."""
import csv
import json
from pathlib import Path
import shutil
import sys
import tarfile

ROOT = Path(__file__).resolve().parents[3]
phase = Path(sys.argv[1]).resolve()
phase.mkdir()
run = ROOT/'corpus/results/arm64_qemu_corpus_19700101_000006_886537'
app = json.loads((run/'details/apps/bcc__set.json').read_text())
programs = json.loads((run/'details/bpf-evidence/bcc_set/baseline/program-inventory.json').read_text())
rows=[]
for program in programs:
    count=app['baseline']['bpf'][str(program['id'])]
    if count['id'] != program['id']: raise ValueError('resident program/counter identity differs')
    rows.append(dict(id=program['id'],name=program['name'],type=program['type'],
        run_cnt_delta=count['run_cnt_delta'],run_time_ns_delta=count['run_time_ns_delta'],
        bytes_jited=count['bytes_jited'],bytes_xlated=count['bytes_xlated']))
with (phase/'resident-counters.csv').open('w') as out:
    writer=csv.DictWriter(out,fieldnames=list(rows[0]),lineterminator='\n')
    writer.writeheader();writer.writerows(rows)
for name in ['result.json','apps/bcc__set.json','bpf-evidence/bcc_set/baseline/program-inventory.json']:
    shutil.copy2(run/'details'/name,phase/Path(name).name)
shutil.copy2('/workspaces/.agent-state/kprog-lanes/A/qemu-bcc-verified-recovery.log',phase/'host-console.log')
with tarfile.open(phase/'raw-run.tar.gz','w:gz') as out:
    out.add(run,arcname=run.name)
print(f'{len(rows)} real resident BCC programs; baseline counters preserved; app status={app["status"]}')
print(app.get('error'))
