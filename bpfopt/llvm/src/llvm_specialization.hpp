// SPDX-License-Identifier: MIT
// Deployment-informed LLVM transformations for bpfopt.
// Included inside main.cpp's anonymous namespace after llvm_mapinline.hpp.

struct SpecializationProfileOptions {
	std::filesystem::path profile;
	std::string program_hash;
	bool phase_stable = false;
	bool layout_hot_roots = false;
	bool layout_versioned_program_roots = false;
};

SpecializationProfileOptions
parse_specialization_profile_args(std::string_view pass,
				  const std::vector<std::string> &args)
{
	SpecializationProfileOptions options;
	bool have_profile = false;
	bool have_program_hash = false;
	for (size_t i = 0; i < args.size(); i++) {
		const std::string &arg = args[i];
		if (arg == "--profile") {
			if (++i >= args.size()) {
				throw std::runtime_error(std::string(pass) +
							 " --profile requires FILE");
			}
			options.profile = args[i];
			have_profile = true;
		} else if (arg.starts_with("--profile=")) {
			options.profile = arg.substr(std::strlen("--profile="));
			have_profile = true;
		} else if (arg == "--program-hash") {
			if (++i >= args.size()) {
				throw std::runtime_error(std::string(pass) +
							 " --program-hash requires 16-HEX");
			}
			options.program_hash = args[i];
			have_program_hash = true;
		} else if (arg.starts_with("--program-hash=")) {
			options.program_hash = arg.substr(
				std::strlen("--program-hash="));
			have_program_hash = true;
		} else if (arg == "--phase-stable") {
			if (pass != "tail_call_icache") {
				throw std::runtime_error(std::string(pass) +
							 " does not accept --phase-stable");
			}
			options.phase_stable = true;
		} else if (arg == "--layout-hot-roots") {
			if (pass != "hot_region_version") {
				throw std::runtime_error(
					std::string(pass) +
					" does not accept --layout-hot-roots");
			}
			options.layout_hot_roots = true;
		} else if (arg == "--layout-versioned-program-roots") {
			if (pass != "hot_region_version") {
				throw std::runtime_error(
					std::string(pass) +
					" does not accept --layout-versioned-program-roots");
			}
			options.layout_versioned_program_roots = true;
		} else {
			throw std::runtime_error(std::string(pass) +
						 " unknown pass-local arg: " + arg);
		}
	}
	if (!have_profile || options.profile.empty()) {
		throw std::runtime_error(std::string(pass) + " requires --profile");
	}
	if (!have_program_hash || options.program_hash.size() != 16 ||
	    !std::all_of(options.program_hash.begin(), options.program_hash.end(),
			 [](unsigned char c) { return std::isxdigit(c); })) {
		throw std::runtime_error(std::string(pass) +
					 " requires --program-hash 16-HEX");
	}
	std::transform(options.program_hash.begin(), options.program_hash.end(),
		       options.program_hash.begin(), [](unsigned char c) {
			       return static_cast<char>(std::tolower(c));
		       });
	return options;
}

uint64_t specialization_u64_field(const llvm::json::Object &object,
				  std::string_view key,
				  std::string_view context)
{
	const auto value = object.getInteger(key);
	if (!value || *value < 0) {
		throw std::runtime_error(std::string(context) + " missing nonnegative " +
					 std::string(key));
	}
	return static_cast<uint64_t>(*value);
}

std::string specialization_string_field(const llvm::json::Object &object,
					std::string_view key,
					std::string_view context)
{
	const auto value = object.getString(key);
	if (!value || value->empty()) {
		throw std::runtime_error(std::string(context) + " missing " +
					 std::string(key));
	}
	return value->str();
}

size_t specialization_parse_pc(std::string_view text,
			       std::string_view context)
{
	if (text.empty() ||
	    !std::all_of(text.begin(), text.end(), [](unsigned char c) {
		    return std::isdigit(c);
	    })) {
		throw std::runtime_error(std::string(context) +
					 " has a non-decimal pc key");
	}
	size_t consumed = 0;
	const unsigned long long value = std::stoull(std::string(text), &consumed);
	if (consumed != text.size() || value > std::numeric_limits<size_t>::max()) {
		throw std::runtime_error(std::string(context) + " pc is out of range");
	}
	return static_cast<size_t>(value);
}

const llvm::json::Object &specialization_profile_root(
	llvm::json::Value &value, const std::filesystem::path &path,
	std::string_view expected_pass, std::string_view expected_program_hash)
{
	auto *root = value.getAsObject();
	if (!root) {
		throw std::runtime_error(path.string() + " root is not an object");
	}
	const uint64_t schema_version = specialization_u64_field(
		*root, "schema_version", path.string());
	if (schema_version != 1) {
		throw std::runtime_error(path.string() +
					 " has unsupported schema_version " +
					 std::to_string(schema_version));
	}
	const std::string pass = specialization_string_field(
		*root, "pass", path.string());
	if (pass != expected_pass) {
		throw std::runtime_error(path.string() + " pass is " + pass +
					 ", expected " + std::string(expected_pass));
	}
	std::string program_hash = specialization_string_field(
		*root, "program_hash", path.string());
	std::transform(program_hash.begin(), program_hash.end(),
		       program_hash.begin(), [](unsigned char c) {
			       return static_cast<char>(std::tolower(c));
		       });
	if (program_hash.size() != 16 ||
	    !std::all_of(program_hash.begin(), program_hash.end(),
			 [](unsigned char c) { return std::isxdigit(c); })) {
		throw std::runtime_error(path.string() +
					 " has invalid program_hash");
	}
	if (program_hash != expected_program_hash) {
		throw std::runtime_error(path.string() + " program_hash is " +
					 program_hash + ", expected " +
					 std::string(expected_program_hash));
	}
	return *root;
}

bool specialization_is_jump_class(uint8_t opcode)
{
	const uint8_t klass = opcode & BPF_CLASS_MASK;
	return klass == BPF_JMP_CLASS || klass == BPF_JMP32_CLASS;
}

bool specialization_is_conditional_jump(uint8_t opcode)
{
	if (!specialization_is_jump_class(opcode)) {
		return false;
	}
	const uint8_t operation = opcode & 0xf0;
	return operation != 0x00 && operation != 0x80 && operation != 0x90;
}

std::vector<size_t>
specialization_block_start_by_pc(const std::vector<uint8_t> &input)
{
	if (input.empty() || input.size() % INSN_SIZE != 0) {
		throw std::runtime_error(
			"specialization input length must be a non-empty multiple of 8");
	}
	const size_t insn_count = input.size() / INSN_SIZE;
	const size_t codegen_end = subprog_start_pc(input).value_or(insn_count);
	std::vector<bool> starts(codegen_end, false);
	if (codegen_end == 0) {
		return {};
	}
	starts[0] = true;
	for (size_t pc = 0; pc < codegen_end; pc++) {
		if (pc > 0 && specialization_is_jump_class(
				      input[(pc - 1) * INSN_SIZE])) {
			starts[pc] = true;
		}
		const uint8_t opcode = input[pc * INSN_SIZE];
		int64_t target = -1;
		if (opcode == BPF_JA) {
			target = static_cast<int64_t>(pc) + 1 + read_off(input, pc);
		} else if (opcode == BPF_JA_IMM) {
			target = static_cast<int64_t>(pc) + 1 + read_imm(input, pc);
		} else if (specialization_is_conditional_jump(opcode)) {
			target = static_cast<int64_t>(pc) + 1 + read_off(input, pc);
		}
		if (target >= 0) {
			if (target >= static_cast<int64_t>(codegen_end)) {
				throw std::runtime_error(
					"specialization control-flow target leaves lifted entry function at pc " +
					std::to_string(pc));
			}
			starts[static_cast<size_t>(target)] = true;
		}
	}
	std::vector<size_t> result(codegen_end, 0);
	size_t current = 0;
	for (size_t pc = 0; pc < codegen_end; pc++) {
		if (starts[pc]) {
			current = pc;
		}
		result[pc] = current;
	}
	return result;
}

llvm::BasicBlock *specialization_find_block(llvm::Function &function,
					    size_t start_pc)
{
	const std::string name = "bb_inst_" + std::to_string(start_pc);
	for (llvm::BasicBlock &block : function) {
		if (block.getName() == name) {
			return &block;
		}
	}
	return nullptr;
}

// --- Dynamic tail-call inline cache ---------------------------------------

struct TailCallIcacheProfileKey {
	uint32_t key = 0;
	uint64_t count = 0;
};

struct TailCallIcacheProfileSite {
	std::vector<TailCallIcacheProfileKey> keys;
	uint64_t observations = 0;
};

using TailCallIcacheProfile = std::map<size_t, TailCallIcacheProfileSite>;

TailCallIcacheProfile
read_tail_call_icache_profile(const SpecializationProfileOptions &options)
{
	const auto &path = options.profile;
	if (!std::filesystem::exists(path)) {
		throw std::runtime_error("tail_call_icache profile missing: " +
					 path.string());
	}
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	const auto &root = specialization_profile_root(
		value, path, "tail_call_icache", options.program_hash);
	const auto *per_site = root.getObject("per_site");
	if (!per_site) {
		throw std::runtime_error(
			"tail_call_icache profile requires per_site");
	}
	TailCallIcacheProfile profile;
	for (const auto &entry : *per_site) {
		const size_t pc = specialization_parse_pc(
			entry.getFirst().str(), "tail_call_icache per_site");
		const auto &site = json_object(
			entry.getSecond(), "tail_call_icache per_site[" +
					   std::to_string(pc) + "]");
		const uint64_t observations = specialization_u64_field(
			site, "observations", "tail_call_icache site");
		const auto *keys = site.getArray("keys");
		if (observations == 0 || !keys || keys->empty()) {
			throw std::runtime_error(
				"tail_call_icache invalid observations/keys at pc " +
				std::to_string(pc));
		}
		TailCallIcacheProfileSite parsed_site;
		parsed_site.observations = observations;
		std::set<uint32_t> unique_keys;
		uint64_t previous_count = std::numeric_limits<uint64_t>::max();
		uint64_t selected_count = 0;
		for (const auto &key_entry : *keys) {
			const auto &key_object = json_object(
				key_entry, "tail_call_icache key");
			const uint64_t key = specialization_u64_field(
				key_object, "key", "tail_call_icache key");
			const uint64_t count = specialization_u64_field(
				key_object, "count", "tail_call_icache key");
			if (key > std::numeric_limits<uint32_t>::max() ||
			    count == 0 || count > previous_count ||
			    count > observations - selected_count ||
			    !unique_keys.insert(static_cast<uint32_t>(key)).second) {
				throw std::runtime_error(
					"tail_call_icache invalid ordered key distribution at pc " +
					std::to_string(pc));
			}
			parsed_site.keys.push_back(TailCallIcacheProfileKey{
				static_cast<uint32_t>(key), count });
			selected_count += count;
			previous_count = count;
		}
		profile.emplace(pc, std::move(parsed_site));
	}
	return profile;
}

std::array<uint8_t, INSN_SIZE>
tail_call_icache_insn(uint8_t opcode, uint8_t dst, uint8_t src,
		      int16_t off, int32_t imm)
{
	std::array<uint8_t, INSN_SIZE> insn{};
	insn[0] = opcode;
	insn[1] = static_cast<uint8_t>((dst & 0x0f) | ((src & 0x0f) << 4));
	std::memcpy(insn.data() + 2, &off, sizeof(off));
	std::memcpy(insn.data() + 4, &imm, sizeof(imm));
	return insn;
}

bool tail_call_key_is_immediate_constant(const std::vector<uint8_t> &input,
					 size_t call_pc, uint32_t hot_key)
{
	if (call_pc == 0)
		return false;
	const size_t key_pc = call_pc - 1;
	const uint8_t opcode = input[key_pc * INSN_SIZE];
	if ((opcode != 0xb4 && opcode != 0xb7) ||
	    dst_reg(input, key_pc) != 3)
		return false;
	return static_cast<uint32_t>(read_imm(input, key_pc)) == hot_key;
}

bool tail_call_range_has_non_fallthrough_predecessor(
	const std::vector<uint8_t> &input, size_t definition_pc, size_t call_pc)
{
	const size_t insn_count = input.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		const uint8_t opcode = input[pc * INSN_SIZE];
		int64_t target = -1;
		if (opcode == BPF_JA || specialization_is_conditional_jump(opcode)) {
			target = static_cast<int64_t>(pc) + 1 +
				 static_cast<int64_t>(read_off(input, pc));
		} else if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
			   src_reg(input, pc) == BPF_PSEUDO_CALL) {
			target = static_cast<int64_t>(pc) + 1 +
				 static_cast<int64_t>(read_imm(input, pc));
		} else if (opcode == BPF_LD_IMM64 &&
			   src_reg(input, pc) == BPF_PSEUDO_FUNC) {
			target = static_cast<int64_t>(pc) + 1 +
				 static_cast<int64_t>(read_imm(input, pc));
		}
		if (target > static_cast<int64_t>(definition_pc) &&
		    target <= static_cast<int64_t>(call_pc))
			return true;
	}
	return false;
}

std::optional<size_t> tail_call_replaceable_key_definition(
	const std::vector<uint8_t> &input, size_t call_pc)
{
	for (size_t scan = call_pc; scan > 0;) {
		const size_t pc = scan - 1;
		const uint8_t opcode = input[pc * INSN_SIZE];
		if (opcode == 0 && pc > 0 &&
		    input[(pc - 1) * INSN_SIZE] == BPF_LD_IMM64) {
			const size_t first_pc = pc - 1;
			if (dst_reg(input, first_pc) == 3 ||
			    src_reg(input, first_pc) == 3)
				return std::nullopt;
			scan = first_pc;
			continue;
		}
		if (opcode == BPF_CALL || opcode == BPF_CALLX ||
		    opcode == BPF_EXIT || opcode == BPF_JA ||
		    specialization_is_conditional_jump(opcode))
			return std::nullopt;
		const uint8_t insn_class = opcode & 0x07;
		if (dst_reg(input, pc) == 3 &&
		    (insn_class == 0x01 || insn_class == 0x04 ||
		     insn_class == 0x07)) {
			if (tail_call_range_has_non_fallthrough_predecessor(
				    input, pc, call_pc))
				return std::nullopt;
			return pc;
		}
		if (src_reg(input, pc) == 3 ||
		    ((insn_class == 0x02 || insn_class == 0x03) &&
		     dst_reg(input, pc) == 3))
			return std::nullopt;
		scan = pc;
	}
	return std::nullopt;
}

std::vector<uint8_t> specialize_tail_call_sites_raw(
	const std::vector<uint8_t> &input,
	const TailCallIcacheProfile &profile, bool phase_stable)
{
	constexpr uint8_t tail_call_key_reg = 3;
	constexpr uint8_t bpf_mov32_k = 0xb4;
	constexpr uint8_t bpf_jne32_k = 0x56;
	const size_t insn_count = input.size() / INSN_SIZE;
	std::vector<size_t> entry_pc(insn_count);
	std::vector<size_t> instruction_pc(insn_count);
	std::map<size_t, int32_t> replacement_keys;
	std::set<size_t> calls_with_replaced_keys;
	if (phase_stable) {
		for (const auto &[pc, site] : profile) {
			if (const auto key_pc =
				    tail_call_replaceable_key_definition(input, pc)) {
				replacement_keys.emplace(
					*key_pc,
					static_cast<int32_t>(site.keys.front().key));
				calls_with_replaced_keys.insert(pc);
			}
		}
	}
	std::vector<uint8_t> output;
	size_t guarded_key_count = 0;
	for (const auto &[_, site] : profile)
		guarded_key_count += site.keys.size();
	output.reserve(input.size() + guarded_key_count * 4 * INSN_SIZE);

	for (size_t pc = 0; pc < insn_count; pc++) {
		entry_pc[pc] = output.size() / INSN_SIZE;
		instruction_pc[pc] = entry_pc[pc];
		if (auto replacement = replacement_keys.find(pc);
		    replacement != replacement_keys.end()) {
			const auto constant_key = tail_call_icache_insn(
				bpf_mov32_k, tail_call_key_reg, 0, 0,
				replacement->second);
			output.insert(output.end(), constant_key.begin(),
				      constant_key.end());
			continue;
		}
		auto profiled = profile.find(pc);
		if (profiled != profile.end()) {
			if (phase_stable) {
				const auto constant_key = tail_call_icache_insn(
					bpf_mov32_k, tail_call_key_reg, 0, 0,
					static_cast<int32_t>(
						profiled->second.keys.front().key));
				if (!calls_with_replaced_keys.contains(pc)) {
					output.insert(output.end(), constant_key.begin(),
						      constant_key.end());
					instruction_pc[pc]++;
				}
			} else {
				const size_t key_count = profiled->second.keys.size();
				for (size_t key_index = 0; key_index < key_count;
				     key_index++) {
					const auto key =
						profiled->second.keys[key_index].key;
					const auto guard = tail_call_icache_insn(
						bpf_jne32_k, tail_call_key_reg, 0, 3,
						static_cast<int32_t>(key));
					const auto constant_key = tail_call_icache_insn(
						bpf_mov32_k, tail_call_key_reg, 0, 0,
						static_cast<int32_t>(key));
					std::array<uint8_t, INSN_SIZE> fast_call{};
					std::copy_n(
						input.begin() + pc * INSN_SIZE,
						INSN_SIZE, fast_call.begin());
					const int64_t skip =
						4 * static_cast<int64_t>(
							    key_count - key_index - 1) +
						1;
					if (skip > std::numeric_limits<int16_t>::max()) {
						throw std::runtime_error(
							"tail_call_icache PIC skip is out of range");
					}
					const auto skip_slow = tail_call_icache_insn(
						BPF_JA, 0, 0,
						static_cast<int16_t>(skip), 0);
					output.insert(output.end(), guard.begin(),
						      guard.end());
					output.insert(output.end(), constant_key.begin(),
						      constant_key.end());
					output.insert(output.end(), fast_call.begin(),
						      fast_call.end());
					output.insert(output.end(), skip_slow.begin(),
						      skip_slow.end());
				}
				instruction_pc[pc] += 4 * key_count;
			}
		}
		output.insert(output.end(), input.begin() + pc * INSN_SIZE,
			      input.begin() + (pc + 1) * INSN_SIZE);
	}

	auto mapped_target = [&](int64_t target) -> size_t {
		if (target < 0 || target >= static_cast<int64_t>(insn_count)) {
			throw std::runtime_error(
				"tail_call_icache branch target out of range");
		}
		return entry_pc[static_cast<size_t>(target)];
	};
	for (size_t old_pc = 0; old_pc < insn_count; old_pc++) {
		const size_t new_pc = instruction_pc[old_pc];
		const uint8_t opcode = input[old_pc * INSN_SIZE];
		if (opcode == BPF_JA || specialization_is_conditional_jump(opcode)) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_off(input, old_pc)));
			const int64_t new_off = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_off < std::numeric_limits<int16_t>::min() ||
			    new_off > std::numeric_limits<int16_t>::max()) {
				throw std::runtime_error(
					"tail_call_icache branch offset out of range");
			}
			write_off(output, new_pc, static_cast<int16_t>(new_off));
		} else if ((opcode == BPF_CALL || opcode == BPF_CALLX) &&
			   src_reg(input, old_pc) == BPF_PSEUDO_CALL) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(input, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"tail_call_icache call offset out of range");
			}
			write_imm(output, new_pc, static_cast<int32_t>(new_imm));
		} else if (opcode == BPF_LD_IMM64 &&
			   src_reg(input, old_pc) == BPF_PSEUDO_FUNC) {
			const size_t new_target = mapped_target(
				static_cast<int64_t>(old_pc) + 1 +
				static_cast<int64_t>(read_imm(input, old_pc)));
			const int64_t new_imm = static_cast<int64_t>(new_target) -
						static_cast<int64_t>(new_pc) - 1;
			if (new_imm < std::numeric_limits<int32_t>::min() ||
			    new_imm > std::numeric_limits<int32_t>::max()) {
				throw std::runtime_error(
					"tail_call_icache function offset out of range");
			}
			write_imm(output, new_pc, static_cast<int32_t>(new_imm));
		}
	}
	return output;
}

std::vector<uint8_t> run_tail_call_icache_roundtrip(
	const std::vector<uint8_t> &input,
	const SpecializationProfileOptions &options,
	PassReportCounts &report_counts)
{
	const auto profile = read_tail_call_icache_profile(options);
	if (profile.empty()) {
		report_counts.sites_applied = 0;
		report_counts.sites_matched = 0;
		report_counts.sites_skipped = 0;
		return input;
	}
	for (const auto &[pc, site] : profile) {
		if (pc >= input.size() / INSN_SIZE ||
		    input[pc * INSN_SIZE] != BPF_CALL ||
		    src_reg(input, pc) == BPF_PSEUDO_CALL ||
		    read_imm(input, pc) != 12) {
			throw std::runtime_error(
				"tail_call_icache profile pc " + std::to_string(pc) +
				" does not identify a tail_call helper");
		}
		if (tail_call_key_is_immediate_constant(
			    input, pc, site.keys.front().key)) {
			throw std::runtime_error(
				"tail_call_icache profile pc " + std::to_string(pc) +
				" already has the profiled constant key");
		}
	}
	if (options.phase_stable) {
		for (const auto &[pc, site] : profile) {
			if (site.keys.size() != 1 ||
			    site.keys.front().count != site.observations) {
				throw std::runtime_error(
					"tail_call_icache --phase-stable requires one perfect "
					"training key at pc " +
					std::to_string(pc));
			}
		}
	}
	report_counts.sites_applied = static_cast<int64_t>(profile.size());
	report_counts.sites_matched = static_cast<int64_t>(profile.size());
	report_counts.sites_skipped = 0;
	return specialize_tail_call_sites_raw(
		input, profile, options.phase_stable);
}

// --- Profile-directed loop unrolling -------------------------------------

struct LoopTripProfileSite {
	uint32_t trip_count = 0;
};

using LoopTripProfile = std::map<size_t, LoopTripProfileSite>;

LoopTripProfile read_loop_trip_profile(
	const SpecializationProfileOptions &options)
{
	const auto &path = options.profile;
	if (!std::filesystem::exists(path)) {
		throw std::runtime_error("loop_trip_spec profile missing: " +
					 path.string());
	}
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	const auto &root = specialization_profile_root(
		value, path, "loop_trip_spec", options.program_hash);
	const auto *per_loop = root.getObject("per_loop");
	if (!per_loop) {
		throw std::runtime_error(
			"loop_trip_spec profile requires per_loop");
	}
	LoopTripProfile profile;
	for (const auto &entry : *per_loop) {
		const size_t pc = specialization_parse_pc(
			entry.getFirst().str(), "loop_trip_spec per_loop");
		const auto &site = json_object(
			entry.getSecond(), "loop_trip_spec per_loop[" +
					   std::to_string(pc) + "]");
		const uint64_t trip_count = specialization_u64_field(
			site, "trip_count", "loop_trip_spec site");
		const uint64_t observations = specialization_u64_field(
			site, "observations", "loop_trip_spec site");
		const uint64_t backedge_count = specialization_u64_field(
			site, "backedge_count", "loop_trip_spec site");
		const uint64_t exit_count = specialization_u64_field(
			site, "exit_count", "loop_trip_spec site");
		const uint64_t latch_pc = specialization_u64_field(
			site, "latch_pc", "loop_trip_spec site");
		const bool count_overflow =
			backedge_count > std::numeric_limits<uint64_t>::max() - exit_count;
		const uint64_t estimated_trip = exit_count == 0
			? 0
			: observations / exit_count +
				  ((observations % exit_count) >=
				   (exit_count / 2 + exit_count % 2));
		if (trip_count < 2 || trip_count > 127 || observations == 0 ||
		    backedge_count == 0 || exit_count == 0 || count_overflow ||
		    backedge_count + exit_count != observations ||
		    estimated_trip != trip_count || latch_pc <= pc ||
		    latch_pc > std::numeric_limits<size_t>::max()) {
			throw std::runtime_error(
				"loop_trip_spec invalid site at header pc " +
				std::to_string(pc));
		}
		profile.emplace(pc, LoopTripProfileSite{
			static_cast<uint32_t>(trip_count) });
	}
	return profile;
}

llvm::MDNode *loop_unroll_metadata(llvm::LLVMContext &context,
				  uint32_t trip_count)
{
	auto temporary = llvm::MDNode::getTemporary(context, {});
	auto *count = llvm::MDNode::get(
		context,
		{ llvm::MDString::get(context, "llvm.loop.unroll.count"),
		  llvm::ConstantAsMetadata::get(
			  llvm::ConstantInt::get(llvm::Type::getInt32Ty(context),
						 trip_count)) });
	auto *loop_id = llvm::MDNode::getDistinct(
		context, { temporary.get(), count });
	loop_id->replaceOperandWith(0, loop_id);
	return loop_id;
}

std::vector<uint8_t> run_loop_trip_spec_roundtrip(
	const std::vector<uint8_t> &input,
	const SpecializationProfileOptions &options,
	PassReportCounts &report_counts)
{
	const auto profile = read_loop_trip_profile(options);
	if (profile.empty()) {
		report_counts.sites_applied = 0;
		report_counts.sites_matched = 0;
		report_counts.sites_skipped = 0;
		return input;
	}
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &llvm_module) {
		auto *function = llvm_module.getFunction("bpf_main");
		if (!function) {
			throw std::runtime_error("loop_trip_spec could not find bpf_main");
		}
		llvm::DominatorTree dominators(*function);
		llvm::LoopInfo loops(dominators);
		int64_t applied = 0;
		int64_t skipped = 0;
		for (const auto &[pc, site] : profile) {
			auto *header = specialization_find_block(*function, pc);
			if (!header) {
				throw std::runtime_error(
					"loop_trip_spec could not find header bb_inst_" +
					std::to_string(pc));
			}
			auto *loop = loops.getLoopFor(header);
			if (!loop || loop->getHeader() != header) {
				constexpr const char *reason = "not_loop_header";
				report_counts.skipped_sites.emplace_back(pc, reason);
				report_counts.skip_reasons[reason]++;
				skipped++;
				continue;
			}
			auto *latch = loop->getLoopLatch();
			if (!latch || !latch->getTerminator()) {
				constexpr const char *reason = "multiple_or_missing_latch";
				report_counts.skipped_sites.emplace_back(pc, reason);
				report_counts.skip_reasons[reason]++;
				skipped++;
				continue;
			}
			latch->getTerminator()->setMetadata(
				llvm::LLVMContext::MD_loop,
				loop_unroll_metadata(llvm_module.getContext(),
						     site.trip_count));
			applied++;
		}
		report_counts.sites_applied = applied;
		report_counts.sites_matched = static_cast<int64_t>(profile.size());
		report_counts.sites_skipped = skipped;
		if (applied == 0) {
			return input;
		}
		if (std::getenv("BPFOPT_DUMP_IR")) {
			llvm_module.print(llvm::errs(), nullptr);
		}
		return extract_relocated_text(emit_bpf_object(llvm_module), input,
					      nullptr);
	});
}

// --- Profile-guided hot-region versioning --------------------------------

struct HotRegionProfile {
	size_t root_pc = 0;
	uint64_t branch_count = 0;
	uint64_t taken = 0;
	uint64_t not_taken = 0;
};

std::vector<HotRegionProfile>
read_hot_region_profile(const SpecializationProfileOptions &options)
{
	const auto &path = options.profile;
	if (!std::filesystem::exists(path)) {
		throw std::runtime_error("hot_region_version profile missing: " +
					 path.string());
	}
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	const auto &root = specialization_profile_root(
		value, path, "hot_region_version", options.program_hash);
	const auto *per_site = root.getObject("per_site");
	if (!per_site) {
		throw std::runtime_error(
			"hot_region_version profile requires per_site");
	}
	std::vector<HotRegionProfile> profiles;
	for (const auto &entry : *per_site) {
		const size_t root_pc = specialization_parse_pc(
			entry.getFirst().str(), "hot_region_version per_site");
		const auto &site = json_object(
			entry.getSecond(), "hot_region_version per_site[" +
						   std::to_string(root_pc) + "]");
		const uint64_t branch_count = specialization_u64_field(
			site, "branch_count", "hot_region_version profile");
		const uint64_t taken = specialization_u64_field(
			site, "taken", "hot_region_version profile");
		const uint64_t not_taken = specialization_u64_field(
			site, "not_taken", "hot_region_version profile");
		if (branch_count == 0 ||
		    taken > std::numeric_limits<uint64_t>::max() - not_taken ||
		    taken + not_taken != branch_count || taken == not_taken) {
			throw std::runtime_error(
				"hot_region_version profile has invalid root counts");
		}
		profiles.push_back(HotRegionProfile{
			root_pc, branch_count, taken, not_taken });
	}
	return profiles;
}

struct SpecializationBranchSite {
	size_t pc = 0;
	size_t block_start_pc = 0;
	size_t target_pc = 0;
	size_t fallthrough_pc = 0;
};

SpecializationBranchSite specialization_branch_site(
	const std::vector<uint8_t> &input, size_t pc)
{
	const size_t insn_count = input.size() / INSN_SIZE;
	const size_t codegen_end = subprog_start_pc(input).value_or(insn_count);
	if (pc >= codegen_end ||
	    !specialization_is_conditional_jump(input[pc * INSN_SIZE])) {
		throw std::runtime_error(
			"hot_region_version root_pc is not a lifted conditional branch");
	}
	const int64_t target =
		static_cast<int64_t>(pc) + 1 + read_off(input, pc);
	if (target < 0 || target >= static_cast<int64_t>(codegen_end) ||
	    pc + 1 >= codegen_end) {
		throw std::runtime_error(
			"hot_region_version root branch leaves lifted entry function");
	}
	const auto block_starts = specialization_block_start_by_pc(input);
	return SpecializationBranchSite{
		pc, block_starts[pc], static_cast<size_t>(target), pc + 1 };
}

llvm::BasicBlock *branch_successor_for_raw_pc(llvm::BranchInst &branch,
					      size_t raw_pc,
					      size_t branch_pc)
{
	const std::string expected = "bb_inst_" + std::to_string(raw_pc);
	for (unsigned i = 0; i < branch.getNumSuccessors(); i++) {
		if (branch.getSuccessor(i)->getName() == expected) {
			return branch.getSuccessor(i);
		}
	}
	throw std::runtime_error(
		"hot_region_version could not map raw successor " + expected +
		" at pc " + std::to_string(branch_pc));
}

uint32_t hot_region_scale_weight(uint64_t value, uint64_t max_value)
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

void annotate_hot_region_root(
	llvm::Module &module, llvm::BranchInst &branch,
	const SpecializationBranchSite &site,
	const HotRegionProfile &profile)
{
	const uint64_t max_count = std::max(profile.taken, profile.not_taken);
	if (max_count == 0) {
		throw std::runtime_error(
			"hot_region_version cannot weight a zero-count root");
	}
	auto *target = branch_successor_for_raw_pc(
		branch, site.target_pc, site.pc);
	auto *fallthrough = branch_successor_for_raw_pc(
		branch, site.fallthrough_pc, site.pc);
	llvm::MDBuilder metadata(module.getContext());
	std::array<uint32_t, 2> weights{};
	for (unsigned i = 0; i < branch.getNumSuccessors(); i++) {
		auto *successor = branch.getSuccessor(i);
		if (successor == target) {
			weights[i] = hot_region_scale_weight(
				profile.taken, max_count);
		} else if (successor == fallthrough) {
			weights[i] = hot_region_scale_weight(
				profile.not_taken, max_count);
		} else {
			throw std::runtime_error(
				"hot_region_version root has an unexpected successor");
		}
	}
	branch.setMetadata(
		llvm::LLVMContext::MD_prof,
		metadata.createBranchWeights(weights[0], weights[1]));
}

llvm::Value *hot_region_mapped_value(llvm::Value *value,
				     llvm::ValueToValueMapTy &value_map)
{
	if (auto found = value_map.find(value); found != value_map.end()) {
		return found->second;
	}
	return value;
}

llvm::BasicBlock *clone_hot_dominated_region(
	llvm::BasicBlock &merge,
	const std::vector<llvm::BasicBlock *> &hot_predecessors,
	llvm::DominatorTree &dominators)
{
	auto *function = merge.getParent();
	if (!function || &merge == &function->getEntryBlock()) {
		throw std::runtime_error(
			"hot_region_version cannot clone the entry block");
	}
	if (hot_predecessors.empty()) {
		throw std::runtime_error(
			"hot_region_version has no hot merge predecessors");
	}
	const std::set<llvm::BasicBlock *> hot_predecessor_set(
		hot_predecessors.begin(), hot_predecessors.end());

	// Clone the complete single-entry tail controlled by the merge, rather
	// than only the first merge block.  Rejoining immediately after a
	// one-block clone sends independently-versioned verifier states into the
	// same downstream CFG and can destroy state pruning on large programs.
	// Keeping the dominated tail versioned also gives LLVM a much larger
	// region in which entry PHIs and their dependent computations can fold.
	std::vector<llvm::BasicBlock *> region;
	std::set<llvm::BasicBlock *> region_set;
	for (llvm::BasicBlock &block : *function) {
		if (dominators.dominates(&merge, &block)) {
			region.push_back(&block);
			region_set.insert(&block);
		}
	}
	if (region.empty() || !region_set.contains(&merge)) {
		throw std::runtime_error(
			"hot_region_version found no dominated hot region");
	}

	llvm::ValueToValueMapTy value_map;
	std::map<llvm::BasicBlock *, llvm::BasicBlock *> clones;
	llvm::BasicBlock *layout_after = hot_predecessors.front();
	for (llvm::BasicBlock *block : region) {
		auto *clone = llvm::CloneBasicBlock(
			block, value_map, ".hot", function);
		value_map[block] = clone;
		clones.emplace(block, clone);
		clone->moveAfter(layout_after);
		layout_after = clone;
	}
	for (llvm::BasicBlock *block : region) {
		for (llvm::Instruction &instruction : *clones.at(block)) {
			llvm::RemapInstruction(
				&instruction, value_map,
				llvm::RF_IgnoreMissingLocals |
					llvm::RF_NoModuleLevelChanges);
		}
	}
	auto *clone = clones.at(&merge);

	// The cloned region has only entries reached from the profiled hot
	// successor. Drop cold incoming values from its entry PHIs and remove the
	// hot incoming values from the original merge. A single hot incoming value
	// folds immediately; multiple hot-side paths retain a smaller PHI.
	for (auto original_it = merge.begin();
	     original_it != merge.end() && llvm::isa<llvm::PHINode>(*original_it);) {
		auto *original_phi = llvm::cast<llvm::PHINode>(&*original_it++);
		const auto mapped_phi = value_map.find(original_phi);
		if (mapped_phi == value_map.end()) {
			throw std::runtime_error(
				"hot_region_version clone is missing a PHI mapping");
		}
		auto *cloned_phi =
			llvm::cast<llvm::PHINode>(mapped_phi->second);
		for (int incoming =
			     static_cast<int>(cloned_phi->getNumIncomingValues()) - 1;
		     incoming >= 0; incoming--) {
			if (!hot_predecessor_set.contains(
				    cloned_phi->getIncomingBlock(incoming))) {
				cloned_phi->removeIncomingValue(incoming, false);
			}
		}
		if (cloned_phi->getNumIncomingValues() == 0) {
			throw std::runtime_error(
				"hot_region_version merge lacks hot incoming values");
		}
		for (llvm::BasicBlock *predecessor : hot_predecessors) {
			const int incoming =
				original_phi->getBasicBlockIndex(predecessor);
			if (incoming < 0) {
				throw std::runtime_error(
					"hot_region_version merge lacks a hot predecessor");
			}
			original_phi->removeIncomingValue(incoming, false);
		}
		if (cloned_phi->getNumIncomingValues() == 1) {
			auto *incoming_value = hot_region_mapped_value(
				cloned_phi->getIncomingValue(0), value_map);
			cloned_phi->replaceAllUsesWith(incoming_value);
			cloned_phi->eraseFromParent();
			value_map[original_phi] = incoming_value;
		}
	}

	// Every exit from the versioned region needs a corresponding cloned edge
	// in successor PHIs.
	for (llvm::BasicBlock *block : region) {
		for (llvm::BasicBlock *successor : llvm::successors(block)) {
			if (region_set.contains(successor)) {
				continue;
			}
			for (llvm::PHINode &phi : successor->phis()) {
				const int incoming = phi.getBasicBlockIndex(block);
				if (incoming >= 0) {
					phi.addIncoming(hot_region_mapped_value(
							phi.getIncomingValue(incoming),
							value_map),
						clones.at(block));
				}
			}
		}
	}

	// Values produced anywhere in the versioned region may be consumed after
	// an exit without an existing boundary PHI. Rebuild SSA so each path uses
	// the corresponding original or cloned definition.
	for (llvm::BasicBlock *block : region) {
		for (llvm::Instruction &original : *block) {
			if (original.getType()->isVoidTy() || original.isTerminator()) {
				continue;
			}
			const auto mapped = value_map.find(&original);
			if (mapped == value_map.end()) {
				continue;
			}
			std::vector<llvm::Use *> external_uses;
			for (llvm::Use &use : original.uses()) {
				auto *user =
					llvm::dyn_cast<llvm::Instruction>(use.getUser());
				if (!user || region_set.contains(user->getParent())) {
					continue;
				}
				if (auto *phi = llvm::dyn_cast<llvm::PHINode>(user)) {
					const unsigned operand = use.getOperandNo();
					if (operand < phi->getNumIncomingValues() &&
					    region_set.contains(
						    phi->getIncomingBlock(operand))) {
						continue;
					}
				}
				external_uses.push_back(&use);
			}
			if (external_uses.empty()) {
				continue;
			}
			llvm::SSAUpdater updater;
			const std::string join_name =
				(original.getName() + ".hot.join").str();
			updater.Initialize(original.getType(), join_name);
			updater.AddAvailableValue(block, &original);
			updater.AddAvailableValue(clones.at(block), mapped->second);
			for (llvm::Use *use : external_uses) {
				updater.RewriteUse(*use);
			}
		}
	}

	for (llvm::BasicBlock *predecessor : hot_predecessors) {
		auto *terminator = predecessor->getTerminator();
		bool redirected = false;
		for (unsigned i = 0; i < terminator->getNumSuccessors(); i++) {
			if (terminator->getSuccessor(i) == &merge) {
				terminator->setSuccessor(i, clone);
				redirected = true;
			}
		}
		if (!redirected) {
			throw std::runtime_error(
				"hot_region_version predecessor does not enter merge");
		}
	}
	return clone;
}

struct HotMerge {
	llvm::BasicBlock *block = nullptr;
	std::vector<llvm::BasicBlock *> predecessors;
};

std::optional<HotMerge>
find_hot_postdominating_merge(llvm::BasicBlock &root,
			      llvm::BasicBlock &hot_successor,
			      llvm::DominatorTree &dominators)
{
	auto *function = root.getParent();
	if (!function) {
		return std::nullopt;
	}
	llvm::PostDominatorTree post_dominators(*function);
	auto *root_node = post_dominators.getNode(&root);
	if (!root_node || !root_node->getIDom()) {
		return std::nullopt;
	}
	auto *merge = root_node->getIDom()->getBlock();
	if (!merge || merge == &root || merge == &hot_successor ||
	    dominators.dominates(&hot_successor, merge)) {
		return std::nullopt;
	}
	std::vector<llvm::BasicBlock *> hot_predecessors;
	for (llvm::BasicBlock *predecessor : llvm::predecessors(merge)) {
		if (!dominators.dominates(&hot_successor, predecessor)) {
			continue;
		}
		if (dominators.dominates(merge, predecessor)) {
			return std::nullopt;
		}
		hot_predecessors.push_back(predecessor);
	}
	if (hot_predecessors.empty() ||
	    hot_predecessors.size() == llvm::pred_size(merge)) {
		return std::nullopt;
	}
	return HotMerge{ merge, std::move(hot_predecessors) };
}

std::vector<uint8_t> run_hot_region_version_roundtrip(
	const std::vector<uint8_t> &input,
	const SpecializationProfileOptions &options,
	PassReportCounts &report_counts)
{
	const auto profiles = read_hot_region_profile(options);
	if (profiles.empty()) {
		report_counts.sites_applied = 0;
		report_counts.sites_matched = 0;
		report_counts.sites_skipped = 0;
		return input;
	}
	std::map<size_t, SpecializationBranchSite> raw_sites;
	for (const auto &profile : profiles)
		raw_sites.emplace(
			profile.root_pc,
			specialization_branch_site(input, profile.root_pc));
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &llvm_module) {
		auto machine = create_bpf_target_machine(
			llvm::CodeGenOptLevel::Aggressive);
#if LLVM_VERSION_MAJOR >= 19
		llvm_module.setTargetTriple(llvm::Triple("bpfel"));
#else
		llvm_module.setTargetTriple("bpfel");
#endif
		llvm_module.setDataLayout(machine->createDataLayout());
		promote_register_allocas(llvm_module, *machine);
		auto *function = llvm_module.getFunction("bpf_main");
		if (!function) {
			throw std::runtime_error(
				"hot_region_version could not find bpf_main");
		}
		llvm::DominatorTree initial_dominators(*function);
		std::vector<HotRegionProfile> ordered = profiles;
		std::sort(ordered.begin(), ordered.end(),
			  [&](const HotRegionProfile &left,
			      const HotRegionProfile &right) {
				  auto *left_block = specialization_find_block(
					  *function,
					  raw_sites.at(left.root_pc).block_start_pc);
				  auto *right_block = specialization_find_block(
					  *function,
					  raw_sites.at(right.root_pc).block_start_pc);
				  const auto *left_node =
					  initial_dominators.getNode(left_block);
				  const auto *right_node =
					  initial_dominators.getNode(right_block);
				  const unsigned left_level =
					  left_node ? left_node->getLevel() : 0;
				  const unsigned right_level =
					  right_node ? right_node->getLevel() : 0;
				  if (left_level != right_level)
					  return left_level > right_level;
				  if (left.branch_count != right.branch_count)
					  return left.branch_count > right.branch_count;
				  return left.root_pc < right.root_pc;
			  });
		report_counts.sites_applied = 0;
		report_counts.sites_matched =
			static_cast<int64_t>(ordered.size());
		report_counts.sites_skipped = 0;
		bool has_versionable_root = false;
		if (options.layout_versioned_program_roots) {
			for (const auto &profile : ordered) {
				const auto &raw_site =
					raw_sites.at(profile.root_pc);
				auto *root_block = specialization_find_block(
					*function, raw_site.block_start_pc);
				if (!root_block) {
					throw std::runtime_error(
						"hot_region_version could not find lifted root block");
				}
				auto *root_branch =
					llvm::dyn_cast<llvm::BranchInst>(
						root_block->getTerminator());
				if (!root_branch ||
				    !root_branch->isConditional()) {
					throw std::runtime_error(
						"hot_region_version lifted root is not conditional");
				}
				const bool hot_taken =
					profile.taken > profile.not_taken;
				auto *hot_successor =
					branch_successor_for_raw_pc(
						*root_branch,
						hot_taken ?
							raw_site.target_pc :
							raw_site.fallthrough_pc,
						raw_site.pc);
				if (find_hot_postdominating_merge(
					    *root_block, *hot_successor,
					    initial_dominators)) {
					has_versionable_root = true;
					break;
				}
			}
		}
		const bool layout_hot_roots =
			options.layout_hot_roots ||
			(options.layout_versioned_program_roots &&
			 has_versionable_root);
		for (const auto &profile : ordered) {
			const auto &raw_site = raw_sites.at(profile.root_pc);
			auto *root_block = specialization_find_block(
				*function, raw_site.block_start_pc);
			if (!root_block) {
				throw std::runtime_error(
					"hot_region_version could not find lifted root block");
			}
			auto *root_branch = llvm::dyn_cast<llvm::BranchInst>(
				root_block->getTerminator());
			if (!root_branch || !root_branch->isConditional()) {
				throw std::runtime_error(
					"hot_region_version lifted root is not conditional");
			}
			const bool hot_taken = profile.taken > profile.not_taken;
			auto *hot_successor = branch_successor_for_raw_pc(
				*root_branch,
				hot_taken ? raw_site.target_pc :
						    raw_site.fallthrough_pc,
				raw_site.pc);
			llvm::DominatorTree dominators(*function);
			auto hot_merge = find_hot_postdominating_merge(
				*root_block, *hot_successor, dominators);
			if (!hot_merge) {
				if (layout_hot_roots) {
					annotate_hot_region_root(
						llvm_module, *root_branch, raw_site,
						profile);
					report_counts.sites_applied =
						report_counts.sites_applied.value() + 1;
					continue;
				}
				constexpr const char *reason =
					"no_postdominating_hot_merge";
				report_counts.sites_skipped =
					report_counts.sites_skipped.value() + 1;
				report_counts.skip_reasons[reason]++;
				report_counts.skipped_sites.emplace_back(
					profile.root_pc, reason);
				continue;
			}
			if (layout_hot_roots) {
				annotate_hot_region_root(
					llvm_module, *root_branch, raw_site, profile);
			}
			clone_hot_dominated_region(
				*hot_merge->block, hot_merge->predecessors,
				dominators);
			report_counts.sites_applied =
				report_counts.sites_applied.value() + 1;
		}
		if (report_counts.sites_applied.value() == 0)
			return input;
		if (std::getenv("BPFOPT_DUMP_IR")) {
			llvm_module.print(llvm::errs(), nullptr);
		}
		if (llvm::verifyModule(llvm_module, &llvm::errs())) {
			throw std::runtime_error(
				"hot_region_version produced invalid LLVM IR");
		}
		return extract_relocated_text(emit_bpf_object(llvm_module), input,
					      nullptr);
	});
}

// --- Context-field function specialization -------------------------------

enum class ContextFieldKind { Context, Packet };

struct ContextLoadSite {
	size_t pc = 0;
	size_t block_start_pc = 0;
	uint32_t offset = 0;
	uint32_t width = 0;
	size_t block_width_ordinal = 0;
	size_t block_width_load_count = 0;
	std::optional<size_t> block_exit_target_pc;
	bool has_proven_packet_offset = false;
};

struct ContextFieldProfile {
	ContextFieldKind kind = ContextFieldKind::Context;
	uint32_t offset = 0;
	uint32_t width = 0;
	uint64_t hot_value = 0;
	uint64_t observations = 0;
	uint64_t hot_count = 0;
	uint32_t context_data_offset = 0;
	uint32_t context_data_end_offset = 0;
	std::vector<uint8_t> hot_bytes;
	std::vector<ContextLoadSite> load_sites;
};

using ContextSpecializeProfile = std::vector<ContextFieldProfile>;
using ContextSpecializeProfiles = std::vector<ContextSpecializeProfile>;

ContextSpecializeProfiles
read_context_specialize_profile(
	const SpecializationProfileOptions &options,
	const std::vector<uint8_t> &input)
{
	const auto &path = options.profile;
	if (!std::filesystem::exists(path)) {
		throw std::runtime_error("context_specialize profile missing: " +
					 path.string());
	}
	auto value = expected_or_throw(llvm::json::parse(read_text(path)));
	const auto &root = specialization_profile_root(
		value, path, "context_specialize", options.program_hash);
	const auto block_starts = specialization_block_start_by_pc(input);
	const auto parse_fields = [&](const llvm::json::Array &fields) {
		ContextSpecializeProfile profile;
		std::set<std::tuple<ContextFieldKind, uint32_t, uint32_t>> seen;
		std::vector<std::pair<uint32_t, uint32_t>> packet_ranges;
	for (const auto &entry : fields) {
		const auto &field = json_object(entry, "context_specialize field");
		const std::string kind_text = specialization_string_field(
			field, "kind", "context_specialize field");
		const std::string source = specialization_string_field(
			field, "source", "context_specialize field");
		ContextFieldKind kind;
		if (kind_text == "context" &&
		    (source == "pmu_branch" || source == "deployment_hint")) {
			kind = ContextFieldKind::Context;
		} else if (kind_text == "packet" && source == "deployment_hint") {
			kind = ContextFieldKind::Packet;
		} else {
			throw std::runtime_error(
				"context_specialize field has invalid kind/source");
		}
		const uint64_t offset = specialization_u64_field(
			field, "offset", "context_specialize field");
		const uint64_t width = specialization_u64_field(
			field, "width", "context_specialize field");
		if (offset > std::numeric_limits<uint32_t>::max() ||
		    (width != 1 && width != 2 && width != 4 && width != 8) ||
		    offset + width > std::numeric_limits<uint32_t>::max()) {
			throw std::runtime_error(
				"context_specialize invalid field profile");
		}
		uint64_t hot_value = 0;
		uint64_t observations = 0;
		uint64_t hot_count = 0;
		uint32_t context_data_offset = 0;
		uint32_t context_data_end_offset = 0;
		std::vector<uint8_t> hot_bytes;
		if (kind == ContextFieldKind::Context) {
			hot_value = specialization_u64_field(
				field, "hot_value", "context_specialize field");
			if (width < 8 && hot_value >=
					 (uint64_t{ 1 } << (width * 8))) {
				throw std::runtime_error(
					"context_specialize context hot_value does not fit width");
			}
			if (source == "pmu_branch") {
				observations = specialization_u64_field(
					field, "observations", "context_specialize field");
				hot_count = specialization_u64_field(
					field, "hot_count", "context_specialize field");
				if (observations == 0 || hot_count == 0 ||
				    hot_count > observations || field.get("hot_bytes_hex") ||
				    field.get("context_data_offset") ||
				    field.get("context_data_end_offset")) {
					throw std::runtime_error(
						"context_specialize invalid PMU context field");
				}
			} else if (field.get("observations") || field.get("hot_count") ||
				   field.get("hot_bytes_hex") ||
				   field.get("context_data_offset") ||
				   field.get("context_data_end_offset")) {
				throw std::runtime_error(
					"context_specialize deployment context field has invalid metadata");
			}
		} else {
			if (field.get("hot_value") || field.get("observations") ||
			    field.get("hot_count")) {
				throw std::runtime_error(
					"context_specialize deployment packet field cannot claim PMU counts");
			}
			const std::string bytes = specialization_string_field(
				field, "hot_bytes_hex", "context_specialize field");
			if (bytes.size() != width * 2 ||
			    !std::all_of(bytes.begin(), bytes.end(), [](unsigned char c) {
				    return std::isxdigit(c);
			    })) {
				throw std::runtime_error(
					"context_specialize packet hot_bytes_hex has wrong width");
			}
			for (size_t i = 0; i < width; i++) {
				const auto byte = static_cast<uint8_t>(std::stoul(
					bytes.substr(i * 2, 2), nullptr, 16));
				hot_bytes.push_back(byte);
				hot_value |= static_cast<uint64_t>(byte) << (i * 8);
			}
			const uint64_t data_offset = specialization_u64_field(
				field, "context_data_offset",
				"context_specialize field");
			const uint64_t data_end_offset = specialization_u64_field(
				field, "context_data_end_offset",
				"context_specialize field");
			if (data_offset > std::numeric_limits<uint32_t>::max() ||
			    data_end_offset > std::numeric_limits<uint32_t>::max() ||
			    data_offset == data_end_offset) {
				throw std::runtime_error(
					"context_specialize invalid packet context offsets");
			}
			context_data_offset = static_cast<uint32_t>(data_offset);
			context_data_end_offset = static_cast<uint32_t>(data_end_offset);
			const uint32_t start = static_cast<uint32_t>(offset);
			const uint32_t end = start + static_cast<uint32_t>(width);
			for (const auto &[other_start, other_end] : packet_ranges) {
				if (std::max(start, other_start) < std::min(end, other_end)) {
					throw std::runtime_error(
						"context_specialize overlapping packet fields");
				}
			}
			packet_ranges.emplace_back(start, end);
		}
		const auto identity = std::make_tuple(
			kind, static_cast<uint32_t>(offset), static_cast<uint32_t>(width));
		if (!seen.insert(identity).second) {
			throw std::runtime_error(
				"context_specialize duplicate kind/offset/width field");
		}
		const auto *load_pcs = field.getArray("load_pcs");
		if (!load_pcs || load_pcs->empty()) {
			throw std::runtime_error(
				"context_specialize field requires load_pcs");
		}
		const auto *load_offsets = field.getArray("load_offsets");
		if (load_offsets &&
		    (kind != ContextFieldKind::Packet ||
		     load_offsets->size() != load_pcs->size())) {
			throw std::runtime_error(
				"context_specialize load_offsets require one packet offset per load pc");
		}
		std::set<size_t> unique_pcs;
		std::vector<ContextLoadSite> load_sites;
		std::set<uint32_t> covered_bytes;
		for (size_t load_index = 0; load_index < load_pcs->size(); load_index++) {
			const auto &raw_pc = (*load_pcs)[load_index];
			const auto pc_value = raw_pc.getAsInteger();
			if (!pc_value || *pc_value < 0 ||
			    static_cast<uint64_t>(*pc_value) >= block_starts.size()) {
				throw std::runtime_error(
					"context_specialize load pc is outside lifted entry function");
			}
			const size_t pc = static_cast<size_t>(*pc_value);
			if (!unique_pcs.insert(pc).second) {
				throw std::runtime_error(
					"context_specialize duplicate load pc");
			}
			const uint8_t opcode = input[pc * INSN_SIZE];
			uint32_t load_width = 0;
			switch (opcode) {
			case BPF_LDXB: load_width = 1; break;
			case BPF_LDXH: load_width = 2; break;
			case BPF_LDXW: load_width = 4; break;
			case BPF_LDXDW: load_width = 8; break;
			default:
				throw std::runtime_error(
					"context_specialize load pc is not LDX memory");
			}
			const int16_t raw_offset = read_off(input, pc);
			int64_t proven_offset = raw_offset;
			if (load_offsets) {
				const auto parsed = (*load_offsets)[load_index].getAsInteger();
				if (!parsed || *parsed < 0 ||
				    static_cast<uint64_t>(*parsed) >
					    std::numeric_limits<uint32_t>::max()) {
					throw std::runtime_error(
						"context_specialize load_offsets contain invalid packet offset");
				}
				proven_offset = *parsed;
			}
			if (proven_offset < 0 ||
			    static_cast<uint64_t>(proven_offset) < offset ||
			    static_cast<uint64_t>(proven_offset) + load_width >
				    offset + width) {
				throw std::runtime_error(
					"context_specialize load pc is outside field range");
			}
			const size_t block_start = block_starts[pc];
			size_t block_width_ordinal = 0;
			size_t block_width_load_count = 0;
			size_t block_end = block_start;
			while (block_end < block_starts.size() &&
			       block_starts[block_end] == block_start) {
				block_end++;
			}
			for (size_t scan_pc = block_start; scan_pc < block_end;
			     scan_pc++) {
				if (input[scan_pc * INSN_SIZE] != opcode) {
					continue;
				}
				if (scan_pc < pc) {
					block_width_ordinal++;
				}
				block_width_load_count++;
			}
			std::optional<size_t> block_exit_target_pc;
			if (block_end > block_start) {
				const size_t terminal_pc = block_end - 1;
				if (input[terminal_pc * INSN_SIZE] == BPF_JA) {
					const int64_t target =
						static_cast<int64_t>(terminal_pc) + 1 +
						read_off(input, terminal_pc);
					if (target >= 0 &&
					    target < static_cast<int64_t>(block_starts.size())) {
						block_exit_target_pc = static_cast<size_t>(target);
					}
				}
			}
			load_sites.push_back(ContextLoadSite{
				pc, block_start, static_cast<uint32_t>(proven_offset),
				load_width, block_width_ordinal,
				block_width_load_count, block_exit_target_pc,
				load_offsets != nullptr });
			for (uint32_t byte = static_cast<uint32_t>(proven_offset);
			     byte < static_cast<uint32_t>(proven_offset) + load_width;
			     byte++) {
				covered_bytes.insert(byte);
			}
		}
		if (kind == ContextFieldKind::Context &&
		    std::any_of(load_sites.begin(), load_sites.end(),
				[&](const ContextLoadSite &site) {
					return site.offset != offset || site.width != width;
				})) {
			throw std::runtime_error(
				"context_specialize context field requires exact loads");
		}
		for (uint32_t byte = static_cast<uint32_t>(offset);
		     byte < static_cast<uint32_t>(offset + width); byte++) {
			if (!covered_bytes.contains(byte)) {
				throw std::runtime_error(
					"context_specialize load_pcs do not cover field bytes");
			}
		}
		profile.push_back(ContextFieldProfile{
			kind,
			static_cast<uint32_t>(offset),
			static_cast<uint32_t>(width), hot_value, observations,
			hot_count, context_data_offset, context_data_end_offset,
			std::move(hot_bytes), std::move(load_sites) });
	}
		return profile;
	};

	const auto *fields = root.getArray("fields");
	const auto *versions = root.getArray("versions");
	if ((fields == nullptr) == (versions == nullptr)) {
		throw std::runtime_error(
			"context_specialize profile requires exactly one of fields or versions");
	}
	if (fields) {
		return ContextSpecializeProfiles{ parse_fields(*fields) };
	}
	if (versions->empty()) {
		throw std::runtime_error(
			"context_specialize versions must not be empty");
	}
	ContextSpecializeProfiles profiles;
	for (const auto &entry : *versions) {
		const auto &version = json_object(
			entry, "context_specialize version");
		const auto *version_fields = version.getArray("fields");
		if (!version_fields || version_fields->empty()) {
			throw std::runtime_error(
				"context_specialize version requires nonempty fields");
		}
		profiles.push_back(parse_fields(*version_fields));
	}
	return profiles;
}

std::optional<int64_t> context_pointer_offset(llvm::Value *pointer,
					     llvm::Argument *context_arg,
					     const llvm::DataLayout &layout)
{
	int64_t offset = 0;
	llvm::Value *current = pointer;
	for (unsigned hops = 0; hops < 8; hops++) {
		if (auto *gep = llvm::dyn_cast<llvm::GetElementPtrInst>(current)) {
			llvm::APInt delta(64, 0);
			if (!gep->accumulateConstantOffset(layout, delta)) {
				return std::nullopt;
			}
			offset += delta.getSExtValue();
			current = gep->getPointerOperand();
			continue;
		}
		if (auto *cast = llvm::dyn_cast<llvm::BitCastInst>(current)) {
			current = cast->getOperand(0);
			continue;
		}
		break;
	}
	if (current != context_arg) {
		return std::nullopt;
	}
	return offset;
}

std::optional<int64_t>
packet_pointer_offset(llvm::Value *pointer, llvm::Argument *context_arg,
		      const llvm::DataLayout &layout,
		      uint32_t context_data_offset)
{
	int64_t offset = 0;
	llvm::Value *current = pointer;
	for (unsigned hops = 0; hops < 8; hops++) {
		if (auto *gep = llvm::dyn_cast<llvm::GetElementPtrInst>(current)) {
			llvm::APInt delta(64, 0);
			if (!gep->accumulateConstantOffset(layout, delta)) {
				return std::nullopt;
			}
			offset += delta.getSExtValue();
			current = gep->getPointerOperand();
			continue;
		}
		if (auto *cast = llvm::dyn_cast<llvm::BitCastInst>(current)) {
			current = cast->getOperand(0);
			continue;
		}
		break;
	}
	auto *int_to_ptr = llvm::dyn_cast<llvm::IntToPtrInst>(current);
	if (!int_to_ptr) {
		return std::nullopt;
	}
	llvm::Value *integer = int_to_ptr->getOperand(0);
	if (auto *zext = llvm::dyn_cast<llvm::ZExtInst>(integer)) {
		integer = zext->getOperand(0);
	}
	auto *data_load = llvm::dyn_cast<llvm::LoadInst>(integer);
	if (!data_load || !data_load->getType()->isIntegerTy(32)) {
		return std::nullopt;
	}
	const auto data_offset = context_pointer_offset(
		data_load->getPointerOperand(), context_arg, layout);
	if (!data_offset || *data_offset != context_data_offset) {
		return std::nullopt;
	}
	return offset;
}

size_t
replace_context_loads(llvm::Function &function,
			      const ContextSpecializeProfile &profile)
{
	if (function.arg_empty()) {
		throw std::runtime_error(
			"context_specialize bpf_main has no context argument");
	}
	auto *context_arg = function.getArg(0);
	const auto &layout = function.getParent()->getDataLayout();
	size_t replaced = 0;
	for (const auto &field : profile) {
		std::map<llvm::LoadInst *, uint64_t> field_replacements;
		for (const auto &site : field.load_sites) {
			auto *block = specialization_find_block(function,
							       site.block_start_pc);
			if (!block) {
				throw std::runtime_error(
					"context_specialize could not find load block for pc " +
					std::to_string(site.pc));
			}
			auto collect_width_candidates =
				[&](llvm::BasicBlock &candidate_block) {
				std::vector<llvm::LoadInst *> found;
				for (llvm::Instruction &instruction : candidate_block) {
					auto *load = llvm::dyn_cast<llvm::LoadInst>(&instruction);
					if (!load || load->isVolatile() ||
					    !load->getType()->isIntegerTy(site.width * 8)) {
						continue;
					}
					found.push_back(load);
				}
				return found;
			};
			auto collect_candidates = [&](llvm::BasicBlock &candidate_block) {
				std::vector<llvm::LoadInst *> found;
				for (auto *load : collect_width_candidates(candidate_block)) {
					std::optional<int64_t> offset;
					if (field.kind == ContextFieldKind::Context) {
						offset = context_pointer_offset(
							load->getPointerOperand(), context_arg, layout);
					} else {
						offset = packet_pointer_offset(
							load->getPointerOperand(), context_arg, layout,
							field.context_data_offset);
					}
					if (offset && *offset == site.offset) {
						found.push_back(load);
					}
				}
				return found;
			};
			std::vector<llvm::LoadInst *> candidates =
				collect_candidates(*block);
			size_t lifted_block_width_loads = 0;
			size_t lifted_pc_block_width_loads = 0;
			size_t lifted_exit_block_width_loads = 0;
			if (candidates.empty() &&
			    field.kind == ContextFieldKind::Context) {
				// The builder proved the raw register's entry-context
				// provenance. LLVM may spill and reload that pointer, which
				// makes pointer tracing impossible. Recover the exact load by
				// its raw basic-block width ordinal only when the lifted block
				// preserves the complete width-load cardinality.
				auto block_loads = collect_width_candidates(*block);
				lifted_block_width_loads = block_loads.size();
				if (block_loads.size() == site.block_width_load_count &&
				    site.block_width_ordinal < block_loads.size()) {
					candidates.push_back(
						block_loads[site.block_width_ordinal]);
				}
			}
			if (candidates.empty() &&
			    field.kind == ContextFieldKind::Packet &&
			    site.has_proven_packet_offset) {
				// The lifter may split one straight-line raw BPF block into
				// multiple bb_inst_<pc> blocks.  A builder-proven dynamic
				// packet offset cannot be recovered from the LLVM pointer, so
				// first use the exact raw-PC block when it contains one load of
				// the expected width.  Fall back to the raw-block ordinal only
				// when the lifter kept the block intact.
				auto *pc_block = specialization_find_block(function, site.pc);
				if (pc_block) {
					auto pc_block_loads =
						collect_width_candidates(*pc_block);
					lifted_pc_block_width_loads = pc_block_loads.size();
					if (pc_block_loads.size() == 1) {
						candidates.push_back(pc_block_loads.front());
					}
				}
				if (candidates.empty() && site.block_exit_target_pc) {
					auto *exit_block = specialization_find_block(
						function, *site.block_exit_target_pc);
					if (exit_block) {
						auto exit_block_loads =
							collect_width_candidates(*exit_block);
						lifted_exit_block_width_loads =
							exit_block_loads.size();
						if (exit_block_loads.size() == 1) {
							candidates.push_back(
								exit_block_loads.front());
						}
					}
				}
				if (candidates.empty()) {
					auto block_loads = collect_width_candidates(*block);
					lifted_block_width_loads = block_loads.size();
					if (block_loads.size() == site.block_width_load_count &&
					    site.block_width_ordinal < block_loads.size()) {
						candidates.push_back(
							block_loads[site.block_width_ordinal]);
					}
				}
			}
			// LLVM may sink a load from a straight-line raw BPF block into the
			// synthetic exit block. Accept that legal movement only when the
			// profiled context field still resolves to one unique load in the
			// entire lifted function.
			if (candidates.empty()) {
				for (llvm::BasicBlock &candidate_block : function) {
					auto found = collect_candidates(candidate_block);
					candidates.insert(candidates.end(), found.begin(), found.end());
				}
			}
			if (candidates.size() != 1) {
				if (std::getenv("BPFOPT_DUMP_IR")) {
					function.print(llvm::errs());
				}
				throw std::runtime_error(
					"context_specialize load pc " +
					std::to_string(site.pc) + " mapped to " +
					std::to_string(candidates.size()) +
					" lifted loads (raw block count=" +
					std::to_string(site.block_width_load_count) +
					", raw ordinal=" +
					std::to_string(site.block_width_ordinal) +
					", lifted pc-block count=" +
					std::to_string(lifted_pc_block_width_loads) +
					", lifted exit-block count=" +
					std::to_string(lifted_exit_block_width_loads) +
					", lifted block count=" +
					std::to_string(lifted_block_width_loads) + ")");
			}
			const uint32_t relative = site.offset - field.offset;
			const uint64_t mask = site.width == 8
						      ? std::numeric_limits<uint64_t>::max()
						      : (uint64_t{ 1 } << (site.width * 8)) - 1;
			const uint64_t value =
				(field.hot_value >> (relative * 8)) & mask;
			auto *load = candidates.front();
			const auto [existing, inserted] =
				field_replacements.emplace(load, value);
			if (!inserted && existing->second != value) {
				throw std::runtime_error(
					"context_specialize coalesced load has conflicting hot values");
			}
		}
		// LLVM can coalesce repeated raw loads of the same context field into
		// one lifted load. Resolve every raw PC before mutating the IR, then
		// replace each unique lifted load once.
		for (const auto &[load, value] : field_replacements) {
			load->replaceAllUsesWith(
				llvm::ConstantInt::get(load->getType(), value));
			load->eraseFromParent();
		}
		replaced++;
	}
	return replaced;
}

constexpr uint32_t CONTEXT_FALLBACK_MAP_MARKER = 0x7ffffffeU;

llvm::Constant *context_fallback_map_argument(llvm::Module &module)
{
	char symbol_name[64];
	std::snprintf(symbol_name, sizeof(symbol_name),
		      "__llvmbpf_pseudo_map_idx_%08x",
		      CONTEXT_FALLBACK_MAP_MARKER);
	auto *symbol = module.getNamedGlobal(symbol_name);
	if (!symbol) {
		symbol = new llvm::GlobalVariable(
			module, llvm::Type::getInt8Ty(module.getContext()), false,
			llvm::GlobalValue::ExternalLinkage, nullptr, symbol_name);
	}
	return llvm::ConstantExpr::getPtrToInt(
		symbol, llvm::Type::getInt64Ty(module.getContext()));
}

llvm::FunctionCallee context_tail_call_helper(llvm::Module &module)
{
	auto *i64 = llvm::Type::getInt64Ty(module.getContext());
	auto *type = llvm::FunctionType::get(i64, { i64, i64, i64 }, false);
	if (auto *existing = module.getFunction("_bpf_helper_ext_0012")) {
		if (existing->getFunctionType() != type) {
			throw std::runtime_error(
				"context_specialize tail_call helper has unexpected signature");
		}
		return existing;
	}
	return module.getOrInsertFunction("_bpf_helper_ext_0012", type);
}

void build_context_specialized_wrapper(
	llvm::Module &module, llvm::Function &original,
	const std::vector<llvm::Function *> &fasts,
	const ContextSpecializeProfiles &profiles)
{
	if (fasts.empty() || fasts.size() != profiles.size()) {
		throw std::runtime_error(
			"context_specialize requires one fast function per version");
	}
	original.setName("bpf_main.context.original");
	original.setLinkage(llvm::GlobalValue::InternalLinkage);
	for (size_t i = 0; i < fasts.size(); i++) {
		fasts[i]->setName("bpf_main.context.fast." + std::to_string(i));
		fasts[i]->setLinkage(llvm::GlobalValue::InternalLinkage);
		// Every guarded version must remain part of the entry function.  The
		// stock verifier rejects tail calls from a transformed BPF subprogram
		// when the raw-bytecode reload cannot supply func_info for its new
		// boundary.  Inlining also keeps the fallback contract independent of
		// synthesized BTF metadata while preserving the per-version guards.
		fasts[i]->addFnAttr(llvm::Attribute::AlwaysInline);
	}

	auto *wrapper = llvm::Function::Create(
		original.getFunctionType(), llvm::GlobalValue::ExternalLinkage,
		"bpf_main");
	// Raw BPF loaders enter at instruction zero. Keep the externally visible
	// wrapper first even though the two internal versions already exist in the
	// module; otherwise the emitted text starts in the unguarded slow version.
	module.getFunctionList().push_front(wrapper);
	wrapper->setCallingConv(original.getCallingConv());
	auto *entry = llvm::BasicBlock::Create(module.getContext(), "entry",
					      wrapper);
	auto *slow_block = llvm::BasicBlock::Create(
		module.getContext(), "context.slow", wrapper);
	auto *context_arg = wrapper->getArg(0);
	auto packet_guard_bytes = [](const ContextSpecializeProfile &profile) {
		std::map<uint32_t, uint8_t> expected_bytes;
		for (const auto &field : profile) {
			if (field.kind != ContextFieldKind::Packet) {
				continue;
			}
			for (size_t byte_index = 0;
			     byte_index < field.hot_bytes.size(); byte_index++) {
				const uint32_t byte_offset =
					field.offset + static_cast<uint32_t>(byte_index);
				if (!expected_bytes.emplace(
					    byte_offset, field.hot_bytes[byte_index]).second) {
					throw std::runtime_error(
						"context_specialize packet guard bytes overlap");
				}
			}
		}
		return expected_bytes;
	};
	bool shared_guard_shape = profiles.size() > 1;
	for (size_t version_index = 1;
	     shared_guard_shape && version_index < profiles.size();
	     version_index++) {
		const auto &reference = profiles.front();
		const auto &candidate = profiles[version_index];
		if (candidate.size() != reference.size()) {
			shared_guard_shape = false;
			break;
		}
		for (size_t field_index = 0; field_index < reference.size();
		     field_index++) {
			const auto &left = reference[field_index];
			const auto &right = candidate[field_index];
			if (left.kind != right.kind || left.offset != right.offset ||
			    left.width != right.width ||
			    (left.kind == ContextFieldKind::Context &&
			     left.hot_value != right.hot_value) ||
			    (left.kind == ContextFieldKind::Packet &&
			     (left.context_data_offset != right.context_data_offset ||
			      left.context_data_end_offset !=
				      right.context_data_end_offset))) {
				shared_guard_shape = false;
				break;
			}
		}
	}
	std::vector<llvm::BasicBlock *> version_entries;
	std::vector<llvm::BasicBlock *> version_checks;
	std::vector<llvm::BasicBlock *> version_fast_blocks;
	for (size_t i = 0; i < profiles.size(); i++) {
		const std::string suffix = "." + std::to_string(i);
		if (!shared_guard_shape) {
			version_entries.push_back(llvm::BasicBlock::Create(
				module.getContext(), "context.version" + suffix, wrapper));
		}
		version_checks.push_back(llvm::BasicBlock::Create(
			module.getContext(), "context.checks" + suffix, wrapper));
		version_fast_blocks.push_back(llvm::BasicBlock::Create(
			module.getContext(), "context.fast" + suffix, wrapper));
	}
	std::vector<llvm::Value *> args;
	for (llvm::Argument &argument : wrapper->args()) {
		args.push_back(&argument);
	}
	struct SharedPacketGuardValue {
		uint32_t offset;
		uint32_t width;
		llvm::Value *value;
	};
	std::vector<SharedPacketGuardValue> shared_packet_guard_values;
	if (!shared_guard_shape) {
		llvm::IRBuilder<>(entry).CreateBr(version_entries.front());
	} else {
		auto *shared_checks = llvm::BasicBlock::Create(
			module.getContext(), "context.shared.checks", wrapper);
		const auto &reference = profiles.front();
		std::vector<const ContextFieldProfile *> packet_fields;
		for (const auto &field : reference) {
			if (field.kind == ContextFieldKind::Packet) {
				packet_fields.push_back(&field);
			}
		}
		llvm::IRBuilder<> entry_builder(entry);
		llvm::Value *packet_data64 = nullptr;
		if (!packet_fields.empty()) {
			const uint32_t data_offset =
				packet_fields.front()->context_data_offset;
			const uint32_t data_end_offset =
				packet_fields.front()->context_data_end_offset;
			uint64_t max_end = 0;
			for (const auto *field : packet_fields) {
				if (field->context_data_offset != data_offset ||
				    field->context_data_end_offset != data_end_offset) {
					throw std::runtime_error(
						"context_specialize packet fields use different data contexts");
				}
				max_end = std::max<uint64_t>(
					max_end, static_cast<uint64_t>(field->offset) +
						 field->width);
			}
			auto *data_pointer = entry_builder.CreateGEP(
				entry_builder.getInt8Ty(), context_arg,
				entry_builder.getInt64(data_offset),
				"context.packet.data.ptr");
			auto *data = entry_builder.CreateLoad(
				entry_builder.getInt32Ty(), data_pointer,
				"context.packet.data");
			data->setAlignment(llvm::Align(4));
			auto *data_end_pointer = entry_builder.CreateGEP(
				entry_builder.getInt8Ty(), context_arg,
				entry_builder.getInt64(data_end_offset),
				"context.packet.data_end.ptr");
			auto *data_end = entry_builder.CreateLoad(
				entry_builder.getInt32Ty(), data_end_pointer,
				"context.packet.data_end");
			data_end->setAlignment(llvm::Align(4));
			packet_data64 = entry_builder.CreateZExt(
				data, entry_builder.getInt64Ty(),
				"context.packet.data64");
			auto *data_end64 = entry_builder.CreateZExt(
				data_end, entry_builder.getInt64Ty(),
				"context.packet.data_end64");
			auto *required_end = entry_builder.CreateAdd(
				packet_data64, entry_builder.getInt64(max_end),
				"context.packet.required_end");
			auto *in_bounds = entry_builder.CreateICmpULE(
				required_end, data_end64,
				"context.packet.in_bounds");
			entry_builder.CreateCondBr(in_bounds, shared_checks, slow_block);
		} else {
			entry_builder.CreateBr(shared_checks);
		}

		llvm::IRBuilder<> shared_builder(shared_checks);
		llvm::Value *common_matches = shared_builder.getTrue();
		for (const auto &field : reference) {
			if (field.kind != ContextFieldKind::Context) {
				continue;
			}
			auto *pointer = shared_builder.CreateGEP(
				shared_builder.getInt8Ty(), context_arg,
				shared_builder.getInt64(field.offset),
				"context.field.ptr");
			auto *type = shared_builder.getIntNTy(field.width * 8);
			auto *field_value = shared_builder.CreateLoad(
				type, pointer, "context.field.value");
			field_value->setAlignment(llvm::Align(1));
			auto *equal = shared_builder.CreateICmpEQ(
				field_value,
				llvm::ConstantInt::get(type, field.hot_value),
				"context.field.hot");
			common_matches = shared_builder.CreateAnd(
				common_matches, equal, "context.all.hot");
		}
		if (packet_data64) {
			auto *packet_base = shared_builder.CreateIntToPtr(
				packet_data64, shared_builder.getPtrTy(),
				"context.packet.base");
			auto expected_bytes = packet_guard_bytes(reference);
			for (auto byte = expected_bytes.begin(); byte != expected_bytes.end();) {
				const uint32_t run_start = byte->first;
				std::vector<uint8_t> run;
				uint32_t expected_offset = run_start;
				while (byte != expected_bytes.end() &&
				       byte->first == expected_offset) {
					run.push_back(byte->second);
					expected_offset++;
					byte++;
				}
				for (size_t run_index = 0; run_index < run.size();) {
					const uint32_t offset = run_start +
						static_cast<uint32_t>(run_index);
					const size_t remaining = run.size() - run_index;
					uint32_t width = 1;
					for (uint32_t candidate : { 8U, 4U, 2U }) {
						if (candidate <= remaining) {
							width = candidate;
							break;
						}
					}
					auto *pointer = shared_builder.CreateGEP(
						shared_builder.getInt8Ty(), packet_base,
						shared_builder.getInt64(offset),
						"context.packet.field.ptr");
					auto *type = shared_builder.getIntNTy(width * 8);
					auto *field_value = shared_builder.CreateLoad(
						type, pointer,
						"context.packet.field.value");
					field_value->setAlignment(llvm::Align(width));
					shared_packet_guard_values.push_back(
						{ offset, width, field_value });
					run_index += width;
				}
			}
		}
		shared_builder.CreateCondBr(
			common_matches, version_checks.front(), slow_block);
	}
	for (size_t version_index = 0; version_index < profiles.size();
	     version_index++) {
		const auto &profile = profiles[version_index];
		auto *next = version_index + 1 < profiles.size()
				     ? (shared_guard_shape
						? version_checks[version_index + 1]
						: version_entries[version_index + 1])
				     : slow_block;
		std::vector<const ContextFieldProfile *> packet_fields;
		auto packet_expected_bytes = packet_guard_bytes(profile);
		for (const auto &field : profile) {
			if (field.kind == ContextFieldKind::Packet) {
				packet_fields.push_back(&field);
			}
		}
		llvm::Value *packet_data64 = nullptr;
		if (!shared_guard_shape && !packet_fields.empty()) {
			llvm::IRBuilder<> version_builder(version_entries[version_index]);
			const uint32_t data_offset =
				packet_fields.front()->context_data_offset;
			const uint32_t data_end_offset =
				packet_fields.front()->context_data_end_offset;
			uint64_t max_end = 0;
			for (const auto *field : packet_fields) {
				if (field->context_data_offset != data_offset ||
				    field->context_data_end_offset != data_end_offset) {
					throw std::runtime_error(
						"context_specialize packet fields use different data contexts");
				}
				max_end = std::max<uint64_t>(
					max_end, static_cast<uint64_t>(field->offset) +
						 field->width);
			}
			auto *data_pointer = version_builder.CreateGEP(
				version_builder.getInt8Ty(), context_arg,
				version_builder.getInt64(data_offset),
				"context.packet.data.ptr");
			auto *data = version_builder.CreateLoad(
				version_builder.getInt32Ty(), data_pointer,
				"context.packet.data");
			data->setAlignment(llvm::Align(4));
			auto *data_end_pointer = version_builder.CreateGEP(
				version_builder.getInt8Ty(), context_arg,
				version_builder.getInt64(data_end_offset),
				"context.packet.data_end.ptr");
			auto *data_end = version_builder.CreateLoad(
				version_builder.getInt32Ty(), data_end_pointer,
				"context.packet.data_end");
			data_end->setAlignment(llvm::Align(4));
			packet_data64 = version_builder.CreateZExt(
				data, version_builder.getInt64Ty(),
				"context.packet.data64");
			auto *data_end64 = version_builder.CreateZExt(
				data_end, version_builder.getInt64Ty(),
				"context.packet.data_end64");
			auto *required_end = version_builder.CreateAdd(
				packet_data64, version_builder.getInt64(max_end),
				"context.packet.required_end");
			auto *in_bounds = version_builder.CreateICmpULE(
				required_end, data_end64,
				"context.packet.in_bounds");
			version_builder.CreateCondBr(
				in_bounds, version_checks[version_index], next);
		} else if (!shared_guard_shape) {
			llvm::IRBuilder<>(version_entries[version_index])
				.CreateBr(version_checks[version_index]);
		}

		llvm::IRBuilder<> check_builder(version_checks[version_index]);
		llvm::Value *packet_base = nullptr;
		if (packet_data64) {
			packet_base = check_builder.CreateIntToPtr(
				packet_data64, check_builder.getPtrTy(),
				"context.packet.base");
		}
		llvm::Value *matches = check_builder.getTrue();
		for (const auto &field : profile) {
			if (shared_guard_shape ||
			    field.kind != ContextFieldKind::Context) {
				continue;
			}
			auto *pointer = check_builder.CreateGEP(
				check_builder.getInt8Ty(), context_arg,
				check_builder.getInt64(field.offset),
				"context.field.ptr");
			auto *type = check_builder.getIntNTy(field.width * 8);
			auto *field_value = check_builder.CreateLoad(
				type, pointer, "context.field.value");
			field_value->setAlignment(llvm::Align(1));
			auto *equal = check_builder.CreateICmpEQ(
				field_value,
				llvm::ConstantInt::get(type, field.hot_value),
				"context.field.hot");
			matches = check_builder.CreateAnd(
				matches, equal, "context.all.hot");
		}
		size_t shared_guard_index = 0;
		for (auto byte = packet_expected_bytes.begin();
		     byte != packet_expected_bytes.end();) {
			const uint32_t run_start = byte->first;
			std::vector<uint8_t> run;
			uint32_t expected_offset = run_start;
			while (byte != packet_expected_bytes.end() &&
			       byte->first == expected_offset) {
				run.push_back(byte->second);
				expected_offset++;
				byte++;
			}
			for (size_t run_index = 0; run_index < run.size();) {
				const uint32_t offset =
					run_start + static_cast<uint32_t>(run_index);
				const size_t remaining = run.size() - run_index;
				uint32_t width = 1;
				for (uint32_t candidate : { 8U, 4U, 2U }) {
					if (candidate <= remaining) {
						width = candidate;
						break;
					}
				}
				uint64_t expected = 0;
				for (uint32_t i = 0; i < width; i++) {
					expected |= static_cast<uint64_t>(run[run_index + i])
						    << (i * 8);
				}
				auto *type = check_builder.getIntNTy(width * 8);
				llvm::Value *field_value = nullptr;
				if (shared_guard_shape) {
					if (shared_guard_index >=
						    shared_packet_guard_values.size() ||
					    shared_packet_guard_values[shared_guard_index].offset !=
						    offset ||
					    shared_packet_guard_values[shared_guard_index].width !=
						    width) {
						throw std::runtime_error(
							"context_specialize shared packet guard shape changed");
					}
					field_value =
						shared_packet_guard_values[shared_guard_index].value;
					shared_guard_index++;
				} else {
					auto *pointer = check_builder.CreateGEP(
						check_builder.getInt8Ty(), packet_base,
						check_builder.getInt64(offset),
						"context.packet.field.ptr");
					field_value = check_builder.CreateLoad(
						type, pointer,
						"context.packet.field.value");
					// Emit the widest guarded packet load directly, including at
					// non-natural offsets such as the IPv4 src/dst tuple at 26.
					// The stock verifier remains the acceptance boundary for the
					// deployment target instead of pre-splitting it into byte loads.
					llvm::cast<llvm::LoadInst>(field_value)
						->setAlignment(llvm::Align(width));
				}
				auto *equal = check_builder.CreateICmpEQ(
					field_value,
					llvm::ConstantInt::get(type, expected),
					"context.packet.field.hot");
				matches = check_builder.CreateAnd(
					matches, equal, "context.all.hot");
				run_index += width;
			}
		}
		if (shared_guard_shape &&
		    shared_guard_index != shared_packet_guard_values.size()) {
			throw std::runtime_error(
				"context_specialize shared packet guard count changed");
		}
		check_builder.CreateCondBr(
			matches, version_fast_blocks[version_index], next);

		llvm::IRBuilder<> fast_builder(
			version_fast_blocks[version_index]);
		auto *fast_result = fast_builder.CreateCall(
			fasts[version_index]->getFunctionType(),
			fasts[version_index], args, "context.fast.result");
		fast_builder.CreateRet(fast_result);
	}

	if (!original.getReturnType()->isIntegerTy(64)) {
		throw std::runtime_error(
			"context_specialize bpf_main must return i64");
	}
	llvm::IRBuilder<> slow_builder(slow_block);
	auto *context_i64 = slow_builder.CreatePtrToInt(
		context_arg, slow_builder.getInt64Ty(), "context.fallback.ctx");
	auto fallback_call = slow_builder.CreateCall(
		context_tail_call_helper(module),
		{ context_i64, context_fallback_map_argument(module),
		  slow_builder.getInt64(0) });
	fallback_call->setName("context.original.tail_call");
	// A populated PROG_ARRAY tail call never returns. Returning zero makes a
	// missing fallback slot fail closed for XDP and remains a neutral return
	// for tracing/TC-style programs; the shim treats map creation/update
	// failure as a hard reload error before this bytecode can be attached.
	slow_builder.CreateRet(slow_builder.getInt64(0));

	// The generic implementation remains live as the shim-held tail-call
	// target. Keeping a second copy in this candidate would make the verifier
	// explore both whole-function CFGs and exceed its global complexity limit.
	original.eraseFromParent();
}

std::vector<uint8_t> run_context_specialize_roundtrip(
	const std::vector<uint8_t> &input,
	const SpecializationProfileOptions &options,
	PassReportCounts &report_counts)
{
	const auto profiles = read_context_specialize_profile(options, input);
	if (profiles.size() == 1 && profiles.front().empty()) {
		report_counts.sites_applied = 0;
		report_counts.sites_matched = 0;
		report_counts.sites_skipped = 0;
		return input;
	}
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &llvm_module) {
		auto machine = create_bpf_target_machine(
			llvm::CodeGenOptLevel::Aggressive);
#if LLVM_VERSION_MAJOR >= 19
		llvm_module.setTargetTriple(llvm::Triple("bpfel"));
#else
		llvm_module.setTargetTriple("bpfel");
#endif
		llvm_module.setDataLayout(machine->createDataLayout());
		promote_register_allocas(llvm_module, *machine);
		auto *slow = llvm_module.getFunction("bpf_main");
		if (!slow) {
			throw std::runtime_error(
				"context_specialize could not find bpf_main");
		}
		std::vector<llvm::Function *> fasts;
		size_t total_replaced = 0;
		size_t total_fields = 0;
		for (const auto &profile : profiles) {
			llvm::ValueToValueMapTy value_map;
			auto *fast = llvm::CloneFunction(slow, value_map);
			const auto replaced = replace_context_loads(*fast, profile);
			if (replaced != profile.size()) {
				if (std::getenv("BPFOPT_DUMP_IR")) {
					fast->print(llvm::errs());
				}
				fast->eraseFromParent();
				throw std::runtime_error(
					"context_specialize profile does not match every lifted context load");
			}
			fasts.push_back(fast);
			total_replaced += replaced;
			total_fields += profile.size();
		}
		build_context_specialized_wrapper(
			llvm_module, *slow, fasts, profiles);
		report_counts.sites_applied =
			static_cast<int64_t>(total_replaced);
		report_counts.sites_matched = static_cast<int64_t>(total_fields);
		report_counts.sites_skipped = 0;
		if (llvm::verifyModule(llvm_module, &llvm::errs())) {
			throw std::runtime_error(
				"context_specialize produced invalid LLVM IR");
		}
		if (std::getenv("BPFOPT_DUMP_IR")) {
			llvm_module.print(llvm::errs(), nullptr);
		}
		return extract_relocated_text(emit_bpf_object(llvm_module), input,
					      nullptr);
	});
}
