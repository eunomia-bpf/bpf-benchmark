/* A real clang frontend fixture for non-PIC map binding and lookup LTO. */
struct map_definition {
    unsigned int type, key_size, value_size, max_entries, flags;
};
struct map_definition test_map __attribute__((section(".maps"), used)) = {
    2, sizeof(unsigned int), sizeof(unsigned long), 3, 0
};
static void *(*const lookup)(void *, const void *) = (void *)1;

unsigned long entry(const unsigned int *key)
{
    const volatile unsigned long *value = lookup(&test_map, key);
    return value ? *value : 0;
}
