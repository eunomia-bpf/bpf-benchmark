"""Linux helper declarations shared by native-proof tooling for both ISAs."""
from dataclasses import dataclass
from functools import cache
from pathlib import Path
import re


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
