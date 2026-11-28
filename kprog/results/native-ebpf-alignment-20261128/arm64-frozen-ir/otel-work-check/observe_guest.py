"""Independent read-only observations; never controls corpus execution or acceptance."""
from pathlib import Path
import hashlib,json,os,shutil,subprocess,sys,time,traceback
HERE=Path(__file__).resolve().parent;OUT=Path(sys.argv[1]);OUT.mkdir(parents=True,exist_ok=True);seen=set();copies={}
(OUT/'guest-abi.json').write_text(json.dumps(dict(uname=list(os.uname()),possible_cpus=Path('/sys/devices/system/cpu/possible').read_text()))+'\n')
def cache_copy():
 src=Path('/tmp/native_kernel_link_cache');dst=OUT/'linkcache'
 if not src.is_dir():return
 for p in src.rglob('*'):
  if not p.is_file() or p.is_symlink():continue
  key=str(p.relative_to(src));st=p.stat();sig=(st.st_size,st.st_mtime_ns)
  if copies.get(key)==sig:continue
  q=dst/key;q.parent.mkdir(parents=True,exist_ok=True);temp=q.with_name(q.name+'.observer-tmp');shutil.copy2(p,temp);os.replace(temp,q)
  if p.stat().st_size==st.st_size and p.stat().st_mtime_ns==st.st_mtime_ns:copies[key]=sig
while True:
 try:
  stamp=Path('/proc/uptime').read_text().split()[0];snap=OUT/'map-observe'/stamp
  r=subprocess.run(['python3',str(HERE/'observe_maps.py'),str(snap)],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
  (snap.parent/(stamp+'.log')).write_text(r.stdout)
  if r.returncode:print('snapshot failed',stamp,r.returncode,flush=True)
  else:
   row=json.loads((snap/'snapshot.json').read_text());names=set()
   for p in row['programs']:
    sig=(p['id'],p['bytes_jited']);name=p['name']
    if name in ['native_tracer_e','perf_unwind_nat','perf_unwind_sto'] and sig not in seen:seen.add(sig);names.add(name)
   if names:
    d=OUT/'progdump'/stamp;d.mkdir(parents=True,exist_ok=True)
    for name in sorted(names):
     r=subprocess.run(['python3',str(HERE/'dump_prog.py'),name,str(d)],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);(d/(name+'.log')).write_text(r.stdout+'\nreturncode='+str(r.returncode)+'\n')
    lines=Path('/proc/kallsyms').read_text().splitlines();(d/'symbols.txt').write_text('\n'.join(x for x in lines if 'bpf_prog_' in x or 'native_lab' in x or any(n in x for n in ['trie_lookup_elem','array_map_lookup_elem','bpf_probe_read_kernel','bpf_jiffies64']))+'\n')
  cache_copy()
 except Exception:print(traceback.format_exc(),flush=True)
 time.sleep(2)
