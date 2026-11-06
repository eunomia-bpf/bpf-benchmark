"""Catch stale pointer/return tags after partial or unaligned native stores."""
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
phase = Path(sys.argv[1]).resolve()
phase.mkdir()
source = r'''
#include "simulator/arm64_sim_local_bpf.h"
#include <stdio.h>
#include <string.h>
int main(void) {
    unsigned cases=0, failures=0;
    const unsigned widths[]={ARM64_WIDTH_8,ARM64_WIDTH_16,ARM64_WIDTH_32,ARM64_WIDTH_64};
    struct xdp_md ctx={0};
    for (unsigned at=64; at<80; at++) for (unsigned w=0; w<4; w++) {
        ARM64_SIM_ENTRY_XDP(&ctx);
        unsigned char bytes[ARM64_SIM_STACK_BYTES], tags[ARM64_SIM_STACK_BYTES/8];
        for (unsigned i=0; i<sizeof(bytes); i++) __a64_stack.b[i]=bytes[i]=(unsigned char)(i*13+7);
        for (unsigned i=0; i<sizeof(tags); i++)
            __a64_stack_tag[i]=tags[i]=(i&1)?ARM64_SIM_TAG_RETURN:ARM64_SIM_TAG_CODE;
        unsigned n=widths[w];
        unsigned long long value=0x123456789abcdef0ULL;
        for (unsigned i=0; i<n; i++) bytes[at+i]=(unsigned char)(value>>(8*i));
        for (unsigned i=at/8; i<=(at+n-1)/8; i++) tags[i]=ARM64_SIM_TAG_SCALAR;
        if (n==8 && at%8==0) tags[at/8]=ARM64_SIM_TAG_STACK;
        ARM64_SIM_L_STACK_WRITE_TAG((long)at-ARM64_SIM_STACK_BIAS, widths[w], value, ARM64_SIM_TAG_STACK);
        unsigned bad=0;
        for (unsigned i=0; i<sizeof(bytes); i++) bad |= __a64_stack.b[i]!=bytes[i];
        for (unsigned i=0; i<sizeof(tags); i++) bad |= __a64_stack_tag[i]!=tags[i];
        if (bad) { printf("FAIL at=%u bytes=%u\n",at,n); failures++; }
        cases++;
    }
    printf("stack store byte/tag checks: %u cases, %u failures\n", cases,failures);
    return failures!=0;
}
'''
(phase/'store.c').write_text('#define ARM64_SIM_ENABLE_STACK 1\n'+source)
for version in ['before','after']:
    out=phase/version
    (out/'simulator').mkdir(parents=True)
    shutil.copytree(ROOT/'kprog/formal/generated',out/'formal/generated')
    for name in ['arm64_sim.h','arm64_sim_local_bpf.h','arm64_sim_direct.h']:
        data=(ROOT/'kprog/arm64'/name).read_bytes()
        if version=='before':
            data=subprocess.check_output(['git','show','ceed44baf:kprog/arm64/'+name],cwd=ROOT)
        (out/'simulator'/name).write_bytes(data)
    shutil.copy2(phase/'store.c',out/'store.c')
    command=['cc','-O1','-g','-fsanitize=address,undefined','-fno-omit-frame-pointer',
             '-I'+str(ROOT/'vendor/libbpf/src'),'-I'+str(ROOT/'vendor/libbpf/include/uapi'),
             str(out/'store.c'),'-o',str(out/'store')]
    built=subprocess.run(command,text=True,capture_output=True)
    (out/'build.json').write_text(json.dumps(dict(command=command,returncode=built.returncode,
         stdout=built.stdout,stderr=built.stderr),indent=2)+'\n')
    if built.returncode: raise RuntimeError(built.stderr)
    run=subprocess.run([str(out/'store')],text=True,capture_output=True)
    (out/'outcome.json').write_text(json.dumps(dict(returncode=run.returncode,
         stdout=run.stdout,stderr=run.stderr),indent=2)+'\n')
    print(version+': '+run.stdout,flush=True)
    if run.returncode != (1 if version=='before' else 0): raise RuntimeError(run.stderr or run.stdout)
