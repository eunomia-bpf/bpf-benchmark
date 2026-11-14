/* Catch ignored alignment attributes, wrong physical widths/displacements,
 * pointer truncation, extra accesses and stores that damage adjacent bytes. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c/Arm64Access.h"
static unsigned long cases;
static void check(int ok,const char *what)
{
	if(!ok){fprintf(stderr,"ARM access adapter=%u case=%lu: %s\n",ADAPTER,cases,what);exit(1);}
}
#if ADAPTER
static unsigned copies;
static void *copy_destination;
static const void *copy_source;
static size_t copy_size,copy_alignment;
void __builtin_memcpy_aligned(void *destination,const void *source,size_t size,size_t alignment)
{
	copies++;copy_destination=destination;copy_source=source;copy_size=size;copy_alignment=alignment;
	memcpy(destination,source,size);
}
#endif
int main(void)
{
	static unsigned char bytes[65600],expected[sizeof(bytes)];
	const __s64 offsets[]={-32769,-32768,-15,-8,-7,-1,0,1,7,8,15,32767,32768};
	const __u64 values[]={0,1,~0ULL,0x8000000000000000ULL,0x12345678ffffffffULL,0xfedcba9876543210ULL};
	for(unsigned at=0;at<13;at++) for(unsigned width=0;width<256;width++) for(unsigned vi=0;vi<6;vi++) {
		__u64 seed=0x9e3779b97f4a7c15ULL*(cases+1);
		for(unsigned i=0;i<sizeof(bytes);i++) bytes[i]=seed+i*17;
		memcpy(expected,bytes,sizeof(bytes));
		void *base=bytes+32784;unsigned index=32784+offsets[at];
		unsigned length=width==8?8:width>=4?4:width>=2?2:1;
		__u64 want=0;for(unsigned i=0;i<length;i++) want|=(__u64)bytes[index+i]<<(i*8);
#if ADAPTER
		copies=0;
#endif
		check(kprog_arm64_access_read(base,offsets[at],width)==want,"unaligned width/displacement/zero extension");
#if ADAPTER
		check(copies==1 && copy_source==bytes+index && copy_size==length && copy_alignment==1,"one complete alignment-1 read");
#endif
		check(!memcmp(bytes,expected,sizeof(bytes)),"read-only frame");
		void *pointer=vi==0?NULL:vi==1?(void *)bytes:vi==2?(void *)(expected+17):(void *)(uintptr_t)values[vi];
		memcpy(bytes+index,&pointer,sizeof(pointer));memcpy(expected+index,&pointer,sizeof(pointer));
#if ADAPTER
		copies=0;
#endif
		check(kprog_arm64_access_pointer(base,offsets[at])==pointer,"typed pointer/full high bits");
#if ADAPTER
		check(copies==1 && copy_source==bytes+index && copy_size==sizeof(pointer) && copy_alignment==1,"one complete typed pointer read");
#endif
		check(!memcmp(bytes,expected,sizeof(bytes)),"pointer read frame");
		for(unsigned i=0;i<length;i++) expected[index+i]=(__u8)(values[vi]>>(i*8));
#if ADAPTER
		copies=0;
#endif
		kprog_arm64_access_write(bytes+index,width,values[vi]);
#if ADAPTER
		check(copies==1 && copy_destination==bytes+index && copy_size==length && copy_alignment==1,"one complete alignment-1 write");
#endif
		check(!memcmp(bytes,expected,sizeof(bytes)),"store low bits/whole byte frame");
		cases++;
	}
	printf("ARM nonarena access adapter %u: %lu width/offset/pointer/frame cases\n",ADAPTER,cases);
	return 0;
}
