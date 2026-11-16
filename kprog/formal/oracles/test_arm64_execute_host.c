/* Catch dispatcher/storage/vector binding and callback-order drift against
 * historical C. Every captured byte is compared; no observation mask is used. */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdarg.h>
#include "../c/Arm64Addressing.h"

/* Compile-time ABI regression: every callee parameter must match libbpf. */
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) \
typedef void (*helper_abi_##NAME)(struct kprog_arm64_addressing *, struct kprog_arm64_vector *, \
                                 __u8 *, __u8 *, __u8 *, __u8 *, __typeof__(NAME)); \
_Static_assert(__builtin_types_compatible_p(__typeof__(&kprog_arm64_helper_##NAME), helper_abi_##NAME), "libbpf helper ABI mismatch: " #NAME);
#include "../c/Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
static void helper_input_phase(void);
static const void *helper_context_key;
static __u64 helper_context_values[2];
static unsigned helper_context_visits,helper_context_refuse;
static jmp_buf rejected;
static unsigned copy_visits,copy_refusal;
static unsigned events[512],count,selector_mode,failures,rejection_armed;
static __u64 values[512],entropy;
static void check(int ok,const char *why)
{ if (!ok) { fprintf(stderr,"ARM execute: %s\n",why);exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	check(count<512,"input overflow");helper_input_phase();
	entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;
	__u64 value=kind==1?0x10000:kind==3?0x20000:entropy;
	check(kind==1 || kind==3 || kind==6,"unexpected input");
	events[count]=kind;values[count++]=value;return value;
}
unsigned long native_lab_exclusive_failure_choice(unsigned site)
{ (void)site;check(0,"unselected exclusive input");return 0; }
void arm64_sim_unsupported_opcode(void)
{ failures++;if (!selector_mode) { check(rejection_armed,"unexpected rejection outside guarded call");longjmp(rejected,1); } }
void kprog_c_trap(void) { check(0,"unselected platform trap");abort(); }
void *kprog_c_context_pointer(const void *ctx,__u8 kind,__u32 offset)
{
	check(ctx==helper_context_key && ctx && kind==KPROG_ABI_KIND_XDP && (offset==0 || offset==4),"helper refresh context/field identity");
	check(offset==helper_context_visits*4 && count<512,"helper refresh data-before-end order");
	helper_context_visits++;events[count]=0x20000+offset;values[count++]=helper_context_values[offset/4];
	if(helper_context_visits==helper_context_refuse)longjmp(rejected,4);
	return (void *)(uintptr_t)helper_context_values[offset/4];
}
__u64 kprog_c_pointer_bits(const void *p)
{ (void)p;check(0,"unselected pointer exposure");return 0; }
__u64 kprog_c_atomic_fetch(void *p,__u64 v,__u32 w,__u32 op,__u32 order)
{ (void)p;(void)v;(void)w;(void)op;(void)order;check(0,"unselected atomic");return 0; }
void __builtin_memcpy_aligned(void *dst,const void *src,size_t n,size_t a)
{ check(a==1,"copy alignment"); if(++copy_visits==copy_refusal) longjmp(rejected,2);memcpy(dst,src,n); }

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
	for(unsigned k=0;k<6;k++)for(unsigned bit=0;bit<4;bit++){
		__u64 kind=k==5?0x100000000ULL:k,position=bit==0?0:bit==1?31:bit==2?63:127,value=0x8000000000000000ULL;int result;count=0;
		KPROG_ARM64_BRANCH_TEST_INTO(result,observe(1,kind),observe(2,value),observe(3,position));
		int expected=kind==0?value==0:kind==1?value!=0:kind==2?!((value>>(position&63))&1):kind==3?!!((value>>(position&63))&1):0;
		check(count==3 && events[0]==1 && events[1]==2 && events[2]==3 && result==expected,"branch predicate full-width/capture/mask");
		check(kprog_arm64_branch_test(kind,value,position)==expected,"actual branch predicate root");
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
	kprog_arm64_execute(&a,f.vectors,NULL,&z,NULL,NULL,ARM64_OP_CSEL,0,1,2,255,4,ARM64_COND_EQ,0);
	check(f.registers[0].x==17 && !count && !failures && z==2,"EQ reads only Z");
	kprog_arm64_execute(&a,f.vectors,NULL,NULL,NULL,NULL,ARM64_OP_CSEL,0,1,2,255,4,ARM64_COND_AL,0);
	check(f.registers[0].x==17 && !count && !failures,"AL reads no flags");
}
/* Independent whole-frame expectations for helper/libc/control wrappers. */
static unsigned wanted_events[512],wanted_count;
static __u64 wanted_values[512],wanted_entropy;
static __u64 want_input(unsigned kind)
{
	check(wanted_count<512,"expected input overflow");
	wanted_entropy^=wanted_entropy<<13;wanted_entropy^=wanted_entropy>>7;wanted_entropy^=wanted_entropy<<17;
	__u64 value=kind==1?0x10000:kind==3?0x20000:wanted_entropy;
	wanted_events[wanted_count]=kind;wanted_values[wanted_count++]=value;return value;
}
static struct kprog_arm64_addressing wrapper_frame(unsigned capacity,__s64 bias,unsigned variant)
{
	memset(&f,0,sizeof(f));count=failures=wanted_count=0;entropy=wanted_entropy=0x123456789abcdef0ULL^variant;
	f.coordinates=(struct kprog_arm64_coordinates){0x10000,0x20000,0,variant%2,(variant/2)%2};
	for(unsigned i=0;i<31;i++){f.registers[i].x=0xfedcba9876543210ULL^i;f.tags[i]=(__u8)(i*7);}
	for(unsigned i=0;i<512;i++)f.bytes[i]=(__u8)(i*17+variant);
	for(unsigned i=0;i<48;i++){f.stack_tags[i]=i%3==0?4:i%3==1?10:255;f.payload[i]=0x0123456789abcdefULL^i;}
	for(unsigned i=0;i<32;i++){f.vectors[i].lo=0x1020304050607080ULL^i;f.vectors[i].hi=~f.vectors[i].lo;}
	for(unsigned i=0;i<4;i++)f.flags[i]=(__u8)(variant+i);
	return (struct kprog_arm64_addressing){&f.coordinates,f.registers,f.tags,f.bytes,f.stack_tags,f.payload,capacity,bias,NULL,NULL,0,ARM64_SIM_ABI_KIND_RAW,(void *)f.bytes};
}
static void wrapper_equal(const struct frame *expected,const char *why)
{
	check(!memcmp(&f,expected,sizeof(f)),why);
	check(count==wanted_count && entropy==wanted_entropy && !memcmp(events,wanted_events,count*sizeof(*events)) && !memcmp(values,wanted_values,count*sizeof(*values)),"wrapper exact callback order/values");
}
static void wrapper_capture(unsigned family,unsigned variant,unsigned capacity,int trapped,__u64 result,int capture)
{
	if(!capture)return;
	const __u64 header[]={0xf000+family,variant,capacity,count,!!trapped,failures,result};
	check(fwrite(header,sizeof(header),1,stdout)==1 && fwrite(&f,sizeof(f),1,stdout)==1 && fwrite(events,sizeof(*events),count,stdout)==count && fwrite(values,sizeof(*values),count,stdout)==count,"wrapper capture write");
}
static __u64 want_read(struct frame *g,unsigned reg)
{
	__u64 value=reg==32?(__u64)g->coordinates.stack_offset:reg<31?g->registers[reg].x:0;
	unsigned tag=reg==32?4:reg<31?g->tags[reg]:0;
	if(tag==4){if(!g->coordinates.sp_valid){g->coordinates.sp_base=want_input(1);g->coordinates.sp_valid=1;}value+=g->coordinates.sp_base;}
	if(tag==10){if(!g->coordinates.return_valid){g->coordinates.return_base=want_input(3);g->coordinates.return_valid=1;}value+=g->coordinates.return_base;}
	return value;
}
static void want_clobbers(struct frame *g,unsigned capacity,__s64 bias)
{
	for(unsigned i=0;i<capacity;i++)if((__s64)i-bias<g->coordinates.stack_offset)g->bytes[i]=(__u8)want_input(6);
	for(unsigned i=0;i<(capacity+7)/8;i++)if((__s64)(i*8)-bias<g->coordinates.stack_offset)g->stack_tags[i]=0;
	for(unsigned i=1;i<=18;i++){g->registers[i].x=want_input(6);g->tags[i]=0;}
	for(unsigned i=0;i<4;i++)g->flags[i]=want_input(6)&1;
	for(unsigned i=0;i<32;i++){g->vectors[i].lo=want_input(6);g->vectors[i].hi=want_input(6);}
}
static void helper_wrappers(int capture)
{
	const unsigned capacities[]={1,7,9,160,200,376,160};const __s64 biases[]={0,-3,4,96,160,280,0x100000100LL};
	unsigned cases=0,libc_cases=0;
	for(unsigned p=0;p<7;p++)for(unsigned release=0;release<4;release++){
		unsigned cap=capacities[p],released=release==0?0:release==1?1:release==2?cap/2:cap;
		struct kprog_arm64_addressing a=wrapper_frame(cap,biases[p],cases);f.coordinates.stack_offset=(__s64)released-biases[p];
		struct frame expected=f;want_clobbers(&expected,cap,biases[p]);
		kprog_arm64_helper_clobbers(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3]);
		wrapper_equal(&expected,"helper clobber full GPR/flags/vector/byte/tag/payload frame");wrapper_capture(0,cases++,cap,0,0,capture);
	}
	const unsigned lengths[]={0,1,7,8,9,16},offsets[]={0,1,8,16};
	for(unsigned p=0;p<7;p++)for(unsigned copy=0;copy<2;copy++)for(unsigned di=0;di<4;di++)for(unsigned si=0;si<(copy?4:1);si++)for(unsigned li=0;li<6;li++)for(unsigned release=0;release<4;release++){
		unsigned cap=capacities[p],dst=offsets[di],src=offsets[si],length=lengths[li],released=release==0?0:release==1?1:release==2?cap/2:cap;
		/* Private arena access is defined only within the supplied capacity. */
		if(dst+length>cap || (copy && src+length>cap))continue;
		struct kprog_arm64_addressing a=wrapper_frame(cap,biases[p],cases);f.coordinates.stack_offset=(__s64)released-biases[p];
		f.registers[0].x=(__u64)((__s64)dst-biases[p]);f.tags[0]=4;
		f.registers[1].x=copy?(__u64)((__s64)src-biases[p]):0x1ff;f.tags[1]=copy?4:0;
		f.registers[2].x=length;f.tags[2]=0;struct frame expected=f;
		for(unsigned i=0;i<length;i++){
			__u8 byte=copy?(src+i<released?(__u8)want_input(6):expected.bytes[src+i]):255;
			expected.bytes[dst+i]=byte;expected.stack_tags[(dst+i)/8]=0;
			if(dst+i<released)expected.bytes[dst+i]=(__u8)want_input(6);
		}
		/* Reconstruct only complete aligned live pointer words, in forward order. */
		for(unsigned i=0;i<length;i++)if(i==0 || !((dst+i)&7)){
			unsigned tag=0;if(copy && src+i>=released && dst+i>=released && !((dst+i)&7) && length-i>=8 && !((src+i)&7)){
				tag=expected.stack_tags[(src+i)/8];if(tag==4 || tag==10)expected.payload[(dst+i)/8]=expected.payload[(src+i)/8];
			}expected.stack_tags[(dst+i)/8]=tag;
		}
		want_clobbers(&expected,cap,biases[p]);
		if(copy)kprog_arm64_libc_memcpy(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3]);
		else kprog_arm64_libc_memset(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3]);
		wrapper_equal(&expected,"libc forward bytes/overlap/provenance/release/clobber full frame");wrapper_capture(1+copy,cases++,cap,0,0,capture);libc_cases++;
	}
	fprintf(stderr,"ARM wrappers: %u clobber and %u libc complete frames\n",cases-libc_cases,libc_cases);
}
#if ADAPTER
/* A physical read import can refuse after an already committed byte prefix.
 * This process-local pointer case is checked independently, outside captures. */
static void libc_read_refusal(void)
{
	struct kprog_arm64_addressing a=wrapper_frame(160,96,0);
	f.coordinates.stack_offset=-96;f.registers[0].x=(__u64)-96;f.tags[0]=4;
	f.registers[1].ptr=f.bytes+64;f.tags[1]=0;f.registers[2].x=8;f.tags[2]=0;
	struct frame expected=f;expected.bytes[0]=expected.bytes[64];expected.bytes[1]=expected.bytes[65];expected.stack_tags[0]=0;
	copy_visits=0;copy_refusal=3;int trapped=setjmp(rejected);
	if(!trapped)kprog_arm64_libc_memcpy(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3]);
	check(trapped==2 && copy_visits==3 && !failures,"libc third physical read refusal");
	wrapper_equal(&expected,"libc read refusal preserves prior byte writes, skips clobbers and current store");copy_refusal=0;
	fprintf(stderr,"ARM wrappers: one adapter-only physical-read refusal prefix\n");
}
#endif
/* Real production helper bodies execute supplied, typed platform callees.
 * Expectations concern the ABI and surrounding C effects, not kernel helpers. */
static struct frame helper_before;
static unsigned helper_id,helper_calls,helper_refuse,helper_inflight,helper_returned;
static __u64 helper_result,helper_raw_return;
static unsigned helper_result_tag;
static __u64 helper_args[5];
static void helper_input_phase(void)
{
	if(helper_inflight && helper_returned)check(f.registers[0].x==helper_raw_return && f.tags[0]==helper_result_tag,"helper result committed before any clobber draw");
}
static void want_event(unsigned event,__u64 value)
{ check(wanted_count<512,"expected helper event overflow");wanted_events[wanted_count]=event;wanted_values[wanted_count++]=value; }
static void enter_helper(unsigned id)
{
	check(helper_inflight && id==helper_id && !helper_calls && !memcmp(&f,&helper_before,sizeof(f)),"typed callee identity/precall frame");
	check(!count,"callee precedes clobber inputs");helper_calls++;events[count]=0x10000+id;values[count++]=0;
}
static void leave_helper(void)
{ if(helper_refuse)longjmp(rejected,3);helper_returned=1; }
static __u64 call_clock(void) { enter_helper(5);leave_helper();return helper_result; }
static __u32 call_random(void) { enter_helper(7);leave_helper();return (__u32)helper_result; }
static void *call_lookup(void *map,const void *key)
{ enter_helper(1);check(map==(void *)0x50000 && key==f.bytes+8,"lookup exact map/key pointers");leave_helper();return (void *)(uintptr_t)helper_raw_return; }
static long call_update(void *map,const void *key,const void *value,__u64 flags)
{ enter_helper(2);check(map==(void *)0x50000 && key==f.bytes+8 && value==f.bytes+16 && flags==helper_args[3],"update map/key/value/full flags ABI");leave_helper();return (long)helper_result; }
static long call_trace(const char *format,__u32 size,...)
{
	enter_helper(6);check(format==(const char *)f.bytes+16 && size==(__u32)helper_args[1],"trace format/size ABI");
	va_list args;va_start(args,size);for(unsigned i=2;i<5;i++)check(va_arg(args,__u64)==helper_args[i],"trace variadic64 argument ABI");va_end(args);leave_helper();return (long)helper_result;
}
static long call_probe(void *dst,__u32 size,const void *src)
{
	enter_helper(4);check(dst==f.bytes+16 && src==f.bytes+64 && size==helper_args[1],"probe captured pointer/length ABI");
	unsigned n=helper_refuse && size?1:size;check(n<=16,"probe fixture footprint");
	for(unsigned i=0;i<n;i++)((__u8 *)dst)[i]=helper_result?0xdd:((const __u8 *)src)[i];leave_helper();return (long)helper_result;
}
static long call_dyn_read(void *dst,__u64 len,const struct bpf_dynptr *src,__u64 offset,__u64 flags)
{
	enter_helper(201);check(dst==f.bytes+16 && src==(const struct bpf_dynptr *)(f.bytes+64) && len==helper_args[1] && offset==helper_args[3] && flags==helper_args[4],"dynptr five-argument read ABI");
	unsigned n=helper_refuse && len?1:(unsigned)len;check(n<=16,"dynptr fixture footprint");for(unsigned i=0;i<n;i++)((__u8 *)dst)[i]=0xc0+i;
	leave_helper();return (long)helper_result;
}
static long call_dyn_write(const struct bpf_dynptr *dst,__u64 offset,void *src,__u64 len,__u64 flags)
{ enter_helper(202);check(dst==(const struct bpf_dynptr *)(f.bytes+64) && src==f.bytes+16 && offset==helper_args[1] && len==helper_args[3] && flags==helper_args[4],"dynptr five-argument full-width write ABI");leave_helper();return (long)helper_result; }
static void call_submit(void *ptr,__u64 flags)
{ enter_helper(132);check(ptr==(void *)0x40000 && flags==helper_args[1],"ringbuf submit pointer/flags ABI");leave_helper(); }
static void call_discard(void *ptr,__u64 flags)
{ enter_helper(133);check(ptr==(void *)0x40000 && flags==helper_args[1],"ringbuf discard pointer/flags ABI");leave_helper(); }
static void call_dyn_submit(struct bpf_dynptr *ptr,__u64 flags)
{ enter_helper(199);check(ptr==(struct bpf_dynptr *)(f.bytes+64) && flags==helper_args[1],"dynptr submit pointer/flags ABI");leave_helper(); }
static void call_dyn_discard(struct bpf_dynptr *ptr,__u64 flags)
{ enter_helper(200);check(ptr==(struct bpf_dynptr *)(f.bytes+64) && flags==helper_args[1],"dynptr discard pointer/flags ABI");leave_helper(); }
static void want_transfer(struct frame *g,unsigned dst,unsigned src,unsigned len,unsigned copy,unsigned released)
{
	for(unsigned i=0;i<len;i++)if(!i || !((dst+i)&7)){
		unsigned tag=0;if(copy && src+i>=released && dst+i>=released && !((dst+i)&7) && len-i>=8 && !((src+i)&7)){
			tag=g->stack_tags[(src+i)/8];if(tag==4 || tag==10)g->payload[(dst+i)/8]=g->payload[(src+i)/8];
		}g->stack_tags[(dst+i)/8]=tag;
	}
}
static void registry_helpers(int capture)
{
#define KPROG_ARM64_HELPER(ID, NAME, RESULT, ARGS) check((uintptr_t)NAME==ID,"libbpf helper numeric identity drift: " #NAME);
#include "../c/Arm64HelperCalls.h"
#undef KPROG_ARM64_HELPER
	const unsigned ids[]={5,7,1,2,6,4,201,202,132,133,199,200},capacities[]={160,200,376,160};
	const __s64 biases[]={96,160,280,0x100000100LL};const __u64 returns[]={0,1,~0ULL,0x8000000000000001ULL};
	const unsigned lengths[]={0,1,7,8,16};unsigned cases=0;
	for(unsigned which=0;which<12;which++)for(unsigned p=0;p<4;p++)for(unsigned ri=0;ri<4;ri++)for(unsigned li=0;li<(which==5 || which==6?5:1);li++)for(unsigned released=0;released<2;released++)for(unsigned refuse=0;refuse<2;refuse++){
		struct kprog_arm64_addressing a=wrapper_frame(capacities[p],biases[p],cases);unsigned lost=released?24:0;f.coordinates.stack_offset=(__s64)lost-biases[p];
		for(unsigned i=0;i<5;i++){f.registers[i].x=0xfedcba9876543210ULL+i;f.tags[i]=0;}
		if(which==2 || which==3){f.registers[0].ptr=(void *)0x50000;f.tags[0]=5;f.registers[1].x=(__u64)(8-biases[p]);f.tags[1]=4;f.registers[2].x=(__u64)(16-biases[p]);f.tags[2]=4;}
		if(which==4){f.registers[0].x=(__u64)(16-biases[p]);f.tags[0]=4;f.registers[1].x=0x100000008ULL;}
		if(which==5 || which==6){f.registers[0].x=(__u64)(16-biases[p]);f.tags[0]=4;f.registers[1].x=lengths[li];f.registers[2].x=(__u64)(64-biases[p]);f.tags[2]=4;}
		if(which==7){f.registers[0].x=(__u64)(64-biases[p]);f.tags[0]=4;f.registers[2].x=(__u64)(16-biases[p]);f.tags[2]=4;f.registers[3].x=0x100000008ULL;}
		if(which==8 || which==9){f.registers[0].ptr=(void *)0x40000;f.tags[0]=6;}
		if(which>=10){f.registers[0].x=(__u64)(64-biases[p]);f.tags[0]=4;}
		for(unsigned i=0;i<5;i++)helper_args[i]=f.registers[i].x;
		helper_id=ids[which];helper_calls=helper_returned=0;helper_refuse=refuse;helper_inflight=1;helper_result=returns[ri];
		helper_raw_return=which==1?(__u32)helper_result:which==2?(ri?0x40000:0):which>=8?0:helper_result;helper_result_tag=which==2?6:0;helper_before=f;
		struct frame expected=f;want_event(0x10000+helper_id,0);
		if(which==5 || which==6){unsigned n=refuse && lengths[li]?1:lengths[li];for(unsigned i=0;i<n;i++)expected.bytes[16+i]=which==6?0xc0+i:helper_result?0xdd:expected.bytes[64+i];}
		if(!refuse){expected.registers[0].x=helper_raw_return;expected.tags[0]=helper_result_tag;want_clobbers(&expected,capacities[p],biases[p]);
			if(which==5 || which==6)want_transfer(&expected,16,64,lengths[li],which==5 && !helper_result,lost);
			if(which>=10)want_transfer(&expected,64,0,16,0,lost);
		}
		int trapped=setjmp(rejected);
		if(!trapped)switch(which){
#define CALL(NAME,FN) kprog_arm64_helper_##NAME(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],FN)
		case 0:CALL(bpf_ktime_get_ns,call_clock);break;case 1:CALL(bpf_get_prandom_u32,call_random);break;
		case 2:CALL(bpf_map_lookup_elem,call_lookup);break;case 3:CALL(bpf_map_update_elem,call_update);break;
		case 4:CALL(bpf_trace_printk,call_trace);break;case 5:CALL(bpf_probe_read,call_probe);break;
		case 6:CALL(bpf_dynptr_read,call_dyn_read);break;case 7:CALL(bpf_dynptr_write,call_dyn_write);break;
		case 8:CALL(bpf_ringbuf_submit,call_submit);break;case 9:CALL(bpf_ringbuf_discard,call_discard);break;
		case 10:CALL(bpf_ringbuf_submit_dynptr,call_dyn_submit);break;case 11:CALL(bpf_ringbuf_discard_dynptr,call_dyn_discard);break;
		default:check(0,"helper case");
#undef CALL
		}
		helper_inflight=0;check(trapped==(refuse?3:0) && helper_calls==1 && !failures,"one typed helper call, return or refusal");
		wrapper_equal(&expected,"helper argument/result/effect/tag/ordered-clobber complete frame");wrapper_capture(32+which,cases++,capacities[p],trapped,helper_raw_return,capture);
	}
	fprintf(stderr,"ARM helpers: 95 libbpf signatures, %u complete typed-callee frames across12 helpers\n",cases);
}
/* A full64-bit length is observed before a callee refuses; no huge local
 * arena or narrowed successful-access premise is needed for this ABI check. */
static void helper_wide_length(void)
{
	struct kprog_arm64_addressing a=wrapper_frame(160,96,0);f.coordinates.stack_offset=-96;
	f.registers[0].x=(__u64)-80;f.tags[0]=4;f.registers[1].x=0x100000008ULL;f.tags[1]=0;
	f.registers[2].x=(__u64)-32;f.tags[2]=4;f.registers[3].x=0x123456789abcdef0ULL;f.tags[3]=0;f.registers[4].x=~0ULL;f.tags[4]=0;
	for(unsigned i=0;i<5;i++)helper_args[i]=f.registers[i].x;
	helper_id=201;helper_calls=helper_returned=0;helper_refuse=helper_inflight=1;helper_result=helper_raw_return=0;helper_result_tag=0;helper_before=f;
	struct frame expected=f;expected.bytes[16]=0xc0;want_event(0x10000+201,0);
	int trapped=setjmp(rejected);if(!trapped)kprog_arm64_helper_bpf_dynptr_read(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],call_dyn_read);
	helper_inflight=0;check(trapped==3 && helper_calls==1 && !failures,"full64 length delivered before refusal");wrapper_equal(&expected,"wide-length refusal effect/argument/frame");
	fprintf(stderr,"ARM helpers: one independent full64-length refusal prefix\n");
}
static struct xdp_md helper_xdp;
static long call_xdp(struct xdp_md *ctx,int delta)
{
	enter_helper(helper_id);check(ctx==&helper_xdp && delta==(int)0x80000007U,"adjust helper real context/signed delta ABI");
	helper_xdp.data=0x12345000;helper_xdp.data_end=0x12346000;leave_helper();return (long)helper_result;
}
static void refresh_helpers(void)
{
	const unsigned ids[]={44,54,65};unsigned cases=0;
	for(unsigned which=0;which<3;which++)for(unsigned error=0;error<2;error++)for(unsigned fail=0;fail<3;fail++){
#if !ADAPTER
		if(fail)continue;
#endif
		struct arm64_sim_xdp_abi abi={(void *)0x11111111,(void *)0x22222222,(void *)0x33333333},expected_abi=abi;
		memset(&helper_xdp,0,sizeof(helper_xdp));struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);
		f.coordinates.stack_offset=-96;a.helper_context=&helper_xdp;a.helper_abi_base=&abi;a.abi_kind=KPROG_ABI_KIND_XDP;a.is_xdp=1;
		f.registers[0].ptr=&abi;f.tags[0]=1;f.registers[1].x=0xffffffff80000007ULL;f.tags[1]=0;
		helper_context_key=&helper_xdp;helper_context_visits=0;helper_context_refuse=fail;helper_context_values[0]=0xabcd000012345000ULL;helper_context_values[1]=0xbcde000012346000ULL;
		helper_id=ids[which];helper_calls=helper_returned=helper_refuse=0;helper_inflight=1;helper_result=error?(__u64)-22:0;helper_raw_return=helper_result;helper_result_tag=0;helper_before=f;
		struct frame expected=f;want_event(0x10000+helper_id,0);expected.registers[0].x=helper_result;expected.tags[0]=0;want_clobbers(&expected,160,96);
#if ADAPTER
		want_event(0x20000,helper_context_values[0]);if(fail!=1){expected_abi.data=(void *)(uintptr_t)helper_context_values[0];want_event(0x20004,helper_context_values[1]);if(fail!=2)expected_abi.data_end=(void *)(uintptr_t)helper_context_values[1];}
#else
		expected_abi.data=(void *)0x12345000;expected_abi.data_end=(void *)0x12346000;
#endif
		int trapped=setjmp(rejected);if(!trapped){
			if(which==0)kprog_arm64_helper_bpf_xdp_adjust_head(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],call_xdp);
			else if(which==1)kprog_arm64_helper_bpf_xdp_adjust_meta(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],call_xdp);
			else kprog_arm64_helper_bpf_xdp_adjust_tail(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],call_xdp);
		}
		helper_inflight=0;check(trapped==(fail?4:0) && helper_calls==1 && !memcmp(&abi,&expected_abi,sizeof(abi)),"refresh full pointer/field order/partial commit after helper success or error");wrapper_equal(&expected,"refresh whole frame/clobber before context reads");cases++;
	}
	helper_context_key=NULL;helper_context_refuse=0;fprintf(stderr,"ARM helpers: %u independent physical-context refresh frames\n",cases);
}
static int want_condition(unsigned cond,const __u8 *flags)
{
	int n=flags[0],z=flags[1],c=flags[2],v=flags[3];
	int answers[]={z,!z,c,!c,n,!n,v,!v,c&&!z,!c||z,n==v,n!=v,!z&&(n==v),z||(n!=v),1};
	return cond<15?answers[cond]:0;
}
static void control_wrappers(int capture)
{
	unsigned cases=0;
	for(unsigned cond=0;cond<17;cond++)for(unsigned flags=0;flags<20;flags++)for(unsigned direction=0;direction<3;direction++){
		struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);
		for(unsigned i=0;i<4;i++)f.flags[i]=flags<16?(flags>>i)&1:((flags+i)&1?255:2);
		struct frame expected=f;rejection_armed=1;int taken=!!want_condition(cond,expected.flags),trapped=setjmp(rejected),got=0;
		if(!trapped)got=kprog_arm64_jcc(&a,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],cond,10,direction==0?4:direction==1?10:20);
		rejection_armed=0;check(!!trapped==(cond>=15) && failures==(cond>=15) && (trapped || got==taken),"JCC flags/direction/refusal");
		wrapper_equal(&expected,"JCC whole frame");wrapper_capture(3,cases++,160,trapped,got,capture);
	}
	const __u64 data[]={0,1,0x100000000ULL,0x8000000000000000ULL,~0ULL};const unsigned registers[]={0,31,32,255},tags[]={0,4,10};
	for(unsigned mode=0;mode<3;mode++)for(unsigned reg=0;reg<4;reg++)for(unsigned tag=0;tag<3;tag++)for(unsigned vi=0;vi<5;vi++)for(unsigned kind=0;kind<6;kind++)for(unsigned direction=0;direction<3;direction++){
		struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);f.registers[0].x=data[vi];f.tags[0]=tags[tag];f.coordinates.stack_offset=(__s64)data[vi];
		struct frame expected=f;__u64 value=want_read(&expected,registers[reg]),code=kind==5?0x100000000ULL:kind,bit=vi==4?127:vi==3?63:vi;
		if(mode==1)value=(__u32)value;
		unsigned selected=mode==2?(bit&63):0;int taken=code==0?value==0:code==1?value!=0:code==2?!((value>>selected)&1):code==3?!!((value>>selected)&1):0;
		int got=mode==0?kprog_arm64_cbz_x(&a,registers[reg],code,10,direction==0?4:direction==1?10:20):mode==1?kprog_arm64_cbz_w(&a,registers[reg],code,10,direction==0?4:direction==1?10:20):kprog_arm64_tbz(&a,registers[reg],bit,code,10,direction==0?4:direction==1?10:20);
		check(got==taken && !failures,"CBZ W/X and TBZ full-kind/masked-bit predicate");wrapper_equal(&expected,"test branch complete cache/register/memory frame");wrapper_capture(4+mode,cases++,160,0,got,capture);
	}
	/* CMP/GT must retain the eager register operand even for CMP-immediate. */
	for(unsigned immediate=0;immediate<2;immediate++)for(unsigned wi=0;wi<3;wi++)for(unsigned li=0;li<5;li++)for(unsigned ri=0;ri<5;ri++)for(unsigned tag=0;tag<3;tag++){
		unsigned width=wi==0?4:wi==1?8:1,bits=width*8;__u64 mask=width==8?~0ULL:(1ULL<<bits)-1;
		struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);f.registers[0].x=data[li];f.tags[0]=tags[tag];f.registers[1].x=data[ri];f.tags[1]=tags[(tag+1)%3];
		struct frame expected=f;__u64 lhs=want_read(&expected,0),rhs=want_read(&expected,1);if(immediate)rhs=data[ri];__u64 l=lhs&mask,r=rhs&mask,result=(l-r)&mask;
		expected.flags[0]=(result>>(bits-1))&1;expected.flags[1]=l==r;expected.flags[2]=l>=r;expected.flags[3]=((l^r)&(l^result))>>(bits-1)&1;
		rejection_armed=1;int wanted=width==4?(__s32)lhs>(__s32)rhs:(__s64)lhs>(__s64)rhs,trapped=setjmp(rejected),got=0;
		if(!trapped)got=kprog_arm64_cmp_gt(&a,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],immediate?ARM64_OP_CMP_IMM:ARM64_OP_CMP_REG,0,1,width,0,data[ri]);
		rejection_armed=0;check(!!trapped==(width==1) && failures==(width==1) && (trapped || got==wanted),"CMP-GT signed width and flags-before-refusal");wrapper_equal(&expected,"CMP-GT full ordered-input/flag/frame");wrapper_capture(7,cases++,160,trapped,got,capture);
	}
	for(unsigned vi=0;vi<5;vi++){
		struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);struct frame expected=f;expected.registers[30].x=data[vi];expected.tags[30]=9;
		__u64 got=kprog_arm64_link(&a,data[vi]);check(got==data[vi] && !failures,"LINK preserves full return address");wrapper_equal(&expected,"LINK X30/code-tag frame");wrapper_capture(8,cases++,160,0,got,capture);
	}
	const unsigned lr_tags[]={0,4,9,10};
	for(unsigned mode=0;mode<2;mode++)for(unsigned sp=0;sp<2;sp++)for(unsigned reg=0;reg<4;reg++)for(unsigned tag=0;tag<4;tag++)for(unsigned vi=0;vi<5;vi++){
		struct kprog_arm64_addressing a=wrapper_frame(160,96,cases);unsigned lr=registers[reg];f.registers[0].x=data[vi];f.tags[0]=tags[vi%3];f.registers[30].x=data[vi];f.tags[30]=lr_tags[tag];f.coordinates.stack_offset=sp?-8:0;
		if(lr==0){f.registers[0].x=data[vi];f.tags[0]=lr_tags[tag];}
		/* Include X30 in the zero-register slot; XZR itself is covered by CBZ. */
		if(lr==31)lr=30;
		struct frame expected=f;__u64 raw=lr==32?(__u64)expected.coordinates.stack_offset:lr<31?expected.registers[lr].x:0;unsigned ltag=lr==32?4:lr<31?expected.tags[lr]:0;
		rejection_armed=1;int refusal=sp || (mode && !(raw==0 && ltag==10));__u64 wanted=refusal?0:(__u32)want_read(&expected,0);int trapped=setjmp(rejected);__u64 got=0;
		if(!trapped)got=mode?kprog_arm64_return_to(&a,lr):kprog_arm64_exit(&a);
		rejection_armed=0;check(!!trapped==refusal && failures==(unsigned)refusal && (trapped || got==wanted),"RET raw LR/tag before SP/result, no unknown continuation");wrapper_equal(&expected,"RET full frame and ordered rejection prefix");wrapper_capture(9+mode,cases++,160,trapped,got,capture);
	}
	fprintf(stderr,"ARM wrappers: %u control/link/return complete frames\n",cases);
}
int main(int argc,char **argv)
{
	check(argc==1 || (argc==2 && !strcmp(argv[1],"--capture")),"arguments");
	int capture=argc==2;
	selectors();
	lazy_flags();
	helper_wrappers(capture);
	registry_helpers(capture);
	helper_wide_length();
	refresh_helpers();
	control_wrappers(capture);
#if ADAPTER
	libc_read_refusal();
#endif
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
		count=failures=0;rejection_armed=1;int trapped=setjmp(rejected);
		if (!trapped) kprog_arm64_execute(&a,f.vectors,&f.flags[0],&f.flags[1],&f.flags[2],&f.flags[3],op,regs[variant%7],regs[(variant+1)%7],regs[(variant+2)%7],regs[(variant+3)%7],width,aux,variant%64);
		rejection_armed=0;
		const __u32 header[]={op,variant,capacities[p],count,!!trapped,failures};
		if (capture) check(fwrite(header,sizeof(header),1,stdout)==1 && fwrite(&f,sizeof(f),1,stdout)==1 && fwrite(events,sizeof(events[0]),count,stdout)==count && fwrite(values,sizeof(values[0]),count,stdout)==count,"frame capture write");
		cases++;
	}
	fprintf(stderr,"ARM execute: %u complete frames, frame_bytes=%zu; selectors/CNT lanes pass\n",cases,sizeof(f));
	return 0;
}
