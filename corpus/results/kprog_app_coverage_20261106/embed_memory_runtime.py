"""Embed exact byte-loop memset into the paired native ELF, not kernel externs."""
from pathlib import Path
import json
import shutil
import subprocess
HERE=Path(__file__).resolve().parent
source=HERE/'bcc-real-14';out=HERE/'bcc-memory-input';out.mkdir()
for name in ('native','original','upstream'):shutil.copytree(source/name,out/name)
assembly=out/'memset.S'
assembly.write_text('''.text
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
run(['cc','-c',str(assembly),'-o',str(out/'memset.o')])
for native in sorted((out/'native').glob('*.native.o')):
 undefined=run(['nm','-u',str(native)]).splitlines()
 if not any(line.split()[-1]=='memset' for line in undefined):continue
 renamed=native.with_suffix('.renamed.o')
 run(['objcopy','--redefine-sym','memset=__kprog_memset',str(native),str(renamed)])
 run(['ld','-r',str(renamed),str(out/'memset.o'),'-o',str(native)])
 renamed.unlink()
 print('embedded exact memset in',native.name)
