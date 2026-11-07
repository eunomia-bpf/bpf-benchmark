from pathlib import Path
import hashlib,json,subprocess
r=Path('/workspaces/repository');s=Path('/workspaces/.agent-state/kprog-lanes/F');old=r/'kprog/fidelity/build-sp-v2e/source';new=r/'kprog/fidelity/build-sp-v3/source';new.mkdir(parents=True,exist_ok=True)
pins=json.loads((s/'sp-v2e-source-pins.json').read_text())
for rel,sha in pins['files'].items():
 data=(old/rel).read_bytes();assert hashlib.sha256(data).hexdigest()==sha,rel
 p=new/rel;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(data)
# Preserve both pre-state origins across a full register permutation, including
# RSP's relative representation. Never reread a source after the first write.
p=new/'kprog/x86/x86_sim_local_bpf.h';t=p.read_text();a=t.index('\t\t\t\t\tvoid *__x86_l_dst_ptr',t.index('KPROG_X86_DISP_XCHG_HANDLED'));b=t.index('\t\t\t} else {',a)
body='''void *__x86_l_dst_ptr = (DST) == X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(DST)) : X86_SIM_L_READ_REG_PTR(DST);
void *__x86_l_src_ptr = (SRC) == X86_RSP ? X86_SIM_L_STACK_PTR((__s64)(long)X86_SIM_L_READ_REG_PTR(SRC)) : X86_SIM_L_READ_REG_PTR(SRC);
__u8 __x86_l_dst_tag = (DST) == X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(DST);
__u8 __x86_l_src_tag = (SRC) == X86_RSP ? X86_SIM_TAG_STACK : X86_SIM_L_REG_TAG(SRC);
__u64 __x86_l_dst_bits = X86_SIM_L_READ_REG(DST);
__u64 __x86_l_src_bits = X86_SIM_L_READ_REG(SRC);
if ((DST) == X86_RSP)
    X86_SIM_L_WRITE_REG_WIDTH((DST), __x86_l_src_bits, X86_WIDTH_64);
else
    X86_SIM_L_WRITE_REG_PTR_TAG((DST), __x86_l_src_ptr, __x86_l_src_tag);
if ((SRC) == X86_RSP)
    X86_SIM_L_WRITE_REG_WIDTH((SRC), __x86_l_dst_bits, X86_WIDTH_64);
else
    X86_SIM_L_WRITE_REG_PTR_TAG((SRC), __x86_l_dst_ptr, __x86_l_dst_tag);
'''
t=t[:a]+''.join('\t\t\t\t'+line+' \\\n' for line in body.splitlines())+t[b:]
for name in ['__x86_stw_index','__x86_str_index']:
 assert t.count('__u32 '+name)==1;t=t.replace('__u32 '+name,'__u64 '+name)
p.write_text(t)
# Single index specification: unsigned native-width wrapping addition.
p=new/'kprog/formal/contracts/x86_stack_index_spec.json';d=json.loads(p.read_text());d['index_mask_bits']=64;p.write_text(json.dumps(d,separators=(',',':'))+'\n')
p=new/'kprog/formal/tools/generate_x86_stack_index_spec.py';t=p.read_text();start=t.index('"""');end=t.index('"""',start+3)+3;t=t[:start]+'"""Generate native-width wrapping frame indexes; distinct high bits must survive."""'+t[end:];t=t.replace('"index_mask_bits": 32','"index_mask_bits": 64').replace('`off + capacity`, truncated to the C helpers\' 32-bit index','`off + capacity`, retained in the C helpers\' 64-bit index').replace(': BitVec 32 :=\n  (capacity + off).truncate 32',': BitVec 64 :=\n  capacity + off').replace('((__u32)((__s64)(OFF) + (__s64)(CAPACITY)))','((__u64)(OFF) + (__u64)(CAPACITY))');p.write_text(t)
p=new/'kprog/formal/KProgFormal/X86StackIndex.lean';p.write_text('''import KProgFormal.Generated.GeneratedX86StackIndex
namespace KProgFormal
open GeneratedX86StackIndex (index)
/-- Native addresses wrap only at 64 bits, independently stated with commuted operands. -/
def x86StackIndexSpec (capacity off : BitVec 64) : BitVec 64 := off + capacity
theorem x86_stack_index_refines (capacity off : BitVec 64) :
    index capacity off = x86StackIndexSpec capacity off := by
  unfold index x86StackIndexSpec
  bv_decide
theorem x86_stack_index_frame_base_is_zero (capacity : BitVec 64) :
    index capacity (-capacity) = 0 := by
  unfold index
  bv_decide
theorem x86_stack_index_top_is_capacity (capacity : BitVec 64) :
    index capacity 0 = capacity := by
  unfold index
  bv_decide
/-- Adding a nonzero high word cannot alias a distinct native address. -/
theorem x86_stack_index_high_bits_distinct (capacity off delta : BitVec 64)
    (h : delta != 0) : index capacity (off + delta) != index capacity off := by
  unfold index
  bv_decide
/-- The old high32 alias input remains, with its corrected native64 result. -/
theorem x86_stack_index_example :
    index 64 (-56) = 8 /\\ index 64 (-8) = 56 /\\ index 64 0 = 64 /\\
    index 64 ((-56) + 0x100000000) = 0x100000008 := by
  decide
end KProgFormal
''')
# Widen the existing arena model, including all dependent bounds. Capacity
# rounding and byte extraction retain their meaning; no second index semantics.
p=new/'kprog/formal/contracts/x86_stack_arena_spec.json';d=json.loads(p.read_text());d['index_bits']=64;p.write_text(json.dumps(d,separators=(',',':'))+'\n')
p=new/'kprog/formal/tools/generate_x86_stack_arena_spec.py';t=p.read_text().replace('"operation": "x86StackArena",','"operation": "x86StackArena",\n    "index_bits": 64,').replace('32-bit stack index','64-bit stack index').replace('BitVec 32','BitVec 64').replace('32-bit\nindex space','64-bit\nindex space')
t=t.replace('((__u32)(INDEX) >>','((__u64)(INDEX) >>').replace('((__u32)(INDEX) &','((__u64)(INDEX) &').replace('((__u32)(CAPACITY) +','((__u64)(CAPACITY) +').replace('(__u64)(__u32)(INDEX)','(__u64)(INDEX)').replace('(__u64)(__u32)(BYTES)','(__u64)(BYTES)').replace('(__u64)(__u32)(CAPACITY)','(__u64)(CAPACITY)').replace('(__u64)(__s64)(__u32)(CAPACITY)','(__u64)(CAPACITY)')
t=t.replace('((KPROG_X86_STACK_WINDOW_END((INDEX), (BYTES)) <= (__u64)(CAPACITY)) ? 1 : 0)','((((__u64)(INDEX) <= (__u64)(CAPACITY)) && ((__u64)(BYTES) <= (__u64)(CAPACITY) - (__u64)(INDEX))) ? 1 : 0)')
# Exact (nonwrapping) fit test, matching subtraction-form C even near UINT64_MAX.
t=t.replace('comparison is widened to 64 bits, so an access near the top of the 32-bit','fit predicate uses a subtraction form, so an access near the top of the 64-bit')
p.write_text(t)
p=new/'kprog/formal/KProgFormal/X86StackArena.lean';t=p.read_text().replace('BitVec 32','BitVec 64').replace('2 ^ 32','2 ^ 64').replace('ofNat 32','ofNat 64').replace('4294967288','18446744073709551608').replace('2^32','2^64');p.write_text(t)
# All old arithmetic inputs are retained, including the previously aliasing pair.
p=new/'kprog/formal/oracles/test_x86_stack_index_host.c';t=p.read_text().replace('keeps the low 32 bits','keeps all 64 bits').replace('high-32-bit-aliasing','high-32-bit-nonaliasing').replace('unsigned-64-bit low-32-bits','unsigned-64-bit full-width').replace('(unsigned long)(((__u64)off + (__u64)cap) &\n\t\t\t\t\t\t0xffffffffULL)','(unsigned long)((__u64)off + (__u64)cap)').replace('/* Aliasing: adding 2^32 to the offset keeps the index. */','/* The same old high32 input now retains its distinct address. */').replace('check_index("alias", cap, off + 0x100000000LL, want);','check_index("distinct_high32", cap, off + 0x100000000LL, want + 0x100000000UL);');p.write_text(t)
# Existing arena oracle tests use32bit capacities, no data removed. Additional
# full-width slots exercise the formerly truncated path without dereferencing.
p=new/'kprog/formal/oracles/test_x86_stack_arena_host.c';t=p.read_text();marker='int main(void)\n{';assert t.count(marker)==1;t=t.replace(marker,marker+'''\n    if (KPROG_X86_STACK_WORD_INDEX(0x100000000ULL) != 0x20000000ULL ||
        KPROG_X86_STACK_WORD_INDEX(0x800000000ULL) != 0x100000000ULL ||
        KPROG_X86_STACK_WINDOW_FITS(0x100000000ULL, 8, 128)) {
        puts("MISMATCH full-width native arena address"); return 1;
    }
''');p.write_text(t)
# Independent XCHG model snapshots source values/tags; geometry is fixture input.
p=new/'kprog/formal/oracles/test_x86_xchg_route_host.c';t=p.read_text();a=t.index('static void model_xchg(');b=t.index('/* Plant the pristine',a)
t=t[:a]+'''static __u64 model_arena_top;
static __u64 model_native_value(unsigned reg)
{
    if (reg != X86_RSP && mtag[reg] == X86_SIM_TAG_STACK)
        return mreg[reg] - model_arena_top;
    return mreg[reg];
}
static void model_xchg(unsigned dst, unsigned src, unsigned flags)
{
    unsigned w = resolve_width(flags);
    __u64 dv = model_native_value(dst), sv = model_native_value(src);
    __u64 dr = dst == X86_RSP ? model_arena_top + mreg[dst] : mreg[dst];
    __u64 sr = src == X86_RSP ? model_arena_top + mreg[src] : mreg[src];
    __u8 dt = dst == X86_RSP ? X86_SIM_TAG_STACK : mtag[dst];
    __u8 st = src == X86_RSP ? X86_SIM_TAG_STACK : mtag[src];
    if (w == X86_WIDTH_64) {
        mreg[dst] = dst == X86_RSP ? sv : sr;
        mtag[dst] = dst == X86_RSP ? X86_SIM_TAG_SCALAR : st;
        mreg[src] = src == X86_RSP ? dv : dr;
        mtag[src] = src == X86_RSP ? X86_SIM_TAG_SCALAR : dt;
    } else {
        mreg[dst] = model_partial_write(dv, sv, w);
        mreg[src] = model_partial_write(sv, dv, w);
        mtag[dst] = mtag[src] = X86_SIM_TAG_SCALAR;
    }
}

'''+t[b:]
t=t.replace('\tPLANT_REGS();','\tmodel_arena_top = (__u64)(unsigned long)&__x86_stack_mem.b[sizeof(__x86_stack_mem.b)];\n\tPLANT_REGS();');p.write_text(t)
# Correct the old raw-cell tag theorem; canonical native semantics is unchanged.
p=new/'kprog/formal/KProgFormal/X86XchgHandler.lean';t=p.read_text().replace('cells exchange their whole 64-bit values and both tags become scalar.','cells exchange their whole values and origin tags.').replace('({ bits := src.bits, tag := .scalar },\n   { bits := dst.bits, tag := .scalar })','(src, dst)');a=t.index('/-- The pointer arm scalarizes both tags:');b=t.index('/-- The subword arm scalarizes',a);t=t[:a]+'''/-- A full-width copy permutes origin metadata along with each value. -/
theorem x86_xchg_pointer_preserves_origins (dst src : X86RegValue) :
    (x86XchgPointerSpec dst src).1.tag = src.tag /\\
      (x86XchgPointerSpec dst src).2.tag = dst.tag := by
  exact { left := rfl, right := rfl }

'''+t[b:];p.write_text(t)
# Prose only: selector shape and emitted constants stay unchanged.
p=new/'kprog/formal/tools/generate_x86_xchg_spec.py';t=p.read_text().replace('scalarizing','origin-preserving').replace('scalarizes both tags','preserves both origin tags').replace('while\n * scalarizing','while\n * preserving source tags').replace('moving the whole 64-bit cell and scalarizing both tags','moving the whole 64-bit cell and preserving both origin tags');p.write_text(t)
(new/'vendor').symlink_to(r/'vendor',target_is_directory=True)
for op in ['stack_index','stack_arena','xchg']:
 subprocess.run(['python3',str(new/f'kprog/formal/tools/generate_x86_{op}_spec.py')],check=True)
files={str(p.relative_to(new)):hashlib.sha256(p.read_bytes()).hexdigest() for p in new.rglob('*') if p.is_file() and not p.is_symlink()}
(s/'sp-v3-source-pins.json').write_text(json.dumps(dict(base=pins['base'],files=files),indent=2)+'\n')
# Generate40-sequence runner and focused route checks only; FULL follows checks.
t=(s/'local-sp-alias-audit.sh').read_text().replace('build-sp-v2e/source','build-sp-v3/source').replace('sp-alias-audit','sp-v3-sequences');(s/'local-sp-v3-sequences.sh').write_text(t)
print('v3 immutable candidate prepared')
