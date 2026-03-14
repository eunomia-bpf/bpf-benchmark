# llvmbpf Map Handling and Parallel Execution Analysis

Date: March 11, 2026

Scope:
- Project code under `vendor/llvmbpf/`, `micro/`, and the archived runtime programs.
- Upstream Linux kernel source for host-kernel-adjacent behavior.
- Host kernel observed locally: `Linux 6.15.11-061511-generic`.

This note separates three questions that are easy to conflate:
- pure codegen quality
- helper/runtime mechanism cost
- shared-state/concurrency behavior

That separation matters because the active micro suite is intentionally pure-JIT, while most interesting map questions are runtime questions.

## 1. Relevant code locations

### llvmbpf core

- `vendor/llvmbpf/include/llvmbpf.hpp`
  - public VM API: external helper registration plus `set_lddw_helpers()`
- `vendor/llvmbpf/src/vm.cpp`
  - VM wrapper around load/compile/exec
- `vendor/llvmbpf/src/llvm_jit_context.cpp`
  - ORC JIT setup and module compilation policy
- `vendor/llvmbpf/src/compiler.cpp`
  - eBPF-to-LLVM lowering, including pseudo-`LDDW` map handling
- `vendor/llvmbpf/src/compiler_utils.cpp`
  - helper call lowering and atomic op helpers

### Benchmark harness

- `micro/programs/common.h`
  - active benchmark macros, including the still-defined map-backed XDP macro
- `config/micro_pure_jit.yaml`
  - current active suite manifest
- `micro/runner/src/kernel_runner.cpp`
  - kernel load/test_run path
- `micro/runner/src/llvmbpf_runner.cpp`
  - llvmbpf runtime path plus userspace map emulation
- `micro/runner/src/elf_program_loader.cpp`
  - object parsing and map metadata extraction

### Archived runtime benchmarks

- `micro/programs/archive/runtime/*.bpf.c`
  - previous map/helper/atomic runtime cases removed from the active pure-JIT suite

## 2. Part 1: llvmbpf array map implementation

## 2.1 High-level conclusion

`llvmbpf` is a JIT/compiler core, not a full map runtime. The README states this directly:

```text
This library ... does not include maps implement, helpers, verifiers, or loaders
for eBPF applications.
```

Source:
- `vendor/llvmbpf/README.md:19`

That leads to two distinct map paths:

1. Helper-based map access
   - `bpf_map_lookup_elem`, `bpf_map_update_elem`, etc.
   - implemented as externally registered host functions
   - lowered as normal function calls

2. Direct map-value/global access via pseudo `LDDW`
   - implemented through `set_lddw_helpers(map_by_fd, map_by_idx, map_val, ...)`
   - lowered either as compile-time relocation or as a call to `map_val`, depending on compilation mode

## 2.2 Helper-based array map lookup in llvmbpf

The public API exposes external helper registration:

```cpp
int register_external_function(size_t index, const std::string &name, void *fn) noexcept;
void set_lddw_helpers(uint64_t (*map_by_fd)(uint32_t),
                      uint64_t (*map_by_idx)(uint32_t),
                      uint64_t (*map_val)(uint64_t),
                      uint64_t (*var_addr)(uint32_t),
                      uint64_t (*code_addr)(uint32_t)) noexcept;
```

Source:
- `vendor/llvmbpf/include/llvmbpf.hpp:40`
- `vendor/llvmbpf/include/llvmbpf.hpp:94`

The example map program shows the intended model. The host provides the map helper:

```cpp
void *bpf_map_lookup_elem(uint64_t map_fd, void *key)
{
    if (map_fd == 5) {
        return &ctl_array[*(uint32_t *)key];
    } else if (map_fd == 6) {
        return &cntrs_array[*(uint32_t *)key];
    }
    return nullptr;
}

vm.register_external_function(1, "bpf_map_lookup_elem", (void *)bpf_map_lookup_elem);
vm.set_lddw_helpers(map_by_fd, nullptr, map_val, nullptr, nullptr);
```

Source:
- `vendor/llvmbpf/example/maps.cpp:58`
- `vendor/llvmbpf/example/maps.cpp:102`

Lowering confirms that helper calls are emitted as external calls, not special-cased inline expansions:

```cpp
auto callInst = builder.CreateCall(
    helperFuncTy, itr->second,
    {
        builder.CreateLoad(builder.getInt64Ty(), regs[1]),
        builder.CreateLoad(builder.getInt64Ty(), regs[2]),
        builder.CreateLoad(builder.getInt64Ty(), regs[3]),
        builder.CreateLoad(builder.getInt64Ty(), regs[4]),
        builder.CreateLoad(builder.getInt64Ty(), regs[5]),
    });
builder.CreateStore(callInst, regs[0]);
```

Source:
- `vendor/llvmbpf/src/compiler_utils.cpp:318`

And the main instruction lowering path routes non-local `CALL` instructions to that helper emission:

```cpp
case EBPF_OP_CALL:
case EBPF_OP_CALL | 0x8:
    ...
    if (auto exp = emitExtFuncCall(...); !exp) {
        return exp.takeError();
    }
```

Source:
- `vendor/llvmbpf/src/compiler.cpp:1058`

### Answer

For `bpf_map_lookup_elem` on array maps, llvmbpf does not implement a built-in array-map fast path in the JIT. It emits a normal external helper call and expects the embedding runtime to implement the map semantics.

## 2.3 Direct array/global map access in llvmbpf

llvmbpf also handles map/data relocation-style accesses through pseudo `LDDW` helpers. The key API contract is:

```cpp
// If the code involve array map access, the map_val function needs to be provided.
```

Source:
- `vendor/llvmbpf/include/llvmbpf.hpp:89`

The lowering for pseudo `LDDW` source kinds `2` and `6` (`map_by_fd + map_val`, `map_by_idx + map_val`) is explicit:

```cpp
if (patch_map_val_at_compile_time) {
    builder.CreateStore(
        builder.getInt64(vm.map_val(mapPtr) + nextinst.imm),
        regs[inst.dst]);
} else {
    auto retMapVal = builder.CreateCall(lddwHelperWithUint64, itrMapVal->second,
                                        { builder.getInt64(mapPtr) });
    auto finalRet = builder.CreateAdd(retMapVal, builder.getInt64(nextinst.imm));
    builder.CreateStore(finalRet, regs[inst.dst]);
}
```

Source:
- `vendor/llvmbpf/src/compiler.cpp:877`
- `vendor/llvmbpf/src/compiler.cpp:899`
- `vendor/llvmbpf/src/compiler.cpp:984`
- `vendor/llvmbpf/src/compiler.cpp:1009`

For normal JIT compilation, `patch_map_val_at_compile_time` is set to `true`:

```cpp
auto bpfModuleOrErr = generateModule(extFuncNames, definedLddwHelpers, true);
```

Source:
- `vendor/llvmbpf/src/llvm_jit_context.cpp:319`

The JIT setup also states that only `map_val` may remain as a runtime symbol, because other relocations are expected to be resolved already:

```cpp
// Only map_val will have a chance to be called at runtime, so it's the only symbol to be defined
tryDefineLddwHelper(LDDW_HELPER_MAP_VAL, (void *)vm.map_val);
```

Source:
- `vendor/llvmbpf/src/llvm_jit_context.cpp:632`

Unit tests make the dependency visible: compilation fails without `map_val` when such relocation is present.

Source:
- `vendor/llvmbpf/test/unit-test/vm_test.cpp:332`

### Answer

For direct array/global map access via pseudo `LDDW`, llvmbpf JIT normally patches the map value address at compile time. That path is closer to inlined direct memory access. The non-inlined function-call behavior applies to helper-based map operations like `bpf_map_lookup_elem`.

## 2.4 What map types does llvmbpf support?

### llvmbpf core

Direct fact:
- llvmbpf core has no built-in map runtime.
- It supports generic helper calls and pseudo-`LDDW` relocation hooks.

Inference:
- The core can only support a map type if the embedding runtime implements the helper semantics or relocation callbacks for it.
- There is no internal llvmbpf map-type-specific specialization comparable to the kernel’s `struct bpf_map_ops`.

### This project’s llvmbpf runner

The runner emulates only three map kinds:

```cpp
if (spec.type == kMapTypeArray || spec.type == kMapTypePercpuArray) {
    map.storage.assign(value_size * max_entries, 0);
} else if (spec.type == kMapTypeHash) {
    map.hash_storage.reserve(spec.max_entries);
} else {
    fail("unsupported llvmbpf map type");
}
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:584`

Lookup/update helpers also only understand array, percpu-array, and hash:

```cpp
if (map->spec.type == kMapTypeArray || map->spec.type == kMapTypePercpuArray) ...
if (map->spec.type == kMapTypeHash) ...
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:343`
- `micro/runner/src/llvmbpf_runner.cpp:368`

The loader metadata does not carry any inner-map description:

```cpp
struct map_spec {
    uint32_t id;
    std::string name;
    uint32_t type;
    uint32_t key_size;
    uint32_t value_size;
    uint32_t max_entries;
};
```

Source:
- `micro/runner/include/micro_exec.hpp:12`

### Answer

In this repository:
- array maps: yes
- hash maps: yes, in the llvmbpf runner’s helper emulation
- per-CPU array maps: superficially yes, but not with real per-CPU semantics
- map-in-map: no meaningful support in the current runner/harness
- prog array / fd array / array-of-maps / other kernel-native special cases: not supported by the current llvmbpf runner

## 3. Kernel handling of `bpf_map_lookup_elem` for array maps

## 3.1 Array-map lookup implementation

Upstream kernel array-map lookup is just indexed pointer arithmetic:

```c
static void *array_map_lookup_elem(struct bpf_map *map, void *key)
{
    struct bpf_array *array = container_of(map, struct bpf_array, map);
    u32 index = *(u32 *)key;

    if (unlikely(index >= array->map.max_entries))
        return NULL;

    return array->value + (u64)array->elem_size * (index & array->index_mask);
}
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:166`

The important detail is not just the C helper; it is the specialization hook:

```c
const struct bpf_map_ops array_map_ops = {
    ...
    .map_lookup_elem = array_map_lookup_elem,
    .map_gen_lookup = array_map_gen_lookup,
    ...
};
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:785`

`array_map_gen_lookup()` emits inline BPF instructions equivalent to the helper:

```c
*insn++ = BPF_ALU64_IMM(BPF_ADD, map_ptr, offsetof(struct bpf_array, value));
*insn++ = BPF_LDX_MEM(BPF_W, ret, index, 0);
*insn++ = BPF_JMP_IMM(BPF_JGE, ret, map->max_entries, ...);
...
*insn++ = BPF_ALU64_REG(BPF_ADD, ret, map_ptr);
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:207`

## 3.2 Is kernel array lookup inlined?

Yes, on 64-bit JITed programs when `map_gen_lookup` is available.

The verifier patches the `BPF_FUNC_map_lookup_elem` call site before final JIT:

```c
if (prog->jit_requested && BITS_PER_LONG == 64 &&
    insn->imm == BPF_FUNC_map_lookup_elem) {
    ...
    if (ops->map_gen_lookup) {
        cnt = ops->map_gen_lookup(map_ptr, insn_buf);
        ...
        new_prog = bpf_patch_insn_data(..., insn_buf, cnt);
        ...
    }
}
```

Source:
- Linux v6.15.11 `kernel/bpf/verifier.c:22082`

If a map type does not provide `map_gen_lookup`, the verifier falls back to patching the helper to a direct map-op call:

```c
case BPF_FUNC_map_lookup_elem:
    insn->imm = BPF_CALL_IMM(ops->map_lookup_elem);
```

Source:
- Linux v6.15.11 `kernel/bpf/verifier.c:22143`

On x86, a remaining `BPF_CALL` becomes a real machine call:

```c
case BPF_JMP | BPF_CALL:
    func = (u8 *) __bpf_call_base + imm32;
    ...
    if (emit_call(&prog, func, ip))
        return -EINVAL;
```

Source:
- Linux v6.15.11 `arch/x86/net/bpf_jit_comp.c:2309`

### Answer

Kernel array-map lookup is not handled as a generic helper call in the final JITed program. For array maps, it is typically inlined by `map_gen_lookup` into straight-line address computation and bounds checking before arch JIT runs.

## 3.3 Kernel per-CPU arrays and map-in-map support

Per-CPU array lookup has its own real per-CPU implementation:

```c
static void *percpu_array_map_lookup_elem(struct bpf_map *map, void *key)
{
    ...
    return this_cpu_ptr(array->pptrs[index & array->index_mask]);
}
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:241`

And the JIT specialization exists for it too:

```c
.map_lookup_elem = percpu_array_map_lookup_elem,
.map_gen_lookup = percpu_array_map_gen_lookup,
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:810`

Kernel array-of-maps support is also explicit:

```c
const struct bpf_map_ops array_of_maps_map_ops = {
    ...
    .map_lookup_elem = array_of_map_lookup_elem,
    .map_gen_lookup = array_of_map_gen_lookup,
    ...
};
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:1425`

### Answer

The kernel supports:
- plain arrays
- per-CPU arrays
- fd arrays / prog arrays / perf-event arrays / cgroup arrays
- array-of-maps

The current llvmbpf benchmark path does not come close to that coverage.

## 4. Performance implications

## 4.1 llvmbpf helper path vs kernel array fast path

For repeated array-map helper lookups, the expected cost structure is:

- llvmbpf helper path
  - external native function call
  - helper dispatch in the embedding runtime
  - key copy from guest memory
  - map-type switch / container lookup in userspace

- kernel array fast path
  - verifier inserts a few BPF instructions
  - arch JIT turns those into straight-line native code
  - no helper call/return for the array lookup itself

Inference from source:
- The gap should be large when lookup dominates the hot path.
- The gap should shrink substantially when the BPF program uses direct map-value/global access rather than helper lookup, because llvmbpf then patches `map_val` at compile time.

## 4.2 Current llvmbpf runner adds extra runtime overhead beyond llvmbpf core

The repository’s llvmbpf runner does not benchmark kernel-like map internals. It benchmarks a userspace emulation layer:

```cpp
thread_local userspace_map_state *active_map_state = nullptr;

uint64_t helper_bpf_map_lookup_elem(...) {
    auto *map = lookup_map(map_id);
    auto *slot = lookup_slot(map, key_ptr);
    return reinterpret_cast<uint64_t>(slot);
}
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:329`
- `micro/runner/src/llvmbpf_runner.cpp:400`

So even if llvmbpf JITed code is fast, map benchmarks in this harness measure:
- helper call overhead
- userspace map emulation overhead
- not just llvmbpf code generation quality

That is exactly why the old runtime suite was archived.

## 4.3 Direct-map-value benchmarks are currently blocked in this harness

The loader currently only rewrites relocations to `BPF_PSEUDO_MAP_FD`:

```cpp
insns[*insn_index].src_reg = BPF_PSEUDO_MAP_FD;
insns[*insn_index].imm = static_cast<int32_t>(map_iter->second);
```

Source:
- `micro/runner/src/elf_program_loader.cpp:493`

I did not find support for `BPF_PSEUDO_MAP_VALUE` relocation in the runner pipeline. That means a benchmark intended to isolate llvmbpf’s compile-time `map_val` path would require loader/runner work first.

## 5. Part 2: parallel/concurrent execution analysis

## 5.1 Scenario 1: multiple BPF programs sharing an array map

### Kernel

Plain array maps are preallocated contiguous storage. Lookup is direct pointer return; update is direct copy:

```c
val = array->value + (u64)array->elem_size * (index & array->index_mask);
if (map_flags & BPF_F_LOCK)
    copy_map_value_locked(map, val, value, false);
else
    copy_map_value(map, val, value);
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:345`

Implications:
- lookup itself is lock-free
- update is lock-free unless the caller uses `BPF_F_LOCK`
- concurrent readers/writers on the same entry are ordinary shared-memory races unless the program uses BPF atomics or a map spin lock

### llvmbpf runner

The llvmbpf helper emulation uses raw `memcpy` into contiguous storage and ignores flags:

```cpp
auto *slot = map->storage.data() + key * value_size;
std::memcpy(slot, reinterpret_cast<const void *>(value_ptr), map->spec.value_size);
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:376`

Implications:
- no map lock
- no `BPF_F_LOCK` behavior
- no kernel-like synchronization semantics

### Current harness limitation

Neither runtime currently shares maps across benchmark invocations:
- kernel runner creates fresh maps per invocation
- llvmbpf runner builds a fresh `userspace_map_state` per invocation

Sources:
- `micro/runner/src/kernel_runner.cpp:645`
- `micro/runner/src/llvmbpf_runner.cpp:584`

So the current harness cannot expose shared-map contention without new infrastructure.

## 5.2 Scenario 2: per-CPU array maps

### Kernel

Kernel per-CPU arrays are real per-CPU storage:

```c
return this_cpu_ptr(array->pptrs[index & array->index_mask]);
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:249`

### llvmbpf runner

The llvmbpf runner treats `BPF_MAP_TYPE_PERCPU_ARRAY` the same as a plain array:

```cpp
if (map->spec.type == kMapTypeArray || map->spec.type == kMapTypePercpuArray) {
    return map->storage.data() + key * value_size;
}
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:351`

This is a semantic mismatch, not a small implementation detail.

### Important `BPF_PROG_TEST_RUN` detail

Kernel test-run timing uses `NO_MIGRATE`:

```c
if (t->mode == NO_PREEMPT)
    preempt_disable();
else
    migrate_disable();
```

Source:
- Linux v6.15.11 `net/bpf/test_run.c:37`

And the common `bpf_test_run()` path uses:

```c
struct bpf_test_timer t = { NO_MIGRATE };
```

Source:
- Linux v6.15.11 `net/bpf/test_run.c:400`

Implication:
- repeated iterations inside one `bpf_prog_test_run_opts(..., repeat=N)` stay on one CPU
- so one test-run syscall does not meaningfully exercise cross-CPU per-CPU behavior

If per-CPU semantics matter, the benchmark must use multiple concurrent callers pinned to different CPUs, not just a large `repeat`.

## 5.3 Scenario 3: parallel `BPF_PROG_TEST_RUN`

The syscall entry itself is simple:

```c
prog = bpf_prog_get(attr->test.prog_fd);
if (prog->aux->ops->test_run)
    ret = prog->aux->ops->test_run(prog, attr, uattr);
```

Source:
- Linux v6.15.11 `kernel/bpf/syscall.c:4405`

`net/bpf/test_run.c` does not show a global serialization lock around independent test runs.

Inference:
- multiple threads/processes can issue `BPF_PROG_TEST_RUN` concurrently
- the kernel can execute them on different CPUs
- each individual caller is migration-disabled during its timed loop, but separate callers are not globally serialized

### Current project behavior

The current Python driver is sequential:

```python
completed = subprocess.run(full_command, capture_output=True, text=True)
...
for benchmark in benchmarks:
    ...
    for runtime in ordered:
        sample = parse_runner_sample(run_command(...).stdout)
```

Source:
- `micro/_driver_impl_run_micro.py:113`
- `micro/_driver_impl_run_micro.py:333`

So the project does not currently test parallel kernel execution at all.

## 5.4 Scenario 4: lock contention

### Kernel array maps

Plain array lookup: no lock on the fast path.

Plain array update:
- no global map lock
- optional locked copy via `BPF_F_LOCK`
- BPF atomics operate on the returned value pointer

### llvmbpf

Core llvmbpf:
- compilation uses a spin lock around compilation only
- this is not a map-access lock

Source:
- `vendor/llvmbpf/src/llvm_jit_context.cpp:187`
- `vendor/llvmbpf/src/llvm_jit_context.cpp:308`

Runner map emulation:
- no locking around lookup/update
- update helper ignores flags

Source:
- `micro/runner/src/llvmbpf_runner.cpp:368`
- `micro/runner/src/llvmbpf_runner.cpp:412`

Implication:
- a benchmark based on `BPF_F_LOCK` or map spin-lock semantics would currently be kernel-only or semantically incomparable

## 5.5 Scenario 5: cache effects and false sharing

### Kernel

Array values are rounded to 8-byte alignment, not cacheline alignment:

```c
elem_size = round_up(attr->value_size, 8);
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:92`

Values are stored contiguously:

```c
return array->value + (u64)array->elem_size * (index & array->index_mask);
```

Source:
- Linux v6.15.11 `kernel/bpf/arraymap.c:174`

Implication:
- adjacent hot counters can share a cache line
- multi-CPU updates to neighboring indices can suffer false sharing
- per-CPU arrays avoid that cross-CPU contention for the common case

### llvmbpf runner

The userspace map emulation also uses a contiguous byte vector for arrays and fake per-CPU arrays:

```cpp
map.storage.assign(value_size * max_entries, 0);
```

Source:
- `micro/runner/src/llvmbpf_runner.cpp:590`

Implication:
- the same false-sharing pattern will appear if shared-state concurrent execution is added
- but current fake per-CPU arrays will incorrectly retain false sharing that the kernel avoids

## 6. Part 3: micro benchmark gap analysis

## 6.1 Why the active suite does not answer these questions

The active suite is explicitly pure-JIT:

- `micro/README.md:3`
- `config/micro_pure_jit.yaml:1`

The map-backed XDP macro still exists:
- `micro/programs/common.h:198`

But for TC and cgroup_skb, the “map-backed” macros are currently aliases to staged packet-backed macros:
- `micro/programs/common.h:256`
- `micro/programs/common.h:284`

But the active manifest does not exercise `io_mode: map`:
- `config/micro_pure_jit.yaml`

And even when kernel `io_mode: map` is used, the runner accounts map setup and result extraction outside the timed `bpf_prog_test_run_opts()` call:
- `micro/runner/src/kernel_runner.cpp:1196`
- `micro/runner/src/kernel_runner.cpp:1303`
- `micro/runner/src/kernel_runner.cpp:1335`

And the archived runtime README states why those cases were removed:

```text
they measure map lookup or helper-call runtime mechanisms rather than pure JIT code
generation quality, and llvmbpf/kernel do not implement those paths in a directly
comparable way.
```

Source:
- `micro/programs/archive/runtime/README.md:1`

That rationale is correct. The right fix is not to force them back into `micro_pure_jit`, but to restore them in a separate runtime-oriented suite.

## 6.2 Concrete benchmark proposals

### Proposal matrix

| Benchmark | What it measures | Implementation notes | Difficulty | Expected signal |
| --- | --- | --- | --- | --- |
| `array_lookup_repeat` | helper-based array lookup hot-path cost | revive archived `map_lookup_repeat.bpf.c` | Low | High |
| `map_roundtrip` | update + lookup roundtrip on one array entry | revive archived `map_roundtrip.bpf.c` | Low | High |
| `helper_call_1/10/100` | generic helper call overhead independent of maps | revive archived helper-call cases | Low | High |
| `atomic_counter_xadd` | map lookup + shared atomic RMW | revive archived `atomic_counter_xadd.bpf.c` | Low | High |
| `atomic_counter_cmpxchg` | CAS-loop behavior on shared map values | new benchmark using `cmpxchg` | Medium | High |
| `percpu_lookup_repeat` | kernel real per-CPU lookup vs llvmbpf fake per-CPU lookup | new benchmark, same structure as `array_lookup_repeat` but `PERCPU_ARRAY` | Medium | High |
| `percpu_map_update` | per-CPU update semantics and cost | archived program exists, but needs concurrent harness to expose semantics clearly | Medium | Medium |
| `hash_lookup_repeat` | non-inline map lookup cost | revive archived `hash_map_lookup.bpf.c` | Low | Medium |
| `parallel_shared_array_xadd_same_key` | true contention on one hot counter | requires parallel/shared-map harness | High | Very High |
| `parallel_shared_array_xadd_false_sharing` | packed vs padded counter layout across CPUs | requires shared maps and CPU pinning | High | Very High |
| `parallel_percpu_array_update` | scalability benefit of real per-CPU storage | kernel meaningful; llvmbpf currently shows semantic mismatch | High | Very High |
| `direct_map_value_repeat` | llvmbpf compile-time `map_val` relocation vs helper path | requires loader support for `BPF_PSEUDO_MAP_VALUE` and llvmbpf runner wiring `set_lddw_helpers()` | High | High |

## 6.3 Best immediate additions

### Tier 1: add first

These have the best value/effort ratio and directly answer the current question.

1. `array_lookup_repeat`
   - resurrect the archived benchmark
   - this is the most direct test of the helper-call-vs-inline question
   - expected outcome: kernel should materially outperform llvmbpf on helper-based array lookup hot paths

2. `map_roundtrip`
   - captures lookup plus update runtime cost
   - exposes llvmbpf userspace helper overhead more strongly than lookup-only cases

3. `helper_call_1/10/100`
   - gives a decomposition baseline
   - if `array_lookup_repeat` is much slower on llvmbpf, these cases help attribute how much is generic helper-call overhead versus map logic

4. `atomic_counter_xadd`
   - directly exercises shared-state atomics that the current pure-JIT suite entirely misses
   - both kernel and llvmbpf support BPF atomic instructions, so this is a useful divergence probe

### Tier 2: add next

5. `percpu_lookup_repeat`
   - high-value because it will reveal a real semantic mismatch in the llvmbpf runner
   - should live in a runtime suite, not the pure-JIT suite

6. `atomic_counter_cmpxchg`
   - complements `xadd`
   - useful if you care about lock-free update patterns, retry loops, and memory-order-sensitive workloads

### Tier 3: add only with harness work

7. `parallel_shared_array_xadd_same_key`
8. `parallel_shared_array_xadd_false_sharing`
9. `parallel_percpu_array_update`

These are probably the most interesting long-term, but they require infrastructure that the project does not currently have.

## 6.4 Benchmarks I would defer

### Map-in-map benchmarks

Defer for now.

Reasons:
- current `map_spec` has no inner-map metadata
- current llvmbpf runner does not support map-in-map
- current kernel runner create/reuse path also lacks the extra setup needed for inner maps

This is high effort and lower priority than array/per-CPU/atomic coverage.

### Spin-lock / `BPF_F_LOCK` benchmarks

Defer until llvmbpf runner semantics are improved.

Reason:
- kernel array-map update honors `BPF_F_LOCK`
- llvmbpf runner ignores helper flags and does raw `memcpy`

That would currently compare a real locking path to a non-locking userspace emulation path.

## 7. Recommendation

## 7.1 Keep `micro_pure_jit` unchanged

Do not mix runtime-map benchmarks back into `config/micro_pure_jit.yaml`.

The current suite is coherent: it isolates code generation. Adding helper-heavy map cases would pollute that signal.

## 7.2 Add a separate runtime characterization suite

Recommended new suite shape:

- `config/runtime_characterization.yaml`
  - map/helper/atomic benchmarks
  - explicit statement that these measure runtime mechanisms, not pure JIT codegen

- `single-thread` subgroup
  - `array_lookup_repeat`
  - `map_roundtrip`
  - `helper_call_1/10/100`
  - `atomic_counter_xadd`
  - `atomic_counter_cmpxchg`
  - `percpu_lookup_repeat`

- `parallel` subgroup
  - shared-map throughput/latency
  - same-key contention
  - false-sharing packed-vs-padded layouts
  - per-CPU scaling tests

## 7.3 Minimal high-value plan

If the goal is to learn the most with the least work:

1. Restore `array_lookup_repeat`, `map_roundtrip`, `helper_call_1/10/100`, and `atomic_counter_xadd` into a new runtime suite.
2. Add one new `percpu_lookup_repeat` case.
3. Build a small parallel harness next, specifically for shared-map contention and false-sharing studies.

## 7.4 Parallel harness design note

For meaningful parallel runtime benchmarks, do not rely on `test_opts.repeat` alone.

Use:
- multiple workers
- CPU pinning per worker
- shared maps across workers
- outer wall-clock throughput and latency metrics

Reason:
- one kernel `BPF_PROG_TEST_RUN` call is migration-disabled and effectively stays on one CPU during its timed repeat loop
- that hides the inter-CPU effects you actually want to study

## 8. Bottom line

- Helper-based array-map lookup is a major divergence point.
  - llvmbpf: external helper call
  - kernel: specialized inline path for array maps when JITed

- Direct map-value/global access is a different story.
  - llvmbpf JIT usually resolves `map_val` at compile time
  - that path is much closer to direct memory access
  - but the current benchmark harness does not expose it

- Per-CPU behavior is currently mis-modeled on the llvmbpf side.
  - the runner accepts `PERCPU_ARRAY`
  - but implements it as a normal shared array

- The current pure-JIT suite is not the right place for these benchmarks.
  - a separate runtime characterization suite is warranted

- The highest-value additions are:
  - `array_lookup_repeat`
  - `map_roundtrip`
  - `helper_call_1/10/100`
  - `atomic_counter_xadd`
  - then `percpu_lookup_repeat`

## 9. Source list

Repository sources:
- `vendor/llvmbpf/include/llvmbpf.hpp`
- `vendor/llvmbpf/src/compiler.cpp`
- `vendor/llvmbpf/src/compiler_utils.cpp`
- `vendor/llvmbpf/src/llvm_jit_context.cpp`
- `vendor/llvmbpf/example/maps.cpp`
- `vendor/llvmbpf/test/unit-test/vm_test.cpp`
- `micro/programs/common.h`
- `config/micro_pure_jit.yaml`
- `micro/runner/include/micro_exec.hpp`
- `micro/runner/src/kernel_runner.cpp`
- `micro/runner/src/llvmbpf_runner.cpp`
- `micro/runner/src/elf_program_loader.cpp`
- `micro/programs/archive/runtime/*.bpf.c`

Upstream kernel sources used:
- Linux v6.15.11 `kernel/bpf/arraymap.c`
- Linux v6.15.11 `kernel/bpf/verifier.c`
- Linux v6.15.11 `kernel/bpf/syscall.c`
- Linux v6.15.11 `net/bpf/test_run.c`
- Linux v6.15.11 `arch/x86/net/bpf_jit_comp.c`

Upstream kernel URLs:
- `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/plain/kernel/bpf/arraymap.c?h=v6.15.11`
- `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/plain/kernel/bpf/verifier.c?h=v6.15.11`
- `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/plain/kernel/bpf/syscall.c?h=v6.15.11`
- `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/plain/net/bpf/test_run.c?h=v6.15.11`
- `https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/plain/arch/x86/net/bpf_jit_comp.c?h=v6.15.11`
