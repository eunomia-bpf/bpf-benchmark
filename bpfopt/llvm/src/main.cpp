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

namespace {

constexpr uint8_t BPF_LD_IMM64 = 0x18;
constexpr uint8_t BPF_CALL = 0x85;
constexpr uint8_t BPF_CALLX = BPF_CALL | 0x08;
constexpr uint8_t BPF_PSEUDO_MAP_FD = 1;
constexpr uint8_t BPF_PSEUDO_MAP_VALUE = 2;
constexpr uint8_t BPF_PSEUDO_MAP_IDX = 5;
constexpr uint8_t BPF_PSEUDO_MAP_IDX_VALUE = 6;
constexpr uint8_t BPF_PSEUDO_CALL = 1;
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

void write_imm(std::vector<uint8_t> &insns, size_t pc, int32_t imm)
{
	std::memcpy(&insns[pc * INSN_SIZE + 4], &imm, sizeof(imm));
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

bool patch_call_symbol(std::vector<uint8_t> &text, size_t pc,
		       std::string_view name)
{
	constexpr std::string_view prefix = "__llvmbpf_pseudo_call_pc_";
	if (!name.starts_with(prefix)) {
		return false;
	}
	const uint32_t target = parse_hex_u32(name.substr(prefix.size()));
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

void apply_one_relocation(llvm::object::ObjectFile &object,
			  const llvm::object::RelocationRef &reloc,
			  std::vector<uint8_t> &text)
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
		   !patch_call_symbol(text, pc, name)) {
		throw std::runtime_error("unsupported relocation symbol " +
					 name + " at offset " +
					 std::to_string(reloc.getOffset()) +
					 " pc " + std::to_string(pc));
	}
}

void apply_text_relocations(llvm::object::ObjectFile &object,
			    std::vector<uint8_t> &text)
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
			apply_one_relocation(object, reloc, text);
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

std::vector<uint8_t>
extract_relocated_text(const std::vector<uint8_t> &object_bytes)
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
	apply_text_relocations(*object, text);
	return text;
}

std::unique_ptr<llvm::TargetMachine> create_bpf_target_machine()
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
					    std::nullopt));
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
		llvm::OptimizationLevel::O2);
	pipeline.run(module, module_am);
}

std::vector<uint8_t> emit_bpf_object(llvm::Module &module)
{
	auto machine = create_bpf_target_machine();
	module.setTargetTriple("bpfel");
	module.setDataLayout(machine->createDataLayout());
	optimize_module(module, *machine);

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

std::vector<uint8_t> run_llvm_roundtrip(const std::vector<uint8_t> &input)
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
	auto module = context.generateModule(helper_symbols(input), {}, false);
	if (!module) {
		throw std::runtime_error(llvm_error_string(module.takeError()));
	}
	return module->withModuleDo([&](llvm::Module &module) {
		return extract_relocated_text(emit_bpf_object(module));
	});
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
		  const std::vector<uint8_t> &output)
{
	if (!cli.report) {
		return;
	}
	const bool changed = input != output;
	llvm::json::Object report{
		{ "pass", *cli.pass },
		{ "sites_applied", changed ? 1 : 0 },
		{ "sites_matched", changed ? 1 : 0 },
		{ "sites_skipped", 0 },
		{ "skip_reasons", llvm::json::Object{} },
		{ "skipped_sites", llvm::json::Array{} },
		{ "diagnostics", llvm::json::Array{} },
		{ "insn_count_before", input.size() / INSN_SIZE },
		{ "insn_count_after", output.size() / INSN_SIZE },
		{ "insn_delta",
		  static_cast<int64_t>(output.size() / INSN_SIZE) -
			  static_cast<int64_t>(input.size() / INSN_SIZE) },
		{ "inlined_map_entries", llvm::json::Array{} },
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
	const auto output = run_llvm_roundtrip(input);
	write_all(cli.output, output);
	write_report(cli, input, output);
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
