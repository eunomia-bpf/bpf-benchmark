#!/usr/bin/env python3
"""Read helper disassembly and model initial-namespace ID conversion, without emitting code."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
MASK32 = (1 << 32) - 1
MASK64 = (1 << 64) - 1


def initial_map_up(value):
    # init_user_ns extent: first=0, lower_first=0, count=0xffffffff.
    # count=1 in map_id_up, so id2 equals id; failure returns (u32)-1.
    return value if 0 <= value <= MASK32 - 1 else MASK32


rows = []
ids = (0,1,65535,0x7fffffff,0xfffffffe,0xffffffff)
for uid in ids:
    for gid in ids:
        kernel = (initial_map_up(gid) << 32) | initial_map_up(uid)
        direct = (gid << 32) | uid
        rows.append(dict(uid=uid,gid=gid,kernel=hex(kernel),direct=hex(direct),equal=kernel==direct))
pid_rows = []
for pid, tgid in ((19,41),(-1,41),(-(1 << 31),41)):
    kernel = (((tgid & MASK64) << 32) | (pid & MASK64)) & MASK64
    packed_words = ((tgid & MASK32) << 32) | (pid & MASK32)
    pid_rows.append(dict(pid=pid,tgid=tgid,kernel=hex(kernel),packed_words=hex(packed_words),
                         equal=kernel==packed_words))
result = dict(recorded_utc=subprocess.check_output(['date','-u','+%FT%TZ'],text=True).strip(),
              scope='Finite arithmetic illustrations plus sole-kernel disassembly. No native candidate, BTF layout emission, memory fault, guest, build, performance/stock-verifier result or new gate. Real credential values remain live, not root constants.',
              sources=['vendor/linux-framework/kernel/bpf/helpers.c:241-258',
                       'vendor/linux-framework/kernel/user.c:37-63',
                       'vendor/linux-framework/kernel/user_namespace.c:348-406,441-444,509-512,980-981',
                       'vendor/linux-framework/include/linux/cred.h:289-296,401-406'],
              initial_namespace_extent=dict(first=0,lower_first=0,count=MASK32,nr_extents=1),
              uid_gid_rows=rows,pid_sign_extension_counterexamples=pid_rows)
# Reuse the native emitter's nine-byte absolute-SIB GS load, not vmlinux's eight-byte RIP form.
shared_parts = dict(current_task_gs=9,null_test=3,null_near_branch=6,
                    live_cred_pointer=7,success_ret=1,error_result=7,error_ret=1)
result['local_leaf_source_byte_estimates'] = dict(common_parts=shared_parts,
    adjacent_uid_gid_load_bytes=4,separate_uid_gid_pack_bytes=15,
    adjacent_total=sum(shared_parts.values())+4,separate_total=sum(shared_parts.values())+15)
(HERE / 'credential-helpers.json').write_text(json.dumps(result,indent=2)+'\n')
outputs = []
for helper in ('bpf_get_current_uid_gid','bpf_get_current_pid_tgid','bpf_get_current_comm'):
    outputs.append(subprocess.check_output(['objdump','-d','--no-show-raw-insn',
        '--disassemble='+helper,'/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'],text=True))
(HERE / 'credential-helpers.disassembly.txt').write_text('\n'.join(outputs))
print(len(rows),'UID/GID arithmetic illustrations;',sum(not row['equal'] for row in rows),'differences')
print('PID packing examples:',[(row['pid'],row['equal']) for row in pid_rows])
