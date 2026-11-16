/* Reject a callee parameter that differs from the real libbpf declaration. */
#include "../c/X86Helpers.h"
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) \
_Static_assert(__builtin_types_compatible_p(__typeof__(NAME), RESULT (*) ARGS), \
               "x86 helper callee ABI: " #NAME);
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
