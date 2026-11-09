#!/usr/bin/env python3
"""Extract the shared successful relocation C model and its source receipt.

This is a build-time source translator. Each supported whole function has a
closed grammar; extraction recognizes its complete normalized body before
lowering it. Linux allocation, memcpy, reference, callback and compiler
semantics are the external interface. The generated functions accept arbitrary
records, maps and images. Run with --check to reproduce the committed module.
"""
from __future__ import annotations
import argparse
import ast
import hashlib
from pathlib import Path
import re
import subprocess

FORMAL = Path(__file__).resolve().parents[1]
REPO = FORMAL.parents[1]
OUTPUT = FORMAL / 'KProgFormal/Generated/NativeLinkSource.lean'


def normalized(text: str) -> str:
    text = re.sub(r'/\*.*?\*/|//[^\n]*', '', text, flags=re.S)
    return re.sub(r'\s+', '', text)


def body(source: str, name: str) -> str:
    source = re.sub(r'"(?:\\.|[^"\\])*"|/\*.*?\*/|//[^\n]*',
        lambda m: m.group() if m.group().startswith('"') else ' ', source, flags=re.S)
    match = re.search(r'\b' + re.escape(name) + r'\s*\([^;{}]*\)\s*(?:->[^;{}]*)?\{', source)
    if match is None:
        raise ValueError(f'function {name}: definition required')
    start = match.end() - 1
    depth = 1
    pos = start + 1
    # These C bodies contain ordinary quoted diagnostics and block comments.
    token = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|[{}]', re.S)
    for item in token.finditer(source, pos):
        if item.group() == '{': depth += 1
        elif item.group() == '}': depth -= 1
        if depth == 0: return source[start+1:item.start()]
    raise ValueError(f'function {name}: balanced body required')


def recognize(source: str, name: str, expected: str) -> str:
    actual = body(source, name)
    if normalized(actual) != normalized(expected):
        raise ValueError(f'{name}: source grammar changed; extend its translation')
    return actual


MAP_TARGET = '''
 u32 id = (u32)reloc->target, offset = reloc->target >> 32, i;
 for (i = 0; i < count; i++) {
  struct bpf_map *map = maps[i]; int err;
  if (map->id != id) continue;
  if (reloc->kind == NATIVE_LAB_RELOC_MAP_POINTER) {
   if (offset) return -EINVAL;
   *target = (unsigned long)map; return 0;
  }
  if (!map->ops->map_direct_value_addr || offset >= map->value_size) return -EINVAL;
  err = map->ops->map_direct_value_addr(map, target, offset);
  if (!err) *target += offset;
  return err;
 }
 return -ENOENT;
'''
LITERAL = '''
 u64 target; int err;
 if ((size_t)reloc->offset + sizeof(target) > length) return -ERANGE;
 if (reloc->kind == NATIVE_LAB_RELOC_HELPER_POINTER) {
  target = reloc->target; err = 0;
 } else { err = native_lab_map_target(reloc, maps, map_count, &target); }
 if (!err) memcpy(destination + reloc->offset, &target, sizeof(target));
 return err;
'''
CHUNK = '''
 std::vector<uint8_t> bytes;
 for (const NativeLabReloc &reloc : relocs) {
  const size_t start = reloc.global_offset;
  const size_t end = start + native_lab_reloc_slot_bytes(reloc.kind);
  if (start >= chunk.offset && end <= chunk.offset + chunk.len) {
   append_u32_le(bytes, static_cast<uint32_t>(start - chunk.offset));
   append_u32_le(bytes, reloc.kind); append_u64_le(bytes, reloc.target);
  }
 }
 return bytes;
'''
RETAIN = '''
 if (prog->aux->native_trusted_request) return 0;
 if (!try_module_get(THIS_MODULE)) return -ENODEV;
 kref_get(&capsule->refs);
 prog->aux->native_trusted_request = capsule;
 prog->aux->native_trusted_put = native_lab_trusted_put;
 prog->aux->native_trusted_owner = THIS_MODULE;
 return 0;
'''
FREE_BLOB = '''
 while (blob->map_count) bpf_map_put(blob->maps[--blob->map_count]);
 kfree(blob->maps); kvfree(blob->bytes); kvfree(blob->relocs);
 kvfree(blob->proof); kvfree(blob->load_sites); kfree(blob);
'''
CAPSULE_RELEASE = '''
 struct native_lab_trusted_capsule *capsule = container_of(ref,
  struct native_lab_trusted_capsule, refs);
 u32 i;
 if (capsule->release_chunks) capsule->release_chunks(capsule);
 for (i = 0; i < capsule->resource_count; i++) bpf_map_put(capsule->resource_maps[i]);
 kfree(capsule->resource_maps);
 if (capsule->source) bpf_prog_put(capsule->source);
 kvfree(capsule->native); kvfree(capsule->metadata);
 kfree(capsule->entry); kfree(capsule);
'''




BIND_MAPS = r"""
 for (const auto &site : patches) {
  const auto identity = companion.map_addr_ids.find(site.name);
  const auto address = companion.map_addrs.find(site.name);
  if (identity == companion.map_addr_ids.end() || address == companion.map_addrs.end())
   fail("native map relocation lacks original map identity: " + site.name);
  const auto map = std::find_if(companion.maps.begin(), companion.maps.end(),
   [&](const MapMeta &m) { return m.kernel_id == identity->second; });
  if (map == companion.maps.end())
   fail("native map relocation has no original map layout: " + site.name);
  uint32_t kind = NATIVE_LAB_RELOC_MAP_POINTER;
  uint64_t offset = 0;
  if (address->second != map->kernel_addr) {
   kind = NATIVE_LAB_RELOC_MAP_VALUE;
   if (!map->value_addr || address->second < map->value_addr ||
     address->second - map->value_addr >= map->value_size)
    fail("native map relocation exceeds original value: " + site.name);
   offset = address->second - map->value_addr;
  }
  if (site.offset > std::numeric_limits<uint32_t>::max())
   fail("native map relocation offset exceeds wire format");
  if (site.offset > linked.blob.size() || sizeof(uint64_t) > linked.blob.size() - site.offset)
   fail("native map literal exceeds linked bytes: " + site.name);
  std::fill_n(linked.blob.begin() + site.offset, sizeof(uint64_t), 0);
  append_u32_le(linked.relocs, static_cast<uint32_t>(site.offset));
  append_u32_le(linked.relocs, kind);
  append_u64_le(linked.relocs, identity->second | (offset << 32));
 }
"""


X86_DATA_OBJECT = r"""
 if size != 0 {
  let end = offset.checked_add(size).ok_or_else(|| anyhow!("PC32 target size overflow"))?;
  let start = usize::try_from(offset)?;
  let end = usize::try_from(end)?;
  let bytes = data.get(start..end)
   .ok_or_else(|| anyhow!("PC32 target {name} exceeds section extent"))?;
  return Ok((name.to_string(), bytes.to_vec(), 0));
 }
 let bytes = if section_name.starts_with(".rodata") { data.to_vec() }
  else if name.is_empty() && section_name == ".bss" { vec![0; usize::try_from(section_size)?] }
  else { bail!("PC32 zero-sized target {name} requires a readonly section or an unnamed bss section"); };
 if bytes.is_empty() || offset > bytes.len() as u64 {
  bail!("PC32 label {name} exceeds section extent");
 }
 Ok((format!("section:{section:?}:{section_name}"), bytes, offset))
"""

TAIL_DIRECT = r"""
 int tcc_ptr_off = BPF_TAIL_CALL_CNT_PTR_STACK_OFF(stack_depth);
 u8 *prog = *pprog, *start = *pprog; int offset;
 EMIT3_off32(0x48, 0x8B, 0x85, tcc_ptr_off);
 EMIT4(0x48, 0x83, 0x38, MAX_TAIL_CALL_CNT);
 offset = ctx->tail_call_direct_label - (prog + 2 - start);
 EMIT2(X86_JAE, offset);
 poke->tailcall_bypass = ip + (prog - start);
 poke->adj_off = X86_TAIL_CALL_OFFSET;
 poke->tailcall_target = ip + ctx->tail_call_direct_label - X86_PATCH_SIZE;
 poke->bypass_addr = (u8 *)poke->tailcall_target + X86_PATCH_SIZE;
 emit_jump(&prog, (u8 *)poke->tailcall_target + X86_PATCH_SIZE, poke->tailcall_bypass);
 EMIT4(0x48, 0x83, 0x00, 0x01);
 if (bpf_prog->aux->exception_boundary) {
  pop_callee_regs(&prog, all_callee_regs_used); pop_r12(&prog);
 } else {
  pop_callee_regs(&prog, callee_regs_used);
  if (bpf_arena_get_kern_vm_start(bpf_prog->aux->arena)) pop_r12(&prog);
 }
 EMIT1(0x58); EMIT1(0x58);
 if (stack_depth) EMIT3_off32(0x48, 0x81, 0xC4, round_up(stack_depth, 8));
 emit_nops(&prog, X86_PATCH_SIZE);
 ctx->tail_call_direct_label = prog - start;
 *pprog = prog;
"""
TAIL_FIXUP = r"""
 struct bpf_jit_poke_descriptor *poke; struct bpf_array *array;
 struct bpf_prog *target; int i, ret;
 for (i = 0; i < prog->aux->size_poke_tab; i++) {
  poke = &prog->aux->poke_tab[i];
  if (poke->aux && poke->aux != prog->aux) continue;
  WARN_ON_ONCE(READ_ONCE(poke->tailcall_target_stable));
  if (poke->reason != BPF_POKE_REASON_TAIL_CALL) continue;
  array = container_of(poke->tail_call.map, struct bpf_array, map);
  mutex_lock(&array->aux->poke_mutex);
  target = array->ptrs[poke->tail_call.key];
  if (target) {
   ret = __bpf_arch_text_poke(poke->tailcall_target, BPF_MOD_NOP, BPF_MOD_JUMP,
    NULL, (u8 *)target->bpf_func + poke->adj_off);
   BUG_ON(ret < 0);
   ret = __bpf_arch_text_poke(poke->tailcall_bypass, BPF_MOD_JUMP, BPF_MOD_NOP,
    (u8 *)poke->tailcall_target + X86_PATCH_SIZE, NULL);
   BUG_ON(ret < 0);
  }
  WRITE_ONCE(poke->tailcall_target_stable, true);
  mutex_unlock(&array->aux->poke_mutex);
 }
"""
PATCH = r"""
 u8 *prog = *pprog; s64 offset;
 offset = func - (ip + X86_PATCH_SIZE);
 if (!is_simm32(offset)) {
  pr_err("Target call %p is out of range\n", func); return -ERANGE;
 }
 EMIT1_off32(opcode, offset); *pprog = prog; return 0;
"""

def extract(repo: Path, scratch: Path) -> str:
    def read(path: str) -> str:
        text = (repo / path).read_text()
        return text
    group_path = 'kinsn/module/include/native_lab_group.h'
    group = read(group_path)
    target = recognize(group, 'native_lab_map_target', MAP_TARGET)
    literal = recognize(group, 'native_lab_emit_literal', LITERAL)
    loader_path = 'kprog/libnativeloader/src/native_loader.cpp'
    loader = read(loader_path)
    chunk = recognize(loader, 'chunk_reloc_bytes', CHUNK)
    binder = recognize(loader, 'bind_native_map_relocations', BIND_MAPS)
    slots = body(loader, 'native_lab_reloc_slot_bytes')
    expected_slots = '''switch (kind) {
      case NATIVE_LAB_RELOC_X86_TAIL_COUNT:
      case NATIVE_LAB_RELOC_X86_TAIL_STACK: return sizeof(int32_t);
      case NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE: return 4;
      case NATIVE_LAB_RELOC_READONLY_DATA: return 1;
      case NATIVE_LAB_RELOC_MAP_POINTER:
      case NATIVE_LAB_RELOC_MAP_VALUE:
      case NATIVE_LAB_RELOC_HELPER_POINTER: return sizeof(uint64_t);
      case kNativeLabRelocHelperCallRel32: return kNativeLabRelocHelperCallRel32Bytes;
      case kNativeLabRelocHelperCallArm64: return kNativeLabRelocHelperCallArm64Bytes;
      case kNativeLabRelocHelperCallArm64Bl26: return kNativeLabRelocHelperCallArm64Bl26Bytes;
      case kNativeLabRelocArm64PercpuMrs: return kNativeLabRelocArm64PercpuMrsBytes;
      default: fail("native_lab reloc has unknown kind " + std::to_string(kind));
    }'''
    if normalized(slots) != normalized(expected_slots): raise ValueError('slot size grammar changed')
    for name, value in [('kNativeLabRelocHelperCallRel32Bytes',5),
                        ('kNativeLabRelocHelperCallArm64Bytes',16),
                        ('kNativeLabRelocHelperCallArm64Bl26Bytes',4),
                        ('kNativeLabRelocArm64PercpuMrsBytes',4)]:
        if not re.search(r'constexpr size_t '+name+r' = '+str(value)+r';',loader):
            raise ValueError(f'{name}: source size changed')
    trusted_path = 'kinsn/module/include/native_lab_trusted.h'
    trusted = read(trusted_path)
    retain = recognize(trusted, 'native_lab_retain_program', RETAIN)
    put = recognize(trusted,'native_lab_trusted_put','''
      struct native_lab_trusted_capsule *capsule = pointer;
      if (capsule) kref_put(&capsule->refs, native_lab_capsule_release);
    ''')
    active = recognize(trusted,'native_lab_active_capsule','''
      struct native_lab_trusted_capsule *capsule = ERR_PTR(-ENOENT);
      mutex_lock(&native_lab_service_lock);
      if (native_lab_service_active && !native_lab_service_active->abandoned &&
          native_lab_service_active->capsule->id == id) {
        capsule = native_lab_service_active->capsule;
        kref_get(&capsule->refs);
      }
      mutex_unlock(&native_lab_service_lock);
      return capsule;
    ''')
    job_release = recognize(trusted,'native_lab_job_release','''
      struct native_lab_trusted_job *job = container_of(ref, struct native_lab_trusted_job, refs);
      if (job->result) bpf_prog_put(job->result);
      native_lab_trusted_put(job->capsule);
      kfree(job);
    ''')
    release = recognize(trusted, 'native_lab_capsule_release', CAPSULE_RELEASE)
    binding = read('kinsn/module/include/native_lab_binding.h')
    names = ['MAP_POINTER', 'MAP_VALUE', 'HELPER_POINTER', 'READONLY_DATA']
    codes = [int(re.search(r'#define NATIVE_LAB_RELOC_'+n+r'\s+(\d+)U', binding)[1]) for n in names]
    if codes != [5, 6, 7, 8]: raise ValueError('relocation kind grammar changed')
    for name, value in [('EXCLUSIVE_FAILURE',9),('X86_TAIL_COUNT',10),('X86_TAIL_STACK',11)]:
        if not re.search(r'#define NATIVE_LAB_RELOC_'+name+r'\s+'+str(value)+r'U',binding):
            raise ValueError(f'{name}: source kind changed')
    for name, value in [('kNativeLabRelocHelperCallRel32',1),('kNativeLabRelocHelperCallArm64',2),
                        ('kNativeLabRelocHelperCallArm64Bl26',3),('kNativeLabRelocArm64PercpuMrs',4)]:
        if not re.search(r'constexpr uint32_t '+name+r' = '+str(value)+r';',loader):
            raise ValueError(f'{name}: source kind changed')
    structs = []
    receipts = [(group_path, 'native_lab_map_target', target),
                (group_path, 'native_lab_emit_literal', literal),
                (loader_path, 'chunk_reloc_bytes', chunk),
                (loader_path, 'bind_native_map_relocations', binder),
                (loader_path, 'native_lab_reloc_slot_bytes', slots),
                (trusted_path, 'native_lab_retain_program', retain),
                (trusted_path, 'native_lab_trusted_put', put),
                (trusted_path, 'native_lab_active_capsule', active),
                (trusted_path, 'native_lab_job_release', job_release),
                (trusted_path, 'native_lab_capsule_release', release)]
    for arch in ['x86', 'arm64']:
        path = f'kinsn/module/{arch}/bpf_{arch}_native_lab.c'
        text = read(path)
        record = re.search(r'struct native_lab_reloc_record\s*\{[^}]*\};', text)[0]
        if normalized(record) != normalized('struct native_lab_reloc_record { u32 offset, kind; u64 target; };'):
            raise ValueError(f'{arch}: record grammar changed')
        structs.append(record)
        if '#include "native_lab_group.h"' not in text:
            raise ValueError(f'{arch}: shared resolver include required')
        code = normalized(text)
        readonly_arm = normalized('case NATIVE_LAB_RELOC_READONLY_DATA: break;')
        if readonly_arm not in code: raise ValueError(f'{arch}: readonly emitter arm changed')
        labels = normalized('case NATIVE_LAB_RELOC_MAP_POINTER: case NATIVE_LAB_RELOC_MAP_VALUE: case NATIVE_LAB_RELOC_HELPER_POINTER:')
        if labels not in code: raise ValueError(f'{arch}: literal routing grammar changed')
        free = recognize(text, 'native_lab_free_blob', FREE_BLOB)
        receipts.append((path, 'native_lab_free_blob', free))
        # Exact source statements for the immutable copy and the shared route.
        for statement in [
          'blob->len = input.native_size;', 'blob->reloc_count = input.reloc_count;',
          'blob->bytes = vmemdup_user(u64_to_user_ptr(input.native_user), blob->len);',
          'blob->relocs = vmemdup_user(u64_to_user_ptr(input.relocs_user), array_size(blob->reloc_count, sizeof(*blob->relocs)));',
          'map = bpf_map_get_curr_or_next(&id);', 'blob->maps[blob->map_count++] = map;',
          'err = native_lab_retain_program(blob->capsule, prog);']:
            if normalized(statement) not in normalized(text):
                raise ValueError(f'{arch}: source operation changed: {statement}')
    x86_path = 'kprog/x86/native_lab/native_link/src/x86.rs'
    x86 = read(x86_path)
    data_object = recognize(x86,'x86_local_data_object',X86_DATA_OBJECT)
    receipts.append((x86_path,'x86_local_data_object',data_object))
    # Both native/proof PC32 branches call the same object selector with the
    # same ELF section, symbol address and declared size.
    object_call = normalized('''let (data_symbol_name, sym_bytes, data_offset) = x86_local_data_object(
      &target_name, target_section_idx, section_name, target_data,
      target_section.size(), sym_off_in_sec, target_sym.size())?;''')
    if normalized(x86).count(object_call) != 2:
        raise ValueError('shared native/proof object selector call grammar changed')
    rust_path = 'kprog/x86/native_lab/native_link/src/main.rs'
    rust = read(rust_path)
    record = re.search(r'pub struct RelocRecord\s*\{[^}]*\}', rust)[0]
    if normalized(record) != normalized('pub struct RelocRecord {offset: u32, kind: u32, target: u64,}'):
        raise ValueError('Rust record grammar changed')
    serialization = re.search(r'for r in &relocs\s*\{(.*?)\}', rust, re.S)[1]
    if normalized(serialization) != normalized('''
      buf.extend_from_slice(&r.offset.to_le_bytes());
      buf.extend_from_slice(&r.kind.to_le_bytes());
      buf.extend_from_slice(&r.target.to_le_bytes());'''):
        raise ValueError('Rust serializer grammar changed')
    receipts.append((rust_path, 'record serializer', serialization))
    core_path = 'vendor/linux-framework/kernel/bpf/core.c'
    core = read(core_path)
    free = body(core, '__bpf_prog_free')
    core_release = re.search(r'if \(fp->aux->native_trusted_put\)\s*\{(.*?)\}', free, re.S)[1]
    if normalized(core_release) != normalized('''
      fp->aux->native_trusted_put(fp->aux->native_trusted_request);
      module_put(fp->aux->native_trusted_owner);'''):
        raise ValueError('core release grammar changed')
    receipts.append((core_path, 'native_trusted_put before module_put', core_release))
    arm_path = 'vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c'
    arm_jit = read(arm_path)
    arm_copy = body(arm_jit,'emit_kinsn_desc_call_arm64')
    for operation in [
      'if (scratch_idx != n_insns || (size_t)n_insns > max_insns) { ret = -EFAULT; goto out; }',
      'if (ctx->image && ctx->write) { for (i = 0; i < n_insns; i++) ctx->image[ctx->idx + i] = cpu_to_le32(scratch[i]); }',
      'ctx->idx += n_insns;']:
        if normalized(operation) not in normalized(arm_copy):
            raise ValueError('ARM JIT word-copy operation changed')
    module_arm = read('kinsn/module/arm64/bpf_arm64_native_lab.c')
    for operation in [
      'for (i = 0; i < native_len; i += sizeof(u32)) image[start_idx + (i / sizeof(u32))] = get_unaligned_le32(native_bytes + i);',
      '*idx += native_len / sizeof(u32);']:
        if normalized(operation) not in normalized(module_arm):
            raise ValueError('ARM module word-copy operation changed')
    receipts.append((arm_path,'word-copy emitter source',arm_copy))
    jit_path = 'vendor/linux-framework/arch/x86/net/bpf_jit_comp.c'
    jit = read(jit_path)
    tail = recognize(jit, 'emit_bpf_tail_call_direct', TAIL_DIRECT)
    fixups = recognize(jit, 'bpf_tail_call_direct_fixup', TAIL_FIXUP)
    patch = recognize(jit, 'emit_patch', PATCH)
    recognize(jit, 'emit_jump', 'return emit_patch(pprog, func, ip, 0xE9);')
    patch_bytes = int(re.search(r'#define X86_PATCH_SIZE\s+(\d+)',jit)[1])
    if patch_bytes != 5: raise ValueError('x86 text-poke width grammar changed')
    prefix = tail[:tail.index('poke->tailcall_bypass')]
    prefix_widths = [int(n)+(4 if suffix else 0)
        for n,suffix in re.findall(r'EMIT([1-4])(_off32)?\(',prefix)]
    if prefix_widths != [7,4,2]: raise ValueError('tail prefix emitter grammar changed')
    receipts.extend([(jit_path,'emit_bpf_tail_call_direct',tail),
                     (jit_path,'bpf_tail_call_direct_fixup',fixups),
                     (jit_path,'emit_patch',patch)])
    # The compiler reports ABI field offsets from the actual extracted C record.
    scratch.mkdir(parents=True, exist_ok=True)
    source = scratch / 'record.c'
    source.write_text('typedef unsigned int u32; typedef unsigned long long u64;\n'+structs[0]+'\n')
    output = subprocess.run(['clang-18', '--target=x86_64-linux-gnu', '-Xclang',
      '-fdump-record-layouts-complete', '-fsyntax-only', str(source)], check=True,
      text=True, capture_output=True).stdout
    layout = re.search(r'0 \| struct native_lab_reloc_record\n(.*?\[sizeof=.*?\])', output, re.S)[1]
    offsets = [int(re.search(r'(\d+) \|\s+u(?:32|64) '+n, layout)[1]) for n in ['offset','kind','target']]
    size = int(re.search(r'sizeof=(\d+)', layout)[1])
    if (offsets,size) != ([0,4,8],16): raise ValueError('C record ABI changed')
    arm_output = subprocess.run(['clang-18','--target=aarch64-linux-gnu','-Xclang',
      '-fdump-record-layouts-complete','-fsyntax-only',str(source)],check=True,
      text=True,capture_output=True).stdout
    arm_layout = re.search(r'0 \| struct native_lab_reloc_record\n(.*?\[sizeof=.*?\])',arm_output,re.S)[1]
    if arm_layout != layout: raise ValueError('x86/ARM record ABI relation changed')
    generator_path = 'kprog/x86/micro-prog/generate_micro_sim_proofs.py'
    generator = read(generator_path)
    tree = ast.parse(generator)
    readonly = next(n for n in tree.body if isinstance(n,ast.FunctionDef) and n.name=='readonly_load_declarations')
    width_loop = next(n for n in ast.walk(readonly) if isinstance(n,ast.For) and
                      isinstance(n.target,ast.Name) and n.target.id=='width')
    widths = ast.literal_eval(width_loop.iter)
    if widths != (1,2,4,8): raise ValueError('readonly case width grammar changed')
    offset_loop = next(n for n in ast.walk(width_loop) if isinstance(n,ast.For) and
                       isinstance(n.target,ast.Name) and n.target.id=='offset')
    if ast.unparse(offset_loop.iter) != 'range(len(data) - width + 1)':
        raise ValueError('readonly offset case grammar changed')
    string_values=[n.value for n in ast.walk(readonly) if isinstance(n,ast.Constant) and isinstance(n.value,str)]
    for fragment in ['\t\t__u64 value = 0;', '\t\t__builtin_memcpy(&value, ', '\t\treturn value;']:
        if not any(fragment in x for x in string_values):
            raise ValueError(f'readonly copy template changed: {fragment!r}')
    receipts.append((generator_path,'readonly width and offset loops',ast.unparse(width_loop.iter)+';'+ast.unparse(offset_loop.iter)))
    for triple in receipts:
        print(f'{triple[0]}:{triple[1]} {hashlib.sha256(normalized(triple[2]).encode()).hexdigest()}')
    receipt_lines = '\n'.join('-- '+p+':'+n+' sha256='+hashlib.sha256(normalized(s).encode()).hexdigest()
                              for p,n,s in receipts)
    # The grammar above translates the branches in their actual source order.
    return f'''-- Generated by tools/extract_native_link_source.py.
{receipt_lines}
import KProgFormal.NativeLinkProducerImage
namespace KProgFormal.NativeLinkSource
open Reference NativeLinkProducer NativeLinkProducerImage

def mapPointer : BitVec 32 := {codes[0]}
def mapValue : BitVec 32 := {codes[1]}
def helperPointer : BitVec 32 := {codes[2]}
def readonlyData : BitVec 32 := {codes[3]}
def recordOffsets : List Nat := [{','.join(map(str,offsets))}]
def recordSize : Nat := {size}

structure Map where
  id : BitVec 32
  address : Word
  valueSize : BitVec 32
  directValue : Option (BitVec 32 → Option Word)

/-- Translation of the shared x86 native/proof object-byte selector. Successful
Rust integer conversions precede this value-level model. The section/object
identity strings follow the recognized routine's corresponding return arm. -/
def x86ObjectBytes (data : List Byte) (sectionSize offset size : Nat)
    (readonlySection unnamedBss : Bool) : Option (List Byte × Nat) :=
  if size ≠ 0 then
    if offset+size ≤ data.length then some ((data.drop offset).take size,0) else none
  else
    let bytes := if readonlySection then some data else
      if unnamedBss then some (List.replicate sectionSize (0 : Byte)) else none
    bytes.bind (fun data => if 0 < data.length ∧ offset ≤ data.length then
      some (data,offset) else none)

/-- Width and offset loops read from the actual Python generator AST. -/
def readonlyWidths : List Nat := [{','.join(map(str,widths))}]

def readonlyCases (length : Nat) : List (Nat × Nat) :=
  readonlyWidths.flatMap (fun width =>
    (List.range (length+1-width)).map (fun offset => (offset,width)))

/-- Successful per-site binder. The retained original symbol/map lookup
supplies id, object address and direct-value base from the same MapMeta. -/
def bindMapRecord (site : BitVec 32) (length : Nat) (identity : BitVec 32)
    (symbolAddress mapAddress valueAddress : Word) (valueSize : BitVec 32) : Option Record :=
  if site.toNat+8 ≤ length then
    if symbolAddress = mapAddress then some ⟨site,mapPointer,packTarget identity 0⟩ else
      if valueAddress ≠ 0 ∧ valueAddress.toNat ≤ symbolAddress.toNat ∧
          symbolAddress.toNat-valueAddress.toNat < valueSize.toNat then
        some ⟨site,mapValue,packTarget identity
          (BitVec.ofNat 32 (symbolAddress.toNat-valueAddress.toNat))⟩
      else none
  else none

/-- Complete successful/error branch translation of native_lab_map_target.
The direct-value API result is its offset-parameterized base. -/
def mapTarget (kind : BitVec 32) (target : Word) : List Map → Option Word
  | [] => none
  | m::rest =>
    if m.id != target.setWidth 32 then mapTarget kind target rest else
    if kind = mapPointer then
      if (target >>> 32).setWidth 32 = (0 : BitVec 32) then some m.address else none
    else
      if ((target >>> 32).setWidth 32 : BitVec 32).toNat < m.valueSize.toNat then
        match m.directValue with
        | none => none
        | some callback => (callback ((target >>> 32).setWidth 32)).map
            (fun base => base + (((target >>> 32).setWidth 32 : BitVec 32).zeroExtend 64))
      else none

/-- Complete translation of the bounds, helper/map branch and memcpy result.
The immutable blob argument is present in C and its value stays unobserved. -/
def emitLiteral (r : Record) (length : Nat) (destination : Image) (maps : List Map) : Option Image :=
  if r.offset.toNat + 8 ≤ length then
    let resolved := if r.kind = helperPointer then some r.target else mapTarget r.kind r.target maps
    resolved.map (fun target => copy destination r.offset.toNat (fromList (le64 target)) 0 8)
  else none

/-- The selected kernel switch arms. Other kinds retain their dedicated
transformation semantics; these functions describe the five/eight source arms. -/
def emitScopedRecord (r : Record) (length : Nat) (destination : Image) (maps : List Map) : Option Image :=
  if r.kind = readonlyData then some destination else
  if r.kind = mapPointer ∨ r.kind = mapValue ∨ r.kind = helperPointer then
    emitLiteral r length destination maps else none

def emitScopedRecords (length : Nat) (maps : List Map) : Image → List Record → Option Image
  | image, [] => some image
  | image, r::rest => (emitScopedRecord r length image maps).bind
      (fun next => emitScopedRecords length maps next rest)

/-- The Rust serializer's actual offset/kind/target LE field sequence. -/
def serialize (r : Record) : List Byte := le32 r.offset ++ le32 r.kind ++ le64 r.target

/-- Successful supported-kind arm sizes from native_lab_reloc_slot_bytes.
The C default terminates generation; its domain is explicit in callers. -/
def slotBytes (kind : BitVec 32) : Nat :=
  if kind = 1 then 5 else if kind = 2 then 16 else
  if kind = 3 ∨ kind = 4 ∨ kind = 9 ∨ kind = 10 ∨ kind = 11 then 4 else
  if kind = 8 then 1 else 8

/-- The loader selects complete slots and appends localized records in input order. -/
def slotSelected (chunk : Chunk) (r : Record) : Prop :=
  chunk.start ≤ r.offset.toNat ∧ r.offset.toNat + slotBytes r.kind ≤ chunk.start + chunk.size

instance (chunk : Chunk) (r : Record) : Decidable (slotSelected chunk r) :=
  inferInstanceAs (Decidable (_ ∧ _))

def chunkRecords (chunk : Chunk) (records : List Record) : List Record :=
  (records.filter (fun r => decide (slotSelected chunk r))).map (localize chunk)

def chunkWire (chunk : Chunk) (records : List Record) : List Byte :=
  (chunkRecords chunk records).flatMap serialize

/-- The module reads an unaligned little-endian u32 into scratch; the ARM
JIT stores that scratch word through cpu_to_le32. Complete aligned chunks
consist of these four-byte groups. -/
def armWordBytes (source : Image) (start : Nat) : List Byte :=
  le32 (littleEndian 32 [source start,source (start+1),source (start+2),source (start+3)])

def armCopiedByte (source : Image) (start i : Nat) : Byte :=
  fromList (armWordBytes source (start+i/4*4)) (i%4)

def armCopyImage (destination source : Image) (destinationAt sourceAt words : Nat) : Image :=
  copy destination destinationAt (armCopiedByte source sourceAt) 0 (words*4)

/-- Macro byte widths and descriptor placement extracted from the complete tail
emitter and finalizer. Dynamic callee-pop/stack-add widths are nonnegative
append-only emitter results; the accepted final JIT pass supplies its label. -/
def tailPrefix : Nat := {'+'.join(map(str,prefix_widths))}
def textPatchBytes : Nat := {patch_bytes}
def tailSize (calleeBytes stackBytes : Nat) : Nat :=
  tailPrefix + textPatchBytes + 4 + calleeBytes + 2 + stackBytes + textPatchBytes

def tailRegion (calleeBytes stackBytes : Nat) : Region :=
  ⟨tailSize calleeBytes stackBytes, false⟩

def tailWrites (start calleeBytes stackBytes : Nat) (target bypass : List Byte) : List Fixup :=
  [⟨start + tailSize calleeBytes stackBytes - textPatchBytes, target⟩,
   ⟨start + tailPrefix, bypass⟩]
end KProgFormal.NativeLinkSource
'''


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--check', action='store_true')
    parser.add_argument('--root', type=Path, default=REPO)
    parser.add_argument('--scratch', type=Path, default=Path('/var/tmp/kprog-tmp/S12/extraction'))
    args = parser.parse_args()
    expected = extract(args.root, args.scratch)
    if args.check:
        if OUTPUT.read_text() != expected: raise SystemExit('native link source extraction requires regeneration')
    else:
        OUTPUT.write_text(expected)
    print('native link source extraction: PASS')

if __name__ == '__main__': main()
