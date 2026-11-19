"""Prove helper selection, inlining and kernel ARRAY boundary semantics."""
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path('/workspaces/repository')
sys.path[:0] = [str(ROOT/'kprog'), str(ROOT/'kprog/x86/micro-prog')]
from inline_array import lookup_source

out, compiler = Path(sys.argv[1]), Path(sys.argv[2])
commands = []
def run(args):
    p = subprocess.run([str(x) for x in args], text=True, capture_output=True)
    commands.append(dict(command=[str(x) for x in args], returncode=p.returncode,
                         stdout=p.stdout, stderr=p.stderr))
    (out/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
    p.check_returncode()
    return p.stdout

fixture = ROOT/'kprog/results/checked-array-c-20261119/fixture.c'
run(['clang-18','-target','bpf','-O3','-emit-llvm','-c',fixture,'-o',out/'input.bc'])
run([compiler,out/'input.bc','--array-map','counts','-o',out/'native.bc'])
text = run(['llvm-dis-18',out/'native.bc','-o','-'])
assert text.count('call ptr @__kprog_array_lookup(') == 1, text
assert text.count('call ptr @bpf_map_lookup_elem(') == 2, text
(out/'helpers.c').write_text(lookup_source('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux'))
run(['clang-18','-O3','-mgeneral-regs-only','-emit-llvm','-c',out/'helpers.c','-o',out/'helpers.bc'])
run(['llvm-link-18',out/'native.bc',out/'helpers.bc','-o',out/'linked.bc'])
run(['clang-18','-O3','-mgeneral-regs-only','-c',out/'linked.bc','-o',out/'native.o'])
asm = run(['llvm-objdump-18','-dr',out/'native.o'])
selected = asm.split('<selected>:')[1].split('\n\n')[0]
assert 'bpf_map_lookup_elem' not in selected and '__kprog_array_lookup' not in selected, selected
assert 'counts' in selected, selected
(out/'native.asm').write_text(asm)
# The executable reference reads the actual C parameters independently of the
# native linker. Boundary indexes must miss; known, unknown and dynamic map
# calls must route to exactly the selected implementation.
import re
source = (out/'helpers.c').read_text()
limit,stride,mask = map(int,re.findall(r'const char \*\)map \+ (\d+)',source))
values = int(re.search(r'return \(char \*\)map \+ (\d+)',source)[1])
(out/'driver.c').write_text('''#include <stdint.h>
#include <stdio.h>
#include <string.h>
unsigned char counts[4096] __attribute__((aligned(8))), other[4096];
static unsigned generic;
void *bpf_map_lookup_elem(void *map, const void *key) {
    (void)key; ++generic; return map;
}
extern void *selected(unsigned *), *unselected(unsigned *), *dynamic(void *, unsigned *);
int main(void) {
    unsigned tests=0;
    for(unsigned n=0;n<=17;++n) for(unsigned size=8;size<=64;size+=8) {
        unsigned mask=31;
        memcpy(counts+LIMIT,&n,4); memcpy(counts+STRIDE,&size,4); memcpy(counts+MASK,&mask,4);
        unsigned keys[]={0,1,16,17,31,0x80000000U,0xffffffffU};
        for(unsigned j=0;j<7;++j) {
            unsigned key=keys[j];
            void *want=key<n ? counts+VALUES+(uint64_t)size*(key&mask):0;
            if(selected(&key)!=want || generic) return 1;
            ++tests;
        }
    }
    unsigned key=0;
    if(unselected(&key)!=other || dynamic(counts,&key)!=counts || generic!=2) return 2;
    printf("%u ARRAY boundary cases and two generic calls passed\\n",tests);
}
'''.replace('LIMIT',str(limit)).replace('STRIDE',str(stride)).replace('MASK',str(mask)).replace('VALUES',str(values)))
run(['clang-18','-O3',out/'driver.c',out/'native.o','-o',out/'execute'])
result = run([out/'execute'])
(out/'summary.json').write_text(json.dumps(dict(result=result,selected_calls=1,generic_calls=2,
    selected_assembly=selected,scope='Host ABI/selection/kernel ARRAY semantics; no app timing claim'),indent=2)+'\n')
print(result,end='')
