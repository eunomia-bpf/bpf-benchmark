/* INC/DEC must move pointer representatives, not their exposed native bits.
 * Narrow/lane writes remain scalar, and CF plus unrelated state stay framed. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../../x86/x86_sim_inline.h"
#if INLINE
X86_SIM_DECLARE_INSTRUCTION(__x86_instruction_X86_OP_ALU_IMM, X86_OP_ALU_IMM)
#endif
static unsigned long cases;
static unsigned draws;
static void require(int ok)
{ if (!ok) { fprintf(stderr,"x86 INC/DEC pointer mismatch at case %lu\n",cases);exit(1); } }
unsigned long native_lab_entry_input(unsigned kind)
{ require(kind==NATIVE_LAB_INPUT_UNSPECIFIED);++draws;return 0x123456789abcdeaaULL; }
void kprog_c_trap(void) { abort(); }
void *kprog_c_context_pointer(const void *p,__u8 k,__u32 o)
{ (void)p;(void)k;(void)o;abort(); }
__u64 kprog_c_pointer_bits(const void *p) { (void)p;abort(); }
void __builtin_memcpy_aligned(void *d,const void *s,size_t n,size_t a)
{ require(a==1);memcpy(d,s,n); }

static void execute(struct x86_sim_state *state,__u8 *tags,void **pointers,
                    unsigned dst,unsigned width,unsigned alu,unsigned shift,__u64 imm)
{
	struct x86_sim_state *__x86_state=state;
	__u8 *__x86_stack_value_tags=tags;
	void **__x86_stack_value_ptrs=pointers;
#if INLINE
	X86_SIM_BIND_INLINE();
	X86_SIM_RUN_OP(X86_OP_ALU_IMM,dst,X86_REG_NONE,width,alu|(shift<<8),imm);
#else
	X86_SIM_L_EXEC_ALU_IMM(dst,width,alu|(shift<<8),imm);
#endif
}
static void check_case(unsigned dst,unsigned tag,unsigned width,unsigned shift,
                       int dec,__u64 imm,unsigned carry)
{
	struct x86_sim_state state,expected;
	__u8 tags[8],saved_tags[8];void *pointers[8],*saved_pointers[8];
	__u8 region[128];
	memset(&state,0xa5,sizeof(state));memset(region,0x5a,sizeof(region));
	state.rsp.ptr=(void *)(intptr_t)-32;state.native_stack_base=0xfedcba9800011000ULL;
	state.cf=carry;
	state.gpr_cells[dst].tag=tag;
	state.gpr_cells[dst].value.ptr=dst==X86_RSP ? (void *)(intptr_t)-32 :
	    tag==X86_SIM_TAG_STACK ? (void *)&state.stack_mem.b[24] : (void *)&region[40];
	for (unsigned i=0;i<8;++i) {tags[i]=i+1;pointers[i]=(void *)(uintptr_t)(0x12340000+i*8);}
	memcpy(&expected,&state,sizeof(state));memcpy(saved_tags,tags,sizeof(tags));
	memcpy(saved_pointers,pointers,sizeof(pointers));
	__u64 raw=(__u64)(uintptr_t)state.gpr_cells[dst].value.ptr;
	__u64 numeric=dst==X86_RSP ? state.native_stack_base-32 :
	    tag==X86_SIM_TAG_STACK ? state.native_stack_base-40 : raw;
	unsigned effective=(__u8)width;if (!effective) effective=8;
	unsigned bits=effective==1?8:effective==2?16:effective==4?32:64;
	__u64 mask=bits==64?~0ULL:(1ULL<<bits)-1;
	__u64 lhs=(numeric>>(bits==8?shift:0))&mask;
	__u64 result=(lhs+(dec?~0ULL:1ULL))&mask;
	__u64 value=bits==8 ? (numeric&~(255ULL<<shift))|(result<<shift) :
	    bits==16 ? (numeric&~65535ULL)|result : result;
	int memory=tag==1||tag==2||tag==3||tag==4||tag==6;
	if (dst!=X86_RSP && effective==8 && shift==0 && memory) {
		expected.gpr_cells[dst].value.ptr=(void *)(uintptr_t)(raw+(dec?~0ULL:1ULL));
	} else {
		expected.gpr_cells[dst].value.ptr=(void *)(uintptr_t)(dst==X86_RSP ? value-state.native_stack_base : value);
		expected.gpr_cells[dst].tag=X86_SIM_TAG_SCALAR;
	}
	unsigned parity=0;for (unsigned i=0;i<8;++i) parity^=(result>>i)&1;
	expected.cf=carry;expected.zf=result==0;expected.sf=result>>(bits-1);
	expected.of=lhs==(dec ? 1ULL<<(bits-1) : (1ULL<<(bits-1))-1);
	expected.af=dec ? (lhs&15)==0 : (lhs&15)==15;expected.pf=!parity;
	if (dst==X86_RSP && !dec) {
		expected.stack_mem.b[32]=0xaa;
		for (unsigned i=0;i<5;++i) {saved_tags[i]=0;saved_pointers[i]=NULL;}
	}
	draws=0;
	execute(&state,tags,pointers,dst,width,dec?X86_ALU_DEC:X86_ALU_INC,shift,imm);
	require(!memcmp(&state,&expected,sizeof(state)) &&
	    !memcmp(tags,saved_tags,sizeof(tags)) && !memcmp(pointers,saved_pointers,sizeof(pointers)) &&
	    draws==(dst==X86_RSP&&!dec));
	cases++;
}
int main(void)
{
	const unsigned regs[]={X86_RDI,X86_RSI},widths[]={0,1,2,4,8,255},carries[]={0,1,255};
	const __u64 immediates[]={0,1,~0ULL};
	for (unsigned r=0;r<2;++r) for (unsigned tag=0;tag<256;++tag)
	for (unsigned w=0;w<6;++w) for (unsigned shift=0;shift<=8;shift+=8)
	for (unsigned dec=0;dec<2;++dec) for (unsigned i=0;i<3;++i) for (unsigned c=0;c<3;++c)
		check_case(regs[r],tag,widths[w],shift,dec,immediates[i],carries[c]);
	for (unsigned tag=0;tag<256;++tag) for (unsigned dec=0;dec<2;++dec)
	for (unsigned i=0;i<3;++i) for (unsigned c=0;c<3;++c)
		check_case(X86_RSP,tag,8,0,dec,immediates[i],carries[c]);
	printf("x86 INC/DEC: %lu pointer/scalar/lane/flag/SP/full-frame cases\n",cases);
	return 0;
}
