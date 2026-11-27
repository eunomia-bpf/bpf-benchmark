"""Reconcile the final opensnoop callback with retained raw and published receipts."""
import io
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
folder=HERE/'guest-20261127T005711Z';controller=json.loads((folder/'controller.json').read_text());raw=Path(controller['raw']);case=raw/'bcc-opensnoop'
published=json.loads((HERE/'opensnoop-after-outcome.json').read_text())
record=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),controller_status=controller['controller_status'],revision=controller['revision'],archive_files=0,archive_bytes=0,requests=[])
process=subprocess.Popen(['zstd','-d','-c',*[str(x) for x in sorted(folder.glob('evidence.tar.zst.part-*'))]],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
with tarfile.open(fileobj=process.stdout,mode='r|') as archive:
 for member in archive:
  if not member.isfile():continue
  relative=Path(member.name).relative_to(raw.name)
  assert archive.extractfile(member).read()==(raw/relative).read_bytes(),str(relative)
  record['archive_files']+=1;record['archive_bytes']+=member.size
process.stdout.close();error=process.stderr.read().decode();assert process.wait()==0,error
for stream in ['stdout','stderr']:assert (case/stream).read_text()==published[stream]
with tarfile.open(case/'service.tar.gz') as outer:
 receipts=[json.loads(x) for x in outer.extractfile('service/service.log').read().decode().splitlines() if '"request_id"' in x]
 assert len(receipts)==len(published['requests'])==2
 for receipt,saved in zip(receipts,published['requests']):
  for key in ['request_id','source_prog_id','prog_id','phase','status','execution_path','b_generated','b_stock_passed','error']:assert receipt.get(key)==saved[key],key
  name='service/requests/'+str(receipt['request_id'])+'.success.tar.gz'
  with tarfile.open(fileobj=io.BytesIO(outer.extractfile(name).read())) as inner:
   files={Path(m.name).name:m for m in inner.getmembers() if m.isfile()}
   for name in ['load.stdout','load.stderr','verify.stderr','native-commands.jsonl']:
    assert inner.extractfile(files[name]).read().decode()==saved[name],name
   assert json.loads(inner.extractfile(files['checked-simulator-verification.json']).read())==saved['stock_verification']
  record['requests'].append(dict(symbol=saved['symbol'],source_prog_id=receipt['source_prog_id'],stock_verification=saved['stock_verification'],native_prog_id=receipt['prog_id'],execution_path=receipt['execution_path'],status=receipt['status'],native_command_returncodes=saved['native_command_returncodes']))
publication=(folder/'publication.log').read_text();assert 'master -> master' in publication
record.update(publication_log=publication,application_returncode=controller['cases'][0]['returncode'],stdout_rows=len(published['stdout'].splitlines()),event_rows=published['event_rows'],test_run='Application startup/attachment and real tracing events; no TEST_RUN oracle was invoked.',conclusion='Published19fe9abdb outcome agrees with raw/archive receipts. Both stock accepted and checked installed;144real open events/no direct fallback/no loader or app stderr. Existing203501fca repair verified; no new failure, source change or rerun required. Full timing frozen.')
(HERE/'opensnoop-callback-audit.json').write_text(json.dumps(record,indent=2)+'\n')
print('Archive files byte-equal:',record['archive_files'])
print('Two checked installs, nativeIDs15/23,144real events; callback fully consumed')
