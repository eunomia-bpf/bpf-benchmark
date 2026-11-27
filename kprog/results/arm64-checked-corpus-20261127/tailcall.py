"""Retain loader products and replay actual ARM tail-call link failures."""
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile

ROOT=Path('/workspaces/repository');HERE=Path(__file__).resolve().parent
OUT=HERE/'tailcall-fix';OUT.mkdir(exist_ok=True)
RAW=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/tailcall-fix');RAW.mkdir(exist_ok=True)
now=lambda:subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
if sys.argv[1]=='capture':
 paths=[ROOT/'runner/build-arm64-llvmbpf/native_loader'/name for name in ['trusted-native-loader','libnative_loader.so','libnative_loader.a','trusted-service-client']]
 with tarfile.open(OUT/'loader-before.tar.gz','w:gz') as archive:
  for path in paths:archive.add(path,arcname=path.name)
 with tarfile.open(OUT/'loader-before.tar.gz') as archive:
  for path in paths:assert archive.extractfile(path.name).read()==path.read_bytes()
 (OUT/'loader-before.json').write_text(json.dumps(dict(utc=now(),files=[dict(path=str(p),bytes=p.stat().st_size) for p in paths],note='Archived products byte-compared before the one ARM loader build is replaced in place.'),indent=2)+'\n')
 print('Retained and compared',len(paths),'canonical ARM loader products')
elif sys.argv[1]=='replay':
 source=Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T021445Z/otelcol-ebpf-profiler-profiling/service.tar.gz')
 linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'
 # Values already supplied by the ordinary ARM loader. Field offsets from
 # the sole kernel's generated kernel_offsets.h and bpf_prog BTF (bpf_func72).
 keys=dict(__native_arm64_bpf_map_max_entries_offset=68,__native_arm64_bpf_array_ptrs_offset=304,__native_arm64_bpf_prog_bpf_func_offset=72,__native_arm64_tail_call_offset=28)
 report=dict(utc=now(),scope='Actual archived loader proof objects/plans; offline kernel linking only, no runtime/install claim.',layout=keys,cases=[])
 with tarfile.open(source) as outer:
  for number in [2,7,8,12,13]:
   case=RAW/str(number);case.mkdir(exist_ok=True)
   with tarfile.open(fileobj=io.BytesIO(outer.extractfile(f'service/requests/{number}.failure.tar.gz').read())) as inner:
    files={Path(m.name).name:m for m in inner if m.isfile()}
    plan_name=next(n for n in files if n.endswith('.link-plan.json'))
    proof_name=plan_name.removesuffix('.link-plan.json')+'.proof.o'
    for name in [plan_name,proof_name,'artifacts.json']:(case/name).write_bytes(inner.extractfile(files[name]).read())
   plan=json.loads((case/plan_name).read_text());symbol=json.loads((case/'artifacts.json').read_text())['symbol']
   assert not any(x['name'] in keys for x in plan['helpers'])
   patched=dict(plan,helpers=plan['helpers']+[dict(name=k,addr=v) for k,v in keys.items()])
   (case/'after-plan.json').write_text(json.dumps(patched,indent=2)+'\n')
   row=dict(request=number,symbol=symbol,commands=[])
   for name,plan_path in [('before',case/plan_name),('after',case/'after-plan.json')]:
    command=[str(linker),'--input',str(case/proof_name),'--symbol',symbol,'--mode','kernel','--link-plan',str(plan_path),'--output',str(case/(name+'.bin'))]
    r=subprocess.run(command,text=True,capture_output=True);row['commands'].append(dict(name=name,command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
    if name=='before':assert r.returncode!=0 and 'needs __native_arm64_bpf_map_max_entries_offset' in r.stderr
    else:r.check_returncode();row['bytes']=(case/'after.bin').stat().st_size
   report['cases'].append(row);(OUT/'replay.json').write_text(json.dumps(report,indent=2)+'\n')
 with tarfile.open(OUT/'replay.tar.gz','w:gz') as archive:archive.add(RAW,arcname='tailcall-fix')
 print('Actual loader proof replay:',[(r['request'],r['bytes']) for r in report['cases']])
elif sys.argv[1]=='startup':
 command=['qemu-aarch64-static','-L',str(ROOT/'.cache/qemu-arm64-root'),'-cpu','cortex-a57',str(ROOT/'runner/build-arm64-llvmbpf/native_loader/trusted-native-loader'),'abi']
 r=subprocess.run(command,text=True,capture_output=True)
 (OUT/'startup.json').write_text(json.dumps(dict(utc=now(),command=command,returncode=r.returncode,stdout=r.stdout,stderr=r.stderr),indent=2)+'\n')
 r.check_returncode();print(r.stdout.strip())
else:raise ValueError(sys.argv[1])
