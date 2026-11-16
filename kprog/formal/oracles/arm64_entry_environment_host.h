#ifndef KPROG_ZERO_ORIGIN_ENTRY_ENVIRONMENT_HOST_H
#define KPROG_ZERO_ORIGIN_ENTRY_ENVIRONMENT_HOST_H
#ifndef __bpf__
/* Host fixtures select zero for stack/return origins and for each
 * unspecified-input visit. These are explicit environment choices, not
 * guarantees about production entry values or undefined registers. Hardware
 * observers supply the actual invocation's stack and outer return separately.
 */
#include <stdio.h>
#include <stdlib.h>
unsigned long native_lab_entry_input(unsigned int kind)
{
	if (kind == 1 || kind == 3 || kind == 6)
		return 0;
	fprintf(stderr, "unsupported host fixture entry input %u\n", kind);
	exit(1);
}

#endif
#endif
