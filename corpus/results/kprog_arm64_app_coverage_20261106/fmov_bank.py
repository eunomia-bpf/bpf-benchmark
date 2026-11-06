"""Three actual native/proof/source comparisons that observe all 32 SIMD cells."""
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
    rows=[]
    for mode in ['d_x','s_w','s_x']:
        name='fmov_bank_'+mode
        body=['ldr x4,[x0]','ldr x3,[x0,#8]','add x6,x4,#8','cmp x6,x3','b.hi 1f','mov x5,#0x100000000']
        for index in range(32):
            body += [f'add x1,x5,#{index+1}',f'fmov {"d" if mode=="d_x" else "s"}{index},{"x1" if mode=="d_x" else "w1"}']
        body+=['mov x2,#0']
        for index in range(32):
            body += [f'fmov {"w1,s" if mode=="s_w" else "x1,d"}{index}','add x2,x2,x1']
        body+=['str x2,[x4]','mov w0,#2','ret','1: mov w0,#0','ret']
        source=phase/'native'/(name+'.S');native=source.with_suffix('.native.o')
        source.write_text('.text\n.global entry\n.type entry,%function\nentry:\n'+'\n'.join(body)+'\n.size entry,.-entry\n')
        subprocess.run(['aarch64-linux-gnu-gcc','-c',source,'-o',native],check=True)
        proof=phase/'native'/(name+'.proof.o')
        subprocess.run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,
            '--symbol','entry','--mode','proof','--output',proof],check=True)
        functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'entry','xdp'),phase/'native')
        rendered=gen.render_program(name,'entry',functions,'xdp',rodata16=rodata,linked_exit=True)
        (phase/(name+'.bpf.c')).write_text(rendered)
        expected=528+(32*(1<<32) if mode=='d_x' else 0)
        (phase/(name+'.source.bpf.c')).write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\n'+
            f'SEC("xdp") int {name}(struct xdp_md *ctx) {{ void *p=(void *)(long)ctx->data; void *e=(void *)(long)ctx->data_end; if (p+8>e) return 0; *(__u64 *)p={expected}ULL; return 2; }}\nchar LICENSE[] SEC("license")="GPL";\n')
        (phase/(name+'.manifest.json')).write_text(json.dumps({'objects':[dict(program=name,native_object='/cases/'+native.name,
            symbol='entry',simulator_object='/cases/'+name+'.bpf.o',simulator_program=name+'_arm64_sim_xdp')]},indent=2)+'\n')
        rows.append(dict(name=name,expected=expected))
    (phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
    coverage.freeze_simulator(phase)
    for source in phase.glob('*.bpf.c'):
        source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
elif sys.argv[2]=='package':
    build=ROOT/'kprog/arm64/build/app-coverage'/phase.name
    root=build/'root';root.mkdir(parents=True)
    with Path(sys.argv[3]).open('rb') as source: unpack=subprocess.run(['gzip','-dc'],stdin=source,capture_output=True,check=True)
    subprocess.run(['cpio','-id','--quiet','--no-absolute-filenames','bin/busybox','lib/*','dev/console'],cwd=root,input=unpack.stdout,check=True)
    for name in ['proc','sys','results','cases','tmp']: (root/name).mkdir()
    (root/'bin/sh').symlink_to('busybox')
    shutil.copy2(phase/'bound-probe',root/'bound-probe')
    shutil.copy2(ROOT/'kprog/loader/target/aarch64-unknown-linux-gnu/debug/reversesim-loader',root/'loader')
    (root/'input.mem').write_bytes(bytes(64))
    shutil.copy2(ROOT/'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link',root/'native-link')
    shutil.copy2('/usr/aarch64-linux-gnu/lib/libgcc_s.so.1',root/'lib/libgcc_s.so.1')
    shutil.copy2('/workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64/bpf_arm64_native_lab.ko',root/'native_lab.ko')
    for source in list(phase.glob('*.bpf.o'))+list(phase.glob('*.manifest.json'))+list((phase/'native').glob('*.native.o'))+list((phase/'native').glob('*.entry.proof.o')):
        shutil.copy2(source,root/'cases'/source.name)
    script=['#!/bin/sh','export PATH=/bin','busybox mount -t proc proc /proc || exit 1',
        'busybox mount -t sysfs sysfs /sys || exit 1','busybox mount -t 9p -o trans=virtio results /results || exit 1',
        'busybox insmod /native_lab.ko || exit 1','ulimit -l unlimited || exit 1','status=0']
    for row in json.loads((phase/'cases.json').read_text()):
        name,expected=row['name'],row['expected']
        if row.get('reject'):
            commands=[('proof',f'/loader --object /cases/{name}.bpf.o --program {name}_arm64_sim_xdp --load-only'),
                ('native',f'/bound-probe /cases/{name}.source.bpf.o /cases/{name}.manifest.json')]
            expected_rc=1
        else:
            commands=[('proof',f'/loader --object /cases/{name}.bpf.o --program {name}_arm64_sim_xdp --input /input.mem --expected-result {expected} --expect-retval 2 --result-channel packet'),
                ('native',f'/bound-probe /cases/{name}.source.bpf.o /cases/{name}.manifest.json {expected} 2')]
            expected_rc=0
        for kind,command in commands:
            script += [command+f' >/results/{name}.{kind}.log 2>&1','rc=$?',f'echo "$rc" >/results/{name}.{kind}.rc',f'if [ "$rc" != {expected_rc} ]; then status=1; fi']
    script+=['echo "$status" >/results/guest-status','busybox sync','busybox poweroff -f']
    (root/'init').write_text('\n'.join(script)+'\n');(root/'init').chmod(0o755)
    files='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
    archive=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=files.encode(),capture_output=True,check=True)
    with (build/'initramfs.cpio.gz').open('wb') as out:subprocess.run(['gzip','-c'],input=archive.stdout,stdout=out,check=True)
else:raise ValueError(sys.argv[2])
