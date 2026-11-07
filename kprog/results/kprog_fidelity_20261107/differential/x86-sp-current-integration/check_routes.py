#!/usr/bin/env python3
"""Run the existing x86 route tests against current source using shared outputs."""
from pathlib import Path
import argparse,hashlib,json,os,shlex,subprocess
R=Path('/workspaces/repository');F=R/'kprog/formal';OUT=Path(__file__).resolve().parent;S=Path('/workspaces/.agent-state/kprog-lanes/F');rows=[]
parser=argparse.ArgumentParser();parser.add_argument('--out',type=Path);parser.add_argument('--only',nargs='*');parser.add_argument('--skip-lean',action='store_true');options=parser.parse_args()
if options.out:OUT=options.out.resolve();OUT.mkdir(parents=True,exist_ok=True)
arm=next(x for x in (F/'Makefile').read_text().splitlines() if x.startswith('ARM64_HOST_ENV :=')).split(':=',1)[1].strip()
for line in (F/'Makefile').read_text().splitlines():
 if not line.startswith('\t$(CC)') or 'oracles/' not in line or '.c -o build/' not in line:continue
 args=shlex.split(line.strip().replace('$(CC)','cc').replace('$(ARM64_HOST_ENV)',arm))
 src=next((x for x in args if x.startswith('oracles/') and x.endswith('.c')),None)
 if not src or not (('x86' in Path(src).name and 'route' in Path(src).name) or Path(src).name in ['value_route_host.c','btmem_index_route_host.c','cmov_step_route_host.c']):continue
 name=Path(src).stem
 if options.only and name not in options.only:continue
 with (OUT/(name+'.compile.log')).open('w') as log:c=subprocess.run(['taskset','-c','16-19',*args],cwd=F,stdout=log,stderr=subprocess.STDOUT).returncode
 run=None
 if c==0:
  with (OUT/(name+'.log')).open('w') as log:run=subprocess.run(['taskset','-c','16-19',str(F/args[args.index('-o')+1])],cwd=F,stdout=log,stderr=subprocess.STDOUT).returncode
 rows.append(dict(source=src,sha256=hashlib.sha256((F/src).read_bytes()).hexdigest(),compile_command=args,compile_returncode=c,run_returncode=run));(OUT/'routes.json').write_text(json.dumps(rows,indent=2)+'\n');print(name,c,run,flush=True)
env=dict(os.environ,PATH='/root/.elan/bin:/usr/local/cargo/bin:'+os.environ['PATH'])
rc=0
if not options.skip_lean:
 with (OUT/'lean.log').open('w') as log:
  rc=subprocess.run(['taskset','-c','16-19','lake','build','KProgFormal.X86StackIndex','KProgFormal.X86StackArena','KProgFormal.X86XchgHandler','KProgFormal.CrossIsaStackArena','KProgFormal.X86StackArmShape','KProgFormal.Refinement.X86NumericAddress'],cwd=F,env=env,stdout=log,stderr=subprocess.STDOUT).returncode
bad=[x for x in rows if x['compile_returncode'] or x['run_returncode']];(OUT/'summary.json').write_text(json.dumps(dict(route_tests=len(rows),failed_routes=[x['source'] for x in bad],lean_returncode=rc),indent=2)+'\n');(S/'sp-current-routes.exit').write_text(str(int(bool(bad) or rc!=0))+'\n');print('finished',len(rows),'routes;',len(bad),'failures; lean',rc,flush=True)
