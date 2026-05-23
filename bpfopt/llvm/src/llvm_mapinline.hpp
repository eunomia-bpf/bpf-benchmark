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
	module.setTargetTriple(llvm::Triple("bpfel"));
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

std::vector<uint8_t> run_llvm_roundtrip(const std::vector<uint8_t> &input)
{
	auto module = generate_llvm_module(input);
	return module.withModuleDo([&](llvm::Module &module) {
		return extract_relocated_text(emit_bpf_object(module), input);
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

// Optional CLI entry hint: for map `map_name`, the hex bytes identify the
// lookup key whose snapshotted value may be used. There is one hint kind.
struct InlineHint {
	std::string map_name;
	std::vector<uint8_t> key;
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
// Soundness: the snapshot constant is used ONLY when the runtime key equals K;
// every other key and a miss take the slow path with the real lookup result
// (so its live value and any write-through pointer are preserved). When K is a
// provable constant O3 folds the branch away and DCEs the call.
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
//      A proven-constant key is sound with no guard, and (no result phi) the
//      value const-propagates like a uniform fold. This is "if the key is
//      constant, skip the call" — done by us, since O3 can't see the constant
//      through llvmbpf's ptrtoint frame arithmetic.
//   2. uniform map -> UNCONDITIONAL fold (value is key-independent).
//   3. CLI entry hint on a runtime key -> guarded branch: fast path skips
//      the lookup, slow path keeps the real lookup as a sound fallback.
struct FoldDecision {
	llvm::CallInst *call;
	std::vector<uint8_t> key;
	std::vector<uint8_t> value;
	bool guarded;
	uint32_t map_id;
};

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
	const auto mutable_maps = ir_mutable_maps(module, args.map_ids);
	std::map<std::string, std::vector<uint8_t>> hint_key;
	for (const auto &h : args.hints) {
		hint_key[h.map_name] = h.key;
	}
	const auto &dl = module.getDataLayout();
	llvm::DominatorTree dt(*main_fn);

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
			std::optional<std::vector<uint8_t>> value;
			bool guarded = false;
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
					guarded = true;
				} else if (snapshot.truly_uniform.count(*map_id)) {
					value = snapshot.uniform_values.at(*map_id);
				}
			}
			if (!value || value->size() != mi->second.value_size ||
			    (guarded && key.size() != mi->second.key_size)) {
				continue;
			}
			decisions.push_back(
				{ call, key, *value, guarded, *map_id });
		}
	}

	// Phase 2 — apply. Guarded folds split blocks (invalidating the dominator
	// tree), but phase 1 made all dominance queries already.
	for (auto &d : decisions) {
		if (d.guarded) {
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
		records.push_back({ d.map_id, d.key, d.value });
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
		module.setTargetTriple(llvm::Triple("bpfel"));
		module.setDataLayout(machine->createDataLayout());
		// Promote per-register allocas to SSA first so a lookup result
		// flows directly to its uses (else it is stored to its alloca).
		promote_register_allocas(module, *machine);
		if (std::getenv("BPFOPT_DUMP_IR")) {
			module.print(llvm::errs(), nullptr);
		}
		records = fold_map_lookups_ir(module, args);
		return extract_relocated_text(emit_bpf_object(module), input);
	});
}

uint32_t module_fd_array_base(size_t map_count)
{
	if (map_count > std::numeric_limits<uint32_t>::max()) {
		throw std::runtime_error("map count exceeds u32");
	}
	return std::max<uint32_t>(static_cast<uint32_t>(map_count), 1);
}
