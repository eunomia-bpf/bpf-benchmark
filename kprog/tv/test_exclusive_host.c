/* Catch a hidden constant-success fallback and unchecked host hook values. */
#include "../../kinsn/module/include/native_lab_input.h"
#include <assert.h>

unsigned long native_lab_exclusive_failure_choice(unsigned int site)
{
	static unsigned visits;
	assert(site == 16 || site == 20);
	return site == 20 ? 2 : visits++;
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		return NATIVE_LAB_EXCLUSIVE_FAILURE(20);
	assert(NATIVE_LAB_EXCLUSIVE_FAILURE(16) == 0);
	assert(NATIVE_LAB_EXCLUSIVE_FAILURE(16) == 1);
	puts("explicit host exclusive outcomes differ per visit: PASS");
	return 0;
}
