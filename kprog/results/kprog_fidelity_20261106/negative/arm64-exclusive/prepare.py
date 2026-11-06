"""Specialize real exclusive-store branches; never execute unsafe native code."""
from pathlib import Path
import shutil
import sys

ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import negative
base=Path(sys.argv[1]).resolve()
base.mkdir(parents=True,exist_ok=True)
paired=ROOT/'kprog/fidelity/build-arm64/sp-alignment-bound'
for name in ['bound-probe','init','bpf_arm64_native_lab.ko','native-link','companion.bpf.o','Image']:
    shutil.copy2(paired/name,base/name)
prefix='sub sp,sp,#16;mov x1,#2;str x1,[sp];mov x2,sp;'
unsafe=';cbz w0,1f;mov x3,#0;ldr w0,[x3];1:add sp,sp,#16;mov w0,#2;ret'
safe=';add sp,sp,#16;mov w0,#2;ret'
negative.FIXTURES['arm64']={
    'unpaired_stxr_failure':prefix+'stxr w0,x1,[x2]'+unsafe,
    'unpaired_stlxr_failure':prefix+'stlxr w0,x1,[x2]'+unsafe,
    'paired_stxr_failure':prefix+'ldxr x1,[x2];stxr w0,x1,[x2]'+unsafe,
    'paired_stlxr_failure':prefix+'ldaxr x1,[x2];stlxr w0,x1,[x2]'+unsafe,
    'unpaired_stxr_control':prefix+'stxr w0,x1,[x2]'+safe,
    'paired_stxr_control':prefix+'ldxr x1,[x2];stxr w0,x1,[x2]'+safe,
}
negative.build('arm64',base/'full-suite')
