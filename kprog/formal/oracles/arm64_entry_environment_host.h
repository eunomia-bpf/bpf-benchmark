/* Legacy routing oracles use zero-origin abstract coordinates. Hardware
 * observers supply the actual invocation's stack and outer return separately.
 * This is an explicit test environment, never a production default.
 */
#include <stdio.h>
#include <stdlib.h>
unsigned long native_lab_entry_input(unsigned int kind)
{
	if (kind == 1 || kind == 3)
		return 0;
	fputs("unexpected legacy entry-environment input\n", stderr);
	exit(1);
}
