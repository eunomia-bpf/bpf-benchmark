"""Separate GPR layout changes from existing finite-control observer failures."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[2]
p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--baseline',required=True)
p.add_argument('--output',type=Path,required=True)
a=p.parse_args(); a.output.mkdir(parents=True,exist_ok=True)
build=ROOT/'kprog/fidelity/build-x86-control'
header=ROOT/'kprog/x86/x86_sim_local_bpf.h'
old=subprocess.check_output(['git','show',a.baseline+':kprog/x86/x86_sim_local_bpf.h'],cwd=ROOT)
source=(build/'generated.c').read_text().replace('#include "../driver.h"', '#include '+json.dumps(str(ROOT/'kprog/fidelity/driver.h')))
source=source.replace('#include '+json.dumps(str(header)),old.decode())
commands=[]

def run(command,stdin=None):
    r=subprocess.run(list(map(str,command)),input=stdin,capture_output=True,text=True)
    commands.append(dict(command=list(map(str,command)),returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
    (a.output/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    return r

common=['cc','-O1','-g','-std=gnu11','-static','-I'+str(ROOT/'vendor/libbpf/src')]
suffix=[ROOT/'kprog/fidelity/driver.c',build/'native.o','-Wl,--section-start=.kprog_native=0x1000000','-o',build/'cpu-differential']
try:
    run([*common,'-iquote',header.parent,'-x','c','-','-x','none',*suffix],source).check_returncode()
    observed=run([build/'cpu-differential','256',a.output,a.output/'cpu-states.bin'])
    current=Path('/workspaces/kprog-raw/perf/20261115-preprocess-growth/cells-control/forms.tsv')
    result=dict(baseline=a.baseline,header_sha256=hashlib.sha256(old).hexdigest(),
        baseline_observer_exit=observed.returncode,
        per_form_counts_equal_current=(a.output/'forms.tsv').read_bytes()==current.read_bytes(),
        source_scope='Historical header streamed in compiler stdin; no copied source tree or retained second binary')
    (a.output/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    if observed.returncode not in (0,1): observed.check_returncode()
    print(json.dumps(result))
finally:
    # Replace the sole executable with the current checkout's normal product.
    run([*common,build/'generated.c',*suffix]).check_returncode()
