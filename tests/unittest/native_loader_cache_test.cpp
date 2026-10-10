#include "../../kprog/libnativeloader/src/native_loader_cache.hpp"

#include <cassert>
#include <cstdio>

int main()
{
    const std::filesystem::path cache_dir = "/tmp/native_kernel_link_cache";
    const auto first = native_link_temporary_base(cache_dir, "abc", 42, 1001);
    const auto same_thread = native_link_temporary_base(cache_dir, "abc", 42, 1001);
    const auto other_thread = native_link_temporary_base(cache_dir, "abc", 42, 1002);

    assert(first == cache_dir / "abc.tmp.42.1001");
    assert(same_thread == first);
    assert(other_thread != first);
    std::puts("native loader cache temp names: PASS");
    return 0;
}
