"""Existing diagnostic guest plus one paired packet test during native startup."""
import importlib.util
from pathlib import Path
import sys

root = Path('/workspaces/repository')
sys.path.insert(0, str(root / 'kprog/perf/profile'))
spec = importlib.util.spec_from_file_location('phase_profile', root / 'kprog/perf/profile/phase-profile.py')
profile = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profile)
profile.GUEST = profile.GUEST.replace('  # Preserve JIT IP -> BTF source-line records while this phase is live.', '''  if [ "$ph" = post_rejit ]; then
    python3 kprog/results/cilium-packet-20261116/packet.py "$O" > "$O/packet.log" 2>&1
    echo $? > "$O/packet.rc"
  fi
  # Preserve JIT IP -> BTF source-line records while this phase is live.''', 1)
sys.exit(profile.main(sys.argv[1:]))
