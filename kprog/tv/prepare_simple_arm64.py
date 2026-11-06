"""Freeze one actual native/proof pair and its production specialization inputs."""
from pathlib import Path
import importlib.util
import shutil
import sys

root = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(root / "kprog/fidelity"))
from tcb import includes, imports

generator = root / "kprog/arm64/micro-prog/generate_micro_sim_proofs.py"
sys.path.insert(0, str(generator.parent))
spec = importlib.util.spec_from_file_location("tv_arm64_generator", generator)
encoder = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = encoder
spec.loader.exec_module(encoder)
output = root / "kprog/tv/build/simple-arm64"
proofs = output / "native-link"
proofs.mkdir(parents=True, exist_ok=True)
shutil.copyfile(root / "kprog/arm64/micro-prog/build/native-link/simple.proof.o", proofs / "simple.proof.o")
snapshot = output / "snapshot"
for path in includes(root / "kprog/arm64/arm64_sim_local_bpf.h") | imports(generator):
    target = snapshot / path.relative_to(root)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(path, target)
bench = next(bench for bench in encoder.load_benches(encoder.CONFIG) if bench.name == "simple")
source = encoder.generate_one(bench, encoder.MICRO_PROGRAMS, output, proofs)
source.write_text(source.read_text().replace('#include "../arm64_sim_local_bpf.h"',
    '#include "snapshot/kprog/arm64/arm64_sim_local_bpf.h"'))
print(source)
