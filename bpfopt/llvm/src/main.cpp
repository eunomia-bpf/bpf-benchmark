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
#include "llvm/IR/Dominators.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/Support/JSON.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/DCE.h"
#include "llvm/Transforms/Scalar/SROA.h"
#include "llvm/Transforms/Utils/Mem2Reg.h"

namespace {

constexpr uint8_t BPF_LD_IMM64 = 0x18;
constexpr uint8_t BPF_CALL = 0x85;
constexpr uint8_t BPF_CALLX = BPF_CALL | 0x08;
constexpr uint8_t BPF_EXIT = 0x95;
constexpr uint8_t BPF_PSEUDO_MAP_FD = 1;
constexpr uint8_t BPF_PSEUDO_MAP_VALUE = 2;
constexpr uint8_t BPF_PSEUDO_MAP_IDX = 5;
constexpr uint8_t BPF_PSEUDO_MAP_IDX_VALUE = 6;
constexpr uint8_t BPF_PSEUDO_CALL = 1;
constexpr uint8_t BPF_PSEUDO_FUNC = 4;
constexpr uint8_t BPF_PSEUDO_KINSN_CALL = 4;
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
	std::optional<std::filesystem::path> fd_to_id;
	std::optional<std::filesystem::path> func_info;
	std::optional<std::filesystem::path> line_info;
	std::string prog_type;
	std::string map_ids;
	std::string func_info_rec_size;
	std::string line_info_rec_size;
	std::vector<std::string> pass_args;
};

struct KinsnTarget {
	int32_t btf_func_id = 0;
	int16_t call_offset = 0;
};

using KinsnTargetMap = std::map<std::string, KinsnTarget>;

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

std::map<int32_t, uint32_t>
read_fd_to_id_map(const std::filesystem::path &path)
{
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	auto *root = value.getAsObject();
	if (!root) {
		throw std::runtime_error("--fd-to-id JSON root is not an object");
	}
	std::map<int32_t, uint32_t> out;
	for (const auto &entry : *root) {
		size_t consumed = 0;
		const auto key = entry.getFirst().str();
		long fd = std::stol(key, &consumed, 10);
		if (key.empty() || consumed != key.size() ||
		    fd < std::numeric_limits<int32_t>::min() ||
		    fd > std::numeric_limits<int32_t>::max()) {
			throw std::runtime_error(
				"--fd-to-id has non-i32 loader fd key: " + key);
		}
		const auto id = entry.getSecond().getAsInteger();
		if (!id || *id < 0 ||
		    *id > std::numeric_limits<uint32_t>::max()) {
			throw std::runtime_error(
				"--fd-to-id has non-u32 map id for fd: " + key);
		}
		out.emplace(static_cast<int32_t>(fd),
			    static_cast<uint32_t>(*id));
	}
	return out;
}

KinsnTargetMap read_kinsn_targets(const std::filesystem::path &path)
{
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	auto *root = value.getAsObject();
	if (!root) {
		throw std::runtime_error("--target JSON root is not an object");
	}
	auto *kinsns = root->getObject("kinsns");
	if (!kinsns) {
		throw std::runtime_error("--target JSON has no kinsns object");
	}
	KinsnTargetMap out;
	for (const auto &entry : *kinsns) {
		auto *obj = entry.getSecond().getAsObject();
		if (!obj) {
			throw std::runtime_error("target kinsn is not an object: " +
						 entry.getFirst().str());
		}
		auto func_id = obj->getInteger("btf_func_id");
		if (!func_id || *func_id <= 0 ||
		    *func_id > std::numeric_limits<int32_t>::max()) {
			throw std::runtime_error(
				"target kinsn has invalid btf_func_id: " +
				entry.getFirst().str());
		}
		auto call_offset = obj->getInteger("call_offset");
		if (!call_offset || *call_offset < 0 ||
		    *call_offset > std::numeric_limits<int16_t>::max()) {
			throw std::runtime_error(
				"target kinsn has invalid call_offset: " +
				entry.getFirst().str());
		}
		out.emplace(entry.getFirst().str(),
			    KinsnTarget{
				    static_cast<int32_t>(*func_id),
				    static_cast<int16_t>(*call_offset),
			    });
	}
	return out;
}

bool is_kinsn_pass(std::string_view pass)
{
	static constexpr std::string_view passes[] = {
		"rotate", "cond_select", "extract", "endian_fusion",
		"bulk_memory", "lea", "prefetch", "ccmp",
	};
	return std::find(std::begin(passes), std::end(passes), pass) !=
	       std::end(passes);
}

std::string trim_copy(std::string_view value)
{
	while (!value.empty() &&
	       std::isspace(static_cast<unsigned char>(value.front()))) {
		value.remove_prefix(1);
	}
	while (!value.empty() &&
	       std::isspace(static_cast<unsigned char>(value.back()))) {
		value.remove_suffix(1);
	}
	return std::string(value);
}

std::string pass_arg_value(const std::vector<std::string> &args, size_t &i,
			   std::string_view option)
{
	const std::string prefix = std::string(option) + "=";
	const auto &arg = args[i];
	if (arg.starts_with(prefix)) {
		return arg.substr(prefix.size());
	}
	if (arg != option) {
		throw std::runtime_error("internal pass arg parser mismatch");
	}
	if (++i >= args.size()) {
		throw std::runtime_error(std::string(option) + " requires VALUE");
	}
	return args[i];
}

void validate_kinsn_mode_arg(std::string_view value)
{
	size_t start = 0;
	while (start <= value.size()) {
		const size_t comma = value.find(',', start);
		const auto end = comma == std::string_view::npos ? value.size() :
								 comma;
		const std::string spec = trim_copy(value.substr(start, end - start));
		if (spec.empty()) {
			throw std::runtime_error("empty --kinsn-mode entry");
		}
		const size_t eq = spec.find('=');
		if (eq == std::string::npos || eq == 0 || eq + 1 >= spec.size() ||
		    spec.find('=', eq + 1) != std::string::npos) {
			throw std::runtime_error("invalid --kinsn-mode entry: " +
						 spec);
		}
		const std::string family = trim_copy(
			std::string_view(spec).substr(0, eq));
		const std::string mode = trim_copy(
			std::string_view(spec).substr(eq + 1));
		if (mode != "disable" && mode != "cost" && mode != "force") {
			throw std::runtime_error("invalid --kinsn-mode value: " +
						 mode);
		}
		if (comma == std::string_view::npos) {
			break;
		}
		start = comma + 1;
	}
}

std::vector<std::string> parse_kinsn_llvm_args(std::string_view pass,
					       const std::vector<std::string> &args)
{
	std::vector<std::string> llvm_args;
	for (size_t i = 0; i < args.size(); i++) {
		const auto &arg = args[i];
		if (arg == "--kinsn-mode" || arg.starts_with("--kinsn-mode=")) {
			const std::string value =
				pass_arg_value(args, i, "--kinsn-mode");
			validate_kinsn_mode_arg(value);
			llvm_args.push_back("-bpf-kinsn-mode=" + value);
		} else if (arg == "--llvm-arg" ||
			   arg.starts_with("--llvm-arg=")) {
			std::string value = pass_arg_value(args, i, "--llvm-arg");
			if (value.starts_with("-bpf-kinsn-mode=")) {
				validate_kinsn_mode_arg(
					std::string_view(value).substr(
						std::string_view(
							"-bpf-kinsn-mode=")
							.size()));
			} else if (value.starts_with(
					   "-bpf-kinsn-rotate-amortization-threshold=")) {
				if (pass != "rotate") {
					throw std::runtime_error(
						"rotate amortization threshold is only valid for rotate");
				}
			} else {
				throw std::runtime_error(
					"kinsn --llvm-arg only accepts BPF kinsn selector options");
			}
			llvm_args.push_back(std::move(value));
		} else {
			throw std::runtime_error("kinsn pass " + std::string(pass) +
						 " unknown pass-local arg: " + arg);
		}
	}
	return llvm_args;
}

void configure_llvm_kinsn_select(const std::vector<std::string> &llvm_args)
{
	std::vector<std::string> args{ "bpfopt", "-bpf-enable-kinsn-select" };
	for (const auto &arg : llvm_args) {
		args.push_back(arg);
	}
	std::vector<const char *> argv;
	argv.reserve(args.size());
	for (const auto &arg : args) {
		argv.push_back(arg.c_str());
	}
	llvm::cl::ParseCommandLineOptions(static_cast<int>(argv.size()),
					  argv.data(), "bpfopt LLVM kinsn\n");
}

int64_t count_kinsn_calls(const std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t count = 0;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
		    src_reg(bytes, pc) == BPF_PSEUDO_KINSN_CALL) {
			count++;
		}
	}
	return count;
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
	std::map<uint32_t, size_t> map_id_to_idx;
	for (size_t i = 0; i < map_ids.size(); i++) {
		map_id_to_idx.emplace(map_ids[i], i);
	}
	const auto fd_to_id =
		cli.fd_to_id ? std::optional(read_fd_to_id_map(*cli.fd_to_id)) :
			       std::nullopt;
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
			if (fd_to_id) {
				const auto id = fd_to_id->find(fd);
				if (id == fd_to_id->end()) {
					throw std::runtime_error(
						"loader fd " + std::to_string(fd) +
						" is not in --fd-to-id mapping");
				}
				const auto idx = map_id_to_idx.find(id->second);
				if (idx == map_id_to_idx.end()) {
					throw std::runtime_error(
						"kernel map id " +
						std::to_string(id->second) +
						" is not in --map-ids");
				}
				fd_to_idx.emplace(fd, idx->second);
			} else if (!fd_to_idx.contains(fd)) {
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
		  const std::vector<InlineRecord> &inlined = {},
		  std::optional<int64_t> sites_applied_override = std::nullopt,
		  const std::vector<std::string> &diagnostics = {})
{
	if (!cli.report) {
		return;
	}
	const bool changed = input != output;
	const bool is_map_inline = cli.pass && *cli.pass == "map_inline";
	llvm::json::Array inlined_entries;
	llvm::json::Array diagnostic_entries;
	for (const auto &record : inlined) {
		inlined_entries.emplace_back(llvm::json::Object{
			{ "map_id", static_cast<int64_t>(record.map_id) },
			{ "key_hex", bytes_hex(record.key) },
			{ "value_hex", bytes_hex(record.value) },
		});
	}
	for (const auto &diagnostic : diagnostics) {
		diagnostic_entries.emplace_back(diagnostic);
	}
	llvm::json::Object report{
		{ "pass", *cli.pass },
		{ "sites_applied",
		  sites_applied_override.value_or(
			  is_map_inline ? static_cast<int64_t>(inlined.size()) :
					  (changed ? 1 : 0)) },
		{ "sites_matched",
		  sites_applied_override.value_or(
			  is_map_inline ? static_cast<int64_t>(inlined.size()) :
					  (changed ? 1 : 0)) },
		{ "sites_skipped", 0 },
		{ "skip_reasons", llvm::json::Object{} },
		{ "skipped_sites", llvm::json::Array{} },
		{ "diagnostics", std::move(diagnostic_entries) },
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
	if (cli.fd_to_id) {
		throw std::runtime_error(
			"--fd-to-id requires --canonicalize-map-refs");
	}
	const bool kinsn_pass = is_kinsn_pass(*cli.pass);
	KinsnTargetMap kinsn_targets;
	if (kinsn_pass) {
		if (!cli.target) {
			throw std::runtime_error("--pass " + *cli.pass +
						 " requires --target");
		}
		kinsn_targets = read_kinsn_targets(*cli.target);
		configure_llvm_kinsn_select(
			parse_kinsn_llvm_args(*cli.pass, cli.pass_args));
	} else if (*cli.pass != "map_inline" && !cli.pass_args.empty()) {
		throw std::runtime_error("--pass " + *cli.pass +
					 " does not accept pass-local args");
	}
	const auto input = read_all(cli.input);
	std::vector<InlineRecord> inlined;
	std::vector<uint8_t> output;
	std::optional<int64_t> sites_applied;
	std::vector<std::string> diagnostics;
	if (kinsn_pass && count_kinsn_calls(input) > 0) {
		output = input;
		sites_applied = 0;
		write_all(cli.output, output);
		write_report(cli, input, output, inlined, sites_applied,
			     diagnostics);
		return;
	}
	if (*cli.pass == "map_inline") {
		output = run_map_inline_roundtrip(input, cli, inlined);
	} else {
		output = run_llvm_roundtrip(
			input, kinsn_pass ? &kinsn_targets : nullptr);
		if (kinsn_pass) {
			sites_applied = count_kinsn_calls(output);
			if (*sites_applied == 0) {
				output = input;
			}
		}
	}
	write_all(cli.output, output);
	write_report(cli, input, output, inlined, sites_applied, diagnostics);
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
		} else if (arg == "--fd-to-id") {
			cli.fd_to_id = next_value(i, argc, argv, arg);
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
