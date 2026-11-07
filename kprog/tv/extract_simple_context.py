"""Bind captured complete kernel BPF bytes and load context to the clang ELF."""
from pathlib import Path
import json
from elftools.elf.elffile import ELFFile

root = Path(__file__).resolve().parent
base = root / "build/simple-context/simple_arm64_sim_xdp"
raw = base.with_suffix(".raw.bin").read_bytes()
physical = base.with_suffix(".xlated.bin").read_bytes()
context = json.loads(base.with_suffix(".context.json").read_text())
with (root / "build/simple-arm64/simple.bpf.o").open("rb") as stream:
    elf = ELFFile(stream)
    symbols = elf.get_section_by_name(".symtab").get_symbol_by_name("simple_arm64_sim_xdp")
    if not symbols or len(symbols) != 1:
        raise ValueError("missing or ambiguous actual compiled entry")
    symbol = symbols[0]
    section = elf.get_section(symbol["st_shndx"])
    begin = symbol["st_value"] - section["sh_addr"]
    if raw != section.data()[begin:begin+symbol["st_size"]]:
        raise ValueError("captured raw BPF differs from actual clang entry")
if (context["version"], context["program_type"], context["expected_attach_type"], context["prog_flags"]) != (1,6,37,0):
    raise ValueError("kernel load context differs from this XDP instantiation")
if context["source_prog_id"] <= 0 or context["attach_btf_id"] != 0:
    raise ValueError("invalid original program identity/context")
if not physical or len(physical) % 8:
    raise ValueError("invalid actual kernel BPF extent")
lines = ["import SimpleCompiled", "set_option maxRecDepth 4096", "set_option maxHeartbeats 500000", "namespace KProgTV.SimplePlatform"]
for name, data in [("raw", raw), ("physical", physical)]:
    lines.append(f"def {name} : Array KProgTV.Byte := #[" + ",".join(hex(b) for b in data) + "]")
for key in ["program_type", "expected_attach_type", "prog_flags", "source_prog_id", "attach_btf_id"]:
    lines.append(f"def {key} : Nat := {context[key]}")
lines += ["theorem raw_is_exact_clang : raw = KProgTV.SimpleCompiled.proof := rfl",
    f"theorem body_decode : ∀ pc : Fin {len(raw)//8-4}, "
    "KProgTV.BPF.decode physical (pc.val + 4) = KProgTV.BPF.decode raw (pc.val + 4) ∧ "
    "KProgTV.BPF.decode physical (pc.val + 5) = KProgTV.BPF.decode raw (pc.val + 5) := by\n  simp only [Fin.forall_fin_succ]\n  repeat' (first | rfl | constructor)\n  all_goals (intro i; exact Fin.elim0 i)",
    "end KProgTV.SimplePlatform", ""]
(root / "build/simple-arm64/SimplePlatform.lean").write_text("\n".join(lines))
print(f"complete actual clang {len(raw)} B / kernel {len(physical)} B; type6/attach37/flags0")
