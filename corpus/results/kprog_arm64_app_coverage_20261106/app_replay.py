"""Export an existing app runtime's exact launch environment for portable QEMU."""
import json
from pathlib import Path
import shlex
import shutil
import sys

if sys.argv[1] == 'build':
    base = Path(sys.argv[2]).resolve()
    image = sys.argv[3]
    target = base / 'spark'
    target.mkdir(exist_ok=True)
    here = Path(__file__).resolve().parent
    shutil.copy2(here / 'AppReplay.mk', target / 'Makefile')
    shutil.copy2(__file__, target / 'configure.py')
    shutil.copy2(base / 'kernel/arch/arm64/boot/Image', target / 'Image')
    shutil.copy2(base / 'root/qemu-init', target / 'qemu-init')
    lines = (base / 'root/qemu-run.sh').read_text().splitlines()
    exports = [line.removeprefix('export ') for line in lines if line.startswith('export ')]
    if len(exports) != 1 or lines[-1] != 'exec python3 -m corpus.driver':
        raise RuntimeError('unexpected existing runtime launch format')
    environment = dict(value.split('=', 1) for value in shlex.split(exports[0]))
    (target / 'environment.json').write_text(json.dumps(environment, indent=2) + '\n')
    (target / 'runtime-image.txt').write_text(image + '\n')
    print(f'Portable app launcher/kernel prepared in {target}; transfer {base}/image.tar alongside it')
else:
    root = Path(sys.argv[1]).resolve()
    environment = json.loads(Path(__file__).with_name('environment.json').read_text())
    environment.update(BPFREJIT_CORPUS_APPS=sys.argv[2], SAMPLES=sys.argv[3],
                       WORKLOAD_DURATION=sys.argv[4], BPFREJIT_CORPUS_BPF_STATS=sys.argv[5])
    if environment['BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF'] != '1':
        raise RuntimeError('packaged application environment lost its bound-path setting')
    text = '#!/bin/sh\nset -eu\nexport ' + shlex.join(
        [key + '=' + value for key, value in environment.items()]) + '\nexec python3 -m corpus.driver\n'
    (root / 'qemu-run.sh').write_text(text)
    (root / 'qemu-run.sh').chmod(0o755)
    status = root / 'qemu-status'
    if status.exists():
        status.unlink()
