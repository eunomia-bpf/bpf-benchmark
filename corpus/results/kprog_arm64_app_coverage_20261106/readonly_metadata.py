"""Catch collapsed identical constants, wrong extents and folded interior addends."""
import json
from pathlib import Path
import subprocess
import sys
from collections import OrderedDict
from elftools.elf.elffile import ELFFile

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen

phase=Path(sys.argv[1]).resolve()
phase.mkdir(exist_ok=True)
assembly=phase/'identical.S'
assembly.write_text('.text\n.global entry\n.type entry,%function\nentry:\nmov w0,#2\nret\n.size entry,.-entry\n')
subprocess.run(['aarch64-linux-gnu-gcc','-c',assembly,'-o',phase/'identical.o'],check=True)
dump=subprocess.check_output(['aarch64-linux-gnu-objdump','-dr',phase/'identical.o'],text=True)
functions=OrderedDict(entry=gen.parse_flat_instructions(dump))
# A hex-looking ASCII display column must never become readonly payload bytes.
hex_payloads = {"hex_ascii": b"deadbeef00000000" * 2, "short_ascii": b"abcdef"}
hex_assembly = phase / 'hex-ascii.S'
rows = ['.section .native_link_rodata,"a"']
for name, value in hex_payloads.items():
    rows.extend(['.balign 16', '.global ' + name, '.type ' + name + ',%object',
                 name + ':', '.byte ' + ','.join(str(byte) for byte in value),
                 '.size ' + name + ',.-' + name])
hex_assembly.write_text(chr(10).join(rows) + chr(10))
hex_object = phase / 'hex-ascii.o'
subprocess.run(['aarch64-linux-gnu-gcc', '-c', hex_assembly, '-o', hex_object], check=True)
with hex_object.open('rb') as stream:
    expected = ELFFile(stream).get_section_by_name('.native_link_rodata').data()
if gen.rodata_bytes(hex_object) != expected or gen.load_rodata_blobs(hex_object) != hex_payloads:
    raise RuntimeError('hexadecimal ASCII display text corrupted native readonly bytes')
if gen.load_rodata_blobs(phase / 'identical.o'):
    raise RuntimeError('object without readonly data gained a private extent')

objects={'first':bytes(120),'section:SectionIndex(5):.rodata':bytes(120)}
source=phase/'identical.bpf.c'
rendered=gen.render_program('identical','entry',functions,'xdp',rodata16=objects).replace(
    '#include "../arm64_sim_local_bpf.h"',f'#include "{ROOT}/kprog/arm64/arm64_sim_local_bpf.h"')
source.write_text('\n'.join(line.rstrip() for line in rendered.splitlines())+'\n')
target=source.with_suffix('.o')
command=['clang','-g','-O2','-target','bpf','-D__TARGET_ARCH_arm64',
         '-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),
         '-I/usr/include/x86_64-linux-gnu','-c',str(source),'-o',str(target)]
subprocess.run(command,check=True)
checks=[]
for path in [target]+sorted((phase.parent/'bcc-readonly-metadata/objects').glob('*.bpf.o')):
    with path.open('rb') as stream:
        elf=ELFFile(stream)
        metadata=elf.get_section_by_name('.native_lab.rodata')
        private=[s for s in elf.iter_sections() if s.name.startswith('.rodata.native.')]
        if metadata is None:
            if private:raise RuntimeError(f'{path}: private maps lack exact identity metadata')
            checks.append(dict(object=path.name,objects=0));continue
        value=json.loads(metadata.data().removesuffix(b'\0'))
        if value['version']!=1:raise RuntimeError('wrong metadata version')
        seen=set();symbols=list(elf.get_section_by_name('.symtab').iter_symbols())
        for row in value['objects']:
            key=row['native_symbol']
            if key in seen:raise RuntimeError('duplicate native object identity')
            seen.add(key)
            section=elf.get_section_by_name(row['proof_section'])
            if section is None or section.data_size!=row['size']:raise RuntimeError('wrong whole-object extent')
            variables=[s for s in symbols if s.name==row['proof_symbol']]
            if len(variables)!=1:raise RuntimeError('missing or ambiguous proof symbol')
            var=variables[0]
            if var['st_value']!=0 or var['st_size']!=row['size'] or elf.get_section(var['st_shndx']).name!=section.name:
                raise RuntimeError('proof variable does not cover its entire private map')
        if {s.name for s in private}!={r['proof_section'] for r in value['objects']}:
            raise RuntimeError('private section/metadata mismatch')
        if path==target:
            if seen!=set(objects) or len(private)!=2 or private[0].data()!=private[1].data():
                raise RuntimeError('identical bytes collapsed distinct native identities')
        checks.append(dict(object=path.name,objects=len(seen)))
(phase/'checks.json').write_text(json.dumps(checks,indent=2)+'\n')
print(f'{len(checks)} ELF objects checked; identical 120-byte constants retain distinct canonical identities and complete map extents')
