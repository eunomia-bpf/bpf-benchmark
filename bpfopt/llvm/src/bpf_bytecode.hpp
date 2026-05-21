// SPDX-License-Identifier: MIT
// Part of bpfopt-llvm. Included inside the anonymous namespace of main.cpp,
// which supplies the system/LLVM include prelude. Not standalone-compilable.

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
