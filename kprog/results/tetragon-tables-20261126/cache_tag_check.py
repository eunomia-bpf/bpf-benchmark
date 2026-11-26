"""Use the existing shared-C alias/replant oracle on both cache clear recipes."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/table-cache')
BUILD.mkdir(parents=True, exist_ok=True)
commands, observations = [], {}

def run(command):
    result = subprocess.run(list(map(str, command)), text=True, capture_output=True)
    commands.append(dict(command=list(map(str, command)), returncode=result.returncode,
                         stdout=result.stdout, stderr=result.stderr))
    (HERE / 'cache-range-check-commands.json').write_text(json.dumps(commands, indent=2) + '\n')
    result.check_returncode()
    return result.stdout

for mode, words in [('full', range(8)), ('sparse', [1, 5])]:
    for control in [False, True]:
        flags = ['clang-18', '-O3', '-fsanitize=undefined', '-fno-sanitize-recover=all',
            '-fno-sanitize-link-runtime', '-mno-red-zone', '-I' + str(ROOT / 'vendor/libbpf/src'),
            '-I' + str(ROOT / 'vendor/libbpf/include/uapi'),
            '-DX86_SIM_STACK_VALUE_WORDS(M)=' + ' '.join(f'M({i})' for i in words)]
        if control:
            flags += ['-DX86_SIM_USE_STATE_STRUCT', '-DX86_SIM_STACK_BYTES=64U',
                      '-include', ROOT / 'kprog/x86/x86_sim_local_bpf.h',
                      '-include', HERE / 'cache_tag_only.h']
        run([*flags, ROOT / 'kprog/results/sparse-stack-cache-20261119/oracle.c',
             '-lubsan', '-o', BUILD / 'oracle'])
        observations[mode + ('-range-tag-only' if control else '-normal')] = json.loads(run([BUILD / 'oracle']))
    if observations[mode + '-normal'] != observations[mode + '-range-tag-only']:
        raise AssertionError(observations)
(HERE / 'cache-range-check.json').write_text(json.dumps(dict(observations=observations,
    scope='Existing shared-C oracle: all provenance tags, sparse/full words, direct/aliased writes, partial writes, release/replant. No stock/app acceptance or complete formal-equivalence claim.'), indent=2) + '\n')
print(json.dumps(observations))
