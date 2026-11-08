"""Exercise trusted service lifecycle, ELF decoding and map declarations."""
import copy
import ctypes
import json
from pathlib import Path
import subprocess
import sys
import unittest
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'kprog'))
import trusted_service as service
from trusted_generation import declarations, validate_native

class TrustedApplicationBootstrap(unittest.TestCase):
    def exercise(self, ready, status):
        import os
        import tarfile
        import tempfile
        from types import SimpleNamespace
        from unittest.mock import patch
        with tempfile.TemporaryDirectory() as directory:
            root=Path(directory)
            marker=root/'application-ran'
            args=SimpleNamespace(arch=1,endpoint=root/'endpoint',state=root/'private',
                module=None,native_link=root/'link',loader=root/'loader',
                results=root/'evidence.tar.gz',run=[sys.executable,'-c',
                    'from pathlib import Path; import os; '
                    'assert os.environ["BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF"]=="1"; '
                    'Path('+repr(str(marker))+').write_text("ran"); raise SystemExit('+str(status)+')'])
            real_popen=subprocess.Popen
            def worker(command, **kwargs):
                if command[1]==str(Path(service.__file__).resolve()):
                    # This fixture supplies no proof and never models a kernel
                    # acceptance. It checks supervisor lifecycle only.
                    state=Path(command[command.index('--state')+1])
                    code='''import fcntl, os, signal
from pathlib import Path
state=Path(STATE)
state.mkdir(parents=True)
with (state/'request.lock').open('w') as lock:
    fcntl.flock(lock,fcntl.LOCK_EX)
    print(READY,flush=True)
    # Compression represents terminal archival work after kernel completion.
    import gzip
    payload=gzip.compress(bytes(range(256))*16384)
    (state/'terminal.json').write_text('{"status":0}')
    fcntl.flock(lock,fcntl.LOCK_UN)
    signal.pause()
'''.replace('STATE',repr(str(state))).replace('READY',repr(json.dumps(dict(ready=ready))))
                    command=[sys.executable,'-c',code]
                return real_popen(command,**kwargs)
            with patch.object(service.subprocess,'Popen',side_effect=worker):
                if ready:
                    self.assertEqual(service.run_application(args),status)
                    self.assertTrue(marker.exists())
                else:
                    with self.assertRaisesRegex(RuntimeError,'did not register'):
                        service.run_application(args)
                    self.assertFalse(marker.exists())
            with tarfile.open(args.results) as archive:
                receipt=json.loads(archive.extractfile('service/summary.json').read())
                self.assertIsNotNone(receipt['service_returncode'])
                self.assertEqual(receipt.get('returncode'),status if ready else None)
                self.assertIn('service/service.log',archive.getnames())
                if ready:
                    self.assertEqual(json.loads(archive.extractfile('service/requests/terminal.json').read()),dict(status=0))
            self.assertEqual(list(args.state.iterdir()),[])
    def test_nonzero_application_status_and_evidence_survive_teardown(self):
        self.exercise(True,7)
    def test_unregistered_service_never_starts_application(self):
        self.exercise(False,0)


class TrustedMetadata(unittest.TestCase):
    def setUp(self):
        self.actual = dict(id=4,prog_type=2,prog_ifindex=0,attach_btf_id=0,attach_btf_obj_id=0,
            maps=[dict(id=11,name='stats',map_type=2,key_size=4,value_size=16,max_entries=8,map_flags=0)])
        self.actual.update(expected_attach_type=0,prog_flags=0,attach_prog_id=0)
        self.envelope = dict(version=1,load_context=dict(prog_type=2,expected_attach_type=0,prog_flags=0,
            attach_btf_id=0,attach_btf_obj_id=0,attach_prog_id=0,prog_ifindex=0),
            maps=[dict(name='stats',map_id=11,map_type=2,key_size=4,value_size=16,max_entries=8,map_flags=0,value_offset=None)])
    def normalize(self):
        return service.normalize(self.envelope,self.actual)
    def test_explicit_zero_direct_value_is_distinct_from_handle(self):
        self.envelope['maps'][0]['value_offset']=0
        self.assertEqual(self.normalize()['maps'][0]['value_size'],16)
        self.assertEqual(self.normalize()['maps'][0]['value_offset'],0)
        self.envelope['maps'][0]['value_offset']=None
        self.assertIsNone(self.normalize()['maps'][0]['value_offset'])
    def test_inner_map_requires_exact_typed_template(self):
        typed=self.normalize();typed['maps'][0]['map_type']=12
        inner=dict(map_type=1,key_size=4,value_size=8,max_entries=32,map_flags=0)
        typed['maps'][0]['inner_map']=inner
        source,names=declarations(typed)
        self.assertIn('__array(values, struct __trusted_inner_0)',source)
        self.assertEqual(names,{'stats'})
    def test_dotted_elf_symbol_preserves_identity_and_avoids_c_collision(self):
        self.envelope['maps'][0]['name']='sys_exit.zero'
        typed=self.normalize()
        typed['maps'].append(dict(typed['maps'][0],name='__trusted_map_decl_0'))
        source,names=declarations(typed)
        self.assertIn('sys_exit.zero',names)
        self.assertIn('__trusted_map_decl_0_ __asm__("sys_exit.zero")',source)
        self.envelope['maps'][0]['name']='bad;code'
        with self.assertRaises(ValueError):self.normalize()

    def test_native_machine_and_entry_checked_before_generation(self):
        with self.assertRaises(ValueError):validate_native(b'', 'entry','EM_X86_64')
        with self.assertRaises(ValueError):validate_native(b'not ELF','entry;code','EM_X86_64')
    def test_real_relocatable_and_shared_entries_use_section_relative_bounds(self):
        import io
        import struct
        import tempfile
        from elftools.elf.elffile import ELFFile
        with tempfile.TemporaryDirectory() as temporary:
            for suffix,flags in [('o',['-c']),('so',['-shared','-nostdlib'])]:
                output=Path(temporary)/('trusted.'+suffix)
                subprocess.run(['clang','-target','x86_64-linux-gnu','-fPIC',
                    *flags,str(ROOT/'kprog/test/trusted_native.c'),'-o',str(output)],check=True)
                native=output.read_bytes()
                validate_native(native,'trusted_entry','EM_X86_64')
                with self.assertRaises(ValueError):
                    validate_native(native,'trusted_entry','EM_AARCH64')
                with self.assertRaises(ValueError):
                    validate_native(native,'no_such_entry','EM_X86_64')
                executable=bytearray(native);struct.pack_into('<H',executable,16,2)
                with self.assertRaises(ValueError):
                    validate_native(bytes(executable),'trusted_entry','EM_X86_64')
                elf=ELFFile(io.BytesIO(native));table=elf.get_section_by_name('.symtab')
                index,symbol=next((i,s) for i,s in enumerate(table.iter_symbols()) if s.name=='trusted_entry')
                section=elf.get_section(symbol['st_shndx'])
                bad_addresses=[section['sh_addr']+section['sh_size']]
                if section['sh_addr']:bad_addresses.append(section['sh_addr']-1)
                for address in bad_addresses:
                    broken=bytearray(native)
                    struct.pack_into('<Q',broken,table['sh_offset']+index*table['sh_entsize']+8,address)
                    with self.assertRaises(ValueError):
                        validate_native(bytes(broken),'trusted_entry','EM_X86_64')

    def test_python_transport_matches_compiled_kernel_header(self):
        values=list(map(int,subprocess.check_output([ROOT/'kprog/libnativeloader/build/trusted-native-loader','abi'],text=True).split()))
        expected=[ctypes.sizeof(service.Request),ctypes.sizeof(service.Result)]
        expected += [getattr(service.Request,n).offset for n in ('request_id','native_size','native_user','entry_user','metadata_user')]
        expected += [getattr(service.Result,n).offset for n in ('status','prog_id','reserved')]
        expected += [service.NEXT,service.COMPLETE]
        expected += [ctypes.sizeof(service.Context),ctypes.sizeof(service.Map),service.Context.prog_flags.offset,service.Map.map_type.offset,service.GET_CONTEXT,service.GET_MAP]
        self.assertEqual(values,expected)

class Arm64PrivateLayout(unittest.TestCase):
    def test_memcpy_payload_geometry_tracks_private_destinations(self):
        sys.path.insert(0,str(ROOT/'kprog/arm64/micro-prog'))
        import generate_micro_sim_proofs as arm
        for destination,want in [('external',[-8]),('private',[-16,-8]),('unknown',None),('dynamic-private',None)]:
            with self.subTest(destination=destination):
                body=[('sub',('sp','sp','#16')),('str',('x30','[sp, #8]'))]
                if destination=='private':body.append(('mov',('x0','sp')))
                if destination=='unknown':body.append(('mov',('x0','x3')))
                if destination=='dynamic-private':body += [('mov',('x0','sp')),('add',('x0','x0','x3'))]
                body += [('add',('x1','sp','#8' if destination=='private' else '#0')),
                         ('mov',('x2','#8' if destination=='private' else '#16')),
                         ('bl',('0 <memcpy>',)),('ldr',('x30','[sp, #8]')),
                         ('add',('sp','sp','#16')),('ret',())]
                insns=[arm.NativeInsn(i*4,op,args,op+' '+', '.join(args),
                                     'memcpy' if op=='bl' else None) for i,(op,args) in enumerate(body)]
                self.assertEqual(arm.collect_layout(insns,{},arm),(-16,0,want))

if __name__=='__main__':unittest.main()
