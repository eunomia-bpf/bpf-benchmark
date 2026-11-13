"""Exercise actual target signatures, native-byte generation and return ABI."""
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog'))
from trusted_service import adapter
from kernel_function_abi import KernelTypes
sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
import kfunc_codegen

native, btf, output = map(Path, sys.argv[1:])
output.mkdir(parents=True, exist_ok=True)
types = KernelTypes(btf)
try:
    signatures = {name: types.function(name, True) for name in (
        'bpf_strnstr', 'bpf_strncasestr', 'bpf_iter_num_new', 'bpf_iter_num_next', 'bpf_iter_num_destroy')}
finally:
    types.close()
assert signatures['bpf_strnstr']['result']['size'] == 4
assert signatures['bpf_iter_num_next']['result']['pointer']
assert signatures['bpf_iter_num_destroy']['result']['type'] == 'void'
assert signatures['bpf_iter_num_new']['arguments'][0]['pointer']
assert all(a['type'].startswith('const ') for a in signatures['bpf_strnstr']['arguments'] if a['pointer'])
(output/'target-signatures.json').write_text(json.dumps(signatures, indent=2)+'\n')

# A negative int return must zero-extend EAX; casting the signed C result
# directly to u64 would incorrectly sign-extend the upper half of RAX.
source = '''#include <stdint.h>
#include <assert.h>
#include <linux/types.h>
#define X86_RAX 0
#define X86_RDI 1
#define X86_RSI 2
#define X86_RDX 3
#define X86_WIDTH_32 32
#define X86_WIDTH_64 64
#define X86_SIM_TAG_STACK 4
#define X86_SIM_TAG_SCALAR 0
#define X86_SIM_L_REG_TAG(R) X86_SIM_TAG_SCALAR
#define X86_SIM_L_STACK_VALUES_CLEAR() (++memory_clobbers)
#define X86_SIM_L_HELPER_ARG_PTR(R) ((void *)(uintptr_t)registers[R])
#define X86_SIM_L_HELPER_CTX_PTR(R) X86_SIM_L_HELPER_ARG_PTR(R)
#define X86_SIM_L_READ_REG(R) registers[R]
#define X86_SIM_L_WRITE_REG_WIDTH(R,V,W) (registers[R]=(W)==32 ? (uint32_t)(V):(uint64_t)(V))
#define X86_SIM_L_STACK_VALUES_CALL_FRAME() ((void)0)
#define X86_SIM_L_HELPER_REGISTER_CLOBBERS() (++clobbers)
static uint64_t registers[4]; static unsigned clobbers, memory_clobbers; static int result;
FUNCTION_HEADER {
    assert(a==(void *)11 && b==(void *)23 && length==37); return result;
}
int main(void) {
    const int cases[]={-1,-34,0,1,2147483647,(-2147483647-1)};
    registers[1]=11;registers[2]=23;registers[3]=37;
    for(unsigned i=0;i<sizeof(cases)/sizeof(cases[0]);++i) {
        result=cases[i];
'''
signature = signatures['bpf_strnstr']
header = signature['result']['type'] + ' bpf_strnstr(' + ', '.join(
    argument['type'] + ' ' + name for argument, name in zip(signature['arguments'], ('a', 'b', 'length'))) + ')'
source = source.replace('FUNCTION_HEADER', header)
source += '\n'.join(kfunc_codegen.call(signatures['bpf_strnstr'], '        '))
source += '\nassert(registers[0]==(uint32_t)result);assert(clobbers==i+1);assert(memory_clobbers==2*(i+1));}}\n'
(output/'return-abi.c').write_text(source)
subprocess.run(['clang-18','-O2',output/'return-abi.c','-o',output/'return-abi'],check=True)
subprocess.run([output/'return-abi'],check=True)

worker = adapter(1)
metadata = dict(version=1, prog_type=2, section='kprobe/trusted', maps=[], kernel_kfunc_context=True)
artifacts = worker.specialize(native.read_bytes(), 'entry', metadata, output/'generated',
    ROOT/'kprog/x86/native_lab/native_link/target/release/native-link', kernel_btf=btf)
iterator = worker.specialize(native.read_bytes(), 'iterator', metadata, output/'iterator',
    ROOT/'kprog/x86/native_lab/native_link/target/release/native-link', kernel_btf=btf)
legacy = dict(version=1, prog_type=2, section='kprobe/trusted', maps=[dict(
    name='stats',map_type=2,key_size=4,value_size=40,max_entries=1,map_flags=1024,value_offset=0)])
worker.specialize((ROOT/'vendor/build/native-bpf/x86/stage/bcc/vfsstat.native.o').read_bytes(),
    'kprobe_vfs_read', legacy, output/'bcc-default',
    ROOT/'kprog/x86/native_lab/native_link/target/release/native-link', kernel_btf=btf)
assert json.loads((output/'bcc-default/kernel-functions.json').read_text()) == {}
print(json.dumps(dict(ok=True, return_boundaries=6, actual_target_signatures=5,
                      scope='Host generation and ABI only; kernel outcome pending', artifacts=artifacts,
                      iterator=iterator)))
