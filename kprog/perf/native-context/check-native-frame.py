#!/usr/bin/env python3
"""Catch the observed zero-offset saved-BPF-frame tail-call recovery bug."""
import argparse
import json
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, required=True)
    args = parser.parse_args()
    build = args.build
    # Exact faulting sequence: recover BPF RBP from RSP+0, then read its -16
    # tail-counter slot. A frame-pointer prologue makes that RSP slot a local.
    bad = bytes.fromhex('48 8b 84 24 00 00 00 00 48 8b 80 f0 ff ff ff')
    before = (build / 'before-links/native_frame.kernel.bin').read_bytes()
    after = (build / 'after-links/native_frame.kernel.bin').read_bytes()
    if bad not in before:
        raise AssertionError('fixture did not reproduce the observed wrong frame recovery')
    if bad in after:
        raise AssertionError('native tail call still recovers BPF RBP from a local stack slot')
    if (build / 'default-before.bc').read_bytes() != (build / 'default-after.bc').read_bytes():
        raise AssertionError('default compiler output changed')
    result = dict(old_fault_sequence_present=True, new_fault_sequence_present=False,
                  default_bitcode_byte_identical=True,
                  scope='Compiler/frame ABI regression and offline synthetic relocations; no actual native installation.')
    (build / 'regression.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))


if __name__ == '__main__':
    main()
