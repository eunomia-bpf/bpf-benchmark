/* RET_TO routing, private scratch, whole register preservation and actual
 * return/CB exit effects over all native source registers and tag bytes. */
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;
#ifndef __always_inline
#define __always_inline inline
#endif
#include "../arm64/arm64_sim_local_bpf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

struct snapshot { __u64 regs[31],vectors[64],sp,lr; __u8 tags[31],flags[4],context[sizeof(struct __sk_buff)]; __u32 mirror[5]; };
struct result { struct snapshot before,after; int route; __u64 target; __u32 value; unsigned inputs; };
struct frame { union arm64_sim_gpr *const *cells; __u8 *const *tags; __u8 **flags; void *vectors; __s64 *sp; __u64 *lr; struct arm64_sim_skb_abi *mirror; };
static struct result out;
static struct frame *active;
static struct __sk_buff context;
static jmp_buf refused;
static unsigned inputs;
static const __u64 stack_base=0x123456789abcdef0ULL,return_base=0xfedcba9876543210ULL;
unsigned long native_lab_entry_input(unsigned kind)
{
 inputs++;if(kind==1)return stack_base;if(kind==3)return return_base;abort();
}
unsigned long native_lab_exclusive_failure_choice(unsigned site) { (void)site;abort(); }
static void capture(struct frame *f,struct snapshot *s)
{
 memset(s,0,sizeof(*s));
 for(unsigned i=0;i<31;i++){s->regs[i]=f->cells[i]->x;s->tags[i]=*f->tags[i];}
 for(unsigned i=0;i<4;i++)s->flags[i]=*f->flags[i];
 memcpy(s->vectors,f->vectors,sizeof(s->vectors));s->sp=(__u64)*f->sp;s->lr=*f->lr;
 memcpy(s->context,&context,sizeof(context));memcpy(s->mirror,f->mirror->cb,sizeof(s->mirror));
}
static void close_frame(struct frame *f) { capture(f,&out.after);out.inputs=inputs; }
void arm64_sim_unsupported_opcode(void)
{
 out.route=-1;capture(active,&out.after);out.inputs=inputs;longjmp(refused,1);
}
#define CASES_ONE case 0ULL: goto target_zero;
#define CASES_FOUR case 0ULL: goto target_zero;case 1ULL: goto target_one;case 256ULL: goto target_256;case 0xffffffffffffffffULL: goto target_max;
static __u32 execute(unsigned src,unsigned tag,__u64 target,unsigned table,unsigned skb,unsigned pattern)
{
 ARM64_SIM_L_DECLARE_STATE();ARM64_SIM_L_DECLARE_STACK();
 (void)&__a64_stack;(void)&__a64_stack_payload;(void)&__a64_stack_tag;
 struct arm64_sim_skb_abi __a64_sim_abi={};
 __a64_sim_helper_ctx=skb?&context:NULL;
 for(unsigned i=0;i<31;i++){__a64_cells[i]->x=0x1122334455667788ULL+i*0x102030405ULL;*__a64_tag_cells[i]=0;}
 const __u64 values[]={0,1,0xffffffffULL,0x100000000ULL,0x8000000000000000ULL,0xffffffffffffffffULL,0x1234567887654321ULL,0xfedcba9876543210ULL};
 const unsigned tags[]={0,4,9,10};
 __a64_x0.x=values[pattern%8];__a64_x0_tag=tags[pattern%4];
 if(src<31){__a64_cells[src]->x=target;*__a64_tag_cells[src]=tag;}
 for(unsigned i=0;i<32;i++){__a64_vectors[i].lo=0x123456789abcdef0ULL+i;__a64_vectors[i].hi=0x876543210fedcba9ULL-i;}
 __a64_sp=0x1234;__a64_lr=0x987654321ULL;
 __a64_n=pattern&1;__a64_z=(pattern>>1)&1;__a64_c=(pattern>>2)&1;__a64_v=(pattern>>3)&1;
 memset(&context,0xa5,sizeof(context));
 for(unsigned i=0;i<5;i++)__a64_sim_abi.cb[i]=0x12345678U+i*0x12121212U+pattern;
 __u8 *flags[]={&__a64_n,&__a64_z,&__a64_c,&__a64_v};
 struct frame f __attribute__((cleanup(close_frame)))={__a64_cells,__a64_tag_cells,flags,__a64_vectors,&__a64_sp,&__a64_lr,&__a64_sim_abi};
 active=&f;inputs=0;memset(&out,0,sizeof(out));capture(&f,&out.before);
 switch(table){
 case 0:ARM64_SIM_A64_RET_TO(src,);break;
 case 1:ARM64_SIM_A64_RET_TO(src,CASES_ONE);break;
 case 2:ARM64_SIM_A64_RET_TO(src,CASES_FOUR);break;
 default:abort();
 }
 abort();
 target_zero:out.route=1;out.target=0;return 0xa0b0c0d0U;
 target_one:out.route=1;out.target=1;return 0xa0b0c0d0U;
 target_256:out.route=1;out.target=256;return 0xa0b0c0d0U;
 target_max:out.route=1;out.target=0xffffffffffffffffULL;return 0xa0b0c0d0U;
}
static int invoke(unsigned src,unsigned tag,__u64 target,unsigned table,unsigned skb,unsigned pattern)
{
 if(setjmp(refused))return 1;
 out.value=execute(src,tag,target,table,skb,pattern);return 0;
}
int main(void)
{
 const __u64 values[]={0,1,2,255,256,257,0xffffffffULL,0x100000000ULL,0x7fffffffffffffffULL,0x8000000000000000ULL,0xfffffffffffffffeULL,0xffffffffffffffffULL};
 unsigned long cases=0,outer=0,internal=0,rejections=0;
 for(unsigned src=0;src<32;src++)for(unsigned tag=0;tag<256;tag++)
 for(unsigned vi=0;vi<12;vi++)for(unsigned table=0;table<3;table++)
 for(unsigned skb=0;skb<2;skb++)for(unsigned pattern=0;pattern<16;pattern++){
  int denied=invoke(src,tag,values[vi],table,skb,pattern);
  __u64 target=src==31?0:values[vi];unsigned effective_tag=src==31?0:tag;
  int member=table==1?target==0:table==2&&(target==0||target==1||target==256||target==0xffffffffffffffffULL);
  int expected=target==0&&effective_tag==10?0:effective_tag==9&&member?1:-1;
  if(out.route!=expected||!!denied!=(expected==-1)){fprintf(stderr,"route src=%u tag=%u value=%llu table=%u\n",src,tag,(unsigned long long)target,table);return 1;}
  struct snapshot want=out.before;want.lr=target;
  unsigned input_count=0;
  if(expected==0){
   __u64 value=want.regs[0];if(want.tags[0]==4){value+=stack_base;input_count++;}else if(want.tags[0]==10){value+=return_base;input_count++;}
   if(out.value!=(__u32)value){fprintf(stderr,"value src=%u tag=%u pattern=%u got=%u want=%u\n",src,tag,pattern,out.value,(__u32)value);return 1;}
   /* RET preserves the live context and the separate ABI mirror. */
   outer++;
  }else if(expected==1){if(out.target!=target||out.value!=0xa0b0c0d0U)return 1;internal++;}
  else rejections++;
  if(memcmp(&want,&out.after,sizeof(want))||out.inputs!=input_count){fprintf(stderr,"frame src=%u tag=%u table=%u profile=%u\n",src,tag,table,skb);return 1;}
  cases++;
 }
 printf("arm64 RET token host cross-check: OK (%lu cases; outer=%lu internal=%lu refused=%lu)\n",cases,outer,internal,rejections);
 return 0;
}
