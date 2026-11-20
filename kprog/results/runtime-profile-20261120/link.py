"""Link the source user-copy entries with the sole kernel's real symbols."""
import json
from pathlib import Path
import subprocess
import sys

root=Path('/workspaces/repository');out=Path(sys.argv[1])
build=Path('/var/tmp/kprog-tmp/perf/runtime-profile-user')
symbols={}
for line in Path('/workspaces/.agent-state/kprog-ck/build-x86/System.map').read_text().splitlines():
    address,kind,name=line.split();symbols[name]=int(address,16)
names=['copy_from_user_nofault','memset']
plan=out/'source-link-plan.json'
plan.write_text(json.dumps(dict(version=1,helpers=[dict(name=n,addr=symbols[n]) for n in names]),indent=2)+'\n')
commands=[]
for name in ('user8','user_dynamic'):
    for mode in ('proof','kernel'):
        command=[str(root/'kprog/x86/native_lab/native_link/target/release/native-link'),
            '--input',str(build/('user.o' if mode=='proof' else 'user.proof.o')),
            '--symbol',name,'--mode',mode,'--output',str(build/('user.proof.o' if mode=='proof' else 'user.bin'))]
        command+=['--preserve-entry-abi'] if mode=='proof' else [
            '--link-plan',str(plan),'--output-relocs',str(build/'user.relocs'),
            '--output-abi',str(build/'user.abi')]
        p=subprocess.run(command,text=True,capture_output=True)
        commands.append(dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr))
        (out/'source-links.json').write_text(json.dumps(commands,indent=2)+'\n')
        p.check_returncode()
print('Two source user-copy entries pass proof and kernel linking with actual kernel bindings.')
