"""Reject changed native/BPF store semantics and the captured before-repair bug."""
from pathlib import Path
import os
import shutil
import subprocess
import tarfile

from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parent
source = root / "build/simple-arm64"


def entry_position(path, name):
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        matches = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        if not matches or len(matches) != 1:
            raise ValueError(f"missing or ambiguous entry: {name}")
        symbol = matches[0]
        section = elf.get_section(symbol["st_shndx"])
        return section["sh_offset"] + symbol["st_value"] - section["sh_addr"]


cases = [
    ("unchanged", None, 0, b""),
    ("narrow-store", "simple.bpf.o", 17 * 8, b"\x73"),
    ("wrong-store-address", "simple.bpf.o", 15 * 8 + 4, b"\x04"),
    ("erased-store", "simple.bpf.o", 17 * 8, bytes.fromhex("bf00000000000000")),
    ("native-wrong-width", "native-link/simple.proof.o", 52, bytes.fromhex("1f0d0039")),
    ("native-wrong-successor", "native-link/simple.proof.o", 72, bytes.fromhex("03000014")),
    ("before-width", "simple.bpf.o", 0, None),
    ("wrong-first-guard", "simple.bpf.o", 7 * 8 + 2, b"\x12"),
    ("wrong-guard-bound", "simple.bpf.o", 9 * 8 + 4, b"\x10"),
    ("native-wrong-condition", "native-link/simple.proof.o", 12, b"\xc0"),
    ("native-wrong-ccmp-fallback", "native-link/simple.proof.o", 28, b"\x40"),
]
for name, target, offset, replacement in cases:
    directory = root / "build/simple-arm64-mutations" / name
    (directory / "native-link").mkdir(parents=True, exist_ok=True)
    for artifact in ("simple.bpf.o", "native-link/simple.proof.o"):
        shutil.copyfile(source / artifact, directory / artifact)
    if target is not None:
        path = directory / target
        if replacement is None:
            archive = root.parent / "results/kprog_tv_20261106/simple-arm64-before-width-inputs.tar.gz"
            with tarfile.open(archive) as inputs:
                stream = inputs.extractfile("build/simple-arm64/simple.bpf.o")
                if stream is None:
                    raise ValueError("before-width archive has no compiled proof")
                path.write_bytes(stream.read())
        else:
            entry = "simple_xdp" if target.startswith("native-link/") else "simple_arm64_sim_xdp"
            position = entry_position(path, entry) + offset
            data = bytearray(path.read_bytes())
            if data[position:position+len(replacement)] == replacement:
                raise ValueError(f"{name}: mutation did not change the artifact")
            data[position:position+len(replacement)] = replacement
            path.write_bytes(data)
    result = subprocess.run([os.environ.get("MAKE", "make"), "--no-print-directory",
        "-o", "native-path-check", "simple-arm64-certificate",
        f"SIMPLE_BLOCK_DIR={directory.relative_to(root)}"], cwd=root,
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (directory / "certificate.log").write_bytes(result.stdout)
    if target is None:
        if result.returncode:
            raise RuntimeError(f"unchanged artifact failed: {directory}/certificate.log")
        print("unchanged actual native/clang pair: PASS", flush=True)
    else:
        if (not result.returncode or not any(file in result.stdout for file in
                    (b"SimpleStoreCertificate.lean:", b"SimpleGuardCertificate.lean:")) or
                (not any(message in result.stdout for message in
                    (b"error: type mismatch", b"tactic 'rfl' failed")) or b"decode" not in result.stdout)):
            raise RuntimeError(f"{name}: semantic rejection missing: {directory}/certificate.log")
        print(f"{name}: REJECTED by canonical byte-decoded semantics", flush=True)
