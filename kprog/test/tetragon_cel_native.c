extern int cel_expression(void *, void *);
int native_cel_entry(void *offsets, void *values)
{
    int (*volatile expression)(void *, void *) = cel_expression;
    return expression(offsets, values);
}
