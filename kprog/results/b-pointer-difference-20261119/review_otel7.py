"""Read archived OTel evidence; do not compile, rewrite or load a program."""
import io
import json
import os
from pathlib import Path
import subprocess
import tarfile

archive_path = Path('/workspaces/kprog-raw/verified/omp-five-20261120/otel/service.tar.gz')
here = Path(__file__).resolve().parent
with tarfile.open(archive_path) as service:
    records = [json.loads(line) for line in service.extractfile('service/requests/requests.jsonl')]
    record = next(row for row in records if row['request_id'] == 7)
    capsule_name = 'service/requests/' + Path(record['artifact_archive']).name
    with tarfile.open(fileobj=io.BytesIO(service.extractfile(capsule_name).read())) as capsule:
        bounds = subprocess.run(['llvm-dis-18', '-o', '-', '-'],
            input=capsule.extractfile('request/generated/trusted_x86.bpf.bounds.bc').read(),
            capture_output=True, check=True).stdout.decode().splitlines()
        source = capsule.extractfile('request/generated/trusted_x86.bpf.c').read().decode().splitlines()
        descriptor = os.memfd_create('archived-otel-B')
        try:
            os.write(descriptor, capsule.extractfile('request/generated/trusted_x86.bpf.o').read())
            disassembly = subprocess.run(['llvm-objdump-18', '-dl', f'/proc/self/fd/{descriptor}'],
                pass_fds=(descriptor,), capture_output=True, text=True, check=True).stdout.splitlines()
        finally:
            os.close(descriptor)
        index = next(i for i, line in enumerate(disassembly) if line.strip().startswith('3137:'))
        residual = next(i for i, line in enumerate(bounds) if ' = sub i64 24,' in line)
        report = dict(archive=str(archive_path), capsule=capsule_name,
            request_id=7, source_prog_id=record['source_prog_id'], native_sha256=record['native_sha256'],
            execution_path=record['execution_path'],
            pointer_difference_anchors=sum('asm sideeffect "$0 -= $2"' in line for line in bounds),
            residual_constant_minus_24=sum(' = sub i64 24,' in line for line in bounds),
            residual_ir=bounds[residual-23:residual+4],
            rejected_B=disassembly[index-10:index+8],
            mapped_C=[f'{i+1}: {source[i]}' for i in range(1752, 1764)],
            verifier_tail=record['simulator_failure']['stderr'].splitlines()[-5:],
            decision='Do not extend the pass for constant-minus-difference from this evidence. The cited first residual is in block1402, guarded by tag==4 although its tag selects only0/6. The actual rejection maps to native0x9eb ALU SUB. Do not add a verifier-verdict switch; any justified repair belongs to the defect class on its original CFG path.',
            scope='Read-only source/IR/archived-object review using installed tools. No compiler change, build, stock retry, new acceptance or performance result.')
(here/'otel7-review.json').write_text(json.dumps(report, indent=2)+'\n')
print(json.dumps({key: report[key] for key in ['pointer_difference_anchors', 'residual_constant_minus_24', 'decision']}, indent=2))
