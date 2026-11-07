"""Select existing native forms and bind the equivalent numeric token APIs."""
from pathlib import Path
import hashlib,json,sys
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-x86-numeric-tokens'
source=(R/'kprog/fidelity/generate.py').read_text()
anchor='    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):\n'
assert source.count(anchor)==1
block=r'''
    from dataclasses import replace
    targets = {}
    for a,b,m in [('al','bl','BYTE'),('ax','bx','WORD'),
                  ('eax','ebx','DWORD'),('rax','rbx','QWORD')]:
        targets[f'add {a}, 0x7f']='X86_OP_ADD_IMM'
        targets[f'add {a}, {b}']='X86_OP_ADD_REG'
        targets[f'xor {a}, {b}']='X86_OP_XOR_REG'
        targets[f'mov {a}, {m} PTR [rdi+8]']='X86_OP_MOV_LOAD_SCALAR'
    selected, bindings, found = [], [], set()
    for assembly,e,special,body,decoded in pairs:
        if assembly not in targets:
            continue
        found.add(assembly)
        forced=replace(e,op=targets[assembly])
        for route in ['raw','direct']:
            statement=(f'X86_SIM_RUN_OP({forced.op}, {forced.dst}, {forced.src}, '
                       f'{forced.flags}, {forced.aux}, {forced.imm})') if route=='raw' else None
            label=f'{assembly} [token={forced.op}; route={route}]'
            selected.append((label,forced,statement,body,decoded))
            bindings.append(dict(assembly=assembly,route=route,original=e.__dict__,bound=forced.__dict__))
    assert found==set(targets) and len(selected)==32
    pairs=selected
    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\n')
'''
selected_source=source.replace(anchor,block+anchor)
B.mkdir(exist_ok=True)
(B/'selected-generator.py').write_text(selected_source)
(B/'selection-review.json').write_text(json.dumps(dict(
 original_generator_sha256=hashlib.sha256(source.encode()).hexdigest(),
 selected_generator_sha256=hashlib.sha256(selected_source.encode()).hexdigest(),
 inserted_block=block,
 scope='Existing native forms, legal numeric token rebinding, raw/direct entry selection; shared states, observer and comparison masks retained.'),indent=2)+'\n')
sys.path.insert(0,str(R/'kprog/fidelity'))
sys.argv=['generate.py','--arch','x86','--out',str(B)]
exec(compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec'),
     {'__name__':'__main__','__file__':str(R/'kprog/fidelity/generate.py')})
