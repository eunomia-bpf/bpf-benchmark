"""Native C scalar helper bodies, instantiated from the shared source header."""
import json
from pathlib import Path
from inline_array import KernelTypes, field_offset


def pid_source(kernel_btf):
    types = KernelTypes(kernel_btf)
    try:
        task = types.lib.btf__find_by_name_kind(types.btf, b'task_struct', 4)
        pid = field_offset(types, task, 'pid')
        tgid = field_offset(types, task, 'tgid')
    finally:
        types.close()
    header = Path(__file__).resolve().parents[3] / 'vendor/bpf/native-helpers.h'
    return '#include ' + json.dumps(str(header)) + '\n__KPROG_PID_TGID_CODE(%d,%d)\n' % (pid, tgid)
