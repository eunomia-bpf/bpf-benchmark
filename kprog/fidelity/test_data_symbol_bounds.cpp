/* A native string-pool symbol the loaded app's map does not cover is not fatal.
 * Tracee is the case: .rodata.str1.1 is 261 bytes where the app's map is 246,
 * the extra bytes being "vdso" at 248 and "unknown" at 253. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2) throw std::runtime_error("expected native object path");
    CompanionLoad load{};
    load.maps.push_back(MapMeta{
        .name = ".rodata.str1.1",
        .fd = 1,
        .kernel_id = 1,
        .type = BPF_MAP_TYPE_ARRAY,
        .key_size = 4,
        .value_size = 10,
        .max_entries = 1,
        .kernel_addr = 0x1000,
        .value_addr = 0x2000,
    });
    // in_range covers bytes 0..7; beyond starts at 8 with 8 bytes, past the
    // map's 10; wrapped's st_size would wrap a bare off+size comparison.
    add_native_data_symbol_addrs(argv[1], load);
    if (load.map_addrs.size() != 1 || !load.map_addrs.count("in_range") ||
        load.map_addrs.at("in_range") != 0x2000) {
        std::cerr << "covered symbol binding changed: " << load.map_addrs.size() << " symbols\n";
        return 1;
    }
    if (load.map_addrs.count("beyond") || load.map_addrs.count("wrapped")) {
        std::cerr << "symbol outside the map value was bound\n";
        return 1;
    }
    std::cout << "uncovered native data symbols skipped, covered one bound at its section offset\n";
}