// Exercise the production original-symbol/current-FD binding and libbpf template.
#include "../../libnativeloader/src/native_loader.cpp"
#include <iostream>
int main(int argc, char **argv) try {
    if (argc != 3) return 2;
    using Object = std::unique_ptr<bpf_object, decltype(&bpf_object__close)>;
    Object fixture(bpf_object__open_file(argv[1],nullptr),bpf_object__close);
    if (!fixture) return 1;
    auto *program=bpf_object__find_program_by_name(fixture.get(),"entry");
    if (!program) return 1;
    std::vector<bpf_insn> code(bpf_program__insns(program),
                             bpf_program__insns(program)+bpf_program__insn_cnt(program));
    for (auto &i:code) if (i.code==(BPF_LD|BPF_DW|BPF_IMM)) {
        i.src_reg=BPF_PSEUDO_MAP_FD; i.imm=101;
    }
    CompanionLoad load;
    MapMeta actual{};
    actual.name="renamed_outer"; actual.fd=101; actual.kernel_id=501;
    actual.type=BPF_MAP_TYPE_HASH_OF_MAPS; actual.kernel_addr=0x12340000;
    load.maps={actual}; load.source_maps_by_fd={{101,actual}};
    bind_original_source_maps(argv[1],"entry",code,load);
    if (load.map_addr_ids.at("outer")!=501 || load.maps[0].inner_type!=BPF_MAP_TYPE_ARRAY ||
        load.maps[0].inner_value_size!=4) return 1;
    SourceBpfMaps original(argv[2]);
    const auto bytes=original.map_definitions(argv[2]);
    Object otel(bpf_object__open_mem(bytes.data(),bytes.size(),nullptr),bpf_object__close);
    if (!otel) return 1;
    unsigned count=0;
    bpf_map *map;
    bpf_object__for_each_map(map,otel.get()) {
        if (!starts_with(bpf_map__name(map),"exe_id_to_")) continue;
        auto *inner=bpf_map__inner_map(map);
        if (!inner || bpf_map__type(inner)!=BPF_MAP_TYPE_ARRAY || bpf_map__value_size(inner)!=4) return 1;
        ++count;
    }
    if (count!=16) return 1;
    std::cout<<"original FD binding and "<<count<<" OTel inner ARRAY/value-size templates pass\n";
    return 0;
} catch(const std::exception &e) { std::cerr<<e.what()<<'\n'; return 1; }
