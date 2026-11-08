#!/usr/bin/env python3
"""Fresh compiler jobs for a registered specializer across a shared VM directory."""
from __future__ import annotations

import argparse
import hashlib
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import time
import uuid

ROOT = Path(__file__).resolve().parents[1]


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def atomic_json(path: Path, value: dict) -> None:
    temporary = path.with_name(path.name + '.' + uuid.uuid4().hex + '.tmp')
    with temporary.open('x') as output:
        json.dump(value, output)
        output.write('\n')
    os.replace(temporary, path)


def compile_command(source: Path, output: Path, arch: str, clang: str, arm64_sysroot: Path | None = None) -> list[str]:
    if arch == 'arm64' and arm64_sysroot is not None:
        return [clang, '-g', '-O2', '-mcpu=v4', '-target', 'bpf', '-mllvm',
                '-bpf-stack-size=4096', '-D__TARGET_ARCH_arm64',
                '--sysroot=' + str(arm64_sysroot),
                '-I', str(ROOT / 'vendor/libbpf/include/uapi'),
                '-I', str(ROOT / 'vendor/libbpf/src'),
                '-I', str(arm64_sysroot / 'usr/include/aarch64-linux-gnu'),
                '-c', str(source), '-o', str(output)]
    return [clang, '-g', '-O3', '-mcpu=v4', '-target', 'bpf', '-mllvm',
            '-bpf-stack-size=4096', '-D__TARGET_ARCH_' + arch,
            '-I', str(ROOT / 'kprog' / arch),
            '-I', str(ROOT / 'kprog/formal/generated'),
            '-I', str(ROOT / 'vendor/libbpf/include/uapi'),
            '-I', str(ROOT / 'vendor/libbpf/src'),
            '-I', '/usr/include/x86_64-linux-gnu', '-c', str(source), '-o', str(output)]


def execute(job: dict, scope: Path, clang: str, arm64_sysroot: Path | None = None) -> dict:
    source, output, arch = Path(job['source']), Path(job['output']), job['arch']
    command = compile_command(source, output, arch, clang, arm64_sysroot)
    start = time.monotonic()
    with tempfile.TemporaryFile() as stdout, tempfile.TemporaryFile() as stderr:
        child = subprocess.Popen(command, stdout=stdout, stderr=stderr)
        _, status, usage = os.wait4(child.pid, 0)
        child.returncode = os.waitstatus_to_exitcode(status)
        stdout.seek(0)
        stderr.seek(0)
        result = dict(returncode=child.returncode,
                      stdout=stdout.read().decode(errors='replace'),
                      stderr=stderr.read().decode(errors='replace'),
                      command=command, source_sha256=digest(source),
                      compiler_sha256=digest(Path(clang)),
                      wall_seconds=time.monotonic() - start,
                      max_rss_kib=usage.ru_maxrss,
                      user_seconds=usage.ru_utime, system_seconds=usage.ru_stime)
    if result['returncode'] == 0:
        result['object_sha256'] = digest(output)
    return result


def serve(scope: Path, state: Path, clang: str, arm64_sysroot: Path | None = None) -> None:
    scope = scope.resolve(strict=True)
    state = state.resolve()
    state.mkdir(mode=0o700, parents=True, exist_ok=True)
    os.chmod(state, 0o700)
    owner = (state / 'owner.lock').open('a')
    fcntl.flock(owner.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)
    compiler = shutil.which(clang)
    if compiler is None:
        raise ValueError('trusted Clang executable is unavailable')
    compiler = str(Path(compiler).resolve())
    atomic_json(state / 'ready.json', dict(pid=os.getpid(), scope=str(scope),
                                          clang=compiler, compiler_sha256=digest(Path(compiler))))
    handled: set[str] = set()
    while not (state / 'STOP').exists():
        for request in sorted(state.glob('*.request.json')):
            identity = request.name.removesuffix('.request.json')
            if identity in handled:
                continue
            try:
                job = json.loads(request.read_text())
                result = execute(job, scope, compiler, arm64_sysroot)
            except Exception as error:
                result = dict(returncode=1, stdout='', stderr=str(error) + '\n')
            atomic_json(state / (identity + '.result.json'), result)
            summary = {key: value for key, value in result.items() if key not in {'stdout', 'stderr'}}
            summary.update(request_id=identity, stdout_bytes=len(result['stdout'].encode()),
                           stderr_bytes=len(result['stderr'].encode()))
            with (state / 'jobs.jsonl').open('a') as log:
                log.write(json.dumps(summary) + '\n')
            handled.add(identity)
        time.sleep(0.1)


def submit(state: Path, source: Path, output: Path, arch: str) -> int:
    state = state.resolve(strict=True)
    source, output = source.resolve(strict=True), output.resolve()
    identity = uuid.uuid4().hex
    job = dict(source=str(source), output=str(output), arch=arch, source_sha256=digest(source))
    atomic_json(state / (identity + '.request.json'), job)
    response = state / (identity + '.result.json')
    # Shared VM filesystems expose host writes through ordinary lookup; the
    # short wait also works with their remote inotify limitations.
    while not response.exists():
        if (state / 'failed.json').exists():
            raise RuntimeError((state / 'failed.json').read_text())
        time.sleep(0.1)
    result = json.loads(response.read_text())
    receipt = {key: value for key, value in result.items() if key not in {'stdout', 'stderr'}}
    atomic_json(output.with_suffix(output.suffix + '.compiler.json'), receipt)
    print(result['stdout'], end='')
    import sys
    print(result['stderr'], end='', file=sys.stderr)
    return result['returncode'] if result['returncode'] >= 0 else 128 - result['returncode']


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest='mode', required=True)
    server = commands.add_parser('serve')
    server.add_argument('--scope', type=Path, required=True)
    server.add_argument('--state', type=Path, required=True)
    server.add_argument('--clang', default='clang-18')
    server.add_argument('--arm64-sysroot', type=Path)
    client = commands.add_parser('submit')
    client.add_argument('--state', type=Path, required=True)
    client.add_argument('--source', type=Path, required=True)
    client.add_argument('--output', type=Path, required=True)
    client.add_argument('--arch', choices=['x86', 'arm64'], required=True)
    arguments = parser.parse_args()
    if arguments.mode == 'serve':
        serve(arguments.scope, arguments.state, arguments.clang, arguments.arm64_sysroot)
        return 0
    return submit(arguments.state, arguments.source, arguments.output, arguments.arch)


if __name__ == '__main__':
    raise SystemExit(main())
