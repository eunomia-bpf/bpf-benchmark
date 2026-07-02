#include <algorithm>
#include <array>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
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
#include "llvm/IR/MDBuilder.h"
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
constexpr uint8_t BPF_LDXW = 0x61;
constexpr uint8_t BPF_LDXH = 0x69;
constexpr uint8_t BPF_LDXB = 0x71;
constexpr uint8_t BPF_LDXDW = 0x79;
constexpr uint8_t BPF_STXDW = 0x7b;
constexpr uint8_t BPF_CALL = 0x85;
constexpr uint8_t BPF_CALLX = BPF_CALL | 0x08;
constexpr uint8_t BPF_EXIT = 0x95;
constexpr uint8_t BPF_MOV32_X = 0xbc;
constexpr uint8_t BPF_MOV64_X = 0xbf;
constexpr uint8_t BPF_MOV64_K = 0xb7;
constexpr uint8_t BPF_LSH64_K = 0x67;
constexpr uint8_t BPF_RSH64_K = 0x77;
constexpr uint8_t BPF_AND32_K = 0x54;
constexpr uint8_t BPF_AND64_X = 0x5f;
constexpr uint8_t BPF_AND64_K = 0x57;
constexpr uint8_t BPF_OR64_X = 0x4f;
constexpr uint8_t BPF_XOR64_K = 0xa7;
constexpr uint8_t BPF_JGT64_K = 0x25;
constexpr uint8_t BPF_JGT32_K = 0x26;
constexpr uint8_t BPF_JGE32_K = 0x36;
constexpr uint8_t BPF_JLT32_K = 0xa6;
constexpr uint8_t BPF_JLE32_K = 0xb6;
constexpr uint8_t BPF_JA = 0x05;
constexpr uint8_t BPF_JA_IMM = 0x06;
constexpr uint8_t BPF_JEQ64_K = 0x15;
constexpr uint8_t BPF_CLASS_MASK = 0x07;
constexpr uint8_t BPF_LD_CLASS = 0x00;
constexpr uint8_t BPF_LDX_CLASS = 0x01;
constexpr uint8_t BPF_ST_CLASS = 0x02;
constexpr uint8_t BPF_STX_CLASS = 0x03;
constexpr uint8_t BPF_ALU_CLASS = 0x04;
constexpr uint8_t BPF_JMP_CLASS = 0x05;
constexpr uint8_t BPF_JMP32_CLASS = 0x06;
constexpr uint8_t BPF_ALU64_CLASS = 0x07;
constexpr uint8_t BPF_SIZE_MASK = 0x18;
constexpr uint8_t BPF_W_SIZE = 0x00;
constexpr uint8_t BPF_H_SIZE = 0x08;
constexpr uint8_t BPF_B_SIZE = 0x10;
constexpr uint8_t BPF_DW_SIZE = 0x18;
constexpr uint8_t BPF_PSEUDO_MAP_FD = 1;
constexpr uint8_t BPF_PSEUDO_MAP_VALUE = 2;
constexpr uint8_t BPF_PSEUDO_MAP_IDX = 5;
constexpr uint8_t BPF_PSEUDO_MAP_IDX_VALUE = 6;
constexpr uint8_t BPF_PSEUDO_CALL = 1;
constexpr uint8_t BPF_PSEUDO_FUNC = 4;
constexpr uint8_t BPF_PSEUDO_KINSN_SIDECAR = 3;
constexpr uint8_t BPF_PSEUDO_KINSN_CALL = 4;
constexpr size_t INSN_SIZE = 8;

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

enum class KinsnTargetArch {
	Unknown,
	X86,
	Arm64,
};

struct BytecodeKinsnPolicy {
	std::optional<bool> all_enabled;
	std::map<std::string, bool> family_enabled;
};

struct KinsnPassOptions {
	std::vector<std::string> llvm_args;
	std::vector<std::string> effective_llvm_args;
	BytecodeKinsnPolicy bytecode_policy;
};

struct BranchFlipOptions {
	std::optional<std::filesystem::path> profile;
};

struct BranchFlipProfileSite {
	uint64_t branch_count = 0;
	uint64_t branch_misses = 0;
	double miss_rate = 0.0;
	uint64_t taken = 0;
	uint64_t not_taken = 0;
};

struct BranchFlipProfile {
	std::map<size_t, BranchFlipProfileSite> per_site;
};

struct PassReportCounts {
	std::optional<int64_t> sites_applied;
	std::optional<int64_t> sites_matched;
	std::optional<int64_t> sites_skipped;
	std::map<std::string, int64_t> skip_reasons;
	std::vector<std::pair<size_t, std::string>> skipped_sites;
};

struct BranchFlipIrSite {
	size_t pc = 0;
	size_t block_start_pc = 0;
};

bool bytecode_kinsn_family_enabled(std::string_view pass, std::string_view family,
				   const BytecodeKinsnPolicy &policy);
bool target_has_kinsn(const KinsnTargetMap &targets, std::string_view name);
bool target_is_x86_kinsn_set(const KinsnTargetMap &targets);
bool target_is_arm64_kinsn_set(const KinsnTargetMap &targets);
bool kinsn_target_arch_is_x86(KinsnTargetArch arch,
			      const KinsnTargetMap &targets);
bool kinsn_target_arch_is_arm64(KinsnTargetArch arch,
				const KinsnTargetMap &targets);

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

KinsnTargetArch parse_kinsn_target_arch(std::string_view arch)
{
	std::string value;
	value.reserve(arch.size());
	for (const char ch : arch) {
		if (!std::isspace(static_cast<unsigned char>(ch))) {
			value.push_back(static_cast<char>(
				std::tolower(static_cast<unsigned char>(ch))));
		}
	}
	if (value.empty()) {
		return KinsnTargetArch::Unknown;
	}
	if (value == "x86" || value == "x86_64" || value == "amd64") {
		return KinsnTargetArch::X86;
	}
	if (value == "arm64" || value == "aarch64") {
		return KinsnTargetArch::Arm64;
	}
	throw std::runtime_error("unsupported target.json arch: " + value);
}

KinsnTargetArch read_kinsn_target_arch(const std::filesystem::path &path)
{
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	auto *root = value.getAsObject();
	if (!root) {
		throw std::runtime_error("--target JSON root is not an object");
	}
	const auto arch = root->getString("arch");
	if (!arch) {
		return KinsnTargetArch::Unknown;
	}
	return parse_kinsn_target_arch(arch->str());
}

bool kinsn_target_arch_is_x86(KinsnTargetArch arch,
			      const KinsnTargetMap &targets)
{
	if (arch == KinsnTargetArch::X86) {
		return true;
	}
	if (arch == KinsnTargetArch::Arm64) {
		return false;
	}
	return target_is_x86_kinsn_set(targets);
}

bool kinsn_target_arch_is_arm64(KinsnTargetArch arch,
				const KinsnTargetMap &targets)
{
	if (arch == KinsnTargetArch::Arm64) {
		return true;
	}
	if (arch == KinsnTargetArch::X86) {
		return false;
	}
	return target_is_arm64_kinsn_set(targets) &&
	       !target_is_x86_kinsn_set(targets);
}

bool is_kinsn_pass(std::string_view pass)
{
	static constexpr std::string_view passes[] = {
		"kinsn", "rotate", "cond_select", "extract", "endian_fusion",
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

BranchFlipOptions parse_branch_flip_pass_args(const std::vector<std::string> &args)
{
	BranchFlipOptions options;
	for (size_t i = 0; i < args.size(); i++) {
		const auto &arg = args[i];
		if (arg == "--profile" || arg.starts_with("--profile=")) {
			options.profile = pass_arg_value(args, i, "--profile");
		} else {
			throw std::runtime_error(
				"branch_flip unknown pass-local arg: " + arg);
		}
	}
	if (!options.profile) {
		throw std::runtime_error("branch_flip requires --profile");
	}
	return options;
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
		if (mode != "disable" && mode != "force") {
			throw std::runtime_error("invalid --kinsn-mode value: " +
						 mode);
		}
		if (comma == std::string_view::npos) {
			break;
		}
		start = comma + 1;
	}
}

bool is_bytecode_kinsn_family(std::string_view family)
{
	static constexpr std::string_view families[] = {
		"all", "rotate", "cond_select", "extract", "endian_fusion",
		"bulk_memory", "prefetch", "bitops", "ccmp",
	};
	return std::find(std::begin(families), std::end(families), family) !=
	       std::end(families);
}

void apply_bytecode_kinsn_mode_arg(BytecodeKinsnPolicy &policy,
				   std::string_view value)
{
	size_t start = 0;
	while (start <= value.size()) {
		const size_t comma = value.find(',', start);
		const auto end = comma == std::string_view::npos ? value.size() :
								 comma;
		const std::string spec = trim_copy(value.substr(start, end - start));
		if (spec.empty()) {
			throw std::runtime_error("empty --bytecode-kinsn-mode entry");
		}
		const size_t eq = spec.find('=');
		if (eq == std::string::npos || eq == 0 || eq + 1 >= spec.size() ||
		    spec.find('=', eq + 1) != std::string::npos) {
			throw std::runtime_error(
				"invalid --bytecode-kinsn-mode entry: " + spec);
		}
		const std::string family = trim_copy(
			std::string_view(spec).substr(0, eq));
		const std::string mode = trim_copy(
			std::string_view(spec).substr(eq + 1));
		if (!is_bytecode_kinsn_family(family)) {
			throw std::runtime_error(
				"invalid --bytecode-kinsn-mode family: " + family);
		}
		if (mode != "disable" && mode != "force") {
			throw std::runtime_error(
				"invalid --bytecode-kinsn-mode value: " + mode);
		}
		const bool enabled = mode == "force";
		if (family == "all") {
			policy.all_enabled = enabled;
		} else {
			policy.family_enabled[family] = enabled;
		}
		if (comma == std::string_view::npos) {
			break;
		}
		start = comma + 1;
	}
}

KinsnPassOptions parse_kinsn_pass_args(std::string_view pass,
				       const std::vector<std::string> &args)
{
	KinsnPassOptions options;
	for (size_t i = 0; i < args.size(); i++) {
		const auto &arg = args[i];
		if (arg == "--kinsn-mode" || arg.starts_with("--kinsn-mode=")) {
			const std::string value =
				pass_arg_value(args, i, "--kinsn-mode");
			validate_kinsn_mode_arg(value);
			options.llvm_args.push_back("-bpf-kinsn-mode=" + value);
		} else if (arg == "--bytecode-kinsn-mode" ||
			   arg.starts_with("--bytecode-kinsn-mode=")) {
			const std::string value =
				pass_arg_value(args, i, "--bytecode-kinsn-mode");
			apply_bytecode_kinsn_mode_arg(options.bytecode_policy,
						      value);
		} else if (arg == "--llvm-arg" ||
			   arg.starts_with("--llvm-arg=")) {
			std::string value = pass_arg_value(args, i, "--llvm-arg");
			if (value.starts_with("-bpf-kinsn-mode=")) {
				validate_kinsn_mode_arg(
					std::string_view(value).substr(
						std::string_view(
							"-bpf-kinsn-mode=")
							.size()));
			} else {
				throw std::runtime_error(
					"kinsn --llvm-arg only accepts BPF kinsn policy options");
			}
			options.llvm_args.push_back(std::move(value));
		} else {
			throw std::runtime_error("kinsn pass " + std::string(pass) +
						 " unknown pass-local arg: " + arg);
		}
	}
	return options;
}

std::optional<std::string> default_kinsn_mode_for_pass(std::string_view pass)
{
	if (pass == "kinsn") {
		return "all=force,movbe-load=disable";
	}
	if (pass == "rotate") {
		return "all=disable,rotate=force";
	}
	if (pass == "extract") {
		return "all=disable,bextr=force,shd=force";
	}
	if (pass == "endian_fusion") {
		return "all=disable,unary=force,movbe-be=force";
	}
	if (pass == "bulk_memory") {
		return "all=disable,wide-load=force,indexed-load=force";
	}
	if (pass == "prefetch") {
		return "all=disable";
	}
	if (pass == "cond_select") {
		return "all=disable,cmov=force";
	}
	if (pass == "lea") {
		return "all=disable,preemit-lea=force,scaled-index-mem=force";
	}
	return std::nullopt;
}

std::vector<std::string>
configure_llvm_kinsn_select(std::string_view pass,
			    const std::vector<std::string> &llvm_args,
			    const KinsnTargetMap &kinsn_targets,
			    KinsnTargetArch target_arch)
{
	bool has_kinsn_mode = false;
	for (const auto &arg : llvm_args) {
		if (arg.starts_with("-bpf-kinsn-mode=")) {
			has_kinsn_mode = true;
			break;
		}
	}

	std::vector<std::string> args{ "bpfopt", "-bpf-enable-kinsn-select",
				       "-bpf-stack-size=4096" };
	const bool arm64_target =
		kinsn_target_arch_is_arm64(target_arch, kinsn_targets);
	if (arm64_target) {
		if (has_kinsn_mode) {
			throw std::runtime_error(
				"explicit LLVM kinsn mode is unsupported for arm64 targets");
		}
		args.push_back("-bpf-kinsn-mode=all=disable");
	} else if (!has_kinsn_mode) {
		if (const auto mode = default_kinsn_mode_for_pass(pass)) {
			args.push_back("-bpf-kinsn-mode=" + *mode);
		} else {
			throw std::runtime_error("no default kinsn mode for pass " +
						 std::string(pass));
		}
	}
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
	return args;
}

void apply_target_bytecode_policy_defaults(std::string_view pass,
					   const KinsnTargetMap &kinsn_targets,
					   KinsnTargetArch target_arch,
					   KinsnPassOptions &options)
{
	const bool arm64_target =
		kinsn_target_arch_is_arm64(target_arch, kinsn_targets);
	if (!arm64_target || pass != "kinsn" ||
	    options.bytecode_policy.all_enabled) {
		return;
	}
	static constexpr std::string_view disabled_by_default[] = {
		"prefetch",
	};
	for (std::string_view family : disabled_by_default) {
		const std::string key(family);
		if (options.bytecode_policy.family_enabled.find(key) ==
		    options.bytecode_policy.family_enabled.end()) {
			options.bytecode_policy.family_enabled[key] = false;
		}
	}
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

using KinsnCallKey = std::pair<int16_t, int32_t>;

std::map<KinsnCallKey, std::string>
kinsn_target_name_by_call_key(const KinsnTargetMap &targets)
{
	std::map<KinsnCallKey, std::string> names;
	for (const auto &[name, target] : targets) {
		const auto [_, inserted] = names.emplace(
			KinsnCallKey{ target.call_offset, target.btf_func_id },
			name);
		if (!inserted) {
			throw std::runtime_error(
				"target.json has duplicate kinsn relocation tuple for " +
				name);
		}
	}
	return names;
}

std::string kinsn_family_for_name(std::string_view name)
{
	if (name.starts_with("bpf_x86_lea")) {
		return "lea";
	}
	if (name.starts_with("bpf_x86_cmp_cmov") ||
	    name.starts_with("bpf_x86_cmov") ||
	    name.starts_with("bpf_arm64_csel")) {
		return "cond_select";
	}
	if (name.starts_with("bpf_arm64_ccmp")) {
		return "ccmp";
	}
	if (name.starts_with("bpf_arm64_cmp") ||
	    name.starts_with("bpf_arm64_cset")) {
		return "ccmp";
	}
	if (name == "bpf_x86_rolw" || name.starts_with("bpf_x86_bswap") ||
	    name.starts_with("bpf_x86_movbe") ||
	    name.starts_with("bpf_arm64_rev")) {
		return "endian_fusion";
	}
	if (name.starts_with("bpf_x86_rol") ||
	    name.starts_with("bpf_x86_ror") ||
	    name.starts_with("bpf_arm64_extr")) {
		return "rotate";
	}
	if (name.starts_with("bpf_x86_bextr") ||
	    name.starts_with("bpf_x86_shld") ||
	    name.starts_with("bpf_x86_shrd") ||
	    name.starts_with("bpf_arm64_ubfm")) {
		return "extract";
	}
	if (name.starts_with("bpf_x86_mov") ||
	    name.starts_with("bpf_arm64_ldr") ||
	    name.starts_with("bpf_arm64_str") ||
	    name.starts_with("bpf_arm64_ldp") ||
	    name.starts_with("bpf_arm64_stp")) {
		return "bulk_memory";
	}
	if (name.starts_with("bpf_x86_prefetch") ||
	    name.starts_with("bpf_arm64_prfm")) {
		return "prefetch";
	}
	if (name.starts_with("bpf_x86_blsi") ||
	    name.starts_with("bpf_x86_blsr") ||
	    name.starts_with("bpf_x86_bzhi") ||
	    name.starts_with("bpf_x86_shlx") ||
	    name.starts_with("bpf_x86_shrx") ||
	    name.starts_with("bpf_x86_popcnt") ||
	    name.starts_with("bpf_x86_and") ||
	    name.starts_with("bpf_x86_not") ||
	    name.starts_with("bpf_x86_imul")) {
		return "bitops";
	}
	return "other";
}

std::map<std::string, int64_t>
count_kinsn_calls_by_name(const std::vector<uint8_t> &bytes,
			  const KinsnTargetMap &targets)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const auto names = kinsn_target_name_by_call_key(targets);
	std::map<std::string, int64_t> counts;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if ((opcode != BPF_CALL && opcode != BPF_CALLX) ||
		    src_reg(bytes, pc) != BPF_PSEUDO_KINSN_CALL) {
			continue;
		}
		const KinsnCallKey key{ read_off(bytes, pc),
					read_imm(bytes, pc) };
		const auto it = names.find(key);
		if (it == names.end()) {
			throw std::runtime_error(
				"output bytecode references a kinsn relocation tuple missing from target.json");
		}
		counts[it->second]++;
	}
	return counts;
}

uint64_t read_kinsn_sidecar_payload(const std::vector<uint8_t> &bytes,
				    size_t pc)
{
	return static_cast<uint64_t>(dst_reg(bytes, pc) & 0xf) |
	       (static_cast<uint64_t>(
			static_cast<uint16_t>(read_off(bytes, pc)))
		<< 4) |
	       (static_cast<uint64_t>(
			static_cast<uint32_t>(read_imm(bytes, pc)))
		<< 20);
}

bool kinsn_payload_wire_escaped(uint64_t payload)
{
	const uint8_t marker = payload & 0xf;
	const uint8_t original_low = (payload >> 4) & 0xf;
	return marker == 10 && original_low >= 11 && original_low <= 15;
}

uint64_t decode_kinsn_payload(uint64_t payload)
{
	if (!kinsn_payload_wire_escaped(payload)) {
		return payload;
	}
	return ((payload >> 8) << 4) | ((payload >> 4) & 0xf);
}

std::string bpf_reg_name(uint8_t reg)
{
	if (reg <= 10) {
		return "r" + std::to_string(reg);
	}
	return "x" + std::to_string(reg);
}

std::string kinsn_payload_shape(std::string_view name, uint64_t payload)
{
	const uint64_t decoded = decode_kinsn_payload(payload);
	if (name.starts_with("bpf_x86_lea")) {
		if ((decoded & 0xf) != 1 || decoded >> 52) {
			std::ostringstream os;
			os << name << "|payload=0x" << std::hex << decoded;
			return os.str();
		}
		const uint8_t dst = (decoded >> 4) & 0xf;
		const uint8_t base = (decoded >> 8) & 0xf;
		const uint8_t index = (decoded >> 12) & 0xf;
		const uint8_t scale = (decoded >> 16) & 0x3;
		const bool has_index = (decoded >> 18) & 1;
		const bool has_base = (decoded >> 19) & 1;
		const int32_t disp =
			static_cast<int32_t>(static_cast<uint32_t>(decoded >> 20));

		std::ostringstream os;
		os << name << "|dst=" << bpf_reg_name(dst)
		   << "|base=" << (has_base ? bpf_reg_name(base) : "none")
		   << "|index=" << (has_index ? bpf_reg_name(index) : "none")
		   << "|scale=" << static_cast<unsigned>(scale)
		   << "|disp=" << disp;
		return os.str();
	}

	std::ostringstream os;
	os << name << "|payload=0x" << std::hex << decoded;
	return os.str();
}

std::map<std::string, int64_t>
count_kinsn_payload_shapes(const std::vector<uint8_t> &bytes,
			   const KinsnTargetMap &targets)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const auto names = kinsn_target_name_by_call_key(targets);
	std::map<std::string, int64_t> counts;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if ((opcode != BPF_CALL && opcode != BPF_CALLX) ||
		    src_reg(bytes, pc) != BPF_PSEUDO_KINSN_CALL) {
			continue;
		}
		if (pc == 0 || bytes[(pc - 1) * INSN_SIZE] != BPF_MOV64_K ||
		    src_reg(bytes, pc - 1) != BPF_PSEUDO_KINSN_SIDECAR) {
			throw std::runtime_error(
				"output bytecode has kinsn call without preceding sidecar");
		}
		const KinsnCallKey key{ read_off(bytes, pc),
					read_imm(bytes, pc) };
		const auto it = names.find(key);
		if (it == names.end()) {
			throw std::runtime_error(
				"output bytecode references a kinsn relocation tuple missing from target.json");
		}
		counts[kinsn_payload_shape(
			it->second,
			read_kinsn_sidecar_payload(bytes, pc - 1))]++;
	}
	return counts;
}

llvm::json::Object counter_json(const std::map<std::string, int64_t> &counts)
{
	llvm::json::Object out;
	for (const auto &[name, count] : counts) {
		out[name] = count;
	}
	return out;
}

llvm::json::Array string_array_json(const std::vector<std::string> &values)
{
	llvm::json::Array out;
	for (const auto &value : values) {
		out.emplace_back(value);
	}
	return out;
}

std::map<std::string, int64_t>
counter_delta(std::map<std::string, int64_t> after,
	      const std::map<std::string, int64_t> &before)
{
	for (const auto &[name, count] : before) {
		after[name] -= count;
		if (after[name] < 0) {
			throw std::runtime_error("kinsn report counter decreased for " +
						 name);
		}
		if (after[name] == 0) {
			after.erase(name);
		}
	}
	return after;
}

std::map<std::string, int64_t>
kinsn_call_family_counts(const std::map<std::string, int64_t> &by_name)
{
	std::map<std::string, int64_t> by_family;
	for (const auto &[name, count] : by_name) {
		by_family[kinsn_family_for_name(name)] += count;
	}
	return by_family;
}

llvm::json::Object
bytecode_kinsn_family_policy_json(std::string_view pass,
				  const BytecodeKinsnPolicy &policy)
{
	static constexpr std::string_view families[] = {
		"rotate", "cond_select", "extract", "endian_fusion",
		"bulk_memory", "prefetch", "bitops", "ccmp",
	};

	llvm::json::Object out;
	for (const auto family : families) {
		out[std::string(family)] =
			bytecode_kinsn_family_enabled(pass, family, policy);
	}
	return out;
}

llvm::json::Object kinsn_policy_json(const Cli &cli,
				     const KinsnPassOptions &options)
{
	llvm::json::Object policy{
		{ "pass_args", string_array_json(cli.pass_args) },
		{ "llvm_args", string_array_json(options.effective_llvm_args) },
		{ "bytecode_families",
		  bytecode_kinsn_family_policy_json(*cli.pass,
						    options.bytecode_policy) },
	};
	if (options.bytecode_policy.all_enabled) {
		policy["bytecode_all_override"] =
			*options.bytecode_policy.all_enabled;
	}
	llvm::json::Object family_overrides;
	for (const auto &[family, enabled] : options.bytecode_policy.family_enabled) {
		family_overrides[family] = enabled;
	}
	policy["bytecode_family_overrides"] = std::move(family_overrides);
	return policy;
}

bool load_zero_extends_within_mask(uint8_t opcode, uint64_t mask)
{
	switch (opcode) {
	case BPF_LDXB:
		return mask >= 0xff;
	case BPF_LDXH:
		return mask >= 0xffff;
	case BPF_LDXW:
		return mask >= 0xffffffffULL;
	default:
		return false;
	}
}

bool opcode_defines_dst(uint8_t opcode)
{
	switch (opcode & BPF_CLASS_MASK) {
	case BPF_LD_CLASS:
		return opcode == BPF_LD_IMM64;
	case BPF_LDX_CLASS:
	case BPF_ALU_CLASS:
	case BPF_ALU64_CLASS:
		return true;
	default:
		return false;
	}
}

bool is_masked_range_intervening_insn(const std::vector<uint8_t> &bytes,
				      size_t pc, uint8_t tmp, uint8_t src)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	if (klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS ||
	    klass == BPF_STX_CLASS || opcode == BPF_LD_IMM64) {
		return false;
	}
	if (opcode_defines_dst(opcode)) {
		const uint8_t dst = dst_reg(bytes, pc);
		if (dst == tmp || dst == src) {
			return false;
		}
	}
	return true;
}

bool is_masked_range_branch(uint8_t opcode)
{
	return opcode == BPF_JGT32_K || opcode == BPF_JGE32_K ||
	       opcode == BPF_JLT32_K || opcode == BPF_JLE32_K;
}

bool is_same_mask_and(uint8_t opcode, int32_t imm, uint64_t mask)
{
	if (imm < 0 || static_cast<uint64_t>(imm) != mask) {
		return false;
	}
	return opcode == BPF_AND32_K || opcode == BPF_AND64_K;
}

void rewrite_insn_to_mov32_x(std::vector<uint8_t> &bytes, size_t pc,
			     uint8_t dst, uint8_t src)
{
	const size_t off = pc * INSN_SIZE;
	bytes[off] = BPF_MOV32_X;
	bytes[off + 1] = static_cast<uint8_t>((src << 4) | dst);
	bytes[off + 2] = 0;
	bytes[off + 3] = 0;
	write_imm(bytes, pc, 0);
}

void rewrite_insn_to_mov64_x(std::vector<uint8_t> &bytes, size_t pc,
			     uint8_t dst, uint8_t src)
{
	const size_t off = pc * INSN_SIZE;
	bytes[off] = BPF_MOV64_X;
	bytes[off + 1] = static_cast<uint8_t>((src << 4) | dst);
	bytes[off + 2] = 0;
	bytes[off + 3] = 0;
	write_imm(bytes, pc, 0);
}

std::optional<int> bpf_mem_width(uint8_t opcode)
{
	switch (opcode & BPF_SIZE_MASK) {
	case BPF_B_SIZE:
		return 1;
	case BPF_H_SIZE:
		return 2;
	case BPF_W_SIZE:
		return 4;
	case BPF_DW_SIZE:
		return 8;
	default:
		return std::nullopt;
	}
}

std::optional<size_t> stack_ctx_slot_index(int16_t off)
{
	if (off < -512 || off > -8) {
		return std::nullopt;
	}
	return static_cast<size_t>(-off);
}

bool byte_ranges_overlap(int lhs_start, int lhs_width, int rhs_start,
			 int rhs_width)
{
	const int lhs_end = lhs_start + lhs_width;
	const int rhs_end = rhs_start + rhs_width;
	return lhs_start < rhs_end && rhs_start < lhs_end;
}

struct StackMemRef {
	size_t pc = 0;
	int16_t off = 0;
	int width = 0;
	bool write = false;
};

std::optional<StackMemRef> fp_stack_mem_ref(const std::vector<uint8_t> &bytes,
					    size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	bool fp_based = false;
	if (klass == BPF_LDX_CLASS) {
		fp_based = src_reg(bytes, pc) == 10;
	} else if (klass == BPF_ST_CLASS || klass == BPF_STX_CLASS) {
		fp_based = dst_reg(bytes, pc) == 10;
	}
	if (!fp_based) {
		return std::nullopt;
	}
	const auto width = bpf_mem_width(opcode);
	if (!width) {
		return std::nullopt;
	}
	return StackMemRef{ pc, read_off(bytes, pc), *width,
			    klass == BPF_ST_CLASS || klass == BPF_STX_CLASS };
}

bool valid_bpf_stack_range(int off, int width)
{
	return off >= -512 && off + width <= 0;
}

constexpr int X86_KINSN_STACK_OFF = -40;
constexpr int X86_KINSN_STACK_BYTES = 40;

bool overlaps_x86_kinsn_stack_contract(int off, int width)
{
	return byte_ranges_overlap(off, width, X86_KINSN_STACK_OFF,
				   X86_KINSN_STACK_BYTES);
}

struct StackAccess {
	size_t pc = 0;
	int off = 0;
	int width = 0;
	bool write = false;
};

bool is_kinsn_sidecar(const std::vector<uint8_t> &bytes, size_t pc)
{
	return bytes[pc * INSN_SIZE] == BPF_MOV64_K &&
	       src_reg(bytes, pc) == BPF_PSEUDO_KINSN_SIDECAR;
}

bool is_kinsn_call(const std::vector<uint8_t> &bytes, size_t pc)
{
	return bytes[pc * INSN_SIZE] == BPF_CALL &&
	       src_reg(bytes, pc) == BPF_PSEUDO_KINSN_CALL;
}

bool candidate_access_overlaps(const StackAccess &access, int off, int width)
{
	return byte_ranges_overlap(access.off, access.width, off, width);
}

bool candidate_has_access_in_range(const std::vector<StackAccess> &accesses,
				   int off, int width, size_t first_pc,
				   size_t last_pc, bool writes_only)
{
	for (const auto &access : accesses) {
		if (access.pc < first_pc || access.pc > last_pc) {
			continue;
		}
		if (writes_only && !access.write) {
			continue;
		}
		if (candidate_access_overlaps(access, off, width)) {
			return true;
		}
	}
	return false;
}

std::optional<StackAccess> first_candidate_access_after(
	const std::vector<StackAccess> &accesses, int off, int width,
	size_t pc)
{
	std::optional<StackAccess> first;
	for (const auto &access : accesses) {
		if (access.pc <= pc ||
		    !candidate_access_overlaps(access, off, width)) {
			continue;
		}
		if (!first || access.pc < first->pc) {
			first = access;
		}
	}
	return first;
}

bool candidate_is_free_for_range(const std::vector<StackAccess> &accesses,
				 int off, int width, size_t first_pc,
				 size_t last_pc)
{
	if (candidate_has_access_in_range(accesses, off, width, first_pc,
					  last_pc, false)) {
		return false;
	}
	const auto next = first_candidate_access_after(accesses, off, width,
						       last_pc);
	return !next || next->write;
}

int64_t remap_out_of_range_stack_spills(std::vector<uint8_t> &bytes,
					bool reserve_x86_kinsn_stack)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}

	std::map<int16_t, int> invalid_slots;
	std::map<int16_t, std::vector<StackMemRef>> invalid_refs;
	std::vector<StackAccess> accesses;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const auto ref = fp_stack_mem_ref(bytes, pc);
		if (!ref) {
			continue;
		}
		if (valid_bpf_stack_range(ref->off, ref->width)) {
			accesses.push_back(StackAccess{
				ref->pc, ref->off, ref->width, ref->write });
			continue;
		}
		if (ref->width <= 0 || ref->width > 8 || ref->off >= -512) {
			throw std::runtime_error(
				"LLVM output has non-remappable out-of-range stack access");
		}
		const auto [it, inserted] =
			invalid_slots.emplace(ref->off, ref->width);
		if (!inserted && it->second != ref->width) {
			throw std::runtime_error(
				"LLVM output has inconsistent out-of-range stack slot width");
		}
		invalid_refs[ref->off].push_back(*ref);
	}
	if (invalid_slots.empty()) {
		return 0;
	}

	std::map<int16_t, int16_t> remap;
	std::vector<StackAccess> remapped_accesses = accesses;
	for (const auto &[old_off, width] : invalid_slots) {
		const auto refs_it = invalid_refs.find(old_off);
		if (refs_it == invalid_refs.end() || refs_it->second.empty()) {
			throw std::runtime_error(
				"LLVM output has invalid stack slot without references");
		}
		const size_t first_pc = refs_it->second.front().pc;
		const size_t last_pc = refs_it->second.back().pc;
		std::optional<int16_t> replacement;
		for (int candidate = -512; candidate <= -width; candidate++) {
			if (!valid_bpf_stack_range(candidate, width)) {
				continue;
			}
			if (reserve_x86_kinsn_stack &&
			    overlaps_x86_kinsn_stack_contract(candidate, width)) {
				continue;
			}
			if (!candidate_is_free_for_range(
				    remapped_accesses, candidate, width,
				    first_pc, last_pc)) {
				continue;
			}
			replacement = static_cast<int16_t>(candidate);
			break;
		}
		if (!replacement) {
			throw std::runtime_error(
				"LLVM output stack spills exceed the BPF 512-byte frame");
		}
		remap.emplace(old_off, *replacement);
		for (const auto &ref : refs_it->second) {
			remapped_accesses.push_back(StackAccess{
				ref.pc, *replacement, ref.width, ref.write });
		}
	}

	int64_t changed = 0;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const auto ref = fp_stack_mem_ref(bytes, pc);
		if (!ref) {
			continue;
		}
		const auto it = remap.find(ref->off);
		if (it == remap.end()) {
			continue;
		}
		write_off(bytes, pc, it->second);
		changed++;
	}
	return changed;
}

struct CtxState {
	std::array<uint8_t, 11> reg{};
	std::array<uint8_t, 513> stack{};
};

bool same_ctx_state(const CtxState &lhs, const CtxState &rhs)
{
	return lhs.reg == rhs.reg && lhs.stack == rhs.stack;
}

CtxState intersect_ctx_state(const CtxState &lhs, const CtxState &rhs)
{
	CtxState out;
	for (size_t i = 0; i < out.reg.size(); i++) {
		out.reg[i] = lhs.reg[i] && rhs.reg[i];
	}
	for (size_t i = 0; i < out.stack.size(); i++) {
		out.stack[i] = lhs.stack[i] && rhs.stack[i];
	}
	return out;
}

void clear_ctx_reg(CtxState &state, uint8_t reg)
{
	if (reg < 10) {
		state.reg[reg] = 0;
	}
}

void clear_overlapping_stack_ctx(CtxState &state, int16_t off, int width)
{
	for (size_t slot = 1; slot < state.stack.size(); slot++) {
		if (!state.stack[slot]) {
			continue;
		}
		const int slot_off = -static_cast<int>(slot);
		if (byte_ranges_overlap(off, width, slot_off, 8)) {
			state.stack[slot] = 0;
		}
	}
}

bool is_conditional_jump(uint8_t opcode)
{
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	return (klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS) &&
	       opcode != BPF_JA && opcode != BPF_JA_IMM && opcode != BPF_CALL &&
	       opcode != BPF_CALLX && opcode != BPF_EXIT;
}

std::array<uint8_t, INSN_SIZE> make_bpf_insn(uint8_t opcode, uint8_t dst,
					     uint8_t src, int16_t off,
					     int32_t imm)
{
	std::array<uint8_t, INSN_SIZE> insn{};
	insn[0] = opcode;
	insn[1] = static_cast<uint8_t>((src << 4) | dst);
	std::memcpy(&insn[2], &off, sizeof(off));
	std::memcpy(&insn[4], &imm, sizeof(imm));
	return insn;
}

uint64_t branch_flip_u64_field(const llvm::json::Object &object,
			       std::string_view key,
			       std::string_view context)
{
	auto value = object.getInteger(key);
	if (!value || *value < 0) {
		throw std::runtime_error("profile " + std::string(context) +
					 " missing u64 field " +
					 std::string(key));
	}
	return static_cast<uint64_t>(*value);
}

double branch_flip_probability_field(const llvm::json::Object &object,
				     std::string_view key,
				     std::string_view context)
{
	auto value = object.getNumber(key);
	if (!value || !std::isfinite(*value) || *value < 0.0 || *value > 1.0) {
		throw std::runtime_error("profile " + std::string(context) +
					 " field " + std::string(key) +
					 " must be finite and within [0, 1]");
	}
	return *value;
}

size_t branch_flip_parse_pc_key(const std::string &key)
{
	if (key.empty()) {
		throw std::runtime_error("invalid per_site pc key: " + key);
	}
	size_t consumed = 0;
	const unsigned long long raw = std::stoull(key, &consumed, 10);
	if (consumed != key.size() ||
	    raw > std::numeric_limits<size_t>::max()) {
		throw std::runtime_error("invalid per_site pc key: " + key);
	}
	return static_cast<size_t>(raw);
}

BranchFlipProfile read_branch_flip_profile(const std::filesystem::path &path)
{
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	const auto &root = json_object(value, path.string());

	BranchFlipProfile profile;
	auto *per_site = root.getObject("per_site");
	if (!per_site) {
		throw std::runtime_error(
			"profile root missing per_site object");
	}
	for (const auto &entry : *per_site) {
		const std::string pc_key = entry.getFirst().str();
		const size_t pc = branch_flip_parse_pc_key(pc_key);
		const auto &site_obj =
			json_object(entry.getSecond(), "per_site[" + pc_key + "]");
		BranchFlipProfileSite site;
		site.branch_count = branch_flip_u64_field(
			site_obj, "branch_count", "per_site[" + pc_key + "]");
		site.branch_misses = branch_flip_u64_field(
			site_obj, "branch_misses", "per_site[" + pc_key + "]");
		if (site.branch_misses > site.branch_count) {
			throw std::runtime_error(
				"profile per_site[" + pc_key +
				"] branch_misses exceeds branch_count");
		}
		site.miss_rate = branch_flip_probability_field(
			site_obj, "miss_rate", "per_site[" + pc_key + "]");
		const double computed_miss_rate =
			site.branch_count == 0
				? 0.0
				: static_cast<double>(site.branch_misses) /
					  static_cast<double>(site.branch_count);
		if (std::fabs(site.miss_rate - computed_miss_rate) > 1e-6) {
			throw std::runtime_error(
				"profile per_site[" + pc_key +
				"] miss_rate disagrees with branch_misses/branch_count");
		}
		site.taken = branch_flip_u64_field(
			site_obj, "taken", "per_site[" + pc_key + "]");
		site.not_taken = branch_flip_u64_field(
			site_obj, "not_taken", "per_site[" + pc_key + "]");
		if (site.taken > std::numeric_limits<uint64_t>::max() -
					 site.not_taken) {
			throw std::runtime_error("profile per_site[" + pc_key +
						 "] direction counters overflow");
		}
		const uint64_t direction_total = site.taken + site.not_taken;
		if (direction_total != site.branch_count) {
			throw std::runtime_error(
				"profile per_site[" + pc_key +
				"] branch_count disagrees with taken/not_taken");
		}
		profile.per_site.emplace(pc, site);
	}
	return profile;
}

bool is_llvmbpf_jump_class(uint8_t opcode)
{
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	return klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS;
}

int64_t checked_branch_flip_target(size_t pc, int64_t offset_or_imm,
				   size_t insn_count, std::string_view kind)
{
	const int64_t target =
		static_cast<int64_t>(pc) + 1 + offset_or_imm;
	if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
		throw std::runtime_error("branch_flip " + std::string(kind) +
					 " target out of range at pc " +
					 std::to_string(pc));
	}
	return target;
}

void branch_flip_mark_block_begin(std::vector<bool> &block_begin,
				  int64_t target)
{
	if (target >= 0 &&
	    target < static_cast<int64_t>(block_begin.size())) {
		block_begin[static_cast<size_t>(target)] = true;
	}
}

std::vector<BranchFlipIrSite>
branch_flip_lifted_conditional_sites(const std::vector<uint8_t> &bytes)
{
	if (bytes.empty() || bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error(
			"input bytecode length must be a non-empty multiple of 8");
	}

	const size_t insn_count = bytes.size() / INSN_SIZE;
	const size_t codegen_end = subprog_start_pc(bytes).value_or(insn_count);
	if (codegen_end == 0) {
		return {};
	}

	std::vector<bool> block_begin(codegen_end, false);
	block_begin[0] = true;
	for (size_t pc = 0; pc < codegen_end; pc++) {
		if (pc > 0 && is_llvmbpf_jump_class(bytes[(pc - 1) * INSN_SIZE])) {
			block_begin[pc] = true;
		}

		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if (opcode == BPF_JA) {
			const int64_t target = checked_branch_flip_target(
				pc, read_off(bytes, pc), insn_count, "jump");
			branch_flip_mark_block_begin(block_begin, target);
		} else if (opcode == BPF_JA_IMM) {
			const int64_t target = checked_branch_flip_target(
				pc, read_imm(bytes, pc), insn_count, "jump");
			branch_flip_mark_block_begin(block_begin, target);
		} else if (is_conditional_jump(opcode)) {
			const int64_t target = checked_branch_flip_target(
				pc, read_off(bytes, pc), insn_count,
				"conditional branch");
			branch_flip_mark_block_begin(block_begin, target);
		} else if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
			   src_reg(bytes, pc) == BPF_PSEUDO_CALL) {
			const int64_t target = checked_branch_flip_target(
				pc, read_imm(bytes, pc), insn_count,
				"local call");
			branch_flip_mark_block_begin(block_begin, target);
		}
	}

	std::vector<BranchFlipIrSite> sites;
	size_t current_block_start = 0;
	for (size_t pc = 0; pc < codegen_end; pc++) {
		if (block_begin[pc]) {
			current_block_start = pc;
		}
		if (is_conditional_jump(bytes[pc * INSN_SIZE])) {
			sites.push_back(BranchFlipIrSite{ pc, current_block_start });
		}
	}
	return sites;
}

llvm::BasicBlock *branch_flip_find_block(llvm::Function &function, size_t pc)
{
	const std::string name = "bb_inst_" + std::to_string(pc);
	for (auto &block : function) {
		if (block.getName() == name) {
			return &block;
		}
	}
	return nullptr;
}

uint32_t branch_flip_scale_weight(uint64_t value, uint64_t max_value)
{
	if (value == 0) {
		return 0;
	}
	constexpr uint32_t max_weight =
		std::numeric_limits<uint32_t>::max();
	if (max_value <= max_weight) {
		return static_cast<uint32_t>(value);
	}
	const long double scaled =
		static_cast<long double>(value) *
		static_cast<long double>(max_weight) /
		static_cast<long double>(max_value);
	const auto rounded = static_cast<uint64_t>(std::llround(scaled));
	return static_cast<uint32_t>(
		std::clamp<uint64_t>(rounded, 1, max_weight));
}

std::pair<uint32_t, uint32_t>
branch_flip_weights(const BranchFlipProfileSite &site)
{
	const uint64_t max_count = std::max(site.taken, site.not_taken);
	if (max_count == 0) {
		throw std::runtime_error(
			"branch_flip cannot weight a zero-count profile site");
	}
	return { branch_flip_scale_weight(site.taken, max_count),
		 branch_flip_scale_weight(site.not_taken, max_count) };
}

int64_t annotate_branch_flip_ir(llvm::Module &module,
				const std::vector<uint8_t> &input,
				const BranchFlipProfile &profile,
				PassReportCounts &report_counts)
{
	auto *function = module.getFunction("bpf_main");
	if (!function) {
		throw std::runtime_error("branch_flip could not find bpf_main");
	}

	const auto sites = branch_flip_lifted_conditional_sites(input);
	std::map<size_t, BranchFlipIrSite> sites_by_pc;
	for (const auto &site : sites) {
		sites_by_pc.emplace(site.pc, site);
	}
	for (const auto &site : sites) {
		if (!profile.per_site.contains(site.pc)) {
			throw std::runtime_error(
				"profile missing per_site[" +
				std::to_string(site.pc) +
				"] for lifted conditional branch");
		}
	}
	for (const auto &[pc, _] : profile.per_site) {
		if (!sites_by_pc.contains(pc)) {
			throw std::runtime_error(
				"profile per_site[" + std::to_string(pc) +
				"] does not match a lifted conditional branch");
		}
	}

	llvm::MDBuilder metadata(module.getContext());
	int64_t annotated = 0;
	int64_t skipped = 0;
	constexpr const char *zero_count_reason = "zero_branch_count";
	for (const auto &[pc, profile_site] : profile.per_site) {
		if (profile_site.branch_count == 0) {
			report_counts.skipped_sites.emplace_back(pc, zero_count_reason);
			report_counts.skip_reasons[zero_count_reason]++;
			skipped++;
			continue;
		}
		const auto &site = sites_by_pc.at(pc);
		auto *block = branch_flip_find_block(*function,
						     site.block_start_pc);
		if (!block) {
			throw std::runtime_error(
				"branch_flip could not find lifted block bb_inst_" +
				std::to_string(site.block_start_pc));
		}
		auto *branch =
			llvm::dyn_cast<llvm::CondBrInst>(block->getTerminator());
		if (!branch) {
			throw std::runtime_error(
				"branch_flip lifted block bb_inst_" +
				std::to_string(site.block_start_pc) +
				" is not a conditional branch");
		}

		const auto &[taken_weight, not_taken_weight] =
			branch_flip_weights(profile_site);
		branch->setMetadata(
			llvm::LLVMContext::MD_prof,
			metadata.createBranchWeights(taken_weight,
						     not_taken_weight));
		annotated++;
	}
	report_counts.sites_applied = annotated;
	report_counts.sites_matched =
		static_cast<int64_t>(profile.per_site.size());
	report_counts.sites_skipped = skipped;
	return annotated;
}

std::vector<uint8_t> run_branch_flip_roundtrip(
	const std::vector<uint8_t> &input, const BranchFlipOptions &options,
	PassReportCounts &report_counts)
{
	if (!options.profile) {
		throw std::runtime_error("branch_flip requires --profile");
	}
	BranchFlipProfile profile;
	const auto sites = branch_flip_lifted_conditional_sites(input);
	if (std::filesystem::exists(*options.profile)) {
		profile = read_branch_flip_profile(*options.profile);
	} else if (!sites.empty()) {
		throw std::runtime_error("branch_flip profile missing for " +
					 options.profile->string());
	}
	if (sites.empty()) {
		if (!profile.per_site.empty()) {
			throw std::runtime_error(
				"branch_flip profile has per_site data but input has no lifted conditional branch");
		}
		report_counts.sites_applied = 0;
		report_counts.sites_matched = 0;
		report_counts.sites_skipped = 0;
		return input;
	}
	if (profile.per_site.empty()) {
		throw std::runtime_error(
			"branch_flip profile contains no per_site data for lifted conditional branches");
	}
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		const int64_t sites_applied =
			annotate_branch_flip_ir(module, input, profile,
						report_counts);
		if (sites_applied == 0) {
			return input;
		}
		if (std::getenv("BPFOPT_DUMP_IR")) {
			module.print(llvm::errs(), nullptr);
		}
		return extract_relocated_text(emit_bpf_object(module), input,
					      nullptr);
	});
}

size_t remap_insert_pc(size_t pc, size_t insert_pc)
{
	return pc + (pc >= insert_pc ? 1 : 0);
}

void insert_insn_at(std::vector<uint8_t> &bytes, size_t insert_pc,
		    const std::array<uint8_t, INSN_SIZE> &insn)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (insert_pc > insn_count) {
		throw std::runtime_error("instruction insertion pc out of range");
	}

	const auto old = bytes;
	std::vector<uint8_t> inserted;
	inserted.reserve((insn_count + 1) * INSN_SIZE);
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (pc == insert_pc) {
			inserted.insert(inserted.end(), insn.begin(), insn.end());
		}
		inserted.insert(inserted.end(), old.begin() + pc * INSN_SIZE,
				old.begin() + (pc + 1) * INSN_SIZE);
	}
	if (insert_pc == insn_count) {
		inserted.insert(inserted.end(), insn.begin(), insn.end());
	}

	auto mapped_target = [&](int64_t target) -> size_t {
		if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("branch target out of range");
		}
		return remap_insert_pc(static_cast<size_t>(target), insert_pc);
	};

	for (size_t old_pc = 0; old_pc < insn_count; old_pc++) {
		const size_t new_pc = remap_insert_pc(old_pc, insert_pc);
		const uint8_t opcode = old[old_pc * INSN_SIZE];
		if (opcode == BPF_JA || is_conditional_jump(opcode)) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_off(old, old_pc)));
			const int64_t new_off = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_off < std::numeric_limits<int16_t>::min() ||
			    new_off > std::numeric_limits<int16_t>::max()) {
				throw std::runtime_error(
					"inserted branch offset out of range");
			}
			write_off(inserted, new_pc, static_cast<int16_t>(new_off));
		} else if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
			   src_reg(old, old_pc) == BPF_PSEUDO_CALL) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(old, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"inserted call offset out of range");
			}
			write_imm(inserted, new_pc, static_cast<int32_t>(new_imm));
		} else if (opcode == BPF_LD_IMM64 &&
			   src_reg(old, old_pc) == BPF_PSEUDO_FUNC) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(old, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"inserted function offset out of range");
			}
			write_imm(inserted, new_pc, static_cast<int32_t>(new_imm));
		}
	}

	bytes.swap(inserted);
}

std::vector<uint8_t> compute_reachable_cfg(const std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	std::vector<uint8_t> reachable(insn_count, 0);
	if (insn_count == 0) {
		return reachable;
	}

	std::deque<size_t> worklist;
	reachable[0] = 1;
	worklist.push_back(0);

	auto add_successor = [&](int64_t succ) {
		if (succ < 0 || succ >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("branch target out of range");
		}
		const size_t next = static_cast<size_t>(succ);
		if (!reachable[next]) {
			reachable[next] = 1;
			worklist.push_back(next);
		}
	};

	while (!worklist.empty()) {
		const size_t pc = worklist.front();
		worklist.pop_front();
		const uint8_t opcode = bytes[pc * INSN_SIZE];

		if (opcode == BPF_EXIT) {
			continue;
		}
		if (opcode == BPF_LD_IMM64) {
			if (src_reg(bytes, pc) == BPF_PSEUDO_FUNC) {
				add_successor(static_cast<int64_t>(pc) + 1 +
					      static_cast<int64_t>(read_imm(bytes, pc)));
			}
			if (pc + 2 < insn_count) {
				add_successor(static_cast<int64_t>(pc) + 2);
			}
			continue;
		}
		if (opcode == BPF_JA) {
			add_successor(static_cast<int64_t>(pc) + 1 +
				      static_cast<int64_t>(read_off(bytes, pc)));
			continue;
		}
		if (is_conditional_jump(opcode)) {
			add_successor(static_cast<int64_t>(pc) + 1 +
				      static_cast<int64_t>(read_off(bytes, pc)));
		}
		if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
		    src_reg(bytes, pc) == BPF_PSEUDO_CALL) {
			add_successor(static_cast<int64_t>(pc) + 1 +
				      static_cast<int64_t>(read_imm(bytes, pc)));
		}
		if (pc + 1 < insn_count) {
			add_successor(static_cast<int64_t>(pc) + 1);
		}
	}

	return reachable;
}

int64_t compact_unreachable_insns(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (insn_count == 0) {
		return 0;
	}

	const auto reachable = compute_reachable_cfg(bytes);
	std::vector<uint8_t> keep(insn_count, 0);
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (!reachable[pc]) {
			continue;
		}
		keep[pc] = 1;
		if (is_ldimm64(bytes, pc)) {
			if (pc + 1 >= insn_count) {
				throw std::runtime_error("truncated LD_IMM64");
			}
			keep[pc + 1] = 1;
		}
	}

	size_t kept = 0;
	for (const auto value : keep) {
		kept += value != 0;
	}
	if (kept == insn_count) {
		return 0;
	}

	constexpr size_t INVALID_PC = std::numeric_limits<size_t>::max();
	std::vector<size_t> old_to_new(insn_count, INVALID_PC);
	std::vector<uint8_t> compacted;
	compacted.reserve(kept * INSN_SIZE);
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (!keep[pc]) {
			continue;
		}
		old_to_new[pc] = compacted.size() / INSN_SIZE;
		compacted.insert(compacted.end(), bytes.begin() + pc * INSN_SIZE,
				 bytes.begin() + (pc + 1) * INSN_SIZE);
	}

	auto mapped_target = [&](int64_t target) -> size_t {
		if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("branch target out of range");
		}
		const size_t old_pc = static_cast<size_t>(target);
		if (old_to_new[old_pc] == INVALID_PC) {
			throw std::runtime_error("branch target removed by compaction");
		}
		return old_to_new[old_pc];
	};

	for (size_t old_pc = 0; old_pc < insn_count; old_pc++) {
		if (!keep[old_pc]) {
			continue;
		}
		const size_t new_pc = old_to_new[old_pc];
		const uint8_t opcode = bytes[old_pc * INSN_SIZE];
		if (opcode == BPF_JA || is_conditional_jump(opcode)) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_off(bytes, old_pc)));
			const int64_t new_off = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_off < std::numeric_limits<int16_t>::min() ||
			    new_off > std::numeric_limits<int16_t>::max()) {
				throw std::runtime_error(
					"compacted branch offset out of range");
			}
			write_off(compacted, new_pc, static_cast<int16_t>(new_off));
		} else if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
			   src_reg(bytes, old_pc) == BPF_PSEUDO_CALL) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(bytes, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"compacted call offset out of range");
			}
			write_imm(compacted, new_pc, static_cast<int32_t>(new_imm));
		} else if (opcode == BPF_LD_IMM64 &&
			   src_reg(bytes, old_pc) == BPF_PSEUDO_FUNC) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(bytes, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"compacted function offset out of range");
			}
			write_imm(compacted, new_pc, static_cast<int32_t>(new_imm));
		}
	}

	bytes.swap(compacted);
	return static_cast<int64_t>(insn_count) - static_cast<int64_t>(kept);
}

void transfer_ctx_state(const std::vector<uint8_t> &bytes, size_t pc,
			CtxState &state)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	const uint8_t dst = dst_reg(bytes, pc);
	const uint8_t src = src_reg(bytes, pc);

	if (opcode == BPF_CALL || opcode == BPF_CALLX) {
		for (uint8_t reg = 0; reg <= 5; reg++) {
			state.reg[reg] = 0;
		}
		return;
	}

	if (klass == BPF_ST_CLASS || klass == BPF_STX_CLASS) {
		if (dst == 10) {
			const auto width = bpf_mem_width(opcode);
			if (width) {
				const int16_t off = read_off(bytes, pc);
				clear_overlapping_stack_ctx(state, off, *width);
				const auto slot = stack_ctx_slot_index(off);
				if (opcode == BPF_STXDW && width == 8 && slot &&
				    src < 10 && state.reg[src]) {
					state.stack[*slot] = 1;
				}
			}
		}
		return;
	}

	if (opcode == BPF_MOV64_X) {
		if (dst < 10) {
			state.reg[dst] = src < 10 && state.reg[src];
		}
		return;
	}

	if (opcode == BPF_LDXDW && src == 10) {
		clear_ctx_reg(state, dst);
		const auto slot = stack_ctx_slot_index(read_off(bytes, pc));
		if (dst < 10 && slot && state.stack[*slot]) {
			state.reg[dst] = 1;
		}
		return;
	}

	if (opcode_defines_dst(opcode)) {
		clear_ctx_reg(state, dst);
	}
}

std::vector<CtxState> compute_entry_ctx_states(const std::vector<uint8_t> &bytes,
					       std::vector<uint8_t> &reachable)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	std::vector<CtxState> states(insn_count);
	reachable.assign(insn_count, 0);
	if (insn_count == 0) {
		return states;
	}

	CtxState entry;
	entry.reg[1] = 1;
	std::deque<size_t> worklist;
	states[0] = entry;
	reachable[0] = 1;
	worklist.push_back(0);

	auto merge_successor = [&](size_t succ, const CtxState &state) {
		if (succ >= insn_count) {
			throw std::runtime_error("branch target out of range");
		}
		if (!reachable[succ]) {
			states[succ] = state;
			reachable[succ] = 1;
			worklist.push_back(succ);
			return;
		}
		const CtxState merged = intersect_ctx_state(states[succ], state);
		if (!same_ctx_state(states[succ], merged)) {
			states[succ] = merged;
			worklist.push_back(succ);
		}
	};

	while (!worklist.empty()) {
		const size_t pc = worklist.front();
		worklist.pop_front();
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		CtxState out = states[pc];
		transfer_ctx_state(bytes, pc, out);

		if (opcode == BPF_EXIT) {
			continue;
		}
		if (opcode == BPF_LD_IMM64) {
			if (pc + 2 < insn_count) {
				merge_successor(pc + 2, out);
			}
			continue;
		}
		if (opcode == BPF_JA) {
			const int64_t target = static_cast<int64_t>(pc) + 1 +
					       static_cast<int64_t>(read_off(bytes, pc));
			if (target < 0) {
				throw std::runtime_error("branch target out of range");
			}
			merge_successor(static_cast<size_t>(target), out);
			continue;
		}
		if (is_conditional_jump(opcode)) {
			const int64_t target = static_cast<int64_t>(pc) + 1 +
					       static_cast<int64_t>(read_off(bytes, pc));
			if (target < 0) {
				throw std::runtime_error("branch target out of range");
			}
			merge_successor(static_cast<size_t>(target), out);
		}
		if (pc + 1 < insn_count) {
			merge_successor(pc + 1, out);
		}
	}

	return states;
}

int64_t eliminate_entry_ctx_null_branches(std::vector<uint8_t> &bytes)
{
	int64_t total_changed = 0;
	while (true) {
		std::vector<uint8_t> reachable;
		const auto states = compute_entry_ctx_states(bytes, reachable);
		int64_t changed = 0;
		const size_t insn_count = bytes.size() / INSN_SIZE;
		for (size_t pc = 0; pc < insn_count; pc++) {
			if (!reachable[pc]) {
				continue;
			}
			const uint8_t opcode = bytes[pc * INSN_SIZE];
			if (opcode != BPF_JEQ64_K) {
				continue;
			}
			const uint8_t dst = dst_reg(bytes, pc);
			if (dst >= 10 || !states[pc].reg[dst] ||
			    read_imm(bytes, pc) != 0) {
				continue;
			}
			rewrite_insn_to_mov64_x(bytes, pc, dst, dst);
			changed++;
		}
		if (changed == 0) {
			return total_changed;
		}
		total_changed += changed;
	}
}

int64_t retarget_masked_range_branches(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t changed = 0;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	constexpr size_t MAX_INTERVENING_INSNS = 4;
	for (size_t pc = 1; pc + 3 < insn_count; pc++) {
		if (bytes[pc * INSN_SIZE] != BPF_MOV32_X ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_AND32_K) {
			continue;
		}

		const uint8_t tmp = dst_reg(bytes, pc);
		const uint8_t src = src_reg(bytes, pc);
		if (tmp == src || dst_reg(bytes, pc + 1) != tmp) {
			continue;
		}

		const int32_t mask_imm = read_imm(bytes, pc + 1);
		if (mask_imm < 0) {
			continue;
		}
		const uint64_t mask = static_cast<uint64_t>(mask_imm);

		const uint8_t def_opcode = bytes[(pc - 1) * INSN_SIZE];
		if (dst_reg(bytes, pc - 1) != src ||
		    !load_zero_extends_within_mask(def_opcode, mask)) {
			continue;
		}

		const size_t max_jgt_pc =
			std::min(insn_count - 2, pc + 2 + MAX_INTERVENING_INSNS);
		for (size_t jgt_pc = pc + 2; jgt_pc <= max_jgt_pc; jgt_pc++) {
			bool intervening_ok = true;
			for (size_t mid = pc + 2; mid < jgt_pc; mid++) {
				if (!is_masked_range_intervening_insn(bytes, mid,
								     tmp, src)) {
					intervening_ok = false;
					break;
				}
			}
			if (!intervening_ok) {
				break;
			}
			if (!is_masked_range_branch(bytes[jgt_pc * INSN_SIZE]) ||
			    dst_reg(bytes, jgt_pc) != tmp) {
				continue;
			}

			const int32_t bound_imm = read_imm(bytes, jgt_pc);
			if (bound_imm < 0 ||
			    static_cast<uint64_t>(bound_imm) > mask) {
				continue;
			}

			set_dst_reg(bytes, jgt_pc, src);
			changed++;
			break;
		}
	}
	return changed;
}

int64_t propagate_masked_range_to_fallthrough_source(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t changed = 0;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	constexpr size_t MAX_INTERVENING_INSNS = 4;
	for (size_t pc = 0; pc + 3 < insn_count; pc++) {
		if (bytes[pc * INSN_SIZE] != BPF_MOV32_X ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_AND32_K) {
			continue;
		}

		const uint8_t tmp = dst_reg(bytes, pc);
		const uint8_t src = src_reg(bytes, pc);
		if (tmp == src || dst_reg(bytes, pc + 1) != tmp) {
			continue;
		}

		const int32_t mask_imm = read_imm(bytes, pc + 1);
		if (mask_imm < 0) {
			continue;
		}
		const uint64_t mask = static_cast<uint64_t>(mask_imm);
		if (pc > 0 && dst_reg(bytes, pc - 1) == src &&
		    load_zero_extends_within_mask(bytes[(pc - 1) * INSN_SIZE],
						 mask)) {
			continue;
		}

		const size_t max_branch_pc =
			std::min(insn_count - 2, pc + 2 + MAX_INTERVENING_INSNS);
		for (size_t branch_pc = pc + 2; branch_pc <= max_branch_pc;
		     branch_pc++) {
			bool intervening_ok = true;
			for (size_t mid = pc + 2; mid < branch_pc; mid++) {
				if (!is_masked_range_intervening_insn(bytes, mid,
								     tmp, src)) {
					intervening_ok = false;
					break;
				}
			}
			if (!intervening_ok) {
				break;
			}
			if (!is_masked_range_branch(bytes[branch_pc * INSN_SIZE]) ||
			    dst_reg(bytes, branch_pc) != tmp) {
				continue;
			}

			const int32_t bound_imm = read_imm(bytes, branch_pc);
			if (bound_imm < 0 ||
			    static_cast<uint64_t>(bound_imm) > mask) {
				continue;
			}

			const size_t fallthrough_pc = branch_pc + 1;
			if (!is_same_mask_and(
				    bytes[fallthrough_pc * INSN_SIZE],
				    read_imm(bytes, fallthrough_pc), mask) ||
			    dst_reg(bytes, fallthrough_pc) != src) {
				continue;
			}

			rewrite_insn_to_mov32_x(bytes, fallthrough_pc, src, tmp);
			changed++;
			break;
		}
	}
	return changed;
}

int64_t propagate_masked_range_to_fallthrough_copies(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t changed = 0;
	const size_t insn_count = bytes.size() / INSN_SIZE;
	constexpr size_t MAX_INTERVENING_INSNS = 4;
	for (size_t pc = 0; pc + 4 < insn_count; pc++) {
		if (bytes[pc * INSN_SIZE] != BPF_MOV32_X ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_AND32_K) {
			continue;
		}

		const uint8_t tmp = dst_reg(bytes, pc);
		const uint8_t src = src_reg(bytes, pc);
		if (tmp == src || dst_reg(bytes, pc + 1) != tmp) {
			continue;
		}

		const int32_t mask_imm = read_imm(bytes, pc + 1);
		if (mask_imm < 0) {
			continue;
		}
		const uint64_t mask = static_cast<uint64_t>(mask_imm);

		const size_t max_branch_pc =
			std::min(insn_count - 3, pc + 2 + MAX_INTERVENING_INSNS);
		for (size_t branch_pc = pc + 2; branch_pc <= max_branch_pc;
		     branch_pc++) {
			bool intervening_ok = true;
			for (size_t mid = pc + 2; mid < branch_pc; mid++) {
				if (!is_masked_range_intervening_insn(bytes, mid,
								     tmp, src)) {
					intervening_ok = false;
					break;
				}
			}
			if (!intervening_ok) {
				break;
			}
			if (!is_masked_range_branch(bytes[branch_pc * INSN_SIZE]) ||
			    dst_reg(bytes, branch_pc) != tmp) {
				continue;
			}

			const int32_t bound_imm = read_imm(bytes, branch_pc);
			if (bound_imm < 0 ||
			    static_cast<uint64_t>(bound_imm) > mask) {
				continue;
			}

			const size_t max_copy_pc =
				std::min(insn_count - 2,
					 branch_pc + 1 + MAX_INTERVENING_INSNS);
			for (size_t copy_pc = branch_pc + 1; copy_pc <= max_copy_pc;
			     copy_pc++) {
				bool copy_intervening_ok = true;
				for (size_t mid = branch_pc + 1; mid < copy_pc;
				     mid++) {
					if (!is_masked_range_intervening_insn(bytes,
									     mid,
									     tmp,
									     src)) {
						copy_intervening_ok = false;
						break;
					}
				}
				if (!copy_intervening_ok) {
					break;
				}

				const uint8_t copy_opcode =
					bytes[copy_pc * INSN_SIZE];
				if (copy_opcode != BPF_MOV32_X &&
				    copy_opcode != BPF_MOV64_X) {
					continue;
				}
				const uint8_t copy_dst = dst_reg(bytes, copy_pc);
				if (copy_dst == tmp || copy_dst == src ||
				    src_reg(bytes, copy_pc) != src) {
					continue;
				}
				const size_t and_pc = copy_pc + 1;
				if (!is_same_mask_and(
					    bytes[and_pc * INSN_SIZE],
					    read_imm(bytes, and_pc), mask) ||
				    dst_reg(bytes, and_pc) != copy_dst) {
					continue;
				}

				rewrite_insn_to_mov32_x(bytes, copy_pc, copy_dst,
							tmp);
				changed++;
				break;
			}
			break;
		}
	}
	return changed;
}

std::optional<size_t> jump_target_pc(const std::vector<uint8_t> &bytes,
				     size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode != BPF_JA && !is_conditional_jump(opcode)) {
		return std::nullopt;
	}
	const int64_t target = static_cast<int64_t>(pc) + 1 +
			       static_cast<int64_t>(read_off(bytes, pc));
	if (target < 0 || target >= static_cast<int64_t>(bytes.size() / INSN_SIZE)) {
		throw std::runtime_error("branch target out of range");
	}
	return static_cast<size_t>(target);
}

bool same_branch_target(const std::vector<uint8_t> &bytes, size_t lhs,
			size_t rhs)
{
	const auto lhs_target = jump_target_pc(bytes, lhs);
	const auto rhs_target = jump_target_pc(bytes, rhs);
	return lhs_target && rhs_target && *lhs_target == *rhs_target;
}

uint64_t read_ldimm64_u64(const std::vector<uint8_t> &bytes, size_t pc)
{
	if (pc + 1 >= bytes.size() / INSN_SIZE ||
	    bytes[pc * INSN_SIZE] != BPF_LD_IMM64) {
		throw std::runtime_error("expected LD_IMM64");
	}
	const uint64_t low =
		static_cast<uint32_t>(read_imm(bytes, pc));
	const uint64_t high =
		static_cast<uint64_t>(static_cast<uint32_t>(
			read_imm(bytes, pc + 1)))
		<< 32;
	return high | low;
}

uint64_t low_bitmask_for_max(uint64_t max_value)
{
	if (max_value == 0) {
		return 0;
	}
	if (max_value == std::numeric_limits<uint64_t>::max()) {
		return max_value;
	}
	uint64_t mask = 1;
	while (mask < max_value) {
		mask = (mask << 1) | 1;
	}
	return mask;
}

struct Low16LoadSource {
	size_t len = 0;
	uint8_t dst = 0;
	uint8_t base = 0;
	int16_t off = 0;
};

std::optional<Low16LoadSource>
low16_load_source_at(const std::vector<uint8_t> &bytes, size_t pc,
		     const std::map<KinsnCallKey, std::string> &kinsn_names)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc >= insn_count) {
		return std::nullopt;
	}

	if (bytes[pc * INSN_SIZE] == BPF_LDXH) {
		return Low16LoadSource{ 1, dst_reg(bytes, pc),
					src_reg(bytes, pc), read_off(bytes, pc) };
	}

	if (pc + 1 >= insn_count || !is_kinsn_sidecar(bytes, pc) ||
	    !is_kinsn_call(bytes, pc + 1)) {
		return std::nullopt;
	}
	const KinsnCallKey key{ read_off(bytes, pc + 1),
				read_imm(bytes, pc + 1) };
	const auto name = kinsn_names.find(key);
	if (name == kinsn_names.end() || name->second != "bpf_x86_movzwl") {
		return std::nullopt;
	}
	const uint64_t payload =
		decode_kinsn_payload(read_kinsn_sidecar_payload(bytes, pc));
	constexpr uint8_t x86_form_mem = 4;
	if ((payload & 0xf) != x86_form_mem || payload >> 28) {
		return std::nullopt;
	}
	return Low16LoadSource{
		2,
		static_cast<uint8_t>((payload >> 4) & 0xf),
		static_cast<uint8_t>((payload >> 8) & 0xf),
		static_cast<int16_t>((payload >> 12) & 0xffff),
	};
}

int64_t preserve_low16_bound_after_composite_u32_check(
	std::vector<uint8_t> &bytes, const KinsnTargetMap &kinsn_targets)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const auto kinsn_names = kinsn_target_name_by_call_key(kinsn_targets);
	int64_t changed = 0;
	size_t pc = 0;
	while (true) {
		const size_t insn_count = bytes.size() / INSN_SIZE;
		if (pc >= insn_count) {
			break;
		}
		const auto low_load = low16_load_source_at(bytes, pc, kinsn_names);
		if (!low_load) {
			pc++;
			continue;
		}

		const size_t high3_pc = pc + low_load->len;
		const size_t high3_shift_pc = high3_pc + 1;
		const size_t high2_pc = high3_pc + 2;
		const size_t high2_shift_pc = high3_pc + 3;
		const size_t merge_high_pc = high3_pc + 4;
		const size_t merge_low_pc = high3_pc + 5;
		const size_t branch_pc = high3_pc + 6;
		if (branch_pc >= insn_count ||
		    bytes[high3_pc * INSN_SIZE] != BPF_LDXB ||
		    bytes[high3_shift_pc * INSN_SIZE] != BPF_LSH64_K ||
		    bytes[high2_pc * INSN_SIZE] != BPF_LDXB ||
		    bytes[high2_shift_pc * INSN_SIZE] != BPF_LSH64_K ||
		    bytes[merge_high_pc * INSN_SIZE] != BPF_OR64_X ||
		    bytes[merge_low_pc * INSN_SIZE] != BPF_OR64_X ||
		    bytes[branch_pc * INSN_SIZE] != BPF_JGT64_K) {
			pc++;
			continue;
		}

		const uint8_t low = low_load->dst;
		const uint8_t base = low_load->base;
		const int low_off = low_load->off;
		const uint8_t high3 = dst_reg(bytes, high3_pc);
		const uint8_t high2 = dst_reg(bytes, high2_pc);
		const uint8_t full = dst_reg(bytes, merge_high_pc);
		const int32_t bound = read_imm(bytes, branch_pc);
		if (bound < 0 || bound > 0xffff ||
		    src_reg(bytes, high3_pc) != base ||
		    read_off(bytes, high3_pc) != low_off + 3 ||
		    dst_reg(bytes, high3_shift_pc) != high3 ||
		    read_imm(bytes, high3_shift_pc) != 24 ||
		    src_reg(bytes, high2_pc) != base ||
		    read_off(bytes, high2_pc) != low_off + 2 ||
		    dst_reg(bytes, high2_shift_pc) != high2 ||
		    read_imm(bytes, high2_shift_pc) != 16 ||
		    full != high2 ||
		    src_reg(bytes, merge_high_pc) != high3 ||
		    dst_reg(bytes, merge_low_pc) != full ||
		    src_reg(bytes, merge_low_pc) != low ||
		    dst_reg(bytes, branch_pc) != full) {
			pc++;
			continue;
		}

		const size_t insert_pc = branch_pc + 1;
		if (insert_pc < bytes.size() / INSN_SIZE &&
		    bytes[insert_pc * INSN_SIZE] == BPF_JGT64_K &&
		    dst_reg(bytes, insert_pc) == low &&
		    read_imm(bytes, insert_pc) == bound &&
		    same_branch_target(bytes, branch_pc, insert_pc)) {
			pc = insert_pc + 1;
			continue;
		}

		const auto old_target = jump_target_pc(bytes, branch_pc);
		if (!old_target) {
			throw std::runtime_error("composite range branch is not a jump");
		}
		const size_t new_target =
			remap_insert_pc(*old_target, insert_pc);
		const int64_t new_off = static_cast<int64_t>(new_target) -
					static_cast<int64_t>(insert_pc) - 1;
		if (new_off < std::numeric_limits<int16_t>::min() ||
		    new_off > std::numeric_limits<int16_t>::max()) {
			throw std::runtime_error(
				"inserted low16 bound offset out of range");
		}

		const auto check =
			make_bpf_insn(BPF_JGT64_K, low, 0,
				      static_cast<int16_t>(new_off), bound);
		insert_insn_at(bytes, insert_pc, check);
		changed++;
		pc = insert_pc + 1;
	}
	return changed;
}

int64_t preserve_shifted_offset_bound_after_guard(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t changed = 0;
	size_t pc = 0;
	while (true) {
		const size_t insn_count = bytes.size() / INSN_SIZE;
		if (pc + 6 >= insn_count) {
			break;
		}
		if (bytes[pc * INSN_SIZE] != BPF_MOV64_X ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_RSH64_K ||
		    bytes[(pc + 2) * INSN_SIZE] != BPF_LD_IMM64 ||
		    bytes[(pc + 4) * INSN_SIZE] != BPF_AND64_X ||
		    !is_kinsn_sidecar(bytes, pc + 5) ||
		    !is_kinsn_call(bytes, pc + 6)) {
			pc++;
			continue;
		}

		const uint8_t tmp = dst_reg(bytes, pc);
		const uint8_t guarded = src_reg(bytes, pc);
		const uint8_t mask_reg = dst_reg(bytes, pc + 2);
		const int32_t shift = read_imm(bytes, pc + 1);
		if (shift < 0 || shift >= 64 ||
		    dst_reg(bytes, pc + 1) != tmp ||
		    dst_reg(bytes, pc + 4) != tmp ||
		    src_reg(bytes, pc + 4) != mask_reg) {
			pc++;
			continue;
		}

		const uint64_t original_mask = read_ldimm64_u64(bytes, pc + 2);

		std::optional<int32_t> guard_bound;
		bool inserted = false;
		const size_t scan_limit = std::min(insn_count, pc + 40);
		for (size_t scan_pc = pc + 7; scan_pc < scan_limit; scan_pc++) {
			const uint8_t opcode = bytes[scan_pc * INSN_SIZE];
			if (opcode == BPF_XOR64_K && dst_reg(bytes, scan_pc) == tmp) {
				if (!guard_bound || read_imm(bytes, scan_pc) < 0 ||
				    scan_pc + 1 >= insn_count ||
				    bytes[(scan_pc + 1) * INSN_SIZE] != BPF_MOV64_X ||
				    src_reg(bytes, scan_pc + 1) != tmp) {
					break;
				}
				const uint64_t source_max =
					static_cast<uint64_t>(*guard_bound) >> shift;
				const uint64_t tight_mask =
					original_mask & low_bitmask_for_max(source_max);
				if (tight_mask > static_cast<uint64_t>(
							 std::numeric_limits<int32_t>::max())) {
					break;
				}

				const size_t insert_pc = scan_pc;
				if (insert_pc > 0 &&
				    bytes[(insert_pc - 1) * INSN_SIZE] ==
					    BPF_AND64_K &&
				    dst_reg(bytes, insert_pc - 1) == tmp &&
				    read_imm(bytes, insert_pc - 1) ==
					    static_cast<int32_t>(tight_mask)) {
					pc = insert_pc + 1;
					inserted = true;
					break;
				}

				const auto mask =
					make_bpf_insn(BPF_AND64_K, tmp, 0, 0,
						      static_cast<int32_t>(tight_mask));
				insert_insn_at(bytes, insert_pc, mask);
				changed++;
				pc = insert_pc + 2;
				inserted = true;
				break;
			}

			if (opcode == BPF_JA || opcode == BPF_CALL ||
			    opcode == BPF_CALLX || opcode == BPF_EXIT) {
				break;
			}
			if (opcode == BPF_JGT64_K &&
			    dst_reg(bytes, scan_pc) == guarded &&
			    read_imm(bytes, scan_pc) >= 0) {
				const auto target = jump_target_pc(bytes, scan_pc);
				if (target && *target > scan_pc + 1) {
					guard_bound = read_imm(bytes, scan_pc);
					continue;
				}
			}
			if (is_conditional_jump(opcode)) {
				break;
			}
			if (opcode_defines_dst(opcode)) {
				const uint8_t dst = dst_reg(bytes, scan_pc);
				if (dst == tmp || dst == guarded) {
					break;
				}
			}
		}
		if (inserted) {
			continue;
		}

		pc++;
	}
	return changed;
}

#include "bpf_kinsn_bytecode.hpp"

std::optional<uint8_t>
rolw_imm8_dst_at(const std::vector<uint8_t> &bytes, size_t pc,
		 const std::map<KinsnCallKey, std::string> &kinsn_names)
{
	if (pc + 1 >= bytes.size() / INSN_SIZE || !is_kinsn_sidecar(bytes, pc) ||
	    !is_kinsn_call(bytes, pc + 1)) {
		return std::nullopt;
	}
	const KinsnCallKey key{ read_off(bytes, pc + 1),
				read_imm(bytes, pc + 1) };
	const auto name = kinsn_names.find(key);
	if (name == kinsn_names.end() || name->second != "bpf_x86_rolw") {
		return std::nullopt;
	}
	const uint64_t payload =
		decode_kinsn_payload(read_kinsn_sidecar_payload(bytes, pc));
	if ((payload & 0xf) != X86_FORM_IMM || ((payload >> 8) & 0xff) != 8 ||
	    payload >> 16) {
		return std::nullopt;
	}
	return static_cast<uint8_t>((payload >> 4) & 0xf);
}

int64_t apply_movbe16_after_low16_load(std::vector<uint8_t> &bytes,
				       const KinsnTargetMap &kinsn_targets)
{
	if (!target_has_kinsn(kinsn_targets, "bpf_x86_movbe16")) {
		return 0;
	}
	const auto kinsn_names = kinsn_target_name_by_call_key(kinsn_targets);
	int64_t changed = 0;
	size_t pc = 0;
	while (true) {
		const size_t insn_count = bytes.size() / INSN_SIZE;
		if (pc >= insn_count) {
			break;
		}
		const auto low_load = low16_load_source_at(bytes, pc, kinsn_names);
		if (!low_load) {
			pc++;
			continue;
		}
		const size_t rolw_pc = pc + low_load->len;
		const auto rolw_dst = rolw_imm8_dst_at(bytes, rolw_pc, kinsn_names);
		const size_t old_len = low_load->len + 2;
		if (!rolw_dst || *rolw_dst != low_load->dst ||
		    !range_is_replaceable(bytes, pc, old_len)) {
			pc++;
			continue;
		}

		std::vector<uint8_t> replacement;
		const auto zero_dst = make_bpf_insn(BPF_MOV64_K, low_load->dst, 0,
						    0, 0);
		replacement.insert(replacement.end(), zero_dst.begin(),
				   zero_dst.end());
		append_kinsn_pair(replacement, kinsn_targets, "bpf_x86_movbe16",
				  pack_x86_mem_payload(low_load->dst,
						       low_load->base,
						       low_load->off));
		replace_insn_range(bytes, pc, old_len, replacement);
		changed++;
		pc += replacement.size() / INSN_SIZE;
	}
	return changed;
}

void apply_generic_llvm_roundtrip_repairs(std::vector<uint8_t> &bytes)
{
	eliminate_entry_ctx_null_branches(bytes);
	propagate_masked_range_to_fallthrough_source(bytes);
	propagate_masked_range_to_fallthrough_copies(bytes);
	retarget_masked_range_branches(bytes);
	compact_unreachable_insns(bytes);
	remap_out_of_range_stack_spills(bytes, false);
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
		  const PassReportCounts *report_counts = nullptr,
		  const std::vector<std::string> &diagnostics = {},
		  const KinsnTargetMap *kinsn_targets = nullptr,
		  const KinsnPassOptions *kinsn_options = nullptr)
{
	if (!cli.report) {
		return;
	}
	const bool changed = input != output;
	const bool is_map_inline = cli.pass && *cli.pass == "map_inline";
	const int64_t reported_sites =
		report_counts && report_counts->sites_applied
			? *report_counts->sites_applied
			: (is_map_inline ? static_cast<int64_t>(inlined.size()) :
					   (changed ? 1 : 0));
	const int64_t reported_matched =
		report_counts && report_counts->sites_matched
			? *report_counts->sites_matched
			: reported_sites;
	const int64_t reported_skipped =
		report_counts && report_counts->sites_skipped
			? *report_counts->sites_skipped
			: 0;
	if (reported_sites < 0 || reported_matched < 0 ||
	    reported_skipped < 0) {
		throw std::runtime_error("negative pass report site count");
	}
	if (reported_sites + reported_skipped != reported_matched) {
		throw std::runtime_error(
			"pass report site counts disagree: applied=" +
			std::to_string(reported_sites) +
			" skipped=" + std::to_string(reported_skipped) +
			" matched=" + std::to_string(reported_matched));
	}
	llvm::json::Array inlined_entries;
	llvm::json::Array diagnostic_entries;
	llvm::json::Object skip_reasons;
	llvm::json::Array skipped_sites;
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
	if (report_counts) {
		for (const auto &[reason, count] : report_counts->skip_reasons) {
			skip_reasons[reason] = count;
		}
		for (const auto &[pc, reason] : report_counts->skipped_sites) {
			skipped_sites.emplace_back(llvm::json::Object{
				{ "pc", static_cast<int64_t>(pc) },
				{ "reason", reason },
			});
		}
	}
	llvm::json::Object report{
		{ "pass", *cli.pass },
		{ "sites_applied", reported_sites },
		{ "sites_matched", reported_matched },
		{ "sites_skipped", reported_skipped },
		{ "skip_reasons", std::move(skip_reasons) },
		{ "skipped_sites", std::move(skipped_sites) },
		{ "diagnostics", std::move(diagnostic_entries) },
		{ "insn_count_before", input.size() / INSN_SIZE },
		{ "insn_count_after", output.size() / INSN_SIZE },
		{ "insn_delta",
		  static_cast<int64_t>(output.size() / INSN_SIZE) -
			  static_cast<int64_t>(input.size() / INSN_SIZE) },
		{ "inlined_map_entries", std::move(inlined_entries) },
	};
	if (kinsn_targets) {
		if (kinsn_options) {
			report["kinsn_policy"] = kinsn_policy_json(cli, *kinsn_options);
		}
		auto by_name = counter_delta(
			count_kinsn_calls_by_name(output, *kinsn_targets),
			count_kinsn_calls_by_name(input, *kinsn_targets));
		int64_t counted_sites = 0;
		for (const auto &[_, count] : by_name) {
			counted_sites += count;
		}
		if (counted_sites != reported_sites) {
			throw std::runtime_error(
				"kinsn report count mismatch: new output calls=" +
				std::to_string(counted_sites) +
				" sites_applied=" +
				std::to_string(reported_sites));
		}
		auto payload_shapes = counter_delta(
			count_kinsn_payload_shapes(output, *kinsn_targets),
			count_kinsn_payload_shapes(input, *kinsn_targets));
		report["kinsn_calls_by_name"] = counter_json(by_name);
		report["kinsn_calls_by_family"] =
			counter_json(kinsn_call_family_counts(by_name));
		report["kinsn_payload_shapes"] = counter_json(payload_shapes);
	}
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
	const bool branch_flip_pass = *cli.pass == "branch_flip";
	KinsnTargetMap kinsn_targets;
	KinsnTargetArch kinsn_target_arch = KinsnTargetArch::Unknown;
	KinsnPassOptions kinsn_options;
	BranchFlipOptions branch_flip_options;
	if (kinsn_pass) {
		if (!cli.target) {
			throw std::runtime_error("--pass " + *cli.pass +
						 " requires --target");
		}
		kinsn_target_arch = read_kinsn_target_arch(*cli.target);
		kinsn_targets = read_kinsn_targets(*cli.target);
		kinsn_options = parse_kinsn_pass_args(*cli.pass, cli.pass_args);
		apply_target_bytecode_policy_defaults(*cli.pass, kinsn_targets,
						      kinsn_target_arch,
						      kinsn_options);
		kinsn_options.effective_llvm_args =
			configure_llvm_kinsn_select(*cli.pass,
						    kinsn_options.llvm_args,
						    kinsn_targets,
						    kinsn_target_arch);
	} else if (branch_flip_pass) {
		branch_flip_options = parse_branch_flip_pass_args(cli.pass_args);
	} else if (*cli.pass != "map_inline" && !cli.pass_args.empty()) {
		throw std::runtime_error("--pass " + *cli.pass +
					 " does not accept pass-local args");
	}
	const auto input = read_all(cli.input);
	const int64_t input_kinsn_calls =
		kinsn_pass ? count_kinsn_calls(input) : 0;
	std::vector<InlineRecord> inlined;
	std::vector<uint8_t> output;
	std::optional<int64_t> sites_applied;
	PassReportCounts pass_report_counts;
	std::vector<std::string> diagnostics;
	if (branch_flip_pass) {
		output = run_branch_flip_roundtrip(input, branch_flip_options,
						   pass_report_counts);
	} else if (*cli.pass == "map_inline") {
		output = run_map_inline_roundtrip(input, cli, inlined);
	} else {
		if (kinsn_pass && count_kinsn_calls(input) > 0) {
			output = input;
		} else {
			output = run_llvm_roundtrip(
				input, kinsn_pass ? &kinsn_targets : nullptr);
		}
		if (kinsn_pass) {
			if (input_kinsn_calls == 0) {
				eliminate_entry_ctx_null_branches(output);
				propagate_masked_range_to_fallthrough_source(output);
				propagate_masked_range_to_fallthrough_copies(output);
				retarget_masked_range_branches(output);
				preserve_low16_bound_after_composite_u32_check(output,
									       kinsn_targets);
				preserve_shifted_offset_bound_after_guard(output);
				apply_movbe16_after_low16_load(output, kinsn_targets);
				compact_unreachable_insns(output);
				remap_out_of_range_stack_spills(output, true);
			}
			apply_bytecode_kinsn_recovery(
				output, *cli.pass, kinsn_options.bytecode_policy,
				kinsn_targets, kinsn_target_arch, diagnostics);
			const int64_t output_kinsn_calls = count_kinsn_calls(output);
			if (output_kinsn_calls < input_kinsn_calls) {
				throw std::runtime_error(
					"kinsn pass removed existing kinsn calls");
			}
			sites_applied = output_kinsn_calls - input_kinsn_calls;
			pass_report_counts.sites_applied = sites_applied;
			if (output_kinsn_calls == 0) {
				output = input;
			}
		} else {
			apply_generic_llvm_roundtrip_repairs(output);
		}
	}
	write_all(cli.output, output);
	const PassReportCounts *report_counts =
		(branch_flip_pass || sites_applied) ? &pass_report_counts :
						      nullptr;
	write_report(cli, input, output, inlined, report_counts, diagnostics,
		     kinsn_pass ? &kinsn_targets : nullptr,
		     kinsn_pass ? &kinsn_options : nullptr);
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
