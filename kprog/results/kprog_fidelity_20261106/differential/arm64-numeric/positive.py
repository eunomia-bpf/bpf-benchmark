from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[5]
sys.path.insert(0,str(ROOT/'kprog/fidelity'))
import negative
negative.FIXTURES['arm64']={
 'restore_return': 'str x30,[sp,#-16]!; ldr x30,[sp],#16; mov w0,#2; ret',
 'restore_stack': 'mov x1,sp; str x1,[sp,#-16]!; ldr x1,[sp],#16; mov sp,x1; mov w0,#2; ret',
 'restore_pair': 'mov x1,sp; stp x1,x30,[sp,#-16]!; ldp x1,x30,[sp],#16; mov sp,x1; mov w0,#2; ret',
 'stack_byte_observation': 'mov x1,sp; str x1,[sp,#-16]!; ldrb w0,[sp]; add sp,sp,#16; ret',
 'return_byte_observation': 'str x30,[sp,#-16]!; ldrb w0,[sp]; add sp,sp,#16; ret',
}
negative.build('arm64',Path(sys.argv[1]))
