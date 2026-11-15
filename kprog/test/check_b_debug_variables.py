"""Catch executable or BTF loss when removing B-only debug variable updates."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]


def sections(path):
    with path.open('rb') as stream:
        return {s.name: dict(bytes=s.data_size, sha256=hashlib.sha256(s.data()).hexdigest())
                for s in ELFFile(stream).iter_sections()
                if s['sh_flags'] & 2 or s.name in ('.BTF', '.BTF.ext')}


def check(a):
    a.build.mkdir(parents=True, exist_ok=True)
    a.output.mkdir(parents=True, exist_ok=True)
    commands = []

    def run(command, *, retain_stdout=True):
        command = list(map(str, command))
        result = subprocess.run(command, text=True, capture_output=True)
        entry = dict(command=command, returncode=result.returncode, stderr=result.stderr)
        if retain_stdout:
            entry['stdout'] = result.stdout
        else:
            data = result.stdout.encode()
            entry.update(stdout_bytes=len(data), stdout_sha256=hashlib.sha256(data).hexdigest())
        commands.append(entry)
        (a.output/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        result.check_returncode()
        return result.stdout

    source = a.build/'debug.bpf.c'
    source.write_text('''#include <linux/bpf.h>
#include <bpf_helpers.h>
struct { __uint(type, BPF_MAP_TYPE_ARRAY); __uint(max_entries, 1);
    __type(key, unsigned); __type(value, unsigned long long); } values SEC(".maps");
SEC("xdp") int debug_probe(struct xdp_md *ctx) {
    unsigned key = 0;
    unsigned long long *value = bpf_map_lookup_elem(&values, &key);
    unsigned sum = ctx->ingress_ifindex;
''' + ''.join(f'    sum += {i};\n' for i in range(2048)) + '''
    return value ? sum + *(volatile unsigned long long *)value : ctx->rx_queue_index;
}
char LICENSE[] SEC("license") = "GPL";
''')
    frontend = a.build/'debug.bc'
    run(['clang-18', '-target', 'bpf', '-mcpu=v4', '-O3', '-g',
         '-I'+str(ROOT/'vendor/libbpf/include/uapi'), '-I'+str(ROOT/'vendor/libbpf/src'),
         '-I/usr/include/x86_64-linux-gnu', '-emit-llvm', '-c', source, '-o', frontend])
    reports = {}
    for name, tool in [('before', a.previous), ('after', a.tool)]:
        bitcode, obj = a.build/(name+'.bc'), a.build/(name+'.o')
        run([tool, frontend, '-o', bitcode])
        ir = run(['llvm-dis-18', bitcode, '-o', '-'], retain_stdout=False)
        run(['llc-18', '-O3', '-march=bpf', '-mcpu=v4', '-filetype=obj', bitcode, '-o', obj])
        reports[name] = dict(
            debug_variables=len(re.findall(r'call void @llvm\.dbg\.(?:value|declare|assign)\(', ir)),
            instruction_locations=len(re.findall(r', !dbg !\d+', ir)), sections=sections(obj))
    (a.output/'result.json').write_text(json.dumps(reports, indent=2)+'\n')
    if not reports['before']['debug_variables'] or reports['after']['debug_variables']:
        raise ValueError('B debug variable updates were not removed')
    if not reports['after']['instruction_locations']:
        raise ValueError('Executable instruction locations were lost')
    for name in ('.BTF', '.BTF.ext', '.maps', 'xdp'):
        if not reports['after']['sections'].get(name, {}).get('bytes'):
            raise ValueError('Required BTF/map/program section missing: '+name)
    if reports['before']['sections'] != reports['after']['sections']:
        raise ValueError('B-only debug cleanup changes allocated sections or BTF')
    print(json.dumps(reports), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('tool', 'previous', 'build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    check(parser.parse_args())
