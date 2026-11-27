"""Profile an archived real ARM B frontend using its original inputs and flags."""
import fcntl
import io
import json
import os
from pathlib import Path
import subprocess
import sys
import tarfile
import time
import traceback
from elftools.elf.elffile import ELFFile

ROOT = Path('/workspaces/repository')
HERE = Path(__file__).resolve().parent
LANE = Path('/workspaces/.agent-state/kprog-lanes/perf')
def now():
    return subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip()
token = subprocess.check_output(['date', '-u', '+%Y%m%dT%H%M%SZ'], text=True).strip()
mode = sys.argv[1] if len(sys.argv) > 1 else 'profile'
OUT = HERE/(mode+'-'+token)
OUT.mkdir()
RAW = Path('/workspaces/kprog-raw/perf/arm64-loadtime-20261127')/token
RAW.mkdir(parents=True)
record = dict(started_utc=now(), pid=os.getpid(), raw=str(RAW),
              revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
              scope='Original Cilium request10 frontend with diagnostic time trace/report; existing B flags and source paths retained. One additional compiler CPU18/AS48GiB, alongside active Tetragon. Main pipeline/source/binaries retained.')
def save():
    (OUT/'controller.json').write_text(json.dumps(record, indent=2)+'\n')
def run(command, name):
    start = time.monotonic()
    with (RAW/(name+'.stdout')).open('wb') as stdout, (RAW/(name+'.stderr')).open('wb') as stderr:
        child = subprocess.Popen(command, cwd=ROOT, stdin=subprocess.DEVNULL, stdout=stdout, stderr=stderr)
        _, status, usage = os.wait4(child.pid, 0)
        child.returncode = os.waitstatus_to_exitcode(status)
    row = dict(command=command, returncode=child.returncode, wall_seconds=time.monotonic()-start,
               max_rss_kib=usage.ru_maxrss, user_seconds=usage.ru_utime, system_seconds=usage.ru_stime)
    record.setdefault('commands', []).append(row)
    save()
    if child.returncode:
        raise RuntimeError(name+' failed; retained stderr at '+str(RAW/(name+'.stderr')))
try:
    save()
    source_run = ROOT/'kprog/results/arm64-checked-corpus-20261127'
    attribution = json.loads((source_run/'loadtime-attribution.json').read_text())
    specimen = max(attribution['per_request'], key=lambda row: row['host_frontend_wall_seconds'])
    record['mode'] = mode
    record['specimen'] = specimen
    raw_source = Path('/workspaces/kprog-raw/perf/arm64-checked-corpus-20261127/20261127T090610Z')
    jobs = [json.loads(line) for line in (raw_source/'broker/jobs.jsonl').read_text().splitlines()]
    with tarfile.open(raw_source/'cilium-agent/service.tar.gz') as outer:
        member = next(m for m in outer.getmembers() if m.name.endswith('/'+str(specimen['request'])+'.success.tar.gz'))
        with tarfile.open(fileobj=io.BytesIO(outer.extractfile(member).read())) as archive:
            def read(suffix):
                member = next(m for m in archive.getmembers() if m.name.endswith(suffix))
                return archive.extractfile(member).read()
            original_source = read('trusted_arm64.bpf.c')
            original_ir = read('trusted_arm64.bpf.frontend.bc')
            original_object = read('trusted_arm64.bpf.o')
    command = specimen['host_frontend_command']
    source = Path(next(arg for arg in command if arg.endswith('.bpf.c')))
    frontend = Path(command[command.index('-o')+1])
    source.parent.mkdir(parents=True, exist_ok=True)
    if source.exists() and source.read_bytes() != original_source:
        raise RuntimeError('canonical archived source path contains different data: '+str(source))
    source_bytes = original_source
    if mode == 'const-selectors':
        header = ROOT/'kprog/arm64/arm64_sim_local_bpf.h'
        lines = header.read_text().splitlines(keepends=True)
        macros = []
        index = 0
        while index < len(lines):
            block = lines[index]
            index += 1
            if not block.startswith('#define '):
                continue
            while block.rstrip().endswith('\\') and index < len(lines):
                block += lines[index]
                index += 1
            declaration = '__u64 __a64_l_reg = (REG);'
            if declaration in block:
                name = block.split('(', 1)[0].removeprefix('#define ')
                macros.append((name, block.replace(declaration, 'const '+declaration)))
        marker = ('#include '+json.dumps(str(header))).encode()
        overrides = '\n'.join('#undef '+name+'\n'+body for name, body in macros).encode()
        source_bytes = source_bytes.replace(marker, marker+b'\n'+overrides)
        record['constant_selector_macros'] = [name for name, _ in macros]
    source.write_bytes(source_bytes)
    record['restored_source'] = str(source)
    record['canonical_outputs_before'] = [str(p) for p in [frontend, frontend.with_name('trusted_arm64.bpf.o')] if p.exists()]
    # The retained original request archive owns the prior canonical products.
    trace = RAW/'frontend-trace.json'
    with Path('/workspaces/.agent-state/kprog-lanes/locks/timing').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_SH)
        if mode == 'early-promote':
            unoptimized = frontend.with_suffix('.unoptimized.bc')
            promoted = frontend.with_suffix('.promoted.bc')
            raw_command = [str(unoptimized) if arg == str(frontend) else arg for arg in command]
            run([*raw_command, '-Xclang', '-disable-llvm-passes', '-ftime-report'], 'frontend-raw')
            run(['/usr/lib/llvm-18/bin/opt', '-passes=mem2reg,simplifycfg', str(unoptimized), '-o', str(promoted), '-time-passes'], 'early-promote')
            command = [str(promoted) if arg == str(source) else arg for arg in command]
        run([*command, '-ftime-report', '-ftime-trace='+str(trace)], 'frontend')
        record['frontend_byte_equal_original'] = frontend.read_bytes() == original_ir
        object_command = next(job['command'] for job in jobs if str(frontend) in job['command'] and '-emit-llvm' not in job['command'])
        run(object_command, 'object')
        actual_object = Path(object_command[object_command.index('-o')+1]).read_bytes()
        def executable(data):
            return {section.name: section.data() for section in ELFFile(io.BytesIO(data)).iter_sections() if section['sh_flags'] & 4}
        record['B_executable_sections_equal_original'] = executable(actual_object) == executable(original_object)
        record['B_entire_object_equal_original'] = actual_object == original_object
    events = json.loads(trace.read_text())['traceEvents']
    totals = sorted((event for event in events if event.get('name', '').startswith('Total ')), key=lambda event: event.get('dur', 0), reverse=True)
    record['trace_totals'] = totals
    (OUT/'trace-totals.json').write_text(json.dumps(totals, indent=2)+'\n')
    record['controller_status'] = 0
except Exception:
    record.update(controller_status=1, exception=traceback.format_exc())
finally:
    record['ended_utc'] = now()
    save()
    if 'restored_source' in record:
        source_path = Path(record['restored_source'])
        produced = [source_path]
        for command in record.get('commands', []):
            arguments = command['command']
            if '-o' in arguments:
                path = Path(arguments[arguments.index('-o')+1])
                if path.exists() and path not in produced:
                    produced.append(path)
        with tarfile.open(RAW/'canonical-stages.tar', 'w') as archive:
            for path in produced:
                archive.add(path, arcname=path.name)
        record['canonical_stages'] = [dict(path=str(path), bytes=path.stat().st_size) for path in produced]
        save()
    try:
        with (OUT/'archive.log').open('wb') as log:
            commands = [['tar', '-C', str(RAW.parent), '-cf', '-', RAW.name],
                        ['zstd', '-T1', '-3', '-c'],
                        ['split', '-b', '48000000', '-', str(OUT/'evidence.tar.zst.part-')]]
            first = subprocess.Popen(commands[0], stdout=subprocess.PIPE, stderr=log)
            second = subprocess.Popen(commands[1], stdin=first.stdout, stdout=subprocess.PIPE, stderr=log)
            first.stdout.close()
            third = subprocess.Popen(commands[2], stdin=second.stdout, stderr=log)
            second.stdout.close()
            codes = [third.wait(), second.wait(), first.wait()][::-1]
        record['archive_commands'] = commands
        record['archive_returncodes'] = codes
        save()
        if any(codes):
            raise RuntimeError('profile archive failed')
        with Path('/workspaces/.agent-state/kprog-lanes/locks/git').open('a') as lock, (OUT/'publication.log').open('a') as log:
            fcntl.flock(lock, fcntl.LOCK_EX)
            path = str(OUT.relative_to(ROOT))
            for command in [['git', 'add', '-f', '--', path], ['git', 'commit', '--only', '-m', 'Record real ARM B frontend '+mode+' profile', '--', path], ['git', 'push']]:
                subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT, check=True)
    except Exception:
        record.update(publication_error=traceback.format_exc(), controller_status=1)
        save()
    with (LANE/'resume-msg.md').open('a') as output:
        output.write(f'\nARM load-time frontend profile finished status {record["controller_status"]}. Read {OUT}/controller.json, trace-totals.json, publication.log and raw frontend.stderr/trace. Original IR/B equivalence fields are observations. Continue common load-time repair now; Tetragon remains on original code.\n')
raise SystemExit(record['controller_status'])
