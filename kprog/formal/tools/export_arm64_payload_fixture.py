#!/usr/bin/env python3
"""Exercise the real ARM producer on the assembled sparse-layout fixture."""
from pathlib import Path
import argparse
import json
import os
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "kprog/arm64/micro-prog"))
import generate_micro_sim_proofs as producer

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--object-dir", type=Path, required=True)
parser.add_argument("--output", type=Path, required=True)
args = parser.parse_args()
bench = producer.Bench("arm64_payload_profile", "arm64_payload_profile", "raw")
functions, rodata = producer.parse_native_linked_program(bench, args.object_dir.resolve())
instructions = [i for body in functions.values() for i in body]
lo, hi, payload = producer.collect_layout(
    instructions, producer.indirect_targets(instructions), producer)
source = producer.render_program(
    bench.name, bench.symbol, functions, bench.kind, rodata16=rodata,
    program_section="socket")
# The renderer normally writes beside its own micro programs. This fixture has
# its one output in formal/build, so relocate only the header include.
header = os.path.relpath(ROOT / "kprog/arm64/arm64_sim_local_bpf.h", args.output.resolve().parent)
args.output.write_text(source.replace('#include "../arm64_sim_local_bpf.h"',
                                      '#include "' + header + '"'))
print(json.dumps({"stack_min": lo, "stack_max": hi,
                  "payload_offsets": sorted(payload) if payload is not None else None}))
