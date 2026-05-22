#include "micro_exec.hpp"

#include <linux/perf_event.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <array>
#include <cerrno>
#include <cstring>
#include <string>
#include <utility>
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

    opened_counter(std::string counter_name, int counter_fd)
        : name(std::move(counter_name)), fd(counter_fd)
    {
    }

    opened_counter(const opened_counter &) = delete;
    opened_counter &operator=(const opened_counter &) = delete;

    opened_counter(opened_counter &&other) noexcept
        : name(std::move(other.name)), fd(other.fd)
    {
        other.fd = -1;
    }

    opened_counter &operator=(opened_counter &&other) noexcept
    {
        if (this != &other) {
            if (fd >= 0) {
                close(fd);
            }
            name = std::move(other.name);
            fd = other.fd;
            other.fd = -1;
        }
        return *this;
    }

    ~opened_counter()
    {
        if (fd >= 0) {
            close(fd);
        }
    }
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

std::string errno_message(const std::string &prefix)
{
    return prefix + ": " + std::strerror(errno);
}

void checked_ioctl(int fd, unsigned long request, const std::string &operation)
{
    if (ioctl(fd, request, 0) != 0) {
        fail(errno_message(operation));
    }
}

uint64_t read_counter_value(const opened_counter &counter)
{
    uint64_t value = 0;
    const ssize_t bytes = read(counter.fd, &value, sizeof(value));
    if (bytes != static_cast<ssize_t>(sizeof(value))) {
        if (bytes < 0) {
            fail(errno_message("read perf counter " + counter.name));
        }
        fail("short read from perf counter " + counter.name);
    }
    return value;
}

} // namespace

perf_counter_capture measure_perf_counters(
    const perf_counter_options &options,
    const std::function<void()> &callback)
{
    perf_counter_capture capture;
    capture.requested = options.enabled;
    capture.include_kernel = options.include_kernel;
    if (!options.enabled) {
        callback();
        return capture;
    }

    std::vector<opened_counter> counters;
    counters.reserve(kCounterDefinitions.size());
    for (const auto &definition : kCounterDefinitions) {
        const int fd = open_perf_counter(definition, options.include_kernel);
        if (fd < 0) {
            fail(errno_message(std::string("perf_event_open ") + definition.name));
        }
        counters.emplace_back(definition.name, fd);
    }

    for (const auto &counter : counters) {
        checked_ioctl(counter.fd, PERF_EVENT_IOC_RESET, "reset perf counter " + counter.name);
    }
    for (const auto &counter : counters) {
        checked_ioctl(counter.fd, PERF_EVENT_IOC_ENABLE, "enable perf counter " + counter.name);
    }

    callback();

    for (const auto &counter : counters) {
        checked_ioctl(counter.fd, PERF_EVENT_IOC_DISABLE, "disable perf counter " + counter.name);
    }

    capture.collected = true;
    capture.counters.reserve(counters.size());
    for (const auto &counter : counters) {
        capture.counters.push_back({
            .name = counter.name,
            .value = read_counter_value(counter),
        });
    }
    return capture;
}
