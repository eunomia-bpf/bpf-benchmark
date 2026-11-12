"""Invoke the frozen corpus from the registered-service supervisor's guest.

The guest preloads the selected transport; the one image supplies applications,
shim, loader and linker. Existing Make variables carry the runtime selection.
"""
import argparse
import os
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('app')
parser.add_argument('samples', type=int)
parser.add_argument('duration', type=int)
parser.add_argument('stats', choices=('0', '1'))
args = parser.parse_args()
environment = dict(os.environ,
    BPFREJIT_CORPUS_APPS=args.app,
    BPFREJIT_CORPUS_BPF_STATS=args.stats,
    BPFREJIT_SHIM_NATIVE_LOADER='post',
    BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF='1',
    BPFREJIT_SHIM_NATIVE_MANIFEST=os.environ.get('BPFREJIT_SHIM_NATIVE_MANIFEST',
        '/opt/bpf-benchmark/native-bpf/x86_64/' + args.app.split('/')[0] + '/manifest.json'),
    BPFREJIT_NATIVE_LINK_BINARY='/usr/local/bin/native-link',
    BPFREJIT_NATIVE_LOADER_SO='/usr/local/lib/bpfrejit/libnative_loader.so',
    KEEP_WORKDIRS='all', BPFREJIT_KEEP_ALL_WORKDIRS='1', SKIP_REJIT='norejit')
# Preserve the frozen Makefile's nine base names and forward the existing
# verified-path selector and raw-artifact retention flag through that API.
names = ('TARGET RUN_TARGET_NAME RUN_TOKEN RUN_TARGET_ARCH RUN_EXECUTOR '
    'RUN_REMOTE_PYTHON_BIN RUN_RUNTIME_PYTHON_BIN RUN_BPFTOOL_BIN RUN_NATIVE_REPOS_CSV '
    'BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF BPFREJIT_KEEP_ALL_WORKDIRS')
raise SystemExit(subprocess.run(['make', '-C', str(ROOT), '__runtime-vm-corpus',
    'PLATFORM=kvm', 'ARCH=x86', 'X86_RUNNER_RUNTIME_IMAGE=bpf-benchmark/kprog:current',
    'X86_RUNNER_RUNTIME_IMAGE_TAR=' + str(ROOT/'.cache/container-images/x86_64-runner-runtime.image.tar'),
    'RUNTIME_ENV_BASE_NAMES=' + names,
    'SAMPLES=' + str(args.samples), 'WORKLOAD_DURATION=' + str(args.duration)],
    env=environment).returncode)
