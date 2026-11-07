#!/usr/bin/env python3
"""Serialize saved LEAVE CPU states to the one canonical native-byte step.

No LEAVE execution is implemented here. Linux trap14/#PF maps to the model's
read fault, and trap12/#SS in these noncanonical-frame cases to non_canonical.
Only exception-delivery RF is removed from saved RFLAGS on fault; raw flags
and the complete input/output record remain in every counterexample.
"""
import argparse
import collections
import csv
import gzip
import hashlib
import json
from pathlib import Path
import subprocess


def main():
 p=argparse.ArgumentParser(description=__doc__)
 p.add_argument('--cases',type=Path,required=True)
 p.add_argument('--binary',type=Path,required=True)
 p.add_argument('--reference',type=Path,required=True)
 p.add_argument('--out',type=Path,required=True)
 p.add_argument('--input-classes',type=int,choices=(8,33),default=8,help='expected complete CPU input-class count')
 a=p.parse_args();a.out.mkdir(parents=True,exist_ok=True)
 symbols={}
 for line in subprocess.check_output(['nm',a.binary],text=True).splitlines():
  fields=line.split()
  if len(fields)==3:symbols[fields[2]]=int(fields[0],16)
 pc=symbols['leave_pc'];next_pc=symbols['leave_next']
 code=subprocess.check_output(['objdump','-d','-Mintel','--disassemble=observe_leave',a.binary],text=True)
 if not any(line.split(':',1)[0].strip()==format(pc,'x') and line.split(':',1)[1].strip().split()[:2]==['c9','leave'] for line in code.splitlines() if ':' in line):raise ValueError('observed instruction is not actual C9 LEAVE')
 if next_pc!=pc+1:raise ValueError('LEAVE instruction boundary mismatch')
 groups=collections.defaultdict(list)
 with gzip.open(a.cases,'rt') as f:
  for line in f:
   row=json.loads(line);groups[row['input_class']].append(row)
 if len(groups)!=a.input_classes or any(len(rows)!=1024 for rows in groups.values()):raise ValueError('incomplete saved CPU states')
 tables=[]
 with (a.out/'mismatches.jsonl').open('w') as bad,(a.out/'unavailable.jsonl').open('w') as missing:
  for name,rows in groups.items():
   requests=[];cells_by_case=[]
   for row in rows:
    if row['memory_changed']:raise ValueError('CPU reports a mapped-page write')
    frame=row['input']['registers'][5]
    cells=[dict(address=frame+i,value=byte,readable=True,writable=True,initialized=True) for i,byte in enumerate(row['readable_bytes'])]
    state=dict(registers=row['input']['registers'],flags=row['input']['flags'],pc=pc,xmm0=0,fs_base=0,gs_base=0,memory=cells)
    requests.append(dict(isa='x86_64',state=state,native_bytes=[201]));cells_by_case.append(cells)
   probe=subprocess.run([str(a.reference.resolve())],input=json.dumps(requests[0])+'\n',text=True,capture_output=True)
   if probe.returncode:
    missing.write(json.dumps(dict(input_class=name,error=probe.stderr,returncode=probe.returncode,first_request=requests[0]))+'\n')
    tables.append(dict(input_class=name,cpu_cases=1024,reference_cases=0,mismatches=0,status='reference_rejected',error=probe.stderr.strip()));continue
   run=subprocess.run([str(a.reference.resolve())],input='\n'.join(json.dumps(r,separators=(',',':')) for r in requests)+'\n',text=True,capture_output=True)
   if run.returncode:raise RuntimeError(run.stderr)
   answers=[json.loads(line) for line in run.stdout.splitlines()]
   if len(answers)!=len(rows):raise ValueError('incomplete canonical response')
   count=0
   for row,answer,cells in zip(rows,answers,cells_by_case):
    fault=answer['fault'];native_fault=row['signal']!=0
    actual_flags=row['observed']['flags']&(~(1<<16) if native_fault else (1<<64)-1)
    expected_kind={14:'read',12:'non_canonical'}.get(row['trap'])
    if native_fault and expected_kind is None:raise ValueError('unmapped hardware fault class')
    fault_bad=(fault is not None)!=native_fault
    if native_fault and fault is not None:
     fault_bad=fault_bad or fault['kind']!=expected_kind or fault.get('address')!=row['input']['registers'][5] or (expected_kind=='read' and fault.get('bytes')!=8)
    expected_pc=row['fault_pc'] if native_fault else row['next_pc']
    changed=(fault_bad or answer['registers']!=row['observed']['registers'] or answer['flags']!=actual_flags or answer['pc']!=expected_pc or answer['memory']!=cells)
    if changed:
     count+=1;bad.write(json.dumps(dict(input_class=name,case=row['case'],cpu=row,canonical=answer,input=requests[row['case']],normalized_cpu_flags=actual_flags))+'\n')
   tables.append(dict(input_class=name,cpu_cases=1024,reference_cases=1024,mismatches=count,status='checked',error='none'))
   print(name,'cases1024 differences',count,flush=True)
 with (a.out/'reference-classes.tsv').open('w') as f:
  w=csv.DictWriter(f,fieldnames=list(tables[0]),delimiter='\t',lineterminator='\n');w.writeheader();w.writerows(tables)
 summary=dict(cpu_cases=sum(len(rows) for rows in groups.values()),input_classes=len(groups),reference_cases=sum(r['reference_cases'] for r in tables),mismatches=sum(r['mismatches'] for r in tables),unavailable_classes=sum(r['reference_cases']==0 for r in tables),reference_sha256=hashlib.sha256(a.reference.read_bytes()).hexdigest(),cpu_binary_sha256=hashlib.sha256(a.binary.read_bytes()).hexdigest(),cpu_cases_gzip_sha256=hashlib.sha256(a.cases.read_bytes()).hexdigest(),fault_flags_normalization='clear exception-delivery RF bit16 only; compare all remaining RFLAGS',compared='all16 GPR/full normalized flags/PC/memory plus fault presence and modeled class; SIMD and segment state not measured by this CPU fixture')
 (a.out/'summary.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary))
 return int(summary['mismatches']!=0 or summary['unavailable_classes']!=0)


if __name__=='__main__':raise SystemExit(main())
