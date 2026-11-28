#ifdef HEADER_ORACLE_BPF
#define CORE_RECORD __attribute__((preserve_access_index))
#define SEC(s) __attribute__((section(s), used))
#define __exists1(x) __builtin_preserve_field_info(x, 2)
#define __exists2(t, m) __builtin_preserve_field_info(((typeof(t) *)0)->m, 2)
#define __exists_pick(a, b, f, ...) f
#define bpf_core_field_exists(...) __exists_pick(__VA_ARGS__, __exists2, __exists1)(__VA_ARGS__)
#define bpf_core_field_offset(x) __builtin_preserve_field_info(x, 0)
#define bpf_core_type_exists(t) __builtin_preserve_type_info(*(typeof(t) *)0, 0)
#define bpf_core_type_size(t) __builtin_preserve_type_info(*(typeof(t) *)0, 1)
#define bpf_core_enum_value_exists(t, v) __builtin_preserve_enum_value(*(typeof(t) *)v, 0)
#define bpf_core_enum_value(t, v) __builtin_preserve_enum_value(*(typeof(t) *)v, 1)
#define _(p) __builtin_preserve_access_index(p)
#else
#include "core-compat.h"
#define CORE_RECORD
#endif
struct request_queue___x { void *disk; } CORE_RECORD;
struct request___x { struct request_queue___x *q; void *rq_disk; } CORE_RECORD;
struct pid_link { void *prev, *next, *pid; } CORE_RECORD;
typedef struct { unsigned val; } kuid_t;
struct task_struct___local {
    struct pid_link pids[4]; void *thread_pid; void *audit; kuid_t loginuid;
} CORE_RECORD;
struct cgroup___new { unsigned long level; void *ancestors[]; } CORE_RECORD;
struct __kernel_timespec { long tv_sec, tv_nsec; } CORE_RECORD;
enum perf_probe_config { PERF_PROBE_CONFIG_IS_RETPROBE = 7 };
SEC("query/disk_exists") long long disk_exists(struct request___x *r)
{ return bpf_core_field_exists(r->rq_disk); }
SEC("query/thread_offset") long long thread_offset(struct task_struct___local *t)
{ return bpf_core_field_offset(t->thread_pid); }
SEC("query/thread_exists_type") long long thread_exists_type(void)
{ return bpf_core_field_exists(struct task_struct___local, thread_pid); }
SEC("query/thread_address") long long thread_address(struct task_struct___local *t)
{ return (char *)_(&t->thread_pid) - (char *)t; }
/* Identical query spelling in a different scope needs a different delta. */
struct task_struct___older_v50 { void *thread_pid; } CORE_RECORD;
SEC("query/thread_address_short") long long thread_address_short(struct task_struct___older_v50 *t)
{ return (char *)_(&t->thread_pid) - (char *)t; }
struct upid___local { int nr; void *ns; } CORE_RECORD;
struct pid___local { struct upid___local numbers[1]; } CORE_RECORD;
SEC("query/pid_namespace_address") long long pid_namespace_address(struct pid___local *p)
{ return (char *)_(&p->numbers[0].ns) - (char *)p; }
enum mod_mem_type { MOD_TEXT = 0 };
struct module_memory___local { void *base; } CORE_RECORD;
struct module___local { struct module_memory___local mem[1]; } CORE_RECORD;
SEC("query/module_text_address") long long module_text_address(struct module___local *p)
{ return (char *)_(&p->mem[MOD_TEXT].base) - (char *)p; }
SEC("query/login_address") long long login_address(struct task_struct___local *t)
{ return (char *)_(&t->loginuid.val) - (char *)t; }
SEC("query/ancestor_address") long long ancestor_address(struct cgroup___new *c)
{ return (char *)_(&c->ancestors[0]) - (char *)c; }
SEC("query/pid_link_exists") long long pid_link_exists(void)
{ return bpf_core_type_exists(struct pid_link); }
SEC("query/timespec_size") long long timespec_size(void)
{ return bpf_core_type_size(struct __kernel_timespec); }
SEC("query/retprobe_exists") long long retprobe_exists(void)
{ return bpf_core_enum_value_exists(enum perf_probe_config, PERF_PROBE_CONFIG_IS_RETPROBE); }
SEC("query/retprobe_value") long long retprobe_value(void)
{ return bpf_core_enum_value(enum perf_probe_config, PERF_PROBE_CONFIG_IS_RETPROBE); }

SEC("query/ancestor_index") long long ancestor_index(struct cgroup___new *c, unsigned i)
{ return (char *)_(&c->ancestors[i]) - (char *)c - (unsigned long)i * sizeof(void *); }

/* Same typeof-qualified intermediate that BPF_CORE_READ emits. */
SEC("query/queue_disk_address") long long queue_disk_address(struct request___x *r)
{
    typeof(r->q) const __t1 = (void *)r;
    return (char *)_(&__t1->disk) - (char *)__t1;
}
