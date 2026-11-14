"""Detect lost packet comparisons, flipped branches, and omitted add overflow."""
import ctypes as c
import json
from pathlib import Path
import subprocess
import sys
tool,native_tool,output=map(Path,sys.argv[1:]);output.mkdir(parents=True)
root=Path(__file__).resolve().parents[2]
calls=[]
def run(command):
    result=subprocess.run([str(x) for x in command],text=True,capture_output=True)
    calls.append(dict(command=[str(x) for x in command],returncode=result.returncode,stdout=result.stdout,stderr=result.stderr))
    (output/'commands.json').write_text(json.dumps(calls,indent=2)+'\n')
    result.check_returncode();return result
run(['clang-18','-target','bpf','-O2','-emit-llvm','-c','-I'+str(root/'vendor/libbpf/include/uapi'),'-I/usr/include/x86_64-linux-gnu',root/'kprog/test/packet_bounds_fixture.c','-o',output/'before.bc'])
result=run([tool,output/'before.bc','-o',output/'after.bc'])
assert 'lowered=6' in result.stderr,result.stderr
for variant in ['before','after']:
    run([native_tool,output/(variant+'.bc'),'-o',output/(variant+'.native.bc')])
    run(['clang-18','-shared','-fPIC','-O2',output/(variant+'.native.bc'),'-o',output/(variant+'.so')])
libraries=[c.CDLL(str(output/(v+'.so'))) for v in ['before','after']]
class Context(c.Structure):_fields_=[('data',c.c_uint32),('end',c.c_uint32)]
vectors=[]
for name in ['less','at_most','at_least','more','unsigned_less','unsigned_more','scalar']:
    functions=[getattr(lib,name) for lib in libraries]
    for f in functions:f.argtypes=[c.c_void_p];f.restype=c.c_int
    for start in [0,1,0x7ffffff0,0xfffffff0]:
        for length in [0,1,63,64,65,127]:
            if start+length>0xffffffff:continue
            context=Context(start,start+length)
            values=[f(c.byref(context)) for f in functions]
            assert values[0]==values[1],(name,start,length,values)
            vectors.append(dict(name=name,start=start,length=length,values=values))
# Shared arithmetic contract, independent of LLVM and of any individual program.
arithmetic=0
for width in [2,3,4,5,6]:
    mask=(1<<width)-1
    for start in range(mask+1):
        for end in range(start,min(mask+1,start+(1<<(width-1)))):
            for size in range(mask+1):
                bound=(start+size)&mask
                assert ((end-start)<size)==(bound<start or bound>end)
                assert ((end-start)<size)==((end-start)<size or bound>end)
                arithmetic+=1
for start in [0,1,(1<<63),0xfffffffffffffff0]:
    for length in [0,1,15,63,64,65]:
        if start+length>=(1<<64):continue
        for size in [0,1,15,64,65,(1<<63),(1<<64)-1]:
            bound=(start+size)&((1<<64)-1)
            assert (length<size)==(bound<start or bound>start+length)
            assert (length<size)==(length<size or bound>start+length)
            arithmetic+=1
(output/'execution.json').write_text(json.dumps(vectors,indent=2)+'\n')
(output/'arithmetic.json').write_text(json.dumps(dict(cases=arithmetic,domain='ordered packet span <=PTRDIFF_MAX, all unsigned thresholds',predicate='length<K iff add overflows or start+K>end'),indent=2)+'\n')
print(json.dumps(dict(executable_vectors=len(vectors),arithmetic_cases=arithmetic,scope='shared bounds lowering, not per-program proof')))

# Keep live choices independent and all unrelated/atomic/narrow/offset reads.
private_ir = '''target triple = "bpf"
@kprog_unspecified_input = external global [0 x i64], section ".ksyms"
@ordinary = external global i64
define i64 @choices() {
  %dead = load volatile i64, ptr @kprog_unspecified_input
  %left = load volatile i64, ptr @kprog_unspecified_input
  %right = load volatile i64, ptr @kprog_unspecified_input
  %delta = sub i64 %left, %right
  ret i64 %delta
}
define void @other() {
  %ordinary_read = load volatile i64, ptr @ordinary
  %nonzero = load volatile i64, ptr getelementptr (i64, ptr @kprog_unspecified_input, i64 1)
  %atomic = load atomic volatile i64, ptr @kprog_unspecified_input monotonic, align 8
  %narrow = load volatile i32, ptr @kprog_unspecified_input
  ret void
}
'''
for section,removed in [('.ksyms',1),('.data',0)]:
    stem='private' if removed else 'ordinary-section'
    source=output/(stem+'.ll');source.write_text(private_ir.replace('.ksyms',section))
    result=run([tool,source,'-o',output/(stem+'.bc')])
    assert f'unused private inputs removed={removed}' in result.stderr,result.stderr
    run(['llvm-dis-18',output/(stem+'.bc'),'-o',output/(stem+'-after.ll')])
    text=(output/(stem+'-after.ll')).read_text()
    assert ('%dead = load' in text)==(not removed)
    for name in ['left','right','ordinary_read','nonzero','atomic','narrow']:
        assert '%'+name+' = load' in text,(section,name)
    assert '%delta = sub i64 %left, %right' in text
print('private input projection PASS: unused choice removed, both live draws and all other reads retained')
