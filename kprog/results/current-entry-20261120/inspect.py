"""Inspect retained OTel P and capsule products; no compilation or execution."""
import io
import json
from hashlib import sha256
from pathlib import Path
import subprocess
import sys
import tarfile

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
raw = Path('/workspaces/kprog-raw/perf/percpu-array-c-20261120/otel-20261120T062059Z/service.tar.gz')
with tarfile.open(raw) as service:
    records = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    for record in records:
        name = 'service/requests/' + Path(record['artifact_archive']).name
        with tarfile.open(fileobj=io.BytesIO(service.extractfile(name).read())) as capsule:
            names = capsule.getnames()
            symbol = capsule.extractfile('request/kernel.entry').read().decode().strip()
            if symbol != 'native_tracer_entry':
                continue
            (out/'members.json').write_text(json.dumps(names, indent=2)+'\n')
            products = []
            for name in names:
                if not name.endswith('.o'):
                    continue
                data = capsule.extractfile(name).read()
                target = out / Path(name).name
                target.write_bytes(data)
                command = ['llvm-objdump-18', '-dr', '--disassemble-symbols='+symbol, str(target)]
                result = subprocess.run(command, capture_output=True, text=True, check=True)
                assembly = target.with_suffix('.asm')
                assembly.write_text(result.stdout)
                products.append(dict(member=name, path=str(target), sha256=sha256(data).hexdigest(),
                                     bytes=len(data), command=command, assembly=str(assembly)))
            report = dict(capture=str(raw), request=record, symbol=symbol, products=products,
                          scope='Retained capsule objects; P precedes direct-native context LTO and is not the installed image. No compilation, app execution or helper latency measurement.')
            (out/'report.json').write_text(json.dumps(report, indent=2)+'\n')
            print(json.dumps(report, indent=2))
            break
    else:
        raise ValueError('No native_tracer_entry request in capture')
