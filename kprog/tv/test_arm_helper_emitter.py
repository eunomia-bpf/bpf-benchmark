"""Catch far-target truncation and stores preceding representability refusal.
Compile the production word writers for host and ARM with UBSan; compare accepted bytes with
that same writer's pre-check body. ISA decoding comes from the Lean reference.
"""
import hashlib
import os
from pathlib import Path
import re
import subprocess
import tempfile

source_path = Path(__file__).resolve().parents[2] / 'kinsn/module/arm64/bpf_arm64_native_lab.c'
source = source_path.read_text()

def function(name):
    match = re.search(r'^static (?:u32|int) ' + re.escape(name) + r'\([^;]+?\)\n\{', source, re.M)
    assert match, name
    start, end, depth = match.start(), match.end(), 1
    while depth:
        depth += (source[end] == '{') - (source[end] == '}')
        end += 1
    return source[start:end]

writer = function('emit_arm64_far_helper_call')
legacy = r"""
static void prior_writer(u32 *image, size_t slot_index, u64 target)
{
    image[slot_index] = 0x92800000U | ((u32)(~target & 0xffff) << 5) | 10U;
    image[slot_index + 1] = 0xf2a00000U | ((u32)((target >> 16) & 0xffff) << 5) | 10U;
    image[slot_index + 2] = 0xf2c00000U | ((u32)((target >> 32) & 0xffff) << 5) | 10U;
    image[slot_index + 3] = 0xd63f0140U;
}
"""
macros = '\n'.join(re.search(r'^#define ' + name + r'\s+[^\n]+', source, re.M).group()
                   for name in ['A64_TMP_REG', 'A64_BLR_X10'])
preamble = '#include <stdint.h>\n#include <stddef.h>\n#include <errno.h>\n#include <stdio.h>\n#include <string.h>\ntypedef uint16_t u16;\ntypedef uint32_t u32;\ntypedef uint64_t u64;\n'
harness = r'''
static int check_target(u64 target, unsigned *accepted, unsigned *rejected)
{
    u32 actual[6], expected[6];
    for (unsigned j=0;j<6;j++) actual[j]=expected[j]=0x12340000U+j;
    int result=emit_arm64_far_helper_call(actual,1,target);
    if ((target>>48)==0xffff) {
        prior_writer(expected,1,target);
        if (result || memcmp(actual,expected,sizeof(actual))) return 1;
        (*accepted)++;
    } else {
        if (result!=-ERANGE || memcmp(actual,expected,sizeof(actual))) return 2;
        (*rejected)++;
    }
    return 0;
}
int main(void)
{
    unsigned accepted=0,rejected=0;
    const u64 lower[]={0,UINT64_C(0x800000000000),UINT64_C(0xfffffffffffc)};
    u64 random=UINT64_C(0x123456789abcdef0);
    for (u64 upper=0;upper<65536;upper++) {
        for (unsigned j=0;j<3;j++) {
            int error=check_target((upper<<48)|lower[j],&accepted,&rejected);
            if (error) return error;
        }
        random^=random<<13; random^=random>>7; random^=random<<17;
        int error=check_target(UINT64_C(0xffff000000000000)|(random&UINT64_C(0xfffffffffffc)),&accepted,&rejected);
        if (error) return error;
    }
    u32 first[4],second[4];
    prior_writer(first,0,UINT64_C(0xfff0000012345678));
    prior_writer(second,0,UINT64_C(0xffff000012345678));
    if (memcmp(first,second,sizeof(first))) return 3;
    if (accepted!=65539 || rejected!=196605) return 4;
    printf("production C emitter: accepted=%u rejected=%u total=%u; canaries and prior accepted bytes PASS; baseline upper-bit collision reproduced\n",accepted,rejected,accepted+rejected);
    return 0;
}
'''
unit = preamble + macros + '\n' + function('a64_movn_x') + '\n' + function('a64_movk_x') + '\n' + legacy + '\n' + writer + '\n' + harness
with tempfile.TemporaryDirectory(prefix='arm-helper-emitter-', dir=Path(__file__).resolve().parent / 'build') as directory:
    path = Path(directory)
    (path / 'check.c').write_text(unit)
    for label, compiler, runner in [('host', os.environ.get('CC', 'cc'), []),
                                    ('aarch64', 'aarch64-linux-gnu-gcc', ['qemu-aarch64-static', '-L', '/usr/aarch64-linux-gnu'])]:
        binary = path / ('check-' + label)
        subprocess.run([compiler, '-std=c11', '-O2', '-Wall', '-Wextra', '-Werror', '-fsanitize=undefined', '-fno-sanitize-recover=all', str(path / 'check.c'), '-o', str(binary)], check=True)
        print(label + ' binary SHA256=' + hashlib.sha256(binary.read_bytes()).hexdigest(), flush=True)
        subprocess.run(runner + [str(binary)], check=True)
print('production source SHA256=' + hashlib.sha256(source.encode()).hexdigest())
print('compiled extraction SHA256=' + hashlib.sha256(unit.encode()).hexdigest())
print('compiled far-helper emitter cases PASS')
