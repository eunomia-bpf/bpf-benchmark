"""Broker B flags must match the ARM worker's single architecture policy."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sys.path.insert(0,str(ROOT/'kprog'))
import trusted_compile
spec=importlib.util.spec_from_file_location('arm_flags',ROOT/'kprog/arm64/trusted_specializer.py')
worker=importlib.util.module_from_spec(spec);spec.loader.exec_module(worker)
phase=sys.argv[1]
command=trusted_compile.compile_command(Path('input.bc'),Path('output.o'),'arm64','clang-18')
expected=['clang-18',*map(str,worker.b_flags()),'-c','input.bc','-o','output.o']
record=dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
 command=command,worker_command=expected,commands_equal=command==expected,
 scope='Actual worker/broker compiler argument contract, no kernel/app/timing claim.')
(HERE/f'flags-{phase}.json').write_text(json.dumps(record,indent=2)+'\n')
print('worker/broker flags equal',record['commands_equal'])
if phase=='after' and not record['commands_equal']:raise AssertionError('ARM compiler flags drift')
