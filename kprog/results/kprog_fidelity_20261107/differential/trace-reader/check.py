#!/usr/bin/env python3
"""Replay archived observer streams through the generic trace reader."""
import argparse
import csv
import hashlib
import importlib.util
import io
import json
from pathlib import Path
import struct
import subprocess
import sys
import tarfile
import tempfile
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[5]
BASE = ROOT / 'kprog/results/kprog_fidelity_20261107/differential'
READER = ROOT / 'kprog/fidelity/reference_check.py'
REFERENCE = Path('/workspaces/.agent-state/kprog-lanes/F/reference-control-frozen')

def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)
    spec = importlib.util.spec_from_file_location('trace_reader', READER)
    reader = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(reader)
    reader_sha = sha(READER)
    arm = BASE / 'arm64-numeric-tokens'
    x86 = BASE / 'x86-numeric-tokens'
    archive = arm / 'baseline-attempts.tar.gz'
    with tarfile.open(archive) as outer:
        nested = outer.extractfile('arm64-numeric-tokens-baseline-unsupported.tar.gz').read()
    with tarfile.open(fileobj=io.BytesIO(nested)) as inner:
        entries = {Path(m.name).name: inner.extractfile(m).read() for m in inner.getmembers()
                   if m.isfile() and Path(m.name).name in {'cpu-states.bin', 'run.log'}}
    assert entries['cpu-states.bin'] == b''
    results = []
    with tempfile.TemporaryDirectory(prefix='trace-reader-', dir='/workspaces/.agent-state/kprog-lanes/F') as temp:
        work = Path(temp)
        trace = work / 'fixture.bin'
        header = b'KPFID002' + struct.pack('<4I', 840, 256, 8, 1024)
        # Actual archived zero-byte observer failure plus format boundary cases.
        failures = [
            ('archived_empty', entries['cpu-states.bin'], 'header truncated'),
            ('partial_header', header[:23], 'header truncated'),
            ('header_only', header, 'length mismatch'),
            ('partial_record', header + bytes(3303), 'length mismatch'),
            ('magic', b'KPFID001' + header[8:], 'layout mismatch'),
            ('state_size', b'KPFID002' + struct.pack('<4I', 841, 256, 8, 1024), 'layout mismatch'),
            ('memory_size', b'KPFID002' + struct.pack('<4I', 840, 255, 8, 1024), 'layout mismatch'),
            ('form_count', b'KPFID002' + struct.pack('<4I', 840, 256, 7, 1024), 'layout mismatch'),
            ('case_count', b'KPFID002' + struct.pack('<4I', 840, 256, 8, 1023), 'layout mismatch'),
        ]
        for name, data, reason in failures:
            trace.write_bytes(data)
            try:
                reader.trace_layout(trace, 'arm64', 8, 1024, -6)
            except RuntimeError as error:
                message = str(error)
                assert reason in message and 'observer_returncode=-6' in message
                results.append(dict(check=name, status='pass', message=message.replace(str(work), '$WORK')))
            else:
                raise AssertionError(name)
        good = arm / 'cpu-states.bin'
        assert reader.trace_layout(good, 'arm64', 8, 1024, 1) == (344, 256, 8, 1024, 1816)
        results.append(dict(check='complete_trace_with_observer_mismatch_exit', status='pass'))
        assert reader.trace_layout(x86 / 'cpu-states.bin', 'x86', 32, 1024, 0) == (344, 256, 32, 1024, 1816)
        results.append(dict(check='complete_x86_trace', status='pass'))
        trace.write_bytes(b'KPFID002' + struct.pack('<4I', 840, 256, 1, 1) + bytes(3304))
        assert reader.trace_layout(trace, 'arm64', 1, 1, 0) == (840, 256, 1, 1, 3304)
        results.append(dict(check='full_vector_arm_layout', status='pass'))
        try:
            reader.trace_layout(trace, 'x86', 1, 1, 0)
        except RuntimeError as error:
            assert 'layout mismatch' in str(error)
            results.append(dict(check='architecture_layout', status='pass'))
        else:
            raise AssertionError('architecture_layout')
        # Header-first diagnostics precede metadata access and preserve reports.
        for code in [-6, 1, 0]:
            out = work / f'exit-{code}'
            out.mkdir()
            sentinel = out / 'reference-mismatches.jsonl'
            sentinel.write_text('retained report\n')
            trace_path = out / 'cpu-states.bin'
            trace_path.write_bytes(entries['cpu-states.bin'])
            calls = []
            def stopped(command, **kwargs):
                calls.append(command)
                return subprocess.CompletedProcess(command, code)
            argv = ['reference_check.py', '--binary', str(ROOT / 'kprog/fidelity/build-arm64-numeric-tokens/cpu-differential'),
                    '--arch', 'arm64', '--cases', '1024', '--out', str(out)]
            with patch.object(sys, 'argv', argv), patch.object(reader.subprocess, 'run', stopped):
                try:
                    reader.main()
                except RuntimeError as error:
                    message = str(error)
                    assert f'observer_returncode={code}' in message and 'header_bytes=0' in message
                else:
                    raise AssertionError('observer_failure')
            assert len(calls) == 1 and sentinel.read_text() == 'retained report\n'
            results.append(dict(check=f'fresh_observer_exit_{code}', status='pass',
                                observer_calls=1, canonical_calls=0,
                                message=message.replace(str(work), '$WORK')))
        # One extra byte exercises exact-length checking on a real complete stream.
        with trace.open('wb') as output, good.open('rb') as source:
            while chunk := source.read(1024 * 1024):
                output.write(chunk)
            output.write(b'\0')
        try:
            reader.trace_layout(trace, 'arm64', 8, 1024)
        except RuntimeError as error:
            assert 'length mismatch' in str(error) and 'saved_trace' in str(error)
            results.append(dict(check='complete_trace_extra_byte', status='pass'))
        else:
            raise AssertionError('complete_trace_extra_byte')
    inputs = []
    for arch, cohort, build in [('arm64', arm, 'build-arm64-numeric-tokens'),
                                 ('x86', x86, 'build-x86-numeric-tokens')]:
        out = args.out / arch
        out.mkdir(exist_ok=True)
        for name in ['forms.tsv', 'native-code.json']:
            (out / name).write_bytes((cohort / name).read_bytes())
        command = [sys.executable, str(READER), '--reuse-trace',
                   '--binary', str(ROOT / 'kprog/fidelity' / build / 'cpu-differential'),
                   '--arch', arch, '--cases', '1024', '--out', str(out),
                   '--trace', str(cohort / 'cpu-states.bin'), '--reference', str(REFERENCE)]
        completed = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        (out / 'run.log').write_text(completed.stdout)
        assert completed.returncode == 0, completed.stdout
        names = ['reference-forms.tsv', 'reference-mismatches.jsonl', 'reference-unavailable.jsonl']
        for name in names:
            assert (out / name).read_bytes() == (cohort / name).read_bytes(), (arch, name)
        with (out / 'reference-forms.tsv').open() as source:
            rows = list(csv.DictReader(source, delimiter='\t'))
        results.append(dict(check=arch + '_canonical_replay', status='pass',
                            forms=len(rows), cases=sum(int(row['reference_cases']) for row in rows),
                            byte_identical_reports=names, command=command))
        inputs.append(dict(arch=arch, trace=str(cohort / 'cpu-states.bin'),
                           trace_sha256=sha(cohort / 'cpu-states.bin'),
                           trace_bytes=(cohort / 'cpu-states.bin').stat().st_size))
    assert reader_sha == sha(READER)
    summary = dict(reader_sha256=reader_sha, archive_sha256=sha(archive),
                   archived_baseline_trace_bytes=len(entries['cpu-states.bin']),
                   reference_sha256=sha(REFERENCE), checks=results, inputs=inputs,
                   checked_cases=sum(row.get('cases', 0) for row in results))
    (args.out / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    print(json.dumps(dict(checks=len(results), cases=summary['checked_cases'], status='pass')))
    return 0

if __name__ == '__main__':
    raise SystemExit(main())
