#!/usr/bin/env python3
"""Read live guest BPF JIT/source-line metadata without changing any program."""
import ctypes as c
import ctypes.util
import hashlib
import json
import os
from pathlib import Path
import struct
import sys
import time

U32, U64 = c.c_uint32, c.c_uint64
class Info(c.Structure):
    # Stable Linux bpf_prog_info prefix; bitfield storage is one u32.
    _fields_ = [('type',U32),('id',U32),('tag',c.c_ubyte*8),
        ('jited_prog_len',U32),('xlated_prog_len',U32),('jited_prog_insns',U64),
        ('xlated_prog_insns',U64),('load_time',U64),('created_by_uid',U32),
        ('nr_map_ids',U32),('map_ids',U64),('name',c.c_char*16),('ifindex',U32),
        ('gpl_compatible',U32),('netns_dev',U64),('netns_ino',U64),
        ('nr_jited_ksyms',U32),('nr_jited_func_lens',U32),('jited_ksyms',U64),
        ('jited_func_lens',U64),('btf_id',U32),('func_info_rec_size',U32),
        ('func_info',U64),('nr_func_info',U32),('nr_line_info',U32),
        ('line_info',U64),('jited_line_info',U64),('nr_jited_line_info',U32),
        ('line_info_rec_size',U32),('jited_line_info_rec_size',U32),
        ('nr_prog_tags',U32),('prog_tags',U64),('run_time_ns',U64),('run_cnt',U64),
        ('recursion_misses',U64),('verified_insns',U32),('attach_btf_obj_id',U32),
        ('attach_btf_id',U32)]


def capture(output):
    lib = c.CDLL(ctypes.util.find_library('bpf'), use_errno=True)
    lib.bpf_prog_get_fd_by_id.argtypes = [U32]
    lib.bpf_prog_get_next_id.argtypes = [U32,c.POINTER(U32)]
    lib.bpf_obj_get_info_by_fd.argtypes = [c.c_int,c.c_void_p,c.POINTER(U32)]
    lib.btf__load_from_kernel_by_id.argtypes = [U32]
    lib.btf__load_from_kernel_by_id.restype = c.c_void_p
    lib.libbpf_get_error.argtypes = [c.c_void_p]
    lib.libbpf_get_error.restype = c.c_long
    lib.btf__name_by_offset.argtypes = [c.c_void_p,U32]
    lib.btf__name_by_offset.restype = c.c_char_p
    lib.btf__free.argtypes = [c.c_void_p]
    report = dict(start_monotonic_ns=time.monotonic_ns(),kernel_release=os.uname().release,
        boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        collector_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),programs=[],errors=[])
    folder = output.with_suffix('.d')
    folder.mkdir(parents=True,exist_ok=True)
    ident = U32()
    while lib.bpf_prog_get_next_id(ident,c.byref(ident)) == 0:
        fd = lib.bpf_prog_get_fd_by_id(ident)
        if fd < 0:
            report['errors'].append(dict(id=ident.value,operation='open',errno=c.get_errno()))
            continue
        btf = None
        try:
            info = Info()
            def query():
                size = U32(c.sizeof(info))
                if lib.bpf_obj_get_info_by_fd(fd,c.byref(info),c.byref(size)):
                    raise OSError(c.get_errno(),'BPF_OBJ_GET_INFO_BY_FD')
            query()
            row = dict(id=info.id,name=info.name.decode(),tag=bytes(info.tag).hex(),
                btf_id=info.btf_id,jited_bytes=info.jited_prog_len,
                line_count=info.nr_line_info,jited_line_count=info.nr_jited_line_info)
            report['programs'].append(row)
            buffers = {}
            for pointer,count,unit in [('line_info',info.nr_line_info,info.line_info_rec_size),
                    ('jited_line_info',info.nr_jited_line_info,info.jited_line_info_rec_size),
                    ('jited_ksyms',info.nr_jited_ksyms,8),('jited_func_lens',info.nr_jited_func_lens,4),
                    ('jited_prog_insns',info.jited_prog_len,1)]:
                buffers[pointer] = c.create_string_buffer(count*unit)
                setattr(info,pointer,c.addressof(buffers[pointer]))
            # The sizing call returns counts even for arrays not requested.
            # Leaving those counts nonzero with NULL pointers requests a copy
            # to NULL and makes the real kernel return EFAULT.
            info.nr_map_ids = info.nr_func_info = info.nr_prog_tags = 0
            info.xlated_prog_len = 0
            query()
            raw = buffers['jited_prog_insns'].raw[:info.jited_prog_len]
            path = folder/f'prog-{info.id}.bin'
            path.write_bytes(raw)
            row.update(binary=str(path.relative_to(output.parent)),sha256=hashlib.sha256(raw).hexdigest())
            row['functions'] = [dict(address=a[0],length=b[0]) for a,b in zip(
                struct.iter_unpack('<Q',buffers['jited_ksyms'].raw),
                struct.iter_unpack('<I',buffers['jited_func_lens'].raw))]
            if not info.nr_line_info or info.nr_line_info != info.nr_jited_line_info:
                row['source_status'] = 'Missing or unequal line arrays; no pairing inferred'
                continue
            if info.line_info_rec_size < 16 or info.jited_line_info_rec_size < 8:
                row['source_status'] = 'Unsupported record size; no pairing inferred'
                continue
            btf = lib.btf__load_from_kernel_by_id(info.btf_id)
            if not btf or lib.libbpf_get_error(btf):
                btf = None
                raise OSError(c.get_errno(),'load source BTF')
            def name(offset):
                value = lib.btf__name_by_offset(btf,offset)
                return value.decode(errors='replace') if value else None
            row['lines'] = []
            for i in range(info.nr_line_info):
                off,file,text,pos = struct.unpack_from('<IIII',buffers['line_info'],i*info.line_info_rec_size)
                address = struct.unpack_from('<Q',buffers['jited_line_info'],i*info.jited_line_info_rec_size)[0]
                row['lines'].append(dict(address=address,raw_insn_off=off,file=name(file),
                    text=name(text),line=pos>>10,column=pos&1023))
        except (OSError,ValueError,struct.error) as error:
            report['errors'].append(dict(id=ident.value,error=str(error)))
        finally:
            if btf: lib.btf__free(btf)
            os.close(fd)
    report['enumeration_errno'] = c.get_errno()
    report['end_monotonic_ns'] = time.monotonic_ns()
    output.write_text(json.dumps(report,indent=2)+'\n')
    return report

if __name__ == '__main__':
    capture(Path(sys.argv[1]))
