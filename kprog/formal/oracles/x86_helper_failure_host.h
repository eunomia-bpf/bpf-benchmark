#ifndef KPROG_X86_HELPER_FAILURE_HOST_H
#define KPROG_X86_HELPER_FAILURE_HOST_H
#include <stdlib.h>
/* Runtime-opcode host grids cannot use a specialization-time diagnostic in
 * a branch that their C compiler cannot eliminate. Any unexpected helper
 * failure still terminates the host. check_helper_errors.py separately proves
 * that the unmodified production declaration rejects invalid specializations. */
#undef X86_SIM_L_UNSUPPORTED_HELPER
#define X86_SIM_L_UNSUPPORTED_HELPER() abort()
#endif
