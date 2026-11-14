"""Stock-only proof replay with captured P and real source-object map resources.

Uses the existing registered-service capability and loader verify phase. It
cancels the submission after verification; it never installs or executes P.
"""
import argparse
import ctypes as c
import errno
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import threading

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'kprog'))
import trusted_service as service


def replay(args):
    spec = importlib.util.spec_from_file_location('retained_submit', ROOT / 'kprog/selftests/submit.py')
    submit = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(submit)
    loader = Path('/workspaces/.agent-state/kprog-ck/verified-loader')
    submit.tools_for_arch = lambda arch: (loader, args.linker)
    args.output.mkdir(parents=True, exist_ok=True)
    expected = json.loads(args.metadata.read_text())
    captured_context = json.loads(args.context.read_text())
    native = args.native.read_bytes()
    resources = submit.ObjectResources.__new__(submit.ObjectResources)
    descriptor = None
    endpoint = None
    request = None
    completed = False
    result = dict(scope='Stock-only retained proof replay; submission cancelled after verification.',
                  native=str(args.native), proof=str(args.proof), context=str(args.context))
    replies = []
    failures = []
    thread = None
    try:
        resources.__init__('x86', args.source, args.symbol, args.output, expected['maps'])
        envelope, fds, details = resources.load(args.source)
        # Resident applications can supply a type for sections libbpf leaves
        # unspecified. Reuse the captured request's type, as submit.py does.
        context = envelope['load_context']
        if context['prog_type'] == 0:
            context['prog_type'] = captured_context['prog_type']
            details['prog_type_source'] = 'retained kernel request'
        for field in sorted(service.CONTEXT | {'gpl_compatible'}):
            if context[field] != captured_context[field]:
                raise ValueError(f'Source context differs for {field}: {context[field]} != {captured_context[field]}')
        available = {item['name']: item for item in envelope['maps']}
        envelope['maps'] = [available[item['name']] for item in expected['maps']]
        (args.output / 'resources.json').write_text(json.dumps(details, indent=2) + '\n')
        buffers = [c.create_string_buffer(value) for value in (
            native, args.symbol.encode(), json.dumps(envelope).encode())]
        handles = (c.c_int32 * len(fds))(*fds)
        submitted = service.Request(version=1, arch=1, source_prog_id=0,
            native_size=len(native), entry_size=len(args.symbol), metadata_size=len(buffers[2].value),
            native_user=c.addressof(buffers[0]), entry_user=c.addressof(buffers[1]),
            metadata_user=c.addressof(buffers[2]))
        submission = submit.Submission(request=submitted, map_count=len(fds), map_fds_user=c.addressof(handles))
        endpoint = os.open('/sys/kernel/debug/bpf_x86_native_lab/specializer', os.O_RDWR | os.O_CLOEXEC)
        descriptor = os.open('/sys/kernel/debug/bpf_x86_native_lab/native_submit', os.O_RDWR | os.O_CLOEXEC)
        service.ioctl(descriptor, submit.SUBMIT, submission)
        request, (captured_native, entry, metadata_bytes) = service.next_request(endpoint)
        def wait():
            try:
                reply = service.Result()
                service.ioctl(descriptor, submit.WAIT, reply)
                replies.append(dict(request_id=reply.request_id, status=reply.status, prog_id=reply.prog_id))
            except Exception as error:
                failures.append(str(error))
        thread = threading.Thread(target=wait)
        thread.start()
        if captured_native != native or entry != args.symbol.encode():
            raise ValueError('Kernel request differs from retained P/entry')
        actual_envelope = json.loads(metadata_bytes)
        actual = service.kernel_facts(endpoint, request, actual_envelope)
        normalized = service.normalize(actual_envelope, actual)
        (args.output / 'generation.metadata.json').write_text(json.dumps(normalized, indent=2) + '\n')
        if normalized != expected:
            raise ValueError('New resource shapes/context differ from retained proof generation')
        command = [str(loader / 'trusted-native-loader'), 'verify', str(endpoint), str(request.request_id), '0',
                   str(args.native), args.symbol, str(args.native), str(args.proof),
                   'trusted_x86_x86_sim_xdp', str(args.linker)]
        command.extend(str(actual[field]) for field in (
            'expected_attach_type', 'prog_flags', 'attach_btf_id', 'attach_btf_obj_id', 'attach_prog_id', 'prog_ifindex'))
        command.extend(str(actual[field]) for field in ('prog_type', 'gpl_compatible', 'source_btf_id', 'source_func_type_id'))
        for item in actual_envelope['maps']:
            command.extend([item['name'], str(item['map_id']),
                            'null' if item['value_offset'] is None else str(item['value_offset'])])
        (args.output / 'command.json').write_text(json.dumps(command, indent=2) + '\n')
        with (args.output / 'verify.stdout').open('w') as stdout, (args.output / 'verify.stderr').open('w') as stderr:
            process = subprocess.run(command, pass_fds=(endpoint,), stdout=stdout, stderr=stderr)
        result.update(verify_exit=process.returncode, stock_accepted=process.returncode == 0,
                      context_and_map_shapes_equal=True)
    except Exception as error:
        result['error'] = str(error)
        raise
    finally:
        if request is not None:
            service.ioctl(endpoint, service.COMPLETE, service.Result(request_id=request.request_id, status=-errno.ECANCELED))
            completed = True
        if thread is not None:
            thread.join()
        result.update(submission_cancelled=completed, replies=replies, wait_errors=failures)
        (args.output / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
        if descriptor is not None:
            os.close(descriptor)
        if endpoint is not None:
            os.close(endpoint)
        resources.close()
    if failures:
        raise RuntimeError('Submission wait failed: ' + '; '.join(failures))
    print(json.dumps(result), flush=True)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__, fromfile_prefix_chars='@')
    for field in ('native', 'metadata', 'context', 'source', 'proof', 'linker', 'output'):
        parser.add_argument('--' + field, type=Path, required=True)
    parser.add_argument('--symbol', required=True)
    replay(parser.parse_args())
