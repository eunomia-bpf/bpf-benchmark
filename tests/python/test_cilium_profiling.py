from __future__ import annotations

import importlib.util
import json
import tempfile
import unittest
from pathlib import Path

from corpus.profiling import host


REPORT_PATH = Path(__file__).resolve().parents[2] / "analysis" / "cilium_profile_report.py"
SPEC = importlib.util.spec_from_file_location("cilium_profile_report", REPORT_PATH)
assert SPEC is not None and SPEC.loader is not None
report = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(report)


class HybridPmuSelectionTest(unittest.TestCase):
    """Catch counting P-core events while agent 2's guest runs on E-cores."""

    def test_selects_atom_pmu_for_agent2_cpu_set(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            (root / "cpu_core").mkdir()
            (root / "cpu_core" / "cpus").write_text("0-7\n")
            (root / "cpu_atom").mkdir()
            (root / "cpu_atom" / "cpus").write_text("8-23\n")
            self.assertEqual(host._resolve_pmu("16-19", root), "cpu_atom")

    def test_rejects_cpu_set_crossing_hybrid_pmus(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            (root / "cpu_core").mkdir()
            (root / "cpu_core" / "cpus").write_text("0-7\n")
            (root / "cpu_atom").mkdir()
            (root / "cpu_atom" / "cpus").write_text("8-23\n")
            with self.assertRaisesRegex(RuntimeError, "exactly one PMU"):
                host._resolve_pmu("7-8", root)

    def test_rejects_cpu_set_outside_agent2_allocation(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "agent 2's CPUs 16-19"):
            host._validate_cpu_allocation("0-3")
        host._validate_cpu_allocation("16,17-19")


class MarkerAndCommandTest(unittest.TestCase):
    """Catch host counters spanning the wrong corpus app or phase."""

    def test_marker_requires_cilium_and_selected_phase(self) -> None:
        line = json.dumps(
            {
                "event": "measurement_start",
                "app": "cilium/agent",
                "phase": "post_rejit",
            }
        )
        self.assertEqual(host._progress_marker(line, "post_rejit"), "measurement_start")
        self.assertIsNone(host._progress_marker(line, "baseline"))
        self.assertIsNone(
            host._progress_marker(
                '{"event":"measurement_start","app":"katran","phase":"post_rejit"}',
                "post_rejit",
            )
        )

    def test_make_command_obeys_agent2_guest_limit(self) -> None:
        command = host._make_command(
            cpus="16-19",
            guest_script=Path("/results/profile/.profile-code/run-jit.sh"),
        )
        self.assertEqual(command[:3], ["taskset", "-c", "16-19"])
        self.assertIn("-o", command)
        self.assertIn("x86-runner-runtime-image-tar", command)
        self.assertIn("__profile-cilium-vm", command)
        self.assertIn("VM_CPU_PIN=", command)
        self.assertIn("VM_CPUS=4", command)
        self.assertIn("VM_MEM=16G", command)
        self.assertIn(
            "CILIUM_PROFILE_GUEST_SCRIPT=/results/profile/.profile-code/run-jit.sh",
            command,
        )
        self.assertLess(len(" ".join(command)), 512)

    def test_guest_code_is_staged_without_runtime_image_change(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            destination = Path(raw) / "code"
            host._stage_profile_code(destination)
            package = destination / "corpus" / "profiling"
            self.assertEqual(
                sorted(path.name for path in package.iterdir()),
                ["__init__.py", "guest.py", "perf_control.py"],
            )

    def test_staged_guest_script_carries_profile_environment(self) -> None:
        command = host._guest_make_command(
            arm="jit",
            duration=5,
            output_dir=Path("/results/profile/jit"),
            perf_root=Path("/results/profile/.perf-tools"),
            code_root=Path("/results/profile/.profile-code"),
        )
        self.assertIn("BPFREJIT_CORPUS_APPS=cilium/agent", command)
        self.assertIn("BPFREJIT_CORPUS_BPF_STATS=1", command)
        self.assertIn("CILIUM_PROFILE_CODE_ROOT=/results/profile/.profile-code", command)
        with tempfile.TemporaryDirectory() as raw:
            script = Path(raw) / "run.sh"
            host._stage_guest_script(script, command)
            self.assertTrue(script.stat().st_mode & 0o100)
            self.assertIn("exec make -C", script.read_text(encoding="utf-8"))

    def test_profile_output_must_be_in_mounted_result_tree(self) -> None:
        selected = host.RESULT_ROOT / "profile-test"
        self.assertEqual(host._resolve_profile_root(str(selected)), selected)
        with self.assertRaisesRegex(RuntimeError, "must be below"):
            host._resolve_profile_root("/tmp/profile-test")


class ReportParsingTest(unittest.TestCase):
    """Catch lost callgraphs and misclassified datapath samples."""

    def test_perf_script_leaf_and_callchain_parsing(self) -> None:
        text = """ffffffffc0010010 bpf_prog_deadbeef_cil_from_host
        ffffffff81001000 __netif_receive_skb
        ffffffff81002000 net_rx_action

ffffffff81003000 htab_map_lookup_elem
        ffffffffc0010010 bpf_prog_deadbeef_cil_from_host

"""
        counts, callgraphs = report.parse_perf_script(text)
        self.assertEqual(counts["bpf_prog_deadbeef_cil_from_host"], 1)
        self.assertEqual(counts["htab_map_lookup_elem"], 1)
        self.assertEqual(len(callgraphs[0]), 3)
        self.assertEqual(report.classify_symbol("bpf_prog_deadbeef_cil_from_host"), "bpf_code")
        self.assertEqual(report.classify_symbol("bpf_kinsn_memcpy"), "bpf_code")
        self.assertEqual(report.classify_symbol("htab_map_lookup_elem"), "maps")
        self.assertEqual(report.classify_symbol("bpf_redirect"), "helpers")
        report.validate_callgraph_samples(counts, callgraphs)

    def test_perf_samples_reject_unknown_only_or_leaf_only_data(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "no resolved leaf"):
            report.validate_callgraph_samples({"[unknown]": 5}, [["[unknown]"]])
        with self.assertRaisesRegex(RuntimeError, "no callchain"):
            report.validate_callgraph_samples(
                {"bpf_prog_deadbeef_cil_from_host": 5},
                [["bpf_prog_deadbeef_cil_from_host"]],
            )
        with self.assertRaisesRegex(RuntimeError, "no BPF-code leaf"):
            report.validate_callgraph_samples(
                {"net_rx_action": 5}, [["net_rx_action", "do_softirq"]]
            )

    def test_perf_stat_rejects_missing_event(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            path = Path(raw) / "stat.csv"
            path.write_text(
                "1,,cpu_atom/cpu-cycles/G,1,100.00,,\n"
                "2,,cpu_atom/instructions/G,1,100.00,,\n"
            )
            with self.assertRaisesRegex(RuntimeError, "missing counters"):
                report.parse_perf_stat(path)

    def test_native_size_parser_requires_original_native_pair(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            path = Path(raw) / "shim.log"
            path.write_text(
                "native-loader jit-info original fd=1 id=10 type=3 name=cil tag=aa "
                "jited_len=100 xlated_len=200 nr_jited_ksyms=1 ksym0=0x1 ksym1=0x0\n"
                "native-loader jit-info native fd=2 id=11 type=3 name=cil tag=bb "
                "jited_len=80 xlated_len=16 nr_jited_ksyms=1 ksym0=0x2 ksym1=0x0\n"
                "native-loader timings prog=cil cache_hit=1 prebuilt_proof=1 "
                "original_id=10 native_id=11 symbol=cil native_object=x "
                "bpf_bytes=200 native_bytes=70 total_ns=1\n"
            )
            rows = report._native_sizes(path)
            self.assertEqual(rows[0]["jit_image_bytes"], 100)
            self.assertEqual(rows[0]["native_blob_bytes"], 70)
            self.assertEqual(rows[0]["native_stub_image_bytes"], 80)

    def test_native_size_coverage_rejects_unpaired_program(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "program IDs: \\[12\\]"):
            report._require_native_size_coverage(
                [{"id": 11}, {"id": 12}], [{"native_id": 11}]
            )


if __name__ == "__main__":
    unittest.main()
