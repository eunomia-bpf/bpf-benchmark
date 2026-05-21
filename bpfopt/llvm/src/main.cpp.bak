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
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include "llvmbpf.hpp"
#include "llvm_jit_context.hpp"

#include "llvm/Analysis/CGSCCPassManager.h"
#include "llvm/Config/llvm-config.h"
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
constexpr uint8_t BPF_LDX_MEM_DW = 0x79;
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

uint8_t src_reg(const std::vector<uint8_t> &insns, size_t pc)
{
	return (insns[pc * INSN_SIZE + 1] >> 4) & 0x0f;
}

uint8_t dst_reg(const std::vector<uint8_t> &insns, size_t pc)
{
	return insns[pc * INSN_SIZE + 1] & 0x0f;
}

void set_dst_reg(std::vector<uint8_t> &insns, size_t pc, uint8_t dst)
{
	auto &regs = insns[pc * INSN_SIZE + 1];
	regs = static_cast<uint8_t>((regs & 0xf0) | (dst & 0x0f));
}

void set_src_reg(std::vector<uint8_t> &insns, size_t pc, uint8_t src)
{
	auto &regs = insns[pc * INSN_SIZE + 1];
	regs = static_cast<uint8_t>((regs & 0x0f) | ((src & 0x0f) << 4));
}

int32_t read_imm(const std::vector<uint8_t> &insns, size_t pc)
{
	int32_t imm = 0;
	std::memcpy(&imm, &insns[pc * INSN_SIZE + 4], sizeof(imm));
	return imm;
}

int16_t read_off(const std::vector<uint8_t> &insns, size_t pc)
{
	int16_t off = 0;
	std::memcpy(&off, &insns[pc * INSN_SIZE + 2], sizeof(off));
	return off;
}

void write_imm(std::vector<uint8_t> &insns, size_t pc, int32_t imm)
{
	std::memcpy(&insns[pc * INSN_SIZE + 4], &imm, sizeof(imm));
}

void write_off(std::vector<uint8_t> &insns, size_t pc, int16_t off)
{
	std::memcpy(&insns[pc * INSN_SIZE + 2], &off, sizeof(off));
}

bool is_ldimm64(const std::vector<uint8_t> &insns, size_t pc)
{
	return insns[pc * INSN_SIZE] == BPF_LD_IMM64;
}

bool is_map_pseudo(uint8_t src)
{
	return src == BPF_PSEUDO_MAP_FD || src == BPF_PSEUDO_MAP_VALUE ||
	       src == BPF_PSEUDO_MAP_IDX ||
	       src == BPF_PSEUDO_MAP_IDX_VALUE;
}

bool is_jmp32_k(uint8_t code)
{
	return (code & 0x07) == 0x06 && code != 0x06;
}

bool is_signed_jmp32_k(uint8_t code)
{
	return code == BPF_JMP32_JSGT_K || code == BPF_JMP32_JSGE_K ||
	       code == BPF_JMP32_JSLT_K || code == BPF_JMP32_JSLE_K;
}

constexpr uint16_t reg_bit(uint8_t reg)
{
	return static_cast<uint16_t>(1u << reg);
}

bool is_alu_class(uint8_t code)
{
	return (code & 0x07) == 0x04 || (code & 0x07) == 0x07;
}

bool is_jmp_class(uint8_t code)
{
	return (code & 0x07) == 0x05 || (code & 0x07) == 0x06;
}

bool is_relative_jump(uint8_t code)
{
	return is_jmp_class(code) && code != BPF_CALL && code != BPF_CALLX &&
	       code != BPF_EXIT;
}

bool is_pure_alu_def(uint8_t code)
{
	return is_alu_class(code);
}

bool insn_defines_reg(const std::vector<uint8_t> &text, size_t pc, uint8_t reg)
{
	const uint8_t code = text[pc * INSN_SIZE];
	const uint8_t dst = dst_reg(text, pc);
	if (code == BPF_CALL || code == BPF_CALLX) {
		return reg <= 5;
	}
	if (code == BPF_LD_IMM64 || is_alu_class(code) ||
	    (code & 0x07) == 0x01) {
		return dst == reg;
	}
	return false;
}

uint16_t alu_uses(uint8_t code, uint8_t dst, uint8_t src)
{
	const uint8_t op = code & 0xf0;
	uint16_t uses = 0;
	if (op != 0xb0) {
		uses |= reg_bit(dst);
	}
	if ((code & 0x08) != 0) {
		uses |= reg_bit(src);
	}
	return uses;
}

void write_noop(std::vector<uint8_t> &insns, size_t pc)
{
	std::fill(insns.begin() + pc * INSN_SIZE,
		  insns.begin() + (pc + 1) * INSN_SIZE, 0);
	insns[pc * INSN_SIZE] = BPF_JA;
}

std::vector<uint32_t> parse_u32_csv(const std::string &csv)
{
	std::vector<uint32_t> values;
	if (csv.empty()) {
		return values;
	}
	std::stringstream ss(csv);
	std::string item;
	while (std::getline(ss, item, ',')) {
		size_t consumed = 0;
		unsigned long value = std::stoul(item, &consumed, 10);
		if (item.empty() || consumed != item.size() ||
		    value > std::numeric_limits<uint32_t>::max()) {
			throw std::runtime_error("invalid --map-ids item: " +
						 item);
		}
		values.push_back(static_cast<uint32_t>(value));
	}
	return values;
}

uint32_t parse_hex_u32(std::string_view text)
{
	if (text.size() != 8) {
		throw std::runtime_error("expected 8 hex digits");
	}
	uint32_t value = 0;
	for (char c : text) {
		value <<= 4;
		if (c >= '0' && c <= '9') {
			value |= static_cast<uint32_t>(c - '0');
		} else if (c >= 'a' && c <= 'f') {
			value |= static_cast<uint32_t>(10 + c - 'a');
		} else if (c >= 'A' && c <= 'F') {
			value |= static_cast<uint32_t>(10 + c - 'A');
		} else {
			throw std::runtime_error("invalid hex digit");
		}
	}
	return value;
}

size_t relocation_pc(uint64_t offset, size_t insn_count)
{
	uint64_t pc = 0;
	if (offset % INSN_SIZE == 0) {
		pc = offset / INSN_SIZE;
	} else if (offset >= 4 && (offset - 4) % INSN_SIZE == 0) {
		pc = (offset - 4) / INSN_SIZE;
	} else {
		throw std::runtime_error("unaligned relocation offset " +
					 std::to_string(offset));
	}
	if (pc >= insn_count) {
		throw std::runtime_error("relocation pc out of range");
	}
	return static_cast<size_t>(pc);
}

std::optional<uint32_t> helper_id_from_symbol(std::string_view name)
{
	constexpr std::string_view prefix = "_bpf_helper_ext_";
	if (!name.starts_with(prefix)) {
		return std::nullopt;
	}
	auto digits = name.substr(prefix.size());
	if (digits.empty() ||
	    !std::all_of(digits.begin(), digits.end(), [](char c) {
		    return std::isdigit(static_cast<unsigned char>(c)) != 0;
	    })) {
		throw std::runtime_error("malformed helper symbol: " +
					 std::string(name));
	}
	return static_cast<uint32_t>(std::stoul(std::string(digits)));
}

bool patch_map_symbol(std::vector<uint8_t> &text, size_t pc,
		      std::string_view name)
{
	struct Pattern {
		std::string_view prefix;
		uint8_t src;
		bool has_offset;
	};
	const Pattern patterns[] = {
		{ "__llvmbpf_pseudo_map_value_fd_", BPF_PSEUDO_MAP_VALUE,
		  true },
		{ "__llvmbpf_pseudo_map_idx_value_",
		  BPF_PSEUDO_MAP_IDX_VALUE, true },
		{ "__llvmbpf_pseudo_map_fd_", BPF_PSEUDO_MAP_FD, false },
		{ "__llvmbpf_pseudo_map_idx_", BPF_PSEUDO_MAP_IDX, false },
	};

	for (const auto &pattern : patterns) {
		if (!name.starts_with(pattern.prefix)) {
			continue;
		}
		auto rest = name.substr(pattern.prefix.size());
		if (rest.size() < 8 || pc + 1 >= text.size() / INSN_SIZE) {
			throw std::runtime_error("malformed map pseudo relocation");
		}
		const uint32_t imm = parse_hex_u32(rest.substr(0, 8));
		uint32_t offset = 0;
		if (pattern.has_offset) {
			constexpr std::string_view sep = "_off_";
			rest.remove_prefix(8);
			if (!rest.starts_with(sep)) {
				throw std::runtime_error(
					"malformed map-value pseudo symbol");
			}
			rest.remove_prefix(sep.size());
			offset = parse_hex_u32(rest);
		}
		text[pc * INSN_SIZE] = BPF_LD_IMM64;
		set_src_reg(text, pc, pattern.src);
		write_imm(text, pc, static_cast<int32_t>(imm));
		std::fill(text.begin() + (pc + 1) * INSN_SIZE,
			  text.begin() + (pc + 2) * INSN_SIZE, 0);
		write_imm(text, pc + 1, static_cast<int32_t>(offset));
		return true;
	}
	return false;
}

std::optional<size_t> subprog_start_pc(const std::vector<uint8_t> &input)
{
	std::optional<size_t> start;
	const size_t insn_count = input.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = input[pc * INSN_SIZE];
		std::optional<int64_t> target;
		if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
		    src_reg(input, pc) == BPF_PSEUDO_CALL) {
			target = static_cast<int64_t>(pc) + 1 +
				 static_cast<int64_t>(read_imm(input, pc));
		} else if (opcode == BPF_LD_IMM64 &&
			   src_reg(input, pc) == BPF_PSEUDO_FUNC) {
			target = static_cast<int64_t>(pc) + 1 +
				 static_cast<int64_t>(read_imm(input, pc));
			pc++;
		}
		if (!target) {
			continue;
		}
		if (*target < 0 || *target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("local subprogram target out of range");
		}
		const auto target_pc = static_cast<size_t>(*target);
		start = start ? std::min(*start, target_pc) : target_pc;
	}
	return start;
}

size_t remap_original_pc(size_t original_pc, std::optional<size_t> subprog_start,
			 size_t generated_insns)
{
	if (!subprog_start) {
		return original_pc;
	}
	if (original_pc < *subprog_start) {
		throw std::runtime_error(
			"pseudo-call target points before subprogram tail");
	}
	return generated_insns + (original_pc - *subprog_start);
}

bool patch_call_symbol(std::vector<uint8_t> &text, size_t pc,
		       std::string_view name,
		       std::optional<size_t> subprog_start,
		       size_t generated_insns)
{
	constexpr std::string_view prefix = "__llvmbpf_pseudo_call_pc_";
	if (!name.starts_with(prefix)) {
		return false;
	}
	const size_t target = remap_original_pc(parse_hex_u32(name.substr(prefix.size())),
						subprog_start,
						generated_insns);
	const int64_t imm = static_cast<int64_t>(target) -
			    static_cast<int64_t>(pc) - 1;
	if (imm < std::numeric_limits<int32_t>::min() ||
	    imm > std::numeric_limits<int32_t>::max() ||
	    text[pc * INSN_SIZE] != BPF_CALL) {
		throw std::runtime_error("invalid pseudo-call relocation");
	}
	set_src_reg(text, pc, BPF_PSEUDO_CALL);
	write_imm(text, pc, static_cast<int32_t>(imm));
	return true;
}

bool patch_func_symbol(std::vector<uint8_t> &text, size_t pc,
		       std::string_view name,
		       std::optional<size_t> subprog_start,
		       size_t generated_insns)
{
	constexpr std::string_view prefix = "__llvmbpf_pseudo_func_pc_";
	if (!name.starts_with(prefix)) {
		return false;
	}
	const size_t target = remap_original_pc(parse_hex_u32(name.substr(prefix.size())),
						subprog_start,
						generated_insns);
	const int64_t imm = static_cast<int64_t>(target) -
			    static_cast<int64_t>(pc) - 1;
	if (imm < std::numeric_limits<int32_t>::min() ||
	    imm > std::numeric_limits<int32_t>::max() ||
	    pc + 1 >= text.size() / INSN_SIZE ||
	    text[pc * INSN_SIZE] != BPF_LD_IMM64) {
		throw std::runtime_error("invalid pseudo-func relocation");
	}
	set_src_reg(text, pc, BPF_PSEUDO_FUNC);
	write_imm(text, pc, static_cast<int32_t>(imm));
	std::fill(text.begin() + (pc + 1) * INSN_SIZE,
		  text.begin() + (pc + 2) * INSN_SIZE, 0);
	return true;
}

void apply_one_relocation(llvm::object::ObjectFile &object,
			  const llvm::object::RelocationRef &reloc,
			  std::vector<uint8_t> &text,
			  std::optional<size_t> subprog_start,
			  size_t generated_insns)
{
	const auto symbol = reloc.getSymbol();
	if (symbol == object.symbol_end()) {
		throw std::runtime_error("text relocation without symbol");
	}
	const std::string name = expected_or_throw(symbol->getName()).str();
	const size_t pc =
		relocation_pc(reloc.getOffset(), text.size() / INSN_SIZE);
	if (const auto helper = helper_id_from_symbol(name)) {
		if (text[pc * INSN_SIZE] != BPF_CALL) {
			throw std::runtime_error(
				"helper relocation does not target a call");
		}
		set_src_reg(text, pc, 0);
		write_imm(text, pc, static_cast<int32_t>(*helper));
		} else if (!patch_map_symbol(text, pc, name) &&
			   !patch_call_symbol(text, pc, name, subprog_start,
					      generated_insns) &&
			   !patch_func_symbol(text, pc, name, subprog_start,
					      generated_insns)) {
		throw std::runtime_error("unsupported relocation symbol " +
					 name + " at offset " +
					 std::to_string(reloc.getOffset()) +
					 " pc " + std::to_string(pc));
	}
}

void apply_text_relocations(llvm::object::ObjectFile &object,
			    std::vector<uint8_t> &text,
			    std::optional<size_t> subprog_start,
			    size_t generated_insns)
{
	for (const auto &section : object.sections()) {
		auto relocated = section.getRelocatedSection();
		if (!relocated) {
			llvm::consumeError(relocated.takeError());
			continue;
		}
		if (*relocated == object.section_end() ||
		    expected_or_throw((*relocated)->getName()) != ".text") {
			continue;
		}
		for (const auto &reloc : section.relocations()) {
			apply_one_relocation(object, reloc, text,
					     subprog_start, generated_insns);
		}
	}
	for (size_t pc = 0; pc < text.size() / INSN_SIZE; pc++) {
		if (text[pc * INSN_SIZE] == BPF_CALL &&
		    src_reg(text, pc) == BPF_PSEUDO_CALL &&
		    read_imm(text, pc) == -1) {
			throw std::runtime_error(
				"unresolved BPF text relocation remains");
		}
	}
}

std::vector<uint8_t> extract_text_section(const std::vector<uint8_t> &object_bytes)
{
	auto buffer = llvm::MemoryBuffer::getMemBuffer(
		llvm::StringRef(reinterpret_cast<const char *>(object_bytes.data()),
				object_bytes.size()),
		"bpfopt-llvm.o", false);
	auto object = expected_or_throw(
		llvm::object::ObjectFile::createObjectFile(
			buffer->getMemBufferRef()));

	std::optional<std::vector<uint8_t>> empty_text;
	for (const auto &section : object->sections()) {
		if (expected_or_throw(section.getName()) != ".text") {
			continue;
		}
		const auto contents = expected_or_throw(section.getContents());
		std::vector<uint8_t> text(contents.bytes_begin(),
					  contents.bytes_end());
		if (text.size() % INSN_SIZE != 0) {
			throw std::runtime_error(".text size is not a multiple of 8");
		}
		if (!text.empty()) {
			return text;
		}
		empty_text = std::move(text);
	}
	if (empty_text) {
		return *empty_text;
	}
	throw std::runtime_error("LLVM BPF object has no .text section");
}

void repair_verifier_range_copies(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = 1; pc + 3 < insn_count; pc++) {
		if (text[pc * INSN_SIZE] != BPF_ALU32_MOV_X) {
			continue;
		}
		const uint8_t checked = dst_reg(text, pc);
		const uint8_t source = src_reg(text, pc);
		if (checked == source ||
		    text[(pc - 1) * INSN_SIZE] != BPF_LDX_MEM_H ||
		    dst_reg(text, pc - 1) != source ||
		    text[(pc + 1) * INSN_SIZE] != BPF_ALU32_AND_K ||
		    dst_reg(text, pc + 1) != checked ||
		    src_reg(text, pc + 1) != 0 ||
		    read_imm(text, pc + 1) != 0xffff ||
		    !is_jmp32_k(text[(pc + 2) * INSN_SIZE]) ||
		    dst_reg(text, pc + 2) != checked ||
		    src_reg(text, pc + 2) != 0 ||
		    read_imm(text, pc + 2) < 0 ||
		    read_imm(text, pc + 2) > 0xffff) {
			continue;
		}
		set_dst_reg(text, pc + 2, source);
	}

	for (size_t pc = 0; pc + 3 < insn_count; pc++) {
		if (text[pc * INSN_SIZE] != BPF_ALU64_MOV_X ||
		    text[(pc + 1) * INSN_SIZE] != BPF_ALU64_ADD_K ||
		    text[(pc + 3) * INSN_SIZE] != BPF_JLT_K) {
			continue;
		}
		const uint8_t adjusted = dst_reg(text, pc);
		const uint8_t source = src_reg(text, pc);
		const int32_t add = read_imm(text, pc + 1);
		const int32_t limit = read_imm(text, pc + 3);
		if (adjusted == source || dst_reg(text, pc + 1) != adjusted ||
		    dst_reg(text, pc + 3) != source || src_reg(text, pc + 3) != 0 ||
		    add < 0 ||
		    limit > std::numeric_limits<int32_t>::max() - add) {
			continue;
		}
		if (text[(pc + 2) * INSN_SIZE] == BPF_ALU64_MOV_X &&
		    src_reg(text, pc + 2) == adjusted) {
			set_dst_reg(text, pc + 3, adjusted);
			write_imm(text, pc + 3, limit + add);
		}
	}
}

void repair_zero_extended_signed_jumps(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	std::vector<bool> is_branch_target(insn_count, false);
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if (!is_jmp_class(code) || code == BPF_CALL ||
		    code == BPF_CALLX || code == BPF_EXIT) {
			continue;
		}
		const int64_t target = static_cast<int64_t>(pc) + 1 +
				       static_cast<int64_t>(read_off(text, pc));
		if (target >= 0 && target < static_cast<int64_t>(insn_count)) {
			is_branch_target[static_cast<size_t>(target)] = true;
		}
	}

	for (size_t pc = 0; pc < insn_count; pc++) {
		if (!is_signed_jmp32_k(text[pc * INSN_SIZE]) ||
		    src_reg(text, pc) != 0 || read_imm(text, pc) != 0 ||
		    is_branch_target[pc]) {
			continue;
		}
		const uint8_t checked = dst_reg(text, pc);
		const size_t search_begin = pc > 16 ? pc - 16 : 0;
		for (size_t q = pc; q-- > search_begin;) {
			if (q < 2 || text[q * INSN_SIZE] != BPF_ALU64_RSH_K ||
			    dst_reg(text, q) != checked ||
			    read_imm(text, q) != 32 ||
			    text[(q - 1) * INSN_SIZE] != BPF_ALU64_LSH_K ||
			    dst_reg(text, q - 1) != checked ||
			    read_imm(text, q - 1) != 32 ||
			    text[(q - 2) * INSN_SIZE] != BPF_ALU64_MOV_X ||
			    dst_reg(text, q - 2) != checked) {
				continue;
			}
			const uint8_t source = src_reg(text, q - 2);
			if (source == checked) {
				break;
			}
			bool valid = true;
			for (size_t k = q + 1; k < pc; k++) {
				if (insn_defines_reg(text, k, checked) ||
				    insn_defines_reg(text, k, source)) {
					valid = false;
					break;
				}
				if (text[k * INSN_SIZE] == BPF_LD_IMM64) {
					k++;
				}
			}
			if (valid) {
				set_dst_reg(text, pc, source);
			}
			break;
		}
	}
}

std::vector<bool> branch_targets(const std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	std::vector<bool> targets(insn_count, false);
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if (!is_relative_jump(code)) {
			if (code == BPF_LD_IMM64) {
				pc++;
			}
			continue;
		}
		const int64_t target = static_cast<int64_t>(pc) + 1 +
				       static_cast<int64_t>(read_off(text, pc));
		if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("relative jump target out of range");
		}
		targets[static_cast<size_t>(target)] = true;
	}
	return targets;
}

void insert_insns_adjusting_jumps(std::vector<uint8_t> &text, size_t insert_pc,
				  const std::vector<uint8_t> &insns)
{
	if (insns.empty() || insns.size() % INSN_SIZE != 0 ||
	    text.size() % INSN_SIZE != 0) {
		throw std::runtime_error("invalid BPF instruction insertion");
	}
	const size_t insn_count = text.size() / INSN_SIZE;
	const size_t added_insns = insns.size() / INSN_SIZE;
	if (insert_pc > insn_count) {
		throw std::runtime_error("BPF insertion pc out of range");
	}
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if ((code == BPF_CALL || code == BPF_CALLX) &&
		    src_reg(text, pc) == BPF_PSEUDO_CALL) {
			const int64_t old_pc = static_cast<int64_t>(pc);
			const int64_t old_target =
				old_pc + 1 + static_cast<int64_t>(read_imm(text, pc));
			if (old_target < 0 ||
			    old_target >= static_cast<int64_t>(insn_count)) {
				throw std::runtime_error("pseudo-call target out of range");
			}
			const int64_t new_pc =
				old_pc +
				(pc >= insert_pc ? static_cast<int64_t>(added_insns) :
						  0);
			const int64_t new_target =
				old_target +
				(old_target >= static_cast<int64_t>(insert_pc) ?
					 static_cast<int64_t>(added_insns) :
					 0);
			const int64_t new_imm = new_target - new_pc - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"pseudo-call offset out of range after insertion");
			}
			write_imm(text, pc, static_cast<int32_t>(new_imm));
			continue;
		}
		if (code == BPF_LD_IMM64) {
			if (src_reg(text, pc) == BPF_PSEUDO_FUNC) {
				const int64_t old_pc = static_cast<int64_t>(pc);
				const int64_t old_target =
					old_pc + 1 +
					static_cast<int64_t>(read_imm(text, pc));
				if (old_target < 0 ||
				    old_target >= static_cast<int64_t>(insn_count)) {
					throw std::runtime_error(
						"pseudo-func target out of range");
				}
				const int64_t new_pc =
					old_pc +
					(pc >= insert_pc ?
						 static_cast<int64_t>(added_insns) :
						 0);
				const int64_t new_target =
					old_target +
					(old_target >= static_cast<int64_t>(insert_pc) ?
						 static_cast<int64_t>(added_insns) :
						 0);
				const int64_t new_imm = new_target - new_pc - 1;
				if (new_imm < std::numeric_limits<int32_t>::min() ||
				    new_imm > std::numeric_limits<int32_t>::max()) {
					throw std::runtime_error(
						"pseudo-func offset out of range after insertion");
				}
				write_imm(text, pc, static_cast<int32_t>(new_imm));
			}
			pc++;
			continue;
		}
		if (!is_relative_jump(code)) {
			continue;
		}
		const int64_t old_pc = static_cast<int64_t>(pc);
		const int64_t old_target =
			old_pc + 1 + static_cast<int64_t>(read_off(text, pc));
		if (old_target < 0 ||
		    old_target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("relative jump target out of range");
		}
		const int64_t new_pc =
			old_pc +
			(pc >= insert_pc ? static_cast<int64_t>(added_insns) :
					  0);
		const int64_t new_target =
			old_target +
			(old_target >= static_cast<int64_t>(insert_pc) ?
				 static_cast<int64_t>(added_insns) :
				 0);
		const int64_t new_off = new_target - new_pc - 1;
		if (new_off < std::numeric_limits<int16_t>::min() ||
		    new_off > std::numeric_limits<int16_t>::max()) {
			throw std::runtime_error(
				"relative jump offset out of range after insertion");
		}
		write_off(text, pc, static_cast<int16_t>(new_off));
	}
	text.insert(text.begin() + insert_pc * INSN_SIZE, insns.begin(),
		    insns.end());
}

void insert_insn_adjusting_jumps(std::vector<uint8_t> &text, size_t insert_pc,
				 const std::vector<uint8_t> &insn)
{
	if (insn.size() != INSN_SIZE) {
		throw std::runtime_error("invalid BPF instruction insertion");
	}
	insert_insns_adjusting_jumps(text, insert_pc, insn);
}

void delete_insns_adjusting_jumps(std::vector<uint8_t> &text, size_t begin_pc,
				  size_t end_pc)
{
	if (begin_pc >= end_pc || text.size() % INSN_SIZE != 0) {
		throw std::runtime_error("invalid BPF instruction deletion");
	}
	const size_t insn_count = text.size() / INSN_SIZE;
	if (end_pc > insn_count) {
		throw std::runtime_error("BPF deletion pc out of range");
	}
	const size_t removed_insns = end_pc - begin_pc;
	const auto remap_pc = [&](int64_t old_pc) -> int64_t {
		if (old_pc < static_cast<int64_t>(begin_pc)) {
			return old_pc;
		}
		if (old_pc >= static_cast<int64_t>(end_pc)) {
			return old_pc - static_cast<int64_t>(removed_insns);
		}
		return static_cast<int64_t>(begin_pc);
	};
	const auto target_is_deleted = [&](int64_t target) {
		return target >= static_cast<int64_t>(begin_pc) &&
		       target < static_cast<int64_t>(end_pc);
	};

	for (size_t pc = 0; pc < insn_count; pc++) {
		if (pc >= begin_pc && pc < end_pc) {
			if (text[pc * INSN_SIZE] == BPF_LD_IMM64) {
				pc++;
			}
			continue;
		}
		const uint8_t code = text[pc * INSN_SIZE];
		if ((code == BPF_CALL || code == BPF_CALLX) &&
		    src_reg(text, pc) == BPF_PSEUDO_CALL) {
			const int64_t old_pc = static_cast<int64_t>(pc);
			const int64_t old_target =
				old_pc + 1 + static_cast<int64_t>(read_imm(text, pc));
			if (old_target < 0 ||
			    old_target >= static_cast<int64_t>(insn_count)) {
				throw std::runtime_error("pseudo-call target out of range");
			}
			if (target_is_deleted(old_target)) {
				throw std::runtime_error(
					"pseudo-call targets deleted instruction");
			}
			const int64_t new_pc = remap_pc(old_pc);
			const int64_t new_target = remap_pc(old_target);
			const int64_t new_imm = new_target - new_pc - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"pseudo-call offset out of range after deletion");
			}
			write_imm(text, pc, static_cast<int32_t>(new_imm));
			continue;
		}
		if (code == BPF_LD_IMM64) {
			if (src_reg(text, pc) == BPF_PSEUDO_FUNC) {
				const int64_t old_pc = static_cast<int64_t>(pc);
				const int64_t old_target =
					old_pc + 1 +
					static_cast<int64_t>(read_imm(text, pc));
				if (old_target < 0 ||
				    old_target >= static_cast<int64_t>(insn_count)) {
					throw std::runtime_error(
						"pseudo-func target out of range");
				}
				if (target_is_deleted(old_target)) {
					throw std::runtime_error(
						"pseudo-func targets deleted instruction");
				}
				const int64_t new_pc = remap_pc(old_pc);
				const int64_t new_target = remap_pc(old_target);
				const int64_t new_imm = new_target - new_pc - 1;
				if (new_imm < std::numeric_limits<int32_t>::min() ||
				    new_imm > std::numeric_limits<int32_t>::max()) {
					throw std::runtime_error(
						"pseudo-func offset out of range after deletion");
				}
				write_imm(text, pc, static_cast<int32_t>(new_imm));
			}
			pc++;
			continue;
		}
		if (!is_relative_jump(code)) {
			continue;
		}
		const int64_t old_pc = static_cast<int64_t>(pc);
		const int64_t old_target =
			old_pc + 1 + static_cast<int64_t>(read_off(text, pc));
		if (old_target < 0 ||
		    old_target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("relative jump target out of range");
		}
		if (target_is_deleted(old_target)) {
			throw std::runtime_error(
				"relative jump targets deleted instruction");
		}
		const int64_t new_pc = remap_pc(old_pc);
		const int64_t new_target = remap_pc(old_target);
		const int64_t new_off = new_target - new_pc - 1;
		if (new_off < std::numeric_limits<int16_t>::min() ||
		    new_off > std::numeric_limits<int16_t>::max()) {
			throw std::runtime_error(
				"relative jump offset out of range after deletion");
		}
		write_off(text, pc, static_cast<int16_t>(new_off));
	}

	text.erase(text.begin() + begin_pc * INSN_SIZE,
		   text.begin() + end_pc * INSN_SIZE);
}

std::vector<std::vector<size_t>>
relative_jump_predecessors(const std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	std::vector<std::vector<size_t>> preds(insn_count);
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if (!is_relative_jump(code)) {
			if (code == BPF_LD_IMM64) {
				pc++;
			}
			continue;
		}
		const int64_t target = static_cast<int64_t>(pc) + 1 +
				       static_cast<int64_t>(read_off(text, pc));
		if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("relative jump target out of range");
		}
		preds[static_cast<size_t>(target)].push_back(pc);
	}
	return preds;
}

bool has_external_branch_entry(const std::vector<std::vector<size_t>> &preds,
			       size_t begin, size_t end)
{
	for (size_t pc = begin + 1; pc <= end; pc++) {
		for (size_t pred : preds[pc]) {
			if (pred < begin || pred >= end) {
				return true;
			}
		}
	}
	return false;
}

std::optional<uint8_t> memory_base_reg(const std::vector<uint8_t> &text,
				       size_t pc)
{
	const uint8_t cls = text[pc * INSN_SIZE] & 0x07;
	if (cls == 0x01) {
		return src_reg(text, pc);
	}
	if (cls == 0x02 || cls == 0x03) {
		return dst_reg(text, pc);
	}
	return std::nullopt;
}

void set_memory_base_reg(std::vector<uint8_t> &text, size_t pc, uint8_t reg)
{
	const uint8_t cls = text[pc * INSN_SIZE] & 0x07;
	if (cls == 0x01) {
		set_src_reg(text, pc, reg);
	} else if (cls == 0x02 || cls == 0x03) {
		set_dst_reg(text, pc, reg);
	} else {
		throw std::runtime_error("instruction has no memory base register");
	}
}

struct RegLiveness {
	std::vector<uint16_t> live_in;
	std::vector<uint16_t> live_out;
};

RegLiveness compute_reg_liveness(const std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	std::vector<uint16_t> uses(insn_count), defs(insn_count), live_in(insn_count),
		live_out(insn_count);
	std::vector<std::vector<size_t>> succs(insn_count);
	constexpr uint16_t helper_args = reg_bit(1) | reg_bit(2) | reg_bit(3) |
					 reg_bit(4) | reg_bit(5);
	constexpr uint16_t helper_clobbers = reg_bit(0) | helper_args;

	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		const uint8_t dst = dst_reg(text, pc);
		const uint8_t src = src_reg(text, pc);
		const auto add_fallthrough = [&](size_t next) {
			if (next < insn_count) {
				succs[pc].push_back(next);
			}
		};
		const auto add_relative_target = [&]() {
			const int64_t target = static_cast<int64_t>(pc) + 1 +
					       static_cast<int64_t>(read_off(text, pc));
			if (target >= 0 && target < static_cast<int64_t>(insn_count)) {
				succs[pc].push_back(static_cast<size_t>(target));
			}
		};

		if (code == BPF_LD_IMM64) {
			defs[pc] = reg_bit(dst);
			add_fallthrough(pc + 2);
			if (pc + 1 < insn_count) {
				pc++;
			}
			continue;
		}
		if (is_alu_class(code)) {
			defs[pc] = reg_bit(dst);
			uses[pc] = alu_uses(code, dst, src);
			add_fallthrough(pc + 1);
			continue;
		}
		switch (code & 0x07) {
		case 0x01:
			defs[pc] = reg_bit(dst);
			uses[pc] = reg_bit(src);
			add_fallthrough(pc + 1);
			break;
		case 0x02:
			uses[pc] = reg_bit(dst);
			add_fallthrough(pc + 1);
			break;
		case 0x03:
			uses[pc] = reg_bit(dst) | reg_bit(src);
			add_fallthrough(pc + 1);
			break;
		case 0x05:
		case 0x06:
			if (code == BPF_EXIT) {
				uses[pc] = reg_bit(0);
			} else if (code == BPF_CALL || code == BPF_CALLX) {
				uses[pc] = helper_args;
				defs[pc] = helper_clobbers;
				add_fallthrough(pc + 1);
			} else if (code == BPF_JA) {
				add_relative_target();
			} else {
				uses[pc] = reg_bit(dst);
				if ((code & 0x08) != 0) {
					uses[pc] |= reg_bit(src);
				}
				add_fallthrough(pc + 1);
				add_relative_target();
			}
			break;
		default:
			add_fallthrough(pc + 1);
			break;
		}
	}

	bool changed = true;
	while (changed) {
		changed = false;
		for (size_t i = insn_count; i-- > 0;) {
			uint16_t out = 0;
			for (const size_t succ : succs[i]) {
				out |= live_in[succ];
			}
			const uint16_t in =
				static_cast<uint16_t>(uses[i] | (out & ~defs[i]));
			if (out != live_out[i] || in != live_in[i]) {
				live_out[i] = out;
				live_in[i] = in;
				changed = true;
			}
		}
	}

	return { std::move(live_in), std::move(live_out) };
}

void repair_added_pointer_mem_accesses(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	const auto preds = relative_jump_predecessors(text);
	for (size_t mem_pc = 0; mem_pc < insn_count; mem_pc++) {
		const auto tmp_reg = memory_base_reg(text, mem_pc);
		if (!tmp_reg) {
			if (text[mem_pc * INSN_SIZE] == BPF_LD_IMM64) {
				mem_pc++;
			}
			continue;
		}
		const size_t add_search_begin = mem_pc > 12 ? mem_pc - 12 : 0;
		std::optional<size_t> add_pc;
		for (size_t q = mem_pc; q-- > add_search_begin;) {
			if (text[q * INSN_SIZE] == BPF_ALU64_ADD_K &&
			    dst_reg(text, q) == *tmp_reg &&
			    src_reg(text, q) == 0) {
				add_pc = q;
				break;
			}
			if (insn_defines_reg(text, q, *tmp_reg)) {
				break;
			}
		}
		if (!add_pc || *add_pc == 0) {
			continue;
		}
		const size_t mov_pc = *add_pc - 1;
		if (text[mov_pc * INSN_SIZE] != BPF_ALU64_MOV_X ||
		    dst_reg(text, mov_pc) != *tmp_reg) {
			continue;
		}
		const uint8_t base_reg = src_reg(text, mov_pc);
		if (base_reg == *tmp_reg ||
		    has_external_branch_entry(preds, mov_pc, mem_pc)) {
			continue;
		}
		bool invalidated = false;
		for (size_t q = mov_pc + 1; q < mem_pc; q++) {
			if (q != *add_pc &&
			    insn_defines_reg(text, q, *tmp_reg)) {
				invalidated = true;
				break;
			}
			if (insn_defines_reg(text, q, base_reg)) {
				invalidated = true;
				break;
			}
			if (text[q * INSN_SIZE] == BPF_LD_IMM64) {
				q++;
			}
		}
		if (invalidated) {
			continue;
		}
		const int64_t combined =
			static_cast<int64_t>(read_off(text, mem_pc)) +
			static_cast<int64_t>(read_imm(text, *add_pc));
		if (combined < std::numeric_limits<int16_t>::min() ||
		    combined > std::numeric_limits<int16_t>::max()) {
			continue;
		}
		set_memory_base_reg(text, mem_pc, base_reg);
		write_off(text, mem_pc, static_cast<int16_t>(combined));
	}
}

void write_direct_load(std::vector<uint8_t> &text, size_t pc, uint8_t code,
		       uint8_t dst, uint8_t base, int16_t off)
{
	std::fill(text.begin() + pc * INSN_SIZE,
		  text.begin() + (pc + 1) * INSN_SIZE, 0);
	text[pc * INSN_SIZE] = code;
	set_dst_reg(text, pc, dst);
	set_src_reg(text, pc, base);
	write_off(text, pc, off);
}

void repair_ctx_offset_switch_loads(std::vector<uint8_t> &text)
{
	bool changed = true;
	while (changed) {
		changed = false;
		const size_t insn_count = text.size() / INSN_SIZE;
		const auto preds = relative_jump_predecessors(text);
		const auto liveness = compute_reg_liveness(text);

		for (size_t load_pc = 1; load_pc < insn_count; load_pc++) {
			const uint8_t load_code = text[load_pc * INSN_SIZE];
			if ((load_code & 0x07) != 0x01) {
				continue;
			}
			const uint8_t base = src_reg(text, load_pc);
			const uint8_t loaded = dst_reg(text, load_pc);
			if (base == 10 || (liveness.live_out[load_pc] & reg_bit(base)) != 0) {
				continue;
			}
			const int32_t common_off = read_off(text, load_pc);
			const size_t join_begin = load_pc > 16 ? load_pc - 16 : 0;
			for (size_t join_pc = load_pc; join_pc-- > join_begin;) {
				if (preds[join_pc].size() < 2) {
					continue;
				}
				bool valid = true;
				for (size_t pc = join_pc; pc < load_pc; pc++) {
					if (insn_defines_reg(text, pc, base) ||
					    insn_defines_reg(text, pc, loaded)) {
						valid = false;
						break;
					}
				}
				if (!valid) {
					continue;
				}

				std::vector<size_t> add_pcs;
				std::vector<size_t> direct_branches;
				for (size_t pred : preds[join_pc]) {
					const uint8_t pred_code = text[pred * INSN_SIZE];
					if (pred_code == BPF_JA && pred > 0 &&
					    text[(pred - 1) * INSN_SIZE] ==
						    BPF_ALU64_ADD_K &&
					    dst_reg(text, pred - 1) == base &&
					    src_reg(text, pred - 1) == 0) {
						add_pcs.push_back(pred - 1);
					} else if (pred_code == BPF_JA) {
						direct_branches.push_back(pred);
					} else {
						direct_branches.push_back(pred);
					}
				}
				if (join_pc > 0 &&
				    text[(join_pc - 1) * INSN_SIZE] ==
					    BPF_ALU64_ADD_K &&
				    dst_reg(text, join_pc - 1) == base &&
				    src_reg(text, join_pc - 1) == 0) {
					add_pcs.push_back(join_pc - 1);
				}
				if (add_pcs.empty()) {
					continue;
				}

				bool offsets_fit = true;
				for (size_t add_pc : add_pcs) {
					const int64_t off =
						static_cast<int64_t>(common_off) +
						static_cast<int64_t>(read_imm(text, add_pc));
					if (off < std::numeric_limits<int16_t>::min() ||
					    off > std::numeric_limits<int16_t>::max()) {
						offsets_fit = false;
						break;
					}
				}
				if (!offsets_fit) {
					continue;
				}

				size_t inserted = 0;
				if (!direct_branches.empty()) {
					if (common_off < std::numeric_limits<int16_t>::min() ||
					    common_off > std::numeric_limits<int16_t>::max()) {
						continue;
					}
					std::vector<uint8_t> block(2 * INSN_SIZE, 0);
					block[0] = BPF_JA;
					write_off(block, 0, 1);
					block[INSN_SIZE] = load_code;
					set_dst_reg(block, 1, loaded);
					set_src_reg(block, 1, base);
					write_off(block, 1, static_cast<int16_t>(common_off));
					insert_insns_adjusting_jumps(text, join_pc, block);
					inserted = 2;
					for (size_t branch_pc : direct_branches) {
						const int64_t off =
							static_cast<int64_t>(join_pc + 1) -
							static_cast<int64_t>(branch_pc) - 1;
						if (off < std::numeric_limits<int16_t>::min() ||
						    off > std::numeric_limits<int16_t>::max()) {
							throw std::runtime_error(
								"ctx switch branch offset out of range");
						}
						write_off(text, branch_pc,
							  static_cast<int16_t>(off));
					}
				}

				for (size_t add_pc : add_pcs) {
					const int64_t off =
						static_cast<int64_t>(common_off) +
						static_cast<int64_t>(read_imm(text, add_pc));
					write_direct_load(text, add_pc, load_code, loaded,
							  base, static_cast<int16_t>(off));
				}
				write_noop(text, load_pc + inserted);
				changed = true;
				break;
			}
			if (changed) {
				break;
			}
		}
	}
}

void repair_mod_shift_pointer_bounds(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	const auto targets = branch_targets(text);
	struct PendingCheck {
		size_t pc;
		uint8_t reg;
		int32_t bound;
	};
	std::vector<PendingCheck> checks;

	for (size_t add_pc = 0; add_pc < insn_count; add_pc++) {
		if (text[add_pc * INSN_SIZE] != BPF_ALU64_ADD_X) {
			continue;
		}
		const uint8_t offset_reg = src_reg(text, add_pc);
		const size_t lsh_search_begin = add_pc > 8 ? add_pc - 8 : 0;
		std::optional<size_t> lsh_pc;
		for (size_t q = add_pc; q-- > lsh_search_begin;) {
			if (text[q * INSN_SIZE] == BPF_ALU32_LSH_K &&
			    dst_reg(text, q) == offset_reg &&
			    src_reg(text, q) == 0) {
				lsh_pc = q;
				break;
			}
			if (insn_defines_reg(text, q, offset_reg)) {
				break;
			}
		}
		if (!lsh_pc) {
			continue;
		}
		const int32_t shift = read_imm(text, *lsh_pc);
		if (shift < 0 || shift > 30) {
			continue;
		}
		bool changed_after_lsh = false;
		bool existing_check = false;
		for (size_t q = *lsh_pc + 1; q < add_pc; q++) {
			if (targets[q]) {
				changed_after_lsh = true;
				break;
			}
			if (text[q * INSN_SIZE] == BPF_JGT_K &&
			    dst_reg(text, q) == offset_reg &&
			    src_reg(text, q) == 0 &&
			    read_off(text, q) == static_cast<int16_t>(add_pc - q) &&
			    read_imm(text, q) >= 0) {
				existing_check = true;
			}
			if (insn_defines_reg(text, q, offset_reg)) {
				changed_after_lsh = true;
				break;
			}
			if (text[q * INSN_SIZE] == BPF_LD_IMM64) {
				q++;
			}
		}
		if (changed_after_lsh || existing_check) {
			continue;
		}

		const size_t mod_search_begin = *lsh_pc > 16 ? *lsh_pc - 16 : 0;
		std::optional<size_t> mod_pc;
		for (size_t q = *lsh_pc; q-- > mod_search_begin;) {
			if (targets[q] && q != *lsh_pc) {
				break;
			}
			if (text[q * INSN_SIZE] == BPF_ALU32_MOD_K &&
			    dst_reg(text, q) == offset_reg &&
			    src_reg(text, q) == 0) {
				mod_pc = q;
				break;
			}
			if (insn_defines_reg(text, q, offset_reg)) {
				break;
			}
		}
		if (!mod_pc) {
			continue;
		}
		bool mid_block_entry = false;
		for (size_t q = *mod_pc + 1; q < *lsh_pc; q++) {
			if (targets[q]) {
				mid_block_entry = true;
				break;
			}
			if (insn_defines_reg(text, q, offset_reg)) {
				mid_block_entry = true;
				break;
			}
			if (text[q * INSN_SIZE] == BPF_LD_IMM64) {
				q++;
			}
		}
		if (mid_block_entry) {
			continue;
		}
		const int32_t mod = read_imm(text, *mod_pc);
		if (mod <= 0) {
			continue;
		}
		const int64_t bound =
			(static_cast<int64_t>(mod) - 1) << shift;
		if (bound < 0 ||
		    bound > std::numeric_limits<int32_t>::max()) {
			continue;
		}
		bool check_already_covers = false;
		for (size_t q = *lsh_pc + 1; q < add_pc; q++) {
			if (text[q * INSN_SIZE] == BPF_JGT_K &&
			    dst_reg(text, q) == offset_reg &&
			    src_reg(text, q) == 0 &&
			    read_off(text, q) == static_cast<int16_t>(add_pc - q) &&
			    read_imm(text, q) >= bound) {
				check_already_covers = true;
				break;
			}
		}
		if (!check_already_covers) {
			checks.push_back({ add_pc, offset_reg,
					   static_cast<int32_t>(bound) });
		}
	}

	for (auto it = checks.rbegin(); it != checks.rend(); ++it) {
		std::vector<uint8_t> check(INSN_SIZE, 0);
		check[0] = BPF_JGT_K;
		check[1] = it->reg & 0x0f;
		write_off(check, 0, 1);
		write_imm(check, 0, it->bound);
		insert_insn_adjusting_jumps(text, it->pc, check);
	}
}

void repair_packet_byte_bounds(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	const auto liveness = compute_reg_liveness(text);
	struct PendingCheck {
		size_t pc;
		uint8_t ptr_reg;
		uint8_t end_reg;
		uint8_t tmp_reg;
		int16_t off;
	};
	std::vector<PendingCheck> checks;

	for (size_t pc = 0; pc + 1 < insn_count; pc++) {
		if (text[pc * INSN_SIZE] != BPF_JGE_X ||
		    text[(pc + 1) * INSN_SIZE] != BPF_LDX_MEM_B ||
		    read_off(text, pc + 1) != 0) {
			continue;
		}
		const uint8_t ptr_reg = dst_reg(text, pc);
		const uint8_t end_reg = src_reg(text, pc);
		if (src_reg(text, pc + 1) != ptr_reg) {
			continue;
		}
		const int64_t target = static_cast<int64_t>(pc) + 1 +
				       static_cast<int64_t>(read_off(text, pc));
		if (target <= static_cast<int64_t>(pc) ||
		    target >= static_cast<int64_t>(insn_count)) {
			continue;
		}
		std::optional<uint8_t> tmp_reg;
		for (uint8_t reg = 0; reg < 10; reg++) {
			if (reg == ptr_reg || reg == end_reg) {
				continue;
			}
			if ((liveness.live_in[pc] & reg_bit(reg)) == 0) {
				tmp_reg = reg;
				break;
			}
		}
		if (!tmp_reg) {
			continue;
		}
		const int64_t inserted_pc = static_cast<int64_t>(pc) + 2;
		const int64_t new_target = target + 3;
		const int64_t new_off = new_target - inserted_pc - 1;
		if (new_off < std::numeric_limits<int16_t>::min() ||
		    new_off > std::numeric_limits<int16_t>::max()) {
			continue;
		}
		checks.push_back({ pc, ptr_reg, end_reg, *tmp_reg,
				   static_cast<int16_t>(new_off) });
	}

	for (size_t pc = 0; pc + 2 < insn_count; pc++) {
		if (text[pc * INSN_SIZE] != BPF_JLT_X ||
		    text[(pc + 1) * INSN_SIZE] != BPF_JA) {
			continue;
		}
		const uint8_t ptr_reg = dst_reg(text, pc);
		const uint8_t end_reg = src_reg(text, pc);
		const int64_t safe_pc = static_cast<int64_t>(pc) + 1 +
					static_cast<int64_t>(read_off(text, pc));
		if (safe_pc <= static_cast<int64_t>(pc + 1) ||
		    safe_pc >= static_cast<int64_t>(insn_count)) {
			continue;
		}
		bool has_byte_load = false;
		const size_t search_end = std::min(insn_count,
						   static_cast<size_t>(safe_pc) + 8);
		for (size_t q = static_cast<size_t>(safe_pc); q < search_end; q++) {
			if (text[q * INSN_SIZE] == BPF_LDX_MEM_B &&
			    src_reg(text, q) == ptr_reg && read_off(text, q) == 0) {
				has_byte_load = true;
				break;
			}
			if (insn_defines_reg(text, q, ptr_reg)) {
				break;
			}
			if (text[q * INSN_SIZE] == BPF_LD_IMM64) {
				q++;
			}
		}
		if (!has_byte_load) {
			continue;
		}
		std::optional<uint8_t> tmp_reg;
		for (uint8_t reg = 0; reg < 10; reg++) {
			if (reg == ptr_reg || reg == end_reg) {
				continue;
			}
			if ((liveness.live_in[pc] & reg_bit(reg)) == 0) {
				tmp_reg = reg;
				break;
			}
		}
		if (!tmp_reg) {
			continue;
		}
		const int64_t inserted_pc = static_cast<int64_t>(pc) + 2;
		const int64_t new_fail_pc = static_cast<int64_t>(pc + 1) + 3;
		const int64_t new_off = new_fail_pc - inserted_pc - 1;
		if (new_off < std::numeric_limits<int16_t>::min() ||
		    new_off > std::numeric_limits<int16_t>::max()) {
			continue;
		}
		checks.push_back({ pc, ptr_reg, end_reg, *tmp_reg,
				   static_cast<int16_t>(new_off) });
	}

	for (auto it = checks.rbegin(); it != checks.rend(); ++it) {
		std::vector<uint8_t> block(3 * INSN_SIZE, 0);
		block[0] = BPF_ALU64_MOV_X;
		set_dst_reg(block, 0, it->tmp_reg);
		set_src_reg(block, 0, it->ptr_reg);
		block[INSN_SIZE] = BPF_ALU64_ADD_K;
		set_dst_reg(block, 1, it->tmp_reg);
		write_imm(block, 1, 1);
		block[2 * INSN_SIZE] = BPF_JGT_X;
		set_dst_reg(block, 2, it->tmp_reg);
		set_src_reg(block, 2, it->end_reg);
		write_off(block, 2, it->off);
		insert_insns_adjusting_jumps(text, it->pc, block);
	}
}

void eliminate_dead_alu_defs(std::vector<uint8_t> &text)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	std::vector<uint16_t> uses(insn_count), defs(insn_count), live_in(insn_count),
		live_out(insn_count);
	std::vector<std::vector<size_t>> succs(insn_count);
	constexpr uint16_t helper_args = reg_bit(1) | reg_bit(2) | reg_bit(3) |
					 reg_bit(4) | reg_bit(5);
	constexpr uint16_t helper_clobbers = reg_bit(0) | helper_args;

	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		const uint8_t dst = dst_reg(text, pc);
		const uint8_t src = src_reg(text, pc);
		const auto add_fallthrough = [&](size_t next) {
			if (next < insn_count) {
				succs[pc].push_back(next);
			}
		};
		const auto add_relative_target = [&]() {
			const int64_t target = static_cast<int64_t>(pc) + 1 +
					       static_cast<int64_t>(read_off(text, pc));
			if (target >= 0 && target < static_cast<int64_t>(insn_count)) {
				succs[pc].push_back(static_cast<size_t>(target));
			}
		};

		if (code == BPF_LD_IMM64) {
			defs[pc] = reg_bit(dst);
			add_fallthrough(pc + 2);
			if (pc + 1 < insn_count) {
				pc++;
			}
			continue;
		}
		if (is_alu_class(code)) {
			defs[pc] = reg_bit(dst);
			uses[pc] = alu_uses(code, dst, src);
			add_fallthrough(pc + 1);
			continue;
		}
		switch (code & 0x07) {
		case 0x01:
			defs[pc] = reg_bit(dst);
			uses[pc] = reg_bit(src);
			add_fallthrough(pc + 1);
			break;
		case 0x02:
			uses[pc] = reg_bit(dst);
			add_fallthrough(pc + 1);
			break;
		case 0x03:
			uses[pc] = reg_bit(dst) | reg_bit(src);
			add_fallthrough(pc + 1);
			break;
		case 0x05:
		case 0x06:
			if (code == BPF_EXIT) {
				uses[pc] = reg_bit(0);
			} else if (code == BPF_CALL || code == BPF_CALLX) {
				uses[pc] = helper_args;
				defs[pc] = helper_clobbers;
				add_fallthrough(pc + 1);
			} else if (code == BPF_JA) {
				add_relative_target();
			} else {
				uses[pc] = reg_bit(dst);
				if ((code & 0x08) != 0) {
					uses[pc] |= reg_bit(src);
				}
				add_fallthrough(pc + 1);
				add_relative_target();
			}
			break;
		default:
			add_fallthrough(pc + 1);
			break;
		}
	}

	bool changed = true;
	while (changed) {
		changed = false;
		for (size_t i = insn_count; i-- > 0;) {
			uint16_t out = 0;
			for (const size_t succ : succs[i]) {
				out |= live_in[succ];
			}
			const uint16_t in =
				static_cast<uint16_t>(uses[i] | (out & ~defs[i]));
			if (out != live_out[i] || in != live_in[i]) {
				live_out[i] = out;
				live_in[i] = in;
				changed = true;
			}
		}
	}

	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if (code == BPF_LD_IMM64) {
			pc++;
			continue;
		}
		const uint8_t dst = dst_reg(text, pc);
		if (dst == 10 || !is_pure_alu_def(code) ||
		    (live_out[pc] & reg_bit(dst)) != 0) {
			continue;
		}
		write_noop(text, pc);
	}
}

std::vector<uint8_t>
extract_relocated_text(const std::vector<uint8_t> &object_bytes,
		       const std::vector<uint8_t> &input)
{
	auto buffer = llvm::MemoryBuffer::getMemBuffer(
		llvm::StringRef(
			reinterpret_cast<const char *>(object_bytes.data()),
			object_bytes.size()),
		"bpfopt-llvm.o", false);
	auto object = expected_or_throw(
		llvm::object::ObjectFile::createObjectFile(
			buffer->getMemBufferRef()));

	std::optional<llvm::object::SectionRef> text_section;
	for (const auto &section : object->sections()) {
		if (expected_or_throw(section.getName()) == ".text") {
			text_section = section;
			break;
		}
	}
	if (!text_section) {
		throw std::runtime_error("LLVM BPF object has no .text section");
	}
	const auto contents = expected_or_throw(text_section->getContents());
	std::vector<uint8_t> text(contents.bytes_begin(), contents.bytes_end());
	if (text.size() % INSN_SIZE != 0) {
		throw std::runtime_error(".text size is not a multiple of 8");
	}
	const auto subprog_start = subprog_start_pc(input);
	const size_t generated_insns = text.size() / INSN_SIZE;
	apply_text_relocations(*object, text, subprog_start, generated_insns);
	if (subprog_start) {
		text.insert(text.end(), input.begin() + *subprog_start * INSN_SIZE,
			    input.end());
	}
	repair_verifier_range_copies(text);
	repair_zero_extended_signed_jumps(text);
	repair_added_pointer_mem_accesses(text);
	repair_mod_shift_pointer_bounds(text);
	repair_packet_byte_bounds(text);
	eliminate_dead_alu_defs(text);
	return text;
}

std::unique_ptr<llvm::TargetMachine>
create_bpf_target_machine(llvm::CodeGenOptLevel opt_level)
{
	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmPrinters();

	std::string error;
	const llvm::Target *target =
		llvm::TargetRegistry::lookupTarget("bpfel", error);
	if (!target) {
		throw std::runtime_error("lookupTarget(bpfel) failed: " + error);
	}
	llvm::TargetOptions options;
	auto machine = std::unique_ptr<llvm::TargetMachine>(
		target->createTargetMachine("bpfel", "v3", "", options,
					    std::nullopt, std::nullopt,
					    opt_level));
	if (!machine) {
		throw std::runtime_error("failed to create BPF target machine");
	}
	return machine;
}

void optimize_module(llvm::Module &module, llvm::TargetMachine &machine)
{
	llvm::LoopAnalysisManager loop_am;
	llvm::FunctionAnalysisManager function_am;
	llvm::CGSCCAnalysisManager cgscc_am;
	llvm::ModuleAnalysisManager module_am;
	llvm::PassBuilder passes(&machine);
	passes.registerModuleAnalyses(module_am);
	passes.registerCGSCCAnalyses(cgscc_am);
	passes.registerFunctionAnalyses(function_am);
	passes.registerLoopAnalyses(loop_am);
	passes.crossRegisterProxies(loop_am, function_am, cgscc_am, module_am);
	auto pipeline = passes.buildPerModuleDefaultPipeline(
		llvm::OptimizationLevel::O3);
	pipeline.run(module, module_am);
}

void promote_register_allocas(llvm::Module &module, llvm::TargetMachine &machine)
{
	llvm::LoopAnalysisManager loop_am;
	llvm::FunctionAnalysisManager function_am;
	llvm::CGSCCAnalysisManager cgscc_am;
	llvm::ModuleAnalysisManager module_am;
	llvm::PassBuilder passes(&machine);
	passes.registerModuleAnalyses(module_am);
	passes.registerCGSCCAnalyses(cgscc_am);
	passes.registerFunctionAnalyses(function_am);
	passes.registerLoopAnalyses(loop_am);
	passes.crossRegisterProxies(loop_am, function_am, cgscc_am, module_am);

	llvm::FunctionPassManager function_pipeline;
	function_pipeline.addPass(llvm::SROAPass(llvm::SROAOptions::PreserveCFG));
	function_pipeline.addPass(llvm::PromotePass());
	function_pipeline.addPass(llvm::DCEPass());
	llvm::ModulePassManager module_pipeline;
	module_pipeline.addPass(llvm::createModuleToFunctionPassAdaptor(
		std::move(function_pipeline)));
	module_pipeline.run(module, module_am);
}

std::vector<uint8_t> emit_bpf_object(llvm::Module &module, bool optimize_ir)
{
	auto machine = create_bpf_target_machine(
		optimize_ir ? llvm::CodeGenOptLevel::Aggressive :
			      llvm::CodeGenOptLevel::Less);
	module.setTargetTriple("bpfel");
	module.setDataLayout(machine->createDataLayout());
	if (optimize_ir) {
		optimize_module(module, *machine);
	} else {
		promote_register_allocas(module, *machine);
	}

	llvm::SmallVector<char, 0> object_stream;
	llvm::raw_svector_ostream output(object_stream);
	llvm::legacy::PassManager pass_manager;
#if LLVM_VERSION_MAJOR >= 18
	if (machine->addPassesToEmitFile(pass_manager, output, nullptr,
					 llvm::CodeGenFileType::ObjectFile)) {
#else
	if (machine->addPassesToEmitFile(pass_manager, output, nullptr,
					 llvm::CGFT_ObjectFile)) {
#endif
		throw std::runtime_error("BPF target cannot emit object file");
	}
	pass_manager.run(module);
	return { object_stream.begin(), object_stream.end() };
}

std::vector<std::string> helper_symbols(const std::vector<uint8_t> &input)
{
	std::map<int32_t, bool> ids;
	const size_t insn_count = input.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = input[pc * INSN_SIZE];
		if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
		    src_reg(input, pc) != BPF_PSEUDO_CALL) {
			const int32_t id = read_imm(input, pc);
			if (id < 0) {
				throw std::runtime_error("negative helper id");
			}
			ids[id] = true;
		}
	}

	std::vector<std::string> names;
	for (const auto &[id, _] : ids) {
		char buf[32];
		std::snprintf(buf, sizeof(buf), "_bpf_helper_ext_%04d", id);
		names.emplace_back(buf);
	}
	return names;
}

llvm::orc::ThreadSafeModule generate_llvm_module(const std::vector<uint8_t> &input)
{
	if (input.empty() || input.size() % INSN_SIZE != 0) {
		throw std::runtime_error(
			"input bytecode length must be a non-empty multiple of 8");
	}
	bpftime::llvmbpf_vm vm;
	if (vm.load_code(input.data(), input.size()) < 0) {
		throw std::runtime_error("llvmbpf load_code failed: " +
					 vm.get_error_message());
	}
	vm.set_kernel_compatible_mode(true);

	bpftime::llvm_bpf_jit_context context(vm);
	return expected_or_throw(
		context.generateModule(helper_symbols(input), {}, false));
}

std::vector<uint8_t> run_llvm_roundtrip(const std::vector<uint8_t> &input,
					bool optimize_ir)
{
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		return extract_relocated_text(emit_bpf_object(module, optimize_ir),
					      input);
	});
}

struct InlineHint {
	std::string map_name;
	std::vector<uint8_t> key;
};

struct MapInfo {
	uint32_t id = 0;
	std::string name;
	uint32_t key_size = 0;
	uint32_t value_size = 0;
};

struct InlineRecord {
	uint32_t map_id = 0;
	std::vector<uint8_t> key;
	std::vector<uint8_t> value;
};

struct MapInlineArgs {
	std::filesystem::path map_values;
	std::vector<uint32_t> map_ids;
	std::vector<InlineHint> hints;
};

struct MapSnapshot {
	std::map<uint32_t, MapInfo> maps;
	std::map<std::string, uint32_t> map_id_by_name;
	std::map<std::pair<uint32_t, std::string>, std::vector<uint8_t>> values;
	std::map<uint32_t, std::vector<uint8_t>> uniform_values;
};

std::string bytes_hex(const std::vector<uint8_t> &bytes)
{
	constexpr char digits[] = "0123456789abcdef";
	std::string out;
	out.reserve(bytes.size() * 2);
	for (uint8_t byte : bytes) {
		out.push_back(digits[byte >> 4]);
		out.push_back(digits[byte & 0x0f]);
	}
	return out;
}

uint8_t parse_hex_nibble(char c)
{
	if (c >= '0' && c <= '9') {
		return static_cast<uint8_t>(c - '0');
	}
	if (c >= 'a' && c <= 'f') {
		return static_cast<uint8_t>(10 + c - 'a');
	}
	if (c >= 'A' && c <= 'F') {
		return static_cast<uint8_t>(10 + c - 'A');
	}
	throw std::runtime_error("invalid hex digit");
}

std::vector<uint8_t> parse_hex_bytes(std::string_view text)
{
	if (text.size() % 2 != 0) {
		throw std::runtime_error("hex string has odd length");
	}
	std::vector<uint8_t> bytes;
	bytes.reserve(text.size() / 2);
	for (size_t i = 0; i < text.size(); i += 2) {
		bytes.push_back(static_cast<uint8_t>(
			(parse_hex_nibble(text[i]) << 4) |
			parse_hex_nibble(text[i + 1])));
	}
	return bytes;
}

std::vector<uint8_t> decode_bpftool_byte_array(const llvm::json::Array &array)
{
	std::vector<uint8_t> bytes;
	bytes.reserve(array.size());
	for (const auto &item : array) {
		const auto text = item.getAsString();
		if (!text || !text->starts_with("0x") || text->size() != 4) {
			throw std::runtime_error("bpftool byte is not 0xNN");
		}
		bytes.push_back(parse_hex_bytes(text->substr(2))[0]);
	}
	return bytes;
}

const llvm::json::Object &json_object(const llvm::json::Value &value,
				      std::string_view label)
{
	auto *object = value.getAsObject();
	if (!object) {
		throw std::runtime_error(std::string(label) + " is not an object");
	}
	return *object;
}

const llvm::json::Array &json_array(const llvm::json::Value &value,
				    std::string_view label)
{
	auto *array = value.getAsArray();
	if (!array) {
		throw std::runtime_error(std::string(label) + " is not an array");
	}
	return *array;
}

std::string json_string_field(const llvm::json::Object &object,
			      std::string_view key)
{
	auto value = object.getString(key);
	if (!value) {
		throw std::runtime_error("missing JSON string field " +
					 std::string(key));
	}
	return value->str();
}

uint32_t json_u32_field(const llvm::json::Object &object, std::string_view key)
{
	auto value = object.getInteger(key);
	if (!value || *value < 0 ||
	    *value > std::numeric_limits<uint32_t>::max()) {
		throw std::runtime_error("missing JSON u32 field " +
					 std::string(key));
	}
	return static_cast<uint32_t>(*value);
}

std::vector<uint8_t> decode_value_hex_field(const llvm::json::Object &object,
					    std::string_view key,
					    size_t expected_size)
{
	auto bytes = parse_hex_bytes(json_string_field(object, key));
	if (bytes.size() != expected_size) {
		throw std::runtime_error("compressed map value has wrong size");
	}
	return bytes;
}

void read_compressed_map_values(const llvm::json::Object &object,
				uint32_t map_id, const MapInfo &info,
				MapSnapshot &snapshot)
{
	const std::string compression = json_string_field(object, "compression");
	const uint32_t value_size = json_u32_field(object, "value_size");
	if (value_size != info.value_size) {
		throw std::runtime_error("compressed map value_size mismatch");
	}
	if (compression == "uniform") {
		snapshot.uniform_values[map_id] =
			decode_value_hex_field(object, "value_hex", value_size);
		return;
	}
	auto *entries = object.getObject("entries");
	if (!entries) {
		throw std::runtime_error("compressed map entries missing");
	}
	std::vector<uint8_t> default_value;
	if (compression == "sparse") {
		default_value =
			decode_value_hex_field(object, "default_hex", value_size);
	}
	for (const auto &entry : *entries) {
		const auto key = parse_hex_bytes(entry.getFirst().str());
		if (key.size() != info.key_size) {
			throw std::runtime_error("compressed map key size mismatch");
		}
		const auto value_text = entry.getSecond().getAsString();
		if (!value_text) {
			throw std::runtime_error("compressed map value is not a string");
		}
		auto value = parse_hex_bytes(*value_text);
		if (value.size() != info.value_size) {
			throw std::runtime_error("compressed map value size mismatch");
		}
		snapshot.values[std::make_pair(map_id, bytes_hex(key))] =
			std::move(value);
	}
	if (compression == "sparse") {
		snapshot.uniform_values[map_id] = std::move(default_value);
	} else if (compression != "enumerated") {
		throw std::runtime_error("unsupported compressed map encoding");
	}
}

MapInlineArgs parse_map_inline_args(const std::vector<std::string> &args)
{
	MapInlineArgs parsed;
	for (size_t i = 0; i < args.size(); i++) {
		const auto &arg = args[i];
		if (arg == "--map-values") {
			if (++i >= args.size()) {
				throw std::runtime_error("--map-values requires DIR");
			}
			parsed.map_values = args[i];
		} else if (arg == "--map-ids") {
			if (++i >= args.size()) {
				throw std::runtime_error("--map-ids requires LIST");
			}
			parsed.map_ids = parse_u32_csv(args[i]);
		} else if (arg == "--inline-hint" ||
			   arg.starts_with("--inline-hint=")) {
			std::string value;
			if (arg == "--inline-hint") {
				if (++i >= args.size()) {
					throw std::runtime_error(
						"--inline-hint requires VALUE");
				}
				value = args[i];
			} else {
				value = arg.substr(std::strlen("--inline-hint="));
			}
			const auto colon = value.find(':');
			if (colon == std::string::npos || colon == 0 ||
			    colon + 1 >= value.size()) {
				throw std::runtime_error("invalid --inline-hint");
			}
			const auto key_text = value.substr(colon + 1);
			if (key_text.empty() || key_text[0] != '!') {
				throw std::runtime_error(
					"LLVM map_inline currently requires hard inline hints");
			}
			parsed.hints.push_back({ value.substr(0, colon),
						 parse_hex_bytes(
							 std::string_view(key_text).substr(1)) });
		} else {
			throw std::runtime_error("map_inline unknown pass-local arg: " +
						 arg);
		}
	}
	if (parsed.map_values.empty()) {
		throw std::runtime_error("map_inline requires --map-values");
	}
	if (parsed.map_ids.empty()) {
		throw std::runtime_error("map_inline requires --map-ids");
	}
	return parsed;
}

MapSnapshot read_map_snapshot(const MapInlineArgs &args)
{
	MapSnapshot snapshot;
	for (uint32_t map_id : args.map_ids) {
		if (map_id == 0) {
			continue;
		}
		const auto show_path =
			args.map_values / ("map-" + std::to_string(map_id) + ".show.json");
		auto show_value =
			expected_or_throw(llvm::json::parse(read_text(show_path)));
		const auto &show = json_object(show_value, show_path.string());
		MapInfo info;
		info.id = json_u32_field(show, "id");
		info.name = json_string_field(show, "name");
		info.key_size = json_u32_field(show, "bytes_key");
		info.value_size = json_u32_field(show, "bytes_value");
		if (info.id != map_id) {
			throw std::runtime_error("map show id mismatch");
		}
		snapshot.map_id_by_name[info.name] = map_id;
		snapshot.maps[map_id] = info;

		const auto dump_path =
			args.map_values / ("map-" + std::to_string(map_id) + ".dump.json");
		if (!std::filesystem::exists(dump_path)) {
			continue;
		}
		auto dump_value =
			expected_or_throw(llvm::json::parse(read_text(dump_path)));
		if (auto *array = dump_value.getAsArray()) {
			for (const auto &entry_value : *array) {
				const auto &entry =
					json_object(entry_value, dump_path.string());
				auto *key_array = entry.getArray("key");
				auto *value_array = entry.getArray("value");
				if (!key_array || !value_array) {
					continue;
				}
				const auto key = decode_bpftool_byte_array(*key_array);
				const auto value =
					decode_bpftool_byte_array(*value_array);
				if (key.size() == info.key_size &&
				    value.size() == info.value_size) {
					snapshot.values[std::make_pair(map_id,
								       bytes_hex(key))] =
						value;
				}
			}
		} else if (auto *object = dump_value.getAsObject()) {
			if (object->getString("compression")) {
				read_compressed_map_values(*object, map_id, info,
							   snapshot);
			}
		}
	}

	const auto overlays_path = args.map_values / "overlays.json";
	if (std::filesystem::exists(overlays_path)) {
		auto overlays_value =
			expected_or_throw(llvm::json::parse(read_text(overlays_path)));
		const auto &overlays = json_object(overlays_value, "overlays.json");
		for (const auto &entry : overlays) {
			const uint32_t map_id =
				static_cast<uint32_t>(std::stoul(entry.getFirst().str()));
			const auto map_it = snapshot.maps.find(map_id);
			if (map_it == snapshot.maps.end()) {
				throw std::runtime_error(
					"overlay references unknown map id");
			}
			read_compressed_map_values(
				json_object(entry.getSecond(), "compressed overlay"),
				map_id, map_it->second, snapshot);
		}
	}
	return snapshot;
}

std::optional<std::vector<uint8_t>>
lookup_snapshot_value(const MapSnapshot &snapshot, uint32_t map_id,
		      const std::vector<uint8_t> &key)
{
	const auto key_hex = bytes_hex(key);
	const auto exact = snapshot.values.find({ map_id, key_hex });
	if (exact != snapshot.values.end()) {
		return exact->second;
	}
	const auto uniform = snapshot.uniform_values.find(map_id);
	if (uniform != snapshot.uniform_values.end()) {
		return uniform->second;
	}
	return std::nullopt;
}

size_t mem_access_size(uint8_t code)
{
	switch (code & 0x18) {
	case 0x00:
		return 4;
	case 0x08:
		return 2;
	case 0x10:
		return 1;
	case 0x18:
		return 8;
	default:
		throw std::runtime_error("invalid BPF memory size");
	}
}

std::optional<uint32_t> map_id_for_lookup(const std::vector<uint8_t> &text,
					  size_t call_pc,
					  const std::vector<uint32_t> &map_ids)
{
	const size_t begin = call_pc > 16 ? call_pc - 16 : 0;
	for (size_t pc = call_pc; pc-- > begin;) {
		if (!is_ldimm64(text, pc)) {
			if (insn_defines_reg(text, pc, 1)) {
				break;
			}
			continue;
		}
		if (dst_reg(text, pc) != 1 ||
		    src_reg(text, pc) != BPF_PSEUDO_MAP_IDX) {
			pc++;
			continue;
		}
		const int32_t idx = read_imm(text, pc);
		if (idx < 0 || static_cast<size_t>(idx) >= map_ids.size()) {
			throw std::runtime_error("map_inline map index out of range");
		}
		return map_ids[static_cast<size_t>(idx)];
	}
	return std::nullopt;
}

std::vector<bool> stack_bytes_used(const std::vector<uint8_t> &text)
{
	std::vector<bool> used(512, false);
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t code = text[pc * INSN_SIZE];
		if (code == BPF_LD_IMM64) {
			pc++;
			continue;
		}
		const auto base = memory_base_reg(text, pc);
		if (!base || *base != 10) {
			continue;
		}
		const int16_t off = read_off(text, pc);
		const size_t size = mem_access_size(code);
		if (off >= 0 || off < -512 ||
		    static_cast<int>(off + size) > 0) {
			continue;
		}
		for (int i = off; i < off + static_cast<int>(size); i++) {
			used[static_cast<size_t>(512 + i)] = true;
		}
	}
	return used;
}

int16_t allocate_stack_slot(std::vector<bool> &used, size_t size)
{
	const size_t aligned = (size + 7) & ~static_cast<size_t>(7);
	for (int start = 512 - static_cast<int>(aligned); start >= 0; start -= 8) {
		bool free = true;
		for (size_t i = 0; i < aligned; i++) {
			if (used[static_cast<size_t>(start) + i]) {
				free = false;
				break;
			}
		}
		if (!free) {
			continue;
		}
		for (size_t i = 0; i < aligned; i++) {
			used[static_cast<size_t>(start) + i] = true;
		}
		return static_cast<int16_t>(start - 512);
	}
	throw std::runtime_error("map_inline could not allocate BPF stack slot");
}

std::vector<uint8_t> build_stack_value_block(const std::vector<uint8_t> &value,
					     int16_t slot)
{
	std::vector<uint8_t> block;
	const auto append = [&](uint8_t code, uint8_t dst, uint8_t src,
				int16_t off, int32_t imm) {
		const size_t pc = block.size() / INSN_SIZE;
		block.resize(block.size() + INSN_SIZE, 0);
		block[pc * INSN_SIZE] = code;
		set_dst_reg(block, pc, dst);
		set_src_reg(block, pc, src);
		write_off(block, pc, off);
		write_imm(block, pc, imm);
	};
	size_t pos = 0;
	for (; pos + 4 <= value.size(); pos += 4) {
		int32_t imm = 0;
		std::memcpy(&imm, value.data() + pos, sizeof(imm));
		append(BPF_ST_MEM_W, 10, 0,
		       static_cast<int16_t>(slot + static_cast<int16_t>(pos)),
		       imm);
	}
	for (; pos < value.size(); pos++) {
		append(BPF_ST_MEM_B, 10, 0,
		       static_cast<int16_t>(slot + static_cast<int16_t>(pos)),
		       value[pos]);
	}
	append(BPF_ALU64_MOV_X, 0, 10, 0, 0);
	append(BPF_ALU64_ADD_K, 0, 0, 0, slot);
	return block;
}

std::vector<InlineRecord> apply_map_inline_hints(std::vector<uint8_t> &text,
						 const Cli &cli)
{
	const auto args = parse_map_inline_args(cli.pass_args);
	if (args.hints.empty()) {
		return {};
	}
	const auto snapshot = read_map_snapshot(args);
	std::map<uint32_t, InlineHint> hints_by_map;
	for (const auto &hint : args.hints) {
		const auto id = snapshot.map_id_by_name.find(hint.map_name);
		if (id == snapshot.map_id_by_name.end()) {
			throw std::runtime_error("map_inline hint map not found: " +
						 hint.map_name);
		}
		hints_by_map[id->second] = hint;
	}
	struct PendingInline {
		size_t call_pc;
		std::optional<size_t> null_pc;
		std::vector<uint8_t> block;
		InlineRecord record;
	};
	std::vector<PendingInline> pending;
	auto used_stack = stack_bytes_used(text);
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (text[pc * INSN_SIZE] != BPF_CALL ||
		    src_reg(text, pc) != 0 || read_imm(text, pc) != 1) {
			continue;
		}
		const auto map_id = map_id_for_lookup(text, pc, args.map_ids);
		if (!map_id) {
			continue;
		}
		const auto hint = hints_by_map.find(*map_id);
		if (hint == hints_by_map.end()) {
			continue;
		}
		const auto map = snapshot.maps.find(*map_id);
		if (map == snapshot.maps.end()) {
			throw std::runtime_error("map_inline map metadata missing");
		}
		if (hint->second.key.size() != map->second.key_size) {
			throw std::runtime_error("map_inline hint key size mismatch");
		}
		auto value = lookup_snapshot_value(snapshot, *map_id,
						   hint->second.key);
		if (!value) {
			throw std::runtime_error(
				"map_inline hint key is not present in snapshot");
		}
		const int16_t slot = allocate_stack_slot(used_stack, value->size());
		std::optional<size_t> null_pc;
		if (pc + 1 < insn_count &&
		    (text[(pc + 1) * INSN_SIZE] == BPF_JEQ_K ||
		     text[(pc + 1) * INSN_SIZE] == BPF_JNE_K) &&
		    dst_reg(text, pc + 1) == 0 &&
		    src_reg(text, pc + 1) == 0 &&
		    read_imm(text, pc + 1) == 0) {
			null_pc = pc + 1;
		}
		pending.push_back({ pc, null_pc,
				    build_stack_value_block(*value, slot),
				    { *map_id, hint->second.key, *value } });
	}

	std::vector<InlineRecord> records;
	for (auto it = pending.rbegin(); it != pending.rend(); ++it) {
		write_noop(text, it->call_pc);
		if (it->null_pc) {
			if (text[*it->null_pc * INSN_SIZE] == BPF_JNE_K) {
				const int64_t target =
					static_cast<int64_t>(*it->null_pc) + 1 +
					static_cast<int64_t>(read_off(text, *it->null_pc));
				const size_t begin = *it->null_pc + 1;
				if (target <= static_cast<int64_t>(begin) ||
				    target > static_cast<int64_t>(text.size() / INSN_SIZE)) {
					throw std::runtime_error(
						"map_inline unsupported JNE null-check shape");
				}
				delete_insns_adjusting_jumps(text, begin,
							    static_cast<size_t>(target));
				write_noop(text, *it->null_pc);
			} else {
				write_noop(text, *it->null_pc);
			}
		}
		insert_insns_adjusting_jumps(text, it->call_pc, it->block);
		records.push_back(it->record);
	}
	std::reverse(records.begin(), records.end());
	return records;
}

uint32_t module_fd_array_base(size_t map_count)
{
	if (map_count > std::numeric_limits<uint32_t>::max()) {
		throw std::runtime_error("map count exceeds u32");
	}
	return std::max<uint32_t>(static_cast<uint32_t>(map_count), 1);
}

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
		auto map_inlined = input;
		inlined = apply_map_inline_hints(map_inlined, cli);
		output = run_llvm_roundtrip(map_inlined, true);
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
