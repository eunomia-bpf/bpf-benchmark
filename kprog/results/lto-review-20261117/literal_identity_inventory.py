#!/usr/bin/env python3
"""Inventory existing ELF identities and dates without linking or executing."""
import datetime
import json
from pathlib import Path
import subprocess

stage = Path(__file__).resolve().parents[3] / 'vendor/build/native-bpf/x86/stage/tracee'


def inspect(path):
    stat = path.stat()
    symbols = subprocess.check_output(['readelf', '-sW', str(path)], text=True)
    sections = subprocess.check_output(['readelf', '-SW', str(path)], text=True)
    return dict(path=str(path), bytes=stat.st_size, mtime_utc=datetime.datetime.fromtimestamp(
        stat.st_mtime, datetime.timezone.utc).isoformat(),
        literal_symbols=[line.strip() for line in symbols.splitlines() if '.L.str.' in line],
        data_sections=[line.strip() for line in sections.splitlines()
                       if '.rodata.str1.1' in line or '.native_link_rodata' in line])


proofs = list(stage.glob('*.proof.o'))
result = dict(captured_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
              scope='Existing stage metadata only. Native P and staged proofs are not an input/output pair; no Os layout claim.',
              objects=[inspect(stage / name) for name in [
                  'tracee.native.o', 'trace_ret_vfs_write_tail.proof.o',
                  'trace_ret_vfs_writev_tail.proof.o']],
              stage_proof_count=len(proofs), stage_proof_bytes=sum(p.stat().st_size for p in proofs))
Path(__file__).with_name('literal-identities.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(dict(stage_proofs=len(proofs), stage_proof_bytes=result['stage_proof_bytes'],
                      observed_dates=[item['mtime_utc'] for item in result['objects']])))
