"""Reconcile immutable original/retry receipts and verify archived compiler outputs."""
import collections
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tarfile

HERE=Path(__file__).resolve().parent
original=HERE/sys.argv[1]
retry=HERE/sys.argv[2]
records=[json.loads((p/'controller.json').read_text()) for p in [original,retry]]
assert records[1]['recovery_of'].endswith(original.name+'/controller.json')
assert records[0]['common_flags']==records[1]['common_flags']
assert records[0]['header_sha256']==records[1]['header_sha256']
assert records[0]['macro_profile_sha256']==records[1]['macro_profile_sha256']
audits=[]
for directory,record in zip([original,retry],records):
    parts=sorted(directory.glob('evidence.tar.zst.part-*'))
    assert parts and record['archive_returncodes']==[0,0,0]
    source=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE)
    decode=subprocess.Popen(['zstd','-dc'],stdin=source.stdout,stdout=subprocess.PIPE)
    source.stdout.close()
    files=[]
    with tarfile.open(fileobj=decode.stdout,mode='r|') as archive:
        for member in archive:
            if not member.isfile():continue
            raw=Path(record['raw']).parent/member.name
            left=archive.extractfile(member)
            sha=hashlib.sha256()
            with raw.open('rb') as right:
                while True:
                    block=left.read(1024*1024)
                    assert block==right.read(len(block) if block else 1),str(raw)
                    if not block:break
                    sha.update(block)
            files.append(dict(member=member.name,bytes=member.size,sha256=sha.hexdigest()))
    assert decode.wait()==source.wait()==0
    audits.append(dict(controller=str(directory/'controller.json'),archived_files_equal_raw=len(files),parts=[dict(path=p.name,bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in parts],files=files))
base=json.loads((original/'compatibility.json').read_text())
recovered=json.loads((retry/'compatibility.json').read_text())
rows={r['index']:r for r in base['requests']}
for row in recovered['requests']:
    old=rows[row['index']]
    assert old['replay_status']=='exception' and row['replay_status']=='compiled'
    assert (old['app'],old['symbol'])==(row['app'],row['symbol'])
    row=dict(row,initial_replay_status=old['replay_status'],recovery_controller=str(retry/'controller.json'))
    rows[row['index']]=row
rows=[rows[k] for k in sorted(rows)]
assert len(rows)==88 and all(r['replay_status']=='compiled' for r in rows)
apps={app:dict(requests=sum(r['app']==app for r in rows),frontend_seconds=sum(c['wall_seconds'] for r in rows if r['app']==app for c in r['replay_commands'] if '-emit-llvm' in c['command']),all_compiler_seconds=sum(c['wall_seconds'] for r in rows if r['app']==app for c in r['replay_commands'])) for app in sorted({r['app'] for r in rows})}
result=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),controllers=[str(p/'controller.json') for p in [original,retry]],original_controller_statuses=[r['controller_status'] for r in records],compiled_requests=88,recovered_input_exceptions=len(recovered['requests']),apps=apps,requests=rows,archive_audits=audits,scope='Original65 compiler successes plus exact23 input-archive exception recoveries, all88 now compiled. Original error receipts remain immutable. Retry controller1 reflects publication index.lock collision, not compilation. Covers23BCC/1Katran/13OTel/51Tetra; additional34Tetra and separate Cilium/Tracee are outside this replay inventory. Compiler completion is not stock/native/frozen900s startup acceptance.')
(retry/'compiled-corpus.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(dict(compiled_requests=88,recovered_input_exceptions=23,apps=apps,archive_files_equal_raw=[a['archived_files_equal_raw'] for a in audits]),indent=2))
