/* Native-only input for the real kernel/service/compiler/binding control. */
int trusted_entry(void *context)
{
    (void)context;
    return 2;
}
