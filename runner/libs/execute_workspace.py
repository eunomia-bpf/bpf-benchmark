from __future__ import annotations

import sys
from pathlib import Path
from typing import cast

from runner.libs.guest_prereqs import install_guest_prereqs, validate_guest_prereqs
from runner.libs.run_contract import load_manifest_environment
from runner.libs.suite_entrypoint import SuiteEntrypoint


def _die(message: str) -> "NoReturn":
    print(f"[execute-workspace][ERROR] {message}", file=sys.stderr)
    raise SystemExit(1)


def main(argv: list[str] | None = None) -> None:
    args = list(sys.argv[1:] if argv is None else argv)
    if len(args) not in {2, 3}:
        _die("usage: execute_workspace.py <workspace> <manifest_path> [archive_path]")
    workspace = Path(args[0]).resolve()
    manifest_path = Path(args[1]).resolve()
    archive_path = Path(args[2]).resolve() if len(args) == 3 and args[2] else None
    if not workspace.is_dir():
        _die(f"workspace is missing: {workspace}")
    if not manifest_path.is_file():
        _die(f"manifest is missing: {manifest_path}")

    contract = load_manifest_environment(manifest_path)
    install_guest_prereqs(workspace)
    validate_guest_prereqs(workspace)
    SuiteEntrypoint.from_contract(
        workspace,
        manifest_path,
        archive_path,
        cast(dict[str, str | list[str]], contract),
    ).run()


if __name__ == "__main__":
    main()
