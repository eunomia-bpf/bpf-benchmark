"""Compile saved ARM inputs without runtime rewrites and compare allocated B sections."""
import hashlib
import importlib.util
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import time
import traceback
from elftools.elf.elffile import ELFFile

ROOT=Path('/workspaces/repository')
HERE=Path(__file__).resolve().parent
LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
sys.path.insert(0,str(ROOT/'kprog'))
from arm64.trusted_specializer import b_flags

def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
receipt=json.loads((LANE/'header-transition.json').read_text())
OUT=Path(receipt['result']);RAW=Path(receipt['raw'])
profile=(RAW/'runtime-overrides.txt').read_bytes()
flags=list(map(str,b_flags(sysroot=ROOT/'.cache/qemu-arm64-root')))
record=dict(started_utc=now(),pid=os.getpid(),source_revision=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip(),producer_sha256=hashlib.sha256((ROOT/'kprog/arm64/trusted_specializer.py').read_bytes()).hexdigest(),flags=flags,cases=[],scope='First captured input per six apps plus slowest captured OTel and Cilium frontends, with one unchanged architecture flag set. Remove only the saved75-macro runtime profile from C; compile through actual current header sources. Compare allocated nonmetadata sections and nondebug relocations. Whole ELF/debug hashes are separate. Not stock/native/frozen900s startup or timing evidence.')
def save():(OUT/'validation-controller.json').write_text(json.dumps(record,indent=2)+'\n')
def command(args,path):
    start=time.monotonic()
    with path.with_suffix('.stdout').open('wb') as stdout,path.with_suffix('.stderr').open('wb') as stderr:
        child=subprocess.Popen(list(map(str,args)),stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,cwd=ROOT)
        _,status,usage=os.wait4(child.pid,0);child.returncode=os.waitstatus_to_exitcode(status)
    return dict(command=list(map(str,args)),returncode=child.returncode,wall_seconds=time.monotonic()-start,max_rss_kib=usage.ru_maxrss)
def elf(data):
    e=ELFFile(io.BytesIO(data));sections={};relocs={}
    assert e.header['e_machine']=='EM_BPF'
    for section in e.iter_sections():
        if section['sh_flags']&2 and not section.name.startswith(('.BTF','.debug')):
            sections[section.name]=dict(size=section['sh_size'],flags=section['sh_flags'],sha256=hashlib.sha256(section.data()).hexdigest())
        if section['sh_type'] not in ['SHT_REL','SHT_RELA']:continue
        target=e.get_section(section['sh_info']).name
        if target.startswith(('.debug','.BTF')):continue
        symtab=e.get_section(section['sh_link'])
        relocs[section.name]=[dict(offset=r['r_offset'],type=r['r_info_type'],symbol=symtab.get_symbol(r['r_info_sym']).name,addend=r.entry.get('r_addend')) for r in section.iter_relocations()]
    return dict(sections=sections,relocations=relocs)
try:
    save()
    plan=json.loads((HERE/'header-const-plan.json').read_text())
    assert '_constant_decoder_overrides' not in (ROOT/'kprog/arm64/trusted_specializer.py').read_text()
    for f in plan['files']:assert hashlib.sha256((ROOT/f['path']).read_bytes()).hexdigest()==f['after_sha256'],f['path']
    record['compiler_header_sha256']={path:hashlib.sha256(Path(path).read_bytes()).hexdigest() for path in json.loads((HERE/'cross-app-20261127T141857Z/controller.json').read_text())['header_sha256']};save()
    corpus=json.loads((HERE/'cross-app-20261127T141857Z/compiled-corpus.json').read_text())
    assert flags==json.loads((HERE/'cross-app-20261127T141857Z/controller.json').read_text())['common_flags']
    initial={}
    for r in corpus['requests']:initial.setdefault(r['app'],r)
    otel=max((r for r in corpus['requests'] if r['app'].startswith('otel')),key=lambda r:sum(c['wall_seconds'] for c in r['replay_commands'] if '-emit-llvm' in c['command']))
    selected=list(initial.values())+[otel];inputs=[]
    for r in selected:
        controller=r.get('recovery_controller',str(HERE/'cross-app-20261127T121315Z/controller.json'))
        baseline=Path(json.loads((ROOT/controller).read_text())['raw'])/str(r['index'])
        inputs.append(dict(app=r['app'],identity='replay-'+str(r['index']),symbol=r['symbol'],source=(baseline/'trusted_arm64.bpf.c').read_bytes(),object=(baseline/'trusted_arm64.bpf.o').read_bytes()))
    for app,token in [('cilium/agent','20261127T120527Z'),('tracee/monitor','20261127T140827Z')]:
        archive=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127')/token/app.replace('/','-')/'service.tar.gz';candidates=[]
        with tarfile.open(archive,mode='r|gz') as outer:
            for m in outer:
                if not m.isfile() or '/requests/' not in m.name or not m.name.endswith('.tar.gz'):continue
                with tarfile.open(fileobj=io.BytesIO(outer.extractfile(m).read())) as inner:
                    files={Path(x.name).name:x for x in inner if x.isfile()}
                    if 'trusted_arm64.bpf.o' not in files:continue
                    front=json.loads(inner.extractfile(files['trusted_arm64.bpf.frontend.compiler.json.broker.json']).read())
                    candidates.append(dict(app=app,identity='request-'+Path(m.name).name.split('.')[0],symbol=inner.extractfile(files['kernel.entry']).read().decode().strip(),source=inner.extractfile(files['trusted_arm64.bpf.c']).read(),object=inner.extractfile(files['trusted_arm64.bpf.o']).read(),baseline_frontend_seconds=front['wall_seconds']))
        candidates.sort(key=lambda c:int(c['identity'].split('-')[1]));inputs.append(candidates[0])
        if app.startswith('cilium'):
            worst=max(candidates,key=lambda c:c['baseline_frontend_seconds'])
            if worst['identity']!=candidates[0]['identity']:inputs.append(worst)
    first=[];stress=[];seen=set()
    for item in inputs:
        (stress if item['app'] in seen else first).append(item);seen.add(item['app'])
    inputs=first+stress
    record['inventory']=[{k:v for k,v in item.items() if k not in ['source','object']} for item in inputs];save()
    generator=ROOT/'kprog/arm64/generate_sim_dispatch.py';spec=importlib.util.spec_from_file_location('header_dispatch',generator);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    rendered=module.render(ROOT/'kprog/arm64/arm64_sim_local_bpf.h',ROOT/'kprog/arm64/arm64_sim.h',RAW/'dispatch-probe')
    (RAW/'regenerated-direct.h').write_text(rendered)
    record['regenerator']=dict(matches_working=rendered==(ROOT/'kprog/arm64/arm64_sim_direct.h').read_text(),matches_published=rendered==subprocess.check_output(['git','show','HEAD:kprog/arm64/arm64_sim_direct.h'],text=True),sha256=hashlib.sha256(rendered.encode()).hexdigest());save()
    for ordinal,item in enumerate(inputs,1):
        row={k:v for k,v in item.items() if k not in ['source','object']};row['commands']=[];folder=RAW/('validation-'+str(ordinal));folder.mkdir()
        assert item['source'].count(profile)==1,row
        source=item['source'].replace(b'\n'+profile,b'',1);c=folder/'trusted_arm64.bpf.c';ir=folder/'trusted_arm64.bpf.frontend.bc';obj=folder/'trusted_arm64.bpf.o';c.write_bytes(source);(folder/'baseline.bpf.o').write_bytes(item['object'])
        for label,args in [('frontend',['-emit-llvm','-c',c,'-o',ir]),('object',['-c',ir,'-o',obj])]:
            step=command([ROOT/'kprog/stock-path/bin/clang',*flags,*args],folder/label);row['commands'].append(step)
            if step['returncode']:row['status']=label+'-failed';break
        else:
            before=elf(item['object']);after=elf(obj.read_bytes());row.update(status='compiled',allocated_sections_equal=before['sections']==after['sections'],code_relocations_equal=before['relocations']==after['relocations'],whole_ELF_equal=item['object']==obj.read_bytes(),baseline=before,current=after)
        record['cases'].append(row);save();print(json.dumps(row),flush=True)
    record['controller_status']=int(any(r['status']!='compiled' or not r.get('allocated_sections_equal') or not r.get('code_relocations_equal') for r in record['cases']))
except Exception:
    record.update(controller_status=1,exception=traceback.format_exc())
finally:
    record['ended_utc']=now();record['header_drift']=[p for p,h in record.get('compiler_header_sha256',{}).items() if hashlib.sha256(Path(p).read_bytes()).hexdigest()!=h];save()
    with (LANE/'resume-msg.md').open('a') as f:f.write('\nARM header-source cleanup validation finished status '+str(record['controller_status'])+'. Read '+str(OUT/'validation-controller.json')+' and actual raw compiler/ELF/dispatch receipts; distinguish code/relocation equivalence from ELF/debug bytes and stock/native acceptance.\n')
raise SystemExit(record['controller_status'])
