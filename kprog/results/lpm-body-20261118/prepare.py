#!/usr/bin/env python3
"""Extract retained compiled trie bodies for a host-only cost diagnostic."""
import argparse
import json
from pathlib import Path
import re
import struct
import subprocess
from elftools.elf.elffile import ELFFile

p = argparse.ArgumentParser(description=__doc__)
p.add_argument('--output', type=Path, required=True)
p.add_argument('--replay', type=Path, default=Path('kprog/results/named-lpm-20261118/replay.json'))
a = p.parse_args()
a.output.mkdir(parents=True, exist_ok=True)
kernel = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
replay = a.replay
request, = [r for r in json.loads(replay.read_text())['requests']
            if r['app'] == 'otelcol-ebpf-profiler/profiling' and r['symbol'] == 'perf_unwind_native']
plan = json.loads(Path(request['plan']).read_text())
with kernel.open('rb') as f:
    elf = ELFFile(f)
    sym, = elf.get_section_by_name('.symtab').get_symbol_by_name('trie_lookup_elem')
    section = elf.get_section(sym['st_shndx'])
    start = sym['st_value'] - section['sh_addr']
    original = section.data()[start:start + sym['st_size']]
    address = sym['st_value']
disassembly = subprocess.check_output(['objdump', '-d', '--disassemble=trie_lookup_elem', str(kernel)], text=True)
(a.output/'kernel.disassembly').write_text(disassembly)
code = bytearray(original)
patches = []
for line in disassembly.splitlines():
    match = re.match(r'\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*(\S+)\s*(.*)', line)
    if not match:
        continue
    ip, raw, op, args = match.groups()
    ip = int(ip, 16)
    assert '(%rip)' not in args and '%gs:' not in args and '%fs:' not in args, line
    assert op not in ['call', 'callq', 'syscall', 'sysret', 'cli', 'sti', 'stac', 'clac'], line
    if op.startswith('j'):
        target = int(args.split()[0], 16)
        if not address <= target < address + len(code):
            assert op == 'jmp' and '<__pi___x86_return_thunk>' in args, line
            offset = ip - address
            assert code[offset] == 0xe9 and len(bytes.fromhex(raw)) == 5, line
            patches.append(dict(offset=offset, original=code[offset:offset+5].hex(),
                                replacement='c390909090', reason='ordinary host RET replaces kernel return thunk'))
            code[offset:offset+5] = bytes.fromhex('c390909090')
assert len(patches) == 1, patches
(a.output/'kernel-original.bin').write_bytes(original)
(a.output/'kernel-host.bin').write_bytes(code)

folder = Path(request['output'])
region, = [r for r in request['lto_ranges'] if r['piece'] == 'runtime_array_lpm']
original = (folder/'image.blob').read_bytes()[region['start']:region['end']]
native = bytearray(original)
relocs = [r for r in struct.iter_unpack('<IIQ', (folder/'image.relocs').read_bytes())
          if region['start'] <= r[0] < region['end']]
helper, = [h['addr'] for h in plan['helpers'] if h['name'] == 'bpf_map_lookup_elem']
assert len(relocs) == 1, relocs
native_patches = []
for offset, kind, target in relocs:
    offset -= region['start']
    assert kind == 1 and target == helper and native[offset] == 0xe8, relocs
    before = native[offset:offset+5].hex()
    native[offset+1:offset+5] = struct.pack('<i', len(original) - offset - 5)
    native_patches.append(dict(offset=offset, original=before, replacement=native[offset:offset+5].hex(),
                               reason='generic fallback targets appended UD2; fixture uses the captured LPM shape'))
native.extend(b'\x0f\x0b')
(a.output/'native-original.bin').write_bytes(original)
(a.output/'native-host.bin').write_bytes(native)
layout = plan['kernel_layout']['lpm']
(a.output/'layout.h').write_text(''.join(f'#define L_{name} {value}\n' for name, value in layout.items()))
report = dict(kernel=str(kernel), replay=str(replay), request=request, layout=layout,
              kernel_bytes=len(code), native_range_bytes=len(original), kernel_patches=patches,
              native_patches=native_patches, native_host_trap_bytes=2,
              scope='Compiled trie body host diagnostic; ordinary returns, stable host nodes, captured offsets. '
                    'Kernel mitigations, RCU concurrency, app frequency and installed app bytes require the image batch.')
(a.output/'extraction.json').write_text(json.dumps(report, indent=2)+'\n')
print(json.dumps({k: report[k] for k in ['kernel_bytes', 'native_range_bytes', 'kernel_patches', 'native_patches']}))
