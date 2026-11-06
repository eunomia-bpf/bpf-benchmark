"""Package every paired BCC resident entry for the unchanged corpus runtime."""
import json
from pathlib import Path
import shutil
import sys
HERE=Path(__file__).resolve().parent
phase=HERE/sys.argv[1]
out=HERE/sys.argv[2]
out.mkdir()
app=out/'bcc';app.mkdir()
manifest=json.loads((phase/'manifest.json').read_text())
rows=[json.loads(line) for line in (phase/'programs.jsonl').read_text().splitlines()]
if len(manifest['objects'])!=len(rows) or any(not row['ok'] for row in rows):
    raise ValueError('every actual BCC entry must have a generated proof')
for entry in manifest['objects']:
    for field in ('native_object','simulator_object'):
        source=Path(entry[field])
        if not source.is_file(): raise FileNotFoundError(source)
        shutil.copy2(source,app/source.name)
        entry[field]='/opt/bpf-benchmark/native-bpf/x86_64/bcc/'+source.name
(app/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
for source,name in [(HERE/'context-runtime-shim.so','libbpfrejit_shim.so'),
                    (HERE/'native-dispatch-link/release/native-link','native-link')]:
    shutil.copy2(source,out/name)
shutil.copy2(phase/'load-pairing.json',out/'load-pairing.json')
print(f'packaged all {len(rows)} BCC resident entries; probes/transient coverage remains in startup records')
