#include "../../../kinsn/module/include/native_lab_input.h"

unsigned long plain_value(unsigned long value) { return value; }

unsigned long numeric_value(unsigned long value)
{
    return NATIVE_LAB_NUMERIC(value);
}

unsigned long numeric_lane(unsigned long value, unsigned int lane)
{
    return (NATIVE_LAB_NUMERIC(value) >> ((lane & 7) * 8)) & 0xffffffffUL;
}
