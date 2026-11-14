"""Record sole-image native artifact hashes beside the canonical stage.

This is provenance data: differences are recorded, never an admission gate.
No image filesystem or alternative base is materialized.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import tarfile


def digest(stream):
    value = hashlib.sha256()
    while block := stream.read(1024 * 1024):
        value.update(block)
    return value.hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, required=True)
    parser.add_argument('--stage', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    prefix = PurePosixPath('artifacts/user/native-bpf/x86_64')
    files = {}
    with tarfile.open(args.image) as image:
        manifest, = json.load(image.extractfile('manifest.json'))
        for name in manifest['Layers']:
            with image.extractfile(name) as content, tarfile.open(fileobj=content, mode='r|*') as layer:
                for member in layer:
                    path = PurePosixPath(member.name.removeprefix('./').lstrip('/'))
                    if not path.is_relative_to(prefix):
                        continue
                    relative = path.relative_to(prefix)
                    if path.name == '.wh..wh..opq':
                        files = {n: v for n, v in files.items() if not PurePosixPath(n).is_relative_to(relative.parent)}
                    elif path.name.startswith('.wh.'):
                        files.pop(str(relative.with_name(path.name[4:])), None)
                    elif member.isfile():
                        with layer.extractfile(member) as stream:
                            files[str(relative)] = dict(bytes=member.size, sha256=digest(stream))
                    elif member.issym():
                        files[str(relative)] = dict(symlink=member.linkname)
    stage = {}
    for path in sorted(args.stage.rglob('*')):
        relative = str(path.relative_to(args.stage))
        if path.is_symlink():
            stage[relative] = dict(symlink=str(path.readlink()))
        elif path.is_file():
            with path.open('rb') as stream:
                stage[relative] = dict(bytes=path.stat().st_size, sha256=digest(stream))
    result = dict(image=str(args.image), config=manifest['Config'], stage=str(args.stage),
        image_files=files, stage_files=stage,
        differences=[dict(path=n, image=files.get(n), stage=stage.get(n))
            for n in sorted(files.keys() | stage.keys()) if files.get(n) != stage.get(n)])
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(dict(image_files=len(files), stage_files=len(stage), differences=len(result['differences']))))


if __name__ == '__main__':
    main()
