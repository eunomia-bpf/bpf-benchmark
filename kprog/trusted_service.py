"""Kernel-backed trusted specializer, registered before application startup.

Only the kernel capability FD is a request endpoint. Applications submit native
bytes to the kernel; the service never accepts a producer proof or file path.
"""
from __future__ import annotations
import argparse
import ctypes as c
import errno
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile

from trusted_generation import declarations, u32
ROOT = Path(__file__).resolve().parent.parent

class Request(c.Structure):
    _fields_ = [(n, c.c_uint32) for n in ('version','arch','source_prog_id','flags')] + [
        ('request_id',c.c_uint64)] + [(n,c.c_uint32) for n in ('native_size','entry_size','metadata_size','reserved')] + [
        (n,c.c_uint64) for n in ('native_user','entry_user','metadata_user')]

class Result(c.Structure):
    _fields_ = [('request_id',c.c_uint64),('status',c.c_int32),('prog_id',c.c_uint32),('reserved',c.c_uint64)]

NEXT = (3 << 30) | (c.sizeof(Request) << 16) | (ord('N') << 8) | 0x71
COMPLETE = (1 << 30) | (c.sizeof(Result) << 16) | (ord('N') << 8) | 0x73
LIBC = c.CDLL(None, use_errno=True)
LIBC.ioctl.argtypes = [c.c_int, c.c_ulong, c.c_void_p]
LIBC.ioctl.restype = c.c_int


def ioctl(fd, operation, value):
    while LIBC.ioctl(fd, operation, c.byref(value)) < 0:
        error = c.get_errno()
        if error != errno.EINTR:
            raise OSError(error, os.strerror(error))


def next_request(fd):
    request = Request(version=1)
    buffers = None
    while True:
        try:
            ioctl(fd, NEXT, request)
        except OSError as error:
            if error.errno != errno.EMSGSIZE:
                raise
            # A canceled queue head can change sizes between the probe/copy.
            buffers = [c.create_string_buffer(n) for n in (request.native_size, request.entry_size, request.metadata_size)]
            request.native_user, request.entry_user, request.metadata_user = [c.addressof(b) for b in buffers]
        else:
            if buffers is None:
                raise RuntimeError('NEXT accepted missing native buffers')
            break
    if request.version != 1 or request.flags or request.reserved or not request.request_id:
        raise RuntimeError('invalid kernel request header')
    spans = [bytes(b.raw[:n]) for b,n in zip(buffers,(request.native_size,request.entry_size,request.metadata_size))]
    return request, spans


def strict_json(text):
    def pairs(items):
        out = {}
        for key, value in items:
            if key in out:
                raise ValueError('duplicate JSON field: '+key)
            out[key] = value
        return out
    return json.loads(text, object_pairs_hook=pairs)


class Context(c.Structure):
    _fields_ = [('request_id',c.c_uint64)] + [(n,c.c_uint32) for n in (
        'prog_type','expected_attach_type','prog_flags','prog_ifindex','attach_btf_id',
        'attach_btf_obj_id','attach_prog_id','gpl_compatible','source_btf_id','token_present')]

class Map(c.Structure):
    _fields_ = [('request_id',c.c_uint64)] + [(n,c.c_uint32) for n in (
        'map_id','depth','map_type','key_size','value_size','max_entries','map_flags',
        'btf_id','btf_key_type_id','btf_value_type_id','has_inner','reserved')]

GET_CONTEXT = (3 << 30) | (c.sizeof(Context) << 16) | (ord('N') << 8) | 0x75
GET_MAP = (3 << 30) | (c.sizeof(Map) << 16) | (ord('N') << 8) | 0x76


def kernel_facts(fd,request,envelope):
    context = Context(request_id=request.request_id)
    ioctl(fd,GET_CONTEXT,context)
    if context.request_id != request.request_id:
        raise RuntimeError('kernel context request identity mismatch')
    actual = {n:getattr(context,n) for n,_ in Context._fields_ if n != 'request_id'}
    actual.update(id=request.source_prog_id,maps=[])
    if type(envelope) is not dict or type(envelope.get('maps')) is not list:
        raise ValueError('typed map envelope missing')
    for item in envelope['maps']:
        if type(item) is not dict:
            raise ValueError('typed map identity missing')
        mid = u32(item['map_id'],'map_id')
        depth = 0; chain = []
        while True:
            m = Map(request_id=request.request_id,map_id=mid,depth=depth)
            ioctl(fd,GET_MAP,m)
            if m.request_id != request.request_id or m.map_id != mid or m.depth != depth or m.reserved or m.has_inner not in (0,1):
                raise RuntimeError('kernel map query identity/shape mismatch')
            node = {f:getattr(m,f) for f in SHAPE}
            chain.append(node)
            if not m.has_inner:break
            depth += 1
        for outer,inner in zip(chain,chain[1:]):outer['inner_map'] = inner
        chain[0]['id'] = mid
        actual['maps'].append(chain[0])
    return actual


CONTEXT = {'prog_type','expected_attach_type','prog_flags','attach_btf_id',
           'attach_btf_obj_id','attach_prog_id','prog_ifindex'}
SHAPE = {'map_type','key_size','value_size','max_entries','map_flags'}
SECTIONS = {1:'socket',2:'kprobe/trusted',3:'classifier',4:'action',
    5:'tracepoint/trusted/trusted',6:'xdp',7:'perf_event',8:'cgroup_skb/ingress',
    9:'cgroup/sock',10:'lwt_in',11:'lwt_out',12:'lwt_xmit',13:'sockops',
    14:'sk_skb/stream_parser',15:'cgroup/dev',16:'sk_msg',17:'raw_tracepoint/trusted',
    18:'cgroup/bind4',19:'lwt_seg6local',20:'lirc_mode2',21:'sk_reuseport',
    22:'flow_dissector',23:'cgroup/sysctl',24:'raw_tracepoint.w/trusted',
    25:'cgroup/getsockopt',26:'fentry/trusted',27:'struct_ops/trusted',
    28:'freplace/trusted',29:'lsm/trusted',30:'sk_lookup',31:'syscall',32:'netfilter'}


def normalize(envelope, actual):
    if type(envelope) is not dict or set(envelope) != {'version','load_context','maps'}:
        raise ValueError('request metadata requires only version/load_context/maps')
    if type(envelope['version']) is not int or envelope['version'] != 1:
        raise ValueError('request metadata version must be 1')
    context = envelope['load_context']
    if type(context) is not dict or set(context) != CONTEXT:
        raise ValueError('request requires exact typed load context')
    for field in CONTEXT:
        u32(context[field],field)
    for field in CONTEXT:
        if context[field] != actual[field]:
            raise ValueError('kernel source context mismatch: '+field)
    if type(envelope['maps']) is not list:
        raise ValueError('request maps must be a list')
    used = {m['id']:m for m in actual['maps']}
    maps = []; names = set()
    for item in envelope['maps']:
        if type(item) is not dict or set(item) != SHAPE | {'name','map_id','value_offset'}:
            raise ValueError('request map requires exact typed identity/shape/value_offset')
        name = item['name']
        if not isinstance(name,str) or re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*',name) is None or name in names:
            raise ValueError('invalid or duplicate map symbol')
        names.add(name)
        mid = u32(item['map_id'],'map_id')
        if mid not in used:
            raise ValueError('map is not used by the kernel-pinned source')
        source = used[mid]
        for field in SHAPE:
            if u32(item[field],field) != source[field]:
                raise ValueError('kernel map shape mismatch: '+name+'.'+field)
        offset = item['value_offset']
        if offset is not None and u32(offset,'value_offset') >= source['value_size']:
            raise ValueError('direct map value offset exceeds kernel map value')
        typed = dict(name=name,value_offset=offset,**{f:source[f] for f in SHAPE})
        if source['map_type'] in {12,13}:
            typed['inner_map'] = source['inner_map']
        maps.append(typed)
    section = SECTIONS[context['prog_type']]
    metadata = dict(version=1,prog_type=context['prog_type'],section=section,maps=maps)
    declarations(metadata)
    return metadata


def adapter(arch):
    isa = {1:'x86',2:'arm64'}[arch]
    spec = importlib.util.spec_from_file_location('kprog_'+isa+'_trusted_worker',
        ROOT / 'kprog' / isa / 'trusted_specializer.py')
    worker = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = worker
    spec.loader.exec_module(worker)
    return worker


def serve(args):
    import hashlib
    import tarfile
    import traceback
    from datetime import datetime,timezone
    root = args.state.resolve()
    root.mkdir(mode=0o700,parents=True,exist_ok=True)
    stat = root.stat()
    if stat.st_uid != os.geteuid() or stat.st_mode & 0o077:
        raise ValueError('service state must be private to its owner')
    worker = adapter(args.arch)
    fd = os.open(args.endpoint,os.O_RDWR | os.O_CLOEXEC)
    try:
        print(json.dumps(dict(ready=True,arch=args.arch,endpoint=str(args.endpoint))),flush=True)
        while True:
            request, (native,entry_bytes,meta_bytes) = next_request(fd)
            record = dict(request_id=request.request_id,source_prog_id=request.source_prog_id,
                native_sha256=hashlib.sha256(native).hexdigest(),started=datetime.now(timezone.utc).isoformat())
            with tempfile.TemporaryDirectory(prefix='request-',dir=root) as temporary:
                job = Path(temporary)
                (job/'kernel.native.o').write_bytes(native)
                (job/'kernel.entry').write_bytes(entry_bytes)
                (job/'kernel.metadata.json').write_bytes(meta_bytes)
                try:
                    if request.arch != args.arch:
                        raise ValueError('kernel request ISA differs from service')
                    entry = entry_bytes.decode('ascii')
                    envelope = strict_json(meta_bytes)
                    actual = kernel_facts(fd,request,envelope)
                    (job/'kernel.facts.json').write_text(json.dumps(actual,indent=2))
                    metadata = normalize(envelope,actual)
                    (job/'generation.metadata.json').write_text(json.dumps(metadata,indent=2))
                    isa={1:'x86',2:'arm64'}[request.arch]
                    source_paths=[Path(__file__),ROOT/'kprog/trusted_generation.py',Path(worker.__file__),
                        ROOT/'kprog'/isa/(isa+'_sim_local_bpf.h'),
                        ROOT/'kprog'/isa/'micro-prog/generate_micro_sim_proofs.py',
                        ROOT/'kprog/libnativeloader/src/native_loader.cpp',
                        ROOT/'kinsn/module/include/native_lab_trusted_wire.h',args.native_link,args.loader]
                    identities={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in source_paths}
                    (job/'source-identities.json').write_text(json.dumps(identities,indent=2))
                    artifacts = worker.specialize(native,entry,metadata,job/'generated',args.native_link)
                    context = envelope['load_context']
                    argv = [args.loader,'load',fd,request.request_id,request.source_prog_id,
                        artifacts['native_object'],entry,artifacts['native_proof_object'],
                        artifacts['simulator_object'],artifacts['simulator_program'],args.native_link]
                    argv.extend(context[f] for f in ('expected_attach_type','prog_flags','attach_btf_id',
                        'attach_btf_obj_id','attach_prog_id','prog_ifindex'))
                    for item in envelope['maps']:
                        argv.extend([item['name'],item['map_id'],'null' if item['value_offset'] is None else item['value_offset']])
                    result = subprocess.run([str(x) for x in argv],pass_fds=(fd,),text=True,capture_output=True)
                    (job/'load.stdout').write_text(result.stdout)
                    (job/'load.stderr').write_text(result.stderr)
                    result.check_returncode()
                    completion = strict_json(result.stdout)
                    if completion['request_id'] != request.request_id or completion['status'] or not completion['prog_id']:
                        raise RuntimeError('loader returned an invalid completion')
                    record.update(completion)
                except Exception as error:
                    record.update(status=-errno.EINVAL if isinstance(error,(ValueError,KeyError,UnicodeError)) else -errno.EIO,
                                  error=str(error),traceback=traceback.format_exc())
                    (job/'error.json').write_text(json.dumps(record,indent=2))
                    archive = root / (str(request.request_id)+'.failure.tar.gz')
                    with tarfile.open(archive,'x:gz') as output:
                        output.add(job,arcname='request')
                    record['failure_archive'] = str(archive)
                    ioctl(fd,COMPLETE,Result(request_id=request.request_id,status=record['status']))
                if record['status'] == 0:
                    archive = root / (str(request.request_id)+'.success.tar.gz')
                    with tarfile.open(archive,'x:gz') as output:
                        output.add(job,arcname='request')
                    record['artifact_archive'] = str(archive)
                record['finished'] = datetime.now(timezone.utc).isoformat()
                with (root/'requests.jsonl').open('a') as log:
                    log.write(json.dumps(record)+'\n')
                print(json.dumps(record),flush=True)
    finally:
        os.close(fd)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--arch',type=int,choices=(1,2),required=True)
    parser.add_argument('--endpoint',type=Path,required=True)
    parser.add_argument('--state',type=Path,required=True)
    parser.add_argument('--native-link',type=Path,required=True)
    parser.add_argument('--loader',type=Path,required=True)
    serve(parser.parse_args())

if __name__ == '__main__':
    main()
