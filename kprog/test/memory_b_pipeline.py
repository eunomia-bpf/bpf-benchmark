"""Observe the unchanged normal B continuation using anonymous stage files.

The owning long job keeps the sole canonical OTel inputs. These seekable fds
transport an observation through the same bounds/MIR/all-pairs/llc functions;
no second build directory or retained compiler output is created.
"""
import hashlib
import io
import os
from pathlib import Path
import re
from elftools.elf.elffile import ELFFile


class MemoryPipeline:
    def __init__(self):
        self.fds = []
        self.stages = {}

    def stage(self, suffix):
        if suffix not in self.stages:
            fd = os.memfd_create('kprog'+suffix, os.MFD_CLOEXEC)
            self.fds.append(fd)
            self.stages[suffix] = Path('/proc/self/fd')/str(fd)
        return self.stages[suffix]

    def with_suffix(self, suffix):
        return self.stage(suffix)

    def close(self):
        for fd in self.fds:
            os.close(fd)

    def compile(self, worker, frontend, bounds, run):
        initial = self.stage('.bounds-input.bc')
        initial.write_bytes(frontend)
        obj = self.stage('.o')
        stage = 0

        def invoke(command):
            nonlocal stage
            command = list(map(str, command))
            # Normal files infer these languages from .bc/.mir; proc fd paths
            # need explicit input language. Optimization flags stay unchanged.
            if command[0].endswith('/clang'):
                command[1:1] = ['-x', 'ir']
            elif command[0] == 'llc-18':
                command[1:1] = ['-x=mir']
            output = run(command, b'', 'backend-'+str(stage), tuple(self.fds))
            stage += 1
            return output

        worker.compile_simulator_from_frontend(str(worker.ROOT/'kprog/stock-path/bin/clang'),
            self, obj, invoke, frontend=initial, bounds_compiler=bounds)
        data = obj.read_bytes()
        elf = ELFFile(io.BytesIO(data))
        allocated = {s.name:dict(bytes=s.data_size,sha256=hashlib.sha256(s.data()).hexdigest())
                     for s in elf.iter_sections() if s['sh_flags'] & 2}
        result = dict(object_bytes=len(data),object_sha256=hashlib.sha256(data).hexdigest(),
                      allocated_sections=allocated,
                      code_bytes=sum(s.data_size for s in elf.iter_sections() if s['sh_flags'] & 4))
        mir = run(['llc-18','-O3','-march=bpf','-mcpu=v4','-bpf-stack-size=4096',
            '-x=mir','-start-before=prologepilog','-stop-after=prologepilog',
            self.stage('.packed.mir'),'-o','-'],b'','frame',tuple(self.fds)).decode()
        frames = {}
        for document in mir.split('\n---\n'):
            name = re.search(r'^name:\s+(\S+)', document, re.M)
            size = re.search(r'^  stackSize:\s+(\d+)', document, re.M)
            if name:
                if size is None:
                    raise ValueError('Post-PEI frame lacks stackSize: '+name[1])
                frames[name[1].strip('\'"')] = int(size[1])
        if not frames:
            raise ValueError('No post-PEI machine frame found')
        result['post_pei_stack_bytes'] = frames
        return result
