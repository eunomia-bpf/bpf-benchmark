"""Use the existing profile workflow and supported runtime linker override."""
import importlib.util
from pathlib import Path
import sys

ROOT = Path('/workspaces/repository')
sys.path.insert(0, str(ROOT / 'kprog/perf/profile'))
spec = importlib.util.spec_from_file_location('phase_profile', ROOT / 'kprog/perf/profile/phase-profile.py')
profile = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profile)
mode = sys.argv[1]
assert mode in ('copy', 'shared')
adapter = ROOT / 'corpus/results/shared-hash-regression-20261116' / (mode + '-link')
profile.GUEST = profile.GUEST.replace('set -u\n', f'set -u\nexport BPFREJIT_NATIVE_LINK_BINARY={adapter}\n', 1)
sys.exit(profile.main(sys.argv[2:]))
