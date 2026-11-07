"""Select existing RORX pairs after the unchanged generator constructs its matrix."""
from pathlib import Path
import sys
ROOT = Path(__file__).resolve().parents[5]
generator = ROOT / "kprog/fidelity/generate.py"
source = generator.read_text()
needle = "    for i, (assembly, encoded, special, native_body, decoded) in enumerate(pairs):"
assert source.count(needle) == 1
source = source.replace(needle, "    pairs = [pair for pair in pairs if pair[1].op in {'X86_OP_RORX', 'X86_OP_RORX_MEM'}]\n" + needle)
build = ROOT / "kprog/fidelity/build-x86-rorx"
build.mkdir(exist_ok=True)
(build / "selected-generator.py").write_text(source)
sys.path.insert(0, str(generator.parent))
sys.argv = [str(generator), "--arch", "x86", "--out", str(build)]
exec(compile(source, str(generator), "exec"), {"__file__": str(generator), "__name__": "__main__"})
