"""Real upstream application startup through the registered ARM service."""
import json
from pathlib import Path
import subprocess
import sys
ROOT=Path('/workspaces/repository');BASE=Path('/workspaces/.agent-state/kprog-ck')
out=Path(sys.argv[1]);case=out/'bcc-opensnoop';case.mkdir()
(case/'captures').mkdir();Path('/run/bpfrejit-checked-app').mkdir()
loader=ROOT/'runner/build-arm64-llvmbpf/native_loader/trusted-native-loader'
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
 '--run','env','LD_PRELOAD=/usr/local/lib/bpfrejit/libbpfrejit_shim.so',
 'BPFREJIT_SHIM_SOCK_DIR=/run/bpfrejit-checked-app','BPFREJIT_SHIM_DIR='+str(case/'captures'),
 'BPFREJIT_SHIM_LOG='+str(case/'shim.log'),'BPFREJIT_SHIM_NATIVE_LOADER=1',
 'BPFREJIT_SHIM_NATIVE_MANIFEST=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json',
 'BPFREJIT_NATIVE_LOADER_SO='+str(loader.with_name('libnative_loader.so')),
 'BPFREJIT_NATIVE_LINK_BINARY='+str(ROOT/'kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link'),
 '/usr/local/bin/opensnoop','-d','10']
r=subprocess.run(command,text=True,capture_output=True)
(case/'stdout').write_text(r.stdout);(case/'stderr').write_text(r.stderr)
row=dict(app='bcc-opensnoop',command=command,returncode=r.returncode)
(out/'cases.json').write_text(json.dumps([row],indent=2)+'\n');print(json.dumps(row),flush=True)
raise SystemExit(r.returncode)
