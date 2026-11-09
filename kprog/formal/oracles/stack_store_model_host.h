#ifndef KPROG_STACK_STORE_MODEL_HOST_H
#define KPROG_STACK_STORE_MODEL_HOST_H

/* Independent byte-interval provenance model. A tag denotes an entire aligned
 * 8-byte pointer word, so any partial overwrite invalidates that whole word.
 * The caller supplies a positive access width and checked fixture bounds. */
static inline void host_stack_store_tags(unsigned char *tags, unsigned index,
                                         unsigned bytes, unsigned char tag)
{
    unsigned first = index / 8U, last = (index + bytes - 1U) / 8U, word;
    for (word = first; word <= last; word++)
        tags[word] = bytes == 8U && index % 8U == 0U ? tag : 0;
}

/* A fixed host fresh input is zero. Releasing the half-open native SP
 * interval forgets its private bytes and every pointer tag overlapping it. */
static inline void host_stack_release_zero(unsigned char *bytes,
                                           unsigned char *tags,
                                           unsigned size, unsigned bias,
                                           long long prior, long long current)
{
    if (current <= prior) return;
    for (unsigned i = 0; i < size; i++) {
        long long at = (long long)i - (long long)bias;
        if (at >= prior && at < current) bytes[i] = 0;
    }
    for (unsigned word = 0; word < (size + 7U) / 8U; word++) {
        long long start = (long long)(word * 8U) - (long long)bias;
        if (start < current && start + 8 > prior) tags[word] = 0;
    }
}

#endif
