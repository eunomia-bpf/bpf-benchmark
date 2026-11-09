"""Use upstream BPF frontends with the recorded application source changes."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
from elftools.elf.elffile import ELFFile

ROOT = Path('/workspaces/repository')
HERE = Path(__file__).resolve().parent
STATE = Path('/var/tmp/kprog-tmp/C/audit-recovery/paired-source')
UPSTREAM = ROOT / 'vendor/repos/tetragon/bpf'
EDITED_HEADERS = [
    'include/compiler.h', 'lib/bpf_d_path.h', 'lib/process.h',
    'process/data_event.h', 'process/bpf_process_event.h',
]
EDITED_FUNCTIONS = {name.encode() for name in [
    'get_namespaces', 'read_exe', 'prepend_path', 'data_event_bytes',
    'data_event_str', '__do_str',
]}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def main():
    STATE.mkdir(parents=True, exist_ok=True)
    objects = STATE / 'tetragon'
    objects.mkdir(exist_ok=True)
    original = ROOT / 'vendor/build/x86/tetragon'
    rows = []
    for source in sorted(original.glob('*.o')):
        with source.open('rb') as stream:
            elf = ELFFile(stream)
            section = elf.get_section_by_name('.debug_str')
            names = set(section.data().split(b'\0')) if section else set()
        references = sorted(name.decode() for name in names & EDITED_FUNCTIONS)
        rows.append(dict(object=source.name, original_sha256=sha(source),
                         edited_function_references=references))
        if not references:
            shutil.copy2(source, objects / source.name)
    overlay = dict(version=0, **{'use-external-names': False},
        roots=[dict(type='file', name=str(UPSTREAM / name),
                    **{'external-contents': str(ROOT / 'vendor/bpf/tetragon/bpf' / name)})
               for name in EDITED_HEADERS])
    write(STATE / 'overlay.json', overlay)
    selected = [str(objects / row['object']) for row in rows
                if row['edited_function_references']]
    command = ['make', '-C', str(UPSTREAM), '-f', str(HERE / 'tetragon.mk'),
               '-j2', *selected, 'OBJSDIR=' + str(objects) + '/',
               'DEPSDIR=' + str(STATE / 'deps') + '/',
               'OBJS=' + ' '.join(selected),
               'CLANG=/usr/lib/llvm-18/bin/clang -ivfsoverlay ' + str(STATE / 'overlay.json')]
    write(STATE / 'tetragon-command.json', command)
    write(STATE / 'selection.json', rows)
    with (STATE / 'tetragon-build.log').open('w') as output:
        run = subprocess.run(command, stdout=output, stderr=subprocess.STDOUT)
    (STATE / 'tetragon-build.exit').write_text(str(run.returncode) + '\n')
    run.check_returncode()
    for row in rows:
        row['selected_sha256'] = sha(objects / row['object'])
        row['frontend'] = ('upstream with edited headers'
                           if row['edited_function_references'] else 'upstream object')
    tracee = STATE / 'tracee'
    tracee.mkdir(exist_ok=True)
    # Only the main Tracee unit includes the recorded buffer/clamp changes.
    main_bpf = Path('/var/tmp/kprog-tmp/C/tracee-current-paired-source/dist/tracee.bpf.o')
    shutil.copy2(main_bpf, tracee / main_bpf.name)
    summary = dict(
        tetragon_objects=rows,
        paired_tetragon_units=len(selected),
        upstream_tetragon_units=len(rows) - len(selected),
        upstream_source_head=subprocess.check_output(
            ['git', '-C', str(UPSTREAM), 'rev-parse', 'HEAD'], text=True).strip(),
        edited_headers={name: sha(ROOT / 'vendor/bpf/tetragon/bpf' / name)
                        for name in EDITED_HEADERS},
        tracee_main_bpf=dict(source=str(main_bpf), sha256=sha(main_bpf)),
        tracee_support='upstream image lsm_support objects and userspace binary',
        workload_revision='9f3855f6f', added_runtime_checks=0)
    write(STATE / 'complete.json', summary)


if __name__ == '__main__':
    main()
