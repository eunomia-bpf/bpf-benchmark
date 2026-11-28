"""One frozen10s check per remaining app, read-only snapshots, no PMU or tuning."""
import json,os,re,resource,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
token=now().replace('-','').replace(':','');out=HERE/('check-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/native-ebpf-alignment-20261128')/token;raw.mkdir(parents=True)
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='checks',raw=str(raw),checks=[],reuse_otel='kprog/results/x86-otel-perf-20261127/profile-20261128T033629Z',scope='Coordinator03:24 bug/alignment checks. Reuse same-image OTel once; remaining5 apps once by frozen check recipe, stats1/1sample/10s/64G. No PMU, new image or full timing.',parent_address_space_limit_bytes=list(resource.getrlimit(resource.RLIMIT_AS)))
def save():(out/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
(LANE/'alignment-check.json').write_text(json.dumps(dict(pid=os.getpid(),result=str(out),raw=str(raw)),indent=2)+'\n')
try:
 entry=ROOT/'kprog/perf/one-image/Makefile';text=entry.read_text();apps=re.search(r'^ORDER \?= (.*)$',text,re.M)[1].split();assert apps[0]=='otelcol-ebpf-profiler/profiling'
 assert 'corpus APPS=$$a SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1' in text
 image=subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip();assert image=='sha256:6b88c0ba4c2253a3eadc999048dc39789185f7516b86a70ec14d098418610e11';r['image']=image;save()
 base=(ROOT/'kprog/results/profile-20261123/profile-host.sh').read_text()
 # Keep its guest/runtime/lock/RAW collection path; remove PMU and SysRq observers.
 a=base.index('last_stress_pid=');b=base.index('(while true; do',base.index('done) &',a)+8);base=base[:a]+base[b:]
 a=base.index('if [ -n "${EVENT:-}" ]');b=base.index('timeout 900 taskset',a);base=base[:a]+base[b:]
 a=base.index('stop_requested=0');b=base.index('for f in $V/kallsyms',a);base=base[:a]+'printf \'%s\\n\' "$guest_rc" > $OUT/guest-exit.txt\n'+base[b:]
 a=base.index('if [ "$guest_rc" != 0 ]');base=base[:a]+'exit "$guest_rc"\n'
 for a,b in {'SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0':'SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1','--cpus 8 --memory 32G':'--cpus 8 --memory 64G','sleep 30':'sleep 2'}.items():assert base.count(a)==1;base=base.replace(a,b)
 line=next(x for x in base.splitlines() if 'if [ -n "$XLATED" ]' in x);base=base.replace(line,'  python3 '+str(ROOT/'kprog/results/x86-otel-perf-20261127/observe_otel_maps.py')+' /var/tmp/map-observe/\\$u all-maps > /var/tmp/map-observe/\\$u.log 2>&1')
 base=base.replace('$V/stack-requests.txt; do','$V/stack-requests.txt $V/map-observe; do').replace('mkdir -p /var/tmp/linkcache','mkdir -p /var/tmp/linkcache /var/tmp/map-observe')
 for app in apps[1:]:
  d=raw/app.replace('/','__');d.mkdir();script=d/'observe-check.sh';script.write_text(base);subprocess.run(['bash','-n',str(script)],check=True)
  row=dict(app=app,raw=str(d),started_utc=now());r['checks'].append(row);save()
  with (d/'controller.log').open('wb') as log:row['returncode']=subprocess.run(['bash',str(script),app,str(d)],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT).returncode
  row['ended_utc']=now();row['run']=(d/'run_dir').read_text().strip() if (d/'run_dir').exists() else None;save()
 r.update(controller_status=int(any(x['returncode']!=0 for x in r['checks'])),phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
