// Catch truncated widened reads, widened stores retaining a source truncation,
// clobbered neighbors on narrowing, and accidental resizing of helper copies.
#ifdef TEST_DRIVER
#define BPF_NO_PRESERVE_ACCESS_INDEX
#include "vmlinux.h"
extern unsigned long narrow_read(void *);
extern unsigned long wide_read(void *);
extern void narrow_write(void *, unsigned long);
extern void wide_write(void *, unsigned long);
extern unsigned long helper_read(void *);
static struct task_struct task, expected;
void core_width_copy(void *dst, const void *src, unsigned long n) {
    __builtin_memcpy(dst, src, n);
}
int main(void) {
    unsigned long values[] = {0, 1, 65535, 65536, 0xffffffffUL, 0x100000000UL,
                             0x123456789abcdef0UL, 0xffffffffffffffffUL};
    for (unsigned i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        __builtin_memset(&task, 0xa5, sizeof(task));
        task.flags = values[i];task.start_boottime = values[i];
        if (narrow_read(&task) != task.flags || wide_read(&task) != task.start_boottime) return 1;
        unsigned long copy;
        __builtin_memcpy(&copy, &task.flags, sizeof(copy));
        if (helper_read(&task) != copy) return 2;
        __builtin_memcpy(&expected, &task, sizeof(task));expected.flags = values[i] ^ ~0UL;
        narrow_write(&task, values[i] ^ ~0UL);
        if (__builtin_memcmp(&expected, &task, sizeof(task))) return 3;
        __builtin_memcpy(&expected, &task, sizeof(task));expected.start_boottime = values[i] ^ ~0UL;
        wide_write(&task, values[i] ^ ~0UL);
        if (__builtin_memcmp(&expected, &task, sizeof(task))) return 4;
    }
    return 0;
}
#else
struct task_struct___core_width {
    unsigned long flags;
    unsigned short start_boottime;
} __attribute__((preserve_access_index));
#ifdef WIDE_COMPARE
__attribute__((section("test"))) int wide_compare(void *ctx) {
    struct task_struct___core_width *p = ctx;
    return p->start_boottime == 0;
}
#else
__attribute__((section("test"))) unsigned long narrow_read(void *ctx) {
    struct task_struct___core_width *p = ctx;return p->flags;
}
__attribute__((section("test"))) unsigned long wide_read(void *ctx) {
    struct task_struct___core_width *p = ctx;return p->start_boottime;
}
__attribute__((section("test"))) void narrow_write(void *ctx, unsigned long value) {
    struct task_struct___core_width *p = ctx;p->flags = value;
}
__attribute__((section("test"))) void wide_write(void *ctx, unsigned long value) {
    struct task_struct___core_width *p = ctx;p->start_boottime = value;
}
extern void core_width_copy(void *, const void *, unsigned long);
__attribute__((section("test"))) unsigned long helper_read(void *ctx) {
    struct task_struct___core_width *p = ctx;unsigned long value;
    core_width_copy(&value, &p->flags, sizeof(value));return value;
}
#endif
#endif
