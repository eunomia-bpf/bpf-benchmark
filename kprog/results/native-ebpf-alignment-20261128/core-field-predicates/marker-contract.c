/* Regression witness for source identity and branch retention, not an app. */
#pragma clang attribute push(__attribute__((annotate("kprog_core"))), apply_to = record)
struct request_queue___x { void *disk; };
struct request___x { struct request_queue___x *q; void *rq_disk; };
struct pid_link { void *prev, *next, *pid; };
typedef struct { unsigned val; } kuid_t;
struct task_struct___local {
  struct pid_link pids[4]; void *thread_pid; void *audit; kuid_t loginuid;
};
struct cgroup___new { unsigned long level; void *ancestors[]; };
#pragma clang attribute pop
/* Deliberately different source value: the target BTF supplies the value. */
enum perf_probe_config { PERF_PROBE_CONFIG_IS_RETPROBE = 7 };
extern unsigned __native_core_field_info(unsigned, ...);
extern unsigned __native_core_type_info(unsigned, ...);
extern long __native_core_enum_info(unsigned, ...);
void *get_disk(struct request___x *r) {
  if (__native_core_field_info(2, r->rq_disk)) return r->rq_disk;
  return r->q->disk;
}
void *get_thread_pid(struct task_struct___local *t) { return t->thread_pid; }
unsigned get_loginuid(struct task_struct___local *t) { return t->loginuid.val; }
void *get_ancestor(struct cgroup___new *c, unsigned i) { return c->ancestors[i]; }
unsigned disk_field_exists(struct request___x *r) { return __native_core_field_info(2, r->rq_disk); }
unsigned old_pid_link_exists(void) { return __native_core_type_info(8, (struct pid_link *)0); }
long long retprobe_exists(void) { return __native_core_enum_info(10, (enum perf_probe_config *)0, PERF_PROBE_CONFIG_IS_RETPROBE); }
long long retprobe_value(void) { return __native_core_enum_info(11, (enum perf_probe_config *)0, PERF_PROBE_CONFIG_IS_RETPROBE); }
