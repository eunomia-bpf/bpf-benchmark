/* Catch fixed-capacity/bias extraction, dropped packed-tag padding, and changed
 * lazy/free-input ordering by comparing the canonical bodies at each profile. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PROFILE
#error PROFILE must select the canonical arena capacity
#endif
#ifndef BIAS
#error BIAS must select the canonical stack coordinate bias
#endif
#define ARM64_SIM_ENABLE_STACK 1
#define ARM64_SIM_STACK_BYTES PROFILE
#define ARM64_SIM_STACK_BIAS BIAS
#include "../c/Arm64Address.h"
#undef ARM64_SIM_L_UNSPECIFIED
#define ARM64_SIM_L_UNSPECIFIED() NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED)

static unsigned requests[512], count;
static __u64 entropy;
static unsigned long cases, free_draws;
static const __u64 input_sp=0xfedcba9876543210ULL, input_return=0x123456789abcdef0ULL;
unsigned long native_lab_entry_input(unsigned kind)
{
	if (count==512) abort();
	requests[count++]=kind;
	if(kind==1) return input_sp;
	if(kind==3) return input_return;
	if(kind!=NATIVE_LAB_INPUT_UNSPECIFIED) abort();
	entropy^=entropy<<13; entropy^=entropy>>7; entropy^=entropy<<17;
	return entropy;
}
void arm64_sim_unsupported_opcode(void) { abort(); }
static void check(int ok, const char *what)
{
	if(!ok) { fprintf(stderr,"ARM profile=%u bias=%lld case=%lu: %s\n",PROFILE,(__s64)BIAS,cases,what); exit(1); }
}
struct operation { unsigned kind; __u64 reg,value; __u8 tag,width; };
static void generic(struct kprog_arm64_coordinates *c, union arm64_sim_gpr *r,
                    __u8 *t, volatile __u8 *bytes, __u8 *facts, struct operation o)
{
	switch(o.kind) {
	case 0: kprog_arm64_write_ptr(c,r,t,bytes,facts,PROFILE,BIAS,o.reg,(void *)(uintptr_t)o.value,o.tag); break;
	case 1: kprog_arm64_write_reg(c,r,t,bytes,facts,PROFILE,BIAS,o.reg,o.value,o.width); break;
	case 2: kprog_arm64_exec_adrp(c,r,t,bytes,facts,PROFILE,BIAS,ARM64_OP_ADRP_GOT,o.reg,o.value); break;
	case 3: kprog_arm64_exec_adrp(c,r,t,bytes,facts,PROFILE,BIAS,ARM64_OP_ADRP_RODATA,o.reg,o.value); break;
	default: abort();
	}
}
static void canonical(struct kprog_arm64_coordinates *c, union arm64_sim_gpr *r,
                       __u8 *t, volatile __u8 *bytes, __u8 *facts, struct operation o)
{
#define __a64_numeric_sp (c->sp_base)
#define __a64_numeric_return (c->return_base)
#define __a64_numeric_sp_valid (c->sp_valid)
#define __a64_numeric_return_valid (c->return_valid)
#define __a64_sp (c->stack_offset)
#define __a64_stack_tag facts
#define CELL(REG,NAME) [KPROG_ARM64_GPR_CELL(REG)] = &r[KPROG_ARM64_GPR_CELL(REG)],
#define TAG(REG,NAME) [KPROG_ARM64_GPR_CELL(REG)] = &t[KPROG_ARM64_GPR_CELL(REG)],
	union arm64_sim_gpr *const __a64_cells[KPROG_ARM64_GPR_COUNT]={ARM64_SIM_L_FOR_EACH_GPR(CELL)};
	__u8 *const __a64_tag_cells[KPROG_ARM64_GPR_COUNT]={ARM64_SIM_L_FOR_EACH_GPR(TAG)};
	struct { volatile __u8 *b; } __a64_stack={bytes};
	switch(o.kind) {
	case 0: ARM64_SIM_L_WRITE_REG_PTR_TAG(o.reg,(void *)(uintptr_t)o.value,o.tag); break;
	case 1: ARM64_SIM_L_WRITE_REG_WIDTH(o.reg,o.value,o.width); break;
	case 2: ARM64_SIM_L_EXEC_ADRP(ARM64_OP_ADRP_GOT,o.reg,o.value); break;
	case 3: ARM64_SIM_L_EXEC_ADRP(ARM64_OP_ADRP_RODATA,o.reg,o.value); break;
	default: abort();
	}
#undef __a64_numeric_sp
#undef __a64_numeric_return
#undef __a64_numeric_sp_valid
#undef __a64_numeric_return_valid
#undef __a64_sp
#undef __a64_stack_tag
#undef CELL
#undef TAG
}
static void equal_coordinates(struct kprog_arm64_coordinates a, struct kprog_arm64_coordinates b)
{
	check(a.sp_base==b.sp_base && a.return_base==b.return_base && a.stack_offset==b.stack_offset &&
	      a.sp_valid==b.sp_valid && a.return_valid==b.return_valid,"coordinate/frame");
}
int main(void)
{
	const __u64 reg_ids[]={0,15,30,31,32,33,255,256,0x100000020ULL,~0ULL};
	const __u8 widths[]={1,2,4,8,0,255}, valid[]={0,1,2,255};
	const __s64 offsets[]={-(__s64)BIAS-1,-(__s64)BIAS,-1,0,PROFILE-(__s64)BIAS-1,(-0x7fffffffffffffffLL-1),0x7fffffffffffffffLL};
	const __s64 targets[]={-(__s64)BIAS-1,-(__s64)BIAS,-35,-1,0,PROFILE-(__s64)BIAS,(-0x7fffffffffffffffLL-1),0x7fffffffffffffffLL};
	enum { tag_bytes=ARM64_SIM_TAG_STORAGE_BYTES(PROFILE) };
	__u8 bytes[PROFILE+16],initial_bytes[sizeof(bytes)],saved_bytes[sizeof(bytes)];
	__u64 facts_storage[tag_bytes/8+2];
	__u8 *facts=(__u8 *)facts_storage, initial_facts[sizeof(facts_storage)],saved_facts[sizeof(facts_storage)];
	union arm64_sim_gpr regs[31],initial_regs[31],saved_regs[31];
	__u8 tags[31],initial_tags[31],saved_tags[31];
	for(unsigned kind=0;kind<4;kind++) for(unsigned ri=0;ri<10;ri++)
	for(unsigned wi=0;wi<6;wi++) for(unsigned vi=0;vi<4;vi++) for(unsigned tag=0;tag<256;tag++) {
		__u64 seed=0x9e3779b97f4a7c15ULL*(cases+1);
		struct kprog_arm64_coordinates initial={seed,~seed,offsets[(cases+wi)%7],valid[vi],valid[(vi+wi)%4]};
		__u64 base=initial.sp_valid?initial.sp_base:input_sp, ret=initial.return_valid?initial.return_base:input_return;
		__u64 value=(__u64)targets[(cases+wi)%8]+base;
		if(kind==0) value=(__u64)targets[(cases+wi)%8]+(tag==4?0:base)-(tag==10?ret:0);
		struct operation o={kind,reg_ids[ri],value,tag,widths[wi]};
		for(unsigned i=0;i<31;i++){initial_regs[i].x=seed^((__u64)i*0x123456789ULL);initial_tags[i]=tag+i;}
		for(unsigned i=0;i<sizeof(bytes);i++) initial_bytes[i]=seed+i*17;
		for(unsigned i=0;i<sizeof(facts_storage);i++) initial_facts[i]=seed+i*31;
		memcpy(regs,initial_regs,sizeof(regs));memcpy(tags,initial_tags,sizeof(tags));
		memcpy(bytes,initial_bytes,sizeof(bytes));memcpy(facts,initial_facts,sizeof(facts_storage));
		struct kprog_arm64_coordinates a=initial,b=initial;
		count=0;entropy=seed;generic(&a,regs,tags,bytes,facts,o);
		unsigned ac=count,saved_requests[512];memcpy(saved_requests,requests,ac*sizeof(unsigned));__u64 ae=entropy;
		for(unsigned i=0;i<ac;i++) free_draws+=requests[i]==NATIVE_LAB_INPUT_UNSPECIFIED;
		memcpy(saved_regs,regs,sizeof(regs));memcpy(saved_tags,tags,sizeof(tags));
		memcpy(saved_bytes,bytes,sizeof(bytes));memcpy(saved_facts,facts,sizeof(facts_storage));
		memcpy(regs,initial_regs,sizeof(regs));memcpy(tags,initial_tags,sizeof(tags));
		memcpy(bytes,initial_bytes,sizeof(bytes));memcpy(facts,initial_facts,sizeof(facts_storage));
		count=0;entropy=seed;canonical(&b,regs,tags,bytes,facts,o);
		equal_coordinates(a,b);check(ac==count && ae==entropy && !memcmp(saved_requests,requests,ac*sizeof(unsigned)),"input identity/order/stream");
		check(!memcmp(saved_regs,regs,sizeof(regs)) && !memcmp(saved_tags,tags,sizeof(tags)),"registers/tags/frame");
		check(!memcmp(saved_bytes,bytes,sizeof(bytes)),"private bytes/guard frame");
		check(!memcmp(saved_facts,facts,sizeof(facts_storage)),"packed facts/padding/guard frame");
		cases++;
	}
	check(free_draws>0,"release paths exercised");
	printf("ARM capacity %u bias %lld: %lu full storage/stream comparisons, %lu free draws\n",PROFILE,(__s64)BIAS,cases,free_draws);
	return 0;
}
