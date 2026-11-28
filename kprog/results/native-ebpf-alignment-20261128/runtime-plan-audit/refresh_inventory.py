"""Refresh the existing static census and join addendum after generic name correction."""
from pathlib import Path
import collections,hashlib,json,os,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;INV=OUT.parent/'arm64-frozen-ir/alignment-inventory'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='preflight',scope='Metadata census reader and static manifest join correction only; current native objects, app binaries, kernels, images and live guests retained.')
def save():(OUT/'inventory-refresh-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 os.sched_setaffinity(0,{19});prep=json.loads((OUT/'inventory-refresh-preparation.json').read_text());assert sha(INV/'inventory.py')==prep['reader_sha256']
 for n,x in prep['before_outputs'].items():assert sha(INV/n)==x['sha256'] and subprocess.check_output(['git','rev-parse','HEAD:'+str((INV/n).relative_to(ROOT))],text=True).strip()==x['git_blob']
 old=json.loads((INV/'programs.json').read_text());old_objects=json.loads((INV/'objects.json').read_text());old_manifests=json.loads((INV/'manifests.json').read_text());r['before_classification']=dict(collections.Counter(x['symbol_resolution'] for x in old));save()
 for label,script in [('reader','inventory.py'),('annotation','annotate_mechanisms.py')]:
  r['phase']=label;save()
  with (OUT/('inventory-'+label+'.log')).open('wb') as f:r[label+'_returncode']=subprocess.run(['python3',str(INV/script)],cwd=ROOT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT).returncode
  assert r[label+'_returncode']==0
 new=json.loads((INV/'programs.json').read_text());new_objects=json.loads((INV/'objects.json').read_text());summary=json.loads((INV/'summary.json').read_text());assert len(old)==len(new)==698 and len(new_objects)==114
 assert old_objects==new_objects and old_manifests==json.loads((INV/'manifests.json').read_text());r['native_object_metadata_equal']=True;r['manifest_metadata_equal']=True
 changes=[]
 for before,after in zip(old,new):
  assert tuple(before[k] for k in ['architecture','app','program','object'])==tuple(after[k] for k in ['architecture','app','program','object'])
  if before!=after:changes.append(dict(before=before,after=after))
 expected={(a,b,p) for a in ['x86','arm64'] for b,p in [('tracee','trace_vfs_write'),('tetragon','filter_char_buf')]};assert {(x['after']['architecture'],x['after']['app'],x['after']['program']) for x in changes}==expected and len(changes)==4
 assert summary['symbol_resolution']=={'exact':600,'ambiguous-prefix':98} and not summary['missing_ir'] and not summary['isa_mismatches'];r['after_classification']=summary['symbol_resolution'];r['changed_rows']=4
 (OUT/'inventory-name-correction.json').write_text(json.dumps(dict(scope='All siblings sharing a kernel15-byte name remain candidates when manifest symbol is unspecified. Explicit symbols retain their existing selection.',changes=changes),indent=2)+'\n')
 data=subprocess.check_output(['zstd','-dc',str(OUT/'runtime-plans.json.zst')]);original=json.loads((OUT/'controller.json').read_text());assert hashlib.sha256(data).hexdigest()==original['outputs']['runtime-plans.json']['sha256'];plans=json.loads(data)['plans'];index=collections.defaultdict(list)
 for row in new:
  for name in row['symbol_candidates']:index[(row['architecture'],row['app'],name)].append(dict(object=row['object'],symbol_resolution=row['symbol_resolution'],manifest_symbol=row['manifest_symbol']))
 updates=[];missing=[]
 for row in plans:
  if not row['entry']:continue
  candidates=index[(row['architecture'],row['app'],row['entry'])]
  if candidates!=row['manifest_candidates']:updates.append(dict(architecture=row['architecture'],app=row['app'],cache_key=row['cache_key'],entry=row['entry'],proof=row['proof_origin'],old_candidates=row['manifest_candidates'],corrected_candidates=candidates))
  if not candidates:missing.append(dict(architecture=row['architecture'],app=row['app'],cache_key=row['cache_key'],entry=row['entry']))
 assert not missing and len(updates)==1 and updates[0]['entry']=='trace_vfs_writev';r['complete_entries_without_inventory_candidates']=0;r['join_updates']=len(updates)
 (OUT/'manifest-join-addendum.json').write_text(json.dumps(dict(scope='Addendum to retained original324-plan report. Full proof entry identity matches the corrected static manifest candidates; actual source-object/program-to-map ID and semantic equality remain separate.',original_report_sha256=original['outputs']['runtime-plans.json']['sha256'],updates=updates,complete_entry_count=sum(bool(x['entry']) for x in plans),captured_proof_gaps=2,remaining_complete_entries_without_candidates=missing),indent=2)+'\n')
 files=[INV/n for n in ['programs.json','objects.json','manifests.json','summary.json','programs.tsv']]+[OUT/'inventory-name-correction.json',OUT/'manifest-join-addendum.json'];r['outputs']={str(p.relative_to(ROOT)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in files};r.update(controller_status=0,phase='finished-census-and-addendum-review-pending')
except Exception:r.update(controller_status=1,phase='failed-receipts-retained',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:v for k,v in r.items() if k!='outputs'}),flush=True)
raise SystemExit(r['controller_status'])
