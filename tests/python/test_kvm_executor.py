from __future__ import annotations

import tarfile
import tempfile
from pathlib import Path

from runner.libs.kvm_executor import bundle_stage_root


def test_bundle_stage_root_extracts_under_tmpdir(tmp_path: Path) -> None:
    source = tmp_path / "source"
    source.mkdir()
    (source / "run-contract.env").write_text("RUN_EXECUTOR=kvm\n", encoding="utf-8")
    run_root = tmp_path / "run.x86-kvm.corpus.token123"
    run_root.mkdir()
    bundle_tar = run_root / "bundle.tar.gz"
    with tarfile.open(bundle_tar, "w:gz") as archive:
        archive.add(source, arcname=".")

    stage_root = bundle_stage_root(bundle_tar, "run.x86-kvm.corpus.token123")

    assert stage_root.is_dir()
    assert str(stage_root).startswith(str(Path(tempfile.gettempdir()) / "bpf-benchmark-kvm"))
    assert "run.x86-kvm.corpus.token123" in str(stage_root)
    assert (stage_root / "run-contract.env").is_file()
