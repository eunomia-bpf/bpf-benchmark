"""Observe loader mappings across an actual dlopen/dlclose pair."""
import _ctypes
import ctypes
import json
from pathlib import Path
import sys

path = Path(sys.argv[1]).resolve(strict=True)


def mappings():
    return [line for line in Path('/proc/self/maps').read_text().splitlines()
            if line.endswith(str(path))]


before = mappings()
library = ctypes.CDLL(str(path))
loaded = mappings()
_ctypes.dlclose(library._handle)
library._handle = 0
after = mappings()
print(json.dumps(dict(path=str(path), before=before, loaded=loaded, after_close=after), indent=2))
