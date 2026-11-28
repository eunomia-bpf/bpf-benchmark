#!/usr/bin/env python3
"""Read retained original BPF ELFs with libbpf's CO-RE resolver, never load them."""
import datetime, hashlib, json, os, struct, subprocess, traceback
from pathlib import Path
ROOT=Path('/workspaces/repository')
BASE=ROOT/'kprog/results/native-ebpf-alignment-20261128/core-field-predicates'
RUN=BASE/'run'
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1024*1024),b''): h.update(b)
    return h.hexdigest()
def seal(p): return {'path':str(p),'size':p.stat().st_size,'sha256':sha(p)}
def write(p,v):
    temp=p.with_suffix(p.suffix+'.tmp');temp.write_text(json.dumps(v,indent=2)+'\n');temp.replace(p)
def bpf_elf(p):
    with p.open('rb') as f: b=f.read(20)
    return len(b)==20 and b[:4]==b'\x7fELF' and b[5] in (1,2) and int.from_bytes(b[18:20],'little' if b[5]==1 else 'big')==247

def main():
    RUN.mkdir(exist_ok=True)
    ctl={'started':now(),'status':'running','scope':'retained original BPF ELFs / main vmlinux BTF only; no module BTF or live installed-code equivalence','pid':os.getpid(),'cases':[]}
    write(RUN/'controller.json',ctl)
    try:
        ctl['inputs']=[seal(BASE/'core_query.cpp'),seal(BASE/'run_census.py'),seal(BASE/'core-query'),seal(ROOT/'runner/build-llvmbpf/vendor/libbpf/pic-obj/libbpf.a')]
        inventory=[]
        for arch in ('x86','arm64'):
            target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux'
            target_seal=seal(target)
            roots={
              'bcc':[ROOT/f'vendor/build/.bcc-libbpf/{arch}/output'],
              'katran':[ROOT/f'vendor/build/{arch}/katran/bpf'],
              'tracee':[ROOT/f'vendor/build/.tracee-build/{arch}/dist'],
              'tetragon':[ROOT/f'vendor/build/{arch}/tetragon',ROOT/f'vendor/build/.tetragon-bpf/{arch}/objs'],
              'cilium':[ROOT/f'vendor/build/{arch}/cilium'],
              'otelcol-ebpf-profiler':[ROOT/f'vendor/build/{arch}/otelcol-ebpf-profiler',ROOT/f'vendor/build/otelcol-ebpf-profiler-build-{arch}']}
            for app,dirs in roots.items():
                paths=sorted({p for d in dirs if d.exists() for p in d.rglob('*.o') if p.is_file() and bpf_elf(p)})
                entry={'arch':arch,'app':app,'searched_roots':[str(d) for d in dirs],'target':target_seal,'original_bpf_elfs':[seal(p) for p in paths]}
                entry['coverage']='retained objects found; not a loaded-program census' if paths else 'GAP: no retained original BPF ELF in searched roots; not zero relocations'
                inventory.append(entry)
        write(RUN/'inventory.json',inventory)
        errors=0
        for app in inventory:
            for source in app['original_bpf_elfs']:
                n=len(ctl['cases']);prefix=f'{n:04d}-{app["arch"]}-{app["app"]}'
                out=RUN/(prefix+'.json');err=RUN/(prefix+'.stderr')
                record={'index':n,'arch':app['arch'],'app':app['app'],'source':source,'target':app['target'],'started':now(),'result':str(out),'stderr':str(err)}
                with out.open('w') as of,err.open('w') as ef:
                    r=subprocess.run([str(BASE/'core-query'),source['path'],app['target']['path']],stdout=of,stderr=ef)
                record['returncode']=r.returncode;record['finished']=now()
                record['source_unchanged']=seal(Path(source['path']))==source
                record['result_file']=seal(out);record['stderr_file']=seal(err)
                try:
                    v=json.loads(out.read_text());record['relocation_errors']=v['errors'];record['core_kind_counts']=v['core_kind_counts']
                    rows=v['rows'];record['predicate_rows']=sum(x['kind'] in (2,8,10) for x in rows)
                    record['resolved_false_predicates']=sum(x['kind'] in (2,8,10) and x['status']==0 and not x['poison'] and x['new_val']==0 for x in rows)
                    record['changed_byte_offsets']=sum(x['kind']==0 and x['status']==0 and not x['poison'] and x['orig_val']!=x['new_val'] for x in rows)
                    record['poisoned_relocations']=sum(x['poison'] for x in rows)
                except Exception as exc: record['decode_error']=str(exc)
                if r.returncode or not record['source_unchanged'] or 'decode_error' in record: errors+=1
                ctl['cases'].append(record);write(RUN/'controller.json',ctl)
        ctl['targets_unchanged']=all(seal(Path(x['target']['path']))==x['target'] for x in inventory)
        ctl['inputs_unchanged']=all(seal(Path(x['path']))==x for x in ctl['inputs'])
        ctl['query_error_cases']=errors
        ctl['missing_original_elf_groups']=[{'arch':x['arch'],'app':x['app'],'coverage':x['coverage']} for x in inventory if not x['original_bpf_elfs']]
        ctl['status']='complete_with_query_errors' if errors or not ctl['targets_unchanged'] or not ctl['inputs_unchanged'] else 'complete'
        ctl['returncode']=int(ctl['status']!='complete')
    except Exception:
        ctl['status']='failed';ctl['returncode']=2;ctl['exception']=traceback.format_exc()
    ctl['finished']=now();write(RUN/'controller.json',ctl)
    return ctl['returncode']
if __name__=='__main__': raise SystemExit(main())
