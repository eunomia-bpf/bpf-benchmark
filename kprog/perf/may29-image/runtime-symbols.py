#!/usr/bin/env python3
"""Retain only mapped executable files from the sole Docker archive for perf.

This produces symbol evidence, not a runnable root/base or source checkout.
Layers are read in manifest order; requested paths must end as regular files.
"""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import tarfile


def mapped_files(text):
    result = set()
    for line in text.splitlines():
        fields = line.split(None, 5)
        if len(fields) == 6 and 'x' in fields[1] and fields[5].startswith('/'):
            path = PurePosixPath(fields[5])
            if '..' in path.parts or fields[5].endswith(' (deleted)'):
                raise ValueError(f'unsupported mapped file: {fields[5]}')
            result.add(str(path).lstrip('/'))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, required=True)
    parser.add_argument('--maps', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    wanted = mapped_files(args.maps.read_text())
    selected = {}
    with tarfile.open(args.image, 'r:*') as image:
        images = json.load(image.extractfile('manifest.json'))
        if len(images) != 1:
            raise ValueError('symbol extraction requires the sole-image archive')
        for layer_name in images[0]['Layers']:
            with image.extractfile(layer_name) as content, tarfile.open(fileobj=content, mode='r:*') as layer:
                for member in layer:
                    name = member.name.removeprefix('./').lstrip('/')
                    path = PurePosixPath(name)
                    if path.name == '.wh..wh..opq':
                        for prior in list(selected):
                            if PurePosixPath(prior).is_relative_to(path.parent):
                                del selected[prior]
                    elif path.name.startswith('.wh.'):
                        selected.pop(str(path.with_name(path.name[4:])), None)
                    elif name in wanted:
                        if not member.isfile():
                            raise ValueError(f'mapped file is not regular in layer: {name}')
                        selected[name] = (layer_name, member.name)
        missing = wanted - selected.keys()
        if missing:
            raise ValueError(f'mapped files absent from image: {sorted(missing)}')
        records = []
        for name, (layer_name, member_name) in sorted(selected.items()):
            with image.extractfile(layer_name) as content, tarfile.open(fileobj=content, mode='r:*') as layer:
                with layer.extractfile(member_name) as source:
                    data = source.read()
            destination = args.output / name
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_bytes(data)
            records.append(dict(path=name, bytes=len(data), sha256=hashlib.sha256(data).hexdigest(), layer=layer_name))
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / 'symbol-files.json').write_text(json.dumps(dict(
        image=str(args.image), image_config=images[0]['Config'], maps=str(args.maps), files=records), indent=2) + '\n')


if __name__ == '__main__':
    main()
