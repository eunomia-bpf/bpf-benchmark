#!/usr/bin/env python3
"""Prepare the core-owner scalar-fact patch, leaving source untouched."""
import difflib
from pathlib import Path
import subprocess
import sys

out=Path(sys.argv[1]);name='kprog/libnativeloader/src/native_loader.cpp'
before=Path(name).read_text()
anchor='''    load.map_addr_ids["LINUX_KERNEL_VERSION"] = map->kernel_id;
}'''
replacement='''    load.map_addr_ids["LINUX_KERNEL_VERSION"] = map->kernel_id;
    if (!map->immutable_value.empty()) {
        constexpr char hex[] = "0123456789abcdef";
        std::string value;
        for (size_t i = 0; i < sizeof(uint32_t); ++i) {
            const auto byte = map->immutable_value[i];
            value += hex[byte >> 4]; value += hex[byte & 15];
        }
        load.immutable_globals["LINUX_KERNEL_VERSION"] = std::move(value);
    }
}'''
after=before.replace(anchor,replacement,1)
patch=out/'kconfig-scalar.patch'
patch.write_text(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),
    fromfile='a/'+name,tofile='b/'+name)))
subprocess.run(['git','apply','--check',str(patch)],check=True)
