/* Disable core dumps for a host test, at process start and therefore in
 * every forked child.
 *
 * Twenty-two host tests verify an unsupported arm by forking a child that
 * calls abort(), so one run of the gate or of a mutation battery leaves one
 * core file per probed code (about 240 per test). The child inherits the
 * limit, so setting it here covers the whole process tree and every caller:
 * make check, a battery's own host build, and an interactive run. */
#ifndef KPROG_FORMAL_TEST_CORE_DUMPS_H
#define KPROG_FORMAL_TEST_CORE_DUMPS_H

#include <sys/resource.h>

static void __attribute__((constructor)) kprog_disable_core_dumps(void)
{
	struct rlimit limit = { 0, 0 };

	(void)setrlimit(RLIMIT_CORE, &limit);
}

#endif
