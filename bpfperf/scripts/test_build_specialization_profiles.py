#!/usr/bin/env python3

from __future__ import annotations

import importlib.util
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest


SCRIPT = Path(__file__).with_name("build_specialization_profiles.py")
SPEC = importlib.util.spec_from_file_location("build_specialization_profiles", SCRIPT)
assert SPEC is not None and SPEC.loader is not None
MODULE = importlib.util.module_from_spec(SPEC)
sys.modules[SPEC.name] = MODULE
SPEC.loader.exec_module(MODULE)


def insn(code: int, dst: int = 0, src: int = 0, off: int = 0, imm: int = 0) -> bytes:
    return struct.pack("<BBhi", code, dst | (src << 4), off, imm)


class SpecializationProfileBuilderTests(unittest.TestCase):
    def setUp(self) -> None:
        self.admission = MODULE.Admission(
            min_observations=100,
            min_hot_permille=800,
            max_tail_sites=2,
            max_loop_sites=2,
            max_context_fields=2,
        )
        self.raw = {
            "prog_id": 17,
            "per_site": {
                "1": {
                    "branch_count": 1000,
                    "branch_misses": 100,
                    "miss_rate": 0.1,
                    "taken": 900,
                    "not_taken": 100,
                },
                "5": {
                    "branch_count": 1000,
                    "branch_misses": 100,
                    "miss_rate": 0.1,
                    "taken": 750,
                    "not_taken": 250,
                }
            },
            "tail_call_sites": {
                "4": {
                    "observations": 1000,
                    "key_counts": {"7": 900, "9": 100},
                }
            },
        }
    def parse_insns(self, raw: bytes):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "program.bin"
            path.write_bytes(raw)
            return MODULE.load_bytecode(path)

    def test_builds_all_observation_driven_profiles(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x61, dst=2, src=1, off=16),
                    insn(0x15, dst=2, off=1, imm=7),
                    insn(0xB7, dst=0, imm=1),
                    insn(0xB7, dst=3, imm=0),
                    insn(0x07, dst=3, imm=1),
                    insn(0xA5, dst=3, off=-2, imm=4),
                    insn(0x95),
                ]
            )
        )
        profiles = MODULE.build_profiles(
            self.raw,
            program,
            "0123456789abcdef",
            list(MODULE.PASS_NAMES),
            self.admission,
        )

        self.assertEqual(
            profiles["tail_call_icache"]["per_site"]["4"]["keys"],
            [{"key": 7, "count": 900}, {"key": 9, "count": 100}],
        )
        self.assertEqual(
            profiles["hot_region_version"]["per_site"]["1"]["taken"], 900
        )
        loop = profiles["loop_trip_spec"]["per_loop"]["4"]
        self.assertEqual(loop["trip_count"], 4)
        self.assertEqual(loop["latch_pc"], 5)
        self.assertEqual(loop["backedge_count"], 750)
        self.assertEqual(loop["exit_count"], 250)
        self.assertEqual(
            profiles["context_specialize"]["fields"],
            [
                {
                    "kind": "context",
                    "source": "pmu_branch",
                    "offset": 16,
                    "width": 4,
                    "hot_value": 7,
                    "observations": 1000,
                    "hot_count": 900,
                    "load_pcs": [0],
                }
            ],
        )
        self.assertEqual(
            profiles["branch_flip"]["per_site"]["1"],
            {
                "branch_count": 1000,
                "branch_misses": 100,
                "miss_rate": 0.1,
                "taken": 900,
                "not_taken": 100,
            },
        )

    def test_hot_region_profile_admits_multiple_roots(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x61, dst=2, src=1, off=16),
                    insn(0x15, dst=2, off=1, imm=7),
                    insn(0xB7, dst=0, imm=1),
                    insn(0xB7, dst=3, imm=0),
                    insn(0x07, dst=3, imm=1),
                    insn(0xA5, dst=3, off=-2, imm=4),
                    insn(0x95),
                ]
            )
        )
        admission = MODULE.Admission(
            min_observations=100,
            min_hot_permille=700,
            max_tail_sites=2,
            max_loop_sites=2,
            max_context_fields=2,
            max_hot_roots=4,
        )

        profile = MODULE.build_hot_region_profile(
            self.raw, program, "0123456789abcdef", admission
        )

        self.assertEqual(list(profile["per_site"]), ["1", "5"])

    def test_tail_profile_omits_already_constant_key(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xB7, dst=3, imm=7),
                    insn(0x85, imm=12),
                    insn(0x95),
                ]
            )
        )
        raw = {
            "prog_id": 17,
            "tail_call_sites": {
                "1": {"observations": 1000, "key_counts": {"7": 1000}}
            },
        }

        profile = MODULE.build_tail_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(profile["per_site"], {})

    def test_tail_profile_admits_top_k_by_cumulative_coverage(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xB7, dst=3, imm=0),
                    insn(0x0F, dst=3, src=2),
                    insn(0x85, imm=12),
                    insn(0x95),
                ]
            )
        )
        raw = {
            "prog_id": 17,
            "tail_call_sites": {
                "2": {
                    "observations": 1000,
                    "key_counts": {"0": 550, "2": 450},
                }
            },
        }

        profile = MODULE.build_tail_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(
            profile["per_site"]["2"]["keys"],
            [{"key": 0, "count": 550}, {"key": 2, "count": 450}],
        )

    def test_tail_profile_rejects_pmu_key_that_contradicts_static_key(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xB4, dst=3, imm=7),
                    insn(0x85, imm=12),
                    insn(0x95),
                ]
            )
        )
        raw = {
            "prog_id": 17,
            "tail_call_sites": {
                "1": {"observations": 1000, "key_counts": {"9": 1000}}
            },
        }

        with self.assertRaisesRegex(MODULE.ProfileError, "contradict static key 7"):
            MODULE.build_tail_profile(
                raw, program, "0123456789abcdef", self.admission
            )

    def test_context_ne_fallthrough_proves_equality(self) -> None:
        raw = {
            "prog_id": 1,
            "per_site": {
                "1": {"branch_count": 500, "taken": 20, "not_taken": 480}
            },
        }
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x71, dst=3, src=1, off=9),
                    insn(0x55, dst=3, off=1, imm=6),
                    insn(0xB7, dst=0, imm=1),
                    insn(0x95),
                ]
            )
        )

        profile = MODULE.build_context_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(profile["fields"][0]["offset"], 9)
        self.assertEqual(profile["fields"][0]["width"], 1)
        self.assertEqual(profile["fields"][0]["hot_value"], 6)
        self.assertEqual(profile["fields"][0]["hot_count"], 480)

    def test_packet_context_hint_keeps_wire_bytes_and_exact_load_pc(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=6, src=1),
                    insn(0x61, dst=7, src=6, off=0),
                    insn(0x71, dst=2, src=7, off=23),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 23,
                    "width": 1,
                    "hot_bytes_hex": "11",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [2],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        field = profile["fields"][0]
        self.assertEqual(field["hot_bytes_hex"], "11")
        self.assertEqual(field["load_pcs"], [2])
        self.assertNotIn("observations", field)
        self.assertNotIn("hot_count", field)

    def test_packet_context_hint_follows_packet_pointer_stack_spill(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=6, src=1),
                    insn(0x61, dst=7, src=6, off=0),
                    insn(0x7B, dst=10, src=7, off=-8),
                    insn(0xB7, dst=7, imm=0),
                    insn(0x79, dst=7, src=10, off=-8),
                    insn(0x71, dst=2, src=7, off=23),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 23,
                    "width": 1,
                    "hot_bytes_hex": "11",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [5],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        self.assertEqual(profile["fields"][0]["load_offsets"], [23])

    def test_context_hint_accepts_multiple_proven_exact_loads(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=6, src=1),
                    insn(0x61, dst=2, src=6, off=16),
                    insn(0x61, dst=3, src=1, off=16),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 16,
                    "width": 4,
                    "hot_value": 8,
                    "load_pcs": [1, 2],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        self.assertEqual(profile["fields"][0]["load_pcs"], [1, 2])

    def test_packet_context_versions_reuse_load_site_with_distinct_values(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=6, src=1),
                    insn(0x61, dst=7, src=6, off=0),
                    insn(0x69, dst=2, src=7, off=34),
                    insn(0x95),
                ]
            )
        )
        hints = [
            MODULE.parse_context_field_hint(
                json.dumps(
                    {
                        "kind": "packet",
                        "source": "deployment_hint",
                        "version": version,
                        "offset": 34,
                        "width": 2,
                        "hot_bytes_hex": hot_bytes,
                        "context_data_offset": 0,
                        "context_data_end_offset": 4,
                        "load_pcs": [2],
                    }
                )
            )
            for version, hot_bytes in ((0, "2710"), (1, "2711"))
        ]

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            hints,
        )

        self.assertNotIn("fields", profile)
        self.assertEqual(
            [version["fields"][0]["hot_bytes_hex"] for version in profile["versions"]],
            ["2710", "2711"],
        )

    def test_packet_context_hint_proves_branch_correlated_dynamic_offset(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x61, dst=7, src=1, off=0),
                    insn(0xB7, dst=2, imm=0),
                    insn(0xB7, dst=4, imm=34),
                    insn(0x15, dst=2, off=1, imm=0),
                    insn(0xB7, dst=4, imm=62),
                    insn(0xBF, dst=3, src=7),
                    insn(0x0F, dst=3, src=4),
                    insn(0x55, dst=2, off=1, imm=0),
                    insn(0x69, dst=5, src=3, off=0),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 34,
                    "width": 2,
                    "hot_bytes_hex": "2710",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [8],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        self.assertEqual(profile["fields"][0]["load_offsets"], [34])

    def test_packet_context_hint_rejects_ambiguous_dynamic_offset(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x61, dst=7, src=1, off=0),
                    insn(0x71, dst=2, src=1, off=8),
                    insn(0xB7, dst=4, imm=34),
                    insn(0x15, dst=2, off=1, imm=0),
                    insn(0xB7, dst=4, imm=62),
                    insn(0xBF, dst=3, src=7),
                    insn(0x0F, dst=3, src=4),
                    insn(0x69, dst=5, src=3, off=0),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 34,
                    "width": 2,
                    "hot_bytes_hex": "2710",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [7],
                }
            )
        )

        with self.assertRaisesRegex(MODULE.ProfileError, "packet provenance"):
            MODULE.build_context_profile(
                {"prog_id": 17, "per_site": {}},
                program,
                "0123456789abcdef",
                self.admission,
                [hint],
            )

    def test_packet_context_hint_rejects_changed_packet_epoch(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=6, src=1),
                    insn(0x61, dst=7, src=6, off=0),
                    insn(0x72, dst=7, off=23, imm=0),
                    insn(0x71, dst=2, src=7, off=23),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "packet",
                    "source": "deployment_hint",
                    "offset": 23,
                    "width": 1,
                    "hot_bytes_hex": "11",
                    "context_data_offset": 0,
                    "context_data_end_offset": 4,
                    "load_pcs": [3],
                }
            )
        )

        with self.assertRaisesRegex(MODULE.ProfileError, "packet epoch"):
            MODULE.build_context_profile(
                {"prog_id": 17, "per_site": {}},
                program,
                "0123456789abcdef",
                self.admission,
                [hint],
            )

    def test_generic_context_hint_keeps_entry_context_provenance(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=8, src=1),
                    insn(0x85, imm=14),
                    insn(0x79, dst=2, src=8, off=8),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 8,
                    "width": 8,
                    "hot_value": 202,
                    "load_pcs": [2],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        self.assertEqual(
            profile["fields"],
            [
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 8,
                    "width": 8,
                    "hot_value": 202,
                    "load_pcs": [2],
                }
            ],
        )

    def test_generic_context_hint_follows_callee_saved_stack_spill(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0xBF, dst=8, src=1),
                    insn(0x7B, dst=10, src=8, off=-8),
                    insn(0xB7, dst=8, imm=0),
                    insn(0x79, dst=8, src=10, off=-8),
                    insn(0x85, imm=14),
                    insn(0x79, dst=2, src=8, off=8),
                    insn(0x95),
                ]
            )
        )
        hint = MODULE.parse_context_field_hint(
            json.dumps(
                {
                    "kind": "context",
                    "source": "deployment_hint",
                    "offset": 8,
                    "width": 8,
                    "hot_value": 202,
                    "load_pcs": [5],
                }
            )
        )

        profile = MODULE.build_context_profile(
            {"prog_id": 17, "per_site": {}},
            program,
            "0123456789abcdef",
            self.admission,
            [hint],
        )

        self.assertEqual(profile["fields"][0]["load_pcs"], [5])

    def test_packet_context_hint_requires_explicit_source(self) -> None:
        with self.assertRaisesRegex(MODULE.ProfileError, "missing keys: source"):
            MODULE.parse_context_field_hint(
                json.dumps(
                    {
                        "kind": "packet",
                        "offset": 23,
                        "width": 1,
                        "hot_bytes_hex": "11",
                        "context_data_offset": 0,
                        "context_data_end_offset": 4,
                        "load_pcs": [2],
                    }
                )
            )

    def test_below_admission_threshold_writes_explicit_empty_sets(self) -> None:
        admission = MODULE.Admission(2000, 950, 1, 1, 1)
        program = self.parse_insns(insn(0xB7, dst=0, imm=1) + insn(0x95))

        profiles = MODULE.build_profiles(
            self.raw,
            program,
            "0123456789abcdef",
            [name for name in MODULE.PASS_NAMES if name != "branch_flip"],
            admission,
        )

        self.assertEqual(profiles["tail_call_icache"]["per_site"], {})
        self.assertEqual(profiles["hot_region_version"]["per_site"], {})
        self.assertEqual(profiles["loop_trip_spec"]["per_loop"], {})
        self.assertEqual(profiles["context_specialize"]["fields"], [])

    def test_rejects_inconsistent_raw_histograms(self) -> None:
        self.raw["tail_call_sites"]["4"]["observations"] = 999

        with self.assertRaisesRegex(MODULE.ProfileError, "disagree"):
            MODULE.build_tail_profile(
                self.raw,
                self.parse_insns(insn(0xB7) + insn(0x95)),
                "0123456789abcdef",
                self.admission,
            )

    def test_specialization_candidates_exclude_unlifted_subprogram_tail(self) -> None:
        program = self.parse_insns(
            b"".join(
                [
                    insn(0x85, src=1, imm=2),
                    insn(0x15, dst=0, off=1, imm=0),
                    insn(0x95),
                    insn(0xB7, dst=0, imm=0),
                    insn(0x15, dst=0, off=1, imm=0),
                    insn(0x95),
                    insn(0x95),
                ]
            )
        )
        raw = {
            "prog_id": 17,
            "per_site": {
                "1": {
                    "branch_count": 1000,
                    "branch_misses": 10,
                    "taken": 900,
                    "not_taken": 100,
                },
                "4": {
                    "branch_count": 10000,
                    "branch_misses": 10,
                    "taken": 9900,
                    "not_taken": 100,
                },
            },
            "tail_call_sites": {
                "4": {"observations": 1000, "key_counts": {"7": 1000}}
            },
        }

        hot = MODULE.build_hot_region_profile(
            raw, program, "0123456789abcdef", self.admission
        )
        tail = MODULE.build_tail_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(list(hot["per_site"]), ["1"])
        self.assertEqual(tail["per_site"], {})

    def test_writes_hash_addressed_profiles(self) -> None:
        profile = {
            "tail_call_icache": {
                "schema_version": 1,
                "pass": "tail_call_icache",
                "per_site": {},
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            MODULE.write_profiles(root, "0123456789abcdef", profile)
            path = root / "tail_call_icache" / "hash-0123456789abcdef.json"
            value = json.loads(path.read_text(encoding="utf-8"))
        self.assertEqual(value["pass"], "tail_call_icache")

    def test_writes_program_instance_addressed_profiles(self) -> None:
        profile = {
            "tail_call_icache": {
                "schema_version": 1,
                "pass": "tail_call_icache",
                "per_site": {},
            }
        }
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            MODULE.write_profiles(
                root,
                "0123456789abcdef",
                profile,
                output_stem="prog-17",
            )
            path = root / "tail_call_icache" / "prog-17.json"
            value = json.loads(path.read_text(encoding="utf-8"))
        self.assertEqual(value["pass"], "tail_call_icache")

    def test_merges_duplicate_program_hash_observations_before_admission(self) -> None:
        first = json.loads(json.dumps(self.raw))
        second = json.loads(json.dumps(self.raw))
        second["prog_id"] = 18

        merged = MODULE.merge_raw_profiles([first, second])

        self.assertEqual(merged["source_prog_ids"], [17, 18])
        self.assertEqual(merged["per_site"]["1"]["branch_count"], 2000)
        self.assertEqual(
            merged["tail_call_sites"]["4"]["key_counts"],
            {"7": 1800, "9": 200},
        )
        self.assertEqual(merged["per_site"]["5"]["branch_count"], 2000)

    def test_loop_profile_treats_missing_sampled_latch_as_noncandidate(self) -> None:
        program = self.parse_insns(
            insn(0xB7, dst=0, imm=0)
            + insn(0x07, dst=0, imm=1)
            + insn(0xA5, dst=0, off=-2, imm=4)
            + insn(0x95)
        )
        raw = {"prog_id": 17, "per_site": {}}

        profile = MODULE.build_loop_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(profile["per_loop"], {})

    def test_loop_profile_excludes_multiple_latches_for_one_header(self) -> None:
        program = self.parse_insns(
            insn(0xB7, dst=0, imm=0)
            + insn(0x15, dst=0, off=2, imm=0)
            + insn(0x07, dst=0, imm=1)
            + insn(0x55, dst=0, off=-3, imm=8)
            + insn(0x07, dst=0, imm=1)
            + insn(0x55, dst=0, off=-5, imm=8)
            + insn(0x95)
        )
        raw = {
            "prog_id": 17,
            "per_site": {
                "3": {"branch_count": 100, "taken": 75, "not_taken": 25},
                "5": {"branch_count": 100, "taken": 75, "not_taken": 25},
            },
        }

        profile = MODULE.build_loop_profile(
            raw, program, "0123456789abcdef", self.admission
        )

        self.assertEqual(profile["per_loop"], {})

    def test_branch_flip_rejects_missing_conditional_site(self) -> None:
        program = self.parse_insns(
            insn(0x15, dst=0, off=1, imm=0) + insn(0x95) + insn(0x95)
        )
        raw = {"prog_id": 17, "per_site": {}}

        with self.assertRaisesRegex(MODULE.ProfileError, "omitted conditional sites"):
            MODULE.build_branch_flip_profile(
                raw, program, "0123456789abcdef"
            )

    def test_branch_flip_rejects_all_zero_pmu_for_running_program(self) -> None:
        program = self.parse_insns(
            insn(0x15, dst=0, off=1, imm=0) + insn(0x95) + insn(0x95)
        )
        raw = {
            "prog_id": 17,
            "run_cnt_delta": 1000,
            "per_site": {
                "0": {
                    "branch_count": 0,
                    "branch_misses": 0,
                    "taken": 0,
                    "not_taken": 0,
                }
            },
        }

        with self.assertRaisesRegex(MODULE.ProfileError, "zero branch observations"):
            MODULE.build_branch_flip_profile(
                raw, program, "0123456789abcdef"
            )

    def test_branch_flip_preserves_crossing_independent_pmu_samples(self) -> None:
        program = self.parse_insns(
            insn(0x15, dst=0, off=1, imm=0) + insn(0x95) + insn(0x95)
        )
        raw = {
            "prog_id": 17,
            "run_cnt_delta": 1000,
            "per_site": {
                "0": {
                    "branch_count": 1,
                    "branch_misses": 2,
                    "taken": 1,
                    "not_taken": 0,
                }
            },
        }

        profile = MODULE.build_branch_flip_profile(
            raw, program, "0123456789abcdef"
        )

        self.assertEqual(profile["per_site"]["0"]["branch_count"], 1)
        self.assertEqual(profile["per_site"]["0"]["branch_misses"], 2)
        self.assertEqual(profile["per_site"]["0"]["miss_rate"], 1.0)


if __name__ == "__main__":
    unittest.main()
