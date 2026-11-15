"""Measure every defined function in an actual native ELF through the service proof route.

Offline artifact measurement: no verifier submission, app loading or timing.
The one proof product is replaced for each function; only logs and identities
are retained. Every failure is recorded and the overall command fails.
"""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import time
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog/fidelity'))
import scale


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main(a):
    a.output.mkdir(parents=True, exist_ok=True)
    a.build.mkdir(parents=True, exist_ok=True)
    with a.native.open('rb') as stream:
        elf = ELFFile(stream)
        functions = [dict(symbol=s.name, section=elf.get_section(s['st_shndx']).name,
                          address=s['st_value'], bytes=s['st_size'], binding=s['st_info']['bind'])
                     for s in elf.get_section_by_name('.symtab').iter_symbols()
                     if s['st_info']['type'] == 'STT_FUNC' and isinstance(s['st_shndx'], int)]
    if not functions:
        raise ValueError('Native ELF has no defined functions')
    functions.sort(key=lambda row: (row['section'], row['address'], row['symbol']))
    identity = dict(native=str(a.native), native_sha256=digest(a.native),
                    linker=str(a.linker), linker_sha256=digest(a.linker),
                    source_head=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
                    scope='Actual native ELF functions, service --preserve-entry-abi proof route only; no source fidelity, B or kernel acceptance')
    (a.output / 'inputs.json').write_text(json.dumps(identity, indent=2) + '\n')
    (a.output / 'functions.json').write_text(json.dumps(functions, indent=2) + '\n')
    rows = []
    started = time.monotonic()
    proof = a.build / 'proof.o'
    for number, function in enumerate(functions):
        command = [a.linker, '--mode', 'proof', '--input', a.native,
                   '--symbol', function['symbol'], '--preserve-entry-abi', '--output', proof]
        log = a.output / f'command-{number:03d}.log'
        status = scale.run(command, log)
        resource = json.loads(log.with_suffix(log.suffix + '.resources.json').read_text())
        row = dict(function, command=resource['command'], returncode=status,
                   resource=str(log.with_suffix(log.suffix + '.resources.json')),
                   wall_seconds=resource['wall_seconds'])
        if status == 0:
            row.update(proof_sha256=digest(proof), proof_bytes=proof.stat().st_size)
            with proof.open('rb') as stream:
                elf = ELFFile(stream)
                row['sections'] = {s.name: s['sh_size'] for s in elf.iter_sections() if s['sh_flags'] & 2}
                row['relocations'] = sum(s.num_relocations() for s in elf.iter_sections()
                                         if s['sh_type'] in ['SHT_RELA', 'SHT_REL'])
        rows.append(row)
        (a.output / 'results.json').write_text(json.dumps(rows, indent=2) + '\n')
        print(function['symbol'], status, flush=True)
    summary = dict(identity, functions=len(rows), proof_success=sum(r['returncode'] == 0 for r in rows),
                   failures=sum(r['returncode'] != 0 for r in rows),
                   native_sha256_after=digest(a.native), wall_seconds=time.monotonic() - started)
    (a.output / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(summary), flush=True)
    if summary['failures']:
        raise SystemExit(1)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['native', 'linker', 'build', 'output']:
        parser.add_argument('--' + name, type=Path, required=True)
    main(parser.parse_args())
