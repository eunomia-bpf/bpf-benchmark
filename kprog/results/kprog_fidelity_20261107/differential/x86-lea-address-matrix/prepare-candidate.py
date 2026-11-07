"""Apply V's published correction to an F-owned source snapshot."""
from pathlib import Path
import gzip,hashlib,json,subprocess
R=Path('/workspaces/repository')
B=R/'kprog/fidelity/build-x86-lea-address-matrix'
C=B/'candidate-tree'
P=R/'kprog/results/kprog_verification_20261107/lea-corrections.patch.gz'
published=subprocess.check_output(['git','show','154955ad9:'+str(P.relative_to(R))],cwd=R)
assert P.read_bytes()==published
patch=gzip.decompress(published)
relative=[line[6:].decode() for line in patch.splitlines() if line.startswith(b'+++ b/')]
expected=['kprog/x86/micro-prog/generate_micro_sim_proofs.py',
          'kprog/formal/tools/generate_x86_mem_offset_spec.py',
          'kprog/formal/generated/x86_mem_offset.h',
          'kprog/formal/oracles/test_x86_mem_offset_route_host.c']
assert set(relative)==set(expected) and len(relative)==4
before={}
for name in relative:
    data=(R/name).read_bytes()
    before[name]=data
    p=C/name;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
command=['git','apply','--directory='+str(C.relative_to(R))]
subprocess.run(command+['--check'],input=patch,cwd=R,check=True)
subprocess.run(command,input=patch,cwd=R,check=True)
changes={}
for name in relative:
    assert (R/name).read_bytes()==before[name]
    after=(C/name).read_bytes()
    changes[name]=dict(before_sha256=hashlib.sha256(before[name]).hexdigest(),
                       after_sha256=hashlib.sha256(after).hexdigest())
(B/'candidate-changes.json').write_text(json.dumps(dict(
 correction_commit='154955ad9',patch_sha256=hashlib.sha256(published).hexdigest(),
 changes=changes,used_snapshot_changes=[expected[0],expected[2]],
 scope='Private source correction from V; candidate encoder and offset header drive F observation.',
 production_adoption='owner_sync_pending'),indent=2)+'\n')
