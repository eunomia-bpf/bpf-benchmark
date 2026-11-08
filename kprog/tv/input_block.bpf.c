#include "../../kinsn/module/include/native_lab_input.h"

unsigned long input_block(unsigned long argument)
{
	unsigned long sp = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_SP);
	unsigned long code = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_CODE);
	unsigned long ret = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_RETURN);
	return sp + code + ret + NATIVE_LAB_NUMERIC(argument);
}

unsigned long input_unspecified(void)
{
	return NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED);
}

unsigned long input_unspecified_pair(void)
{
	unsigned long first = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED);
	unsigned long second = NATIVE_LAB_ENTRY_INPUT(NATIVE_LAB_INPUT_UNSPECIFIED);
	return first + second;
}
