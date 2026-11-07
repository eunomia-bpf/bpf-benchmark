from pathlib import Path
import hashlib,json,os,shutil,subprocess,time,traceback
root=Path('/workspaces/repository');lane=Path('/workspaces/.agent-state/kprog-lanes/F');v=lane.parent/'V';source=root/'kprog/fidelity/build-sp-v3c/source';out=lane/'sp-v3c-full-export';rc=1
(lane/'sp-v3c-full.state').write_text('preparing v2 raw-setter-preserving candidate\n')
try:
 assert (lane/'local-sp-v3c-focused.exit').read_text().strip()=='0'
 def another_full_is_running():
  for line in subprocess.check_output(['ps','-eo','args='],text=True).splitlines():
   args=line.split()
   if args and Path(args[0]).name=='make' and 'check' in args[1:] and any('kprog/formal' in part for part in args[1:]):return True
  return False
 while another_full_is_running():time.sleep(10)
 assert not out.exists();out.mkdir()
 pins=json.loads((lane/'sp-v3c-source-pins.json').read_text())
 for rel,expected in pins['files'].items():
  data=(source/rel).read_bytes();assert hashlib.sha256(data).hexdigest()==expected,rel
  target=out/rel;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 (out/'vendor').symlink_to(root/'vendor',target_is_directory=True)
 shutil.copytree(root/'kprog/formal/.lake',out/'kprog/formal/.lake')
 shutil.copytree(root/'kprog/formal/build/native-link',out/'kprog/formal/build/native-link')
 (lane/'sp-v3c-full.sources.json').write_text(json.dumps(pins,indent=2)+'\n')
 (lane/'sp-v3c-full.state').write_text('running '+pins['base']+' plus only F SP/lemma/observer\n')
 env=dict(os.environ,PATH='/root/.elan/bin:/usr/local/cargo/bin:'+os.environ['PATH'])
 with (lane/'sp-v3c-full.log').open('w') as log:
  rc=subprocess.run(['taskset','-c','16-19','make','-C',str(out/'kprog/formal'),'check'],cwd=out,env=env,stdout=log,stderr=subprocess.STDOUT).returncode
except Exception:traceback.print_exc()
finally:
 if out.exists():
  assert out.resolve().parent==lane.resolve();shutil.rmtree(out)
 (lane/'sp-v3c-full.exit').write_text(str(rc)+'\n');(lane/'sp-v3c-full.state').write_text('finished '+str(rc)+'; temporary source/cache deleted\n')
 with (lane.parent/'COORDINATION.md').open('a') as f:f.write('\n- F immutable SP+publishedROR full ended '+str(rc)+', source/cache export deleted; exact logs/source hashes at F/sp-v3c-full.*. No ROOT/sharedindex writes.\n')
