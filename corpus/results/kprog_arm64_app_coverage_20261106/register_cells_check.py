"""Drive existing register/flag/helper semantic oracles against the frozen candidate."""
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
PHASE = Path(sys.argv[1]).resolve() if len(sys.argv) > 1 else HERE / 'register-cells'
BUILD = ROOT / 'kprog/arm64/build/register-cell-hosts'
CASES = sys.argv[2:] or ['test_arm64_reg_dispatch_route_host', 'test_arm64_write_arm_route_host',
         'test_arm64_alu_operand_select_route_host', 'test_arm64_flag_route_host',
         'test_arm64_csel_route_host', 'test_arm64_helper_call_host']


def main():
    BUILD.mkdir(parents=True, exist_ok=True)
    logs = PHASE / 'host-check'
    logs.mkdir(exist_ok=True)
    failed = False
    for name in CASES:
        source = PHASE / 'formal/oracles' / (name + '.c')
        if not source.exists():
            source.parent.mkdir(parents=True, exist_ok=True)
            source.write_text((ROOT / 'kprog/formal/oracles' / source.name).read_text())
        frozen = BUILD / source.name
        frozen.write_text(source.read_text().replace(
            '../arm64/arm64_sim_local_bpf.h', str(PHASE / 'simulator/arm64_sim_local_bpf.h')))
        command = ['cc', '-Wall', '-Wextra', '-O2',
                   '-include', str(ROOT/'kprog/formal/oracles/arm64_entry_environment_host.h'),
                   '-DKPROG_TEST_EXCLUSIVE_FAILURE=0',
                   '-include', str(ROOT/'kprog/formal/oracles/arm64_exclusive_choice_host.h'),
                   '-I'+str(ROOT/'kprog/formal'),
                   '-I'+str(ROOT/'kprog'), '-I'+str(ROOT/'vendor/libbpf/src'),
                   str(frozen), '-o', str(BUILD/name)]
        compiled = subprocess.run(command, text=True, capture_output=True)
        record = dict(command=command, returncode=compiled.returncode,
                      stdout=compiled.stdout, stderr=compiled.stderr)
        if compiled.returncode == 0:
            run = subprocess.run([str(BUILD/name)], text=True, capture_output=True)
            record['execution'] = dict(command=[str(BUILD/name)], returncode=run.returncode,
                                       stdout=run.stdout, stderr=run.stderr)
            failed |= run.returncode != 0
            print(run.stdout.strip(), flush=True)
        else:
            failed = True
            print(compiled.stderr, flush=True)
        (logs/(name+'.json')).write_text(json.dumps(record)+'\n')
    return int(failed)


if __name__ == '__main__':
    raise SystemExit(main())
