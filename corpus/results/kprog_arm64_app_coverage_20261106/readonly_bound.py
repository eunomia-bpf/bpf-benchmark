"""Exercise named readonly bases/interior addends in real generation-bound ARM."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve()
if sys.argv[2]=='prepare':
    phase.mkdir();(phase/'native').mkdir()
    for offset in [7,64,119]:
        name='readonly_'+str(offset);native=phase/'native'/(name+'.native.o')
        source=phase/'native'/(name+'.S')
        data=[(i*13+7)&255 for i in range(120)];expected=data[offset]
        source.write_text('.section .rodata\n.fill 16,1,238\n.global value\n.type value,%object\nvalue:\n.byte '+
            ','.join(map(str,data))+'\n.size value,.-value\n.text\n.global entry\n.type entry,%function\nentry:\n'+
            f'adrp x1,value+{offset}\nadd x1,x1,:lo12:value+{offset}\nldrb w0,[x1]\nret\n.size entry,.-entry\n')
        subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',native],check=True)
        proof=phase/'native'/(name+'.proof.o')
        subprocess.run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,
                        '--symbol','entry','--mode','proof','--output',proof],check=True,capture_output=True)
        functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'entry','xdp'),phase/'native')
        addends=[i.reloc_addend for i in functions['entry'] if i.mnemonic=='adrp']
        if addends!=[offset] or list(map(len,rodata.values()))!=[120]:
            raise RuntimeError(f'{name}: original readonly extent/interior relocation lost')
        rendered=gen.render_program(name,'entry',functions,'xdp',rodata16=rodata,linked_exit=True)
        (phase/(name+'.bpf.c')).write_text(rendered)
        needle=f'__arm64_rodata_0 + {offset}'
        if rendered.count(needle)!=1: raise RuntimeError('expected exactly one interior pointer')
        (phase/(name+'.no-addend.bpf.c')).write_text(rendered.replace(needle,'__arm64_rodata_0 + 0'))
        (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'+
            f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ return {expected}; }}\nchar LICENSE[] SEC("license")="GPL";\n')
        (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name,native_object='/cases/'+native.name,
            symbol='entry',simulator_object='/cases/'+name+'.bpf.o',simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
        (phase/(name+'.expected')).write_text(str(expected)+'\n')
    coverage.freeze_simulator(phase)
    for source in phase.glob('*.bpf.c'):
        source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
elif sys.argv[2]=='package':
    build=ROOT/'kprog/arm64/build/app-coverage'/phase.name
    root=build/'root';root.mkdir(parents=True)
    base=Path(sys.argv[3])
    with base.open('rb') as source: unpack=subprocess.run(['gzip','-dc'],stdin=source,capture_output=True,check=True)
    subprocess.run(['cpio','-id','--quiet','--no-absolute-filenames','bin/busybox','lib/*','dev/console'],cwd=root,input=unpack.stdout,check=True)
    for name in ['proc','sys','results','cases','tmp']: (root/name).mkdir()
    (root/'bin/sh').symlink_to('busybox')
    shutil.copy2(phase/'bound-probe',root/'bound-probe')
    shutil.copy2(ROOT/'kprog/loader/target/aarch64-unknown-linux-gnu/debug/reversesim-loader',root/'loader')
    (root/'input.mem').write_bytes(bytes(64))
    shutil.copy2(ROOT/'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link',root/'native-link')
    shutil.copy2('/usr/aarch64-linux-gnu/lib/libgcc_s.so.1',root/'lib/libgcc_s.so.1')
    pair=Path('/workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64')
    shutil.copy2(pair/'bpf_arm64_native_lab.ko',root/'native_lab.ko')
    for source in list(phase.glob('*.bpf.o'))+list(phase.glob('*.manifest.json'))+list((phase/'native').glob('*.native.o')):
        shutil.copy2(source,root/'cases'/source.name)
    script=['#!/bin/sh','export PATH=/bin','busybox mount -t proc proc /proc || exit 1',
        'busybox mount -t sysfs sysfs /sys || exit 1','busybox mount -t 9p -o trans=virtio results /results || exit 1',
        'busybox insmod /native_lab.ko || exit 1','ulimit -l unlimited || exit 1','status=0']
    for offset in [7,64,119]:
        name='readonly_'+str(offset);expected=(phase/(name+'.expected')).read_text().strip()
        script += [f'/loader --object /cases/{name}.bpf.o --program {name}_arm64_sim_xdp --input /input.mem --expected-result 0 --expect-retval {expected} --result-channel packet >/results/{name}.proof.log 2>&1',
                   'rc=$?',f'echo "$rc" >/results/{name}.proof.rc','if [ "$rc" != 0 ]; then status=1; fi',
                   f'/loader --object /cases/{name}.no-addend.bpf.o --program {name}_arm64_sim_xdp --input /input.mem --expected-result 0 --expect-retval {expected} --result-channel packet >/results/{name}.mutant.log 2>&1',
                   'rc=$?',f'echo "$rc" >/results/{name}.mutant.rc','if [ "$rc" != 1 ]; then status=1; fi',
                   f'busybox grep -q "unexpected XDP retval: got 7, expected {expected}" /results/{name}.mutant.log || status=1',
                   f'/bound-probe /cases/{name}.source.bpf.o /cases/{name}.manifest.json 0 {expected} >/results/{name}.log 2>&1',
                   'rc=$?',f'echo "$rc" >/results/{name}.rc','if [ "$rc" != 0 ]; then status=1; fi']
    script+=['echo "$status" >/results/guest-status','busybox sync','busybox poweroff -f']
    (root/'init').write_text('\n'.join(script)+'\n');(root/'init').chmod(0o755)
    files='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
    archive=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=files.encode(),capture_output=True,check=True)
    with (build/'initramfs.cpio.gz').open('wb') as out:subprocess.run(['gzip','-c'],input=archive.stdout,stdout=out,check=True)
elif sys.argv[2]=='collect':
    rows=[]
    for offset in [7,64,119]:
        name='readonly_'+str(offset);expected=int((phase/(name+'.expected')).read_text())
        outcomes={suffix:int((phase/'verify'/(name+suffix+'.rc')).read_text()) for suffix in ['','.proof','.mutant']}
        log=(phase/'verify'/(name+'.mutant.log')).read_text()
        if outcomes!={'':0,'.proof':0,'.mutant':1} or f'unexpected XDP retval: got 7, expected {expected}' not in log:
            raise RuntimeError(f'{name}: source/proof/native/mutation contract failed: {outcomes}')
        rows.append(dict(name=name,offset=offset,expected_retval=expected,**{
            'native_rc':outcomes[''],'proof_rc':outcomes['.proof'],'mutant_rc':outcomes['.mutant']}))
    (phase/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
    print('all3 source/proof/generation-bound native outputs match; all3 erased-addend mutants fail with the expected wrong byte')
else:
    raise ValueError(sys.argv[2])
