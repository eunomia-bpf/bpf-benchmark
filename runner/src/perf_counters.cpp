#include "micro_exec.hpp"

#include <linux/perf_event.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <array>
#include <cerrno>
#include <cctype>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace {

namespace fs = std::filesystem;

struct counter_definition {
    std::string name;
    uint32_t type;
    uint64_t config;
    std::string source;
};

struct logical_counter_definition {
    std::string name;
    std::vector<counter_definition> events;
};

struct hardware_counter_spec {
    const char *name;
    const char *event_name;
    uint64_t generic_config;
};

struct pmu_source {
    std::string name;
    uint32_t type = 0;
    fs::path path;
};

struct opened_event {
    std::string description;
    int fd = -1;

    opened_event(std::string event_description, int event_fd)
        : description(std::move(event_description)), fd(event_fd)
    {
    }

    opened_event(const opened_event &) = delete;
    opened_event &operator=(const opened_event &) = delete;

    opened_event(opened_event &&other) noexcept
        : description(std::move(other.description)), fd(other.fd)
    {
        other.fd = -1;
    }

    opened_event &operator=(opened_event &&other) noexcept
    {
        if (this != &other) {
            if (fd >= 0) {
                close(fd);
            }
            description = std::move(other.description);
            fd = other.fd;
            other.fd = -1;
        }
        return *this;
    }

    ~opened_event()
    {
        if (fd >= 0) {
            close(fd);
        }
    }
};

struct opened_counter {
    std::string name;
    std::vector<opened_event> events;
};

constexpr std::array<hardware_counter_spec, 6> kHardwareCounterSpecs = {{
    {"cycles", "cpu-cycles", PERF_COUNT_HW_CPU_CYCLES},
    {"instructions", "instructions", PERF_COUNT_HW_INSTRUCTIONS},
    {"branches", "branch-instructions", PERF_COUNT_HW_BRANCH_INSTRUCTIONS},
    {"branch_misses", "branch-misses", PERF_COUNT_HW_BRANCH_MISSES},
    {"cache_references", "cache-references", PERF_COUNT_HW_CACHE_REFERENCES},
    {"cache_misses", "cache-misses", PERF_COUNT_HW_CACHE_MISSES},
}};

const std::array<counter_definition, 4> kSoftwareCounterDefinitions = {{
    {"task_clock_ns", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_TASK_CLOCK, "software"},
    {"context_switches", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_CONTEXT_SWITCHES, "software"},
    {"cpu_migrations", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_CPU_MIGRATIONS, "software"},
    {"page_faults", PERF_TYPE_SOFTWARE, PERF_COUNT_SW_PAGE_FAULTS, "software"},
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

std::string trim(std::string text)
{
    size_t begin = 0;
    while (begin < text.size() && std::isspace(static_cast<unsigned char>(text[begin]))) {
        ++begin;
    }
    size_t end = text.size();
    while (end > begin && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
        --end;
    }
    return text.substr(begin, end - begin);
}

uint64_t parse_u64(const std::string &text, const fs::path &path)
{
    try {
        size_t parsed = 0;
        const uint64_t value = std::stoull(trim(text), &parsed, 0);
        if (parsed != trim(text).size()) {
            fail("invalid integer in " + path.string() + ": " + text);
        }
        return value;
    } catch (const std::exception &) {
        fail("invalid integer in " + path.string() + ": " + text);
    }
}

std::string read_text_file(const fs::path &path)
{
    std::ifstream input(path);
    if (!input) {
        fail("failed to open " + path.string() + ": " + std::strerror(errno));
    }
    std::string text(
        (std::istreambuf_iterator<char>(input)),
        std::istreambuf_iterator<char>());
    if (input.bad()) {
        fail("failed to read " + path.string());
    }
    return text;
}

uint32_t read_pmu_type(const fs::path &path)
{
    const uint64_t type = parse_u64(read_text_file(path / "type"), path / "type");
    if (type > UINT32_MAX) {
        fail("PMU type does not fit in u32: " + (path / "type").string());
    }
    return static_cast<uint32_t>(type);
}

std::vector<std::string> split_tokens(const std::string &text)
{
    std::vector<std::string> tokens;
    std::string current;
    for (const char ch : text) {
        if (ch == ',' || ch == '\n' || ch == '\0') {
            current = trim(current);
            if (!current.empty()) {
                tokens.push_back(current);
            }
            current.clear();
            continue;
        }
        current.push_back(ch);
    }
    current = trim(current);
    if (!current.empty()) {
        tokens.push_back(current);
    }
    return tokens;
}

uint64_t apply_config_format(
    uint64_t config,
    const fs::path &format_path,
    const std::string &format,
    uint64_t value)
{
    const std::string spec = trim(format);
    const size_t colon = spec.find(':');
    if (colon == std::string::npos) {
        fail("invalid perf PMU format in " + format_path.string() + ": " + spec);
    }
    if (spec.substr(0, colon) != "config") {
        fail("unsupported perf PMU format in " + format_path.string() + ": " + spec);
    }
    for (const auto &range_text : split_tokens(spec.substr(colon + 1))) {
        const size_t dash = range_text.find('-');
        const uint64_t low = parse_u64(dash == std::string::npos ? range_text : range_text.substr(0, dash), format_path);
        const uint64_t high = dash == std::string::npos ? low : parse_u64(range_text.substr(dash + 1), format_path);
        if (high < low || high >= 64) {
            fail("invalid perf PMU bit range in " + format_path.string() + ": " + range_text);
        }
        const uint64_t width = high - low + 1;
        const uint64_t mask = width == 64 ? UINT64_MAX : ((1ULL << width) - 1);
        config |= (value & mask) << low;
        value >>= width;
    }
    if (value != 0) {
        fail("perf PMU value does not fit format " + format_path.string());
    }
    return config;
}

uint64_t read_pmu_event_config(const pmu_source &pmu, const std::string &event_name)
{
    const fs::path event_path = pmu.path / "events" / event_name;
    std::ifstream event_file(event_path);
    if (!event_file) {
        fail("missing perf PMU event " + event_path.string());
    }
    std::string event_text(
        (std::istreambuf_iterator<char>(event_file)),
        std::istreambuf_iterator<char>());
    if (event_file.bad()) {
        fail("failed to read " + event_path.string());
    }

    uint64_t config = 0;
    for (const auto &token : split_tokens(event_text)) {
        const size_t equals = token.find('=');
        if (equals == std::string::npos) {
            fail("invalid perf PMU event token in " + event_path.string() + ": " + token);
        }
        const std::string field = token.substr(0, equals);
        const uint64_t value = parse_u64(token.substr(equals + 1), event_path);
        const fs::path format_path = pmu.path / "format" / field;
        config = apply_config_format(config, format_path, read_text_file(format_path), value);
    }
    return config;
}

std::optional<pmu_source> load_pmu_if_present(const std::string &name)
{
    const fs::path path = fs::path("/sys/bus/event_source/devices") / name;
    std::error_code error;
    if (!fs::is_directory(path, error)) {
        return std::nullopt;
    }
    return pmu_source {
        .name = name,
        .type = read_pmu_type(path),
        .path = path,
    };
}

std::vector<pmu_source> discover_hardware_pmus()
{
    if (auto cpu = load_pmu_if_present("cpu")) {
        return {*cpu};
    }

    std::vector<pmu_source> pmus;
    for (const std::string &name : {"cpu_core", "cpu_atom"}) {
        if (auto pmu = load_pmu_if_present(name)) {
            pmus.push_back(std::move(*pmu));
        }
    }
    return pmus;
}

std::vector<logical_counter_definition> build_counter_definitions()
{
    std::vector<logical_counter_definition> definitions;
    definitions.reserve(kHardwareCounterSpecs.size() + kSoftwareCounterDefinitions.size());

    const auto hardware_pmus = discover_hardware_pmus();
    for (const auto &spec : kHardwareCounterSpecs) {
        logical_counter_definition logical {
            .name = spec.name,
            .events = {},
        };
        if (hardware_pmus.empty()) {
            logical.events.push_back({
                .name = spec.name,
                .type = PERF_TYPE_HARDWARE,
                .config = spec.generic_config,
                .source = "hardware",
            });
        } else {
            logical.events.reserve(hardware_pmus.size());
            for (const auto &pmu : hardware_pmus) {
                logical.events.push_back({
                    .name = spec.name,
                    .type = pmu.type,
                    .config = read_pmu_event_config(pmu, spec.event_name),
                    .source = pmu.name,
                });
            }
        }
        definitions.push_back(std::move(logical));
    }

    for (const auto &definition : kSoftwareCounterDefinitions) {
        definitions.push_back({
            .name = definition.name,
            .events = {definition},
        });
    }
    return definitions;
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

uint64_t read_event_value(const opened_event &event)
{
    uint64_t value = 0;
    const ssize_t bytes = read(event.fd, &value, sizeof(value));
    if (bytes != static_cast<ssize_t>(sizeof(value))) {
        if (bytes < 0) {
            fail(errno_message("read perf counter " + event.description));
        }
        fail("short read from perf counter " + event.description);
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

    const auto definitions = build_counter_definitions();
    std::vector<opened_counter> counters;
    counters.reserve(definitions.size());
    for (const auto &definition : definitions) {
        opened_counter counter {
            .name = definition.name,
            .events = {},
        };
        counter.events.reserve(definition.events.size());
        for (const auto &event : definition.events) {
            const int fd = open_perf_counter(event, options.include_kernel);
            const std::string description = event.name + "/" + event.source;
            if (fd < 0) {
                fail(errno_message("perf_event_open " + description));
            }
            counter.events.emplace_back(description, fd);
        }
        counters.push_back(std::move(counter));
    }

    for (const auto &counter : counters) {
        for (const auto &event : counter.events) {
            checked_ioctl(event.fd, PERF_EVENT_IOC_RESET, "reset perf counter " + event.description);
        }
    }
    for (const auto &counter : counters) {
        for (const auto &event : counter.events) {
            checked_ioctl(event.fd, PERF_EVENT_IOC_ENABLE, "enable perf counter " + event.description);
        }
    }

    callback();

    for (const auto &counter : counters) {
        for (const auto &event : counter.events) {
            checked_ioctl(event.fd, PERF_EVENT_IOC_DISABLE, "disable perf counter " + event.description);
        }
    }

    capture.collected = true;
    capture.counters.reserve(counters.size());
    for (const auto &counter : counters) {
        uint64_t value = 0;
        for (const auto &event : counter.events) {
            value += read_event_value(event);
        }
        capture.counters.push_back({
            .name = counter.name,
            .value = value,
        });
    }
    return capture;
}
