#!/usr/bin/env python3
"""Generate real TCP, fsync and queued block I/O for the complete BCC workload."""
import json,mmap,os,socket,subprocess,tempfile
from pathlib import Path

def tcp(family,host):
    connections=received=0
    with socket.socket(family,socket.SOCK_STREAM) as listener:
        listener.bind((host,0));listener.listen()
        for iteration in range(8):
            with socket.socket(family,socket.SOCK_STREAM) as client:
                client.connect(listener.getsockname())
                accepted,address=listener.accept()
                with accepted:
                    payload=b'bcc-workload-event\n';client.sendall(payload)
                    data=accepted.recv(len(payload));received+=len(data)
                    accepted.sendall(data)
                    returned=client.recv(len(data))
                    connections+=1
    return dict(family='IPv6' if family==socket.AF_INET6 else 'IPv4',connections=connections,received_bytes=received)

def main():
    records=[tcp(socket.AF_INET,'127.0.0.1'),tcp(socket.AF_INET6,'::1')]
    with tempfile.TemporaryDirectory(prefix='bcc-events-',dir=os.environ['TMPDIR']) as temporary:
        path=Path(temporary)/'io.bin'
        with path.open('wb') as out:
            out.write(b'bcc-fsync-event\n'*256);out.flush();os.fsync(out.fileno())
        records.append(dict(operation='file_fsync',calls=1,file_bytes=path.stat().st_size))
        print(json.dumps(dict(input_operations=records)),flush=True)
        command=['/usr/bin/fio','--name=bcc-block-events','--filename='+str(path),'--rw=write','--bs=4k','--size=16M','--ioengine=libaio','--direct=1','--iodepth=64','--iodepth_batch_submit=64','--iodepth_batch_complete_min=1','--iodepth_batch_complete_max=64','--numjobs=1','--end_fsync=1','--output-format=json']
        print(json.dumps(dict(block_io_command=command)),flush=True)
        subprocess.run(command,check=True)
if __name__=='__main__':main()
