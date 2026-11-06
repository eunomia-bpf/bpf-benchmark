"""Checkpoint finite CFG-target resolution for the archived application artifacts."""
import concurrent.futures
import importlib.util
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'kprog/x86/micro-prog'))
spec=importlib.util.spec_from_file_location('target_generator',ROOT/'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
g=importlib.util.module_from_spec(spec)
sys.modules[spec.name]=g
spec.loader.exec_module(g)
OUT=HERE/'finite-targets'
OUT.mkdir(exist_ok=True)
paths=list((ROOT/'vendor/build/native-bpf/x86/stage').glob('*/*.proof.o'))
paths+=list((HERE/'native-cilium').rglob('*.proof.o'))
def scan(path):
    app='cilium' if (HERE/'native-cilium') in path.parents else next(
        part for part in path.parts if part in {'bcc','cilium','katran','otelcol-ebpf-profiler','tetragon','tracee'})
    name=app+'_'+path.name.removesuffix('.proof.o')
    output=OUT/(name+'.json')
    if output.exists():
        return json.loads(output.read_text())
    row={'name':name,'object':str(path),'app':app}
    if path.name in {'bpf_generic_uprobe_v61.try_preload_arg.proof.o','bpf_multi_uprobe_v61.try_preload_arg.proof.o'}:
        path=HERE/'zero-address-call/input/tetragon'/path.name
        row['replacement_object']=str(path)
    try:
        insns,subs,end,_=g.parse_proof_object_program(path.name.removesuffix('.proof.o'),path.parent)
        all_insns=[*insns,*(i for fn in subs.values() for i in fn)]
        targets=g.indirect_targets(all_insns,end,{insns[0].addr,*(fn[0].addr for fn in subs.values() if fn)})
        row.update(ok=True,targets={hex(a):sorted(ts) for a,ts in targets.items()},helper_symbols=sorted(
            {i.reloc_symbol for i in all_insns if i.reloc_symbol in g.helper_idents().values()}))
    except (ValueError,RuntimeError,KeyError) as error:
        row.update(ok=False,error=str(error))
    temporary=output.with_suffix('.tmp')
    temporary.write_text(json.dumps(row)+'\n')
    temporary.replace(output)
    return row
with concurrent.futures.ThreadPoolExecutor(max_workers=6) as pool:
    for n,row in enumerate(pool.map(scan,paths),1):
        print(n,len(paths),row['name'],row.get('error','resolved'),flush=True)
rows=[json.loads(f.read_text()) for f in OUT.glob('*.json')]
from collections import Counter
print('by_app',Counter((r['app'],r['ok']) for r in rows))
ids=sorted({v for r in rows if r['ok'] for ts in r['targets'].values() for k,v in ts if k=='scalar'})
print('helper_ids',[(v,g.helper_idents()[v]) for v in ids])
