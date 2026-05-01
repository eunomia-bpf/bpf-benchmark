import subprocess
import sys
import time
import unittest

from runner.libs import benchmark_catalog, workload


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


if __name__ == "__main__":
    unittest.main()
