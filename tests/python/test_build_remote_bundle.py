from __future__ import annotations

import json
from pathlib import Path

from runner.libs import ROOT_DIR
from runner.libs import build_remote_bundle


def test_build_remote_bundle_smoke_for_x86_micro(tmp_path: Path) -> None:
    generated_dir = tmp_path / "generated"
    generated_dir.mkdir()
    (generated_dir / "fake.bpf.o").write_bytes(b"x")

    manifest_path = tmp_path / "run-contract.env"
    manifest_path.write_text(
        "RUN_TARGET_NAME=x86-kvm\n"
        "RUN_TARGET_ARCH=x86_64\n"
        "RUN_EXECUTOR=kvm\n"
        "RUN_SUITE_NAME=micro\n"
        "RUN_NEEDS_RUNNER_BINARY=0\n"
        "RUN_NEEDS_DAEMON_BINARY=0\n"
        "RUN_NEEDS_KINSN_MODULES=0\n"
        "RUN_WORKLOAD_TOOLS_CSV=\n"
        "RUN_BUNDLED_WORKLOAD_TOOLS_CSV=\n",
        encoding="utf-8",
    )

    bundle_inputs_path = tmp_path / "bundle-inputs.json"
    bundle_inputs_path.write_text(
        json.dumps(
            {
                "RUN_LOCAL_REPO_ROOT": str(ROOT_DIR),
                "MICRO_PROGRAMS_GENERATED_DIR": str(generated_dir),
            }
        ),
        encoding="utf-8",
    )

    bundle_dir = tmp_path / "bundle"
    bundle_tar = tmp_path / "bundle.tar.gz"
    build_remote_bundle.main(
        [
            str(manifest_path),
            str(bundle_inputs_path),
            str(bundle_dir),
            str(bundle_tar),
        ]
    )

    assert (bundle_dir / "run-contract.env").is_file()
    assert (bundle_dir / "micro/programs/fake.bpf.o").is_file()
    assert (bundle_dir / "vendor/libbpf").is_dir()
    assert bundle_tar.is_file()
