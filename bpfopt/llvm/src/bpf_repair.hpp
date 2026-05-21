// SPDX-License-Identifier: MIT
// Part of bpfopt-llvm. Included inside the anonymous namespace of main.cpp,
// which supplies the system/LLVM include prelude. Not standalone-compilable.

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
