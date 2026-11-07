"""Replay the existing13 positive native-only cases without changing F evidence."""
from pathlib import Path
from datetime import datetime,timezone
import gzip,hashlib,json,tarfile,tempfile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
SOURCE=ROOT/'kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service'
EXPECTED='d6319ef0d6dc39de75ef99e83c060c0e1e9cb6c8ff480c9554d0ffcfc3fea92b'
source=(SOURCE/'check.py').read_bytes()
assert hashlib.sha256(source).hexdigest()==EXPECTED,'existing driver changed; inspect before reuse'
namespace={'__file__':str(SOURCE/'check.py')}
exec(compile(source.decode().split('p=argparse.ArgumentParser();')[0],str(SOURCE/'check.py'),'exec'),namespace)
pins=[ROOT/'kprog/x86/x86_sim_local_bpf.h',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py',ROOT/'kprog/formal/oracles/x86_route_host.c',ROOT/'kprog/tv/build-x86/bpf_x86_native_lab.ko',ROOT/'kprog/tv/build-kernel-x86/arch/x86/boot/bzImage']
def hashes():return {str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in pins}
summary=dict(ok=False,started=datetime.now(timezone.utc).isoformat(),positive_driver_sha256=EXPECTED,source_pins=hashes(),unsafe_execution_permitted=False)
with tempfile.TemporaryDirectory(prefix='.live-',dir=OUT) as directory:
 live=Path(directory);(live/'inputs.json').write_bytes((SOURCE/'inputs.json').read_bytes());namespace['O']=live
 try:
  namespace['check']();summary['ok']=True
 finally:
  summary['finished']=datetime.now(timezone.utc).isoformat();summary['source_pins_after']=hashes()
  summary['pins_unchanged']=summary['source_pins']==summary['source_pins_after']
  if (live/'outcomes.json').exists():
   rows=json.loads((live/'outcomes.json').read_text());summary['cases']=len(rows);summary['passed']=sum(r['stage']=='passed' for r in rows)
   (OUT/'outcomes.json.gz').write_bytes(gzip.compress((live/'outcomes.json').read_bytes(),mtime=0))
  (live/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');archive=OUT/('positive-'+datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%S%fZ')+'.tar.gz')
  with tarfile.open(archive,'x:gz') as target:target.add(live,arcname='positive')
  summary.update(archive=archive.name,archive_sha256=hashlib.sha256(archive.read_bytes()).hexdigest());(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
  print(json.dumps({k:summary.get(k) for k in ['ok','cases','passed','pins_unchanged','archive']}),flush=True)
