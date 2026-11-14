#!/usr/bin/env python3
"""Export the existing native linker's canonical BPF-helper names for IR lowering."""
import json
from pathlib import Path
import re

source = Path(__file__).resolve().parents[2]/'kprog/x86/native_lab/native_link/src/x86.rs'
body = source.read_text().split('pub(super) fn bpf_helper_name_from_id', 1)[1].split('\n}\n', 1)[0]
pairs = re.findall(r'(\d+)\s*=>\s*Some\("([^"]+)"\)', body)
names = dict(pairs)
if not names or len(names) != len(pairs):
    raise ValueError('missing or duplicate canonical helper IDs')
print(json.dumps(names, indent=2))
