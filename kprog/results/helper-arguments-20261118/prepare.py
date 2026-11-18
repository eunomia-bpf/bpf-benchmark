#!/usr/bin/env python3
"""Prepare the producer-owner selector draft while preserving its trace caller."""
from pathlib import Path
import difflib

path=Path('vendor/bpf/core-compat.h')
old=path.read_text()
start=old.index('static __always_inline unsigned long native_helper_id1(')
end=old.index('static __always_inline unsigned long native_helper_id5(',start)
new=old[:start]+old[end:]
start=new.index('#define native_bpf_helper1(')
end=new.index('#define NATIVE_BPF_FUNC_map_lookup_elem',start)
new=new[:start]+'''/* The final C call evaluates arguments; the selector preserves its helper ID. */
#define native_bpf_helper1(type, id, a0) native_bpf_helper0(type, id)
#define __kprog_va1(a, ...) a
#define native_bpf_helper2(type, id, a0, a1) native_bpf_helper0(type, id)
#define native_bpf_helper3(type, id, a0, a1, a2) native_bpf_helper0(type, id)
#define native_bpf_helper4(type, id, a0, a1, a2, a3) native_bpf_helper0(type, id)
#define native_bpf_helper5(type, id, a0, a1, a2, a3, a4) native_bpf_helper0(type, id)

'''+new[end:]
out=Path('kprog/results/helper-arguments-20261118/id-only-selector.patch')
out.write_text(''.join(difflib.unified_diff(old.splitlines(True),new.splitlines(True),
                                         fromfile='a/'+str(path),tofile='b/'+str(path))))
print('draft additions/deletions',sum(1 for l in out.read_text().splitlines() if l.startswith('+') and not l.startswith('+++')),
      sum(1 for l in out.read_text().splitlines() if l.startswith('-') and not l.startswith('---')))
print('native_helper_id5 stays for __kprog_trace_printk; its helper-call semantics need a separate review')
