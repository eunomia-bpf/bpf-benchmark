"""Use the existing negative builder with real writeback/overlap encodings."""
from pathlib import Path
import shutil
import sys

ROOT = Path(__file__).resolve().parents[5]
sys.path.insert(0, str(ROOT/'kprog/fidelity'))
import negative

base = Path(sys.argv[1]).resolve()
base.mkdir(parents=True, exist_ok=True)
paired = ROOT/'kprog/fidelity/build-arm64/sp-alignment-bound'
for name in ['bound-probe','init','bpf_arm64_native_lab.ko','native-link','companion.bpf.o','Image']:
    shutil.copy2(paired/name, base/name)
prefix = 'sub sp,sp,#32;mov x3,#2;stp x3,x3,[sp];stp x3,x3,[sp,#16];mov x1,sp;'
suffix = ';add sp,sp,#32;mov w0,#2;ret'
cases = {
    'ldr_x_alias_post': 'ldr x1,[x1],#8',
    'ldr_w_alias_post': 'ldr w1,[x1],#4',
    'ldrb_alias_post': 'ldrb w1,[x1],#1',
    'ldrh_alias_post': 'ldrh w1,[x1],#2',
    'ldr_x_alias_pre': 'ldr x1,[x1,#8]!',
    'ldp_first_alias_post': 'ldp x1,x2,[x1],#16',
    'ldp_second_alias_pre': 'ldp x2,x1,[x1,#16]!',
    'str_x_alias_post': 'str x1,[x1],#8',
    'str_w_alias_post': 'str w1,[x1],#4',
    'stp_first_alias_post': 'stp x1,x2,[x1],#16',
    'stp_second_alias_pre': 'stp x2,x1,[x1,#16]!',
    'ldr_distinct_control': 'ldr x2,[x1],#8',
    'str_distinct_control': 'str x3,[x1],#8',
    'ldp_distinct_control': 'ldp x2,x3,[x1],#16',
    'stp_distinct_control': 'stp x2,x3,[x1],#16',
    'sp_zr_control': 'str xzr,[sp,#-16]!;add sp,sp,#16',
}
# X2 is also a defined scalar for both STP cases, without altering base X1.
negative.FIXTURES['arm64'] = {name:prefix+'mov x2,#2;'+body+suffix for name,body in cases.items()}
negative.build('arm64', base/'full-suite')
