// Catch a loader choosing the generic target despite an available key-size entry,
// changing hash-family postprocessing, or using a specialized entry above MAX_BPF_STACK.
#ifdef TRUSTED
#include "../../libnativeloader/src/native_loader_trusted.cpp"
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
        for (unsigned size : {1U, 14U, 511U, 512U, 513U, 1024U}) {
            std::string symbol = "kprog_htab_elem_k" + std::to_string(size);
            for (uint64_t specialized : {0UL, 0x2000UL}) {
                symbols[symbol] = specialized;
                CompanionLoad::LookupSite site{};
                assert(configure_lookup_site_for_shape(site, {kind, size, 32, 64},
                                                      {304, 304}, {48, 35}, 0x3000));
                assert(site.target_addr == (specialized && size <= 512 ? specialized : 0x1000));
                assert(site.key_offset == 48 + ((size + 7) & ~7U));
                if (kind == BPF_MAP_TYPE_LRU_HASH) assert(site.value_offset == 35);
                if (kind == BPF_MAP_TYPE_PERCPU_HASH) assert(site.percpu_base_addr == 0x3000);
                ++cases;
            }
            symbols.erase(symbol);
            assert(htab_lookup_elem_kernel_addr(size) == 0x1000);
            ++cases;
        }
    }
    symbols.clear();
    symbols["fixture_nonempty"] = 1; // Keep the cache initialized while omitting the target.
    bool failed = false;
    try { htab_lookup_elem_kernel_addr(14); }
    catch (const std::runtime_error &) { failed = true; }
    assert(failed);
    std::cout << cases << " specialized/zero/absent target cases; missing generic fails\n";
}
