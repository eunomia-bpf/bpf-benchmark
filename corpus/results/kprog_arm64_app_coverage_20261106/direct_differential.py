"""Use F's unchanged native CPU matrix against the frozen constant-op bodies."""
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
phase = Path(sys.argv[1]).resolve()
source = ROOT/'kprog/fidelity/build-arm64-a-direct/generated.c'
text = source.read_text().replace('../../arm64/arm64_sim_local_bpf.h',
                                 str(phase/'simulator/arm64_sim_local_bpf.h'))
text = text.replace('ARM64_SIM_RUN_OP3(', 'ARM64_SIM_RUN_KNOWN_OP3(')
source.write_text(text)
