"""Stock-load the already emitted archived B objects with captured map shapes."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

mode, index, replay, out = sys.argv[1:]
index, replay, out = Path(index), Path(replay), Path(out)
source = json.loads(index.read_text())
out.mkdir(parents=True, exist_ok=True)
if mode == 'prepare':
    with tarfile.open(source['source_archive']) as archive:
        for row in source['requests']:
            directory = out/str(row['request']); directory.mkdir(exist_ok=True)
            with tarfile.open(fileobj=archive.extractfile('service/requests/'+row['capsule'])) as capsule:
                for name in ('generation.metadata.json', 'kernel.facts.json'):
                    (directory/name).write_bytes(capsule.extractfile('request/'+name).read())
    print(f"Retained map shapes/context for {len(source['requests'])} captured requests.", flush=True)
elif mode == 'load':
    results = []
    for row in source['requests']:
        request = row['request']; directory = out/str(request)
        command = [str(out/'probe-inputs/archive-stock'), str(replay/str(request)/'replay.bpf.o'),
                   str(directory/'generation.metadata.json'), str(directory/'kernel.facts.json'),
                   str(directory/'verifier.log')]
        process = subprocess.run(command, text=True, capture_output=True)
        (directory/'command.json').write_text(json.dumps(dict(command=command,
            returncode=process.returncode, stdout=process.stdout, stderr=process.stderr), indent=2)+'\n')
        record = dict(request=request, returncode=process.returncode)
        if process.stdout:
            record.update(json.loads(process.stdout))
        results.append(record)
        (out/'result.json').write_text(json.dumps(dict(source_archive=source['source_archive'],
            replay=str(replay), requests=results,
            scope='Sole-kernel detached stock loads of archived B with matching fresh map shapes. No live app binding, native execution or timing result.'), indent=2)+'\n')
        print(json.dumps(record), flush=True)
    sys.exit(1 if any(row['returncode'] for row in results) else 0)
else:
    raise ValueError(f'unknown mode {mode}')
