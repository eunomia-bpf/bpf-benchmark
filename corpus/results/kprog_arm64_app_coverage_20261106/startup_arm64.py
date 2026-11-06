"""Compile the actual libbpf startup bytecode into paired AArch64 proof artifacts."""
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog'))
from helper_abi import helper_idents
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve()
if sys.argv[2]=='prepare':
    phase.mkdir();(phase/'native').mkdir()
    (phase/'source.bpf.c').write_text('#include <linux/bpf.h>\n#include <bpf_helpers.h>\nSEC("xdp") int runtime_source(struct xdp_md *ctx) { return 127; }\nchar LICENSE[] SEC("license")="GPL";\n')
elif sys.argv[2]=='generate':
    source=Path(__file__).with_name('startup-bytecode.json')
    entries=json.loads(source.read_text())
    with (phase/'source.bpf.o').open('rb') as stream:
        source_bytes=ELFFile(stream).get_section_by_name('xdp').data()
    entries.append(dict(program='runtime_source',prog_type=6,source_bytecode_hex=source_bytes.hex()))
    manifest=[];commands=[]
    def run(command):
        command=list(map(str,command));result=subprocess.run(command,text=True,capture_output=True,timeout=120)
        commands.append(dict(command=command,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
        (phase/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        if result.returncode:raise RuntimeError(result.stderr)
    names=helper_idents()
    for index,entry in enumerate(entries):
        name='startup_'+str(index);raw=phase/(name+'.bin');raw.write_bytes(bytes.fromhex(entry['source_bytecode_hex']))
        ir=phase/(name+'.ll');optimized=phase/(name+'.opt.ll')
        run([ROOT/'corpus/results/kprog_app_coverage_20261106/lift-bpf-ir',raw,ir])
        ir.write_text(re.sub(r'_bpf_helper_ext_([0-9]+)',lambda m:names[int(m[1])],ir.read_text()))
        run(['opt-18','-O3','-S',ir,'-o',optimized])
        native=phase/'native'/(name+'.native.o')
        run(['llc-18','-mtriple=aarch64-linux-gnu','-mcpu=generic',
             '-mattr=+reserve-x18,+reserve-x26,+reserve-x27,+reserve-x28',
             '-filetype=obj','-O=3','-relocation-model=pic',optimized,'-o',native])
        proof=phase/'native'/(name+'.proof.o')
        run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,
             '--symbol','bpf_main','--mode','proof','--preserve-entry-abi','--output',proof])
        functions,rodata=gen.parse_native_linked_program(gen.Bench(name,'bpf_main','raw'),phase/'native')
        section={1:'socket',2:'kprobe',9:'cgroup/sock',6:'xdp',26:'fentry/native_startup_probe',5:'tracepoint/native/startup'}[entry['prog_type']]
        text=gen.render_program(name,'bpf_main',functions,'raw',rodata16=rodata,
            linked_exit=True,program_section=section)
        (phase/(name+'.bpf.c')).write_text(text)
        manifest.append(dict(program=entry['program'],prog_type=entry['prog_type'],
            source_bytecode_hex=entry['source_bytecode_hex'],native_object='/cases/'+native.name,
            symbol='bpf_main',simulator_object='/cases/'+name+'.bpf.o',simulator_program=name+'_arm64_sim_xdp'))
        shutil.copy2(proof,phase/'native'/(name+'.bpf_main.proof.o'))
    (phase/'manifest.json').write_text(json.dumps(dict(objects=manifest),indent=2)+'\n')
    coverage.freeze_simulator(phase)
    for path in phase.glob('startup_*.bpf.c'):
        path.write_text(path.read_text().replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"'))
    print(f'all{len(manifest)} exact startup bytecode/name/type selectors have AArch64 native/proof pairs')
elif sys.argv[2]=='package':
    build=ROOT/'kprog/arm64/build/app-coverage'/phase.name;root=build/'root';root.mkdir(parents=True)
    with Path(sys.argv[3]).open('rb') as stream: unpack=subprocess.run(['gzip','-dc'],stdin=stream,capture_output=True,check=True)
    subprocess.run(['cpio','-id','--quiet','--no-absolute-filenames','bin/busybox','lib/*','dev/console'],cwd=root,input=unpack.stdout,check=True)
    for name in ['proc','sys','results','cases','tmp']: (root/name).mkdir()
    (root/'bin/sh').symlink_to('busybox')
    files={root/'inspect':phase/'inspect',root/'startup':phase/'startup',root/'shim.so':ROOT/'bpfopt/shim/build-arm64-a-context-v5/libbpfrejit_shim.so',
        root/'libnative_loader.so':Path(sys.argv[4]),
        root/'native-link':ROOT/'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link'}
    for destination,source in files.items():shutil.copy2(source,destination)
    directories=[ROOT/'.cache/aarch64-sysroot/usr/lib/aarch64-linux-gnu',ROOT/'.cache/aarch64-sysroot/lib/aarch64-linux-gnu',Path('/usr/aarch64-linux-gnu/lib')]
    pending=list(files);seen=set()
    while pending:
        path=pending.pop()
        with path.open('rb') as stream:
            elf=ELFFile(stream)
            dynamic=elf.get_section_by_name('.dynamic')
            needed=[tag.needed for tag in dynamic.iter_tags() if tag.entry.d_tag=='DT_NEEDED'] if dynamic else []
        for name in needed:
            if name in seen:continue
            seen.add(name)
            candidates=[directory/name for directory in directories if (directory/name).is_file()]
            if not candidates:raise RuntimeError(f'missing actual AArch64 shared dependency: {name}')
            destination=root/'lib'/name;shutil.copy2(candidates[0],destination);pending.append(destination)
    pair=Path('/workspaces/.agent-state/kprog-lanes/T/paired-context-v2/arm64')
    shutil.copy2(pair/'bpf_arm64_native_lab.ko',root/'native_lab.ko')
    for source in [phase/'source.bpf.o',phase/'manifest.json',*phase.glob('startup_*.bpf.o'),*(phase/'native').glob('*.native.o'),*(phase/'native').glob('*.bpf_main.proof.o')]:
        shutil.copy2(source,root/'cases'/source.name)
    script=['#!/bin/sh','export PATH=/bin','export LD_LIBRARY_PATH=/lib','busybox mount -t proc proc /proc || exit 1',
        'busybox mount -t devtmpfs devtmpfs /dev || exit 1',
        'busybox mount -t sysfs sysfs /sys || exit 1','busybox mount -t 9p -o trans=virtio results /results || exit 1',
        'busybox mount -t tmpfs tmpfs /tmp || exit 1','busybox insmod /native_lab.ko || exit 1','ulimit -l unlimited || exit 1','status=0',
        '/inspect /cases/startup_0.bpf.o startup_0_arm64_sim_xdp >/results/inspect.log 2>&1',
        'echo "$?" >/results/inspect.rc']
    for flags in [0,8]:
        script += [f'busybox mkdir -p /tmp/shim{flags} /tmp/sockets{flags}',
            f'LD_PRELOAD=/shim.so BPFREJIT_SHIM_NATIVE_LOADER=1 BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 BPFREJIT_SHIM_NATIVE_KMSG_PROGRESS=1 '+
            'BPFREJIT_SHIM_NATIVE_MANIFEST=/cases/manifest.json BPFREJIT_NATIVE_LINK_BINARY=/native-link BPFREJIT_NATIVE_LOADER_SO=/libnative_loader.so '+
            f'BPFREJIT_SHIM_DIR=/tmp/shim{flags} BPFREJIT_SHIM_SOCK_DIR=/tmp/sockets{flags} BPFREJIT_SHIM_LOG=/results/flags{flags}.shim.log '+
            f'/startup /cases/source.bpf.o {flags} >/results/flags{flags}.stdout 2>/results/flags{flags}.stderr',
            'rc=$?',f'echo "$rc" >/results/flags{flags}.rc','if [ "$rc" != 0 ]; then status=1; fi',
            f'busybox cp -a /tmp/shim{flags} /results/shim{flags} || status=1']
    script+=['busybox dmesg >/results/dmesg.log','echo "$status" >/results/guest-status','busybox sync','busybox poweroff -f']
    (root/'init').write_text('\n'.join(script)+'\n');(root/'init').chmod(0o755)
    names='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
    archive=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=names.encode(),capture_output=True,check=True)
    with (build/'initramfs.cpio.gz').open('wb') as out:subprocess.run(['gzip','-c'],input=archive.stdout,stdout=out,check=True)
elif sys.argv[2]=='collect':
    rows=[]
    for flags in [0,8]:
        code=int((phase/'verify'/f'flags{flags}.rc').read_text());log=(phase/'verify'/f'flags{flags}.shim.log').read_text()
        loads=log.count('BPF_PROG_LOAD type=');replacements=log.count('native-loader replaced prog=')
        if code or loads!=6 or replacements!=6 or 'skipped feature probe' in log or 'skipped internal' in log:
            raise RuntimeError(f'flags{flags}: startup failed or bypassed a program: rc={code} loads={loads} replacements={replacements}')
        stdout=(phase/'verify'/f'flags{flags}.stdout').read_text()
        if 'nonzero_generations=1' not in stdout or 'retval=127' not in stdout:raise RuntimeError(stdout)
        contexts=[int(value) for value in re.findall(r'native-loader source-context flags=(\d+) token_fd=-1',log)]
        if contexts != [0,0,0,0,0,flags]:raise RuntimeError(f'incorrect original startup flags: {contexts}')
        rows.append(dict(flags=flags,returncode=code,loads=loads,native_replacements=replacements,stdout=stdout))
    (phase/'outcomes.json').write_text(json.dumps(rows,indent=2)+'\n')
    print('all6 actual libbpf startup loads generation-bound for both flags0/8; no probe/name bypass; native main returns127')
elif sys.argv[2]=='install':
    stage=ROOT/'kprog/arm64/build/app-verified-stage'
    probes=json.loads((phase/'manifest.json').read_text())['objects'][:-1]
    for manifest in sorted(stage.glob('*/manifest.json')):
        target=manifest.parent/'startup';target.mkdir(exist_ok=True)
        entries=[]
        for probe in probes:
            entry=dict(probe)
            for key in ['native_object','simulator_object']:
                name=Path(entry[key]).name
                source=(phase/'native'/name if key=='native_object' else phase/name)
                shutil.copy2(source,target/name);entry[key]='startup/'+name
            proof=Path(probe['native_object']).name.removesuffix('.native.o')+'.bpf_main.proof.o'
            shutil.copy2(phase/'native'/proof,target/proof)
            entries.append(entry)
        data=json.loads(manifest.read_text())
        keys={(e['program'],e['prog_type'],e['source_bytecode_hex']) for e in entries}
        data['objects']=[e for e in data['objects'] if (e.get('program'),e.get('prog_type'),e.get('source_bytecode_hex')) not in keys]+entries
        manifest.write_text(json.dumps(data,indent=2)+'\n')
        print(f'{manifest.parent.name}: installed all{len(entries)} exact startup probe selectors and native/proof/simulator triples')
else:raise ValueError(sys.argv[2])
