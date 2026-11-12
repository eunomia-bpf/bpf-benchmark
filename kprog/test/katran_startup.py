"""Actual upstream Katran startup and packet TEST_RUN under a registered service.

The existing session owns loading and attachment. This diagnostic retains raw
program counters and packet results; the corpus owns workload measurements.
"""
import argparse
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from runner.libs.agent import bpftool_prog_show_records
from runner.libs.app_runners.katran import KatranServerSession


def run(inputs, output):
    output.mkdir(parents=True, exist_ok=True)
    os.environ['BPFTOOL_BIN'] = str(ROOT/'vendor/build/x86/bpftool/bin/bpftool')
    os.environ['LD_LIBRARY_PATH'] = str(inputs/'lib')
    Path('/proc/sys/kernel/bpf_stats_enabled').write_text('1\n')
    initial = bpftool_prog_show_records()
    (output/'programs-initial.json').write_text(json.dumps(initial, indent=2))
    subprocess.run(['ip', 'link', 'add', 'tvkatran0', 'type', 'veth',
                    'peer', 'name', 'tvkatran1'], check=True)
    session = KatranServerSession(server_binary=inputs/'katran_server_grpc',
        balancer_prog_path=ROOT/'vendor/build/x86/katran/bpf/balancer.bpf.o',
        healthchecking_prog_path=ROOT/'vendor/build/x86/katran/bpf/healthchecking_ipip.bpf.o',
        iface='tvkatran0', default_router_mac='02:00:00:00:00:01')
    try:
        for iface in ('tvkatran0', 'tvkatran1'):
            subprocess.run(['ip', 'link', 'set', iface, 'up'], check=True)
        with session:
            try:
                (output/'session.json').write_text(json.dumps(session.metadata(), indent=2))
                before = bpftool_prog_show_records()
                (output/'programs-before-work.json').write_text(json.dumps(before, indent=2))
                initial_ids = {p['id'] for p in initial}
                for program in before:
                    if program['id'] in initial_ids:
                        continue
                    prefix = output/str(program['id'])
                    command = [os.environ['BPFTOOL_BIN'], '-j', 'prog', 'run',
                        'id', str(program['id']), 'data_in',
                        str(ROOT/'corpus/inputs/katran_vip_packet_64.bin'),
                        'data_out', str(prefix)+'.packet', 'repeat', '1']
                    result = subprocess.run(command, text=True, capture_output=True)
                    Path(str(prefix)+'.json').write_text(json.dumps(dict(command=command,
                        returncode=result.returncode, stdout=result.stdout, stderr=result.stderr), indent=2))
                    result.check_returncode()
                (output/'programs-after-work.json').write_text(json.dumps(bpftool_prog_show_records(), indent=2))
            finally:
                (output/'server-output.json').write_text(json.dumps(session.collector_snapshot(), indent=2))
    finally:
        subprocess.run(['ip', 'link', 'del', 'tvkatran0'], check=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('inputs', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    run(args.inputs, args.output)
