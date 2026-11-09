"""Recompile the three published Katran profiles for direct-native timing."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
import tarfile

ROOT = Path('/workspaces/repository')
STATE = Path('/var/tmp/kprog-tmp/C/direct-native-katran-handoff/rebuilt')
PROFILES = {
    'inline': Path('/var/tmp/kprog-tmp/C/katran-regression-current/inline-producer'),
    'array-cleanup': Path('/var/tmp/kprog-tmp/C/map-lookup-native/cleanup/candidate'),
    'percpu-array': Path('/var/tmp/kprog-tmp/C/map-lookup-native/percpu-array/candidate'),
}
HARDENING = {'-mretpoline-external-thunk', '-mfunction-return=thunk-extern',
             '-fcf-protection=branch'}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def main():
    STATE.mkdir(parents=True, exist_ok=True)
    results = []
    for label, original in PROFILES.items():
        work = STATE / label
        native = work / 'native/katran'
        native.mkdir(parents=True, exist_ok=True)
        old_commands = json.loads((original / 'commands.json').read_text())
        commands = []
        objects = []
        for old in old_commands:
            if '-c' not in old:
                continue
            command = [arg for arg in old if arg not in HARDENING]
            previous = Path(command[command.index('-o') + 1])
            output = native / previous.name
            command[command.index('-o') + 1] = str(output)
            plugin_at = next(i for i, arg in enumerate(command)
                             if arg.startswith('-fpass-plugin='))
            plugin = Path(command[plugin_at].split('=', 1)[1])
            preserved_plugin = work / 'native_division.so'
            shutil.copy2(plugin, preserved_plugin)
            command[plugin_at] = '-fpass-plugin=' + str(preserved_plugin)
            commands.append(command)
            with (work / (output.stem + '.log')).open('w') as log:
                run = subprocess.run(command, cwd=ROOT, stdout=log,
                                     stderr=subprocess.STDOUT)
            (work / (output.stem + '.exit')).write_text(str(run.returncode) + '\n')
            run.check_returncode()
            symbols = subprocess.check_output(
                ['llvm-nm-18', '--undefined-only', str(output)], text=True)
            objects.append(dict(name=output.name, sha256=sha(output),
                                source=command[-1], source_sha256=sha(Path(command[-1])),
                                plugin_sha256=sha(preserved_plugin),
                                undefined_symbols=symbols.splitlines()))
        command = ['python3', str(ROOT / 'vendor/bpf/write_native_manifest.py'),
                   '--app', 'katran', '--llvm-nm', 'llvm-nm-18',
                   '--output', str(native / 'manifest.json')]
        for row in objects:
            command += ['--object', str(native / row['name'])]
        commands.append(command)
        with (work / 'manifest.log').open('w') as log:
            run = subprocess.run(command, cwd=ROOT, stdout=log,
                                 stderr=subprocess.STDOUT)
        (work / 'manifest.exit').write_text(str(run.returncode) + '\n')
        run.check_returncode()
        write(work / 'commands.json', commands)
        row = dict(profile=label, original_commands=str(original / 'commands.json'),
                   removed_compiler_flags=sorted(HARDENING), objects=objects,
                   manifest_rows=len(json.loads((native / 'manifest.json').read_text())['objects']),
                   manifest_sha256=sha(native / 'manifest.json'))
        write(work / 'summary.json', row)
        archive = STATE / (label + '.tar.gz')
        with tarfile.open(archive, 'w:gz') as stream:
            stream.add(work / 'native', arcname='native')
        row['payload'] = str(archive)
        row['payload_sha256'] = sha(archive)
        results.append(row)
        write(STATE / 'progress.json', results)
    write(STATE / 'complete.json', results)


if __name__ == '__main__':
    main()
