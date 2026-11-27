"""Existing bound-native service client through the ARM checked pipeline."""
import json
import os
from pathlib import Path
import subprocess
import sys
ROOT=Path('/workspaces/repository')
BASE=Path('/workspaces/.agent-state/kprog-ck')
out=Path(sys.argv[1]);rows=[]
loader=ROOT/'runner/build-arm64-llvmbpf/native_loader/trusted-native-loader'
client=loader.with_name('trusted-service-client')
for kind in ['xdp','tc']:
 case=out/kind;case.mkdir()
 command=['python3',str(ROOT/'kprog/trusted_service.py'),'--arch','2',
  '--endpoint','/sys/kernel/debug/bpf_arm64_native_lab/specializer',
  '--module',str(BASE/'verified-module/arm64/bpf_arm64_native_lab.ko'),
  '--state',str(case/'state'),'--results',str(case/'service.tar.gz'),
  '--native-link',str(ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'),
  '--loader',str(loader),'--execution-mode','checked-sim-c',
  '--sim-native-compiler',str(BASE/'verified-compiler/compile-sim-ir'),
  '--sim-context-compiler',str(BASE/'verified-compiler/context-lower'),
  '--sim-public-layout',str(BASE/'verified-compiler/arm64/public-layout.json'),
  '--sim-physical-layout',str(BASE/'verified-compiler/arm64/physical-layout.json'),
  '--run',str(client),'/var/tmp/kprog-tmp/perf/arm64-checked-control/control.o',kind]
 r=subprocess.run(command,text=True,capture_output=True)
 (case/'stdout').write_text(r.stdout);(case/'stderr').write_text(r.stderr)
 rows.append(dict(kind=kind,command=command,returncode=r.returncode))
 (out/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
 print(json.dumps(rows[-1]),flush=True)
if any(r['returncode'] for r in rows):raise RuntimeError('ARM checked service client failed; all attempted cases retained')
