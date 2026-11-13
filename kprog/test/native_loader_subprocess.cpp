/* Exercise the loader's real child boundary, including failed redirection. */
#include "../libnativeloader/src/native_loader_subprocess.hpp"
#include <fstream>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <thread>
#include <pthread.h>

static volatile sig_atomic_t interrupted;
static void observe_signal(int) { interrupted = 1; }

static void require(bool condition, const char *message)
{
    if (!condition) throw std::runtime_error(message);
}

static int run_test(int argc, char **argv)
{
    if (argc > 1 && std::string(argv[1]) == "child") {
        require(argc == 3 && std::string(argv[2]) == "literal $(argument) with spaces", "argv changed");
        require(std::getenv("LD_PRELOAD") == nullptr, "child inherited preload");
        require(std::getenv("NATIVE_LOADER_CHILD_TEST") &&
                std::string(std::getenv("NATIVE_LOADER_CHILD_TEST")) == "retained value", "environment lost");
        std::cout << "child stdout\n";
        std::cerr << "child stderr\n";
        return 7;
    }
    if (argc > 1 && std::string(argv[1]) == "signal") {
        raise(SIGTERM);
        return 99;
    }
    if (argc > 1 && std::string(argv[1]) == "delay") {
        usleep(100000);
        return 3;
    }
    require(argc == 2, "provide persistent output directory");
    const auto output = std::filesystem::path(argv[1]);
    const auto executable = std::filesystem::canonical("/proc/self/exe").string();
    require(setenv("LD_PRELOAD", "/deliberately-absent-preload.so", 1) == 0, "set preload");
    require(setenv("NATIVE_LOADER_CHILD_TEST", "retained value", 1) == 0, "set child environment");
    const std::vector<std::string> command{executable, "child", "literal $(argument) with spaces"};
    require(native_loader_detail::run_subprocess(command, output / "child.log") == 7, "child exit status changed");
    std::ifstream log(output / "child.log");
    std::ostringstream contents; contents << log.rdbuf();
    require(contents.str() == "child stdout\nchild stderr\n", "redirection or preload filtering changed");
    require(std::string(std::getenv("LD_PRELOAD")) == "/deliberately-absent-preload.so", "parent environment changed");
    require(native_loader_detail::run_subprocess(command, output / "absent" / "child.log") == -1 && errno == ENOENT,
            "failed redirection was treated as child success");
    require(native_loader_detail::run_subprocess({"/deliberately-absent-linker"}, output / "exec-error.log") == -1 && errno == ENOENT,
            "launch error lost");
    require(native_loader_detail::run_subprocess({}, {}) == -1 && errno == EINVAL, "empty command error lost");
    require(native_loader_detail::run_subprocess({executable, "signal"}, output / "signal.log") == -1,
            "signal termination treated as normal exit");
    struct sigaction action{}, prior{};
    action.sa_handler = observe_signal;
    require(sigaction(SIGUSR1, &action, &prior) == 0, "install signal observer");
    const auto parent = pthread_self();
    int delivery_status = -1;
    std::thread delivery([&] { usleep(10000); delivery_status = pthread_kill(parent, SIGUSR1); });
    const int delayed_status = native_loader_detail::run_subprocess({executable, "delay"}, output / "delayed.log");
    delivery.join();
    require(sigaction(SIGUSR1, &prior, nullptr) == 0, "restore signal observer");
    require(delivery_status == 0 && interrupted && delayed_status == 3, "interrupted wait lost child status");
    std::cout << "loader child boundary PASS: argv, environment, redirection, exit, launch errors, signal and interrupted wait\n";
    return 0;
}

int main(int argc, char **argv)
{
    try { return run_test(argc, argv); }
    catch (const std::exception &error) { std::cerr << error.what() << '\n'; return 1; }
}
