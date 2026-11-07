"""Bind existing ARM immediate arithmetic forms to numeric raw/direct entries."""
from pathlib import Path
import hashlib,json,sys
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-arm64-numeric-tokens'
source=(R/'kprog/fidelity/generate.py').read_text()
anchor='    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):\n'
assert source.count(anchor)==1
block="\n    from dataclasses import replace\n    targets={f'{op} {w}0, {w}1, #127':('ARM64_OP_ADD_IMM' if op=='add' else 'ARM64_OP_SUB_IMM')\n             for op in ['add','sub'] for w in ['w','x']}\n    selected,bindings,found=[],[],set()\n    for assembly,e,special,body,decoded in pairs:\n        if assembly not in targets:\n            continue\n        found.add(assembly)\n        forced=replace(e,op=targets[assembly])\n        for route in ['raw','direct']:\n            entry='ARM64_SIM_RUN_OP3' if route=='raw' else 'ARM64_SIM_RUN_KNOWN_OP3'\n            statement=(f'{entry}({forced.op}, {forced.dst}, {forced.src}, '\n                       f'{forced.src2}, {forced.src3}, {forced.width}, {forced.aux}, {forced.imm})')\n            label=f'{assembly} [token={forced.op}; route={route}]'\n            selected.append((label,forced,statement,body,decoded))\n            bindings.append(dict(assembly=assembly,route=route,original=e.__dict__,bound=forced.__dict__))\n    assert found==set(targets) and len(selected)==8\n    pairs=selected\n    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\\n')\n"
selected_source=source.replace(anchor,block+anchor)
emit_anchor='            c += emitted\n'
assert selected_source.count(emit_anchor)==1
emit_override='            if special is not None:\n                emitted = [special + ";" ]\n'
selected_source=selected_source.replace(emit_anchor,emit_override+emit_anchor)
compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec')
B.mkdir(exist_ok=True)
(B/'selected-generator.py').write_text(selected_source)
(B/'selection-review.json').write_text(json.dumps(dict(
 original_generator_sha256=hashlib.sha256(source.encode()).hexdigest(),
 selected_generator_sha256=hashlib.sha256(selected_source.encode()).hexdigest(),
 inserted_block=block,emit_override=emit_override,
 scope='Existing native forms and legal numeric raw/direct bindings; observer, state generation and comparison masks retained.'),indent=2)+'\n')
sys.path.insert(0,str(R/'kprog/fidelity'))
sys.argv=['generate.py','--arch','arm64','--out',str(B)]
exec(compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec'),
     {'__name__':'__main__','__file__':str(R/'kprog/fidelity/generate.py')})

exec(compile((Path(__file__).parent/"apply-candidate.py").read_text(),str(Path(__file__).parent/"apply-candidate.py"),"exec"),{"__name__":"candidate_apply"})
