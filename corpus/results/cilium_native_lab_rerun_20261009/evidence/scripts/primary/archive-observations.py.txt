#!/usr/bin/env python3
"""Losslessly package observations, including every image and command record."""
from pathlib import Path
import shutil
import tarfile

root=Path(__file__).resolve().parent
for label in ['paper','current','paper-smoke','paper-smoke-2','paper-smoke-3','paper-smoke-4']:
    for run in sorted((root/label).glob('pair-*')):
        if not (run/'exit.json').exists():continue
        folders=[run/phase for phase in ['baseline','post_rejit'] if (run/phase).exists()]
        if not folders:continue
        archive=run/'observations.tar.gz'
        if archive.exists():raise RuntimeError('archive already exists with unpacked input: '+str(run))
        with tarfile.open(archive,'w:gz')as tar:
            for folder in folders:tar.add(folder,arcname=folder.name)
        # Verify all bytes before removing only these task-created unpacked
        # copies. The raw archive remains the authoritative observation data.
        with tarfile.open(archive,'r:gz')as tar:
            for member in tar.getmembers():
                if member.isfile():
                    saved=tar.extractfile(member).read()
                    if saved!=(run/member.name).read_bytes():raise RuntimeError('archive byte mismatch: '+member.name)
        for folder in folders:shutil.rmtree(folder)
        print(archive.relative_to(root))
