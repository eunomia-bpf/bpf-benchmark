"""Read actual BCC workload and stock/checked/direct receipts outside the framework."""
import collections
import io
import json
from pathlib import Path
import subprocess
import tarfile
HERE=Path(__file__).resolve().parent
folder=HERE/'guest-20261127T012418Z';controller=json.loads((folder/'controller.json').read_text());raw=Path(controller['raw']);case=raw/'bcc-set'
paths=json.loads((case/'corpus-paths.json').read_text());run=next(Path(x) for x in paths if Path(x).name.startswith('arm64_qemu_corpus_'))
corpus=json.loads((run/'details/result.json').read_text());app=json.loads((run/'details/apps/bcc__set.json').read_text())
report=dict(utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),controller_status=controller['controller_status'],revision=controller['revision'],corpus_status=corpus['status'],app_status=app['status'],app_error=app['error'],samples=corpus['samples'],requested_workload_seconds=corpus['workload_seconds'],warmups=corpus['warmups'],bpf_stats=corpus['bpf_stats'],workload=app['selected_workload'],phases={},requests=[])
for phase in ['baseline','post_rejit']:
 data=app[phase];report['phases'][phase]=dict(programs=data['bpf'],workloads=data['workloads'],installed_programs=len(data['bpf']),programs_with_calls=sum(x['run_cnt_delta']>0 for x in data['bpf'].values()))
with tarfile.open(case/'service.tar.gz') as outer:
 receipts=[json.loads(x) for x in outer.extractfile('service/service.log').read().decode().splitlines() if '"request_id"' in x]
 for receipt in receipts:
  row={k:receipt.get(k) for k in ['request_id','source_prog_id','prog_id','phase','status','execution_path','b_generated','b_stock_passed','error']}
  member=next(m for m in outer.getmembers() if m.isfile() and m.name.endswith('/'+str(receipt['request_id'])+'.success.tar.gz'))
  with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as inner:
   files={Path(m.name).name:m for m in inner.getmembers() if m.isfile()}
   art=json.loads(inner.extractfile(files['artifacts.json']).read());row['symbol']=art['symbol']
   row['metadata']=json.loads(inner.extractfile(files['generation.metadata.json']).read())
   row['verifier_log']=inner.extractfile(files['verify.stderr']).read().decode()
   if 'checked-simulator-verification.json' in files:row['stock_verification']=json.loads(inner.extractfile(files['checked-simulator-verification.json']).read())
   if 'native-commands.jsonl' in files:row['native_commands']=[json.loads(x) for x in inner.extractfile(files['native-commands.jsonl']).read().decode().splitlines() if x.strip()]
  if receipt.get('simulator_failure'):
   row['simulator_failure']=receipt['simulator_failure'];text=row['verifier_log']
   # Reporting of observed diagnostics only; no execution or admission selection.
   markers=['infinite loop detected','dereference of modified ctx','invalid mem access','doesn\'t have 2-th argument','doesn\'t have field','invalid bpf_context']
   row['diagnostics']=[line for line in text.splitlines() if any(marker in line for marker in markers)]
  row['post_counters']=app['post_rejit']['bpf'][str(receipt['prog_id'])]
  report['requests'].append(row)
report['counts']=dict(collections.Counter(x['execution_path'] for x in report['requests']))
report['test_run']='Frozen corpus baseline/post workload and attachment, no separate TEST_RUN oracle.'
report['scope']='One BCC/set functional sample per phase on ARM QEMU. Direct fallbacks are not checked proof coverage; no timing/performance claim.'
(HERE/'bcc-outcome.json').write_text(json.dumps(report,indent=2)+'\n')
with (HERE/'bcc-programs.tsv').open('w') as f:
 f.write('request\tsymbol\tprog_type\tnative_id\tb_generated\tb_stock_passed\texecution_path\tstatus\trun_cnt_delta\trun_time_ns_delta\tdiagnostics\n')
 for x in report['requests']:
  f.write('\t'.join(str(v) for v in [x['request_id'],x['symbol'],x['metadata']['prog_type'],x['prog_id'],x['b_generated'],x['b_stock_passed'],x['execution_path'],x['status'],x['post_counters']['run_cnt_delta'],x['post_counters']['run_time_ns_delta'],'; '.join(x.get('diagnostics',[]))])+'\n')
print('Corpus/app',report['corpus_status'],report['app_status'],'mix',report['counts'])
for phase,p in report['phases'].items():print(phase,'programs',p['installed_programs'],'with calls',p['programs_with_calls'],'workloads',[(x['returncode'],x['duration_s']) for x in p['workloads']])
for row in report['requests']:
 if row.get('diagnostics'):print(row['request_id'],row['symbol'],row['diagnostics'])
