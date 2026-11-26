// Catch a loader choosing the generic target despite an available key-size entry,
// or changing the hash-family postprocessing when that entry is absent/zero.
#ifdef TRUSTED
#include "../../libnativeloader/src/native_loader_trusted.cpp"
namespace native_loader::internal {
[[noreturn]] void fail(const std::string &message) { throw std::runtime_error(message); }
}
namespace loader = native_loader::trusted;
#else
#include "../../libnativeloader/src/native_loader.cpp"
namespace loader = native_loader::internal;
#endif
#include <cassert>
#include <iostream>
int main()
{
    using namespace loader;
    auto &symbols = const_cast<std::unordered_map<std::string, uint64_t> &>(kallsyms_table());
    symbols.clear();
    symbols["__htab_map_lookup_elem"] = 0x1000;
    unsigned cases = 0;
    for (int kind : {BPF_MAP_TYPE_HASH, BPF_MAP_TYPE_LRU_HASH,
                     BPF_MAP_TYPE_PERCPU_HASH, BPF_MAP_TYPE_HASH_OF_MAPS}) {
        for (uint64_t specialized : {0UL, 0x2000UL}) {
            symbols["kprog_htab_elem_k14"] = specialized;
            CompanionLoad::LookupSite site{};
            assert(configure_lookup_site_for_shape(site, {kind, 14, 32, 64},
                                                  {304, 304}, {48, 35}, 0x3000));
            assert(site.target_addr == (specialized ? specialized : 0x1000));
            assert(site.key_offset == 64);
            if (kind == BPF_MAP_TYPE_LRU_HASH) assert(site.value_offset == 35);
            if (kind == BPF_MAP_TYPE_PERCPU_HASH) assert(site.percpu_base_addr == 0x3000);
            ++cases;
        }
        symbols.erase("kprog_htab_elem_k14");
        assert(htab_lookup_elem_kernel_addr(14) == 0x1000);
        ++cases;
    }
    symbols.clear();
    bool failed = false;
    try { htab_lookup_elem_kernel_addr(14); }
    catch (const std::runtime_error &) { failed = true; }
    assert(failed);
    std::cout << cases << " specialized/zero/absent target cases; missing generic fails\n";
}
