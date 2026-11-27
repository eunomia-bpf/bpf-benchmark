"""Build the existing production-relocation archive loader for the ARM guest."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time
ROOT=Path('/workspaces/repository');LANE=Path('/workspaces/.agent-state/kprog-lanes/perf')
r=json.loads((LANE/'scalar-run.json').read_text());OUT=Path(r['result']);RAW=Path(r['raw']);tool=RAW/'tools';tool.mkdir(exist_ok=True)
source=ROOT/'kprog/results/cilium-headlen-20261119/archive_stock.cpp'
includes=['micro/programs/build-arm64','kprog/libnativeloader/include','runner/build-arm64-llvmbpf/vendor/libbpf/prefix/include','vendor/libbpf/include','vendor/libbpf/include/uapi','.cache/aarch64-sysroot/usr/include']
command=['prlimit','--as=51539607552','taskset','-c','18','aarch64-linux-gnu-g++','-std=gnu++20','-O1','-g','-ffunction-sections','-fdata-sections',*['-I'+str(ROOT/p) for p in includes],str(source),'-Wl,--gc-sections',str(ROOT/'runner/build-arm64-llvmbpf/native_loader/libnative_loader.a'),str(ROOT/'runner/build-arm64-llvmbpf/vendor/libbpf/pic-obj/libbpf.a'),'-L'+str(ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'),'-Wl,-rpath-link,'+str(ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu'),'-lelf','-lz','-lzstd','-ldl','-pthread','-o',str(tool/'archive-stock')]
start=time.monotonic()
with (tool/'build.log').open('wb') as log:
 child=subprocess.Popen(command,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,cwd=ROOT);_,status,usage=os.wait4(child.pid,0);child.returncode=os.waitstatus_to_exitcode(status)
record=dict(command=command,status=child.returncode,wall_seconds=time.monotonic()-start,max_rss_kib=usage.ru_maxrss,source_sha256=hashlib.sha256(source.read_bytes()).hexdigest())
if child.returncode==0:record['binary_sha256']=hashlib.sha256((tool/'archive-stock').read_bytes()).hexdigest()
(OUT/'stock-build.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(record),flush=True)
raise SystemExit(child.returncode)
