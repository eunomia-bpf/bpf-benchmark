"""Map actual failed B instructions using their completed native-success capsules."""
import io
import json
from pathlib import Path
import re
import subprocess
import sys
import tarfile
from elftools.elf.elffile import ELFFile

service_archive, out = map(Path, sys.argv[1:])
out.mkdir(parents=True, exist_ok=True)
rows, commands = [], []
targets = {f'service/requests/{number}.success.tar.gz': (number, pc)
           for number, pc in [(27, 959), (28, 1), (30, 27607)]}

def inspect(capsule_bytes, archive, request_id, pc):
    directory = out/str(request_id)
    directory.mkdir()
    with tarfile.open(fileobj=io.BytesIO(capsule_bytes)) as capsule:
        entry = capsule.extractfile('request/kernel.entry').read().decode().strip()
        artifacts = json.load(capsule.extractfile('request/generated/artifacts.json'))
        symbol = artifacts['simulator_program']
        binary = capsule.extractfile('request/generated/trusted_x86.bpf.o').read()
        elf = ELFFile(io.BytesIO(binary))
        function, = elf.get_section_by_name('.symtab').get_symbol_by_name(symbol)
        section = elf.get_section(function['st_shndx'])
        command = ['llvm-objdump-18', '-dl', '-']
        result = subprocess.run(command, input=binary, capture_output=True)
        commands.append(dict(command=command, archive=str(archive), returncode=result.returncode,
                             stderr=result.stderr.decode()))
        (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        text = result.stdout.decode()
        (directory/'disassembly.txt').write_text(text)
        lines, current, windows = text.splitlines(), None, []
        target = function['st_value']//8+pc
        for index, line in enumerate(lines):
            match = re.match(r'Disassembly of section (.*):', line)
            if match:
                current = match[1]
            instruction = re.match(r'\s*(\d+):', line)
            if current == section.name and instruction and int(instruction[1]) == target:
                windows.append(lines[max(0, index-16):index+9])
        (directory/'pc-window.txt').write_text('\n\n'.join('\n'.join(window) for window in windows)+'\n')
        for member, filename in [('request/generated/trusted_x86.bpf.bounds-input.bc', 'frontend.ll'),
                                 ('request/generated/trusted_x86.bpf.bounds.bc', 'bounds.ll')]:
            command = ['llvm-dis-18', '-', '-o', str(directory/filename)]
            result = subprocess.run(command, input=capsule.extractfile(member).read(), capture_output=True)
            commands.append(dict(command=command, archive=str(archive), returncode=result.returncode,
                                 stderr=result.stderr.decode()))
            (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
            result.check_returncode()
        rows.append(dict(request=request_id, entry=entry, verifier_pc=pc, section=section.name,
            section_bytes=section['sh_size'], symbol_byte_offset=function['st_value'],
            disassembly_index=target, mapped=bool(windows), windows=windows))
        print(json.dumps({key: value for key, value in rows[-1].items() if key != 'windows'}), flush=True)

with tarfile.open(service_archive, mode='r|gz') as service:
    for member in service:
        if member.name in targets:
            request_id, pc = targets[member.name]
            inspect(service.extractfile(member).read(),
                    str(service_archive)+'::'+member.name, request_id, pc)
            if len(rows) == len(targets):
                break
(out/'result.json').write_text(json.dumps(dict(rows=rows,
    scope='Retained-object/debug mapping only; no compilation, stock reload, app census or timing.'), indent=2)+'\n')
assert len(rows) == len(targets), 'Requested completed capsules are missing from the service archive'
assert all(row['mapped'] for row in rows), 'Verifier PC not mapped in its primary B section; inspect subprogram layout'
