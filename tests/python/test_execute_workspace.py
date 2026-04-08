from __future__ import annotations

from pathlib import Path

from runner.libs import execute_workspace


def test_execute_workspace_runs_install_validate_then_suite(monkeypatch, tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    manifest = tmp_path / "run-contract.env"
    manifest.write_text("RUN_TARGET_NAME=x86-kvm\nRUN_SUITE_NAME=test\n", encoding="utf-8")

    calls: list[str] = []

    def fake_load_manifest_environment(path: Path) -> dict[str, str]:
        calls.append(f"load:{path.name}")
        return {"RUN_TARGET_NAME": "x86-kvm", "RUN_SUITE_NAME": "test"}

    def fake_install_guest_prereqs(path: Path) -> None:
        calls.append(f"install:{path.name}")

    def fake_validate_guest_prereqs(path: Path) -> None:
        calls.append(f"validate:{path.name}")

    class FakeSuite:
        def run(self) -> None:
            calls.append("run")

    def fake_from_contract(
        workspace_path: Path,
        manifest_path: Path,
        archive_path: Path | None,
        contract: dict[str, str],
    ) -> FakeSuite:
        calls.append(f"contract:{workspace_path.name}:{manifest_path.name}:{archive_path}")
        assert contract["RUN_TARGET_NAME"] == "x86-kvm"
        return FakeSuite()

    monkeypatch.setattr(execute_workspace, "load_manifest_environment", fake_load_manifest_environment)
    monkeypatch.setattr(execute_workspace, "install_guest_prereqs", fake_install_guest_prereqs)
    monkeypatch.setattr(execute_workspace, "validate_guest_prereqs", fake_validate_guest_prereqs)
    monkeypatch.setattr(execute_workspace.SuiteEntrypoint, "from_contract", staticmethod(fake_from_contract))

    execute_workspace.main([str(workspace), str(manifest)])

    assert calls == [
        "load:run-contract.env",
        "install:workspace",
        "validate:workspace",
        "contract:workspace:run-contract.env:None",
        "run",
    ]
