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
