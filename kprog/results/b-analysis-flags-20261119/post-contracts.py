"""Test O3 only after the existing B memory/identity normalization, reusing IR."""
import json
from pathlib import Path
import subprocess
import sys
import time
ROOT=Path('/workspaces/repository');sys.path.insert(0,str(ROOT/'kprog/x86'))
import trusted_specializer as worker
out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/production-20261119T063707Z-211523/tetragon6/trusted_x86.bpf.bounds.bc')
# Experiment-local policy only: frontend has already completed at O1. Keep the
# production file/flags unchanged, then optimize its normalized IR at O3.
worker.COMPILE_FLAGS[worker.COMPILE_FLAGS.index('-O1')]='-O3'
commands=[]
def run(args):
    begin=time.perf_counter();p=subprocess.run([str(x) for x in args],text=True,capture_output=True)
    commands.append(dict(command=[str(x) for x in args],returncode=p.returncode,seconds=time.perf_counter()-begin,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n');p.check_returncode()
worker._compile_simulator_backend(str(ROOT/'kprog/stock-path/bin/clang'),out/'post-contracts.bpf.c',out/'B.o',run,compiled_input=source)
(out/'summary.json').write_text(json.dumps(dict(completed=True,commands=len(commands),source=str(source),
    scope='Host-only O3-after-contracts experiment; no source frontend/normalization repeat, production policy change, stock load or native installation.'),indent=2)+'\n')
