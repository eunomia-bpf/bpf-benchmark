#!/usr/bin/env python3
"""Delegate the image linker unchanged and retain its actual diagnostic inputs."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


def main(argv):
    options = {argv[i]: argv[i+1] for i in range(len(argv)-1) if argv[i].startswith('--')}
    mode = options.get('--mode')
    capture = Path(tempfile.mkdtemp(prefix='link-', dir=Path(__file__).absolute().parent / 'captures'))
    if mode == 'kernel':
        shutil.copyfile(options['--input'], capture / 'entry.proof.o')
        shutil.copyfile(options['--link-plan'], capture / 'link-plan.json')
    result = subprocess.run(['/usr/local/bin/native-link', *argv], capture_output=True)
    (capture / 'stdout').write_bytes(result.stdout)
    (capture / 'stderr').write_bytes(result.stderr)
    if result.returncode and mode != 'kernel' and '--input' in options:
        shutil.copyfile(options['--input'], capture / 'failed-input.o')
    outputs = []
    for flag, name in [('--output', 'image.blob'), ('--output-relocs', 'image.relocs'),
                       ('--output-map-patches', 'image.maps'), ('--output-abi', 'image.abi')]:
        if flag in options and Path(options[flag]).is_file():
            shutil.copyfile(options[flag], capture / name)
            outputs.append(name)
    (capture / 'adapter.json').write_text(json.dumps(dict(mode=mode, argv=argv,
        returncode=result.returncode, outputs=outputs), indent=2)+'\n')
    sys.stdout.buffer.write(result.stdout)
    sys.stderr.buffer.write(result.stderr)
    return result.returncode


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
