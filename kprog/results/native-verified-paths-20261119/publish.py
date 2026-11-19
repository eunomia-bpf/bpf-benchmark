"""Publish the completed post-verification path subset, retaining raw outputs."""
from pathlib import Path
import json
import subprocess
import sys
raw=Path(sys.argv[1]);stamp=sys.argv[2];dst=Path('kprog/results/native-verified-paths-20261119')
summary=json.loads((raw/'summary.json').read_text());rows=json.loads((raw/'bcc-replay/replay.json').read_text())
(dst/'host-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
(dst/'bcc-replay.json').write_text(json.dumps(rows,indent=2)+'\n')
with (dst/'README.md').open('a') as f:f.write(f'\nPERF {stamp}: Actual native compiler build and verified-domain/ordinary-check regression pass. All25 retained BCC production compile APIs/proof links pass with C helpers enabled, as do the ARRAY and retained OTel regressions. Raw {raw}. This is host post-verification code generation, not new stock acceptance, installed code or app performance.\n')
with Path('kprog/docs/optimizations.md').open('a') as f:f.write(f'\nPERF {stamp}: After stock B acceptance, compile_sim_ir.cpp replaces only the exact invalid call-minus-one and null-store fault forms with llvm.assume(false). B, ordinary program checks, recoverable probe errors and direct-native fallback retain their behavior. Host verified-domain/ordinary-check execution tests, recoverable probe tests,25 BCC compile/proof replays and ARRAY/OTel regressions pass; all C helper pieces stay on. Runtime/body/helpers/maps/installed bytes await the combined batch. Results native-verified-paths-20261119.\n')
todo=Path('kprog/docs/todo.md');text=todo.read_text();pos=text.index('## 0. Lane 目标与待办')+len('## 0. Lane 目标与待办');note=f'\n\nPERF {stamp}: Native verifier-invalid-path elimination implemented and host-tested;25 BCC and ARRAY/OTel compile regressions pass. C helpers remain enabled. Source/receipt in results/native-verified-paths-20261119; app per-call/body/helpers/maps/installed results remain pending the combined checked-sim-c batch.\n';todo.write_text(text[:pos]+note+text[pos:])
paths=['kprog/x86/compile_sim_ir.cpp',str(dst/'host-summary.json'),str(dst/'bcc-replay.json'),str(dst/'README.md'),'kprog/docs/optimizations.md','kprog/docs/todo.md']
with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('w') as lock:
    import fcntl
    fcntl.flock(lock,fcntl.LOCK_EX)
    subprocess.run(['git','status','--short','--branch','--untracked-files=no'],check=True)
    subprocess.run(['git','diff','--check','--',*paths],check=True)
    subprocess.run(['git','add',*paths],check=True)
    subprocess.run(['git','commit','-m','Eliminate verifier-invalid paths from checked native LTO','--',*paths],check=True)
    subprocess.run(['git','push','origin','master'],check=True)
    commit=subprocess.run(['git','log','-1','--format=%h'],text=True,capture_output=True,check=True).stdout.strip()
with Path('/workspaces/.agent-state/kprog-lanes/COORDINATION.md').open('a') as f:f.write(f'\n- LANE PERF {stamp}: Native verifier-invalid-path source and host receipt pushed as {commit}; verified-domain/ordinary-check execution, recoverable probe tests,25 BCC production compile/proof and ARRAY/OTel regressions pass. Compiler tools rebuilt in place under timing SH/image EX, no image or guest. Raw {raw}; runtime effect remains pending the combined batch.\n')
