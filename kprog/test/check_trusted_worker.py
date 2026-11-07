"""Compile fresh proofs from actual BCC native bytes, without proof siblings."""
import hashlib
import json
from pathlib import Path
import sys
import struct
import subprocess
import tempfile
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'kprog'))
from trusted_service import adapter
from trusted_generation import validate_native

worker=adapter(1)
native=ROOT/'vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o'
blob=native.read_bytes()
metadata=dict(version=1,prog_type=2,section='kprobe/trusted',maps=[dict(
    name='stats',map_type=2,key_size=4,value_size=40,max_entries=1,map_flags=1024,value_offset=0)])
rows=[]
with tempfile.TemporaryDirectory(prefix='trusted-worker-',dir=ROOT/'kprog/libnativeloader/build') as directory:
    for entry,offset,expected_addend in [('kprobe_vfs_read',0,0),('kprobe_vfs_write',0,0),('kprobe_vfs_read',8,0)]:
        metadata['maps'][0]['value_offset']=offset
        result=worker.specialize(blob,entry,metadata,Path(directory)/(entry+str(offset)),
            ROOT/'kprog/x86/native_lab/native_link/target/release/native-link')
        with Path(result['simulator_object']).open('rb') as stream:
            elf=ELFFile(stream)
            assert elf['e_machine']=='EM_BPF'
            symbols=[s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name==result['simulator_program']]
            assert len(symbols)==1 and symbols[0]['st_size']
            section=elf.get_section(symbols[0]['st_shndx'])
            assert section.name==metadata['section']
            relocs=elf.get_section_by_name('.rel'+section.name)
            targets=elf.get_section(relocs['sh_link'])
            matched=[]
            for relocation in relocs.iter_relocations():
                symbol=targets.get_symbol(relocation['r_info_sym'])
                if symbol.name=='stats':
                    assert symbol['st_shndx']=='SHN_UNDEF'
                    site=relocation['r_offset']
                    code=section.data()
                    assert code[site]==0x18 and relocation['r_info_type']==1
                    low=struct.unpack_from('<I',code,site+4)[0]
                    high=struct.unpack_from('<I',code,site+12)[0]
                    matched.append(low|(high<<32))
            assert matched and set(matched)=={expected_addend},(entry,offset,matched)
            rows.append(dict(entry=entry,value_offset=offset,external_addends=matched,proof_instructions=symbols[0]['st_size']//8,
                native_sha256=result['native_sha256'],simulator_sha256=hashlib.sha256(Path(result['simulator_object']).read_bytes()).hexdigest()))
# Actual ELF relocation rename control: code bytes are unchanged, while the
# native data symbol needs a C asm alias rather than a dotted C expression.
with tempfile.TemporaryDirectory(prefix='trusted-symbol-',dir=ROOT/'kprog/libnativeloader/build') as directory:
    directory=Path(directory);renamed=directory/'renamed.o'
    subprocess.run(['llvm-objcopy','--redefine-sym','stats=sys_exit.zero',native,renamed],check=True)
    metadata['maps'][0].update(name='sys_exit.zero',value_offset=0)
    result=worker.specialize(renamed.read_bytes(),'kprobe_vfs_read',metadata,directory/'generated',
        ROOT/'kprog/x86/native_lab/native_link/target/release/native-link')
    with Path(result['simulator_object']).open('rb') as stream:
        elf=ELFFile(stream)
        matches=[s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name=='sys_exit.zero']
        assert len(matches)==1 and matches[0]['st_shndx']=='SHN_UNDEF'
    rows.append(dict(entry='kprobe_vfs_read',native_symbol='sys_exit.zero',kind='renamed actual ELF relocation control',compiled=True))
for machine,entry in [('EM_AARCH64','kprobe_vfs_read'),('EM_X86_64','no_such_entry')]:
    try:validate_native(blob,entry,machine)
    except ValueError:pass
    else:raise AssertionError('wrong ISA or missing entry accepted')
print(json.dumps(dict(ok=True,kind='actual BCC generation/compile only; not kernel acceptance',programs=rows),indent=2))
