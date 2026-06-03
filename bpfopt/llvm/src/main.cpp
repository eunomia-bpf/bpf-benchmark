#include <algorithm>
#include <array>
#include <cctype>
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
constexpr uint8_t BPF_LDXW = 0x61;
constexpr uint8_t BPF_LDXH = 0x69;
constexpr uint8_t BPF_LDXB = 0x71;
constexpr uint8_t BPF_LDXDW = 0x79;
constexpr uint8_t BPF_STXDW = 0x7b;
constexpr uint8_t BPF_CALL = 0x85;
constexpr uint8_t BPF_CALLX = BPF_CALL | 0x08;
constexpr uint8_t BPF_EXIT = 0x95;
constexpr uint8_t BPF_MOV32_X = 0xbc;
constexpr uint8_t BPF_MOV32_K = 0xb4;
constexpr uint8_t BPF_MOV64_X = 0xbf;
constexpr uint8_t BPF_MOV64_K = 0xb7;
constexpr uint8_t BPF_ADD64_X = 0x0f;
constexpr uint8_t BPF_ADD64_K = 0x07;
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

// BPF helper function ids (uapi/linux/bpf.h __BPF_FUNC_MAPPER order). This pure
// LLVM tool does not link libbpf, so the relevant ids are spelled out here like
// the opcode constants above.
constexpr int32_t BPF_FUNC_map_lookup_elem = 1;
constexpr int32_t BPF_FUNC_map_update_elem = 2;
constexpr int32_t BPF_FUNC_map_delete_elem = 3;
constexpr int32_t BPF_FUNC_probe_read = 4;
constexpr int32_t BPF_FUNC_get_current_comm = 16;
constexpr int32_t BPF_FUNC_skb_load_bytes = 26;
constexpr int32_t BPF_FUNC_probe_read_str = 45;
constexpr int32_t BPF_FUNC_skb_load_bytes_relative = 68;
constexpr int32_t BPF_FUNC_map_push_elem = 87;
constexpr int32_t BPF_FUNC_map_pop_elem = 88;
constexpr int32_t BPF_FUNC_probe_read_user = 112;
constexpr int32_t BPF_FUNC_probe_read_kernel = 113;
constexpr int32_t BPF_FUNC_probe_read_user_str = 114;
constexpr int32_t BPF_FUNC_probe_read_kernel_str = 115;

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
				if (pass != "rotate" && pass != "kinsn") {
					throw std::runtime_error(
						"rotate amortization threshold is only valid for rotate/kinsn");
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
	bool has_kinsn_mode = false;
	for (const auto &arg : llvm_args) {
		if (arg.starts_with("-bpf-kinsn-mode=")) {
			has_kinsn_mode = true;
			break;
		}
	}

	std::vector<std::string> args{ "bpfopt", "-bpf-enable-kinsn-select" };
	if (!has_kinsn_mode) {
		args.push_back("-bpf-kinsn-mode=all=force");
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

void reserve_stack_range(std::vector<std::pair<int, int>> &occupied, int off,
			 int width)
{
	occupied.emplace_back(off, off + width);
}

bool stack_range_is_free(const std::vector<std::pair<int, int>> &occupied,
			 int off, int width)
{
	const int end = off + width;
	for (const auto &[used_start, used_end] : occupied) {
		if (off < used_end && used_start < end) {
			return false;
		}
	}
	return true;
}

void reserve_x86_kinsn_stack_contract(std::vector<std::pair<int, int>> &occupied)
{
	// The current x86 kinsn emitters may use this verifier-visible scratch
	// range after the kernel expands a pseudo call. Keep compiler spill slots
	// out of it until the module stack contract is removed.
	reserve_stack_range(occupied, -512, 184);
}

struct StackAccess {
	size_t pc = 0;
	int off = 0;
	int width = 0;
	bool write = false;
};

enum class KnownKind {
	Unknown,
	Frame,
	ScalarConst,
};

struct KnownValue {
	KnownKind kind = KnownKind::Unknown;
	int64_t value = 0;
};

KnownValue unknown_value()
{
	return KnownValue{};
}

KnownValue frame_value(int64_t off)
{
	return KnownValue{ KnownKind::Frame, off };
}

KnownValue scalar_const_value(int64_t value)
{
	return KnownValue{ KnownKind::ScalarConst, value };
}

bool same_known_value(const KnownValue &lhs, const KnownValue &rhs)
{
	return lhs.kind == rhs.kind && lhs.value == rhs.value;
}

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

std::set<std::pair<int16_t, int32_t>>
kinsn_call_ids_for_names(const KinsnTargetMap *targets,
			 std::initializer_list<std::string_view> names)
{
	std::set<std::pair<int16_t, int32_t>> ids;
	if (!targets) {
		return ids;
	}
	for (std::string_view name : names) {
		const auto it = targets->find(std::string(name));
		if (it == targets->end()) {
			continue;
		}
		ids.emplace(it->second.call_offset, it->second.btf_func_id);
	}
	return ids;
}

bool kinsn_call_matches(const std::vector<uint8_t> &bytes, size_t pc,
			const std::set<std::pair<int16_t, int32_t>> &ids)
{
	if (!is_kinsn_call(bytes, pc)) {
		return false;
	}
	return ids.contains({ read_off(bytes, pc), read_imm(bytes, pc) });
}

struct X86LeaPayload {
	uint8_t dst = 0;
	uint8_t base = 0;
	uint8_t index = 0;
	uint8_t scale_log2 = 0;
	bool has_base = false;
	bool has_index = false;
	int32_t disp = 0;
};

std::optional<X86LeaPayload>
decode_x86_lea_sidecar(const std::vector<uint8_t> &bytes, size_t pc)
{
	if (!is_kinsn_sidecar(bytes, pc) || dst_reg(bytes, pc) != 1) {
		return std::nullopt;
	}
	const uint16_t payload16 = static_cast<uint16_t>(read_off(bytes, pc));
	X86LeaPayload out;
	out.dst = payload16 & 0xf;
	out.base = (payload16 >> 4) & 0xf;
	out.index = (payload16 >> 8) & 0xf;
	out.scale_log2 = (payload16 >> 12) & 0x3;
	out.has_index = (payload16 >> 14) & 0x1;
	out.has_base = (payload16 >> 15) & 0x1;
	out.disp = read_imm(bytes, pc);
	return out;
}

std::optional<std::pair<uint8_t, uint8_t>>
helper_stack_write_args(int32_t helper)
{
	switch (helper) {
	case BPF_FUNC_probe_read:
	case BPF_FUNC_get_current_comm:
	case BPF_FUNC_probe_read_str:
	case BPF_FUNC_probe_read_user:
	case BPF_FUNC_probe_read_kernel:
	case BPF_FUNC_probe_read_user_str:
	case BPF_FUNC_probe_read_kernel_str:
		return std::pair<uint8_t, uint8_t>{ 1, 2 };
	case BPF_FUNC_skb_load_bytes:
	case BPF_FUNC_skb_load_bytes_relative:
		return std::pair<uint8_t, uint8_t>{ 3, 4 };
	default:
		return std::nullopt;
	}
}

void clear_stack_value_range(std::map<int16_t, KnownValue> &stack, int off,
			     int width)
{
	for (auto it = stack.begin(); it != stack.end();) {
		if (byte_ranges_overlap(off, width, it->first, 8)) {
			it = stack.erase(it);
		} else {
			++it;
		}
	}
}

void record_known_equivalent_slots(
	std::map<int16_t, std::vector<std::set<int16_t>>> &equiv_by_slot,
	std::set<int16_t> &unknown_store_slots, int16_t old_off,
	const KnownValue &value, const std::map<int16_t, KnownValue> &stack)
{
	if (value.kind != KnownKind::Frame) {
		unknown_store_slots.insert(old_off);
		return;
	}
	std::set<int16_t> slots;
	for (const auto &[off, slot_value] : stack) {
		if (off % 8 != 0 || !valid_bpf_stack_range(off, 8)) {
			continue;
		}
		if (same_known_value(value, slot_value)) {
			slots.insert(off);
		}
	}
	equiv_by_slot[old_off].push_back(std::move(slots));
}

void analyze_stack_values_and_accesses(
	const std::vector<uint8_t> &bytes,
	const std::map<int16_t, int> &invalid_slots,
	const KinsnTargetMap *kinsn_targets,
	std::vector<StackAccess> &accesses,
	std::map<int16_t, std::vector<std::set<int16_t>>> &equiv_by_slot,
	std::set<int16_t> &unknown_store_slots)
{
	const auto leaq_ids =
		kinsn_call_ids_for_names(kinsn_targets, { "bpf_x86_leaq" });
	std::array<KnownValue, 11> regs{};
	std::map<int16_t, KnownValue> stack;
	regs[10] = frame_value(0);
	const size_t insn_count = bytes.size() / INSN_SIZE;

	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if (opcode == BPF_LD_IMM64) {
			regs[dst_reg(bytes, pc)] = unknown_value();
			pc++;
			continue;
		}

		if (kinsn_call_matches(bytes, pc, leaq_ids) && pc > 0) {
			if (const auto lea = decode_x86_lea_sidecar(bytes, pc - 1)) {
				KnownValue value = unknown_value();
				if (lea->has_base && !lea->has_index &&
				    lea->base < regs.size() &&
				    regs[lea->base].kind == KnownKind::Frame) {
					value = frame_value(regs[lea->base].value +
							    lea->disp);
				} else if (!lea->has_base && !lea->has_index) {
					value = scalar_const_value(lea->disp);
				}
				if (lea->dst < regs.size()) {
					regs[lea->dst] = value;
				}
			}
			continue;
		}

		if (const auto ref = fp_stack_mem_ref(bytes, pc)) {
			const bool valid = valid_bpf_stack_range(ref->off, ref->width);
			if (ref->write) {
				clear_stack_value_range(stack, ref->off, ref->width);
			}
			if (!valid) {
				if (ref->write && ref->width == 8 &&
				    (opcode & BPF_CLASS_MASK) == BPF_STX_CLASS &&
				    invalid_slots.contains(ref->off)) {
					record_known_equivalent_slots(
						equiv_by_slot, unknown_store_slots,
						ref->off, regs[src_reg(bytes, pc)],
						stack);
				}
			} else if (ref->write) {
				if ((opcode & BPF_CLASS_MASK) == BPF_STX_CLASS &&
				    ref->width == 8 && ref->off % 8 == 0 &&
				    regs[src_reg(bytes, pc)].kind ==
					    KnownKind::Frame) {
					stack[ref->off] = regs[src_reg(bytes, pc)];
				}
			} else if (ref->width == 8) {
				const auto it = stack.find(ref->off);
				regs[dst_reg(bytes, pc)] =
					it == stack.end() ? unknown_value() :
							    it->second;
			} else {
				regs[dst_reg(bytes, pc)] = unknown_value();
			}
		}

		switch (opcode) {
		case BPF_MOV64_X:
			regs[dst_reg(bytes, pc)] = regs[src_reg(bytes, pc)];
			break;
		case BPF_MOV32_X:
			regs[dst_reg(bytes, pc)] = unknown_value();
			break;
		case BPF_MOV64_K:
		case BPF_MOV32_K:
			if (!is_kinsn_sidecar(bytes, pc)) {
				regs[dst_reg(bytes, pc)] =
					scalar_const_value(read_imm(bytes, pc));
			}
			break;
		case BPF_ADD64_K:
			if (regs[dst_reg(bytes, pc)].kind == KnownKind::Frame ||
			    regs[dst_reg(bytes, pc)].kind ==
				    KnownKind::ScalarConst) {
				regs[dst_reg(bytes, pc)].value +=
					read_imm(bytes, pc);
			}
			break;
		case BPF_ADD64_X: {
			const uint8_t dst = dst_reg(bytes, pc);
			const uint8_t src = src_reg(bytes, pc);
			if (regs[dst].kind == KnownKind::Frame &&
			    regs[src].kind == KnownKind::ScalarConst) {
				regs[dst].value += regs[src].value;
			} else if (regs[dst].kind == KnownKind::ScalarConst &&
				   regs[src].kind == KnownKind::Frame) {
				regs[dst] = frame_value(regs[src].value +
							regs[dst].value);
			} else {
				regs[dst] = unknown_value();
			}
			break;
		}
		case BPF_CALL:
		case BPF_CALLX: {
			if (src_reg(bytes, pc) == BPF_PSEUDO_KINSN_CALL ||
			    src_reg(bytes, pc) == BPF_PSEUDO_CALL) {
				break;
			}
			if (const auto args = helper_stack_write_args(
				    read_imm(bytes, pc))) {
				const auto [dst_arg, len_arg] = *args;
				if (regs[dst_arg].kind == KnownKind::Frame) {
					int width = 512;
					if (regs[len_arg].kind ==
						    KnownKind::ScalarConst &&
					    regs[len_arg].value > 0 &&
					    regs[len_arg].value <= 512) {
						width = static_cast<int>(
							regs[len_arg].value);
					}
					const int off =
						static_cast<int>(regs[dst_arg].value);
					if (off < 0) {
						width = std::min(width, -off);
						accesses.push_back(StackAccess{
							pc, off, width, true });
						clear_stack_value_range(stack, off,
									width);
					}
				}
			}
			for (uint8_t reg = 0; reg <= 5; reg++) {
				regs[reg] = unknown_value();
			}
			break;
		}
		default:
			if (opcode_defines_dst(opcode)) {
				regs[dst_reg(bytes, pc)] = unknown_value();
			}
			break;
		}
	}
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

std::set<int16_t> intersect_equivalent_slot_sets(
	const std::vector<std::set<int16_t>> &sets)
{
	std::set<int16_t> out;
	if (sets.empty()) {
		return out;
	}
	out = sets.front();
	for (size_t i = 1; i < sets.size(); i++) {
		std::set<int16_t> next;
		std::set_intersection(out.begin(), out.end(), sets[i].begin(),
				      sets[i].end(),
				      std::inserter(next, next.begin()));
		out = std::move(next);
	}
	return out;
}

int64_t remap_out_of_range_stack_spills(std::vector<uint8_t> &bytes,
					bool reserve_x86_kinsn_stack,
					const KinsnTargetMap *kinsn_targets)
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
		if (ref->width != 8 || ref->off % 8 != 0 || ref->off >= -512) {
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

	std::map<int16_t, std::vector<std::set<int16_t>>> equiv_by_slot;
	std::set<int16_t> unknown_store_slots;
	analyze_stack_values_and_accesses(bytes, invalid_slots, kinsn_targets,
					  accesses, equiv_by_slot,
					  unknown_store_slots);

	if (reserve_x86_kinsn_stack) {
		std::vector<std::pair<int, int>> occupied;
		reserve_x86_kinsn_stack_contract(occupied);
		for (const auto &[start, end] : occupied) {
			accesses.push_back(StackAccess{
				0, start, end - start, true });
		}
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
		if (!unknown_store_slots.contains(old_off)) {
			const auto equiv_it = equiv_by_slot.find(old_off);
			if (equiv_it != equiv_by_slot.end()) {
				for (int16_t candidate :
				     intersect_equivalent_slot_sets(
					     equiv_it->second)) {
					if (!valid_bpf_stack_range(candidate, width)) {
						continue;
					}
					if (candidate_has_access_in_range(
						    remapped_accesses, candidate,
						    width, first_pc, last_pc,
						    true)) {
						continue;
					}
					replacement = candidate;
					break;
				}
			}
		}
		if (!replacement) {
			for (int candidate = -512; candidate <= -8; candidate += 8) {
				if (!valid_bpf_stack_range(candidate, width)) {
					continue;
				}
				if (reserve_x86_kinsn_stack &&
				    byte_ranges_overlap(candidate, width, -512,
							184)) {
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
	       opcode != BPF_JA && opcode != BPF_CALL &&
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

int64_t preserve_low16_bound_after_composite_u32_check(std::vector<uint8_t> &bytes)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	int64_t changed = 0;
	size_t pc = 0;
	while (true) {
		const size_t insn_count = bytes.size() / INSN_SIZE;
		if (pc + 7 >= insn_count) {
			break;
		}
		if (bytes[pc * INSN_SIZE] != BPF_LDXH ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_LDXB ||
		    bytes[(pc + 2) * INSN_SIZE] != BPF_LSH64_K ||
		    bytes[(pc + 3) * INSN_SIZE] != BPF_LDXB ||
		    bytes[(pc + 4) * INSN_SIZE] != BPF_LSH64_K ||
		    bytes[(pc + 5) * INSN_SIZE] != BPF_OR64_X ||
		    bytes[(pc + 6) * INSN_SIZE] != BPF_OR64_X ||
		    bytes[(pc + 7) * INSN_SIZE] != BPF_JGT64_K) {
			pc++;
			continue;
		}

		const uint8_t low = dst_reg(bytes, pc);
		const uint8_t base = src_reg(bytes, pc);
		const int16_t low_off = read_off(bytes, pc);
		const uint8_t high3 = dst_reg(bytes, pc + 1);
		const uint8_t high2 = dst_reg(bytes, pc + 3);
		const uint8_t full = dst_reg(bytes, pc + 5);
		const int32_t bound = read_imm(bytes, pc + 7);
		if (bound < 0 || bound > 0xffff ||
		    src_reg(bytes, pc + 1) != base ||
		    read_off(bytes, pc + 1) != low_off + 3 ||
		    dst_reg(bytes, pc + 2) != high3 ||
		    read_imm(bytes, pc + 2) != 24 ||
		    src_reg(bytes, pc + 3) != base ||
		    read_off(bytes, pc + 3) != low_off + 2 ||
		    dst_reg(bytes, pc + 4) != high2 ||
		    read_imm(bytes, pc + 4) != 16 ||
		    full != high2 || src_reg(bytes, pc + 5) != high3 ||
		    dst_reg(bytes, pc + 6) != full ||
		    src_reg(bytes, pc + 6) != low ||
		    dst_reg(bytes, pc + 7) != full) {
			pc++;
			continue;
		}

		const size_t branch_pc = pc + 7;
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
			eliminate_entry_ctx_null_branches(output);
			propagate_masked_range_to_fallthrough_source(output);
			propagate_masked_range_to_fallthrough_copies(output);
			retarget_masked_range_branches(output);
			preserve_low16_bound_after_composite_u32_check(output);
			preserve_shifted_offset_bound_after_guard(output);
			compact_unreachable_insns(output);
			remap_out_of_range_stack_spills(output, true,
							&kinsn_targets);
			sites_applied = count_kinsn_calls(output);
			if (*sites_applied == 0) {
				output = input;
			}
		} else {
			remap_out_of_range_stack_spills(output, false, nullptr);
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
