/* Detect lost lazy coordinate inputs, immediate/index routing, helper pointer
 * identity, pre/post byte/tag release, and metadata/payload frame damage. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#define ARM64_SIM_ENABLE_STACK 1
#include "../c/Arm64Addressing.h"
static unsigned requests[512],count;
static __u64 entropy;
static unsigned long cases;
static jmp_buf rejected;
static int allow_reject;
static const __u64 sp_input=0xfedcba9876543210ULL,ret_input=0x123456789abcdef0ULL;
static __u64 fresh(__u64 *s){*s^=*s<<13;*s^=*s>>7;*s^=*s<<17;return *s;}
unsigned long native_lab_entry_input(unsigned kind)
{
	if(count==512) abort();requests[count++]=kind;
	if(kind==1) return sp_input;if(kind==3) return ret_input;
	if(kind!=6) abort();return fresh(&entropy);
}
void arm64_sim_unsupported_opcode(void){if(allow_reject) longjmp(rejected,1);abort();}
static void check(int ok,const char *what)
{
	if(!ok){fprintf(stderr,"ARM addressing case %lu: %s\n",cases,what);exit(1);}
}
static void coordinates_equal(struct kprog_arm64_coordinates a,struct kprog_arm64_coordinates b)
{
	check(a.sp_base==b.sp_base && a.return_base==b.return_base && a.stack_offset==b.stack_offset && a.sp_valid==b.sp_valid && a.return_valid==b.return_valid,"coordinate cache/frame");
}
static unsigned wanted[512],wanted_count;
static __u64 materialize(struct kprog_arm64_coordinates *c,__u64 value,unsigned tag)
{
	if(tag==4){if(!c->sp_valid){c->sp_base=sp_input;c->sp_valid=1;wanted[wanted_count++]=1;}return value+c->sp_base;}
	if(tag==10){if(!c->return_valid){c->return_base=ret_input;c->return_valid=1;wanted[wanted_count++]=3;}return value+c->return_base;}
	return value;
}
static __u64 read_value(struct kprog_arm64_coordinates *c,union arm64_sim_gpr *r,__u8 *t,__u64 reg)
{
	return materialize(c,reg==32?(__u64)c->stack_offset:reg<31?r[reg].x:0,reg==32?4:reg<31?t[reg]:0);
}
static void inputs_equal(void)
{
	check(count==wanted_count && !memcmp(requests,wanted,count*sizeof(unsigned)),"input identity/order/laziness");
}
int main(void)
{
	__u64 storage[64],before_storage[64],packed[8],before_packed[8],payload[64],before_payload[64];
	union arm64_sim_gpr regs[31],before_regs[31];__u8 tags[31],before_tags[31];
	__u8 *bytes=(__u8 *)storage,*stack_tags=(__u8 *)packed;
	const __u64 ids[]={0,15,30,31,32,33,255,256,0x100000020ULL,~0ULL};
	const __u8 valid[]={0,1,2,255},widths[]={1,2,4,8,0,255},shifts[]={0,1,31,63};
	const __u64 values[]={0,1,~0ULL,0x8000000000000000ULL,0x12345678ffffffffULL,0xfedcba9876543210ULL};
	const __u32 modes[]={0,1,2,3,255};
	struct kprog_arm64_coordinates c;
	struct kprog_arm64_addressing a={&c,regs,tags,bytes,stack_tags,payload,160,96,bytes+128,bytes+192,0,0,storage};
	for(unsigned mod=0;mod<12;mod++) for(unsigned si=0;si<4;si++) for(unsigned ri=0;ri<10;ri++)
	for(unsigned tag=0;tag<256;tag++) for(unsigned variant=0;variant<2;variant++) {
		__u64 seed=0x9e3779b97f4a7c15ULL*(cases+1),reg=ids[ri];
		__u8 width=widths[cases%6],modifier=mod==11?255:mod;
		a.capacity=cases%3==0?64:cases%3==1?160:376;a.bias=cases%3==0?0:cases%3==1?96:0x100000100LL;
		c=(struct kprog_arm64_coordinates){seed,~seed,-a.bias+16,valid[cases%4],valid[(cases/4)%4]};
		struct kprog_arm64_coordinates want=c;
		a.is_xdp=valid[(cases/7)%4];a.abi_kind=valid[(cases/11)%4];
		for(unsigned i=0;i<31;i++){tags[i]=tag;regs[i].x=tag==4?(__u64)(-a.bias+32):tag==1?(uintptr_t)((__u8 *)a.helper_abi_base+(variant?8:0)):values[(cases+i)%6];}
		for(unsigned i=0;i<sizeof(storage);i++) bytes[i]=seed+i*17;
		for(unsigned i=0;i<sizeof(packed);i++) stack_tags[i]=seed+i*31;
		for(unsigned i=0;i<64;i++) payload[i]=seed^((__u64)i*0x123456789ULL);
		memcpy(before_storage,storage,sizeof(storage));memcpy(before_packed,packed,sizeof(packed));memcpy(before_payload,payload,sizeof(payload));memcpy(before_regs,regs,sizeof(regs));memcpy(before_tags,tags,sizeof(tags));
		count=wanted_count=0;entropy=seed;
		__u64 raw=read_value(&want,regs,tags,reg);
		__u64 expected=KPROG_ARM64_MOD_VALUE(modifier,raw,shifts[si],width);
		check(kprog_arm64_modified_reg(&a,reg,modifier,shifts[si],width)==expected,"modified register transport");coordinates_equal(c,want);inputs_equal();
		__u32 mode=modes[cases%5],aux=(mode<<24)|((__u32)shifts[si]<<16)|((__u32)modifier<<8);
		__u64 imm=values[(cases+variant)%6],index=0;
		if(reg!=255){raw=read_value(&want,regs,tags,reg);index=KPROG_ARM64_MOD_VALUE(modifier,raw,shifts[si],8);}
		__u64 offset=((mode&3)?0:imm)+index;
		check(kprog_arm64_memory_offset(&a,aux,reg,imm)==(__s64)offset,"index/sentinel/immediate/suppression/wrap");coordinates_equal(c,want);inputs_equal();
		unsigned source_tag=reg==32?4:reg<31?tags[reg]:0;
		void *pointer=reg==32?(void *)(uintptr_t)c.stack_offset:reg<31?regs[reg].ptr:NULL;
		void *arg=source_tag==4?(void *)(bytes+((__s64)(uintptr_t)pointer+a.bias)):pointer;
		check(kprog_arm64_helper_argument(&a,reg)==arg,"helper arena/pointer identity");
		void *ctx=source_tag==1?(pointer==a.helper_abi_base?a.helper_context:pointer):arg;
		check(kprog_arm64_helper_context(&a,reg)==ctx,"helper base-only context substitution");coordinates_equal(c,want);inputs_equal();
		unsigned result_tag=0;
		if(reg==32 || source_tag==4){unsigned at=reg==32?16:32;result_tag=width==8?stack_tags[at/8]:0;}
		else if(source_tag==1 && width==8){
			if(a.abi_kind==2) result_tag=1;
			else {__s64 off=(a.is_xdp || a.abi_kind==1)?(__s64)((uintptr_t)pointer-(uintptr_t)(a.is_xdp?a.helper_context:a.helper_abi_base)):0;
			if((a.abi_kind==0 && off==0)||(a.abi_kind==1 && off==208))result_tag=2;
			else if((a.abi_kind==0 && off==8)||(a.abi_kind==1 && off==80))result_tag=3;}
		} else if(source_tag==7 && width==8) result_tag=5;
		check(kprog_arm64_memory_tag(&a,reg,255,0,0,0,width)==result_tag,"stack/ABI/relocation tag routing");
		check(kprog_arm64_memory_payload(&a,32,255,0,0,0,seed,tag)==(tag==4 || tag==10?payload[2]:seed),"payload recovery and identity arm");
		coordinates_equal(c,want);inputs_equal();check(entropy==seed,"read/address path drew free input");
		check(!memcmp(regs,before_regs,sizeof(regs)) && !memcmp(tags,before_tags,sizeof(tags)),"register/tag read frame");
		check(!memcmp(storage,before_storage,sizeof(storage)) && !memcmp(packed,before_packed,sizeof(packed)) && !memcmp(payload,before_payload,sizeof(payload)),"private storage/padding/payload read frame");cases++;
	}
	for(unsigned base_i=0;base_i<3;base_i++) for(unsigned mode=0;mode<4;mode++) for(unsigned post=0;post<2;post++) for(unsigned delta_i=0;delta_i<3;delta_i++) {
		__u64 base=base_i==0?32:base_i==1?15:255,seed=0x123456789abcdefULL;__s64 delta=delta_i==0?0:delta_i==1?8:-8;
		c=(struct kprog_arm64_coordinates){seed,~seed,-80,2,255};struct kprog_arm64_coordinates want=c;
		a.capacity=160;a.bias=96;
		for(unsigned i=0;i<31;i++){regs[i].ptr=bytes+64;tags[i]=i;}
		for(unsigned i=0;i<sizeof(storage);i++) bytes[i]=i*17;for(unsigned i=0;i<sizeof(packed);i++)stack_tags[i]=i+5;
		memcpy(before_storage,storage,sizeof(storage));memcpy(before_packed,packed,sizeof(packed));memcpy(before_regs,regs,sizeof(regs));memcpy(before_tags,tags,sizeof(tags));
		unsigned selected=(mode&(post?2:1))!=0;__s64 step=selected?delta:0;__u64 expected_entropy=seed;count=wanted_count=0;entropy=seed;
		if(base==32){want.stack_offset+=step;if(step>0){for(unsigned i=16;i<24;i++){((__u8 *)before_storage)[i]=(__u8)fresh(&expected_entropy);wanted[wanted_count++]=6;}((__u8 *)before_packed)[2]=0;}}
		else if(base<31 && step){before_regs[base].ptr=bytes+64+step;}
		if(post)kprog_arm64_memory_post(&a,base,mode<<24,(__u64)delta);else kprog_arm64_memory_pre(&a,base,mode<<24,(__u64)delta);
		coordinates_equal(c,want);inputs_equal();check(entropy==expected_entropy,"writeback released input stream");
		check(!memcmp(regs,before_regs,sizeof(regs)) && !memcmp(tags,before_tags,sizeof(tags)),"writeback register/tag frame");
		check(!memcmp(storage,before_storage,sizeof(storage)) && !memcmp(packed,before_packed,sizeof(packed)),"writeback byte/packed-tag frame");cases++;
	}
	/* A zero GPR is still an address word; writeback must not use host null GEP. */
	c.stack_offset=-80;regs[15].ptr=NULL;tags[15]=4;count=0;
	kprog_arm64_memory_post(&a,15,2U<<24,8);
	check((uintptr_t)regs[15].ptr==8 && tags[15]==4 && !count,"zero-word GPR writeback");cases++;
	/* Alignment rejection precedes every pre writeback, including delta0. */
	for(unsigned mode=0;mode<4;mode++) for(unsigned delta=0;delta<2;delta++) {
		c.stack_offset=-79;struct kprog_arm64_coordinates prior=c;allow_reject=1;count=0;
		memcpy(before_storage,storage,sizeof(storage));memcpy(before_packed,packed,sizeof(packed));
		if(setjmp(rejected)==0){kprog_arm64_memory_pre(&a,32,mode<<24,delta?8:0);check(0,"missing pre alignment rejection");}
		allow_reject=0;coordinates_equal(c,prior);check(!count,"alignment rejection requested input");
		check(!memcmp(storage,before_storage,sizeof(storage)) && !memcmp(packed,before_packed,sizeof(packed)),"alignment rejection changed frame");cases++;
	}
	regs[15].ptr=bytes+64;tags[15]=7;allow_reject=1;count=0;
	if(setjmp(rejected)==0){(void)kprog_arm64_memory_tag(&a,15,255,0,1,0,8);check(0,"missing relocation-offset rejection");}
	allow_reject=0;check(!count,"relocation rejection requested input");cases++;
	/* Non-pointer payload arms must not fetch a cold return-coordinate index. */
	c.return_valid=0;regs[0].x=0x8000000000000001ULL;tags[0]=10;count=0;
	check(kprog_arm64_memory_payload(&a,32,0,0,0,0,0x123456789abcdef0ULL,255)==0x123456789abcdef0ULL,"payload identity value");
	check(!count && !c.return_valid,"eager payload index/cache request");cases++;
	printf("ARM address consumers: %lu coordinate/routing/frame/error cases\n",cases);
	return 0;
}
