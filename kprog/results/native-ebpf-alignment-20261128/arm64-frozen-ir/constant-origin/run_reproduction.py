from pathlib import Path
import hashlib,json,os,subprocess,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent;LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
r=dict(pid=os.getpid(),started_utc=now(),phase='parser-library-reproduction',controller_status=None,scope='Actual embedded ARM/x86 BPF ELF and current recorded Go dependencies; VariableSpec.Set versus direct NewMap input serialization only. No BPF syscall, app rebuild, guest, image/kernel/source/settings mutation.')
def save():(OUT/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
try:
 save()
 cmd=['prlimit','--as=51539607552','--','taskset','-c','16,18','bash',str(OUT/'reproduce.sh')];r['command']=cmd;save()
 with (OUT/'reproduction.json').open('w') as stdout,(OUT/'reproduction.stderr').open('w') as stderr:r['returncode']=subprocess.run(cmd,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr).returncode
 assert r['returncode']==0;r['observations']=json.loads((OUT/'reproduction.json').read_text());r['set_value_lost_at_direct_newmap_input']=all(x['variable_after_Set']=='ffffffffffffffff' and x['map_contents_after_Set']=='0000000000000000' for x in r['observations']);r.update(controller_status=0,phase='finished-manual-source-chain-review-pending')
except Exception:r.update(controller_status=1,phase='failed',exception=traceback.format_exc())
finally:r['ended_utc']=now();save();print(json.dumps({k:r.get(k) for k in ['controller_status','phase','returncode','set_value_lost_at_direct_newmap_input','exception']}),flush=True)
raise SystemExit(r['controller_status'])
