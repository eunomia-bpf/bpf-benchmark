/* Catch wrong cell/lane/profile binding, eager unused-reference reads and
 * leaked expression adapters in the actual inline interpreter header. */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X86_SIM_ENABLE_STACK 1
#define X86_SIM_USE_STATE_STRUCT 1
#include "../../x86/x86_sim_inline.h"

static unsigned long cases;
static void check(int ok, const char *why)
{
	if (!ok) { fprintf(stderr,"inline binding case %lu: %s\n",cases,why); exit(1); }
}
unsigned long native_lab_entry_input(unsigned kind)
{
	(void)kind; fputs("unexpected input in register observation\n",stderr); abort();
}
void kprog_c_trap(void) { fputs("unexpected inline trap\n",stderr); abort(); }

int main(void)
{
	struct x86_sim_state state, before;
	struct x86_sim_state *__x86_state = &state;
	struct x86_sim_inline_bindings binding = {0};
	const __u64 registers[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,255,256,0x100000004ULL,~0ULL};
	const __u64 widths[] = {0,1,2,4,8,255,256,0x100000001ULL,~0ULL};
	const __u64 shifts[] = {0,8,256,0x100000008ULL};
	const __u64 origins[] = {0,0x123456789abcdef0ULL,~0ULL};
	memset(&state,0x5a,sizeof(state));
#define CHECK_CELL(REG, NAME) \
	check((void *)&state.NAME == (void *)&state.gpr_cells[REG].value && \
	      &state.NAME##_tag == &state.gpr_cells[REG].tag,"named/indexed cell ABI");
	X86_SIM_L_FOR_EACH_GPR(CHECK_CELL)
#undef CHECK_CELL
	for (unsigned t=0;t<256;t++) for (unsigned ri=0;ri<sizeof(registers)/sizeof(registers[0]);ri++)
	for (unsigned wi=0;wi<sizeof(widths)/sizeof(widths[0]);wi++) for (unsigned si=0;si<sizeof(shifts)/sizeof(shifts[0]);si++)
	for (unsigned oi=0;oi<sizeof(origins)/sizeof(origins[0]);oi++) {
		for (unsigned i=0;i<16;i++) {
			state.gpr_cells[i].value.ptr = (void *)(uintptr_t)(0x1020304050607080ULL ^ ((__u64)i*0x11223344556677ULL));
			state.gpr_cells[i].tag = t;
			if (t==4) state.gpr_cells[i].value.ptr = (void *)&state.stack_mem.b[(i*7U)%X86_SIM_STACK_BYTES];
		}
		state.rsp.ptr = (void *)(intptr_t)-16;
		state.native_stack_base = origins[oi];
		memcpy(&before,&state,sizeof(state));
		__u64 reg=registers[ri], code=widths[wi], shift=shifts[si];
		/* Tag selection uses the full operand; register observations capture
		 * the byte field before indexing, exactly as the production body. */
		binding.cells = reg<16 ? state.gpr_cells : NULL;
		check(x86_sim_inline_reg_tag(&binding,reg)==(reg<16?t:0),"full-width tag selector");
		unsigned r=(__u8)reg, width=(__u8)code, lane=(__u8)shift;
		if (!width) width=8;
		__u64 value=r<16 ? (__u64)(uintptr_t)state.gpr_cells[r].value.ptr : 0;
		if (r==4) value+=origins[oi];
		else if (r<16 && t==4) value=origins[oi]+(__u64)((__s64)((r*7U)%X86_SIM_STACK_BYTES)-X86_SIM_STACK_BYTES);
		__u64 expected=width==1 ? (value>>lane)&255U : width==2 ? value&65535U : width==4 ? value&0xffffffffULL : value;
		binding.cells = r<16 ? state.gpr_cells : NULL;
		binding.stack = r<16 && r!=4 && t==4 ? &state.stack_mem : NULL;
		binding.native_stack_base = r==4 || (r<16 && t==4) ? &state.native_stack_base : NULL;
		check(x86_sim_inline_read_reg(&binding,reg,code,shift)==expected,"cell/stack-origin/width/lane binding");
		/* Restored facades must resolve the caller's state, not __x86_bind. */
		check(X86_SIM_L_READ_REG_WIDTH_SHIFT(reg,code,shift)==expected && X86_SIM_L_REG_TAG(reg)==(reg<16?t:0),"macro scope restoration");
		check(!memcmp(&state,&before,sizeof(state)),"whole state/arena/flags/environment frame");
		cases++;
	}
	for (unsigned wi=0;wi<sizeof(widths)/sizeof(widths[0]);wi++) {
		__u64 probe=widths[wi], old=probe;
		__u8 expected=(__u8)old ? (__u8)old : 8;
		check(X86_SIM_L_EFFECTIVE_WIDTH(probe++)==expected && probe==old+1,"single evaluation before byte defaulting");
	}
	unsigned source_cases=0;
	for (unsigned t=0;t<256;t++) for (unsigned ri=0;ri<sizeof(registers)/sizeof(registers[0]);ri++)
	for (unsigned wi=0;wi<sizeof(widths)/sizeof(widths[0]);wi++) {
		__u64 reg=registers[ri], width=widths[wi];
		for (unsigned r=0;r<16;r++) state.gpr_cells[r].tag=t;
		memcpy(&before,&state,sizeof(state));
		/* The stack arm and out-of-range operands must not touch cells.
		 * Other binding references are deliberately absent throughout. */
		binding=(struct x86_sim_inline_bindings){0};
		binding.cells=reg<16 && reg!=X86_RSP ? state.gpr_cells : NULL;
		__u8 expected=reg==X86_RSP ? 0 : reg<16 && t==1 && width==8 ? 1 : 2;
		check(x86_sim_inline_mem_read_src(&binding,reg,width)==expected,"lazy memory-source binding/full operands");
		check(X86_SIM_L_MEM_READ_SRC(reg,width)==expected,"memory-source macro scope restoration");
		check(!memcmp(&state,&before,sizeof(state)),"memory-source complete frame");
		source_cases++;
	}
	printf("x86 inline memory-source: %u lazy binding/frame cases\n",source_cases);
	printf("x86 inline binding: %lu defined-lane/register/profile/frame cases\n",cases);
	return 0;
}
