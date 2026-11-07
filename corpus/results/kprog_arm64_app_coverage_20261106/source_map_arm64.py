"""Emit the exact captured BCC map-value probe with source-site map identity."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
from elftools.elf.elffile import ELFFile
import coverage
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
import generate_micro_sim_proofs as gen
phase=Path(sys.argv[1]).resolve()
if len(sys.argv)>2 and sys.argv[2]=='install':
    stage=ROOT/'kprog/arm64/build/app-verified-stage'
    entry=json.loads((phase/'manifest-entry.json').read_text())
    for manifest in sorted(stage.glob('*/manifest.json')):
        target=manifest.parent/'startup';target.mkdir(exist_ok=True)
        for source in [phase/'source_map.bpf.o',phase/'native/source_map.native.o',phase/'native/source_map.bpf_main.proof.o']:
            shutil.copy2(source,target/source.name)
        installed=dict(entry,native_object='startup/source_map.native.o',simulator_object='startup/source_map.bpf.o')
        data=json.loads(manifest.read_text())
        selector=lambda item:tuple(item.get(key) for key in ('program','prog_type','source_bytecode_hex'))
        data['objects']=[item for item in data['objects'] if selector(item)!=selector(installed)]+[installed]
        manifest.write_text(json.dumps(data,indent=2)+'\n')
        print(manifest.parent.name+': exact runtime-FD map-value probe triple installed')
    sys.exit(0)
if len(sys.argv)>2 and sys.argv[2]=='package':
    build=ROOT/'kprog/arm64/build/app-coverage'/phase.name
    root=build/'root';root.mkdir(parents=True)
    with Path(sys.argv[3]).open('rb') as stream:unpack=subprocess.run(['gzip','-dc'],stdin=stream,capture_output=True,check=True)
    subprocess.run(['cpio','-id','--quiet','--no-absolute-filenames','bin/busybox','lib/*','dev/console'],cwd=root,input=unpack.stdout,check=True)
    for name in ['proc','sys','results','cases','tmp']:(root/name).mkdir()
    (root/'bin/sh').symlink_to('busybox')
    shutil.copy2(phase/'source-map-probe',root/'source-map-probe')
    shutil.copy2(ROOT/'kprog/arm64/build/app-native-link/aarch64-unknown-linux-gnu/release/native-link',root/'native-link')
    shutil.copy2('/usr/aarch64-linux-gnu/lib/libgcc_s.so.1',root/'lib/libgcc_s.so.1')
    shutil.copy2('/workspaces/.agent-state/kprog-lanes/T/context-v2-source-map/arm64/bpf_arm64_native_lab.ko',root/'native_lab.ko')
    for source in [phase/'source.bpf.bin',*phase.glob('source_map*.bpf.o'),*(phase/'native').glob('*.native.o'),*(phase/'native').glob('*.bpf_main.proof.o')]:
        shutil.copy2(source,root/'cases'/source.name)
    entry=json.loads((phase/'manifest-entry.json').read_text())
    (root/'cases/manifest.json').write_text(json.dumps({'objects':[entry]},indent=2)+'\n')
    wrong=dict(entry,simulator_object='/cases/source_map_wrong.bpf.o')
    (root/'cases/wrong-offset.json').write_text(json.dumps({'objects':[wrong]},indent=2)+'\n')
    readonly_argument=''
    if (phase/'source_map_wrong_rodata.bpf.o').exists():
        wrong=dict(entry,simulator_object='/cases/source_map_wrong_rodata.bpf.o')
        (root/'cases/wrong-rodata.json').write_text(json.dumps({'objects':[wrong]},indent=2)+'\n')
        readonly_argument=' /cases/wrong-rodata.json'
    script=['#!/bin/sh','export PATH=/bin','busybox mount -t proc proc /proc || exit 1',
        'busybox mount -t sysfs sysfs /sys || exit 1','busybox mount -t 9p -o trans=virtio results /results || exit 1',
        'busybox insmod /native_lab.ko || exit 1','ulimit -l unlimited || exit 1',
        'BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF=1 /source-map-probe /cases/source.bpf.bin /cases/manifest.json /cases/wrong-offset.json'+readonly_argument+' >/results/source-map.log 2>&1',
        'rc=$?','echo "$rc" >/results/guest-status','busybox dmesg >/results/dmesg.log','busybox sync','busybox poweroff -f']
    (root/'init').write_text('\n'.join(script)+'\n');(root/'init').chmod(0o755)
    names='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
    archive=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=names.encode(),capture_output=True,check=True)
    with (build/'initramfs.cpio.gz').open('wb') as out:subprocess.run(['gzip','-c'],input=archive.stdout,stdout=out,check=True)
    sys.exit(0)
phase.mkdir();(phase/'native').mkdir()
source=Path(__file__).with_name('source-map-input')
for name in ['source.bpf.bin','native.opt.ll','source-map-bindings.json']:shutil.copy2(source/name,phase/name)
if len(sys.argv)>2:
    if sys.argv[2] != 'readonly': raise ValueError(sys.argv[2])
    ir=phase/'native.opt.ll'
    text=ir.read_text().replace('@__native_source_map_0 = external', '@__readonly_value = private constant i64 42, align 8\n\n@__native_source_map_0 = external')
    text=text.replace('  store i64 42,', '  %value = load volatile i64, ptr @__readonly_value, align 8\n  store i64 %value,')
    ir.write_text(text)
bindings=json.loads((phase/'source-map-bindings.json').read_text())
commands=[]
def run(args):
    args=list(map(str,args));result=subprocess.run(args,text=True,capture_output=True,timeout=120)
    commands.append(dict(command=args,returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
    (phase/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
    if result.returncode:raise RuntimeError(result.stderr)
native=phase/'native'/'source_map.native.o'
run(['llc-18','-mtriple=aarch64-linux-gnu','-mcpu=generic','-mattr=+reserve-x18,+reserve-x26,+reserve-x27,+reserve-x28',
     '-filetype=obj','-O=3','-relocation-model=pic',phase/'native.opt.ll','-o',native])
proof=phase/'native'/'source_map.proof.o'
run([ROOT/'kprog/arm64/build/app-native-link/release/native-link','--input',native,'--symbol','bpf_main',
     '--mode','proof','--preserve-entry-abi','--output',proof])
shutil.copy2(proof,phase/'native'/'source_map.bpf_main.proof.o')
functions,rodata=gen.parse_native_linked_program(gen.Bench('source_map','bpf_main','raw'),phase/'native')
text=gen.render_program('source_map','bpf_main',functions,'raw',rodata16=rodata,linked_exit=True,
    program_section='socket',source_map_bindings=bindings)
checks=[]
bad=[('missing original map identity',[]),('invalid source kind',[dict(bindings[0],kind=3)]),
     ('boolean source kind',[dict(bindings[0],kind=True)]),('negative source offset',[dict(bindings[0],value_offset=-1)]),
     ('overflow source offset',[dict(bindings[0],value_offset=1<<32)]),('duplicate source identity',bindings+bindings)]
for label,metadata in bad:
    try:gen.render_program('source_map','bpf_main',functions,'raw',rodata16=rodata,linked_exit=True,
        program_section='socket',source_map_bindings=metadata)
    except ValueError as error:checks.append(dict(case=label,rejected=True,error=str(error)))
    else:raise RuntimeError('invalid source-map binding accepted: '+label)
(phase/'binding-errors.json').write_text(json.dumps(checks,indent=2)+'\n')
coverage.freeze_simulator(phase)
text=text.replace('#include "../arm64_sim_local_bpf.h"',f'#include "{phase}/simulator/arm64_sim_local_bpf.h"')
(phase/'source_map.bpf.c').write_text(text)
run(['clang','-g','-O2','-target','bpf','-D__TARGET_ARCH_arm64','-I'+str(ROOT/'vendor/libbpf/include/uapi'),
     '-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',phase/'source_map.bpf.c','-o',phase/'source_map.bpf.o'])
if len(sys.argv)>2 and sys.argv[2]=='readonly':
    with (phase/'source_map.bpf.o').open('rb') as stream:
        elf=ELFFile(stream);section=elf.get_section_by_name('.rodata.native.0')
        if section is None: raise RuntimeError('readonly fixture has no private data relocation')
        data=bytearray(section.data());data[0]^=1
    bad=phase/'wrong-readonly.bin';bad.write_bytes(data)
    run(['llvm-objcopy-18','--update-section=.rodata.native.0='+str(bad),
        phase/'source_map.bpf.o',phase/'source_map_wrong_rodata.bpf.o'])
if text.count('__source_map_base_0 + 16ULL')!=1:raise RuntimeError('expected one explicit source map offset')
(phase/'source_map_wrong.bpf.c').write_text(text.replace('__source_map_base_0 + 16ULL','__source_map_base_0 + 0ULL'))
run(['clang','-g','-O2','-target','bpf','-D__TARGET_ARCH_arm64','-I'+str(ROOT/'vendor/libbpf/include/uapi'),
     '-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',phase/'source_map_wrong.bpf.c','-o',phase/'source_map_wrong.bpf.o'])
entry=json.loads((source/'manifest-entry.json').read_text())
entry.update(native_object='/cases/source_map.native.o',simulator_object='/cases/source_map.bpf.o',simulator_program='source_map_arm64_sim_xdp',prog_type=1)
(phase/'manifest-entry.json').write_text(json.dumps(entry,indent=2)+'\n')
with (phase/'source_map.bpf.o').open('rb') as stream:
    elf=ELFFile(stream);metadata=json.loads(elf.get_section_by_name('.native_lab.source_maps').data().rstrip(b'\0'))
    if metadata!={'version':1,'objects':[{k:b[k] for k in ['native_symbol','source_insn','proof_symbol']} for b in bindings]}:
        raise RuntimeError('compiled source-map identity metadata differs')
    if elf.get_section_by_name('.maps') is not None:raise RuntimeError('source-map proof invented an application map')
print('actual BCC5-insn map-value probe: AArch64 native/proof/SIM compilation and exact source-site metadata PASS')
