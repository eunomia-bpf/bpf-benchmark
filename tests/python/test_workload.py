import subprocess
import sys
import time
import unittest
from http.client import HTTPConnection
from unittest import mock

from runner.libs import benchmark_catalog, workload
from runner.libs.app_runners import get_app_runner
from runner.libs.app_runners import calico as calico_runner
from runner.libs.app_runners import cilium as cilium_runner


class _FakeHttpServer:
    url = f"http://{workload.BENCHMARK_PEER_IFACE_IP}:18080/"

    def __enter__(self) -> "_FakeHttpServer":
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        del exc_type, exc, tb


def _workload_result() -> workload.WorkloadResult:
    return workload.WorkloadResult(
        ops_total=1.0,
        ops_per_sec=1.0,
        duration_s=1.0,
        stdout="",
        stderr="",
    )


class WorkloadContractTests(unittest.TestCase):
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
                deadline=time.monotonic() + 2.0,
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

    def test_stress_ng_os_excludes_timerfd(self) -> None:
        self.assertNotIn("timerfd", workload._STRESS_NG_WORKLOAD_STRESSORS["stress_ng_os"])
        self.assertNotIn("timerfd", workload._STRESS_NG_WORKLOAD_STRESSORS["stress_ng_os_io_network"])
        self.assertNotIn("timerfd", benchmark_catalog.TRACEE_E2E_WORKLOADS[0]["command"])

    def test_interface_bound_network_client_runs_inside_benchmark_netns(self) -> None:
        with mock.patch.object(workload, "which", return_value="/sbin/ip"):
            command = workload._network_client_command(["wrk", "http://198.18.0.2:18080/"], workload.BENCHMARK_IFACE)

        self.assertEqual(
            command,
            ["/sbin/ip", "netns", "exec", workload.BENCHMARK_NETNS, "wrk", "http://198.18.0.2:18080/"],
        )

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

    def test_network_load_error_reports_actual_client_namespace_command(self) -> None:
        completed = subprocess.CompletedProcess(
            args=[],
            returncode=1,
            stdout="",
            stderr="unable to connect to 198.18.0.2:18080 Cannot assign requested address",
        )
        with (
            mock.patch.object(workload, "resolve_workload_tool", return_value="wrk"),
            mock.patch.object(workload, "_network_http_server", return_value=_FakeHttpServer()),
            mock.patch.object(workload, "which", return_value="/sbin/ip"),
            mock.patch.object(workload, "run_command", return_value=completed),
        ):
            with self.assertRaisesRegex(RuntimeError, "/sbin/ip netns exec bpfbenchns wrk"):
                workload.run_network_load(1, network_device=workload.BENCHMARK_IFACE)

    def test_calico_network_workload_passes_benchmark_device(self) -> None:
        result = _workload_result()
        runner = calico_runner.CalicoRunner(workload_kind="network")
        runner.device = workload.BENCHMARK_IFACE
        with mock.patch.object(
            calico_runner,
            "run_named_workload",
            return_value=result,
        ) as run_named:
            self.assertIs(runner._run_workload(1), result)

        run_named.assert_called_once_with("network", 1, network_device=workload.BENCHMARK_IFACE)

    def test_cilium_network_workload_passes_benchmark_device(self) -> None:
        result = _workload_result()
        runner = cilium_runner.CiliumRunner(workload_kind="network")
        runner.device = workload.BENCHMARK_IFACE
        with mock.patch.object(
            cilium_runner,
            "run_named_workload",
            return_value=result,
        ) as run_named:
            self.assertIs(runner._run_workload(1), result)

        run_named.assert_called_once_with("network", 1, network_device=workload.BENCHMARK_IFACE)

    def test_corpus_runner_adapter_preserves_network_device_path(self) -> None:
        for runner_name, runner_module in (
            ("calico", calico_runner),
            ("cilium", cilium_runner),
        ):
            with self.subTest(runner=runner_name):
                result = _workload_result()
                runner = get_app_runner(runner_name, workload="network")
                runner.session = object()
                runner.device = workload.BENCHMARK_IFACE
                with mock.patch.object(
                    runner_module,
                    "run_named_workload",
                    return_value=result,
                ) as run_named:
                    self.assertIs(runner.run_workload(1), result)

                run_named.assert_called_once_with(
                    "network",
                    1,
                    network_device=workload.BENCHMARK_IFACE,
                )

    def test_calico_cilium_network_workload_fail_fast_without_device(self) -> None:
        for runner in (
            calico_runner.CalicoRunner(workload_kind="network"),
            cilium_runner.CiliumRunner(workload_kind="network"),
        ):
            with self.subTest(runner=type(runner).__name__):
                with self.assertRaisesRegex(RuntimeError, "could not determine a network device"):
                    runner._run_workload(1)


if __name__ == "__main__":
    unittest.main()
