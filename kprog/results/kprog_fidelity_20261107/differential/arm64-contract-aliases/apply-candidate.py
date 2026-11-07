"""Install A's published synchronized C contract headers in the F snapshot."""
from pathlib import Path
import hashlib,json,re,subprocess,tarfile
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-arm64-contract-aliases'
S=B/'snapshot'
P=R/'corpus/results/kprog_arm64_app_coverage_20261107/numeric-contract-sync'
COMMIT='f9b20a904'
def sha(data):return hashlib.sha256(data).hexdigest()
for name in ['inputs.tar.gz','summary.json','candidate.patch.gz']:
    assert (P/name).read_bytes()==subprocess.check_output(['git','show',COMMIT+':'+str((P/name).relative_to(R))],cwd=R)
summary=json.loads((P/'summary.json').read_text())
assert sha((P/'inputs.tar.gz').read_bytes())==summary['inputs_sha256']
relative=['kprog/formal/generated/arm64_dispatch_family.h',
          'kprog/formal/generated/arm64_alu_operand_select.h',
          'kprog/arm64/arm64_sim_direct.h']
changes={}
with tarfile.open(P/'inputs.tar.gz') as archive:
    for name in relative:
        before=archive.extractfile('before/'+name).read()
        after=archive.extractfile('after/'+name).read()
        assert (S/name).read_bytes()==before
        live=(R/name).read_bytes()
        assert live==before
        (S/name).write_bytes(after)
        changes[name]=dict(before_sha256=sha(before),after_sha256=sha(after),
                           source='f9b20a904:inputs.tar.gz:after/'+name)
        assert (R/name).read_bytes()==live
    old=archive.extractfile('before/'+relative[2]).read().decode()
    new=archive.extractfile('after/'+relative[2]).read().decode()
pattern=r'#define ARM64_SIM_DIRECT_(ARM64_OP_\w+)\([^\n]*\) \\\nARM64_SIM_DIRECT_BODY_(\d+)\('
old_map=dict(re.findall(pattern,old));new_map=dict(re.findall(pattern,new))
assert len(old_map)==len(new_map)==71
changed=[op for op in old_map if old_map[op]!=new_map[op]]
assert set(changed)=={'ARM64_OP_ADD_IMM','ARM64_OP_SUB_IMM'}
assert new_map['ARM64_OP_ADD_IMM']==new_map['ARM64_OP_SUB_IMM']==new_map['ARM64_OP_ALU_IMM']
marker='#define ARM64_SIM_DIRECT_ARM64_OP_'
assert old.split(marker,1)[0]==new.split(marker,1)[0]
(B/'candidate-changes.json').write_text(json.dumps(dict(
 scope='A synchronized generic immediate-alias contracts; C headers copied exactly from published candidate bundle into F private compiled snapshot.',
 candidate_commit=COMMIT,candidate_inputs_sha256=summary['inputs_sha256'],
 changes=changes,changed_direct_tokens=changed,retained_direct_tokens=69,
 generated_body_text_equal=True,
 universal_alias_theorem=summary['universal_theorem'],
 production_adoption='owner_sync_pending'),indent=2)+'\n')
