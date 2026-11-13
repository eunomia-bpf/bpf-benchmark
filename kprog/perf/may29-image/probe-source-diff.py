#!/usr/bin/env python3
"""Host-only semantic probes against the real headers, no app/source edits."""
import argparse
import importlib.util
import json
from pathlib import Path
import subprocess
import re
import sys
sys.dont_write_bytecode = True

ROOT = Path(__file__).resolve().parents[3]

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    a.out.mkdir(parents=True, exist_ok=True)
    records = []
    def command(argv, stdin=None):
        p = subprocess.run([str(x) for x in argv], input=stdin, cwd=ROOT,
                           text=True, capture_output=True)
        r = {'argv': [str(x) for x in argv], 'returncode': p.returncode,
             'stdout': p.stdout, 'stderr': p.stderr}
        records.append(r)
        return p
    def compile_probe(name, source, flags=(), execute=True):
        dest = a.out / name
        cmd = ['clang-18', '-O2', '-Wno-unknown-attributes', '-I', str(ROOT),
               '-I', str(ROOT / 'vendor/bpf/tetragon/bpf/include'),
               '-I', str(ROOT / 'vendor/bpf/tetragon/bpf/libbpf'),
               *flags, '-x', 'c', '-', '-o', str(dest)]
        p = command(cmd, source)
        # Exact probe source is retained as evidence, not a copy of any application tree.
        (a.out / (name + '.input.txt')).write_text(source)
        if not p.returncode and execute:
            command([dest.resolve()])
        return p
    compile_probe('substring', r'''
#define MICRO_NATIVE
#define MICRO_NATIVE_TETRAGON
#define __TARGET_ARCH_x86
#include "vendor/bpf/native_compat.h"
#include "vendor/bpf/tetragon/bpf/include/vmlinux.h"
#include "vendor/bpf/tetragon/bpf/include/api.h"
extern int printf(const char *, ...);
int main(void) {
    char hay[240], needle[180];
    for (int i=0; i<239; i++) hay[i]='a'; hay[239]=0;
    for (int i=0; i<179; i++) needle[i]='a'; needle[179]=0;
    printf("exact_suffix=%d expected=0\n", bpf_strnstr("abc", "abc", 3));
    printf("exact_suffix_case=%d expected=0\n", bpf_strncasestr("ABC", "abc", 3));
    printf("empty_at_len0=%d expected=0\n", bpf_strnstr("", "", 0));
    printf("notfound=%d expected=-2\n", bpf_strnstr("abc", "z", 3));
    printf("long_needle=%d expected=0\n", bpf_strnstr(hay, needle, 239));
    const char embedded[6]={'a',0,'z',0,0,0};
    printf("past_nul=%d expected=-2\n", bpf_strnstr(embedded, "z", 4));
    return 0;
}
''')
    compile_probe('syscall-regs', r'''
#define MICRO_NATIVE
#define __TARGET_ARCH_x86
#include "vendor/bpf/native_compat.h"
#include "vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h"
extern int printf(const char *, ...);
int main(void) {
    struct pt_regs inner={0}, outer={0};
    inner.cx=111; inner.r10=222; outer.di=(unsigned long)&inner;
    printf("syscall_arg4=%lu expected=222\n", (unsigned long)PT_REGS_PARM4_CORE_SYSCALL(&inner));
    printf("wrapper_unwrapped=%d expected=1\n", PT_REGS_SYSCALL_REGS(&outer)==&inner);
    return 0;
}
''')
    compile_probe('cilium-other-ctx', r'''
#define MICRO_NATIVE
#include "vendor/bpf/native_compat.h"
#include "vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h"
extern int printf(const char *, ...);
int main(void) {
    struct sockaddr_in addr={0}; addr.sin_addr.s_addr=0x12345678;
    struct bpf_sock_addr_kern kern={0}; kern.uaddr=(void *)&addr;
    unsigned int native_ip=0;
    __builtin_memcpy(&native_ip,(char *)&kern+offsetof(struct bpf_sock_addr,user_ip4),4);
    printf("sock_native_user_ip4=%x expected=12345678\n",native_ip);
    printf("sock_native_user_ip4_offset=%lu physical_uaddr_pointer_offset=%lu\n",
        (unsigned long)offsetof(struct bpf_sock_addr,user_ip4),
        (unsigned long)offsetof(struct bpf_sock_addr_kern,uaddr));
    struct net_device dev={}; dev.ifindex=7;
    struct xdp_rxq_info rxq={0}; rxq.dev=&dev;
    struct xdp_buff xdp={0}; xdp.rxq=&rxq; xdp.data_end=(void *)0x1122334455667788UL;
    unsigned int native_ifindex=0;
    __builtin_memcpy(&native_ifindex,(char *)&xdp+offsetof(struct xdp_md,ingress_ifindex),4);
    printf("xdp_native_ingress_ifindex=%x expected=7\n",native_ifindex);
    return 0;
}
''')
    compile_probe('cel', r'''
#define MICRO_NATIVE
#define __LARGE_BPF_PROG
#define GENERIC_KPROBE
#define FUNC_INLINE static inline
#include "vendor/bpf/tetragon/bpf/process/cel_expr.h"
extern int printf(const char *, ...);
int main(void) { long a=0; char b=0; printf("native_cel=%d (always zero)\n",cel_expr(0,&a,&b)); return 0; }
''')
    compile_probe('bcc-core', r'''
#define MICRO_NATIVE
#define __TARGET_ARCH_x86
#include "vendor/bpf/native_compat.h"
#include "vendor/bpf/bcc/libbpf-tools/core_fixes.bpf.h"
extern int printf(const char *, ...);
long bpf_probe_read_kernel(void *dst, unsigned int size, const void *src) {
    for (unsigned int i=0;i<size;i++) ((char *)dst)[i]=((const char *)src)[i];
    return 0;
}
int main(void) {
    struct task_struct task={0};
    task.thread_info.flags=99; task.__state=7;
    printf("native_state_offset=%lu target_state_offset=%lu\n",
        (unsigned long)offsetof(struct task_struct___x,__state),
        (unsigned long)offsetof(struct task_struct,__state));
    printf("native_get_task_state=%lld target_state=7\n",(long long)get_task_state(&task));
    printf("native_rq_disk_exists=%d expected=0 (target has no rq_disk)\n",
        bpf_core_field_exists(((struct request___x *)0)->rq_disk));
    return 0;
}
''', flags=('-I', str(ROOT / 'vendor/bpf/bcc/libbpf-tools/x86')))
    compile_probe('cilium-cb', r'''
#define MICRO_NATIVE
#include "vendor/bpf/native_compat.h"
#include "vendor/bpf/cilium/bpf/include/linux/bpf.h"
extern int printf(const char *, ...);
int main(void) {
    struct __sk_buff skb={0};
    skb.cb[0]=1234; skb.cb[1]=0x12345678; skb.cb[2]=55;
    printf("native_cb0_offset=%lu expected=48 (BTF: skb.cb40+qdisc.data8)\n",
        (unsigned long)offsetof(struct __sk_buff,cb[0]));
    printf("native_cb4_offset=%lu expected=64\n",(unsigned long)offsetof(struct __sk_buff,cb[4]));
    printf("native_cb0_wrote_kernel_pkt_len=%u\n", *(unsigned int *)((char *)&skb+40));
    printf("kernel_cb0_reads_native_cb2=%u\n", *(unsigned int *)((char *)&skb+48));
    return 0;
}
''', flags=('-I', str(ROOT / 'vendor/bpf/cilium/bpf/include')))
    compile_probe('helper-args', r'''
#define MICRO_NATIVE
#define MICRO_NATIVE_HELPER_MACROS
#include "vendor/bpf/native_compat.h"
extern void *next_key(void);
void *test(void *map) { return bpf_map_lookup_elem(map, next_key()); }
''', flags=('-c',), execute=False)
    command(['llvm-objdump-18', '-dr', a.out / 'helper-args'])
    for t in ['qdisc_skb_cb', 'bpf_skb_data_end']:
        p = command(['pahole', '-C', t, '/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'])
        (a.out / ('kernel-' + t + '.txt')).write_text(p.stdout + p.stderr)
    names = re.findall(r'^#define NATIVE_BPF_FUNC_(\w+) \d+', (ROOT / 'vendor/bpf/native_compat.h').read_text(), re.M)
    checks = '\n'.join('_Static_assert(NATIVE_BPF_FUNC_%s == BPF_FUNC_%s, "helper ID %s");' % (n,n,n) for n in names)
    compile_probe('helper-ids', '#define MICRO_NATIVE\n#define MICRO_NATIVE_HELPER_MACROS\n#include "vendor/bpf/native_compat.h"\n#include "vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h"\n' + checks + '\nint main(void) { return 0; }\n')
    # Source supplied by the existing builder; only preprocess/dependency operations
    # execute, never its build/specialization/publish routines.
    spec = importlib.util.spec_from_file_location('native_units', ROOT / 'vendor/bpf/native_specialize_objects.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    dependencies = []
    for app in ['bcc', 'otel', 'cilium', 'tetragon', 'tracee', 'katran']:
        for stem, source, flags in module.units_for_app(app):
            opts = [x for x in module.NATIVE_CFLAGS + flags if x != '-c']
            cmd = ['clang-18', *opts, '-M', '-MT', stem, str(source)]
            p = subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True)
            deps = p.stdout.replace('\\\n', ' ').split()[1:] if not p.returncode else []
            dependencies.append({'app': app, 'stem': stem, 'source': str(source),
                                 'argv': cmd, 'returncode': p.returncode,
                                 'stderr': p.stderr, 'dependencies': deps})
    (a.out / 'dependencies.json').write_text(json.dumps(dependencies, indent=2) + '\n')
    (a.out / 'host-probes.json').write_text(json.dumps(records, indent=2) + '\n')
    for r in records:
        print(' '.join(r['argv'][:3]), 'rc=', r['returncode'])
        print(r['stdout'][:2500] or r['stderr'][:2500])
    print('dependency commands:', len(dependencies), 'failures:', sum(d['returncode']!=0 for d in dependencies))
    if any(r['returncode'] for r in records) or any(d['returncode'] for d in dependencies):
        raise SystemExit('One or more audit commands failed; all diagnostics were retained')

if __name__ == '__main__': main()
