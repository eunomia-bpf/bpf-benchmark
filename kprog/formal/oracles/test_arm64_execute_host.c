/* Catch dispatcher/storage/vector binding and callback-order drift against
 * historical C. Every captured byte is compared; no observation mask is used. */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "../c/Arm64Addressing.h"

static jmp_buf rejected;
static unsigned events[512],count,selector_mode,failures;
static __u64 values[512],entropy;
static void check(int ok,const char *why)
{ if (!ok) { fprintf(stderr,"ARM execute: %s\n",why);exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	check(count<512,"input overflow");
	entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;
	__u64 value=kind==1?0x10000:kind==3?0x20000:entropy;
	check(kind==1 || kind==3 || kind==6,"unexpected input");
	events[count]=kind;values[count++]=value;return value;
}
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{ (void)site;check(0,"unselected exclusive input");return 0; }
void arm64_sim_unsupported_opcode(void)
{ failures++;if (!selector_mode) longjmp(rejected,1); }
void kprog_c_trap(void) { check(0,"unselected platform trap");abort(); }
void *kprog_c_context_pointer(const void *ctx,__u8 kind,__u32 offset)
{ (void)ctx;(void)kind;(void)offset;check(0,"unselected context input");return NULL; }
__u64 kprog_c_pointer_bits(const void *p)
{ (void)p;check(0,"unselected pointer exposure");return 0; }
__u64 kprog_c_atomic_fetch(void *p,__u64 v,__u32 w,__u32 op,__u32 order)
{ (void)p;(void)v;(void)w;(void)op;(void)order;check(0,"unselected atomic");return 0; }
void __builtin_memcpy_aligned(void *dst,const void *src,size_t n,size_t a)
{ check(a==1,"copy alignment");memcpy(dst,src,n); }

static __u64 observe(unsigned event,__u64 value)
{ check(count<512,"selector event overflow");events[count++]=event;return value; }
static void selectors(void)
{
	selector_mode=1;
	const __u64 widths[]={0,1,2,4,8,256,0x100000008ULL},shifts[]={0,16,32,48,1,63};
	for (unsigned op=0;op<80;op++) for (unsigned wi=0;wi<7;wi++) {
		__u64 result;count=failures=0;
		KPROG_ARM64_MOV_PTR_TAG_PATH_INTO(result,observe(1,op),observe(2,widths[wi]),arm64_sim_unsupported_opcode());
		check(count==2 && events[0]==1 && events[1]==2 && failures==(op!=1 && op!=2) && result==(op==2 && widths[wi]==8),"MOV raw capture/selection");
		failures=0;check(kprog_arm64_mov_path(op,widths[wi])==result && failures==(op!=1 && op!=2),"actual MOV selector root");
		count=failures=0;
		KPROG_ARM64_CSEL_PTR_TAG_PATH_INTO(result,observe(1,op),observe(2,widths[wi]),arm64_sim_unsupported_opcode());
		unsigned legal=op==28 || op==29 || op==30 || op==52 || op==61 || op==62 || op==68 || op==69;
		check(count==2 && events[0]==1 && events[1]==2 && failures==!legal && result==(op==28 && widths[wi]==8),"CSEL full capture/selection");
		failures=0;check(kprog_arm64_csel_path(op,widths[wi])==result && failures==!legal,"actual CSEL selector root");
		count=0;KPROG_ARM64_FLAG_RHS_INTO(result,observe(1,op),observe(2,0x123456789abcdef0ULL),observe(3,~0ULL));
		unsigned immediate=op==48 || op==49 || op==22 || op==24 || op==55 || op==26;
		check(count==2+immediate && events[0]==3 && events[1]==1 && (!immediate || events[2]==2) && result==(immediate?0x123456789abcdef0ULL:~0ULL),"flag operand eager register/lazy immediate");
		check(kprog_arm64_flag_rhs(op,0x123456789abcdef0ULL,~0ULL)==result,"actual flag operand root");
		check(kprog_arm64_alu_source(op)==(op==3 || op==4 || op==6),"ALU source selector");
	}
	/* Preserve raw flag values, repeated condition evaluation and short circuit
	 * reads; booleanizing EQ/CS/MI/VS would silently change this C interface. */
	for (unsigned cond=0;cond<17;cond++) for (unsigned raw=0;raw<4;raw++) {
		const int flags[]={0,1,2,255};int n=flags[raw],z=flags[(raw+1)%4],c=flags[(raw+2)%4],v=flags[(raw+3)%4];
		int expected[]={z,!z,c,!c,n,!n,v,!v,c&&!z,!c||z,n==v,n!=v,!z&&(n==v),z||(n!=v),1,0,0};
		int result;count=failures=0;
		KPROG_ARM64_EVAL_COND_INTO(result,observe(1,cond),n,z,c,v,arm64_sim_unsupported_opcode());
		check(result==expected[cond] && count==(cond<15?cond+1:15) && failures==(cond>=15),"condition raw flags/repeated selection");
	}
	for (unsigned s=0;s<6;s++) {
		unsigned shift=shifts[s];__u64 result,mask=s<4?0xffffULL<<shift:0;count=failures=0;
		KPROG_ARM64_MOVK_INSERT_INTO(result,observe(1,~0ULL),observe(2,0x12345678ULL),observe(3,shift),arm64_sim_unsupported_opcode());
		check(count==3 && events[0]==1 && events[1]==2 && events[2]==3 && failures==(s>=4) && result==((~0ULL&~mask)|((0x12345678ULL<<shift)&mask)),"MOVK capture/column/unsupported");
		failures=0;check(kprog_arm64_movk(~0ULL,0x12345678ULL,shift)==result && failures==(s>=4),"actual MOVK root");
	}
	for (unsigned b=0;b<256;b++) for (unsigned lane=0;lane<8;lane++) {
		__u64 value=(__u64)b<<(lane*8),ones=0;for (unsigned bit=0;bit<8;bit++) ones+=(b>>bit)&1;
		check(kprog_arm64_reduction(ARM64_OP_CNT,value)==ones<<(lane*8),"every byte/lane CNT");
		check(kprog_arm64_reduction(ARM64_OP_UADDLV,value)==b,"every byte/lane UADDLV");
	}
	selector_mode=0;
}
struct frame {
	struct kprog_arm64_coordinates coordinates;
	union arm64_sim_gpr registers[31];
	__u8 tags[31],flags[4];
	_Alignas(8) __u8 bytes[512],stack_tags[48];
	__u64 payload[48];
	struct kprog_arm64_vector vectors[32];
};
_Static_assert(offsetof(struct kprog_arm64_vector,lo)==0 && offsetof(struct kprog_arm64_vector,hi)==8 && sizeof(struct kprog_arm64_vector[32])==512,"production vector cell layout/stride");
static struct frame f;
static void lazy_flags(void)
{
	memset(&f,0,sizeof(f));f.registers[1].x=17;f.registers[2].x=23;
	struct kprog_arm64_addressing a={&f.coordinates,f.registers,f.tags,f.bytes,f.stack_tags,f.payload,1,0,NULL,NULL,0,ARM64_SIM_ABI_KIND_RAW,(void *)f.bytes};
	__u8 z=2;count=failures=0;
	if (setjmp(rejected)) check(0,"valid lazy condition rejected");
	kprog_arm64_execute(&a,f.vectors,NULL,&z,NULL,NULL,ARM64_OP_CSEL,0,1,2,255,4,ARM64_COND_EQ,0);
	check(f.registers[0].x==17 && !count && !failures && z==2,"EQ reads only Z");
	kprog_arm64_execute(&a,f.vectors,NULL,NULL,NULL,NULL,ARM64_OP_CSEL,0,1,2,255,4,ARM64_COND_AL,0);
	check(f.registers[0].x==17 && !count && !failures,"AL reads no flags");
}
int main(int argc,char **argv)
{
	check(argc==1 || (argc==2 && !strcmp(argv[1],"--capture")),"arguments");
	int capture=argc==2;
	selectors();
	lazy_flags();
	const unsigned ops[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,35,36,37,38,39,44,45,46,47,48,49,50,51,52,53,55,58,59,60,61,62,64,65,66,67,68,69,255,256};
	const unsigned capacities[]={1,7,9,160,200,376};const __s64 biases[]={0,-3,4,96,160,280};
	const unsigned regs[]={0,1,15,30,31,32,255};const __u64 data[]={0,1,0xffffffffULL,0xffffffffffffffffULL,0x8000000000000000ULL,0x123456789abcdef0ULL};
	unsigned cases=0;
	for (unsigned p=0;p<6;p++) for (unsigned oi=0;oi<sizeof(ops)/sizeof(ops[0]);oi++) for (unsigned variant=0;variant<12;variant++) {
		unsigned op=ops[oi],width=variant&1?4:8;__u32 aux=ARM64_AUX_ALU(variant%6,ARM64_MOD_LSL,variant%2);
		if (op==5) aux=ARM64_AUX_MOVK(16*(variant%4));
		if (op==8 || op==9) aux=variant%4;
		if (op==18) aux=ARM64_AUX_BITFIELD(variant%5,variant%4,1+variant%16);
		if (op==26 || op==27) aux=ARM64_AUX_CCMP(variant%16,variant);
		if (op==28 || op==29 || op==30 || op==52 || op==61 || op==62 || op==65 || op==68 || op==69) aux=variant;
		if (op==35) aux=variant%4;
		if (op==36 || op==37) aux=variant&1?16:8;
		memset(&f,0,sizeof(f));entropy=0x123456789abcdef0ULL^cases;
		f.coordinates=(struct kprog_arm64_coordinates){0x10000,0x20000,0,variant%2,(variant/2)%2};
		for (unsigned i=0;i<31;i++) { f.tags[i]=variant%3==0?4:variant%3==1?10:0;f.registers[i].x=f.tags[i]==4?(__u64)-16:data[(variant+i)%6]; }
		for (unsigned i=0;i<512;i++) f.bytes[i]=(__u8)(i*17+variant);
		for (unsigned i=0;i<48;i++) { f.stack_tags[i]=(i%3)?4:10;f.payload[i]=0x123456789abcdef0ULL^i; }
		for (unsigned i=0;i<32;i++) { f.vectors[i].lo=data[(variant+i)%6];f.vectors[i].hi=~f.vectors[i].lo; }
		f.flags[0]=variant&1;f.flags[1]=(variant>>1)&1;f.flags[2]=(variant>>2)&1;f.flags[3]=(variant>>3)&1;
		if (variant==11) { f.flags[0]=255;f.flags[1]=2;f.flags[2]=255;f.flags[3]=2; }
		struct kprog_arm64_addressing a={&f.coordinates,f.registers,f.tags,f.bytes,f.stack_tags,f.payload,capacities[p],biases[p],NULL,NULL,0,ARM64_SIM_ABI_KIND_RAW,(void *)f.bytes};
		count=failures=0;int trapped=setjmp(rejected);
		if (!trapped) kprog_arm64_execute(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],op,regs[variant%7],regs[(variant+1)%7],regs[(variant+2)%7],regs[(variant+3)%7],width,aux,variant%64);
		const __u32 header[]={op,variant,capacities[p],count,!!trapped,failures};
		if (capture) check(fwrite(header,sizeof(header),1,stdout)==1 && fwrite(&f,sizeof(f),1,stdout)==1 && fwrite(events,sizeof(events[0]),count,stdout)==count && fwrite(values,sizeof(values[0]),count,stdout)==count,"frame capture write");cases++;
	}
	fprintf(stderr,"ARM execute: %u complete frames, frame_bytes=%zu; selectors/CNT lanes pass\n",cases,sizeof(f));
	return 0;
}
