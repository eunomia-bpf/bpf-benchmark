from __future__ import annotations

import unittest
from pathlib import Path

from runner.libs import workload


class StressNgWorkloadTests(unittest.TestCase):
    def test_named_stress_ng_workloads_use_explicit_stressors(self) -> None:
        for name, stressors in workload._STRESS_NG_WORKLOAD_STRESSORS.items():
            with self.subTest(name=name):
                command = workload._build_stress_ng_stressor_command(
                    "/usr/bin/stress-ng",
                    stressors,
                    seconds=1,
                    temp_root=Path("/var/tmp"),
                )
                self.assertNotIn("--class", command)
                self.assertNotIn("--all", command)
                self.assertIn("--metrics-brief", command)
                self.assertIn("--timeout", command)
                for stressor in stressors:
                    self.assertIn(f"--{stressor}", command)
                    self.assertIn(f"--{stressor}-ops", command)

    def test_named_stress_ng_workloads_avoid_disruptive_stressors(self) -> None:
        disruptive = {
            "apparmor",
            "bad-ioctl",
            "bind-mount",
            "binderfs",
            "cgroup",
            "chroot",
            "cpu-online",
            "icmp-flood",
            "ioport",
            "klog",
            "loop",
            "memhotplug",
            "module",
            "priv-instr",
            "quota",
            "ramfs",
            "rawpkt",
            "rawsock",
            "rawudp",
            "reboot",
            "seccomp",
            "softlockup",
            "swap",
            "sysinval",
            "tun",
            "umount",
            "watchdog",
        }
        for name, stressors in workload._STRESS_NG_WORKLOAD_STRESSORS.items():
            with self.subTest(name=name):
                self.assertFalse(disruptive.intersection(stressors))

    def test_filesystem_workload_avoids_vm_unreliable_stressors(self) -> None:
        unreliable = {"copy-file", "fiemap", "symlink"}
        self.assertFalse(unreliable.intersection(workload._STRESS_NG_FILESYSTEM_STRESSORS))

    def test_stress_ng_metric_parser_sums_bogo_ops(self) -> None:
        text = "\n".join(
            [
                "stress-ng: metrc: [123] stressor       bogo ops real time",
                "stress-ng: metrc: [123] cap              10      1.00",
                "stress-ng: metrc: [123] syscall           2.5    1.00",
            ]
        )
        self.assertEqual(12.5, workload.parse_stress_ng_total_bogo_ops(text))


if __name__ == "__main__":
    unittest.main()
