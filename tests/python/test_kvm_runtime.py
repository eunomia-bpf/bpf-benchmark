from __future__ import annotations

import os
from pathlib import Path
import stat
import subprocess
import tempfile
import textwrap
import unittest


ROOT = Path(__file__).resolve().parents[2]


class CiliumNativeConfigurationTests(unittest.TestCase):
    def test_native_policy_mode_matches_cilium_runtime(self) -> None:
        """Catch native policy drops when the runtime is configured to audit."""
        runner = (ROOT / "runner/libs/app_runners/cilium.py").read_text(
            encoding="utf-8"
        )
        native_makefile = (ROOT / "vendor/bpf/Makefile").read_text(
            encoding="utf-8"
        )

        self.assertIn('"--policy-audit-mode=true"', runner)
        options = native_makefile.split("CILIUM_MAX_BASE_OPTIONS :=", 1)[1].split(
            "CILIUM_MAX_LB_OPTIONS :=", 1
        )[0]
        self.assertIn("-DPOLICY_AUDIT_MODE=1", options)


class KvmRuntimeTests(unittest.TestCase):
    def test_module_publish_keeps_last_complete_generation(self) -> None:
        """Catch interrupted image rebuilds erasing the usable module tree."""
        with tempfile.TemporaryDirectory() as raw:
            root = Path(raw)
            current = root / "modules-install-current"
            publisher = ROOT / "runner/scripts/publish-kernel-modules"

            first = root / ".modules-install.first"
            first_release = first / "lib/modules/test/kernel/net/core"
            first_release.mkdir(parents=True)
            (first / "lib/modules/test/modules.order").write_text(
                "kernel/net/core/pktgen.ko\n", encoding="utf-8"
            )
            (first_release / "pktgen.ko").write_bytes(b"first")
            subprocess.run(["bash", publisher, first, current], check=True)
            published = current / "lib/modules/test/kernel/net/core/pktgen.ko"
            self.assertEqual(published.read_bytes(), b"first")

            incomplete = root / ".modules-install.incomplete"
            incomplete.mkdir()
            failed = subprocess.run(
                ["bash", publisher, incomplete, current],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )
            self.assertNotEqual(failed.returncode, 0)
            self.assertEqual(published.read_bytes(), b"first")

            second = root / ".modules-install.second"
            second_release = second / "lib/modules/test/kernel/net/core"
            second_release.mkdir(parents=True)
            (second / "lib/modules/test/modules.order").write_text(
                "kernel/net/core/pktgen.ko\n", encoding="utf-8"
            )
            (second_release / "pktgen.ko").write_bytes(b"second")
            subprocess.run(["bash", publisher, second, current], check=True)
            self.assertEqual(published.read_bytes(), b"second")
            self.assertEqual((first_release / "pktgen.ko").read_bytes(), b"first")

    def test_kvm_vcpus_are_pinned_one_per_performance_core(self) -> None:
        """Catch timing guests sharing arbitrary P-cores instead of distinct pins."""
        dry_run = subprocess.run(
            [
                "make",
                "--no-print-directory",
                "--eval",
                "print-vng:;@echo $(VNG)",
                "print-vng",
                "PLATFORM=kvm",
                "ARCH=x86",
            ],
            cwd=ROOT,
            check=True,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
        )
        self.assertIn("--cpus 8 --pin 0-7", dry_run.stdout)

    def test_guest_docker_uses_private_config_instead_of_host_config(self) -> None:
        """Catch host daemon.json data-root collisions that prevent socket creation."""
        with tempfile.TemporaryDirectory() as tmp:
            temp = Path(tmp)
            daemon_args = temp / "dockerd.args"
            fake_dockerd = temp / "dockerd"
            fake_docker = temp / "docker"
            fake_dockerd.write_text(
                textwrap.dedent(
                    """\
                    #!/usr/bin/env python3
                    import os
                    from pathlib import Path
                    import sys
                    import time

                    Path(os.environ["DAEMON_ARGS"]).write_text("\\n".join(sys.argv[1:]))
                    time.sleep(2)
                    """
                ),
                encoding="utf-8",
            )
            fake_docker.write_text(
                textwrap.dedent(
                    """\
                    #!/usr/bin/env python3
                    import os
                    from pathlib import Path
                    import sys

                    args = Path(os.environ["DAEMON_ARGS"])
                    if not args.is_file():
                        sys.exit(1)
                    tokens = args.read_text().splitlines()
                    config = Path(tokens[tokens.index("--config-file") + 1])
                    sys.exit(0 if config.read_text() == "{}\\n" else 1)
                    """
                ),
                encoding="utf-8",
            )
            fake_dockerd.chmod(fake_dockerd.stat().st_mode | stat.S_IXUSR)
            fake_docker.chmod(fake_docker.stat().st_mode | stat.S_IXUSR)

            runtime_root = temp / "runtime"
            (runtime_root / "data").mkdir(parents=True)
            (runtime_root / "exec").mkdir()
            env = dict(os.environ)
            env.update(
                {
                    "BPFREJIT_VM_DOCKER_ROOT": str(runtime_root),
                    "BPFREJIT_VM_DOCKER_SOCKET": str(temp / "docker.sock"),
                    "BPFREJIT_VM_DOCKER_WAIT_SECONDS": "2",
                    "DOCKERD_BIN": str(fake_dockerd),
                    "DOCKER_BIN": str(fake_docker),
                    "DAEMON_ARGS": str(daemon_args),
                }
            )
            subprocess.run(
                [str(ROOT / "runner/scripts/start-vm-docker")],
                check=True,
                env=env,
            )

            args = daemon_args.read_text(encoding="utf-8").splitlines()
            self.assertEqual(
                args[args.index("--config-file") + 1],
                str(runtime_root / "daemon.json"),
            )
            self.assertEqual(
                args[args.index("--data-root") + 1],
                str(runtime_root / "data"),
            )


if __name__ == "__main__":
    unittest.main()
