"""One all-six-app frozen10s alignment check on collected current image; no full timing."""
from pathlib import Path
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');OUT=HERE/'run';RAW=Path('/workspaces/kprog-raw/perf/current-six-app-check-20261128');IMAGE='sha256:31f611e1374d1f6cd7660166b97816bbdff2d75013843a7066c6d704dd9db388';now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest();assert not OUT.exists() and not RAW.exists();OUT.mkdir();RAW.mkdir();os.sched_setaffinity(0,{19});r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='checks',image=IMAGE,raw=str(RAW),checks=[],parent_address_space_limit=list(resource.getrlimit(resource.RLIMIT_AS)),scope='COORDINATOR11:20 allSIX on new currentimage/frozen1x10s/stats1/64G/CPUs0-7, sameflags/manifest/kernel/app2689. timingEX/imageSH/batchEX percase. Common read-only1s/8s phase map/stats probes, actualJIT/cache once perphase; noPMU/recurring cache copying. OTel extra existing unwindmap probes. Equalwork/install outcomes require actual collection; controller0 is not acceptance. Known host schedulingconfound, no speedclaim/fulltiming.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
def image_id():return subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip()
(LANE/'current-six-app-check.json').write_text(json.dumps(dict(pid=os.getpid(),result=str(OUT/'controller.json'),raw=str(RAW),log=str(HERE/'job.log')),indent=2)+'\n')
try:
 save();review=json.loads((HERE.parent/'ordered-image-refresh/collection-review.json').read_text());assert review['collection_status']==0 and review['current_image']==IMAGE
 newest=re.findall(r'^COORDINATOR (\S+):',(LANE/'resume-msg.md').read_text(),re.M)[-1];assert newest=='2026-11-28T11:20Z',newest;assert image_id()==IMAGE
 entry=ROOT/'kprog/perf/one-image/Makefile';apps=re.search(r'^ORDER \?= (.*)$',entry.read_text(),re.M)[1].split();assert len(apps)==6 and len(set(apps))==6;r['apps']=apps
 template=ROOT/'kprog/results/native-ebpf-alignment-20261128/observe-check.template.sh';script=template.read_text();script='#!/bin/bash\n# Newimage all-six frozencheck, readonly phase evidence only.\n'+script[script.index('set -u\n'):];a=script.index('mkdir -p /var/tmp/linkcache /var/tmp/map-observe');b=script.index('make -f $M guest',a);script=script[:a]+'python3 '+str(HERE/'observe_phases.py')+' $APP /var/tmp/phase-observe &\n'+script[b:];old='exec 8>$L/image; flock -s 8';assert script.count(old)==1;script=script.replace(old,old+'\n[ "$(docker image inspect --format \'{{.Id}}\' bpf-benchmark/kprog:current)" = "'+IMAGE+'" ] || exit 85\nexec 7>$L/batch; flock -x 7');assert script.count('$V/map-observe; do')==2;script=script.replace('$V/map-observe; do','$V/map-observe $V/phase-observe; do');assert 'nsenter' not in script and 'perf kvm' not in script
 r['source_sha256']={str(p.relative_to(ROOT)):sha(p) for p in [Path(__file__),HERE/'observe_phases.py',HERE/'dump_all.py',ROOT/'kprog/results/x86-otel-perf-20261127/observe_otel_maps.py',template,entry,ROOT/'corpus/driver.py']};r['kernel_sha256']=sha(Path('/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage'));save()
 for app in apps:
  assert image_id()==IMAGE and (LANE/'STOP').exists();assert subprocess.check_output(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','rev-parse','HEAD'],text=True).strip().startswith('2689a430');d=RAW/app.replace('/','__');d.mkdir();p=d/'observe.sh';p.write_text(script);subprocess.run(['bash','-n',str(p)],check=True);row=dict(app=app,started_utc=now(),raw=str(d),recipe_sha256=sha(p));r['checks'].append(row);save()
  with (d/'controller.log').open('wb') as f:row['returncode']=subprocess.run(['bash',str(p),app,str(d)],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT).returncode
  row['ended_utc']=now()
  for name in ['guest-exit.txt','profile-image.txt','profile-source.txt','run_dir']:
   if (d/name).exists():row[name]=(d/name).read_text().strip()
  row['image_matches']=row.get('profile-image.txt')==IMAGE;row['app_status']=None
  if row.get('run_dir'):
   af=Path(row['run_dir'])/'details/apps'/(app.replace('/','__')+'.json')
   if af.exists():row['app_status']=json.loads(af.read_text()).get('status');row['app_json']=str(af)
  o=d/'phase-observe/observer.json';row['observer_exists']=o.exists()
  if o.exists():
   try:obs=json.loads(o.read_text());row['phase_snapshot_counts']={ph:len(x.get('snapshots',[])) for ph,x in obs['phases'].items()};row['observer_exception']=obs.get('exception')
   except Exception:row['observer_parse_error']=traceback.format_exc()
  save()
 r.update(controller_status=int(any(x['returncode']!=0 or x.get('guest-exit.txt')!='0' or not x['image_matches'] or x['app_status']!='ok' for x in r['checks'])),phase='finished',next='Collect SAME actual guest/app/image/install requests/stats/maps/JIT/plans and phasecoverage. Controller0 is not equalwork/performance acceptance; archive full evidence before any duplicatecleanup.')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
