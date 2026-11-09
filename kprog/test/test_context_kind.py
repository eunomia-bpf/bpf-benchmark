"""Entry-layout dispatch follows the kernel's context conversion families."""
from pathlib import Path
import ast
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from trusted_generation import context_kind

root = Path(__file__).resolve().parents[2]
identity = {2, 5, 15, 17, 20, 24, 26, 27, 28, 29, 31, 32}
typed = {3: 'tc', 6: 'xdp', 8: 'cgroup_skb'}
# Kernel declarations tie UAPI context families to their kernel objects.
source = (root / 'vendor/linux-framework/include/linux/bpf_types.h').read_text()
entries = re.findall(r'BPF_PROG_TYPE\(BPF_PROG_TYPE_(\w+),\s*(\w+),\s*([^,]+),\s*([^\)]+)\)', source)
uapi = (root / 'vendor/linux-framework/include/uapi/linux/bpf.h').read_text()
enum = uapi.split('enum bpf_prog_type {', 1)[1].split('};', 1)[0]
names = re.findall(r'\bBPF_PROG_TYPE_(\w+)\b', enum)
conversions = {'sk_filter','tc_cls_act','xdp','cg_skb','cg_sock','cg_sock_addr',
               'lwt_in','lwt_out','lwt_xmit','lwt_seg6local','sock_ops','sk_skb',
               'sk_msg','flow_dissector','perf_event','cg_sysctl','cg_sockopt',
               'sk_reuseport','sk_lookup'}
for name, handler, public, kernel in entries:
    n = names.index(name)
    if handler in conversions:
        assert n not in identity, (name, public, kernel)
    else:
        assert n in identity, (name, public, kernel)
for n in range(1, 33):
    if n in typed or n in identity:
        assert context_kind(n) == typed.get(n, 'raw')
    else:
        try:
            context_kind(n)
        except ValueError as error:
            assert 'context layout handler required' in str(error)
        else:
            raise AssertionError(n)
for arch in ('x86', 'arm64'):
    tree = ast.parse((root / f'kprog/{arch}/trusted_specializer.py').read_text())
    calls = [n for n in ast.walk(tree) if isinstance(n, ast.Call)
             and isinstance(n.func, ast.Name) and n.func.id == 'context_kind']
    assert len(calls) == 1, arch
print('context layout dispatch: PASS (32 types, both ISAs)')
