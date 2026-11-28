"""Finish only the manifest join using the verified existing census and plan archive."""
from pathlib import Path
import collections,hashlib,json,os,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;INV=OUT.parent/'arm64-frozen-ir/alignment-inventory'
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='join-existing-outputs',scope='Only the failed join stage; completed census/annotation and original324-plan archive retained.')
try:
 os.sched_setaffinity(0,{19});v=json.loads((OUT/'inventory-census-validation.json').read_text())
 for name,row in v['outputs'].items():assert sha(ROOT/name)==row['sha256'],name
 archive=OUT/'runtime-plans.json.zst';meta=json.loads((OUT/'runtime-plans-archive.json').read_text());assert sha(archive)==meta['sha256'];data=subprocess.check_output(['zstd','-dc',str(archive)]);assert len(data)==meta['uncompressed']['bytes'] and hashlib.sha256(data).hexdigest()==meta['uncompressed']['sha256'];report=json.loads(data)
 index=collections.defaultdict(list)
 for row in json.loads((INV/'programs.json').read_text()):
  for name in row['symbol_candidates']:index[(row['architecture'],row['app'],name)].append(dict(object=row['object'],symbol_resolution=row['symbol_resolution'],manifest_symbol=row['manifest_symbol']))
 updates=[];missing=[];complete=0
 for row in report['plans']:
  if not row['entry']:continue
  complete+=1;candidates=index[(row['architecture'],row['app'],row['entry'])]
  if candidates!=row['manifest_candidates']:updates.append(dict(architecture=row['architecture'],app=row['app'],cache_key=row['cache_key'],entry=row['entry'],proof=row['proof_origin'],old_candidates=row['manifest_candidates'],corrected_candidates=candidates))
  if not candidates:missing.append(dict(architecture=row['architecture'],app=row['app'],cache_key=row['cache_key'],entry=row['entry']))
 result=dict(scope='Addendum to retained324-plan report. Full proof entries match corrected static manifest candidates; original source-object/program-to-map identity and semantic equality remain separate.',original_report_sha256=meta['uncompressed']['sha256'],verified_census_outputs=v['outputs'],updates=updates,complete_entry_plan_count=complete,captured_proof_gaps=report['proof_capture_gaps'],remaining_complete_entries_without_candidates=missing,prior_wrapper='1344048 retained a guessed exactly-one-update assertion. This stage records every actual candidate update and missing match.')
 (OUT/'manifest-join-addendum.json').write_text(json.dumps(result,indent=2)+'\n');r.update(controller_status=0,phase='finished-join-review-ready',complete_entry_plan_count=complete,join_updates=len(updates),changed_entries=[x['entry'] for x in updates],remaining_complete_entries_without_candidates=len(missing),captured_proof_gaps=len(report['proof_capture_gaps']),outputs={'manifest-join-addendum.json':dict(bytes=(OUT/'manifest-join-addendum.json').stat().st_size,sha256=sha(OUT/'manifest-join-addendum.json'))})
except Exception:r.update(controller_status=1,phase='failed-receipts-retained',exception=traceback.format_exc())
finally:r['ended_utc']=now();(OUT/'inventory-join-controller.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
