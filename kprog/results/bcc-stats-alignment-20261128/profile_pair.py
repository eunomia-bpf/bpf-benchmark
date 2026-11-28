"""One current-image BCC stats0/stats1 PMU/code pair for the operator's alignment diagnosis."""
from pathlib import Path
import hashlib,json,os,re,resource,subprocess,traceback
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;OUT=HERE/'paired-profile';RAW=Path('/workspaces/kprog-raw/perf/bcc-stats-alignment-20261128/paired-profile');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf');sha=lambda b:hashlib.sha256(b).hexdigest();now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip();expected='sha256:6b88c0ba4c2253a3eadc999048dc39789185f7516b86a70ec14d098418610e11';assert not OUT.exists() and not RAW.exists();OUT.mkdir();RAW.mkdir(parents=True)
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='paired-current-image-observation',image_expected=expected,scope='Latest coordinator11:20 BCC stats-off bug/alignment diagnosis. ONEstats0/stats1 pair on unchanged current image, each default-check1sample/10s/64G settings except intended stats switch. No full rotate, tuning, app/P/kernel/image/source change. Observers are external to frozen benchmark.',host_address_space_limit_bytes=list(resource.getrlimit(resource.RLIMIT_AS)),raw=str(RAW),cases=[])
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
(LANE/'bcc-stats-profile.json').write_text(json.dumps(dict(pid=os.getpid(),result=str(OUT),raw=str(RAW)),indent=2)+'\n')
try:
 save();template=ROOT/'kprog/results/profile-20261123/profile-host.sh';entry=ROOT/'kprog/perf/one-image/Makefile';observer=ROOT/'kprog/results/x86-otel-perf-20261127/observe_otel_maps.py';text=entry.read_text();assert 'corpus APPS=$$a SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS=1' in text and re.search(r'^VM_MEM \?= 64G$',text,re.M);r['source_sha256']={str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in [Path(__file__),template,entry,observer,ROOT/'kprog/results/profile-20261123/dump-prog.py']};script=template.read_text();a=script.index('last_stress_pid=');b=script.index('(while true; do',script.index('done) &',a)+8);script=script[:a]+script[b:]
 replacements={'--cpus 8 --memory 32G':'--cpus 8 --memory 64G','taskset -c 8-23 $PERF':'taskset -c 19 $PERF','sleep 30':'sleep 2'}
 for a,b in replacements.items():assert script.count(a)==1;script=script.replace(a,b)
 old='exec 8>$L/image; flock -s 8';assert script.count(old)==1;script=script.replace(old,old+'\nexec 7>$L/batch; flock -x 7')
 line=next(s for s in script.splitlines() if 'if [ -n "$XLATED" ]' in s);capture='  for name in sys_enter sys_exit sched_switch; do python3 '+str(ROOT/'kprog/results/profile-20261123/dump-prog.py')+' \\$name /var/tmp/progdump/\\$u > /dev/null 2>&1; done';script=script.replace(line,capture+'\n  python3 '+str(observer)+' /var/tmp/map-observe/\\$u all-maps > /var/tmp/map-observe/\\$u.log 2>&1');script=script.replace('$V/stack-requests.txt; do','$V/stack-requests.txt $V/map-observe; do').replace('mkdir -p /var/tmp/linkcache','mkdir -p /var/tmp/linkcache /var/tmp/map-observe')
 r['effective_recipe']=dict(samples=1,workload_seconds=10,stats_modes=[0,1],guest_memory='64G',guest_cpus='0-7',host_pmu_cpu=19,locks=['timingEX','imageSH','batchEX'],program_dump_names=['sys_enter','sys_exit','sched_switch'],scope='Dump names select read-only observation only; every normal BCC program loads via the same manifest. SysRq loop removed,2sreadonly metadata polling and normal guest-mode PMU retained.');save()
 for stats in [0,1]:
  assert subprocess.check_output(['docker','image','inspect','--format','{{.Id}}','bpf-benchmark/kprog:current'],text=True).strip()==expected
  assert subprocess.check_output(['git','-C','vendor/repos/opentelemetry-ebpf-profiler','rev-parse','HEAD'],text=True).strip().startswith('2689a430')
  d=RAW/('stats'+str(stats));d.mkdir();old='SAMPLES=1 WORKLOAD_DURATION=60 BPFREJIT_CORPUS_BPF_STATS=0';assert script.count(old)==1;s=script.replace(old,'SAMPLES=1 WORKLOAD_DURATION=10 BPFREJIT_CORPUS_BPF_STATS='+str(stats));p=d/'profile-host.sh';p.write_text(s);subprocess.run(['bash','-n',str(p)],check=True);row=dict(stats=stats,started_utc=now(),raw=str(d),recipe_sha256=sha(p.read_bytes()),command=['bash',str(p),'bcc/set',str(d)]);r['cases'].append(row);save()
  with (d/'controller.log').open('wb') as log:row['profile_returncode']=subprocess.run(row['command'],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT).returncode
  row['ended_utc']=now()
  for n in ['guest-exit.txt','perf-exit.txt','profile-image.txt','profile-source.txt','run_dir']:
   if (d/n).exists():row[n]=(d/n).read_text().strip()
  row['image_matches']=row.get('profile-image.txt')==expected;save()
 r.update(controller_status=int(any(x['profile_returncode']!=0 or not x['image_matches'] for x in r['cases'])),phase='finished')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
