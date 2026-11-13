#!/usr/bin/env python3
"""Read generated Cilium state headers and compiled objects into a raw archive."""
import hashlib
import io
import json
from pathlib import Path
import sys
import tarfile


def capture(root, output, features=None, artifacts=()):
    root=root.resolve(strict=True)
    records=[]
    with tarfile.open(fileobj=output,mode='w|gz') as target:
        paths=[(path,str(path.relative_to(root))) for path in sorted(root.rglob('*'))
               if path.is_file() and path.suffix in ('.h','.o','.json')]
        if features is not None:
            paths += [(features/name,'generated-features/'+name)
                      for name in ('features.h','features_skb.h','features_xdp.h')]
        for directory,prefix in artifacts:
            paths += [(path,prefix+'/'+str(path.relative_to(directory)))
                      for path in sorted(directory.rglob('*')) if path.is_file()]
        for path,name in paths:
            data=path.read_bytes()
            info=tarfile.TarInfo(name);info.size=len(data)
            target.addfile(info,io.BytesIO(data))
            records.append(dict(source=str(path),archive=name,bytes=len(data),sha256=hashlib.sha256(data).hexdigest()))
        data=(json.dumps(dict(state_dir=str(root),files=records),indent=2)+'\n').encode()
        info=tarfile.TarInfo('capture.json');info.size=len(data)
        target.addfile(info,io.BytesIO(data))


if __name__=='__main__':
    root=Path(sys.argv[1])
    # Native-link cache contains generated ELF/plan/blob artifacts, not app source.
    cache=Path('/tmp/native_kernel_link_cache')
    capture(root,sys.stdout.buffer,Path(sys.argv[2]) if len(sys.argv)>2 else None,
            [(cache,'native-link-cache')] if cache.exists() else [])
