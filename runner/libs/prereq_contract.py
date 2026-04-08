from __future__ import annotations

import os


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
    ("apt", "insmod"): ("kmod",),
    ("dnf", "insmod"): ("kmod",),
    ("apt", "ip"): ("iproute2",),
    ("dnf", "ip"): ("iproute",),
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


def env_csv(name: str) -> list[str]:
    value = os.environ.get(name, "").strip()
    if not value:
        return []
    return [token for token in value.split(",") if token]


def python_import_name(package_name: str) -> str:
    try:
        return PYTHON_IMPORT_MAP[package_name]
    except KeyError as exc:
        raise RuntimeError(f"unsupported python package contract: {package_name}") from exc


def required_commands(*, mode: str = "runtime") -> list[str]:
    commands: list[str] = []
    for token in (
        os.environ.get("RUN_BPFTOOL_BIN", "").strip(),
        os.environ.get("RUN_REMOTE_PYTHON_BIN", "").strip(),
        *env_csv("RUN_REMOTE_COMMANDS_CSV"),
    ):
        if token and token not in commands:
            commands.append(token)
    if mode == "runtime":
        for token in env_csv("RUN_WORKLOAD_TOOLS_CSV"):
            if token and token not in commands:
                commands.append(token)
    return commands


def tool_packages(manager: str, tool: str) -> tuple[str, ...]:
    try:
        return TOOL_PACKAGE_MAP[(manager, tool)]
    except KeyError as exc:
        raise RuntimeError(f"unsupported tool contract on {manager}: {tool}") from exc
