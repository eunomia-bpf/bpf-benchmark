#include "micro_exec.hpp"

#include <linux/perf_event.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <array>
#include <cerrno>
#include <cstring>
#include <string>
#include <vector>

namespace {

struct counter_definition {
    const char *name;
    uint32_t type;
    uint64_t config;
};

struct opened_counter {
    std::string name;
    int fd = -1;
};

constexpr std::array<counter_definition, 10> kCounterDefinitions = {{
    {"cycles", PERF_TYPE_HARDWARE, PERF_COUNT_HW_CPU_CYCLES},
    {"instructions", PERF_TYPE_HARDWARE, PERF_COUNT_HW_INSTRUCTIONS},
    {"branches", PERF_TYPE_HARDWARE, PERF_COUNT_HW_BRANCH_INSTRUCTIONS},
    {"branch_misses", PERF_TYPE_HARDWARE, PERF_COUNT_HW_BRANCH_MISSES},
    {"cache_references", PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_REFERENCES},
    {"cache_misses", PERF_TYPE_HARDWARE, PERF_COUNT_HW_CACHE_MISSES},
    {"task_clock_ns", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_TASK_CLOCK},
    {"context_switches", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_CONTEXT_SWITCHES},
    {"cpu_migrations", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_CPU_MIGRATIONS},
    {"page_faults", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_PAGE_FAULTS},
}};

int open_perf_counter(const counter_definition &definition, bool include_kernel)
{
    perf_event_attr attr = {};
    attr.size = sizeof(attr);
    attr.type = definition.type;
    attr.config = definition.config;
    attr.disabled = 1;
    attr.exclude_kernel = include_kernel ? 0 : 1;
    attr.exclude_hv = 1;
    attr.exclude_guest = 1;

    return static_cast<int>(syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0));
}

void close_counters(const std::vector<opened_counter> &counters)
{
    for (const auto &counter : counters) {
        if (counter.fd >= 0) {
            close(counter.fd);
        }
    }
}

std::string errno_message(const std::string &prefix)
{
    return prefix + ": " + std::strerror(errno);
}

std::string join_messages(const std::vector<std::string> &messages)
{
    std::string joined;
    for (size_t index = 0; index < messages.size(); ++index) {
        if (index != 0) {
            joined += "; ";
        }
        joined += messages[index];
    }
    return joined;
}

} // namespace

perf_counter_capture measure_perf_counters(
    const perf_counter_options &options,
    const std::function<void()> &callback)
{
    perf_counter_capture capture;
    capture.requested = options.enabled;
    capture.include_kernel = options.include_kernel;
    capture.scope = options.scope;

    if (!options.enabled) {
        callback();
        return capture;
    }

    std::vector<opened_counter> counters;
    std::vector<std::string> errors;

    for (const auto &definition : kCounterDefinitions) {
        const int fd = open_perf_counter(definition, options.include_kernel);
        if (fd < 0) {
            errors.push_back(errno_message(std::string("perf_event_open(") + definition.name + ")"));
            continue;
        }
        counters.push_back({definition.name, fd});
    }

    if (counters.empty()) {
        capture.error = join_messages(errors);
        callback();
        return capture;
    }

    auto disable_and_close = [&]() {
        for (const auto &counter : counters) {
            if (counter.fd >= 0) {
                ioctl(counter.fd, PERF_EVENT_IOC_DISABLE, 0);
            }
        }
        close_counters(counters);
    };

    for (const auto &counter : counters) {
        if (ioctl(counter.fd, PERF_EVENT_IOC_RESET, 0) != 0) {
            errors.push_back(errno_message("PERF_EVENT_IOC_RESET(" + counter.name + ")"));
        }
        if (ioctl(counter.fd, PERF_EVENT_IOC_ENABLE, 0) != 0) {
            errors.push_back(errno_message("PERF_EVENT_IOC_ENABLE(" + counter.name + ")"));
        }
    }

    try {
        callback();
    } catch (...) {
        disable_and_close();
        throw;
    }

    for (const auto &counter : counters) {
        if (ioctl(counter.fd, PERF_EVENT_IOC_DISABLE, 0) != 0) {
            errors.push_back(errno_message("PERF_EVENT_IOC_DISABLE(" + counter.name + ")"));
        }
    }

    for (const auto &counter : counters) {
        uint64_t value = 0;
        const ssize_t bytes = read(counter.fd, &value, sizeof(value));
        if (bytes != static_cast<ssize_t>(sizeof(value))) {
            errors.push_back(errno_message("read(" + counter.name + ")"));
            continue;
        }
        capture.counters.push_back({counter.name, value});
    }

    capture.collected = !capture.counters.empty();
    if (!errors.empty()) {
        capture.error = join_messages(errors);
    }

    close_counters(counters);
    return capture;
}
