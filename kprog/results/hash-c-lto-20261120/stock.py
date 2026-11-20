"""Use the existing stock relocation probe with fresh plain HASH maps."""
import json
from pathlib import Path
import subprocess
import sys
out=Path(sys.argv[1])
artifact=json.loads((out/'generation-inputs/fixture.json').read_text())['artifact']
(out/'metadata.json').write_text(json.dumps(dict(maps=artifact['maps']),indent=2)+'\n')
facts=dict(prog_type=2,expected_attach_type=0,prog_flags=0,prog_ifindex=0,
           attach_btf_id=0,attach_btf_obj_id=0,attach_prog_id=0,gpl_compatible=1)
(out/'kernel-facts.json').write_text(json.dumps(facts,indent=2)+'\n')
command=[str(out/'probe-inputs/archive-stock'),str(out/'generation-inputs'/Path(artifact['simulator_object']).name),
         str(out/'metadata.json'),str(out/'kernel-facts.json'),str(out/'verifier.log')]
p=subprocess.run(command,capture_output=True,text=True)
record=dict(command=command,returncode=p.returncode,stdout=p.stdout,stderr=p.stderr,
            scope='Detached sole-kernel stock verification with fresh plain HASH map; not native/app execution')
if p.stdout: record['verdict']=json.loads(p.stdout)
(out/'stock-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2),flush=True)
sys.exit(p.returncode)
