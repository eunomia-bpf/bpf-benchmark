from __future__ import annotations

import unittest
from pathlib import Path

from runner.libs import workload


class StressNgWorkloadTests(unittest.TestCase):
    def test_named_stress_ng_workloads_use_explicit_fixed_ops_stressors(self) -> None:
        for name, stressors in workload._STRESS_NG_WORKLOAD_STRESSORS.items():
            with self.subTest(name=name):
                for stressor in stressors:
                    command = workload._build_stress_ng_stressor_command(
                        "/usr/bin/stress-ng",
                        stressor,
                        seconds=1,
                        temp_root=Path("/var/tmp"),
                    )
                    self.assertNotIn("--class", command)
                    self.assertNotIn("--all", command)
                    self.assertIn("--metrics-brief", command)
                    self.assertIn("--timeout", command)
                    self.assertIn(f"--{stressor}", command)
                    self.assertIn(f"--{stressor}-ops", command)
                    stressor_flags = [
                        arg
                        for arg in command
                        if arg.startswith("--") and arg[2:] in workload._STRESS_NG_STRESSOR_OPS
                    ]
                    self.assertEqual([f"--{stressor}"], stressor_flags)

    def test_network_stressor_ports_are_stable_within_process(self) -> None:
        first = workload._build_stress_ng_stressor_command(
            "/usr/bin/stress-ng",
            "sock",
            seconds=1,
            temp_root=Path("/var/tmp"),
        )
        second = workload._build_stress_ng_stressor_command(
            "/usr/bin/stress-ng",
            "sock",
            seconds=1,
            temp_root=Path("/var/tmp"),
        )
        first_port = first[first.index("--sock-port") + 1]
        second_port = second[second.index("--sock-port") + 1]
        self.assertEqual(first_port, second_port)

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


if __name__ == "__main__":
    unittest.main()
