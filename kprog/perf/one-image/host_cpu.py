"""Apply the frozen host CPU preparation and restore shared-node controls."""
import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import signal
import subprocess

ROOT = Path(__file__).resolve().parents[3]
CPU = Path('/sys/devices/system/cpu')


def snapshot(root):
    paths = [root/'intel_pstate/no_turbo']
    governors = sorted(root.glob('cpu[0-9]*/cpufreq/scaling_governor'))
    policies = sorted(root.glob('cpufreq/policy[0-9]*'))
    if not governors or not policies:
        raise RuntimeError('Frozen kvm-host-cpu controls are unavailable')
    paths += governors
    paths += [policy/name for policy in policies
              for name in ('scaling_min_freq', 'scaling_max_freq')]
    return {str(path): path.read_text().strip() for path in paths}


def write_control(path, value):
    subprocess.run(['sudo', '-n', 'tee', str(path)], input=value+'\n',
                   text=True, stdout=subprocess.DEVNULL, check=True)


def run_batch(command, state, *, root=CPU, prepare=None, writer=write_control):
    if prepare is None:
        prepare = ['make', '-r', '-C', str(ROOT), 'kvm-host-cpu']
    state.parent.mkdir(parents=True, exist_ok=True)
    record = dict(command=command, prepare=prepare, before=snapshot(root), signals=[])
    child = None
    restoring = False

    def save():
        record['updated_at'] = datetime.now(timezone.utc).isoformat()
        state.write_text(json.dumps(record, indent=2)+'\n')

    def interrupted(number, frame):
        record['signals'].append(number)
        if child is not None and not restoring and child.poll() is None:
            child.send_signal(number)

    def invoke(arguments):
        nonlocal child
        if record['signals']:
            raise InterruptedError('CPU batch interrupted before child launch')
        child = subprocess.Popen(arguments)
        try:
            if record['signals']:
                child.send_signal(record['signals'][-1])
            return child.wait()
        finally:
            child = None

    previous = {s: signal.signal(s, interrupted) for s in (signal.SIGINT, signal.SIGTERM)}
    try:
        save()
        try:
            status = invoke(prepare)
            record['prepare_returncode'] = status
            save()
            if status:
                raise subprocess.CalledProcessError(status, prepare)
            record['prepared'] = snapshot(root)
            save()
            status = invoke(command)
            record['command_returncode'] = status
            save()
            return 128-status if status < 0 else status
        finally:
            restoring = True
            errors = []

            def restore(path, value):
                try:
                    if path.read_text().strip() != value:
                        writer(path, value)
                except (OSError, subprocess.CalledProcessError) as error:
                    errors.append(dict(path=str(path), error=str(error)))

            before = record['before']
            # Restore turbo first so the old frequency bounds are available.
            turbo = root/'intel_pstate/no_turbo'
            restore(turbo, before[str(turbo)])
            for policy in sorted(root.glob('cpufreq/policy[0-9]*')):
                low, high = policy/'scaling_min_freq', policy/'scaling_max_freq'
                # Lower min before restoring max, then restore the original min.
                current_low = low.read_text().strip()
                restore(low, str(min(int(current_low), int(before[str(low)]))))
                restore(high, before[str(high)])
                restore(low, before[str(low)])
            for path, value in before.items():
                if path.endswith('/scaling_governor'):
                    restore(Path(path), value)
            record['restore_errors'] = errors
            record['after_restore'] = snapshot(root)
            save()
            if errors or record['after_restore'] != before:
                raise RuntimeError('Host CPU controls were not fully restored; see '+str(state))
    finally:
        for number, handler in previous.items():
            signal.signal(number, handler)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--state', type=Path, required=True)
    parser.add_argument('command', nargs=argparse.REMAINDER)
    args = parser.parse_args()
    command = args.command[1:] if args.command[:1] == ['--'] else args.command
    if not command:
        parser.error('a batch command is required after --')
    raise SystemExit(run_batch(command, args.state))
