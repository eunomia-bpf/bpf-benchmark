"""Resume immutable MIR processing without an unnecessary base/image lease."""
import json
from pathlib import Path
import subprocess
import sys
import time
ROOT=Path('/workspaces/repository');out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
source=Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/post-contracts-20261119T072515Z-223517/post-contracts.bpf.before.mir')
rows=[]
for command in [
    [sys.executable,ROOT/'kprog/x86/whole_word_spills.py',source,out/'packed.mir'],
    ['llc-18','-O1','-march=bpf','-mcpu=v4','-bpf-stack-size=4096','-start-before=prologepilog','-filetype=obj',out/'packed.mir','-o',out/'B.o']]:
    start=time.perf_counter();p=subprocess.run([str(x) for x in command],text=True,capture_output=True)
    rows.append(dict(command=[str(x) for x in command],returncode=p.returncode,seconds=time.perf_counter()-start,stdout=p.stdout,stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(rows,indent=2)+'\n');p.check_returncode()
(out/'summary.json').write_text(json.dumps(dict(completed=True,source=str(source),scope='Resumed read-only MIR after successful O3 backend; no source frontend repeat, production change, stock load or native install.'),indent=2)+'\n')
