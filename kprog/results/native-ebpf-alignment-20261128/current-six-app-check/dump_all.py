#!/usr/bin/env python3
"""Write every loaded BPF program whose name (the kernel's 15-character name) matches NAME: its
verifier-rewritten instructions (xlated), its JITed machine code, and the address and length of each JITed
function, straight from bpf(BPF_OBJ_GET_INFO_BY_FD). Runs as root in the guest. Usage: dump-prog.py NAME OUTDIR"""
import ctypes, os, struct, sys
NAME, OUT = sys.argv[1].encode(), sys.argv[2]
libc = ctypes.CDLL(None, use_errno=True)
SYS_bpf = 321
BPF_PROG_GET_NEXT_ID, BPF_PROG_GET_FD_BY_ID, BPF_OBJ_GET_INFO_BY_FD = 11, 13, 15
INFO_LEN = 232

def bpf(cmd, attr):
    buf = ctypes.create_string_buffer(attr, 128)
    r = libc.syscall(SYS_bpf, cmd, buf, 128)
    return r, buf.raw

def info(fd, fill=None):
    b = ctypes.create_string_buffer(fill or b'\0' * INFO_LEN, INFO_LEN)
    attr = struct.pack('<IIQ', fd, INFO_LEN, ctypes.addressof(b))
    r, _ = bpf(BPF_OBJ_GET_INFO_BY_FD, attr)
    if r < 0:
        raise OSError(ctypes.get_errno(), 'info')
    return bytearray(b.raw)

os.makedirs(OUT, exist_ok=True)
pid = 0
while True:
    r, raw = bpf(BPF_PROG_GET_NEXT_ID, struct.pack('<III', pid, 0, 0))
    if r < 0:
        break
    pid = struct.unpack_from('<I', raw, 4)[0]
    r, _ = bpf(BPF_PROG_GET_FD_BY_ID, struct.pack('<III', pid, 0, 0))
    if r < 0:
        continue
    fd = r
    try:
        i = info(fd)
        name = bytes(i[64:80]).split(b'\0')[0]
        if NAME and name != NAME:
            continue
        jlen, xlen = struct.unpack_from('<II', i, 16)
        nks, nfl = struct.unpack_from('<II', i, 104)
        jb = ctypes.create_string_buffer(max(jlen, 1)); xb = ctypes.create_string_buffer(max(xlen, 1))
        kb = ctypes.create_string_buffer(max(nks, 1) * 8); fb = ctypes.create_string_buffer(max(nfl, 1) * 4)
        req = bytearray(INFO_LEN)
        struct.pack_into('<II', req, 16, jlen, xlen)
        struct.pack_into('<QQ', req, 24, ctypes.addressof(jb), ctypes.addressof(xb))
        struct.pack_into('<II', req, 104, nks, nfl)
        struct.pack_into('<QQ', req, 112, ctypes.addressof(kb), ctypes.addressof(fb))
        info(fd, bytes(req))
        base = os.path.join(OUT, 'prog-%d-%s' % (pid, name.decode()))
        open(base + '.jited.bin', 'wb').write(jb.raw[:jlen])
        open(base + '.xlated.bin', 'wb').write(xb.raw[:xlen])
        ks = struct.unpack_from('<%dQ' % nks, kb.raw) if nks else ()
        fl = struct.unpack_from('<%dI' % nfl, fb.raw) if nfl else ()
        with open(base + '.funcs.txt', 'w') as f:
            for a, l in zip(ks, fl):
                f.write('%x %d\n' % (a, l))
        print(base, jlen, xlen, nks)
    finally:
        os.close(fd)
