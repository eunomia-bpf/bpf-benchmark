from __future__ import annotations

import gzip
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path
from unittest import mock

from corpus.profiling import guest, host


REPORT_PATH = Path(__file__).resolve().parents[2] / "analysis" / "cilium_profile_report.py"
SPEC = importlib.util.spec_from_file_location("cilium_profile_report", REPORT_PATH)
assert SPEC is not None and SPEC.loader is not None
report = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(report)


class HybridPmuSelectionTest(unittest.TestCase):
    """Catch collecting timing profiles on the wrong hybrid-core PMU."""

    def test_selects_core_pmu_for_timing_cpu_set(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            (root / "cpu_core").mkdir()
            (root / "cpu_core" / "cpus").write_text("0-7\n")
            (root / "cpu_atom").mkdir()
            (root / "cpu_atom" / "cpus").write_text("8-23\n")
            self.assertEqual(host._resolve_pmu("0-7", root), "cpu_core")

    def test_rejects_cpu_set_crossing_hybrid_pmus(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            (root / "cpu_core").mkdir()
            (root / "cpu_core" / "cpus").write_text("0-7\n")
            (root / "cpu_atom").mkdir()
            (root / "cpu_atom" / "cpus").write_text("8-23\n")
            with self.assertRaisesRegex(RuntimeError, "exactly one PMU"):
                host._resolve_pmu("7-8", root)

    def test_rejects_cpu_set_outside_timing_allocation(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "timing CPUs 0-7"):
            host._validate_cpu_allocation("16-19")
        host._validate_cpu_allocation("0,1-7")


class MarkerAndCommandTest(unittest.TestCase):
    """Catch host counters spanning the wrong corpus app or phase."""

    def test_marker_requires_cilium_and_selected_phase(self) -> None:
        line = json.dumps(
            {
                "event": "profile_measurement_start",
                "app": "cilium/agent",
                "phase": "post_rejit",
            }
        )
        self.assertEqual(host._progress_marker(line, "post_rejit"), "measurement_start")
        self.assertIsNone(host._progress_marker(line, "baseline"))
        self.assertIsNone(
            host._progress_marker(
                '{"event":"profile_measurement_start","app":"katran",'
                '"phase":"post_rejit"}',
                "post_rejit",
            )
        )

    def test_all_selects_only_jit_and_whole_program_native(self) -> None:
        self.assertEqual(host._parse_arms("all"), ["jit", "kprog"])
        with self.assertRaisesRegex(RuntimeError, "unknown=.*kinsn"):
            host._parse_arms("kinsn")

    def test_both_orders_use_four_fresh_guest_runs(self) -> None:
        self.assertEqual(
            host._profile_plan(["jit", "kprog"], "both"),
            [
                {"run_id": "jit-kprog/01-jit", "order": "jit-kprog", "position": 1, "arm": "jit"},
                {"run_id": "jit-kprog/02-kprog", "order": "jit-kprog", "position": 2, "arm": "kprog"},
                {"run_id": "kprog-jit/01-kprog", "order": "kprog-jit", "position": 1, "arm": "kprog"},
                {"run_id": "kprog-jit/02-jit", "order": "kprog-jit", "position": 2, "arm": "jit"},
            ],
        )
        self.assertEqual(
            host._profile_plan(["jit"], "single")[0]["run_id"], "single/01-jit"
        )

    def test_guest_scan_matches_executable_not_package_argument(self) -> None:
        self.assertTrue(
            host._is_qemu_executable(Path("/usr/local/bin/qemu-system-x86_64"))
        )
        self.assertFalse(host._is_qemu_executable(Path("/usr/bin/apt-get")))
        self.assertIsNone(
            host._progress_marker(
                '{"event":"measurement_start","app":"cilium/agent",'
                '"phase":"post_rejit"}',
                "post_rejit",
            )
        )

    def test_make_command_matches_timing_guest(self) -> None:
        command = host._make_command(
            cpus="0-7",
            guest_script=Path("/results/profile/.profile-code/run-jit.sh"),
        )
        self.assertEqual(command[:3], ["taskset", "-c", "0-7"])
        self.assertIn("-o", command)
        self.assertIn("x86-runner-runtime-image-tar", command)
        self.assertIn("__profile-cilium-vm", command)
        self.assertIn("VM_CPU_PIN=0-7", command)
        self.assertIn("VM_CPUS=8", command)
        self.assertIn("VM_MEM=64G", command)
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
        self.assertIn("CILIUM_PROFILE_PERF_ROOT=/results/profile/.perf-tools", command)
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

    def test_record_uses_guest_local_storage_software_clock_and_frame_pointers(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            perf_root = Path(raw)
            (perf_root / "lib64").mkdir()
            (perf_root / "lib64" / "ld-linux-x86-64.so.2").touch()
            (perf_root / "usr/lib/linux-tools").mkdir(parents=True)
            (perf_root / "usr/lib/linux-tools/perf").touch()
            (perf_root / "usr/lib/libperf-test.so").touch()
            command = guest._perf_command(perf_root, Path("/var/tmp/work"))
        self.assertIn("cpu-clock:k", command)
        self.assertIn("1000000", command)
        self.assertEqual(command[command.index("--call-graph") + 1], "fp")
        self.assertNotIn("-j", command)
        self.assertEqual(
            command[command.index("-o") + 1], "/var/tmp/work/guest.perf.data"
        )
        control = next(item for item in command if item.startswith("--control="))
        self.assertNotIn("corpus/results", control)

    def test_symbol_snapshot_follows_workload_and_sampling_stop(self) -> None:
        events: list[str] = []

        def measure(**kwargs: object) -> dict[str, object]:
            self.assertEqual(kwargs, {"sample": 1})
            events.append("measure")
            return {"ok": True}

        collector = mock.Mock()
        collector.disable.side_effect = lambda: events.append("disable")
        with mock.patch.object(
            guest, "_print_profile_marker", side_effect=lambda *_: events.append("marker")
        ), mock.patch.object(
            guest, "_capture_symbols", side_effect=lambda *_: events.append("snapshot")
        ):
            result = guest._measure_stop_and_capture(
                measure, {"sample": 1}, collector, Path("/results"), "baseline"
            )
        self.assertEqual(result, {"ok": True})
        self.assertEqual(events, ["measure", "marker", "disable", "snapshot"])
        collector.disable.assert_called_once_with()

    def test_perf_data_is_published_only_after_driver_returns(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            local_data = Path(raw) / "local.perf.data"
            result_data = Path(raw) / "result" / "guest.perf.data"
            result_data.parent.mkdir()
            local_data.write_bytes(b"profile")

            def fake_driver_main(argv: list[str]) -> int:
                self.assertEqual(argv, [])
                self.assertFalse(result_data.exists())
                return 0

            with mock.patch.object(guest.driver, "main", side_effect=fake_driver_main):
                self.assertEqual(
                    guest._run_driver_then_publish(local_data, result_data), 0
                )
            self.assertEqual(result_data.read_bytes(), b"profile")
            self.assertFalse((result_data.parent / "guest.perf.data.tmp").exists())


class ReportParsingTest(unittest.TestCase):
    """Catch lost callgraphs and misclassified datapath samples."""

    def test_profile_text_artifacts_are_reproducible(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            report_path = root / "perf-report.txt"
            script_path = root / "perf-script.txt.gz"
            normalized = report._write_reproducible_text_artifacts(
                report_path,
                "row   \nblank\t\n",
                script_path,
                "sample\n",
            )
            first = script_path.read_bytes()
            report._write_reproducible_text_artifacts(
                report_path,
                "row   \nblank\t\n",
                script_path,
                "sample\n",
            )
            self.assertEqual(normalized, "row\nblank\n")
            self.assertEqual(report_path.read_text(encoding="utf-8"), normalized)
            self.assertEqual(script_path.read_bytes(), first)
            self.assertEqual(gzip.decompress(first), b"sample\n")
            self.assertEqual(first[4:8], b"\x00\x00\x00\x00")

    def test_perf_script_leaf_and_callchain_parsing(self) -> None:
        text = """ffffffffc0010010 bpf_prog_deadbeef_cil_from_host net_rx_action+0x1/bpf_prog_deadbeef_cil_from_host+0x2/P/-/-/3/CALL/-
        ffffffff81001000 __netif_receive_skb
        ffffffff81002000 net_rx_action

ffffffff81003000 _raw_spin_lock bpf_common_lru_pop_free+0x1/_raw_spin_lock+0x2/P/-/-/4/CALL/- htab_lru_map_update_elem+0x1/bpf_common_lru_pop_free+0x2/P/-/-/4/CALL/-
        ffffffffc0010010 bpf_prog_deadbeef_cil_from_host

"""
        counts, callgraphs, histories = report.parse_perf_script(text)
        self.assertEqual(counts["bpf_prog_deadbeef_cil_from_host"], 1)
        self.assertEqual(counts["_raw_spin_lock"], 1)
        self.assertEqual(len(callgraphs[0]), 3)
        self.assertEqual(
            histories[0][:2],
            ["bpf_prog_deadbeef_cil_from_host", "net_rx_action"],
        )
        self.assertEqual(
            histories[1],
            ["_raw_spin_lock", "bpf_common_lru_pop_free", "htab_lru_map_update_elem"],
        )
        self.assertEqual(report.classify_symbol("bpf_prog_deadbeef_cil_from_host"), "bpf_code")
        self.assertEqual(report.classify_symbol("htab_map_lookup_elem"), "maps")
        self.assertEqual(report.classify_symbol("lookup_nulls_elem_raw"), "maps")
        self.assertEqual(report.classify_symbol("bpf_redirect"), "helpers")
        self.assertEqual(
            report.classify_context(
                ["_raw_spin_lock", "bpf_common_lru_pop_free", "bpf_prog_x"]
            ),
            "maps",
        )
        self.assertIn("pv_native_safe_halt", report.IDLE_SYMBOLS)
        report.validate_callgraph_samples(counts, callgraphs, histories)

    def test_post_workload_module_snapshot_resolves_pktgen_samples(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            kallsyms = root / "kallsyms"
            modules = root / "modules"
            kallsyms.write_text(
                "ffffffffc0100000 t pktgen_xmit [pktgen]\n"
                "ffffffffc0100100 t mod_cur_headers [pktgen]\n",
                encoding="utf-8",
            )
            modules.write_text(
                "pktgen 8192 0 - Live 0xffffffffc0100000\n", encoding="utf-8"
            )
            script = (
                "ffffffffc0100120 [unknown]\n"
                "        ffffffff81000000 net_rx_action\n\n"
                "ffffffff81000000 [unknown]\n"
            )
            resolved = report.symbolize_module_ips(script, kallsyms, modules)
            self.assertIn("ffffffffc0100120 mod_cur_headers", resolved)
            self.assertIn("ffffffff81000000 [unknown]", resolved)

    def test_completed_lbr_call_does_not_reclassify_rest_sample(self) -> None:
        active = report.reconstruct_active_lbr(
            "net_rx_action",
            [
                ("bpf_prog_old", "net_rx_action", "RET"),
                ("net_rx_action", "bpf_prog_old", "CALL"),
            ],
        )
        self.assertEqual(active, ["net_rx_action"])
        self.assertEqual(report.classify_context(active), "rest")

    def test_native_validation_requires_live_native_frame(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "crossing a live native"):
            report.validate_callgraph_samples(
                {"bpf_prog_stub": 1},
                [["bpf_prog_stub", "bpf_dispatcher"]],
                [["bpf_prog_stub", "bpf_dispatcher"]],
                frozenset({"bpf_prog_e984be621a492c42_cil_to_host"}),
            )
        report.validate_callgraph_samples(
            {"_raw_spin_lock": 1},
            [["_raw_spin_lock", "bpf_common_lru_pop_free", "bpf_prog_e984be621a492c42_cil_to_host"]],
            [[]],
            frozenset({"bpf_prog_e984be621a492c42_cil_to_host"}),
        )

    def test_perf_samples_reject_unknown_only_or_leaf_only_data(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "no resolved leaf"):
            report.validate_callgraph_samples({"[unknown]": 5}, [["[unknown]"]], [[]])
        with self.assertRaisesRegex(RuntimeError, "no callchain"):
            report.validate_callgraph_samples(
                {"bpf_prog_deadbeef_cil_from_host": 5},
                [["bpf_prog_deadbeef_cil_from_host"]],
                [["bpf_prog_deadbeef_cil_from_host", "net_rx_action"]],
            )
        with self.assertRaisesRegex(RuntimeError, "no BPF-code context"):
            report.validate_callgraph_samples(
                {"net_rx_action": 5},
                [["net_rx_action", "do_softirq"]],
                [["netif_receive_skb", "net_rx_action"]],
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
            self.assertEqual(rows[0]["native_ksym"], "bpf_prog_bb_cil")

    def test_program_attach_points_use_measurement_time_net_snapshot(self) -> None:
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            evidence = root / "evidence"
            evidence.mkdir()
            (evidence / "manifest.json").write_text(
                '{"program_array_dumps": {}}\n', encoding="utf-8"
            )
            live_net = root / "guest-bpf-net.json"
            live_net.write_text(
                '[{"tc":[{"devname":"lxcbench0","kind":"tcx/ingress",'
                '"prog_id":158}],"xdp":[]}]\n',
                encoding="utf-8",
            )
            self.assertEqual(
                report._program_attach_points(evidence, live_net),
                {158: ["tc:lxcbench0:tcx/ingress"]},
            )

    def test_live_native_sizes_exclude_lifecycle_replacements(self) -> None:
        self.assertEqual(
            report._live_native_sizes(
                frozenset({12}),
                [
                    {"native_id": 11, "native_blob_bytes": 100},
                    {"native_id": 12, "native_blob_bytes": 80},
                    {"native_id": 13, "native_blob_bytes": 60},
                ],
            ),
            [{"native_id": 12, "native_blob_bytes": 80}],
        )

    def test_live_program_rows_exclude_stale_measured_ids(self) -> None:
        self.assertEqual(
            report._select_live_program_rows(
                [
                    {"id": 11, "name": "stale"},
                    {"id": 12, "name": "reachable"},
                ],
                [12],
            ),
            [{"id": 12, "name": "reachable"}],
        )

    def test_live_program_rows_require_every_reachable_id(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "live program IDs: \\[13\\]"):
            report._select_live_program_rows([{"id": 12}], [12, 13])

    def test_native_size_coverage_rejects_unpaired_program(self) -> None:
        with self.assertRaisesRegex(RuntimeError, "program IDs: \\[12\\]"):
            report._live_native_sizes(
                frozenset({11, 12}), [{"native_id": 11}]
            )

    def test_packet_metrics_preserve_outcome_verdicts(self) -> None:
        workloads = [
            {
                "components": [
                    {"stdout": "pkts-sofar: 100\n", "returncode": 0},
                    {"stdout": "pkts-sofar: 101\n", "returncode": 0},
                ],
                "config": {
                    "outcomes": {
                        "delta": {
                            "receivers": {
                                "left": {
                                    "rx_packets": 202,
                                    "rx_errors": 0,
                                    "rx_dropped": 0,
                                }
                            },
                            "verdicts": {
                                "reason=0,direction=1": {"count": 201, "bytes": 12864},
                                "reason=3,direction=1": {"count": 1, "bytes": 64},
                            },
                        }
                    }
                },
            }
        ]
        metrics = report._packet_metrics(workloads)
        self.assertEqual(metrics["packets_sent"], 201)
        self.assertEqual(metrics["packets_received"], 202)
        self.assertEqual(
            report._verdict_count(metrics, "reason=0,direction=1"), 201
        )
        self.assertEqual(report._other_verdict_count(metrics), 1)


if __name__ == "__main__":
    unittest.main()
