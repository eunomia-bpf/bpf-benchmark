"""Select CL double-shift forms using the production encoder and observer."""
from pathlib import Path
import hashlib,json,sys
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-x86-dshift-cl16'
source=(R/'kprog/fidelity/generate.py').read_text()
matrix=[]
for op in ['shld','shrd']:
    for regs in [('ax','bx','cx','sp')]:
        a,b,c,sp=regs
        for dst,src in [(a,b),(a,a),(c,a),(a,c),(c,c),(sp,a),(a,sp),(sp,sp)]:
            matrix.append(f'{op} {dst}, {src}, cl')
assert len(matrix)==16 and len(set(matrix))==16
forms_anchor='    forms = x86_forms(encoder.CC_AUX) if arch == "x86" else arm64_forms()\n'
assert source.count(forms_anchor)==1
source=source.replace(forms_anchor,'    forms = '+repr(matrix)+'\n')
anchor='    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):\n'
assert source.count(anchor)==1
block="\n    from dataclasses import asdict\n    selected,bindings=[],[]\n    for assembly,e,special,body,decoded in pairs:\n        if assembly not in forms:\n            continue\n        for route in ['raw','direct']:\n            step=(f'X86_SIM_RUN_OP({e.op}, {e.dst}, {e.src}, '\n                  f'{e.flags}, {e.aux}, {e.imm})') if route=='raw' else None\n            selected.append((assembly,e,step,body,decoded))\n            bindings.append(dict(form=len(selected)-1,assembly=assembly,route=route,encoded=asdict(e)))\n    assert len(selected)==32\n    pairs=selected\n    (out/'numeric-bindings.json').write_text(json.dumps(bindings,indent=2)+'\\n')\n"
selected_source=source.replace(anchor,block+anchor)
B.mkdir(exist_ok=True)
(B/'selected-generator.py').write_text(selected_source)
(B/'selection-review.json').write_text(json.dumps(dict(
 original_generator_sha256=hashlib.sha256((R/'kprog/fidelity/generate.py').read_bytes()).hexdigest(),
 selected_generator_sha256=hashlib.sha256(selected_source.encode()).hexdigest(),
 matrix=matrix, inserted_block=block,
 scope='Production encoding preserved, raw/direct routes, 16-bit defined CL counts and RCX/RSP aliases; shared states, observer and comparison masks retained.'),indent=2)+'\n')
sys.path.insert(0,str(R/'kprog/fidelity'))
sys.argv=['generate.py','--arch','x86','--out',str(B)]
exec(compile(selected_source,str(R/'kprog/fidelity/generate.py'),'exec'),
     {'__name__':'__main__','__file__':str(R/'kprog/fidelity/generate.py')})
coverage=json.loads((B/'coverage.json').read_text())
bindings=json.loads((B/'numeric-bindings.json').read_text())
for row,binding in zip(coverage,bindings):
    row['route']=binding['route']
    row['form']=binding['form']
(B/'coverage.json').write_text(json.dumps(coverage,indent=2)+'\n')

driver=(R/'kprog/fidelity/driver.c').read_text()
anchor='            memcpy(before, memory, sizeof(memory));\n'
assert driver.count(anchor)==1
sample=('            input.r[1] = (input.r[1] & ~UINT64_C(255)) | '
        '(c < 128 ? c % 17 : (input.r[1] & 255) % 17);\n')
sampled=driver.replace(anchor,sample+anchor)
(B/'driver-sample.c').write_text(sampled)
review=json.loads((B/'selection-review.json').read_text())
review['input_sampling']=dict(
 scope='16-bit SHLD/SHRD architectural defined count domain 0..16; upper RCX bits and all remaining sampled state retained.',
 original_driver_sha256=hashlib.sha256(driver.encode()).hexdigest(),
 sampled_driver_sha256=hashlib.sha256(sampled.encode()).hexdigest(),
 inserted_input_assignment=sample)
(B/'selection-review.json').write_text(json.dumps(review,indent=2)+'\n')
