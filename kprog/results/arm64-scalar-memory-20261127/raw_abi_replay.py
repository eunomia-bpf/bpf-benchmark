"""Replay all145 captured B inputs with the common nested RAW-ABI probe route."""
import hashlib,json,os,subprocess,tarfile,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
PRIOR=HERE/'run-20261127T161303Z'
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
stamp=now();token=stamp.replace('-','').replace(':','');out=HERE/('raw-abi-'+token);out.mkdir();raw=Path('/workspaces/kprog-raw/perf/arm64-raw-abi-20261127')/token;raw.mkdir(parents=True)
record=dict(pid=os.getpid(),started_utc=stamp,source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),phase='recover-committed-inputs',controller_status=None,scope='All145 captured inputs, previous45 stock-accepted controls/100refused. Same common ARM flags/kernel/fresh map fixtures/capped2workers. This is a RAW-ABI routing replay, not an exclusive-retry replacement, native install or app startup claim.',raw=str(raw),result=str(out))
def save():(out/'pipeline-controller.json').write_text(json.dumps(record,indent=2)+'\n')
manifest=out/'manifest.json';manifest.write_text(json.dumps(dict(raw=str(raw),result=str(out)),indent=2)+'\n')
(LANE/'raw-abi-replay.json').write_text(json.dumps(dict(result=str(out),raw=str(raw),manifest=str(manifest),pid=os.getpid()),indent=2)+'\n')
try:
 save();old=json.loads((PRIOR/'prepare-controller.json').read_text());outcomes={r['index']:r for r in json.loads((PRIOR/'outcomes.json').read_text())['requests']};assert len(outcomes)==145
 receipt=json.loads((PRIOR/'controller.json').read_text());wanted={}
 for r in old['inputs']:
  for name,new in [('after.bpf.c','after.bpf.c'),('after.bpf.o','before.bpf.o'),('generation.metadata.json','generation.metadata.json'),('kernel.facts.json','kernel.facts.json')]:
   wanted[str(r['index'])+'/'+name]=str(r['index'])+'/'+new
 wanted['tools/archive-stock']='tools/archive-stock'
 parts=sorted(PRIOR.glob('evidence.tar.zst.part-*'))
 for p in parts:
  assert subprocess.check_output(['git','ls-tree','HEAD','--',str(p.relative_to(ROOT))],text=True).split()[2]==subprocess.check_output(['git','hash-object',str(p)],text=True).strip()
 a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();found=set()
 with tarfile.open(fileobj=b.stdout,mode='r|') as archive:
  for m in archive:
   p=Path(m.name)
   if not m.isfile() or p.parts[0]!='20261127T161303Z':continue
   rel=str(Path(*p.parts[1:]))
   if rel not in wanted:continue
   data=archive.extractfile(m).read();assert receipt['archive_files'][rel]==dict(bytes=len(data),sha256=hashlib.sha256(data).hexdigest())
   dst=raw/wanted[rel];dst.parent.mkdir(parents=True,exist_ok=True);dst.write_bytes(data);dst.chmod(m.mode);found.add(rel)
 b.stdout.close();assert a.wait()==b.wait()==0 and found==set(wanted)
 inputs=[]
 for item in old['inputs']:
  r={k:item[k] for k in ['index','app','request','symbol','normalized_source_sha256']}
  r.update(baseline_object='before.bpf.o',baseline_kind='previous-common-scalar-probe',original_stock_passed=outcomes[r['index']]['after']['status']=='accepted',initial_stock_passed=item['original_stock_passed'])
  inputs.append(r)
 assert sum(r['original_stock_passed'] for r in inputs)==45
 (out/'prepare-controller.json').write_text(json.dumps(dict(controller_status=0,raw=str(raw),inputs=inputs,source_archive=str(PRIOR),verified_files=len(found)),indent=2)+'\n')
 (out/'stock-build.json').write_text(json.dumps(dict(status=0,tool='Reused exact committed prior archive-stock executable',sha256=hashlib.sha256((raw/'tools/archive-stock').read_bytes()).hexdigest()),indent=2)+'\n')
 record.update(verified_files=len(found),phase='compile-all145');save()
 for name,phase in [('compile.py','compile-all145'),('stock_controller.py','paired-stock-all145')]:
  record['phase']=phase;save()
  with (raw/(name+'.log')).open('wb') as log:
   child=subprocess.Popen(['taskset','-c','19','python3',str(HERE/name),'--manifest',str(manifest)],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT);record['child_pid']=child.pid;save();code=child.wait()
  record[name+'_returncode']=code;save();assert code==0,name
 stock=json.loads((out/'all145-stock-controller.json').read_text());assert len(stock['stock']['cases'])==145
 record.update(controller_status=0,phase='finished')
except Exception:record.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:
 record['ended_utc']=now();save()
 with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM RAW-ABI all145 replay ended status '+str(record['controller_status'])+'. Read '+str(out/'pipeline-controller.json')+' and actual compile/stock controllers; collect/archive/publish/everyfileverifieddedup next. Preserve RAW until publication. No native/stage2 acceptance implied.\n')
 print(json.dumps(record),flush=True)
raise SystemExit(record['controller_status'])
