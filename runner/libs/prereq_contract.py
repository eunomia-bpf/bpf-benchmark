from __future__ import annotations

import os
from typing import Mapping


PYTHON_IMPORT_MAP = {
    "PyYAML": "yaml",
    "pyelftools": "elftools",
}

TOOL_PACKAGE_MAP = {
    ("apt", "bpftool"): ("bpftool",),
    ("dnf", "bpftool"): ("bpftool",),
    ("apt", "python3"): ("python3", "python3-pip"),
    ("dnf", "python3"): ("python3", "python3-pip"),
    ("apt", "python3.11"): ("python3.11", "python3-pip"),
    ("dnf", "python3.11"): ("python3.11", "python3.11-pip"),
    ("apt", "curl"): ("curl",),
    ("dnf", "curl"): ("curl-minimal",),
    ("apt", "file"): ("file",),
    ("dnf", "file"): ("file",),
    ("apt", "tar"): ("tar",),
    ("dnf", "tar"): ("tar",),
    ("apt", "taskset"): ("util-linux",),
    ("dnf", "taskset"): ("util-linux",),
    ("apt", "setpriv"): ("util-linux",),
    ("dnf", "setpriv"): ("util-linux",),
    ("apt", "insmod"): ("kmod",),
    ("dnf", "insmod"): ("kmod",),
    ("apt", "dd"): ("coreutils",),
    ("dnf", "dd"): ("coreutils",),
    ("apt", "ip"): ("iproute2",),
    ("dnf", "ip"): ("iproute",),
    ("apt", "tc"): ("iproute2",),
    ("dnf", "tc"): ("iproute-tc",),
    ("apt", "wrk"): ("wrk",),
    ("dnf", "wrk"): ("wrk",),
    ("apt", "sysbench"): ("sysbench",),
    ("dnf", "sysbench"): ("sysbench",),
    ("apt", "hackbench"): ("rt-tests",),
    ("dnf", "hackbench"): ("rt-tests",),
    ("apt", "stress-ng"): ("stress-ng",),
    ("dnf", "stress-ng"): ("stress-ng",),
    ("apt", "fio"): ("fio",),
    ("dnf", "fio"): ("fio",),
    ("apt", "bpftrace"): ("bpftrace",),
    ("dnf", "bpftrace"): ("bpftrace",),
}


def _contract_scalar(contract: Mapping[str, str | list[str]] | None, name: str) -> str:
    if contract is None:
        return os.environ.get(name, "").strip()
    value = contract.get(name, "")
    if isinstance(value, list):
        return " ".join(value).strip()
    return value.strip()


def env_csv(name: str, *, contract: Mapping[str, str | list[str]] | None = None) -> list[str]:
    value = _contract_scalar(contract, name)
    if not value:
        return []
    return [token for token in value.split(",") if token]


def python_import_name(package_name: str) -> str:
    try:
        return PYTHON_IMPORT_MAP[package_name]
    except KeyError as exc:
        raise RuntimeError(f"unsupported python package contract: {package_name}") from exc


def required_commands(*, contract: Mapping[str, str | list[str]] | None = None) -> list[str]:
    commands: list[str] = []
    for token in (
        _contract_scalar(contract, "RUN_BPFTOOL_BIN"),
        _contract_scalar(contract, "RUN_REMOTE_PYTHON_BIN"),
        *env_csv("RUN_REMOTE_COMMANDS_CSV", contract=contract),
        *bundled_commands(contract=contract),
    ):
        if token and token not in commands:
            commands.append(token)
    return commands


def bundled_commands(*, contract: Mapping[str, str | list[str]] | None = None) -> list[str]:
    if _contract_scalar(contract, "RUN_NEEDS_WORKLOAD_TOOLS") != "1":
        return []
    return ["hackbench", "sysbench", "wrk"]


def tool_packages(manager: str, tool: str) -> tuple[str, ...]:
    try:
        return TOOL_PACKAGE_MAP[(manager, tool)]
    except KeyError as exc:
        raise RuntimeError(f"unsupported tool contract on {manager}: {tool}") from exc
