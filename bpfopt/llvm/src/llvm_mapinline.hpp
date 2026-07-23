// SPDX-License-Identifier: MIT
// Part of bpfopt-llvm. Included inside the anonymous namespace of main.cpp,
// which supplies the system/LLVM include prelude. Not standalone-compilable.

std::vector<uint8_t>
extract_relocated_text(const std::vector<uint8_t> &object_bytes,
		       const std::vector<uint8_t> &input,
		       const KopTargetMap *kop_targets)
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
	const auto call_src_by_imm = external_call_src_regs(input);
	apply_text_relocations(*object, text, subprog_start, generated_insns,
			       call_src_by_imm, kop_targets);
	if (subprog_start) {
		text.insert(text.end(), input.begin() + *subprog_start * INSN_SIZE,
			    input.end());
	}
	return text;
}

std::unique_ptr<llvm::TargetMachine>
create_bpf_target_machine(llvm::CodeGenOptLevel opt_level)
{
	LLVMInitializeBPFTargetInfo();
	LLVMInitializeBPFTarget();
	LLVMInitializeBPFTargetMC();
	LLVMInitializeBPFAsmPrinter();

	std::string error;
	llvm::Triple triple("bpfel");
#if LLVM_VERSION_MAJOR >= 19
	const llvm::Target *target =
		llvm::TargetRegistry::lookupTarget(triple, error);
#else
	const std::string triple_name = triple.str();
	const llvm::Target *target =
		llvm::TargetRegistry::lookupTarget(triple_name, error);
#endif
	if (!target) {
		throw std::runtime_error("lookupTarget(bpfel) failed: " + error);
	}
	llvm::TargetOptions options;
	auto machine = std::unique_ptr<llvm::TargetMachine>(
#if LLVM_VERSION_MAJOR >= 19
		target->createTargetMachine(triple, "v3", "", options,
					    std::nullopt, std::nullopt,
					    opt_level));
#else
		target->createTargetMachine(triple_name, "v3", "", options,
					    std::nullopt, std::nullopt,
					    opt_level));
#endif
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
	// InstCombine canonicalizes llvmbpf's frame pointers: the lifted code
	// addresses the stack via `inttoptr(ptrtoint(stackEnd) + off)`, which keeps
	// frame stores off the alloca's def-use chain. InstCombine folds
	// `inttoptr(ptrtoint(gep(alloca)))` back to `gep(alloca)`, reconnecting the
	// stores so resolve_const_key can recover a constant key written there.
	function_pipeline.addPass(llvm::InstCombinePass());
	function_pipeline.addPass(llvm::DCEPass());
	llvm::ModulePassManager module_pipeline;
	module_pipeline.addPass(llvm::createModuleToFunctionPassAdaptor(
		std::move(function_pipeline)));
	module_pipeline.run(module, module_am);
}

std::vector<uint8_t> emit_bpf_object(llvm::Module &module)
{
	auto machine = create_bpf_target_machine(llvm::CodeGenOptLevel::Aggressive);
#if LLVM_VERSION_MAJOR >= 19
	module.setTargetTriple(llvm::Triple("bpfel"));
#else
	module.setTargetTriple("bpfel");
#endif
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
					const KopTargetMap *kop_targets)
{
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		return extract_relocated_text(emit_bpf_object(module), input,
					      kop_targets);
	});
}

struct MapInfo {
	uint32_t id = 0;
	std::string name;
	std::string map_type;
	uint32_t key_size = 0;
	uint32_t value_size = 0;
	uint32_t max_entries = 0;
	uint32_t flags = 0;
	bool data_path_mutable = false;
};

constexpr uint32_t BPF_F_RDONLY_PROG_VALUE = 1U << 7;

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
	std::string stability;
};

// Optional CLI entry hint: for map `map_name`, the hex bytes identify the
// lookup key whose snapshotted value may be used. There is one hint kind.
struct InlineHint {
	std::string map_name;
	std::vector<uint8_t> key;
};

enum class MapInlineStability {
	Unspecified,
	Guarded,
	PhaseStable,
};

std::string_view map_inline_stability_name(MapInlineStability stability)
{
	switch (stability) {
	case MapInlineStability::Guarded:
		return "guarded";
	case MapInlineStability::PhaseStable:
		return "phase-stable";
	case MapInlineStability::Unspecified:
		break;
	}
	return "unspecified";
}

struct MapInlineArgs {
	std::filesystem::path map_values;
	std::vector<uint32_t> map_ids;
	std::vector<InlineHint> hints;
	std::set<std::string> included_maps;
	std::set<std::string> excluded_maps;
	std::set<std::string> direct_array_maps;
	MapInlineStability stability = MapInlineStability::Unspecified;
	bool only_hinted = false;
	bool assume_hint_key = false;
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
				value = arg.substr(
					std::strlen("--inline-hint="));
			}
			// name:hex
			const auto colon = value.find(':');
			if (colon == std::string::npos || colon == 0 ||
			    colon + 1 >= value.size()) {
				throw std::runtime_error("invalid --inline-hint");
			}
			auto key_text = value.substr(colon + 1);
			parsed.hints.push_back({ value.substr(0, colon),
						  parse_hex_bytes(key_text) });
		} else if (arg == "--stability") {
			if (++i >= args.size()) {
				throw std::runtime_error(
					"--stability requires guarded or phase-stable");
			}
			if (args[i] == "guarded") {
				parsed.stability = MapInlineStability::Guarded;
			} else if (args[i] == "phase-stable") {
				parsed.stability = MapInlineStability::PhaseStable;
			} else {
				throw std::runtime_error(
					"map_inline --stability must be guarded or phase-stable");
			}
		} else if (arg == "--only-hinted") {
			parsed.only_hinted = true;
		} else if (arg == "--assume-hint-key") {
			parsed.assume_hint_key = true;
		} else if (arg == "--direct-array-map" ||
			   arg.starts_with("--direct-array-map=")) {
			std::string value;
			if (arg == "--direct-array-map") {
				if (++i >= args.size()) {
					throw std::runtime_error(
						"--direct-array-map requires MAP_NAME");
				}
				value = args[i];
			} else {
				value = arg.substr(std::strlen("--direct-array-map="));
			}
			if (value.empty()) {
				throw std::runtime_error(
					"--direct-array-map requires non-empty MAP_NAME");
			}
			if (!parsed.direct_array_maps.insert(value).second) {
				throw std::runtime_error(
					"duplicate map_inline --direct-array-map " + value);
			}
		} else if (arg == "--include-map" ||
			   arg.starts_with("--include-map=")) {
			std::string value;
			if (arg == "--include-map") {
				if (++i >= args.size()) {
					throw std::runtime_error(
						"--include-map requires MAP_NAME");
				}
				value = args[i];
			} else {
				value = arg.substr(std::strlen("--include-map="));
			}
			if (value.empty()) {
				throw std::runtime_error(
					"--include-map requires non-empty MAP_NAME");
			}
			if (!parsed.included_maps.insert(value).second) {
				throw std::runtime_error(
					"duplicate map_inline --include-map " + value);
			}
		} else if (arg == "--exclude-map" ||
			   arg.starts_with("--exclude-map=")) {
			std::string value;
			if (arg == "--exclude-map") {
				if (++i >= args.size()) {
					throw std::runtime_error(
						"--exclude-map requires MAP_NAME");
				}
				value = args[i];
			} else {
				value = arg.substr(std::strlen("--exclude-map="));
			}
			if (value.empty()) {
				throw std::runtime_error(
					"--exclude-map requires non-empty MAP_NAME");
			}
			if (!parsed.excluded_maps.insert(value).second) {
				throw std::runtime_error(
					"duplicate map_inline --exclude-map " + value);
			}
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
	if (parsed.stability == MapInlineStability::Unspecified) {
		throw std::runtime_error(
			"map_inline requires explicit --stability guarded or phase-stable");
	}
	if (parsed.only_hinted && parsed.hints.empty()) {
		throw std::runtime_error(
			"map_inline --only-hinted requires at least one --inline-hint");
	}
	if (parsed.only_hinted && !parsed.included_maps.empty()) {
		throw std::runtime_error(
			"map_inline --only-hinted and --include-map are mutually exclusive");
	}
	if (!parsed.included_maps.empty() && !parsed.excluded_maps.empty()) {
		throw std::runtime_error(
			"map_inline --include-map and --exclude-map are mutually exclusive");
	}
	if (parsed.assume_hint_key && parsed.hints.empty()) {
		throw std::runtime_error(
			"map_inline --assume-hint-key requires at least one --inline-hint");
	}
	if (parsed.assume_hint_key &&
	    parsed.stability != MapInlineStability::PhaseStable) {
		throw std::runtime_error(
			"map_inline --assume-hint-key requires --stability phase-stable");
	}
	return parsed;
}

bool map_inline_map_is_selected(const MapInlineArgs &args,
				const std::string &map_name)
{
	if (args.excluded_maps.contains(map_name)) {
		return false;
	}
	if (!args.included_maps.empty()) {
		return args.included_maps.contains(map_name);
	}
	if (args.only_hinted) {
		return std::any_of(args.hints.begin(), args.hints.end(),
				   [&map_name](const InlineHint &hint) {
					   return hint.map_name == map_name;
				   });
	}
	return true;
}

void validate_map_inline_included_maps(const MapInlineArgs &args,
				       const MapSnapshot &snapshot)
{
	for (const auto &map_name : args.included_maps) {
		if (!snapshot.map_id_by_name.contains(map_name)) {
			throw std::runtime_error(
				"map_inline --include-map references unknown map " +
				map_name);
		}
	}
	for (const auto &map_name : args.direct_array_maps) {
		if (!snapshot.map_id_by_name.contains(map_name)) {
			throw std::runtime_error(
				"map_inline --direct-array-map references unknown map " +
				map_name);
		}
	}
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
		if (auto max_entries = show.getInteger("max_entries")) {
			if (*max_entries < 0 ||
			    *max_entries > std::numeric_limits<uint32_t>::max()) {
				throw std::runtime_error(
					"map show max_entries is not a u32");
			}
			info.max_entries = static_cast<uint32_t>(*max_entries);
		}
		if (auto flags = show.getInteger("flags")) {
			if (*flags < 0 ||
			    *flags > std::numeric_limits<uint32_t>::max()) {
				throw std::runtime_error("map show flags is not a u32");
			}
			info.flags = static_cast<uint32_t>(*flags);
		}
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

// --- IR-level map_inline ---------------------------------------------------
// Everything below works on the lifted LLVM IR; nothing analyzes the raw
// bytecode. llvmbpf lowers a map reference (kernel-compatible mode) to
// `ptrtoint(@__llvmbpf_pseudo_map_idx_<8hex>)`, so a map_lookup_elem call's map
// argument is traced back to that global symbol and the hex index maps through
// the canonical --map-ids list to a map_id.
std::optional<uint32_t> parse_pseudo_map_idx(llvm::StringRef name)
{
	constexpr llvm::StringRef prefix = "__llvmbpf_pseudo_map_idx_";
	if (!name.starts_with(prefix)) {
		return std::nullopt;
	}
	const auto rest = name.drop_front(prefix.size());
	if (rest.size() != 8) {
		return std::nullopt; // exclude the longer _idx_value_ variant
	}
	uint32_t idx = 0;
	if (rest.getAsInteger(16, idx)) {
		return std::nullopt;
	}
	return idx;
}

// Trace an i64 map argument back to its pseudo-map global and return the idx.
std::optional<uint32_t> resolve_map_idx_ir(llvm::Value *v)
{
	for (int hops = 0; hops < 8 && v; hops++) {
		if (auto *ce = llvm::dyn_cast<llvm::ConstantExpr>(v)) {
			if (ce->getOpcode() == llvm::Instruction::PtrToInt ||
			    ce->getOpcode() == llvm::Instruction::BitCast) {
				v = ce->getOperand(0);
				continue;
			}
		}
		if (auto *p2i = llvm::dyn_cast<llvm::PtrToIntInst>(v)) {
			v = p2i->getOperand(0);
			continue;
		}
		if (auto *bc = llvm::dyn_cast<llvm::BitCastInst>(v)) {
			v = bc->getOperand(0);
			continue;
		}
		if (auto *gv = llvm::dyn_cast<llvm::GlobalValue>(v)) {
			return parse_pseudo_map_idx(gv->getName());
		}
		break;
	}
	return std::nullopt;
}

std::optional<uint32_t> lookup_call_map_id(llvm::CallInst *call,
					   const std::vector<uint32_t> &map_ids)
{
	if (call->arg_size() < 1) {
		return std::nullopt;
	}
	const auto idx = resolve_map_idx_ir(call->getArgOperand(0));
	if (!idx || *idx >= map_ids.size()) {
		return std::nullopt;
	}
	return map_ids[*idx];
}

// Maps written by the data path (map_update/delete/push/pop), found by scanning
// IR calls to those helper externs and resolving each call's map argument. Such
// maps are never folded (their snapshot value may be stale).
std::set<uint32_t> ir_mutable_maps(llvm::Module &module,
				   const std::vector<uint32_t> &map_ids)
{
	std::set<uint32_t> mut;
	for (int id : { BPF_FUNC_map_update_elem, BPF_FUNC_map_delete_elem,
			BPF_FUNC_map_push_elem, BPF_FUNC_map_pop_elem }) {
		char buf[32];
		std::snprintf(buf, sizeof(buf), "_bpf_helper_ext_%04d", id);
		auto *fn = module.getFunction(buf);
		if (!fn) {
			continue;
		}
		for (llvm::User *u : fn->users()) {
			if (auto *ci = llvm::dyn_cast<llvm::CallInst>(u)) {
				if (const auto m =
					    lookup_call_map_id(ci, map_ids)) {
					mut.insert(*m);
				}
			}
		}
	}
	return mut;
}

// Build `key_bytes == K` over the lookup's key pointer (arg1), as a chain of
// per-word integer compares ANDed together. Inserted at `b`'s point.
llvm::Value *build_key_match(llvm::IRBuilder<> &b, llvm::Value *key_arg,
			     const std::vector<uint8_t> &k)
{
	auto *keyptr = b.CreateIntToPtr(key_arg, b.getPtrTy());
	llvm::Value *match = b.getTrue();
	size_t off = 0;
	for (; off + 4 <= k.size(); off += 4) {
		auto *p = b.CreateGEP(b.getInt8Ty(), keyptr, b.getInt64(off));
		auto *kv = b.CreateLoad(b.getInt32Ty(), p);
		uint32_t c = 0;
		std::memcpy(&c, k.data() + off, sizeof(c));
		match = b.CreateAnd(match, b.CreateICmpEQ(kv, b.getInt32(c)));
	}
	for (; off < k.size(); off++) {
		auto *p = b.CreateGEP(b.getInt8Ty(), keyptr, b.getInt64(off));
		auto *kv = b.CreateLoad(b.getInt8Ty(), p);
		match = b.CreateAnd(match,
				    b.CreateICmpEQ(kv, b.getInt8(k[off])));
	}
	return match;
}

// Compare the current map value against the profiled bytes. The caller must
// branch on a non-NULL lookup result before entering the block that emits these
// loads. Loads use alignment one because map values may contain packed fields.
llvm::Value *build_value_match(llvm::IRBuilder<> &b, llvm::Value *value_arg,
			       const std::vector<uint8_t> &value)
{
	auto *value_ptr = b.CreateIntToPtr(value_arg, b.getPtrTy());
	llvm::Value *match = b.getTrue();
	size_t off = 0;
	for (; off + 4 <= value.size(); off += 4) {
		auto *pointer = b.CreateGEP(b.getInt8Ty(), value_ptr,
					    b.getInt64(off));
		auto *current = b.CreateLoad(b.getInt32Ty(), pointer,
					     "mapinline.current.word");
		current->setAlignment(llvm::Align(1));
		uint32_t constant = 0;
		std::memcpy(&constant, value.data() + off, sizeof(constant));
		match = b.CreateAnd(
			match, b.CreateICmpEQ(current, b.getInt32(constant)),
			"mapinline.value.words.match");
	}
	for (; off < value.size(); off++) {
		auto *pointer = b.CreateGEP(b.getInt8Ty(), value_ptr,
					    b.getInt64(off));
		auto *current = b.CreateLoad(b.getInt8Ty(), pointer,
					     "mapinline.current.byte");
		current->setAlignment(llvm::Align(1));
		match = b.CreateAnd(
			match, b.CreateICmpEQ(current, b.getInt8(value[off])),
			"mapinline.value.bytes.match");
	}
	return match;
}

// Allocate a fresh entry-block stack buffer of `size` bytes (so no constant
// global / .rodata map is introduced for the value).
llvm::AllocaInst *alloc_value_buf(llvm::Function *fn, size_t size)
{
	llvm::IRBuilder<> eb(&*fn->getEntryBlock().getFirstInsertionPt());
	auto *arr = llvm::ArrayType::get(eb.getInt8Ty(), size);
	return eb.CreateAlloca(arr, nullptr, "mapinline.buf");
}

// Store the snapshot constant `value` into `buf` at `b`'s point, as i32 words +
// i8 tail (the proven roundtrip granularity).
void store_const_to_buf(llvm::IRBuilder<> &b, llvm::Value *buf,
			const std::vector<uint8_t> &value)
{
	size_t off = 0;
	for (; off + 4 <= value.size(); off += 4) {
		uint32_t w = 0;
		std::memcpy(&w, value.data() + off, sizeof(w));
		b.CreateStore(b.getInt32(w),
			      b.CreateGEP(b.getInt8Ty(), buf, b.getInt64(off)));
	}
	for (; off < value.size(); off++) {
		b.CreateStore(b.getInt8(value[off]),
			      b.CreateGEP(b.getInt8Ty(), buf, b.getInt64(off)));
	}
}

// Materialize `value` into a fresh entry-block stack slot and return its address
// as an i64 — the representation a map_lookup_elem result carries. Used by the
// unconditional folds (uniform / const-key); O3's SROA forwards the stored bytes
// into the downstream value loads.
llvm::Value *materialize_value_ptr(llvm::IRBuilder<> &b,
				   const std::vector<uint8_t> &value,
				   llvm::Type *i64ty)
{
	auto *buf = alloc_value_buf(b.GetInsertBlock()->getParent(), value.size());
	store_const_to_buf(b, buf, value);
	return b.CreatePtrToInt(buf, i64ty);
}

// Hinted-entry speculation as a real control-flow guard, NOT a select:
//
//   orig:  %m = (key == K)
//          br %m, fast, slow
//   fast:  <materialize snapshot V on stack>       ; skips the lookup entirely
//          br merge
//   slow:  %r = call map_lookup_elem(...)           ; live value, writes preserved
//          br merge
//   merge: %r0 = phi [&buf, fast], [%r, slow]
//
// A select would still run the (expensive, e.g. HASH) lookup every dispatch;
// this branch skips it on the fast path. Replacing the result at the call
// boundary handles every downstream use uniformly (loads, null checks, PHIs).
// The key guard preserves all other keys and misses, but it does not prove that
// K's snapshotted value remains current. The pass therefore requires the
// caller's explicit `--stability phase-stable` contract: the selected map
// values must not change while this program version is installed. A later map
// update requires installing a new version before the changed value is used.
// When K is a provable constant O3 folds the branch away and DCEs the call.
//
// NOTE: the fast path gives the verifier a known-constant value where the slow
// path has an unknown live value; these are distinct value-abstractions, so the
// verifier explores the lookup's downstream for both. That cost is inherent to
// speculation and scales with the downstream size — cheap for a value consumed
// as a small scalar (e.g. vip_map -> real index), but ~50k processed insns for a
// value that feeds a large cone (e.g. an ARRAY reals entry driving IPIP encap).
// Only worth guarding lookups that are themselves expensive (HASH), not cheap
// O(1) ARRAY indices.
void fold_guarded_branch(llvm::Module &module, llvm::CallInst *call,
			 const std::vector<uint8_t> &key,
			 const std::vector<uint8_t> &value)
{
	llvm::LLVMContext &ctx = module.getContext();
	llvm::BasicBlock *orig = call->getParent();
	llvm::Function *fn = orig->getParent();

	// Split so `call` opens the slow block and the rest becomes the merge.
	llvm::BasicBlock *slow = orig->splitBasicBlock(call, "mapinline.slow");
	llvm::BasicBlock *merge =
		slow->splitBasicBlock(call->getNextNode(), "mapinline.merge");

	llvm::BasicBlock *fast =
		llvm::BasicBlock::Create(ctx, "mapinline.fast", fn, slow);
	llvm::IRBuilder<> fb(fast);
	auto *fast_ptr = materialize_value_ptr(fb, value, call->getType());
	fb.CreateBr(merge);

	// Replace orig's unconditional branch (to slow) with the key guard.
	llvm::IRBuilder<> ob(orig->getTerminator());
	auto *match = build_key_match(ob, call->getArgOperand(1), key);
	orig->getTerminator()->eraseFromParent();
	llvm::BranchInst::Create(fast, slow, match, orig);

	auto *phi = llvm::PHINode::Create(call->getType(), 2, "mapinline.r0",
					  &*merge->getFirstInsertionPt());
	call->replaceAllUsesWith(phi);
	phi->addIncoming(fast_ptr, fast);
	phi->addIncoming(call, slow);
}

// Guarded-freshness mode always performs the real lookup. It substitutes the
// profiled constant only when the selected key (if any), non-NULL result, and
// every current value byte match the snapshot:
//
//   r = map_lookup_elem(map, key)
//   if selected_key(key) && r != NULL && *r == snapshot:
//       use snapshot constant
//   else:
//       use r
//
// This provides immediate per-invocation fallback when a deployment phase
// changes. It deliberately does not claim lookup elimination; phase-stable
// mode below is the stronger contract that permits skipping the helper.
void fold_value_guarded_branch(llvm::Module &module, llvm::CallInst *call,
			       const std::vector<uint8_t> &selected_key,
			       const std::vector<uint8_t> &value)
{
	llvm::LLVMContext &context = module.getContext();
	llvm::BasicBlock *lookup = call->getParent();
	llvm::Function *function = lookup->getParent();
	llvm::Instruction *continuation = call->getNextNode();
	if (!continuation) {
		throw std::runtime_error(
			"map_inline lookup has no continuation for guarded mode");
	}

	// Preserve only the uses that existed before the guard is built. New guard
	// uses must keep referring to the real helper result, not the merge PHI.
	std::vector<llvm::Use *> original_uses;
	for (llvm::Use &use : call->uses()) {
		original_uses.push_back(&use);
	}

	llvm::BasicBlock *merge = lookup->splitBasicBlock(
		continuation, "mapinline.merge");
	llvm::BasicBlock *compare = llvm::BasicBlock::Create(
		context, "mapinline.compare", function, merge);
	llvm::BasicBlock *fast = llvm::BasicBlock::Create(
		context, "mapinline.fast", function, merge);
	llvm::BasicBlock *slow = llvm::BasicBlock::Create(
		context, "mapinline.slow", function, merge);

	llvm::IRBuilder<> lookup_builder(lookup->getTerminator());
	llvm::Value *eligible = lookup_builder.CreateICmpNE(
		call, llvm::ConstantInt::get(call->getType(), 0),
		"mapinline.nonnull");
	if (!selected_key.empty()) {
		eligible = lookup_builder.CreateAnd(
			eligible,
			build_key_match(lookup_builder, call->getArgOperand(1),
					selected_key),
			"mapinline.selected.current");
	}
	lookup->getTerminator()->eraseFromParent();
	llvm::BranchInst::Create(compare, slow, eligible, lookup);

	llvm::IRBuilder<> compare_builder(compare);
	auto *fresh = build_value_match(compare_builder, call, value);
	compare_builder.CreateCondBr(fresh, fast, slow);

	llvm::IRBuilder<> fast_builder(fast);
	auto *fast_ptr = materialize_value_ptr(
		fast_builder, value, call->getType());
	fast_builder.CreateBr(merge);
	llvm::IRBuilder<>(slow).CreateBr(merge);

	auto *phi = llvm::PHINode::Create(call->getType(), 2,
					  "mapinline.r0",
					  &*merge->getFirstInsertionPt());
	for (llvm::Use *use : original_uses) {
		use->set(phi);
	}
	phi->addIncoming(fast_ptr, fast);
	phi->addIncoming(call, slow);
}

// Walk every constant-offset store reachable from alloca pointer `p` at
// cumulative byte offset `off`, recording (byte offset, store). Used to recover
// a frame slot's contents. Loads / ptrtoint / calls are ignored (they read the
// slot; only stores define it).
void collect_alloca_stores(
	llvm::Value *p, int64_t off, const llvm::DataLayout &dl,
	std::vector<std::pair<int64_t, llvm::StoreInst *>> &out)
{
	for (llvm::User *u : p->users()) {
		if (auto *st = llvm::dyn_cast<llvm::StoreInst>(u)) {
			if (st->getPointerOperand() == p) {
				out.push_back({ off, st });
			}
		} else if (auto *gep =
				   llvm::dyn_cast<llvm::GetElementPtrInst>(u)) {
			llvm::APInt o(64, 0);
			if (gep->accumulateConstantOffset(dl, o)) {
				collect_alloca_stores(
					gep, off + o.getSExtValue(), dl, out);
			}
		}
	}
}

// Recover a compile-time-constant lookup key from arg1 when it points to a frame
// slot written only by constant stores that dominate the call. llvmbpf lifts the
// BPF frame as an alloca plus `ptrtoint(stackEnd)` integer arithmetic, so the key
// pointer looks like `ptrtoint(gep(stackBegin, FS)) + C`; LLVM cannot
// alias-analyze that integer form back to the `gep(stackBegin, off)` stores, so
// O3 never folds such a constant key itself. Recovering it here lets a
// constant-key lookup fold unconditionally (no guard) — sound, and the value
// then const-propagates like a uniform fold. Each covered byte must be written
// by exactly one constant store that dominates the call (any second or runtime
// store to those bytes aborts, since ordering can't be proven).
std::optional<std::vector<uint8_t>>
resolve_const_key(llvm::CallInst *call, size_t key_size, llvm::DominatorTree &dt,
		  const llvm::DataLayout &dl)
{
	llvm::Value *kp = call->getArgOperand(1);
	int64_t add_c = 0;
	if (auto *bo = llvm::dyn_cast<llvm::BinaryOperator>(kp)) {
		if (bo->getOpcode() == llvm::Instruction::Add) {
			if (auto *c = llvm::dyn_cast<llvm::ConstantInt>(
				    bo->getOperand(1))) {
				add_c = c->getSExtValue();
				kp = bo->getOperand(0);
			}
		}
	}
	auto *p2i = llvm::dyn_cast<llvm::PtrToIntInst>(kp);
	if (!p2i) {
		return std::nullopt;
	}
	llvm::Value *base = p2i->getPointerOperand();
	int64_t base_off = 0;
	while (auto *gep = llvm::dyn_cast<llvm::GetElementPtrInst>(base)) {
		llvm::APInt o(64, 0);
		if (!gep->accumulateConstantOffset(dl, o)) {
			return std::nullopt;
		}
		base_off += o.getSExtValue();
		base = gep->getPointerOperand();
	}
	auto *slot = llvm::dyn_cast<llvm::AllocaInst>(base);
	if (!slot) {
		return std::nullopt;
	}
	const int64_t key_off = base_off + add_c;
	if (key_off < 0) {
		return std::nullopt;
	}
	std::vector<std::pair<int64_t, llvm::StoreInst *>> stores;
	collect_alloca_stores(slot, 0, dl, stores);
	std::vector<uint8_t> key(key_size, 0);
	std::vector<bool> have(key_size, false);    // some store sets this byte
	std::vector<bool> covered(key_size, false); // a dominating store sets it
	// Every store touching the key bytes must be a constant; all stores must
	// agree per byte; and each byte must have at least one store that
	// dominates the call. Then — regardless of path or ordering — that byte
	// holds the agreed constant at the call (the dominating store guarantees
	// it is written; all writers store the same value). Any runtime or
	// disagreeing write to the key bytes aborts.
	for (const auto &[soff, st] : stores) {
		const auto width = dl.getTypeStoreSize(
			st->getValueOperand()->getType());
		const int64_t lo = std::max<int64_t>(soff, key_off);
		const int64_t hi = std::min<int64_t>(soff + (int64_t)width,
						     key_off + (int64_t)key_size);
		if (lo >= hi) {
			continue; // store does not touch the key bytes
		}
		auto *cv = llvm::dyn_cast<llvm::ConstantInt>(st->getValueOperand());
		if (!cv) {
			return std::nullopt; // runtime write to the key bytes
		}
		const bool dom = dt.dominates(st, call);
		const auto value = cv->getValue();
		for (int64_t b = lo; b < hi; b++) {
			const auto byte = static_cast<uint8_t>(
				value.extractBitsAsZExtValue(8, (b - soff) * 8));
			const size_t i = b - key_off;
			if (have[i] && key[i] != byte) {
				return std::nullopt; // conflicting writers
			}
			key[i] = byte;
			have[i] = true;
			covered[i] = covered[i] || dom;
		}
	}
	for (size_t i = 0; i < key_size; i++) {
		if (!covered[i]) {
			return std::nullopt; // byte not guaranteed-written by a const
		}
	}
	return key;
}

// All-IR map_inline. For each map_lookup_elem call: resolve its map (IR symbol),
// skip data-path-mutable maps, and fold per the snapshot. Three cases, in
// priority order:
//   1. constant key (recovered via resolve_const_key) -> UNCONDITIONAL fold:
//      replace the result with a stack copy of the value and delete the lookup.
//      Under the explicit phase-stable value contract, no key guard is needed,
//      and (no result phi) the value const-propagates like a uniform fold. This is "if the key is
//      constant, skip the call" — done by us, since O3 can't see the constant
//      through llvmbpf's ptrtoint frame arithmetic.
//   2. uniform map -> UNCONDITIONAL fold (value is key-independent).
//   3. CLI entry hint on a runtime key -> guarded branch: fast path skips
//      the lookup, slow path keeps the real lookup as a sound fallback.
struct FoldDecision {
	llvm::CallInst *call;
	std::vector<uint8_t> key;
	std::vector<uint8_t> value;
	bool guard_key;
	bool sparse_scalar;
	uint32_t map_id;
};

struct SparseScalarFoldPlan {
	std::vector<std::pair<llvm::LoadInst *, uint64_t>> loads;
	std::vector<std::pair<llvm::ICmpInst *, bool>> null_checks;
	std::vector<std::pair<llvm::PHINode *, unsigned>> null_edge_phis;
	std::vector<llvm::Instruction *> derived_pointers;
};

bool is_null_constant(llvm::Value *value)
{
	if (auto *integer = llvm::dyn_cast<llvm::ConstantInt>(value)) {
		return integer->isZero();
	}
	return llvm::isa<llvm::ConstantPointerNull>(value);
}

std::optional<bool> null_comparison_nonnull_result(llvm::ICmpInst *compare,
						    llvm::Value *value)
{
	const unsigned operand = compare->getOperand(0) == value ? 0 :
				 compare->getOperand(1) == value ? 1 : 2;
	if (operand == 2 ||
	    !is_null_constant(compare->getOperand(1 - operand)) ||
	    (compare->getPredicate() != llvm::CmpInst::ICMP_EQ &&
	     compare->getPredicate() != llvm::CmpInst::ICMP_NE)) {
		return std::nullopt;
	}
	return compare->getPredicate() == llvm::CmpInst::ICMP_NE;
}

bool collect_sparse_scalar_uses(
	llvm::Value *value, int64_t offset, size_t value_size,
	const llvm::DataLayout &layout, SparseScalarFoldPlan &plan,
	std::map<llvm::Value *, int64_t> &visited)
{
	if (auto found = visited.find(value); found != visited.end()) {
		return found->second == offset;
	}
	visited.emplace(value, offset);

	for (llvm::Use &use : value->uses()) {
		auto *user = llvm::dyn_cast<llvm::Instruction>(use.getUser());
		if (!user) {
			return false;
		}
		if (auto *load = llvm::dyn_cast<llvm::LoadInst>(user)) {
			if (load->getPointerOperand() != value || load->isVolatile() ||
			    load->isAtomic() || !load->getType()->isIntegerTy()) {
				return false;
			}
			const unsigned bits = load->getType()->getIntegerBitWidth();
			if (bits == 0 || bits > 64 || bits % 8 != 0 || offset < 0 ||
			    static_cast<uint64_t>(offset) > value_size ||
			    bits / 8 > value_size - static_cast<uint64_t>(offset)) {
				return false;
			}
			plan.loads.emplace_back(load, static_cast<uint64_t>(offset));
			continue;
		}
		if (auto *compare = llvm::dyn_cast<llvm::ICmpInst>(user)) {
			const auto nonnull_result =
				null_comparison_nonnull_result(compare, value);
			if (!nonnull_result) {
				return false;
			}
			plan.null_checks.emplace_back(compare, *nonnull_result);
			continue;
		}
		if (auto *phi = llvm::dyn_cast<llvm::PHINode>(user)) {
			const unsigned incoming_index = use.getOperandNo();
			if (incoming_index >= phi->getNumIncomingValues()) {
				return false;
			}
			auto *incoming = phi->getIncomingBlock(incoming_index);
			auto *branch = llvm::dyn_cast<llvm::BranchInst>(
				incoming->getTerminator());
			if (!branch || !branch->isConditional()) {
				return false;
			}
			auto *compare = llvm::dyn_cast<llvm::ICmpInst>(
				branch->getCondition());
			const auto nonnull_when_true = compare ?
				null_comparison_nonnull_result(compare, value) :
				std::nullopt;
			if (!nonnull_when_true) {
				return false;
			}
			const bool edge_is_true =
				branch->getSuccessor(0) == phi->getParent();
			const bool edge_is_false =
				branch->getSuccessor(1) == phi->getParent();
			if (edge_is_true == edge_is_false ||
			    edge_is_true == *nonnull_when_true) {
				return false;
			}
			plan.null_edge_phis.emplace_back(phi, incoming_index);
			continue;
		}
		if (auto *gep = llvm::dyn_cast<llvm::GetElementPtrInst>(user)) {
			if (gep->getPointerOperand() != value) {
				return false;
			}
			llvm::APInt delta(64, 0);
			if (!gep->accumulateConstantOffset(layout, delta)) {
				return false;
			}
			if (!collect_sparse_scalar_uses(
				    gep, offset + delta.getSExtValue(), value_size,
				    layout, plan, visited)) {
				return false;
			}
			plan.derived_pointers.push_back(gep);
			continue;
		}
		if (llvm::isa<llvm::IntToPtrInst>(user) ||
		    llvm::isa<llvm::PtrToIntInst>(user) ||
		    llvm::isa<llvm::BitCastInst>(user) ||
		    llvm::isa<llvm::AddrSpaceCastInst>(user)) {
			if (user->getOperand(0) != value) {
				return false;
			}
			if (!collect_sparse_scalar_uses(
				    user, offset, value_size, layout, plan, visited)) {
				return false;
			}
			plan.derived_pointers.push_back(user);
			continue;
		}
		return false;
	}
	return true;
}

std::optional<SparseScalarFoldPlan>
sparse_scalar_fold_plan(llvm::CallInst *call,
			const std::vector<uint8_t> &value,
			const llvm::DataLayout &layout)
{
	if (call->use_empty()) {
		return std::nullopt;
	}
	SparseScalarFoldPlan plan;
	std::map<llvm::Value *, int64_t> visited;
	if (!collect_sparse_scalar_uses(
		    call, 0, value.size(), layout, plan, visited) ||
	    (plan.loads.empty() && plan.null_checks.empty())) {
		return std::nullopt;
	}
	return plan;
}

void fold_sparse_scalar_lookup(llvm::CallInst *call,
			       const std::vector<uint8_t> &value,
			       const llvm::DataLayout &layout)
{
	auto plan = sparse_scalar_fold_plan(call, value, layout);
	if (!plan) {
		throw std::runtime_error(
			"map_inline sparse scalar use graph changed during application");
	}
	for (const auto &[load, offset] : plan->loads) {
		const unsigned bits = load->getType()->getIntegerBitWidth();
		uint64_t constant = 0;
		for (unsigned byte = 0; byte < bits / 8; byte++) {
			constant |= static_cast<uint64_t>(
				value[static_cast<size_t>(offset) + byte]) <<
				(byte * 8);
		}
		load->replaceAllUsesWith(
			llvm::ConstantInt::get(load->getType(), constant));
	}
	for (const auto &[compare, nonnull_result] : plan->null_checks) {
		compare->replaceAllUsesWith(llvm::ConstantInt::get(
			compare->getType(), nonnull_result));
	}
	for (const auto &[phi, incoming_index] : plan->null_edge_phis) {
		phi->setIncomingValue(
			incoming_index,
			llvm::ConstantInt::get(call->getType(), 0));
	}
	for (const auto &[load, _] : plan->loads) {
		load->eraseFromParent();
	}
	for (const auto &[compare, _] : plan->null_checks) {
		compare->eraseFromParent();
	}
	for (llvm::Instruction *pointer : plan->derived_pointers) {
		if (!pointer->use_empty()) {
			throw std::runtime_error(
				"map_inline sparse derived pointer remains live");
		}
		pointer->eraseFromParent();
	}
	if (!call->use_empty()) {
		throw std::runtime_error(
			"map_inline sparse lookup remains live after scalar folding");
	}
	call->eraseFromParent();
}

// Materialized folds consume BPF stack so downstream pointer uses remain
// valid. Account for the existing static frame before choosing such a site.
// A phase-stable exact entry whose uses are only fixed-offset scalar loads
// takes the sparse path above and needs no value-sized stack allocation.
uint64_t static_alloca_bytes(const llvm::Function &function,
			     const llvm::DataLayout &layout)
{
	uint64_t bytes = 0;
	for (const llvm::BasicBlock &block : function) {
		for (const llvm::Instruction &instruction : block) {
			auto *alloca = llvm::dyn_cast<llvm::AllocaInst>(
				&instruction);
			if (!alloca) {
				continue;
			}
			auto *count = llvm::dyn_cast<llvm::ConstantInt>(
				alloca->getArraySize());
			if (!count) {
				return 512;
			}
			const auto type_size =
				layout.getTypeAllocSize(alloca->getAllocatedType());
			if (type_size.isScalable()) {
				return 512;
			}
			const uint64_t alignment = alloca->getAlign().value();
			bytes = llvm::alignTo(bytes, alignment);
			const uint64_t count_value = count->getZExtValue();
			const uint64_t element_size = type_size.getFixedValue();
			if (count_value != 0 &&
			    element_size >
				    (std::numeric_limits<uint64_t>::max() - bytes) /
					    count_value) {
				return 512;
			}
			bytes += element_size * count_value;
		}
	}
	return bytes;
}

struct PseudoMapValueSymbol {
	uint32_t map_index;
	uint32_t base_offset;
};

std::optional<PseudoMapValueSymbol>
parse_pseudo_map_value_symbol(llvm::StringRef name)
{
	const llvm::StringRef prefix =
		"__llvmbpf_pseudo_map_idx_value_";
	const llvm::StringRef separator = "_off_";
	if (!name.starts_with(prefix)) {
		return std::nullopt;
	}
	name = name.drop_front(prefix.size());
	if (name.size() != 8 + separator.size() + 8 ||
	    name.substr(8, separator.size()) != separator) {
		throw std::runtime_error("malformed pseudo map-value symbol");
	}
	return PseudoMapValueSymbol{
		parse_hex_u32(name.substr(0, 8).str()),
		parse_hex_u32(name.substr(8 + separator.size(), 8).str()),
	};
}

struct PseudoMapValuePointer {
	llvm::GlobalVariable *symbol;
	PseudoMapValueSymbol reference;
	int64_t derived_offset;
};

std::optional<PseudoMapValuePointer>
pseudo_map_value_pointer(llvm::Value *pointer, const llvm::DataLayout &layout)
{
	llvm::APInt offset(layout.getPointerSizeInBits(), 0, true);
	llvm::Value *root = pointer->stripAndAccumulateConstantOffsets(
		layout, offset, true);
	auto *symbol = llvm::dyn_cast<llvm::GlobalVariable>(root);
	if (!symbol) {
		return std::nullopt;
	}
	auto reference = parse_pseudo_map_value_symbol(symbol->getName());
	if (!reference) {
		return std::nullopt;
	}
	return PseudoMapValuePointer{
		symbol, *reference, offset.getSExtValue()
	};
}

// libbpf global data accesses are relocated as BPF_PSEUDO_MAP_VALUE pointers,
// not map_lookup_elem calls.  A program-read-only array (for example an
// application's .rodata configuration map) cannot be changed by any BPF data
// path.  Under the explicit phase-stable contract, fixed-width loads from its
// snapshotted value can therefore be folded exactly like fixed-key lookups.
// Writable .data/.bss maps and guarded mode remain untouched.
std::vector<InlineRecord>
fold_pseudo_map_value_loads_ir(llvm::Module &module,
			       const MapInlineArgs &args)
{
	std::vector<InlineRecord> records;
	if (args.stability != MapInlineStability::PhaseStable) {
		return records;
	}
	auto *main_fn = module.getFunction("bpf_main");
	if (!main_fn) {
		return records;
	}
	const auto snapshot = read_map_snapshot(args);
	validate_map_inline_included_maps(args, snapshot);
	const auto &layout = module.getDataLayout();
	std::set<llvm::GlobalVariable *> written_symbols;
	for (llvm::BasicBlock &block : *main_fn) {
		for (llvm::Instruction &instruction : block) {
			llvm::Value *pointer = nullptr;
			if (auto *store = llvm::dyn_cast<llvm::StoreInst>(&instruction)) {
				pointer = store->getPointerOperand();
			} else if (auto *atomic =
					   llvm::dyn_cast<llvm::AtomicRMWInst>(&instruction)) {
				pointer = atomic->getPointerOperand();
			} else if (auto *compare =
					   llvm::dyn_cast<llvm::AtomicCmpXchgInst>(&instruction)) {
				pointer = compare->getPointerOperand();
			}
			if (pointer) {
				if (auto target = pseudo_map_value_pointer(pointer, layout)) {
					written_symbols.insert(target->symbol);
				}
			}
		}
	}

	struct Fold {
		llvm::LoadInst *load;
		uint32_t map_id;
		std::vector<uint8_t> key;
		std::vector<uint8_t> bytes;
	};
	std::vector<Fold> folds;
	for (llvm::BasicBlock &block : *main_fn) {
		for (llvm::Instruction &instruction : block) {
			auto *load = llvm::dyn_cast<llvm::LoadInst>(&instruction);
			if (!load || load->isVolatile() || load->isAtomic() ||
			    !load->getType()->isIntegerTy()) {
				continue;
			}
			const unsigned bits = load->getType()->getIntegerBitWidth();
			if (bits == 0 || bits > 64 || bits % 8 != 0) {
				continue;
			}
			auto target = pseudo_map_value_pointer(
				load->getPointerOperand(), layout);
			if (!target || written_symbols.count(target->symbol) ||
			    target->reference.map_index >= args.map_ids.size()) {
				continue;
			}
			const uint32_t map_id =
				args.map_ids[target->reference.map_index];
			const auto info_it = snapshot.maps.find(map_id);
			if (map_id == 0 || info_it == snapshot.maps.end()) {
				continue;
			}
			const MapInfo &info = info_it->second;
			if (info.map_type != "array" ||
			    !(info.flags & BPF_F_RDONLY_PROG_VALUE)) {
				continue;
			}
			if (!map_inline_map_is_selected(args, info.name)) {
				continue;
			}
			std::vector<uint8_t> key(info.key_size, 0);
			const auto value_it = snapshot.values.find(
				{ map_id, bytes_hex(key) });
			if (value_it == snapshot.values.end()) {
				continue;
			}
			const int64_t absolute_offset =
				static_cast<int64_t>(target->reference.base_offset) +
				target->derived_offset;
			const size_t width = bits / 8;
			if (absolute_offset < 0 ||
			    static_cast<uint64_t>(absolute_offset) >
				    value_it->second.size() ||
			    width > value_it->second.size() -
					    static_cast<size_t>(absolute_offset)) {
				continue;
			}
			const auto begin = value_it->second.begin() + absolute_offset;
			folds.push_back({
				load, map_id, std::move(key),
				std::vector<uint8_t>(begin, begin + width),
			});
		}
	}

	for (Fold &fold : folds) {
		uint64_t constant = 0;
		for (size_t i = 0; i < fold.bytes.size(); i++) {
			constant |= static_cast<uint64_t>(fold.bytes[i]) << (8 * i);
		}
		fold.load->replaceAllUsesWith(
			llvm::ConstantInt::get(fold.load->getType(), constant));
		fold.load->eraseFromParent();
		records.push_back({
			fold.map_id, std::move(fold.key), std::move(fold.bytes),
			std::string(map_inline_stability_name(args.stability)),
		});
	}
	return records;
}

llvm::Constant *direct_array_value_argument(llvm::Module &module,
					    uint32_t map_index,
					    uint32_t value_offset,
					    llvm::Type *result_type)
{
	if (!result_type->isIntegerTy(64)) {
		throw std::runtime_error(
			"map_inline lookup helper has unexpected result type");
	}
	char symbol_name[96];
	std::snprintf(symbol_name, sizeof(symbol_name),
		      "__llvmbpf_pseudo_map_idx_value_%08x_off_%08x",
		      map_index, value_offset);
	auto *symbol = module.getNamedGlobal(symbol_name);
	if (!symbol) {
		symbol = new llvm::GlobalVariable(
			module, llvm::Type::getInt8Ty(module.getContext()), false,
			llvm::GlobalValue::ExternalLinkage, nullptr, symbol_name);
	}
	return llvm::ConstantExpr::getPtrToInt(symbol, result_type);
}

// A stock-kernel ARRAY with one element has a stable direct value address for
// the lifetime of the map.  When the key is proven to be zero, explicitly
// requested deployment specialization can replace map_lookup_elem with that
// live address.  This does not snapshot or freeze the value: subsequent loads
// and atomic writes still access the real map value.  The one-entry restriction
// mirrors array_map_direct_value_addr() in the stock kernel verifier.
std::vector<InlineRecord>
direct_array_lookups_ir(llvm::Module &module, const MapInlineArgs &args)
{
	std::vector<InlineRecord> records;
	if (args.direct_array_maps.empty()) {
		return records;
	}
	auto *lookup = module.getFunction("_bpf_helper_ext_0001");
	auto *main_fn = module.getFunction("bpf_main");
	if (!lookup || !main_fn) {
		return records;
	}
	const auto snapshot = read_map_snapshot(args);
	validate_map_inline_included_maps(args, snapshot);
	const auto &layout = module.getDataLayout();
	llvm::DominatorTree dominators(*main_fn);
	struct Decision {
		llvm::CallInst *call;
		uint32_t map_index;
		uint32_t map_id;
		std::vector<uint8_t> key;
	};
	std::vector<Decision> decisions;
	for (llvm::BasicBlock &block : *main_fn) {
		for (llvm::Instruction &instruction : block) {
			auto *call = llvm::dyn_cast<llvm::CallInst>(&instruction);
			if (!call || call->getCalledFunction() != lookup ||
			    call->arg_size() < 1) {
				continue;
			}
			const auto map_index =
				resolve_map_idx_ir(call->getArgOperand(0));
			if (!map_index || *map_index >= args.map_ids.size()) {
				continue;
			}
			const uint32_t map_id = args.map_ids[*map_index];
			const auto map_it = snapshot.maps.find(map_id);
			if (map_id == 0 || map_it == snapshot.maps.end()) {
				continue;
			}
			const MapInfo &info = map_it->second;
			if (!args.direct_array_maps.contains(info.name) ||
			    info.map_type != "array" || info.key_size != sizeof(uint32_t) ||
			    info.max_entries != 1) {
				continue;
			}
			auto key = resolve_const_key(call, info.key_size, dominators,
						     layout);
			if (!key || key->size() != sizeof(uint32_t) ||
			    std::any_of(key->begin(), key->end(),
					[](uint8_t byte) { return byte != 0; })) {
				continue;
			}
			decisions.push_back({ call, *map_index, map_id, std::move(*key) });
		}
	}
	for (Decision &decision : decisions) {
		decision.call->replaceAllUsesWith(direct_array_value_argument(
			module, decision.map_index, 0, decision.call->getType()));
		decision.call->eraseFromParent();
		records.push_back({ decision.map_id, std::move(decision.key), {},
				    "direct-location" });
	}
	return records;
}

std::vector<InlineRecord> fold_map_lookups_ir(llvm::Module &module,
					      const MapInlineArgs &args)
{
	std::vector<InlineRecord> records;
	auto *lookup = module.getFunction("_bpf_helper_ext_0001");
	auto *main_fn = module.getFunction("bpf_main");
	if (!lookup || !main_fn) {
		return records;
	}
	const auto snapshot = read_map_snapshot(args);
	validate_map_inline_included_maps(args, snapshot);
	const auto mutable_maps = ir_mutable_maps(module, args.map_ids);
	std::map<std::string, std::vector<uint8_t>> hint_key;
	for (const auto &h : args.hints) {
		const auto map = snapshot.map_id_by_name.find(h.map_name);
		if (map == snapshot.map_id_by_name.end()) {
			throw std::runtime_error(
				"map_inline hint references unknown map " + h.map_name);
		}
		if (h.key.size() != snapshot.maps.at(map->second).key_size) {
			throw std::runtime_error(
				"map_inline hint key size mismatch for map " + h.map_name);
		}
		hint_key[h.map_name] = h.key;
	}
	const auto &dl = module.getDataLayout();
	llvm::DominatorTree dt(*main_fn);
	uint64_t materialized_bytes = static_alloca_bytes(*main_fn, dl);
	// llvmbpf's lifted register machine needs backend spill space in addition
	// to explicit IR allocas.  A materialized value larger than half the BPF
	// stack cannot leave bounded room for those spills; Tracee's 272-byte
	// config_map demonstrates the failure even for a 46-instruction input.
	/* Guarded freshness retains the lookup and adds a bytewise live-value
	 * comparison, so large values quickly cost more instructions and verifier
	 * states than the lookup can save.  Phase-stable versions may still use the
	 * wider limit because their hot path removes the lookup entirely. */
	const uint64_t max_materialized_value_bytes =
		args.stability == MapInlineStability::Guarded ? 64 : 256;

	// Phase 1 — analysis only (no IR mutation), so the dominator tree stays
	// valid for resolve_const_key across every site.
	std::vector<FoldDecision> decisions;
	for (auto &bb : *main_fn) {
		for (auto &inst : bb) {
			auto *call = llvm::dyn_cast<llvm::CallInst>(&inst);
			if (!call || call->getCalledFunction() != lookup) {
				continue;
			}
			const auto map_id = lookup_call_map_id(call, args.map_ids);
			if (!map_id || mutable_maps.count(*map_id)) {
				continue;
			}
			const auto mi = snapshot.maps.find(*map_id);
			if (mi == snapshot.maps.end() ||
			    !map_type_supports_value_inline(mi->second.map_type)) {
				continue;
			}
			if (!map_inline_map_is_selected(args, mi->second.name)) {
				continue;
			}
			std::optional<std::vector<uint8_t>> value;
			bool guard_key = false;
			std::vector<uint8_t> key;
			if (auto ck = resolve_const_key(call, mi->second.key_size,
							dt, dl)) {
				const auto exact = snapshot.values.find(
					{ *map_id, bytes_hex(*ck) });
				if (exact != snapshot.values.end()) {
					key = *ck;
					value = exact->second;
				}
			}
			if (!value) {
				const auto hit = hint_key.find(mi->second.name);
				if (hit != hint_key.end()) {
					key = hit->second;
					const auto exact = snapshot.values.find(
						{ *map_id, bytes_hex(key) });
					if (exact != snapshot.values.end()) {
						value = exact->second;
					} else if (snapshot.truly_uniform.count(
							   *map_id)) {
						value = snapshot.uniform_values.at(
							*map_id);
					}
					guard_key = !args.assume_hint_key;
				} else if (snapshot.truly_uniform.count(*map_id)) {
					value = snapshot.uniform_values.at(*map_id);
				}
			}
			if (!value || value->size() != mi->second.value_size ||
			    (guard_key && key.size() != mi->second.key_size)) {
				continue;
			}
			const bool sparse_scalar =
				args.stability == MapInlineStability::PhaseStable &&
				!guard_key && !key.empty() &&
				sparse_scalar_fold_plan(call, *value, dl).has_value();
			if (!sparse_scalar) {
				if (value->size() > max_materialized_value_bytes) {
					continue;
				}
				const uint64_t aligned = llvm::alignTo(
					materialized_bytes, uint64_t{8});
				if (value->size() > 512 ||
				    aligned > 512 - value->size()) {
					continue;
				}
				materialized_bytes = aligned + value->size();
			}
			decisions.push_back(
				{ call, key, *value, guard_key, sparse_scalar, *map_id });
		}
	}

	// Phase 2 — apply. Guarded folds split blocks (invalidating the dominator
	// tree), but phase 1 made all dominance queries already.
	for (auto &d : decisions) {
		if (d.sparse_scalar) {
			fold_sparse_scalar_lookup(d.call, d.value, dl);
		} else if (args.stability == MapInlineStability::Guarded) {
			fold_value_guarded_branch(
				module, d.call,
				d.guard_key ? d.key : std::vector<uint8_t>{},
				d.value);
		} else if (d.guard_key) {
			fold_guarded_branch(module, d.call, d.key, d.value);
		} else {
			// Unconditional: replace the result with a stack copy of
			// the value and delete the lookup. O3's SROA forwards the
			// stored bytes into the value loads and a non-null stack
			// address satisfies any null check.
			llvm::IRBuilder<> b(d.call);
			auto *ptr = materialize_value_ptr(b, d.value,
							  d.call->getType());
			d.call->replaceAllUsesWith(ptr);
			d.call->eraseFromParent();
		}
		records.push_back({
			d.map_id, d.key, d.value,
			std::string(map_inline_stability_name(args.stability)) });
	}
	return records;
}

std::vector<uint8_t> run_map_inline_roundtrip(const std::vector<uint8_t> &input,
					      const Cli &cli,
					      std::vector<InlineRecord> &records)
{
	const auto args = parse_map_inline_args(cli.pass_args);
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		auto machine = create_bpf_target_machine(
			llvm::CodeGenOptLevel::Aggressive);
#if LLVM_VERSION_MAJOR >= 19
		module.setTargetTriple(llvm::Triple("bpfel"));
#else
		module.setTargetTriple("bpfel");
#endif
		module.setDataLayout(machine->createDataLayout());
		// Promote per-register allocas to SSA first so a lookup result
		// flows directly to its uses (else it is stored to its alloca).
		promote_register_allocas(module, *machine);
		if (std::getenv("BPFOPT_DUMP_IR")) {
			module.print(llvm::errs(), nullptr);
		}
		records = fold_pseudo_map_value_loads_ir(module, args);
		auto direct_records = direct_array_lookups_ir(module, args);
		records.insert(records.end(),
			       std::make_move_iterator(direct_records.begin()),
			       std::make_move_iterator(direct_records.end()));
		auto lookup_records = fold_map_lookups_ir(module, args);
		records.insert(records.end(),
			       std::make_move_iterator(lookup_records.begin()),
			       std::make_move_iterator(lookup_records.end()));
		if (records.empty()) {
			return input;
		}
		if (std::getenv("BPFOPT_DUMP_IR")) {
			module.print(llvm::errs(), nullptr);
		}
		return extract_relocated_text(emit_bpf_object(module), input,
					      nullptr);
	});
}

uint32_t module_fd_array_base(size_t map_count)
{
	if (map_count > std::numeric_limits<uint32_t>::max()) {
		throw std::runtime_error("map count exceeds u32");
	}
	return std::max<uint32_t>(static_cast<uint32_t>(map_count), 1);
}
