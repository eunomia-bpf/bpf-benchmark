/* Exercise the production resolver, not a second loader or a model of it. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

struct HelperCase {
    const char *name;
    bpf_prog_type type;
    bpf_attach_type attach;
    const char *output_symbol;
    const char *stack_symbol;
    const char *cookie_symbol;
    const char *netns_symbol;
    const char *fib_symbol = nullptr;
    const char *skc_symbol = nullptr;
};

static std::unordered_map<std::string, std::vector<uint64_t>> symbol_addresses()
{
    std::ifstream input("/proc/kallsyms");
    if (!input) throw std::runtime_error("open /proc/kallsyms");
    std::unordered_map<std::string, std::vector<uint64_t>> symbols;
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream fields(line);
        uint64_t address;
        char type;
        std::string name;
        if (!(fields >> std::hex >> address >> type >> name))
            throw std::runtime_error("parse /proc/kallsyms");
        symbols[name].push_back(address);
    }
    if (!input.eof()) throw std::runtime_error("read /proc/kallsyms");
    return symbols;
}

static bool matches(const std::unordered_map<std::string, std::vector<uint64_t>> &symbols,
                    const char *symbol, uint64_t address)
{
    if (!symbol[0]) return address == 0;
    const auto it = symbols.find(symbol);
    if (!address || it == symbols.end()) return false;
    return std::find(it->second.begin(), it->second.end(), address) != it->second.end();
}

static uint64_t query_bind(int program_fd, uint32_t type)
{
    const auto bytes = encode_helper_query(kallsyms_lookup("bpf_verifier_ops"),
                                           program_fd, type, {BPF_FUNC_bind});
    ScopedFd fd(open((std::string(kNativeLabTarget.debugfs_dir) + "/helper_targets").c_str(),
                     O_RDWR | O_CLOEXEC));
    if (fd.get() < 0) fail("open helper_targets: " + std::string(strerror(errno)));
    const ssize_t written = write(fd.get(), bytes.data(), bytes.size());
    if (written < 0) fail("write bind query: " + std::string(strerror(errno)));
    if (written != static_cast<ssize_t>(bytes.size())) fail("short write bind query");
    if (lseek(fd.get(), 0, SEEK_SET) < 0)
        fail("seek bind query: " + std::string(strerror(errno)));
    std::vector<uint8_t> response(sizeof(uint64_t));
    const ssize_t got = read(fd.get(), response.data(), response.size());
    if (got < 0) fail("read bind query: " + std::string(strerror(errno)));
    response.resize(got);
    return decode_helper_targets(response, 1).front();
}

int main(int argc, char **argv)
try {
    if (argc != 2) fail("usage: helper-kernel OUTPUT_DIRECTORY");
    const auto root = std::filesystem::path(argv[1]);
    std::ofstream output(root / "helper-query.jsonl");
    if (!output) fail("open helper-query.jsonl");
    const auto symbols = symbol_addresses();
    const HelperCase cases[] = {
        {"kprobe", BPF_PROG_TYPE_KPROBE, {}, "bpf_perf_event_output", "bpf_get_stackid", "", ""},
        {"tracepoint", BPF_PROG_TYPE_TRACEPOINT, {}, "bpf_perf_event_output_tp", "bpf_get_stackid_tp", "", ""},
        {"raw_tp", BPF_PROG_TYPE_RAW_TRACEPOINT, {}, "bpf_perf_event_output_raw_tp", "bpf_get_stackid_raw_tp", "", ""},
        {"tc", BPF_PROG_TYPE_SCHED_CLS, {}, nullptr, nullptr, "bpf_get_socket_cookie", "bpf_get_netns_cookie",
         "bpf_skb_fib_lookup", "bpf_tc_skc_lookup_tcp"},
        {"xdp", BPF_PROG_TYPE_XDP, {}, nullptr, nullptr, nullptr, nullptr,
         "bpf_xdp_fib_lookup", "bpf_xdp_skc_lookup_tcp"},
        {"sock_create", BPF_PROG_TYPE_CGROUP_SOCK, BPF_CGROUP_INET_SOCK_CREATE, nullptr, nullptr,
         "bpf_get_socket_cookie_sock", "bpf_get_netns_cookie_sock"},
        {"sock_connect", BPF_PROG_TYPE_CGROUP_SOCK_ADDR, BPF_CGROUP_INET4_CONNECT, nullptr, nullptr,
         "bpf_get_socket_cookie_sock_addr", "bpf_get_netns_cookie_sock_addr"},
        {"sock_bind", BPF_PROG_TYPE_CGROUP_SOCK_ADDR, BPF_CGROUP_INET4_BIND, nullptr, nullptr,
         "bpf_get_socket_cookie_sock_addr", "bpf_get_netns_cookie_sock_addr"},
        {"sock_ops", BPF_PROG_TYPE_SOCK_OPS, {}, nullptr, nullptr,
         "bpf_get_socket_cookie_sock_ops", "bpf_get_netns_cookie_sock_ops"},
        {"sk_msg", BPF_PROG_TYPE_SK_MSG, {}, nullptr, nullptr, nullptr, "bpf_get_netns_cookie_sk_msg"},
    };
    bool passed = true;
    for (const auto &test : cases) {
        std::cout << "query " << test.name << std::endl;
        const bpf_insn insns[] = {
            {.code=BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg=BPF_REG_0},
            {.code=BPF_JMP | BPF_EXIT},
        };
        char verifier_log[65536] = {};
        bpf_prog_load_opts options{};
        options.sz = sizeof(options);
        options.expected_attach_type = test.attach;
        options.log_buf = verifier_log;
        options.log_size = sizeof(verifier_log);
        options.log_level = 1;
        ScopedFd program(bpf_prog_load(test.type, test.name, "GPL", insns, 2, &options));
        const int load_error = errno;
        std::ofstream log(root / (std::string(test.name) + ".verifier.log"));
        log << verifier_log;
        log.close();
        if (!log) fail("write verifier log");
        if (program.get() < 0) fail(std::string("load ") + test.name + ": " + strerror(load_error));
        bpf_prog_info info{};
        uint32_t info_size = sizeof(info);
        if (bpf_prog_get_info_by_fd(program.get(), &info, &info_size))
            fail("program info: " + std::string(strerror(errno)));
        const auto targets = query_program_helper_targets(program.get(), info.type);
        output << "{\"case\":\"" << test.name << "\",\"prog_id\":" << info.id
               << ",\"type\":" << info.type << ",\"expected_attach_type\":" << test.attach
               << ",\"targets\":[";
        bool first = true;
        for (const auto &[name, address] : targets) {
            if (!first) output << ',';
            first = false;
            output << "{\"helper\":\"" << name << "\",\"address\":" << address << '}';
        }
        output << "],\"checks\":[";
        first = true;
        const std::pair<const char *, const char *> checks[] = {
            {"bpf_perf_event_output", test.output_symbol}, {"bpf_get_stackid", test.stack_symbol},
            {"bpf_get_socket_cookie", test.cookie_symbol}, {"bpf_get_netns_cookie", test.netns_symbol},
            {"bpf_fib_lookup", test.fib_symbol}, {"bpf_skc_lookup_tcp", test.skc_symbol},
            {"bpf_probe_read", test.type == BPF_PROG_TYPE_KPROBE ? "bpf_probe_read_compat" : nullptr},
            {"bpf_probe_read_compat", test.type == BPF_PROG_TYPE_KPROBE ? "bpf_probe_read_compat" : nullptr},
        };
        for (const auto &[name, expected] : checks) {
            if (!expected) continue;
            const auto found = std::find_if(targets.begin(), targets.end(),
                [&](const auto &target) { return target.first == name; });
            const uint64_t actual = found == targets.end() ? 0 : found->second;
            const bool match = matches(symbols, expected, actual);
            if (!first) output << ',';
            first = false;
            output << "{\"helper\":\"" << name << "\",\"expected_symbol\":\"" << expected
                   << "\",\"address\":" << actual << ",\"matches\":" << (match ? "true" : "false") << '}';
            passed &= match;
        }
        output << ']';
        if (test.type == BPF_PROG_TYPE_CGROUP_SOCK_ADDR) {
            const uint64_t address = query_bind(program.get(), info.type);
            const char *expected = test.attach == BPF_CGROUP_INET4_CONNECT ? "bpf_bind" : "";
            const bool match = matches(symbols, expected, address);
            passed &= match;
            output << ",\"bind_address\":" << address << ",\"bind_matches\":" << (match ? "true" : "false");
        }
        output << "}\n";
        output.flush();
        if (!output) fail("write helper-query.jsonl");
        if (test.type == BPF_PROG_TYPE_KPROBE) {
            bool failed = false;
            try { query_program_helper_targets(program.get(), BPF_PROG_TYPE_XDP); }
            catch (const std::runtime_error &error) {
                failed = true;
                std::ofstream errors(root / "wrong-type-error.txt");
                errors << error.what() << '\n';
                errors.close();
                if (!errors) fail("write wrong-type-error.txt");
            }
            passed &= failed;
        }
    }
    if (!passed) fail("helper target/attach/FD regression failed; raw addresses retained");
    std::cout << "original program helper targets/availability/attach metadata/FD errors PASS" << std::endl;
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << std::endl;
    return 1;
}
