"""Pin census inputs to the exact full-formal-checked helper source export."""
from pathlib import Path
import shutil
HERE=Path(__file__).resolve().parent
source=Path('/workspaces/.agent-state/kprog-lanes/C/helper-check-source')
snapshot=HERE/'startup-helper-census/simulator'
for path in snapshot.rglob('*'):
    if not path.is_file():continue
    peer=source/path.relative_to(snapshot)
    if not peer.is_file():raise FileNotFoundError(peer)
    shutil.copy2(peer,path)
print('all census generator/header/ABI inputs copied from checked immutable helper export')
