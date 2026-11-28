"""Execute actual public XDP accessors against the current physical ABI."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
phase=sys.argv[1];assert phase in ['before','before-canonical','before-isolated','after'];DEST=OUT/phase;DEST.mkdir(exist_ok=False);os.sched_setaffinity(0,{19})
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits():
 resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{16})
r=dict(pid=os.getpid(),started_utc=now(),controller_status=None,cases=[],layouts=[])
try:
 for arch in ['x86','arm64']:
  btf=Path(f'/workspaces/.agent-state/kprog-ck/build-{arch}/vmlinux');raw=subprocess.run([str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),'-j','btf','dump','file',str(btf),'format','raw'],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True);types=json.loads(raw.stdout)['types'];selected={x['name']:x for x in types if x.get('kind')=='STRUCT' and x.get('name') in ['xdp_buff','xdp_rxq_info','net_device']}
  fields={kind:{m['name']:m['bits_offset']//8 for m in t['members']} for kind,t in selected.items()};assert fields['xdp_buff']['rxq']==32 and fields['xdp_rxq_info']['dev']==0 and fields['net_device']['ifindex']==224
  r['layouts'].append(dict(architecture=arch,path=str(btf),sha256=sha(btf),types=selected))
  output=DEST/(arch+'.elf');flags=['-O3','-g','-fPIC','-DMICRO_NATIVE','-fomit-frame-pointer','-fno-stack-protector','-fno-asynchronous-unwind-tables','-fno-unwind-tables','-fno-jump-tables','-fno-optimize-sibling-calls','-Wno-unknown-attributes','-mllvm','-switch-to-lookup=false']
  flags+=['-march=native','-mno-red-zone','-mgeneral-regs-only','-mllvm','-x86-cmov-converter-force-all'] if arch=='x86' else ['--target=aarch64-linux-gnu','-mtune=neoverse-n1','-mgeneral-regs-only','-mno-outline-atomics','-ffixed-x26']
  inc=ROOT/'vendor/bpf/cilium/bpf';args=['clang-18',*flags,'-include',str(ROOT/'vendor/bpf/native_compat.h'),'-I'+str(inc/'include'),'-I'+str(inc/'include/bpf'),'-I'+str(inc),'-c',str(OUT/'ifindex_witness.c'),'-o',str(DEST/(arch+'-accessors.o'))]
  with (DEST/(arch+'-compile.log')).open('xb') as f:c=subprocess.run(args,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=limits)
  row=dict(architecture=arch,compile_command=args,compile_returncode=c.returncode);r['cases'].append(row);assert c.returncode==0,arch
  driver=['clang-18',*flags,'-static',str(OUT/'ifindex_driver.c'),str(DEST/(arch+'-accessors.o')),'-o',str(output)];row['driver_compile_command']=driver
  with (DEST/(arch+'-driver-compile.log')).open('xb') as f:c=subprocess.run(driver,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=limits)
  row['driver_compile_returncode']=c.returncode;assert c.returncode==0,arch
  command=[str(output)] if arch=='x86' else ['qemu-aarch64-static',str(output)]
  c=subprocess.run(command,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE);(DEST/(arch+'-stdout.txt')).write_bytes(c.stdout);(DEST/(arch+'-stderr.txt')).write_bytes(c.stderr);row.update(execute_command=command,execute_returncode=c.returncode);row.update(values=json.loads(c.stdout),regression_passed=c.returncode==0)
  tool='objdump' if arch=='x86' else 'aarch64-linux-gnu-objdump';dis=subprocess.run([tool,'-d',str(DEST/(arch+'-accessors.o'))],stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True);(DEST/(arch+'-disassembly.txt')).write_bytes(dis.stdout)
 sources=['vendor/bpf/cilium/bpf/include/bpf/ctx/xdp.h','vendor/bpf/cilium/bpf/include/linux/bpf.h','vendor/bpf/native_compat.h','vendor/linux-framework/net/core/filter.c'];r.update(controller_status=0,regression_passed=all(x['regression_passed'] for x in r['cases']),sources={n:sha(ROOT/n) for n in sources},scope='Actual native header accessor execution against a physical context fixture whose pointer-chain offsets match both canonical kernel BTFs and xdp_convert_ctx_access. Not kernel execution, actual corpus path or timing acceptance.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:
 r['ended_utc']=now();r['files']={p.name:dict(bytes=p.stat().st_size,sha256=sha(p)) for p in DEST.iterdir() if p.is_file() and p.name!='controller.json'};(DEST/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
raise SystemExit(r['controller_status'])
