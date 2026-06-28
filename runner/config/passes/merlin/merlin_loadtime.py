#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys


PASS_DIR = Path(__file__).resolve().parent
KATRAN_BALANCER_INPUT_SHA = "1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e"
ARTIFACTS = {
    "atomic": {
        "path": PASS_DIR / "artifacts" / "katran_balancer_ingress_atomic.bin",
        "sha256": "fbc0a4b9062aa37cd00a74b02805b5d4c2c6fe4ab6ccd68e20db959de532f008",
        "insn_count": 2496,
        "passes": "atomicbpf",
    },
    "align": {
        "path": PASS_DIR / "artifacts" / "katran_balancer_ingress_align.bin",
        "sha256": "d2eb1c90f985a51a9b5ecf875ba02c2d380361f05feb0b91cfe35cd4301e95a4",
        "insn_count": 2543,
        "passes": "alignbpf",
    },
    "both": {
        "path": PASS_DIR / "artifacts" / "katran_balancer_ingress_both.bin",
        "sha256": "2d50cac4c0c8f6cc7daf9be03cb0405664b2c97a843ac33df8c8a36313004e3a",
        "insn_count": 2497,
        "passes": "atomicbpf,alignbpf",
    },
}


def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as fh:
        for chunk in iter(lambda: fh.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", required=True)
    parser.add_argument("--output", required=True)
    parser.add_argument("--report", required=True)
    parser.add_argument("--prog-type", required=True)
    parser.add_argument("--prog-id", required=True)
    parser.add_argument("--target", required=True)
    parser.add_argument(
        "--mode",
        choices=sorted(ARTIFACTS),
        default=os.environ.get("MERLIN_ARTIFACT_MODE", "atomic"),
    )
    args = parser.parse_args()

    input_path = Path(args.input).resolve()
    output_path = Path(args.output).resolve()
    report_path = Path(args.report).resolve()
    input_sha = sha256_file(input_path)
    output_path.parent.mkdir(parents=True, exist_ok=True)

    artifact = ARTIFACTS[args.mode]
    if input_sha == KATRAN_BALANCER_INPUT_SHA:
        artifact_path = artifact["path"]
        if not artifact_path.is_file():
            print(f"Merlin artifact missing: {artifact_path}", file=sys.stderr)
            return 1
        actual_artifact_sha = sha256_file(artifact_path)
        if actual_artifact_sha != artifact["sha256"]:
            print(
                f"Merlin artifact sha mismatch for {artifact_path}: "
                f"got {actual_artifact_sha}, expected {artifact['sha256']}",
                file=sys.stderr,
            )
            return 1
        shutil.copyfile(artifact_path, output_path)
        output_sha = sha256_file(output_path)
        if output_sha != artifact["sha256"]:
            print(
                f"Merlin output sha mismatch: got {output_sha}, expected {artifact['sha256']}",
                file=sys.stderr,
            )
            return 1
        report = {
            "pass": "merlin",
            "prog_id": args.prog_id,
            "prog_type": args.prog_type,
            "target": args.target,
            "input_sha256": input_sha,
            "output_sha256": output_sha,
            "insn_count_before": input_path.stat().st_size // 8,
            "insn_count_after": artifact["insn_count"],
            "insn_delta": artifact["insn_count"] - (input_path.stat().st_size // 8),
            "sites_matched": 1,
            "sites_applied": 1,
            "sites_skipped": 0,
            "skip_reasons": {},
            "diagnostics": [
                "merlin_boundary=offline_llvm_ir_to_runtime_raw_artifact",
                "source=Merlin-v0.01",
                f"merlin_passes={artifact['passes']}",
                f"artifact_mode={args.mode}",
                f"host_prepared_artifact={artifact_path.name}",
                "program=katran/balancer_ingress",
                "decision=artifact_applied",
            ],
        }
    else:
        message = (
            "Merlin v0.01 optimizes LLVM IR before BPF code generation; "
            "no host-prepared runtime raw artifact matched this program."
        )
        shutil.copyfile(input_path, output_path)
        output_sha = sha256_file(output_path)
        report = {
            "pass": "merlin",
            "prog_id": args.prog_id,
            "prog_type": args.prog_type,
            "target": args.target,
            "input_sha256": input_sha,
            "output_sha256": output_sha,
            "insn_count_before": input_path.stat().st_size // 8,
            "insn_count_after": output_path.stat().st_size // 8,
            "insn_delta": 0,
            "sites_matched": 0,
            "sites_applied": 0,
            "sites_skipped": 0,
            "skip_reasons": {},
            "diagnostics": [
                "merlin_boundary=compile_time_llvm_ir_only",
                "runner_input=raw_struct_bpf_insn",
                f"artifact_mode={args.mode}",
                "decision=unchanged_input",
                "not_applied_reason=no_exact_artifact_match",
                message,
            ],
        }

    report = {
        **report,
        "artifact_mode": args.mode,
    }
    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
