#include "micro_exec.hpp"

#include <exception>
#include <iostream>
#include <string>

namespace {

int run_single_shot(const cli_options &options)
{
    if (options.command == "list-programs") {
        print_program_listing(list_programs(options.program));
        return 0;
    }
    if (options.command == "run-llvmbpf") {
#if MICRO_EXEC_ENABLE_LLVMBPF
        print_json(run_llvmbpf(options));
        return 0;
#else
        fail("run-llvmbpf is unavailable in this micro_exec build");
#endif
    }
    if (options.command == "run-kernel") {
        print_json(run_kernel(options));
        return 0;
    }
    if (options.command == "run-kernel-attach") {
        print_json(run_kernel_attach(options));
        return 0;
    }
    fail("unknown command: " + options.command);
}

int run_keep_alive_loop()
{
    initialize_micro_exec_process();

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.find_first_not_of(" \t\r\n") == std::string::npos) {
            continue;
        }

        const auto request = parse_keep_alive_request(line);
        if (request.cmd == "exit") {
            return 0;
        }
        if (request.cmd == "list-programs") {
            print_program_listing(list_programs(request.options.program));
            std::cout.flush();
            continue;
        }
        if (request.options.command == "run-llvmbpf") {
#if MICRO_EXEC_ENABLE_LLVMBPF
            print_json(run_llvmbpf(request.options));
            std::cout.flush();
            continue;
#else
            fail("run-llvmbpf is unavailable in this micro_exec build");
#endif
        }
        if (request.options.command == "run-kernel") {
            auto samples = run_kernel(request.options);
            if (samples.empty()) {
                fail("run-kernel produced no samples");
            }
            // Keep-alive mode is strictly request/response, so return the final
            // measured sample for multi-phase kernel REJIT runs.
            print_json(samples.back());
            std::cout.flush();
            continue;
        }
        if (request.options.command == "run-kernel-attach") {
            auto samples = run_kernel_attach(request.options);
            if (samples.empty()) {
                fail("run-kernel-attach produced no samples");
            }
            print_json(samples.back());
            std::cout.flush();
            continue;
        }
        fail("unsupported keep-alive request command: " + request.options.command);
    }

    return 0;
}

} // namespace

int main(int argc, char **argv)
{
    try {
        if (argc > 1) {
            if (std::string_view(argv[1]) == "run-batch") {
                return run_batch_cli(argc, argv);
            }
            const auto options = parse_args(argc, argv);
            return run_single_shot(options);
        }
        return run_keep_alive_loop();
    } catch (const std::exception &error) {
        std::cerr << error.what() << "\n";
        return 1;
    }

    return 1;
}
