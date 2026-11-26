"""Retain the actual PEI layout for the completed range-cache control."""
import gzip
import json
from pathlib import Path
import re
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
source = HERE.relative_to(ROOT) / 'request-39/trusted_x86.bpf.packed.mir'
revision = 'd2bda6f56'
mir = subprocess.check_output(['git', 'show', revision + ':' + str(source)], cwd=ROOT)
command = ['llc-18', '-O1', '-march=bpf', '-mcpu=v4', '-bpf-stack-size=4096',
           '-start-before=prologepilog', '-stop-after=prologepilog', '-x=mir', '-o', '-', '-']
result = subprocess.run(command, input=mir, capture_output=True, check=True)
output = HERE / 'range-frame-layout.mir.gz'
output.write_bytes(gzip.compress(result.stdout, mtime=0))
documents = [d for d in result.stdout.decode().split('\n---\n') if 'body:             |' in d]
functions = []
for document in documents:
    head, body = document.split('body:             |', 1)
    name = re.search(r'^name:\s+(\S+)', head, re.M)[1]
    objects = []
    for match in re.finditer(r'^  - \{ id: (\d+), name: .*?\n.*?\}', head, re.M | re.S):
        declaration = match[0]
        kind = re.search(r'type: ([^,]+)', declaration)
        offset = re.search(r'offset: (-?\d+)', declaration)
        size = re.search(r'size: (\d+)', declaration)
        if kind and offset and size:
            objects.append(dict(id=int(match[1]), kind=kind[1], offset=int(offset[1]), size=int(size[1])))
    first = [line for line in body.splitlines() if line.strip() and not line.lstrip().startswith(('successors:', 'liveins:', 'DBG_'))][:28]
    functions.append(dict(name=name, objects=objects, first_lines=first,
                          frame_info=head[head.index('frameInfo:'):head.index('fixedStack:')]))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
              revision=revision, source=str(source), command=command,
              returncode=result.returncode, stderr=result.stderr.decode(), functions=functions,
              raw_mir=output.name,
              scope='Existing completed candidate after PEI only, no codegen-policy change, object replacement, stock replay, native execution or timing. Layout is specific to this compiled control, not a semantic lower bound.')
(HERE / 'range-frame-layout.json').write_text(json.dumps(record, indent=2) + '\n')
for function in functions:
    print(function['name'], len(function['objects']), function['frame_info'])
    print('first rejected offset objects', [o for o in function['objects'] if o['offset'] == -944])
    print('\n'.join(function['first_lines'][:18]))
