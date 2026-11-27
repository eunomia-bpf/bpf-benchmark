"""Read-only guest snapshots of actual program-array targets, mapping hits and metrics."""
import ctypes as C,errno,json,os,struct,sys
from pathlib import Path
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True);libc=C.CDLL(None,use_errno=True)
def bpf(cmd,attr):
 b=C.create_string_buffer(attr,128);rc=libc.syscall(321,cmd,b,128);return rc,b.raw,C.get_errno()
def info(fd,size):
 b=C.create_string_buffer(size);rc,_,err=bpf(15,struct.pack('<IIQ',fd,size,C.addressof(b)))
 if rc<0:raise OSError(err,'BPF_OBJ_GET_INFO_BY_FD')
 return b.raw
def ids(next_cmd,fd_cmd):
 current=0
 while True:
  rc,b,err=bpf(next_cmd,struct.pack('<III',current,0,0))
  if rc<0:
   if err!=errno.ENOENT:raise OSError(err,'get next ID')
   return
  current=struct.unpack_from('<I',b,4)[0];fd,_,err=bpf(fd_cmd,struct.pack('<III',current,0,0))
  if fd<0:
   if err==errno.ENOENT:continue
   raise OSError(err,'get ID FD')
  try:yield current,fd
  finally:os.close(fd)
def lookup(fd,key,n):
 k=C.create_string_buffer(key);v=C.create_string_buffer(n);rc,_,err=bpf(1,struct.pack('<IIQQQ',fd,0,C.addressof(k),C.addressof(v),0));return dict(returncode=rc,errno=err if rc<0 else 0,value=v.raw.hex() if rc==0 else None)
possible=Path('/sys/devices/system/cpu/possible').read_text().strip();ncpu=sum(int(x.split('-')[-1])-int(x.split('-')[0])+1 for x in possible.split(','));pids=[]
for p in Path('/proc').iterdir():
 if not p.name.isdigit():continue
 try:
  if (p/'comm').read_text().strip().startswith('stress-ng'):pids.append(int(p.name))
 except FileNotFoundError:pass
r=dict(uptime=Path('/proc/uptime').read_text().split()[0],possible_cpus=possible,stress_pids=sorted(pids),programs=[],maps=[])
for pid,fd in ids(11,13):
 i=info(fd,232);r['programs'].append(dict(id=pid,type=struct.unpack_from('<I',i)[0],name=i[64:80].split(b'\0')[0].decode(),bytes_jited=struct.unpack_from('<I',i,16)[0]))
for mid,fd in ids(12,14):
 i=info(fd,88);kind,_,ks,vs,maximum,flags=struct.unpack_from('<IIIIII',i);name=i[24:40].split(b'\0')[0].decode()
 if name not in ['perf_progs','metrics','per_cpu_records','pid_page_to_mapping_info'[:15]]:continue
 row=dict(id=mid,name=name,type=kind,key_size=ks,value_size=vs,max_entries=maximum,flags=flags,queries=[]);size=((vs+7)//8*8)*ncpu if kind in [5,6,10] else vs
 if name=='per_cpu_records':
  x=lookup(fd,struct.pack('<I',0),size)
  if x['returncode']==0:
   filename=str(mid)+'-percpu-record.bin';(out/filename).write_bytes(bytes.fromhex(x.pop('value')));x['file']=filename
  row['queries'].append(dict(key=0,**x))
 elif name=='pid_page_to_mapping_info'[:15]:
  for pid in pids:row['queries'].append(dict(pid=pid,**lookup(fd,struct.pack('<I',96)+struct.pack('>IQ',pid,0),size)))
 else:
  for key in range(maximum):row['queries'].append(dict(key=key,**lookup(fd,struct.pack('<I',key),size)))
 r['maps'].append(row)
(out/'snapshot.json').write_text(json.dumps(r,indent=2)+'\n')
