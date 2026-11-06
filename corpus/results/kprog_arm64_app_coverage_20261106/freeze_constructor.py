"""Freeze exact constructor dependencies and every staged native proof input."""
from pathlib import Path
import shutil
import sys
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
from tcb import imports, includes
phase=Path(sys.argv[1]).resolve();phase.mkdir()
paths=includes(ROOT/'kprog/arm64/arm64_sim_local_bpf.h') | imports(ROOT/'kprog/arm64/micro-prog/generate_micro_sim_proofs.py')
paths.add(ROOT/'vendor/libbpf/src/bpf_helper_defs.h')
for path in paths:
 out=phase/'constructor'/path.relative_to(ROOT);out.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(path,out)
shutil.copytree(ROOT/'vendor/build/native-bpf/arm64/stage',phase/'input',ignore=shutil.ignore_patterns('*.native.o','*.bpf.o','*.json','*.S','*.log','*.bin'))
coverage.freeze_simulator(phase)
print(f'{len(paths)} constructor inputs and all staged native proofs frozen')
