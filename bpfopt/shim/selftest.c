/*
 * selftest.c — exercises the shim with a synthetic BPF_PROG_LOAD call so the
 * shim's dump/log paths can be validated without root or a real kernel attach.
 *
 * Expectation: BPF_PROG_LOAD likely fails with EPERM (no CAP_BPF), but the
 * shim still captures the attr + bytecode and writes a hash-keyed dump file
 * to $BPFREJIT_SHIM_DIR.
 *
 * Build: gcc -O2 -g -Wall selftest.c -o selftest
 * Run:   BPFREJIT_SHIM_DIR=/tmp/shim_st BPFREJIT_SHIM_LOG=/tmp/shim_st.log \
 *        LD_PRELOAD=$PWD/libbpfrejit_shim.so ./selftest
 */

#include <errno.h>
#include <linux/bpf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

static const struct bpf_insn prog[] = {
    /* return 0; */
    {.code = 0xb7, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0}, /* mov r0, 0 */
    {.code = 0x95, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0}, /* exit */
};

int main(void) {
    union bpf_attr attr = {0};
    attr.prog_type = BPF_PROG_TYPE_SOCKET_FILTER;
    attr.insn_cnt = sizeof(prog) / sizeof(prog[0]);
    attr.insns = (uintptr_t)prog;
    attr.license = (uintptr_t) "GPL";
    strncpy(attr.prog_name, "shim_st_dummy", sizeof(attr.prog_name) - 1);

    long fd = syscall(SYS_bpf, BPF_PROG_LOAD, &attr, sizeof(attr));
    if (fd < 0) {
        printf("PROG_LOAD returned fd=%ld errno=%d (%s) — expected without "
               "CAP_BPF; the shim should still have captured the call\n",
               fd, errno, strerror(errno));
    } else {
        printf("PROG_LOAD succeeded fd=%ld\n", fd);
        close((int)fd);
    }

    /* Hold so the shim worker thread can tick. Default 0 = exit immediately. */
    const char *hold = getenv("BPFREJIT_SHIM_HOLD_S");
    int s = hold ? atoi(hold) : 0;
    if (s > 0) {
        printf("holding for %d s so shim worker can run\n", s);
        sleep(s);
    }
    return 0;
}
