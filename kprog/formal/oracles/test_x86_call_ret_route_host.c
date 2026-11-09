/*
 * Host cross-check for the x86 simulator's call and subroutine-return emission
 * (`X86_SIM_X86_CALL`, `X86_SIM_X86_SUB_RET`, and the `SUB_JMP` / `SUB_JCC`
 * aliases).
 *
 * Why this host exists. Step 0529/0530 executed the AArch64 emission surface
 * and found every emitter there had been undriven. The x86 surface is larger --
 * it has a real call/return pair, which AArch64 models through the link
 * register instead -- and none of it was executed either: no host mentions
 * X86_SIM_X86_CALL, X86_SIM_X86_RET, X86_SIM_X86_SUB_RET, X86_SIM_X86_SUB_JMP
 * or X86_SIM_X86_SUB_JCC.
 *
 * The x86 pair is worth more than the AArch64 one because it moves the stack
 * pointer. CALL decrements `rsp` by eight and writes the return address there;
 * SUB_RET reads that word back and increments by eight. A pair that disagreed
 * -- write at one width, read at another, or increment without a matching
 * decrement -- would corrupt `rsp` and return through a stale word, and every
 * check that inspects the address alone would still pass.
 *
 * What is checked:
 *
 *   - CALL decrements `rsp` by exactly eight and stores the return address at
 *     the new top of stack;
 *   - SUB_RET reads that address back into the simulator's return slot,
 *     restores `rsp` to its original value, and transfers control to its
 *     dispatch label;
 *   - the round trip is exact for addresses whose bytes are all distinct, so a
 *     width or endianness slip shows;
 *   - RET returns the low word of the accumulator and preserves the live skb
 *     control block;
 *   - SUB_JMP and SUB_JCC select the same targets as JMP and JCC, which is
 *     what makes them aliases rather than variants -- driven in *both* the
 *     taken and the not-taken direction, since a conditional degraded to an
 *     unconditional jump passes a taken-only test.
 *
 * Build and run:
 *   cd kprog/formal &&
 *   cc -Wall -Wextra -O2 -I. -I../x86 -I../../kprog \
 *      -I../../runner/build-host-docker-llvmbpf/vendor/libbpf/prefix/include/bpf \
 *      test_x86_call_ret_route_host.c -o build/test_x86_call_ret_route_host &&
 *   ./build/test_x86_call_ret_route_host
 */

#define X86_SIM_ENABLE_STACK 1
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef unsigned int __u32;
typedef unsigned long long __u64;
typedef signed char __s8;
typedef signed short __s16;
typedef signed int __s32;
typedef signed long long __s64;

#define __always_inline inline

#include "../x86/x86_sim_local_bpf.h"

#include <stdio.h>

static unsigned long unsupported_calls;
static void xcpu_sim_unsupported_opcode(void)
{
	unsupported_calls++;
}

/* A frame inside the modelled arena: the index is OFF + CAPACITY, so a
 * valid offset is negative and at most CAPACITY in magnitude. */
#define BASE ((__s64)(-(__s64)X86_SIM_STACK_BYTES / 2))

static int failures;
static unsigned long cases;

/* The simulator's state is ambient for the non-struct build, so a file-scope
 * declaration is what the emission macros expect. */
#define DECL_STATE()                                                       \
	X86_SIM_L_DECLARE_STATE();                                         \
	X86_SIM_L_DECLARE_STACK();                                         \
	struct x86_sim_xdp_abi __x86_sim_abi = { 0 };                      \
	struct __sk_buff *__x86_sim_skb_ctx = (struct __sk_buff *)0;       \
	(void)__x86_sim_skb_ctx

/* Where the callee "lands". */
static int hit_target;
/* Where the callee "dispatches" back to. */
static int hit_dispatch;

/* Drive CALL, observing the stack pointer and the stored word before jumping. */
static void probe_call(__u64 ret_addr, __u64 *rsp_after, __u64 *slot)
{
	DECL_STATE();

	__x86_rsp.ptr = (void *)(long)BASE;
	
	hit_target = 0;

	goto dispatch;

arrived:
	*rsp_after = (__u64)(long)__x86_rsp.ptr;
	*slot = __x86_stack_mem.q[KPROG_X86_STACK_WORD_INDEX(
		X86_SIM_L_STACK_INDEX((__s64)(BASE - 8)))];
	hit_target = 1;
	return;

dispatch:
	X86_SIM_X86_CALL(arrived, ret_addr);
	return;
}

/* Drive SUB_RET from a prepared stack. */
static void probe_sub_ret(__u64 ret_addr, __u64 rsp_in, __u64 *rsp_out,
			  __u64 *ret_slot)
{
	DECL_STATE();

	__x86_rsp.ptr = (void *)(long)rsp_in;
	__x86_stack_mem.q[KPROG_X86_STACK_WORD_INDEX(
		X86_SIM_L_STACK_INDEX((__s64)rsp_in))] = ret_addr;
	__x86_sim_ret_addr = 0;
	hit_dispatch = 0;

	goto dispatch;

dispatched:
	*rsp_out = (__u64)(long)__x86_rsp.ptr;
	*ret_slot = __x86_sim_ret_addr;
	hit_dispatch = 1;
	return;

dispatch:
	X86_SIM_X86_SUB_RET(dispatched);
	return;
}


#define SUB_TARGET 0xABCDULL

/* X86_SIM_X86_RET returns from the calling function, so it needs its own. */
/* X86_SIM_X86_RET ends in a `return` from the calling function, so the
 * driving scope has to be inside the probe: it declares the state, plants rax
 * and the live cb words, and the returned value is the function's result. */
static __u32 probe_ret_value(__u64 rax_value, struct __sk_buff *ctx,
			      __u32 cb0, __u32 cb1)
{
	DECL_STATE();

	__x86_rax.ptr = (void *)(long)rax_value;
	__x86_sim_skb_ctx = ctx;
	ctx->cb[0] = cb0;
	ctx->cb[1] = cb1;
	X86_SIM_X86_RET();
	return 0;
}

/* SUB_JMP: an unconditional subroutine jump. */
static __u64 probe_sub_jmp(void)
{
	__u64 got;
	DECL_STATE();
	goto dispatch;

arrived:
	got = SUB_TARGET;
	return got;

dispatch:
	X86_SIM_X86_SUB_JMP(0, 0, arrived);
	got = 0;
	return got;
}

/* SUB_JCC: a conditional subroutine jump. */
static __u64 probe_sub_jcc(unsigned cc, __u64 current, __u64 target,
			    int zf, int zf_unused)
{
	__u64 got;
	DECL_STATE();
	(void)zf_unused;
	__x86_cf = 1;
	__x86_zf = (__u8)zf;
	__x86_sf = 0;
	__x86_of = 0;
	goto dispatch;

arrived:
	got = target;
	return got;

dispatch:
	X86_SIM_X86_SUB_JCC(cc, current, target, arrived);
	got = current;
	return got;
}

/* Complete emitted-CALL frame: the saved word, numeric/raw/tag cells,
 * vector, flags and every stack byte survive the exact branch transfer. */
static unsigned long frame_cases;
static __u8 native_call_stack[X86_SIM_STACK_BYTES];
static void probe_call_frame(__u64 saved, unsigned depth, unsigned fs, unsigned profile)
{
 DECL_STATE();
 __x86_native_stack_base=(__u64)(long)&native_call_stack[X86_SIM_STACK_BYTES];
 __u64 before[16], raw[16]; __u8 tags[16], expected[X86_SIM_STACK_BYTES];
 __u64 vector_lo=0x1122334455667788ULL^saved, vector_hi=~vector_lo;
 for(unsigned i=0;i<X86_SIM_STACK_BYTES;i++)__x86_stack_mem.b[i]=expected[i]=(__u8)(i*137+29);
 for(unsigned r=0;r<16;r++) {
  unsigned kind=(r+profile)%4;
  __u8 tag=kind==1?X86_SIM_TAG_ABI:kind==2?X86_SIM_TAG_STACK:kind==3?X86_SIM_TAG_CODE:X86_SIM_TAG_SCALAR;
  void *value=kind==2?(void *)&__x86_stack_mem.b[(r*3+profile)%(X86_SIM_STACK_BYTES-8)]:(void *)(long)(0x1020304050607080ULL+r*0x100020003ULL);
  X86_SIM_L_WRITE_REG_PTR_TAG(r,value,tag);
 }
 __x86_rsp.ptr=(void *)(long)-(__s64)depth;
 __x86_cf=!!(fs&1);__x86_pf=!!(fs&2);__x86_af=!!(fs&4);__x86_zf=!!(fs&8);__x86_sf=!!(fs&16);__x86_of=!!(fs&32);
 __x86_xmm0_lo=vector_lo;__x86_xmm0_hi=vector_hi;
 for(unsigned r=0;r<16;r++){before[r]=X86_SIM_L_READ_REG(r);raw[r]=(__u64)(long)X86_SIM_L_REG_VALUE(r);tags[r]=X86_SIM_L_REG_TAG(r);}
 unsigned at=X86_SIM_STACK_BYTES-depth-8;
 for(unsigned i=0;i<8;i++)expected[at+i]=(__u8)(saved>>(8*i));
 goto dispatch;
arrived:
 frame_cases++;
 for(unsigned r=0;r<16;r++) {
  __u64 delta=r==X86_RSP?8:0;
  if(X86_SIM_L_READ_REG(r)!=before[r]-delta||(__u64)(long)X86_SIM_L_REG_VALUE(r)!=raw[r]-delta||X86_SIM_L_REG_TAG(r)!=tags[r]) {
   printf("CALL full register frame r=%u depth=%u flags=%u profile=%u\n",r,depth,fs,profile);failures++;return;
  }
 }
 for(unsigned i=0;i<X86_SIM_STACK_BYTES;i++)if(__x86_stack_mem.b[i]!=expected[i]) {
  printf("CALL full stack image byte=%u depth=%u\n",i,depth);failures++;return;
 }
 if(__x86_xmm0_lo!=vector_lo||__x86_xmm0_hi!=vector_hi||__x86_cf!=!!(fs&1)||__x86_pf!=!!(fs&2)||__x86_af!=!!(fs&4)||__x86_zf!=!!(fs&8)||__x86_sf!=!!(fs&16)||__x86_of!=!!(fs&32)) {
  printf("CALL full flag/vector frame depth=%u\n",depth);failures++;
 }
 return;
dispatch:
 X86_SIM_X86_CALL(arrived,saved);
}

/* SUB_RET preserves the complete frame while reading the old stack slot. */
static unsigned long return_frame_cases,return_switch_hits,return_switch_fallthroughs;
static void probe_return_frame(__u64 saved, unsigned depth, unsigned fs, unsigned profile, unsigned table)
{
 DECL_STATE();
 int hit=-1;
 __x86_native_stack_base=(__u64)(long)&native_call_stack[X86_SIM_STACK_BYTES];
 __u64 before[16], raw[16]; __u8 tags[16], expected[X86_SIM_STACK_BYTES];
 __u64 vector_lo=0x1122334455667788ULL^saved, vector_hi=~vector_lo;
 for(unsigned i=0;i<X86_SIM_STACK_BYTES;i++)__x86_stack_mem.b[i]=expected[i]=(__u8)(i*137+29);
 for(unsigned r=0;r<16;r++) {
  unsigned kind=(r+profile)%4;
  __u8 tag=kind==1?X86_SIM_TAG_ABI:kind==2?X86_SIM_TAG_STACK:kind==3?X86_SIM_TAG_CODE:X86_SIM_TAG_SCALAR;
  void *value=kind==2?(void *)&__x86_stack_mem.b[(r*3+profile)%(X86_SIM_STACK_BYTES-8)]:(void *)(long)(0x1020304050607080ULL+r*0x100020003ULL);
  X86_SIM_L_WRITE_REG_PTR_TAG(r,value,tag);
 }
 __x86_rsp.ptr=(void *)(long)-(__s64)depth;
 __x86_cf=!!(fs&1);__x86_pf=!!(fs&2);__x86_af=!!(fs&4);__x86_zf=!!(fs&8);__x86_sf=!!(fs&16);__x86_of=!!(fs&32);
 __x86_xmm0_lo=vector_lo;__x86_xmm0_hi=vector_hi;
 for(unsigned r=0;r<16;r++){before[r]=X86_SIM_L_READ_REG(r);raw[r]=(__u64)(long)X86_SIM_L_REG_VALUE(r);tags[r]=X86_SIM_L_REG_TAG(r);}
 unsigned at=X86_SIM_STACK_BYTES-depth;
 /* SUB_RET reads the saved word, then releases its eight private bytes. */
 for(unsigned i=0;i<8;i++){__x86_stack_mem.b[at+i]=(__u8)(saved>>(8*i));expected[at+i]=0;}
 goto dispatch;
arrived:
 hit=1;
 goto observed;
unmatched:
 hit=0;
observed:
 return_frame_cases++;
 if(hit!=(table==2||(table==1&&saved==0))){printf("SUB_RET continuation table=%u saved=%llx\n",table,(unsigned long long)saved);failures++;return;}
 if(hit)return_switch_hits++;else return_switch_fallthroughs++;
 if(__x86_sim_ret_addr!=saved){printf("SUB_RET saved word mismatch depth=%u\n",depth);failures++;return;}
 for(unsigned r=0;r<16;r++) {
  __u64 delta=r==X86_RSP?8:0;
  if(X86_SIM_L_READ_REG(r)!=before[r]+delta||(__u64)(long)X86_SIM_L_REG_VALUE(r)!=raw[r]+delta||X86_SIM_L_REG_TAG(r)!=tags[r]) {
   printf("SUB_RET full register frame r=%u depth=%u flags=%u profile=%u\n",r,depth,fs,profile);failures++;return;
  }
 }
 for(unsigned i=0;i<X86_SIM_STACK_BYTES;i++)if(__x86_stack_mem.b[i]!=expected[i]) {
  printf("SUB_RET full stack image byte=%u depth=%u\n",i,depth);failures++;return;
 }
 if(__x86_xmm0_lo!=vector_lo||__x86_xmm0_hi!=vector_hi||__x86_cf!=!!(fs&1)||__x86_pf!=!!(fs&2)||__x86_af!=!!(fs&4)||__x86_zf!=!!(fs&8)||__x86_sf!=!!(fs&16)||__x86_of!=!!(fs&32)) {
  printf("SUB_RET full flag/vector frame depth=%u\n",depth);failures++;
 }
 return;
dispatch:
 X86_SIM_X86_SUB_RET(ret_dispatch);
ret_dispatch:
 if(table==1){switch(__x86_sim_ret_addr){case 0ULL:goto arrived;}}
 else if(table==2){switch(__x86_sim_ret_addr){
  case 0ULL:goto arrived;
  case 1ULL:goto arrived;
  case 0xffULL:goto arrived;
  case 0x100ULL:goto arrived;
  case 0x7fffULL:goto arrived;
  case 0x8000ULL:goto arrived;
  case 0x7fffffffULL:goto arrived;
  case 0x80000000ULL:goto arrived;
  case 0x7fffffffffffffffULL:goto arrived;
  case 0x8000000000000000ULL:goto arrived;
  case 0xffffffffffffffffULL:goto arrived;
  case 0x1122334455667788ULL:goto arrived;
  case 0x00ff00ff00ff00ffULL:goto arrived;
 }}
 goto unmatched;
}

int main(void)
{
	static const __u64 rets[] = {
		0x1122334455667788ULL,
		0x0000000000000001ULL,
		0xffffffffffffffffULL,
		0x00ff00ff00ff00ffULL,
	};
	unsigned i;

	for (i = 0; i < sizeof(rets) / sizeof(rets[0]); i++) {
		__u64 rsp_after = 0, slot = 0;
		__u64 rsp_out = 0, got_ret = 0;

		probe_call(rets[i], &rsp_after, &slot);
		cases++;

		if (hit_target != 1) {
			printf("CALL v=%#llx: did not transfer control\n",
			       (unsigned long long)rets[i]);
			failures++;
		}
		if (rsp_after != (__u64)(BASE - 8)) {
			printf("CALL v=%#llx: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)rsp_after,
			       (unsigned long long)(BASE - 8));
			failures++;
		}
		if (slot != rets[i]) {
			printf("CALL v=%#llx: stored %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)slot);
			failures++;
		}

		probe_sub_ret(rets[i], (__u64)(BASE - 8), &rsp_out, &got_ret);
		cases++;

		if (hit_dispatch != 1) {
			printf("SUB_RET v=%#llx: did not dispatch\n",
			       (unsigned long long)rets[i]);
			failures++;
		}
		if (got_ret != rets[i]) {
			printf("SUB_RET v=%#llx: read %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)got_ret);
			failures++;
		}
		if (rsp_out != (__u64)BASE) {
			printf("SUB_RET v=%#llx: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rets[i],
			       (unsigned long long)rsp_out,
			       (unsigned long long)BASE);
			failures++;
		}
	}

	/* CALL then SUB_RET as a pair: the stack pointer must return to where
	 * it started, which is the property a mismatched pair breaks. */
	{
		__u64 rsp_after = 0, slot = 0, rsp_out = 0, got_ret = 0;

		probe_call(0xCAFEF00DDEADBEEFULL, &rsp_after, &slot);
		probe_sub_ret(slot, rsp_after, &rsp_out, &got_ret);
		cases++;

		if (rsp_out != (__u64)BASE) {
			printf("round trip: rsp is %#llx, want %#llx\n",
			       (unsigned long long)rsp_out,
			       (unsigned long long)BASE);
			failures++;
		}
		if (got_ret != 0xCAFEF00DDEADBEEFULL) {
			printf("round trip: return address is %#llx\n",
			       (unsigned long long)got_ret);
			failures++;
		}
	}

	/* X86_SIM_X86_RET returns the low word of rax -- the program's return
	 * value -- so a truncation or a wrong register shows here. It also
	 * preserves the live skb cb words installed in the probe. */
	{
		static struct __sk_buff skb;
		__u32 got;

		skb.cb[0] = 0;
		skb.cb[1] = 0;
		cases++;
		got = probe_ret_value(0xDEADBEEFCAFEF00DULL, &skb,
				      0x11223344, 0x55667788);

		if (got != 0xCAFEF00DUL) {
			printf("RET: returned %#x, want %#x (low word of rax)\n",
			       got, 0xCAFEF00DU);
			failures++;
		}
		if (skb.cb[0] != 0x11223344 || skb.cb[1] != 0x55667788) {
			printf("RET: skb cb words are %#x %#x\n", skb.cb[0],
			       skb.cb[1]);
			failures++;
		}
	}

	/* SUB_JMP and SUB_JCC are aliases of JMP and JCC -- the same target
	 * selection with a subroutine-flavoured name. Driving them confirms
	 * the aliasing rather than assuming it from the definition. */
	{
		__u64 got;
		int taken;

		DECL_STATE();
		cases++;
		got = probe_sub_jmp();
		if (got != SUB_TARGET) {
			printf("SUB_JMP: arrived at %#llx, want %#llx\n",
			       (unsigned long long)got,
			       (unsigned long long)SUB_TARGET);
			failures++;
		}

		for (taken = 0; taken < 2; taken++) {
			int n = taken, z = 0, c = 1, v = 0;

			DECL_STATE();
			__x86_cf = (__u8)c;
			__x86_zf = (__u8)z;
			__x86_sf = (__u8)n;
			__x86_of = (__u8)v;
			cases++;
			/* CC 0x5 is NE. With zf = 1 the condition fails and
			 * control must fall through; with zf = 0 it holds and
			 * control must reach the target. Driving only the true
			 * case would pass with SUB_JCC degraded to an
			 * unconditional jump, so both are needed. */
			got = probe_sub_jcc(0x5U, 100, 200, /*zf=*/1, 0);
			if (got != 100) {
				printf("SUB_JCC: NE with zf=1 arrived at %#llx, "
				       "want the fall-through 100\n",
				       (unsigned long long)got);
				failures++;
			}

			got = probe_sub_jcc(0x5U, 100, 200, /*zf=*/0, 1);
			if (got != 200) {
				printf("SUB_JCC: NE with zf=0 arrived at %#llx, "
				       "want the target 200\n",
				       (unsigned long long)got);
				failures++;
			}
		}
	}

 {
  static const __u64 words[]={0,1,0xff,0x100,0x7fff,0x8000,0x7fffffff,0x80000000ULL,0x7fffffffffffffffULL,0x8000000000000000ULL,0xffffffffffffffffULL,0x1122334455667788ULL,0x00ff00ff00ff00ffULL};
  for(unsigned n=0;n<sizeof(words)/sizeof(words[0]);n++)for(unsigned depth=0;depth<64;depth+=8)for(unsigned fs=0;fs<64;fs++)for(unsigned profile=0;profile<4;profile++)
   probe_call_frame(words[n],depth,fs,profile);
  printf("x86 CALL full frame cross-check: %lu cases\n",frame_cases);
  for(unsigned n=0;n<sizeof(words)/sizeof(words[0]);n++)for(unsigned depth=8;depth<=64;depth++)for(unsigned fs=0;fs<64;fs++)for(unsigned profile=0;profile<4;profile++)
   for(unsigned table=0;table<3;table++)probe_return_frame(words[n],depth,fs,profile,table);
  printf("x86 SUB_RET full frame/switch cross-check: %lu cases; selected=%lu fallthrough=%lu\n",return_frame_cases,return_switch_hits,return_switch_fallthroughs);
 }
	if (failures) {
		printf("x86 call/ret route host cross-check: FAIL (%d/%lu)\n",
		       failures, cases);
		return 1;
	}
	printf("x86 call/ret route host cross-check: OK (%lu cases)\n", cases);
	return 0;
}