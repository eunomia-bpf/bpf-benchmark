#!/usr/bin/env python3
"""Exercise production map-site resolvers on both ISAs."""
import os
from pathlib import Path
import subprocess
ROOT = Path(__file__).resolve().parent.parent
if __name__ == "__main__":
    env = dict(os.environ, CARGO_TARGET_DIR=str(ROOT / "build/native-link"))
    subprocess.run(["cargo", "test", "--locked", "--quiet", "--jobs", "1",
                    "--manifest-path", str(ROOT.parent / "x86/native_lab/native_link/Cargo.toml"),
                    "_selection_"], env=env, check=True)
    print("production resolver selection regressions PASS")
