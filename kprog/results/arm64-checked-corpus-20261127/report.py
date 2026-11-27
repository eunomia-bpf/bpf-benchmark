"""Read actual corpus workload and stock/checked/direct receipts outside the framework."""
import collections
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile
HERE=Path(__file__).resolve().parent
folder=HERE/('guest-'+sys.argv[1] if len(sys.argv)>1 else 'guest-20261127T012418Z');controller=json.loads((folder/'controller.json').read_text());raw=Path(controller['raw']);app_name=controller['cases'][0]['app'];case=raw/app_name.replace('/','-')
destination=folder if len(sys.argv)>1 else HERE;prefix=app_name.split('/')[0]
paths=json.loads((case/'corpus-paths.json').read_text());run=next(Path(x) for x in paths if Path(x).name.startswith('arm64_qemu_corpus_'))
corpus=json.loads((run/'details/result.json').read_text());app=json.loads((run/'details/apps'/(app_name.replace('/','__')+'.json')).read_text())
report=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),controller_status=controller['controller_status'],revision=controller['revision'],corpus_status=corpus['status'],app_status=app['status'],app_error=app['error'],samples=corpus['samples'],requested_workload_seconds=corpus['workload_seconds'],warmups=corpus['warmups'],bpf_stats=corpus['bpf_stats'],workload=app['selected_workload'],phases={},requests=[])
for phase in ['baseline','post_rejit']:
 data=app[phase]
 if data is None:
  report['phases'][phase]=None
  continue
 report['phases'][phase]=dict(programs=data['bpf'],workloads=data['workloads'],installed_programs=len(data['bpf']),programs_with_calls=sum(x['run_cnt_delta']>0 for x in data['bpf'].values()))
with tarfile.open(case/'service.tar.gz') as outer:
 receipts=[json.loads(x) for x in outer.extractfile('service/service.log').read().decode().splitlines() if '"request_id"' in x]
 for receipt in receipts:
  row={k:receipt.get(k) for k in ['request_id','source_prog_id','prog_id','phase','status','execution_path','b_generated','b_stock_passed','error']}
  if row['status'] != 0:row['execution_path']='failed'
  suffix='.success.tar.gz' if row['status']==0 else '.failure.tar.gz'
  member=next(m for m in outer.getmembers() if m.isfile() and m.name.endswith('/'+str(receipt['request_id'])+suffix))
  with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as inner:
   files={Path(m.name).name:m for m in inner.getmembers() if m.isfile()}
   if 'artifacts.json' in files:
    art=json.loads(inner.extractfile(files['artifacts.json']).read());row['symbol']=art['symbol']
   else:row['symbol']=inner.extractfile(files['kernel.entry']).read().decode().strip()
   row['metadata']=json.loads(inner.extractfile(files['generation.metadata.json']).read())
   row['verifier_log']=inner.extractfile(files['verify.stderr']).read().decode() if 'verify.stderr' in files else None
   if 'simulator-failure.json' in files:
    row['simulator_failure']=json.loads(inner.extractfile(files['simulator-failure.json']).read())
    row['b_generated']=row['simulator_failure']['stage']!='generation'
    row['b_stock_passed']=False
   for name in ['load-direct.stderr','load.stderr','commands.jsonl']:
    if name in files:row[name]=inner.extractfile(files[name]).read().decode()
   if 'checked-simulator-verification.json' in files:
    row['stock_verification']=json.loads(inner.extractfile(files['checked-simulator-verification.json']).read())
    if row['stock_verification'].get('status') == 0:
     row['b_generated']=True
     row['b_stock_passed']=True
   if 'native-commands.jsonl' in files:row['native_commands']=[json.loads(x) for x in inner.extractfile(files['native-commands.jsonl']).read().decode().splitlines() if x.strip()]
  if receipt.get('simulator_failure'):row['simulator_failure']=receipt['simulator_failure']
  # Observed diagnostics only; no execution or admission selection.
  markers=['infinite loop detected','dereference of modified ctx','invalid mem access',"doesn't have 2-th argument","doesn't have field",'invalid bpf_context','unbounded memory access']
  row['diagnostics']=[line for line in row['verifier_log'].splitlines() if any(marker in line for marker in markers)] if row['verifier_log'] is not None else []
  if 'load-direct.stderr' in row:row['diagnostics'] += [line for line in row['load-direct.stderr'].splitlines() if line.startswith('Error:')]
  post_id=receipt['prog_id'] if row['status']==0 else receipt['source_prog_id']
  row['post_prog_id']=post_id
  row['post_counters']=(app['post_rejit'] or {}).get('bpf',{}).get(str(post_id))
  row['post_uses_original']=row['status']!=0 and row['post_counters'] is not None
  report['requests'].append(row)
report['counts']=dict(collections.Counter(x['execution_path'] for x in report['requests']))
report['broker_failures']=[dict(path=str(path),**json.loads(path.read_text())) for path in sorted((raw/'broker').rglob('*.result.json')) if json.loads(path.read_text())['returncode']!=0]
report['test_run']='Frozen corpus workload and attachment receipts; phase presence is recorded above. No separate TEST_RUN oracle.'
report['scope']=f'{app_name} ARM QEMU functional corpus requested one sample per phase; recorded phases show completed data. Direct fallbacks are not checked proof coverage; no timing/performance claim.'
(destination/(prefix+'-outcome.json')).write_text(json.dumps(report,indent=2)+'\n')
with (destination/(prefix+'-programs.tsv')).open('w') as f:
 f.write('request\tsymbol\tprog_type\tnative_id\tsource_prog_id\tpost_prog_id\tpost_uses_original\tb_generated\tb_stock_passed\texecution_path\tstatus\trun_cnt_delta\trun_time_ns_delta\tdiagnostics\n')
 for x in report['requests']:
  f.write('\t'.join(str(v) for v in [x['request_id'],x['symbol'],x['metadata']['prog_type'],x['prog_id'],x['source_prog_id'],x['post_prog_id'],x['post_uses_original'],x['b_generated'],x['b_stock_passed'],x['execution_path'],x['status'],x['post_counters']['run_cnt_delta'] if x['post_counters'] else None,x['post_counters']['run_time_ns_delta'] if x['post_counters'] else None,'; '.join(x.get('diagnostics',[]))])+'\n')
print('Corpus/app',report['corpus_status'],report['app_status'],'mix',report['counts'])
for phase,p in report['phases'].items():
 if p is None:
  print(phase,'absent; app status',report['app_status'],'error',str(report['app_error']).splitlines()[0])
 else:
  print(phase,'programs',p['installed_programs'],'with calls',p['programs_with_calls'],'workloads',[(x['workload_name'],x['returncode'],x['duration_s']) for w in p['workloads'] for x in ([w] if 'returncode' in w else w['components'])])
for row in report['requests']:
 if row.get('diagnostics'):print(row['request_id'],row['symbol'],row['diagnostics'])
