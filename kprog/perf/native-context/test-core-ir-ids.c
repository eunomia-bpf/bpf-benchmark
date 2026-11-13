// Type IDs must come from the matching original object and the selected target.
#ifdef TEST_DRIVER
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/btf.h>
extern unsigned int core_local_id(void);
extern unsigned int core_target_id(void);
int main(int argc, char **argv) {
    if (argc != 3) return 1;
    struct btf *local = btf__parse(argv[1], 0), *target = btf__parse(argv[2], 0);
    if (!local || !target || libbpf_get_error(local) || libbpf_get_error(target)) return 2;
    int a = btf__find_by_name_kind(local, "task_struct___core_ids", BTF_KIND_STRUCT);
    int b = btf__find_by_name_kind(target, "task_struct", BTF_KIND_STRUCT);
    int bad = a <= 0 || b <= 0 || core_local_id() != (unsigned)a || core_target_id() != (unsigned)b;
    btf__free(local); btf__free(target);
    return bad;
}
#else
struct task_struct___core_ids { int pid; };
__attribute__((section("test"))) unsigned int core_local_id(void) {
    return __builtin_btf_type_id(*(struct task_struct___core_ids *)0, 0);
}
__attribute__((section("test"))) unsigned int core_target_id(void) {
    return __builtin_btf_type_id(*(struct task_struct___core_ids *)0, 1);
}
#endif
