/* Compare the generic-capacity exported bodies with the canonical C using the
 * producer's array/scalar ghost backends. Same arena address and free-input
 * stream in both executions; every register, private byte and fact is observed. */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROFILE
#error PROFILE must select the canonical fixture capacity
#endif
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#define X86_SIM_STACK_BYTES PROFILE
#if SCALAR_FACTS
#define WORDS8(M) M(0) M(1) M(2) M(3) M(4) M(5) M(6) M(7)
#define WORDS25(M) WORDS8(M) M(8) M(9) M(10) M(11) M(12) M(13) M(14) M(15) M(16) M(17) M(18) M(19) M(20) M(21) M(22) M(23) M(24)
#define WORDS47(M) WORDS25(M) M(25) M(26) M(27) M(28) M(29) M(30) M(31) M(32) M(33) M(34) M(35) M(36) M(37) M(38) M(39) M(40) M(41) M(42) M(43) M(44) M(45) M(46)
#if PROFILE == 64
#define X86_SIM_STACK_VALUE_WORDS(M) WORDS8(M)
#elif PROFILE == 200
#define X86_SIM_STACK_VALUE_WORDS(M) WORDS25(M)
#elif PROFILE == 376
#define X86_SIM_STACK_VALUE_WORDS(M) WORDS47(M)
#else
#error no scalarized producer fixture for this profile
#endif
#endif
#include "../c/X86Pointer.h"
#undef __x86_stack_mem
#define __x86_stack_mem (*native_arena)
#undef X86_SIM_L_UNSPECIFIED
#define X86_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)

static unsigned draws;
static __u64 entropy;
static unsigned long cases, free_draws;
unsigned long native_lab_entry_input(unsigned kind)
{
	if (kind != NATIVE_LAB_INPUT_UNSPECIFIED) abort();
	draws++;
	entropy ^= entropy << 13; entropy ^= entropy >> 7; entropy ^= entropy << 17;
	return entropy;
}
static void check(int ok, const char *what)
{
	if (!ok) { fprintf(stderr,"profile=%u scalar=%u case=%lu: %s\n",PROFILE,SCALAR_FACTS,cases,what); exit(1); }
}
struct operation { unsigned kind; __u8 op,dst,src,flags,shift; __u32 aux; __u64 value; };
static __u64 generic(struct x86_sim_register_state *s, struct kprog_x86_arena *a,
                     struct kprog_x86_stack_fact *facts, struct operation o)
{
	switch(o.kind) {
	case 0: kprog_x86_ptr_load(s,a,facts,PROFILE,o.op,o.dst,o.aux,o.value); break;
	case 1: return kprog_x86_read_reg(s,a,PROFILE,o.src,o.flags,o.shift);
	case 2: kprog_x86_write_reg(s,a,facts,PROFILE,o.dst,o.value,o.flags,o.shift); break;
	case 3: kprog_x86_mov_imm(s,a,facts,PROFILE,o.dst,o.flags,o.aux,o.value); break;
	case 4: kprog_x86_mov_reg(s,a,facts,PROFILE,o.dst,o.src,o.flags,o.aux); break;
	case 5: kprog_x86_movx_reg(s,a,facts,PROFILE,o.op,o.dst,o.src,o.flags,o.aux); break;
	default: abort();
	}
	return 0;
}
static __u64 native(struct x86_sim_register_state *s, struct kprog_x86_arena *a,
                    struct kprog_x86_stack_fact *facts, struct operation o)
{
	struct x86_sim_register_state *__x86_state=s;
	volatile union x86_sim_stack_mem *native_arena=(volatile union x86_sim_stack_mem *)(void *)a->b;
	X86_SIM_L_DECLARE_STACK_VALUES();
#define LOAD(I) do { X86_SIM_L_SV_TAG(I)=*facts[I].tag; X86_SIM_L_SV_PTR(I)=*facts[I].pointer; } while(0);
	X86_SIM_L_SV_EACH(LOAD)
#undef LOAD
	__u64 result=0;
	switch(o.kind) {
	case 0: X86_SIM_L_EXEC_PTR_LOAD(o.op,o.dst,o.aux,o.value); break;
	case 1: result=X86_SIM_L_READ_REG_WIDTH_SHIFT(o.src,o.flags,o.shift); break;
	case 2: X86_SIM_L_WRITE_REG_WIDTH_SHIFT(o.dst,o.value,o.flags,o.shift); break;
	case 3: X86_SIM_L_EXEC_MOV_IMM_AUX(o.dst,o.flags,o.aux,o.value); break;
	case 4: X86_SIM_L_EXEC_MOV_REG_AUX(o.dst,o.src,o.flags,o.aux); break;
	case 5: X86_SIM_L_EXEC_MOVX_REG(o.op,o.dst,o.src,o.flags,o.aux); break;
	default: abort();
	}
#define SAVE(I) do { *facts[I].tag=X86_SIM_L_SV_TAG(I); *facts[I].pointer=X86_SIM_L_SV_PTR(I); } while(0);
	X86_SIM_L_SV_EACH(SAVE)
#undef SAVE
	return result;
}
static void equal_state(struct x86_sim_register_state *a, struct x86_sim_register_state *b)
{
#define REG(R,N) check(a->N.ptr==b->N.ptr && a->N##_tag==b->N##_tag, #N);
	X86_SIM_L_FOR_EACH_GPR(REG)
#undef REG
#define FIELD(N) check(a->N==b->N,#N)
	FIELD(native_stack_base); FIELD(cf); FIELD(zf); FIELD(sf); FIELD(of); FIELD(pf); FIELD(af);
	FIELD(xmm0_lo); FIELD(xmm0_hi); FIELD(ret_addr); FIELD(call_depth);
	FIELD(skb_ctx); FIELD(helper_ctx); FIELD(is_xdp); FIELD(helper_abi_base); FIELD(abi_kind);
#undef FIELD
	check(!memcmp(&a->xdp_abi,&b->xdp_abi,sizeof(a->xdp_abi)),"XDP ABI frame");
	check(!memcmp(&a->skb_abi,&b->skb_abi,sizeof(a->skb_abi)),"SKB ABI frame");
}
int main(void)
{
	enum { words=KPROG_X86_STACK_WORDS(PROFILE), extent=(PROFILE+7U)&~7U };
	__u8 *bytes=malloc(extent+16); if(!bytes) return 1;
	struct kprog_x86_arena arena={bytes,(volatile __u64 *)(void *)bytes};
	__u8 tags[words],saved_tags[words],initial_tags[words],initial_bytes[extent+16],saved_bytes[extent+16];
	void *pointers[words],*saved_pointers[words],*initial_pointers[words];
	struct scattered { __u64 before; void *pointer; __u64 middle; __u8 tag; __u64 after; } scattered[words];
	struct kprog_x86_stack_fact facts[words];
	const __u8 widths[]={1,2,4,8,0,255};
	const __u64 values[]={0,1,~0ULL,0x8000000000000000ULL,0x12345678ffffffffULL,0xfedcba9876543210ULL};
	const __s64 offsets[]={0,-PROFILE,-1,1,(-0x7fffffffffffffffLL-1),0x7fffffffffffffffLL};
	for(unsigned layout=0;layout<2;layout++) for(unsigned kind=0;kind<6;kind++)
	for(unsigned dst=0;dst<17;dst++) for(unsigned src=0;src<21;src++)
	for(unsigned wi=0;wi<6;wi++) for(unsigned lane=0;lane<4;lane++) {
		__u64 seed=0x9e3779b97f4a7c15ULL*(cases+1);
		struct x86_sim_register_state initial,a,b;
		memset(&initial,0xa5,sizeof(initial));
#define INIT(R,N) initial.N.ptr=(void *)(uintptr_t)(seed^((__u64)(R)*0x123456789ULL)); initial.N##_tag=(__u8)(cases+(R)*17);
		X86_SIM_L_FOR_EACH_GPR(INIT)
#undef INIT
		initial.rsp.ptr=(void *)(uintptr_t)offsets[(cases+wi)%6];
		initial.native_stack_base=seed^0xfedcba9876543210ULL;
		for(unsigned i=0;i<sizeof(initial_bytes);i++) initial_bytes[i]=(__u8)(seed+i*17);
		for(unsigned i=0;i<words;i++) {
			initial_tags[i]=(__u8)(seed+i*31); initial_pointers[i]=(void *)(uintptr_t)(seed+i*8);
			scattered[i].before=seed; scattered[i].middle=~seed; scattered[i].after=seed^0x55aa;
			facts[i].tag=layout?&scattered[i].tag:&tags[i];
			facts[i].pointer=layout?&scattered[i].pointer:&pointers[i];
		}
		struct operation o={kind,kind==0?(wi&1?X86_OP_MOV_LOAD_HELPER_ID:X86_OP_MOV_LOAD_MAP_PTR):wi&1?X86_OP_MOVSX_REG:X86_OP_MOVZX_REG,
			dst==16?255:dst,src==20?255:src>=16?128+src-16:src,widths[wi],(lane&1)*8,
			((lane&1)*8U<<16)|((lane>>1)*8U<<24)|(lane&1),values[(cases+lane)%6]};
		a=initial; memcpy(bytes,initial_bytes,sizeof(initial_bytes));
		for(unsigned i=0;i<words;i++){*facts[i].tag=initial_tags[i];*facts[i].pointer=initial_pointers[i];}
		draws=0; entropy=seed; __u64 ar=generic(&a,&arena,facts,o); unsigned ad=draws; __u64 ae=entropy;
		memcpy(saved_bytes,bytes,sizeof(saved_bytes));
		for(unsigned i=0;i<words;i++){saved_tags[i]=*facts[i].tag;saved_pointers[i]=*facts[i].pointer;}
		b=initial; memcpy(bytes,initial_bytes,sizeof(initial_bytes));
		for(unsigned i=0;i<words;i++){*facts[i].tag=initial_tags[i];*facts[i].pointer=initial_pointers[i];}
		draws=0; entropy=seed; __u64 br=native(&b,&arena,facts,o);
		check(ar==br && ad==draws && ae==entropy,"result/free-input stream"); equal_state(&a,&b);
		free_draws+=ad;
		check(!memcmp(saved_bytes,bytes,sizeof(saved_bytes)),"private bytes/guard frame");
		for(unsigned i=0;i<words;i++) {
			check(saved_tags[i]==*facts[i].tag && saved_pointers[i]==*facts[i].pointer,"fact transport/frame");
			check(scattered[i].before==seed && scattered[i].middle==~seed && scattered[i].after==(seed^0x55aa),"fact descriptor guard");
		}
		cases++;
	}
	free(bytes);
	check(free_draws>0,"stack-release paths exercised");
	printf("x86 capacity %u scalar %u: %lu full storage/stream comparisons, %lu free draws\n",PROFILE,SCALAR_FACTS,cases,free_draws);
	return 0;
}
