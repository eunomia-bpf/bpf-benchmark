/* Finite-control experiment environment, populated by the hardware tracer. */
#include "control_inputs.h"
#include "../../kinsn/module/include/native_lab_input.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

_Static_assert(sizeof(unsigned long) == sizeof(uint64_t), "x86 input-word ABI");
int64_t control_input_fd = -1;
extern uint64_t native_stack_base;
static uint64_t count, consumed;
static int observing;

static void fail(const char *message)
{
    fprintf(stderr, "control hardware inputs: %s\n", message);
    exit(1);
}

static uint64_t word(uint64_t index)
{
    uint64_t value;
    ssize_t n;
    do n = pread(control_input_fd, &value, sizeof(value), index * sizeof(value));
    while (n < 0 && errno == EINTR);
    if (n != sizeof(value)) fail("missing input word");
    return value;
}

void control_begin_inputs(void)
{
    struct stat st;
    if (observing || control_input_fd < 0) fail("hardware tracer was not attached");
    if (fstat(control_input_fd, &st)) fail("cannot inspect input stream");
    count = word(0);
    if (st.st_size < 8 || count != (uint64_t)st.st_size / 8 - 1 || st.st_size % 8)
        fail("input count does not match stream length");
    consumed = 0;
    observing = 1;
}

void control_end_inputs(void)
{
    if (!observing || consumed != count) fail("hardware input words left unconsumed");
    observing = 0;
}

unsigned long native_lab_entry_input(unsigned int kind)
{
    if (kind == NATIVE_LAB_INPUT_SP) return native_stack_base;
    if (kind != NATIVE_LAB_INPUT_UNSPECIFIED) fail("unexpected input identity");
    /* Initialization choices are overwritten by the driver's complete input
     * state before control_begin_inputs. Every body choice uses the witness. */
    if (!observing) return 0;
    if (consumed == count) fail("hardware input words exhausted");
    return word(++consumed);
}
