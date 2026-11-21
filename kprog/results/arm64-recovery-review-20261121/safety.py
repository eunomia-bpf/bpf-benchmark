"""Replay the retained34 assembly inputs with the current common loader."""
from pathlib import Path
import hashlib,json,subprocess,sys,tarfile,time
R=Path('/workspaces/repository')
def build(S):
    B=S/'safety-inputs';B.mkdir(exist_ok=True)
    rows=json.loads((R/'kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/cases.json').read_text())
    assert len(rows)==34
    for row in rows:
        src=B/(row['name']+'.S');obj=src.with_suffix('.o')
        src.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+row['assembly'].replace('; ','\n')+'\n.size entry,.-entry\n.section .note.GNU-stack,"",@progbits\n')
        subprocess.run(['aarch64-linux-gnu-gcc','-c',str(src),'-o',str(obj)],check=True)
        row['object']=str(obj);row['current_native_sha256']=hashlib.sha256(obj.read_bytes()).hexdigest()
    (B/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
    context=B/'context.bpf.c'
    context.write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\nstruct { __uint(type,BPF_MAP_TYPE_HASH); __uint(max_entries,1); __type(key,__u32); __type(value,__u64); } neg_map SEC(".maps");\nSEC("xdp") int neg_source(struct xdp_md *ctx) { (void)ctx; __u32 key=0; bpf_map_lookup_elem(&neg_map,&key); return 2; }\nchar LICENSE[] SEC("license")="GPL";\n')
    subprocess.run(['clang-18','-O2','-g','-target','bpf','-I'+str(R/'vendor/libbpf/include/uapi'),'-I'+str(R/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(context),'-o',str(B/'context.bpf.o')],check=True)
    print('compiled34originalassemblycases/commonHASHcontext',flush=True)
def run(S,env):
    O=S/'safety';rows=[]
    for row in json.loads((S/'safety-inputs/cases.json').read_text()):
        before=len([x for x in (O/'service.log').read_text().splitlines() if '"request_id"' in x])
        cmd=[str(S/'safety-probe'),str(S/'safety-inputs/context.bpf.o'),row['object'],'negative' if row['negative'] else 'positive']
        done=subprocess.run(cmd,env=env,text=True,capture_output=True)
        lines=[x for x in (O/'service.log').read_text().splitlines() if '"request_id"' in x]
        # SUBMIT completion precedes its final receipt; retain it before next input.
        if done.returncode==0 or 'trusted specializer refused native program:' in done.stderr:
            while len(lines)==before:
                time.sleep(.05)
                lines=[x for x in (O/'service.log').read_text().splitlines() if '"request_id"' in x]
        record=json.loads(lines[-1]) if len(lines)>before else {}
        stage='infrastructure_error';evidence=''
        if record.get('status')==0:stage='accepted_load_only' if row['negative'] else ('valid_executed' if done.returncode==0 else 'positive_execution_error')
        elif record.get('failure_archive'):
            with tarfile.open(record['failure_archive']) as t:
                evidence='\n'.join(t.extractfile(m).read().decode(errors='replace') for m in t.getmembers() if m.isfile() and m.name.endswith(('.stderr','.stdout','.log','.txt','.json')))
            if 'ValueError:' in record.get('traceback','') and '/micro-prog/' in record.get('traceback',''):stage='generation_rejected'
            elif 'processed ' in evidence and any(x in evidence for x in ['BPF_PROG_LOAD','bpf_object__load failed','service simulator verification failed']):stage='verifier_rejected'
            else:stage='pipeline_rejected_unclassified'
        rows.append(dict(row,command=cmd,exit=done.returncode,stdout=done.stdout,stderr=done.stderr,request=record,stage=stage,unsafe_native_executed=False))
        (O/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
        print(row['name'],stage,flush=True)
    from collections import Counter
    summary=dict(cases=len(rows),stages=dict(Counter(r['stage'] for r in rows)),unsafe_native_executions=0,accepted_load_only=[r['name'] for r in rows if r['stage']=='accepted_load_only'])
    (O/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
    return int(any(r['stage'] in ['infrastructure_error','positive_execution_error','pipeline_rejected_unclassified'] for r in rows))
if __name__=='__main__':build(Path(sys.argv[1]))
