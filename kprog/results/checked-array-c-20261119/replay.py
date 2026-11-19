"""Replay retained checked app frontends, without regenerating or changing B."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile

ROOT=Path('/workspaces/repository')
sys.path[:0]=[str(ROOT/'kprog'),str(ROOT/'kprog/x86/micro-prog')]
from trusted_generation import native_map_label
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
archive=Path(sys.argv[2]) if len(sys.argv)>2 else Path('/workspaces/kprog-raw/verified/20261118-deletion-check/bcc/service.tar.gz')
compiler=Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir')
rows=[]
def requests():
    if archive.is_dir():
        for path in sorted(archive.glob('*.success.tar.gz'),key=lambda p:int(p.name.split('.')[0])):
            with tarfile.open(path) as request:
                yield path.name,request
    else:
        with tarfile.open(archive) as outer:
            members=sorted((m for m in outer.getmembers() if m.name.endswith('.success.tar.gz')),
                           key=lambda m:int(Path(m.name).name.split('.')[0]))
            for member in members:
                with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as request:
                    yield Path(member.name).name,request

for name,request in requests():
        directory=out/name.split('.')[0];directory.mkdir(exist_ok=True)
        metadata=json.load(request.extractfile('request/generation.metadata.json'))
        arrays=[native_map_label(m['name']) for m in metadata['maps']
                if m['map_type']==2 and m.get('value_offset') is None]
        (directory/'frontend.bc').write_bytes(request.extractfile('request/generated/checked-simulator.bc').read())
        args=[str(compiler),str(directory/'frontend.bc'),'-o',str(directory/'native.bc'),
              *[v for name in arrays for v in ('--array-map',name)]]
        p=subprocess.run(args,text=True,capture_output=True)
        row=dict(request=name,arrays=arrays,returncode=p.returncode,stderr=p.stderr)
        rows.append(row)
        (out/'replay.json').write_text(json.dumps(rows,indent=2)+'\n')
        p.check_returncode()
        p=subprocess.run(['llvm-dis-18',str(directory/'native.bc'),'-o','-'],text=True,capture_output=True,check=True)
        row['selected_calls']=sum('call ptr @__kprog_array_lookup(' in l for l in p.stdout.splitlines())
        row['generic_calls']=sum('call ptr @bpf_map_lookup_elem(' in l for l in p.stdout.splitlines())
        print(row,flush=True)
(out/'replay.json').write_text(json.dumps(rows,indent=2)+'\n')
print('frontends',len(rows),'selected calls',sum(r['selected_calls'] for r in rows),
      'generic calls',sum(r['generic_calls'] for r in rows))
