"""Compile the original generated ARM micro cohorts with the stock input ABI."""
from pathlib import Path
import json,subprocess,sys
R=Path('/workspaces/repository');S=Path(sys.argv[1]);rows=[]
for group,expected in [('micro',29),('negative',1)]:
    sources=sorted((S/(group+'-src')).glob('*.bpf.c'))
    if len(sources)!=expected:raise RuntimeError(f'{group}: {len(sources)} sources, expected {expected}')
    out=S/(group+'-objects');out.mkdir(exist_ok=True)
    for p in sources:
        cmd=['clang-18','-g','-O2','-mcpu=v4','-target','bpf','-mllvm','-bpf-stack-size=4096','-D__TARGET_ARCH_arm64','-include',str(R/'kprog/stock-path/include/stock_native_input.h'),'-I'+str(R/'kprog/arm64/micro-prog'),'-I'+str(R/'vendor/libbpf/include/uapi'),'-I'+str(R/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(p),'-o',str(out/p.with_suffix('.o').name)]
        p1=subprocess.run(cmd,capture_output=True,text=True)
        rows.append(dict(group=group,name=p.name,command=cmd,exit=p1.returncode,stderr=p1.stderr));print(group,p.name,p1.returncode,flush=True)
(S/'micro-compilation.json').write_text(json.dumps(rows,indent=2)+'\n')
raise SystemExit(int(any(x['exit'] for x in rows)))
