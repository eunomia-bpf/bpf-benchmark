"""Check emitted exclusive-site metadata against real pre/post-link ARM objects."""
import json
from pathlib import Path
import struct
import subprocess
import sys
from elftools.elf.elffile import ELFFile
ROOT=Path(__file__).resolve().parents[3]
phase=Path(sys.argv[1]).resolve();phase.mkdir()
linker=ROOT/'kprog/arm64/build/app-native-link/release/native-link'
commands=[];checks=[]
plan=phase/'plan.json'
plan.write_text(json.dumps(dict(version=1,helpers=[dict(name='bpf_get_current_uid_gid',addr=0xffff800012340000)]))+'\n')
def run(args,expected=0):
    args=list(map(str,args));result=subprocess.run(args,capture_output=True,text=True,timeout=120)
    commands.append(dict(command=args,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
    (phase/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if result.returncode!=expected:raise RuntimeError(result.stderr)
    return result
for width in [4,8]:
 for release in [False,True]:
    stem=f'w{width}_{int(release)}';source=phase/(stem+'.S');native=source.with_suffix('.native.o');proof=phase/(stem+'.proof.o')
    reg='w2' if width==4 else 'x2';store='stlxr' if release else 'stxr'
    source.write_text('.text\n.global entry\n.type entry,%function\nentry:\nstp x19,x30,[sp,#-16]!\nmov x19,x0\nbl bpf_get_current_uid_gid\nldxr '+reg+',[x19]\n'+store+' w3,'+reg+',[x19]\nldp x19,x30,[sp],#16\nret\n.size entry,.-entry\n')
    run(['aarch64-linux-gnu-gcc','-c',source,'-o',native])
    run([linker,'--input',native,'--symbol','entry','--mode','proof','--preserve-entry-abi','--output',proof])
    base=[linker,'--input',proof,'--symbol','entry','--mode','kernel','--output',phase/(stem+'.bin'),
        '--output-relocs',phase/(stem+'.relocs.bin'),'--output-environment-layout',phase/(stem+'.json'),
        '--link-plan',plan]
    run(base)
    data=json.loads((phase/(stem+'.json')).read_text());blob=(phase/(stem+'.bin')).read_bytes()
    with proof.open('rb') as stream:text=ELFFile(stream).get_section_by_name('.text').data()
    sites=data['sites']
    if data['version']!=1 or len(sites)!=1:raise RuntimeError('missing/duplicate exclusive site')
    site=sites[0];source_word=struct.unpack_from('<I',text,site['source_pc'])[0];native_word=struct.unpack_from('<I',blob,site['offset'])[0]
    if source_word!=native_word or site['width']!=width or site['release']!=release or site['offset']<=site['source_pc']:
        raise RuntimeError('exclusive site does not follow helper expansion exactly')
    checks.append(dict(case=stem,**site,source_word=source_word,native_word=native_word))
    bad=run([linker,'--input',native,'--symbol','entry','--mode','proof','--output',phase/(stem+'.bad.proof.o'),
             '--output-environment-layout',phase/(stem+'.bad.json')],1)
    if 'proof mode writes a single' not in bad.stderr:raise RuntimeError('wrong proof-mode rejection')
(phase/'checks.json').write_text(json.dumps(checks,indent=2)+'\n')
source=phase/'x86.S';source.write_text('.text\n.global entry\n.type entry,@function\nentry:\nret\n.size entry,.-entry\n')
run(['cc','-c',source,'-o',phase/'x86.native.o'])
run([linker,'--input',phase/'x86.native.o','--symbol','entry','--mode','proof','--output',phase/'x86.proof.o'])
bad=run([linker,'--input',phase/'x86.proof.o','--symbol','entry','--mode','kernel','--output',phase/'x86.bad.bin',
         '--output-environment-layout',phase/'x86.bad.json'],1)
if 'requires ARM input' not in bad.stderr or (phase/'x86.bad.bin').exists() or (phase/'x86.bad.json').exists():
    raise RuntimeError('foreign architecture produced a partial environment layout')
print('four actual STXR/STLXR layouts retain exact source/native opcodes after helper expansion; proof-mode sideband rejected')
