#!/usr/bin/env python3
"""Inspect an existing P's ELF and embedded IR; never compile or execute it."""
import datetime
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

source = Path(sys.argv[1]).resolve()
destination = Path(sys.argv[2])
metadata = source.stat()
sections = {}
for line in subprocess.check_output(['readelf', '-SW', str(source)], text=True).splitlines():
    match = re.match(r'^\s*\[\s*(\d+)\]\s+(\S+)\s+PROGBITS\s+\S+\s+\S+\s+(\S+)\s+\S+\s+(\S+)', line)
    if match and 'X' in match[4] and int(match[3], 16):
        sections[int(match[1])] = match[2]
functions = []
for line in subprocess.check_output(['readelf', '-sW', str(source)], text=True).splitlines():
    fields = line.split()
    if len(fields) >= 8 and fields[3] == 'FUNC' and fields[6].isdigit() and int(fields[6]) in sections:
        functions.append(dict(name=fields[7], section=sections[int(fields[6])],
                              bytes=int(fields[2]), binding=fields[4]))
# Read the ELF64 section directly into memory; no copied object or IR file.
elf = source.read_bytes()
section_offset = struct.unpack_from('<Q', elf, 40)[0]
entry_size, section_count, names_index = struct.unpack_from('<HHH', elf, 58)
table = [struct.unpack_from('<IIQQQQIIQQ', elf, section_offset + index * entry_size)
         for index in range(section_count)]
names_entry = table[names_index]
names = elf[names_entry[4]:names_entry[4] + names_entry[5]]
bitcode = next(elf[section[4]:section[4] + section[5]] for section in table
               if names[section[0]:].split(b'\0', 1)[0] == b'.llvmbc')
disassemble = subprocess.run(['llvm-dis-18', '-o', '-'], input=bitcode,
                             stdout=subprocess.PIPE)
definitions = 0
roots = []
attributes = {}
for line in disassemble.stdout.decode().splitlines():
    if line.startswith('define '):
        definitions += 1
        if ' section ' in line:
            roots.append(line.strip())
    if line.startswith('attributes #'):
        number = re.match(r'attributes #(\d+)', line)[1]
        attributes[number] = dict(
            no_red_zone=' noredzone ' in line,
            optimize_for_size=' optsize ' in line,
            minimum_size=' minsize ' in line,
            target_cpu=re.findall(r'"target-cpu"="([^"]*)"', line),
            target_features=re.findall(r'"target-features"="([^"]*)"', line))
subprocess_status = dict(llvm_dis=disassemble.returncode)
result = dict(captured_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
              source=str(source), source_bytes=metadata.st_size, source_mtime_ns=metadata.st_mtime_ns,
              subprocess_status=subprocess_status, executable_functions=functions,
              executable_bytes=sum(function['bytes'] for function in functions),
              ir_definitions=definitions, sectioned_ir_definitions=roots, ir_attribute_groups=attributes,
              scope='Existing stage P inventory only; no new compiled object, installed-size comparison or compiler timing.')
destination.write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(elf_functions=len(functions), executable_bytes=result['executable_bytes'],
                      ir_definitions=definitions, sectioned_ir_roots=len(roots), **subprocess_status)))
if any(subprocess_status.values()):
    sys.exit(1)
