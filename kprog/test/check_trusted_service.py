"""Reject producer metadata that could redirect or weaken a generated proof."""
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
                    command=[sys.executable,'-c',
                        'import time; print('+repr(json.dumps(dict(ready=ready)))+',flush=True); time.sleep(60)']
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
    def test_shape_and_identity_spoof_rejected(self):
        for field,value in [('map_id',12),('value_size',8),('map_flags',128),('max_entries',9)]:
            with self.subTest(field=field):
                before=self.envelope['maps'][0][field];self.envelope['maps'][0][field]=value
                with self.assertRaises(ValueError):self.normalize()
                self.envelope['maps'][0][field]=before
    def test_explicit_zero_direct_value_is_distinct_from_handle(self):
        self.envelope['maps'][0]['value_offset']=0
        self.assertEqual(self.normalize()['maps'][0]['value_size'],16)
        self.assertEqual(self.normalize()['maps'][0]['value_offset'],0)
        self.envelope['maps'][0]['value_offset']=None
        self.assertIsNone(self.normalize()['maps'][0]['value_offset'])
        self.envelope['maps'][0]['value_offset']=16
        with self.assertRaises(ValueError):self.normalize()
    def test_bool_cannot_replace_u32(self):
        self.envelope['maps'][0]['map_flags']=False
        with self.assertRaises(ValueError):self.normalize()
    def test_context_and_proof_fields_rejected(self):
        self.envelope['load_context']['prog_type']=6
        with self.assertRaises(ValueError):self.normalize()
        self.envelope['load_context']['prog_type']=2
        for name in ('simulator_object','proof_insns','source','compiler_flags'):
            self.envelope[name]='producer controlled'
            with self.assertRaises(ValueError):self.normalize()
            del self.envelope[name]
    def test_duplicate_symbol_and_json_fields_rejected(self):
        self.envelope['maps'].append(copy.deepcopy(self.envelope['maps'][0]))
        with self.assertRaises(ValueError):self.normalize()
        with self.assertRaises(ValueError):service.strict_json('{"map_id":11,"map_id":12}')
    def test_inner_map_requires_exact_typed_template(self):
        typed=self.normalize();typed['maps'][0]['map_type']=12
        with self.assertRaises(ValueError):declarations(typed)
        inner=dict(map_type=1,key_size=4,value_size=8,max_entries=32,map_flags=0)
        typed['maps'][0]['inner_map']=inner
        source,names=declarations(typed)
        self.assertIn('__array(values, struct __trusted_inner_0)',source)
        self.assertEqual(names,{'stats'})
        inner['source']='untrusted C'
        with self.assertRaises(ValueError):declarations(typed)
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
    def test_python_transport_matches_compiled_kernel_header(self):
        values=list(map(int,subprocess.check_output([ROOT/'kprog/libnativeloader/build/trusted-native-loader','abi'],text=True).split()))
        expected=[ctypes.sizeof(service.Request),ctypes.sizeof(service.Result)]
        expected += [getattr(service.Request,n).offset for n in ('request_id','native_size','native_user','entry_user','metadata_user')]
        expected += [getattr(service.Result,n).offset for n in ('status','prog_id','reserved')]
        expected += [service.NEXT,service.COMPLETE]
        expected += [ctypes.sizeof(service.Context),ctypes.sizeof(service.Map),service.Context.prog_flags.offset,service.Map.map_type.offset,service.GET_CONTEXT,service.GET_MAP]
        self.assertEqual(values,expected)

if __name__=='__main__':unittest.main()
