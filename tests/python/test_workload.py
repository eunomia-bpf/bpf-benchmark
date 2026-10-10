import json
import subprocess
import sys
import unittest
from http.client import HTTPConnection
from types import SimpleNamespace
from unittest import mock

from runner.libs import workload
from runner.libs import app_outcomes
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners import cilium as cilium_runner
from runner.libs.app_runners import katran as katran_runner


class _FakeHttpServer:
    url = f"http://{workload.BENCHMARK_PEER_IFACE_IP}:18080/"

    def __enter__(self) -> "_FakeHttpServer":
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        del exc_type, exc, tb


def _workload_result() -> workload.WorkloadResult:
    return workload.WorkloadResult(
        workload_name="unit",
        command=("true",),
        returncode=0,
        duration_s=1.0,
        stdout="",
        stderr="",
    )


class WorkloadContractTests(unittest.TestCase):
    def test_network_softirq_parser_preserves_per_cpu_napi_placement(self) -> None:
        parsed = workload._parse_network_softirq_counts(
            "                    CPU0       CPU1       CPU2\n"
            "          HI:          1          2          3\n"
            "      NET_TX:         10         20         30\n"
            "      NET_RX:        100        200        300\n"
        )
        self.assertEqual(parsed["NET_RX"], {"CPU0": 100, "CPU1": 200, "CPU2": 300})
        self.assertEqual(parsed["NET_TX"], {"CPU0": 10, "CPU1": 20, "CPU2": 30})

    def test_bpftool_hex_bytes_are_decoded_for_per_cpu_counters(self) -> None:
        self.assertEqual(app_outcomes._little_endian(["0x62", "0x6b", "0x0c", "0x00"]), 813922)

    def test_cilium_verdict_keys_decode_bpftool_hex_bytes(self) -> None:
        record = {
            "key": ["0x8b", "0x02", "0x00", "0x00"],
            "values": [{"value": ["0x03", *("0x00" for _ in range(15))]}],
        }
        with (
            mock.patch.object(app_outcomes, "_map_ids", return_value=[42]),
            mock.patch.object(app_outcomes, "_map_dump", return_value=[record]),
            mock.patch.object(app_outcomes, "_link_stats", return_value={}),
        ):
            snapshot = app_outcomes.cilium_outcome_snapshot()

        self.assertEqual(
            snapshot["verdicts"],
            {"reason=139,direction=2": {"count": 3, "bytes": 0}},
        )

    def test_outcome_snapshot_waits_for_async_receiver_drain(self) -> None:
        snapshots = iter(({"packets": 1}, {"packets": 4}))
        with mock.patch.object(app_outcomes.time, "sleep") as sleep:
            result = app_outcomes.run_with_outcomes(
                _workload_result, lambda: next(snapshots), settle_seconds=2.0
            )
        sleep.assert_called_once_with(2.0)
        self.assertEqual(result.config["outcomes"]["delta"], {"packets": 3})
        self.assertEqual(result.config["outcomes"]["settle_seconds"], 2.0)

    def test_katran_pktgen_uses_isolated_busy_poll_workers(self) -> None:
        self.assertEqual(katran_runner.KATRAN_PKTGEN_THREAD_IDS, (7,))
        self.assertEqual(
            len({*katran_runner.KATRAN_PKTGEN_THREAD_IDS,
                 katran_runner.KATRAN_ROUTER_NAPI_CPU,
                 katran_runner.KATRAN_RECEIVER_NAPI_CPU}),
            3,
        )
        self.assertEqual(katran_runner.KATRAN_NAPI_THREADED_MODE, "busy-poll")
        self.assertEqual(katran_runner.DEFAULT_PKTGEN_SRC_PORT, 10000)
        completed = subprocess.CompletedProcess(
            args=[], returncode=0, stdout="kpktgend_0\nkpktgend_7\n", stderr=""
        )
        with mock.patch.object(katran_runner, "ns_exec_command", return_value=completed):
            self.assertEqual(
                katran_runner._available_katran_pktgen_thread_ids("katran-router"),
                (7,),
            )

    def test_katran_napi_workers_are_pinned_and_realtime(self) -> None:
        """Catch veth-ring loss when threaded NAPI loses CPU to softirq producers."""
        with (
            mock.patch.object(katran_runner.os, "sched_setaffinity") as set_affinity,
            mock.patch.object(katran_runner.os, "sched_setscheduler") as set_scheduler,
        ):
            katran_runner._pin_threaded_napi(123, 6)

        set_affinity.assert_called_once_with(123, {6})
        set_scheduler.assert_called_once_with(
            123,
            katran_runner.os.SCHED_FIFO,
            katran_runner.os.sched_param(katran_runner.KATRAN_NAPI_RT_PRIORITY),
        )

    def test_katran_napi_workers_enable_netdev_busy_poll(self) -> None:
        """Catch a fallback to wake-driven NAPI that can overflow veth rings."""
        responses = [
            subprocess.CompletedProcess(
                args=[], returncode=0,
                stdout='[{"id": 41, "ifindex": 9, "threaded": "enabled", "pid": 100}]',
                stderr="",
            ),
            subprocess.CompletedProcess(args=[], returncode=0, stdout="{}", stderr=""),
            subprocess.CompletedProcess(
                args=[], returncode=0,
                stdout='[{"id": 41, "ifindex": 9, "threaded": "busy-poll", "pid": 123}]',
                stderr="",
            ),
        ]
        with (
            mock.patch.object(katran_runner, "YNL_CLI", katran_runner.Path(__file__)),
            mock.patch.object(katran_runner, "_namespace_ifindex", return_value=9),
            mock.patch.object(katran_runner, "remote_python_binary", return_value="python3"),
            mock.patch.object(katran_runner, "ns_exec_command", side_effect=responses) as ns_exec,
            mock.patch.object(katran_runner, "_pin_threaded_napi") as pin_worker,
        ):
            pid = katran_runner._enable_threaded_peer_napi("katran-router", "rtlb0", 6)

        self.assertEqual(pid, 123)
        set_command = ns_exec.call_args_list[1].args[1]
        self.assertIn("napi-set", set_command)
        self.assertEqual(
            json.loads(set_command[set_command.index("--json") + 1]),
            {"id": 41, "threaded": "busy-poll"},
        )
        pin_worker.assert_called_once_with(123, 6)

    def test_namespaced_http_ready_marker_contract(self) -> None:
        process = subprocess.Popen(
            [
                sys.executable,
                "-u",
                "-c",
                "import time; print('READY', flush=True); time.sleep(0.2)",
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1,
        )
        try:
            workload._wait_for_stdout_marker(
                process,
                marker=workload._NAMESPACED_HTTP_READY_MARKER,
                description="test process",
            )
        finally:
            if process.poll() is None:
                process.terminate()
            process.wait(timeout=5)
            if process.stdout is not None:
                process.stdout.close()
            if process.stderr is not None:
                process.stderr.close()

    def test_interface_bound_network_client_runs_in_root_namespace(self) -> None:
        command = workload._network_client_command(["wrk", "http://198.18.0.2:18080/"], workload.BENCHMARK_IFACE)

        # Client must NOT be wrapped in `ip netns exec bpfbenchns` so that HTTP
        # traffic crosses bpfbench0 and hits TC BPF programs (cilium datapath).
        self.assertEqual(command, ["wrk", "http://198.18.0.2:18080/"])
        self.assertNotIn("netns", command)
        self.assertNotIn(workload.BENCHMARK_NETNS, command)

    def test_loopback_network_client_stays_in_current_namespace(self) -> None:
        command = workload._network_client_command(["wrk", "http://127.0.0.1:18080/"], None)

        self.assertEqual(command, ["wrk", "http://127.0.0.1:18080/"])

    def test_http_workload_handlers_use_http11_keep_alive(self) -> None:
        with workload.LocalHttpServer("127.0.0.1") as server:
            host_port = server.url.removeprefix("http://").removesuffix("/")
            host, port_text = host_port.rsplit(":", 1)
            conn = HTTPConnection(host, int(port_text), timeout=2)
            try:
                conn.request("GET", "/")
                first = conn.getresponse()
                self.assertEqual(first.version, 11)
                first.read()
                conn.request("GET", "/")
                second = conn.getresponse()
                self.assertEqual(second.version, 11)
                second.read()
            finally:
                conn.close()
        self.assertIn('protocol_version = "HTTP/1.1"', workload._NAMESPACED_HTTP_SERVER_SCRIPT)

    def test_network_load_error_reports_actual_client_command(self) -> None:
        completed = subprocess.CompletedProcess(
            args=[],
            returncode=1,
            stdout="",
            stderr="unable to connect to 198.18.0.2:18080 Cannot assign requested address",
        )
        with (
            mock.patch.object(workload, "resolve_workload_tool", return_value="wrk"),
            mock.patch.object(workload, "_network_http_server", return_value=_FakeHttpServer()),
            mock.patch.object(workload, "run_command", return_value=completed),
        ):
            with self.assertRaisesRegex(RuntimeError, r"wrk.*198\.18\.0\.2"):
                workload.run_xdp_traffic_load(1, network_device=workload.BENCHMARK_IFACE)

    def test_cilium_network_workload_passes_benchmark_device(self) -> None:
        result = _workload_result()
        runner = cilium_runner.CiliumRunner(workload_kind="network_lossy_multi")
        runner.device = workload.BENCHMARK_IFACE
        with mock.patch.object(
            cilium_runner,
            "run_named_workload",
            return_value=result,
        ) as run_named, mock.patch.object(
            cilium_runner,
            "run_with_outcomes",
            side_effect=lambda run, snapshot: run(),
        ):
            self.assertIs(runner._run_workload(1), result)

        run_named.assert_called_once_with("network_lossy_multi", 1, network_device=workload.BENCHMARK_IFACE)

    def test_corpus_runner_adapter_preserves_network_device_path(self) -> None:
        for runner_name, runner_module in (
            ("cilium", cilium_runner),
        ):
            with self.subTest(runner=runner_name):
                result = _workload_result()
                runner = get_app_runner(runner_name, workload="network_lossy_multi")
                runner.session = SimpleNamespace(process=None)
                runner.device = workload.BENCHMARK_IFACE
                with mock.patch.object(
                    runner_module,
                    "run_named_workload",
                    return_value=result,
                ) as run_named, mock.patch.object(
                    runner_module,
                    "run_with_outcomes",
                    side_effect=lambda run, snapshot: run(),
                ):
                    self.assertIs(runner.run_workload(1), result)

                run_named.assert_called_once_with(
                    "network_lossy_multi",
                    1,
                    network_device=workload.BENCHMARK_IFACE,
                )

    def test_cilium_network_workload_fail_fast_without_device(self) -> None:
        runner = cilium_runner.CiliumRunner(workload_kind="network_lossy_multi")
        with self.assertRaisesRegex(RuntimeError, "could not determine a network device"):
            runner._run_workload(1)


if __name__ == "__main__":
    unittest.main()
