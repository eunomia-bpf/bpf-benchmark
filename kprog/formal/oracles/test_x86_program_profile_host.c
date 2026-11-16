/* Closed producer program: real CALL/RET labels, helper effects and high64 SP. */
#include <linux/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

extern int x86_program_profile_x86_sim_xdp(void *);
static __u64 entropy, sp_base, seed_value, event_values[256];
static unsigned event_kinds[256], count, inputs, sp_calls, helpers;
static jmp_buf refusal;
static int rejecting;
static void require(int ok)
{ if (!ok) { fputs("x86 producer program mismatch\n",stderr);exit(1); } }
static void record(unsigned kind, __u64 value)
{ require(count<256);event_kinds[count]=kind;event_values[count++]=value; }
unsigned long native_lab_entry_input(unsigned kind)
{
	require(kind==1 || kind==6);++inputs;
	__u64 value;
	if (kind==1) {++sp_calls;value=sp_base;}
	else {entropy^=entropy<<13;entropy^=entropy>>7;entropy^=entropy<<17;value=entropy;}
	record(kind,value);return value;
}
static __u64 time_value(unsigned n)
{ return seed_value*0x9e3779b97f4a7c15ULL ^ ((__u64)n*0x1122334455667788ULL); }
unsigned long long kprog_x86_observe_time(void)
{
	++helpers;require(helpers<=2);
	__u64 value=time_value(helpers);record(0x105,value);
	if (rejecting && helpers==2) longjmp(refusal,1);
	return value;
}
__u64 kprog_x86_callee_bpf_ktime_get_ns(void)
{ return kprog_x86_observe_time(); }
__u32 kprog_x86_callee_bpf_get_prandom_u32(void)
{
	require(helpers==0 && inputs==24 && sp_calls==1);
	fputs("unexpected x86 helper identity\n",stderr);exit(1);
}
void kprog_x86_observe_unresolved(void)
{
	require(helpers==1 && inputs==41 && sp_calls==1 && count==42);
	fputs("unexpected x86 return continuation\n",stderr);exit(1);
}
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p,__u8 kind,__u32 off)
{ (void)p;(void)kind;(void)off;abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p;abort(); }
__u64 kprog_c_atomic_fetch(void *p,__u64 v,__u32 width,__u32 op,__u32 order)
{ (void)p;(void)v;(void)width;(void)op;(void)order;abort(); }
void __builtin_memcpy_aligned(void *dst,const void *src,size_t n,size_t align)
{ require(align==1);memcpy(dst,src,n); }

int main(int argc,char **argv)
{
	int capture=argc==2 && !strcmp(argv[1],"--capture");require(argc==1||capture);
	for (volatile unsigned seed=1;seed<=32;++seed) for (rejecting=0;rejecting<2;++rejecting) {
		seed_value=seed;entropy=seed;count=inputs=sp_calls=helpers=0;
		sp_base=0xfedcba9800011000ULL+((__u64)seed<<8);
		volatile __u32 got=0;
		if (!setjmp(refusal)) {
			got=x86_program_profile_x86_sim_xdp(NULL);
			require(!rejecting);
			__u64 value=time_value(1)^time_value(2)^(sp_base-24);
			require(got==(__u32)(value^(value>>32)));
		}
		require(sp_calls==1 && helpers==2 && inputs==(rejecting?41U:63U) && count==inputs+2);
		if (capture) {
			const __u32 header[]={seed,(unsigned)rejecting,got,count};
			require(fwrite(header,sizeof(header),1,stdout)==1 &&
			    fwrite(event_kinds,sizeof(*event_kinds),count,stdout)==count &&
			    fwrite(event_values,sizeof(*event_values),count,stdout)==count);
		}
	}
	fputs("x86 producer program: 32 high64 return cases and 32 helper-refusal prefixes\n",stderr);
	return 0;
}
