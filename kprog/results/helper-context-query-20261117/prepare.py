#!/usr/bin/env python3
"""Read the shipped BCC manifest and prepare two diagnostic native configurations."""
import json
from pathlib import Path, PurePosixPath
import sys
import tarfile

output = Path(sys.argv[1])
output.mkdir(parents=True, exist_ok=True)
image_path = Path('.cache/container-images/x86_64-runner-runtime.image.tar')
manifest_path = 'artifacts/user/native-bpf/x86_64/bcc/manifest.json'
runtime_dir = PurePosixPath('/opt/bpf-benchmark/native-bpf/x86_64/bcc')
with tarfile.open(image_path) as image:
    descriptor = json.load(image.extractfile('manifest.json'))[0]
    manifest = None
    for layer in reversed(descriptor['Layers']):
        with tarfile.open(fileobj=image.extractfile(layer), mode='r|*') as contents:
            for member in contents:
                if member.name.removeprefix('./') == manifest_path:
                    manifest = json.load(contents.extractfile(member))
                    break
        if manifest is not None:
            break
    if manifest is None:
        raise RuntimeError('Shipped BCC manifest is absent from the current image archive')
(output / 'shipped-manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
staged = json.loads(Path('vendor/build/native-bpf/x86/stage/bcc/manifest.json').read_text())
print('shipped entries', len(manifest['objects']), 'matches staged manifest', manifest == staged)
for mode in ('control', 'query'):
    candidate = json.loads(json.dumps(manifest))
    for entry in candidate['objects']:
        for key in ('native_object', 'source_bpf_object', 'kernel_kfunc_btf'):
            if key in entry and not PurePosixPath(entry[key]).is_absolute():
                entry[key] = str(runtime_dir / entry[key])
        if mode == 'query':
            entry['kernel_helper_context'] = True
    (output / f'{mode}-manifest.json').write_text(json.dumps(candidate, indent=2)+'\n')
    print(mode, 'entries', len(candidate['objects']), 'query enabled',
          sum(e.get('kernel_helper_context', False) for e in candidate['objects']))
