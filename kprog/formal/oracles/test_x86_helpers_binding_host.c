/* Detect wrong callee types, capacity/fact binding, result tags, clobber order
 * and helper output aliasing in the exported canonical C bodies. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "x86_helper_environment_host.h"
#define __bpf_fastcall
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../c/X86Helpers.h"

#undef __x86_stack_mem
#define __x86_stack_mem (*arena)
#undef X86_SIM_STACK_BYTES
#define X86_SIM_STACK_BYTES capacity
#undef X86_SIM_L_SV_TAG
#undef X86_SIM_L_SV_PTR
#define X86_SIM_L_SV_TAG(I) (*facts[(I)].tag)
#define X86_SIM_L_SV_PTR(I) (*facts[(I)].pointer)

static __u64 entropy, inputs[512];
static unsigned draws;
static unsigned long cases;
static int capture;
static void require(int ok)
{ if (!ok) { fprintf(stderr,"x86 helper binding mismatch at case %lu\n",cases); exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{
	require(kind == NATIVE_LAB_INPUT_UNSPECIFIED && draws < 512);
	entropy ^= entropy << 13; entropy ^= entropy >> 7; entropy ^= entropy << 17;
	inputs[draws++] = entropy; return entropy;
}
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p, __u8 kind, __u32 off)
{ (void)p; (void)kind; (void)off; abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p; abort(); }
void __builtin_memcpy_aligned(void *dst, const void *src, size_t size, size_t align)
{ require(align == 1); memcpy(dst, src, size); }

#define RESULT_KIND(TYPE) _Generic((TYPE *)0, void *:0, __u32 *:1, \
    __u64 *:2, long *:2, __s64 *:2, default:3)
static void invoke(unsigned id, int bound, struct x86_sim_register_state *state,
                   struct kprog_x86_arena *arena, struct kprog_x86_stack_fact *facts,
                   __u32 capacity)
{
	struct x86_sim_register_state *__x86_state = state;
	switch (id) {
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) \
	case ID: \
		if (bound) kprog_x86_helper_##NAME(state,arena,facts,capacity,NAME); \
		else { X86_SIM_BPF_CALL_##NAME(); } \
		require(ora_called == ID); \
		require((__u64)(uintptr_t)state->rax.ptr == (RESULT_KIND(RESULT) == 0 ? 0 : \
		    RESULT_KIND(RESULT) == 1 ? (__u32)ora_raw_result(ID) : ora_raw_result(ID))); \
		require(state->rax_tag == (RESULT_KIND(RESULT) == 3 ? X86_SIM_TAG_MAP_VALUE : X86_SIM_TAG_SCALAR)); \
		break;
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
	default: abort();
	}
}

struct fact_cell { __u64 before; __u8 tag; __u64 middle; void *pointer; __u64 after; };
static struct x86_sim_register_state state, initial, saved;
static union { __u64 q[48]; __u8 b[384]; __u32 d[96]; __u16 w[192]; } storage;
static struct kprog_x86_arena arena = {storage.b, storage.q, storage.w, storage.d};
static struct fact_cell cells[47], initial_cells[47], saved_cells[47];
static struct kprog_x86_stack_fact facts[47];
static __u8 saved_bytes[384];
static void record(unsigned id, unsigned capacity)
{
	if (!capture) return;
	const __u32 header[]={id,capacity,draws,ora_argc};
	require(fwrite(header,sizeof(header),1,stdout)==1 &&
	    fwrite(&state,sizeof(state),1,stdout)==1 &&
	    fwrite(storage.b,sizeof(storage),1,stdout)==1 &&
	    fwrite(cells,sizeof(cells),1,stdout)==1 &&
	    fwrite(ora_arguments,sizeof(ora_arguments),1,stdout)==1 &&
	    fwrite(inputs,sizeof(*inputs),draws,stdout)==draws);
}

static void initialize(unsigned capacity, unsigned seed, unsigned stack_case)
{
	memset(&state, 0xa5, sizeof(state));
	for (unsigned r=0;r<16;++r) {
		state.gpr_cells[r].value.ptr = (void *)(uintptr_t)(0xfedcba9800000000ULL + r*0x101 + seed);
		state.gpr_cells[r].tag = (r+seed)%9;
	}
	state.rsp.ptr = (void *)(intptr_t)(stack_case == 0 ? -(__s64)capacity :
	    stack_case == 1 ? -(__s64)(capacity/2) : 0);
	state.native_stack_base = 0x1234567800001000ULL + seed*0x100;
	state.helper_abi_base = state.rdi.ptr;
	state.helper_ctx = (void *)(uintptr_t)0x2233445500006789ULL;
	state.cf=3;state.zf=5;state.sf=7;state.of=9;state.pf=11;state.af=13;
	state.xmm0_lo=0x9876543210012345ULL;state.xmm0_hi=0xabcdef0123456789ULL;
	for (unsigned i=0;i<384;++i) storage.b[i]=(__u8)(i*17+seed);
	for (unsigned i=0;i<(capacity+7)/8;++i) {
		memset(&cells[i],0x5a,sizeof(cells[i]));
		cells[i].before=0x1111222233334444ULL;cells[i].middle=~cells[i].before;cells[i].after=seed;
		cells[i].tag=(i+seed)%9;cells[i].pointer=(void *)(uintptr_t)(0xaabbccdd00001000ULL+i*8);
		facts[i].tag=&cells[i].tag;facts[i].pointer=&cells[i].pointer;
	}
	memcpy(&initial,&state,sizeof(state));memcpy(initial_cells,cells,sizeof(cells));
}

static void registry(void)
{
	static const unsigned ids[] = {
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) ID,
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
	};
	const unsigned capacities[]={1,7,9,64,200,376};
	for (unsigned p=0;p<6;++p) for (unsigned s=0;s<3;++s)
	for (unsigned seed=1;seed<=4;++seed) for (unsigned i=0;i<sizeof(ids)/sizeof(*ids);++i) {
		unsigned cap=capacities[p], count, argc; __u64 seen[5], stream[512];
		initialize(cap,seed,s);
		entropy=seed;draws=ora_called=ora_argc=0;memset(ora_arguments,0,sizeof(ora_arguments));
		invoke(ids[i],0,&state,&arena,facts,cap);
		memcpy(&saved,&state,sizeof(state));memcpy(saved_cells,cells,sizeof(cells));
		memcpy(saved_bytes,storage.b,sizeof(storage));memcpy(stream,inputs,sizeof(inputs));
		memcpy(seen,ora_arguments,sizeof(seen));count=draws;argc=ora_argc;
		memcpy(&state,&initial,sizeof(state));memcpy(cells,initial_cells,sizeof(cells));
		for (unsigned j=0;j<384;++j) storage.b[j]=(__u8)(j*17+seed);
		entropy=seed;draws=ora_called=ora_argc=0;memset(ora_arguments,0,sizeof(ora_arguments));
		invoke(ids[i],1,&state,&arena,facts,cap);
		require(!memcmp(&saved,&state,sizeof(state)) && !memcmp(saved_cells,cells,sizeof(cells)) &&
		    !memcmp(saved_bytes,storage.b,sizeof(storage)) && draws==count && argc==ora_argc &&
		    !memcmp(stream,inputs,count*sizeof(*inputs)) && !memcmp(seen,ora_arguments,sizeof(seen)));
		unsigned released=(unsigned)((__s64)cap+(__s64)(intptr_t)initial.rsp.ptr);
		unsigned packed=released/8+released%8;
		require(draws==packed+16);
		const unsigned clobbered[]={X86_RCX,X86_RDX,X86_RSI,X86_RDI,X86_R8,X86_R9,X86_R10,X86_R11};
		for (unsigned j=0;j<8;++j)
			require((__u64)(uintptr_t)state.gpr_cells[clobbered[j]].value.ptr==inputs[packed+j] &&
			    state.gpr_cells[clobbered[j]].tag==0);
		require(state.cf==(inputs[packed+8]&1) && state.zf==(inputs[packed+9]&1) &&
		    state.sf==(inputs[packed+10]&1) && state.of==(inputs[packed+11]&1) &&
		    state.pf==(inputs[packed+12]&1) && state.af==(inputs[packed+13]&1) &&
		    state.xmm0_lo==inputs[packed+14] && state.xmm0_hi==inputs[packed+15]);
		for (unsigned r=0;r<16;++r) if (r==X86_RSP || r==X86_RBX || r==X86_RBP || r>=X86_R12)
			require(!memcmp(&state.gpr_cells[r],&initial.gpr_cells[r],sizeof(state.gpr_cells[r])));
		record(ids[i],cap);cases++;
	}
}

static jmp_buf refusal;
static int refuse;
static unsigned requested_size;
static long write_helper(void *dst, __u32 size, const void *src)
{
	require(dst==storage.b && size==requested_size && src==storage.b+4 && draws==0);
	memmove(dst,src,size);
	/* The post-call invalidation must use the arguments captured before the
	 * callee changed their register cells. This also exposes a copied state. */
	state.rdi.ptr=storage.b+24;state.rsi.ptr=(void *)1;
	if (refuse) longjmp(refusal,1);
	return -9;
}
static void output_alias(void)
{
	const unsigned sizes[]={0,1,8,9,256};
	for (refuse=0;refuse<2;++refuse) for (volatile unsigned s=0;s<5;++s) for (volatile int bound=0;bound<2;++bound) {
		requested_size=sizes[s];initialize(376,1,0);
		state.rdi.ptr=storage.b;state.rdi_tag=X86_SIM_TAG_STACK;
		state.rsi.ptr=(void *)(uintptr_t)(0x100000000ULL+requested_size);state.rsi_tag=X86_SIM_TAG_SCALAR;
		state.rdx.ptr=storage.b+4;state.rdx_tag=X86_SIM_TAG_STACK;
		for (unsigned i=0;i<47;++i) cells[i].tag=X86_SIM_TAG_STACK;
		entropy=1;draws=0;
		if (!setjmp(refusal)) {
			if (bound) kprog_x86_helper_bpf_probe_read(&state,&arena,facts,376,write_helper);
			else {
				struct x86_sim_register_state *__x86_state=&state;
				unsigned capacity=376;
				struct kprog_x86_arena *arena=&(struct kprog_x86_arena){storage.b,storage.q,storage.w,storage.d};
				/* Shadow the real typed helper name, keeping its invocation macro. */
				long (*bpf_probe_read)(void *,__u32,const void *)=write_helper;
				X86_SIM_BPF_CALL_bpf_probe_read();
			}
			require(!refuse);
		}
		if (!bound) {
			memcpy(&saved,&state,sizeof(state));memcpy(saved_cells,cells,sizeof(cells));
			memcpy(saved_bytes,storage.b,sizeof(storage));
		} else require(!memcmp(&saved,&state,sizeof(state)) &&
		    !memcmp(saved_cells,cells,sizeof(cells)) && !memcmp(saved_bytes,storage.b,sizeof(storage)));
		require(draws==(refuse?0:16));
		if (refuse) require(state.rax.ptr==initial.rax.ptr && state.rax_tag==initial.rax_tag);
		for (unsigned i=0;i<384;++i)
			require(storage.b[i]==(__u8)((i+(i<requested_size?4:0))*17+1));
		for (unsigned i=0;i<47;++i)
			require(cells[i].tag==(!refuse && i*8<requested_size ? X86_SIM_TAG_SCALAR:X86_SIM_TAG_STACK));
		cases++;
	}
}

int main(int argc, char **argv)
{
	capture=argc==2 && !strcmp(argv[1],"--capture");require(argc==1||capture);
	registry();
	unsigned long registry_cases=cases;
	output_alias();
	fprintf(stderr,"x86 typed helper bindings: %lu paired registry comparisons and %lu alias/refusal executions\n",
	        registry_cases,cases-registry_cases);
	return 0;
}
