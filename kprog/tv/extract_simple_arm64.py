"""Expose the frozen pair's actual bytes; Lean supplies all ISA semantics."""
from pathlib import Path
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parent / "build/simple-arm64"


def function_bytes(path, name, machine):
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != machine or not elf.little_endian:
            raise ValueError(f"wrong architecture: {path}")
        matches = elf.get_section_by_name(".symtab").get_symbol_by_name(name)
        if not matches or len(matches) != 1:
            raise ValueError(f"ambiguous or absent entry: {name}")
        symbol = matches[0]
        section_id = symbol["st_shndx"]
        if not isinstance(section_id, int):
            raise ValueError(f"unresolved entry: {name}")
        section = elf.get_section(section_id)
        begin = symbol["st_value"] - section["sh_addr"]
        # Native-link's entry extent excludes its final return trampoline;
        # retain the entire bound text section, including that real successor.
        size = symbol["st_size"] if machine == "EM_BPF" else section["sh_size"] - begin
        for relocation in elf.iter_sections():
            if relocation["sh_type"] in ("SHT_REL", "SHT_RELA") and relocation["sh_info"] == section_id:
                if any(begin <= item["r_offset"] < begin + size for item in relocation.iter_relocations()):
                    raise ValueError(f"unresolved relocation in {name}")
        data = section.data()[begin:begin+size]
        if len(data) != size or not data:
            raise ValueError(f"invalid entry extent: {name}")
        return data


native = function_bytes(root / "native-link/simple.proof.o", "simple_xdp", "EM_AARCH64")
proof = function_bytes(root / "simple.bpf.o", "simple_arm64_sim_xdp", "EM_BPF")
lines = ["import ARM64Path", "import BPFPath", "namespace KProgTV.SimpleCompiled"]
for name, data in [("native", native), ("proof", proof)]:
    lines.append(f"def {name} : Array KProgTV.Byte := #[" + ",".join(hex(b) for b in data) + "]")
lines += ["end KProgTV.SimpleCompiled", ""]
(root / "SimpleCompiled.lean").write_text("\n".join(lines))
print(f"exact ELF entry bytes: native={len(native)} BPF={len(proof)}")
