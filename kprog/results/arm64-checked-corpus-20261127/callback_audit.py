"""Compare published callback members with retained raw files, without extraction."""
import json
from pathlib import Path
import subprocess
import sys
import tarfile

here = Path(__file__).resolve().parent
folder = here / ('guest-' + sys.argv[1] if len(sys.argv) > 1 else 'guest-20261127T012418Z')
destination = folder if len(sys.argv) > 1 else here
controller = json.loads((folder / 'controller.json').read_text())
raw = Path(controller['raw'])
parts = sorted(folder.glob('evidence.tar.zst.part-*'))
assert len(parts) == 1, parts
process = subprocess.Popen(['zstd', '-dc', str(parts[0])], stdout=subprocess.PIPE)
compared = []
with tarfile.open(fileobj=process.stdout, mode='r|') as archive:
    for member in archive:
        if member.isfile():
            path = raw.parent / member.name
            assert archive.extractfile(member).read() == path.read_bytes(), path
            compared.append(dict(member=member.name, bytes=member.size))
process.stdout.close()
assert process.wait() == 0
prefix = controller['cases'][0]['app'].split('/')[0]
report = json.loads((destination / (prefix + '-outcome.json')).read_text())
result = dict(utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              controller_status=controller['controller_status'],
              archived_files_equal_raw=len(compared), members=compared,
              requests=len(report['requests']), execution_paths=report['counts'],
              cleanup='No own deletion or preprocessing cleanup in this guest/callback; retained raw directories and archives.',
              test_run=report['test_run'])
(destination / 'callback-audit.json').write_text(json.dumps(result, indent=2) + '\n')
print('All', len(compared), 'archived files equal retained raw copies;', len(report['requests']), 'requests:', report['counts'])
