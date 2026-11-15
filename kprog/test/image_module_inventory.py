"""Record installed/image kernel module identities; no runtime admission gate."""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import subprocess
import sys
from elftools.elf.elffile import ELFFile
from image_native_inventory import digest, image_files

ROOT = Path(__file__).resolve().parents[2]


def main(a):
    manifest, image = image_files(a.image, PurePosixPath('artifacts/lib/modules'))
    _, image_kernel = image_files(a.image, PurePosixPath('artifacts/kernel'))
    _, image_native = image_files(a.image, PurePosixPath('artifacts/kinsn'))
    built = {}
    for name, path in [('boot', a.kernel/'arch/x86/boot/bzImage'),
                       ('native_module', ROOT/'kinsn/module/x86/build/bpf_x86_native_lab.ko')]:
        with path.open('rb') as stream:
            built[name] = dict(bytes=path.stat().st_size, sha256=digest(stream))
    installed = {}
    for path in sorted((a.kernel/'modules-install/lib/modules').rglob('*')):
        name = str(path.relative_to(a.kernel/'modules-install/lib/modules'))
        if path.is_symlink():
            installed[name] = dict(symlink=str(path.readlink()))
        elif path.is_file():
            with path.open('rb') as stream:
                installed[name] = dict(bytes=path.stat().st_size, sha256=digest(stream))
    with (a.kernel/'vmlinux').open('rb') as stream:
        btf = ELFFile(stream).get_section_by_name('.BTF')
        if btf is None:
            raise ValueError('sole kernel ELF has no BTF')
        btf_sha256 = hashlib.sha256(btf.data()).hexdigest()
    command = [sys.executable, str(ROOT/'vendor/linux-framework/scripts/diffconfig'),
               str(a.kernel/'.config.old'), str(a.kernel/'.config')]
    settings = subprocess.run(command, capture_output=True, text=True, check=True)
    differences = [dict(path=name, image=image.get(name), installed=installed.get(name))
                   for name in sorted(image.keys() | installed.keys()) if image.get(name) != installed.get(name)]
    result = dict(image=str(a.image), image_config=manifest['Config'], kernel=str(a.kernel),
        image_kernel=image_kernel, image_native_module=image_native.get('bpf_x86_native_lab.ko'),
        built=built, boot_matches=image_kernel.get('bzImage') == built['boot'],
        native_module_matches=image_native.get('bpf_x86_native_lab.ko') == built['native_module'],
        core_btf_sha256=btf_sha256, settings_diff_command=command, settings_diff=settings.stdout,
        image_files=image, installed_files=installed,
        module_differences=[row for row in differences if row['path'].endswith('.ko')],
        metadata_differences=[row for row in differences if not row['path'].endswith('.ko')],
        scope='Offline packaging observations; metadata includes depmod outputs generated in the image.')
    a.output.mkdir(parents=True, exist_ok=True)
    (a.output/'module-inventory.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(dict(image_modules=sum(name.endswith('.ko') for name in image),
        installed_modules=sum(name.endswith('.ko') for name in installed),
        module_differences=len(result['module_differences']), metadata_differences=len(result['metadata_differences']),
        boot_matches=result['boot_matches'], native_module_matches=result['native_module_matches'],
        core_btf_sha256=btf_sha256, settings_diff=settings.stdout)))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['image', 'kernel', 'output']:
        parser.add_argument('--'+name, type=Path, required=True)
    main(parser.parse_args())
