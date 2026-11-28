#!/usr/bin/env python3
"""Expand the closed census to retained upstream OTel BPF outputs, no rebuild."""
import datetime,hashlib,json,os,subprocess,traceback
from pathlib import Path
ROOT=Path('/workspaces/repository');BASE=Path(__file__).resolve().parent;OUT=BASE/'additional-originals'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
 h=hashlib.sha256()
 with p.open('rb') as f:
  for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
 return h.hexdigest()
def seal(p):return dict(path=str(p),size=p.stat().st_size,sha256=sha(p))
def bpf(p):
 with p.open('rb') as f:b=f.read(20)
 return len(b)==20 and b[:4]==b'\x7fELF' and b[5] in (1,2) and int.from_bytes(b[18:20],'little' if b[5]==1 else 'big')==247
def save(c):
 p=OUT/'controller.json';q=OUT/'controller.tmp';q.write_text(json.dumps(c,indent=2)+'\n');q.replace(p)
def main():
 OUT.mkdir(exist_ok=True);c=dict(pid=os.getpid(),started=now(),status='running',latest_resume='COORDINATOR2026-11-28T14:21Z',cases=[]);save(c)
 try:
  sources=ROOT/'vendor/repos/opentelemetry-ebpf-profiler/support/ebpf'
  c['inputs']=[seal(BASE/'core-query'),seal(BASE/'core_query.cpp'),seal(BASE/'complete_original_sources.py')]
  c['frozen_app_commit']=subprocess.check_output(['git','-C',str(ROOT/'vendor/repos/opentelemetry-ebpf-profiler'),'rev-parse','HEAD'],text=True).strip()
  assert c['frozen_app_commit']=='2689a430a04318cb69f79f76adcba10dd40bb218'
  c['inventory']=[]
  for arch,goarch in [('x86','amd64'),('arm64','arm64')]:
   target=Path('/workspaces/.agent-state/kprog-ck')/('build-'+arch)/'vmlinux'
   paths=sorted(p for p in sources.iterdir() if p.is_file() and (p.name.endswith('.ebpf.'+goarch+'.o') or p.name.endswith('.ebpf.'+goarch)) and bpf(p))
   assert paths,arch
   c['inventory'].append(dict(arch=arch,app='otelcol-ebpf-profiler',target=seal(target),objects=[seal(p) for p in paths],scope='all retained arch-suffixed unit and linked EM_BPF outputs, including integration objects; not a live-loaded-program census'))
  # Preserve an exact negative inventory for existing Cilium original-build roots.
  c['cilium_roots']=[str(ROOT/'vendor/repos/cilium/bpf')]+[str(ROOT/f'vendor/build/{a}/cilium') for a in ('x86','arm64')]
  c['cilium_original_elf_paths']=sorted(str(p) for d in c['cilium_roots'] for p in Path(d).rglob('*.o') if p.is_file() and bpf(p))
  c['cilium_coverage']='No original EM_BPF ELF retained in these roots; no zero-relocation or complete Cilium coverage claim' if not c['cilium_original_elf_paths'] else 'New inputs found: architecture/config provenance must be established before querying'
  save(c);errors=0
  for group in c['inventory']:
   for source in group['objects']:
    prefix=f'{len(c["cases"]):04d}-{group["arch"]}-{Path(source["path"]).name}'
    out=OUT/(prefix+'.json');err=OUT/(prefix+'.stderr');row=dict(arch=group['arch'],source=source,target=group['target'],started=now())
    with out.open('w') as of,err.open('w') as ef:r=subprocess.run([str(BASE/'core-query'),source['path'],group['target']['path']],stdin=subprocess.DEVNULL,stdout=of,stderr=ef)
    row.update(returncode=r.returncode,result=seal(out),stderr=seal(err),source_unchanged=seal(Path(source['path']))==source,finished=now())
    try:
     v=json.loads(out.read_text());row.update(relocation_errors=v['errors'],core_kind_counts=v['core_kind_counts'],btf_ext_present=v['btf_ext_present'])
    except Exception as exc:row['decode_error']=str(exc)
    if r.returncode or not row['source_unchanged'] or 'decode_error' in row:errors+=1
    c['cases'].append(row);save(c)
  c['inputs_unchanged']=all(seal(Path(x['path']))==x for x in c['inputs'])
  c['targets_unchanged']=all(seal(Path(g['target']['path']))==g['target'] for g in c['inventory'])
  c['query_error_cases']=errors;c['returncode']=int(bool(errors) or not c['inputs_unchanged'] or not c['targets_unchanged']);c['status']='complete' if c['returncode']==0 else 'complete_with_errors'
 except Exception:
  c.update(status='failed',returncode=2,exception=traceback.format_exc())
 c['finished']=now();save(c);return c['returncode']
if __name__=='__main__':raise SystemExit(main())
