"""Replay exact native context reads with the existing compact worker and service."""
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
D = ROOT / "kprog/arm64/build/trusted-transport/context-memory-read"
OUT = HERE / "trusted-bcc-frame-result/context-native"


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


candidate = load("context_memory_compact", HERE / "trusted_payload_check.py")
candidate.CANDIDATE = D


def transport():
    module = candidate.transport()
    module.HERE, module.__file__ = OUT, __file__
    return module


def check():
    from elftools.elf.elffile import ELFFile
    sys.path.insert(0, str(ROOT / "kprog"))
    import trusted_service
    worker = candidate.adapter(trusted_service)
    link = ROOT / "kprog/arm64/build/app-native-link/release/native-link"
    folder = D / "partial-compiler"
    folder.mkdir(exist_ok=False)
    records = []
    names = ["valid_context_data_high32", "valid_context_end_high32",
             "valid_context_meta_word", "context_outside_object_read"]
    for name in names:
        job = folder / name
        job.mkdir()
        native = D / "safety-inputs" / (name + ".native.o")
        artifacts = worker.specialize(native.read_bytes(), "entry",
            dict(version=1, prog_type=6, section="xdp", maps=[]), job / "generated", link)
        with Path(artifacts["simulator_object"]).open("rb") as f:
            elf = ELFFile(f)
            words = [struct.unpack("<BBhi", section.data()[i:i+8])
                     for section in elf.iter_sections() if section["sh_flags"] & 4
                     for i in range(0, section["sh_size"], 8)]
        numeric = sum(code == 0xb7 and regs == 0x90 and off == 4 and imm == 2
                      for code, regs, off, imm in words)
        offsets = [off for code, regs, off, imm in words if code == 0x61]
        if "high32" in name:
            assert numeric == 1, (name, numeric)
            assert offsets == [0 if "data_" in name else 4], (name, offsets)
            shifted = any(code == 0x77 and imm == 32 for code, regs, off, imm in words)
            boundary = any(code == 0x18 and imm == 0 and words[i+1][3] == 1
                           for i, (code, regs, off, imm) in enumerate(words[:-1]))
            compared = any(code in {0x2d, 0x3d, 0xad, 0xbd} for code, regs, off, imm in words)
            assert shifted or (boundary and compared), name
        elif name == "valid_context_meta_word":
            assert offsets == [8], offsets
        else:
            assert offsets == [4096], offsets
        records.append(dict(name=name, native_sha256=hashlib.sha256(native.read_bytes()).hexdigest(),
                            numeric_markers=numeric, ctx_word_load_offsets=offsets,
                            simulator_sha256=hashlib.sha256(Path(artifacts["simulator_object"]).read_bytes()).hexdigest()))
    (folder / "summary.json").write_text(json.dumps(records, indent=2) + "\n")
    print("4 exact native context compiler probes PASS; no verifier/execution claim", flush=True)


def guest(live, case):
    module = transport()
    original = module.subprocess.Popen

    def start(command, *args, **kwargs):
        if len(command) > 1 and Path(command[1]) in {
            ROOT / "kprog/trusted_service.py", HERE / "trusted_payload_check.py"}:
            command = [command[0], __file__, "service", *command[2:]]
        return original(command, *args, **kwargs)

    module.subprocess.Popen = start
    if case == "katran":
        module.guest(live, "katran")
    elif case == "safety":
        suite = load("context_memory_safety", HERE / "trusted_payload_negative.py")
        suite.candidate = candidate
        suite.BUILD = D / "safety-inputs"
        suite.guest(Path(live))
    else:
        raise ValueError("unknown replay")


if __name__ == "__main__":
    if sys.argv[1:] == ["check"]:
        check()
    elif len(sys.argv) > 1 and sys.argv[1] == "service":
        sys.path.insert(0, str(ROOT / "kprog"))
        import trusted_service
        worker = candidate.adapter(trusted_service)
        def select(arch):
            if arch != 2:
                raise ValueError("AArch64 request required")
            return worker
        trusted_service.adapter = select
        del sys.argv[1]
        trusted_service.main()
    elif len(sys.argv) == 3 and sys.argv[1] == "host":
        case = sys.argv[2]
        if case not in {"katran", "safety"}:
            raise ValueError("unknown replay")
        # The existing host transport labels non-application service runs control.
        if case == "safety":
            transport().host("control")
        else:
            transport().host("katran")
    elif len(sys.argv) == 4 and sys.argv[1] == "guest":
        guest(sys.argv[2], "safety" if sys.argv[3] == "control" else sys.argv[3])
    else:
        raise SystemExit("usage: trusted_context_memory.py check | host katran|safety | guest LIVE control|katran | service [broker args]")
