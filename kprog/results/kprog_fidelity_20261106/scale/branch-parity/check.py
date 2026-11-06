"""Catch dispatch/folding mistakes that an all-ones packet can conceal."""
import json
from pathlib import Path
import subprocess
import sys

root=Path(__file__).resolve().parents[5]
build=Path(sys.argv[1])
fidelity=root/'kprog/fidelity/build-x86'
objects={
    'n10000_ptr_direct':fidelity/'scale-late-regref/n10000_ptr_direct.bpf.o',
    'n10000_ptr_indirect':fidelity/'scale-late-indirect/n10000_ptr_indirect.bpf.o',
    'n10000_scalar_direct':fidelity/'scale/n10000_scalar_direct.bpf.o',
    'n10000_scalar_indirect':fidelity/'scale-late-scalar-indirect/n10000_scalar_indirect.bpf.o',
}
rows=[]
failed=False
for name,obj in objects.items():
    for byte in [0,1,2,3,127,128,254,255]:
        stem=f'{name}-byte{byte}'
        native=subprocess.run([str(build/name),str(byte)],capture_output=True,text=True)
        Path(stem+'.native.log').write_text(native.stdout+native.stderr)
        row=dict(name=name,input_byte=byte,native_returncode=native.returncode)
        if native.returncode:
            row.update(stage='native_failed',error=native.stderr)
        else:
            reference=json.loads(native.stdout)
            row['native']=reference
            probe=subprocess.run([str(build/'scale-probe'),str(obj),stem+'.verifier.log',
                                  str(reference['result']),str(byte)],capture_output=True,text=True)
            Path(stem+'.probe.log').write_text(probe.stdout+probe.stderr)
            row.update(stage='passed' if probe.returncode==0 else 'probe_failed',
                       probe_returncode=probe.returncode,error=probe.stderr)
            counters=[json.loads(line) for line in probe.stdout.splitlines() if line.startswith('{')]
            if counters: row['probe_counters']=counters
        rows.append(row)
        failed |= row['stage']!='passed'
        Path('outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
        print(stem+': '+row['stage'],flush=True)
raise SystemExit(int(failed))
