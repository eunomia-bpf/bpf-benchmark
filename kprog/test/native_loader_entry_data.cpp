// Regression: another entry's absent BTF global must not prevent this entry's
// load; a reachable global missing from that same DATASEC must still fail.
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>
#include <sys/mman.h>

static void require(bool condition, const std::string &message)
{
    if (!condition) fail(message);
}

static void mutable_data(const std::filesystem::path &object,
                         const std::filesystem::path &linker,
                         const std::filesystem::path &output)
{
    struct { uint32_t before=0x12345678; uint8_t flag=0; uint8_t pad[3]={1,2,3};
             uint32_t bias=7, after=0x87654321; } live;
    NativeLinkArgs args; args.linker=linker;
    args.maps={{"mutable_flag",reinterpret_cast<uint64_t>(&live.flag)},
               {"mutable_bias",reinterpret_cast<uint64_t>(&live.bias)}};
    std::unordered_map<std::string,uint64_t> addresses;
    for (const auto &map : args.maps) addresses[map.name]=map.addr;
    for (const std::string symbol : {"mutable_entry","mutable_immediate"}) {
        const auto proof=cached_native_entry_proof(linker,object,symbol);
        const auto names=native_entry_symbol_names(proof);
        require(names.contains("mutable_flag"),"mutable PC32 lost its original variable identity");
        const auto linked=invoke_native_link(object,symbol,args,output/symbol,{},proof);
        auto bytes=read_binary_file(linked.blob);
        patch_map_literals(bytes,read_map_patch_file(linked.map_patches),addresses);
        bytes.push_back(0xc3); // The inline image's exit lands just past its bytes.
        const size_t size=(bytes.size()+4095)&~size_t(4095);
        void *code=mmap(nullptr,size,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
        require(code!=MAP_FAILED,"allocate mutable-data execution image");
        std::memcpy(code,bytes.data(),bytes.size());
        require(!mprotect(code,size,PROT_READ|PROT_EXEC),"protect actual native text RX");
        auto run=reinterpret_cast<unsigned(*)(void*)>(code);
        if (symbol=="mutable_entry") {
            require(run(nullptr)==8 && run(nullptr)==9 && live.flag==2,"mutable state did not persist");
            live.bias=100;
            require(run(nullptr)==103 && live.flag==3,"native data copied instead of using live binding");
        } else require(run(nullptr)==9 && live.flag==9,"trailing immediate PC32 bias changed its target");
        require(live.before==0x12345678 && live.after==0x87654321 &&
                live.pad[0]==1 && live.pad[1]==2 && live.pad[2]==3,"mutable write damaged adjacent bytes");
        require(!munmap(code,size),"release native text mapping");
    }
    std::cout << "RX native text, live writable DATASEC aliases, persistent state, runtime updates and immediate-store bias: PASS" << std::endl;
}

static int kernel_mutable(const char *native,const char *linker,const char *directory,const char *original)
{
    std::unique_ptr<bpf_object,decltype(&bpf_object__close)> object(bpf_object__open_file(original,nullptr),bpf_object__close);
    require(object && !libbpf_get_error(object.get()),"open mutable source BPF");
    require(!bpf_object__load(object.get()),"load mutable source BPF");
    auto *flags=bpf_object__find_map_by_name(object.get(),".bss");
    auto *data=bpf_object__find_map_by_name(object.get(),".data");
    require(flags && data,"source mutable DATASEC maps absent");
    const uint32_t key=0;
    std::vector<uint8_t> state(bpf_map__value_size(flags));
    std::vector<uint8_t> values(bpf_map__value_size(data));
    const auto output=std::filesystem::path(directory);
    std::ofstream results(output/"mutable-execution.jsonl");
    for (const std::string name : {"mutable_entry","mutable_immediate"}) {
        auto *program=bpf_object__find_program_by_name(object.get(),name.c_str());
        require(program,"source mutable program absent");
        const auto manifest=output/(name+".json");
        std::ofstream config(manifest);
        config << "{\"objects\":[{\"program\":\"" << name << "\",\"symbol\":\"" << name
               << "\",\"native_object\":\"" << native << "\",\"kernel_data_layout\":true}]}";
        config.close();
        native_loader::FdLoadOptions request;request.original_prog_fd=bpf_program__fd(program);
        request.native_link_path=linker;request.manifest_path=manifest;
        require(!setenv("BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF","1",1),"select registered service");
        auto loaded=native_loader::load_from_fd(request);
        require(loaded.replaced && loaded.prog_fd>=0,"install mutable native program");
        for (uint32_t bias : {7,100}) for (const auto &[route,fd] :
                std::vector<std::pair<const char*,int>>{{"stock",request.original_prog_fd},{"native",loaded.prog_fd}}) {
            std::fill(state.begin(),state.end(),0);state[0]=3;
            std::fill(values.begin(),values.end(),0);std::memcpy(values.data(),&bias,4);
            require(!bpf_map_update_elem(bpf_map__fd(flags),&key,state.data(),0) &&
                    !bpf_map_update_elem(bpf_map__fd(data),&key,values.data(),0),"configure live source globals");
            unsigned char packet[64]{};
            bpf_test_run_opts run{};run.sz=sizeof(run);run.data_in=packet;run.data_size_in=sizeof(packet);run.repeat=1;
            require(!bpf_prog_test_run_opts(fd,&run),"run actual mutable program");
            require(!bpf_map_lookup_elem(bpf_map__fd(flags),&key,state.data()),"read changed live source global");
            const unsigned flag=name=="mutable_entry"?4:9;
            const unsigned expected=name=="mutable_entry"?bias+flag:flag;
            results << "{\"program\":\"" << name << "\",\"route\":\"" << route
                << "\",\"bias\":" << bias << ",\"flag\":" << unsigned(state[0])
                << ",\"retval\":" << run.retval << "}" << std::endl;
            require(run.retval==expected && state[0]==flag,"native write/return differs from source live DATASEC");
        }
        native_loader::close_loaded_program(&loaded);
    }
    std::cout << "kernel mutable source/native live DATASEC: 8 executions PASS" << std::endl;
    return 0;
}

int main(int argc, char **argv)
try {
    require(argc == 6, "usage: entry-data host|kernel NATIVE_OBJECT NATIVE_LINK OUTPUT EXISTING_PROOF");
    if (std::string(argv[1])=="kernel-mutable") return kernel_mutable(argv[2],argv[3],argv[4],argv[5]);
    const bool kernel = std::string(argv[1]) == "kernel";
    require(kernel || std::string(argv[1]) == "host", "unknown mode");
    const std::filesystem::path output = argv[4];
    const auto entry = cached_native_entry_proof(argv[3], argv[2], "entry");
    const auto other = cached_native_entry_proof(argv[3], argv[2], "other_entry");
    const auto entry_names = native_entry_symbol_names(entry);
    const auto other_names = native_entry_symbol_names(other);
    require(entry_names.contains("live_value") && entry_names.contains("shared_read") &&
            !entry_names.contains("other_value"), "callee/global reachability lost entry identity");
    require(other_names.contains("other_value") && !other_names.contains("live_value"),
            "other entry inherited unrelated globals");
    const auto modified = std::filesystem::last_write_time(entry);
    require(cached_native_entry_proof(argv[3], argv[2], "entry") == entry &&
            std::filesystem::last_write_time(entry) == modified, "entry extraction cache rebuilt on a hit");
    std::filesystem::copy_file(entry, output / "entry.proof.o");
    std::filesystem::copy_file(other, output / "other-entry.proof.o");
    // Also exercise the ELF reader on a retained real application artifact.
    const auto actual_names = native_entry_symbol_names(argv[5]);
    std::ofstream names(output / "existing-proof-symbols.txt");
    for (const auto &name : std::set<std::string>(actual_names.begin(), actual_names.end())) names << name << '\n';
    names.close();
    require(static_cast<bool>(names), "write real entry symbol inventory");
    NativeLinkArgs args;
    args.linker = argv[3];
    args.maps.push_back({"live_value", 0}); // Existing address-neutral link template.
    const auto fresh = invoke_native_link(argv[2], "entry", args, output / "fresh", {}, {});
    const auto reused = invoke_native_link(argv[2], "entry", args, output / "reused", {}, entry);
    require(read_binary_file(fresh.proof) == read_binary_file(reused.proof) &&
            read_binary_file(fresh.blob) == read_binary_file(reused.blob) &&
            read_binary_file(fresh.relocs) == read_binary_file(reused.relocs) &&
            read_binary_file(fresh.map_patches) == read_binary_file(reused.map_patches) &&
            read_binary_file(fresh.abi) == read_binary_file(reused.abi),
            "reused entry extraction changed native code or its sidebands");
    mutable_data(argv[2],argv[3],output);
    if (!kernel) {
        std::cout << "entry/callee/global reachability, cache, real ELF inventory, identical fresh/reused native template: PASS\n";
        return 0;
    }

    std::unique_ptr<btf, decltype(&btf__free)> types(btf__new_empty(), btf__free);
    require(types != nullptr, "create fixture BTF");
    const int word = btf__add_int(types.get(), "unsigned", 4, 0);
    require(word > 0, "create BTF scalar");
    const int variable = btf__add_var(types.get(), "live_value", BTF_VAR_GLOBAL_ALLOCATED, word);
    require(variable > 0, "create live BTF variable");
    const int section = btf__add_datasec(types.get(), ".rodata.config", 8);
    require(section > 0 && !btf__add_datasec_var_info(types.get(), variable, 4, 4), "create live DATASEC");
    require(!btf__load_into_kernel(types.get()), "load fixture BTF");
    bpf_map_create_opts options{};
    options.sz = sizeof(options);
    options.btf_fd = btf__fd(types.get());
    options.btf_key_type_id = word;
    options.btf_value_type_id = section;
    ScopedFd map(bpf_map_create(BPF_MAP_TYPE_ARRAY, "f.rodata.config", 4, 8, 1, &options));
    require(map.get() >= 0, "create config map: " + std::string(std::strerror(errno)));
    const uint32_t key = 0;
    const uint32_t values[2] = {0x12345678, 91};
    require(!bpf_map_update_elem(map.get(), &key, values, 0), "write application config");
    CompanionLoad source;
    add_map_meta(source, load_map_meta_from_fd(map.get()));
    auto legacy = source;
    add_native_data_symbol_addrs(argv[2], legacy);
    require(legacy.native_data_symbols.contains("other_value"), "default data layout unexpectedly filtered globals");
    auto load = source;
    add_native_data_symbol_addrs(argv[2], load, true, &entry_names);
    require(load.native_data_symbols.contains("live_value") &&
            !load.native_data_symbols.contains("other_value"), "unused global became a capability");
    const auto &meta = source.maps.at(0);
    require(load.map_addrs.at("live_value") == meta.value_addr + 4 &&
            load.map_addr_ids.at("live_value") == meta.kernel_id, "lost live symbol BTF offset/map identity");
    for (const auto *selection : {static_cast<const std::unordered_set<std::string> *>(nullptr), &other_names}) {
        bool rejected = false;
        auto invalid = source;
        try { add_native_data_symbol_addrs(argv[2], invalid, true, selection); }
        catch (const std::runtime_error &error) {
            rejected = std::string(error.what()).find("lacks native symbol other_value") != std::string::npos;
        }
        require(rejected, "reachable missing global or whole-object failure disappeared");
    }
    uint32_t actual[2]{};
    require(!bpf_map_lookup_elem(map.get(), &key, actual) && std::equal(actual, actual + 2, values),
            "binding altered application config bytes");
    std::cout << "kernel selected-entry binding, actual BTF offset/map identity, needed-missing error, live bytes: PASS\n";
    return 0;
} catch (const std::exception &error) {
    std::cerr << error.what() << '\n';
    return 1;
}
