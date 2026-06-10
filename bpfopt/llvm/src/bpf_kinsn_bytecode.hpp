// SPDX-License-Identifier: MIT
// Bytecode-level kinsn recovery for patterns that do not survive cleanly as
// LLVM MachineInstr trees. Included inside main.cpp's anonymous namespace.

constexpr uint8_t BPF_LDX_MEM_MODE = 0x60;
constexpr uint8_t BPF_STXW = 0x63;
constexpr uint8_t BPF_STXH = 0x6b;
constexpr uint8_t BPF_STXB = 0x73;
constexpr uint8_t BPF_STW = 0x62;
constexpr uint8_t BPF_STH = 0x6a;
constexpr uint8_t BPF_STB = 0x72;
constexpr uint8_t BPF_STDW = 0x7a;
constexpr uint8_t BPF_MOV32_K = 0xb4;
constexpr uint8_t BPF_ADD64_K = 0x07;
constexpr uint8_t BPF_ADD64_X = 0x0f;
constexpr uint8_t BPF_SUB64_K = 0x17;
constexpr uint8_t BPF_SUB64_X = 0x1f;
constexpr uint8_t BPF_MUL64_X = 0x2f;
constexpr uint8_t BPF_LSH32_K = 0x64;
constexpr uint8_t BPF_LSH32_X = 0x6c;
constexpr uint8_t BPF_LSH64_X = 0x6f;
constexpr uint8_t BPF_RSH32_K = 0x74;
constexpr uint8_t BPF_RSH32_X = 0x7c;
constexpr uint8_t BPF_RSH64_X = 0x7f;
constexpr uint8_t BPF_AND32_X = 0x5c;
constexpr uint8_t BPF_OR32_X = 0x4c;
constexpr uint8_t BPF_XOR32_K = 0xa4;
constexpr uint8_t BPF_NEG64 = 0x87;
constexpr uint8_t BPF_JNE64_K = 0x55;
constexpr uint8_t BPF_JEQ32_K = 0x16;
constexpr uint8_t BPF_JNE32_K = 0x56;
constexpr uint8_t BPF_END_BE = 0xdc;
constexpr uint8_t BPF_END_LE = 0xd4;
constexpr uint8_t BPF_SRC_X = 0x08;
constexpr uint8_t BPF_OP_MASK = 0xf0;
constexpr uint8_t BPF_NEG_OP = 0x80;
constexpr uint8_t BPF_MOV_OP = 0xb0;
constexpr uint8_t BPF_END_OP = 0xd0;
constexpr int32_t BPF_FUNC_map_lookup_elem = 1;
constexpr uint8_t X86_FORM_RR = 1;
constexpr uint8_t X86_FORM_IMM = 2;
constexpr uint8_t X86_FORM_MEM = 4;
constexpr uint8_t X86_FORM_STORE = 6;
constexpr uint8_t X86_FORM_STORE_IMM = 7;
constexpr uint8_t X86_ROTATE_PROOF_SCRATCH0 = 6;
constexpr uint8_t X86_ROTATE_PROOF_SCRATCH1 = 7;
constexpr uint8_t X86_ROTATE_PROOF_SCRATCH2 = 8;

bool target_has_kinsn(const KinsnTargetMap &targets, std::string_view name)
{
	return targets.find(std::string(name)) != targets.end();
}

bool target_is_x86_kinsn_set(const KinsnTargetMap &targets)
{
	return target_has_kinsn(targets, "bpf_x86_movq") ||
	       target_has_kinsn(targets, "bpf_x86_rorxl") ||
	       target_has_kinsn(targets, "bpf_x86_movbe32");
}

bool target_is_arm64_kinsn_set(const KinsnTargetMap &targets)
{
	return target_has_kinsn(targets, "bpf_arm64_extr_x") ||
	       target_has_kinsn(targets, "bpf_arm64_rev_x") ||
	       target_has_kinsn(targets, "bpf_arm64_ubfm_x");
}

uint64_t pack_u4(uint64_t value, unsigned shift)
{
	if (value > 0xf) {
		throw std::runtime_error("kinsn payload nibble overflow");
	}
	return value << shift;
}

uint64_t pack_u8(uint64_t value, unsigned shift)
{
	if (value > 0xff) {
		throw std::runtime_error("kinsn payload byte overflow");
	}
	return value << shift;
}

uint64_t pack_u16(uint64_t value, unsigned shift)
{
	if (value > 0xffff) {
		throw std::runtime_error("kinsn payload u16 overflow");
	}
	return value << shift;
}

uint64_t pack_u32(uint64_t value, unsigned shift)
{
	if (value > 0xffffffffULL) {
		throw std::runtime_error("kinsn payload u32 overflow");
	}
	return value << shift;
}

uint64_t pack_x86_rotate_payload(uint8_t dst, uint8_t src, uint8_t shift)
{
	return pack_u4(X86_FORM_IMM, 0) | pack_u4(dst, 4) |
	       pack_u4(src, 8) | pack_u8(shift, 12);
}

uint64_t pack_x86_reg_imm_payload(uint8_t dst, uint8_t imm)
{
	return pack_u4(X86_FORM_IMM, 0) | pack_u4(dst, 4) |
	       pack_u8(imm, 8);
}

uint64_t pack_x86_mov_rr_payload(uint8_t dst, uint8_t src)
{
	return pack_u4(X86_FORM_RR, 0) | pack_u4(dst, 4) |
	       pack_u4(src, 8);
}

uint64_t pack_x86_mem_payload(uint8_t dst, uint8_t base, int16_t off)
{
	return pack_u4(X86_FORM_MEM, 0) | pack_u4(dst, 4) |
	       pack_u4(base, 8) |
	       pack_u16(static_cast<uint16_t>(off), 12);
}

uint64_t pack_x86_store_reg_payload(uint8_t src, uint8_t base, int16_t off)
{
	return pack_u4(X86_FORM_STORE, 0) | pack_u4(src, 4) |
	       pack_u4(base, 8) |
	       pack_u16(static_cast<uint16_t>(off), 12);
}

uint64_t pack_x86_store_imm_payload(uint8_t base, int16_t off, uint32_t imm)
{
	return pack_u4(X86_FORM_STORE_IMM, 0) | pack_u4(base, 4) |
	       pack_u16(static_cast<uint16_t>(off), 8) |
	       pack_u32(imm, 24);
}

uint64_t pack_x86_bextr_payload(uint8_t dst, uint8_t src, uint8_t ctl)
{
	return pack_u4(dst, 0) | pack_u4(src, 4) | pack_u4(ctl, 8);
}

uint64_t pack_x86_shd_payload(uint8_t dst, uint8_t src, uint8_t shift)
{
	return pack_u4(dst, 0) | pack_u4(src, 4) | pack_u8(shift, 8);
}

uint64_t pack_x86_bmi1_payload(uint8_t dst, uint8_t src)
{
	return pack_u4(dst, 0) | pack_u4(src, 4);
}

uint64_t pack_x86_bmi2_shift_payload(uint8_t dst, uint8_t src, uint8_t cnt)
{
	return pack_u4(dst, 0) | pack_u4(src, 4) | pack_u4(cnt, 8);
}

uint64_t pack_x86_bzhi_payload(uint8_t dst, uint8_t src, uint8_t cnt)
{
	return pack_x86_bmi2_shift_payload(dst, src, cnt);
}

uint64_t pack_x86_popcnt_payload(uint8_t dst, uint8_t src)
{
	return pack_u4(X86_FORM_RR, 0) | pack_u4(dst, 4) |
	       pack_u4(src, 8);
}

uint64_t pack_arm64_rotate_payload(uint8_t dst, uint8_t src, uint8_t tmp,
				   uint8_t shift)
{
	return pack_u4(dst, 0) | pack_u4(src, 4) | pack_u8(shift, 8) |
	       pack_u4(tmp, 16);
}

uint64_t pack_arm64_extract_payload(uint8_t dst, uint8_t start,
				    uint8_t bit_len)
{
	return pack_u4(dst, 0) | pack_u8(start, 8) | pack_u8(bit_len, 16);
}

uint64_t pack_arm64_pair_payload(uint8_t lane0, uint8_t lane1, uint8_t base,
				 int16_t off)
{
	return pack_u4(lane0, 0) | pack_u4(lane1, 4) | pack_u4(base, 8) |
	       pack_u16(static_cast<uint16_t>(off), 12);
}

uint64_t pack_arm64_mem_payload(uint8_t reg, uint8_t base, int16_t off)
{
	return pack_u4(reg, 0) | pack_u4(base, 4) |
	       pack_u16(static_cast<uint16_t>(off), 8);
}

uint64_t pack_arm64_csel_payload(uint8_t dst, uint8_t true_reg,
				 uint8_t false_reg, uint8_t cond_reg)
{
	return pack_u4(dst, 0) | pack_u4(true_reg, 4) |
	       pack_u4(false_reg, 8) | pack_u4(cond_reg, 12);
}

uint64_t pack_arm64_ccmp_payload(uint8_t reg, uint8_t mode)
{
	return pack_u4(reg, 0) | pack_u4(mode, 4);
}

uint64_t pack_arm64_cset_payload(uint8_t dst, uint8_t count, uint8_t mode,
				 bool width32, const std::vector<uint8_t> &regs)
{
	if (count < 2 || count > 4 || regs.size() != count) {
		throw std::runtime_error("invalid arm64 ccmp term count");
	}
	uint64_t payload = pack_u4(dst, 0) |
			   pack_u4(static_cast<uint8_t>(count - 2), 4) |
			   pack_u4(mode, 6) |
			   pack_u4(width32 ? 1 : 0, 7);
	for (size_t i = 0; i < regs.size(); i++) {
		payload |= pack_u4(regs[i], 8 + static_cast<unsigned>(4 * i));
	}
	return payload;
}

void append_kinsn_pair(std::vector<uint8_t> &out, const KinsnTargetMap &targets,
		       std::string_view name, uint64_t payload)
{
	if (payload >> 52) {
		throw std::runtime_error("kinsn payload exceeds sidecar capacity");
	}
	const auto target = targets.find(std::string(name));
	if (target == targets.end()) {
		throw std::runtime_error("target.json has no kinsn entry for " +
					 std::string(name));
	}

	const auto sidecar = make_bpf_insn(
		BPF_MOV64_K, static_cast<uint8_t>(payload & 0xf),
		BPF_PSEUDO_KINSN_SIDECAR,
		static_cast<int16_t>((payload >> 4) & 0xffff),
		static_cast<int32_t>((payload >> 20) & 0xffffffffULL));
	const auto call = make_bpf_insn(BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL,
				       target->second.call_offset,
				       target->second.btf_func_id);
	out.insert(out.end(), sidecar.begin(), sidecar.end());
	out.insert(out.end(), call.begin(), call.end());
}

bool is_relative_target_insn(const std::vector<uint8_t> &bytes, size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	return opcode == BPF_JA || is_conditional_jump(opcode) ||
	       ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
		src_reg(bytes, pc) == BPF_PSEUDO_CALL) ||
	       (opcode == BPF_LD_IMM64 &&
		src_reg(bytes, pc) == BPF_PSEUDO_FUNC);
}

std::optional<int64_t> relative_target_pc(const std::vector<uint8_t> &bytes,
					  size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode == BPF_JA || is_conditional_jump(opcode)) {
		return static_cast<int64_t>(pc) + 1 +
		       static_cast<int64_t>(read_off(bytes, pc));
	}
	if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
	    src_reg(bytes, pc) == BPF_PSEUDO_CALL) {
		return static_cast<int64_t>(pc) + 1 +
		       static_cast<int64_t>(read_imm(bytes, pc));
	}
	if (opcode == BPF_LD_IMM64 &&
	    src_reg(bytes, pc) == BPF_PSEUDO_FUNC) {
		return static_cast<int64_t>(pc) + 1 +
		       static_cast<int64_t>(read_imm(bytes, pc));
	}
	return std::nullopt;
}

void write_relative_target_pc(std::vector<uint8_t> &bytes, size_t pc,
			      int64_t target)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const int64_t rel = target - static_cast<int64_t>(pc) - 1;
	if (opcode == BPF_JA || is_conditional_jump(opcode)) {
		if (rel < std::numeric_limits<int16_t>::min() ||
		    rel > std::numeric_limits<int16_t>::max()) {
			throw std::runtime_error("rewritten branch offset out of range");
		}
		write_off(bytes, pc, static_cast<int16_t>(rel));
		return;
	}
	if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
	    src_reg(bytes, pc) == BPF_PSEUDO_CALL) {
		if (rel < std::numeric_limits<int32_t>::min() ||
		    rel > std::numeric_limits<int32_t>::max()) {
			throw std::runtime_error("rewritten call offset out of range");
		}
		write_imm(bytes, pc, static_cast<int32_t>(rel));
		return;
	}
	if (opcode == BPF_LD_IMM64 &&
	    src_reg(bytes, pc) == BPF_PSEUDO_FUNC) {
		if (rel < std::numeric_limits<int32_t>::min() ||
		    rel > std::numeric_limits<int32_t>::max()) {
			throw std::runtime_error("rewritten function offset out of range");
		}
		write_imm(bytes, pc, static_cast<int32_t>(rel));
		return;
	}
	throw std::runtime_error("instruction has no relative target");
}

bool range_splits_ldimm64(const std::vector<uint8_t> &bytes, size_t start,
			  size_t old_len)
{
	const size_t end = start + old_len;
	if (start > 0 && is_ldimm64(bytes, start - 1)) {
		return true;
	}
	for (size_t pc = start; pc < end; pc++) {
		if (is_ldimm64(bytes, pc) && pc + 1 >= end) {
			return true;
		}
	}
	return false;
}

bool range_has_interior_target(const std::vector<uint8_t> &bytes, size_t start,
			       size_t old_len)
{
	if (old_len <= 1) {
		return false;
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const auto target = relative_target_pc(bytes, pc);
		if (!target) {
			continue;
		}
		if (*target < 0 || *target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("relative target out of range");
		}
		const size_t target_pc = static_cast<size_t>(*target);
		if (target_pc > start && target_pc < start + old_len) {
			return true;
		}
	}
	return false;
}

bool range_is_replaceable(const std::vector<uint8_t> &bytes, size_t start,
			  size_t old_len)
{
	if (start + old_len > bytes.size() / INSN_SIZE) {
		return false;
	}
	return !range_splits_ldimm64(bytes, start, old_len) &&
	       !range_has_interior_target(bytes, start, old_len);
}

void replace_insn_range(std::vector<uint8_t> &bytes, size_t start,
			size_t old_len, const std::vector<uint8_t> &replacement)
{
	if (bytes.size() % INSN_SIZE != 0 ||
	    replacement.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t old_count = bytes.size() / INSN_SIZE;
	const size_t repl_count = replacement.size() / INSN_SIZE;
	if (start > old_count || start + old_len > old_count) {
		throw std::runtime_error("replacement range out of bounds");
	}
	if (old_len == 0 && repl_count == 0) {
		return;
	}
	if (!range_is_replaceable(bytes, start, old_len)) {
		throw std::runtime_error("replacement range is not CFG-safe");
	}

	const int64_t delta = static_cast<int64_t>(repl_count) -
			      static_cast<int64_t>(old_len);
	const size_t new_count = old_count - old_len + repl_count;
	std::vector<uint8_t> rewritten;
	rewritten.reserve(new_count * INSN_SIZE);
	rewritten.insert(rewritten.end(), bytes.begin(),
			 bytes.begin() + start * INSN_SIZE);
	rewritten.insert(rewritten.end(), replacement.begin(), replacement.end());
	rewritten.insert(rewritten.end(),
			 bytes.begin() + (start + old_len) * INSN_SIZE,
			 bytes.end());

	auto map_old_pc = [&](size_t pc) -> size_t {
		if (old_len == 0) {
			return pc < start ? pc : pc + repl_count;
		}
		if (pc < start) {
			return pc;
		}
		if (pc >= start + old_len) {
			return static_cast<size_t>(static_cast<int64_t>(pc) + delta);
		}
		if (pc == start) {
			return start;
		}
		throw std::runtime_error("relative target points inside replacement range");
	};

	for (size_t old_pc = 0; old_pc < old_count; old_pc++) {
		if (old_len > 0 && old_pc >= start && old_pc < start + old_len) {
			continue;
		}
		const auto target = relative_target_pc(bytes, old_pc);
		if (!target) {
			continue;
		}
		if (*target < 0 || *target >= static_cast<int64_t>(old_count)) {
			throw std::runtime_error("relative target out of range");
		}
		const size_t new_pc = map_old_pc(old_pc);
		size_t new_target;
		if (old_len == 0) {
			const size_t target_pc = static_cast<size_t>(*target);
			new_target = target_pc < start ? target_pc :
				     target_pc + repl_count;
		} else {
			new_target = map_old_pc(static_cast<size_t>(*target));
		}
		write_relative_target_pc(rewritten, new_pc,
					 static_cast<int64_t>(new_target));
	}

	bytes.swap(rewritten);
}

bool is_ldx_mem_opcode(uint8_t opcode)
{
	return opcode == BPF_LDXB || opcode == BPF_LDXH ||
	       opcode == BPF_LDXW || opcode == BPF_LDXDW;
}

bool is_stx_mem_opcode(uint8_t opcode)
{
	return opcode == BPF_STXB || opcode == BPF_STXH ||
	       opcode == BPF_STXW || opcode == BPF_STXDW;
}

bool is_st_mem_opcode(uint8_t opcode)
{
	return opcode == BPF_STB || opcode == BPF_STH ||
	       opcode == BPF_STW || opcode == BPF_STDW;
}

bool insn_uses_reg(const std::vector<uint8_t> &bytes, size_t pc, uint8_t reg)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	const uint8_t dst = dst_reg(bytes, pc);
	const uint8_t src = src_reg(bytes, pc);
	if (klass == BPF_LDX_CLASS) {
		return src == reg;
	}
	if (klass == BPF_STX_CLASS) {
		return dst == reg || src == reg;
	}
	if (klass == BPF_ST_CLASS) {
		return dst == reg;
	}
	if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
	    src_reg(bytes, pc) != BPF_PSEUDO_CALL) {
		return reg >= 1 && reg <= 5;
	}
	if (opcode == BPF_EXIT) {
		return reg == 0;
	}
	if (klass == BPF_ALU_CLASS || klass == BPF_ALU64_CLASS) {
		const uint8_t op = opcode & BPF_OP_MASK;
		if (op == BPF_MOV_OP) {
			return (opcode & BPF_SRC_X) && src == reg;
		}
		if (op == BPF_NEG_OP || op == BPF_END_OP) {
			return dst == reg;
		}
		return dst == reg || ((opcode & BPF_SRC_X) && src == reg);
	}
	if (klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS) {
		if (opcode == BPF_JA) {
			return false;
		}
		return dst == reg || ((opcode & BPF_SRC_X) && src == reg);
	}
	return false;
}

bool insn_writes_reg(const std::vector<uint8_t> &bytes, size_t pc, uint8_t reg)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	if (opcode == BPF_CALL || opcode == BPF_CALLX) {
		return reg <= 5;
	}
	if ((klass == BPF_LD_CLASS && opcode == BPF_LD_IMM64) ||
	    klass == BPF_LDX_CLASS || klass == BPF_ALU_CLASS ||
	    klass == BPF_ALU64_CLASS) {
		return dst_reg(bytes, pc) == reg;
	}
	return false;
}

std::vector<size_t> liveness_successors(const std::vector<uint8_t> &bytes,
					size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode == BPF_EXIT) {
		return {};
	}
	if (opcode == BPF_JA) {
		const auto target = relative_target_pc(bytes, pc);
		if (!target || *target < 0 ||
		    *target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("branch target out of range");
		}
		return { static_cast<size_t>(*target) };
	}
	if (is_conditional_jump(opcode)) {
		const auto target = relative_target_pc(bytes, pc);
		if (!target || *target < 0 ||
		    *target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("branch target out of range");
		}
		std::vector<size_t> out{ static_cast<size_t>(*target) };
		if (pc + 1 < insn_count) {
			out.push_back(pc + 1);
		}
		return out;
	}
	if (opcode == BPF_LD_IMM64) {
		return pc + 2 < insn_count ? std::vector<size_t>{ pc + 2 } :
					     std::vector<size_t>{};
	}
	return pc + 1 < insn_count ? std::vector<size_t>{ pc + 1 } :
				     std::vector<size_t>{};
}

bool reg_read_before_write_on_any_path_after(const std::vector<uint8_t> &bytes,
					     size_t pc, uint8_t reg)
{
	if (bytes.size() % INSN_SIZE != 0) {
		throw std::runtime_error("bytecode length is not a multiple of 8 bytes");
	}
	const size_t insn_count = bytes.size() / INSN_SIZE;
	std::deque<size_t> worklist;
	std::vector<uint8_t> visited(insn_count, 0);
	if (pc < insn_count) {
		worklist.push_back(pc);
	}
	while (!worklist.empty()) {
		const size_t cur = worklist.front();
		worklist.pop_front();
		if (cur >= insn_count || visited[cur]) {
			continue;
		}
		visited[cur] = 1;
		if (insn_uses_reg(bytes, cur, reg)) {
			return true;
		}
		if (insn_writes_reg(bytes, cur, reg)) {
			continue;
		}
		for (const size_t succ : liveness_successors(bytes, cur)) {
			if (succ < insn_count && !visited[succ]) {
				worklist.push_back(succ);
			}
		}
	}
	return false;
}

std::optional<uint64_t> const_reg_value_before(const std::vector<uint8_t> &bytes,
					       size_t pc, uint8_t reg)
{
	size_t scan = pc;
	while (scan > 0) {
		scan--;
		if (!insn_writes_reg(bytes, scan, reg)) {
			continue;
		}
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		if (opcode == BPF_LD_IMM64) {
			return read_ldimm64_u64(bytes, scan);
		}
		if (opcode == BPF_MOV64_K || opcode == BPF_MOV32_K) {
			return static_cast<uint32_t>(read_imm(bytes, scan));
		}
		return std::nullopt;
	}
	return std::nullopt;
}

enum class RotateWidth { W32, W64 };

unsigned rotate_width_bits(RotateWidth width)
{
	return width == RotateWidth::W32 ? 32 : 64;
}

bool is_reg_mov_for_width(const std::vector<uint8_t> &bytes, size_t pc,
			  RotateWidth width)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	return opcode == BPF_MOV64_X ||
	       (width == RotateWidth::W32 && opcode == BPF_MOV32_X);
}

bool is_lsh_imm_for_width(uint8_t opcode, RotateWidth width)
{
	return width == RotateWidth::W32 ? opcode == BPF_LSH32_K :
					   opcode == BPF_LSH64_K;
}

bool is_rsh_imm_for_width(uint8_t opcode, RotateWidth width)
{
	return width == RotateWidth::W32 ? opcode == BPF_RSH32_K :
					   opcode == BPF_RSH64_K;
}

bool is_or_reg_for_width(uint8_t opcode, RotateWidth width)
{
	return width == RotateWidth::W32 ? opcode == BPF_OR32_X :
					   opcode == BPF_OR64_X;
}

bool checked_shift_pair(const std::vector<uint8_t> &bytes, size_t lhs,
			size_t rhs, RotateWidth width, uint32_t &lsh_amount,
			uint8_t &lsh_reg, uint8_t &rsh_reg)
{
	const uint8_t lhs_op = bytes[lhs * INSN_SIZE];
	const uint8_t rhs_op = bytes[rhs * INSN_SIZE];
	uint32_t rsh_amount = 0;
	if (is_rsh_imm_for_width(lhs_op, width) &&
	    is_lsh_imm_for_width(rhs_op, width)) {
		rsh_amount = static_cast<uint32_t>(read_imm(bytes, lhs));
		lsh_amount = static_cast<uint32_t>(read_imm(bytes, rhs));
		rsh_reg = dst_reg(bytes, lhs);
		lsh_reg = dst_reg(bytes, rhs);
	} else if (is_lsh_imm_for_width(lhs_op, width) &&
		   is_rsh_imm_for_width(rhs_op, width)) {
		lsh_amount = static_cast<uint32_t>(read_imm(bytes, lhs));
		rsh_amount = static_cast<uint32_t>(read_imm(bytes, rhs));
		lsh_reg = dst_reg(bytes, lhs);
		rsh_reg = dst_reg(bytes, rhs);
	} else {
		return false;
	}
	return lsh_amount != 0 && rsh_amount != 0 &&
	       lsh_amount + rsh_amount == rotate_width_bits(width) &&
	       lsh_reg != rsh_reg;
}

bool uses_both_regs(uint8_t dst, uint8_t src, uint8_t a, uint8_t b)
{
	return (dst == a && src == b) || (dst == b && src == a);
}

std::optional<uint64_t> and_mask_value(const std::vector<uint8_t> &bytes,
				       size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode == BPF_AND64_K) {
		return static_cast<uint32_t>(read_imm(bytes, pc));
	}
	if (opcode != BPF_AND64_X) {
		return std::nullopt;
	}
	return const_reg_value_before(bytes, pc, src_reg(bytes, pc));
}

std::optional<uint64_t> high32_rotate_mask(uint32_t rsh_amount)
{
	if (rsh_amount >= 32) {
		return std::nullopt;
	}
	return (uint64_t{ std::numeric_limits<uint32_t>::max() } << rsh_amount) &
	       std::numeric_limits<uint32_t>::max();
}

bool is_zero_extend32_pair(const std::vector<uint8_t> &bytes, size_t pc,
			   uint8_t reg)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	return pc + 1 < insn_count &&
	       bytes[pc * INSN_SIZE] == BPF_LSH64_K &&
	       dst_reg(bytes, pc) == reg && read_imm(bytes, pc) == 32 &&
	       bytes[(pc + 1) * INSN_SIZE] == BPF_RSH64_K &&
	       dst_reg(bytes, pc + 1) == reg && read_imm(bytes, pc + 1) == 32;
}

struct RotateSite {
	size_t start = 0;
	size_t old_len = 0;
	uint8_t dst = 0;
	uint8_t val = 0;
	uint8_t tmp = 0;
	uint32_t shift = 0;
	RotateWidth width = RotateWidth::W64;
	bool clobbers_tmp = true;
	bool preinit_proof_scratch = false;
};

std::optional<RotateSite> make_rotate_site(size_t start, size_t old_len,
					   uint8_t dst, uint8_t val,
					   uint8_t tmp, uint32_t shift,
					   RotateWidth width)
{
	if (dst == tmp || val == tmp || shift > 255) {
		return std::nullopt;
	}
	return RotateSite{ start, old_len, dst, val, tmp, shift, width, true };
}

std::optional<RotateSite> match_split_copy_rotate(const std::vector<uint8_t> &bytes,
						  size_t pc,
						  RotateWidth width)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 5 > insn_count || !is_reg_mov_for_width(bytes, pc, width) ||
	    !is_reg_mov_for_width(bytes, pc + 2, width)) {
		return std::nullopt;
	}
	const uint8_t val = src_reg(bytes, pc);
	if (src_reg(bytes, pc + 2) != val) {
		return std::nullopt;
	}
	const uint8_t reg0 = dst_reg(bytes, pc);
	const uint8_t reg1 = dst_reg(bytes, pc + 2);
	if (reg0 == reg1 || dst_reg(bytes, pc + 1) != reg0 ||
	    dst_reg(bytes, pc + 3) != reg1 ||
	    !is_or_reg_for_width(bytes[(pc + 4) * INSN_SIZE], width)) {
		return std::nullopt;
	}
	uint32_t lsh_amount = 0;
	uint8_t lsh_reg = 0;
	uint8_t rsh_reg = 0;
	if (!checked_shift_pair(bytes, pc + 1, pc + 3, width, lsh_amount,
				lsh_reg, rsh_reg)) {
		return std::nullopt;
	}
	if (!uses_both_regs(dst_reg(bytes, pc + 4), src_reg(bytes, pc + 4),
			    reg0, reg1)) {
		return std::nullopt;
	}
	return make_rotate_site(pc, 5, dst_reg(bytes, pc + 4), val,
				src_reg(bytes, pc + 4), lsh_amount, width);
}

std::optional<RotateSite> match_provenance_rotate(const std::vector<uint8_t> &bytes,
						  size_t pc,
						  RotateWidth width)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 3 > insn_count ||
	    !is_or_reg_for_width(bytes[(pc + 2) * INSN_SIZE], width)) {
		return std::nullopt;
	}
	uint32_t lsh_amount = 0;
	uint8_t lsh_reg = 0;
	uint8_t rsh_reg = 0;
	if (!checked_shift_pair(bytes, pc, pc + 1, width, lsh_amount, lsh_reg,
				rsh_reg)) {
		return std::nullopt;
	}
	if (!uses_both_regs(dst_reg(bytes, pc + 2), src_reg(bytes, pc + 2),
			    lsh_reg, rsh_reg)) {
		return std::nullopt;
	}
	if (pc == 0) {
		return std::nullopt;
	}
	for (auto [tmp, val] : { std::pair<uint8_t, uint8_t>{ rsh_reg, lsh_reg },
				 std::pair<uint8_t, uint8_t>{ lsh_reg, rsh_reg } }) {
		if (dst_reg(bytes, pc - 1) == tmp &&
		    src_reg(bytes, pc - 1) == val &&
		    is_reg_mov_for_width(bytes, pc - 1, width)) {
			return make_rotate_site(pc - 1, 4, dst_reg(bytes, pc + 2),
						val, tmp, lsh_amount, width);
		}
	}
	return std::nullopt;
}

std::optional<std::pair<size_t, bool>>
masked32_and_index(const std::vector<uint8_t> &bytes, size_t pc, uint8_t val,
		   uint8_t rsh_reg)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc >= insn_count) {
		return std::nullopt;
	}
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode == BPF_AND64_K || opcode == BPF_AND64_X) {
		return std::pair<size_t, bool>{ pc, false };
	}
	if (opcode != BPF_LD_IMM64 && opcode != BPF_MOV64_K &&
	    opcode != BPF_MOV32_K) {
		return std::nullopt;
	}
	const uint8_t mask_reg = dst_reg(bytes, pc);
	const size_t and_pc = opcode == BPF_LD_IMM64 ? pc + 2 : pc + 1;
	if (mask_reg == val || mask_reg == rsh_reg || and_pc >= insn_count) {
		return std::nullopt;
	}
	return (bytes[and_pc * INSN_SIZE] == BPF_AND64_X &&
		src_reg(bytes, and_pc) == mask_reg) ?
		       std::optional(std::pair<size_t, bool>{ and_pc, true }) :
		       std::nullopt;
}

std::optional<RotateSite> match_masked32_rotate(const std::vector<uint8_t> &bytes,
						size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 5 > insn_count || bytes[pc * INSN_SIZE] != BPF_MOV64_X) {
		return std::nullopt;
	}
	const uint8_t val = src_reg(bytes, pc);
	const uint8_t rsh_reg = dst_reg(bytes, pc);
	const auto and_info = masked32_and_index(bytes, pc + 1, val, rsh_reg);
	if (!and_info) {
		return std::nullopt;
	}
	const size_t and_pc = and_info->first;
	const bool preserves_mask_load = and_info->second;
	if (and_pc + 4 > insn_count ||
	    dst_reg(bytes, and_pc) != rsh_reg ||
	    bytes[(and_pc + 1) * INSN_SIZE] != BPF_RSH64_K ||
	    dst_reg(bytes, and_pc + 1) != rsh_reg) {
		return std::nullopt;
	}
	const uint32_t rsh_amount =
		static_cast<uint32_t>(read_imm(bytes, and_pc + 1));
	if (rsh_amount == 0 || rsh_amount >= 32) {
		return std::nullopt;
	}
	const auto expected_mask = high32_rotate_mask(rsh_amount);
	const auto actual_mask = and_mask_value(bytes, and_pc);
	if (!expected_mask || !actual_mask || *expected_mask != *actual_mask) {
		return std::nullopt;
	}

	size_t start = pc;
	size_t old_len = 0;
	size_t lsh_pc = 0;
	size_t or_pc = 0;
	uint8_t lsh_reg = 0;
	bool clobbers_tmp = true;
	if (bytes[(and_pc + 2) * INSN_SIZE] == BPF_MOV64_X) {
		if (src_reg(bytes, and_pc + 2) != val ||
		    and_pc + 5 > insn_count) {
			return std::nullopt;
		}
		lsh_reg = dst_reg(bytes, and_pc + 2);
		lsh_pc = and_pc + 3;
		or_pc = and_pc + 4;
		start = preserves_mask_load ? and_pc : pc;
		old_len = or_pc + 1 - start;
		clobbers_tmp = true;
	} else {
		if (and_pc + 6 > insn_count ||
		    !is_zero_extend32_pair(bytes, and_pc + 4, val)) {
			return std::nullopt;
		}
		lsh_reg = val;
		lsh_pc = and_pc + 2;
		or_pc = and_pc + 3;
		start = and_pc + 2;
		old_len = 2;
		clobbers_tmp = false;
	}

	if (rsh_reg == lsh_reg ||
	    bytes[lsh_pc * INSN_SIZE] != BPF_LSH64_K ||
	    dst_reg(bytes, lsh_pc) != lsh_reg ||
	    bytes[or_pc * INSN_SIZE] != BPF_OR64_X ||
	    !uses_both_regs(dst_reg(bytes, or_pc), src_reg(bytes, or_pc), lsh_reg,
			    rsh_reg)) {
		return std::nullopt;
	}
	const uint32_t lsh_amount = static_cast<uint32_t>(read_imm(bytes, lsh_pc));
	if (lsh_amount == 0 || lsh_amount + rsh_amount != 32) {
		return std::nullopt;
	}
	auto site = make_rotate_site(start, old_len, dst_reg(bytes, or_pc), val,
				     dst_reg(bytes, or_pc) == rsh_reg ? lsh_reg :
									 rsh_reg,
				     lsh_amount, RotateWidth::W32);
	if (site) {
		site->clobbers_tmp = clobbers_tmp;
	}
	return site;
}

std::optional<RotateSite> match_rotate_site(const std::vector<uint8_t> &bytes,
					    size_t pc)
{
	for (RotateWidth width : { RotateWidth::W64, RotateWidth::W32 }) {
		if (auto site = match_split_copy_rotate(bytes, pc, width)) {
			return site;
		}
	}
	if (auto site = match_masked32_rotate(bytes, pc)) {
		return site;
	}
	for (RotateWidth width : { RotateWidth::W64, RotateWidth::W32 }) {
		if (auto site = match_provenance_rotate(bytes, pc, width)) {
			return site;
		}
	}
	return std::nullopt;
}

uint8_t rotate_proof_scratch(const RotateSite &site)
{
	for (uint8_t reg : { X86_ROTATE_PROOF_SCRATCH0,
			     X86_ROTATE_PROOF_SCRATCH1,
			     X86_ROTATE_PROOF_SCRATCH2 }) {
		if (reg != site.dst && reg != site.val) {
			return reg;
		}
	}
	return X86_ROTATE_PROOF_SCRATCH0;
}

std::vector<uint8_t> emit_rotate_replacement(const KinsnTargetMap &targets,
					    const RotateSite &site,
					    KinsnTargetArch target_arch)
{
	std::vector<uint8_t> out;
	if (kinsn_target_arch_is_arm64(target_arch, targets)) {
		const char *name = site.width == RotateWidth::W64 ?
					   "bpf_arm64_extr_x" :
					   "bpf_arm64_extr_w";
		if (!target_has_kinsn(targets, name)) {
			return out;
		}
		append_kinsn_pair(out, targets, name,
				  pack_arm64_rotate_payload(
					  site.dst, site.val, site.tmp,
					  static_cast<uint8_t>(site.shift)));
		return out;
	}
	if (!kinsn_target_arch_is_x86(target_arch, targets)) {
		return out;
	}
	if (site.preinit_proof_scratch) {
		const auto init =
			make_bpf_insn(BPF_MOV64_K, rotate_proof_scratch(site), 0,
				      0, 0);
		out.insert(out.end(), init.begin(), init.end());
	}
	if (site.width == RotateWidth::W64) {
		if (site.dst != site.val) {
			append_kinsn_pair(out, targets, "bpf_x86_movq",
					  pack_x86_mov_rr_payload(site.dst,
								  site.val));
		}
		append_kinsn_pair(out, targets, "bpf_x86_rolq",
				  pack_x86_rotate_payload(
					  site.dst, site.dst,
					  static_cast<uint8_t>(site.shift)));
	} else {
		if (target_has_kinsn(targets, "bpf_x86_roll")) {
			if (site.dst != site.val) {
				const auto mov = make_bpf_insn(
					BPF_MOV32_X, site.dst, site.val, 0, 0);
				out.insert(out.end(), mov.begin(), mov.end());
			}
			append_kinsn_pair(out, targets, "bpf_x86_roll",
					  pack_x86_rotate_payload(
						  site.dst, site.dst,
						  static_cast<uint8_t>(
							  site.shift)));
		} else {
			append_kinsn_pair(out, targets, "bpf_x86_rorxl",
					  pack_x86_rotate_payload(
						  site.dst, site.val,
						  static_cast<uint8_t>(
							  site.shift)));
		}
	}
	return out;
}

std::vector<size_t> subprog_entry_pcs(const std::vector<uint8_t> &bytes)
{
	std::vector<size_t> entries{ 0 };
	const size_t insn_count = bytes.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		if ((opcode != BPF_CALL && opcode != BPF_CALLX) ||
		    src_reg(bytes, pc) != BPF_PSEUDO_CALL) {
			continue;
		}
		const auto target = relative_target_pc(bytes, pc);
		if (!target || *target < 0 ||
		    *target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error("BPF pseudo-call target out of range");
		}
		const auto target_pc = static_cast<size_t>(*target);
		if (std::find(entries.begin(), entries.end(), target_pc) ==
		    entries.end()) {
			entries.push_back(target_pc);
		}
	}
	return entries;
}

size_t function_entry_for_pc(const std::vector<size_t> &entries, size_t pc)
{
	size_t entry = 0;
	for (const size_t candidate : entries) {
		if (candidate <= pc && candidate >= entry) {
			entry = candidate;
		}
	}
	return entry;
}

bool reg_written_between(const std::vector<uint8_t> &bytes, size_t start,
			 size_t end, uint8_t reg)
{
	for (size_t pc = start; pc < end; pc++) {
		if (insn_writes_reg(bytes, pc, reg)) {
			return true;
		}
	}
	return false;
}

int64_t apply_rotate_bytecode_kinsns(std::vector<uint8_t> &bytes,
				     const KinsnTargetMap &targets,
				     KinsnTargetArch target_arch)
{
	std::vector<RotateSite> sites;
	const auto subprog_entries = subprog_entry_pcs(bytes);
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		auto site = match_rotate_site(bytes, pc);
		if (!site || !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}
		if (site->clobbers_tmp &&
		    reg_read_before_write_on_any_path_after(
			    bytes, site->start + site->old_len, site->tmp)) {
			pc++;
			continue;
		}
		const uint8_t proof_scratch = rotate_proof_scratch(*site);
		const size_t function_entry =
			function_entry_for_pc(subprog_entries, site->start);
		site->preinit_proof_scratch =
			!reg_written_between(bytes, function_entry, site->start,
					     proof_scratch);
		sites.push_back(*site);
		pc = site->start + site->old_len;
	}
	int64_t applied = 0;
	for (auto it = sites.rbegin(); it != sites.rend(); ++it) {
		const auto replacement =
			emit_rotate_replacement(targets, *it, target_arch);
		if (replacement.empty()) {
			continue;
		}
		replace_insn_range(bytes, it->start, it->old_len, replacement);
		applied++;
	}
	return applied;
}

std::optional<unsigned> low_mask_width(uint64_t mask)
{
	if (mask == 0) {
		return std::nullopt;
	}
	unsigned width = 0;
	while (width < 64 && (mask & 1)) {
		width++;
		mask >>= 1;
	}
	return mask == 0 ? std::optional(width) : std::nullopt;
}

std::optional<uint8_t> find_dead_scratch_reg_after(const std::vector<uint8_t> &bytes,
						   size_t pc,
						   std::initializer_list<uint8_t> exclude)
{
	for (uint8_t reg = 0; reg <= 9; reg++) {
		if (std::find(exclude.begin(), exclude.end(), reg) !=
		    exclude.end()) {
			continue;
		}
		if (!reg_read_before_write_on_any_path_after(bytes, pc, reg)) {
			return reg;
		}
	}
	return std::nullopt;
}

struct ShdSite {
	size_t start = 0;
	size_t old_len = 0;
	const char *name = nullptr;
	uint8_t dst = 0;
	uint8_t src = 0;
	uint8_t tmp = 0;
	uint8_t shift = 0;
};

const char *shd_name_for(bool left, RotateWidth width)
{
	if (left) {
		return width == RotateWidth::W64 ? "bpf_x86_shldq" :
						   "bpf_x86_shldl";
	}
	return width == RotateWidth::W64 ? "bpf_x86_shrdq" :
					   "bpf_x86_shrdl";
}

std::optional<ShdSite> match_shd_site(const std::vector<uint8_t> &bytes,
				      size_t pc, RotateWidth width)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	const uint8_t lsh_op =
		width == RotateWidth::W32 ? BPF_LSH32_K : BPF_LSH64_K;
	const uint8_t rsh_op =
		width == RotateWidth::W32 ? BPF_RSH32_K : BPF_RSH64_K;
	const uint8_t or_op =
		width == RotateWidth::W32 ? BPF_OR32_X : BPF_OR64_X;
	if (pc >= insn_count) {
		return std::nullopt;
	}
	size_t shift_pc = pc;
	uint8_t dst = dst_reg(bytes, pc);
	if (is_reg_mov_for_width(bytes, pc, width)) {
		if (pc + 5 > insn_count) {
			return std::nullopt;
		}
		shift_pc = pc + 1;
		dst = dst_reg(bytes, pc);
	} else if (pc + 4 > insn_count) {
		return std::nullopt;
	}
	const size_t mov_tmp_pc = shift_pc + 1;
	const size_t shift_tmp_pc = shift_pc + 2;
	const size_t or_pc = shift_pc + 3;
	if (!is_reg_mov_for_width(bytes, mov_tmp_pc, width) ||
	    bytes[or_pc * INSN_SIZE] != or_op ||
	    dst_reg(bytes, shift_pc) != dst ||
	    dst_reg(bytes, or_pc) != dst ||
	    src_reg(bytes, or_pc) != dst_reg(bytes, mov_tmp_pc)) {
		return std::nullopt;
	}
	const uint8_t tmp = dst_reg(bytes, mov_tmp_pc);
	const uint8_t src = src_reg(bytes, mov_tmp_pc);
	if (tmp == dst || tmp == src) {
		return std::nullopt;
	}
	const int width_bits = static_cast<int>(rotate_width_bits(width));
	const int dst_shift = read_imm(bytes, shift_pc);
	const int tmp_shift = read_imm(bytes, shift_tmp_pc);
	if (dst_shift <= 0 || dst_shift >= width_bits ||
	    tmp_shift <= 0 || tmp_shift >= width_bits ||
	    dst_shift + tmp_shift != width_bits) {
		return std::nullopt;
	}
	const uint8_t dst_shift_op = bytes[shift_pc * INSN_SIZE];
	const uint8_t tmp_shift_op = bytes[shift_tmp_pc * INSN_SIZE];
	const bool shld = dst_shift_op == lsh_op && tmp_shift_op == rsh_op;
	const bool shrd = dst_shift_op == rsh_op && tmp_shift_op == lsh_op;
	if (!shld && !shrd) {
		return std::nullopt;
	}
	const size_t start = shift_pc;
	const size_t old_len = or_pc + 1 - start;
	return ShdSite{ start, old_len, shd_name_for(shld, width), dst, src,
			tmp, static_cast<uint8_t>(dst_shift) };
}

int64_t apply_shd_bytecode_kinsns(std::vector<uint8_t> &bytes,
				  const KinsnTargetMap &targets,
				  KinsnTargetArch target_arch)
{
	if (!kinsn_target_arch_is_x86(target_arch, targets)) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		std::optional<ShdSite> site;
		for (RotateWidth width : { RotateWidth::W64, RotateWidth::W32 }) {
			site = match_shd_site(bytes, pc, width);
			if (site) {
				break;
			}
		}
		if (!site || !target_has_kinsn(targets, site->name) ||
		    !range_is_replaceable(bytes, site->start, site->old_len) ||
		    reg_read_before_write_on_any_path_after(
			    bytes, site->start + site->old_len, site->tmp)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, site->name,
				  pack_x86_shd_payload(site->dst, site->src,
						       site->shift));
		replace_insn_range(bytes, site->start, site->old_len,
				   replacement);
		applied++;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

std::optional<std::pair<uint8_t, uint8_t>>
extract_from_shifted_mask(uint64_t mask, int32_t shift)
{
	if (shift < 0 || shift >= 64) {
		return std::nullopt;
	}
	const uint64_t low_bits =
		shift == 0 ? 0 : ((uint64_t{ 1 } << shift) - 1);
	if (mask & low_bits) {
		return std::nullopt;
	}
	const auto bit_len = low_mask_width(mask >> shift);
	if (!bit_len || *bit_len == 0 ||
	    shift + static_cast<int32_t>(*bit_len) > 64 ||
	    (*bit_len > 32 && *bit_len != 64)) {
		return std::nullopt;
	}
	return std::pair<uint8_t, uint8_t>{ static_cast<uint8_t>(shift),
					    static_cast<uint8_t>(*bit_len) };
}

std::optional<uint64_t> extract_and_mask_value(const std::vector<uint8_t> &bytes,
					       size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode == BPF_AND64_K) {
		return static_cast<uint64_t>(
			static_cast<int64_t>(read_imm(bytes, pc)));
	}
	if (opcode != BPF_AND64_X) {
		return std::nullopt;
	}
	return const_reg_value_before(bytes, pc, src_reg(bytes, pc));
}

int64_t apply_extract_bytecode_kinsns(std::vector<uint8_t> &bytes,
				      const KinsnTargetMap &targets,
				      KinsnTargetArch target_arch)
{
	int64_t applied = 0;
	size_t pc = 0;
	if (kinsn_target_arch_is_x86(target_arch, targets)) {
		applied += apply_shd_bytecode_kinsns(bytes, targets,
						     target_arch);
	}
	while (pc + 1 < bytes.size() / INSN_SIZE) {
		if (dst_reg(bytes, pc) != dst_reg(bytes, pc + 1) ||
		    !range_is_replaceable(bytes, pc, 2)) {
			pc++;
			continue;
		}
		std::optional<std::pair<uint8_t, uint8_t>> extract;
		if (bytes[pc * INSN_SIZE] == BPF_RSH64_K) {
			if (const auto mask = extract_and_mask_value(bytes, pc + 1);
			    mask && (bytes[(pc + 1) * INSN_SIZE] == BPF_AND64_K ||
				     bytes[(pc + 1) * INSN_SIZE] == BPF_AND64_X)) {
				const auto bit_len = low_mask_width(*mask);
				const int32_t shift_imm = read_imm(bytes, pc);
				if (shift_imm >= 0 && shift_imm < 64 && bit_len &&
				    shift_imm + static_cast<int32_t>(*bit_len) <= 64 &&
				    (*bit_len <= 32 || *bit_len == 64)) {
					extract = std::pair<uint8_t, uint8_t>{
						static_cast<uint8_t>(shift_imm),
						static_cast<uint8_t>(*bit_len)
					};
				}
			}
		} else if ((bytes[pc * INSN_SIZE] == BPF_AND64_K ||
			    bytes[pc * INSN_SIZE] == BPF_AND64_X) &&
			   bytes[(pc + 1) * INSN_SIZE] == BPF_RSH64_K) {
			if (const auto mask = extract_and_mask_value(bytes, pc)) {
				extract = extract_from_shifted_mask(
					*mask, read_imm(bytes, pc + 1));
			}
		}
		if (!extract) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		const uint8_t dst = dst_reg(bytes, pc);
		if (kinsn_target_arch_is_arm64(target_arch, targets)) {
			if (!target_has_kinsn(targets, "bpf_arm64_ubfm_x")) {
				pc++;
				continue;
			}
			append_kinsn_pair(replacement, targets, "bpf_arm64_ubfm_x",
					  pack_arm64_extract_payload(
						  dst, extract->first,
						  extract->second));
		} else {
			if (!kinsn_target_arch_is_x86(target_arch, targets) ||
			    !target_has_kinsn(targets, "bpf_x86_bextrq")) {
				pc++;
				continue;
			}
			const auto ctl_reg =
				find_dead_scratch_reg_after(bytes, pc + 2, { dst });
			if (!ctl_reg) {
				pc++;
				continue;
			}
			const uint32_t ctl =
				static_cast<uint32_t>(extract->first) |
				(static_cast<uint32_t>(extract->second) << 8);
			const auto ctl_mov =
				make_bpf_insn(BPF_MOV64_K, *ctl_reg, 0, 0,
					      static_cast<int32_t>(ctl));
			replacement.insert(replacement.end(), ctl_mov.begin(),
					   ctl_mov.end());
			append_kinsn_pair(replacement, targets, "bpf_x86_bextrq",
					  pack_x86_bextr_payload(dst, dst,
								 *ctl_reg));
		}
		replace_insn_range(bytes, pc, 2, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
	}
	return applied;
}

struct Bmi1Site {
	size_t start = 0;
	size_t old_len = 0;
	const char *name = nullptr;
	uint8_t dst = 0;
	uint8_t src = 0;
	std::optional<uint8_t> dropped_copy_reg;
};

std::optional<Bmi1Site> match_bmi1_site(const std::vector<uint8_t> &bytes,
					size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 3 > insn_count || bytes[pc * INSN_SIZE] != BPF_MOV64_X) {
		return std::nullopt;
	}
	const uint8_t tmp = dst_reg(bytes, pc);
	const uint8_t src = src_reg(bytes, pc);
	if (tmp != src && dst_reg(bytes, pc + 1) == tmp &&
	    dst_reg(bytes, pc + 2) == tmp &&
	    bytes[(pc + 2) * INSN_SIZE] == BPF_AND64_X &&
	    src_reg(bytes, pc + 2) == src) {
		if (bytes[(pc + 1) * INSN_SIZE] == BPF_ADD64_K &&
		    read_imm(bytes, pc + 1) == -1) {
			return Bmi1Site{ pc, 3, "bpf_x86_blsrq", tmp, src,
					 std::nullopt };
		}
		if (bytes[(pc + 1) * INSN_SIZE] == BPF_NEG64) {
			return Bmi1Site{ pc, 3, "bpf_x86_blsiq", tmp, src,
					 std::nullopt };
		}
	}
	if (tmp != src && pc + 4 <= insn_count &&
	    bytes[(pc + 1) * INSN_SIZE] == BPF_MOV64_X &&
	    src_reg(bytes, pc + 1) == src &&
	    bytes[(pc + 3) * INSN_SIZE] == BPF_AND64_X &&
	    dst_reg(bytes, pc + 2) == dst_reg(bytes, pc + 1) &&
	    dst_reg(bytes, pc + 3) == dst_reg(bytes, pc + 1) &&
	    src_reg(bytes, pc + 3) == tmp) {
		const uint8_t dst = dst_reg(bytes, pc + 1);
		if (dst != tmp) {
			if (bytes[(pc + 2) * INSN_SIZE] == BPF_ADD64_K &&
			    read_imm(bytes, pc + 2) == -1) {
				return Bmi1Site{ pc, 4, "bpf_x86_blsrq", dst,
						 src, tmp };
			}
			if (bytes[(pc + 2) * INSN_SIZE] == BPF_NEG64) {
				return Bmi1Site{ pc, 4, "bpf_x86_blsiq", dst,
						 src, tmp };
			}
		}
	}
	if (tmp != src && dst_reg(bytes, pc + 1) == src &&
	    bytes[(pc + 2) * INSN_SIZE] == BPF_AND64_X &&
	    dst_reg(bytes, pc + 2) == src &&
	    src_reg(bytes, pc + 2) == tmp) {
		if (bytes[(pc + 1) * INSN_SIZE] == BPF_ADD64_K &&
		    read_imm(bytes, pc + 1) == -1) {
			return Bmi1Site{ pc, 3, "bpf_x86_blsrq", src, src,
					 tmp };
		}
		if (bytes[(pc + 1) * INSN_SIZE] == BPF_NEG64) {
			return Bmi1Site{ pc, 3, "bpf_x86_blsiq", src, src,
					 tmp };
		}
	}
	return std::nullopt;
}

int64_t apply_bmi1_bytecode_kinsns(std::vector<uint8_t> &bytes,
				   const KinsnTargetMap &targets)
{
	if (!target_is_x86_kinsn_set(targets)) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_bmi1_site(bytes, pc);
		if (!site || !target_has_kinsn(targets, site->name) ||
		    !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}
		if (site->dropped_copy_reg &&
		    reg_read_before_write_on_any_path_after(
			    bytes, site->start + site->old_len,
			    *site->dropped_copy_reg)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, site->name,
				  pack_x86_bmi1_payload(site->dst, site->src));
		replace_insn_range(bytes, site->start, site->old_len, replacement);
		applied++;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

const char *bmi2_shift_name(uint8_t opcode)
{
	switch (opcode) {
	case BPF_LSH64_X:
		return "bpf_x86_shlxq";
	case BPF_LSH32_X:
		return "bpf_x86_shlxl";
	case BPF_RSH64_X:
		return "bpf_x86_shrxq";
	case BPF_RSH32_X:
		return "bpf_x86_shrxl";
	default:
		return nullptr;
	}
}

int64_t apply_bmi2_shift_bytecode_kinsns(std::vector<uint8_t> &bytes,
					 const KinsnTargetMap &targets)
{
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		const char *name = bmi2_shift_name(opcode);
		if (!name || !target_has_kinsn(targets, name) ||
		    !range_is_replaceable(bytes, pc, 1)) {
			pc++;
			continue;
		}
		const uint8_t dst = dst_reg(bytes, pc);
		const uint8_t cnt = src_reg(bytes, pc);
		if (dst == cnt) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, name,
				  pack_x86_bmi2_shift_payload(dst, dst, cnt));
		replace_insn_range(bytes, pc, 1, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
	}
	return applied;
}

const char *bzhi_name_for_opcode(uint8_t opcode)
{
	switch (opcode) {
	case BPF_LSH64_X:
		return "bpf_x86_bzhiq";
	case BPF_LSH32_X:
		return "bpf_x86_bzhil";
	default:
		return nullptr;
	}
}

uint8_t bzhi_width_for_opcode(uint8_t opcode)
{
	return opcode == BPF_LSH64_X ? 64 : 32;
}

bool reg_has_all_ones_before(const std::vector<uint8_t> &bytes, size_t pc,
			     uint8_t reg, uint8_t width)
{
	size_t scan = pc;
	while (scan > 0) {
		scan--;
		if (!insn_writes_reg(bytes, scan, reg)) {
			continue;
		}
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		if (width == 32 && opcode == BPF_MOV32_K &&
		    static_cast<uint32_t>(read_imm(bytes, scan)) ==
			    std::numeric_limits<uint32_t>::max()) {
			return true;
		}
		if (width == 64 && opcode == BPF_MOV64_K &&
		    read_imm(bytes, scan) == -1) {
			return true;
		}
		if (width == 64 && opcode == BPF_LD_IMM64 &&
		    read_ldimm64_u64(bytes, scan) ==
			    std::numeric_limits<uint64_t>::max()) {
			return true;
		}
		return false;
	}
	return false;
}

bool reg_is_bzhi_count_bounded_before(const std::vector<uint8_t> &bytes,
				      size_t pc, uint8_t reg, uint8_t width)
{
	size_t scan = pc;
	while (scan > 0) {
		scan--;
		if (!insn_writes_reg(bytes, scan, reg)) {
			continue;
		}
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		if (opcode == BPF_MOV64_K || opcode == BPF_MOV32_K) {
			return static_cast<uint32_t>(read_imm(bytes, scan)) < width;
		}
		if ((opcode == BPF_AND64_K || opcode == BPF_AND32_K) &&
		    read_imm(bytes, scan) >= 0) {
			return static_cast<uint32_t>(read_imm(bytes, scan)) < width;
		}
		return false;
	}
	return false;
}

int64_t apply_bzhi_bytecode_kinsns(std::vector<uint8_t> &bytes,
				   const KinsnTargetMap &targets)
{
	int64_t applied = 0;
	size_t pc = 0;
	while (pc + 1 < bytes.size() / INSN_SIZE) {
		const uint8_t opcode = bytes[pc * INSN_SIZE];
		const char *name = bzhi_name_for_opcode(opcode);
		if (!name || !target_has_kinsn(targets, name) ||
		    !range_is_replaceable(bytes, pc, 2)) {
			pc++;
			continue;
		}
		const uint8_t mask = dst_reg(bytes, pc);
		const uint8_t cnt = src_reg(bytes, pc);
		const uint8_t width = bzhi_width_for_opcode(opcode);
		const uint8_t xor_opcode = width == 64 ? BPF_XOR64_K :
						       BPF_XOR32_K;
		if (bytes[(pc + 1) * INSN_SIZE] != xor_opcode ||
		    dst_reg(bytes, pc + 1) != mask ||
		    read_imm(bytes, pc + 1) != -1 ||
		    !reg_has_all_ones_before(bytes, pc, mask, width) ||
		    !reg_is_bzhi_count_bounded_before(bytes, pc, cnt, width)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, name,
				  pack_x86_bzhi_payload(mask, mask, cnt));
		replace_insn_range(bytes, pc, 2, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
	}
	return applied;
}

struct PopcntSite {
	size_t start = 0;
	size_t old_len = 0;
	size_t interlude_start = 0;
	size_t interlude_len = 0;
	uint8_t dst = 0;
	uint8_t src = 0;
};

bool reg_has_const_before(const std::vector<uint8_t> &bytes, size_t pc,
			  uint8_t reg, uint64_t expected)
{
	const auto value = const_reg_value_before(bytes, pc, reg);
	return value && *value == expected;
}

bool match_popcnt_swar_tail(const std::vector<uint8_t> &bytes, size_t pc,
			    uint8_t src, uint8_t dst, size_t &tail_len)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 8 > insn_count ||
	    bytes[pc * INSN_SIZE] != BPF_MOV64_X ||
	    dst_reg(bytes, pc) != src || src_reg(bytes, pc) != dst ||
	    bytes[(pc + 1) * INSN_SIZE] != BPF_RSH64_K ||
	    dst_reg(bytes, pc + 1) != src || read_imm(bytes, pc + 1) != 4 ||
	    bytes[(pc + 2) * INSN_SIZE] != BPF_ADD64_X ||
	    dst_reg(bytes, pc + 2) != dst || src_reg(bytes, pc + 2) != src ||
	    bytes[(pc + 3) * INSN_SIZE] != BPF_LD_IMM64 ||
	    dst_reg(bytes, pc + 3) != src ||
	    read_ldimm64_u64(bytes, pc + 3) != 0x0f0f0f0f0f0f0f0fULL ||
	    bytes[(pc + 5) * INSN_SIZE] != BPF_AND64_X ||
	    dst_reg(bytes, pc + 5) != dst || src_reg(bytes, pc + 5) != src ||
	    bytes[(pc + 6) * INSN_SIZE] != BPF_MUL64_X ||
	    dst_reg(bytes, pc + 6) != dst ||
	    !reg_has_const_before(bytes, pc + 6, src_reg(bytes, pc + 6),
				  0x0101010101010101ULL) ||
	    bytes[(pc + 7) * INSN_SIZE] != BPF_RSH64_K ||
	    dst_reg(bytes, pc + 7) != dst || read_imm(bytes, pc + 7) != 56) {
		return false;
	}
	tail_len = 8;
	return true;
}

std::optional<size_t> popcnt_interlude_len(const std::vector<uint8_t> &bytes,
					   size_t pc, uint8_t scratch,
					   uint8_t dst)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 3 > insn_count ||
	    bytes[pc * INSN_SIZE] != BPF_MOV64_X ||
	    dst_reg(bytes, pc) != scratch ||
	    bytes[(pc + 1) * INSN_SIZE] != BPF_AND64_K ||
	    dst_reg(bytes, pc + 1) != scratch || read_imm(bytes, pc + 1) != 7 ||
	    bytes[(pc + 2) * INSN_SIZE] != BPF_RSH64_X ||
	    src_reg(bytes, pc + 2) != scratch ||
	    dst_reg(bytes, pc + 2) == dst) {
		return std::nullopt;
	}
	return 3;
}

std::optional<PopcntSite> match_popcnt_swar_site(const std::vector<uint8_t> &bytes,
						 size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 17 > insn_count ||
	    bytes[pc * INSN_SIZE] != BPF_MOV64_X ||
	    bytes[(pc + 1) * INSN_SIZE] != BPF_RSH64_K ||
	    bytes[(pc + 2) * INSN_SIZE] != BPF_AND64_X ||
	    bytes[(pc + 3) * INSN_SIZE] != BPF_SUB64_X ||
	    bytes[(pc + 4) * INSN_SIZE] != BPF_MOV64_X ||
	    bytes[(pc + 5) * INSN_SIZE] != BPF_AND64_X ||
	    bytes[(pc + 6) * INSN_SIZE] != BPF_RSH64_K ||
	    bytes[(pc + 7) * INSN_SIZE] != BPF_AND64_X ||
	    bytes[(pc + 8) * INSN_SIZE] != BPF_ADD64_X) {
		return std::nullopt;
	}

	const uint8_t tmp = dst_reg(bytes, pc);
	const uint8_t src = src_reg(bytes, pc);
	const uint8_t dst = dst_reg(bytes, pc + 4);
	if (tmp == src || dst == src || dst == tmp ||
	    dst_reg(bytes, pc + 1) != tmp || read_imm(bytes, pc + 1) != 1 ||
	    dst_reg(bytes, pc + 2) != tmp ||
	    !reg_has_const_before(bytes, pc + 2, src_reg(bytes, pc + 2),
				  0x5555555555555555ULL) ||
	    dst_reg(bytes, pc + 3) != src || src_reg(bytes, pc + 3) != tmp ||
	    src_reg(bytes, pc + 4) != src ||
	    dst_reg(bytes, pc + 5) != dst ||
	    !reg_has_const_before(bytes, pc + 5, src_reg(bytes, pc + 5),
				  0x3333333333333333ULL) ||
	    dst_reg(bytes, pc + 6) != src || read_imm(bytes, pc + 6) != 2 ||
	    dst_reg(bytes, pc + 7) != src ||
	    src_reg(bytes, pc + 7) != src_reg(bytes, pc + 5) ||
	    dst_reg(bytes, pc + 8) != dst || src_reg(bytes, pc + 8) != src) {
		return std::nullopt;
	}

	size_t tail_pc = pc + 9;
	size_t interlude_len = 0;
	if (const auto len = popcnt_interlude_len(bytes, tail_pc, src, dst)) {
		interlude_len = *len;
		tail_pc += interlude_len;
	}

	size_t tail_len = 0;
	if (!match_popcnt_swar_tail(bytes, tail_pc, src, dst, tail_len)) {
		return std::nullopt;
	}
	return PopcntSite{ pc, (tail_pc - pc) + tail_len, pc + 9,
			   interlude_len, dst, src };
}

int64_t apply_popcnt_bytecode_kinsns(std::vector<uint8_t> &bytes,
				     const KinsnTargetMap &targets)
{
	if (!target_has_kinsn(targets, "bpf_x86_popcntq")) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_popcnt_swar_site(bytes, pc);
		if (!site ||
		    !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}
		if (site->src != site->dst &&
		    reg_read_before_write_on_any_path_after(
			    bytes, site->start + site->old_len, site->src)) {
			pc++;
			continue;
		}

		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, "bpf_x86_popcntq",
				  pack_x86_popcnt_payload(site->dst, site->src));
		if (site->interlude_len) {
			replacement.insert(
				replacement.end(),
				bytes.begin() + site->interlude_start * INSN_SIZE,
				bytes.begin() +
					(site->interlude_start +
					 site->interlude_len) *
						INSN_SIZE);
		}
		replace_insn_range(bytes, site->start, site->old_len,
				   replacement);
		applied++;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

std::optional<int> endian_size_bytes(const std::vector<uint8_t> &bytes,
				     size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (opcode != BPF_END_BE) {
		return std::nullopt;
	}
	const int32_t bits = read_imm(bytes, pc);
	if (bits != 16 && bits != 32 && bits != 64) {
		return std::nullopt;
	}
	return bits / 8;
}

bool endian_load_size_matches(int load_bytes, int endian_bytes)
{
	return load_bytes == endian_bytes ||
	       ((load_bytes == 4 || load_bytes == 8) && load_bytes > endian_bytes);
}

std::string_view movbe_target_for_size(int bytes)
{
	switch (bytes) {
	case 2:
		return "bpf_x86_movbe16";
	case 4:
		return "bpf_x86_movbe32";
	case 8:
		return "bpf_x86_movbe64";
	default:
		throw std::runtime_error("unsupported MOVBE width");
	}
}

std::string_view arm64_rev_target_for_size(int bytes)
{
	switch (bytes) {
	case 2:
		return "bpf_arm64_rev16_w";
	case 4:
		return "bpf_arm64_rev_w";
	case 8:
		return "bpf_arm64_rev_x";
	default:
		throw std::runtime_error("unsupported REV width");
	}
}

struct EndianSite {
	size_t start = 0;
	size_t old_len = 0;
	uint8_t dst = 0;
	uint8_t base = 0;
	int16_t off = 0;
	int load_bytes = 0;
	int bytes = 0;
};

struct ByteLoadComponent {
	int16_t off = 0;
	uint8_t shift = 0;
};

struct ByteLoadExpr {
	uint8_t base = 0;
	std::vector<ByteLoadComponent> components;
};

struct Arm64ByteLoadFusionSite {
	size_t start = 0;
	size_t old_len = 0;
	uint8_t dst = 0;
	uint8_t base = 0;
	int16_t off = 0;
	int width = 0;
	bool big_endian = false;
	std::vector<uint8_t> clobbered;
};

std::optional<EndianSite> match_endian_site(const std::vector<uint8_t> &bytes,
					    size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	const uint8_t load_op = bytes[pc * INSN_SIZE];
	if (!is_ldx_mem_opcode(load_op)) {
		return std::nullopt;
	}
	const auto load_bytes = bpf_mem_width(load_op);
	if (!load_bytes || *load_bytes == 1) {
		return std::nullopt;
	}
	const uint8_t dst = dst_reg(bytes, pc);
	if (pc + 1 < insn_count && dst_reg(bytes, pc + 1) == dst) {
		const auto endian_bytes = endian_size_bytes(bytes, pc + 1);
		if (endian_bytes &&
		    endian_load_size_matches(*load_bytes, *endian_bytes)) {
			return EndianSite{ pc, 2, dst, src_reg(bytes, pc),
					   read_off(bytes, pc), *load_bytes,
					   *endian_bytes };
		}
	}
	if (*load_bytes != 4 && *load_bytes != 8) {
		return std::nullopt;
	}
	const size_t scan_end = std::min(insn_count, pc + 33);
	for (size_t scan = pc + 1; scan < scan_end; scan++) {
		if (dst_reg(bytes, scan) == dst) {
			const auto endian_bytes = endian_size_bytes(bytes, scan);
			if (endian_bytes &&
			    endian_load_size_matches(*load_bytes, *endian_bytes)) {
				return EndianSite{ pc, scan + 1 - pc, dst,
						   src_reg(bytes, pc),
						   read_off(bytes, pc),
						   *load_bytes,
						   *endian_bytes };
			}
		}
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		if (opcode == BPF_LD_IMM64 || opcode == BPF_JA ||
		    is_conditional_jump(opcode) || opcode == BPF_CALL ||
		    opcode == BPF_CALLX || opcode == BPF_EXIT ||
		    insn_uses_reg(bytes, scan, dst) ||
		    insn_writes_reg(bytes, scan, dst)) {
			break;
		}
	}
	return std::nullopt;
}

std::string_view arm64_load_target_for_width(int bytes)
{
	switch (bytes) {
	case 2:
		return "bpf_arm64_ldrh";
	case 4:
		return "bpf_arm64_ldr_w";
	default:
		throw std::runtime_error("unsupported ARM64 byte-load width");
	}
}

bool byte_load_expr_merge(ByteLoadExpr &dst, const ByteLoadExpr &src)
{
	if (dst.base != src.base) {
		return false;
	}
	for (const auto &incoming : src.components) {
		for (const auto &existing : dst.components) {
			if (existing.off == incoming.off ||
			    existing.shift == incoming.shift) {
				return false;
			}
		}
		dst.components.push_back(incoming);
	}
	return true;
}

std::optional<std::pair<int16_t, bool>>
classify_byte_load_expr(const ByteLoadExpr &expr, int width)
{
	if (static_cast<int>(expr.components.size()) != width) {
		return std::nullopt;
	}
	auto components = expr.components;
	std::sort(components.begin(), components.end(),
		  [](const ByteLoadComponent &lhs, const ByteLoadComponent &rhs) {
			  return lhs.off < rhs.off;
		  });
	const int16_t base_off = components.front().off;
	for (int i = 0; i < width; i++) {
		if (components[i].off != base_off + i) {
			return std::nullopt;
		}
	}

	bool little_endian = true;
	bool big_endian = true;
	for (int i = 0; i < width; i++) {
		const uint8_t le_shift = static_cast<uint8_t>(8 * i);
		const uint8_t be_shift = static_cast<uint8_t>(8 * (width - 1 - i));
		little_endian &= components[i].shift == le_shift;
		big_endian &= components[i].shift == be_shift;
	}
	if (little_endian) {
		return std::pair<int16_t, bool>{ base_off, false };
	}
	if (big_endian) {
		return std::pair<int16_t, bool>{ base_off, true };
	}
	return std::nullopt;
}

size_t extend_byte_load_cleanup(const std::vector<uint8_t> &bytes, size_t end,
				uint8_t dst, int width)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (width == 4 && end + 1 < insn_count &&
	    bytes[end * INSN_SIZE] == BPF_LSH64_K &&
	    bytes[(end + 1) * INSN_SIZE] == BPF_RSH64_K &&
	    dst_reg(bytes, end) == dst && dst_reg(bytes, end + 1) == dst &&
	    read_imm(bytes, end) == 32 && read_imm(bytes, end + 1) == 32) {
		return end + 2;
	}
	if (end < insn_count && dst_reg(bytes, end) == dst) {
		const uint8_t opcode = bytes[end * INSN_SIZE];
		const int32_t imm = read_imm(bytes, end);
		if (width == 2 &&
		    (opcode == BPF_AND64_K || opcode == BPF_AND32_K) &&
		    imm == 0xffff) {
			return end + 1;
		}
		if (width == 4 && opcode == BPF_AND32_K && imm == -1) {
			return end + 1;
		}
	}
	return end;
}

std::optional<Arm64ByteLoadFusionSite>
match_arm64_byte_load_fusion_site(const std::vector<uint8_t> &bytes, size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc >= insn_count || bytes[pc * INSN_SIZE] != BPF_LDXB) {
		return std::nullopt;
	}

	std::array<std::optional<ByteLoadExpr>, 11> exprs;
	std::vector<uint8_t> written;
	std::optional<Arm64ByteLoadFusionSite> best;
	std::optional<uint8_t> base;
	bool base_clobbered = false;
	const size_t scan_end = std::min(insn_count, pc + 14);

	for (size_t scan = pc; scan < scan_end; scan++) {
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		const uint8_t dst = dst_reg(bytes, scan);
		const uint8_t src = src_reg(bytes, scan);

		if (opcode == BPF_LDXB) {
			if (!base) {
				base = src;
			}
			if (src != *base || base_clobbered) {
				break;
			}
			if (dst >= exprs.size()) {
				break;
			}
			exprs[dst] = ByteLoadExpr{
				*base,
				std::vector<ByteLoadComponent>{
					ByteLoadComponent{ read_off(bytes, scan), 0 },
				},
			};
		} else if (opcode == BPF_LSH64_K || opcode == BPF_LSH32_K) {
			if (dst >= exprs.size() || !exprs[dst]) {
				break;
			}
			const int32_t amount = read_imm(bytes, scan);
			if (amount < 0 || amount >= 64) {
				break;
			}
			for (auto &component : exprs[dst]->components) {
				const int shifted =
					static_cast<int>(component.shift) + amount;
				if (shifted >= 64) {
					return std::nullopt;
				}
				component.shift = static_cast<uint8_t>(shifted);
			}
		} else if (opcode == BPF_OR64_X || opcode == BPF_OR32_X) {
			if (dst >= exprs.size() || src >= exprs.size() ||
			    !exprs[dst] || !exprs[src]) {
				break;
			}
			if (!byte_load_expr_merge(*exprs[dst], *exprs[src])) {
				break;
			}
		} else {
			break;
		}

		if (std::find(written.begin(), written.end(), dst) == written.end()) {
			written.push_back(dst);
		}
		if (base && dst == *base) {
			base_clobbered = true;
		}

		if (dst < exprs.size() && exprs[dst]) {
			for (int width : { 4, 2 }) {
				const auto classified =
					classify_byte_load_expr(*exprs[dst], width);
				if (!classified) {
					continue;
				}
				const size_t end =
					extend_byte_load_cleanup(bytes, scan + 1,
								 dst, width);
				Arm64ByteLoadFusionSite site{
					pc, end - pc, dst, exprs[dst]->base,
					classified->first, width,
					classified->second, {}
				};
				for (uint8_t reg : written) {
					if (reg != dst &&
					    std::find(site.clobbered.begin(),
						      site.clobbered.end(),
						      reg) == site.clobbered.end()) {
						site.clobbered.push_back(reg);
					}
				}
				if (!best || site.width > best->width ||
				    (site.width == best->width &&
				     site.old_len > best->old_len)) {
					best = std::move(site);
				}
			}
		}
	}
	return best;
}

std::vector<uint8_t>
emit_arm64_byte_load_fusion(const KinsnTargetMap &targets,
			    const Arm64ByteLoadFusionSite &site)
{
	std::vector<uint8_t> replacement;
	const auto load_name = arm64_load_target_for_width(site.width);
	if (!target_has_kinsn(targets, load_name)) {
		return replacement;
	}
	append_kinsn_pair(replacement, targets, load_name,
			  pack_arm64_mem_payload(site.dst, site.base, site.off));
	if (!site.big_endian) {
		return replacement;
	}
	const auto rev_name = arm64_rev_target_for_size(site.width);
	if (!target_has_kinsn(targets, rev_name)) {
		replacement.clear();
		return replacement;
	}
	append_kinsn_pair(replacement, targets, rev_name, pack_u4(site.dst, 0));
	return replacement;
}

int64_t apply_arm64_byte_load_fusion_kinsns(std::vector<uint8_t> &bytes,
					    const KinsnTargetMap &targets,
					    bool big_endian)
{
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_arm64_byte_load_fusion_site(bytes, pc);
		if (!site || site->big_endian != big_endian ||
		    !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}
		bool clobbers_live_reg = false;
		for (uint8_t reg : site->clobbered) {
			if (reg_read_before_write_on_any_path_after(
				    bytes, site->start + site->old_len, reg)) {
				clobbers_live_reg = true;
				break;
			}
		}
		if (clobbers_live_reg) {
			pc++;
			continue;
		}
		const auto replacement = emit_arm64_byte_load_fusion(targets, *site);
		if (replacement.empty()) {
			pc++;
			continue;
		}
		replace_insn_range(bytes, site->start, site->old_len,
				   replacement);
		applied++;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

int64_t apply_arm64_endian_bytecode_kinsns(std::vector<uint8_t> &bytes,
					   const KinsnTargetMap &targets)
{
	int64_t applied = apply_arm64_byte_load_fusion_kinsns(bytes, targets,
							      true);
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto endian_bytes = endian_size_bytes(bytes, pc);
		if (!endian_bytes || !range_is_replaceable(bytes, pc, 1)) {
			pc++;
			continue;
		}
		const auto name = arm64_rev_target_for_size(*endian_bytes);
		if (!target_has_kinsn(targets, name)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, name,
				  pack_u4(dst_reg(bytes, pc), 0));
		replace_insn_range(bytes, pc, 1, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
	}
	return applied;
}

int64_t apply_endian_bytecode_kinsns(std::vector<uint8_t> &bytes,
				     const KinsnTargetMap &targets,
				     KinsnTargetArch target_arch)
{
	if (kinsn_target_arch_is_arm64(target_arch, targets)) {
		return apply_arm64_endian_bytecode_kinsns(bytes, targets);
	}
	if (!kinsn_target_arch_is_x86(target_arch, targets)) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_endian_site(bytes, pc);
		if (!site || !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		const size_t endian_pc = site->start + site->old_len - 1;
		if (site->bytes == 2) {
			if (site->load_bytes != 2) {
				pc++;
				continue;
			}
			replacement.insert(replacement.end(),
					   bytes.begin() +
						   site->start * INSN_SIZE,
					   bytes.begin() + endian_pc * INSN_SIZE);
			append_kinsn_pair(replacement, targets, "bpf_x86_rolw",
					  pack_x86_reg_imm_payload(site->dst, 8));
		} else {
			append_kinsn_pair(replacement, targets,
					  movbe_target_for_size(site->bytes),
					  pack_x86_mem_payload(site->dst,
							       site->base,
							       site->off));
			const size_t preserve_first = site->start + 1;
			replacement.insert(replacement.end(),
					   bytes.begin() +
						   preserve_first * INSN_SIZE,
					   bytes.begin() +
						   endian_pc * INSN_SIZE);
		}
		replace_insn_range(bytes, site->start, site->old_len, replacement);
		applied++;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

struct CondSelectSite {
	size_t start = 0;
	uint8_t dst = 0;
	uint8_t true_reg = 0;
	uint8_t false_reg = 0;
	uint8_t cond_reg = 0;
};

std::optional<CondSelectSite>
match_arm64_csel_ne_site(const std::vector<uint8_t> &bytes, size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 4 > insn_count ||
	    (bytes[pc * INSN_SIZE] != BPF_JEQ64_K &&
	     bytes[pc * INSN_SIZE] != BPF_JNE64_K) ||
	    bytes[(pc + 1) * INSN_SIZE] != BPF_MOV64_X ||
	    bytes[(pc + 2) * INSN_SIZE] != BPF_JA ||
	    bytes[(pc + 3) * INSN_SIZE] != BPF_MOV64_X ||
	    read_imm(bytes, pc) != 0 || read_off(bytes, pc) != 2 ||
	    read_off(bytes, pc + 2) != 1) {
		return std::nullopt;
	}
	const uint8_t dst = dst_reg(bytes, pc + 1);
	if (dst_reg(bytes, pc + 3) != dst) {
		return std::nullopt;
	}
	if (bytes[pc * INSN_SIZE] == BPF_JEQ64_K) {
		return CondSelectSite{ pc, dst, src_reg(bytes, pc + 1),
				       src_reg(bytes, pc + 3), dst_reg(bytes, pc) };
	}
	return CondSelectSite{ pc, dst, src_reg(bytes, pc + 3),
			       src_reg(bytes, pc + 1), dst_reg(bytes, pc) };
}

int64_t apply_cond_select_bytecode_kinsns(std::vector<uint8_t> &bytes,
					  const KinsnTargetMap &targets,
					  KinsnTargetArch target_arch)
{
	if (!kinsn_target_arch_is_arm64(target_arch, targets) ||
	    !target_has_kinsn(targets, "bpf_arm64_tst") ||
	    !target_has_kinsn(targets, "bpf_arm64_csel_ne")) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_arm64_csel_ne_site(bytes, pc);
		if (!site || !range_is_replaceable(bytes, site->start, 4)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, "bpf_arm64_tst",
				  pack_u4(site->cond_reg, 0));
		append_kinsn_pair(replacement, targets, "bpf_arm64_csel_ne",
				  pack_arm64_csel_payload(
					  site->dst, site->true_reg,
					  site->false_reg, site->cond_reg));
		replace_insn_range(bytes, site->start, 4, replacement);
		applied += 2;
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

constexpr uint8_t ARM64_CCMP_MODE_FAIL_EQ = 0;
constexpr uint8_t ARM64_CCMP_MODE_FAIL_NE = 1;

struct CcmpSite {
	size_t start = 0;
	size_t old_len = 0;
	bool width32 = false;
	uint8_t dst = 0;
	uint8_t mode = 0;
	std::vector<uint8_t> regs;
};

bool is_bool_mov_imm(const std::vector<uint8_t> &bytes, size_t pc, uint8_t value)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	return (opcode == BPF_MOV64_K || opcode == BPF_MOV32_K) &&
	       read_imm(bytes, pc) == value;
}

std::optional<CcmpSite> match_arm64_ccmp_site(const std::vector<uint8_t> &bytes,
					      size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 4 > insn_count || !is_bool_mov_imm(bytes, pc, 0)) {
		return std::nullopt;
	}
	const uint8_t dst = dst_reg(bytes, pc);
	if (dst > 9) {
		return std::nullopt;
	}

	std::vector<uint8_t> regs;
	std::optional<bool> width32;
	std::optional<uint8_t> mode;
	for (size_t i = 0; i < 4 && pc + 1 + i < insn_count; i++) {
		const size_t branch_pc = pc + 1 + i;
		const uint8_t opcode = bytes[branch_pc * INSN_SIZE];
		bool branch_width32 = false;
		uint8_t branch_mode = 0;
		if (opcode == BPF_JEQ64_K) {
			branch_mode = ARM64_CCMP_MODE_FAIL_EQ;
		} else if (opcode == BPF_JNE64_K) {
			branch_mode = ARM64_CCMP_MODE_FAIL_NE;
		} else if (opcode == BPF_JEQ32_K) {
			branch_width32 = true;
			branch_mode = ARM64_CCMP_MODE_FAIL_EQ;
		} else if (opcode == BPF_JNE32_K) {
			branch_width32 = true;
			branch_mode = ARM64_CCMP_MODE_FAIL_NE;
		} else {
			break;
		}
		if (read_imm(bytes, branch_pc) != 0 || dst_reg(bytes, branch_pc) == dst) {
			break;
		}
		if (width32 && *width32 != branch_width32) {
			break;
		}
		if (mode && *mode != branch_mode) {
			break;
		}
		width32 = branch_width32;
		mode = branch_mode;
		regs.push_back(dst_reg(bytes, branch_pc));
	}

	if (regs.size() < 2 || !width32 || !mode) {
		return std::nullopt;
	}
	const size_t mov_one_pc = pc + 1 + regs.size();
	if (mov_one_pc >= insn_count || !is_bool_mov_imm(bytes, mov_one_pc, 1) ||
	    dst_reg(bytes, mov_one_pc) != dst) {
		return std::nullopt;
	}
	const size_t skip_pc = mov_one_pc + 1;
	for (size_t i = 0; i < regs.size(); i++) {
		const size_t branch_pc = pc + 1 + i;
		if (read_off(bytes, branch_pc) !=
		    static_cast<int16_t>(skip_pc - branch_pc - 1)) {
			return std::nullopt;
		}
	}
	return CcmpSite{ pc, regs.size() + 2, *width32, dst, *mode, regs };
}

int64_t apply_ccmp_bytecode_kinsns(std::vector<uint8_t> &bytes,
				   const KinsnTargetMap &targets,
				   KinsnTargetArch target_arch)
{
	if (!kinsn_target_arch_is_arm64(target_arch, targets) ||
	    !target_has_kinsn(targets, "bpf_arm64_cmp_x") ||
	    !target_has_kinsn(targets, "bpf_arm64_cmp_w") ||
	    !target_has_kinsn(targets, "bpf_arm64_ccmp_x") ||
	    !target_has_kinsn(targets, "bpf_arm64_ccmp_w") ||
	    !target_has_kinsn(targets, "bpf_arm64_cset_x_cond")) {
		return 0;
	}

	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		const auto site = match_arm64_ccmp_site(bytes, pc);
		if (!site || !range_is_replaceable(bytes, site->start, site->old_len)) {
			pc++;
			continue;
		}

		const char *cmp_name = site->width32 ? "bpf_arm64_cmp_w" :
						     "bpf_arm64_cmp_x";
		const char *ccmp_name = site->width32 ? "bpf_arm64_ccmp_w" :
						      "bpf_arm64_ccmp_x";
		std::vector<uint8_t> replacement;
		append_kinsn_pair(replacement, targets, cmp_name,
				  pack_u4(site->regs[0], 0));
		for (size_t i = 1; i < site->regs.size(); i++) {
			append_kinsn_pair(replacement, targets, ccmp_name,
					  pack_arm64_ccmp_payload(site->regs[i],
								  site->mode));
		}
		append_kinsn_pair(replacement, targets, "bpf_arm64_cset_x_cond",
				  pack_arm64_cset_payload(
					  site->dst,
					  static_cast<uint8_t>(site->regs.size()),
					  site->mode, site->width32, site->regs));

		replace_insn_range(bytes, site->start, site->old_len,
				   replacement);
		applied += static_cast<int64_t>(site->regs.size() + 1);
		pc = site->start + replacement.size() / INSN_SIZE;
	}
	return applied;
}

struct MemcpyLane {
	int width = 0;
	uint8_t tmp = 0;
	uint8_t src_base = 0;
	uint8_t dst_base = 0;
	int16_t src_off = 0;
	int16_t dst_off = 0;
};

std::optional<MemcpyLane> memcpy_lane_at(const std::vector<uint8_t> &bytes,
					 size_t pc)
{
	const size_t insn_count = bytes.size() / INSN_SIZE;
	if (pc + 1 >= insn_count) {
		return std::nullopt;
	}
	const uint8_t load_op = bytes[pc * INSN_SIZE];
	const uint8_t store_op = bytes[(pc + 1) * INSN_SIZE];
	if (!is_ldx_mem_opcode(load_op) || !is_stx_mem_opcode(store_op) ||
	    (load_op & BPF_SIZE_MASK) != (store_op & BPF_SIZE_MASK) ||
	    src_reg(bytes, pc + 1) != dst_reg(bytes, pc)) {
		return std::nullopt;
	}
	const auto width = bpf_mem_width(load_op);
	if (!width || dst_reg(bytes, pc) == src_reg(bytes, pc) ||
	    dst_reg(bytes, pc) == dst_reg(bytes, pc + 1)) {
		return std::nullopt;
	}
	return MemcpyLane{ *width, dst_reg(bytes, pc), src_reg(bytes, pc),
			   dst_reg(bytes, pc + 1), read_off(bytes, pc),
			   read_off(bytes, pc + 1) };
}

bool byte_ranges_overlap_i16(int16_t lhs, int16_t rhs, size_t len)
{
	const int lhs_start = lhs;
	const int rhs_start = rhs;
	const int width = static_cast<int>(len);
	return lhs_start < rhs_start + width && rhs_start < lhs_start + width;
}

bool checked_i16_offset(int16_t base, size_t delta, int16_t &out)
{
	const int64_t value = static_cast<int64_t>(base) +
			      static_cast<int64_t>(delta);
	if (value < std::numeric_limits<int16_t>::min() ||
	    value > std::numeric_limits<int16_t>::max()) {
		return false;
	}
	out = static_cast<int16_t>(value);
	return true;
}

std::string_view mov_load_target_for_width(int width)
{
	switch (width) {
	case 1:
		return "bpf_x86_movzbl";
	case 2:
		return "bpf_x86_movzwl";
	case 4:
		return "bpf_x86_movl";
	case 8:
		return "bpf_x86_movq";
	default:
		throw std::runtime_error("unsupported memcpy load width");
	}
}

std::string_view mov_store_target_for_width(int width)
{
	switch (width) {
	case 1:
		return "bpf_x86_movb";
	case 2:
		return "bpf_x86_movw";
	case 4:
		return "bpf_x86_movl";
	case 8:
		return "bpf_x86_movq";
	default:
		throw std::runtime_error("unsupported memcpy store width");
	}
}

std::vector<uint8_t> emit_memcpy_lane_kinsns(const KinsnTargetMap &targets,
					     const MemcpyLane &first,
					     size_t lanes)
{
	std::vector<uint8_t> out;
	for (size_t lane = 0; lane < lanes; lane++) {
		int16_t src_off = 0;
		int16_t dst_off = 0;
		const size_t delta = lane * static_cast<size_t>(first.width);
		if (!checked_i16_offset(first.src_off, delta, src_off) ||
		    !checked_i16_offset(first.dst_off, delta, dst_off)) {
			throw std::runtime_error("bulk_memory lane offset exceeds i16");
		}
		append_kinsn_pair(out, targets, mov_load_target_for_width(first.width),
				  pack_x86_mem_payload(first.tmp, first.src_base,
						       src_off));
		append_kinsn_pair(out, targets,
				  mov_store_target_for_width(first.width),
				  pack_x86_store_reg_payload(first.tmp,
							     first.dst_base,
							     dst_off));
	}
	return out;
}

std::vector<uint8_t> emit_memcpy_lanes_kinsns(const KinsnTargetMap &targets,
					      const std::vector<MemcpyLane> &lanes)
{
	std::vector<uint8_t> out;
	for (const auto &lane : lanes) {
		append_kinsn_pair(out, targets, mov_load_target_for_width(lane.width),
				  pack_x86_mem_payload(lane.tmp, lane.src_base,
						       lane.src_off));
		append_kinsn_pair(out, targets,
				  mov_store_target_for_width(lane.width),
				  pack_x86_store_reg_payload(lane.tmp,
							     lane.dst_base,
							     lane.dst_off));
	}
	return out;
}

bool lanes_cover_contiguous_copy(const std::vector<MemcpyLane> &lanes,
				 size_t &total_bytes, int16_t &min_src_off,
				 int16_t &min_dst_off)
{
	if (lanes.empty()) {
		return false;
	}
	const int width = lanes.front().width;
	const uint8_t src_base = lanes.front().src_base;
	const uint8_t dst_base = lanes.front().dst_base;
	std::vector<int16_t> src_offsets;
	std::vector<int16_t> dst_offsets;
	src_offsets.reserve(lanes.size());
	dst_offsets.reserve(lanes.size());
	for (const auto &lane : lanes) {
		if (lane.width != width || lane.src_base != src_base ||
		    lane.dst_base != dst_base) {
			return false;
		}
		src_offsets.push_back(lane.src_off);
		dst_offsets.push_back(lane.dst_off);
	}
	std::sort(src_offsets.begin(), src_offsets.end());
	std::sort(dst_offsets.begin(), dst_offsets.end());
	for (size_t i = 1; i < lanes.size(); i++) {
		if (src_offsets[i] != src_offsets[i - 1] + width ||
		    dst_offsets[i] != dst_offsets[i - 1] + width) {
			return false;
		}
	}
	const int delta = lanes.front().dst_off - lanes.front().src_off;
	for (const auto &lane : lanes) {
		if (lane.dst_off - lane.src_off != delta) {
			return false;
		}
	}
	total_bytes = lanes.size() * static_cast<size_t>(width);
	min_src_off = src_offsets.front();
	min_dst_off = dst_offsets.front();
	return true;
}

bool memcpy_temps_dead_after(const std::vector<uint8_t> &bytes, size_t pc,
			     const std::vector<MemcpyLane> &lanes)
{
	std::vector<uint8_t> temps;
	for (const auto &lane : lanes) {
		if (std::find(temps.begin(), temps.end(), lane.tmp) ==
		    temps.end()) {
			temps.push_back(lane.tmp);
		}
	}
	for (uint8_t tmp : temps) {
		if (reg_read_before_write_on_any_path_after(bytes, pc, tmp)) {
			return false;
		}
	}
	return true;
}

struct MemsetLane {
	int width = 0;
	uint8_t base = 0;
	int16_t off = 0;
	uint8_t fill = 0;
	uint32_t imm = 0;
};

std::optional<uint8_t> repeated_fill_byte(size_t bytes, uint64_t value)
{
	const uint8_t fill = static_cast<uint8_t>(value & 0xff);
	for (size_t i = 1; i < bytes; i++) {
		if (((value >> (i * 8)) & 0xff) != fill) {
			return std::nullopt;
		}
	}
	return fill;
}

std::optional<MemsetLane> memset_lane_at(const std::vector<uint8_t> &bytes,
					 size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (!is_st_mem_opcode(opcode)) {
		return std::nullopt;
	}
	const auto width = bpf_mem_width(opcode);
	if (!width) {
		return std::nullopt;
	}
	uint64_t value;
	if (*width == 8) {
		value = static_cast<uint64_t>(
			static_cast<int64_t>(read_imm(bytes, pc)));
	} else {
		const uint64_t mask = (uint64_t{ 1 } << (*width * 8)) - 1;
		value = static_cast<uint32_t>(read_imm(bytes, pc)) & mask;
	}
	const auto fill = repeated_fill_byte(*width, value);
	if (!fill) {
		return std::nullopt;
	}
	return MemsetLane{ *width, dst_reg(bytes, pc), read_off(bytes, pc),
			   *fill, static_cast<uint32_t>(read_imm(bytes, pc)) };
}

std::vector<uint8_t> emit_memset_lane_kinsns(const KinsnTargetMap &targets,
					     const std::vector<MemsetLane> &lanes)
{
	std::vector<uint8_t> out;
	for (const auto &lane : lanes) {
		append_kinsn_pair(out, targets,
				  mov_store_target_for_width(lane.width),
				  pack_x86_store_imm_payload(
					  lane.base, lane.off, lane.imm));
	}
	return out;
}

bool arm64_ldstp_soff_ok(int16_t off)
{
	return off >= -512 && off <= 504 && (off % 8) == 0;
}

int64_t apply_arm64_pair_memory_bytecode_kinsns(std::vector<uint8_t> &bytes,
						const KinsnTargetMap &targets,
						KinsnTargetArch target_arch)
{
	if (!kinsn_target_arch_is_arm64(target_arch, targets)) {
		return 0;
	}

	int64_t applied = apply_arm64_byte_load_fusion_kinsns(bytes, targets,
							      false);
	size_t pc = 0;
	while (pc + 1 < bytes.size() / INSN_SIZE) {
		std::vector<uint8_t> replacement;
		if (bytes[pc * INSN_SIZE] == BPF_LDXDW &&
		    bytes[(pc + 1) * INSN_SIZE] == BPF_LDXDW &&
		    src_reg(bytes, pc) == src_reg(bytes, pc + 1) &&
		    dst_reg(bytes, pc) != dst_reg(bytes, pc + 1) &&
		    src_reg(bytes, pc) != dst_reg(bytes, pc) &&
		    src_reg(bytes, pc) != dst_reg(bytes, pc + 1) &&
		    target_has_kinsn(targets, "bpf_arm64_ldp_x") &&
		    range_is_replaceable(bytes, pc, 2)) {
			const int16_t off0 = read_off(bytes, pc);
			const int16_t off1 = read_off(bytes, pc + 1);
			if (off1 == off0 + 8 && arm64_ldstp_soff_ok(off0)) {
				append_kinsn_pair(
					replacement, targets, "bpf_arm64_ldp_x",
					pack_arm64_pair_payload(
						dst_reg(bytes, pc),
						dst_reg(bytes, pc + 1),
						src_reg(bytes, pc), off0));
			} else if (off0 == off1 + 8 &&
				   arm64_ldstp_soff_ok(off1)) {
				append_kinsn_pair(
					replacement, targets, "bpf_arm64_ldp_x",
					pack_arm64_pair_payload(
						dst_reg(bytes, pc + 1),
						dst_reg(bytes, pc),
						src_reg(bytes, pc), off1));
			}
		} else if (bytes[pc * INSN_SIZE] == BPF_STXDW &&
			   bytes[(pc + 1) * INSN_SIZE] == BPF_STXDW &&
			   dst_reg(bytes, pc) == dst_reg(bytes, pc + 1) &&
			   target_has_kinsn(targets, "bpf_arm64_stp_x") &&
			   range_is_replaceable(bytes, pc, 2)) {
			const int16_t off0 = read_off(bytes, pc);
			const int16_t off1 = read_off(bytes, pc + 1);
			if (off1 == off0 + 8 && arm64_ldstp_soff_ok(off0)) {
				append_kinsn_pair(
					replacement, targets, "bpf_arm64_stp_x",
					pack_arm64_pair_payload(
						src_reg(bytes, pc),
						src_reg(bytes, pc + 1),
						dst_reg(bytes, pc), off0));
			} else if (off0 == off1 + 8 &&
				   arm64_ldstp_soff_ok(off1)) {
				append_kinsn_pair(
					replacement, targets, "bpf_arm64_stp_x",
					pack_arm64_pair_payload(
						src_reg(bytes, pc + 1),
						src_reg(bytes, pc),
						dst_reg(bytes, pc), off1));
			}
		}
		if (replacement.empty()) {
			pc++;
			continue;
		}
		replace_insn_range(bytes, pc, 2, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
	}
	return applied;
}

int64_t apply_bulk_memory_bytecode_kinsns(std::vector<uint8_t> &bytes,
					  const KinsnTargetMap &targets,
					  KinsnTargetArch target_arch)
{
	if (kinsn_target_arch_is_arm64(target_arch, targets)) {
		return apply_arm64_pair_memory_bytecode_kinsns(
			bytes, targets, target_arch);
	}
	if (!kinsn_target_arch_is_x86(target_arch, targets)) {
		return 0;
	}
	constexpr size_t MinBulkBytes = 16;
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		if (const auto first = memcpy_lane_at(bytes, pc)) {
			std::vector<MemcpyLane> lanes{ *first };
			size_t pairs = 1;
			size_t cursor = pc + 2;
			while (const auto lane = memcpy_lane_at(bytes, cursor)) {
				const int next_src = first->src_off +
						     static_cast<int>(pairs *
								      first->width);
				const int next_dst = first->dst_off +
						     static_cast<int>(pairs *
								      first->width);
				if (lane->width != first->width ||
				    lane->src_base != first->src_base ||
					    lane->dst_base != first->dst_base ||
					    lane->src_off != next_src ||
					    lane->dst_off != next_dst) {
					break;
				}
				lanes.push_back(*lane);
				pairs++;
				cursor += 2;
			}
			const size_t total_bytes = pairs * first->width;
			const size_t old_len = pairs * 2;
			if (total_bytes >= MinBulkBytes &&
			    range_is_replaceable(bytes, pc, old_len) &&
			    !(first->src_base == first->dst_base &&
			      byte_ranges_overlap_i16(first->src_off,
						      first->dst_off,
						      total_bytes)) &&
			    memcpy_temps_dead_after(bytes, pc + old_len,
						    lanes)) {
				const auto replacement =
					emit_memcpy_lane_kinsns(targets, *first,
								pairs);
				replace_insn_range(bytes, pc, old_len,
						    replacement);
				applied++;
				pc += replacement.size() / INSN_SIZE;
				continue;
			}

			while (const auto lane = memcpy_lane_at(bytes, cursor)) {
				if (lane->width != first->width ||
				    lane->src_base != first->src_base ||
				    lane->dst_base != first->dst_base) {
					break;
				}
				lanes.push_back(*lane);
				cursor += 2;
			}
			size_t unordered_bytes = 0;
			int16_t min_src_off = 0;
			int16_t min_dst_off = 0;
			const size_t unordered_old_len = lanes.size() * 2;
			if (lanes.size() > pairs &&
			    lanes_cover_contiguous_copy(lanes, unordered_bytes,
							min_src_off,
							min_dst_off) &&
			    unordered_bytes >= MinBulkBytes &&
			    range_is_replaceable(bytes, pc, unordered_old_len) &&
			    !(first->src_base == first->dst_base &&
			      byte_ranges_overlap_i16(min_src_off, min_dst_off,
						      unordered_bytes)) &&
			    memcpy_temps_dead_after(bytes, pc + unordered_old_len,
						    lanes)) {
				const auto replacement =
					emit_memcpy_lanes_kinsns(targets, lanes);
				replace_insn_range(bytes, pc, unordered_old_len,
						    replacement);
				applied++;
				pc += replacement.size() / INSN_SIZE;
				continue;
			}
		}

		if (const auto first = memset_lane_at(bytes, pc)) {
			std::vector<MemsetLane> lanes{ *first };
			size_t total_bytes = first->width;
			size_t cursor = pc + 1;
			while (const auto lane = memset_lane_at(bytes, cursor)) {
				const int next_off =
					first->off + static_cast<int>(total_bytes);
				if (lane->base != first->base ||
				    lane->fill != first->fill ||
				    lane->off != next_off) {
					break;
				}
				total_bytes += lane->width;
				lanes.push_back(*lane);
				cursor++;
			}
			if (total_bytes >= MinBulkBytes &&
			    range_is_replaceable(bytes, pc, lanes.size())) {
				const auto replacement =
					emit_memset_lane_kinsns(targets, lanes);
				replace_insn_range(bytes, pc, lanes.size(),
						    replacement);
				applied++;
				pc += replacement.size() / INSN_SIZE;
				continue;
			}
		}
		pc++;
	}
	return applied;
}

std::optional<uint8_t> memory_base_reg(const std::vector<uint8_t> &bytes,
				       size_t pc)
{
	const uint8_t opcode = bytes[pc * INSN_SIZE];
	if (is_ldx_mem_opcode(opcode)) {
		return src_reg(bytes, pc);
	}
	if (is_st_mem_opcode(opcode) || is_stx_mem_opcode(opcode)) {
		return dst_reg(bytes, pc);
	}
	return std::nullopt;
}

bool previous_is_same_prefetch(const std::vector<uint8_t> &bytes, size_t pc,
			       uint8_t ptr_reg)
{
	if (pc < 2 || !is_kinsn_sidecar(bytes, pc - 2) ||
	    !is_kinsn_call(bytes, pc - 1)) {
		return false;
	}
	return (read_kinsn_sidecar_payload(bytes, pc - 2) & 0xf) == ptr_reg;
}

std::optional<std::string_view>
prefetch_target_name(const KinsnTargetMap &targets, KinsnTargetArch target_arch)
{
	if (kinsn_target_arch_is_arm64(target_arch, targets) &&
	    target_has_kinsn(targets, "bpf_arm64_prfm_pldl1keep")) {
		return "bpf_arm64_prfm_pldl1keep";
	}
	if (kinsn_target_arch_is_x86(target_arch, targets) &&
	    target_has_kinsn(targets, "bpf_x86_prefetcht0")) {
		return "bpf_x86_prefetcht0";
	}
	return std::nullopt;
}

bool scan_prefetch_alias_path(std::vector<uint8_t> &bytes,
			      const KinsnTargetMap &targets,
			      std::string_view target_name, size_t start,
			      size_t scan_end, std::array<uint8_t, 11> alias,
			      size_t &next_pc, int64_t &applied)
{
	for (size_t scan = start; scan < scan_end; scan++) {
		const uint8_t opcode = bytes[scan * INSN_SIZE];
		if (const auto base = memory_base_reg(bytes, scan)) {
			if (*base < alias.size() && alias[*base]) {
				if (!previous_is_same_prefetch(bytes, scan, *base)) {
					std::vector<uint8_t> replacement;
					append_kinsn_pair(replacement, targets,
							  target_name,
							  pack_u4(*base, 0));
					replace_insn_range(bytes, scan, 0,
							    replacement);
					applied++;
				}
				next_pc = scan + 2;
				return true;
			}
		}
		if (opcode == BPF_EXIT || opcode == BPF_JA ||
		    is_conditional_jump(opcode) || opcode == BPF_CALL ||
		    opcode == BPF_CALLX || opcode == BPF_LD_IMM64) {
			break;
		}
		if (opcode == BPF_MOV64_X) {
			alias[dst_reg(bytes, scan)] =
				src_reg(bytes, scan) < alias.size() ?
					alias[src_reg(bytes, scan)] :
					0;
		} else if ((opcode == BPF_ADD64_K ||
			    opcode == BPF_SUB64_K) &&
			   dst_reg(bytes, scan) < alias.size() &&
			   alias[dst_reg(bytes, scan)]) {
			alias[dst_reg(bytes, scan)] = 1;
		} else if (opcode_defines_dst(opcode) &&
			   dst_reg(bytes, scan) < alias.size()) {
			alias[dst_reg(bytes, scan)] = 0;
		}
	}
	return false;
}

int64_t apply_prefetch_bytecode_kinsns(std::vector<uint8_t> &bytes,
				       const KinsnTargetMap &targets,
				       KinsnTargetArch target_arch)
{
	const auto target_name = prefetch_target_name(targets, target_arch);
	if (!target_name) {
		return 0;
	}
	int64_t applied = 0;
	size_t pc = 0;
	while (pc < bytes.size() / INSN_SIZE) {
		if (bytes[pc * INSN_SIZE] != BPF_CALL ||
		    src_reg(bytes, pc) != 0 ||
		    read_imm(bytes, pc) != BPF_FUNC_map_lookup_elem) {
			pc++;
			continue;
		}
		std::array<uint8_t, 11> alias{};
		alias[0] = 1;
		const size_t insn_count = bytes.size() / INSN_SIZE;
		bool inserted = false;
		if (pc + 1 < insn_count &&
		    bytes[(pc + 1) * INSN_SIZE] == BPF_JEQ64_K &&
		    dst_reg(bytes, pc + 1) == 0 &&
		    read_imm(bytes, pc + 1) == 0 &&
		    read_off(bytes, pc + 1) > 0) {
			const size_t target_pc =
				pc + 2 + static_cast<size_t>(read_off(bytes, pc + 1));
			if (target_pc <= insn_count) {
				const size_t scan_end =
					std::min(target_pc, pc + 65);
				inserted = scan_prefetch_alias_path(
					bytes, targets, *target_name, pc + 2,
					scan_end, alias, pc, applied);
			}
		}
		if (!inserted) {
			const size_t scan_end =
				std::min(bytes.size() / INSN_SIZE, pc + 65);
			inserted = scan_prefetch_alias_path(
				bytes, targets, *target_name, pc + 1, scan_end,
				alias, pc, applied);
		}
		if (!inserted) {
			pc++;
		}
	}
	return applied;
}

bool bytecode_kinsn_family_enabled(std::string_view pass, std::string_view family,
				   const BytecodeKinsnPolicy &policy)
{
	bool enabled = pass == "kinsn" || pass == family;
	if (policy.all_enabled) {
		enabled = *policy.all_enabled;
	}
	const auto it = policy.family_enabled.find(std::string(family));
	if (it != policy.family_enabled.end()) {
		enabled = it->second;
	}
	return enabled;
}

int64_t apply_bytecode_kinsn_recovery(std::vector<uint8_t> &bytes,
				      std::string_view pass,
				      const BytecodeKinsnPolicy &policy,
				      const KinsnTargetMap &targets,
				      KinsnTargetArch target_arch,
				      std::vector<std::string> &diagnostics)
{
	const bool is_x86 = kinsn_target_arch_is_x86(target_arch, targets);
	const bool is_arm64 = kinsn_target_arch_is_arm64(target_arch, targets);
	if (!is_x86 && !is_arm64) {
		return 0;
	}
	const int64_t before = count_kinsn_calls(bytes);
	if (is_arm64) {
		if (bytecode_kinsn_family_enabled(pass, "ccmp", policy)) {
			apply_ccmp_bytecode_kinsns(bytes, targets, target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "cond_select", policy)) {
			apply_cond_select_bytecode_kinsns(bytes, targets,
							 target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "rotate", policy)) {
			apply_rotate_bytecode_kinsns(bytes, targets, target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "extract", policy)) {
			apply_extract_bytecode_kinsns(bytes, targets,
						      target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "endian_fusion", policy)) {
			apply_endian_bytecode_kinsns(bytes, targets,
						     target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "bulk_memory", policy)) {
			apply_bulk_memory_bytecode_kinsns(bytes, targets,
							 target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "prefetch", policy)) {
			apply_prefetch_bytecode_kinsns(bytes, targets,
						       target_arch);
		}
	} else {
		if (bytecode_kinsn_family_enabled(pass, "bitops", policy)) {
			apply_popcnt_bytecode_kinsns(bytes, targets);
			apply_bzhi_bytecode_kinsns(bytes, targets);
			apply_bmi2_shift_bytecode_kinsns(bytes, targets);
			apply_bmi1_bytecode_kinsns(bytes, targets);
		}
		if (bytecode_kinsn_family_enabled(pass, "rotate", policy)) {
			apply_rotate_bytecode_kinsns(bytes, targets, target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "extract", policy)) {
			apply_extract_bytecode_kinsns(bytes, targets,
						      target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "endian_fusion", policy)) {
			apply_endian_bytecode_kinsns(bytes, targets,
						     target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "bulk_memory", policy)) {
			apply_bulk_memory_bytecode_kinsns(bytes, targets,
							 target_arch);
		}
		if (bytecode_kinsn_family_enabled(pass, "prefetch", policy)) {
			apply_prefetch_bytecode_kinsns(bytes, targets,
						       target_arch);
		}
	}
	const int64_t after = count_kinsn_calls(bytes);
	if (after > before) {
		diagnostics.push_back("bytecode_kinsn_recovery_applied=" +
				      std::to_string(after - before));
	}
	return after - before;
}
