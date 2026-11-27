"""Reconcile queued control callbacks with published and raw receipts."""
import io
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
published=json.loads((HERE/'actual-outcomes.json').read_text())
report=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),runs=[])
for original in published['runs']:
 directory=HERE/original['directory'];controller=json.loads((directory/'controller.json').read_text());raw=Path(controller['raw'])
 row=dict(directory=directory.name,controller_status=controller['controller_status'],qemu_returncode=controller['qemu_returncode'],archive_returncodes=controller['archive_returncodes'],cases=[],archive_files=0,archive_bytes=0)
 assert row['controller_status']==original['controller_status']
 parts=sorted(directory.glob('evidence.tar.zst.part-*'))
 process=subprocess.Popen(['zstd','-d','-c',*[str(x) for x in parts]],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
 members=set()
 with tarfile.open(fileobj=process.stdout,mode='r|') as archive:
  for member in archive:
   if not member.isfile():continue
   relative=Path(member.name).relative_to(raw.name)
   assert archive.extractfile(member).read()==(raw/relative).read_bytes(),str(relative)
   members.add(relative);row['archive_files']+=1;row['archive_bytes']+=member.size
 process.stdout.close();error=process.stderr.read().decode();assert process.wait()==0,error
 row['later_raw_files']=[str(x.relative_to(raw)) for x in sorted(raw.rglob('*')) if x.is_file() and x.relative_to(raw) not in members]
 publication=(directory/'publication.log').read_text();assert 'master -> master' in publication
 row['publication_log']=publication
 for saved in original['cases']:
  kind=saved['kind'];case=raw/kind;result=dict(kind=kind,client_returncode=saved.get('client_returncode'))
  for stream in ['stdout','stderr']:
   if stream in saved:assert saved[stream]==(case/stream).read_text()
  if 'service_receipts' in saved:
   with tarfile.open(case/'service.tar.gz') as outer:
    receipts=[json.loads(x) for x in outer.extractfile('service/service.log').read().decode().splitlines() if x.strip()]
    assert receipts==saved['service_receipts']
    result['service_receipts']=receipts
    for request in saved['request_receipts']:
     with tarfile.open(fileobj=io.BytesIO(outer.extractfile(request['archive']).read())) as inner:
      files={Path(x.name).name:x for x in inner.getmembers() if x.isfile()}
      for name,value in request.items():
       if name=='archive':continue
       if name=='native_commands':
        actual=[json.loads(x) for x in inner.extractfile(files['native-commands.jsonl']).read().decode().splitlines() if x.strip()]
       else:
        actual=inner.extractfile(files[name]).read().decode()
        if name.endswith('.json'):actual=json.loads(actual)
       assert actual==value,(directory.name,kind,name)
     if 'checked-simulator-verification.json' in request:result['stock_verification']=request['checked-simulator-verification.json']
     if 'verify.stderr' in request:result['verifier_log']=request['verify.stderr']
     if 'native_commands' in request:result['native_command_returncodes']=[x['returncode'] for x in request['native_commands']]
   result['client_stdout']=saved.get('stdout')
  row['cases'].append(result)
 report['runs'].append(row)
 print(directory.name,'controller',row['controller_status'],'archive members byte-equal',row['archive_files'],'cases',[(x['kind'],x['client_returncode']) for x in row['cases']])
report['conclusion']='All five queued callbacks already resolved. Boot-only failure; import-only failure; direct-native fallback twice with no B; B stock acceptance then host LLVM-name failure; finally XDP and TC checked-sim-c installation and TEST_RUN2. Existing common fix acea7bf30 and outcomes b933f7ea2 remain accurate. No new execution or source fix required.'
(HERE/'callback-audit.json').write_text(json.dumps(report,indent=2)+'\n')
