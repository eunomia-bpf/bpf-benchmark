/* Native-link inputs for the real shared-loader binding regression. */
int tv_short_entry(void *ctx)
{
	(void)ctx;
	return 2;
}

int tv_long_entry(void *ctx)
{
	(void)ctx;
	__asm__ __volatile__(".rept 80\naddq $1, %%rax\n.endr" : : : "rax", "cc");
	return 2;
}
