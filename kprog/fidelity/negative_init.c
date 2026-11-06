/* Minimal initramfs driver: load generated proofs, never execute native code. */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/reboot.h>
#include <sys/wait.h>
#ifdef BOUND_NEGATIVE
#include <sys/syscall.h>
#endif
#include <unistd.h>
static void die(const char *what)
{
    perror(what);
    fflush(stdout);
    fflush(stderr);
    if (reboot(RB_POWER_OFF)) perror("poweroff");
    exit(1);
}
int main(void)
{
    if (mount("devtmpfs", "/dev", "devtmpfs", 0, NULL)) die("mount devtmpfs");
    int console = open("/dev/console", O_RDWR);
    if (console < 0) die("open console");
    for (int i = 0; i < 3; i++) if (dup2(console, i) < 0) die("dup console");
    if (console > 2 && close(console)) die("close console");
    if (mount("proc", "/proc", "proc", 0, NULL)) die("mount proc");
    if (mount("sysfs", "/sys", "sysfs", 0, NULL)) die("mount sysfs");
#ifdef BOUND_NEGATIVE
    if (mount("debugfs", "/sys/kernel/debug", "debugfs", 0, NULL)) die("mount debugfs");
    int module=open("/module.ko",O_RDONLY);
    if (module<0) die("open native module");
    if (syscall(SYS_finit_module,module,"",0)) die("load native module");
    if (close(module)) die("close native module");
#endif
    FILE *cases = fopen("/cases", "r");
    if (!cases) die("open cases");
    char name[128];
    while (fgets(name, sizeof(name), cases)) {
        name[strcspn(name, "\n")] = 0;
        char object[256], program[256];
#ifdef BOUND_NEGATIVE
        int a = snprintf(object, sizeof(object), "/proofs/%s.manifest.json", name);
#else
        int a = snprintf(object, sizeof(object), "/proofs/%s.bpf.o", name);
#endif
        int b = snprintf(program, sizeof(program), "%s_arm64_sim_xdp", name);
        if (a < 0 || (size_t)a >= sizeof(object) || b < 0 || (size_t)b >= sizeof(program)) { errno = EOVERFLOW; die("case path"); }
        printf("LANE_F_CASE_BEGIN %s\n", name);
        if (fflush(stdout)) die("flush begin");
        pid_t pid = fork();
        if (pid < 0) die("fork");
        if (!pid) {
#ifdef BOUND_NEGATIVE
            execl("/bound-probe", "bound-probe", "/companion.bpf.o", object, NULL);
#else
            execl("/loader", "loader", "--object", object, "--program", program, "--load-only", NULL);
#endif
            perror("exec loader");
            _exit(127);
        }
        int status;
        if (waitpid(pid, &status, 0) < 0) die("wait loader");
        int code = WIFEXITED(status) ? WEXITSTATUS(status) : 128 + WTERMSIG(status);
        printf("LANE_F_CASE_END %s %d\n", name, code);
        if (fflush(stdout)) die("flush end");
    }
    if (ferror(cases)) die("read cases");
    if (fclose(cases)) die("close cases");
    puts("LANE_F_SUITE_COMPLETE");
    if (fflush(stdout)) die("flush completion");
    if (reboot(RB_POWER_OFF)) die("poweroff");
    return 0;
}
