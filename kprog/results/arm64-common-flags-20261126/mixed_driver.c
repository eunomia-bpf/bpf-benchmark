#define main base_helpers_main
#include "helpers_driver.c"
#undef main
static _Alignas(8) unsigned char task[32768];
static unsigned task_present=1;
unsigned long long bpf_get_current_task(void) { return task_present?(uintptr_t)task:0; }
extern uint64_t pid_probe_entry(const uint64_t *);
int main(void) {
 if (base_helpers_main()) return 1;
 unsigned cases=0; uint64_t value=42,pid=((uint64_t)73<<32)|19;
 u32(task,TASK_PID,19); u32(task,TASK_TGID,73);
 CHECK(pid_probe_entry(&value)==pid+42);
 CHECK(pid_probe_entry(NULL)==pid-14);
 task_present=0; CHECK(pid_probe_entry(&value)==20);
 printf("%u combined PID/probe cases passed\n",cases);
 return 0;
}
