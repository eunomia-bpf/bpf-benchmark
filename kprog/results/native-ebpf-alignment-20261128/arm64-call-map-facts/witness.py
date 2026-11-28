"""Execute original ELF and current native-link output in ARM user-mode QEMU."""
from pathlib import Path
import hashlib,json,os,resource,subprocess,sys,traceback
ROOT=Path('/workspaces/repository');OUT=Path(__file__).resolve().parent
phase=sys.argv[1];assert phase in ['before','before-canonical','after'];DEST=OUT/phase
DEST.mkdir(exist_ok=False);os.sched_setaffinity(0,{19})
def sha(p):return hashlib.file_digest(p.open('rb'),'sha256').hexdigest()
def now():return subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip()
def limits(cpu):
 def set_limits():
  resource.setrlimit(resource.RLIMIT_AS,(48*1024**3,48*1024**3));os.sched_setaffinity(0,{cpu})
 return set_limits
commands=[]
def run(label,args,cpu=16,expected=None):
 with (DEST/(label+'.log')).open('xb') as f:r=subprocess.run([str(x) for x in args],cwd=OUT,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,preexec_fn=limits(cpu))
 commands.append(dict(label=label,args=[str(x) for x in args],returncode=r.returncode,cpu=cpu,address_space_bytes=48*1024**3))
 if expected is not None:assert r.returncode==expected,(label,r.returncode)
 return r.returncode
r=dict(pid=os.getpid(),started_utc=now(),phase=phase,controller_status=None,commands=commands,cases=[])
try:
 linker=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link';source=ROOT/'kprog/x86/native_lab/native_link/src/main.rs';r.update(linker=dict(path=str(linker),bytes=linker.stat().st_size,sha256=sha(linker)),source=dict(path=str(source),sha256=sha(source),git_head=subprocess.check_output(['git','rev-parse','HEAD'],text=True).strip()))
 plan=dict(version=1,maps=[dict(name='frozen_word',addr=0x410000),dict(name='mutable_word',addr=0x410008)],const_values=[dict(name='frozen_word',hex='11000000')]);(DEST/'plan.json').write_text(json.dumps(plan,indent=2)+'\n')
 (DEST/'layout.ld').write_text('ENTRY(_start)\nSECTIONS { . = 0x400000; .text : { *(.text*) } . = 0x410000; .data : { *(.data*) } }\n')
 run('assemble-fixture',['aarch64-linux-gnu-as',OUT/'fixture.s','-o',DEST/'fixture.o'],expected=0)
 run('input-relocations',['aarch64-linux-gnu-objdump','-dr',DEST/'fixture.o'],cpu=19,expected=0)
 data='\n.data\n.balign 8\n.global frozen_word\nfrozen_word: .word 17, 0\n.global mutable_word\nmutable_word: .word 34, 0\n'
 for entry in ['entry_reloc','entry_local']:
  prefix=DEST/entry
  original=Path(str(prefix)+'.original.s');original.write_text(f'.text\n.global _start\n_start:\n bl {entry}\n mov x8, #93\n svc #0\n'+data)
  run(entry+'-assemble-original',['aarch64-linux-gnu-as',original,'-o',str(prefix)+'.original.o'],expected=0)
  run(entry+'-link-original',['aarch64-linux-gnu-ld','-T',DEST/'layout.ld','-o',str(prefix)+'.original.elf',str(prefix)+'.original.o',DEST/'fixture.o'],expected=0)
  original_exit=run(entry+'-execute-original',['qemu-aarch64-static',str(prefix)+'.original.elf'],cpu=19)
  run(entry+'-proof',[linker,'--input',DEST/'fixture.o','--symbol',entry,'--mode','proof','--output',str(prefix)+'.proof.o'],expected=0)
  run(entry+'-native-link',[linker,'--input',str(prefix)+'.proof.o','--symbol',entry,'--link-plan',DEST/'plan.json','--output',str(prefix)+'.blob.bin','--output-map-patches',str(prefix)+'.map-patches.tsv','--output-relocs',str(prefix)+'.relocs.tsv','--output-abi',str(prefix)+'.abi.tsv','--show'],expected=0)
  run(entry+'-disassemble-blob',['aarch64-linux-gnu-objdump','-D','-b','binary','-m','aarch64',str(prefix)+'.blob.bin'],cpu=19,expected=0)
  native=Path(str(prefix)+'.native.s');native.write_text('.text\n.global _start\n_start:\n b linked_entry\n.balign 8\nlinked_entry:\n.incbin "'+str(prefix)+'.blob.bin"\n mov x0, x7\n mov x8, #93\n svc #0\n'+data)
  run(entry+'-assemble-native',['aarch64-linux-gnu-as',native,'-o',str(prefix)+'.native.o'],expected=0)
  run(entry+'-link-native',['aarch64-linux-gnu-ld','-T',DEST/'layout.ld','-o',str(prefix)+'.native.elf',str(prefix)+'.native.o'],expected=0)
  native_exit=run(entry+'-execute-native',['qemu-aarch64-static',str(prefix)+'.native.elf'],cpu=19)
  r['cases'].append(dict(entry=entry,original_exit=original_exit,native_exit=native_exit,expected_live_value=34,stale_frozen_value=17,regression_passed=original_exit==native_exit==34))
 r.update(controller_status=0,regression_passed=all(x['regression_passed'] for x in r['cases']),scope='Synthetic AAPCS correctness witness using actual current native-link kernel mode and actual AArch64 user execution. Not a corpus timing, kernel-installed or actual-app affected-program claim.')
except BaseException:r.update(controller_status=1,error=traceback.format_exc());traceback.print_exc()
finally:
 r['ended_utc']=now();r['files']={str(p.relative_to(DEST)):dict(bytes=p.stat().st_size,sha256=sha(p)) for p in sorted(DEST.iterdir()) if p.is_file() and p.name!='controller.json'};(DEST/'controller.json').write_text(json.dumps(r,indent=2)+'\n')
raise SystemExit(r['controller_status'])
