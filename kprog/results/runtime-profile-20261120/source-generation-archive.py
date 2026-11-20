"""Keep the exact P input and generated artifacts before the next rebuild."""
from pathlib import Path
import sys
import tarfile

raw=Path(sys.argv[1])
tmp=Path('/var/tmp/kprog-tmp/perf/runtime-profile-user')
with tarfile.open(raw/'source-generation-evidence.tar.gz','w:gz') as archive:
    archive.add(tmp/'user.o',arcname='source-P.o')
    archive.add(tmp/'generation',arcname='generation')
