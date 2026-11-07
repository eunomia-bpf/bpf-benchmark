"""Audit every full native ELF candidate selected by the six ARM manifests.

A missing explicit symbol uses all STT_FUNC names whose kernel truncation
matches the selector. This is deliberately candidate coverage: live source BTF
must choose the exact entry at load time; this audit never invents that identity.
"""
from collections import Counter
from datetime import datetime, timezone
import gzip
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
STAGE = ROOT / 'kprog/arm64/build/app-verified-stage'
LINK = ROOT / 'kprog/arm64/build/app-native-link/release/native-link'
GEN = ROOT / 'kprog/arm64/micro-prog/generate_micro_sim_proofs.py'
sys.path.insert(0, str(GEN.parent))
spec = importlib.util.spec_from_file_location('arm64_manifest_dispatch_generator', GEN)
gen = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = gen
spec.loader.exec_module(gen)


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    out = HERE / 'manifest-dispatch-result'
    out.mkdir(exist_ok=True)
    summary = dict(scope='manifest selectors and all matching native ELF candidates; not loaded-program/verifier/execution coverage',
        started=datetime.now(timezone.utc).isoformat(), apps={}, failure_classes={})
    failures = Counter()
    with gzip.open(out / 'selectors.jsonl.gz', 'wt') as records:
        for app in ['bcc', 'cilium', 'katran', 'otelcol-ebpf-profiler', 'tetragon', 'tracee']:
            manifest = STAGE / app / 'manifest.json'
            counts = Counter()
            manifest_sha = sha(manifest)
            entries = json.loads(manifest.read_text())['objects']
            for index, entry in enumerate(entries, 1):
                counts['selectors'] += 1
                native = manifest.parent / entry['native_object']
                with native.open('rb') as stream:
                    elf = ELFFile(stream)
                    functions = sorted({s.name for s in elf.get_section_by_name('.symtab').iter_symbols()
                        if s['st_info']['type'] == 'STT_FUNC' and isinstance(s['st_shndx'], int) and s['st_size']})
                symbol = entry.get('symbol') or entry.get('source_btf_symbol')
                candidates = [symbol] if symbol else [name for name in functions if name[:15] == entry['program']]
                record = dict(app=app, index=index, selector=entry, manifest_sha256=manifest_sha,
                    native_sha256=sha(native), selection='explicit' if symbol else 'all kernel-name-matching STT_FUNC candidates', candidates=[])
                if not candidates:
                    record.update(status='failed', error='no native ELF function matches selector')
                    failures['selector_without_ELF_candidate'] += 1
                for symbol in candidates:
                    counts['candidates'] += 1
                    candidate = dict(symbol=symbol, status='failed')
                    try:
                        with tempfile.TemporaryDirectory(prefix='arm64-dispatch-') as temporary:
                            directory = Path(temporary)
                            proof = directory / 'audit.proof.o'
                            command = [str(LINK), '--input', str(native), '--symbol', symbol,
                                '--mode', 'proof', '--preserve-entry-abi', '--output', str(proof)]
                            result = subprocess.run(command, text=True, capture_output=True)
                            candidate.update(command=command, returncode=result.returncode,
                                stdout=result.stdout, stderr=result.stderr)
                            result.check_returncode()
                            candidate['proof_sha256'] = sha(proof)
                            bodies, _ = gen.parse_native_linked_program(gen.Bench('audit', symbol, 'raw'), directory)
                            insns = [i for body in bodies.values() for i in body]
                            targets = gen.indirect_targets(insns)
                            candidate.update(instruction_count=len(insns), indirect_sites=[
                                dict(address=address, targets=sorted(values)) for address, values in sorted(targets.items())],
                                status='finite_target_analysis_complete')
                            counts['indirect_sites'] += len(targets)
                            counts['finite_candidates'] += 1
                    except Exception as error:
                        candidate.update(error=str(error), error_class=type(error).__name__)
                        failures[type(error).__name__ + ': ' + str(error).split(':')[0]] += 1
                    record['candidates'].append(candidate)
                if candidates:
                    record['status'] = 'finite_target_analysis_complete' if all(c['status'] == 'finite_target_analysis_complete' for c in record['candidates']) else 'failed'
                counts['finite_selectors' if record['status'] == 'finite_target_analysis_complete' else 'failed_selectors'] += 1
                records.write(json.dumps(record) + chr(10)); records.flush()
            summary['apps'][app] = dict(counts)
            print(app, dict(counts), flush=True)
    summary.update(finished=datetime.now(timezone.utc).isoformat(), failure_classes=dict(failures),
        tools=dict(native_link_sha256=sha(LINK), generator_sha256=sha(GEN)))
    (out / 'summary.json').write_text(json.dumps(summary, indent=2) + chr(10))
    (out / 'tools.json').write_text(json.dumps(summary['tools'], indent=2) + chr(10))
    if failures:
        raise SystemExit(1)


if __name__ == '__main__':
    main()
