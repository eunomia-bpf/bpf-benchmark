"""Registered-service launch dependencies and lossless short guest transport."""
import os
import json
import shutil
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


class ServiceCommand(unittest.TestCase):
    def test_long_quoted_arguments_reach_guest_through_short_exec(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            bin_dir = root / "bin"
            bin_dir.mkdir()
            output = root / "out"
            # Execute the real staged shell script; only the VM and inner make
            # are replaced, so quoting is checked at the process boundary.
            fake_vng = bin_dir / "vng"
            fake_vng.write_text("#!/usr/bin/env python3" + chr(10) +
                "import json,os,pathlib,shlex,subprocess,sys" + chr(10) +
                "a=sys.argv[1:];pathlib.Path(os.environ['VNG_CAPTURE']).write_text(json.dumps(a))" + chr(10) +
                "raise SystemExit(subprocess.run(shlex.split(a[a.index('--exec')+1])).returncode)" + chr(10))
            fake_make = bin_dir / "make"
            fake_make.write_text("#!/usr/bin/env python3" + chr(10) +
                "import json,os,pathlib,sys" + chr(10) +
                "pathlib.Path(os.environ['GUEST_CAPTURE']).write_text(json.dumps(sys.argv[1:]))" + chr(10))
            fake_vng.chmod(0o755)
            fake_make.chmod(0o755)
            service_run = 'env A="two words" python3 -c "print(' + chr(39) + 'quoted' + chr(39) + ')" ' + 'argument ' * 400
            service_run += chr(10) + '# preserve "double" and ' + chr(39) + 'single' + chr(39)
            service_args = '--execution-mode checked-sim-c --sim-native-compiler /path/with-compiler'
            environment = dict(os.environ, PATH=str(bin_dir)+os.pathsep+os.environ['PATH'],
                VNG_CAPTURE=str(root/'vng.json'), GUEST_CAPTURE=str(root/'guest.json'))
            cwd = Path(__file__).resolve().parents[1] / "libnativeloader"
            result = subprocess.run([shutil.which('make'), '-o', 'trusted-service', 'trusted-service-kvm',
                'OUTPUT='+str(output), 'BUILD_DIR='+str(root/'build'),
                'SERVICE_RUN='+service_run, 'SERVICE_EXECUTION_ARGS='+service_args,
                'SERVICE_HOST_CPUS=16-19'], cwd=cwd, env=environment, capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout+result.stderr)
            vng = json.loads((root/'vng.json').read_text())
            guest = json.loads((root/'guest.json').read_text())
            self.assertLess(len(vng[vng.index('--exec')+1]), 512)
            self.assertIn('SERVICE_RUN='+service_run, guest)
            self.assertIn('SERVICE_EXECUTION_ARGS='+service_args, guest)
            self.assertIn('BUILD_DIR='+str(root/'build'), guest)
            self.assertIn('OUTPUT='+str(output), guest)


if __name__ == "__main__":
    unittest.main()
