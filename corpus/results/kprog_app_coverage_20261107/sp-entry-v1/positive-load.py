from pathlib import Path
import json,subprocess
ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
rows=json.loads((HERE/'positive-build.json').read_text())
for r in rows:
 if r['returncode']:continue
 cmd=[str(ROOT/'kprog/loader/target/debug/reversesim-loader'),'--object',r['object'],'--program',r['name']+'_x86_sim_xdp','--load-only']
 p=subprocess.run(cmd,capture_output=True,text=True);log=HERE/(r['phase']+'-'+r['name']+'.load.log');log.write_text(p.stdout+p.stderr)
 r.update(load_command=cmd,load_returncode=p.returncode);(HERE/'positive-load.json').write_text(json.dumps(rows,indent=2)+'\n');print(r['phase'],r['name'],p.returncode,flush=True)
