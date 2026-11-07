"""Observe partial-register storage through native instructions and both simulator entries."""
from pathlib import Path
import hashlib,json,sys,tarfile
R=Path('/workspaces/repository')
O=Path(__file__).resolve().parent
B=R/'kprog/fidelity/build-x86-partial-gpr-candidate'
B.mkdir(exist_ok=True)
source=(R/'kprog/fidelity/generate.py').read_text()
forms_anchor='    forms = x86_forms(encoder.CC_AUX) if arch == "x86" else arm64_forms()\n'
assert source.count(forms_anchor)==1
source=source.replace(forms_anchor,'    forms = '+repr(['mov al, bl', 'mov ah, bl', 'mov al, ah', 'mov ah, al', 'mov ax, bx', 'mov r8b, r9b', 'mov r8w, r9w', 'mov dil, sil', 'mov bpl, dl', 'mov spl, al', 'mov sp, ax', 'mov eax, ebx', 'mov rax, rbx', 'mov al, 0x7f', 'mov ah, 0x7f', 'mov ax, 0x7fff'])+'\n')
anchor='    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):\n'
assert source.count(anchor)==1
selected_source=source.replace(anchor,"\n    from dataclasses import asdict\n    selected,bindings=[],[]\n    for assembly,e,special,body,decoded in pairs:\n        if assembly not in forms:\n            continue\n        for route in ['raw','direct']:\n            step=(f'X86_SIM_RUN_OP({e.op}, {e.dst}, {e.src}, '\n                  f'{e.flags}, {e.aux}, {e.imm})') if route=='raw' else None\n            selected.append((assembly,e,step,body,decoded))\n            bindings.append(dict(form=len(selected)-1,assembly=assembly,route=route,encoded=asdict(e)))\n    assert len(selected)==32\n    pairs=selected\n    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\\n')\n"+anchor)
compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec')
(B/'selected-generator.py').write_text(selected_source)
(B/'selection-review.json').write_text(json.dumps(dict(original_generator_sha256=hashlib.sha256((R/'kprog/fidelity/generate.py').read_bytes()).hexdigest(),selected_generator_sha256=hashlib.sha256(selected_source.encode()).hexdigest(),matrix=['mov al, bl', 'mov ah, bl', 'mov al, ah', 'mov ah, al', 'mov ax, bx', 'mov r8b, r9b', 'mov r8w, r9w', 'mov dil, sil', 'mov bpl, dl', 'mov spl, al', 'mov sp, ax', 'mov eax, ebx', 'mov rax, rbx', 'mov al, 0x7f', 'mov ah, 0x7f', 'mov ax, 0x7fff'],inserted_block="\n    from dataclasses import asdict\n    selected,bindings=[],[]\n    for assembly,e,special,body,decoded in pairs:\n        if assembly not in forms:\n            continue\n        for route in ['raw','direct']:\n            step=(f'X86_SIM_RUN_OP({e.op}, {e.dst}, {e.src}, '\n                  f'{e.flags}, {e.aux}, {e.imm})') if route=='raw' else None\n            selected.append((assembly,e,step,body,decoded))\n            bindings.append(dict(form=len(selected)-1,assembly=assembly,route=route,encoded=asdict(e)))\n    assert len(selected)==32\n    pairs=selected\n    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\\n')\n"),indent=2)+'\n')
sys.path.insert(0,str(R/'kprog/fidelity'))
sys.argv=['generate.py','--arch','x86','--out',str(B)]
exec(compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec'),{'__name__':'__main__','__file__':str(R/'kprog/fidelity/generate.py')})
target=B/'snapshot/kprog/formal/generated/x86_reg_write.h'
with tarfile.open(O/'candidate-inputs.tar.gz') as archive:
    prior=archive.extractfile('before.h').read()
    after=archive.extractfile('include/generated/x86_reg_write.h').read()
assert target.read_bytes()==prior
assert hashlib.sha256(after).hexdigest()=='ad3b3e39ea65e459dc5d3a20902d33738457e965c3c16c56c9c790e4134562d3'
target.write_bytes(after)
(B/'candidate-changes.json').write_text(json.dumps(dict(owner_publication='52e83e0216f760f70b62c973c5d32aeb3f0615b0',production_adoption='owner_runtime_candidate',changes={'kprog/formal/generated/x86_reg_write.h':dict(before_sha256=hashlib.sha256(prior).hexdigest(),after_sha256=hashlib.sha256(after).hexdigest())}),indent=2)+'\n')
coverage=json.loads((B/'coverage.json').read_text())
bindings=json.loads((B/'numeric-bindings.json').read_text())
for row,binding in zip(coverage,bindings):
    row['route']=binding['route'];row['form']=binding['form']
(B/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
