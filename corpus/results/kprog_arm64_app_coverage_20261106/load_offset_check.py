"""Catch modified-context addressing and width/offset loss in BPF loads."""
import json
from pathlib import Path
import struct
import subprocess
import sys
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
out = Path(sys.argv[1]).resolve()
out.mkdir(exist_ok=True)
widths = {8: 1, 16: 2, 32: 4, 64: 8}
offsets = [-32769, -32768, -16, 0, 16, 32767, 32768]
functions = []
source = ['#include <linux/types.h>']
for bits, size in widths.items():
    source.append(f'#define ARM64_WIDTH_{bits} {size}U')
source.append(f'#include "{ROOT}/kprog/formal/generated/arm64_load_bytes.h"')
for bits in widths:
    for index, offset in enumerate(offsets):
        name = f'load_{bits}_{index}'
        functions.append((name, bits, offset))
        source.append(f'__u64 {name}(void *base) {{ return KPROG_ARM64_LOAD_BYTES_OFFSET(base, {offset}, ARM64_WIDTH_{bits}); }}')
    name = f'load_{bits}_dynamic'
    functions.append((name, bits, None))
    source.append(f'__u64 {name}(void *base, long offset) {{ return KPROG_ARM64_LOAD_BYTES_OFFSET(base, offset, ARM64_WIDTH_{bits}); }}')
source += ['#ifndef __BPF__', '#include <stdio.h>', 'int main(void) {',
           'static unsigned char bytes[131088];',
           'for (unsigned i=0; i<sizeof(bytes); ++i) bytes[i]=(i*37+19) & 255;',
           'unsigned char *base=bytes+65536; unsigned cases=0;']
for name, bits, offset in functions:
    if offset is None:
        continue
    expected = ' | '.join(f'((__u64)base[{offset + i}] << {8*i})' for i in range(widths[bits]))
    source.append(f'if ({name}(base) != ({expected})) return 1;\n++cases;')
for bits in widths:
    source += ['for (long off=-32769; off<=32769; off+=257) {', '__u64 expected=0;',
               f'for (unsigned j=0; j<{widths[bits]}; ++j) expected |= (__u64)base[off+j] << (8*j);',
               f'if (load_{bits}_dynamic(base,off) != expected) return 2;\n++cases;', '}']
source += ['printf("load offset values: %u cases\\n",cases); return 0; }', '#endif']
(out/'loads.c').write_text('\n'.join(source)+'\n')
commands = []
def run(command, log):
    result = subprocess.run(command, text=True, capture_output=True)
    commands.append(dict(command=command, returncode=result.returncode))
    (out/log).write_text(result.stdout+result.stderr)
    result.check_returncode()
run(['cc','-O2','-Wall','-Wextra','-Werror',str(out/'loads.c'),'-o',str(out/'loads-host')], 'host-build.log')
run([str(out/'loads-host')], 'host-run.log')
run(['clang','-O2','-target','bpf','-mcpu=v4','-I/usr/include/x86_64-linux-gnu','-c',str(out/'loads.c'),'-o',str(out/'loads.bpf.o')], 'bpf-build.log')
run(['llvm-objdump-18','-d',str(out/'loads.bpf.o')], 'loads.asm')
rows = []
with (out/'loads.bpf.o').open('rb') as stream:
    elf=ELFFile(stream);symtab=elf.get_section_by_name('.symtab')
    for name,bits,offset in functions:
        symbol=symtab.get_symbol_by_name(name)[0];section=elf.get_section(symbol['st_shndx'])
        code=section.data()[symbol['st_value']:symbol['st_value']+symbol['st_size']]
        insns=[struct.unpack('<BBhi',code[i:i+8]) for i in range(0,len(code),8)]
        loads=[i for i in insns if i[0] in [0x71,0x69,0x61,0x79]]
        assert len(loads)==1,(name,insns)
        load=loads[0];assert load[0]=={8:0x71,16:0x69,32:0x61,64:0x79}[bits],(name,loads)
        direct=offset is not None and -32768<=offset<=32767
        assert load[2]==(offset if direct else 0),(name,load)
        if direct:
            assert len(insns)==2 and load[1]>>4==1,(name,insns)
        rows.append(dict(function=name,width=bits,offset=offset,direct=direct,instructions=insns))
(out/'encoding.json').write_text(json.dumps(rows,indent=2)+'\n')
(out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
print((out/'host-run.log').read_text().strip())
print(f'{len(rows)} BPF width/offset encodings checked; all signed16 offsets use the unmodified base')
