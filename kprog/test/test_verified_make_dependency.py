"""A failed image build must not launch queued guests using its incomplete base."""
import os
from pathlib import Path
import subprocess
import tempfile
import unittest


LAUNCHER = Path(__file__).with_name("run_verified_make.sh")


class MakeDependency(unittest.TestCase):
    def run_dependency(self, status):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            dependency = root / "dependency"
            dependency.mkdir()
            (dependency / "exit-code").write_text(f"{status}\n")
            makefile = root / "Makefile"
            makefile.write_text(f"all:\n\t@touch {root / 'launched'}\n")
            run = root / "run"
            environment = dict(os.environ, VERIFIED_WAIT_JOB=str(dependency),
                               VERIFIED_BUILD_CPUS="8-15")
            environment.pop("VERIFIED_WAIT_PID", None)
            environment.pop("VERIFIED_IMAGE_LOCK", None)
            result = subprocess.run(["bash", str(LAUNCHER), str(run), "-f", str(makefile), "all"],
                                    env=environment, capture_output=True, text=True)
            return (result, (root / "launched").exists(), (run / "exit-code").read_text(),
                    (run / "started").exists(), (run / "finished").exists())

    def test_failed_build_status_is_retained_without_starting_make(self):
        result, launched, status, started, finished = self.run_dependency(2)
        self.assertEqual(result.returncode, 2)
        self.assertFalse(launched)
        self.assertEqual(status, "2\n")
        self.assertFalse(started)
        self.assertTrue(finished)
        self.assertIn("Make was not started", result.stderr)

    def test_successful_build_allows_the_real_make_job(self):
        result, launched, status, started, finished = self.run_dependency(0)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertTrue(launched)
        self.assertEqual(status, "0\n")
        self.assertTrue(started)
        self.assertTrue(finished)


if __name__ == "__main__":
    unittest.main()
