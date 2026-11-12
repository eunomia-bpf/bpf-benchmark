#!/usr/bin/env python3
"""Build one application's native objects with its frozen .rodata as constants.

Build-time form of the load-time specialization. The .rodata bytes the loader
finds in a program's .rodata map are captured once, from a real run
(native_capture_rodata.py); every native object of the application is then
rebuilt with those values as plain constants, so clang folds the reads and the
branches the configuration values decide -- the same folds the verifier does on
the eBPF side.

The value of a global is the bytes the loaded .rodata image holds at that
global's offset in the native object: the loader patches each native .rodata
symbol to map_value_addr + native offset, so the native object's own layout is
what the loaded image is indexed by. When the object's .rodata is larger than
the map value the loader keeps the object's own copy, and then the constant is
the object's initializer as it stands.

Every object is built twice: once with the Makefile's own source and flags
(<stem>.plain.o, the switch-off path) and once from the specialized unit
(<stem>.rodata.o). The difference between the two is the specialization's
effect.

Usage: native_specialize_objects.py --app tracee \
           --capture <run dir>/details/map-snapshots/<app> \
           --bpf-object <the app's .bpf.o> --output <dir> [--only <stem>...]
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
HERE = Path(__file__).resolve().parent

NATIVE_CFLAGS = [
    "-O3", "-g", "-fPIC", "-c", "-DMICRO_NATIVE", "-fomit-frame-pointer",
    "-march=native", "-mno-red-zone", "-mgeneral-regs-only",
    "-fno-stack-protector", "-fno-asynchronous-unwind-tables",
    "-fno-unwind-tables", "-fno-jump-tables", "-fno-optimize-sibling-calls",
    "-Wno-unknown-attributes", "-mllvm", "-switch-to-lookup=false",
]


def bcc_tools() -> list[str]:
    return ["capable", "biosnoop", "vfsstat", "opensnoop", "syscount",
            "tcpconnect", "tcplife", "runqlat"]


def tetragon_variants() -> list[tuple[str, str, str, list[str]]]:
    """The objects the image ships, with the flags the Makefile gives each.

    The Makefile builds every kernel variant; the manifest names 35 of them, and
    the ones that carry configuration are the _v511/_v61 variants.
    """
    process = "process"
    large = ["-D__LARGE_BPF_PROG"]
    v511 = large + ["-D__V511_BPF_PROG"]
    v61 = v511 + ["-D__V61_BPF_PROG"]
    out: list[tuple[str, str, str, list[str]]] = []
    for name in ("bpf_loader", "bpf_cgroup", "bpf_prog_iter", "bpf_execve_event",
                 "bpf_fork", "bpf_exit", "bpf_execve_bprm_commit_creds",
                 "bpf_generic_kprobe", "bpf_generic_retkprobe",
                 "bpf_generic_tracepoint", "bpf_generic_uprobe",
                 "bpf_generic_retuprobe", "bpf_generic_rawtp", "bpf_generic_usdt",
                 "bpf_generic_fentry", "bpf_generic_fexit", "bpf_execve_map_update"):
        out.append((name, process, name, []))
    for name in ("bpf_execve_event", "bpf_execve_map_update", "bpf_generic_kprobe",
                 "bpf_generic_retkprobe", "bpf_generic_tracepoint",
                 "bpf_generic_uprobe", "bpf_generic_retuprobe", "bpf_generic_rawtp",
                 "bpf_generic_usdt", "bpf_generic_fentry", "bpf_generic_fexit",
                 "bpf_generic_lsm_core", "bpf_generic_lsm_output",
                 "bpf_generic_lsm_ima_file", "bpf_generic_lsm_ima_bprm"):
        out.append((f"{name}_v511", process, name, v511))
    for name in ("bpf_execve_event", "bpf_execve_map_update", "bpf_generic_kprobe",
                 "bpf_generic_retkprobe", "bpf_generic_tracepoint",
                 "bpf_generic_uprobe", "bpf_generic_retuprobe", "bpf_generic_rawtp",
                 "bpf_generic_usdt", "bpf_generic_fentry", "bpf_generic_fexit",
                 "bpf_generic_lsm_core", "bpf_generic_lsm_output",
                 "bpf_generic_lsm_ima_file", "bpf_generic_lsm_ima_bprm"):
        out.append((f"{name}_v61", process, name, v61))
    for pair, extra in ((("bpf_multi_kprobe_v61", "bpf_generic_kprobe"), v61),
                         (("bpf_multi_retkprobe_v61", "bpf_generic_retkprobe"), v61),
                         (("bpf_multi_uprobe_v61", "bpf_generic_uprobe"), v61),
                         (("bpf_multi_retuprobe_v61", "bpf_generic_retuprobe"), v61),
                         (("bpf_multi_usdt_v61", "bpf_generic_usdt"), v61)):
        out.append((pair[0], process, pair[1], extra + ["-D__MULTI_KPROBE"]))
    # One source, several programs: the enforcer is compiled three ways and the
    # _v511/_v61 objects reuse a plain source with a kernel-version define.
    for name, extra in (("bpf_enforcer", ["-D__BPF_OVERRIDE_RETURN"]),
                        ("bpf_fmodret_enforcer", []),
                        ("bpf_multi_enforcer", ["-D__BPF_OVERRIDE_RETURN",
                                                 "-D__MULTI_KPROBE"])):
        out.append((name, process, "bpf_enforcer", extra))
    for name in ("bpf_exit", "bpf_fork", "bpf_loader"):
        out.append((f"{name}_v511", process, name, v511))
    out.append(("bpf_multi_usdt_v511", process, "bpf_generic_usdt",
                v511 + ["-D__MULTI_KPROBE"]))
    for name in ("bpf_cgroup_mkdir", "bpf_cgroup_rmdir", "bpf_cgroup_release"):
        out.append((name, "cgroup", name, []))
        out.append((f"{name}_v511", "cgroup", name, v511))
    out.append(("bpf_cgtracker", "cgroup", "bpf_cgtracker", []))
    return out


def units_for_app(app: str) -> list[tuple[str, Path, list[str]]]:
    """(stem, source, flags) for each native object the image carries."""
    bpf = ROOT / "vendor" / "bpf"
    if app == "bcc":
        flags = [f"-include", str(bpf / "native_compat.h"),
                 f"-I{bpf}/bcc/libbpf-tools", f"-I{bpf}/bcc/libbpf-tools/x86",
                 f"-I{bpf}/bcc/src/cc/libbpf/include/uapi",
                 "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        return [(tool, bpf / f"bcc/libbpf-tools/{tool}.bpf.c", flags)
                for tool in bcc_tools()]
    if app == "cilium":
        # The Makefile gives each object its own options (XDP drops
        # ENABLE_NODEPORT_ACCELERATION, host drops ENABLE_HOST_FIREWALL, ...),
        # and a run loads the object compiled with the options the image used.
        base = ["-DSKIP_DEBUG=1", "-DENABLE_IPV4=1", "-DENABLE_ROUTING=1",
                "-DPOLICY_VERDICT_NOTIFY=1", "-DMONITOR_AGGREGATION=3",
                "-DCT_REPORT_FLAGS=0x0002", "-DENABLE_HOST_FIREWALL=1",
                "-DENABLE_MASQUERADE_IPV4=1", "-DENABLE_NODEPORT=1",
                "-DENABLE_NODEPORT_ACCELERATION=1", "-DENABLE_DSR_ICMP_ERRORS=1",
                "-DENABLE_DSR=1", "-DENABLE_DSR_BYUSER=1",
                "-DENABLE_HOST_ROUTING=1", "-DSERVICE_NO_BACKEND_RESPONSE=1"]
        def without(*drop):
            return [flag for flag in base if flag not in drop]
        lb = ["-DLB_SELECTION_PER_SERVICE=1", "-DLB_SELECTION_MAGLEV=2",
              "-DLB_SELECTION_RANDOM=1"]
        per_object = {
            "bpf_lxc": base + ["-DENCAP_IFINDEX=1"],
            "bpf_overlay": base + ["-DENCAP_IFINDEX=1", "-DTUNNEL_MODE=1"] + lb,
            "bpf_sock": base + ["-DENCAP_IFINDEX=1", "-DTUNNEL_MODE=1"] + lb,
            "bpf_host": without("-DENABLE_HOST_FIREWALL=1") + ["-DENCAP_IFINDEX=1"],
            "bpf_wireguard": base + ["-DENCAP_IFINDEX=1", "-DTUNNEL_MODE=1",
                                     "-DENABLE_WIREGUARD=1"],
            "bpf_xdp": without("-DENABLE_NODEPORT_ACCELERATION=1") + lb,
        }
        include = [f"-include", str(bpf / "native_compat.h"),
                   f"-I{bpf}/cilium/bpf", f"-I{bpf}/cilium/bpf/include",
                   f"-I{bpf}/cilium/bpf/include/bpf",
                   f"-I{bpf}/cilium/bpf/include/linux",
                   f"-I{bpf}/cilium/bpf/lib",
                   "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        # bpf_alignchecker.c guards itself with "policy_log.h only supports
        # inclusion from bpf_host or bpf_lxc", so it only compiles inside those
        # programs; it carries no configuration of its own.
        return [(name, bpf / f"cilium/bpf/{name}.c", options + include)
                for name, options in per_object.items()]
    if app == "tetragon":
        # The Makefile's tetragon common_flags, in its own order.
        common = ["-fms-extensions", "-DMICRO_NATIVE_HELPER_MACROS",
                  "-DMICRO_NATIVE_TETRAGON", "-D__TARGET_ARCH_x86",
                  "-include", str(bpf / "native_compat.h"),
                  f"-I{bpf}/tetragon/bpf", f"-I{bpf}/tetragon/bpf/include",
                  f"-I{bpf}/tetragon/bpf/lib", f"-I{bpf}/tetragon/bpf/libbpf",
                  f"-I{bpf}/tetragon/bpf/process", f"-I{bpf}/tetragon/bpf/errmetrics",
                  "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        return [(name, bpf / f"tetragon/bpf/{subdir}/{src}.c", common + extra)
                for name, subdir, src, extra in tetragon_variants()]
    if app == "tracee":
        flags = [f"-include", str(bpf / "native_compat.h"),
                 "-DMICRO_NATIVE_HELPER_MACROS", "-D__TARGET_ARCH_x86",
                 "-D__BPF_TRACING__", "-DCORE", "-DCOMMON_BUILD",
                 f"-I{bpf}/tracee/pkg/ebpf/c",
                 "-I/usr/include", "-I/usr/include/x86_64-linux-gnu"]
        units = [("tracee", bpf / "tracee/pkg/ebpf/c/tracee.bpf.c", flags)]
        for name in ("kprobe_check", "lsm_check"):
            units.append((f"lsm_support/{name}",
                          bpf / f"tracee/pkg/ebpf/c/lsmsupport/{name}.bpf.c",
                          flags + [f"-I{bpf}/tracee/pkg/ebpf/c/lsmsupport"]))
        return units
    raise SystemExit(f"native_specialize_objects: no object list for {app}")


def section_symbols(object_path: Path, section_prefix: str) -> dict[str, tuple[str, int, int]]:
    """name -> (section, offset in section, size) for objects in a section."""
    out = subprocess.run(["readelf", "-SW", str(object_path)],
                         capture_output=True, text=True).stdout
    sections: dict[int, tuple[str, int, int]] = {}
    for m in re.finditer(r"^\s*\[\s*(\d+)\]\s+(\S+)\s+(\S+)\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)",
                         out, re.M):
        sections[int(m.group(1))] = (m.group(2), int(m.group(4), 16), int(m.group(6), 16))
    symbols = subprocess.run(["readelf", "-sW", str(object_path)],
                             capture_output=True, text=True).stdout
    found: dict[str, tuple[str, int, int]] = {}
    for line in symbols.splitlines():
        fields = line.split()
        if len(fields) < 8 or not fields[0].endswith(":") or not fields[6].isdigit():
            continue
        if fields[3] != "OBJECT":
            continue
        section = sections.get(int(fields[6]))
        if not section or not section[0].startswith(section_prefix):
            continue
        found.setdefault(fields[7], (section[0], int(fields[1], 16) - section[1],
                                     int(fields[2])))
    return found


def captured_map_shapes(capture: Path) -> tuple[dict[str, int], dict[str, int]]:
    """Map name -> value size and key size, from the load-time capture.

    The capture records each program's maps with the sizes the loader saw, which
    is the layout a lookup body needs; the map declarations in the program give
    the kind and entry count but not the sizes of the value types they alias.
    """
    values: dict[str, int] = {}
    keys: dict[str, int] = {}
    for ref in sorted(capture.glob("*/ref.json")):
        meta = json.loads(ref.read_text())
        name = meta.get("map_name", "")
        if not name:
            continue
        if meta.get("value_size"):
            values[name] = int(meta["value_size"])
        if meta.get("key_size"):
            keys[name] = int(meta["key_size"])
    return values, keys


def loaded_rodata(capture: Path) -> dict[str, bytes]:
    """Tool name -> the .rodata image of the programs that read it.

    Each BCC tool names its .rodata map "<tool>.rodata"; the tracee object
    names it ".rodata". The map name is the join key between a captured
    program and the object built from the same source.
    """
    values: dict[str, bytes] = {}
    for ref in sorted(capture.glob("*/ref.json")):
        meta = json.loads(ref.read_text())
        map_name = meta.get("map_name", "")
        if not map_name.startswith(".rodata"):
            continue
        dump = ref.parent / "map-values" / f"map-{meta['map_id']}.dump.json"
        if not dump.exists():
            continue
        entries = json.loads(dump.read_text())
        if not entries or "value" not in entries[0]:
            continue
        image = bytes(int(byte, 16) for byte in entries[0]["value"])
        # ".rodata" and ".rodata.<variant>" (cilium's .rodata.config) both name
        # the program's own configuration map; "<tool>.rodata" is a BCC tool's.
        tool = map_name[: -len(".rodata")] if map_name.endswith(".rodata") \
            and not map_name.startswith(".rodata") else ""
        # Programs of one BPF object all read the same image; cilium's objects
        # each carry their own, and the first one seen is the layout its
        # .rodata symbols are patched against.
        values.setdefault(tool, image)
    return values


def plain_rodata_bytes(object_path: Path, section: str = ".rodata") -> bytes:
    """The object's own contents of one .rodata section.

    The loader patches each native .rodata symbol to map_value_addr + its offset
    in the section, so the constants are the bytes the plain object carries
    there. Cilium's configuration lives in .rodata.config and the plain-array
    maps in .rodata, so the section is named.
    """
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    for m in re.finditer(
            r"^\s*\[\s*\d+\]\s+" + re.escape(section) +
            r"\s+PROGBITS\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)",
            sections, re.M):
        offset, size = int(m.group(1), 16), int(m.group(2), 16)
        with open(object_path, "rb") as handle:
            handle.seek(offset)
            return handle.read(size)
    return b""


def plain_rodata_section(object_path: Path) -> str:
    """The .rodata section holding the configuration globals, by its symbols."""
    out = subprocess.run(["readelf", "-SW", str(object_path)],
                         capture_output=True, text=True).stdout
    names = [m.group(1) for m in re.finditer(
        r"^\s*\[\s*\d+\]\s+(\.rodata\S*)\s+PROGBITS", out, re.M)]
    for preferred in (".rodata.config", ".rodata.var", ".rodata"):
        if preferred in names:
            return preferred
    return names[0] if names else ".rodata"


def plain_rodata_size(object_path: Path) -> int:
    """Bytes of the object's .rodata section, the loader's fit test."""
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    for m in re.finditer(
            r"^\s*\[\s*\d+\]\s+\.rodata\s+\S+\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)",
            sections, re.M):
        return int(m.group(1), 16)
    return 0


def program_sizes(object_path: Path) -> dict[str, int]:
    """Executable section name -> bytes, one entry per BPF program."""
    sections = subprocess.run(["readelf", "-SW", str(object_path)],
                              capture_output=True, text=True).stdout
    return {m.group(1): int(m.group(2), 16) for m in re.finditer(
        r"^\s*\[\s*\d+\]\s+(\S+)\s+PROGBITS\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)\s+\S+\s+AX",
        sections, re.M)}


def run(argv: list[str]) -> None:
    result = subprocess.run(argv, capture_output=True, text=True)
    if result.returncode != 0:
        sys.stderr.write(result.stderr[-4000:])
        raise SystemExit(f"failed: {' '.join(argv[:4])} ...")


def publish_manifest(app: str, output: Path, published: dict[str, str],
                     image_manifest: Path) -> None:
    """Name the specialized objects as the loader expects and write the manifest.

    The image's manifest lists one entry per program, each naming the object the
    loader maps it from; replacing that file with the specialized one and
    pointing every entry at the new name is all a run needs.
    """
    if not image_manifest.is_file():
        sys.exit(f"--manifest: {image_manifest} is not a file")
    manifest = json.loads(image_manifest.read_text())
    shipped = {Path(entry["native_object"]).name.replace(".native.o", "")
               for entry in manifest["objects"]}
    missing = sorted(shipped - set(published))
    if missing:
        sys.exit(f"{app}: {len(missing)} objects the manifest ships were not "
                 f"specialized: {missing}")
    for stem, path in published.items():
        target = output / f"{stem}.native.o"
        if Path(path).resolve() != target.resolve():
            target.write_bytes(Path(path).read_bytes())
    kept, dropped = [], set()
    for entry in manifest["objects"]:
        stem = Path(entry["native_object"]).name.replace(".native.o", "")
        if stem in published:
            kept.append(entry)
        else:
            dropped.add(entry["native_object"])
    manifest["objects"] = kept
    manifest["status"] = "specialized"
    (output / "manifest.json").write_text(json.dumps(manifest, indent=1) + "\n")
    print(f"{app}: manifest {len(kept)} entries over {len(published)} objects"
          + (f", {len(dropped)} objects left out: {sorted(dropped)}" if dropped else ""),
          file=sys.stderr)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--app", required=True)
    parser.add_argument("--capture", required=True)
    parser.add_argument("--bpf-objects", default="",
                        help="directory of <stem>.bpf.o inputs")
    parser.add_argument("--output", required=True)
    parser.add_argument("--only", nargs="*", default=[])
    parser.add_argument("--publish", action="store_true",
                        help="name each specialized object <stem>.native.o and "
                             "write the manifest a run loads it through")
    parser.add_argument("--manifest", default="",
                        help="the image's own manifest, copied when publishing")
    parser.add_argument("--maps", action="store_true",
                        help="also give bpf_map_lookup_elem a C body built from "
                             "the load-time map layout (native_specialize_maps.py)")
    parser.add_argument("--maps-hash", action="store_true",
                        help="with --maps, lower hash lookups too")
    parser.add_argument("--maps-type-sizes", action="store_true",
                        help="with --maps, size a map's value type from the unit "
                             "when the capture did not record that map")
    args = parser.parse_args()

    capture = Path(args.capture)
    output = Path(args.output).resolve()
    output.mkdir(parents=True, exist_ok=True)
    bpf_objects = Path(args.bpf_objects)
    loaded = loaded_rodata(capture)
    print(f"{args.app}: {len(loaded)} captured .rodata maps under {capture.name}",
          file=sys.stderr)

    # Every program of one BPF object reads the same .rodata globals, so the
    # values are identical across the captured programs; verify that, then use
    # the single image the object's own offsets index.
    if not loaded:
        raise SystemExit(f"no captured .rodata image under {capture}")

    published: dict[str, str] = {}
    for stem, source, flags in units_for_app(args.app):
        if args.only and stem not in args.only:
            continue
        tool = Path(stem).name
        if tool not in loaded and "" in loaded:
            # An object whose programs name their map ".rodata" (tracee) has a
            # single image, selected by the empty tool name.
            tool = ""
        if tool not in loaded:
            # BPF object names are truncated to 15 characters, so the map is
            # "<first 7 characters>.rodata"; match on that as well.
            short = tool[:7]
            match = [name for name in loaded if name and name[:7] == short]
            if len(match) == 1:
                tool = match[0]
        if tool not in loaded:
            print(f"{stem:22} no captured .rodata map", file=sys.stderr)
            continue
        reference = loaded[tool]
        directory = output / Path(stem).parent
        directory.mkdir(parents=True, exist_ok=True)
        base = directory / Path(stem).name
        plain = base.with_suffix(".plain.o")
        run(["clang-18", *NATIVE_CFLAGS, *flags, "-o", str(plain), str(source)])
        section = plain_rodata_size(plain)
        if section > len(reference):
            print(f"{stem:22} .rodata {section} > map value {len(reference)}; "
                  f"the object keeps its own copy", file=sys.stderr)

        section_name = plain_rodata_section(plain)
        unit = base.with_suffix(".unit.i")
        index = base.with_suffix(".decls.json")
        run([sys.executable, str(HERE / "native_specialize_prepares.py"),
             "--object", str(plain), "--output-dir", str(directory),
             "--", "clang-18", *NATIVE_CFLAGS, *flags, str(source)])
        # The prepares step names the unit after the object it read.
        produced_unit = directory / f"{Path(stem).name}.i"
        produced_index = produced_unit.with_suffix(".decls.json")

        # The loader indexes the loaded image by the plain object's .rodata
        # offsets, so the constants come from the plain object's own section.
        rodata_file = directory / f"{base.name}.rodata.bin"
        rodata_file.write_bytes(plain_rodata_bytes(plain, section_name))
        specialized = base.with_suffix(".rodata.i")
        run([sys.executable, str(HERE / "native_specialize.py"),
             "--unit", str(produced_unit), "--decls", str(produced_index),
             "--rodata", str(rodata_file), "--output", str(specialized)])
        if args.maps:
            # The map layout is known here, so the lookup becomes address
            # arithmetic before clang compiles the caller and the NULL check,
            # field offsets and branches fold through it.
            mapped = base.with_suffix(".maps.i")
            value_sizes, key_sizes = captured_map_shapes(capture)
            shapes = directory / f"{Path(stem).name}.map-shapes.json"
            keys_file = directory / f"{Path(stem).name}.map-keys.json"
            shapes.write_text(json.dumps(value_sizes))
            keys_file.write_text(json.dumps(key_sizes))
            maps_argv = [sys.executable, str(HERE / "native_specialize_maps.py"),
                         "--unit", str(specialized), "--output", str(mapped),
                         "--value-sizes", str(shapes),
                         "--key-sizes", str(keys_file)]
            if args.maps_hash:
                maps_argv.append("--hash")
            if args.maps_type_sizes:
                maps_argv.append("--type-sizes")
            run(maps_argv)
            specialized = mapped
        spec_object = base.with_suffix(".rodata.o")
        # The unit is preprocessed, so only the language flags the compile
        # needs (-fms-extensions for tetragon's struct filename) apply.
        language = [arg for arg in flags if arg.startswith("-fms-extensions")]
        run(["clang-18", *NATIVE_CFLAGS, *language, str(specialized),
             "-o", str(spec_object)])

        before, after = program_sizes(plain), program_sizes(spec_object)
        changed = [(name, before[name], after.get(name, 0)) for name in before
                   if before[name] != after.get(name, 0)]
        total = sum(before.values()), sum(after.values())
        print(f"{stem:22} code {total[0]:>7} -> {total[1]:>7}  "
              f"({len(changed)} of {len(before)} programs changed)", file=sys.stderr)
        if args.publish:
            # A run loads the file its manifest names "native_object", so the
            # specialized object takes that name.
            published[Path(stem).name] = str(spec_object)

    if args.publish:
        publish_manifest(args.app, output, published, Path(args.manifest))


if __name__ == "__main__":
    main()