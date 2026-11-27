#include <iostream>
// Exercise the production parser and link schema against the actual boot kernel.
#include "../../libnativeloader/src/native_loader_trusted.cpp"
int main() {
    try {
        using namespace native_loader::trusted;
        CompanionLoad companion{};
        companion.needs_kernel_symbols = true;
        companion.context_helpers.emplace();
        const auto args = build_native_link_args(
            "/workspaces/repository/kprog/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link",
            {}, companion);
        std::cout << "{\"symbols\":{";
        bool first = true;
        for (const char *name : native_lto::kernel_symbols) {
            const auto address = kallsyms_lookup(name);
            const auto match = std::find_if(args.helpers.begin(), args.helpers.end(),
                [&](const auto &item) { return item.name == name && item.addr == address; });
            if (!address || match == args.helpers.end())
                throw std::runtime_error(std::string("missing production binding: ") + name);
            if (!first) std::cout << ',';
            first = false;
            std::cout << '"' << name << "\":" << address;
        }
        std::cout << "},\"status\":0}\n";
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
