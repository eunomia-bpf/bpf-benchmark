"""Test app-loaded original/native programs with the same captured UDP packet."""
import json
import os
from pathlib import Path
import re
import socket
import struct
import subprocess
import sys

root = Path('/workspaces/repository')
bpftool = root / 'vendor/build/x86/bpftool/bin/bpftool'

def pairs(text):
    pending, result = {}, {}
    for line in text.splitlines():
        m = re.search(r'pid=(\d+) tid=(\d+).*native-loader jit-info (original|native) fd=\d+ id=(\d+)', line)
        if m:
            pid, tid, kind, ident = m.groups()
            if kind == 'original':
                pending[pid, tid] = int(ident)
            else:
                result[int(ident)] = pending.pop((pid, tid))
    return result

def objects(value):
    if isinstance(value, dict):
        yield value
        for child in value.values():
            yield from objects(child)
    elif isinstance(value, list):
        for child in value:
            yield from objects(child)

def main(out):
    layout = json.loads((Path(__file__).parent / 'layout.json').read_text())
    interface = 'lxcbench0'  # Frozen workload.py source endpoint host interface.
    ifindex = socket.if_nametoindex(interface)
    net = subprocess.check_output([str(bpftool), '-j', 'net', 'show', 'dev', interface], text=True)
    (out / 'packet-net.json').write_text(net)
    attached, = [r for r in objects(json.loads(net)) if r.get('devname') == interface
                  and 'ingress' in r.get('kind', '') and r.get('name', '').startswith('cil_from_cont')]
    native = attached['prog_id' if attached['kind'].startswith('tcx/') else 'id']
    paths = list((root / 'corpus/results').glob('x86_kvm_corpus_*/details/shim-logs/cilium__agent.post_rejit.log'))
    log = max(paths, key=lambda p: p.stat().st_mtime_ns)
    original = pairs(log.read_text())[native]
    (out / 'packet-programs.json').write_text(json.dumps(dict(original=original, native=native,
        interface=interface, ifindex=ifindex, shim_log=str(log)), indent=2) + '\n')
    with socket.socket(socket.AF_PACKET, socket.SOCK_RAW, socket.htons(0x0003)) as capture:
        capture.bind((interface, 0))
        capture.settimeout(15)
        while True:
            data, address = capture.recvfrom(65535)
            if address[2] != socket.PACKET_OUTGOING and len(data) >= 34 and data[12:14] == b'\x08\x00' and data[23] == 17:
                break
    packet = out / 'packet.bin'
    packet.write_bytes(data)
    context = bytearray(layout['size'])
    for name, value in [('ifindex', ifindex), ('ingress_ifindex', ifindex), ('wire_len', len(data))]:
        struct.pack_into('<I', context, layout[name], value)
    ctx = out / 'packet-context.bin'
    ctx.write_bytes(context)
    trace = Path('/sys/kernel/tracing')
    if not os.path.ismount(trace):
        subprocess.run(['mount', '-t', 'tracefs', 'tracefs', str(trace)], check=True)
    names, rows = [], []
    try:
        for helper in ['bpf_redirect', 'bpf_redirect_peer', 'bpf_redirect_neigh']:
            event = 'kprog_packet_' + helper
            with (trace / 'kprobe_events').open('a') as f:
                f.write(f'p:{event} {helper} target_ifindex=%di:u32\n')
            names.append(event)
            (trace / 'events/kprobes' / event / 'enable').write_text('1')
        for phase, ident in [('original', original), ('native', native)]:
            (trace / 'trace').write_text('')
            command = [str(bpftool), '-j', 'prog', 'run', 'id', str(ident),
                       'data_in', str(packet), 'data_out', str(out / (phase + '.packet-out.bin')),
                       'ctx_in', str(ctx), 'ctx_out', str(out / (phase + '.context-out.bin')), 'repeat', '1']
            wrapper = 'for name in "$1"/events/kprobes/kprog_packet_*/filter; do echo "common_pid == $$" > "$name"; done; shift; exec "$@"'
            done = subprocess.run(['sh', '-ec', wrapper, 'packet-test', str(trace), *command], capture_output=True, text=True)
            (out / (phase + '.test.stdout')).write_text(done.stdout)
            (out / (phase + '.test.stderr')).write_text(done.stderr)
            (out / (phase + '.redirect.trace')).write_text((trace / 'trace').read_text())
            row = dict(phase=phase, id=ident, command=command, returncode=done.returncode)
            if done.returncode == 0:
                row['test'] = json.loads(done.stdout)
                raw_ctx = (out / (phase + '.context-out.bin')).read_bytes()
                row['context'] = {name: struct.unpack_from('<I', raw_ctx, layout[name])[0]
                                  for name in ['ifindex', 'ingress_ifindex', 'wire_len']}
            rows.append(row)
            (out / 'packet-result.json').write_text(json.dumps(rows, indent=2) + '\n')
            done.check_returncode()
    finally:
        for event in names:
            (trace / 'events/kprobes' / event / 'enable').write_text('0')
            with (trace / 'kprobe_events').open('a') as f:
                f.write('-:' + event + '\n')

if __name__ == '__main__':
    main(Path(sys.argv[1]))
