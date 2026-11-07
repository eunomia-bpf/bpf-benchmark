"""Catch compiler opacity changes hiding stack UB or blocking valid accesses."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage
ROOT=Path(__file__).resolve().parents[3]
phase=Path(sys.argv[1]).resolve();mode=sys.argv[2]
if mode=='prepare':
 phase.mkdir();coverage.freeze_simulator(phase)
 for name in ['objects','compile']: (phase/name).mkdir()
 cases=[('high35','ARM64_SIM_L_STACK_WRITE(0x800000000LL-32,8,37); return ARM64_SIM_L_STACK_READ(0x800000000LL-32,8);',1),
  ('hightag','ARM64_SIM_L_TAG_SET(0x100000000ULL,ARM64_SIM_TAG_STACK); return ARM64_SIM_L_TAG_GET(0x100000000ULL);',1),
  ('highword','ARM64_SIM_L_STACK_WRITE(0x100000000LL-32,8,37); return ARM64_SIM_L_STACK_READ(0x100000000LL-32,8);',1),
  ('lowword','ARM64_SIM_L_STACK_WRITE(-0x100000000LL-32,8,37); return ARM64_SIM_L_STACK_READ(-0x100000000LL-32,8);',1),
  ('highbyte','ARM64_SIM_L_STACK_WRITE(0x100000000LL-32,1,37); return ARM64_SIM_L_STACK_READ(0x100000000LL-32,1);',1),
  ('highdynamic','__u64 at=0x100000000ULL; asm volatile("" : "+r"(at)); ARM64_SIM_L_STACK_WRITE(at-32,8,37); return ARM64_SIM_L_STACK_READ(at-32,8);',1),
  ('fixed','ARM64_SIM_L_STACK_WRITE(-32,8,37); return ARM64_SIM_L_STACK_READ(-32,8)==37?2:0;',0),
  ('dynamic','__u32 at=8; asm volatile("" : "+r"(at)); ARM64_SIM_L_STACK_WRITE((__s64)at-32,8,37); return ARM64_SIM_L_STACK_READ((__s64)at-32,8)==37?2:0;',0),
  ('uninit','return ARM64_SIM_L_STACK_READ(-24,8);',0),
  ('below','ARM64_SIM_L_STACK_WRITE(-33,1,37); return ARM64_SIM_L_STACK_READ(-33,1);',1),
  ('above','ARM64_SIM_L_STACK_WRITE(0,8,37); return ARM64_SIM_L_STACK_READ(0,8);',1),
  ('cross','ARM64_SIM_L_STACK_WRITE(-4,8,37); return ARM64_SIM_L_STACK_READ(-4,8);',1),
  ('huge','__u32 at=0xfffffff8U; asm volatile("" : "+r"(at)); ARM64_SIM_L_STACK_WRITE((__s64)at-32,8,37); return ARM64_SIM_L_STACK_READ((__s64)at-32,8);',1)]
 rows=[]
 for short,body,expected in cases:
  name='layout_'+short;src=phase/(name+'.bpf.c')
  src.write_text('#define ARM64_SIM_ENABLE_STACK 1\n#define ARM64_SIM_STACK_BYTES 32U\n#define ARM64_SIM_STACK_BIAS 32LL\n#include "simulator/arm64_sim_local_bpf.h"\nSEC("xdp") int '+name+'_arm64_sim_xdp(void *ctx) { ARM64_SIM_ENTRY_RAW(ctx); '+body+' }\nARM64_SIM_LICENSE();\n')
  command=['clang','-g','-O2','-target','bpf','-mcpu=v4','-I'+str(ROOT/'vendor/libbpf/include/uapi'),'-I'+str(ROOT/'vendor/libbpf/src'),'-I/usr/include/x86_64-linux-gnu','-c',str(src),'-o',str(phase/'objects'/(name+'.bpf.o'))]
  r=subprocess.run(command,text=True,capture_output=True);record=dict(name=name,returncode=r.returncode,command=command,stdout=r.stdout,stderr=r.stderr,expected_rc=expected,load_only=(short=='uninit'))
  (phase/'compile'/(name+'.json')).write_text(json.dumps(record,indent=2)+'\n');r.check_returncode();rows.append(record)
 (phase/'cases.json').write_text(json.dumps(rows,indent=2)+'\n')
elif mode=='package':
 build=ROOT/'kprog/arm64/build/app-coverage'/phase.name
 coverage.package(phase,build,Path(sys.argv[3]));root=build/'root'
 shutil.copy2(Path(sys.argv[4]),root/'native_lab.ko')
 (root/'input.mem').write_bytes(bytes(64))
 lines=['#!/bin/sh','export PATH=/bin','busybox mount -t proc proc /proc || exit 1','busybox mount -t sysfs sysfs /sys || exit 1','busybox mount -t 9p -o trans=virtio results /results || exit 1','busybox insmod /native_lab.ko || exit 1','ulimit -l unlimited || exit 1','status=0']
 for row in json.loads((phase/'cases.json').read_text()):
  name=row['name'];mode='--load-only' if row['expected_rc'] or row.get('load_only') else '--input /input.mem --expected-result 0 --expect-retval 2 --result-channel packet'
  lines += [f'/loader --object /objects/{name}.bpf.o --program {name}_arm64_sim_xdp {mode} --verifier-log /results/{name}.verifier.log >/results/{name}.log 2>&1','rc=$?',f'echo "$rc" >/results/{name}.rc',f'if [ "$rc" != {row["expected_rc"]} ]; then status=1; fi']
 lines += ['echo "$status" >/results/guest-status','busybox sync','busybox poweroff -f']
 (root/'init').write_text('\n'.join(lines)+'\n')
 files='\n'.join(['.']+sorted(str(p.relative_to(root)) for p in root.rglob('*')))+'\n'
 r=subprocess.run(['cpio','-o','-H','newc','--quiet'],cwd=root,input=files.encode(),capture_output=True,check=True)
 with (build/'initramfs.cpio.gz').open('wb') as stream:subprocess.run(['gzip','-c'],input=r.stdout,stdout=stream,check=True)
elif mode=='collect':
 outcomes=[]
 for row in json.loads((phase/'cases.json').read_text()):
  name=row['name'];rc=int((phase/'verify'/(name+'.rc')).read_text());log=(phase/'verify'/(name+'.log')).read_text();assert rc==row['expected_rc'],(name,rc,log)
  if rc:assert 'load program:' in log or 'Permission denied' in log or 'Invalid argument' in log,(name,log)
  outcomes.append(dict(name=name,expected_rc=row['expected_rc'],actual_rc=rc))
 (phase/'outcomes.json').write_text(json.dumps(outcomes,indent=2)+'\n');print(json.dumps(outcomes))
else:raise ValueError(mode)
