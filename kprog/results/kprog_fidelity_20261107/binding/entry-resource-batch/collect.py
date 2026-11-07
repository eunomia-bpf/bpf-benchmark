"""Replay the shared entry-resource query over frozen cross-ISA native inputs."""
import csv,gzip,hashlib,io,json,posixpath,subprocess,tarfile,tempfile
from pathlib import Path,PurePosixPath
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[5]
OUT=Path(__file__).resolve().parent
STATE=Path('/workspaces/.agent-state/kprog-lanes/F')
C='c664565ccb449e88d3580ebda1e3c079b71d8c53'
A='bca4d587e9ca84a2d55043e2c30a95c02438e9cd'
CB='corpus/results/kprog_app_coverage_20261107/native-resource-scope/'
AB='corpus/results/kprog_arm64_app_coverage_20261107/entry-resource-scope/'
PINS={}
def sha(data):return hashlib.sha256(data).hexdigest()
def published(commit,path):
    value=subprocess.check_output(['git','show',commit+':'+path],cwd=ROOT)
    PINS[commit+':'+path]=dict(commit=commit,path=path,sha256=sha(value),bytes=len(value))
    return value
def contents(payload):
    with tarfile.open(fileobj=io.BytesIO(payload)) as archive:
        return {m.name:archive.extractfile(m).read() for m in archive if m.isfile()}
def add(archive,name,data):
    member=tarfile.TarInfo(name);member.size=len(data);member.mode=0o644
    archive.addfile(member,io.BytesIO(data))

def capture(arm,x86,raw_x86):
    path=OUT/'native-inputs.tar.gz'
    if path.exists():return
    data={};objects={};manifests={}
    for relative,digest in arm['input_pins'].items():
        value=(ROOT/relative).read_bytes()
        assert sha(value)==digest,relative
        if relative.endswith('/manifest.json'):
            manifests[relative]=value
        else:
            assert value[:4]==b'\x7fELF'
            objects[relative]=digest;data[digest]=value
    for app,record in x86['resource_queries'].items():
        value=raw_x86[app+'.native.o']
        assert sha(value)==record['native_sha256']
        relative='captured-x86/'+app+'.native.o'
        objects[relative]=sha(value);data[sha(value)]=value
    manifest=dict(native_paths=objects,
        manifests={relative:dict(member='manifests/'+Path(relative).parent.name+'.json',sha256=sha(value))
                   for relative,value in manifests.items()},
        blobs={digest:dict(member='objects/'+digest+'.o',bytes=len(value)) for digest,value in data.items()})
    temporary=path.with_suffix('.tmp')
    with temporary.open('wb') as stream:
        with gzip.GzipFile(filename='',fileobj=stream,mode='wb',mtime=0) as packed:
            with tarfile.open(fileobj=packed,mode='w') as archive:
                add(archive,'inputs.json',(json.dumps(manifest,indent=2)+'\n').encode())
                for relative,value in manifests.items():
                    add(archive,manifest['manifests'][relative]['member'],value)
                for digest,value in sorted(data.items()):
                    add(archive,manifest['blobs'][digest]['member'],value)
    temporary.replace(path)

def main():
    x86=json.loads(published(C,CB+'observations.json'))
    arm=json.loads(published(A,AB+'entry-resources.json'))
    arm_build=json.loads(published(A,AB+'summary.json'))
    raw_x86=contents(published(C,CB+'raw.tar.gz'))
    raw_arm=contents(published(A,AB+'build-inputs.tar.gz'))
    sources={}
    for path,digest in arm_build['source_pins'].items():
        value=raw_arm['source/'+path]
        assert sha(value)==digest
        assert value==published(A,path)==published(C,path)
        sources[path]=digest
    assert len(sources)==21
    assert raw_x86['main.candidate.rs']==raw_arm['source/kprog/x86/native_lab/native_link/src/main.rs']
    assert raw_x86['native_loader.candidate.cpp']==raw_arm['source/kprog/libnativeloader/src/native_loader.cpp']
    for label in ['test','build','caller-check']:assert int(raw_x86[label+'.exit'])==0
    assert b'89 passed; 0 failed;' in raw_x86['test.log']
    assert b'Ran 12 tests' in raw_x86['caller-check.log'] and b'OK' in raw_x86['caller-check.log']
    for label in ['caller','linker','queries']:assert int(raw_arm['build/'+label+'.exit'])==0
    host=raw_arm['build/host-native-link']
    assert sha(host)==arm_build['host_linker_sha256']==arm['host_linker_sha256']
    assert sha(host)==x86['artifacts']['kprog/x86/native_lab/native_link/target/release/native-link-resources-c']
    assert host[:4]==b'\x7fELF' and int.from_bytes(host[18:20],'little')==62
    actual_binaries={}
    for path,digest in arm_build['binary_pins'].items():
        value=raw_arm['bin/'+Path(path).name]
        assert sha(value)==digest
        assert value[:4]==b'\x7fELF' and int.from_bytes(value[18:20],'little')==183
        actual_binaries[path]=digest
    assert len(actual_binaries)==5
    assert arm_build['shared_commit']==C and arm_build['query_errors']==arm['errors']==0
    assert arm_build['applications']==arm['applications']
    capture(arm,x86,raw_x86)
    bundle=(OUT/'native-inputs.tar.gz').read_bytes()
    packed=contents(bundle);manifest=json.loads(packed['inputs.json'])
    objects={path:packed[manifest['blobs'][digest]['member']] for path,digest in manifest['native_paths'].items()}
    for path,digest in manifest['native_paths'].items():assert sha(objects[path])==digest
    assert set(manifest['blobs'])==set(manifest['native_paths'].values())
    for digest,record in manifest['blobs'].items():
        value=packed[record['member']]
        assert sha(value)==digest and len(value)==record['bytes']
    functions={}
    def elf_functions(value):
        digest=sha(value)
        if digest not in functions:
            elf=ELFFile(io.BytesIO(value));symtab=elf.get_section_by_name('.symtab')
            functions[digest]=sorted({s.name for s in symtab.iter_symbols()
                if s['st_info']['type']=='STT_FUNC' and s['st_shndx']!='SHN_UNDEF' and s['st_size']>0})
        return functions[digest]
    selected={}
    for path,record in manifest['manifests'].items():
        value=packed[record['member']]
        assert sha(value)==record['sha256']==arm['input_pins'][path]
        data=json.loads(value);app=data['app'];entries={}
        for row in data['objects']:
            obj=posixpath.normpath(str(PurePosixPath(path).parent/row['native_object']))
            native=objects[obj]
            names=[row['symbol']] if row.get('symbol') else [
                name for name in elf_functions(native) if name.startswith(row['program'])]
            assert names,(app,row)
            for symbol in names:
                assert symbol in elf_functions(native)
                entries[(obj,symbol)]=None
        expected=[r for r in arm['queries'] if r['app']==app]
        assert set(entries)=={(r['native_object'],r['symbol']) for r in expected}
        selected[app]=dict(packaged_selectors=len(data['objects']),unique_entry_queries=len(entries))
    assert len(selected)==6 and len(arm['queries'])==605
    assert sum(r['packaged_selectors'] for r in selected.values())==548
    for relative,digest in arm['input_pins'].items():
        if relative in manifest['native_paths']:assert manifest['native_paths'][relative]==digest
        else:assert manifest['manifests'][relative]['sha256']==digest
    entries={'tracee':'tracepoint__raw_syscalls__sys_enter','cilium':'cil_xdp_entry',
             'tetragon':'event_exit_disassociate_ctty','otel':'read_task_struct'}
    cases=[]
    for app,entry in entries.items():
        expected=x86['resource_queries'][app]
        archived=json.loads(raw_x86[app+'.resources.json'])
        assert archived==dict(version=expected['version'],symbols=expected['symbols'])
        cases.append(dict(isa='x86_64',app=app,native_object='captured-x86/'+app+'.native.o',
            symbol=entry,native_sha256=expected['native_sha256'],exit=0,stderr='',
            resource_symbols=expected['symbols']))
    cases.extend(dict(r,isa='aarch64') for r in arm['queries'])
    results=[];log=[]
    STATE.mkdir(parents=True,exist_ok=True)
    try:
        with tempfile.TemporaryDirectory(prefix='entry-resource-',dir=STATE) as work:
            work=Path(work);binary=work/'native-link';binary.write_bytes(host);binary.chmod(0o700)
            current=work/'native.o';last=None
            for case in cases:
                native=objects[case['native_object']]
                assert sha(native)==case['native_sha256']
                machine=int.from_bytes(native[18:20],'little')
                assert machine=={'x86_64':62,'aarch64':183}[case['isa']]
                assert case['symbol'] in elf_functions(native)
                if last!=case['native_sha256']:
                    current.write_bytes(native);last=case['native_sha256']
                command=[str(binary),'--input',str(current),'--symbol',case['symbol'],
                         '--mode','resources','--output','/dev/stdout']
                result=subprocess.run(command,capture_output=True)
                output=result.stdout.decode();error=result.stderr.decode()
                record=dict(isa=case['isa'],app=case['app'],native_object=case['native_object'],
                    entry=case['symbol'],native_sha256=case['native_sha256'],
                    command=command,exit=result.returncode,stdout=output,stderr=error,
                    expected_symbols=case['resource_symbols'])
                log.append(record)
                assert result.returncode==case['exit']==0,record
                assert error==case['stderr'],record
                observed=json.loads(output)
                assert observed==dict(version=1,symbols=case['resource_symbols']),record
                assert observed['symbols']==sorted(set(observed['symbols']))
                results.append(dict(isa=case['isa'],app=case['app'],native_object=case['native_object'],
                    entry=case['symbol'],native_sha256=case['native_sha256'],exit=result.returncode,
                    resource_symbol_count=len(observed['symbols']),
                    resource_symbols=json.dumps(observed['symbols'],separators=(',',':')),
                    published_symbols_equal=True,stdout_sha256=sha(result.stdout),stderr_sha256=sha(result.stderr)))
    finally:
        (OUT/'query.log.gz').write_bytes(gzip.compress(
            (''.join(json.dumps(row)+'\n' for row in log)).encode(),mtime=0))
    assert len(results)==609 and all(row['published_symbols_equal'] for row in results)
    arm_rows=[r for r in results if r['isa']=='aarch64']
    apps=[]
    for recorded in arm['applications']:
        observed=[r for r in arm_rows if r['app']==recorded['app']]
        actual=dict(app=recorded['app'],**selected[recorded['app']],
            query_successes=len(observed),resource_symbols_min=min(r['resource_symbol_count'] for r in observed),
            resource_symbols_max=max(r['resource_symbol_count'] for r in observed))
        assert actual==recorded
        apps.append(actual)
    with (OUT/'queries.tsv').open('w') as output:
        writer=csv.DictWriter(output,fieldnames=list(results[0]),delimiter=chr(9),lineterminator='\n')
        writer.writeheader();writer.writerows(results)
    report=dict(query_executions=609,x86_query_executions=4,aarch64_input_query_executions=605,
        matching_published_outputs=609,query_errors=0,aarch64_applications=apps,
        x86_applications=[dict(app=r['app'],entry=r['entry'],resource_symbols=json.loads(r['resource_symbols']))
                          for r in results if r['isa']=='x86_64'],
        packaged_arm_selectors=548,captured_native_paths=len(objects),
        distinct_native_objects=len(manifest['blobs']),
        captured_native_bytes=sum(len(packed[r['member']]) for r in manifest['blobs'].values()),
        captured_manifests=len(manifest['manifests']),source_files=21,source_sha256=sources,
        host_linker_sha256=sha(host),archived_arm_binary_sha256=actual_binaries,
        recorded_x86_artifact_sha256=x86['artifacts'],
        retained_producer_tests=dict(native_link=89,trusted_service=12,
            native_link_exit=0,caller_build_exit=0,service_tests_exit=0,arm_build_exits=[0,0,0]),
        input_publications=[C,A],input_pins=PINS,
        native_input_archive_sha256=sha(bundle),native_input_archive_bytes=len(bundle),
        query_log_sha256=sha((OUT/'query.log.gz').read_bytes()),
        query_table_sha256=sha((OUT/'queries.tsv').read_bytes()),
        backend='x86-64 host metadata query over x86-64 and AArch64 ELF objects',
        scope='Generic entry/function/data relocation resource metadata and paired source/binary identity observations.')
    (OUT/'summary.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps({k:v for k,v in report.items() if k not in
        ['input_pins','source_sha256','archived_arm_binary_sha256','recorded_x86_artifact_sha256']},indent=2))
if __name__=='__main__':main()
