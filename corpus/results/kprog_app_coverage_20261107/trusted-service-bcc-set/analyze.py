"""Summarize every retained request, including failed and interrupted startup."""
import csv
import hashlib
import io
import json
from pathlib import Path
import re
import tarfile
ROOT=Path(__file__).resolve().parent
rows=[];runs=[]
for archive in sorted(ROOT.glob('run-*.tar.gz')):
 with tarfile.open(archive) as outer:
  files={m.name:m for m in outer.getmembers() if m.isfile()}
  def read(name):return outer.extractfile(files[name]).read()
  summary=json.loads(read('run/summary.json'))
  records={}
  for line in read('run/service.log').decode().splitlines():
   record=json.loads(line)
   if 'request_id' in record:records[record['request_id']]=record
  by_hash={value:Path(name).name.removesuffix('.native.o') for name,value in summary.get('artifact_sha256',{}).items() if name.endswith('.native.o')}
  request_files=sorted((n for n in files if re.fullmatch(r'run/requests/[0-9]+\.(success|failure)\.tar\.gz',n)),key=lambda n:int(Path(n).name.split('.')[0]))
  done=set();run_rows=[]
  for name in request_files:
   request_id=int(Path(name).name.split('.')[0]);done.add(request_id)
   record=records.get(request_id,{})
   payload={};incomplete=''
   try:
    with tarfile.open(fileobj=io.BytesIO(read(name))) as inner:
     payload={m.name:inner.extractfile(m).read() for m in inner.getmembers() if m.isfile()}
   except (tarfile.ReadError,EOFError) as error:incomplete=str(error)
   def get(suffix):return next((b for n,b in payload.items() if n.endswith(suffix)),b'')
   entry=get('/kernel.entry').decode().strip()
   error=get('/error.json').decode()
   stderr=get('/load.stderr').decode()
   status=record.get('status');accepted=status==0
   if accepted:cause='accepted'
   elif incomplete:cause='interrupted-archive'
   elif 'misaligned' in stderr:cause='verifier-misaligned-stack-access'
   elif 'invalid write to stack' in stderr:cause='verifier-stack-limit'
   elif 'math between fp pointer' in stderr:cause='verifier-scalar-stack-pointer-arithmetic'
   elif 'BPF_PROG_LOAD native_lab stub' in stderr:cause='verifier-EINVAL-no-failure-line-retained'
   elif 'activation refused' in stderr:cause='request-activation-refused-during-teardown'
   elif 'GET_MAP' in error or 'No such file' in error:cause='map-metadata-kernel-query'
   elif error:cause='specialization-or-loader-error'
   else:cause='interrupted-request'
   row=dict(run=archive.name,request_id=request_id,source_prog_id=record.get('source_prog_id',''),app=by_hash.get(record.get('native_sha256'),'unknown'),entry=entry,
     proof_generated=bool(get('/trusted_x86.bpf.c')),proof_compiled=bool(get('/trusted_x86.bpf.o')),accepted=accepted,cause=cause,status=status,
     raw_request=name,archive_complete=not bool(incomplete))
   rows.append(row);run_rows.append(row)
  for request_id,record in records.items():
   if request_id not in done:raise ValueError(f'receipt without archive: {archive.name}/{request_id}')
  work=json.loads(read('run/functional-work.json')) if 'run/functional-work.json' in files else None
  runs.append(dict(archive=archive.name,sha256=hashlib.sha256(archive.read_bytes()).hexdigest(),outer_ok=summary['ok'],
    observed_requests=len(run_rows),proof_generated=sum(r['proof_generated'] for r in run_rows),proof_compiled=sum(r['proof_compiled'] for r in run_rows),
    accepted=sum(r['accepted'] for r in run_rows),causes={cause:sum(r['cause']==cause for r in run_rows) for cause in sorted({r['cause'] for r in run_rows})},
    functional_work=work,full_bcc_set=False))
with (ROOT/'coverage.csv').open('w') as stream:
 writer=csv.DictWriter(stream,fieldnames=list(rows[0]),lineterminator=chr(10));writer.writeheader();writer.writerows(rows)
(ROOT/'coverage.json').write_text(json.dumps(dict(runs=runs,scope='Observed actual requests, not a complete eight-tool inventory. No failed or interrupted requests are excluded.'),indent=2)+'\n')
for run in runs:print(run['archive'],run['observed_requests'],run['proof_generated'],run['proof_compiled'],run['accepted'],run['causes'])
