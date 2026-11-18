#!/usr/bin/env python3
"""Prepare an owner-applied query patch and retain current service FD coverage."""
import argparse
from collections import Counter
import difflib
import json
from pathlib import Path
import subprocess

p=argparse.ArgumentParser(description=__doc__)
p.add_argument('--output',type=Path,required=True)
p.add_argument('--service-log',type=Path,required=True)
a=p.parse_args();a.output.mkdir(parents=True,exist_ok=True)
patch=[]
for name in ['kprog/libnativeloader/src/native_loader.cpp',
             'kprog/libnativeloader/src/native_loader_manifest.hpp']:
    before=Path(name).read_text();after=before
    if name.endswith('native_loader.cpp'):
        anchor='''    out.prog_type = prog_info.type;
    out.source_bytecode_bytes = source_insn_cnt * sizeof(bpf_insn);'''
        after=after.replace(anchor,'''    out.prog_type = prog_info.type;
    out.context_helpers = query_program_helper_targets(program_fd, prog_info.type);
    out.source_bytecode_bytes = source_insn_cnt * sizeof(bpf_insn);''',1)
        after=after.replace('    bool kernel_helper_context = false;\n','',1)
        after=after.replace('        kernel_helper_context = resolution->kernel_helper_context;\n','',1)
        after=after.replace('''    if (kernel_helper_context)
        companion.context_helpers = query_program_helper_targets(options.original_prog_fd, prog_info.type);
''','',1)
    else:
        after=after.replace('    bool kernel_helper_context = false;\n','',1)
        after=after.replace('        candidate.kernel_helper_context = json_object_bool(entry, "kernel_helper_context").value_or(false);\n','',1)
    patch.extend(difflib.unified_diff(before.splitlines(True),after.splitlines(True),
                                     fromfile='a/'+name,tofile='b/'+name))
draft=a.output/'original-fd-query.patch';draft.write_text(''.join(patch))
check=subprocess.run(['git','apply','--check',str(draft)],text=True,capture_output=True)
(a.output/'patch-check.json').write_text(json.dumps(dict(command=['git','apply','--check',str(draft)],
    returncode=check.returncode,stdout=check.stdout,stderr=check.stderr),indent=2)+'\n')
rows=[];controls=[]
for line in a.service_log.read_text().splitlines():
    entry=json.loads(line)
    if 'source_prog_id' not in entry:
        controls.append({k:entry[k] for k in ['ready','arch','endpoint','request_id','status','error'] if k in entry})
        continue
    rows.append({k:entry[k] for k in ['request_id','source_prog_id','phase','status',
        'execution_path','b_generated','b_stock_passed','started','finished','artifact_archive'] if k in entry})
counts=Counter(records=len(rows))
for r in rows:
    counts['with_source_id' if r.get('source_prog_id') else 'context_only']+=1
    if 'status' in r:counts['status:'+str(r['status'])]+=1
    if 'execution_path' in r:counts['path:'+r['execution_path']]+=1
result=dict(scope='Completed rows from one still-running checked Tracee service. '
    'A positive source ID is reopened as an actual program FD by trusted_loader.cpp. '
    'This is partial run coverage, separate from app success, prototype correctness or timing.',
    service_log=str(a.service_log),counts=dict(counts),records=rows,control_records=controls)
(a.output/'service-fd-coverage.json').write_text(json.dumps(result,indent=2)+'\n')
module=Path('/workspaces/.agent-state/kprog-ck/verified-module/bpf_x86_native_lab.ko')
strings=subprocess.check_output(['strings',str(module)],text=True)
evidence=[s for s in strings.splitlines() if s=='helper_targets' or s=='kprog_stock.c'
          or s=='native_lab_helper_query_impl.h' or s.endswith('/kprog/stock-path/module/kprog_stock.c')]
(a.output/'module-origin.json').write_text(json.dumps(dict(module=str(module),
    file_size=module.stat().st_size,selected_strings=evidence),indent=2)+'\n')
print('draft patch context status',check.returncode)
print('completed service rows',dict(counts))
print('current module origin',evidence)
raise SystemExit(check.returncode)
