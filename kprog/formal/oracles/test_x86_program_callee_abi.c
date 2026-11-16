/* Save actual public pointer types before the extraction names are rebound. */
#include "../c/X86Helpers.h"
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) typedef __typeof__(NAME) kprog_public_##NAME;
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
#include "../c/X86ProgramCallees.h"
#define KPROG_X86_HELPER(ID, NAME, RESULT, ARGS) \
_Static_assert(__builtin_types_compatible_p(__typeof__(&kprog_x86_callee_##NAME), kprog_public_##NAME), \
               "x86 program callee ABI: " #NAME);
#include "../c/X86HelperCalls.h"
#undef KPROG_X86_HELPER
