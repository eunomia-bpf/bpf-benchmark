#!/usr/bin/env python3
"""Exercise the production exact-name map-site resolver."""
import os
from pathlib import Path
import subprocess
ROOT = Path(__file__).resolve().parent.parent
if __name__ == "__main__":
    env = dict(os.environ, CARGO_TARGET_DIR=str(ROOT.parent / "x86/native_lab/native_link/target"))
    subprocess.run(["cargo", "test", "--locked", "--quiet", "--jobs", "1",
                    "--manifest-path", str(ROOT.parent / "x86/native_lab/native_link/Cargo.toml"),
                    "runtime_known_maps_use_only_exact_named_map_facts", "--", "--test-threads=1"], env=env, check=True)
    print("production exact-name resolver regression PASS")
