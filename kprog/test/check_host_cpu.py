"""Exercise CPU-control restoration on command/preparation failure and SIGTERM."""
import argparse
import importlib.util
import json
import os
from pathlib import Path
import signal
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('host_cpu', ROOT/'kprog/perf/one-image/host_cpu.py')
cpu = importlib.util.module_from_spec(spec)
spec.loader.exec_module(cpu)


def write_checked(path, value):
    if path.name in ('scaling_min_freq', 'scaling_max_freq'):
        other = path.parent/('scaling_max_freq' if path.name == 'scaling_min_freq' else 'scaling_min_freq')
        if ((path.name == 'scaling_min_freq' and int(value) > int(other.read_text())) or
            (path.name == 'scaling_max_freq' and int(value) < int(other.read_text()))):
            raise ValueError('Invalid frequency-bound restoration order')
    path.write_text(value+'\n')


def prepare_fixture(root, status):
    for path in root.glob('cpu[0-9]*/cpufreq/scaling_governor'):
        path.write_text('performance\n')
    (root/'intel_pstate/no_turbo').write_text('1\n')
    for index, maximum in ((0, 4700), (16, 3300)):
        policy = root/f'cpufreq/policy{index}'
        (policy/'scaling_min_freq').write_text(('4700' if index == 0 else '800')+'\n')
        (policy/'scaling_max_freq').write_text(str(maximum)+'\n')
    return status


def check(a):
    a.output.mkdir(parents=True, exist_ok=True)
    results = []
    for name, command_status, prepare_status in (
            ('success', 0, 0), ('command-failure', 7, 0),
            ('prepare-failure', 0, 5), ('signal', -15, 0)):
        root = a.build/name
        values = {'intel_pstate/no_turbo': '0'}
        for index, governor, low, high in ((0, 'powersave', 5200, 5500), (16, 'schedutil', 800, 4300)):
            values[f'cpu{index}/cpufreq/scaling_governor'] = governor
            values[f'cpufreq/policy{index}/scaling_min_freq'] = str(low)
            values[f'cpufreq/policy{index}/scaling_max_freq'] = str(high)
        for filename, value in values.items():
            path = root/filename
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(value+'\n')
        before = cpu.snapshot(root)
        command = [sys.executable, __file__, 'signal_fixture' if name == 'signal' else 'exit_fixture', str(command_status)]
        try:
            status = cpu.run_batch(command, a.output/(name+'.json'), root=root,
                prepare=[sys.executable, __file__, 'prepare_fixture', str(root), str(prepare_status)],
                writer=write_checked)
        except subprocess.CalledProcessError as error:
            if name != 'prepare-failure' or error.returncode != 5:
                raise
            status = 5
        expected = 143 if name == 'signal' else prepare_status or command_status
        if status != expected or cpu.snapshot(root) != before:
            raise ValueError('CPU controls not restored for '+name)
        results.append(dict(case=name, returncode=status, restored=True))
    (a.output/'result.json').write_text(json.dumps(results, indent=2)+'\n')
    print(json.dumps(results), flush=True)


if __name__ == '__main__':
    if sys.argv[1:2] == ['prepare_fixture']:
        raise SystemExit(prepare_fixture(Path(sys.argv[2]), int(sys.argv[3])))
    if sys.argv[1:2] == ['exit_fixture']:
        raise SystemExit(int(sys.argv[2]))
    if sys.argv[1:2] == ['signal_fixture']:
        os.kill(os.getppid(), signal.SIGTERM)
        time.sleep(1)
        raise SystemExit('SIGTERM was not forwarded to the batch child')
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('build', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    check(parser.parse_args())
