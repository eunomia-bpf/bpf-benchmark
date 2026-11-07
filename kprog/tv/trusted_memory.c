/* Generic intrinsic boundary controls: exact copied bytes and returned pointer;
 * the unsafe destination control exercises the verifier before native execution.
 */
#ifndef COPY_BYTES
#define COPY_BYTES 16
#endif
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
int trusted_entry(void *context)
{
    volatile unsigned char source[COPY_BYTES], destination[COPY_BYTES];
    (void)context;
    #pragma clang loop unroll(full)
    for (unsigned i=0; i<COPY_BYTES; i++)
        source[i]=(unsigned char)(i*13+7);
#ifdef UNSAFE_DESTINATION
    void *target=(void *)1UL;
#else
    void *target=(void *)destination;
#endif
    if (memset(target, 0x55, COPY_BYTES)!=target)
        return 1;
    if (memcpy(target, (const void *)source, COPY_BYTES)!=target)
        return 1;
    #pragma clang loop unroll(full)
    for (unsigned i=0; i<COPY_BYTES; i++)
        if (destination[i]!=(unsigned char)(i*13+7))
            return 1;
    return 2;
}
