#include "micro_exec.hpp"

#include <exception>
#include <iostream>

int main(int argc, char **argv)
{
    try {
        const auto options = parse_args(argc, argv);
        if (options.command == "list-programs") {
            print_program_listing(list_programs(options.program));
            return 0;
        }
        if (options.command == "test-run") {
            print_json(run_kernel(options));
            return 0;
        }
        fail("unknown command: " + options.command);
    } catch (const std::exception &error) {
        std::cerr << error.what() << "\n";
        return 1;
    }

    return 1;
}
