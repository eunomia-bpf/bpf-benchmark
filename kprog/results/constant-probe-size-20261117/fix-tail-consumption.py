#!/usr/bin/env python3
"""Mark a rewritten tail field consumed in native emission as well as proof."""
import argparse
from pathlib import Path

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--apply',action='store_true')
args=p.parse_args()
path=Path('/workspaces/repository/kprog/x86/native_lab/native_link/src/x86.rs')
before=path.read_text()
old='''                if let Some(offset) = tail.relocation_offset {
                    canonicalized_relocations.insert(local_site_key(sym, offset));
                }'''
new='''                if let Some(offset) = tail.relocation_offset {
                    let key=local_site_key(sym,offset);
                    canonicalized_relocations.insert(key);
                    resolved_got_relocations.insert(key); // Native emission consumed this field too.
                }'''
assert before.count(old)==1
after=before.replace(old,new)
if args.apply:path.write_text(after)
else:
    import difflib
    print(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),
                                    fromfile=str(path),tofile=str(path))),end='')
