"""Retain native instruction evidence for an entire existing failure class.

This reads the previously published class worklist. It does not classify or
filter new programs, change programs, run them, or add acceptance criteria.
"""
import argparse
import hashlib
import io
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


def inspect(worklist, output, bpf=False):
    output.mkdir(parents=True)
    evidence = []
    for request in json.loads(worklist.read_text())['requests']:
        source = Path(request['archive'])
        case = output/f'body-{request["body_group"]}'
        case.mkdir()
        with tarfile.open(source) as outer:
            stream = io.BytesIO(outer.extractfile(request['member']).read()) if 'member' in request else None
            archive = tarfile.open(fileobj=stream) if stream is not None else outer
            artifacts = json.load(archive.extractfile('request/generated/artifacts.json'))
            names = ['generated/trusted_x86.proof.o', 'generated/trusted_x86.bpf.c',
                     'source-identities.json', 'kernel.metadata.json']
            # checked-sim-c may fail initial verification before load is run.
            members = set(archive.getnames())
            names.append('load.stderr' if 'request/load.stderr' in members else 'verify.stderr')
            if 'request/load.stderr' in members and 'request/verify.stderr' in members:
                names.append('verify.stderr')
            if bpf:
                names.append('generated/trusted_x86.bpf.o')
            for name in names:
                with (case/Path(name).name).open('xb') as destination:
                    destination.write(archive.extractfile('request/'+name).read())
            if archive is not outer:
                archive.close()
        command = ['llvm-objdump-18','-d','--no-show-raw-insn','-Mintel',
                   '--disassemble-symbols='+artifacts['symbol'],str(case/'trusted_x86.proof.o')]
        with (case/'native.disassembly').open('w') as stdout, (case/'objdump.stderr').open('w') as stderr:
            result = subprocess.run(command,stdout=stdout,stderr=stderr)
        (case/'command.json').write_text(json.dumps(dict(command=command,returncode=result.returncode),indent=2)+'\n')
        result.check_returncode()
        if bpf:
            command = ['llvm-objdump-18','-d','-l','--no-show-raw-insn',str(case/'trusted_x86.bpf.o')]
            with (case/'bpf.disassembly').open('w') as stdout, (case/'bpf-objdump.stderr').open('w') as stderr:
                result = subprocess.run(command,stdout=stdout,stderr=stderr)
            (case/'bpf-command.json').write_text(json.dumps(dict(command=command,returncode=result.returncode),indent=2)+'\n')
            result.check_returncode()
        evidence.append(dict(application=request['application'],body_group=request['body_group'],
            retained_archive=str(source),retained_archive_sha256=digest(source),
            retained_member=request.get('member'),
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
    parser.add_argument('--bpf',action='store_true',help='Also retain compiled B and its source-line disassembly')
    args=parser.parse_args()
    inspect(args.worklist,args.output,args.bpf)
