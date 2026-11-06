/* PID1 wrapper for actual Arm kernel context capture, without an app runtime. */
#define TV_CONTEXT_INIT
#include "capture_context.cpp"
#include <sys/reboot.h>

int main()
{
    char name[] = "capture-context", object[] = "/simple.bpf.o", directory[] = "/capture";
    char *arguments[] = {name, object, directory, nullptr};
    if (!capture_context_main(3, arguments)) {
        for (const char *suffix : {"raw.bin", "xlated.bin", "context.json"}) {
            const std::string path = std::string(directory) + "/simple_arm64_sim_xdp." + suffix;
            std::ifstream file(path, std::ios::binary);
            if (!file) { std::fprintf(stderr, "missing captured file %s\n", suffix); return 1; }
            std::printf("TV_CAPTURE %s ", suffix);
            for (char byte; file.get(byte);) std::printf("%02x", static_cast<unsigned char>(byte));
            if (!file.eof()) { std::fprintf(stderr, "read captured file %s\n", suffix); return 1; }
            std::puts("");
        }
        std::puts("actual ARM kernel context capture: PASS");
        std::fflush(stdout);
        if (!reboot(RB_POWER_OFF)) return 0;
        std::perror("capture guest poweroff");
    }
    return 1;
}
