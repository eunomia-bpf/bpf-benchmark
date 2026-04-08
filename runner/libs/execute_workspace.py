from __future__ import annotations

import sys
from functools import partial
from pathlib import Path

from runner.libs.cli_support import fail
from runner.libs.guest_prereqs import install_guest_prereqs, validate_guest_prereqs
from runner.libs.manifest_file import parse_manifest
from runner.libs.suite_entrypoint import SuiteEntrypoint

_die = partial(fail, "execute-workspace")


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

    contract = parse_manifest(manifest_path)
    install_guest_prereqs(workspace, contract)
    validate_guest_prereqs(workspace, contract)
    SuiteEntrypoint.from_contract(
        workspace,
        manifest_path,
        archive_path,
        contract,
    ).run()


if __name__ == "__main__":
    main()
