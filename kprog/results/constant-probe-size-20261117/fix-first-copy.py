#!/usr/bin/env python3
"""Forward fixes for the first scalar-copy host attempt; preserve its raw."""
import argparse
from pathlib import Path

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--apply',action='store_true')
args=p.parse_args()
root=Path('/workspaces/repository/kprog/x86/native_lab/native_link')
prepared=[]
for name,pairs in [
    ('fixtures/probe_read_driver.c',[
        ('mode == 1 || mode == 7 || mode == 9','mode == 1 || mode == 7 || mode == 11'),
        ('if (mode == 8 || mode == 9)','if (mode == 10 || mode == 11)'),
    ]),
    ('src/x86_probe_read.rs',[
        ('.arg(if user {"9"} else {"8"})','.arg(if user {"11"} else {"10"})'),
    ]),
    ('src/x86.rs',[
        ('if matches!(r_type, 1 | 2 | 10 | 11) && resolved_got_relocations',
         'if matches!(r_type, 1 | 2 | 4 | 10 | 11) && resolved_got_relocations'),
    ]),
]:
    path=root/name
    before=path.read_text();after=before
    for old,new in pairs:
        assert after.count(old)==1,(name,old,after.count(old))
        after=after.replace(old,new)
    prepared.append((path,before,after))
for path,before,after in prepared:
    if args.apply:path.write_text(after)
    else:
        import difflib
        print(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),
                                        fromfile=str(path),tofile=str(path))),end='')
