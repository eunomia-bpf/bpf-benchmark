"""Build ARM images from the published strict shim without consuming shared WIP."""
from pathlib import Path
import subprocess
ROOT=Path(__file__).resolve().parents[3]
revision='0bff849bf'
target=ROOT/'kprog/arm64/build/published-shim-v5'
files=subprocess.check_output(['git','ls-tree','-r','--name-only',revision,'--','bpfopt/shim'],cwd=ROOT,text=True).splitlines()
if not files:raise RuntimeError('published shim source is absent')
for name in files:
    path=target/name;path.parent.mkdir(parents=True,exist_ok=True)
    path.write_bytes(subprocess.check_output(['git','show',revision+':'+name],cwd=ROOT))
vendor=target/'vendor'
if not vendor.exists():vendor.symlink_to(ROOT/'vendor',target_is_directory=True)
(target/'SOURCE_COMMIT').write_text(revision+'\n')
print(f'published strict shim {revision} exported to {target}; shared shim files preserved')
