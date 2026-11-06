#include "../libnativeloader/src/native_rodata_binding.hpp"
#include <cassert>
#include <cstdio>

template<class Fn> static void rejects(Fn call, const char *message)
{
    try { call(); }
    catch (const std::runtime_error &error) {
        assert(std::string(error.what()).find(message) != std::string::npos);
        return;
    }
    throw std::runtime_error("invalid readonly metadata accepted");
}

int main()
{
    const std::string first = R"({"native_symbol":"a","offset":0,"size":16})";
    const std::string second = R"({"native_symbol":"b","offset":16,"size":16})";
    const auto layout = parse_native_readonly_layout("{\"version\":1,\"objects\":[" + first + "," + second + "]}", 32);
    const auto proof = parse_proof_readonly_bindings(R"({"version":1,"objects":[
        {"proof_section":".rodata.native.0","proof_symbol":"p0","native_symbol":"a","size":16},
        {"proof_section":".rodata.native.1","proof_symbol":"p1","native_symbol":"b","size":16}]})");
    assert(resolve_readonly_extent(proof[0], layout, 16).offset == 0);
    assert(resolve_readonly_extent(proof[1], layout, 16).offset == 16);
    rejects([&] { parse_native_readonly_layout("{\"version\":1,\"objects\":[" + first + "," + first + "]}", 32); }, "duplicate");
    for (const auto &record : {
        R"({"native_symbol":"a","offset":18446744073709551615,"size":16})",
        R"({"native_symbol":"a","offset":0,"size":33})",
        R"({"native_symbol":"a","offset":0,"size":0})"})
        rejects([&] { parse_native_readonly_layout("{\"version\":1,\"objects\":[" + std::string(record) + "]}", 32); }, "extent");
    for (const auto &text : {
        R"({"version":2,"objects":[]})", R"({"version":1.0,"objects":[]})",
        R"({"version":1,"version":1,"objects":[]})", R"({"version":1,"objects":[],"extra":0})",
        R"({"version":1,"objects":[],})", R"({"version":1,"objects":[{},]})"})
        rejects([&] { parse_native_readonly_layout(text, 32); }, "readonly");
    rejects([&] { resolve_readonly_extent(proof[0], layout, 8); }, "map size");
    auto wrong = proof[0]; wrong.native_symbol = "absent";
    rejects([&] { resolve_readonly_extent(wrong, layout, 16); }, "absent");
    wrong = proof[0]; wrong.size = 8;
    rejects([&] { resolve_readonly_extent(wrong, layout, 8); }, "sizes differ");
    auto duplicate = std::string(R"({"proof_section":".rodata.native.0","proof_symbol":"p0","native_symbol":"a","size":16})");
    rejects([&] { parse_proof_readonly_bindings("{\"version\":1,\"objects\":[" + duplicate + "," + duplicate + "]}"); }, "duplicate");
    std::puts("readonly symbol identity/size/overflow/version/duplicate/unknown/JSON rejection: PASS");
}
