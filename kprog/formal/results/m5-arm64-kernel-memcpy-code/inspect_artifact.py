"""Record the sole kernel memcpy symbol bytes used by the native loader."""
from pathlib import Path
import argparse, datetime, hashlib, json, subprocess
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser()
parser.add_argument("--output", type=Path, required=True)
args = parser.parse_args()
root = Path(__file__).resolve().parents[4]
build = Path("/workspaces/.agent-state/kprog-ck/build-arm64")
names = ["memcpy", "__memcpy", "__pi_memcpy", "__pi_memcpy_generic"]
def symbols(path):
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError(f"{path}: expected the real AArch64 product")
        table = elf.get_section_by_name(".symtab")
        if table is None:
            raise RuntimeError(f"{path}: symbol table required")
        matches = {name: [] for name in names}
        for symbol in table.iter_symbols():
            if symbol.name in matches:
                matches[symbol.name].append(symbol)
        result = {}
        for name, found in matches.items():
            if len(found) != 1:
                raise RuntimeError(f"{path}: expected one {name}, got {len(found)}")
            symbol = found[0]
            section = elf.get_section(symbol["st_shndx"])
            offset = symbol["st_value"] - section["sh_addr"]
            stream.seek(section["sh_offset"] + offset)
            data = stream.read(symbol["st_size"])
            if len(data) != symbol["st_size"] or len(data) % 4:
                raise RuntimeError(f"{path}:{name}: complete native words required")
            result[name] = {"address": hex(symbol["st_value"]), "size": len(data),
                "sha256": hashlib.sha256(data).hexdigest(),
                "words": [f"{int.from_bytes(data[i:i+4], 'little'):08x}" for i in range(0, len(data), 4)]}
        return result

obj = build / "arch/arm64/lib/memcpy.o"
vmlinux = build / "vmlinux"
object_symbols = symbols(obj)
kernel_symbols = symbols(vmlinux)
for name in names:
    if object_symbols[name]["words"] != kernel_symbols[name]["words"]:
        raise RuntimeError(f"{name}: object and linked kernel bytes differ")
if len({kernel_symbols[name]["address"] for name in names[:3]}) != 1:
    raise RuntimeError("memcpy aliases must bind the same kernel entry")
loader = root / "kprog/libnativeloader/src/native_loader_trusted.cpp"
assembly = root / "vendor/linux-framework/arch/arm64/lib/memcpy.S"
record = {"utc": datetime.datetime.now(datetime.timezone.utc).isoformat(),
    "kernel_revision": subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root/"vendor/linux-framework", text=True).strip(),
    "inputs": {str(p): {"size": p.stat().st_size, "sha256": hashlib.file_digest(p.open("rb"), "sha256").hexdigest()}
        for p in [obj, vmlinux, assembly, loader, build/".config"]},
    "object_symbols": object_symbols, "kernel_symbols": kernel_symbols,
    "domain": "linked sole-kernel generic implementation and unpatched MOPS alternative entry; live CPU alternatives retain their own binding"}
args.output.write_text(json.dumps(record, indent=2)+"\n")
print(json.dumps({"output": str(args.output), "generic_bytes": kernel_symbols["__pi_memcpy_generic"]["size"],
    "entry": kernel_symbols["memcpy"], "first_13_generic_words": kernel_symbols["__pi_memcpy_generic"]["words"][:13]}, indent=2))
