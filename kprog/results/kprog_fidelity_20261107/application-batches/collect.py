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
JOIN_PUBLICATION='21cf7278605fc3b4b6468b3bec639badec9ab0fb'
KATRAN_PUBLICATION='3993aa884362093ba6821db4e97cdded89504d99'
ARM_PUBLICATION='5d0d953946ffe83e2a958b8d6c6990850bb86531'
ARM_BASE='corpus/results/kprog_arm64_app_coverage_20261107/trusted-arm64-tracee-result/'
ARM_PASS_PUBLICATION='57db4da4387f19e86f79eae6dfa95bfaf024ee3d'
TRACEE_PUBLICATION='f41ccb6b773d0b24273b8145d758680f9b3f8793'
MEMCPY_PUBLICATION='4adeb4807bb26eddd57324799eb79d9dc0118d56'
ARM_ROOT='corpus/results/kprog_arm64_app_coverage_20261107/'
ARM_COHORTS=[
 ('bcc','arm64_functional_172354',ARM_ROOT+'bcc-full-start-coverage.json',
  'corpus/results/kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/run-20261107T172354861230Z.tar.gz'),
 ('otel','arm64_functional_182921',ARM_ROOT+'trusted-arm64-otelcol-ebpf-profiler-result/coverage.json',
  ARM_ROOT+'trusted-arm64-otelcol-ebpf-profiler-result/run-20261107T182921697243Z.tar.gz'),
 ('cilium','arm64_functional_183612',ARM_ROOT+'trusted-arm64-cilium-result/coverage.json',
  ARM_ROOT+'trusted-arm64-cilium-result/run-20261107T183612879202Z.tar.gz'),
 ('tetragon','arm64_functional_183759',ARM_ROOT+'trusted-arm64-tetragon-result/coverage.json',
  ARM_ROOT+'trusted-arm64-tetragon-result/run-20261107T183759739461Z.tar.gz'),
 ('katran','arm64_functional_185947',ARM_ROOT+'trusted-arm64-katran-result/coverage.json',
  ARM_ROOT+'trusted-arm64-katran-result/run-20261107T185947373335Z.tar.gz'),
]
def normalized_stage(stage):
    return 'bound' if stage=='bound_accepted' else stage


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

def packet_work(payload,metadata,app,batch_records):
    with tarfile.open(fileobj=io.BytesIO(payload)) as archive:
        members=[m for m in archive.getmembers() if m.isfile() and m.name.endswith('/details/apps/'+app+'.json')]
        assert len(members)==1
        raw_app=archive.extractfile(members[0]).read()
    result=json.loads(raw_app)
    assert result['status']==metadata['app_status']
    observed={};configs={}
    for phase in ['baseline','post_rejit']:
        value=result[phase]
        assert value==metadata[phase]
        assert len(value['workloads'])==1
        workload=value['workloads'][0]
        config=dict(workload['config']);outcomes=config.pop('outcomes');configs[phase]=config
        before,after,delta=[outcomes[key] for key in ['before','after','delta']]
        for name in ['lru','lru_miss','tx','drop','vip_0','pass','encap_fail','consistent_hash_drop']:
            assert after['counters'][name]['packets_or_v1']-before['counters'][name]['packets_or_v1']==delta['counters'][name]['packets_or_v1']
        for name in ['rx_packets','rx_dropped']:
            assert after['receiver'][name]-before['receiver'][name]==delta['receiver'][name]
        device='load_balancer/katran0'
        assert after['interfaces'][device]['tx_dropped']-before['interfaces'][device]['tx_dropped']==delta['interfaces'][device]['tx_dropped']
        sent=sum(int(re.search(r'pkts-sofar:\s*(\d+)',part['stdout'])[1]) for part in workload['components'])
        packet=lambda name:delta['counters'][name]['packets_or_v1']
        receiver=delta['receiver']['rx_packets'];receiver_drop=delta['receiver']['rx_dropped']
        tx_drop=delta['interfaces'][device]['tx_dropped']
        recorded=metadata['work_reconciliation'][phase]
        counts=dict(sent=sent,bpf_run_count=sum(row['run_cnt_delta'] for row in value['bpf'].values()),
                    xdp_tx=packet('tx'),xdp_drop=packet('drop'),lru=delta['counters']['lru'],
                    lru_miss=delta['counters']['lru_miss'],receiver_packets=receiver,
                    receiver_drops=receiver_drop,load_balancer_tx_drops=tx_drop)
        assert counts==recorded
        ids={int(key) for key in value['bpf']}
        if phase=='post_rejit':
            assert ids=={int(row['bound_prog_id']) for row in batch_records if row['stage']=='bound'}
        observed[phase]=dict(**counts,bpf_ids=sorted(ids),vip_packets=packet('vip_0'),
                            sent_equals_bpf_xdp_lru_vip=sent==counts['bpf_run_count']==counts['xdp_tx']==packet('lru')==packet('vip_0'),
                            receiver_gap=sent-receiver,network_drop_sum=tx_drop+receiver_drop,
                            network_accounting_equal=sent-receiver==tx_drop+receiver_drop,
                            derived_counter_deltas_equal=True,duration_seconds=workload['duration_s'],
                            workload_returncode=workload['returncode'],
                            component_returncodes=[part['returncode'] for part in workload['components']])
    return dict(app_result_sha256=sha(raw_app),app_status=result['status'],
                phases=observed,workload_configs_equal=configs['baseline']==configs['post_rejit'],
                recorded_work_reconciliation_equal=True)


def workload_observation(workload):
    value=dict(name=workload['workload_name'])
    for source,target in [('duration_s','duration_seconds'),('returncode','returncode')]:
        if source in workload:value[target]=workload[source]
    for channel in ['stdout','stderr']:
        if channel in workload:value[channel+'_sha256']=sha(workload[channel].encode())
    if 'components' in workload:
        value['components']=[workload_observation(part) for part in workload['components']]
    return value


def recorded_application_work(payload,metadata,batch_records,run_summary):
    with tarfile.open(fileobj=io.BytesIO(payload)) as archive:
        applications=[]
        for recorded in metadata['applications']:
            raw=archive.extractfile(recorded['archive_member']).read()
            result=json.loads(raw)
            assert all(result[key]==recorded[key] for key in ['app','status'])
            if 'error' in recorded:assert result['error']==recorded['error']
            if 'error_first_line' in recorded:
                assert (result.get('error','').splitlines() or [''])[0]==recorded['error_first_line']
            phases={}
            for phase,coverage in recorded['phases'].items():
                actual=result[phase]
                assert (actual or {})==coverage['raw_measurement']
                programs=list((actual or {}).get('bpf',{}).values())
                if 'programs' in coverage:assert programs==coverage['programs']
                workloads=(actual or {}).get('workloads',[])
                phases[phase]=dict(raw_measurement_present=actual is not None,
                    archived_coverage_equal=True,resident_program_count=len(programs),
                    bpf_run_count=sum(row['run_cnt_delta'] for row in programs),
                    bpf_run_time_ns=sum(row['run_time_ns_delta'] for row in programs),
                    workloads=[workload_observation(w) for w in workloads])
            applications.append(dict(app=result['app'],app_status=result['status'],
                app_error=result['error'],app_result_sha256=sha(raw),phases=phases))
    expected=metadata['requests']
    assert len(expected)==len(batch_records)==metadata['service_request_attempts']
    for observed,recorded in zip(batch_records,expected):
        for key in ['request_id','source_prog_id','native_sha256','entry','status','request_archive_sha256']:
            assert observed[key]==recorded[key]
        assert observed['stage']==normalized_stage(recorded['stage'])
        if recorded['prog_id'] is not None:assert observed['bound_prog_id']==recorded['prog_id']
        assert observed['generated_source']==recorded['source_generated']
        assert observed['compiled_object']==recorded['proof_generated']
    assert Counter(row['stage'] for row in batch_records)==Counter({normalized_stage(key):value for key,value in metadata['stages'].items()})
    assert len({row['source_prog_id'] for row in batch_records})==metadata['distinct_source_prog_ids']
    assert sha(payload)==run_summary['archive_sha256']
    assert run_summary['hashes_unchanged']==metadata['hashes_unchanged']
    plans=[]
    with tarfile.open(fileobj=io.BytesIO(payload)) as archive:
        for row in expected:
            request_bytes=archive.extractfile(row['request_archive']).read()
            assert sha(request_bytes)==row['request_archive_sha256']
            with tarfile.open(fileobj=io.BytesIO(request_bytes)) as request:
                for member in request.getmembers():
                    if member.isfile() and member.name.endswith('.link-plan.json'):
                        plan_bytes=request.extractfile(member).read();plan=json.loads(plan_bytes)
                        plans.append(dict(request_id=row['request_id'],sha256=sha(plan_bytes),
                            map_names=[value['name'] for value in plan['maps']],
                            tail_call_maps=plan['tail_call_maps']))
    return dict(applications=applications,published_request_fields_equal=True,
        host_ok=run_summary['ok'],guest_exit=run_summary['guest_exit'],
        qemu_returncode=run_summary['qemu_returncode'],
        recorded_hashes_unchanged=run_summary['hashes_unchanged'],
        initial_source_identity_count=len(run_summary['hashes_before']),link_plans=plans,
        archive_sha256=sha(payload))


def whole_application_outcome(payload,metadata,batch_records,published_observations):
    with tarfile.open(fileobj=io.BytesIO(payload)) as archive:
        members=[m.name for m in archive.getmembers() if m.isfile() and '/details/apps/' in m.name and m.name.endswith('.json')]
        assert len(members)==1
        raw=archive.extractfile(members[0]).read();result=json.loads(raw)
        assert result['status']==metadata['app_status']
        assert result['error']==metadata['app_error']
        assert result['rejit_result']==metadata['rejit_result']
        phases={}
        for phase in ['baseline','post_rejit']:
            value=result[phase]
            assert value==metadata[phase]
            values=list((value or {}).get('bpf',{}).values())
            phases[phase]=dict(raw_measurement_present=value is not None,
                resident_program_count=len(values),bpf_run_count=sum(v['run_cnt_delta'] for v in values),
                workloads=[workload_observation(w) for w in (value or {}).get('workloads',[])])
        replacements=[];plans=[];timings=[];shim_pins={}
        for member in archive.getmembers():
            if member.isfile() and '/details/shim-logs/' in member.name and member.name.endswith('.post_rejit.log'):
                data=archive.extractfile(member).read();shim_pins[member.name]=sha(data)
                for line in data.decode().splitlines():
                    if any(label in line for label in ['native-loader replaced ','native-loader link-plan ','native-loader timings ']):
                        fields=dict(re.findall(r'(\w+)=(\S+)',line))
                        pair=(int(fields['original_id']),int(fields['native_id']))
                        if 'native-loader replaced ' in line:replacements.append((*pair,fields['symbol']))
                        elif 'native-loader link-plan ' in line:plans.append((*pair,fields['symbol'],int(fields['trusted_request'])))
                        else:timings.append((*pair,int(fields['prebuilt_proof']),int(fields['bound_required'])))
        expected={(r['source_prog_id'],r['bound_prog_id'],r['entry']) for r in batch_records if r['stage']=='bound'}
        assert len(replacements)==len(expected) and set(replacements)==expected
        assert set(plans)=={(*row,r['request_id']) for r in batch_records for row in expected if row[:2]==(r['source_prog_id'],r['bound_prog_id'])}
        assert len(timings)==len(expected) and set(timings)=={(*row[:2],0,1) for row in expected}
        assert len(expected)==metadata['native_replaced']
        assert sorted([list(row[:2]) for row in expected])==published_observations['bound_id_pairs']
        assert phases['baseline']['resident_program_count']==published_observations['baseline_resident_bpf_records']
    return dict(app_status=result['status'],app_error=result['error'],app_result_sha256=sha(raw),
        phases=phases,shim_sha256=shim_pins,replacement_pairs=sorted([list(row[:2]) for row in expected]),
        all_replacements_match_bound_service=True,all_replacements_require_bound=True,
        prebuilt_proof_count=sum(row[2] for row in timings),published_observations=published_observations)


def main():
    source_pins={}
    def published(path,publication=PUBLICATION):
        data=subprocess.check_output(['git','show',publication+':'+path],cwd=ROOT)
        source_pins[path]=dict(publication=publication,sha256=sha(data),bytes=len(data))
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
      ('tetragon','functional_210552',BASE+'native-join-tetragon__observer/coverage.json',BASE+'native-join-tetragon__observer/service.tar.gz'),
      ('tracee','functional_211016',BASE+'tracee-join-helper/coverage.json',BASE+'tracee-join-helper/service.tar.gz'),
      ('katran','functional_213447',BASE+'katran-tagged-storage/coverage.json',BASE+'katran-tagged-storage/service.tar.gz'),
      ('tracee','arm64_functional_202335',ARM_BASE+'coverage.json',ARM_BASE+'run-20261107T202335483042Z.tar.gz'),
    ]
    cases+=ARM_COHORTS+[
      ('tracee','functional_214037',BASE+'tracee-narrow-range/coverage.json',BASE+'tracee-narrow-range/service.tar.gz'),
      ('tetragon','functional_221545',BASE+'tetragon-memcpy-replay/coverage.json',BASE+'tetragon-memcpy-replay/service.tar.gz')]
    arm_pass_batches={row[1] for row in ARM_COHORTS}
    batches=[];records=[];failures=[];identity_sets={};work_observations={}
    for app,batch,metadata_path,service_path in cases:
        publication=MEMCPY_PUBLICATION if batch=='functional_221545' else TRACEE_PUBLICATION if batch=='functional_214037' else ARM_PASS_PUBLICATION if batch in arm_pass_batches else ARM_PUBLICATION if batch.startswith('arm64_') else KATRAN_PUBLICATION if batch=='functional_213447' else JOIN_PUBLICATION if batch in {'functional_210552','functional_211016'} else PUBLICATION
        metadata=json.loads(published(metadata_path,publication)) if metadata_path else {}
        payload=captured[service_path.split(':',1)[1]] if service_path.startswith('capture:') else published(service_path,publication)
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
                    elif re.search(r'\binfinite loop detected at insn \d+',stderr):
                        stage='verifier_rejected'
                    elif re.search(r'^trusted-native-loader: BPF_PROG_LOAD native_lab stub: Invalid argument$',stderr,re.M):
                        stage='native_stub_load_error'
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
            if batch.startswith('arm64_'):
                batch_records=[record for record in records if record['batch']==batch]
                work_observations[batch]=recorded_application_work(payload,metadata,batch_records,
                    json.loads(published(str(Path(service_path).with_name('summary.json')),publication)))
                published_requests={row['request_id']:row for row in metadata['requests']}
                for actual in [failure for failure in failures if failure['batch']==batch]:
                    recorded=published_requests[actual['request_id']]
                    if 'load_stderr' in recorded:assert actual['loader_stderr']==recorded['load_stderr']
                    if recorded.get('cause')=='infinite_loop':
                        assert re.search(r'\binfinite loop detected at insn \d+',actual['loader_stderr'])
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
            classification=metadata.get('failure_classification',{})
            for stage,key in [('verifier_rejected','confirmed_verifier_rejections'),('native_stub_load_error','native_stub_load_errors'),('specialization_rejected','specialization_errors')]:
                if key in classification:
                    compare[key]=dict(observed=stages[stage],recorded=classification[key],equal=stages[stage]==classification[key])
            if batch=='functional_221545':
                result_path=str(Path(service_path).with_name('result.tar.gz'))
                observations_path=str(Path(service_path).with_name('observations.json'))
                work_observations[batch]=whole_application_outcome(published(result_path,publication),metadata,
                    [record for record in records if record['batch']==batch],json.loads(published(observations_path,publication)))
            if 'work_reconciliation' in metadata:
                result_path=str(Path(service_path).with_name('result.tar.gz'))
                work_observations[batch]=packet_work(published(result_path,publication),metadata,app,
                    [record for record in records if record['batch']==batch])
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
    summary=dict(source_publication=PUBLICATION,additional_source_publications=[JOIN_PUBLICATION,KATRAN_PUBLICATION,ARM_PUBLICATION,ARM_PASS_PUBLICATION,TRACEE_PUBLICATION,MEMCPY_PUBLICATION],batches=batches,terminal_requests=len(records),
                 stages=dict(Counter(record['stage'] for record in records)),
                 kernel_worker_receipt_identity_matches=len(records),input_artifacts=source_pins,
                 captured_input_manifest=capture_manifest,captured_input_archive_sha256=sha((OUT/'captured-inputs.tar.gz').read_bytes()),
                 recorded_count_matches=all(row['equal'] for batch in batches for row in batch['recorded_counts'].values()),
                 work_observations=work_observations,
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
                         timing_failed_extents=load_rows,work_observations=work_observations),indent=2))
    return 0

if __name__=='__main__':
    raise SystemExit(main())
