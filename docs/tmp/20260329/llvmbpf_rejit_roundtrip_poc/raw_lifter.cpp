#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "llvmbpf.hpp"

using namespace bpftime;

namespace {

uint64_t passthrough_map_value(uint64_t map_handle)
{
	return map_handle;
}

std::vector<uint8_t> read_file(const std::filesystem::path &path)
{
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	if (!file.is_open()) {
		throw std::runtime_error("unable to open input file: " +
					 path.string());
	}

	const auto size = file.tellg();
	std::vector<uint8_t> buffer(static_cast<size_t>(size));
	file.seekg(0, std::ios::beg);
	if (!file.read(reinterpret_cast<char *>(buffer.data()), size)) {
		throw std::runtime_error("unable to read input file: " +
					 path.string());
	}
	return buffer;
}

int emit_llvm_from_raw(const std::filesystem::path &path)
{
	const auto raw = read_file(path);
	llvmbpf_vm vm;

	if (vm.load_code(raw.data(), raw.size()) < 0) {
		std::cerr << "load_code failed: " << vm.get_error_message()
			  << "\n";
		return 1;
	}
	vm.set_kernel_compatible_mode(true);

	for (int i = 0; i < 1000; i++) {
		if (vm.register_external_function(
			    static_cast<size_t>(i),
			    "helper_" + std::to_string(i), nullptr) < 0) {
			std::cerr << "register_external_function(" << i
				  << ") failed: " << vm.get_error_message()
				  << "\n";
			return 1;
		}
	}

	vm.set_lddw_helpers(nullptr, nullptr, passthrough_map_value, nullptr,
			    nullptr);
	auto object = vm.do_aot_compile(true);
	if (!object.has_value()) {
		std::cerr << "do_aot_compile failed: " << vm.get_error_message()
			  << "\n";
		return 1;
	}
	return 0;
}

void print_usage(const char *argv0)
{
	std::cerr << "Usage: " << argv0
		  << " emit-llvm <raw_bpf_insns.bin>\n";
}

} // namespace

int main(int argc, char **argv)
{
	try {
		if (argc != 3 || std::string(argv[1]) != "emit-llvm") {
			print_usage(argv[0]);
			return 1;
		}
		return emit_llvm_from_raw(argv[2]);
	} catch (const std::exception &err) {
		std::cerr << err.what() << "\n";
		return 1;
	}
}
