/* Detect byte/tag/payload frame loss, eager coordinate inputs and reordered
 * free inputs in the real stack roots. The model uses direct byte intervals.
 * Mapped prefix/suffix windows also catch an invented capacity guard. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARM64_SIM_ENABLE_STACK 1
#include "../c/Arm64Stack.h"
static unsigned requests[16], count;
static __u64 entropy;
static unsigned long cases;
static const __u64 sp_input=0xfedcba9876543210ULL, ret_input=0x123456789abcdef0ULL;
static __u64 fresh(__u64 *state)
{
	*state^=*state<<13; *state^=*state>>7; *state^=*state<<17; return *state;
}
unsigned long native_lab_entry_input(unsigned kind)
{
	if(count==16) abort(); requests[count++]=kind;
	if(kind==1) return sp_input;
	if(kind==3) return ret_input;
	if(kind!=NATIVE_LAB_INPUT_UNSPECIFIED) abort();
	return fresh(&entropy);
}
void arm64_sim_unsupported_opcode(void) { abort(); }
static void check(int ok,const char *what)
{
	if(!ok){fprintf(stderr,"ARM stack case %lu: %s\n",cases,what);exit(1);}
}
static __u64 mask(unsigned width)
{
	return width==1?0xffULL:width==2?0xffffULL:width==4?0xffffffffULL:~0ULL;
}
static void equal_coordinates(struct kprog_arm64_coordinates a,struct kprog_arm64_coordinates b)
{
	check(a.sp_base==b.sp_base && a.return_base==b.return_base && a.stack_offset==b.stack_offset &&
	      a.sp_valid==b.sp_valid && a.return_valid==b.return_valid,"coordinates/cache frame");
}
int main(void)
{
	const struct {unsigned capacity;__s64 bias;} profiles[]={{1,0},{7,-3},{9,4},{160,96},{200,160},{376,280},{9,0x100000004LL},{160,-0x100000060LL}};
	const __u8 widths[]={1,2,4,8,0,255},valid[]={0,1,2,255};
	const __u64 values[]={0,1,~0ULL,0x8000000000000000ULL,0x12345678ffffffffULL,0xfedcba9876543210ULL};
	for(unsigned pi=0;pi<8;pi++) {
		unsigned cap=profiles[pi].capacity;__s64 bias=profiles[pi].bias;
		/* Extra mapped words are observed, not zero-filled or silently ignored. */
		__u64 storage[52],expected_storage[52],packed[9],expected_packed[9],payload[52],expected_payload[52];
		__u8 *bytes=(__u8 *)storage+16,*want_bytes=(__u8 *)expected_storage+16;
		__u8 *tags=(__u8 *)packed,*want_tags=(__u8 *)expected_packed;
		for(unsigned point=0;point<20;point++) for(unsigned wi=0;wi<7;wi++)
		for(unsigned tag=0;tag<256;tag++) for(unsigned spi=0;spi<6;spi++) for(unsigned owned=0;owned<2;owned++) {
			unsigned at=point<16?point:point==16?cap-1:point==17?cap:point==18?cap+1:cap+7;
			unsigned width=wi<6?widths[wi]:tag;
			__s64 off=(__s64)at-bias;
			__s64 sp=spi==0?off-1:spi==1?off:spi==2?off+1:spi==3?off+7:spi==4?(-0x7fffffffffffffffLL-1):0x7fffffffffffffffLL;
			__u64 seed=0x9e3779b97f4a7c15ULL*(cases+1);
			struct kprog_arm64_coordinates coords={seed,~seed,sp,valid[cases%4],valid[(cases/4)%4]},want=coords;
			struct kprog_arm64_memory memory={&coords,bytes,(volatile __u64 *)(void *)bytes,tags,payload,cap,bias};
			for(unsigned i=0;i<sizeof(storage);i++) ((__u8 *)storage)[i]=seed+i*17;
			for(unsigned i=0;i<sizeof(packed);i++) tags[i]=seed+i*31;
			for(unsigned i=0;i<52;i++) payload[i]=seed^((__u64)i*0x123456789ULL);
			memcpy(expected_storage,storage,sizeof(storage));memcpy(expected_packed,packed,sizeof(packed));memcpy(expected_payload,payload,sizeof(payload));
			unsigned read_bytes=width>=8?8:width>=4?4:width>=2?2:1;
			__u64 raw=0;for(unsigned i=0;i<read_bytes;i++) raw|=(__u64)bytes[at+i]<<(i*8);
			count=0;entropy=seed;
			check(kprog_arm64_stack_read_owned(&memory,off,width)==raw,"owned little-endian width/read");
			check(count==0 && entropy==seed,"owned read requested input");
			__u64 expected_entropy=seed,observed=raw;
			if(off<sp) observed=fresh(&expected_entropy)&mask(width);
			check(kprog_arm64_stack_read(&memory,off,width)==observed,"released read value");
			check(count==(unsigned)(off<sp) && entropy==expected_entropy && (!count || requests[0]==6),"released read input identity/stream");
			unsigned read_count=count;
			check(kprog_arm64_stack_read_tag(&memory,off,width)==(off>=sp && width==8 && at%8==0?tags[at/8]:0),"owned aligned tag selection");
			check(count==read_count && entropy==expected_entropy,"tag read requested input");
			check(kprog_arm64_stack_pointer(&memory,off)==(void *)(bytes+at),"biased pointer/escaped mapped window");
			equal_coordinates(coords,want);
			check(!memcmp(storage,expected_storage,sizeof(storage)) && !memcmp(packed,expected_packed,sizeof(packed)) && !memcmp(payload,expected_payload,sizeof(payload)),"read-only storage frame");
			__u64 value=values[(cases+wi)%6]&mask(width);
			unsigned write_bytes=width==1?1:width==2?2:width==4?4:8;
			for(unsigned i=0;i<write_bytes;i++) want_bytes[at+i]=(__u8)(value>>(i*8));
			unsigned expected_requests[16],expected_count=0;expected_entropy=seed;
			if(width==8 && at%8==0) {
				want_tags[at/8]=tag;
				if(tag==4 || tag==10) {
					__u64 base;
					if(tag==4){if(!want.sp_valid){want.sp_base=sp_input;want.sp_valid=1;expected_requests[expected_count++]=1;}base=want.sp_base;}
					else {if(!want.return_valid){want.return_base=ret_input;want.return_valid=1;expected_requests[expected_count++]=3;}base=want.return_base;}
					expected_payload[at/8]=value-base;
				}
			} else for(unsigned w=at/8;w<=(at+write_bytes-1)/8;w++) want_tags[w]=0;
			if(!owned && off<sp) for(unsigned i=0;i<8 && i<width;i++) if(off+i<sp) {
				want_bytes[at+i]=(__u8)fresh(&expected_entropy);expected_requests[expected_count++]=6;want_tags[(at+i)/8]=0;
			}
			count=0;entropy=seed;
			if(owned) kprog_arm64_stack_write_owned(&memory,off,width,values[(cases+wi)%6],tag);
			else kprog_arm64_stack_write(&memory,off,width,values[(cases+wi)%6],tag);
			check(count==expected_count && entropy==expected_entropy && !memcmp(requests,expected_requests,count*sizeof(unsigned)),"write coordinate/free input order/stream");
			equal_coordinates(coords,want);
			check(!memcmp(storage,expected_storage,sizeof(storage)),"written bytes/whole frame");
			check(!memcmp(packed,expected_packed,sizeof(packed)),"packed tags/padding/whole frame");
			check(!memcmp(payload,expected_payload,sizeof(payload)),"pointer payload/whole frame");
			cases++;
		}
	}
	printf("ARM private stack bindings: %lu byte/tag/payload/cache/input checks\n",cases);
	return 0;
}
