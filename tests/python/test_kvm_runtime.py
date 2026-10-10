from __future__ import annotations

import os
from pathlib import Path
import stat
import subprocess
import tempfile
import textwrap
import unittest


ROOT = Path(__file__).resolve().parents[2]


class KvmRuntimeTests(unittest.TestCase):
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
