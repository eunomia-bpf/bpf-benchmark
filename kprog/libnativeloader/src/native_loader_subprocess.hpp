#pragma once
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fcntl.h>
#include <string>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>
extern "C" char **environ;
namespace native_loader_detail {
inline std::vector<char *> environment_without_ld_preload()
{
    std::vector<char *> clean_env;
    for (char **env = environ; env && *env; ++env) {
        if (std::strncmp(*env, "LD_PRELOAD=", 11) != 0) {
            clean_env.push_back(*env);
        }
    }
    clean_env.push_back(nullptr);
    return clean_env;
}

/* posix_spawn executes the linker through the platform's spawn primitive,
 * keeping application address-space duplication out of this boundary. */
inline int run_subprocess(const std::vector<std::string> &argv,
                   const std::filesystem::path &stderr_path)
{
    if (argv.empty()) { errno = EINVAL; return -1; }
    std::vector<char *> raw;
    raw.reserve(argv.size() + 1);
    for (auto &s : argv) {
        raw.push_back(const_cast<char *>(s.c_str()));
    }
    raw.push_back(nullptr);
    std::vector<char *> clean_env = environment_without_ld_preload();

    posix_spawn_file_actions_t actions;
    int rc = posix_spawn_file_actions_init(&actions);
    if (rc) { errno = rc; return -1; }
    if (!stderr_path.empty()) {
        rc = posix_spawn_file_actions_addopen(&actions, STDOUT_FILENO,
            stderr_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0600);
        if (!rc) rc = posix_spawn_file_actions_adddup2(&actions, STDOUT_FILENO, STDERR_FILENO);
    }
    pid_t pid = -1;
    if (!rc) rc = posix_spawn(&pid, raw[0], &actions, nullptr, raw.data(), clean_env.data());
    const int destroy_rc = posix_spawn_file_actions_destroy(&actions);
    // Setup/launch errors take precedence; a successful launch is always reaped.
    if (rc) { errno = rc; return -1; }
    int status = 0;
    pid_t waited;
    do { waited = waitpid(pid, &status, 0); } while (waited < 0 && errno == EINTR);
    if (waited < 0) return -1;
    if (destroy_rc) { errno = destroy_rc; return -1; }
    if (!WIFEXITED(status)) { errno = ECHILD; return -1; }
    return WEXITSTATUS(status);
}

}
