from __future__ import annotations

import unittest
from pathlib import Path
from unittest import mock

from runner.libs import ROOT_DIR
from runner.libs.aws_common import AwsExecutorContext
from runner.libs.aws_executor import _remote_workspace_sync_members
from runner.libs.run_contract import RunConfig


def _context(suite_name: str, target_arch: str) -> AwsExecutorContext:
    contract = RunConfig.from_mapping(
        {
            "RUN_TARGET_NAME": "aws-arm64" if target_arch == "arm64" else "aws-x86",
            "RUN_TARGET_ARCH": target_arch,
            "RUN_EXECUTOR": "aws-ssh",
            "RUN_SUITE_NAME": suite_name,
            "RUN_TOKEN": "token",
        }
    )
    target_root = ROOT_DIR / ".cache" / "test-aws-executor"
    run_state_dir = target_root / "run-state"
    return AwsExecutorContext(
        action="run",
        config_path=ROOT_DIR / "runner" / "targets" / "aws-x86.env",
        contract=contract,
        target_name=contract.identity.target_name,
        suite_name=suite_name,
        run_token=contract.identity.token,
        remote_user="ec2-user",
        remote_stage_dir="/var/tmp/bpf-benchmark",
        key_path=ROOT_DIR / "dummy.pem",
        aws_region="us-east-1",
        aws_profile="default",
        target_root=target_root,
        run_state_dir=run_state_dir,
        state_file=run_state_dir / "instance.json",
        results_dir=target_root / "results",
    )


class AwsExecutorSyncMembersTests(unittest.TestCase):
    def test_test_suite_syncs_x86_test_binaries(self) -> None:
        members = _remote_workspace_sync_members(_context("test", "x86_64"))

        self.assertIn("daemon/target/release/bpfrejit-daemon", members)
        self.assertIn("tests/unittest/build", members)
        self.assertIn("tests/negative/build", members)
        self.assertNotIn("tests/unittest/build-arm64", members)
        self.assertNotIn("tests/negative/build-arm64", members)
        self.assertNotIn("tests/kernel/build", members)

    def test_test_suite_syncs_arm64_test_binaries(self) -> None:
        members = _remote_workspace_sync_members(_context("test", "arm64"))

        self.assertIn("daemon/target/aarch64-unknown-linux-gnu/release/bpfrejit-daemon", members)
        self.assertIn("tests/unittest/build-arm64", members)
        self.assertIn("tests/negative/build-arm64", members)
        self.assertNotIn("tests/unittest/build", members)
        self.assertNotIn("tests/negative/build", members)

    def test_test_suite_syncs_kernel_selftest_when_build_exists(self) -> None:
        kernel_build = (ROOT_DIR / "tests" / "kernel" / "build").resolve()
        original_exists = Path.exists

        def fake_exists(path: Path) -> bool:
            if path.resolve() == kernel_build:
                return True
            return original_exists(path)

        with mock.patch.object(Path, "exists", autospec=True, side_effect=fake_exists):
            members = _remote_workspace_sync_members(_context("test", "x86_64"))

        self.assertIn("tests/kernel/build", members)

    def test_e2e_suite_syncs_driver_cases_and_daemon(self) -> None:
        members = _remote_workspace_sync_members(_context("e2e", "x86_64"))

        expected = {
            "daemon/target/release/bpfrejit-daemon",
            "e2e/driver.py",
            "e2e/cases/__init__.py",
            "e2e/cases/bcc",
            "e2e/cases/bpftrace",
            "e2e/cases/katran",
            "e2e/cases/tetragon",
            "e2e/cases/tracee/__init__.py",
            "e2e/cases/tracee/case.py",
        }
        self.assertTrue(expected.issubset(set(members)))
        self.assertNotIn("e2e/cases/tracee/bin", members)


if __name__ == "__main__":
    unittest.main()
