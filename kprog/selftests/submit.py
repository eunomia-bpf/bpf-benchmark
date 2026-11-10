#!/usr/bin/env python3
"""Submit compiled native selftests with their maps and program context.

Each object opens with every program's autoload disabled. Libbpf creates the
maps and BTF; temporary map pins and SUBMIT_RESOURCES retain their capabilities
through the native outcome. The request carries native P, source_prog_id 0 and
the object's load context. The common service generates B from the kernel copy.

The agreement table uses the installed stage for __success and stock-verifier
rejection for __failure. Generation, resource and transport outcomes retain
their coverage stages. Installed __failure rows count as findings.
"""
import argparse
import contextlib
import ctypes as c
import errno
import fcntl
import hashlib
import json
import os
import pathlib
import subprocess
import sys
import tarfile
import tempfile
import threading
import traceback

ROOT = pathlib.Path(__file__).resolve().parents[2]
DEFAULT_TABLE = ROOT / "kprog/selftests/build"
sys.path.insert(0, str(ROOT / "kprog"))
from trusted_service import Request, Result, ioctl


class Submission(c.Structure):
    _fields_ = [("request", Request), ("map_count", c.c_uint32),
                ("reserved", c.c_uint32), ("map_fds_user", c.c_uint64)]


class MapInfo(c.Structure):
    _fields_ = [(name, c.c_uint32) for name in
                ("map_type", "map_id", "key_size", "value_size",
                 "max_entries", "map_flags")]


class BtfInfo(c.Structure):
    _fields_ = [("btf", c.c_uint64), ("btf_size", c.c_uint32),
                ("id", c.c_uint32), ("name", c.c_uint64),
                ("name_len", c.c_uint32), ("kernel_btf", c.c_uint32)]


SUBMIT = (3 << 30) | (c.sizeof(Submission) << 16) | (ord("N") << 8) | 0x77
WAIT = (2 << 30) | (c.sizeof(Result) << 16) | (ord("N") << 8) | 0x74


def tools_for_arch(arch):
    if arch == "arm64":
        return (ROOT / "runner/build-arm64-llvmbpf/native_loader",
                ROOT / "kprog/arm64/build/app-native-link/"
                       "aarch64-unknown-linux-gnu/release/native-link")
    return (ROOT / "kprog/libnativeloader/build",
            ROOT / "kprog/x86/native_lab/native_link/target/release/native-link")


def run(cmd, cwd=None, timeout=120):
    """Keep each direct producer's complete stdout and stderr."""
    try:
        done = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True,
                              timeout=timeout)
        return done.returncode, done.stdout, done.stderr
    except subprocess.TimeoutExpired:
        return 124, "", "timeout after %ds" % timeout


def start_service(arch=1):
    target = {1: "x86", 2: "arm64"}[arch]
    loader, linker = tools_for_arch(target)
    endpoint = pathlib.Path("/sys/kernel/debug/bpf_" + target +
                            "_native_lab/specializer")
    if not endpoint.exists():
        return None, None
    state = pathlib.Path(tempfile.mkdtemp(prefix="trusted-"))
    proc = subprocess.Popen(
        [sys.executable, str(ROOT / "kprog/trusted_service.py"),
         "--arch", str(arch), "--endpoint", str(endpoint), "--state", str(state),
         "--native-link", str(linker), "--loader", str(loader / "trusted-native-loader")],
        stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    line = proc.stdout.readline()
    try:
        if not json.loads(line)["ready"]:
            return None, proc
    except (ValueError, KeyError):
        return None, proc
    return proc, state


def resource_pinning_btf(raw, lib):
    """Give map pinning to the direct request's explicit temporary pin paths."""
    for name, result, arguments in [
        ("btf__new", c.c_void_p, [c.c_void_p, c.c_uint32]),
        ("btf__free", None, [c.c_void_p]),
        ("libbpf_get_error", c.c_long, [c.c_void_p]),
        ("btf__type_cnt", c.c_uint32, [c.c_void_p]),
        ("btf__type_by_id", c.c_void_p, [c.c_void_p, c.c_uint32]),
        ("btf__name_by_offset", c.c_char_p, [c.c_void_p, c.c_uint32]),
        ("btf__add_array", c.c_int, [c.c_void_p, c.c_int, c.c_int, c.c_uint32]),
        ("btf__add_ptr", c.c_int, [c.c_void_p, c.c_int]),
        ("btf__raw_data", c.c_void_p, [c.c_void_p, c.POINTER(c.c_uint32)]),
    ]:
        function = getattr(lib, name)
        function.restype, function.argtypes = result, arguments
    buffer = c.create_string_buffer(raw)
    btf = lib.btf__new(buffer, len(raw))
    error = lib.libbpf_get_error(btf)
    if error or not btf:
        raise OSError(-error if error else c.get_errno(), "resource BTF parse")
    def fields(identifier):
        address = lib.btf__type_by_id(btf, identifier)
        return c.cast(address, c.POINTER(c.c_uint32 * 3)).contents
    def resolved(identifier):
        while ((fields(identifier)[1] >> 24) & 31) in {8, 9, 10, 11, 18}:
            identifier = fields(identifier)[2]
        return identifier
    changes = []
    try:
        for identifier in range(1, lib.btf__type_cnt(btf)):
            section = fields(identifier)
            if ((section[1] >> 24) & 31) != 15 or lib.btf__name_by_offset(btf, section[0]) != b".maps":
                continue
            variables = (c.c_uint32 * (3 * (section[1] & 65535))).from_address(c.addressof(section) + 12)
            for offset in range(0, len(variables), 3):
                variable = fields(variables[offset])
                structure_id = resolved(variable[2])
                structure = fields(structure_id)
                if ((structure[1] >> 24) & 31) != 4:
                    continue
                members = (c.c_uint32 * (3 * (structure[1] & 65535))).from_address(c.addressof(structure) + 12)
                for member in range(0, len(members), 3):
                    if lib.btf__name_by_offset(btf, members[member]) != b"pinning":
                        continue
                    pointer = fields(resolved(members[member + 1]))
                    if ((pointer[1] >> 24) & 31) != 2:
                        continue
                    array_id = resolved(pointer[2])
                    array_header = fields(array_id)
                    if ((array_header[1] >> 24) & 31) != 3:
                        continue
                    array = c.cast(lib.btf__type_by_id(btf, array_id),
                                   c.POINTER(c.c_uint32 * 6)).contents
                    if array[5]:
                        changes.append(dict(map=lib.btf__name_by_offset(btf, variable[0]).decode(),
                                            source= int(array[5]), resource=0,
                                            structure_id=structure_id, member=member,
                                            element=int(array[3]), index=int(array[4])))
        pointers = {}
        for change in changes:
            key = (change["index"], change["element"])
            if key not in pointers:
                array_id = lib.btf__add_array(btf, *key, 0)
                if array_id < 0:
                    raise OSError(-array_id, "resource BTF pinning array")
                pointer_id = lib.btf__add_ptr(btf, array_id)
                if pointer_id < 0:
                    raise OSError(-pointer_id, "resource BTF pinning pointer")
                pointers[key] = pointer_id
            structure = fields(change["structure_id"])
            members = (c.c_uint32 * (3 * (structure[1] & 65535))).from_address(c.addressof(structure) + 12)
            members[change["member"] + 1] = pointers[key]
        if changes:
            size = c.c_uint32()
            data = lib.btf__raw_data(btf, c.byref(size))
            return c.string_at(data, size.value), changes
        return None, []
    finally:
        lib.btf__free(btf)


@contextlib.contextmanager
def libbpf_resource_object(path, directory, lib):
    """Prepare source maps/BTF through a resource-only ELF metadata view."""
    from elftools.elf.elffile import ELFFile
    path = pathlib.Path(path)
    with path.open("rb") as source:
        elf = ELFFile(source)
        program_relocations = elf.get_section_by_name(".BTF.ext") is not None
        btf = elf.get_section_by_name(".BTF")
        pinning_btf, pinning = resource_pinning_btf(btf.data(), lib) if btf else (None, [])
        local_entries = [
            symbol.name for symbol in elf.get_section_by_name(".symtab").iter_symbols()
            if symbol["st_info"]["type"] == "STT_FUNC"
            and symbol["st_info"]["bind"] == "STB_LOCAL"
            and isinstance(symbol["st_shndx"], int)
            and elf.get_section(symbol["st_shndx"])["sh_flags"] & 4
            and elf.get_section(symbol["st_shndx"]).name != ".text"
        ]
    if local_entries or program_relocations or pinning:
        with tempfile.TemporaryDirectory(prefix="resource-elf-", dir=directory) as temp:
            resource = pathlib.Path(temp) / path.name
            # Source programs keep autoload=false. Their CO-RE/function/line
            # relocation table belongs to source execution; maps and entry
            # prototypes use the retained .BTF section.
            btf_args = []
            if pinning_btf is not None:
                btf_file = pathlib.Path(temp) / "resource.btf"
                btf_file.write_bytes(pinning_btf)
                btf_args = ["--update-section=.BTF=" + str(btf_file)]
            subprocess.run(["llvm-objcopy-18", "--remove-section=.BTF.ext", *btf_args,
                            *("--globalize-symbol=" + name for name in local_entries),
                            str(path), str(resource)], check=True)
            yield resource, local_entries, pinning
    else:
        yield path, [], []


class ObjectResources:
    """A libbpf object containing maps/BTF and autoload=false programs."""
    def __init__(self, arch, path, program, directory=None, map_info=()):
        loader_directory, _ = tools_for_arch(arch)
        self.obj = None
        self.pins = None
        self.source_stack = contextlib.ExitStack()
        self.entry_name = program.encode()
        self.lib = c.CDLL(str(loader_directory / "libnative_loader.so"), use_errno=True)
        self.pins = pathlib.Path(tempfile.mkdtemp(prefix="kprog-selftest-",
                                                dir="/sys/fs/bpf"))
        self.bind("libbpf_get_error", c.c_long, c.c_void_p)
        self.bind("bpf_object__open_file", c.c_void_p, c.c_char_p, c.c_void_p)
        self.bind("bpf_object__close", None, c.c_void_p)
        self.bind("bpf_object__prepare", c.c_int, c.c_void_p)
        self.bind("bpf_object__next_program", c.c_void_p, c.c_void_p, c.c_void_p)
        self.bind("bpf_object__find_program_by_name", c.c_void_p, c.c_void_p, c.c_char_p)
        self.bind("bpf_program__set_autoload", c.c_int, c.c_void_p, c.c_bool)
        self.bind("bpf_program__type", c.c_uint32, c.c_void_p)
        self.bind("bpf_program__expected_attach_type", c.c_uint32, c.c_void_p)
        self.bind("bpf_program__flags", c.c_uint32, c.c_void_p)
        self.bind("bpf_program__section_name", c.c_char_p, c.c_void_p)
        self.bind("bpf_object__next_map", c.c_void_p, c.c_void_p, c.c_void_p)
        self.bind("bpf_map__name", c.c_char_p, c.c_void_p)
        self.bind("bpf_map__is_internal", c.c_bool, c.c_void_p)
        self.bind("bpf_map__set_pin_path", c.c_int, c.c_void_p, c.c_char_p)
        self.bind("bpf_map__pin", c.c_int, c.c_void_p, c.c_char_p)
        self.bind("bpf_map__fd", c.c_int, c.c_void_p)
        self.bind("bpf_obj_get_info_by_fd", c.c_int, c.c_int, c.c_void_p,
                  c.POINTER(c.c_uint32))
        self.bind("bpf_object__btf", c.c_void_p, c.c_void_p)
        self.bind("bpf_object__btf_fd", c.c_int, c.c_void_p)
        self.bind("btf__type_cnt", c.c_uint32, c.c_void_p)
        self.bind("btf__type_by_id", c.c_void_p, c.c_void_p, c.c_uint32)
        self.bind("btf__name_by_offset", c.c_char_p, c.c_void_p, c.c_uint32)
        self.bind("btf__find_by_name_kind", c.c_int, c.c_void_p, c.c_char_p, c.c_uint32)
        self.bind("libbpf_find_vmlinux_btf_id", c.c_int, c.c_char_p, c.c_uint32)
        resource, self.globalized_entries, self.pinning = self.source_stack.enter_context(
            libbpf_resource_object(path, directory, self.lib))
        self.obj = self.lib.bpf_object__open_file(os.fsencode(resource), None)
        error = self.lib.libbpf_get_error(self.obj)
        if error or not self.obj:
            self.obj = None
            raise OSError(-error if error else c.get_errno(), "bpf_object__open_file")
        prog = None
        while True:
            prog = self.lib.bpf_object__next_program(self.obj, prog)
            if not prog:
                break
            self.ok(self.lib.bpf_program__set_autoload(prog, False), "set_autoload")
        self.program = self.lib.bpf_object__find_program_by_name(
            self.obj, program.encode())
        if not self.program:
            raise OSError(errno.ENOENT, "program context symbol " + program)
        self.maps = []
        self.configured_maps = []
        for field in ("key_size", "value_size", "max_entries"):
            self.bind("bpf_map__" + field, c.c_uint32, c.c_void_p)
            self.bind("bpf_map__set_" + field, c.c_int, c.c_void_p, c.c_uint32)
        item = None
        while True:
            item = self.lib.bpf_object__next_map(self.obj, item)
            if not item:
                break
            self.ok(self.lib.bpf_map__set_pin_path(
                item, os.fsencode(self.pins / str(len(self.maps)))), "set_pin_path")
            name = self.lib.bpf_map__name(item).decode()
            profiles = [info for info in map_info if info.get("name") in (name, name[:15])]
            if len(profiles) == 1:
                profile = profiles[0]
                for field, inventory_field in (("key_size", "bytes_key"),
                                                ("value_size", "bytes_value"),
                                                ("max_entries", "max_entries")):
                    value = profile.get(field, profile.get(inventory_field, 0))
                    if value and not getattr(self.lib, "bpf_map__" + field)(item):
                        self.ok(getattr(self.lib, "bpf_map__set_" + field)(item, value),
                                "configure map " + field)
                        self.configured_maps.append(dict(name=name, field=field, value=value))
            self.maps.append(item)

    def bind(self, name, result, *arguments):
        function = getattr(self.lib, name)
        function.restype = result
        function.argtypes = list(arguments)

    @staticmethod
    def ok(rc, operation):
        if rc < 0:
            raise OSError(-rc, operation + ": " + os.strerror(-rc))

    def info(self, fd, output):
        length = c.c_uint32(c.sizeof(output))
        self.ok(self.lib.bpf_obj_get_info_by_fd(
            fd, c.byref(output), c.byref(length)), "get_info_by_fd")
        return output

    def datasections(self, btf):
        sections = []
        if not btf:
            return sections
        for index in range(1, self.lib.btf__type_cnt(btf)):
            address = self.lib.btf__type_by_id(btf, index)
            fields = (c.c_uint32 * 3).from_address(address)
            if ((fields[1] >> 24) & 31) != 15:
                continue
            name = self.lib.btf__name_by_offset(btf, fields[0]).decode()
            variables = []
            for offset in range(fields[1] & 65535):
                item = (c.c_uint32 * 3).from_address(address + 12 + offset * 12)
                variable = self.lib.btf__type_by_id(btf, item[0])
                symbol = self.lib.btf__name_by_offset(
                    btf, c.c_uint32.from_address(variable).value).decode()
                variables.append((symbol, item[1]))
            sections.append((name, variables))
        return sections

    def load(self, path):
        self.ok(self.lib.bpf_object__prepare(self.obj), "maps/BTF object prepare")
        btf = self.lib.bpf_object__btf(self.obj)
        sections = self.datasections(btf)
        bindings, fds, pins = [], [], []
        for item in self.maps:
            fd = self.lib.bpf_map__fd(item)
            if fd < 0:
                continue
            self.ok(self.lib.bpf_map__pin(item, None), "map pin")
            identity = self.info(fd, MapInfo())
            name = self.lib.bpf_map__name(item).decode()
            fds.append(fd)
            pins.append(dict(name=name, map_id=identity.map_id))
            bindings.append(dict(name=name, map_id=identity.map_id,
                                 value_offset=None))
            if self.lib.bpf_map__is_internal(item):
                for section, variables in sections:
                    if name == section or name.endswith(section):
                        bindings.extend(dict(name=symbol, map_id=identity.map_id,
                                             value_offset=offset)
                                        for symbol, offset in variables)
        program = self.program
        section = self.lib.bpf_program__section_name(program).decode()
        flags = self.lib.bpf_program__flags(program)
        prefix = section.split("/", 1)[0]
        if "s" in prefix.split("."):
            flags |= 1 << 4
        if prefix.startswith("xdp.frags"):
            flags |= 1 << 5
        context = dict(prog_type=self.lib.bpf_program__type(program),
                       expected_attach_type=self.lib.bpf_program__expected_attach_type(program),
                       prog_flags=flags, prog_ifindex=0, attach_btf_id=0,
                       attach_btf_obj_id=0, attach_prog_id=0, gpl_compatible=1,
                       source_btf_id=0, source_func_type_id=0, token_present=0)
        btf_fd = self.lib.bpf_object__btf_fd(self.obj)
        if btf_fd >= 0:
            context["source_btf_id"] = self.info(btf_fd, BtfInfo()).id
            # Entry function BTF follows the selected program name.
            identifier = self.lib.btf__find_by_name_kind(btf, self.entry_name, 12)
            if identifier >= 0:
                context["source_func_type_id"] = identifier
        target_error = None
        if context["prog_type"] in (26, 29) and "/" in section:
            target = section.split("/", 1)[1]
            identifier = self.lib.libbpf_find_vmlinux_btf_id(
                target.encode(), context["expected_attach_type"])
            if identifier >= 0:
                context["attach_btf_id"] = identifier
            else:
                target_error = dict(target=target, errno=-identifier)
        from elftools.elf.elffile import ELFFile
        with pathlib.Path(path).open("rb") as source:
            elf = ELFFile(source)
            license = elf.get_section_by_name("license")
            context["gpl_compatible"] = int(license is not None and
                                            b"GPL" in license.data().split(b"\0", 1)[0])
        return dict(version=1, load_context=context, maps=bindings), fds, dict(
            section=section, maps=pins, pin_root=str(self.pins),
            attach_target_resolution=target_error,
            resource_globalized_entries=self.globalized_entries,
            resource_view="maps-and-btf", resource_pinning=self.pinning,
            resource_configured_maps=self.configured_maps)

    def close(self):
        if self.obj:
            self.lib.bpf_object__close(self.obj)
            self.obj = None
        self.source_stack.close()
        if self.pins is not None:
            for pin in self.pins.iterdir():
                pin.unlink()
            self.pins.rmdir()


def service_stage(record):
    if record["status"] == 0:
        return "installed", ""
    path = record.get("failure_archive")
    text = ""
    if path:
        with tarfile.open(path) as archive:
            names = archive.getnames()
            if "request/load.stderr" in names:
                text = archive.extractfile("request/load.stderr").read().decode(errors="replace")
            if "processed " in text:
                return "verifier_rejected", text
            if "native-link kernel failed" in text:
                return "generation_failed", text
            if not any(name.endswith(".bpf.c") for name in names):
                return "generation_failed", record.get("error", "") + text
            if not any(name.endswith(".bpf.o") for name in names):
                return "compilation_failed", record.get("error", "") + text
            if "request/commands.jsonl" in names:
                commands = [json.loads(line) for line in
                            archive.extractfile("request/commands.jsonl").read().splitlines()]
                if any(cmd["returncode"] for cmd in commands):
                    return "compilation_failed", text
    if "ValueError" in record.get("traceback", ""):
        return "generation_failed", record.get("error", "") + text
    return "load_failed", record.get("error", "") + text


def direct(arch, state, native, row):
    resources = None
    descriptor = None
    result = dict(source_prog_id=0, stage="resource_failed")
    try:
        native_bytes = pathlib.Path(native).read_bytes()
        result["native_sha256"] = hashlib.sha256(native_bytes).hexdigest()
        # Allocation before __init__ keeps cleanup available for libbpf errors.
        resources = ObjectResources.__new__(ObjectResources)
        resources.__init__(arch, row["bpf_object"], row["program"], state,
                           row.get("map_info", ()))
        metadata, fds, details = resources.load(row["bpf_object"])
        if not metadata["load_context"]["prog_type"] and row.get("prog_type"):
            # The source section names no libbpf program type; the resident
            # program's bpf_prog_info type supplies it.
            metadata["load_context"]["prog_type"] = row["prog_type"]
            details["prog_type_source"] = "resident bpf_prog_info"
        entry_bytes = row["program"].encode()
        meta_bytes = json.dumps(metadata, separators=(",", ":")).encode()
        buffers = [c.create_string_buffer(value) for value in
                   (native_bytes, entry_bytes, meta_bytes)]
        handles = (c.c_int32 * len(fds))(*fds)
        request = Request(version=1, arch={"x86": 1, "arm64": 2}[arch],
                          source_prog_id=0, native_size=len(native_bytes),
                          entry_size=len(entry_bytes), metadata_size=len(meta_bytes),
                          native_user=c.addressof(buffers[0]),
                          entry_user=c.addressof(buffers[1]),
                          metadata_user=c.addressof(buffers[2]))
        submission = Submission(request=request, map_count=len(fds),
                                map_fds_user=c.addressof(handles))
        result.update(context=metadata, resources=details,
                      native_sha256=hashlib.sha256(native_bytes).hexdigest(),
                      stage="transport_failed")
        endpoint = pathlib.Path("/sys/kernel/debug/bpf_" + arch + "_native_lab/native_submit")
        descriptor = os.open(endpoint, os.O_RDWR | os.O_CLOEXEC)
        ioctl(descriptor, SUBMIT, submission)
        reply = Result()
        ioctl(descriptor, WAIT, reply)
        result.update(request_id=reply.request_id, status=reply.status,
                      prog_id=reply.prog_id)
        with (state / "request.lock").open("rb") as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            record = next(json.loads(line) for line in
                          (state / "requests.jsonl").read_text().splitlines()
                          if json.loads(line)["request_id"] == reply.request_id)
            result["service"] = record
            result["stage"], result["diagnostic"] = service_stage(record)
    except Exception as error:
        result.update(error=str(error), traceback=traceback.format_exc())
    finally:
        if descriptor is not None:
            os.close(descriptor)
        if resources is not None:
            resources.close()
    print(json.dumps(result), flush=True)
    return int(result["stage"] in {"resource_failed", "transport_failed"})


def agreement(results, total):
    counts = dict(catalog_rows=total, attempted=len(results),
                  submitted=sum("request_id" in row for row in results))
    for stage in ("installed", "verifier_rejected", "generation_failed",
                  "compilation_failed", "resource_failed", "transport_failed", "load_failed"):
        counts[stage] = sum(row["stage"] == stage for row in results)
    counts["skipped"] = 0
    for expected in ("failure", "success"):
        reached = [row for row in results if row["expect"] == expected and
                   row["stage"] in {"installed", "verifier_rejected"}]
        counts[expected] = len(reached)
        counts[expected + "_agrees"] = sum(
            row["stage"] == ("installed" if expected == "success" else "verifier_rejected")
            for row in reached)
        counts[expected + "_installed"] = sum(row["stage"] == "installed" for row in reached)
    return counts


def main(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument("--table", default=str(DEFAULT_TABLE))
    parser.add_argument("--arch", default="x86")
    parser.add_argument("--out", default=str(ROOT / "kprog/selftests/results"))
    parser.add_argument("--limit", type=int, default=0)
    parser.add_argument("--only", default="")
    parser.add_argument("--micro-exec", default=None, help=argparse.SUPPRESS)
    args = parser.parse_args(argv[1:])
    out = pathlib.Path(args.out)
    out.mkdir(parents=True, exist_ok=True)
    catalog = json.loads((pathlib.Path(args.table) / "programs.json").read_text())["programs"]
    work = [row for row in catalog if row["body"] == "c" and
            row.get("compiled") and row.get("entry")]
    if args.only:
        work = [row for row in work if args.only in row["program"]]
    if args.limit:
        work = work[:args.limit]
    service, state = start_service({"x86": 1, "arm64": 2}[args.arch])
    if service is None:
        raise RuntimeError("trusted service endpoint startup failed")
    readers = []
    def drain(stream, path):
        with path.open("w") as output:
            for line in stream:
                output.write(line)
                output.flush()
    for name, stream in (("stdout", service.stdout), ("stderr", service.stderr)):
        reader = threading.Thread(target=drain, args=(stream, state / ("service." + name)))
        reader.start()
        readers.append(reader)
    results = []
    def save():
        payload = dict(counts=agreement(results, len(catalog)), programs=results,
                       skipped=[], invocation=vars(args),
                       source_scope="Direct load-only native P with source_prog_id 0; maps/BTF and installed-stage agreement")
        (out / "submissions.json").write_text(json.dumps(payload, indent=2) + "\n")
    try:
        for row in work:
            native = pathlib.Path(args.table) / (
                pathlib.Path(row["path"]).stem + "__" + row["program"] + ".native.o")
            command = [sys.executable, str(pathlib.Path(__file__)), "direct",
                       args.arch, str(state), str(native), json.dumps(row)]
            rc, stdout, stderr = run(command, timeout=None)
            try:
                outcome = json.loads(stdout)
            except ValueError:
                outcome = dict(stage="resource_failed", error="direct producer exited",
                               source_prog_id=0)
            outcome.update(file=row["file"], program=row["program"],
                           section=row["section"], expect=row["expect"],
                           returncode=rc, stdout=stdout, stderr=stderr, command=command)
            results.append(outcome)
            save()
            print(row["program"], outcome["stage"], flush=True)
    finally:
        with (state / "request.lock").open("rb") as lock:
            fcntl.flock(lock, fcntl.LOCK_EX)
            service.terminate()
        service.wait()
        for reader in readers:
            reader.join()
        save()
    print(json.dumps(agreement(results, len(catalog)), indent=2))
    return 0


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "direct":
        raise SystemExit(direct(sys.argv[2], pathlib.Path(sys.argv[3]),
                                pathlib.Path(sys.argv[4]), json.loads(sys.argv[5])))
    raise SystemExit(main(sys.argv))
