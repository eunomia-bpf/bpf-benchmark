"""Check whether B compile flags retain loader-required typed externs."""
import ctypes as c
import json
from pathlib import Path
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
lib=c.CDLL('libbpf.so.1');lib.bpf_object__open_file.argtypes=[c.c_char_p,c.c_void_p];lib.bpf_object__open_file.restype=c.c_void_p
lib.libbpf_get_error.argtypes=[c.c_void_p];lib.libbpf_get_error.restype=c.c_long
lib.bpf_object__close.argtypes=[c.c_void_p]
rows=[]
for label,debug in [('g0','-g0'),('line','-gline-tables-only'),('types','-g')]:
    obj=out/(label+'.o');args=['clang-18','-target','bpf','-O1',debug,'-I/usr/include/x86_64-linux-gnu',
        '-I'+str(ROOT/'vendor/libbpf/src'),'-c',str(ROOT/'kprog/results/b-analysis-flags-20261119/map.bpf.c'),'-o',str(obj)]
    p=subprocess.run(args,text=True,capture_output=True)
    (out/(label+'.compile.txt')).write_text(p.stdout+p.stderr)
    p.check_returncode()
    with obj.open('rb') as f:sections=[s.name for s in ELFFile(f).iter_sections()]
    pointer=lib.bpf_object__open_file(str(obj).encode(),None);error=lib.libbpf_get_error(pointer)
    if not error:lib.bpf_object__close(pointer)
    rows.append(dict(label=label,command=args,open_error=error,sections=sections))
    print(label,'libbpf open',error,'BTF','.BTF' in sections,flush=True)
(out/'metadata.json').write_text(json.dumps(rows,indent=2)+'\n')
assert rows[-1]['open_error']==0
