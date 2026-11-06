/* Explicit environment for legacy host fixtures. The Make recipe selects the
 * outcome; production simulation has no default. Exclusive-specific tests
 * provide their own per-case hook and exercise both outcomes instead.
 */
#ifndef KPROG_TEST_EXCLUSIVE_FAILURE
#error "host fixture must explicitly choose its exclusive-store outcome"
#endif
_Static_assert(KPROG_TEST_EXCLUSIVE_FAILURE == 0 || KPROG_TEST_EXCLUSIVE_FAILURE == 1,
               "exclusive-store fixture outcome must be Boolean");
unsigned long native_lab_exclusive_failure_choice(unsigned int site)
{
	(void)site;
	return KPROG_TEST_EXCLUSIVE_FAILURE;
}
