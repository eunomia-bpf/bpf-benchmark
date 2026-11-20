"""Stock-load the emitted LPM fixture with production map relocations."""
import json
from pathlib import Path
import subprocess
import sys

here=Path(__file__).resolve().parent
out=Path(sys.argv[1]); out.mkdir(parents=True,exist_ok=True)
artifact=json.loads((here/'report.json').read_text())['generation']['artifact']
(out/'metadata.json').write_text(json.dumps(dict(maps=artifact['maps']),indent=2)+'\n')
facts=dict(prog_type=2,expected_attach_type=0,prog_flags=0,prog_ifindex=0,
           attach_btf_id=0,attach_btf_obj_id=0,attach_prog_id=0,gpl_compatible=1)
(out/'kernel-facts.json').write_text(json.dumps(facts,indent=2)+'\n')
command=[str(out/'probe-inputs/archive-stock'),artifact['simulator_object'],
         str(out/'metadata.json'),str(out/'kernel-facts.json'),str(out/'verifier.log')]
child=subprocess.run(command,capture_output=True,text=True)
record=dict(command=command,returncode=child.returncode,stdout=child.stdout,stderr=child.stderr,
    fixture_native_revision='7580c903b',kernel='sole build-x86',
    scope='Detached stock verifier acceptance with fresh map shapes; application installation and native execution remain separate.')
if child.stdout:
    record['verdict']=json.loads(child.stdout)
(out/'stock-result.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2),flush=True)
sys.exit(child.returncode)
