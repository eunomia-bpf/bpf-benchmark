#!/usr/bin/env python3
"""Read generated Cilium state headers and compiled objects into a raw archive."""
import hashlib
import io
import json
from pathlib import Path
import sys
import tarfile


def capture(root, output):
    root=root.resolve(strict=True)
    records=[]
    with tarfile.open(fileobj=output,mode='w|gz') as target:
        for path in sorted(root.rglob('*')):
            if not path.is_file() or path.suffix not in ('.h','.o'): continue
            data=path.read_bytes()
            name=str(path.relative_to(root))
            info=tarfile.TarInfo(name);info.size=len(data)
            target.addfile(info,io.BytesIO(data))
            records.append(dict(source=str(path),archive=name,bytes=len(data),sha256=hashlib.sha256(data).hexdigest()))
        data=(json.dumps(dict(state_dir=str(root),files=records),indent=2)+'\n').encode()
        info=tarfile.TarInfo('capture.json');info.size=len(data)
        target.addfile(info,io.BytesIO(data))


if __name__=='__main__': capture(Path(sys.argv[1]),sys.stdout.buffer)
