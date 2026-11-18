#include "../../libnativeloader/src/native_loader.cpp"
#include <iostream>

int main()
{
    unsigned failures=0;
    for (bool frozen : {false,true}) {
        CompanionLoad load{};
        MapMeta map{};
        map.name="kconfig";map.type=BPF_MAP_TYPE_ARRAY;
        map.key_size=4;map.value_size=4;map.max_entries=1;
        map.kernel_id=3;map.value_addr=0x5678;
        if (frozen) map.immutable_value={1,2,3,4};
        load.maps.push_back(map);
        add_known_kconfig_symbol_addrs(load);
        const auto value=load.immutable_globals.find("LINUX_KERNEL_VERSION");
        const bool valid=load.map_addrs.at("LINUX_KERNEL_VERSION")==0x5678 &&
            load.map_addr_ids.at("LINUX_KERNEL_VERSION")==3 &&
            (frozen ? value!=load.immutable_globals.end() && value->second=="01020304"
                    : value==load.immutable_globals.end());
        std::cout << "frozen=" << frozen << " scalar_fact="
                  << (value==load.immutable_globals.end()?"absent":value->second)
                  << " contract=" << valid << '\n';
        failures+=!valid;
    }
    return failures ? 1 : 0;
}
