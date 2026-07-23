#!/usr/bin/env python3
"""Focused CLI regressions for deployment-informed bpfopt passes."""

from __future__ import annotations

import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile
import unittest


BPF_LD_IMM64 = 0x18
BPF_LDXDW = 0x79
BPF_LDXW = 0x61
BPF_LDXH = 0x69
BPF_LDXB = 0x71
BPF_STW = 0x62
BPF_STXDW = 0x7B
BPF_MOV64_K = 0xB7
BPF_MOV64_X = 0xBF
BPF_ADD64_K = 0x07
BPF_ADD64_X = 0x0F
BPF_JA = 0x05
BPF_JEQ64_K = 0x15
BPF_JGT64_X = 0x2D
BPF_JLT64_X = 0xAD
BPF_CALL = 0x85
BPF_EXIT = 0x95
BPF_PSEUDO_MAP_IDX = 5
BPF_PSEUDO_MAP_IDX_VALUE = 6
BPF_PSEUDO_CALL = 1
CONTEXT_FALLBACK_MAP_MARKER = 0x7FFFFFFE
BPFOPT_PATH: Path | None = None
SPECIALIZATION_PASSES = {
    "tail_call_icache",
    "hot_region_version",
    "loop_trip_spec",
    "context_specialize",
}
TEST_PROGRAM_HASH = "0123456789abcdef"


def insn(code: int, dst: int = 0, src: int = 0, off: int = 0, imm: int = 0) -> bytes:
    return struct.pack("<BBhi", code, dst | (src << 4), off, imm)


def write_program(path: Path, instructions: list[bytes]) -> None:
    path.write_bytes(b"".join(instructions))


class SpecializationCliTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls) -> None:
        if BPFOPT_PATH is None:
            raise RuntimeError("expected bpfopt path")
        cls.bpfopt = BPFOPT_PATH

    def run_pass(
        self,
        workdir: Path,
        pass_name: str,
        profile: dict[str, object],
        program: list[bytes],
        *,
        dump_ir: bool = False,
        pass_args: tuple[str, ...] = (),
    ) -> tuple[bytes, dict[str, object], str]:
        input_path = workdir / "input.bin"
        output_path = workdir / "output.bin"
        report_path = workdir / "report.json"
        profile_path = workdir / "profile.json"
        write_program(input_path, program)
        if pass_name in SPECIALIZATION_PASSES:
            profile = {"program_hash": TEST_PROGRAM_HASH, **profile}
        profile_path.write_text(json.dumps(profile), encoding="utf-8")
        env = os.environ.copy()
        if dump_ir:
            env["BPFOPT_DUMP_IR"] = "1"
        command = [
            str(self.bpfopt),
            "--pass",
            pass_name,
            "--input",
            str(input_path),
            "--output",
            str(output_path),
            "--report",
            str(report_path),
            "--prog-type",
            "xdp",
            "--",
            "--profile",
            str(profile_path),
        ]
        if pass_name in SPECIALIZATION_PASSES:
            command.extend(["--program-hash", TEST_PROGRAM_HASH])
        command.extend(pass_args)
        completed = subprocess.run(
            command,
            env=env,
            check=False,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        self.assertEqual(completed.returncode, 0, completed.stderr)
        return (
            output_path.read_bytes(),
            json.loads(report_path.read_text(encoding="utf-8")),
            completed.stderr,
        )

    def run_map_inline(
        self,
        workdir: Path,
        stability: str | None,
        *,
        only_hinted: bool = False,
        include_uniform_other: bool = False,
        included_maps: tuple[str, ...] = (),
        excluded_maps: tuple[str, ...] = (),
        assume_hint_key: bool = False,
    ) -> subprocess.CompletedProcess[str]:
        input_path = workdir / "map-input.bin"
        output_path = workdir / "map-output.bin"
        report_path = workdir / "map-report.json"
        map_values = workdir / "map-values"
        map_values.mkdir()
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LD_IMM64, dst=1, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_MOV64_X, dst=2, src=6),
            insn(BPF_CALL, imm=1),
        ]
        if include_uniform_other:
            program.extend(
                [
                    insn(BPF_LD_IMM64, dst=1, src=BPF_PSEUDO_MAP_IDX, imm=1),
                    insn(0),
                    insn(BPF_MOV64_X, dst=2, src=6),
                    insn(BPF_CALL, imm=1),
                ]
            )
        program.extend(
            [
                insn(BPF_JEQ64_K, dst=0, off=1, imm=0),
                insn(BPF_LDXW, dst=0, src=0),
                insn(BPF_EXIT),
            ]
        )
        write_program(input_path, program)
        (map_values / "map-1.show.json").write_text(
            json.dumps(
                {
                    "id": 1,
                    "name": "cfg",
                    "type": "hash",
                    "bytes_key": 4,
                    "bytes_value": 4,
                }
            ),
            encoding="utf-8",
        )
        (map_values / "map-1.dump.json").write_text(
            json.dumps(
                [
                    {
                        "key": ["0x01", "0x00", "0x00", "0x00"],
                        "value": ["0x07", "0x00", "0x00", "0x00"],
                    }
                ]
            ),
            encoding="utf-8",
        )
        if include_uniform_other:
            (map_values / "map-2.show.json").write_text(
                json.dumps(
                    {
                        "id": 2,
                        "name": "unrelated_array",
                        "type": "array",
                        "bytes_key": 4,
                        "bytes_value": 4,
                    }
                ),
                encoding="utf-8",
            )
            (map_values / "map-2.dump.json").write_text(
                json.dumps(
                    {
                        "compression": "uniform",
                        "value_size": 4,
                        "value_hex": "09000000",
                    }
                ),
                encoding="utf-8",
            )
        command = [
            str(self.bpfopt),
            "--pass",
            "map_inline",
            "--input",
            str(input_path),
            "--output",
            str(output_path),
            "--report",
            str(report_path),
            "--prog-type",
            "xdp",
            "--",
            "--map-values",
            str(map_values),
            "--map-ids",
            "1,2" if include_uniform_other else "1",
            "--inline-hint=cfg:01000000",
        ]
        if only_hinted:
            command.append("--only-hinted")
        for map_name in included_maps:
            command.append(f"--include-map={map_name}")
        for map_name in excluded_maps:
            command.append(f"--exclude-map={map_name}")
        if assume_hint_key:
            command.append("--assume-hint-key")
        if stability is not None:
            command.extend(["--stability", stability])
        env = os.environ.copy()
        env["BPFOPT_DUMP_IR"] = "1"
        return subprocess.run(
            command,
            env=env,
            check=False,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )

    def test_tail_call_icache_duplicates_only_dynamic_site(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LD_IMM64, dst=2, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_LDXW, dst=3, src=1, off=16),
            insn(BPF_CALL, imm=12),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "tail_call_icache",
            "per_site": {
                "4": {
                    "observations": 1000,
                    "keys": [
                        {"key": 7, "count": 800},
                        {"key": 9, "count": 200},
                    ],
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "tail_call_icache", profile, program, dump_ir=True
            )
        calls = [
            struct.unpack_from("<i", output, pc + 4)[0]
            for pc in range(0, len(output), 8)
            if output[pc] == BPF_CALL
        ]
        self.assertEqual(calls.count(12), 3, ir)
        self.assertEqual(len(output), len(program) * 8 + 8 * 8)
        self.assertEqual(output[4 * 8], 0x56)  # if w3 != key 7 -> key 9
        self.assertEqual(output[5 * 8], 0xB4)  # w3 = key 7
        self.assertEqual(output[6 * 8], BPF_CALL)
        self.assertEqual(output[7 * 8], 0x05)  # skip key 9 and dynamic slow
        self.assertEqual(output[8 * 8], 0x56)
        self.assertEqual(output[9 * 8], 0xB4)
        self.assertEqual(output[10 * 8], BPF_CALL)
        self.assertEqual(output[11 * 8], 0x05)
        self.assertEqual(output[12 * 8], BPF_CALL)
        self.assertEqual(struct.unpack_from("<h", output, 4 * 8 + 2)[0], 3)
        self.assertEqual(struct.unpack_from("<h", output, 7 * 8 + 2)[0], 5)
        self.assertEqual(struct.unpack_from("<h", output, 11 * 8 + 2)[0], 1)
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(report["sites_skipped"], 0)

    def test_tail_call_icache_remaps_crossing_branch_and_local_call(self) -> None:
        program = [
            insn(BPF_CALL, src=BPF_PSEUDO_CALL, imm=6),  # target pc 7
            insn(BPF_JEQ64_K, dst=0, off=4, imm=0),  # target pc 6
            insn(BPF_LD_IMM64, dst=2, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_LDXW, dst=3, src=1, off=16),
            insn(BPF_CALL, imm=12),
            insn(BPF_EXIT),
            insn(BPF_MOV64_K, dst=0, imm=1),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "tail_call_icache",
            "per_site": {
                "5": {
                    "observations": 1000,
                    "keys": [{"key": 7, "count": 900}],
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, _ = self.run_pass(
                Path(tmp), "tail_call_icache", profile, program
            )
        self.assertEqual(len(output), len(program) * 8 + 4 * 8)
        self.assertEqual(struct.unpack_from("<i", output, 4)[0], 10)
        self.assertEqual(struct.unpack_from("<h", output, 1 * 8 + 2)[0], 8)
        self.assertEqual(output[5 * 8], 0x56)
        self.assertEqual(output[9 * 8], BPF_CALL)
        self.assertEqual(report["sites_applied"], 1)

    def test_tail_call_icache_phase_stable_replaces_dynamic_key_without_guard(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LD_IMM64, dst=2, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_LDXW, dst=3, src=1, off=16),
            insn(BPF_CALL, imm=12),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "tail_call_icache",
            "per_site": {
                "4": {
                    "observations": 1000,
                    "keys": [{"key": 7, "count": 1000}],
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, _ = self.run_pass(
                Path(tmp),
                "tail_call_icache",
                profile,
                program,
                pass_args=("--phase-stable",),
            )
        calls = [
            struct.unpack_from("<i", output, pc + 4)[0]
            for pc in range(0, len(output), 8)
            if output[pc] == BPF_CALL
        ]
        self.assertEqual(calls.count(12), 1)
        self.assertEqual(len(output), len(program) * 8)
        self.assertEqual(output[3 * 8], 0xB4)
        self.assertEqual(output[3 * 8 + 1] & 0x0F, 3)
        self.assertEqual(struct.unpack_from("<i", output, 3 * 8 + 4)[0], 7)
        self.assertEqual(output[4 * 8], BPF_CALL)
        self.assertEqual(report["sites_applied"], 1)

    def test_tail_call_icache_phase_stable_replaces_earlier_reaching_key_load(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LDXH, dst=3, src=6, off=6),
            insn(BPF_MOV64_X, dst=1, src=6),
            insn(BPF_LD_IMM64, dst=2, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_CALL, imm=12),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "tail_call_icache",
            "per_site": {
                "5": {
                    "observations": 1000,
                    "keys": [{"key": 745, "count": 1000}],
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, _ = self.run_pass(
                Path(tmp),
                "tail_call_icache",
                profile,
                program,
                pass_args=("--phase-stable",),
            )
        self.assertEqual(len(output), len(program) * 8)
        self.assertEqual(output[1 * 8], 0xB4)
        self.assertEqual(output[1 * 8 + 1] & 0x0F, 3)
        self.assertEqual(struct.unpack_from("<i", output, 1 * 8 + 4)[0], 745)
        self.assertEqual(output[5 * 8], BPF_CALL)
        self.assertEqual(report["sites_applied"], 1)

    def test_tail_call_icache_phase_stable_keeps_definition_when_path_can_bypass_it(self) -> None:
        program = [
            insn(BPF_JEQ64_K, dst=0, off=1, imm=0),  # target pc 2
            insn(BPF_LDXW, dst=3, src=1, off=16),
            insn(BPF_MOV64_X, dst=1, src=6),
            insn(BPF_CALL, imm=12),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "tail_call_icache",
            "per_site": {
                "3": {
                    "observations": 1000,
                    "keys": [{"key": 7, "count": 1000}],
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, _ = self.run_pass(
                Path(tmp),
                "tail_call_icache",
                profile,
                program,
                pass_args=("--phase-stable",),
            )
        self.assertEqual(len(output), (len(program) + 1) * 8)
        self.assertEqual(output[1 * 8], BPF_LDXW)
        self.assertEqual(output[3 * 8], 0xB4)
        self.assertEqual(output[4 * 8], BPF_CALL)
        self.assertEqual(report["sites_applied"], 1)

    def test_loop_trip_profile_marks_real_loop_header(self) -> None:
        program = [
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_ADD64_K, dst=0, imm=1),
            insn(BPF_JLT64_X, dst=0, src=2, off=-2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "loop_trip_spec",
            "per_loop": {
                "2": {
                    "trip_count": 127,
                    "observations": 127,
                    "backedge_count": 126,
                    "exit_count": 1,
                    "latch_pc": 3,
                }
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "loop_trip_spec", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("llvm.loop.unroll.count", ir)

    def test_hot_region_versions_merge_reached_by_profiled_hot_edge(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=2, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=10),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=0, imm=20),
            insn(BPF_ADD64_K, dst=0, imm=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "hot_region_version",
            "per_site": {
                "1": {"branch_count": 1000, "taken": 900, "not_taken": 100}
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "hot_region_version", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn(".hot", ir)

    def test_hot_region_repairs_cloned_value_used_by_downstream_phi(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_MOV64_K, dst=7, imm=1),
            insn(BPF_JEQ64_K, dst=2, off=2, imm=7),
            insn(BPF_MOV64_K, dst=6, imm=2),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=6, imm=3),
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_JA, off=0),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=0),
            insn(BPF_MOV64_X, dst=7, src=6),
            insn(BPF_MOV64_X, dst=0, src=7),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "hot_region_version",
            "per_site": {
                "2": {"branch_count": 1000, "taken": 900, "not_taken": 100}
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "hot_region_version", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        # The hot version must carry the dependent value through the cloned
        # downstream region instead of immediately rejoining the cold CFG.
        self.assertIn("bb_inst_10.hot", ir)
        self.assertIn("ret i64 %r7.0.hot", ir)

    def test_hot_region_versions_merge_with_multiple_successors(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=2, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=10),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=0, imm=20),
            insn(BPF_ADD64_K, dst=0, imm=3),
            insn(BPF_JEQ64_K, dst=0, off=2, imm=23),
            insn(BPF_MOV64_K, dst=6, imm=1),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=6, imm=2),
            insn(BPF_ADD64_X, dst=0, src=6),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "hot_region_version",
            "per_site": {
                "1": {"branch_count": 1000, "taken": 900, "not_taken": 100}
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "hot_region_version", profile, program, dump_ir=True
            )
        self.assertNotEqual(output, b"".join(program))
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(report["sites_matched"], 1)
        self.assertEqual(report["sites_skipped"], 0)
        self.assertIn(".hot", ir)

    def test_hot_region_versions_multiple_roots_inside_out(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=2, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=10),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=0, imm=20),
            insn(BPF_ADD64_K, dst=0, imm=3),
            insn(BPF_JEQ64_K, dst=2, off=2, imm=9),
            insn(BPF_MOV64_K, dst=6, imm=1),
            insn(BPF_JA, off=1),
            insn(BPF_MOV64_K, dst=6, imm=2),
            insn(BPF_ADD64_X, dst=0, src=6),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "hot_region_version",
            "per_site": {
                "1": {"branch_count": 1000, "taken": 900, "not_taken": 100},
                "6": {"branch_count": 800, "taken": 700, "not_taken": 100},
            },
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "hot_region_version", profile, program, dump_ir=True
            )
        self.assertNotEqual(output, b"".join(program))
        self.assertEqual(report["sites_applied"], 2)
        self.assertEqual(report["sites_matched"], 2)
        self.assertEqual(report["sites_skipped"], 0)
        self.assertGreaterEqual(ir.count(".hot"), 2)

    def test_context_specialize_builds_guarded_fast_and_slow_versions(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_ADD64_K, dst=0, imm=11),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=7),
            insn(BPF_ADD64_K, dst=0, imm=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "context",
                    "source": "pmu_branch",
                    "offset": 16,
                    "width": 4,
                    "hot_value": 7,
                    "observations": 1000,
                    "hot_count": 950,
                    "load_pcs": [0],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("bpf_main.context.fast", ir)
        self.assertNotIn("bpf_main.context.original", ir)
        self.assertIn("context.field.hot", ir)
        self.assertIn("context.original.tail_call", ir)

    def test_context_specialize_accepts_guarded_deployment_context_hint(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=8, src=1),
            insn(BPF_LDXDW, dst=2, src=8, off=8),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 8,
                    "width": 8,
                    "hot_value": 202,
                    "load_pcs": [1],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("bpf_main.context.fast", ir)
        self.assertIn("context.field.hot", ir)
        self.assertIn("context.original.tail_call", ir)

    def test_context_specialize_does_not_alias_map_load_at_same_offset(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=8, src=1),
            insn(BPF_LDXW, dst=2, src=8, off=0),
            insn(BPF_LD_IMM64, dst=7, src=BPF_PSEUDO_MAP_IDX, imm=0),
            insn(0),
            insn(BPF_LDXW, dst=4, src=7, off=0),
            insn(BPF_ADD64_X, dst=2, src=4),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 0,
                    "width": 4,
                    "hot_value": 64,
                    "load_pcs": [1],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("bpf_main.context.fast", ir)
        self.assertIn("__llvmbpf_pseudo_map", ir)

    def test_context_specialize_recovers_builder_proven_spilled_context_load(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_STXDW, dst=10, src=6, off=-8),
            insn(BPF_LDXDW, dst=8, src=10, off=-8),
            insn(BPF_LDXW, dst=2, src=8, off=0),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 0,
                    "width": 4,
                    "hot_value": 64,
                    "load_pcs": [3],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("bpf_main.context.fast", ir)
        self.assertIn("context.field.hot", ir)

    def test_context_specialize_replaces_multiple_exact_context_loads(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_LDXW, dst=3, src=1, off=16),
            insn(BPF_ADD64_X, dst=0, src=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 16,
                    "width": 4,
                    "hot_value": 8,
                    "load_pcs": [0, 2],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertIn("bpf_main.context.fast", ir)
        self.assertIn("context.field.hot", ir)

    def test_context_specialize_builds_multiple_guarded_fast_versions(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_MOV64_X, dst=0, src=2),
            insn(BPF_EXIT),
        ]
        def field(hot_value: int) -> dict[str, object]:
            return {
                "kind": "context",
                "source": "deployment_hint",
                "offset": 16,
                "width": 4,
                "hot_value": hot_value,
                "load_pcs": [0],
            }

        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "versions": [
                {"name": "first", "fields": [field(7)]},
                {"name": "second", "fields": [field(9)]},
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 2)
        self.assertEqual(report["sites_matched"], 2)
        self.assertIn("bpf_main.context.fast.0", ir)
        self.assertIn("bpf_main.context.fast.1", ir)
        self.assertEqual(ir.count("context.original.tail_call"), 1)
        decoded = [
            struct.unpack_from("<BBhi", output, offset)
            for offset in range(0, len(output), 8)
        ]
        self.assertFalse(
            any(
                code == BPF_CALL and (registers >> 4) == BPF_PSEUDO_CALL
                for code, registers, _off, _imm in decoded
            ),
            "guarded fast versions must inline into the entry function",
        )

    def test_packet_context_specialize_bounds_guard_dominates_wire_byte_guard(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LDXW, dst=7, src=6, off=0),
            insn(BPF_LDXW, dst=8, src=6, off=4),
            insn(BPF_MOV64_X, dst=2, src=7),
            insn(BPF_ADD64_K, dst=2, imm=24),
            insn(BPF_JGT64_X, dst=2, src=8, off=3),
            insn(BPF_LDXB, dst=3, src=7, off=23),
            insn(BPF_MOV64_X, dst=0, src=3),
            insn(BPF_EXIT),
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 23,
                    "width": 1,
                    "hot_bytes_hex": "11",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [6],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        fast = re.search(
            r"define internal i64 @bpf_main\.context\.fast.*?^}",
            ir,
            flags=re.MULTILINE | re.DOTALL,
        )
        wrapper = re.search(
            r"define i64 @bpf_main.*?^}",
            ir,
            flags=re.MULTILINE | re.DOTALL,
        )
        self.assertIsNotNone(fast, ir)
        self.assertIsNotNone(wrapper, ir)
        self.assertNotIn("load i8", fast.group(0))
        wrapper_ir = wrapper.group(0)
        self.assertLess(
            wrapper_ir.index("context.packet.in_bounds"),
            wrapper_ir.index("context.packet.field.value"),
        )
        output_insns = list(struct.iter_unpack("<BBhi", output))
        self.assertEqual(
            {
                (item[0], item[1] >> 4, item[2])
                for item in output_insns[:2]
            },
            {(BPF_LDXW, 1, 0), (BPF_LDXW, 1, 4)},
        )
        self.assertEqual(
            sum(
                item[0] == BPF_CALL
                and item[1] >> 4 != BPF_PSEUDO_CALL
                and item[3] == 12
                for item in output_insns
            ),
            1,
        )
        self.assertEqual(
            sum(
                item[0] == BPF_LD_IMM64
                and item[1] >> 4 == BPF_PSEUDO_MAP_IDX
                and item[3] == CONTEXT_FALLBACK_MAP_MARKER
                for item in output_insns
            ),
            1,
        )
        self.assertEqual(report["sites_applied"], 1)

    def test_packet_context_specialize_ignores_local_call_target_in_entry_cfg(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LDXW, dst=7, src=6, off=0),
            insn(BPF_LDXW, dst=8, src=6, off=4),
            insn(BPF_MOV64_X, dst=2, src=7),
            insn(BPF_ADD64_K, dst=2, imm=24),
            insn(BPF_JGT64_X, dst=2, src=8, off=3),
            insn(BPF_LDXB, dst=3, src=7, off=23),
            insn(BPF_CALL, src=BPF_PSEUDO_CALL, imm=3),
            insn(BPF_EXIT),
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_EXIT),
            insn(BPF_MOV64_K, dst=0, imm=1),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 23,
                    "width": 1,
                    "hot_bytes_hex": "11",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [6],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, _ = self.run_pass(
                Path(tmp), "context_specialize", profile, program
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(report["sites_skipped"], 0)

    def test_packet_context_specialize_uses_exact_pc_for_proven_dynamic_offset(self) -> None:
        program = [
            insn(BPF_LDXW, dst=7, src=1, off=0),
            insn(BPF_MOV64_K, dst=2, imm=0),
            insn(BPF_MOV64_K, dst=4, imm=34),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=0),
            insn(BPF_MOV64_K, dst=4, imm=62),
            insn(BPF_MOV64_X, dst=3, src=7),
            insn(BPF_ADD64_X, dst=3, src=4),
            insn(0x55, dst=2, off=1, imm=0),
            insn(BPF_LDXH, dst=5, src=3, off=0),
            insn(BPF_MOV64_X, dst=0, src=5),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 34,
                    "width": 2,
                    "hot_bytes_hex": "2710",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [8],
                    "load_offsets": [34],
                }
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        fast = re.search(
            r"define internal i64 @bpf_main\.context\.fast.*?^}",
            ir,
            flags=re.MULTILINE | re.DOTALL,
        )
        self.assertIsNotNone(fast, ir)
        self.assertNotIn("load i16", fast.group(0))

    def test_packet_context_specialize_coalesces_contiguous_guard_bytes(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LDXW, dst=7, src=6, off=0),
            insn(BPF_LDXW, dst=8, src=6, off=4),
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_MOV64_X, dst=2, src=7),
            insn(BPF_ADD64_K, dst=2, imm=18),
            insn(BPF_JGT64_X, dst=2, src=8, off=4),
            insn(BPF_LDXW, dst=3, src=7, off=12),
            insn(BPF_LDXH, dst=4, src=7, off=16),
            insn(BPF_ADD64_X, dst=3, src=4),
            insn(BPF_MOV64_X, dst=0, src=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "fields": [
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 12,
                    "width": 4,
                    "hot_bytes_hex": "01020304",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [7],
                },
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 16,
                    "width": 2,
                    "hot_bytes_hex": "0506",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [8],
                },
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        wrapper = re.search(
            r"define i64 @bpf_main.*?^}",
            ir,
            flags=re.MULTILINE | re.DOTALL,
        )
        self.assertIsNotNone(wrapper, ir)
        guard_widths = re.findall(
            r"context\.packet\.field\.value[^=]* = load i(\d+)",
            wrapper.group(0),
        )
        self.assertEqual(guard_widths, ["32", "16"])
        self.assertEqual(report["sites_applied"], 2)

    def test_packet_context_specialize_uses_wide_unaligned_guard(self) -> None:
        program = [
            insn(BPF_MOV64_X, dst=6, src=1),
            insn(BPF_LDXW, dst=7, src=6, off=0),
            insn(BPF_LDXW, dst=8, src=6, off=4),
            insn(BPF_MOV64_K, dst=0, imm=0),
            insn(BPF_MOV64_X, dst=2, src=7),
            insn(BPF_ADD64_K, dst=2, imm=34),
            insn(BPF_JGT64_X, dst=2, src=8, off=4),
            insn(BPF_LDXW, dst=3, src=7, off=26),
            insn(BPF_LDXW, dst=4, src=7, off=30),
            insn(BPF_ADD64_X, dst=3, src=4),
            insn(BPF_MOV64_X, dst=0, src=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "schema_version": 1,
            "pass": "context_specialize",
            "versions": [
                {
                    "name": "forward",
                    "fields": [
                        {
                            "kind": "packet",
                            "source": "deployment_hint",
                            "offset": 26,
                            "width": 8,
                            "hot_bytes_hex": "0102030405060708",
                            "context_data_offset": 0,
                            "context_data_end_offset": 4,
                            "load_pcs": [7, 8],
                        }
                    ],
                },
                {
                    "name": "reverse",
                    "fields": [
                        {
                            "kind": "packet",
                            "source": "deployment_hint",
                            "offset": 26,
                            "width": 8,
                            "hot_bytes_hex": "0807060504030201",
                            "context_data_offset": 0,
                            "context_data_end_offset": 4,
                            "load_pcs": [7, 8],
                        }
                    ],
                },
            ],
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, ir = self.run_pass(
                Path(tmp), "context_specialize", profile, program, dump_ir=True
            )
        wrapper = re.search(
            r"define i64 @bpf_main.*?^}",
            ir,
            flags=re.MULTILINE | re.DOTALL,
        )
        self.assertIsNotNone(wrapper, ir)
        guard_widths = re.findall(
            r"context\.packet\.field\.value[^=]* = load i(\d+)",
            wrapper.group(0),
        )
        self.assertEqual(guard_widths, ["64"])
        output_insns = list(struct.iter_unpack("<BBhi", output))
        self.assertTrue(
            any(code == BPF_LDXDW and off == 26 for code, _regs, off, _imm in output_insns),
            "the emitted guard must retain one wide load at the unaligned tuple offset: "
            f"{output_insns}",
        )
        self.assertEqual(
            sum(code == BPF_LDXDW and off == 26 for code, _regs, off, _imm in output_insns),
            1,
        )
        self.assertEqual(report["sites_applied"], 2)

    def test_branch_flip_maps_taken_weight_by_bpf_target_not_ir_condition(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "per_site": {
                "1": {
                    "branch_count": 1000,
                    "branch_misses": 100,
                    "miss_rate": 0.1,
                    "taken": 900,
                    "not_taken": 100,
                }
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, ir = self.run_pass(
                Path(tmp), "branch_flip", profile, program, dump_ir=True
            )
        self.assertEqual(report["sites_applied"], 1)
        branch = re.search(
            r"br i1 .*label %(bb_inst_3), label %(bb_inst_2).*!prof !(\d+)", ir
        )
        reverse = re.search(
            r"br i1 .*label %(bb_inst_2), label %(bb_inst_3).*!prof !(\d+)", ir
        )
        matched = branch or reverse
        self.assertIsNotNone(matched, ir)
        metadata_id = matched.group(3 if branch else 3)
        metadata = re.search(
            rf"!{metadata_id} = !\{{!\"branch_weights\", i32 (\d+), i32 (\d+)\}}",
            ir,
        )
        self.assertIsNotNone(metadata, ir)
        weights = (int(metadata.group(1)), int(metadata.group(2)))
        self.assertEqual(weights, (900, 100) if branch else (100, 900))

    def test_branch_flip_accepts_independent_pmu_sample_counts(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "per_site": {
                "1": {
                    "branch_count": 1,
                    "branch_misses": 2,
                    "miss_rate": 1.0,
                    "taken": 1,
                    "not_taken": 0,
                }
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, _ = self.run_pass(
                Path(tmp), "branch_flip", profile, program
            )
        self.assertEqual(report["sites_applied"], 1)

    def test_branch_flip_skips_when_raw_fallthrough_is_already_hot(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=7),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_EXIT),
        ]
        profile = {
            "per_site": {
                "1": {
                    "branch_count": 1000,
                    "branch_misses": 10,
                    "miss_rate": 0.01,
                    "taken": 100,
                    "not_taken": 900,
                }
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            output, report, _ = self.run_pass(
                Path(tmp), "branch_flip", profile, program
            )
        self.assertEqual(output, b"".join(program))
        self.assertEqual(report["sites_applied"], 0)
        self.assertEqual(report["sites_skipped"], 1)
        self.assertEqual(report["skip_reasons"], {"target_not_hot": 1})

    def test_branch_flip_limits_annotations_by_bias_per_layout_distance(self) -> None:
        program = [
            insn(BPF_LDXW, dst=2, src=1, off=16),
            insn(BPF_JEQ64_K, dst=2, off=3, imm=7),
            insn(BPF_JEQ64_K, dst=2, off=1, imm=9),
            insn(BPF_MOV64_K, dst=0, imm=2),
            insn(BPF_MOV64_K, dst=0, imm=3),
            insn(BPF_EXIT),
        ]
        profile = {
            "per_site": {
                "1": {
                    "branch_count": 1000,
                    "branch_misses": 10,
                    "miss_rate": 0.01,
                    "taken": 900,
                    "not_taken": 100,
                },
                "2": {
                    "branch_count": 1000,
                    "branch_misses": 20,
                    "miss_rate": 0.02,
                    "taken": 700,
                    "not_taken": 300,
                },
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            _, report, _ = self.run_pass(
                Path(tmp),
                "branch_flip",
                profile,
                program,
                pass_args=("--max-sites", "1"),
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(report["sites_matched"], 2)
        self.assertEqual(report["sites_skipped"], 1)
        self.assertEqual(report["skip_reasons"], {"site_budget": 1})
        self.assertEqual(
            report["skipped_sites"], [{"pc": 1, "reason": "site_budget"}]
        )

    def test_map_inline_guarded_checks_live_value_and_reports_contract(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            completed = self.run_map_inline(workdir, "guarded")
            self.assertEqual(completed.returncode, 0, completed.stderr)
            report = json.loads(
                (workdir / "map-report.json").read_text(encoding="utf-8")
            )
        self.assertIn("mapinline.current.word", completed.stderr)
        self.assertIn("mapinline.nonnull", completed.stderr)
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(
            report["inlined_map_entries"][0]["stability"], "guarded"
        )

    def test_map_inline_requires_explicit_stability_contract(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            completed = self.run_map_inline(Path(tmp), None)
        self.assertNotEqual(completed.returncode, 0)
        self.assertIn("requires explicit --stability", completed.stderr)

    def test_map_inline_only_hinted_excludes_unselected_uniform_map(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            completed = self.run_map_inline(
                workdir,
                "guarded",
                only_hinted=True,
                include_uniform_other=True,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            report = json.loads(
                (workdir / "map-report.json").read_text(encoding="utf-8")
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(
            {entry["map_id"] for entry in report["inlined_map_entries"]},
            {1},
        )

    def test_map_inline_include_map_selects_uniform_map_without_key_guard(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            completed = self.run_map_inline(
                workdir,
                "phase-stable",
                include_uniform_other=True,
                included_maps=("unrelated_array",),
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            report = json.loads(
                (workdir / "map-report.json").read_text(encoding="utf-8")
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(
            {entry["map_id"] for entry in report["inlined_map_entries"]},
            {2},
        )
        self.assertNotIn("mapinline.key_match", completed.stderr)

    def test_map_inline_include_map_rejects_unknown_map(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            completed = self.run_map_inline(
                Path(tmp), "phase-stable", included_maps=("missing",)
            )
        self.assertNotEqual(completed.returncode, 0)
        self.assertIn("--include-map references unknown map missing", completed.stderr)

    def test_map_inline_exclude_map_omits_entry_map_and_keeps_other_maps(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            completed = self.run_map_inline(
                workdir,
                "phase-stable",
                include_uniform_other=True,
                excluded_maps=("cfg",),
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            report = json.loads(
                (workdir / "map-report.json").read_text(encoding="utf-8")
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(
            {entry["map_id"] for entry in report["inlined_map_entries"]},
            {2},
        )

    def test_map_inline_phase_stable_can_assume_observed_hint_key(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            completed = self.run_map_inline(
                workdir, "phase-stable", assume_hint_key=True
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            report = json.loads(
                (workdir / "map-report.json").read_text(encoding="utf-8")
            )
        self.assertEqual(report["sites_applied"], 1)
        self.assertNotIn("mapinline.key_match", completed.stderr)

    def test_map_inline_directs_single_entry_array_lookup_to_live_value(self) -> None:
        """Catch helper retention or illegal multi-entry direct relocation."""
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            input_path = workdir / "map-input.bin"
            output_path = workdir / "map-output.bin"
            report_path = workdir / "map-report.json"
            map_values = workdir / "map-values"
            map_values.mkdir()
            program = [
                insn(BPF_STW, dst=10, off=-4, imm=0),
                insn(BPF_LD_IMM64, dst=1, src=BPF_PSEUDO_MAP_IDX, imm=0),
                insn(0),
                insn(BPF_MOV64_X, dst=2, src=10),
                insn(BPF_ADD64_K, dst=2, imm=-4),
                insn(BPF_CALL, imm=1),
                insn(BPF_JEQ64_K, dst=0, off=1, imm=0),
                insn(BPF_LDXW, dst=0, src=0),
                insn(BPF_EXIT),
            ]
            write_program(input_path, program)
            show_path = map_values / "map-1.show.json"
            show = {
                "id": 1,
                "name": "hot_data",
                "type": "array",
                "bytes_key": 4,
                "bytes_value": 32,
                "max_entries": 1,
            }
            show_path.write_text(json.dumps(show), encoding="utf-8")
            command = [
                str(self.bpfopt),
                "--pass",
                "map_inline",
                "--input",
                str(input_path),
                "--output",
                str(output_path),
                "--report",
                str(report_path),
                "--prog-type",
                "tracepoint",
                "--",
                "--map-values",
                str(map_values),
                "--map-ids",
                "1",
                "--stability",
                "phase-stable",
                "--direct-array-map",
                "hot_data",
            ]
            completed = subprocess.run(
                command,
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            output = output_path.read_bytes()
            report = json.loads(report_path.read_text(encoding="utf-8"))
            helper_ids = [
                struct.unpack_from("<i", output, pc + 4)[0]
                for pc in range(0, len(output), 8)
                if output[pc] == BPF_CALL
            ]
            pseudo_sources = [
                output[pc + 1] >> 4
                for pc in range(0, len(output), 8)
                if output[pc] == BPF_LD_IMM64
            ]
            self.assertNotIn(1, helper_ids, completed.stderr)
            self.assertIn(BPF_PSEUDO_MAP_IDX_VALUE, pseudo_sources)
            self.assertEqual(report["sites_applied"], 1)
            self.assertEqual(
                report["inlined_map_entries"][0]["stability"],
                "direct-location",
            )

            show["max_entries"] = 2
            show_path.write_text(json.dumps(show), encoding="utf-8")
            rejected = subprocess.run(
                command,
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            self.assertEqual(rejected.returncode, 0, rejected.stderr)
            self.assertEqual(output_path.read_bytes(), b"".join(program))
            rejected_report = json.loads(report_path.read_text(encoding="utf-8"))
            self.assertEqual(rejected_report["sites_applied"], 0)

    def test_map_inline_guarded_rejects_assumed_hint_key(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            completed = self.run_map_inline(
                Path(tmp), "guarded", assume_hint_key=True
            )
        self.assertNotEqual(completed.returncode, 0)
        self.assertIn(
            "--assume-hint-key requires --stability phase-stable",
            completed.stderr,
        )

    def test_map_inline_phase_stable_folds_sparse_field_from_large_value(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            input_path = workdir / "map-input.bin"
            output_path = workdir / "map-output.bin"
            report_path = workdir / "map-report.json"
            map_values = workdir / "map-values"
            map_values.mkdir()
            write_program(
                input_path,
                [
                    insn(BPF_STW, dst=10, off=-4, imm=0),
                    insn(BPF_LD_IMM64, dst=1, src=BPF_PSEUDO_MAP_IDX, imm=0),
                    insn(0),
                    insn(BPF_MOV64_X, dst=2, src=10),
                    insn(BPF_ADD64_K, dst=2, imm=-4),
                    insn(BPF_CALL, imm=1),
                    insn(BPF_JEQ64_K, dst=0, off=1, imm=0),
                    insn(BPF_LDXH, dst=0, src=0, off=14),
                    insn(BPF_EXIT),
                ],
            )
            value = bytearray(272)
            value[14:16] = b"\x34\x12"
            (map_values / "map-1.show.json").write_text(
                json.dumps(
                    {
                        "id": 1,
                        "name": "config_map",
                        "type": "array",
                        "bytes_key": 4,
                        "bytes_value": len(value),
                        "flags": 1 << 7,
                    }
                ),
                encoding="utf-8",
            )
            (map_values / "map-1.dump.json").write_text(
                json.dumps(
                    [
                        {
                            "key": ["0x00", "0x00", "0x00", "0x00"],
                            "value": [f"0x{byte:02x}" for byte in value],
                        }
                    ]
                ),
                encoding="utf-8",
            )
            completed = subprocess.run(
                [
                    str(self.bpfopt),
                    "--pass",
                    "map_inline",
                    "--input",
                    str(input_path),
                    "--output",
                    str(output_path),
                    "--report",
                    str(report_path),
                    "--prog-type",
                    "xdp",
                    "--",
                    "--map-values",
                    str(map_values),
                    "--map-ids",
                    "1",
                    "--stability",
                    "phase-stable",
                ],
                env={**os.environ, "BPFOPT_DUMP_IR": "1"},
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            output = output_path.read_bytes()
            report = json.loads(report_path.read_text(encoding="utf-8"))

        helper_ids = [
            struct.unpack_from("<i", output, pc + 4)[0]
            for pc in range(0, len(output), 8)
            if output[pc] == BPF_CALL
        ]
        immediates = [
            struct.unpack_from("<i", output, pc + 4)[0]
            for pc in range(0, len(output), 8)
        ]
        self.assertNotIn(1, helper_ids, completed.stderr)
        self.assertIn(0x1234, immediates)
        self.assertEqual(report["sites_applied"], 1)
        self.assertEqual(
            report["inlined_map_entries"][0]["stability"], "phase-stable"
        )

    def test_map_inline_phase_stable_folds_pseudo_map_value_load(self) -> None:
        """Detect missed libbpf .rodata/config loads after map relocation."""
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            input_path = workdir / "map-input.bin"
            output_path = workdir / "map-output.bin"
            report_path = workdir / "map-report.json"
            map_values = workdir / "map-values"
            map_values.mkdir()
            program = [
                insn(
                    BPF_LD_IMM64,
                    dst=1,
                    src=BPF_PSEUDO_MAP_IDX_VALUE,
                    imm=0,
                ),
                insn(0, imm=4),
                insn(BPF_LDXB, dst=0, src=1, off=3),
                insn(BPF_EXIT),
            ]
            write_program(input_path, program)
            value = bytearray(16)
            value[7] = 0x2A
            (map_values / "map-1.show.json").write_text(
                json.dumps(
                    {
                        "id": 1,
                        "name": "bcc.rodata",
                        "type": "array",
                        "bytes_key": 4,
                        "bytes_value": len(value),
                        "flags": 1 << 7,
                    }
                ),
                encoding="utf-8",
            )
            (map_values / "map-1.dump.json").write_text(
                json.dumps(
                    [
                        {
                            "key": ["0x00", "0x00", "0x00", "0x00"],
                            "value": [f"0x{byte:02x}" for byte in value],
                        }
                    ]
                ),
                encoding="utf-8",
            )
            command = [
                str(self.bpfopt),
                "--pass",
                "map_inline",
                "--input",
                str(input_path),
                "--output",
                str(output_path),
                "--report",
                str(report_path),
                "--prog-type",
                "kprobe",
                "--",
                "--map-values",
                str(map_values),
                "--map-ids",
                "1",
                "--stability",
                "phase-stable",
            ]
            completed = subprocess.run(
                command,
                env={**os.environ, "BPFOPT_DUMP_IR": "1"},
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            self.assertEqual(completed.returncode, 0, completed.stderr)
            output = output_path.read_bytes()
            report = json.loads(report_path.read_text(encoding="utf-8"))
            guarded = subprocess.run(
                [*command[:-1], "guarded"],
                env={**os.environ, "BPFOPT_DUMP_IR": "1"},
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            self.assertEqual(guarded.returncode, 0, guarded.stderr)
            guarded_output = output_path.read_bytes()
            guarded_report = json.loads(
                report_path.read_text(encoding="utf-8")
            )

        immediates = [
            struct.unpack_from("<i", output, pc + 4)[0]
            for pc in range(0, len(output), 8)
        ]
        self.assertEqual(report["sites_applied"], 1, completed.stderr)
        self.assertIn(0x2A, immediates, completed.stderr)
        self.assertNotIn(BPF_PSEUDO_MAP_IDX_VALUE, [
            output[pc + 1] >> 4 for pc in range(0, len(output), 8)
            if output[pc] == BPF_LD_IMM64
        ], completed.stderr)
        self.assertEqual(guarded_output, b"".join(program), guarded.stderr)
        self.assertEqual(guarded_report["sites_applied"], 0, guarded.stderr)

    def test_empty_admission_profile_is_a_successful_unchanged_pass(self) -> None:
        cases = {
            "tail_call_icache": {"per_site": {}},
            "hot_region_version": {"per_site": {}},
            "loop_trip_spec": {"per_loop": {}},
            "context_specialize": {"fields": []},
        }
        program = [insn(BPF_MOV64_K, dst=0, imm=2), insn(BPF_EXIT)]
        for pass_name, payload in cases.items():
            with self.subTest(pass_name=pass_name), tempfile.TemporaryDirectory() as tmp:
                profile = {
                    "schema_version": 1,
                    "pass": pass_name,
                    **payload,
                }
                output, report, _ = self.run_pass(
                    Path(tmp), pass_name, profile, program
                )
                self.assertEqual(output, b"".join(program))
                self.assertEqual(report["sites_matched"], 0)
                self.assertEqual(report["sites_applied"], 0)
                self.assertEqual(report["sites_skipped"], 0)

    def test_profile_hash_must_match_shim_program_identity(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            workdir = Path(tmp)
            input_path = workdir / "input.bin"
            output_path = workdir / "output.bin"
            report_path = workdir / "report.json"
            profile_path = workdir / "profile.json"
            write_program(
                input_path,
                [insn(BPF_MOV64_K, dst=0, imm=2), insn(BPF_EXIT)],
            )
            profile_path.write_text(
                json.dumps(
                    {
                        "schema_version": 1,
                        "pass": "tail_call_icache",
                        "program_hash": "fedcba9876543210",
                        "per_site": {},
                    }
                ),
                encoding="utf-8",
            )
            completed = subprocess.run(
                [
                    str(self.bpfopt),
                    "--pass",
                    "tail_call_icache",
                    "--input",
                    str(input_path),
                    "--output",
                    str(output_path),
                    "--report",
                    str(report_path),
                    "--prog-type",
                    "xdp",
                    "--",
                    "--profile",
                    str(profile_path),
                    "--program-hash",
                    TEST_PROGRAM_HASH,
                ],
                check=False,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
        self.assertNotEqual(completed.returncode, 0)
        self.assertIn(
            "program_hash is fedcba9876543210, expected 0123456789abcdef",
            completed.stderr,
        )


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise RuntimeError("expected bpfopt path")
    BPFOPT_PATH = Path(sys.argv[1]).resolve()
    sys.argv = [sys.argv[0]]
    unittest.main()
