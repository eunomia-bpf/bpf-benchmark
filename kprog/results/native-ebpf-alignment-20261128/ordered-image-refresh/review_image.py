"""Collect1475904 without rebuilding: preserve controller1, verify old image absence and delivered bytes."""
from pathlib import Path
import json,hashlib,subprocess,fcntl,re
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');LOCKS=LANE.parent/'locks'
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1048576),b''):h.update(b)
 return h.hexdigest()
r=json.loads((HERE/'controller.json').read_text());assert r['pid']==1475904 and r['controller_status']==1 and r['kernel_P_source_app_unchanged'];assert len(r['commands'])==4 and all(x['returncode']==0 for x in r['commands']);assert r['image_payload_verification']['returncode']==0 and json.loads(r['image_payload_verification']['stdout'])==dict(files=121,bad=[]);assert r['old_image_retirement']['returncode']==1 and 'No such image' in r['old_image_retirement']['stderr']
with (LOCKS/'timing').open('a') as timing,(LOCKS/'image').open('a') as image:
 fcntl.flock(timing,fcntl.LOCK_SH);fcntl.flock(image,fcntl.LOCK_SH)
 current=subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip();inventory=set(subprocess.check_output(['docker','image','ls','--all','--no-trunc','--quiet'],text=True).split());assert current==r['new_image'] and current in inventory and r['old_image'] not in inventory
 old=subprocess.run(['docker','image','inspect',r['old_image']],stdin=subprocess.DEVNULL,text=True,capture_output=True);assert old.returncode!=0 and 'No such image' in old.stderr
 assert sha(Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage'))==r['kernel_sha256'];stage=ROOT/'vendor/build/native-bpf/x86/stage';assert r['native_P_inputs']=={str(p.relative_to(stage)):sha(p) for p in sorted(stage.rglob('*')) if p.is_file() and p.name!='kprog-perf-context-lto'};assert all(sha(ROOT/p)==h for p,h in r['source_sha256'].items());assert all(sha(Path(x['host_path']))==x['sha256'] for x in r['products'].values())
 assert subprocess.check_output(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','rev-parse','HEAD'],text=True).strip().startswith('2689a430') and '2689a430' in subprocess.check_output(['git','ls-tree','HEAD','vendor/repos/opentelemetry-ebpf-profiler'],text=True);subprocess.run(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','diff','--quiet'],check=True)
 expected={**{n:x['sha256'] for n,x in r['products'].items()},**{'/opt/bpf-benchmark/native-bpf/x86_64/'+n:h for n,h in r['native_P_inputs'].items()}}
 code="import sys,json,hashlib;d=json.load(sys.stdin);bad=[p for p,h in d.items() if hashlib.sha256(open(p,'rb').read()).hexdigest()!=h];print(json.dumps(dict(files=len(d),bad=bad)));sys.exit(bool(bad))"
 a=subprocess.run(['docker','run','--rm','-i','--cpuset-cpus','19','--network','none','--entrypoint','python3',current,'-c',code],input=json.dumps(expected),text=True,capture_output=True);assert a.returncode==0;assert json.loads(a.stdout)==dict(files=121,bad=[]);assert sha(Path(r['runtime_tar']['path']))==r['runtime_tar']['sha256']
 out=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),newest_resume='COORDINATOR2026-11-28T11:20Z',same_build_pid=1475904,original_controller_status=1,original_controller_sha256=sha(HERE/'controller.json'),collection_status=0,disposition='All build/payload/tar/kernel/P/source/app checks pass. Controller1 is solely an attempted deletion of an already-absent oldimage. Exact oldID absent in inventory and inspect, current newID present. Originalfailure unchanged; no rebuild/tag/cleanup performed by collector.',current_image=current,old_image=r['old_image'],old_absent=True,inside_image_verification=dict(returncode=a.returncode,result=json.loads(a.stdout),container_cpu=19),kernel_P_source_app_unchanged=True,runtime_tar=r['runtime_tar'],products=r['products'],limits='Image delivery only. No six-app/installed-code/equalwork/performance acceptance yet; schedulingconfound remains.')
 with (HERE/'collection-review.json').open('x') as f:f.write(json.dumps(out,indent=2)+'\n')
 print(json.dumps(out,indent=2))
