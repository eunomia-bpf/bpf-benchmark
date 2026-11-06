#include "../../kinsn/module/include/native_lab_input.h"

unsigned long input_block(unsigned long argument)
{
	unsigned long sp = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_SP);
	unsigned long code = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_CODE);
	unsigned long ret = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_RETURN);
	return sp + code + ret + NATIVE_LAB_NUMERIC(argument);
}
