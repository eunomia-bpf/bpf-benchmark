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

#endif
