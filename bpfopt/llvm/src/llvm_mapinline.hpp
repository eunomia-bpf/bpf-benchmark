// SPDX-License-Identifier: MIT
// Part of bpfopt-llvm. Included inside the anonymous namespace of main.cpp,
// which supplies the system/LLVM include prelude. Not standalone-compilable.

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
	llvm::Triple triple("bpfel");
	const llvm::Target *target =
		llvm::TargetRegistry::lookupTarget(triple, error);
	if (!target) {
		throw std::runtime_error("lookupTarget(bpfel) failed: " + error);
	}
	llvm::TargetOptions options;
	auto machine = std::unique_ptr<llvm::TargetMachine>(
		target->createTargetMachine(triple, "v3", "", options,
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
	module.setTargetTriple(llvm::Triple("bpfel"));
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

struct MapInfo {
	uint32_t id = 0;
	std::string name;
	std::string map_type;
	uint32_t key_size = 0;
	uint32_t value_size = 0;
	bool data_path_mutable = false;
};

// Map types whose value is an ordinary fixed-layout blob that map_inline can
// fold a constant into. Excludes map-in-map, prog/perf arrays, ringbuf, sock
// maps, stack-trace, etc. — there "value" is not a value the program derefs.
bool map_type_supports_value_inline(const std::string &type)
{
	return type == "hash" || type == "array" || type == "percpu_hash" ||
	       type == "percpu_array" || type == "lru_hash" ||
	       type == "lru_percpu_hash";
}


struct InlineRecord {
	uint32_t map_id = 0;
	std::vector<uint8_t> key;
	std::vector<uint8_t> value;
};

struct MapInlineArgs {
	std::filesystem::path map_values;
	std::vector<uint32_t> map_ids;
};

struct MapSnapshot {
	std::map<uint32_t, MapInfo> maps;
	std::map<std::string, uint32_t> map_id_by_name;
	std::map<std::pair<uint32_t, std::string>, std::vector<uint8_t>> values;
	std::map<uint32_t, std::vector<uint8_t>> uniform_values;
	// Maps whose every entry holds the same value ("uniform" compression), as
	// opposed to a sparse map's default fallback (which also lands in
	// uniform_values but is only correct for absent keys). Only these may be
	// folded when the lookup key is not a recovered constant.
	std::set<uint32_t> truly_uniform;
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
		snapshot.truly_uniform.insert(map_id);
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
		info.map_type = json_string_field(show, "type");
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

// Maps the data path writes via map_update/delete/push/pop. Folding a snapshot
// value into a lookup on such a map could use a stale value. Necessary (not
// sufficient) mutability proxy: userspace writes are invisible to this
// bytecode-only tool; that broader decision belongs to the global facts layer.
std::set<uint32_t>
scan_data_path_mutable_maps(const std::vector<uint8_t> &text,
			    const std::vector<uint32_t> &map_ids)
{
	std::set<uint32_t> mutable_ids;
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (is_ldimm64(text, pc)) {
			pc++;
			continue;
		}
		if (text[pc * INSN_SIZE] != BPF_CALL || src_reg(text, pc) != 0) {
			continue;
		}
		const int32_t fn = read_imm(text, pc);
		if (fn != BPF_FUNC_map_update_elem &&
		    fn != BPF_FUNC_map_delete_elem &&
		    fn != BPF_FUNC_map_push_elem && fn != BPF_FUNC_map_pop_elem) {
			continue;
		}
		if (const auto id = map_id_for_lookup(text, pc, map_ids)) {
			mutable_ids.insert(*id);
		}
	}
	return mutable_ids;
}

// Recover a compile-time-constant lookup key for the lookup at call_pc when the
// key pointer (r2) is r10+off and every key byte was written by a constant
// ST_MEM store before the call. Returns nullopt for runtime-built keys, which
// are left to the future global speculation layer.
// Recover the stack offset of the lookup key when the key pointer (r2) is
// r10+off just before the call. Returns nullopt if r2 is not a simple frame
// offset (e.g. it points into the packet).
std::optional<int> find_key_stack_off(const std::vector<uint8_t> &text,
				      size_t call_pc)
{
	const size_t begin = call_pc > 64 ? call_pc - 64 : 0;
	for (size_t pc = call_pc; pc-- > begin;) {
		if (is_ldimm64(text, pc) || !insn_defines_reg(text, pc, 2)) {
			continue;
		}
		const uint8_t code = text[pc * INSN_SIZE];
		if (code == BPF_ALU64_MOV_X && dst_reg(text, pc) == 2 &&
		    src_reg(text, pc) == 10) {
			return 0;
		}
		if (code == BPF_ALU64_ADD_K && dst_reg(text, pc) == 2) {
			const int32_t off = read_imm(text, pc);
			for (size_t q = pc; q-- > begin;) {
				if (!insn_defines_reg(text, q, 2)) {
					continue;
				}
				if (text[q * INSN_SIZE] == BPF_ALU64_MOV_X &&
				    dst_reg(text, q) == 2 &&
				    src_reg(text, q) == 10) {
					return off;
				}
				return std::nullopt;
			}
		}
		return std::nullopt;
	}
	return std::nullopt;
}

// Conservatively decide whether the looked-up value pointer (r0) at present_pc
// is only ever read (fixed-offset LDX) before it dies. Any store through r0
// (the value being mutated, e.g. a stats counter), any copy of r0 to another
// register, or any branch before r0 is redefined returns false so the site is
// skipped — folding such a value would change semantics or use a stale value.
bool value_ptr_is_read_only(const std::vector<uint8_t> &text, size_t present_pc)
{
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = present_pc; pc < insn_count; pc++) {
		if (is_ldimm64(text, pc)) {
			if (dst_reg(text, pc) == 0) {
				return true; // r0 redefined -> value dead
			}
			pc++;
			continue;
		}
		const uint8_t code = text[pc * INSN_SIZE];
		const uint8_t cls = code & 0x07;
		const auto base = memory_base_reg(text, pc);
		if (base && *base == 0) {
			if (cls == 0x01) {
				// LDX *(r0+off): a read. If it loads into r0,
				// the pointer dies afterwards.
				if (dst_reg(text, pc) == 0) {
					return true;
				}
				continue;
			}
			return false; // store through the value pointer
		}
		// STX *(rX+off) = r0: the value pointer escapes to memory (e.g.
		// saved to a stack slot and reloaded later as a map-value ptr).
		// We can no longer track it, so do not fold.
		if (cls == 0x03 && src_reg(text, pc) == 0) {
			return false;
		}
		if (code == BPF_CALL || code == BPF_CALLX || code == BPF_EXIT) {
			return true; // r0 clobbered / function returns
		}
		if (is_jmp_class(code)) {
			// Branches do not consume the pointer; the value is
			// usually already loaded into another register. Keep
			// scanning the linear range until r0 is redefined — any
			// store through r0 textually before that is still caught.
			continue;
		}
		// r0 used as an X-form source (e.g. copied out) -> escapes.
		if ((code & 0x08) && src_reg(text, pc) == 0 &&
		    dst_reg(text, pc) != 0) {
			return false;
		}
		if (insn_defines_reg(text, pc, 0)) {
			return true; // r0 redefined -> value dead
		}
	}
	return true;
}

struct GuardEntry {
	std::vector<uint8_t> key; // empty => unconditional (uniform) fast path
	std::vector<uint8_t> value;
	int16_t slot = 0;
};

// Build a guarded enumeration block to splice *before* a map_lookup_elem call:
//
//   entry i:  r3 = *(u32)(r10 + key_off + 4c)   ; load each key word
//             if r3 != Ki_c goto <next entry / SLOW>
//             ...
//             <materialize Vi on stack; r0 = &Vi>
//             goto OVER_CALL                      ; skip the kept real lookup
//   SLOW:     <original call ...>                 ; any unlisted key / miss
//   OVER_CALL:<original null check ...>
//
// A uniform entry (empty key) emits no compares: r0 = &V unconditionally and the
// call becomes dead (O3 removes it), eliminating the lookup. Listed exact keys
// keep the call as the slow-path fallback, so unlisted keys stay correct. All
// jumps are block-relative; r3 is a scratch register (r1-r5 are caller-saved and
// treated as clobbered across the call, so overwriting r3 on the fast path —
// which skips the call — is safe). Keys must be 4-byte aligned.
std::vector<uint8_t> build_guard_chain_block(int key_off,
					     const std::vector<GuardEntry> &entries)
{
	const size_t n = entries.size();
	std::vector<std::vector<uint8_t>> fast(n);
	std::vector<size_t> nchunks(n), entry_len(n), start(n);
	size_t total = 0;
	for (size_t i = 0; i < n; i++) {
		if (!entries[i].key.empty() && entries[i].key.size() % 4 != 0) {
			return {};
		}
		fast[i] = build_stack_value_block(entries[i].value,
						  entries[i].slot);
		nchunks[i] = entries[i].key.size() / 4;
		entry_len[i] = nchunks[i] * 2 + fast[i].size() / INSN_SIZE + 1;
		start[i] = total;
		total += entry_len[i];
	}
	const size_t block_len = total;
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
	for (size_t i = 0; i < n; i++) {
		const size_t mismatch =
			(i + 1 < n) ? start[i + 1] : block_len; // next entry / SLOW
		for (size_t c = 0; c < nchunks[i]; c++) {
			int32_t kc = 0;
			std::memcpy(&kc, entries[i].key.data() + c * 4,
				    sizeof(kc));
			append(BPF_LDX_MEM_W, 3, 10,
			       static_cast<int16_t>(
				       key_off + static_cast<int>(c * 4)),
			       0);
			const size_t j = block.size() / INSN_SIZE;
			append(BPF_JMP32_JNE_K, 3, 0,
			       static_cast<int16_t>(mismatch - j - 1), kc);
		}
		block.insert(block.end(), fast[i].begin(), fast[i].end());
		const size_t j = block.size() / INSN_SIZE;
		// Jump to OVER_CALL = block_len + 1 (just past the 1-insn call).
		append(BPF_JA, 0, 0, static_cast<int16_t>(block_len + 1 - j - 1),
		       0);
	}
	return block;
}

// Auto soft map_inline (no hints, no hard fold). For every lookup whose map
// snapshot supplies a value — matched by a recovered constant key, or a uniform
// map — fold that constant value into the lookup-succeeded path while keeping
// the real lookup as the presence guard. The lookup is not deleted, so misses
// and other keys still take the original path; only the value is replaced. This
// assumes the entry's value is stable (gated by skipping data-path-mutable maps
// and value pointers that are written through); the broader userspace-mutability
// decision is deferred to the global facts layer.
std::vector<InlineRecord> apply_map_inline_auto(std::vector<uint8_t> &text,
						const Cli &cli)
{
	const auto args = parse_map_inline_args(cli.pass_args);
	const auto snapshot = read_map_snapshot(args);
	const auto mutable_maps = scan_data_path_mutable_maps(text, args.map_ids);

	struct PendingInline {
		size_t insert_pc;
		std::vector<uint8_t> block;
		InlineRecord record;
	};
	std::vector<PendingInline> pending;
	auto used_stack = stack_bytes_used(text);
	const size_t insn_count = text.size() / INSN_SIZE;
	for (size_t pc = 0; pc < insn_count; pc++) {
		if (is_ldimm64(text, pc)) {
			pc++;
			continue;
		}
		if (text[pc * INSN_SIZE] != BPF_CALL || src_reg(text, pc) != 0 ||
		    read_imm(text, pc) != BPF_FUNC_map_lookup_elem) {
			continue;
		}
		const auto map_id = map_id_for_lookup(text, pc, args.map_ids);
		if (!map_id || mutable_maps.count(*map_id)) {
			continue;
		}
		const auto map = snapshot.maps.find(*map_id);
		if (map == snapshot.maps.end() ||
		    !map_type_supports_value_inline(map->second.map_type)) {
			continue;
		}
		// The looked-up value must only be read (never written back through
		// r0); otherwise folding it would drop a real map write.
		if (pc + 1 >= insn_count || !value_ptr_is_read_only(text, pc + 1)) {
			continue;
		}
		// Choose a guard strategy:
		//   - truly-uniform map: one unconditional fast path; the kept
		//     call becomes dead and O3 eliminates the lookup (assumes a
		//     stable value and in-range presence, sound for bounded-index
		//     ARRAY maps such as the consistent-hash ring);
		//   - 1..MAX_ENUM exact keys: a guard chain over those keys with
		//     the real lookup retained as the slow-path fallback (sound for
		//     any unlisted key or miss; a constant key collapses under O3).
		constexpr size_t MAX_ENUM = 4;
		std::vector<GuardEntry> guard;
		int key_off = 0;
		InlineRecord record{ *map_id, {}, {} };
		if (snapshot.truly_uniform.count(*map_id)) {
			const auto &v = snapshot.uniform_values.at(*map_id);
			if (v.size() != map->second.value_size) {
				continue;
			}
			guard.push_back(
				{ {}, v, allocate_stack_slot(used_stack, v.size()) });
			record.value = v;
		} else {
			std::vector<std::pair<std::vector<uint8_t>,
					      std::vector<uint8_t>>>
				entries;
			for (const auto &kv : snapshot.values) {
				if (kv.first.first == *map_id) {
					entries.push_back(
						{ parse_hex_bytes(kv.first.second),
						  kv.second });
				}
			}
			if (entries.empty() || entries.size() > MAX_ENUM ||
			    map->second.key_size % 4 != 0) {
				continue;
			}
			bool ok = true;
			for (const auto &e : entries) {
				if (e.first.size() != map->second.key_size ||
				    e.second.size() != map->second.value_size) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			const auto ko = find_key_stack_off(text, pc);
			if (!ko) {
				continue;
			}
			key_off = *ko;
			for (const auto &e : entries) {
				guard.push_back(
					{ e.first, e.second,
					  allocate_stack_slot(
						  used_stack, e.second.size()) });
			}
			record.key = entries[0].first;
			record.value = entries[0].second;
		}
		auto block = build_guard_chain_block(key_off, guard);
		if (block.empty()) {
			continue;
		}
		pending.push_back({ pc, std::move(block), record });
	}

	// Apply highest insert_pc first so earlier pcs are not shifted.
	std::sort(pending.begin(), pending.end(),
		  [](const PendingInline &a, const PendingInline &b) {
			  return a.insert_pc > b.insert_pc;
		  });
	std::vector<InlineRecord> records;
	for (const auto &item : pending) {
		insert_insns_adjusting_jumps(text, item.insert_pc, item.block);
		records.push_back(item.record);
	}
	std::reverse(records.begin(), records.end());
	return records;
}

// --- IR-level map_inline ---------------------------------------------------
// Decide, per map_lookup_elem call in main-program order, the constant value to
// fold (or nullopt). Only the main program [0, subprog_start) is lifted to IR,
// so these ordinals line up with the IR call sites. A site is folded when its
// map is data-path-immutable, value-inlineable, the result is only read (never
// written through), and the snapshot gives a single value (uniform map, or a
// single exact entry). The IR rewrite is fold_lookups_in_module().
std::vector<std::optional<std::vector<uint8_t>>>
decide_lookup_folds(const std::vector<uint8_t> &text, const Cli &cli,
		    std::vector<InlineRecord> &records)
{
	const auto args = parse_map_inline_args(cli.pass_args);
	const auto snapshot = read_map_snapshot(args);
	const auto mutable_maps = scan_data_path_mutable_maps(text, args.map_ids);
	const auto subprog = subprog_start_pc(text);
	const size_t limit = subprog ? *subprog : text.size() / INSN_SIZE;
	std::vector<std::optional<std::vector<uint8_t>>> folds;
	for (size_t pc = 0; pc < limit; pc++) {
		if (is_ldimm64(text, pc)) {
			pc++;
			continue;
		}
		if (text[pc * INSN_SIZE] != BPF_CALL || src_reg(text, pc) != 0 ||
		    read_imm(text, pc) != BPF_FUNC_map_lookup_elem) {
			continue;
		}
		std::optional<std::vector<uint8_t>> value;
		uint32_t fold_map = 0;
		const auto map_id = map_id_for_lookup(text, pc, args.map_ids);
		if (map_id && !mutable_maps.count(*map_id) && pc + 1 < limit &&
		    value_ptr_is_read_only(text, pc + 1)) {
			const auto map = snapshot.maps.find(*map_id);
			if (map != snapshot.maps.end() &&
			    map_type_supports_value_inline(map->second.map_type)) {
				if (snapshot.truly_uniform.count(*map_id)) {
					const auto &v =
						snapshot.uniform_values.at(*map_id);
					if (v.size() == map->second.value_size) {
						value = v;
					}
				} else {
					const std::vector<uint8_t> *only = nullptr;
					size_t cnt = 0;
					for (const auto &kv : snapshot.values) {
						if (kv.first.first == *map_id) {
							only = &kv.second;
							cnt++;
						}
					}
					if (cnt == 1 &&
					    only->size() == map->second.value_size) {
						value = *only;
					}
				}
				if (value) {
					fold_map = *map_id;
				}
			}
		}
		if (value) {
			records.push_back({ fold_map, {}, *value });
		}
		folds.push_back(std::move(value));
	}
	return folds;
}

// Little-endian integer of `width` bytes from `v` at byte `off`.
uint64_t le_value(const std::vector<uint8_t> &v, size_t off, size_t width)
{
	uint64_t x = 0;
	for (size_t i = 0; i < width; i++) {
		x |= static_cast<uint64_t>(v[off + i]) << (8 * i);
	}
	return x;
}

// Collect the integer loads reachable from a value pointer `p` (the lookup
// result cast to a pointer) at cumulative byte offset `base`. Every use of `p`
// must be a constant-offset GEP or an in-range integer load, else returns false
// (the site is not cleanly foldable and is skipped).
bool collect_value_loads(
	llvm::Value *p, int64_t base, const std::vector<uint8_t> &v,
	const llvm::DataLayout &dl,
	std::vector<std::pair<llvm::LoadInst *, llvm::Constant *>> &out)
{
	for (llvm::User *u : p->users()) {
		if (auto *ld = llvm::dyn_cast<llvm::LoadInst>(u)) {
			if (ld->getPointerOperand() != p ||
			    !ld->getType()->isIntegerTy()) {
				return false;
			}
			const unsigned bits = ld->getType()->getIntegerBitWidth();
			if (bits % 8 != 0) {
				return false;
			}
			const size_t width = bits / 8;
			if (base < 0 ||
			    static_cast<size_t>(base) + width > v.size()) {
				return false;
			}
			out.push_back({ ld, llvm::ConstantInt::get(
						     ld->getType(),
						     le_value(v,
							      static_cast<size_t>(
								      base),
							      width)) });
		} else if (auto *gep =
				   llvm::dyn_cast<llvm::GetElementPtrInst>(u)) {
			llvm::APInt off(64, 0);
			if (!gep->accumulateConstantOffset(dl, off)) {
				return false;
			}
			if (!collect_value_loads(gep, base + off.getSExtValue(),
						 v, dl, out)) {
				return false;
			}
		} else {
			return false;
		}
	}
	return true;
}

// Fold map_lookup_elem results to constants in IR: replace the value-deref loads
// with immediate ConstantInts and make the null check see a non-null pointer,
// then erase the lookup. Pure register immediates (no global / .rodata, no stack
// round-trip), so O3 propagates them and DCEs the dead lookup. A site whose
// result is used in any other way is left untouched (skipped).
void fold_lookups_in_module(
	llvm::Module &module,
	const std::vector<std::optional<std::vector<uint8_t>>> &folds)
{
	auto *lookup = module.getFunction("_bpf_helper_ext_0001");
	auto *main_fn = module.getFunction("bpf_main");
	if (!lookup || !main_fn) {
		return;
	}
	std::vector<llvm::CallInst *> calls;
	for (auto &bb : *main_fn) {
		for (auto &inst : bb) {
			if (auto *ci = llvm::dyn_cast<llvm::CallInst>(&inst)) {
				if (ci->getCalledFunction() == lookup) {
					calls.push_back(ci);
				}
			}
		}
	}
	if (calls.size() != folds.size()) {
		return; // ordinal/count mismatch: fold nothing (safety)
	}
	const auto &dl = module.getDataLayout();
	for (size_t i = 0; i < calls.size(); i++) {
		if (!folds[i]) {
			continue;
		}
		const auto &v = *folds[i];
		auto *call = calls[i];
		// Validate every use first: null-check (icmp vs 0) or a pointer
		// deref via inttoptr -> [gep]* -> integer load.
		std::vector<std::pair<llvm::LoadInst *, llvm::Constant *>> loads;
		std::vector<llvm::ICmpInst *> nullchecks;
		std::vector<llvm::IntToPtrInst *> casts;
		bool ok = true;
		for (llvm::User *u : call->users()) {
			if (auto *ic = llvm::dyn_cast<llvm::ICmpInst>(u)) {
				nullchecks.push_back(ic);
			} else if (auto *itp =
					   llvm::dyn_cast<llvm::IntToPtrInst>(u)) {
				casts.push_back(itp);
				if (!collect_value_loads(itp, 0, v, dl, loads)) {
					ok = false;
					break;
				}
			} else {
				ok = false;
				break;
			}
		}
		if (!ok) {
			continue;
		}
		// Apply: loads -> constants; null checks see a non-null result.
		for (auto &lf : loads) {
			lf.first->replaceAllUsesWith(lf.second);
			lf.first->eraseFromParent();
		}
		for (auto *ic : nullchecks) {
			ic->replaceUsesOfWith(
				call, llvm::ConstantInt::get(call->getType(), 1));
		}
		for (auto *itp : casts) {
			if (itp->use_empty()) {
				itp->eraseFromParent();
			}
		}
		if (call->use_empty()) {
			call->eraseFromParent();
		}
	}
}

std::vector<uint8_t> run_map_inline_roundtrip(const std::vector<uint8_t> &input,
					      const Cli &cli,
					      std::vector<InlineRecord> &records)
{
	const auto folds = decide_lookup_folds(input, cli, records);
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		// Set the BPF data layout before folding so GEP offset
		// accumulation in the fold matches codegen.
		auto machine = create_bpf_target_machine(
			llvm::CodeGenOptLevel::Aggressive);
		module.setTargetTriple(llvm::Triple("bpfel"));
		module.setDataLayout(machine->createDataLayout());
		// Promote the per-register allocas to SSA first, so a lookup
		// result flows directly to its null check / deref uses instead of
		// being stored to its register alloca.
		promote_register_allocas(module, *machine);
		fold_lookups_in_module(module, folds);
		return extract_relocated_text(emit_bpf_object(module, true),
					      input);
	});
}

uint32_t module_fd_array_base(size_t map_count)
{
	if (map_count > std::numeric_limits<uint32_t>::max()) {
		throw std::runtime_error("map count exceeds u32");
	}
	return std::max<uint32_t>(static_cast<uint32_t>(map_count), 1);
}
