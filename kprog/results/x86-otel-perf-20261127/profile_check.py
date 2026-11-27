"""Host-PMU OTel diagnosis using the frozen check's effective guest settings."""
import hashlib,json,os,re,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
stamp=now();token=stamp.replace('-','').replace(':','');out=HERE/('profile-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/x86-otel-perf-20261127')/token;raw.mkdir(parents=True)
record=dict(pid=os.getpid(),started_utc=stamp,raw=str(raw),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),phase='profile',controller_status=None,scope='Current-image x86 OTel eBPF/native host PMU diagnosis under timingEX/imageSH. Effective frozen check settings1sample/10seconds/stats1, no full timing rerun or performance acceptance. Profile observers live outside benchmark.')
def save():(out/'controller.json').write_text(json.dumps(record,indent=2)+'\n')
(LANE/'otel-performance-profile.json').write_text(json.dumps(dict(result=str(out),raw=str(raw),pid=os.getpid()),indent=2)+'\n')
try:
 save();entry=ROOT/'kprog/perf/one-image/Makefile';text=entry.read_text();check=text.split('\ncheck:\n',1)[1]
 assert 'corpus APPS=$$a SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1' in check
 assert re.search(r'^VM_MEM \?= 64G$',text,re.M)
 old=ROOT/'kprog/results/profile-20261123/profile-host.sh';script=old.read_text()
 replacements={'SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0':'SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1','--cpus 8 --memory 32G':'--cpus 8 --memory 64G','taskset -c 8-23 $PERF':'taskset -c 19 $PERF','sleep 30':'sleep 2'}
 for a,b in replacements.items():assert script.count(a)==1,(a,script.count(a));script=script.replace(a,b)
 # Workload settings are the frozen check recipe, rather than the historical
 # profile's60s/stats-off settings. Poll only metadata more often for10s phases.
 path=raw/'profile-host-check.sh';path.write_text(script);path.chmod(0o755)
 record['source_sha256']={str(p.relative_to(ROOT)):hashlib.sha256(p.read_bytes()).hexdigest() for p in [Path(__file__),old,entry]}
 record['observer_changes']=replacements;record['effective_check']=dict(samples=1,workload_seconds=10,bpf_stats=1,guest_memory='64G')
 record['command']=['bash',str(path),'otelcol-ebpf-profiler/profiling',str(raw),'native_tracer_e'];save()
 with (raw/'controller.log').open('wb') as log:record['profile_returncode']=subprocess.run(record['command'],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT).returncode
 record['controller_status']=int(record['profile_returncode']!=0);record['phase']='finished'
 for n in ['guest-exit.txt','perf-exit.txt','profile-image.txt','profile-source.txt','run_dir']:
  p=raw/n
  if p.exists():record[n]=p.read_text().strip()
except Exception:record.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nx86 OTel priority host-PMU profile ended status '+str(record['controller_status'])+'. Read '+str(out/'controller.json')+' and actual guest/perf exits/program snapshots/corpus result; resolve both phases and largest native cost before changing common headers/flags/linker. No full timing claim.\n')
 print(json.dumps(record),flush=True)
raise SystemExit(record['controller_status'])
