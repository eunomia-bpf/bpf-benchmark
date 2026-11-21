"""Run each retained host command and preserve every exit independently."""
from pathlib import Path
import json,re,subprocess,sys,tarfile
S=Path(sys.argv[1]);R=Path('/workspaces/repository')
env='-include oracles/arm64_entry_environment_host.h -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include oracles/arm64_exclusive_choice_host.h'
with tarfile.open(R/'kprog/results/kprog_arm64_read_recovery_20261109/host-commands.tar.gz') as archive:
    for name in ['hosts.mk','recovery.mk']:
        text=archive.extractfile(name).read().decode().replace('/var/tmp/kprog-tmp/S2/hosts',str(S/'hosts')).replace('/var/tmp/kprog-tmp/S2/read-recovery',str(S/'read-recovery'))
        (S/name).write_text(text)
(S/'hosts').mkdir(exist_ok=True)
rows=[]
with (S/'hosts-current.log').open('w') as log:
    for name in ['hosts.mk','recovery.mk']:
        for line in (S/name).read_text().splitlines():
            if not line.startswith('\t'):continue
            cmd=line.strip().replace('$(CC)','cc').replace('$(CXX)','c++').replace('$(ARM64_HOST_ENV)',env)
            if '$(' in cmd:raise RuntimeError('unexpanded retained host command '+cmd)
            p=subprocess.run(cmd,shell=True,cwd=R/'kprog/formal',text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
            row=dict(command=cmd,exit=p.returncode);rows.append(row)
            log.write(json.dumps(row)+'\n'+p.stdout);log.flush()
            (S/'hosts-current.json').write_text(json.dumps(rows,indent=2)+'\n')
    print('commands',len(rows),'exit0',sum(r['exit']==0 for r in rows),flush=True)
