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
constexpr uint8_t BPF_SUB64_K = 0x17;
constexpr uint8_t BPF_LSH32_K = 0x64;
constexpr uint8_t BPF_RSH32_K = 0x74;
constexpr uint8_t BPF_AND32_X = 0x5c;
constexpr uint8_t BPF_OR32_X = 0x4c;
constexpr uint8_t BPF_END_BE = 0xdc;
constexpr uint8_t BPF_END_LE = 0xd4;
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
	if (klass == BPF_ALU_CLASS || klass == BPF_ALU64_CLASS ||
	    klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS) {
		if ((opcode & 0x08) && src == reg) {
			return true;
		}
	}
	if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
	    src_reg(bytes, pc) != BPF_PSEUDO_CALL) {
		return reg >= 1 && reg <= 5;
	}
	if (opcode == BPF_EXIT) {
		return reg == 0;
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
					     const RotateSite &site)
{
	std::vector<uint8_t> out;
	if (site.preinit_proof_scratch) {
		const auto init = make_bpf_insn(BPF_MOV64_K,
						rotate_proof_scratch(site), 0,
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
		append_kinsn_pair(out, targets, "bpf_x86_rorxl",
				  pack_x86_rotate_payload(
					  site.dst, site.val,
					  static_cast<uint8_t>(site.shift)));
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
				     const KinsnTargetMap &targets)
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
	for (auto it = sites.rbegin(); it != sites.rend(); ++it) {
		const auto replacement = emit_rotate_replacement(targets, *it);
		replace_insn_range(bytes, it->start, it->old_len, replacement);
	}
	return static_cast<int64_t>(sites.size());
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

int64_t apply_extract_bytecode_kinsns(std::vector<uint8_t> &bytes,
				      const KinsnTargetMap &targets)
{
	int64_t applied = 0;
	size_t pc = 0;
	while (pc + 1 < bytes.size() / INSN_SIZE) {
		if (bytes[pc * INSN_SIZE] != BPF_RSH64_K ||
		    bytes[(pc + 1) * INSN_SIZE] != BPF_AND64_K ||
		    dst_reg(bytes, pc) != dst_reg(bytes, pc + 1) ||
		    !range_is_replaceable(bytes, pc, 2)) {
			pc++;
			continue;
		}
		const int32_t shift_imm = read_imm(bytes, pc);
		if (shift_imm < 0 || shift_imm >= 64) {
			pc++;
			continue;
		}
		const uint64_t mask = static_cast<uint64_t>(
			static_cast<int64_t>(read_imm(bytes, pc + 1)));
		const auto bit_len = low_mask_width(mask);
		if (!bit_len || shift_imm + static_cast<int32_t>(*bit_len) > 64 ||
		    (*bit_len > 32 && *bit_len != 64)) {
			pc++;
			continue;
		}
		std::vector<uint8_t> replacement;
		const uint8_t dst = dst_reg(bytes, pc);
		const auto ctl_reg =
			find_dead_scratch_reg_after(bytes, pc + 2, { dst });
		if (!ctl_reg) {
			pc++;
			continue;
		}
		const uint32_t ctl =
			static_cast<uint32_t>(shift_imm) |
			(static_cast<uint32_t>(*bit_len) << 8);
		const auto ctl_mov = make_bpf_insn(BPF_MOV64_K, *ctl_reg, 0, 0,
						   static_cast<int32_t>(ctl));
		replacement.insert(replacement.end(), ctl_mov.begin(), ctl_mov.end());
		append_kinsn_pair(replacement, targets, "bpf_x86_bextrq",
				  pack_x86_bextr_payload(dst, dst, *ctl_reg));
		replace_insn_range(bytes, pc, 2, replacement);
		applied++;
		pc += replacement.size() / INSN_SIZE;
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

struct EndianSite {
	size_t start = 0;
	size_t old_len = 0;
	uint8_t dst = 0;
	uint8_t base = 0;
	int16_t off = 0;
	int load_bytes = 0;
	int bytes = 0;
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

int64_t apply_endian_bytecode_kinsns(std::vector<uint8_t> &bytes,
				     const KinsnTargetMap &targets)
{
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

int64_t apply_bulk_memory_bytecode_kinsns(std::vector<uint8_t> &bytes,
					  const KinsnTargetMap &targets)
{
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

int64_t apply_prefetch_bytecode_kinsns(std::vector<uint8_t> &bytes,
				       const KinsnTargetMap &targets)
{
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
		const size_t scan_end = std::min(bytes.size() / INSN_SIZE, pc + 65);
		bool inserted = false;
		for (size_t scan = pc + 1; scan < scan_end; scan++) {
			const uint8_t opcode = bytes[scan * INSN_SIZE];
			if (const auto base = memory_base_reg(bytes, scan)) {
				if (*base < alias.size() && alias[*base]) {
					if (!previous_is_same_prefetch(bytes, scan,
								       *base)) {
						std::vector<uint8_t> replacement;
						append_kinsn_pair(
							replacement, targets,
							"bpf_x86_prefetcht0",
							pack_u4(*base, 0));
						replace_insn_range(bytes, scan, 0,
								    replacement);
						applied++;
					}
					pc = scan + 2;
					inserted = true;
					break;
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
		if (!inserted) {
			pc++;
		}
	}
	return applied;
}

bool bytecode_kinsn_family_enabled(std::string_view pass, std::string_view family)
{
	return pass == "kinsn" || pass == family;
}

int64_t apply_bytecode_kinsn_recovery(std::vector<uint8_t> &bytes,
				      std::string_view pass,
				      const KinsnTargetMap &targets,
				      std::vector<std::string> &diagnostics)
{
	if (!target_is_x86_kinsn_set(targets)) {
		return 0;
	}
	const int64_t before = count_kinsn_calls(bytes);
	if (bytecode_kinsn_family_enabled(pass, "rotate")) {
		apply_rotate_bytecode_kinsns(bytes, targets);
	}
	if (bytecode_kinsn_family_enabled(pass, "extract")) {
		apply_extract_bytecode_kinsns(bytes, targets);
	}
	if (bytecode_kinsn_family_enabled(pass, "endian_fusion")) {
		apply_endian_bytecode_kinsns(bytes, targets);
	}
	if (bytecode_kinsn_family_enabled(pass, "bulk_memory")) {
		apply_bulk_memory_bytecode_kinsns(bytes, targets);
	}
	if (bytecode_kinsn_family_enabled(pass, "prefetch")) {
		apply_prefetch_bytecode_kinsns(bytes, targets);
	}
	const int64_t after = count_kinsn_calls(bytes);
	if (after > before) {
		diagnostics.push_back("bytecode_kinsn_recovery_applied=" +
				      std::to_string(after - before));
	}
	return after - before;
}
