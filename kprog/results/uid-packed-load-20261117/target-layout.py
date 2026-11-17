#!/usr/bin/env python3
"""Read UID/GID layout from the sole kernel through the existing BTF reader."""
import argparse,importlib.util,json
from pathlib import Path
root=Path(__file__).resolve().parents[3]
p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
spec=importlib.util.spec_from_file_location('core_answers',root/'vendor/bpf/core-answers.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
kernel=Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
types=m.Btf(root/'vendor/build/x86/bpftool/bin/bpftool',kernel)
layout={};fields={}
for name,parent,field in [('task_cred','task_struct','cred'),('cred_uid','cred','uid'),('cred_gid','cred','gid')]:
    member,bits=types.member(parent,[field]);t=types.resolve(member['type_id'])
    layout[name]=bits//8
    fields[name]={'type':t['name'],'size':types.size_of(t),'bit_offset':bits}
result={'kernel':str(kernel),'reader':'vendor/bpf/core-answers.py','layout':layout,'fields':fields,
        'uid_then_gid_adjacent':layout['cred_gid']==layout['cred_uid']+4}
a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
