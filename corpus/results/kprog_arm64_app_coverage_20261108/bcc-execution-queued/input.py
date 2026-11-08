#!/usr/bin/env python3
"""Generate real TCP, fsync and queued block I/O for the complete BCC workload."""
import ctypes,json,mmap,os,socket,subprocess,tempfile
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

def aio_sync(fd):
    class IOCB(ctypes.Structure):
        _fields_=[('data',ctypes.c_uint64),('key',ctypes.c_uint32),('rw_flags',ctypes.c_uint32),('opcode',ctypes.c_uint16),('priority',ctypes.c_int16),('fd',ctypes.c_uint32),('buf',ctypes.c_uint64),('nbytes',ctypes.c_uint64),('offset',ctypes.c_int64),('reserved',ctypes.c_uint64),('flags',ctypes.c_uint32),('resfd',ctypes.c_uint32)]
    class Event(ctypes.Structure):
        _fields_=[('data',ctypes.c_uint64),('object',ctypes.c_uint64),('result',ctypes.c_int64),('result2',ctypes.c_int64)]
    lib=ctypes.CDLL('libaio.so.1t64');context=ctypes.c_uint64();records=[]
    result=lib.io_setup(8,ctypes.byref(context))
    if result<0:raise OSError(-result,'io_setup')
    try:
        for opcode in [2,3]:
            request=IOCB(opcode=opcode,fd=fd);array=(ctypes.POINTER(IOCB)*1)(ctypes.pointer(request));event=Event()
            result=lib.io_submit(context,1,array)
            if result!=1:raise OSError(-result,'io_submit fsync')
            result=lib.io_getevents(context,1,1,ctypes.byref(event),None)
            if result!=1 or event.result:raise OSError(-event.result,'io_getevents fsync')
            records.append(dict(operation='aio_fsync' if opcode==2 else 'aio_fdatasync',completion=event.result))
    finally:lib.io_destroy(context)
    return records

def main():
    records=[dict(queue_scheduler=Path('/sys/block/vda/queue/scheduler').read_text().strip(),queue_requests=Path('/sys/block/vda/queue/nr_requests').read_text().strip()),tcp(socket.AF_INET,'127.0.0.1'),tcp(socket.AF_INET6,'::1')]
    with tempfile.TemporaryDirectory(prefix='bcc-events-',dir=os.environ['TMPDIR']) as temporary:
        path=Path(temporary)/'io.bin'
        with path.open('wb') as out:
            out.write(b'bcc-fsync-event\n'*256);out.flush();os.fsync(out.fileno());records.extend(aio_sync(out.fileno()))
        records.append(dict(operation='file_fsync',calls=1,file_bytes=path.stat().st_size))
        print(json.dumps(dict(input_operations=records)),flush=True)
        command=['/usr/bin/fio','--name=bcc-block-events','--filename='+str(path),'--rw=write','--bs=512','--size=4M','--offset_increment=4M','--ioengine=libaio','--direct=1','--iodepth=128','--iodepth_batch_submit=128','--iodepth_batch_complete_min=1','--iodepth_batch_complete_max=128','--numjobs=4','--end_fsync=1','--output-format=json']
        print(json.dumps(dict(block_io_command=command)),flush=True)
        subprocess.run(command,check=True)
if __name__=='__main__':main()
