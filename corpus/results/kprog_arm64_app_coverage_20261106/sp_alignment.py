"""Retain exact native SP-alignment counterexamples for load-only verification."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve();phase.mkdir();(phase/'native').mkdir()
rows=[]
for name in ['misaligned-sp','unaligned-address']:
    source=phase/'native'/(name+'.S')
    shutil.copy2('/workspaces/.agent-state/kprog-lanes/V/sp-alignment/'+name+'.S',source)
    native=source.with_suffix('.native.o')
    subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',native],check=True)
    proof=phase/'native'/(name+'.proof.o')
    subprocess.run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,
        '--symbol','entry','--mode','proof','--preserve-entry-abi','--output',proof],check=True)
    functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'entry','xdp'),phase/'native')
    cname=name.replace('-','_')
    (phase/(name+'.bpf.c')).write_text(gen.render_program(cname,'entry',functions,'xdp',rodata16=rodata,linked_exit=True))
    (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\nSEC("xdp") int '+cname+'(struct xdp_md *ctx) { return 0; }\nchar LICENSE[] SEC("license")="GPL";\n')
    (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=cname,native_object='/cases/'+native.name,
        symbol='entry',simulator_object='/cases/'+name+'.bpf.o',simulator_program=cname+'_arm64_sim_xdp')]},indent=2)+'\n')
    rows.append(dict(name=name,program=cname,expected=0,expected_rc=int(sys.argv[2]) if name=='misaligned-sp' else 0))
(phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
coverage.freeze_simulator(phase)
for source in phase.glob('*.bpf.c'):
    source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
shutil.copy2(phase.parent/'fmov-bank-bound-v2/bound-probe',phase/'bound-probe')
