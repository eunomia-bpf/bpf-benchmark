from __future__ import annotations

import fcntl
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Mapping, Sequence


_CILIUM_SOURCES = {
    "bpf_alignchecker",
    "bpf_host",
    "bpf_lxc",
    "bpf_overlay",
    "bpf_sock",
    "bpf_wireguard",
    "bpf_xdp",
}
_CONFIG_HEADERS = (
    "node_config.h",
    "netdev_config.h",
    "ep_config.h",
    "filter_config.h",
)
_ABI_DEFINES = frozenset(
    {
        "BPFBENCH_CILIUM_HYBRID_ROUTING_ENABLED",
        "MICRO_NATIVE",
        "__TARGET_ARCH_x86",
    }
)
_ABI_MACROS = frozenset(
    {
        "CILIUM_HYBRID_ROUTING_ENABLED",
        "CONFIG",
        "__native_bpf_helper",
        "clone_redirect",
        "csum_diff_external",
        "fib_lookup",
        "for_each_map_elem",
        "get_cgroup_classid",
        "get_current_cgroup_id",
        "get_netns_cookie",
        "get_prandom_u32",
        "get_smp_processor_id",
        "get_socket_cookie",
        "get_socket_opt",
        "jiffies64",
        "ktime_get_boot_ns",
        "ktime_get_ns",
        "loop",
        "map_delete_elem",
        "map_lookup_elem",
        "map_lookup_percpu_elem",
        "map_update_elem",
        "redirect",
        "redirect_peer",
        "ringbuf_discard",
        "ringbuf_reserve",
        "ringbuf_submit",
        "set_retval",
        "set_socket_opt",
        "sk_assign",
        "sk_lookup_tcp",
        "sk_lookup_udp",
        "sk_release",
        "skb_adjust_room",
        "skb_change_head",
        "skb_change_proto",
        "skb_change_tail",
        "skb_change_type",
        "skb_event_output",
        "skb_get_tunnel_key",
        "skb_get_tunnel_opt",
        "skb_load_bytes",
        "skb_pull_data",
        "skb_set_tunnel_key",
        "skb_set_tunnel_opt",
        "skb_store_bytes",
        "skc_lookup_tcp",
        "sock_event_output",
        "tail_call",
        "tail_call_static",
        "trace_printk",
        "xdp_adjust_head",
        "xdp_adjust_meta",
        "xdp_adjust_tail",
        "xdp_event_output",
        "xdp_get_buff_len",
    }
)
_ABI_PATCH_PATHS = frozenset(
    {
        "bpf_host.c",
        "bpf_lxc.c",
        "include/bpf/access.h",
        "include/bpf/ctx/skb.h",
        "include/bpf/ctx/xdp.h",
        "include/bpf/helpers.h",
        "include/bpf/tailcall.h",
        "include/linux/bpf.h",
        "lib/arp.h",
        "lib/hexdump.h",
        "lib/overloadable_skb.h",
        "lib/static_data.h",
        "lib/subnet.h",
    }
)
_DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_][A-Za-z0-9_]*)\b")


def _env_path(name: str, default: str) -> Path:
    return Path(os.environ.get(name, "").strip() or default)


def prepare_cilium_native_runtime(root: Path) -> Mapping[str, str]:
    root = Path(root).resolve()
    root.mkdir(parents=True, exist_ok=True)
    manifest = root / "manifest.json"
    if not manifest.exists():
        manifest.write_text(
            json.dumps(
                {
                    "version": 1,
                    "app": "cilium",
                    "status": "runtime-config-paired",
                    "objects": [],
                    "map_rules": [],
                },
                indent=2,
                sort_keys=True,
            )
            + "\n",
            encoding="utf-8",
        )
    return {
        "BPFREJIT_SHIM_NATIVE_MANIFEST": str(manifest),
        "BPFREJIT_CILIUM_NATIVE_BUILD_ROOT": str(root),
    }


def _target_value(args: Sequence[str]) -> str:
    for index, arg in enumerate(args):
        if arg in {"-target", "--target"} and index + 1 < len(args):
            return args[index + 1]
        if arg.startswith("--target="):
            return arg.split("=", 1)[1]
    return ""


def _source_path(args: Sequence[str]) -> Path | None:
    skip = False
    value_flags = {
        "-D", "-I", "-include", "-isystem", "-idirafter", "-iquote",
        "-MF", "-MT", "-MQ", "-o", "-target", "--target", "-mcpu", "-x", "-Xclang",
    }
    for arg in args:
        if skip:
            skip = False
            continue
        if arg in value_flags:
            skip = True
            continue
        if not arg.startswith("-") and arg.endswith(".c"):
            return Path(arg)
    return None


def is_cilium_native_compile(args: Sequence[str]) -> bool:
    if not os.environ.get("BPFREJIT_CILIUM_NATIVE_BUILD_ROOT", "").strip():
        return False
    if "-c" not in args or not _target_value(args).startswith("bpf"):
        return False
    source = _source_path(args)
    return source is not None and source.stem in _CILIUM_SOURCES


def _output_is_stdout(args: Sequence[str]) -> bool:
    for index, arg in enumerate(args):
        if arg == "-o" and index + 1 < len(args):
            return args[index + 1] == "-"
        if arg == "-o-":
            return True
    return False


def _replace_output(args: Sequence[str], output: Path) -> list[str]:
    result: list[str] = []
    index = 0
    replaced = False
    while index < len(args):
        arg = args[index]
        if arg == "-o":
            if index + 1 >= len(args):
                raise RuntimeError("clang -o requires a value")
            result.extend(("-o", str(output)))
            index += 2
            replaced = True
            continue
        if arg.startswith("-o") and len(arg) > 2:
            result.extend(("-o", str(output)))
            index += 1
            replaced = True
            continue
        result.append(arg)
        index += 1
    if not replaced:
        result.extend(("-o", str(output)))
    return result


def _include_and_define_args(args: Sequence[str]) -> list[str]:
    result: list[str] = []
    index = 0
    while index < len(args):
        arg = args[index]
        if arg in {"-I", "-D", "-isystem", "-idirafter", "-iquote"}:
            if index + 1 >= len(args):
                raise RuntimeError(f"{arg} requires a value")
            result.extend((arg, args[index + 1]))
            index += 2
            continue
        if arg.startswith(("-I", "-D")) and len(arg) > 2:
            result.append(arg)
        index += 1
    return result


def _native_preprocessor_args(
    args: Sequence[str], *, original_root: Path, native_root: Path
) -> list[str]:
    values = _include_and_define_args(args)
    result: list[str] = []
    inserted = False
    index = 0
    while index < len(values):
        arg = values[index]
        include_value = ""
        width = 1
        if arg == "-I":
            include_value = values[index + 1]
            width = 2
        elif arg.startswith("-I"):
            include_value = arg[2:]
        if include_value and Path(include_value).resolve() == original_root.resolve() and not inserted:
            result.extend(("-I", str(native_root), "-I", str(native_root / "include")))
            inserted = True
        result.extend(values[index : index + width])
        index += width
    if not inserted:
        raise RuntimeError(f"Cilium compile command lacks source include root {original_root}")
    return result


def native_compile_args(
    args: Sequence[str], output: Path, compat: Path, native_root: Path,
    native_source: Path, extra_defines: Sequence[str] = (),
) -> list[str]:
    original_source = _source_path(args)
    if original_source is None:
        raise RuntimeError("Cilium compile command has no C source")
    return [
        "-O3", "-g", "-fPIC", "-c", "-DMICRO_NATIVE", "-D__TARGET_ARCH_x86",
        *extra_defines,
        "-fms-extensions", "-fomit-frame-pointer", "-march=native", "-mno-red-zone",
        "-mgeneral-regs-only", "-fno-stack-protector", "-fno-asynchronous-unwind-tables",
        "-fno-unwind-tables", "-fno-jump-tables", "-fno-optimize-sibling-calls",
        "-Wno-unknown-attributes", "-mllvm", "-switch-to-lookup=false",
        "-include", str(compat),
        *_native_preprocessor_args(
            args, original_root=original_source.parent, native_root=native_root
        ),
        "-o", str(output), str(native_source),
    ]


def _defined_options(args: Sequence[str]) -> dict[str, str]:
    result: dict[str, str] = {}
    index = 0
    while index < len(args):
        arg = args[index]
        value = ""
        if arg == "-D":
            if index + 1 >= len(args):
                raise RuntimeError("-D requires a value")
            value = args[index + 1]
            index += 2
        elif arg.startswith("-D") and len(arg) > 2:
            value = arg[2:]
            index += 1
        else:
            index += 1
            continue
        name, separator, expansion = value.partition("=")
        result[name] = expansion if separator else "1"
    return result


def validate_compile_defines(bpf_args: Sequence[str], native_args: Sequence[str]) -> dict[str, object]:
    bpf = _defined_options(bpf_args)
    native = _defined_options(native_args)
    disallowed = {
        name: {"bpf": bpf.get(name), "native": native.get(name)}
        for name in sorted(set(bpf) | set(native))
        if bpf.get(name) != native.get(name) and name not in _ABI_DEFINES
    }
    if disallowed:
        raise RuntimeError(f"Cilium native compile define mismatch: {json.dumps(disallowed, sort_keys=True)}")
    return {
        "bpf_defines": bpf,
        "native_defines": native,
        "allowed_abi_defines": sorted(_ABI_DEFINES),
        "non_abi_define_diff": disallowed,
    }


def _include_dirs(args: Sequence[str]) -> list[Path]:
    result: list[Path] = []
    index = 0
    while index < len(args):
        arg = args[index]
        if arg == "-I":
            if index + 1 >= len(args):
                raise RuntimeError("-I requires a value")
            result.append(Path(args[index + 1]))
            index += 2
            continue
        if arg.startswith("-I") and len(arg) > 2:
            result.append(Path(arg[2:]))
        index += 1
    return result


def _config_headers(args: Sequence[str]) -> list[Path]:
    found: list[Path] = []
    seen_names: set[str] = set()
    for directory in _include_dirs(args):
        for name in _CONFIG_HEADERS:
            candidate = (directory / name).resolve()
            if candidate.is_file() and name not in seen_names:
                seen_names.add(name)
                found.append(candidate)
    if not found:
        raise RuntimeError("Cilium compile command exposes no generated configuration headers")
    return found


def _macro_dump_args(
    args: Sequence[str], *, native: bool, compat: Path, native_root: Path,
    native_source: Path, native_extra_defines: Sequence[str] = (),
) -> list[str]:
    source = _source_path(args)
    assert source is not None
    common = ["-dM", "-E", *_include_and_define_args(args)]
    if native:
        return [
            "-DMICRO_NATIVE", "-D__TARGET_ARCH_x86", *native_extra_defines,
            "-include", str(compat),
            "-dM", "-E",
            *_native_preprocessor_args(
                args, original_root=source.parent, native_root=native_root
            ),
            str(native_source),
        ]
    return ["--target=bpf", *common, str(source)]


def _compiler_baseline_macro_args(*, native: bool, compat: Path) -> list[str]:
    if native:
        return [
            "-DMICRO_NATIVE", "-D__TARGET_ARCH_x86", "-include", str(compat),
            "-dM", "-E", "-x", "c", "/dev/null",
        ]
    return ["--target=bpf", "-dM", "-E", "-x", "c", "/dev/null"]


def _read_unsigned_scalar(data: bytes, offset: int, size: int) -> int:
    if size not in {1, 2, 4, 8}:
        raise RuntimeError(f"unsupported Cilium config scalar size: {size}")
    if offset < 0 or offset + size > len(data):
        raise RuntimeError(
            f"Cilium config scalar [{offset}, {offset + size}) exceeds section size {len(data)}"
        )
    return int.from_bytes(data[offset : offset + size], "little", signed=False)


def _bpf_config_scalar(object_path: Path, symbol_name: str) -> dict[str, object]:
    try:
        from elftools.elf.elffile import ELFFile
    except ImportError as exc:
        raise RuntimeError("pyelftools is required for paired Cilium config") from exc
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symtab = elf.get_section_by_name(".symtab")
        if symtab is None:
            raise RuntimeError(f"Cilium BPF object has no .symtab: {object_path}")
        matches = symtab.get_symbol_by_name(symbol_name) or []
        if len(matches) != 1:
            raise RuntimeError(
                f"Cilium BPF object must contain one {symbol_name}, found {len(matches)}"
            )
        symbol = matches[0]
        section_index = symbol["st_shndx"]
        if not isinstance(section_index, int):
            raise RuntimeError(f"Cilium config symbol {symbol_name} has no data section")
        section = elf.get_section(section_index)
        if section is None or section.name != ".rodata.config":
            raise RuntimeError(
                f"Cilium config symbol {symbol_name} is not in .rodata.config"
            )
        size = int(symbol["st_size"])
        offset = int(symbol["st_value"] - section["sh_addr"])
        value = _read_unsigned_scalar(section.data(), offset, size)
    return {
        "object": str(object_path),
        "section": ".rodata.config",
        "symbol": symbol_name,
        "offset": offset,
        "size": size,
        "value": value,
    }


def _audit_native_abi_tree(
    original_root: Path, native_root: Path, output_root: Path
) -> dict[str, object]:
    changed: set[str] = set()
    for native_path in sorted(path for path in native_root.rglob("*") if path.is_file()):
        relative = native_path.relative_to(native_root).as_posix()
        original_path = original_root / relative
        if not original_path.is_file() or original_path.read_bytes() != native_path.read_bytes():
            changed.add(relative)
    if changed != _ABI_PATCH_PATHS:
        raise RuntimeError(
            "Cilium native ABI tree differs outside audited paths: "
            + json.dumps(
                {
                    "unexpected": sorted(changed - _ABI_PATCH_PATHS),
                    "missing": sorted(_ABI_PATCH_PATHS - changed),
                },
                sort_keys=True,
            )
        )
    archive = output_root / "native-abi"
    records: list[dict[str, str]] = []
    for relative in sorted(changed):
        original_path = original_root / relative
        native_path = native_root / relative
        for label, path in (("jit-source", original_path), ("native-abi", native_path)):
            destination = archive / label / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(path, destination)
        records.append(
            {
                "path": relative,
                "jit_source_sha256": hashlib.sha256(original_path.read_bytes()).hexdigest(),
                "native_abi_sha256": hashlib.sha256(native_path.read_bytes()).hexdigest(),
            }
        )
    record: dict[str, object] = {
        "status": "pass",
        "purpose": "native-entry-ABI-lowering-only",
        "feature_defines_added": [],
        "audited_changed_paths": records,
    }
    (output_root / "native-abi.json").write_text(
        json.dumps(record, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    return record


def _make_native_abi_overlay(
    original_root: Path, native_root: Path, output_root: Path
) -> Path:
    overlay = output_root / "native-abi-overlay"
    shutil.copytree(original_root, overlay, dirs_exist_ok=True)
    for relative in sorted(_ABI_PATCH_PATHS):
        source = native_root / relative
        if not source.is_file():
            raise RuntimeError(f"Cilium native ABI source missing: {source}")
        destination = overlay / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(source, destination)
    return overlay


def _parse_macro_dump(text: str) -> dict[str, str]:
    result: dict[str, str] = {}
    for line in text.splitlines():
        match = _DEFINE_RE.match(line)
        if match:
            result[match.group(1)] = line.strip()
    return result


def _header_macro_names(headers: Sequence[Path]) -> set[str]:
    names: set[str] = set()
    for header in headers:
        for line in header.read_text(encoding="utf-8").splitlines():
            match = _DEFINE_RE.match(line)
            if match:
                names.add(match.group(1))
    return names


def _run_capture(command: Sequence[str]) -> str:
    return subprocess.run(command, check=True, capture_output=True, text=True).stdout


def _config_digest(args: Sequence[str], headers: Sequence[Path]) -> str:
    digest = hashlib.sha256()
    source = _source_path(args)
    assert source is not None
    digest.update(source.stem.encode())
    for value in _include_and_define_args(args):
        digest.update(value.encode())
        digest.update(b"\0")
    for header in headers:
        digest.update(header.name.encode())
        digest.update(header.read_bytes())
    return digest.hexdigest()


def _object_specs(family: str, native_object: Path) -> list[str]:
    base = str(native_object)
    if family == "bpf_lxc":
        return [
            base + ",source_map_prefix=cilium_calls_0",
            base + ",symbol=cil_lxc_policy_egress,source_xlated_len=16,source_lacks_map_prefix=cilium_calls_0",
            base + ",symbol=tail_drop_notify,source_xlated_len=696",
        ]
    if family == "bpf_host":
        return [
            base + ",source_map_prefix=cilium_calls_ho,source_map_prefix=cilium_calls_ne",
            base + ",symbol=cil_host_policy,source_xlated_len=16,source_lacks_map_prefix=cilium_calls_ho,source_lacks_map_prefix=cilium_calls_ne",
            base + ",symbol=tail_drop_notify,source_xlated_len=752",
        ]
    if family == "bpf_overlay":
        return [base + ",source_map_prefix=cilium_calls_ov"]
    if family == "bpf_wireguard":
        return [base + ",source_map_prefix=cilium_calls_wi"]
    if family == "bpf_xdp":
        return [base + ",prog_type=6"]
    return [base]


def _text_symbols(llvm_nm: Path, native_object: Path) -> list[str]:
    output = _run_capture([str(llvm_nm), "--defined-only", "--format=posix", str(native_object)])
    symbols: list[str] = []
    for line in output.splitlines():
        fields = line.split()
        if len(fields) >= 2 and fields[1] in {"T", "t"} and not fields[0].startswith(("LBB", "__check_")):
            symbols.append(fields[0])
    if not symbols:
        raise RuntimeError(f"no native text symbols in {native_object}")
    return symbols


def _write_parity_record(
    *, clang: Path, bpf_args: Sequence[str], native_args: Sequence[str], headers: Sequence[Path],
    compat: Path, native_root: Path, native_source: Path,
    abi_record: Mapping[str, object], output_dir: Path,
    native_extra_defines: Sequence[str] = (),
    paired_config_specialization: Mapping[str, object] | None = None,
) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)
    bpf_macros = _run_capture([
        str(clang), *_macro_dump_args(
            bpf_args, native=False, compat=compat, native_root=native_root,
            native_source=native_source,
        )
    ])
    native_macros = _run_capture([
        str(clang), *_macro_dump_args(
            bpf_args, native=True, compat=compat, native_root=native_root,
            native_source=native_source,
            native_extra_defines=native_extra_defines,
        )
    ])
    (output_dir / "bpf.macros").write_text(bpf_macros, encoding="utf-8")
    (output_dir / "native.macros").write_text(native_macros, encoding="utf-8")
    bpf_baseline = _run_capture([
        str(clang), *_compiler_baseline_macro_args(native=False, compat=compat)
    ])
    native_baseline = _run_capture([
        str(clang), *_compiler_baseline_macro_args(native=True, compat=compat)
    ])
    (output_dir / "bpf.compiler-baseline.macros").write_text(
        bpf_baseline, encoding="utf-8"
    )
    (output_dir / "native.compiler-baseline.macros").write_text(
        native_baseline, encoding="utf-8"
    )
    header_names = _header_macro_names(headers)
    bpf_parsed = _parse_macro_dump(bpf_macros)
    native_parsed = _parse_macro_dump(native_macros)
    bpf_baseline_parsed = _parse_macro_dump(bpf_baseline)
    native_baseline_parsed = _parse_macro_dump(native_baseline)
    compiler_abi_names = {
        name
        for name in set(bpf_baseline_parsed) | set(native_baseline_parsed)
        if bpf_baseline_parsed.get(name) != native_baseline_parsed.get(name)
    }
    full_non_abi_diff = {
        name: {"bpf": bpf_parsed.get(name), "native": native_parsed.get(name)}
        for name in sorted(set(bpf_parsed) | set(native_parsed))
        if bpf_parsed.get(name) != native_parsed.get(name)
        and name not in compiler_abi_names
        and name not in _ABI_DEFINES
        and name not in _ABI_MACROS
    }
    config_diff = {
        name: {"bpf": bpf_parsed.get(name), "native": native_parsed.get(name)}
        for name in sorted(header_names)
        if bpf_parsed.get(name) != native_parsed.get(name)
    }
    define_record = validate_compile_defines(bpf_args, native_args)
    if config_diff:
        raise RuntimeError(f"Cilium generated-header macro mismatch: {json.dumps(config_diff, sort_keys=True)}")
    if full_non_abi_diff:
        raise RuntimeError(
            "Cilium preprocessed macro mismatch outside compiler/native ABI: "
            + json.dumps(full_non_abi_diff, sort_keys=True)
        )
    copied_headers: list[dict[str, str]] = []
    headers_dir = output_dir / "headers"
    headers_dir.mkdir(exist_ok=True)
    for index, header in enumerate(headers):
        destination = headers_dir / f"{index:02d}-{header.name}"
        shutil.copy2(header, destination)
        copied_headers.append(
            {
                "source": str(header),
                "archive": str(destination.relative_to(output_dir)),
                "sha256": hashlib.sha256(header.read_bytes()).hexdigest(),
            }
        )
    record = {
        **define_record,
        "config_header_macro_diff": config_diff,
        "full_non_abi_macro_diff": full_non_abi_diff,
        "compiler_native_abi_macro_names": sorted(compiler_abi_names),
        "allowed_native_abi_macro_names": sorted(_ABI_MACROS),
        "headers": copied_headers,
        "bpf_command": [str(clang), *bpf_args],
        "native_command": [str(clang), *native_args],
        "native_abi": dict(abi_record),
        "paired_config_specialization": dict(paired_config_specialization or {}),
        "status": "pass",
    }
    (output_dir / "parity.json").write_text(json.dumps(record, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def _publish_family_manifest(root: Path, family: str, fragment_path: Path) -> None:
    lock_path = root / "manifest.lock"
    with lock_path.open("a+", encoding="utf-8") as lock_file:
        fcntl.flock(lock_file.fileno(), fcntl.LOCK_EX)
        manifest_path = root / "manifest.json"
        current = json.loads(manifest_path.read_text(encoding="utf-8"))
        fragment = json.loads(fragment_path.read_text(encoding="utf-8"))
        retained = [
            entry for entry in current.get("objects", [])
            if isinstance(entry, dict) and entry.get("config_family") != family
        ]
        additions = []
        fragment_prefix = fragment_path.parent.resolve().relative_to(root.resolve())
        for raw in fragment.get("objects", []):
            entry = dict(raw)
            native_object = Path(str(entry["native_object"]))
            if native_object.is_absolute():
                raise RuntimeError(
                    f"Cilium manifest fragment contains absolute native object: {native_object}"
                )
            entry["native_object"] = str(fragment_prefix / native_object)
            entry["config_family"] = family
            additions.append(entry)
        current.update(
            {
                "version": 1,
                "app": "cilium",
                "status": "runtime-config-paired",
                "objects": retained + additions,
                "map_rules": fragment.get("map_rules", []),
            }
        )
        temporary = manifest_path.with_suffix(".json.tmp")
        temporary.write_text(json.dumps(current, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        os.replace(temporary, manifest_path)


def run_paired_cilium_compile(clang: str, args: Sequence[str]) -> int:
    root = _env_path("BPFREJIT_CILIUM_NATIVE_BUILD_ROOT", "/var/tmp/bpfrejit-cilium-native").resolve()
    compat = _env_path("BPFREJIT_CILIUM_NATIVE_COMPAT", "/usr/local/lib/bpfrejit/native/native_compat.h")
    native_root = _env_path(
        "BPFREJIT_CILIUM_NATIVE_SOURCE_ROOT",
        "/usr/local/lib/bpfrejit/native/cilium-bpf",
    )
    pristine_root = _env_path(
        "BPFREJIT_CILIUM_PRISTINE_SOURCE_ROOT",
        "/usr/local/lib/bpfrejit/native/cilium-bpf-original",
    )
    writer = _env_path("BPFREJIT_CILIUM_NATIVE_MANIFEST_WRITER", "/usr/local/lib/bpfrejit/native/write_native_manifest.py")
    native_link = _env_path("BPFREJIT_NATIVE_LINK_BINARY", "/usr/local/bin/native-link")
    llvm_nm = _env_path("BPFREJIT_CILIUM_LLVM_NM", "/usr/bin/llvm-nm-18")
    for path, label in ((compat, "native compatibility header"), (writer, "manifest writer"), (native_link, "native-link"), (llvm_nm, "llvm-nm")):
        if not path.is_file():
            raise RuntimeError(f"Cilium {label} not found: {path}")
    if not native_root.is_dir():
        raise RuntimeError(f"Cilium native ABI source tree not found: {native_root}")
    if not pristine_root.is_dir():
        raise RuntimeError(f"Cilium pristine source tree not found: {pristine_root}")
    prepare_cilium_native_runtime(root)
    source = _source_path(args)
    assert source is not None
    family = source.stem
    headers = _config_headers(args)
    config_hash = _config_digest(args, headers)
    variant_dir = root / "objects" / family / config_hash
    variant_dir.mkdir(parents=True, exist_ok=True)
    bpf_object = variant_dir / f"{config_hash}.o"
    native_object = variant_dir / f"{config_hash}.native.o"
    original_output_stdout = _output_is_stdout(args)
    original_command = [clang, *_replace_output(args, bpf_object)]
    subprocess.run(original_command, check=True)
    native_extra_defines: list[str] = []
    paired_config_specialization: dict[str, object] = {}
    if family in {"bpf_host", "bpf_lxc"}:
        hybrid = _bpf_config_scalar(
            bpf_object, "__config_hybrid_routing_enabled"
        )
        value = int(hybrid["value"])
        if value not in {0, 1}:
            raise RuntimeError(
                f"Cilium hybrid_routing_enabled must be boolean, got {value}"
            )
        native_extra_defines.append(
            f"-DBPFBENCH_CILIUM_HYBRID_ROUTING_ENABLED={value}"
        )
        paired_config_specialization["hybrid_routing_enabled"] = hybrid
    parity_dir = root / "parity" / family / config_hash
    abi_record = _audit_native_abi_tree(pristine_root, native_root, parity_dir)
    native_overlay = _make_native_abi_overlay(source.parent, native_root, parity_dir)
    native_source = native_overlay / source.name
    if not native_source.is_file():
        raise RuntimeError(f"Cilium source missing from runtime ABI overlay: {native_source}")
    native_args = native_compile_args(
        args, native_object, compat, native_overlay, native_source,
        native_extra_defines,
    )
    _write_parity_record(
        clang=Path(clang), bpf_args=list(args), native_args=native_args,
        headers=headers, compat=compat, native_root=native_overlay,
        native_source=native_source,
        abi_record=abi_record, output_dir=parity_dir,
        native_extra_defines=native_extra_defines,
        paired_config_specialization=paired_config_specialization,
    )
    subprocess.run([clang, *native_args], check=True)
    for symbol in _text_symbols(llvm_nm, native_object):
        proof = variant_dir / f"{config_hash}.{symbol}.proof.o"
        subprocess.run(
            [str(native_link), "--input", str(native_object), "--symbol", symbol,
             "--output", str(proof), "--mode", "proof", "--preserve-entry-abi"],
            check=True,
        )
    fragment = variant_dir / "manifest.fragment.json"
    command = [
        "python3", str(writer), "--app", "cilium", "--llvm-nm", str(llvm_nm),
        "--output", str(fragment), "--source-object-root", str(variant_dir),
        "--include-local-source-programs",
    ]
    for spec in _object_specs(family, native_object):
        command.extend(("--object", spec))
    subprocess.run(command, check=True)
    _publish_family_manifest(root, family, fragment)
    if original_output_stdout:
        sys.stdout.buffer.write(bpf_object.read_bytes())
        sys.stdout.buffer.flush()
    else:
        requested = None
        for index, arg in enumerate(args):
            if arg == "-o" and index + 1 < len(args):
                requested = Path(args[index + 1])
            elif arg.startswith("-o") and len(arg) > 2:
                requested = Path(arg[2:])
        if requested is None:
            raise RuntimeError("Cilium compile command has no output")
        requested.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(bpf_object, requested)
    return 0
