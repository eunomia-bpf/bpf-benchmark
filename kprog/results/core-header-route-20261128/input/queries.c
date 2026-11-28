#ifdef HEADER_ORACLE_BPF
#define CORE_RECORD __attribute__((preserve_access_index))
#define SEC(s) __attribute__((section(s), used))
#define bpf_core_field_exists(x) __builtin_preserve_field_info(x, 2)
#define bpf_core_field_offset(x) __builtin_preserve_field_info(x, 0)
#define bpf_core_type_exists(t) __builtin_preserve_type_info(*(typeof(t) *)0, 0)
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
enum perf_probe_config { PERF_PROBE_CONFIG_IS_RETPROBE = 7 };
SEC("query/disk_exists") long long disk_exists(struct request___x *r)
{ return bpf_core_field_exists(r->rq_disk); }
SEC("query/thread_offset") long long thread_offset(struct task_struct___local *t)
{ return bpf_core_field_offset(t->thread_pid); }
SEC("query/thread_address") long long thread_address(struct task_struct___local *t)
{ return (char *)_(&t->thread_pid) - (char *)t; }
SEC("query/login_address") long long login_address(struct task_struct___local *t)
{ return (char *)_(&t->loginuid.val) - (char *)t; }
SEC("query/ancestor_address") long long ancestor_address(struct cgroup___new *c)
{ return (char *)_(&c->ancestors[0]) - (char *)c; }
SEC("query/pid_link_exists") long long pid_link_exists(void)
{ return bpf_core_type_exists(struct pid_link); }
SEC("query/retprobe_exists") long long retprobe_exists(void)
{ return bpf_core_enum_value_exists(enum perf_probe_config, PERF_PROBE_CONFIG_IS_RETPROBE); }
SEC("query/retprobe_value") long long retprobe_value(void)
{ return bpf_core_enum_value(enum perf_probe_config, PERF_PROBE_CONFIG_IS_RETPROBE); }

SEC("query/ancestor_index") long long ancestor_index(struct cgroup___new *c, unsigned i)
{ return (char *)_(&c->ancestors[i]) - (char *)c - (unsigned long)i * sizeof(void *); }
