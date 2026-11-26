"""Apply one common cache-clear control to the canonical generated B source."""
import io
import json
import os
from pathlib import Path
import sys
import tarfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
ident, records = int(sys.argv[1]), Path(sys.argv[2])
records.mkdir(parents=True, exist_ok=True)
source = HERE / f'request-{ident}/trusted_x86.bpf.c'
original = source.read_bytes()
with tarfile.open(records / 'source-before.tar.gz', 'w:gz') as archive:
    member = tarfile.TarInfo('trusted_x86.bpf.c')
    member.size = len(original)
    archive.addfile(member, io.BytesIO(original))
include = '#include ' + json.dumps(str(ROOT / 'kprog/x86/x86_sim_local_bpf.h'))
control = '#include ' + json.dumps(str(HERE / 'cache_tag_only.h'))
text = original.decode()
if control not in text:
    if text.count(include) != 1:
        raise ValueError('canonical generated source does not have its unique shared-I include')
    source.write_text(text.replace(include, include + '\n' + control, 1))
(records / 'control.json').write_text(json.dumps(dict(recipe='Ranged ghost-cache invalidation clears tag only; full clears/frame release retain original pointer clearing.',
    source_before_bytes=len(original), source_control_bytes=source.stat().st_size,
    control_header=str(HERE / 'cache_tag_only.h'), scope='Result-only normal-O1 B compiler control, one recipe for all requested cases; no production header/P/native/image change.'), indent=2) + '\n')
os.execv(sys.executable, [sys.executable, str(HERE / 'compile.py'), str(ident), str(records)])
