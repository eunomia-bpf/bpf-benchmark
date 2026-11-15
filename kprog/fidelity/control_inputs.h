#ifndef KPROG_CONTROL_INPUTS_H
#define KPROG_CONTROL_INPUTS_H
#include <stdint.h>
extern int64_t control_input_fd;
void control_initialize_inputs(void);
void control_begin_inputs(void);
void control_end_inputs(void);
#endif
