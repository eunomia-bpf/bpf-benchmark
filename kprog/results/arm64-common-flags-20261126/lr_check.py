"""An AAPCS call overwrites LR: it cannot retain a frozen-map address fact."""
import gzip
import json
from pathlib import Path
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
phase=sys.argv[1]
commands=[]
def run(command):
 r=subprocess.run(list(map(str,command)),text=True,capture_output=True)
 commands.append(dict(command=list(map(str,command)),returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (HERE/f'lr-{phase}-commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 r.check_returncode()
 return r.stdout
obj=BUILD/'lr.o'
run(['clang-18','--target=aarch64-linux-gnu','-c',HERE/'lr_fixture.S','-o',obj])
(HERE/'lr.o.gz').write_bytes(gzip.compress(obj.read_bytes(),mtime=0))
plan=BUILD/'lr-plan.json'
plan.write_text(json.dumps(dict(version=1,maps=[dict(name='frozen_map',addr=0x200000)],
 helpers=[dict(name='bpf_ktime_get_ns',addr=0x100000)],
 const_values=[dict(name='frozen_map',hex='1122334455667788')])) )
rows=[]
for entry in ['lr_after_blr','lr_after_bl']:
 output=BUILD/'lr.bin'
 proof=BUILD/'lr.proof.o'
 run([ROOT/'kprog/x86/native_lab/native_link/target/release/native-link','--input',obj,
      '--symbol',entry,'--mode','proof','--preserve-entry-abi','--output',proof])
 run([ROOT/'kprog/x86/native_lab/native_link/target/release/native-link','--input',proof,
      '--symbol',entry,'--mode','kernel','--link-plan',plan,'--output',output])
 data=output.read_bytes()
 (HERE/f'lr-{phase}-{entry}.bin').write_bytes(data)
 # The actual post-call instruction is LDR X0,[X30], encoding f94003c0.
 rows.append(dict(entry=entry,load_from_lr_retained=bytes.fromhex('c00340f9') in data,
                  blob_bytes=len(data)))
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 phase=phase,rows=rows,scope='Actual assembled/native-link kernel-mode frozen-map rewrite regression; no kernel execution, stock, app or timing claim.')
(HERE/f'lr-{phase}-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2))
if phase=='after' and not all(row['load_from_lr_retained'] for row in rows):raise AssertionError('stale LR map fact')
