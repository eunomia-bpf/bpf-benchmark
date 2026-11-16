"""Actual kernel regression: rejected/generated B, original P and error boundaries."""
import argparse
import io
import json
from pathlib import Path
import subprocess
import sys
import tarfile
from types import SimpleNamespace
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog'))
import trusted_service as service


def worker(case):
    original_adapter = service.adapter
    def adapter(arch):
        implementation = original_adapter(arch)
        original = implementation.specialize
        def specialize(*args, **kwargs):
            if case == 'generation':
                raise ValueError('deliberate B generation failure')
            artifacts = original(*args, **kwargs)
            if case in {'verification', 'native'}:
                from elftools.elf.elffile import ELFFile
                obj = Path(artifacts['simulator_object'])
                data = bytearray(obj.read_bytes())
                section = ELFFile(io.BytesIO(data)).get_section_by_name('xdp')
                end = section['sh_offset'] + section['sh_size'] - 8
                assert data[end] == 0x95, 'fixture must end in EXIT'
                data[end] = 0xff  # Kernel rejects this instruction; P is intact.
                obj.write_bytes(data)
                if case == 'native':
                    artifacts['symbol'] = 'missing_native_entry'
            elif case == 'artifact':
                artifacts['simulator_object'] += '.missing'
            return artifacts
        implementation.specialize = specialize
        return implementation
    service.adapter = adapter
    if case == 'transport':
        actual_run = service.subprocess.run
        def invalid_capability(command, **kwargs):
            if len(command) > 2 and str(command[1]) in {'verify', 'load-direct'}:
                command = list(command)
                command[2] = str((1 << 31) - 1)  # Real ioctl gets EBADF.
            return actual_run(command, **kwargs)
        service.subprocess.run = invalid_capability
    service.main()


def check(output, loader):
    compiler = Path('/workspaces/.agent-state/kprog-ck/verified-compiler')
    base = Path('/workspaces/.agent-state/kprog-ck/verified-loader')
    real_popen = subprocess.Popen
    rows = []
    for case in ('verification', 'generation', 'artifact', 'transport', 'native', 'accepted'):
        directory = output / case
        directory.mkdir(parents=True)
        args = SimpleNamespace(arch=1, endpoint=Path('/sys/kernel/debug/bpf_x86_native_lab/specializer'),
            module=None, state=directory/'state', results=directory/'service.tar.gz',
            native_link=ROOT/'kprog/x86/native_lab/native_link/target/release/native-link', loader=loader,
            execution_mode='checked-sim-c', sim_native_compiler=compiler/'compile-sim-ir',
            sim_context_compiler=compiler/'context-lower', sim_public_layout=compiler/'public-layout.json',
            sim_physical_layout=compiler/'physical-layout.json', sim_bounds_compiler=compiler/'packet-bounds',
            run=[str(base/'trusted-service-client'), str(base/'trusted-native.o')])
        def launch(command, **kwargs):
            if command[1] == str(Path(service.__file__).resolve()):
                command = [command[0], str(Path(__file__).resolve()), '--worker', case, *command[2:]]
            return real_popen(command, **kwargs)
        with patch.object(service.subprocess, 'Popen', side_effect=launch):
            status = service.run_application(args)
        assert status == (1 if case in {'transport', 'native'} else 0), (case, status)
        with tarfile.open(args.results) as archive:
            records = [json.loads(line) for line in archive.extractfile('service/requests/requests.jsonl')]
            assert len(records) == 1, records
            record = records[0]
            if case in {'transport', 'native'}:
                assert record['status'] != 0 and 'execution_path' not in record, record
                member = 'service/requests/' + Path(record['failure_archive']).name
                with tarfile.open(fileobj=io.BytesIO(archive.extractfile(member).read())) as failed:
                    assert 'request/load-direct.stderr' in failed.getnames()
            else:
                assert record['status'] == 0 and record['prog_id'] > 0, record
                assert record['execution_path'] == ('checked-sim-c' if case == 'accepted' else 'direct-native'), record
                assert record['b_stock_passed'] == (case == 'accepted'), record
                assert record['b_generated'] == (case != 'generation'), record
                if case != 'accepted':
                    assert record['simulator_failure']['stage'] == ('verification-preparation' if case == 'artifact' else case), record
        rows.append(dict(case=case, application_returncode=status, record=record))
        (output/'results.json').write_text(json.dumps(rows, indent=2)+'\n')


if __name__ == '__main__':
    if len(sys.argv) > 2 and sys.argv[1] == '--worker':
        selected = sys.argv[2]
        sys.argv = [str(Path(service.__file__).resolve()), *sys.argv[3:]]
        worker(selected)
    else:
        parser = argparse.ArgumentParser(description=__doc__)
        parser.add_argument('--output', type=Path, required=True)
        parser.add_argument('--loader', type=Path, required=True)
        args = parser.parse_args()
        check(args.output, args.loader)
