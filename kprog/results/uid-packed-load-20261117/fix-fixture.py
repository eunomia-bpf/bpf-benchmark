#!/usr/bin/env python3
"""Repair the C fixture's literal newline and consume an existing test counter."""
from pathlib import Path
old='printf("uid_gid leaf: read-only/guard/unaligned/live IDs/NULL current, %u vectors PASS'+chr(10)+'", vectors);'
new='printf("uid_gid leaf: read-only/guard/unaligned/live IDs/NULL current, %u vectors PASS'+chr(92)+'n", vectors);'
for name in ['kprog/x86/native_lab/native_link/fixtures/task_driver.c',
             'kprog/results/uid-packed-load-20261117/apply.py']:
    p=Path(name);s=p.read_text();assert s.count(old)==1,name;p.write_text(s.replace(old,new))
p=Path('kprog/x86/native_lab/native_link/src/x86_probe_read.rs');s=p.read_text()
old='println!("Probe branch layout:24 mixed-edge/relocation/recovery/append cases PASS");'
new='println!("Probe branch layout:{cases} mixed-edge/relocation/recovery/append cases PASS");'
assert s.count(old)==1;p.write_text(s.replace(old,new))
