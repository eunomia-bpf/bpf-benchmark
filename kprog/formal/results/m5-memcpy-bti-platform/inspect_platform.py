from pathlib import Path
import argparse,datetime,hashlib,json,os,subprocess
p=argparse.ArgumentParser();p.add_argument('--output',required=True,type=Path);a=p.parse_args()
processes=[]
for process in Path('/proc').iterdir():
 if not process.name.isdigit():continue
 try: args=process.joinpath('cmdline').read_bytes().split(b'\0')
 except (FileNotFoundError,ProcessLookupError):continue
 if args and args[0].split(b'/')[-1]==b'qemu-system-aarch64':
  processes.append((process,[v.decode() for v in args if v]))
if len(processes)!=1:raise RuntimeError('expected the current sole AArch64 guest process')
proc,args=processes[0];cpu=args[args.index('-cpu')+1]
if cpu!='cortex-a57':raise RuntimeError('record the actual represented CPU domain: '+cpu)
exe=Path(os.readlink(proc/'exe'));version=subprocess.check_output([str(exe),'--version'],text=True)
build=Path('/workspaces/.agent-state/kprog-ck/build-arm64');config=build/'.config'
relevant=[l for l in config.read_text().splitlines() if 'CONFIG_ARM64_BTI' in l or 'CONFIG_AS_HAS_MOPS' in l]
inputs=[config,Path('/workspaces/repository/vendor/linux-framework/arch/arm64/lib/memcpy.S')]
result={'recorded_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'guest_pid':int(proc.name),'guest_command':args,
 'cpu':cpu,'emulator':str(exe),'emulator_version':version,
 'emulator_sha256':hashlib.file_digest(exe.open('rb'),'sha256').hexdigest(),'config_features':relevant,
 'inputs':{str(f):{'sha256':hashlib.file_digest(f.open('rb'),'sha256').hexdigest(),'bytes':f.stat().st_size} for f in inputs},
 'domain':'actual unmodified Cortex-A57 invocation and sole kernel configuration; live text and feature-register binding continue explicitly'}
a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({'cpu':cpu,'version':version,'output':str(a.output)},indent=2))
