# runner/ Dead-Code Audit - 2026-05-18

Scope audited: `runner/libs`, `runner/src`, `runner/suites`, `runner/scripts`, `runner/mk`, `runner/targets`, `runner/containers`, and source-level `runner/build*` inventory. `runner/repos/` was skipped as vendored upstream code.

Caller grep scope for every finding: `runner corpus micro bpfopt daemon ebpf-vm tests`, with only `runner/repos/**` excluded. `runner/include` appears in grep evidence only because it contains declarations for some `runner/src` implementations; findings are anchored in the requested `runner/src` scope.

Tooling notes:

- `python -m pyflakes runner/libs runner/suites runner/scripts` found the unused `sys` import below. It also found `runner/libs/rejit.py:204:26: undefined name 'base64'`, which is inside the dead `_write_failure_workdir_tar()` block; the undefined-name issue is not separately reported as dead code.
- `/tmp/bpfbench-vulture/bin/vulture runner/libs runner/suites runner/scripts --min-confidence 80` produced no findings.
- A custom Python AST pass found no Python unreachable blocks, no unread locals, and no additional unused imports in the scoped Python sources.
- C++ `g++ -fsyntax-only -Wall -Wextra -Wunused-function -Wunused-variable -Wunused-but-set-variable` did not report extra scoped dead-code findings. It emitted only existing initializer warnings in live code and no warnings for the no-caller external helpers listed below.

## Summary

| Location | Finding | Est. LOC | grep evidence |
| --- | --- | ---: | --- |
| `runner/src/bpf_helpers.cpp:164` | `prog_type_name_from_enum()` is implemented and declared, but has no caller. | 43 | `rg '\bprog_type_name_from_enum\b' ...` returns only `runner/src/bpf_helpers.cpp:164` and `runner/include/bpf_helpers.hpp:36`. |
| `runner/src/bpf_helpers.cpp:124` | `prog_type_from_string()` is implemented and declared, but has no caller. | 39 | `rg '\bprog_type_from_string\b' ...` returns only `runner/src/bpf_helpers.cpp:124` and `runner/include/bpf_helpers.hpp:34`. |
| `runner/src/bpf_helpers.cpp:85` | `format_byte_dump()` is implemented and declared, but has no caller. | 29 | `rg '\bformat_byte_dump\b' ...` returns only `runner/src/bpf_helpers.cpp:85` and `runner/include/bpf_helpers.hpp:29`. |
| `runner/libs/rejit.py:190` | `_write_failure_workdir_tar()` has no caller and is now bypassed by the shim path. | 15 | `rg '\b_write_failure_workdir_tar\b' ...` returns only `runner/libs/rejit.py:190`. |
| `runner/src/bpf_helpers.cpp:115` | `program_name_from_info()` is implemented and declared, but has no caller. | 8 | `rg '\bprogram_name_from_info\b' ...` returns only `runner/src/bpf_helpers.cpp:115` and `runner/include/bpf_helpers.hpp:33`. |
| `runner/libs/run_contract.py:172` | `RunConfig.from_json_text()` is never called; JSON contract consumers use `to_json_text()` and `from_mapping()`. | 8 | `rg '\bfrom_json_text\b' ...` returns only `runner/libs/run_contract.py:172`. |
| `runner/libs/rejit.py:388` | `DaemonSession._closed` is written in `close()` but never read. | 2 | `rg '\b_closed\b' ...` returns only the field and assignment. |
| `runner/libs/run_contract.py:6` | `sys` is imported but never used in the file. | 1 | `rg '\bsys\b' runner/libs/run_contract.py` returns only line 6; pyflakes confirms unused import. |

## Findings

### 1. `runner/src/bpf_helpers.cpp:164` - `prog_type_name_from_enum()`

Current code:

```cpp
std::string prog_type_name_from_enum(enum bpf_prog_type prog_type)
{
    static const std::pair<enum bpf_prog_type, std::string_view> mapping[] = {
        {BPF_PROG_TYPE_SOCKET_FILTER, "socket_filter"},
        {BPF_PROG_TYPE_KPROBE, "kprobe"},
        {BPF_PROG_TYPE_SCHED_CLS, "sched_cls"},
        {BPF_PROG_TYPE_SCHED_ACT, "sched_act"},
        {BPF_PROG_TYPE_TRACEPOINT, "tracepoint"},
        {BPF_PROG_TYPE_XDP, "xdp"},
        {BPF_PROG_TYPE_PERF_EVENT, "perf_event"},
        {BPF_PROG_TYPE_CGROUP_SKB, "cgroup_skb"},
        {BPF_PROG_TYPE_CGROUP_SOCK, "cgroup_sock"},
        {BPF_PROG_TYPE_LWT_IN, "lwt_in"},
        {BPF_PROG_TYPE_LWT_OUT, "lwt_out"},
        {BPF_PROG_TYPE_LWT_XMIT, "lwt_xmit"},
        {BPF_PROG_TYPE_SOCK_OPS, "sock_ops"},
        {BPF_PROG_TYPE_SK_SKB, "sk_skb"},
        {BPF_PROG_TYPE_CGROUP_DEVICE, "cgroup_device"},
        {BPF_PROG_TYPE_SK_MSG, "sk_msg"},
        {BPF_PROG_TYPE_RAW_TRACEPOINT, "raw_tracepoint"},
        {BPF_PROG_TYPE_CGROUP_SOCK_ADDR, "cgroup_sock_addr"},
        {BPF_PROG_TYPE_LWT_SEG6LOCAL, "lwt_seg6local"},
        {BPF_PROG_TYPE_LIRC_MODE2, "lirc_mode2"},
        {BPF_PROG_TYPE_SK_REUSEPORT, "sk_reuseport"},
        {BPF_PROG_TYPE_FLOW_DISSECTOR, "flow_dissector"},
        {BPF_PROG_TYPE_CGROUP_SYSCTL, "cgroup_sysctl"},
        {BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE, "raw_tracepoint_writable"},
        {BPF_PROG_TYPE_CGROUP_SOCKOPT, "cgroup_sockopt"},
        {BPF_PROG_TYPE_TRACING, "tracing"},
        {BPF_PROG_TYPE_STRUCT_OPS, "struct_ops"},
        {BPF_PROG_TYPE_EXT, "ext"},
        {BPF_PROG_TYPE_LSM, "lsm"},
        {BPF_PROG_TYPE_SK_LOOKUP, "sk_lookup"},
        {BPF_PROG_TYPE_SYSCALL, "syscall"},
        {BPF_PROG_TYPE_NETFILTER, "netfilter"},
    };
    for (const auto &[value, name] : mapping) {
        if (value == prog_type) {
            return std::string(name);
        }
    }
    return {};
}
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\bprog_type_name_from_enum\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/include/bpf_helpers.hpp:36:std::string prog_type_name_from_enum(enum bpf_prog_type prog_type);
runner/src/bpf_helpers.cpp:164:std::string prog_type_name_from_enum(enum bpf_prog_type prog_type)
```

Deletion suggestion:

Delete the `prog_type_name_from_enum()` implementation from `runner/src/bpf_helpers.cpp`. Also remove the matching declaration in `runner/include/bpf_helpers.hpp` if header cleanup is in scope for the follow-up patch. After deleting both prog-type helpers, `<string_view>` and `<utility>` in this translation unit should be rechecked because they may become unused.

### 2. `runner/src/bpf_helpers.cpp:124` - `prog_type_from_string()`

Current code:

```cpp
std::optional<enum bpf_prog_type> prog_type_from_string(
    const std::string &value)
{
    static const std::pair<std::string_view, enum bpf_prog_type> mapping[] = {
        {"xdp", BPF_PROG_TYPE_XDP},
        {"sched_cls", BPF_PROG_TYPE_SCHED_CLS},
        {"sched_act", BPF_PROG_TYPE_SCHED_ACT},
        {"kprobe", BPF_PROG_TYPE_KPROBE},
        {"tracepoint", BPF_PROG_TYPE_TRACEPOINT},
        {"raw_tracepoint", BPF_PROG_TYPE_RAW_TRACEPOINT},
        {"raw_tp", BPF_PROG_TYPE_RAW_TRACEPOINT},
        {"tracing", BPF_PROG_TYPE_TRACING},
        {"perf_event", BPF_PROG_TYPE_PERF_EVENT},
        {"socket_filter", BPF_PROG_TYPE_SOCKET_FILTER},
        {"cgroup_skb", BPF_PROG_TYPE_CGROUP_SKB},
        {"cgroup_sock", BPF_PROG_TYPE_CGROUP_SOCK},
        {"cgroup_device", BPF_PROG_TYPE_CGROUP_DEVICE},
        {"cgroup_sock_addr", BPF_PROG_TYPE_CGROUP_SOCK_ADDR},
        {"cgroup_sysctl", BPF_PROG_TYPE_CGROUP_SYSCTL},
        {"cgroup_sockopt", BPF_PROG_TYPE_CGROUP_SOCKOPT},
        {"sk_msg", BPF_PROG_TYPE_SK_MSG},
        {"sk_skb", BPF_PROG_TYPE_SK_SKB},
        {"flow_dissector", BPF_PROG_TYPE_FLOW_DISSECTOR},
        {"lwt_in", BPF_PROG_TYPE_LWT_IN},
        {"lwt_out", BPF_PROG_TYPE_LWT_OUT},
        {"lwt_xmit", BPF_PROG_TYPE_LWT_XMIT},
        {"lwt_seg6local", BPF_PROG_TYPE_LWT_SEG6LOCAL},
        {"sockops", BPF_PROG_TYPE_SOCK_OPS},
        {"struct_ops", BPF_PROG_TYPE_STRUCT_OPS},
        {"lsm", BPF_PROG_TYPE_LSM},
        {"syscall", BPF_PROG_TYPE_SYSCALL},
    };
    for (const auto &[name, prog_type] : mapping) {
        if (name == value) {
            return prog_type;
        }
    }
    return std::nullopt;
}
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\bprog_type_from_string\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/include/bpf_helpers.hpp:34:std::optional<enum bpf_prog_type> prog_type_from_string(
runner/src/bpf_helpers.cpp:124:std::optional<enum bpf_prog_type> prog_type_from_string(
```

Deletion suggestion:

Delete the `prog_type_from_string()` implementation from `runner/src/bpf_helpers.cpp`. Also remove the matching declaration in `runner/include/bpf_helpers.hpp` if header cleanup is in scope for the follow-up patch.

### 3. `runner/src/bpf_helpers.cpp:85` - `format_byte_dump()`

Current code:

```cpp
std::string format_byte_dump(
    const std::vector<uint8_t> &bytes,
    size_t width,
    bool annotate_pc)
{
    if (bytes.empty()) {
        return {};
    }

    std::ostringstream out;
    for (size_t offset = 0; offset < bytes.size(); offset += width) {
        if (offset != 0) {
            out << "\n";
        }
        if (annotate_pc) {
            out << std::setw(4) << (offset / width) << ": ";
        }
        const size_t line_width = std::min(width, bytes.size() - offset);
        for (size_t index = 0; index < line_width; ++index) {
            if (index != 0) {
                out << " ";
            }
            out << std::hex << std::setw(2) << std::setfill('0')
                << static_cast<unsigned int>(bytes[offset + index])
                << std::dec << std::setfill(' ');
        }
    }
    return out.str();
}
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\bformat_byte_dump\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/include/bpf_helpers.hpp:29:std::string format_byte_dump(
runner/src/bpf_helpers.cpp:85:std::string format_byte_dump(
```

Deletion suggestion:

Delete the implementation from `runner/src/bpf_helpers.cpp`. Also remove the matching declaration in `runner/include/bpf_helpers.hpp` if header cleanup is in scope for the follow-up patch. After deletion, `<algorithm>`, `<iomanip>`, and `<sstream>` should be rechecked in `runner/src/bpf_helpers.cpp`.

### 4. `runner/libs/rejit.py:190` - `_write_failure_workdir_tar()`

Current code:

```python
def _write_failure_workdir_tar(
    prog_id: int,
    workdir_tar_b64: object,
    failure_artifacts_dir: Path | None,
) -> None:
    if workdir_tar_b64 is None:
        return
    if not isinstance(workdir_tar_b64, str):
        raise RuntimeError(f"daemon response field workdir_tar_b64 for prog {prog_id} must be a string")
    # Caller passes failure_artifacts_dir=None to deliberately discard the tar.
    if failure_artifacts_dir is None:
        return
    failure_artifacts_dir.mkdir(parents=True, exist_ok=True)
    tar_path = failure_artifacts_dir / f"{prog_id}.tar.gz"
    tar_path.write_bytes(base64.b64decode(workdir_tar_b64, validate=True))
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\b_write_failure_workdir_tar\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/libs/rejit.py:190:def _write_failure_workdir_tar(
```

Related live code:

```python
def apply_daemon_rejit(..., failure_artifacts_dir: Path | None = None, ...) -> dict[str, object]:
    ...
    del failure_artifacts_dir  # accepted for API stability; shim path has no workdir tar payload
```

Deletion suggestion:

Delete `_write_failure_workdir_tar()`. This is not the live `KEEP_WORKDIRS` option path: the current shim implementation explicitly accepts and discards `failure_artifacts_dir` for API stability, and no caller invokes this helper. Deleting this block also removes the pyflakes `undefined name 'base64'` report at line 204.

### 5. `runner/src/bpf_helpers.cpp:115` - `program_name_from_info()`

Current code:

```cpp
std::string program_name_from_info(const bpf_prog_info &info)
{
    const char *name = reinterpret_cast<const char *>(info.name);
    if (name == nullptr || name[0] == '\0') {
        return {};
    }
    return std::string(name);
}
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\bprogram_name_from_info\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/include/bpf_helpers.hpp:33:std::string program_name_from_info(const bpf_prog_info &info);
runner/src/bpf_helpers.cpp:115:std::string program_name_from_info(const bpf_prog_info &info)
```

Deletion suggestion:

Delete the implementation from `runner/src/bpf_helpers.cpp`. Also remove the matching declaration in `runner/include/bpf_helpers.hpp` if header cleanup is in scope for the follow-up patch.

### 6. `runner/libs/run_contract.py:172` - `RunConfig.from_json_text()`

Current code:

```python
@classmethod
def from_json_text(cls, text: str) -> "RunConfig":
    raw = json.loads(text)
    if not isinstance(raw, dict): raise RuntimeError("run config JSON must contain an object")
    values: dict[str, str | list[str]] = {}
    for key, value in raw.items():
        if not isinstance(key, str): raise RuntimeError("run config JSON keys must be strings")
        values[key] = [str(item) for item in value] if isinstance(value, list) else ("" if value is None else str(value))
    return cls.from_mapping(values)
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\bfrom_json_text\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/libs/run_contract.py:172:    def from_json_text(cls, text: str) -> "RunConfig":
```

Adjacent live JSON contract users:

```text
$ rg -n --hidden --glob '!runner/repos/**' 'run-contract-json|to_json_text|RunConfig\.from_mapping' runner corpus micro bpfopt daemon ebpf-vm tests
runner/libs/suite_commands.py:171:        command.extend(["--run-contract-json", config.to_json_text()])
runner/libs/run_contract.py:134:    def to_json_text(self) -> str:
runner/libs/run_contract.py:390:    return RunConfig.from_mapping(_build_run_config_mapping(target_name, suite_name, env=env))
runner/libs/run_contract.py:407:    return RunConfig.from_mapping({"RUN_TARGET_NAME": target_name, "RUN_TARGET_ARCH": target.get("TARGET_ARCH", ""),
runner/suites/test.py:45:    parser.add_argument("--run-contract-json", default="", help="Run contract JSON to persist beside test logs.")
```

Deletion suggestion:

Delete `RunConfig.from_json_text()`. The CLI flag path preserves the JSON string for logs, and config construction uses `RunConfig.from_mapping()`. There is no direct or dynamic `getattr`/`hasattr` reference to `from_json_text` in the grep scope.

### 7. `runner/libs/rejit.py:388` - `DaemonSession._closed`

Current code:

```python
@dataclass
class DaemonSession:
    ...
    kinsn_metadata: dict[str, object] = field(default_factory=dict)
    _closed: bool = False
    ...
    def close(self) -> None:
        self._closed = True
```

Full-repo grep result:

```text
$ rg -n --hidden --glob '!runner/repos/**' '\b_closed\b' runner corpus micro bpfopt daemon ebpf-vm tests
runner/libs/rejit.py:388:    _closed: bool = False
runner/libs/rejit.py:424:        self._closed = True
```

Deletion suggestion:

Delete the `_closed` dataclass field and the assignment in `close()`. `close()` is still part of the context-manager API, but this private state is never read and does not gate any behavior.

### 8. `runner/libs/run_contract.py:6` - unused `sys` import

Current code:

```python
import json
import os
import shlex
import sys
from dataclasses import dataclass
```

File-local grep result:

```text
$ rg -n '\bsys\b' runner/libs/run_contract.py
6:import sys
```

pyflakes result:

```text
runner/libs/run_contract.py:6:1: 'sys' imported but unused
```

Deletion suggestion:

Delete the `import sys` line.

## Excluded False Positives

- Env/CLI/config paths were not reported. Examples: `BPFREJIT_*`, `KEEP_WORKDIRS`, `--run-contract-json`, `--native-lab-symbol`, and benchmark config parsing were treated as live even when default-off.
- Hook/callback methods were not reported. Examples: `run_workload_spec()`, `live_rejit_programs()`, `do_GET()`, and `log_message()` are intentionally callable through subclasses/frameworks.
- Public top-level Python APIs were not reported even when only their definition appeared in grep. Examples: `docs_tmp_dir()`, `prepare_kinsn_modules()`, input generator functions, `load_app_suite_from_yaml()`, and `kvm_kernel_image_path()`.
- Makefile targets, Docker image COPY/source lists, target env files, and generated `runner/build*` artifacts were not reported as deletable code.

## Top Deletable List

1. `runner/src/bpf_helpers.cpp:164` - delete `prog_type_name_from_enum()` (about 43 LOC).
2. `runner/src/bpf_helpers.cpp:124` - delete `prog_type_from_string()` (about 39 LOC).
3. `runner/src/bpf_helpers.cpp:85` - delete `format_byte_dump()` (about 29 LOC).
4. `runner/libs/rejit.py:190` - delete `_write_failure_workdir_tar()` (about 15 LOC).
5. `runner/src/bpf_helpers.cpp:115` - delete `program_name_from_info()` (about 8 LOC).
6. `runner/libs/run_contract.py:172` - delete `RunConfig.from_json_text()` (about 8 LOC).
7. `runner/libs/rejit.py:388` - delete `_closed` field plus assignment (about 2 LOC).
8. `runner/libs/run_contract.py:6` - delete unused `sys` import (1 LOC).

Total scoped deletable code estimate: about 145 LOC, plus optional matching `runner/include/bpf_helpers.hpp` declaration cleanup if the follow-up patch extends to headers.
