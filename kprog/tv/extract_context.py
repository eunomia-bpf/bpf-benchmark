"""Extract the kernel-produced context expansions of the clang field fixtures.

No instruction semantics lives here; Lean decodes and executes the exact bytes.
The unchanged return-zero suffix identifies each physical conversion extent.
"""
from pathlib import Path
import argparse
import json
import struct

root = Path(__file__).resolve().parent
parser = argparse.ArgumentParser()
parser.add_argument("--input-dir", type=Path, default=root / "build/context-access")
parser.add_argument("--output", type=Path, default=root / "build/KernelContexts.lean")
args = parser.parse_args()
source = args.input_dir
fields = ["data", "data_end", "data_meta", "ingress_ifindex", "rx_queue_index", "egress_ifindex"]
lines = ["import BPFPlatform", "namespace KProgTV.KernelContexts", "open KProgTV BPFPlatform"]


def array(data):
    return "#[" + ",".join(hex(byte) for byte in data) + "]"


for index, name in enumerate(fields):
    context = json.loads((source / f"tv_ctx_{name}.context.json").read_text())
    if (context["version"] != 1 or context["program_type"] != 6 or context["prog_flags"] != 0 or
            context["expected_attach_type"] != (33 if name == "egress_ifindex" else 37) or
            not context["source_prog_id"] or context["attach_btf_id"]):
        raise ValueError(f"{name}: wrong bound kernel context")
    raw = (source / f"tv_ctx_{name}.raw.bin").read_bytes()
    translated = (source / f"tv_ctx_{name}.xlated.bin").read_bytes()
    expected = struct.pack("<BBhi", 0x61, 0x11, index * 4, 0) + bytes.fromhex(
        "b7000000000000009500000000000000")
    if raw != expected or not translated.endswith(raw[8:]):
        raise ValueError(f"{name}: clang/kernel instruction correspondence changed")
    physical = translated[:-16]
    if not physical or len(physical) % 8:
        raise ValueError(f"{name}: invalid physical expansion extent")
    for position in range(0, len(physical), 8):
        code, registers, offset, immediate = struct.unpack("<BBhi", physical[position:position+8])
        if code not in (0x61, 0x79) or registers != 0x11 or immediate:
            raise ValueError(f"{name}: conversion is not the captured linear load fixture")
    count = len(physical) // 8
    lines += [f"def raw_{name} : Array KProgTV.Byte := {array(raw)}",
              f"def physical_{name} : Array KProgTV.Byte := {array(physical)}",
              f"def expansion_{name} : Expansion :=",
              f"  ⟨⟨0x61, 1, 1, {index * 4}, 0⟩, physical_{name}, fun _ => {list(range(count))}⟩"]
    print(f"{name}: exact clang load -> {count} captured physical BPF loads")
lines += ["end KProgTV.KernelContexts", ""]
args.output.write_text("\n".join(lines))
