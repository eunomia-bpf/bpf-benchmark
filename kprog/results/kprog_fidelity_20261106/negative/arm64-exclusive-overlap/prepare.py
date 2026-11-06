"""Real STXR/STLXR status overlap encodings, through the production generator."""
from pathlib import Path
import shutil
import sys

ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import negative
base=Path(sys.argv[1]).resolve();base.mkdir(parents=True,exist_ok=True)
paired=ROOT/'kprog/fidelity/build-arm64/sp-alignment-bound'
for name in ['bound-probe','init','bpf_arm64_native_lab.ko','native-link','companion.bpf.o','Image']:
    shutil.copy2(paired/name,base/name)
prefix='sub sp,sp,#16;mov x1,#2;str x1,[sp];mov x2,sp;'
suffix=';add sp,sp,#16;mov w0,#2;ret'
negative.FIXTURES['arm64']={
    'stxr_status_data':prefix+'stxr w1,x1,[x2]'+suffix,
    'stlxr_status_data':prefix+'stlxr w1,w1,[x2]'+suffix,
    'stxr_status_base':prefix+'stxr w2,x1,[x2]'+suffix,
    'stlxr_status_base':prefix+'stlxr w2,w1,[x2]'+suffix,
    'status_zr_control':prefix+'stxr wzr,x1,[x2]'+suffix,
    'data_zr_control':prefix+'stlxr w0,xzr,[sp]'+suffix,
}
negative.build('arm64',base/'full-suite')
