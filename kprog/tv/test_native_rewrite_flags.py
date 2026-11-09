"""Execute the pre-restore flag producer with synthetic verifier state."""
from pathlib import Path
import os
import subprocess
import tempfile

root = Path(__file__).resolve().parents[2]
patch = (root / 'kprog/tv/native-proof-regions.patch').read_text().splitlines()
a = patch.index('+static void retain_kinsn_proof_flags(struct bpf_verifier_env *env)')
b = next(i for i in range(a, len(patch)) if patch[i].startswith(' static int restore_kinsn_proof_regions'))
body = '\n'.join(x[1:] for x in patch[a:b] if x.startswith('+'))
harness = r'''
#include <linux/bpf.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
typedef uint32_t u32;
#define MAX_PACKET_OFF 65535
#define U16_MAX UINT16_MAX
#define MAX_BPF_STACK 512
#define PTR_TO_CTX 1
#define BPF_LDST_BYTES(p) (BPF_SIZE((p)->code)==BPF_DW?8:BPF_SIZE((p)->code)==BPF_W?4:BPF_SIZE((p)->code)==BPF_H?2:1)
struct bpf_prog_aux {u32 max_pkt_offset;};
struct bpf_prog {struct bpf_prog_aux *aux;struct bpf_insn *insnsi;bool jit_requested,dst_needed,kprobe_override,cb_access;};
struct bpf_insn_aux_data {u32 seen,ptr_type,ctx_field_size;};
struct bpf_kinsn {bool native_proof;};
struct bpf_kinsn_region {struct bpf_kinsn *kinsn;u32 start,proof_len;};
enum bpf_access_type {BPF_READ,BPF_WRITE};
struct ops {u32 (*convert_ctx_access)(enum bpf_access_type,const struct bpf_insn*,struct bpf_insn*,struct bpf_prog*,u32*);};
struct subprog {u32 stack_depth;};
struct bpf_verifier_env {struct bpf_prog *prog;u32 kinsn_region_cnt;struct bpf_kinsn_region *kinsn_regions;struct bpf_insn_aux_data *insn_aux_data;struct ops *ops;struct subprog *subprog_info;};
static int rnd_init,converts,supports;
static void bpf_user_rnd_init_once(void){rnd_init++;}
static bool bpf_jit_supports_subprog_tailcalls(void){return supports;}
static int bpf_ctx_off_adjust_machine(int n){return n;}
static u32 convert(enum bpf_access_type type,const struct bpf_insn *si,struct bpf_insn *out,struct bpf_prog *prog,u32 *size){
 assert(si->off==48);assert(type==BPF_READ);assert(BPF_SIZE(si->code)==BPF_W);
 prog->cb_access=1;converts++;*size=4;return 1;
}
'''
main = r'''
int main(void){
 struct bpf_insn insns[7]={
 {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_get_route_realm},
 {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_get_prandom_u32},
 {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_override_return},
 {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_tail_call},
 {.code=BPF_LDX|BPF_MEM|BPF_B,.off=51},
 {.code=BPF_LDX|BPF_MEM|BPF_B,.off=51},
 {.code=BPF_JMP|BPF_CALL,.imm=BPF_FUNC_override_return,.src_reg=BPF_PSEUDO_KFUNC_CALL}};
 struct bpf_insn_aux_data aux[7]={{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,PTR_TO_CTX,4},{0,PTR_TO_CTX,4},{1,0,0}};
 struct bpf_prog_aux pa={0};struct bpf_prog p={.aux=&pa,.insnsi=insns,.jit_requested=true};
 struct bpf_kinsn k={true};struct bpf_kinsn_region r={&k,0,7};struct ops ops={convert};struct subprog sub={16};
 struct bpf_verifier_env e={&p,1,&r,aux,&ops,&sub};
 retain_kinsn_proof_flags(&e);
 assert(p.dst_needed&&p.kprobe_override&&p.cb_access&&rnd_init==1&&converts==1);
 assert(pa.max_pkt_offset==MAX_PACKET_OFF&&sub.stack_depth==MAX_BPF_STACK);
 supports=1;sub.stack_depth=16;retain_kinsn_proof_flags(&e);assert(sub.stack_depth==16);
 p.cb_access=0;r.start=4;r.proof_len=1;retain_kinsn_proof_flags(&e);assert(p.cb_access);
 k.native_proof=false;p.cb_access=0;retain_kinsn_proof_flags(&e);assert(!p.cb_access);
 return 0;
}
'''
with tempfile.TemporaryDirectory(prefix='rewrite-flags-') as temp:
    source = Path(temp) / 'flags.c'
    binary = Path(temp) / 'flags'
    source.write_text(harness + body + main)
    subprocess.run([os.environ.get('CC', 'cc'), '-O2', '-Wall', '-Werror', '-D__EXPORTED_HEADERS__',
                    '-I', str(root / 'vendor/linux-framework/include/uapi'),
                    str(source), '-o', str(binary)], check=True)
    subprocess.run([str(binary)], check=True)
print('native rewrite flag retention: PASS (helpers, narrow context, live regions, tail stack)')
