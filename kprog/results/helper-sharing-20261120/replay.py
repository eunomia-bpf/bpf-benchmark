"""Re-emit two archived accepted programs through the real native API.

Only generated inputs are restored to their one canonical output directory;
the repository, headers and compiler tools remain the existing checkout.
"""
from concurrent.futures import ThreadPoolExecutor, as_completed
import argparse
import importlib.util
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import time
import traceback
from elftools.elf.elffile import ELFFile

parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('out',type=Path)
parser.add_argument('--capture',type=Path,default=Path('/workspaces/kprog-raw/perf/lpm-c-lto-20261120/combined-otel-20261120T043228Z/service.tar.gz'))
parser.add_argument('--requests',type=int,nargs='+',default=[3,4])
args=parser.parse_args()
root=Path('/workspaces/repository');out=args.out;out.mkdir(parents=True,exist_ok=True)
build=Path('/var/tmp/kprog-tmp/perf/helper-sharing')
capture=args.capture
os.environ['CLANG']=str(root/'kprog/stock-path/bin/clang')
sys.path[:0]=[str(root/'kprog'),str(root/'kprog/x86/micro-prog')]
spec=importlib.util.spec_from_file_location('sharing_native',root/'kprog/x86/trusted_specializer.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
def sizes(data,symbol):
    elf=ELFFile(io.BytesIO(data))
    functions=[dict(name=s.name,bytes=s['st_size']) for s in elf.get_section_by_name('.symtab').iter_symbols()
               if s['st_info']['type']=='STT_FUNC']
    return dict(entry_bytes=next(s['bytes'] for s in functions if s['name']==symbol),
                executable_bytes=sum(s['sh_size'] for s in elf.iter_sections() if s['sh_flags']&4),functions=functions)
jobs=[]
with tarfile.open(capture) as service:
    records=[json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    for identity in args.requests:
        record=next(row for row in records if row['request_id']==identity)
        assert record['b_stock_passed'] and record['execution_path']=='checked-sim-c',record
        with tarfile.open(fileobj=io.BytesIO(service.extractfile('service/requests/'+Path(record['artifact_archive']).name).read())) as capsule:
            artifact=json.load(capsule.extractfile('request/generated/artifacts.json'))
            directory=build/str(identity);directory.mkdir(parents=True,exist_ok=True)
            for field in ['simulator_source','simulator_preprocessed']:
                name=Path(artifact[field]).name
                (directory/name).write_bytes(capsule.extractfile('request/generated/'+name).read())
                artifact[field]=str(directory/name)
            frontend=dict(artifact['simulator_frontend']);name=Path(frontend['path']).name
            (directory/name).write_bytes(capsule.extractfile('request/generated/'+name).read())
            frontend['path']=str(directory/name);artifact['simulator_frontend']=frontend
            artifact['kernel_btf']='/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'
            symbol=artifact['simulator_program']
            before={kind:sizes(capsule.extractfile('request/generated/checked-simulator.'+suffix).read(),symbol)
                    for kind,suffix in [('native','native.o'),('proof','proof.o')]}
            jobs.append((identity,artifact,before))
def emit(job):
    identity,artifact,before=job;started=time.monotonic()
    native=module.compile_checked_simulator(artifact,
        root/'kprog/x86/native_lab/native_link/target/release/native-link',
        Path('/workspaces/.agent-state/kprog-ck/verified-compiler/compile-sim-ir'))
    after={kind:sizes(Path(native[field]).read_bytes(),native['symbol'])
           for kind,field in [('native','native_object'),('proof','native_proof_object')]}
    row=dict(request_id=identity,symbol=artifact['symbol'],before=before,after=after,native=native,
             native_emission_seconds=time.monotonic()-started,
             scope='Same archived accepted B frontend/native API. Proof executable bytes include all reachable workers. Native object total also includes unreferenced helper definitions. No app execution or speed claim.')
    (out/f'request-{identity}.json').write_text(json.dumps(row,indent=2)+'\n')
    print(identity,artifact['symbol'],before['proof']['executable_bytes'],after['proof']['executable_bytes'],flush=True)
    return row
rows=[];failed=[]
with ThreadPoolExecutor(max_workers=2) as pool:
    futures={pool.submit(emit,job):job[0] for job in jobs}
    for future in as_completed(futures):
        try: rows.append(future.result())
        except Exception:
            identity=futures[future];failed.append(identity)
            (out/f'request-{identity}-failure.txt').write_text(traceback.format_exc())
(out/'replay-result.json').write_text(json.dumps(dict(capture=str(capture),rows=rows,failed=failed),indent=2)+'\n')
if failed: raise RuntimeError('Native replay failed for captured requests '+str(failed))
