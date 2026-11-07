"""Embed exact byte-loop memset into the paired native ELF, not kernel externs."""
from pathlib import Path
import json
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
HERE=Path(__file__).resolve().parent
if len(sys.argv) not in (1,3): raise ValueError('expected SOURCE OUTPUT, or no arguments for the recorded x86 run')
source=Path(sys.argv[1]).resolve() if len(sys.argv)==3 else HERE/'bcc-real-14'
out=Path(sys.argv[2]).resolve() if len(sys.argv)==3 else HERE/'bcc-memory-input'
out.mkdir()
for name in ('native','original','upstream'):
 if (source/name).is_dir():shutil.copytree(source/name,out/name)
natives=sorted((out/'native').glob('*.native.o'))
if not natives: raise ValueError('no native ELF objects')
machines=set()
for native in natives:
 with native.open('rb') as stream:machines.add(ELFFile(stream)['e_machine'])
if len(machines)!=1: raise ValueError('native ELF architectures differ')
arm64=machines=={'EM_AARCH64'}
if not arm64 and machines!={'EM_X86_64'}: raise ValueError('unsupported native ELF architecture')
cc,objcopy,ld=('aarch64-linux-gnu-gcc','aarch64-linux-gnu-objcopy','aarch64-linux-gnu-ld') if arm64 else ('cc','objcopy','ld')
assembly=out/'memset.S'
assembly.write_text('''.text
.globl __kprog_memset
.type __kprog_memset,%function
__kprog_memset:
 mov x3,x0
 cbz x2,2f
1:
 strb w1,[x3],#1
 subs x2,x2,#1
 b.ne 1b
2:
 ret
.size __kprog_memset,.-__kprog_memset
.section .note.GNU-stack,"",%progbits
''' if arm64 else '''.text
.globl __kprog_memset
.type __kprog_memset,@function
__kprog_memset:
 mov %rdi,%rax
 test %rdx,%rdx
 je 2f
1:
 mov %sil,(%rdi)
 inc %rdi
 dec %rdx
 jne 1b
2:
 ret
.size __kprog_memset,.-__kprog_memset
.section .note.GNU-stack,"",@progbits
''')
commands=[]
def run(cmd):
 r=subprocess.run(cmd,text=True,capture_output=True)
 commands.append(dict(command=list(map(str,cmd)),returncode=r.returncode,stdout=r.stdout,stderr=r.stderr))
 (out/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
 if r.returncode:raise RuntimeError(r.stderr)
 return r.stdout
run([cc,'-c',str(assembly),'-o',str(out/'memset.o')])
for native in sorted((out/'native').glob('*.native.o')):
 undefined=run(['nm','-u',str(native)]).splitlines()
 if not any(line.split()[-1]=='memset' for line in undefined):continue
 renamed=native.with_suffix('.renamed.o')
 run([objcopy,'--redefine-sym','memset=__kprog_memset',str(native),str(renamed)])
 run([ld,'-r',str(renamed),str(out/'memset.o'),'-o',str(native)])
 renamed.unlink()
 print('embedded exact memset in',native.name)
