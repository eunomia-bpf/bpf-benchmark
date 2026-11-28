"""Inspect all active generic-kprobe entry dumps in the existing six-app archive; no new guest."""
from pathlib import Path
import collections,hashlib,json,os,re,resource,subprocess,tarfile
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
BASE=ROOT/'kprog/results/native-ebpf-alignment-20261128/current-six-app-check'
A=BASE/'collections/20261128T135218Z-1485279/archive'
os.sched_setaffinity(0,{19});resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3))
sha=lambda b:hashlib.sha256(b).hexdigest()
manifest=json.loads((A/'controller.json').read_text());reviewfile=BASE/'cases/tetragon__observer/review.json';review=json.loads(reviewfile.read_text())
wanted={};metadata={};missing=[]
for phase,ph in review['phases'].items():
 obs=next(o for o in ph['observations'] if o['path']==phase+'-start')
 members={x['id']:x for x in obs['jit_files']}
 for v in ph['programs'].values():
  if v['name']!='generic_kprobe_' or not v['run_cnt_delta'] or v['bytes_jited'] not in [1879,1401]:continue
  pid=v['id']
  if pid not in members:missing.append(dict(phase=phase,counter=v,reason='Absent from original early snapshot'));continue
  x=members[pid];prefix='observations/tetragon__observer/phase-observe/'+phase+'-start/'
  stem=prefix+'progs/'+Path(x['jit']['path']).name
  wanted[stem]=manifest['files'][stem];metadata[stem]=dict(phase=phase,counter=v,functions=x['functions'])
 for suffix in ['kallsyms.txt']:
  n='observations/tetragon__observer/phase-observe/'+phase+'-start/'+suffix;wanted[n]=manifest['files'][n]
parts=sorted(A.glob('evidence.tar.zst.part-*'))
assert len(parts)==3
for p in parts:
 rows=[x for x in manifest['parts'] if Path(x['path']).name==p.name];assert len(rows)==1
 x=rows[0];b=p.read_bytes();assert len(b)==x['bytes'] and sha(b)==x['sha256']
a=subprocess.Popen(['cat',*map(str,parts)],stdout=subprocess.PIPE,stdin=subprocess.DEVNULL)
z=subprocess.Popen(['zstd','-q','-dc'],stdin=a.stdout,stdout=subprocess.PIPE);a.stdout.close();captured={}
with tarfile.open(fileobj=z.stdout,mode='r|') as tf:
 for m in tf:
  if m.name not in wanted:continue
  b=tf.extractfile(m).read();x=wanted[m.name];assert len(b)==x['bytes'] and sha(b)==x['sha256']
  captured[m.name]=b
while z.stdout.read(1024*1024):pass
assert a.wait()==z.wait()==0 and set(captured)==set(wanted)
symbols={}
for ph in review['phases']:
 text=captured['observations/tetragon__observer/phase-observe/'+ph+'-start/kallsyms.txt'].decode()
 d=collections.defaultdict(list)
 for line in text.splitlines():
  v=line.split()
  if len(v)>=3:d[int(v[0],16)].append(' '.join(v[2:]))
 symbols[ph]=d
result=dict(scope='Actual current-image archived installed JIT bytes for all active generic-kprobe entry dumps. Missing original early snapshots retained. No new timing or code generation; original May29 installed bytes remain unavailable.',image=review['image'],archive_manifest_sha256=sha((A/'controller.json').read_bytes()),review_sha256=sha(reviewfile.read_bytes()),verified_archive_members=len(captured),missing=missing,programs=[])
representative=set()
for n,info in metadata.items():
 b=captured[n];assert sum(f['bytes'] for f in info['functions'])==len(b)
 calls=[];dis=[];off=0
 for f in info['functions']:
  fd=os.memfd_create('archived-kprobe-entry')
  try:
   os.write(fd,b[off:off+f['bytes']]);os.lseek(fd,0,os.SEEK_SET)
   p=subprocess.run(['objdump','-D','-b','binary','-m','i386:x86-64','--no-show-raw-insn','--adjust-vma='+hex(f['address']),f'/proc/self/fd/{fd}'],pass_fds=(fd,),stdin=subprocess.DEVNULL,capture_output=True,text=True);assert p.returncode==0
  finally:os.close(fd)
  dis.append(p.stdout);off+=f['bytes']
  for line in p.stdout.splitlines():
   m=re.match(r'\s*([0-9a-f]+):\s+(callq?|jmpq?)\s+([^\s]+)',line)
   if not m:continue
   target=int(m[3],16) if re.fullmatch('(?:0x)?[0-9a-f]+',m[3]) else None
   calls.append(dict(address=int(m[1],16),offset=int(m[1],16)-f['address'],opcode=m[2],target=hex(target) if target is not None else m[3],symbols=symbols[info['phase']].get(target,[]),text=line.strip()))
 row=dict(**info,member=n,bytes=len(b),sha256=sha(b),hex=b.hex(),calls_and_unconditional_jumps=calls)
 result['programs'].append(row)
 if info['phase'] not in representative:
  representative.add(info['phase']);(OUT/(info['phase']+'-installed-root.dis')).write_text('\n'.join(dis))
result['call_sequences']={}
for ph in review['phases']:
 counts=collections.Counter(tuple(tuple(x['symbols']) if x['symbols'] else (x['target'],) for x in row['calls_and_unconditional_jumps'] if x['opcode'].startswith('call')) for row in result['programs'] if row['phase']==ph)
 result['call_sequences'][ph]=[dict(count=v,sequence=k) for k,v in counts.items()]
(OUT/'current-root-code.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(dict(verified_members=result['verified_archive_members'],captured_programs=len(result['programs']),missing=len(missing),sequences={p:[dict(count=x['count'],sequence=[z for z in x['sequence'] if not(z and str(z[0]).startswith('0xffffffff'))]) for x in rows] for p,rows in result['call_sequences'].items()}),indent=2))
