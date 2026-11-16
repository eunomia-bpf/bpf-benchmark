extern int cel_expression(void *, void *);
#ifdef CEL_STOCK_ENTRY
__attribute__((section("kprobe/test")))
int native_cel_stock(unsigned long *ctx)
{
    unsigned long offsets[] = {0, 8, 16};
    unsigned long values[] = {ctx[0], ctx[1], ctx[2]};
    int (*volatile expression)(void *, void *) = cel_expression;
    return expression(offsets, values);
}
#else
int native_cel_entry(void *offsets, void *values)
{
    int (*volatile expression)(void *, void *) = cel_expression;
    return expression(offsets, values);
}
#endif
