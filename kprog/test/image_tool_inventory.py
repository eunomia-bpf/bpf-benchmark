"""Record shipped linker/loader hashes without extracting an image filesystem."""
import argparse
import json
from pathlib import Path, PurePosixPath
from image_native_inventory import digest, image_files

ROOT = Path(__file__).resolve().parents[2]


def main(args):
    tools = [
        ('usr/local/bin', 'native-link',
         ROOT/'kprog/x86/native_lab/native_link/target/release/native-link'),
        ('usr/local/lib/bpfrejit', 'libnative_loader.so',
         ROOT/'runner/build-llvmbpf/native_loader/libnative_loader.so'),
        ('usr/local/lib/bpfrejit', 'libbpfrejit_shim.so',
         ROOT/'bpfopt/shim/build-x86/libbpfrejit_shim.so'),
    ]
    inventories = {}
    rows = []
    for prefix, name, built in tools:
        if prefix not in inventories:
            manifest, inventories[prefix] = image_files(args.image, PurePosixPath(prefix))
        shipped = inventories[prefix][name]
        with built.open('rb') as stream:
            current = dict(bytes=built.stat().st_size, sha256=digest(stream))
        rows.append(dict(path=f'/{prefix}/{name}', shipped=shipped,
                         built=str(built), current=current, equal=shipped == current))
    result = dict(image=str(args.image), config=manifest['Config'], tools=rows,
                  scope='Artifact identity only; not application execution or performance.')
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(result))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    main(parser.parse_args())
