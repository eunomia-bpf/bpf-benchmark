"""Apply a generic alias-family candidate inside the private compilation snapshot."""
from pathlib import Path
import difflib,hashlib,importlib.util,json,re
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-arm64-numeric-tokens'
S=B/'snapshot'
relative=['kprog/formal/generated/arm64_dispatch_family.h',
          'kprog/formal/generated/arm64_alu_operand_select.h',
          'kprog/arm64/arm64_sim_direct.h']
root_hash={n:hashlib.sha256((R/n).read_bytes()).hexdigest() for n in relative}
before={n:(S/n).read_text() for n in relative}
p=S/relative[0];text=p.read_text()
anchor='(((OP) == ARM64_OP_ALU_IMM) ||'
replacement='(((OP) == ARM64_OP_ADD_IMM) || '+chr(92)+'\n\t((OP) == ARM64_OP_SUB_IMM) || '+chr(92)+'\n\t((OP) == ARM64_OP_ALU_IMM) ||'
assert text.count(anchor)==1;p.write_text(text.replace(anchor,replacement))
p=S/relative[1];text=p.read_text();anchor='\t\tcase 6U:'
assert text.count(anchor)==1
replacement='\t\tcase 3U: '+chr(92)+'\n\t\tcase 4U: '+chr(92)+'\n'+anchor
p.write_text(text.replace(anchor,replacement))
spec=importlib.util.spec_from_file_location('arm_direct_candidate',R/'kprog/arm64/generate_sim_dispatch.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
generated=module.render(S/'kprog/arm64/arm64_sim_local_bpf.h',
                       S/'kprog/arm64/arm64_sim.h',B/'candidate-dispatch-probe')
(S/relative[2]).write_text(generated)
pattern=r'#define ARM64_SIM_DIRECT_(ARM64_OP_\w+)\([^\n]*\) \\\nARM64_SIM_DIRECT_BODY_(\d+)\('
old_map=dict(re.findall(pattern,before[relative[2]]));new_map=dict(re.findall(pattern,generated))
assert len(old_map)==len(new_map)==71
changed=[op for op in old_map if old_map[op]!=new_map[op]]
assert set(changed)=={'ARM64_OP_ADD_IMM','ARM64_OP_SUB_IMM'}
assert new_map['ARM64_OP_ADD_IMM']==new_map['ARM64_OP_SUB_IMM']==new_map['ARM64_OP_ALU_IMM']
assert all(hashlib.sha256((R/n).read_bytes()).hexdigest()==h for n,h in root_hash.items())
changes={}
for n in relative:
 after=(S/n).read_text()
 changes[n]=dict(before_sha256=hashlib.sha256(before[n].encode()).hexdigest(),
  after_sha256=hashlib.sha256(after.encode()).hexdigest(),
  diff=''.join(difflib.unified_diff(before[n].splitlines(True),after.splitlines(True),fromfile='a/'+n,tofile='b/'+n)))
(B/'candidate-changes.json').write_text(json.dumps(dict(
 scope='Private generic candidate: numeric3/4 join existing ALU immediate family; source fields and live production files retain their bytes.',
 changes=changes,direct_token_mapping_changes=changed,
 retained_direct_mapping_tokens=69,live_source_sha256=root_hash),indent=2)+'\n')
