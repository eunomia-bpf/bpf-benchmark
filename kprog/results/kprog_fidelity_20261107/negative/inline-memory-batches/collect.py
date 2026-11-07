"""Reconcile generic inline-memory service batch and transport observations."""
import ast
from collections import Counter
import csv,gzip,hashlib,io,json
from pathlib import Path
import re,subprocess,tarfile
ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
PUBLICATION='697bea0ea4326472119c137b306d298621a9a218'
HELPER_PUBLICATION='919dd0201b092e9b3b3cb56befe11832985d7d27'
BASE='kprog/results/kprog_tv_20261107/trusted-inline-memory-binding'
def sha(data):return hashlib.sha256(data).hexdigest()
def resource_observations(previous_outcomes):
    publication='c94fbff015cfcf2a6b253a26122e9991036c558b'
    base='kprog/results/kprog_tv_20261107/trusted-native-resources'
    pins={}
    def published(path):
        value=subprocess.check_output(['git','show',publication+':'+path],cwd=ROOT)
        pins[path]=dict(publication=publication,sha256=sha(value),bytes=len(value))
        return value
    metadata=json.loads(published(base+'.json'))
    raw=published(base+'.raw.tar.gz');packed_log=published(base+'.log.gz')
    log_bytes=gzip.decompress(packed_log);log=log_bytes.decode()
    for path,packed,unpacked in [(base+'.raw.tar.gz',raw,gzip.decompress(raw)),
                                (base+'.log.gz',packed_log,log_bytes)]:
        entry=metadata['archives'][path]
        assert sha(packed)==entry['gzip_sha256']
        assert sha(unpacked)==entry['raw_sha256'] and len(unpacked)==entry['raw_bytes']
    sources={path:published(path) for path in metadata['source_sha256']}
    assert all(sha(data)==metadata['source_sha256'][path] for path,data in sources.items())
    tested_sources={};tested_artifacts={}
    with tarfile.open(fileobj=io.BytesIO(raw)) as archive:
        input_metadata=json.loads(archive.extractfile('metadata/inputs.json').read())
        for key in ['source_sha256','source_git_epoch','implementation_source_observations','runtime_artifact_sha256']:
            assert input_metadata[key]==metadata[key]
        for path,digest in metadata['source_sha256'].items():
            data=archive.extractfile('inputs/'+path).read()
            observed=sha(data);tested_sources[path]=observed
            assert observed==input_metadata['observed_source_sha256'][path]
            if observed!=digest:
                observation=metadata['implementation_source_observations'][path]
                assert observed==observation['observed_sha256'] and digest==observation['published_sha256']
                assert [line for line in data.splitlines() if line.strip()]==[
                    line for line in sources[path].splitlines() if line.strip()]
        mapping={
            'artifacts/bpf_x86_native_lab.ko':'kprog/tv/build-x86/bpf_x86_native_lab.ko',
            'artifacts/test-trusted-transport':'kprog/tv/build/test-trusted-transport',
            'artifacts/.bpf_x86_native_lab.o.cmd':'kprog/tv/build-x86/.bpf_x86_native_lab.o.cmd'}
        for member,path in mapping.items():
            digest=sha(archive.extractfile(member).read())
            assert digest==metadata['runtime_artifact_sha256'][path]
            tested_artifacts[path]=digest
        assert archive.extractfile('logs/final.log').read()==log_bytes
        initial=archive.extractfile('logs/initial-wrapper-diagnostic.log').read()
        initial_sha256=sha(initial)
    segment=re.findall(r'^\./build/test-trusted-transport[^\n]*\n(.*?)(?=^rmmod |^make: Leaving|\Z)',log,re.M|re.S)
    assert len(segment)==1
    suite='registered trusted transport, immutable P, application proof refusal and fail-closed disconnect'
    rows=[];api=[]
    source=sources['kprog/tv/test_trusted_transport.c'].decode()
    for line in segment[0].splitlines():
        match=re.fullmatch(r'(.+): (PASS|REJECTED)(?: \((\d+)\))?',line)
        if match:
            label=match[1]
            assert json.dumps(label) in source or json.dumps(label+': PASS') in source
            rows.append(dict(control=label,outcome=match[2],errno=match[3] or '',
                record_kind='suite_summary' if label==suite else 'individual_outcome'))
        match=re.fullmatch(r'(.+): libbpf_result=(-?\d+) errno=(\d+)',line)
        if match:
            api.append(dict(control=match[1],libbpf_result=int(match[2]),errno=int(match[3])))
    assert len({row['control'] for row in rows})==len(rows)
    validation=metadata['validation']
    assert len(rows)==validation['outcome_lines']==34
    named=[row for row in rows if row['record_kind']=='individual_outcome']
    assert len(named)==validation['named_case_outcomes']==33
    assert sum(row['record_kind']=='suite_summary' for row in rows)==validation['suite_summary_lines']==1
    refused=[dict(case=row['control'],errno=int(row['errno'])) for row in rows if row['outcome']=='REJECTED']
    assert refused==validation['refusal_records'] and len(refused)==validation['expected_refusals']==30
    passed=[row['control'] for row in rows if row['outcome']=='PASS']
    assert passed==validation['positive_records']
    assert sum(row['outcome']=='PASS' for row in named)==validation['positive_case_outcomes']==3
    assert len(api)==len(validation['lifetime_api_results'])==2
    for observed,recorded in zip(api,validation['lifetime_api_results']):
        assert observed['libbpf_result']==recorded['libbpf_result']==-2
        assert observed['errno']==recorded['errno']==2
    original_labels={row['control'] for row in previous_outcomes}
    assert [row for row in rows if row['control'] in original_labels]==previous_outcomes
    additional=[row for row in named if row['control'] not in original_labels]
    assert len(additional)==15 and sum(row['outcome']=='REJECTED' for row in additional)==14
    abi=dict(re.findall(r'_Static_assert\(sizeof\(struct (native_lab_trusted_\w+)\) == (\d+)',source))
    assert abi==dict(native_lab_trusted_request='64',native_lab_trusted_submission='80')
    wire=sources['kinsn/module/include/native_lab_trusted_wire.h'].decode()
    assert "_IOWR('N', 0x77, struct native_lab_trusted_submission)" in wire
    assert 'puts("'+suite+': PASS");' in source
    lifetime_labels={row['control'] for row in api}
    for row in rows:
        row['operation_kind']=('suite_summary' if row['record_kind']=='suite_summary' else
            'lifetime_map_id_lookup' if row['control'] in lifetime_labels else
            'protocol_refusal' if row['outcome']=='REJECTED' else 'protocol_observation')
    report=dict(source_publication=publication,input_pins=pins,
        published_source_files=len(sources),archived_source_sha256=tested_sources,
        archived_runtime_artifact_sha256=tested_artifacts,
        recorded_runtime_artifact_sha256=metadata['runtime_artifact_sha256'],
        metadata_runtime_artifact_pins_beyond_archive=sorted(set(metadata['runtime_artifact_sha256'])-set(tested_artifacts)),
        source_observations=metadata['implementation_source_observations'],
        outcomes=len(rows),named_outcomes=len(named),expected_refusals=len(refused),
        positive_named_outcomes=3,suite_summaries=1,prior_outcomes_preserved=len(previous_outcomes),
        protocol_refusal_outcomes=sum(row['operation_kind']=='protocol_refusal' for row in rows),
        lifetime_map_id_lookup_outcomes=len(api),
        positive_protocol_observations=sum(row['operation_kind']=='protocol_observation' for row in rows),
        additional_named_outcomes=len(additional),additional_expected_refusals=14,
        lifetime_api_observations=api,abi_bytes={key:int(value) for key,value in abi.items()},
        ioctl_group='N',ioctl_number=0x77,recorded_command_exit=validation['exit'],
        final_log_matches_archive=True,initial_diagnostic_sha256=initial_sha256,
        scope='Archived transport submission/query/completion and map-reference-lifetime observations.')
    return report,rows



def arm_resource_observations(x86_rows):
    publication='340a4ea5e07c38d415031c51aca057b57f62d955'
    base='corpus/results/kprog_arm64_app_coverage_20261107/native-resources/'
    service_base=base+'replay/trusted-arm64-service-result/'
    pins={}
    def published(path):
        value=subprocess.check_output(['git','show',publication+':'+path],cwd=ROOT)
        pins[path]=dict(publication=publication,sha256=sha(value),bytes=len(value))
        return value
    metadata=json.loads(published(base+'summary.json'))
    service=json.loads(published(service_base+'summary.json'))
    audit=json.loads(published(service_base+'native-identity-audit.json'))
    raw=published(base+'inputs-and-controls.tar.gz')
    packed=published(service_base+service['archive'])
    assert sha(packed)==service['archive_sha256']==audit['archive_sha256']
    source_bytes={};source_hashes={};git_sources={};source_observations={}
    with tarfile.open(fileobj=io.BytesIO(raw)) as archive:
        data=lambda path:archive.extractfile(path).read()
        captured=json.loads(data('control/inputs.json'))
        for key in ['source_pins','kernel_interface_commit','caller_commit']:
            assert captured[key]==metadata[key]
        for path,digest in metadata['source_pins'].items():
            value=data('source/'+path);source_bytes[path]=value
            assert sha(value)==digest;source_hashes[path]=digest
            if path=='vendor/build/arm64/linux/Module.symvers':
                continue
            git_value=published(path);git_sources[path]=sha(git_value)
            if value!=git_value:
                assert path=='kinsn/module/include/native_lab_group.h'
                assert [line for line in value.splitlines() if line.strip()]==[
                    line for line in git_value.splitlines() if line.strip()]
                source_observations[path]=dict(archived_sha256=digest,published_sha256=sha(git_value),
                    observation='Captured header retains two additional empty lines.')
        assert len(source_hashes)==41 and len(git_sources)==40
        artifact_bytes={'bpf_arm64_native_lab.ko':data('bin/bpf_arm64_native_lab.ko')}
        artifact_bytes.update({name:data('bin/'+name) for name in metadata['loader_binaries']})
        artifacts={name:sha(value) for name,value in artifact_bytes.items()}
        assert artifacts['bpf_arm64_native_lab.ko']==metadata['module_sha256']
        assert all(artifacts[name]==digest for name,digest in metadata['loader_binaries'].items())
        transport_inputs=json.loads(data('control/transport-output/inputs.json'))
        transport_binary=data('control/transport-output/test-trusted-transport')
        transport_hashes=transport_inputs['hashes']
        assert sha(transport_binary)==transport_hashes['kprog/arm64/build/trusted-transport/test-trusted-transport']
        assert transport_hashes['kinsn/module/arm64/build/bpf_arm64_native_lab.ko']==metadata['module_sha256']
        for path in ['kprog/tv/test_trusted_transport.c','kinsn/module/include/native_lab_trusted_wire.h']:
            assert transport_hashes[path]==source_hashes[path]
        for name,value in {**artifact_bytes,'test-trusted-transport':transport_binary}.items():
            assert value[:4]==b'\x7fELF' and int.from_bytes(value[18:20],'little')==183,name
        artifacts['test-trusted-transport']=sha(transport_binary)
        log=data('control/transport-output/console.log').decode()
        markers=[];api=[]
        for line in log.splitlines():
            if re.fullmatch(r'(.+): (PASS|REJECTED)(?: \((\d+)\))?',line):
                markers.append(line)
            match=re.fullmatch(r'(.+): libbpf_result=(-?\d+) errno=(\d+)',line)
            if match:api.append(dict(control=match[1],libbpf_result=int(match[2]),errno=int(match[3])))
        assert markers==metadata['transport_markers'] and len(markers)==34
        for marker,row in zip(markers,x86_rows):
            match=re.fullmatch(r'(.+): (PASS|REJECTED)(?: \((\d+)\))?',marker)
            assert (match[1],match[2],match[3] or '')==(row['control'],row['outcome'],row['errno'])
        assert len(api)==2 and all(row['libbpf_result']==-2 and row['errno']==2 for row in api)
        assert {row['control'] for row in api}=={
            row['control'] for row in x86_rows if row['operation_kind']=='lifetime_map_id_lookup'}
        rows=[dict(row,isa='aarch64') for row in x86_rows]
        for name in ['module','loader','transport-build','transport']:
            assert int(data('control/'+name+'.exit'))==0
        assert int(data('control/transport-output/exit'))==int(data('control/transport-output/guest-status'))==0
        assert json.loads(data('control/transport-output/result.json'))==metadata['transport_result']
        control_hashes={name:sha(data('control/'+name)) for name in
            ['freeze.sh','service.sh','transport.sh','run.py','module-build.sh','transport-output/console.log']}
    with tarfile.open(fileobj=io.BytesIO(packed)) as archive:
        data=lambda path:archive.extractfile(path).read()
        guest=json.loads(data('run/guest.json'));client=json.loads(data('run/client.stdout'))
        assert guest==service['guest']
        assert all(client[key]==guest[key] for key in client)
        assert guest['ok'] and service['ok'] and metadata['service_host_ok']
        assert int(data('run/guest.exit'))==service['guest_exit']==service['qemu_returncode']==0
        assert metadata['service_guest_exit']==0 and guest['retval']==metadata['service_retval']==2
        assert guest['prebuilt_proof'] is False and guest['returncode']==0
        events=[json.loads(line) for line in data('run/requests/requests.jsonl').splitlines()]
        assert events==[guest['receipt']] and len(events)==audit['completed_requests_or_cases']==1
        event=events[0]
        assert event['status']==0 and event['source_prog_id']==guest['original_prog_id']==3
        assert event['prog_id']==guest['native_prog_id']==9
        request_name='run/requests/'+Path(event['artifact_archive']).name
        request_bytes=data(request_name);identity=audit['request_identities'][0]
        assert sha(request_bytes)==identity['request_archive_sha256']
        service_inputs=json.loads(data('run/inputs.json'))
        assert service_inputs['hashes_before']==service['hashes_before']
        assert service_inputs['command']==service['command']
        with tarfile.open(fileobj=io.BytesIO(request_bytes)) as request:
            data=lambda path:request.extractfile(path).read()
            native=data('request/kernel.native.o')
            assert native==data('request/generated/request.native.o')
            assert sha(native)==event['native_sha256']==identity['native_sha256']
            assert native[:4]==b'\x7fELF' and int.from_bytes(native[18:20],'little')==183
            assert data('request/kernel.entry').decode().strip()=='trusted_entry'
            facts=json.loads(data('request/kernel.facts.json'))
            assert facts['id']==event['source_prog_id'] and facts['maps']==[]
            reply=json.loads(data('request/load.stdout'))
            assert reply=={key:event[key] for key in ['request_id','prog_id','status']}
            for path,digest in identity['artifacts'].items():assert sha(data(path))==digest
            identities=json.loads(data('request/source-identities.json'))
            for path,digest in identities.items():
                relative=path.removeprefix('/workspaces/repository/')
                if relative in service['hashes_before']:
                    assert digest==service['hashes_before'][relative]
                if relative in source_bytes:
                    assert sha(source_bytes[relative])==digest
                elif '/build/' not in relative and 'build-arm64-' not in relative:
                    assert sha(published(relative))==digest
            loader='kprog/libnativeloader/build-arm64-a-map-order-v3/trusted-native-loader'
            assert identities['/workspaces/repository/'+loader]==artifacts['trusted-native-loader']
            assert service['hashes_before']['kinsn/module/arm64/build/bpf_arm64_native_lab.ko']==metadata['module_sha256']
            assert service['hashes_before']['kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link']==metadata['linker_sha256']
            assert sha(native)==service['hashes_before']['kprog/libnativeloader/build-arm64-a-map-order-v3/trusted-native.o']
            commands=[json.loads(line) for line in data('request/generated/commands.jsonl').splitlines()]
            assert len(commands)==2 and all(row['returncode']==0 for row in commands)
            assert '-target' in commands[1]['command'] and 'bpf' in commands[1]['command']
            request_hashes={path:sha(data(path)) for path in identity['artifacts']}
    assert metadata['identity_errors']==audit['identity_errors']==[]
    assert audit['all_recorded_identities_match'] and service['hashes_unchanged']
    assert len(markers)==len(rows)==34
    report=dict(source_publication=publication,input_pins=pins,
        archived_source_sha256=source_hashes,published_source_sha256=git_sources,
        source_observations=source_observations,archived_runtime_artifact_sha256=artifacts,
        recorded_retained_runtime_sha256=metadata['retained_runtime'],
        transport_command=transport_inputs['command'],service_command=service['command'],
        transport_log_sha256=control_hashes['transport-output/console.log'],
        archived_control_sha256=control_hashes,outcomes=34,named_outcomes=33,
        protocol_refusal_outcomes=28,lifetime_map_id_lookup_outcomes=2,
        positive_protocol_observations=3,suite_summaries=1,
        rendered_refusal_outcomes=metadata['transport_rejection_count'],
        lifetime_api_observations=api,x86_outcomes_equal=True,
        actual_service_requests=1,fresh_compiled_bound_requests=1,actual_native_executions=1,
        observed_retval=2,source_prog_id=3,bound_prog_id=9,
        kernel_worker_receipt_native_sha256=sha(native),source_map_count=len(facts['maps']),
        packaged_baseline_native_sha256=artifacts['trusted-native.o'],
        request_archive_sha256=sha(request_bytes),request_artifact_sha256=request_hashes,
        recorded_source_identities=identities,service_input_identities=service['hashes_before'],
        transport_guest_exit=0,service_guest_exit=0,
        scope='Portable resource transport observations and a fresh registered-service scalar native execution.')
    return report,rows


def main():
    pins={}
    def published(path,commit=PUBLICATION):
        data=subprocess.check_output(['git','show',commit+':'+path],cwd=ROOT)
        pins[path]=dict(publication=commit,sha256=sha(data),bytes=len(data))
        return data
    metadata=json.loads(published(BASE+'.json'))
    raw=published(BASE+'.raw.tar.gz')
    packed_log=published(BASE+'.log.gz');log=gzip.decompress(packed_log).decode()
    assert sha(raw)==metadata['validation']['raw_archive_sha256']
    assert sha(log.encode())==metadata['validation']['raw_log_sha256']
    helper_path='kprog/results/kprog_fidelity_20261107/application-batches/collect.py'
    helper=ast.parse(published(helper_path,HELPER_PUBLICATION).decode())
    function=next(node for node in helper.body if isinstance(node,ast.FunctionDef) and node.name=='service_archive')
    namespace=dict(io=io,tarfile=tarfile)
    exec(compile(ast.Module(body=[function],type_ignores=[]),helper_path,'exec'),namespace)
    open_service=namespace['service_archive']
    for path,digest in metadata['source_sha256'].items():
        assert sha(published(path))==digest,path
    transports=[]
    transport=re.findall(r'^\./build/test-trusted-transport[^\n]*\n(.*?)^rmmod ',log,re.M|re.S)
    assert len(transport)==1
    for line in transport[0].splitlines():
        match=re.fullmatch(r'(.+): (PASS|REJECTED)(?: \((\d+)\))?',line)
        if match:
            transports.append(dict(control=match[1],outcome=match[2],errno=match[3] or ''))
    assert len(transports)==metadata['validation']['transport_controls']==19
    assert sum(row['outcome']=='REJECTED' for row in transports)==metadata['validation']['expected_transport_rejections']==16
    suite_label='registered trusted transport, immutable P, application proof refusal and fail-closed disconnect'
    transport_source=published('kprog/tv/test_trusted_transport.c').decode()
    assert 'puts("'+suite_label+': PASS");' in transport_source
    for row in transports:
        row['record_kind']='suite_summary' if row['control']==suite_label else 'individual_outcome'
    assert sum(row['record_kind']=='suite_summary' for row in transports)==1

    clients={}
    for line in log.splitlines():
        if line.startswith('{'):
            row=json.loads(line)
            if 'case' in row:
                assert row['case'] not in clients
                clients[row['case']]=row
    assert [clients[row['case']] for row in metadata['validation']['cases']]==metadata['validation']['cases']
    records=[];failures=[];batches=[];tested={}
    source_sets={}
    with tarfile.open(fileobj=io.BytesIO(raw)) as outer:
        for member in outer.getmembers():
            if member.isfile() and member.name.startswith('tested/'):
                data=outer.extractfile(member).read();original=member.name.removeprefix('tested/')
                digest=sha(data);tested[original]=digest
                if original in metadata['source_sha256']:
                    expected=metadata['source_sha256'][original]
                    if digest!=expected:
                        observation=next(row for row in metadata['source_observations'] if row['path']==original)
                        assert digest==observation['observed_sha256'] and expected==observation['published_sha256']
                        published_data=published(original)
                        assert [line for line in data.splitlines() if line.strip()]==[line for line in published_data.splitlines() if line.strip()]
                elif original in metadata['tested_binary_sha256']:
                    assert digest==metadata['tested_binary_sha256'][original]
        expected_archives={Path(row['path']).name:row['sha256'] for row in metadata['service_archives']}
        final_name=Path(metadata['service_archives'][-1]['path']).name
        for member in outer.getmembers():
            if member.isfile() and member.name.startswith('service/'):
                archive_data=outer.extractfile(member).read();name=Path(member.name).name
                assert sha(archive_data)==expected_archives.pop(name)
                archive,log_name=open_service(archive_data)
                with archive:
                    events=[json.loads(line) for line in archive.extractfile(log_name).read().splitlines()]
                    terminal=[row for row in events if 'request_id' in row]
                    nested={m.name for m in archive.getmembers() if m.isfile() and '/requests/' in m.name and m.name.endswith('.tar.gz')}
                    consumed=set();counter=Counter()
                    for event in terminal:
                        field='artifact_archive' if event['status']==0 else 'failure_archive'
                        matches=[path for path in nested if Path(path).name==Path(event[field]).name]
                        assert len(matches)==1 and matches[0] not in consumed;path=matches[0];consumed.add(path)
                        request_data=archive.extractfile(path).read()
                        with tarfile.open(fileobj=io.BytesIO(request_data)) as request:
                            names={m.name for m in request.getmembers() if m.isfile()}
                            data=lambda n:request.extractfile(n).read()
                            native=data('request/kernel.native.o')
                            assert native==data('request/generated/request.native.o')
                            assert sha(native)==event['native_sha256']
                            facts=json.loads(data('request/kernel.facts.json'))
                            assert facts['id']==event['source_prog_id']>0
                            identities=json.loads(data('request/source-identities.json'))
                            source_key=sha(json.dumps(identities,sort_keys=True).encode());source_sets[source_key]=identities
                            generated=[n for n in names if n.startswith('request/generated/trusted_') and n.endswith('.bpf.c')]
                            commands=[json.loads(line) for line in data('request/generated/commands.jsonl').splitlines()]
                            stderr=data('request/load.stderr').decode() if 'request/load.stderr' in names else ''
                            macros=sorted(re.findall(r'X86_SIM_L_EXEC_CALL_MEM(?:CPY|SET)\(\d+ULL\);','\n'.join(data(n).decode() for n in generated)))
                            if event['status']==0:
                                reply=json.loads(data('request/load.stdout'))
                                assert reply=={key:event[key] for key in ['request_id','prog_id','status']}
                                stage='bound'
                            else:
                                stage='verifier_rejected' if 'R2 invalid mem access' in stderr else 'specialization_rejected'
                                error=json.loads(data('request/error.json'))
                                failures.append(dict(archive=name,request_id=event['request_id'],stage=stage,error=error,
                                                     loader_stderr=stderr,commands=commands))
                            case=''
                            if name==final_name:
                                case=next(key for key,row in clients.items() if row['object_sha256']==sha(native))
                                record=next(row for row in metadata['validation']['terminal_records'] if row['name']==path)
                                assert record['kernel_and_worker_native_sha256']==sha(native)
                                assert tested['kprog/tv/build/trusted-memory-'+case+'.o']==sha(native)
                                epochs=next(row for row in metadata['runtime_source_epochs'] if row['terminal']==path)
                                assert epochs['captured_source_and_binary_sha256']==identities
                                if case=='unsafe':
                                    assert stage=='verifier_rejected' and event['status']!=0
                                    assert "R2 invalid mem access 'scalar'" in stderr
                                    assert re.search(r'processed 47 insns \(limit 1000000\)',stderr)
                                    assert re.search(r'^46:.*\nR2 invalid mem access',stderr,re.M)
                                else:
                                    assert stage=='bound' and clients[case]['returncode']==0
                                    executed=json.loads(clients[case]['stdout'])
                                    assert executed['ok'] and executed['retval']==2 and executed['prebuilt_proof']==False
                                    assert executed['original_prog_id']==event['source_prog_id'] and executed['native_prog_id']==event['prog_id']
                                    assert macros==sorted(record['memory_macros'])
                            counter[stage]+=1
                            records.append(dict(archive=name,final_batch=name==final_name,case=case,
                                request_id=event['request_id'],source_prog_id=event['source_prog_id'],
                                bound_prog_id=event.get('prog_id',''),status=event['status'],stage=stage,
                                native_sha256=sha(native),kernel_worker_receipt_identity_equal=True,
                                request_archive_sha256=sha(request_data),recorded_source_set_sha256=source_key,
                                generated_memory_macros=';'.join(macros)))
                    assert consumed==nested
                    batches.append(dict(archive=name,sha256=sha(archive_data),terminal_requests=len(terminal),stages=dict(counter),final_batch=name==final_name))
        assert expected_archives=={}
    final=[row for row in records if row['final_batch']]
    assert len(final)==4 and Counter(row['stage'] for row in final)==Counter(bound=3,verifier_rejected=1)
    assert len({row['recorded_source_set_sha256'] for row in final})==1
    resource_report,resource_rows=resource_observations(transports)
    arm_report,arm_rows=arm_resource_observations(resource_rows)
    for path,rows in [('terminal-outcomes.tsv',records),('transport-outcomes.tsv',transports),('resource-transport-outcomes.tsv',resource_rows),('arm-resource-transport-outcomes.tsv',arm_rows)]:
        with (OUT/path).open('w') as output:
            columns=list(rows[0])
            if path=='terminal-outcomes.tsv':
                columns.remove('native_sha256');columns.append('native_sha256')
            writer=csv.DictWriter(output,fieldnames=columns,delimiter='\t',lineterminator='\n')
            writer.writeheader();writer.writerows(rows)
    (OUT/'failures.jsonl.gz').write_bytes(gzip.compress((''.join(json.dumps(row)+'\n' for row in failures)).encode(),mtime=0))
    report=dict(source_publication=PUBLICATION,input_pins=pins,service_batches=batches,
                terminal_requests=len(records),kernel_worker_receipt_identity_matches=len(records),
                stages=dict(Counter(row['stage'] for row in records)),final_batch_requests=4,
                final_native_executions=3,final_expected_retval=2,final_unsafe_rejections=1,
                final_unsafe_accepts=0,final_recorded_source_vectors_equal=True,
                transport_reported_count=metadata['validation']['transport_controls'],transport_log_outcomes=len(transports),
                transport_individual_outcomes=sum(row['record_kind']=='individual_outcome' for row in transports),
                transport_suite_summaries=1,transport_rejections=sum(row['outcome']=='REJECTED' for row in transports),
                tested_artifact_sha256=tested,recorded_source_vectors=source_sets,
                source_observations=metadata['source_observations'],
                scope='Offline batch runtime/source identity reconciliation supporting generic memory binding and refusal.')
    report['resource_transport_batch']=resource_report
    report['arm_resource_batch']=arm_report
    (OUT/'summary.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:v for k,v in report.items() if k not in ['input_pins','tested_artifact_sha256','recorded_source_vectors','source_observations','resource_transport_batch','arm_resource_batch']},indent=2))
    print(json.dumps(dict(resource_transport={key:resource_report[key] for key in ['source_publication','outcomes','named_outcomes','protocol_refusal_outcomes','lifetime_map_id_lookup_outcomes','positive_protocol_observations','suite_summaries','prior_outcomes_preserved']}),indent=2))
    print(json.dumps(dict(arm_resource={key:arm_report[key] for key in ['source_publication','outcomes','protocol_refusal_outcomes','lifetime_map_id_lookup_outcomes','positive_protocol_observations','actual_native_executions','observed_retval','kernel_worker_receipt_native_sha256']}),indent=2))
if __name__=='__main__':main()
