#!/usr/bin/env python3
"""Render an assembled native frame with the actual x86 producer."""
import argparse
import json
import os
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "kprog/x86/micro-prog"))
import generate_micro_sim_proofs as producer

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--name", required=True)
parser.add_argument("--kind", choices=("raw", "xdp", "tc", "cgroup_skb"), default="raw")
parser.add_argument("--object-dir", type=Path, required=True)
parser.add_argument("--output", type=Path, required=True)
args = parser.parse_args()
instructions, functions, exit_addr, rodata = producer.parse_proof_object_program(
    args.name, args.object_dir.resolve())
source = producer.render_program(args.name, instructions, functions, kind=args.kind,
                                 exit_addr=exit_addr, rodata16=rodata,
                                 program_section="socket" if args.kind == "raw" else None)
header = os.path.relpath(ROOT / "kprog/x86/x86_sim_local_bpf.h", args.output.resolve().parent)
args.output.write_text(source.replace('#include "../x86_sim_local_bpf.h"',
                                      '#include "' + header + '"'))
print(json.dumps({"name": args.name, "instructions": len(instructions),
                  "subfunctions": len(functions),
                  "preamble": source.split('#include', 1)[0]}))
