"""Compare published callback members with retained raw files, without extraction."""
import json
from pathlib import Path
import subprocess
import tarfile

here = Path(__file__).resolve().parent
folder = here / 'guest-20261127T012418Z'
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
report = json.loads((here / 'bcc-outcome.json').read_text())
assert len(report['requests']) == 23
assert all(row['status'] == 0 and row['b_generated'] for row in report['requests'])
assert report['counts'] == {'checked-sim-c': 11, 'direct-native': 12}, report['counts']
result = dict(utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              controller_status=controller['controller_status'],
              archived_files_equal_raw=len(compared), members=compared,
              requests=23, checked=11, direct=12,
              cleanup='No own deletion or preprocessing cleanup in this guest/callback; retained raw directories and archives.',
              test_run=report['test_run'])
(here / 'callback-audit.json').write_text(json.dumps(result, indent=2) + '\n')
print('All', len(compared), 'archived files equal retained raw copies; 23 requests, 11 checked, 12 direct.')
