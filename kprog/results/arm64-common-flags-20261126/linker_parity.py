"""Check both canonical tool executables through the legacy ARM target alias."""
import json
from pathlib import Path
import subprocess
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BUILD=Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
commands=[]
outputs={}
for entry in ['lr_after_blr','lr_after_bl']:
    outputs[entry]={}
    for arch,prefix,path in [
        ('host',[],ROOT/'kprog/arm64/build/app-native-link/release/native-link'),
        ('arm64',['qemu-aarch64-static','-cpu','cortex-a57'],ROOT/'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link')]:
        proof=BUILD/'lr.proof.o';blob=BUILD/'lr.bin'
        for args in [
            ['--input',BUILD/'lr.o','--symbol',entry,'--mode','proof','--preserve-entry-abi','--output',proof],
            ['--input',proof,'--symbol',entry,'--mode','kernel','--link-plan',BUILD/'lr-plan.json','--output',blob]]:
            command=list(map(str,[*prefix,path,*args]))
            r=subprocess.run(command,text=True,capture_output=True)
            commands.append(dict(command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
            r.check_returncode()
        outputs[entry][arch]=blob.read_bytes()
        (HERE/f'linker-{arch}-{entry}.bin').write_bytes(blob.read_bytes())
rows=[dict(entry=entry,bytes=len(result['host']),host_arm_equal=result['host']==result['arm64'],
           load_from_lr_retained=bytes.fromhex('c00340f9') in result['arm64'])
      for entry,result in outputs.items()]
(HERE/'linker-parity.json').write_text(json.dumps(dict(
    recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
    commands=commands,rows=rows,
    scope='Host and ARM native-link actual proof/kernel-mode rewrite parity on two LR cases through canonical alias; no stock/kernel/app execution or timing result.'),indent=2)+'\n')
print(json.dumps(rows,indent=2))
if not all(r['host_arm_equal'] and r['load_from_lr_retained'] for r in rows):raise AssertionError('linker parity regression')
