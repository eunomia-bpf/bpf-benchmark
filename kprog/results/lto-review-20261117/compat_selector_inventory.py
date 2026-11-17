#!/usr/bin/env python3
"""Read-only source boundary arithmetic; does not generate or execute native code."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
rows = []
for paging_bits in (47, 56):
    user_max = (1 << paging_bits) - 4096
    for addr32 in (False, True):
        for limit_3gb in (False, True):
            task_size = (0xc0000000 if limit_3gb else 0xffffe000) if addr32 else user_max
            pointers = sorted({0, 0xc0000000 - 1, 0xc0000000, 0xd0000000,
                               0xffffe000 - 1, 0xffffe000, task_size - 1, task_size,
                               user_max - 1, user_max, 0xffff888000001000})
            for src in pointers:
                for size in (0, 8):
                    domain = 'user' if src < task_size else 'kernel'
                    rows.append(dict(paging_bits=paging_bits, tif_addr32=addr32,
                                     addr_limit_3gb=limit_3gb, source=hex(src), size=size,
                                     task_size=hex(task_size), kernel_selector=domain,
                                     boot_limit_only='user' if src < user_max else 'kernel',
                                     inclusive_selector='user' if src <= task_size else 'kernel',
                                     end_based_selector='user' if src + size < task_size else 'kernel'))
result = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
              scope='Finite arithmetic illustrations of the sole kernel source selector. Not a native implementation test, memory-read outcome, syscall-mode proxy, equal-work assertion or admission check.',
              sources={'selector':'vendor/linux-framework/kernel/trace/bpf_trace.c:285-313',
                       'task_limit':'vendor/linux-framework/arch/x86/include/asm/page_64_types.h:59-67',
                       'address_width_flag':'vendor/linux-framework/arch/x86/include/asm/thread_info.h:103',
                       'personality':'vendor/linux-framework/include/uapi/linux/personality.h:24'},
              flag_masks={'thread_info_flags':hex(1 << 27), 'personality':hex(0x08000000)},
              rows=rows)
(HERE / 'compat-selector.json').write_text(json.dumps(result, indent=2) + '\n')
vmlinux = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
disassembly = subprocess.check_output(['objdump', '-d', '--no-show-raw-insn',
                                      '--disassemble=bpf_probe_read_compat', str(vmlinux)], text=True)
(HERE / 'compat-kernel-helper.disassembly.txt').write_text(disassembly)
print(len(rows), 'source-selector rows; existing kernel helper disassembly retained')
for recipe in ('boot_limit_only', 'inclusive_selector', 'end_based_selector'):
    print(recipe, sum(row[recipe] != row['kernel_selector'] for row in rows), 'differing illustrations')
