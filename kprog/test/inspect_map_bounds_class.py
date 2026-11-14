"""Retain native instruction evidence for an entire existing failure class.

This reads the previously published class worklist. It does not classify or
filter new programs, change programs, run them, or add acceptance criteria.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import tarfile


def digest(path):
    value = hashlib.sha256()
    with path.open('rb') as source:
        while block := source.read(1024 * 1024):
            value.update(block)
    return value.hexdigest()


def inspect(worklist, output):
    output.mkdir(parents=True)
    evidence = []
    for request in json.loads(worklist.read_text())['requests']:
        source = Path(request['archive'])
        case = output/f'body-{request["body_group"]}'
        case.mkdir()
        with tarfile.open(source) as archive:
            artifacts = json.load(archive.extractfile('request/generated/artifacts.json'))
            for name in ('generated/trusted_x86.proof.o', 'generated/trusted_x86.bpf.c',
                         'source-identities.json', 'load.stderr', 'kernel.metadata.json'):
                with (case/Path(name).name).open('xb') as destination:
                    destination.write(archive.extractfile('request/'+name).read())
        command = ['llvm-objdump-18','-d','--no-show-raw-insn','-Mintel',
                   '--disassemble-symbols='+artifacts['symbol'],str(case/'trusted_x86.proof.o')]
        with (case/'native.disassembly').open('w') as stdout, (case/'objdump.stderr').open('w') as stderr:
            result = subprocess.run(command,stdout=stdout,stderr=stderr)
        (case/'command.json').write_text(json.dumps(dict(command=command,returncode=result.returncode),indent=2)+'\n')
        result.check_returncode()
        evidence.append(dict(application=request['application'],body_group=request['body_group'],
            retained_archive=str(source),retained_archive_sha256=digest(source),
            native_symbol=artifacts['symbol'],submitted_native_sha256=artifacts['native_sha256'],
            files={path.name:dict(bytes=path.stat().st_size,sha256=digest(path)) for path in case.iterdir()}))
    receipt = dict(worklist=str(worklist),scope='Read-only native P evidence for every request already in the full failure class',
                   no_new_program_runs=True,no_model_change=True,requests=evidence,raw_removed=False)
    (output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(requests=len(evidence),output=str(output),no_new_program_runs=True)))


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--worklist',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    inspect(args.worklist,args.output)
