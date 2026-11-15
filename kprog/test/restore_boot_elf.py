"""Repair canonical kernel metadata from the unchanged authoritative boot image."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile


def describe(path):
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        return dict(path=str(path), bytes=path.stat().st_size,
                    sections={name: hashlib.sha256(elf.get_section_by_name(name).data()).hexdigest()
                              for name in ['.text', '.BTF']},
                    build_ids=[note['n_desc'] for note in elf.get_section_by_name('.notes').iter_notes()
                               if note['n_type'] == 'NT_GNU_BUILD_ID'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--kernel', type=Path, required=True)
    parser.add_argument('--extractor', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    canonical = args.kernel/'vmlinux'
    temporary = args.kernel/'.vmlinux.perf-boot-repair'
    boot = args.kernel/'arch/x86/boot/bzImage'
    record = dict(recorded=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
                  before=describe(canonical), authoritative=describe(args.kernel/'arch/x86/boot/compressed/vmlinux.bin'),
                  boot_image_sha256=hashlib.sha256(boot.read_bytes()).hexdigest())
    with temporary.open('xb') as stream:
        subprocess.run([args.extractor, boot], stdout=stream, check=True)
    record['extracted'] = describe(temporary)
    if any(record['extracted'][key] != record['authoritative'][key] for key in ['sections', 'build_ids']):
        raise ValueError('Extracted ELF does not match the authoritative boot build')
    os.replace(temporary, canonical)
    record['canonical_sha256'] = hashlib.sha256(canonical.read_bytes()).hexdigest()
    record['scope'] = 'Metadata repair only; boot image/source/guests unchanged. Earlier module-build ELF was not authoritative.'
    (args.output/'receipt.json').write_text(json.dumps(record, indent=2)+'\n')


if __name__ == '__main__':
    main()
