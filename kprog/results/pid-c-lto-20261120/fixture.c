typedef unsigned long long u64;
static u64 (*const pid)(void)=(void *)14;
u64 call_pid(void) { return pid(); }
u64 two_pids(void) { u64 first=pid();return first^(pid()<<1); }
