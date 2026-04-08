from __future__ import annotations

from pathlib import Path

from runner.libs import execute_workspace


def test_execute_workspace_runs_install_validate_then_suite(monkeypatch, tmp_path: Path) -> None:
    workspace = tmp_path / "workspace"
    workspace.mkdir()
    manifest = tmp_path / "run-contract.env"
    manifest.write_text("RUN_TARGET_NAME=x86-kvm\nRUN_SUITE_NAME=test\n", encoding="utf-8")

    calls: list[str] = []

    def fake_parse_manifest(path: Path) -> dict[str, str]:
        calls.append(f"parse:{path.name}")
        return {"RUN_TARGET_NAME": "x86-kvm", "RUN_SUITE_NAME": "test"}

    def fake_install_guest_prereqs(path: Path, contract: dict[str, str]) -> None:
        calls.append(f"install:{path.name}:{contract['RUN_SUITE_NAME']}")

    def fake_validate_guest_prereqs(path: Path, contract: dict[str, str]) -> None:
        calls.append(f"validate:{path.name}:{contract['RUN_TARGET_NAME']}")

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

    monkeypatch.setattr(execute_workspace, "parse_manifest", fake_parse_manifest)
    monkeypatch.setattr(execute_workspace, "install_guest_prereqs", fake_install_guest_prereqs)
    monkeypatch.setattr(execute_workspace, "validate_guest_prereqs", fake_validate_guest_prereqs)
    monkeypatch.setattr(execute_workspace.SuiteEntrypoint, "from_contract", staticmethod(fake_from_contract))

    execute_workspace.main([str(workspace), str(manifest)])

    assert calls == [
        "parse:run-contract.env",
        "install:workspace:test",
        "validate:workspace:x86-kvm",
        "contract:workspace:run-contract.env:None",
        "run",
    ]
