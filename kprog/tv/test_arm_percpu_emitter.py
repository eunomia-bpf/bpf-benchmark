"""Catch kind4 offset wrap, premature stores, incorrect TP selection and Xt drift.
Compile the production case verbatim for host and AArch64 with UBSan.
Canonical MRS behavior is supplied by NativeLinkArmPerCpu.lean.
"""
import hashlib
import os
from pathlib import Path
import re
import subprocess
import tempfile

source_path = Path(__file__).resolve().parents[2] / 'kinsn/module/arm64/bpf_arm64_native_lab.c'
source = source_path.read_text()
start = source.index('case NATIVE_LAB_RELOC_ARM64_PERCPU_MRS: {')
cursor = source.index('{', start) + 1
depth = 1
while depth:
    depth += (source[cursor] == '{') - (source[cursor] == '}')
    cursor += 1
case = source[start:cursor]
assert case.count('image[slot_index] =') == 1
assert case.index('r->offset &') < case.index('(size_t)r->offset + sizeof(u32)') < case.index('image[slot_index] !=') < case.index('image[slot_index] =')
macros = '\n'.join(re.search(r'^#define ' + name + r'\s+[^\n]+', source, re.M).group()
                   for name in ['NATIVE_LAB_RELOC_ARM64_PERCPU_MRS', 'A64_MRS_X10_TPIDR_EL1', 'A64_MRS_X10_TPIDR_EL2'])
preamble = r'''
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
typedef uint32_t u32;
typedef uint64_t u64;
_Static_assert(sizeof(size_t)==8,"ARM64 offset arithmetic");
#define native_lab_emit_error(...) ((void)0)
#define cpus_have_cap(cap) (vhe)
struct native_lab_reloc_record { u32 offset,kind; u64 target; };
'''
wrapper = '''
static int actual_case(u32 *image, size_t start_idx, size_t native_len, u32 offset, u64 target, int vhe)
{
    struct native_lab_reloc_record record={offset,NATIVE_LAB_RELOC_ARM64_PERCPU_MRS,target};
    const struct native_lab_reloc_record *r=&record;
    int err=0;
    switch (r->kind) {
''' + case + '''
    }
    return err;
}
'''
harness = r'''
static unsigned accepted,refused;
static int check(u32 offset,size_t length,u32 old,int vhe,u64 target)
{
    enum { START=3,WORDS=264 };
    u32 actual[WORDS],expected[WORDS];
    for (unsigned j=0;j<WORDS;j++) actual[j]=expected[j]=0x12340000U+j*7919U;
    size_t index=START+(size_t)offset/4;
    if (index<WORDS) actual[index]=expected[index]=old;
    int wanted=(offset%4)?-EINVAL:((u64)offset+4>length)?-ERANGE:(old!=0xd538d08aU)?-EINVAL:0;
    if (!wanted) expected[index]=vhe?0xd53cd04aU:0xd538d08aU;
    int result=actual_case(actual,START,length,offset,target,vhe);
    if (result!=wanted || memcmp(actual,expected,sizeof(actual))) {
        fprintf(stderr,"offset=%u length=%zu old=%08x vhe=%d actual=%d wanted=%d\n",offset,length,old,vhe,result,wanted);
        return 1;
    }
    if (wanted) refused++; else accepted++;
    return 0;
}
int main(void)
{
    const u32 current[]={0xd538d08aU,0xd53cd04aU,0xd538d089U,0U,0xffffffffU};
    for (u32 offset=0;offset<1024;offset++) {
        const size_t lengths[]={0,3,4,1023,1024,(size_t)offset+3,(size_t)offset+4,(size_t)offset+5};
        for (unsigned i=0;i<sizeof(lengths)/sizeof(lengths[0]);i++)
            for (unsigned j=0;j<sizeof(current)/sizeof(current[0]);j++)
                for (int vhe=0;vhe<2;vhe++)
                    if (check(offset,lengths[i],current[j],vhe,UINT64_C(0xfeed800012345678))) return 1;
    }
    const u32 high[]={0xfffffffcU,0xfffffffdU,0xfffffffeU,0xffffffffU,0x80000000U,0x7fffffffU};
    for (unsigned i=0;i<sizeof(high)/sizeof(high[0]);i++)
        for (int vhe=0;vhe<2;vhe++)
            if (check(high[i],1024,0xd538d08aU,vhe,0)) return 2;
    for (unsigned bit=0;bit<32;bit++)
        for (int vhe=0;vhe<2;vhe++)
            if (check(4,8,0xd538d08aU^(1U<<bit),vhe,UINT64_MAX)) return 3;
    printf("production kind4: accepted=%u refused=%u total=%u; bounds/alignment/X10/VHE/canaries PASS\n",accepted,refused,accepted+refused);
    return 0;
}
'''
unit = preamble + macros + '\n' + wrapper + harness
build = Path(__file__).resolve().parent / 'build'
build.mkdir(exist_ok=True)
with tempfile.TemporaryDirectory(prefix='arm-percpu-emitter-', dir=build) as directory:
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
print('kind4 current-word guard and successful one-word store PASS')
