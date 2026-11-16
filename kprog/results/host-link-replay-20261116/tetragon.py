"""Existing profile workflow with native-link capture and verbose guest console."""
import importlib.util
from pathlib import Path
import sys

ROOT = Path('/workspaces/repository')
sys.path.insert(0, str(ROOT / 'kprog/perf/profile'))
spec = importlib.util.spec_from_file_location('phase_profile', ROOT / 'kprog/perf/profile/phase-profile.py')
profile = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profile)
profile.GUEST = profile.GUEST.replace('set -u\n',
    'set -u\nexport BPFREJIT_NATIVE_LINK_BINARY=/workspaces/repository/corpus/results/shared-hash-regression-20261116/shared-link\n', 1)
execute = profile.execution_command


def verbose(command, args, out):
    command.insert(command.index('vng') + 1, '--verbose')
    return execute(command, args, out)


profile.execution_command = verbose
sys.exit(profile.main(sys.argv[1:]))
