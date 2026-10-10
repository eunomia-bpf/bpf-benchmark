from __future__ import annotations

import json
import importlib.util
from pathlib import Path

import pytest

from runner.libs.cilium_native_build import (
    _ABI_MACROS,
    _ABI_PATCH_PATHS,
    _audit_native_abi_tree,
    _config_headers,
    _make_native_abi_overlay,
    _publish_family_manifest,
    _read_unsigned_scalar,
    native_compile_args,
    prepare_cilium_native_runtime,
    validate_compile_defines,
)


def test_native_abi_macro_allowlist_excludes_datapath_configuration() -> None:
    assert {
        "CILIUM_HYBRID_ROUTING_ENABLED",
        "CONFIG",
        "map_lookup_elem",
        "tail_call_static",
    } <= _ABI_MACROS
    assert not {
        "ENABLE_HOST_FIREWALL",
        "ENABLE_DSR",
        "MONITOR_AGGREGATION",
        "CT_REPORT_FLAGS",
        "POLICY_AUDIT_MODE",
    } & _ABI_MACROS


def test_hybrid_routing_native_alias_preserves_all_config_reads() -> None:
    original = Path("vendor/repos/cilium/bpf").resolve()
    native = Path("vendor/bpf/cilium/bpf").resolve()
    original_reads = sum(
        (original / source).read_text(encoding="utf-8").count(
            "CONFIG(hybrid_routing_enabled)"
        )
        for source in ("bpf_host.c", "bpf_lxc.c")
    )
    native_reads = sum(
        (native / source).read_text(encoding="utf-8").count(
            "CILIUM_HYBRID_ROUTING_ENABLED"
        )
        for source in ("bpf_host.c", "bpf_lxc.c")
    )
    subnet = (native / "lib/subnet.h").read_text(encoding="utf-8")
    assert original_reads == native_reads == 4
    assert (
        "#define CILIUM_HYBRID_ROUTING_ENABLED CONFIG(hybrid_routing_enabled)"
        in subnet
    )


def test_cilium_manifest_accepts_local_tail_call_entry_symbols() -> None:
    script = Path("vendor/bpf/write_native_manifest.py").resolve()
    spec = importlib.util.spec_from_file_location("write_native_manifest", script)
    assert spec is not None and spec.loader is not None
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    assert module.source_symbol_binding_allowed("STB_LOCAL", include_local=True)
    assert not module.source_symbol_binding_allowed("STB_LOCAL", include_local=False)
    assert module.source_symbol_binding_allowed("STB_GLOBAL", include_local=True)


def test_native_compile_preserves_generated_include_and_feature_defines(tmp_path: Path) -> None:
    source = tmp_path / "bpf_host.c"
    source.write_text("int x;\n", encoding="utf-8")
    compat = tmp_path / "native_compat.h"
    compat.write_text("\n", encoding="utf-8")
    native_root = tmp_path / "native-source"
    native_root.mkdir()
    native_source = native_root / "bpf_host.c"
    native_source.write_text("int x;\n", encoding="utf-8")
    output = tmp_path / "bpf_host.native.o"
    original = [
        "-I", "/run/cilium/state/globals", "-I/run/cilium/state/device",
        "-I", str(tmp_path),
        "-DENABLE_IPV4=1", "--target=bpf", "-mcpu=v3", "-c", str(source), "-o", "-",
    ]
    native = native_compile_args(
        original,
        output,
        compat,
        native_root,
        native_source,
        ["-DBPFBENCH_CILIUM_HYBRID_ROUTING_ENABLED=0"],
    )
    assert "/run/cilium/state/globals" in native
    assert "-I/run/cilium/state/device" in native
    assert "-DENABLE_IPV4=1" in native
    assert "--target=bpf" not in native
    assert "-DMICRO_NATIVE" in native
    assert "-D__TARGET_ARCH_x86" in native
    assert "-DBPFBENCH_CILIUM_HYBRID_ROUTING_ENABLED=0" in native
    assert str(native_root) in native
    assert native[-1] == str(native_source)


def test_paired_config_scalar_decoding_is_bounds_checked() -> None:
    assert _read_unsigned_scalar(bytes.fromhex("00123400"), 1, 2) == 0x3412
    with pytest.raises(RuntimeError, match="exceeds section size"):
        _read_unsigned_scalar(b"\x00", 1, 1)
    with pytest.raises(RuntimeError, match="unsupported"):
        _read_unsigned_scalar(b"\x00\x00\x00", 0, 3)


def test_generated_header_resolution_uses_first_include_match(tmp_path: Path) -> None:
    generated = tmp_path / "generated"
    stale = tmp_path / "stale"
    generated.mkdir()
    stale.mkdir()
    (generated / "node_config.h").write_text("#define ENABLE_IPV4 1\n", encoding="utf-8")
    (stale / "node_config.h").write_text("#define ENABLE_HOST_FIREWALL 1\n", encoding="utf-8")
    headers = _config_headers(["-I", str(generated), "-I", str(stale)])
    assert headers == [(generated / "node_config.h").resolve()]


def test_native_abi_tree_has_only_audited_pinned_source_differences(tmp_path: Path) -> None:
    original = Path("vendor/repos/cilium/bpf").resolve()
    native = Path("vendor/bpf/cilium/bpf").resolve()
    record = _audit_native_abi_tree(original, native, tmp_path)
    assert {
        item["path"] for item in record["audited_changed_paths"]
    } == _ABI_PATCH_PATHS
    assert record["feature_defines_added"] == []


def test_native_abi_overlay_preserves_runtime_tree_and_overwrites_only_patches(tmp_path: Path) -> None:
    runtime = tmp_path / "runtime"
    (runtime / "include/bpf/ctx").mkdir(parents=True)
    (runtime / "include/bpf").mkdir(parents=True, exist_ok=True)
    (runtime / "include/bpf/features.h").write_text("#define RUNTIME_PROBE 1\n", encoding="utf-8")
    (runtime / "bpf_xdp.c").write_text("int runtime_xdp;\n", encoding="utf-8")
    native = Path("vendor/bpf/cilium/bpf").resolve()
    overlay = _make_native_abi_overlay(runtime, native, tmp_path)
    assert (overlay / "include/bpf/ctx/xdp.h").is_file()
    assert (overlay / "bpf_xdp.c").read_text(encoding="utf-8") == "int runtime_xdp;\n"
    assert (overlay / "include/bpf/features.h").read_text(encoding="utf-8") == "#define RUNTIME_PROBE 1\n"


def test_define_parity_rejects_hardcoded_datapath_feature() -> None:
    with pytest.raises(RuntimeError, match="ENABLE_HOST_FIREWALL"):
        validate_compile_defines(
            ["-DENABLE_IPV4=1"],
            ["-DENABLE_IPV4=1", "-DENABLE_HOST_FIREWALL=1", "-DMICRO_NATIVE"],
        )


def test_define_parity_allows_only_native_abi_defines() -> None:
    record = validate_compile_defines(
        ["-DPOLICY_AUDIT_MODE=1"],
        ["-DPOLICY_AUDIT_MODE=1", "-DMICRO_NATIVE", "-D__TARGET_ARCH_x86"],
    )
    assert record["non_abi_define_diff"] == {}


def test_family_manifest_update_replaces_only_same_configuration_family(tmp_path: Path) -> None:
    prepare_cilium_native_runtime(tmp_path)
    first = tmp_path / "first.json"
    first.write_text(
        json.dumps({"objects": [{"program": "cil_from_host", "native_object": "a.o"}], "map_rules": [{"match": "exact"}]})
        + "\n",
        encoding="utf-8",
    )
    _publish_family_manifest(tmp_path, "bpf_host", first)
    second = tmp_path / "second.json"
    second.write_text(
        json.dumps({"objects": [{"program": "cil_from_contai", "native_object": "b.o"}], "map_rules": [{"match": "prefix"}]})
        + "\n",
        encoding="utf-8",
    )
    _publish_family_manifest(tmp_path, "bpf_lxc", second)
    replacement = tmp_path / "replacement.json"
    replacement.write_text(
        json.dumps({"objects": [{"program": "cil_to_host", "native_object": "c.o"}], "map_rules": [{"match": "suffix"}]})
        + "\n",
        encoding="utf-8",
    )
    _publish_family_manifest(tmp_path, "bpf_host", replacement)
    manifest = json.loads((tmp_path / "manifest.json").read_text(encoding="utf-8"))
    assert [(item["config_family"], item["native_object"]) for item in manifest["objects"]] == [
        ("bpf_lxc", "b.o"),
        ("bpf_host", "c.o"),
    ]
    assert manifest["map_rules"] == [{"match": "suffix"}]


def test_family_manifest_rebases_nested_fragment_object_paths(tmp_path: Path) -> None:
    prepare_cilium_native_runtime(tmp_path)
    nested = tmp_path / "objects" / "bpf_xdp" / "hash"
    nested.mkdir(parents=True)
    fragment = nested / "manifest.fragment.json"
    fragment.write_text(
        json.dumps({"objects": [{"program": "cil_xdp_entry", "native_object": "hash.native.o"}]})
        + "\n",
        encoding="utf-8",
    )
    _publish_family_manifest(tmp_path, "bpf_xdp", fragment)
    manifest = json.loads((tmp_path / "manifest.json").read_text(encoding="utf-8"))
    assert manifest["objects"][0]["native_object"] == "objects/bpf_xdp/hash/hash.native.o"
