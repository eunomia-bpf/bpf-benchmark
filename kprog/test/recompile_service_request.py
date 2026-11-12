"""Regenerate and compile B from a captured x86 service request.

The registered adapter consumes the captured P, entry and generation metadata.
Kernel verification and application execution use their separate service runs.
"""
import argparse
import io
import json
from pathlib import Path
import sys
import tarfile

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'kprog'))
from trusted_service import adapter

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('archive', type=Path)
parser.add_argument('member')
parser.add_argument('output', type=Path)
args = parser.parse_args()
with tarfile.open(args.archive) as outer:
    captured = outer.extractfile(args.member).read()
with tarfile.open(fileobj=io.BytesIO(captured)) as request:
    native = request.extractfile('request/kernel.native.o').read()
    entry = request.extractfile('request/kernel.entry').read().decode().strip()
    metadata = json.loads(request.extractfile('request/generation.metadata.json').read())
adapter(1).specialize(native, entry, metadata, args.output,
    ROOT/'kprog/x86/native_lab/native_link/target/release/native-link')
