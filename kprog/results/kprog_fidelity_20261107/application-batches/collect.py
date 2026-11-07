#!/usr/bin/env python3
"""Read application service batch outcomes and kernel/worker input identities."""
from collections import Counter
import csv
import gzip
import hashlib
import io
import json
from pathlib import Path
import re
import subprocess
import tarfile

ROOT=Path(__file__).resolve().parents[4]
OUT=Path(__file__).resolve().parent
BASE='corpus/results/kprog_app_coverage_20261107/'
PUBLICATION='afc178f46e725fe96f85694d76fcf4c45c842914'

def sha(data):
    return hashlib.sha256(data).hexdigest()

def service_archive(payload):
    archive=tarfile.open(fileobj=io.BytesIO(payload))
    for depth in range(4):
        logs=[m.name for m in archive.getmembers() if m.isfile() and m.name.endswith('/service.log')]
        if logs:
            assert len(logs)==1
            return archive,logs[0]
        files=[m for m in archive.getmembers() if m.isfile()]
        assert len(files)==1
        nested=archive.extractfile(files[0]).read()
        archive.close();archive=tarfile.open(fileobj=io.BytesIO(nested))
    raise ValueError('service archive nesting depth')

def main():
    source_pins={}
    def published(path):
        data=subprocess.check_output(['git','show',PUBLICATION+':'+path],cwd=ROOT)
        source_pins[path]=dict(publication=PUBLICATION,sha256=sha(data),bytes=len(data))
        return data
    capture_manifest=json.loads((OUT/'captured-inputs.json').read_text())
    with tarfile.open(OUT/'captured-inputs.tar.gz') as capture:
        captured={name:capture.extractfile(name).read() for name in capture_manifest['files']}
    assert all(sha(data)==capture_manifest['files'][name]['sha256'] for name,data in captured.items())
    cases=[
      ('bcc','functional_153239',BASE+'native-only-runtime/standard-bcc-8g.json',
       BASE+'native-only-runtime/corpus-20261107T153640028572Z.tar.gz'),
      ('otel','functional_192310',BASE+'otel-narrow-load/coverage.json',BASE+'otel-narrow-load/service.tar.gz'),
      ('cilium','functional_201146',BASE+'native-modules-cilium__agent/coverage.json',BASE+'native-modules-cilium__agent/service.tar.gz'),
      ('tetragon','functional_201956',BASE+'native-coherent-tetragon__observer/coverage.json',BASE+'native-coherent-tetragon__observer/service.tar.gz'),
      ('katran','functional_201524',BASE+'native-coherent-katran/coverage.json',BASE+'native-coherent-katran/service.tar.gz'),
      ('tracee','functional_203243',BASE+'tracee-core-helper/coverage.json',BASE+'tracee-core-helper/service.tar.gz'),
      ('tetragon','functional_205401',None,'capture:tetragon-functional.service.tar.gz'),
      ('tetragon','timing_204105',None,'capture:tetragon-timing.service.tar.gz'),
    ]
    batches=[];records=[];failures=[];identity_sets={}
    for app,batch,metadata_path,service_path in cases:
        metadata=json.loads(published(metadata_path)) if metadata_path else {}
        payload=captured[service_path.split(':',1)[1]] if service_path.startswith('capture:') else published(service_path)
        service,log_path=service_archive(payload)
        with service:
            all_rows=[json.loads(line) for line in service.extractfile(log_path).read().splitlines()]
            terminal=[row for row in all_rows if 'request_id' in row]
            archives={m.name for m in service.getmembers() if m.isfile() and '/requests/' in m.name and m.name.endswith('.tar.gz')}
            consumed=set();request_ids=set();bound_ids=set();stages=Counter();generated=compiled=0
            for row in terminal:
                assert row['request_id']>0 and row['request_id'] not in request_ids
                request_ids.add(row['request_id'])
                key='artifact_archive' if row['status']==0 else 'failure_archive'
                matched=[name for name in archives if Path(name).name==Path(row[key]).name]
                assert len(matched)==1
                member=matched[0];assert member not in consumed;consumed.add(member)
                raw=service.extractfile(member).read()
                with tarfile.open(fileobj=io.BytesIO(raw)) as request:
                    names={m.name for m in request.getmembers() if m.isfile()}
                    def data(name):
                        return request.extractfile(name).read()
                    native=data('request/kernel.native.o')
                    assert native==data('request/generated/request.native.o')
                    assert sha(native)==row['native_sha256']
                    facts=json.loads(data('request/kernel.facts.json'))
                    assert facts['id']==row['source_prog_id']>0
                    commands=[json.loads(line) for line in data('request/generated/commands.jsonl').splitlines()]
                    identities=json.loads(data('request/source-identities.json'))
                    identity_key=sha(json.dumps(identities,sort_keys=True).encode())
                    identity_sets[identity_key]=identities
                    sources=[n for n in names if n.startswith('request/generated/trusted_') and n.endswith('.bpf.c')]
                    objects=[n for n in names if n.startswith('request/generated/trusted_') and n.endswith('.bpf.o') and request.getmember(n).size>0]
                    generated+=bool(sources);compiled+=bool(objects)
                    entry=data('request/kernel.entry').decode().strip()
                    error=json.loads(data('request/error.json')) if 'request/error.json' in names else {}
                    stderr=data('request/load.stderr').decode() if 'request/load.stderr' in names else ''
                    failed_commands=[c for c in commands if c['returncode']]
                    if row['status']==0:
                        load=json.loads(data('request/load.stdout'))
                        assert load=={key:row[key] for key in ['request_id','prog_id','status']}
                        assert row['prog_id']>0 and row['prog_id'] not in bound_ids
                        assert sources and objects and all(c['returncode']==0 for c in commands)
                        bound_ids.add(row['prog_id']);stage='bound'
                    elif failed_commands:
                        compiler=[c for c in failed_commands if '-target' in c['command'] and 'bpf' in c['command']]
                        stage='compiler_rejected' if compiler else 'specialization_rejected'
                    elif not sources:
                        stage='specialization_rejected'
                    elif ('BPF program load failed' in stderr or 'load simulator program' in stderr
                          or ('BPF_PROG_LOAD' in stderr and re.search(r'processed \d+ insns \(limit \d+\)',stderr))):
                        stage='verifier_rejected'
                    else:
                        stage='loader_rejected'
                    statistics=re.search(r'processed (\d+) insns \(limit (\d+)\).*?total_states (\d+) peak_states (\d+)',stderr)
                    verifier_stats=(dict(processed=int(statistics[1]),limit=int(statistics[2]),
                                         total_states=int(statistics[3]),peak_states=int(statistics[4]))
                                    if statistics else {})
                    stages[stage]+=1
                    record=dict(app=app,batch=batch,request_id=row['request_id'],source_prog_id=row['source_prog_id'],
                                bound_prog_id=row.get('prog_id',''),entry=entry,status=row['status'],stage=stage,
                                generated_source=bool(sources),compiled_object=bool(objects),
                                kernel_worker_receipt_identity_equal=True,native_sha256=sha(native),
                                request_archive_sha256=sha(raw),recorded_source_set_sha256=identity_key,
                                error=error.get('error',row.get('error','')),
                                verifier_statistics=json.dumps(verifier_stats,separators=(',',':')),
                                command_returns=json.dumps([dict(executable=Path(c['command'][0]).name,returncode=c['returncode']) for c in commands],separators=(',',':')))
                    records.append(record)
                    if row['status']:
                        failures.append(dict(app=app,batch=batch,request_id=row['request_id'],entry=entry,
                                             stage=stage,error_json=error,service_error=row.get('error',''),
                                             loader_stderr=stderr,verifier_statistics=verifier_stats,commands=commands))
            assert consumed==archives
            baseline=metadata.get('baseline_load_observations',{})
            counts=dict(terminal_requests=len(terminal),generated=generated,compiled=compiled,accepted_bound=stages['bound'])
            compare={}
            for found,recorded in [('terminal_requests','native_requests'),('generated','generated'),('compiled','compiled'),('accepted_bound','accepted_bound')]:
                if recorded in metadata:
                    compare[found]=dict(observed=counts[found],recorded=metadata[recorded],equal=counts[found]==metadata[recorded])
            for found,recorded in [('generated','proof_generated'),('accepted_bound','bound_loads'),('accepted_bound','verifier_accepted')]:
                if recorded in metadata:
                    compare[recorded]=dict(observed=counts[found],recorded=metadata[recorded],equal=counts[found]==metadata[recorded])
            for stage,recorded in [('specialization_rejected','specialization_failed'),('verifier_rejected','verifier_rejected')]:
                if recorded in metadata:
                    compare[recorded]=dict(observed=stages[stage],recorded=metadata[recorded],equal=stages[stage]==metadata[recorded])
            if 'programs_total' in metadata:
                compare['terminal_requests']=dict(observed=len(terminal),recorded=metadata['programs_total'],equal=len(terminal)==metadata['programs_total'])
            batches.append(dict(app=app,batch=batch,metadata_path=metadata_path,service_path=service_path,
                                service_sha256=sha(payload),**counts,stages=dict(stages),
                                app_status=metadata.get('app_status','captured_service_batch'),
                                baseline_accepted_loads=baseline.get('application_accepted_loads'),
                                baseline_resident_counters=len(metadata.get('baseline',{}).get('bpf',{})),
                                recorded_counts=compare))
    shim=captured['tetragon-timing.shim.log'].decode()
    failure_names={re.search(r'prog=(\S+)',line)[1] for line in shim.splitlines() if 'native-loader failed ' in line}
    load_rows=[]
    for line in shim.splitlines():
        if 'BPF_PROG_LOAD ' not in line:continue
        name=re.search(r'name=(\S+)',line)
        count=re.search(r'insn_cnt=(\d+)',line)
        if name and count and name[1] in failure_names:
            load_rows.append(dict(name=name[1],insn_cnt=int(count[1]),bytes=int(count[1])*8,raw_line=line))
    timing_metadata=json.loads(captured['tetragon-timing.metadata.json'])
    timing_result=json.loads(captured['tetragon-timing.result.json'])
    summary=dict(source_publication=PUBLICATION,batches=batches,terminal_requests=len(records),
                 stages=dict(Counter(record['stage'] for record in records)),
                 kernel_worker_receipt_identity_matches=len(records),input_artifacts=source_pins,
                 captured_input_manifest=capture_manifest,captured_input_archive_sha256=sha((OUT/'captured-inputs.tar.gz').read_bytes()),
                 recorded_count_matches=all(row['equal'] for batch in batches for row in batch['recorded_counts'].values()),
                 timing_context=dict(metadata_status=timing_metadata['status'],result_status=timing_result['status'],
                                     samples=timing_result['samples'],workload_seconds=timing_result['workload_seconds'],
                                     failed_load_extents=load_rows),
                 scope='Whole captured application/service batch observations and kernel/worker byte identities.')
    with (OUT/'terminal-requests.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(records[0]),delimiter='\t',lineterminator='\n')
        writer.writeheader();writer.writerows(records)
    (OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    (OUT/'recorded-source-identities.json').write_text(json.dumps(identity_sets,indent=2)+'\n')
    (OUT/'failures.jsonl.gz').write_bytes(gzip.compress((''.join(json.dumps(row)+'\n' for row in failures)).encode(),mtime=0))
    print(json.dumps(dict(batches=len(batches),requests=len(records),stages=summary['stages'],
                         identity_matches=len(records),recorded_counts_match=summary['recorded_count_matches'],
                         timing_failed_extents=load_rows),indent=2))
    return 0

if __name__=='__main__':
    raise SystemExit(main())
