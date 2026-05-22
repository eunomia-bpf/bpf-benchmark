#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include "llvmbpf.hpp"
#include "llvm_jit_context.hpp"

#include "llvm/Analysis/CGSCCPassManager.h"
#include "llvm/Config/llvm-config.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/JSON.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/Scalar/DCE.h"
#include "llvm/Transforms/Scalar/SROA.h"
#include "llvm/Transforms/Utils/Mem2Reg.h"

namespace {

constexpr uint8_t BPF_LD_IMM64 = 0x18;
constexpr uint8_t BPF_LDX_MEM_B = 0x71;
constexpr uint8_t BPF_LDX_MEM_H = 0x69;
constexpr uint8_t BPF_LDX_MEM_W = 0x61;
constexpr uint8_t BPF_LDX_MEM_DW = 0x79;
constexpr uint8_t BPF_JMP32_JNE_K = 0x56;
constexpr uint8_t BPF_ALU64_ADD_K = 0x07;
constexpr uint8_t BPF_ALU64_ADD_X = 0x0f;
constexpr uint8_t BPF_ALU64_LSH_K = 0x67;
constexpr uint8_t BPF_ALU64_MOV_X = 0xbf;
constexpr uint8_t BPF_ALU64_RSH_K = 0x77;
constexpr uint8_t BPF_ALU32_MOV_X = 0xbc;
constexpr uint8_t BPF_ALU32_AND_K = 0x54;
constexpr uint8_t BPF_ALU32_LSH_K = 0x64;
constexpr uint8_t BPF_ALU32_MOD_K = 0x94;
constexpr uint8_t BPF_ST_MEM_B = 0x72;
constexpr uint8_t BPF_ST_MEM_W = 0x62;
constexpr uint8_t BPF_JEQ_K = 0x15;
constexpr uint8_t BPF_JMP32_JSGT_K = 0x66;
constexpr uint8_t BPF_JMP32_JSGE_K = 0x76;
constexpr uint8_t BPF_JMP32_JSLT_K = 0xc6;
constexpr uint8_t BPF_JMP32_JSLE_K = 0xd6;
constexpr uint8_t BPF_JGT_K = 0x25;
constexpr uint8_t BPF_JGT_X = 0x2d;
constexpr uint8_t BPF_JGE_X = 0x3d;
constexpr uint8_t BPF_JLT_K = 0xa5;
constexpr uint8_t BPF_JLT_X = 0xad;
constexpr uint8_t BPF_JNE_K = 0x55;
constexpr uint8_t BPF_JA = 0x05;
constexpr uint8_t BPF_CALL = 0x85;
constexpr uint8_t BPF_CALLX = BPF_CALL | 0x08;
constexpr uint8_t BPF_EXIT = 0x95;
constexpr uint8_t BPF_PSEUDO_MAP_FD = 1;
constexpr uint8_t BPF_PSEUDO_MAP_VALUE = 2;
constexpr uint8_t BPF_PSEUDO_MAP_IDX = 5;
constexpr uint8_t BPF_PSEUDO_MAP_IDX_VALUE = 6;
constexpr uint8_t BPF_PSEUDO_CALL = 1;
constexpr uint8_t BPF_PSEUDO_FUNC = 4;
constexpr size_t INSN_SIZE = 8;

// BPF helper function ids (uapi/linux/bpf.h __BPF_FUNC_MAPPER order). This pure
// LLVM tool does not link libbpf, so the relevant ids are spelled out here like
// the opcode constants above.
constexpr int32_t BPF_FUNC_map_lookup_elem = 1;
constexpr int32_t BPF_FUNC_map_update_elem = 2;
constexpr int32_t BPF_FUNC_map_delete_elem = 3;
constexpr int32_t BPF_FUNC_map_push_elem = 87;
constexpr int32_t BPF_FUNC_map_pop_elem = 88;

struct Cli {
	bool canonicalize_map_refs = false;
	std::optional<std::string> pass;
	std::optional<std::filesystem::path> input;
	std::optional<std::filesystem::path> output;
	std::optional<std::filesystem::path> report;
	std::optional<std::filesystem::path> target;
	std::optional<std::filesystem::path> target_output;
	std::optional<std::filesystem::path> verifier_states;
	std::optional<std::filesystem::path> func_info;
	std::optional<std::filesystem::path> line_info;
	std::string prog_type;
	std::string map_ids;
	std::string func_info_rec_size;
	std::string line_info_rec_size;
	std::vector<std::string> pass_args;
};

std::string llvm_error_string(llvm::Error err)
{
	std::string message;
	llvm::raw_string_ostream os(message);
	os << err;
	return os.str();
}

template <typename T> T expected_or_throw(llvm::Expected<T> value)
{
	if (!value) {
		throw std::runtime_error(llvm_error_string(value.takeError()));
	}
	return std::move(*value);
}

std::vector<uint8_t> read_all(std::optional<std::filesystem::path> path)
{
	if (!path) {
		return { std::istreambuf_iterator<char>(std::cin),
			 std::istreambuf_iterator<char>() };
	}
	std::ifstream file(*path, std::ios::binary | std::ios::ate);
	if (!file.is_open()) {
		throw std::runtime_error("failed to open " + path->string());
	}
	const auto size = file.tellg();
	if (size < 0) {
		throw std::runtime_error("failed to size " + path->string());
	}
	std::vector<uint8_t> bytes(static_cast<size_t>(size));
	file.seekg(0, std::ios::beg);
	if (!bytes.empty() &&
	    !file.read(reinterpret_cast<char *>(bytes.data()), size)) {
		throw std::runtime_error("failed to read " + path->string());
	}
	return bytes;
}

std::string read_text(const std::filesystem::path &path)
{
	auto bytes = read_all(path);
	return std::string(bytes.begin(), bytes.end());
}

void write_all(std::optional<std::filesystem::path> path,
	       const std::vector<uint8_t> &bytes)
{
	if (!path) {
		std::cout.write(reinterpret_cast<const char *>(bytes.data()),
				static_cast<std::streamsize>(bytes.size()));
		std::cout.flush();
		if (!std::cout) {
			throw std::runtime_error("failed to write stdout");
		}
		return;
	}
	std::ofstream file(*path, std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("failed to create " + path->string());
	}
	if (!bytes.empty()) {
		file.write(reinterpret_cast<const char *>(bytes.data()),
			   static_cast<std::streamsize>(bytes.size()));
	}
	if (!file) {
		throw std::runtime_error("failed to write " + path->string());
	}
}

void write_text(const std::filesystem::path &path, std::string_view text)
{
	const std::vector<uint8_t> bytes(text.begin(), text.end());
	write_all(path, bytes);
}

#include "bpf_bytecode.hpp"

#include "bpf_repair.hpp"

#include "llvm_mapinline.hpp"

void shift_target_call_offsets(const std::filesystem::path &input,
			       const std::filesystem::path &output,
			       size_t map_count)
{
	auto value = expected_or_throw(llvm::json::parse(read_text(input)));
	auto *root = value.getAsObject();
	if (!root) {
		throw std::runtime_error("target.json root is not an object");
	}
	auto *kinsns = root->getObject("kinsns");
	if (kinsns) {
		const uint32_t base = module_fd_array_base(map_count);
		for (auto &entry : *kinsns) {
			auto *obj = entry.getSecond().getAsObject();
			if (!obj) {
				throw std::runtime_error(
					"target kinsn is not an object");
			}
			auto call_offset = obj->getInteger("call_offset");
			if (!call_offset) {
				throw std::runtime_error(
					"target kinsn has no call_offset");
			}
			if (*call_offset == 0) {
				continue;
			}
			if (*call_offset < 0) {
				throw std::runtime_error(
					"target kinsn has negative call_offset");
			}
			auto btf_id = obj->getInteger("btf_id");
			if (!btf_id || *btf_id == 0) {
				throw std::runtime_error(
					"target kinsn has call_offset but no BTF object id");
			}
			const int64_t shifted =
				static_cast<int64_t>(base) + *call_offset - 1;
			if (shifted > std::numeric_limits<int16_t>::max()) {
				throw std::runtime_error(
					"shifted call_offset exceeds BPF off field");
			}
			(*obj)["call_offset"] = shifted;
		}
	}

	std::string json;
	llvm::raw_string_ostream os(json);
	os << llvm::formatv("{0:2}", value) << "\n";
	write_text(output, os.str());
}

void canonicalize_map_refs(Cli &cli)
{
	if (cli.pass) {
		throw std::runtime_error(
			"--canonicalize-map-refs cannot be combined with --pass");
	}
	if (cli.report) {
		throw std::runtime_error(
			"--canonicalize-map-refs does not produce --report");
	}
	if (!cli.pass_args.empty()) {
		throw std::runtime_error("pass-local args require --pass <name>");
	}
	if (cli.target.has_value() != cli.target_output.has_value()) {
		throw std::runtime_error(
			"--canonicalize-map-refs --target requires --target-output");
	}

	auto bytes = read_all(cli.input);
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error(
			"bytecode length is not a multiple of 8 bytes");
	}
	const auto map_ids = parse_u32_csv(cli.map_ids);
	std::map<int32_t, size_t> fd_to_idx;
	const size_t insn_count = bytes.size() / INSN_SIZE;

	for (size_t pc = 0; pc < insn_count; pc++) {
		if (!is_ldimm64(bytes, pc)) {
			continue;
		}
		const uint8_t src = src_reg(bytes, pc);
		if (is_map_pseudo(src) && pc + 1 >= insn_count) {
			throw std::runtime_error(
				"truncated LD_IMM64 map reference");
		}
		if (src == BPF_PSEUDO_MAP_FD ||
		    src == BPF_PSEUDO_MAP_VALUE) {
			const int32_t fd = read_imm(bytes, pc);
			if (!fd_to_idx.contains(fd)) {
				fd_to_idx.emplace(fd, fd_to_idx.size());
			}
		}
		if (is_ldimm64(bytes, pc)) {
			pc++;
		}
	}
	if (fd_to_idx.size() > map_ids.size()) {
		throw std::runtime_error(
			"bytecode references more loader map fds than --map-ids entries");
	}

	for (size_t pc = 0; pc < insn_count; pc++) {
		if (!is_ldimm64(bytes, pc)) {
			continue;
		}
		const uint8_t src = src_reg(bytes, pc);
		if (!is_map_pseudo(src)) {
			pc++;
			continue;
		}
		if (pc + 1 >= insn_count) {
			throw std::runtime_error(
				"truncated LD_IMM64 map reference");
		}
		if (src == BPF_PSEUDO_MAP_FD ||
		    src == BPF_PSEUDO_MAP_VALUE) {
			const auto it = fd_to_idx.find(read_imm(bytes, pc));
			if (it == fd_to_idx.end()) {
				throw std::runtime_error(
					"loader map fd was not present in first-seen bindings");
			}
			write_imm(bytes, pc, static_cast<int32_t>(it->second));
			set_src_reg(bytes, pc,
				    src == BPF_PSEUDO_MAP_FD ?
					    BPF_PSEUDO_MAP_IDX :
					    BPF_PSEUDO_MAP_IDX_VALUE);
		} else {
			const int32_t idx = read_imm(bytes, pc);
			if (idx < 0 ||
			    static_cast<size_t>(idx) >= map_ids.size()) {
				throw std::runtime_error(
					"map index out of range for --map-ids");
			}
		}
		pc++;
	}

	write_all(cli.output, bytes);
	if (cli.target && cli.target_output) {
		shift_target_call_offsets(*cli.target, *cli.target_output,
					  map_ids.size());
	}
}

void write_report(const Cli &cli, const std::vector<uint8_t> &input,
		  const std::vector<uint8_t> &output,
		  const std::vector<InlineRecord> &inlined = {})
{
	if (!cli.report) {
		return;
	}
	const bool changed = input != output;
	const bool is_map_inline = cli.pass && *cli.pass == "map_inline";
	llvm::json::Array inlined_entries;
	for (const auto &record : inlined) {
		inlined_entries.emplace_back(llvm::json::Object{
			{ "map_id", static_cast<int64_t>(record.map_id) },
			{ "key_hex", bytes_hex(record.key) },
			{ "value_hex", bytes_hex(record.value) },
		});
	}
	llvm::json::Object report{
		{ "pass", *cli.pass },
		{ "sites_applied",
		  is_map_inline ? static_cast<int64_t>(inlined.size()) :
				  (changed ? 1 : 0) },
		{ "sites_matched",
		  is_map_inline ? static_cast<int64_t>(inlined.size()) :
				  (changed ? 1 : 0) },
		{ "sites_skipped", 0 },
		{ "skip_reasons", llvm::json::Object{} },
		{ "skipped_sites", llvm::json::Array{} },
		{ "diagnostics", llvm::json::Array{} },
		{ "insn_count_before", input.size() / INSN_SIZE },
		{ "insn_count_after", output.size() / INSN_SIZE },
		{ "insn_delta",
		  static_cast<int64_t>(output.size() / INSN_SIZE) -
			  static_cast<int64_t>(input.size() / INSN_SIZE) },
		{ "inlined_map_entries", std::move(inlined_entries) },
	};
	std::string json;
	llvm::raw_string_ostream os(json);
	os << llvm::formatv("{0:2}", llvm::json::Value(std::move(report)))
	   << "\n";
	write_text(*cli.report, os.str());
}

void run_pass(Cli &cli)
{
	if (!cli.pass) {
		throw std::runtime_error("bpfopt requires --pass <name>");
	}
	if (!cli.map_ids.empty()) {
		throw std::runtime_error(
			"--map-ids requires --canonicalize-map-refs or a pass-local use after --");
	}
	if (cli.target_output) {
		throw std::runtime_error(
			"--target-output requires --canonicalize-map-refs");
	}
	const auto input = read_all(cli.input);
	std::vector<InlineRecord> inlined;
	std::vector<uint8_t> output;
	if (*cli.pass == "noop") {
		output = run_llvm_roundtrip(input, false);
	} else if (*cli.pass == "map_inline") {
		output = run_map_inline_roundtrip(input, cli, inlined);
	} else {
		output = run_llvm_roundtrip(input, true);
	}
	write_all(cli.output, output);
	write_report(cli, input, output, inlined);
}

std::string next_value(int &i, int argc, char **argv, std::string_view opt)
{
	if (i + 1 >= argc) {
		throw std::runtime_error("missing value after " + std::string(opt));
	}
	return argv[++i];
}

Cli parse_cli(int argc, char **argv)
{
	Cli cli;
	bool after_dashdash = false;
	for (int i = 1; i < argc; i++) {
		const std::string arg = argv[i];
		if (after_dashdash) {
			cli.pass_args.push_back(arg);
		} else if (arg == "--") {
			after_dashdash = true;
		} else if (arg == "--help" || arg == "-h") {
			std::cout
				<< "bpfopt LLVM drop-in\n"
				<< "  --canonicalize-map-refs --input FILE --output FILE [--map-ids CSV]\n"
				<< "  --pass NAME --input FILE --output FILE [--report FILE]\n";
			std::exit(0);
		} else if (arg == "--version" || arg == "-V") {
			std::cout << "bpfopt-llvm 0.1.0\n";
			std::exit(0);
		} else if (arg == "--canonicalize-map-refs") {
			cli.canonicalize_map_refs = true;
		} else if (arg == "--pass") {
			cli.pass = next_value(i, argc, argv, arg);
		} else if (arg == "--input") {
			cli.input = next_value(i, argc, argv, arg);
		} else if (arg == "--output") {
			cli.output = next_value(i, argc, argv, arg);
		} else if (arg == "--report") {
			cli.report = next_value(i, argc, argv, arg);
		} else if (arg == "--target") {
			cli.target = next_value(i, argc, argv, arg);
		} else if (arg == "--target-output") {
			cli.target_output = next_value(i, argc, argv, arg);
		} else if (arg == "--verifier-states") {
			cli.verifier_states = next_value(i, argc, argv, arg);
		} else if (arg == "--func-info") {
			cli.func_info = next_value(i, argc, argv, arg);
		} else if (arg == "--line-info") {
			cli.line_info = next_value(i, argc, argv, arg);
		} else if (arg == "--prog-type") {
			cli.prog_type = next_value(i, argc, argv, arg);
		} else if (arg == "--map-ids") {
			cli.map_ids = next_value(i, argc, argv, arg);
		} else if (arg == "--func-info-rec-size") {
			cli.func_info_rec_size = next_value(i, argc, argv, arg);
		} else if (arg == "--line-info-rec-size") {
			cli.line_info_rec_size = next_value(i, argc, argv, arg);
		} else {
			throw std::runtime_error("unknown argument: " + arg);
		}
	}
	return cli;
}

} // namespace

int main(int argc, char **argv)
{
	try {
		auto cli = parse_cli(argc, argv);
		if (cli.canonicalize_map_refs) {
			canonicalize_map_refs(cli);
		} else {
			run_pass(cli);
		}
		return 0;
	} catch (const std::exception &err) {
		std::cerr << "error: " << err.what() << "\n";
		return 1;
	}
}
