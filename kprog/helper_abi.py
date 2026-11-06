"""Linux helper declarations shared by native-proof tooling for both ISAs."""
from dataclasses import dataclass
from functools import cache
from pathlib import Path
import re

# Zero-based destination/size arguments for helpers that overwrite the entire
# requested region on both success and failure. This is stronger than
# ARG_PTR_TO_UNINIT_MEM: probe_read_*_str may leave the suffix untouched.
# Kernel bodies: kernel/trace/bpf_trace.c, kernel/bpf/{helpers,stackmap}.c,
# net/core/filter.c. Size parameters in these prototypes are u32.
HELPER_FULL_WRITES = {
    'bpf_probe_read': (0, 1),
    'bpf_probe_read_user': (0, 1),
    'bpf_probe_read_kernel': (0, 1),
    'bpf_get_current_comm': (0, 1),
    'bpf_copy_from_user': (0, 1),
    'bpf_get_stack': (1, 2),
    'bpf_skb_load_bytes': (2, 3),
    'bpf_skb_load_bytes_relative': (2, 3),
}
# Probe/copy helpers may copy unspecified saved ABI bytes from native private
# stack memory. Writing those bytes does not make their values defined.
HELPER_COPY_SOURCES = {
    'bpf_probe_read': 2,
    'bpf_probe_read_user': 2,
    'bpf_probe_read_kernel': 2,
    'bpf_copy_from_user': 2,
}


@dataclass(frozen=True)
class Helper:
    result: str
    arguments: str
    number: int


@cache
def helper_prototypes() -> dict[str, Helper]:
    source = (Path(__file__).resolve().parents[1] /
              "vendor/libbpf/src/bpf_helper_defs.h").read_text()
    return {name: Helper(result.strip(), arguments.strip(), int(number))
            for result, name, arguments, number in re.findall(
                r"^static (.*?)\(\* const (bpf_\w+)\)\((.*?)\) = \(void \*\) (\d+);",
                source, re.M)}


@cache
def helper_idents() -> dict[int, str]:
    return {prototype.number: name for name, prototype in helper_prototypes().items()}


def is_helper_symbol(symbol: str | None) -> bool:
    return symbol in helper_prototypes()
