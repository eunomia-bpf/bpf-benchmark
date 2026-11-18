#include "../../libnativeloader/src/native_loader.cpp"
#include <cassert>
#include <iostream>

int main()
{
    CompanionLoad::LookupSite site{};
    site.kind = CompanionLoad::LookupSite::Kind::Call;
    site.target_addr = 0x5678;
    site.map_name = "actual_map";
    MapMeta meta{};
    unsigned cases = 0;
    for (int type : {BPF_MAP_TYPE_LPM_TRIE, BPF_MAP_TYPE_ARRAY, BPF_MAP_TYPE_HASH}) {
        for (uint32_t key : {4U, 8U, 12U, 16U, 20U, 24U}) {
            meta.type = type;
            meta.key_size = key;
            auto bound = make_link_lookup_site(site, &meta);
            assert(bound.kind == (type == BPF_MAP_TYPE_LPM_TRIE && key == 16 ? "lpm12" : "call"));
            assert(bound.target_addr == site.target_addr && bound.map_name == site.map_name);
            ++cases;
        }
    }
    assert(make_link_lookup_site(site).kind == "call");
    std::cout << cases << " loaded type/key shapes and legacy site retain target and name\n";
}
