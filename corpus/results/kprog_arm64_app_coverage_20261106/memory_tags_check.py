"""Catch stale/corrupted return tags in libc and helper memory writes."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import coverage

ROOT=Path(__file__).resolve().parents[3]
phase=Path(sys.argv[1]).resolve();phase.mkdir()
coverage.freeze_simulator(phase)
source=r'''
#define ARM64_SIM_ENABLE_STACK 1
#define bpf_probe_read_kernel bpf_probe_read_kernel_declaration
#define bpf_get_current_comm bpf_get_current_comm_declaration
#define bpf_probe_read_kernel_str bpf_probe_read_kernel_str_declaration
#include "simulator/arm64_sim_local_bpf.h"
#undef bpf_probe_read_kernel
#undef bpf_get_current_comm
#undef bpf_probe_read_kernel_str
#include <stdio.h>
#include <string.h>
static long result;
static long bpf_probe_read_kernel(void *dst, unsigned len, const void *src) {
    if (result) memset(dst,0,len); else memcpy(dst,src,len);
    return result;
}
static long bpf_get_current_comm(void *dst, unsigned len) {
    memset(dst,0x5a,len); return 0;
}
static long bpf_probe_read_kernel_str(void *dst, unsigned len, const void *src) {
    if (result<0) { memset(dst,0,len); return result; }
    unsigned n=len<5?len:5;
    if (n) { memcpy(dst,src,n); ((unsigned char *)dst)[n-1]=0; }
    return n;
}
int main(void) {
    unsigned cases=0, failures=0;
    struct xdp_md ctx={0};
    for (unsigned mode=0; mode<7; mode++) for (unsigned da=0; da<8; da++)
    for (unsigned sa=0; sa<8; sa++) for (unsigned len=0; len<=24; len++) {
        ARM64_SIM_ENTRY_XDP(&ctx);
        unsigned char bytes[ARM64_SIM_STACK_BYTES],tags[ARM64_SIM_STACK_BYTES/8],original[ARM64_SIM_STACK_BYTES/8];
        unsigned dst=80+da,src=32+sa;
        for (unsigned i=0; i<sizeof(bytes); i++) __a64_stack.b[i]=bytes[i]=(unsigned char)(i*17+3);
        for (unsigned i=0; i<sizeof(tags); i++)
            __a64_stack_tag[i]=tags[i]=original[i]=(i&1)?ARM64_SIM_TAG_RETURN:ARM64_SIM_TAG_CODE;
        unsigned written=mode==5?(len<5?len:5):len;
        for (unsigned i=0; i<written; i++)
            bytes[dst+i]=(mode==1||mode==2||mode==5)?bytes[src+i]:((mode==3||mode==6)?0:0x5a);
        if (mode==5 && written) bytes[dst+written-1]=0;
        for (unsigned i=0; i<sizeof(tags); i++) {
            unsigned start=i*8;
            if (len && start<dst+len && start+8>dst) {
                tags[i]=ARM64_SIM_TAG_SCALAR;
                if ((mode==1||mode==2) && start>=dst && start+8<=dst+len && (src+start-dst)%8==0)
                    tags[i]=original[(src+start-dst)/8];
            }
        }
        ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X0,(void *)((long)dst-ARM64_SIM_STACK_BIAS),ARM64_SIM_TAG_STACK);
        if (mode==0) {
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1,0x5a,ARM64_WIDTH_64);
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2,len,ARM64_WIDTH_64);
            ARM64_SIM_LIBC_MEMSET();
        } else if (mode==1) {
            ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X1,(void *)((long)src-ARM64_SIM_STACK_BIAS),ARM64_SIM_TAG_STACK);
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X2,len,ARM64_WIDTH_64);
            ARM64_SIM_LIBC_MEMCPY();
        } else if (mode==2||mode==3) {
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1,len,ARM64_WIDTH_64);
            ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,(void *)((long)src-ARM64_SIM_STACK_BIAS),ARM64_SIM_TAG_STACK);
            result=mode==2?0:-14;
            ARM64_SIM_BPF_CALL_bpf_probe_read_kernel();
        } else if (mode==4) {
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1,len,ARM64_WIDTH_64);
            ARM64_SIM_BPF_CALL_bpf_get_current_comm();
        } else {
            ARM64_SIM_L_WRITE_REG_WIDTH(ARM64_X1,len,ARM64_WIDTH_64);
            ARM64_SIM_L_WRITE_REG_PTR_TAG(ARM64_X2,(void *)((long)src-ARM64_SIM_STACK_BIAS),ARM64_SIM_TAG_STACK);
            result=mode==5?0:-14;
            ARM64_SIM_BPF_CALL_bpf_probe_read_kernel_str();
        }
        unsigned bad=0;
        for (unsigned i=0; i<sizeof(bytes); i++) bad |= __a64_stack.b[i]!=bytes[i];
        for (unsigned i=0; i<sizeof(tags); i++) bad |= __a64_stack_tag[i]!=tags[i];
        if (bad) { printf("FAIL mode=%u dst=%u src=%u length=%u\n",mode,da,sa,len); failures++; }
        cases++;
    }
    printf("memory byte/tag checks: %u cases, %u failures\n",cases,failures);
    return failures!=0;
}
'''
(phase/'memory.c').write_text(source)
command=['cc','-O1','-g','-fsanitize=address,undefined','-fno-omit-frame-pointer',
         '-include',str(ROOT/'kprog/formal/oracles/arm64_entry_environment_host.h'),
         '-I'+str(ROOT/'vendor/libbpf/src'),'-I'+str(ROOT/'vendor/libbpf/include/uapi'),
         str(phase/'memory.c'),'-o',str(phase/'memory')]
built=subprocess.run(command,text=True,capture_output=True)
(phase/'build.json').write_text(json.dumps(dict(command=command,returncode=built.returncode,stdout=built.stdout,stderr=built.stderr),indent=2)+'\n')
if built.returncode: raise RuntimeError(built.stderr)
run=subprocess.run([str(phase/'memory')],text=True,capture_output=True)
(phase/'outcome.json').write_text(json.dumps(dict(returncode=run.returncode,stdout=run.stdout,stderr=run.stderr),indent=2)+'\n')
print(run.stdout,end='')
if run.returncode: raise RuntimeError(run.stderr or run.stdout)
