/* Catch selecting a continuation/wrong LDDW kind, malformed source index,
 * or two different specializations of the same native source-map symbol.
 */
#include "../libnativeloader/src/native_loader_manifest.hpp"
#include <cassert>
#include <cstdio>

template<class Fn> static void rejects(Fn call, const char *message)
{
    try { call(); }
    catch (const std::runtime_error &error) {
        assert(std::string(error.what()).find(message) != std::string::npos);
        return;
    }
    throw std::runtime_error("invalid source map binding accepted");
}

int main()
{
    const auto bindings = parse_source_map_bindings(R"({"source_map_bindings":[
        {"native_symbol":"map_object","source_insn":0},
        {"native_symbol":"map_value","source_insn":2}]})");
    assert(bindings.size() == 2 && bindings[1].source_insn == 2);
    std::vector<bpf_insn> source{
        {.code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .src_reg = BPF_PSEUDO_MAP_FD, .off = 0, .imm = 7}, {},
        {.code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 2, .src_reg = BPF_PSEUDO_MAP_VALUE, .off = 0, .imm = 8},
        {.code = 0, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 3},
    };
    auto object = source_map_reference(source, 0), value = source_map_reference(source, 2);
    assert(object.fd == 7 && !object.value && object.offset == 0);
    assert(value.fd == 8 && value.value && value.offset == 3);
    for (auto site : {1u, 3u, 4u, 0xffffffffu})
        rejects([&] { source_map_reference(source, site); }, "instruction site");
    for (unsigned field = 0; field < 7; field++) {
        auto bad = source;
        if (field == 0) bad[0].code = BPF_ALU64 | BPF_MOV | BPF_K;
        if (field == 1) bad[0].src_reg = 0;
        if (field == 2) bad[0].imm = -1;
        if (field == 3) bad[1].code = BPF_JMP | BPF_EXIT;
        if (field == 4) bad[1].imm = 1;
        if (field == 5) bad[0].off = 1;
        if (field == 6) bad[0].dst_reg = BPF_REG_10;
        rejects([&] { source_map_reference(bad, 0); }, "invalid LDDW");
    }
    for (const char *record : {R"({"native_symbol":"a"})",
         R"({"native_symbol":"a","source_insn":0,"source_insn":2})",
         R"({"native_symbol":"a","source_insn":0,"extra":0})",
         R"({"native_symbol":"a","source_insn":1.0})",
         R"({"native_symbol":"a","source_insn":4294967296})"})
        rejects([&] { parse_source_map_bindings("{\"source_map_bindings\":[" + std::string(record) + "]}"); }, "");
    rejects([&] { parse_source_map_bindings(R"({"source_map_bindings":[
        {"native_symbol":"a","source_insn":0},{"native_symbol":"a","source_insn":2}]})"); }, "duplicate");
    auto proof_binding = parse_proof_source_maps(R"({"version":1,"objects":[
        {"native_symbol":"map_value","source_insn":2,"proof_symbol":"external_base"}]})");
    assert(proof_binding.size() == 1 && proof_binding[0].source == bindings[1]);
    for (const char *text : {R"({"version":2,"objects":[]})",
        R"({"version":1,"objects":[{"native_symbol":"a","source_insn":0}]})",
        R"({"version":1,"objects":[{"native_symbol":"a","source_insn":0,"proof_symbol":"x"},
            {"native_symbol":"b","source_insn":2,"proof_symbol":"x"}]})"})
        rejects([&] { parse_proof_source_maps(text); }, "");
    auto fd_template = source;
    fd_template[0].imm = 0;
    fd_template[2].imm = 0;
    std::string encoded;
    static constexpr char hex[] = "0123456789abcdef";
    const auto *bytes = reinterpret_cast<const unsigned char *>(fd_template.data());
    for (size_t i = 0; i < fd_template.size() * sizeof(bpf_insn); i++) {
        encoded.push_back(hex[bytes[i] >> 4]); encoded.push_back(hex[bytes[i] & 15]);
    }
    assert(manifest_bound_source_matches(encoded, source, {0,2}, bindings));
    // A heterogeneous manifest must skip this template for other startup probes.
    std::vector<bpf_insn> other_probe{{.code = BPF_ALU64 | BPF_MOV | BPF_K,
        .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0},
        {.code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0}};
    assert(!manifest_bound_source_matches(encoded, other_probe, {0,2}, bindings));
    auto changed = source;
    changed[3].imm = 16; // Only the FD word can vary, never the value offset.
    assert(!manifest_bound_source_matches(encoded, changed, {0,2}, bindings));
    changed = source; changed[0].src_reg = BPF_PSEUDO_MAP_VALUE;
    assert(!manifest_bound_source_matches(encoded, changed, {0,2}, bindings));
    rejects([&] { manifest_bound_source_matches(encoded, source, {0,2}, {bindings[0]}); }, "lacks an explicit");
    rejects([&] { manifest_bound_source_matches(encoded, source, {1}, bindings); }, "lacks an explicit");
    for (const char *sites : {"[0,0]", "[1.0]", "[4294967296]", "[-1]", "[0,]"})
        rejects([&] { parse_source_map_fd_sites("{\"source_map_fd_sites\":" + std::string(sites) + "}"); }, "");
    // Native-symbol base and compiled REL/RELA addends are separate quantities.
    assert(trusted_map_relocation_offset(std::nullopt,0,0,false,0)==0);
    assert(trusted_map_relocation_offset(0,0,0,false,40)==0);
    assert(trusted_map_relocation_offset(8,0,0,false,40)==8);
    assert(trusted_map_relocation_offset(8,8,0,false,40)==16);
    assert(trusted_map_relocation_offset(8,static_cast<uint64_t>(-4LL),0,false,40)==4);
    assert(trusted_map_relocation_offset(8,123,8,true,40)==16);
    assert(trusted_map_relocation_offset(UINT32_MAX-1,0,0,false,UINT32_MAX)==UINT32_MAX-1);
    rejects([] { trusted_map_relocation_offset(std::nullopt,1,0,false,40); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(8,32,0,false,40); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(8,UINT32_MAX-3ULL,0,false,UINT32_MAX); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(1,INT64_MAX,0,false,40); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(1,1ULL<<63,0,false,40); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(UINT32_MAX,0,0,false,UINT32_MAX); }, "trusted proof map addend");
    rejects([] { trusted_map_relocation_offset(0,0,-1,true,40); }, "trusted proof map addend");
    std::puts("trusted extern base/relative/full-width/REL/RELA/boundary controls: PASS");
    std::puts("source map exact site/kind/continuation/FD/offset/metadata rejection: PASS");
}
