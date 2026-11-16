/* Compile the actual helper entry point with an explicitly supplied ID. */
#define __BPF_HELPERS__ 1
#define X86_SIM_ENABLE_STACK 1
#include <linux/types.h>
#include "x86_helper_environment_host.h"
#include "../x86/x86_sim_local_bpf.h"
int main(void)
{
    X86_SIM_L_DECLARE_STATE();
    X86_SIM_L_DECLARE_STACK();
    X86_SIM_BPF_CALL_ID(ORA_NEGATIVE_HELPER);
    return 0;
}
