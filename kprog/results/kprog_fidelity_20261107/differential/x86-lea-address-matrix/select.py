"""Select LEA index/scale/address/write-width forms through V's candidate."""
from pathlib import Path
import hashlib,json,shutil,sys
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-x86-lea-address-matrix'
B.mkdir(exist_ok=True)
exec(compile((Path(__file__).parent/'prepare-candidate.py').read_text(),str(Path(__file__).parent/'prepare-candidate.py'),'exec'),{'__name__':'candidate_prepare'})
C=B/'candidate-tree'
matrix=[]
indices64=['rax','rcx','rdx','rbx','rbp','rsi','rdi']+[f'r{i}' for i in range(8,16)]
indices32=['eax','ecx','edx','ebx','ebp','esi','edi']+[f'r{i}d' for i in range(8,16)]
for address_bits,indices in [(64,indices64),(32,indices32)]:
    for dst in ['ax','eax','rax']:
        for index in indices:
            for scale in [1,2,4,8]:
                matrix.append(f'lea {dst}, [{index}*{scale}+7]')
        base,sp,c,a=('rbx','rsp','rcx','rax') if address_bits==64 else ('ebx','esp','ecx','eax')
        for address in [f'[{base}+{c}*1+7]',f'[{sp}+{c}*2-7]',f'[{c}+7]',f'[{a}+{c}*8+7]']:
            matrix.append(f'lea {dst}, {address}')
assert len(matrix)==len(set(matrix))==384
source=(R/'kprog/fidelity/generate.py').read_text()
forms_anchor='    forms = x86_forms(encoder.CC_AUX) if arch == "x86" else arm64_forms()\n'
assert source.count(forms_anchor)==1
source=source.replace(forms_anchor,'    forms = '+repr(matrix)+'\n')
encoder_anchor='    spec = importlib.util.spec_from_file_location("encoder", ROOT / "kprog" / arch / "micro-prog/generate_micro_sim_proofs.py")\n'
candidate=C/'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
assert source.count(encoder_anchor)==1
source=source.replace(encoder_anchor,'    spec = importlib.util.spec_from_file_location("encoder", '+repr(str(candidate))+')\n')
loader='    spec.loader.exec_module(encoder)\n'
assert source.count(loader)==1
source=source.replace(loader,'    encoder.__file__ = str(ROOT / "kprog/x86/micro-prog/generate_micro_sim_proofs.py")\n'+loader)
anchor='    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):\n'
assert source.count(anchor)==1
block="\n    from dataclasses import asdict\n    selected,bindings=[],[]\n    for assembly,e,special,body,decoded in pairs:\n        if assembly not in forms:\n            continue\n        assert e.op=='X86_OP_LEA'\n        for route in ['raw','direct']:\n            step=(f'X86_SIM_RUN_OP({e.op}, {e.dst}, {e.src}, '\n                  f'{e.flags}, {e.aux}, {e.imm})') if route=='raw' else None\n            selected.append((assembly,e,step,body,decoded))\n            bindings.append(dict(form=len(selected)-1,assembly=assembly,route=route,encoded=asdict(e)))\n    assert len(selected)==768\n    pairs=selected\n    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\\n')\n"
selected_source=source.replace(anchor,block+anchor)
compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec')
(B/'selected-generator.py').write_text(selected_source)
(B/'selection-review.json').write_text(json.dumps(dict(
 original_generator_sha256=hashlib.sha256((R/'kprog/fidelity/generate.py').read_bytes()).hexdigest(),
 selected_generator_sha256=hashlib.sha256(selected_source.encode()).hexdigest(),
 candidate_encoder_file=str(candidate),encoder_dependency_base=str(R/'kprog/x86/micro-prog'),
 matrix=matrix,inserted_block=block,
 scope='V candidate encoding, raw/direct APIs, all15 legal SIB indices/four scales/two address sizes/three write widths plus24 adjacent controls; common observer/state/masks retained.'),indent=2)+'\n')
sys.path.insert(0,str(R/'kprog/fidelity'))
sys.argv=['generate.py','--arch','x86','--out',str(B)]
exec(compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec'),{'__name__':'__main__','__file__':str(R/'kprog/fidelity/generate.py')})
changes=json.loads((B/'candidate-changes.json').read_text())
for name in changes['used_snapshot_changes']:
    shutil.copyfile(C/name,B/'snapshot'/name)
coverage=json.loads((B/'coverage.json').read_text())
bindings=json.loads((B/'numeric-bindings.json').read_text())
for row,binding in zip(coverage,bindings):
    row['route']=binding['route'];row['form']=binding['form']
(B/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')
