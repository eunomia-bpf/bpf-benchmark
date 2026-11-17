#!/usr/bin/env python3
"""Inspect embedded frontend IR of the actual staged manifest objects, without rewriting P."""
from collections import Counter
import json
from pathlib import Path
import re
import subprocess
import sys

raw = Path(sys.argv[1])
raw.mkdir(parents=True, exist_ok=True)
stage = Path('/workspaces/repository/vendor/build/native-bpf/x86/stage')
asm_pattern = re.compile(r'\basm(?: sideeffect)?(?: alignstack)?(?: inteldialect)?\s+"((?:[^"\\]|\\.)*)",\s*"((?:[^"\\]|\\.)*)"')
rows = []
commands = []
for app in ('otelcol-ebpf-profiler', 'bcc', 'cilium', 'tetragon', 'tracee', 'katran'):
    manifest = json.loads((stage/app/'manifest.json').read_text())
    objects = sorted({(stage/app/entry['native_object']).resolve() for entry in manifest['objects']})
    for index, source in enumerate(objects):
        name = f'{app}-{index:03d}'
        before = source.stat()
        bc, ll = raw/(name+'.bc'), raw/(name+'.ll')
        for command in (['llvm-objcopy-18', '--dump-section=.llvmbc='+str(bc), str(source), '/dev/null'],
                        ['llvm-dis-18', str(bc), '-o', str(ll)]):
            result = subprocess.run(command, capture_output=True, text=True)
            commands.append(dict(argv=command, returncode=result.returncode,
                                 stdout=result.stdout, stderr=result.stderr))
            (raw/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
            result.check_returncode()
        text = ll.read_text()
        function = None
        occurrences = []
        declarations = []
        for lineno, line in enumerate(text.splitlines(), 1):
            if line.startswith('define '):
                function = line
            if line.startswith('declare ') and '@bpf_' in line:
                declarations.append(dict(line=lineno, text=line))
            match = asm_pattern.search(line)
            if match:
                assembly, constraints = match.groups()
                occurrences.append(dict(line=lineno, function=function,
                    assembly=assembly, constraints=constraints, text=line.strip()))
        after = source.stat()
        row = dict(app=app, source=str(source), bitcode=str(bc), ir=str(ll),
                   bitcode_bytes=bc.stat().st_size, ir_bytes=ll.stat().st_size,
                   source_size_before=before.st_size, source_size_after=after.st_size,
                   source_mtime_before=before.st_mtime_ns, source_mtime_after=after.st_mtime_ns,
                   inline_asm=occurrences, helper_declarations=declarations)
        rows.append(row)
        counts = Counter('empty' if not r['assembly'] else 'nonempty' for r in occurrences)
        print(app, source.name, 'asm', dict(counts), 'helper declarations', len(declarations), flush=True)
result = dict(scope='Read-only host-staged frontend IR inventory. Not current-image execution, installed '
                    'size or timing. Memory clobbers and nonempty asm are recorded, not removed.', objects=rows)
(raw/'inventory.json').write_text(json.dumps(result, indent=2)+'\n')
summary = []
for app in sorted({r['app'] for r in rows}):
    selected = [r for r in rows if r['app']==app]
    forms = Counter((a['assembly'],a['constraints']) for r in selected for a in r['inline_asm'])
    summary.append(dict(app=app, objects=len(selected), bitcode_bytes=sum(r['bitcode_bytes'] for r in selected),
                        forms=[dict(assembly=k[0], constraints=k[1], count=v) for k,v in forms.items()],
                        helper_declarations=sum(len(r['helper_declarations']) for r in selected)))
(raw/'summary.json').write_text(json.dumps(summary, indent=2)+'\n')
print('completed objects',len(rows),flush=True)
