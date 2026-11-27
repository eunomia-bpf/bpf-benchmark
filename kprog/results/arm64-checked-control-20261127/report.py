"""Report actual control paths from retained service and request receipts."""
import io
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
report=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),scope='Tiny XDP/TC controls only; client0 alone does not establish checked installation; no application/timing claim.',runs=[])
for directory in sorted(HERE.glob('guest-*')):
 if not directory.is_dir():continue
 controller=json.loads((directory/'controller.json').read_text());raw=Path(controller['raw'])
 row=dict(directory=directory.name,revision=controller['revision'],controller_status=controller.get('controller_status'),ended_utc=controller.get('ended_utc'),cases=[])
 if 'exception' in controller:row['controller_exception']=controller['exception']
 for kind in ['xdp','tc']:
  case=raw/kind
  if not case.exists():continue
  outcome=dict(kind=kind)
  for stream in ['stdout','stderr']:
   if (case/stream).exists():outcome[stream]=(case/stream).read_text()
  if (raw/'cases.json').exists():outcome['client_returncode']=next((x['returncode'] for x in json.loads((raw/'cases.json').read_text()) if x['kind']==kind),None)
  if (case/'service.tar.gz').exists():
   with tarfile.open(case/'service.tar.gz') as outer:
    outcome['service_receipts']=[json.loads(x) for x in outer.extractfile('service/service.log').read().decode().splitlines() if x.strip()]
    requests=[]
    for member in outer.getmembers():
     if not member.isfile() or not member.name.endswith('.tar.gz'):continue
     request=dict(archive=member.name)
     with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as inner:
      for item in inner.getmembers():
       if not item.isfile():continue
       name=item.name
       if name.endswith(('checked-simulator-verification.json','completion.json','error.json')):
        request[Path(name).name]=json.loads(inner.extractfile(item).read())
       elif name.endswith(('verify.stderr','load.stderr','load.stdout','load-direct.stdout')):
        request[Path(name).name]=inner.extractfile(item).read().decode()
       elif name.endswith('native-commands.jsonl'):
        request['native_commands']=[json.loads(x) for x in inner.extractfile(item).read().decode().splitlines() if x.strip()]
     requests.append(request)
    outcome['request_receipts']=requests
  row['cases'].append(outcome)
 report['runs'].append(row)
(HERE/'actual-outcomes.json').write_text(json.dumps(report,indent=2)+'\n')
for run in report['runs']:
 print(run['directory'],'controller',run['controller_status'])
 for case in run['cases']:
  print(' ',case['kind'],'client',case.get('client_returncode'),[(r.get('execution_path'),r.get('b_generated'),r.get('b_stock_passed'),r.get('status')) for r in case.get('service_receipts',[]) if 'request_id' in r])
