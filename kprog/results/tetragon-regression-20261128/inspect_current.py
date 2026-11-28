"""Reuse the committed03:56 same-image check: decode two candidate entry blobs, no guest/rebuild."""
from pathlib import Path
from elftools.elf.elffile import ELFFile
import hashlib,io,json,os,resource,subprocess,tarfile,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;RAW=Path('/workspaces/kprog-raw/perf/tetragon-regression-20261128');RAW.mkdir(parents=True,exist_ok=True)
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));sha=lambda b:hashlib.sha256(b).hexdigest();now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,phase='reuse-committed-current-code',scope='Decode existing same-image archived03:56 candidate entry objects/plans/blobs, NOT installed long-run bytes or old11-23 code. No compiler,guest,newP,image,root,app or benchmark change.')
def save():(OUT/'current-code-controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save();source=ROOT/'kprog/results/native-ebpf-alignment-20261128/check-20261128T034810Z/collection-controller.json';meta=json.loads(source.read_text());r['archive_manifest']=dict(path=str(source.relative_to(ROOT)),sha256=sha(source.read_bytes()));r['parts']=meta['parts'];keys=['14c39eec84e8b216','90f202a84992a835'];wanted={n:x for n,x in meta['files'].items() if n.startswith('tetragon__observer/linkcache/native_kernel_link_cache/') and any(Path(n).name.startswith(k+'.') for k in keys)};assert len(wanted)==14
 for p in meta['parts']:
  b=(ROOT/p['path']).read_bytes();assert len(b)==p['bytes'] and sha(b)==p['sha256']
 a=subprocess.Popen(['cat',*[str(ROOT/p['path']) for p in meta['parts']]],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL);b=subprocess.Popen(['zstd','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();captured={}
 with tarfile.open(fileobj=b.stdout,mode='r|') as tf:
  for m in tf:
   if not m.isfile():continue
   rel=str(Path(*Path(m.name).parts[1:]))
   if rel not in wanted:continue
   data=tf.extractfile(m).read();v=wanted[rel];assert len(data)==v['bytes'] and sha(data)==v['sha256'];assert rel not in captured;captured[rel]=data
 b.stdout.close();assert a.wait()==b.wait()==0;assert set(captured)==set(wanted)
 records=[]
 for key in keys:
  selected={Path(n).name:dict(member=n,bytes=len(d),sha256=sha(d)) for n,d in captured.items() if Path(n).name.startswith(key+'.')};blob=next(d for n,d in captured.items() if n.endswith('/'+key+'.blob.bin'));plan_bytes=next(d for n,d in captured.items() if Path(n).name.startswith(key+'.tmp.') and n.endswith('.link-plan.json'));plan=json.loads(plan_bytes);proof=next(d for n,d in captured.items() if n.endswith('/'+key+'.proof.o'));ef=ELFFile(io.BytesIO(proof));sym=ef.get_section_by_name('.symtab');funcs=[]
  for s in sym.iter_symbols():
   if s['st_info']['type']!='STT_FUNC' or not isinstance(s['st_shndx'],int):continue
   funcs.append(dict(name=s.name,value=s['st_value'],size=s['st_size'],section=ef.get_section(s['st_shndx']).name))
  fd=os.memfd_create('captured-generic-kprobe-entry')
  try:
   os.write(fd,blob);os.lseek(fd,0,os.SEEK_SET);cmd=['objdump','-D','-b','binary','-m','i386:x86-64',f'/proc/self/fd/{fd}'];p=subprocess.run(cmd,pass_fds=(fd,),stdin=subprocess.DEVNULL,capture_output=True,text=True);assert p.returncode==0,p.stderr
  finally:os.close(fd)
  records.append(dict(cache_key=key,origins=selected,blob_hex=blob.hex(),blob_bytes=len(blob),blob_sha256=sha(blob),plan=plan,proof_functions=funcs,disassembly_command=cmd,disassembly_returncode=p.returncode,disassembly=p.stdout,abi=next(d.decode() for n,d in captured.items() if n.endswith('/'+key+'.abi.tsv')),map_patches=next(d.decode() for n,d in captured.items() if n.endswith('/'+key+'.map-patches.tsv'))))
 anchors=[]
 for name,lo,hi in [('vendor/bpf/tetragon/bpf/process/bpf_generic_kprobe.c',67,108),('vendor/bpf/tetragon/bpf/process/generic_calls.h',20,79)]:
  p=ROOT/name;lines=p.read_text().splitlines();anchors.append(dict(path=name,sha256=sha(p.read_bytes()),lines=[dict(line=i,text=lines[i-1]) for i in range(lo,hi+1)]))
 result=dict(scope=r['scope'],archive_manifest=r['archive_manifest'],records=records,source_anchors=anchors,limits=['Canonical blob contents are pre-final-runtime-relocation; inspect relocs and wrapper before comparing installed instructions.','Long-run generic_kprobe installed lengths1329/1401 are actual receipts; these same-image candidate blobs1355 are not independently bound to the long-run loaded bytes by length.','Both current plans have constants CONFIG_ITER_NUM1/PARENTS_MAP_ENABLED0. That does not establish historical frozen values or map/attach identity.']);dest=RAW/'current-code-records.json';assert not dest.exists();dest.write_text(json.dumps(result,indent=2)+'\n');r.update(controller_status=0,phase='complete',verified_archive_members=len(captured),records=str(dest),records_sha256=sha(dest.read_bytes()),records_bytes=dest.stat().st_size)
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps(r),flush=True)
raise SystemExit(r['controller_status'])
