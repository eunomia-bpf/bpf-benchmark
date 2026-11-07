from pathlib import Path
import json,hashlib,subprocess
r=Path('/workspaces/repository');s=Path('/workspaces/.agent-state/kprog-lanes/F');old=r/'kprog/fidelity/build-sp-v3/source';new=r/'kprog/fidelity/build-sp-v3b/source';new.mkdir(parents=True,exist_ok=True);pins=json.loads((s/'sp-v3-source-pins.json').read_text())
for rel,sha in pins['files'].items():
 data=(old/rel).read_bytes();assert hashlib.sha256(data).hexdigest()==sha,rel;p=new/rel;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
p=new/'kprog/formal/KProgFormal/X86StackArmShape.lean';p.write_text(p.read_text().replace('(index : BitVec 32)','(index : BitVec 64)'))
p=new/'kprog/formal/KProgFormal/CrossIsaStackArena.lean';t=p.read_text()
t=t.replace('GeneratedX86StackArena.wordIndex index := rfl','(GeneratedX86StackArena.wordIndex (index.zeroExtend 64)).truncate 32 := by\n  unfold GeneratedArm64StackArena.wordIndex GeneratedX86StackArena.wordIndex\n  bv_decide')
t=t.replace('GeneratedX86StackArena.wordAligned index := rfl','GeneratedX86StackArena.wordAligned (index.zeroExtend 64) := by\n  unfold GeneratedArm64StackArena.wordAligned GeneratedX86StackArena.wordAligned\n  bv_decide')
t=t.replace('theorem words_agrees (capacity : BitVec 32) :','theorem words_agrees (capacity : BitVec 32)\n    (h : capacity <= 4294967288) :').replace('GeneratedX86StackArena.words capacity := rfl','(GeneratedX86StackArena.words (capacity.zeroExtend 64)).truncate 32 := by\n  unfold GeneratedArm64StackArena.words GeneratedX86StackArena.words\n  bv_decide')
t=t.replace('GeneratedX86StackArena.windowEnd index width := rfl','GeneratedX86StackArena.windowEnd (index.zeroExtend 64) (width.zeroExtend 64) := by\n  simp [GeneratedArm64StackArena.windowEnd, GeneratedX86StackArena.windowEnd]')
t=t.replace('GeneratedX86StackArena.windowFits index width capacity := rfl','GeneratedX86StackArena.windowFits (index.zeroExtend 64) (width.zeroExtend 64) (capacity.zeroExtend 64) := by\n  simp [GeneratedArm64StackArena.windowFits, GeneratedArm64StackArena.windowEnd,\n    GeneratedX86StackArena.windowFits, GeneratedX86StackArena.windowEnd]')
t=t.replace('GeneratedX86StackArena.pointerFits index capacity := rfl','GeneratedX86StackArena.pointerFits (index.zeroExtend 64) (capacity.zeroExtend 64) := by\n  simp [GeneratedArm64StackArena.pointerFits, GeneratedX86StackArena.pointerFits]')
t=t.replace('on both ISAs. -/','on both ISAs for capacities whose low-width rounding does not wrap. -/',1);p.write_text(t)
(new/'vendor').symlink_to(r/'vendor',target_is_directory=True)
files={str(p.relative_to(new)):hashlib.sha256(p.read_bytes()).hexdigest() for p in new.rglob('*') if p.is_file() and not p.is_symlink()}
(s/'sp-v3b-source-pins.json').write_text(json.dumps(dict(base=pins['base'],files=files),indent=2)+'\n')
t=(s/'local-sp-v3-full.py').read_text().replace('sp-v3/','sp-v3b/').replace('sp-v3-source-pins','sp-v3b-source-pins').replace('sp-v3-full','sp-v3b-full').replace("assert (lane/'local-sp-v3-focused2.exit').read_text().strip()=='0'","assert (lane/'local-sp-v3b-focused.exit').read_text().strip()=='0'");(s/'local-sp-v3b-full.py').write_text(t)
(s/'local-sp-v3b-focused.sh').write_text('''#!/bin/bash
set -euo pipefail
cd /workspaces/repository/kprog/fidelity/build-sp-v3b/source/kprog/formal
state=/workspaces/.agent-state/kprog-lanes/F
trap 'rc=$?;printf "%s\\n" "$rc" > "$state/local-sp-v3b-focused.exit"' EXIT
cp -a /workspaces/repository/kprog/fidelity/build-sp-v3/source/kprog/formal/.lake .lake
export PATH=/root/.elan/bin:/usr/local/cargo/bin:$PATH
taskset -c 16-19 lake build KProgFormal.CrossIsaStackArena KProgFormal.X86StackArmShape
python3 "$state/local-sp-v3b-full.py"
''')
# Preserve first rejected constructions; the new controls restore SP from a
# saved entry value, so rejection must reach the memory path instead of RET.
t=(s/'sp_v3_high32.py').read_text();a=t.index("  negative.FIXTURES");b=t.index('\nbuild=',a)
t=t[:a]+'''  negative.FIXTURES['x86']['high32_'+name+'_'+lane]='mov rdx,rsp; sub rsp,16; mov QWORD PTR [rsp],37; mov ecx,1; shl rcx,32; '+('neg rcx; ' if name=='negative' else '')+'add rsp,rcx; '+('mov rax,QWORD PTR [rsp]; ' if lane=='qword' else 'movzx eax,BYTE PTR [rsp]; ')+'mov rsp,rdx; ret'
'''+t[b:];t=t.replace('sp-v3-high32','sp-v3-high32c');compile(t,'high32c','exec');(s/'sp_v3_high32c.py').write_text(t)
t=(s/'local-sp-v3-high32.sh').read_text().replace('sp_v3_high32.py','sp_v3_high32c.py').replace('local-sp-v3-high32.exit','local-sp-v3-high32c.exit');(s/'local-sp-v3-high32c.sh').write_text(t)
print('prepared2dependenttypeupdates; runtime byte-identicalv3')
