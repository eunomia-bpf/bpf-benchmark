# OTel request 14: `custom__generic` binds its tail call to a prog array its own program does not use (OMP 2026-11-26T01:20Z)

Request 14 of the OTel checked pass (`source_prog_id` 111, `custom__generic`, prog type 2) fails with

```
trusted-native-loader: service simulator verification failed before native compilation: Invalid argument
processed 5717 insns (limit 1000000) max_states_per_insn 4 total_states 222 peak_states 222 mark_read 0
```

The verifier log is complete and clean, and the failure is `-EINVAL` from `bpf_check_tail_call`, after the
program has verified and after the JIT. The map the kernel refuses is `perf_progs`: an array of ten
perf_event programs, while the program being loaded is a kprobe.

## 1. Kernel rule, line by line

`__bpf_prog_map_compatible` (`vendor/linux-framework/kernel/bpf/core.c:2421-2485`) fixes a prog array's owner
at the first program that names it (`:2435-2450`) and from then on requires every other program that names it to
agree on `resolve_prog_type(fp)` (`:2452-2455`), `jited`, `xdp_has_frags`, `sleepable`, and, for
`BPF_MAP_TYPE_PROG_ARRAY`, `expected_attach_type` (`:2456-2458`). `attach_func_proto` alone is compared only
for TRACING/LSM/EXT/STRUCT_OPS (`:2468-2476`).

`bpf_check_tail_call` (`core.c:2500-2521`) walks `aux->used_maps` and returns a bare `-EINVAL` on the first
`map_type_contains_progs` map that is not compatible. It writes nothing to the verifier log, which is exactly
what the two stderr texts above show: a full log plus a bare `Invalid argument`.

The call site is `core.c:2607`, inside `bpf_prog_select_runtime`, after `finalize:` and after
`bpf_prog_lock_ro` (`:2597-2598`) — i.e. after the JIT has already produced the image. The owner is not
released when the owning program closes: `map->owner` is freed only in `bpf_map_free_deferred`
(`kernel/bpf/syscall.c:919`). And because `prog_fd_array_get_ptr` (`kernel/bpf/arraymap.c:973`) applies the
same rule to a `MAP_UPDATE_ELEM` from the application, the owner is fixed by whoever first inserts a program.

Every fd in `fd_array` becomes a used map whether or not the program references it: `process_fd_array`
(`kernel/bpf/verifier.c:25453-25487`) returns early at `:25467` only when `fd_array_cnt == 0`, and otherwise
calls `add_fd_from_fd_array` (`:25424-25441`) on each entry, which is `__add_used_map`
(`verifier.c:21688-21747`, deduplicated by map pointer, `MAX_USED_MAPS` 64). That is why a map the proof code
never mentions can still decide the load.

## 2. What the application does at load time

The ELF relocations of `uprobe/custom__generic` name only `perf_progs` — `support/ebpf/tracer.ebpf.amd64`
carries 49 relocations for that section with `perf_progs` and no `kprobe_progs`, and the B-side
`custom_trace.plain.o` / `custom_trace.native.o` of `corpus/results/spec-test/otel/` have the same three
`perf_progs` relocations (`+0x95c`, `+0x98e`, `+0x99a`). The application then rewrites the map at load time in
Go:

- `vendor/repos/opentelemetry-ebpf-profiler/tracer/tracer.go:445-453` builds the `custom__generic` entry and
  calls `loadProbeUnwinders(coll, ebpfProgs, ebpfMaps["kprobe_progs"], customProgs, ...,
  ebpfMaps["perf_progs"].FD())` — the `kprobe_progs` map object is the replacement target and `perf_progs`'s
  fd is the marker to find.
- `:601-622 progArrayReferences` selects every `LdClass` instruction whose `ins.Map()` fd equals
  `perfTailCallMapFD`.
- `:647-653` reassociates each of those instructions with `tailcallMap`, i.e. with `kprobe_progs`, with the
  comment "Replace the prog array for the tail calls."
- `:664-690 loadProgram` then loads the rewritten bytes. `custom__generic` carries
  `noTailCallTarget: true` (`:448`, "Not added to perf_progs, users manage their own prog_array"), so the
  application does not insert it into `perf_progs` itself.

The same rewrite is applied to `uprobe__generic` (`:437-441`) and to the sched-switch kprobes (`:423-425`).
The two maps in `off_cpu.ebpf.c:5-11` (`kprobe_progs`, type 3, 10 entries) and
`interpreter_dispatcher.ebpf.c:29-35` (`perf_progs`, type 3, `NUM_TRACER_PROGS` = 10) are therefore both
prog arrays of the same shape, differing only in their set of programs.

## 3. What the kernel recorded

The baseline shim log
`corpus/results/x86_kvm_corpus_20261125_082733_452277/details/shim-logs/otelcol-ebpf-profiler__profiling.baseline.log`
records every map create (lines 23-60) and every `MAP_UPDATE_ELEM`:

- `perf_progs` is fd 13, kernel map id 8 (line 29). Ten `MAP_UPDATE_ELEM prog_array name=perf_progs
  map_fd=13` follow at lines 178-215, with prog ids 6-15, all of them attached type 7 (perf_event).
- `kprobe_progs` is fd 15, kernel map id 11, type 3, 10 entries (line 37). **No `MAP_UPDATE_ELEM` for
  `map_fd=15` appears anywhere in the log**, so `kprobe_progs` stays empty and its owner unset.
- `custom__generic` loads at line 222 (`insn_cnt=1253 hash=aedb5aa661acf418`) and succeeds at line 223
  (`PROG_LOAD -> fd=67 errno=0 kernel_prog_id=18`). Its own load passes because the array it names has no
  owner yet: `__bpf_prog_map_compatible` takes the `!map->owner` branch and sets the owner to this program's
  own type.

The captured bytecode confirms which fd the loaded program names.
`corpus/results/verified-captures-7c12opr9/bpfrejit_1852_aedb5aa661acf418.bpf` (1253 insns) has one
`BPF_FUNC_tail_call` (`code=0x85 imm=12`) at insn 294. Insns 287-294 are the `record->tailCalls` increment
(`0x71` byte load at `off=4996`, `0x07 +1`, `0x73` byte store at `off=4996`) and then:

```
291: code=0x18 src=1 (BPF_PSEUDO_MAP_FD) dst=2 imm=15   -> kprobe_progs (fd 15, kernel id 11)
293: code=0xbf src=6 dst=3
294: code=0x85 imm=12 (BPF_FUNC_tail_call)
```

The post-ReJIT capture `bpfrejit_1951_7408293886fac5d0.bpf` is the same instruction list with `imm=41` at
insn 291 (`kprobe_progs` reopened as fd 41, kernel map id 210) and the ten `MAP_UPDATE_ELEM map_fd=33`
entries of `perf_progs` (fd 33, kernel map id 204).

A survey of every capture in that directory gives one tail-call LDDW per program, and `perf_progs` (fd 13
baseline, 33 post) in all eleven others; `aedb5aa661acf418` is the single program that names `kprobe_progs`:

```
bpfrejit_1852_0654df483b499c68  7974 insns  imm=13
bpfrejit_1852_1ee44b81d2778dbb  7475 insns  imm=13
bpfrejit_1852_2db937dc7603bde3  1322 insns  imm=13, 13
bpfrejit_1852_58426cbdefd16caf  5458 insns  imm=13
bpfrejit_1852_599da2ff04186d1d  6972 insns  imm=13
bpfrejit_1852_82186c3b57366234  7817 insns  imm=13
bpfrejit_1852_925e758ea856ec73  7593 insns  imm=13
bpfrejit_1852_933d387623af50c1  1631 insns  imm=13
bpfrejit_1852_aedb5aa661acf418  1253 insns  imm=15   <- custom__generic
bpfrejit_1852_c97a42b1796abd8b  5894 insns  imm=13
bpfrejit_1852_cb9185cd44f8b8a8  6899 insns  imm=13
```

The shim captures exactly a program's `used_maps` (`bpfopt/shim/libbpfrejit_shim.c:600-680`: `map_ids` from
`BPF_OBJ_GET_INFO_BY_FD`, then `/proc/self/fd` matched by kernel map id), so `kprobe_progs` reaching this
request is the kernel's own record that the loaded program uses it.

The 2026-11-26 re-run (section 6) reproduces the same split with different fds, which rules out a one-off
numbering coincidence. In `corpus/results/x86_kvm_corpus_20261126_021711_899337`, the baseline creates
`kprobe_progs` as fd 13 / kernel id 8 (line 28) and `perf_progs` as fd 35 / kernel id 41 (line 119), with ten
`MAP_UPDATE_ELEM prog_array name=perf_progs map_fd=35` inserts (fd 35, none on fd 13). The captured
`bpfrejit_1855_31c23f29cf92a6ee.bpf` (1253 insns) has its tail-call LDDW at insn 291 with `imm=13` —
`kprobe_progs`. Post-ReJIT (`.../post_rejit.log`), `kprobe_progs` is fd 25 / id 186 and `perf_progs` fd 47 /
id 223 (ten updates on 47, none on 25), and the captured `bpfrejit_1956_200c5306b1a6e9ce.bpf` names `imm=25`.
So in both runs the program names the array the app rewrote to, and B names the array the ELF does.

## 4. Where B's `perf_progs` comes from

B reads the captured, already-rewritten bytecode, so B's own generated instruction stream binds the tail call
to the fd the app wrote (`15` in the 08:31Z run, `13` in the 14f run). Its `native_data_symbols`, however,
carry `perf_progs`:

```
generated/trusted_x86.bpf.c:12   extern __u8 perf_progs[] __ksym;
generated/trusted_x86.bpf.c:573  X86_OP_MOV_LOAD_MAP_PTR ... ((__u64)(long)perf_progs)
generated/trusted_x86.bpf.c:585  X86_OP_MOV_LOAD_MAP_PTR ... ((__u64)(long)perf_progs)
generated/trusted_x86.bpf.c:594  X86_OP_CALL_HELPER ... X86_SIM_HELPER_bpf_tail_call
```

`generated/trusted_x86.proof.o` `.rela.text` carries `perf_progs` at `+0x373` and `+0x382` and
`bpf_tail_call` at `+0x38c`. Its symbol table holds one undefined map symbol — `perf_progs` — and no
`kprobe_progs` at all. `generated/request.native.o` (`kernel.native.o`, byte-identical, 85064 bytes) has the
same two `perf_progs` code relocations at `+0x373`/`+0x382` in `.relauprobe/custom__generic`; its second map
symbol `kprobe_progs` (`.maps` offset `0x320`) reaches only `.rela.debug_addr`, i.e. DWARF, not code.
Disassembling the site shows the map load feeding the call:

```
370:  movq (%rip), %rsi        # reloc +0x373 -> perf_progs
377:  movq %rbx, %rdi
37a:  movl %r12d, %edx
37d:  jmp  0x38b
37f:  movq (%rip), %rsi        # reloc +0x382 -> perf_progs
38b:  callq 0x390              # reloc +0x38c -> bpf_tail_call
```

`kernel.metadata.json` therefore names exactly one prog array, `perf_progs`, out of its eleven maps (the
others are arrays, hashes, a `pid_page_to_mapping_info` LPM trie, `kernel_stackmap` stack trace,
`per_cpu_records`, `custom_context_map` and `metrics`).

The one array B names is therefore the array the application's ELF names, not the array the captured
bytecode names — and the two differ only for this program, because only this program's tail call is rewritten
by the application at load time (section 2). Three steps produce that:

1. `add_native_data_symbol_addrs` (`native_loader_trusted.cpp:1801-1941`) walks the native object's `.maps`
   symbols, and its first filter at `:1844` drops any name absent from `entry_symbols`.
2. `entry_symbols` is the *proof's whole symbol table*: `cached_native_entry_proof` (`:3196`) runs the
   linker in proof mode, and `native_entry_symbol_names` (`native_loader_entry_data.hpp:6-31`) returns every
   non-empty name in its `SHT_SYMTAB`/`SHT_DYNSYM`. The proof holds `perf_progs` (relocated by the two code
   LDDWs) and no `kprobe_progs`, so step 1 keeps one array symbol and skips the other even though both sit in
   `.maps` at `0x528` and `0x320`.
3. `add_native_map_symbol_alias` (`:1532-1597`) then binds the surviving name to a map identity:
   `find_exact_map_meta` at `:1539` searches the program's own maps, a manifest map is tried at
   `:1544-1554`, a shape match at `:1556-1590`, and — the branch that fires here — `:1592-1596`
   `find_open_process_map_by_name` scans the whole process for an open map of that name. The program's own
   maps hold `kprobe_progs` (its LDDW) and never `perf_progs`, so the exact and shape branches find nothing and
   the process scan supplies the app's `perf_progs`. `submit_trusted_native` (`:2408-2438`) serializes
   exactly `companion.native_data_symbols`, so `metadata["maps"]` names `perf_progs` with the process's id —
   223 in 14f, 204 in the 08:31Z run — the array owned by ten perf_event programs.

`bind_original_source_maps` is the step that would have rebound the ELF name to the loaded program's own map.
It runs at `:3200` only when `source_bpf_object` is non-empty; `source_bpf_object` is declared empty at
`:3148` and assigned only at `:3171`, inside the manifest branch. The checked service path passes no
manifest (`trusted_service.py:155-167`: `native_object`, `symbol`, proof, simulator, link, then service
fields and map triples), and `trusted_loader.cpp:44-72` sets only `native_object_path`, `symbol_name`,
proof paths, `native_link_path`, `trusted_maps` and the context fields — never `manifest_path`,
`source_bpf_path` or `source_insns`. So on this path the rebinding never runs and the proof's name stands.

## 5. Why the load fails, and what the retry does

For the request, `bpf_check_tail_call` walks the used maps of the program being loaded. `perf_progs` (id 204)
enters `used_maps` in one of two ways, and both apply here:

1. `process_fd_array` adds every fd of `opts.fd_array` (`native_loader_trusted.cpp:3041-3044`,
   `reopen_relocated_map_fds(linked.relocated_map_ids)`), and the native blob's `MAP_POINTER`/`MAP_VALUE`
   relocations name id 204.
2. The proof object's own LDDWs (`+0x373`, `+0x382`) bind `perf_progs` by fd (`relocate_trusted_proof`,
   `:2790-2855`, `low.imm = map_fds.at(id)`).

`perf_progs`'s owner is prog type 7 (`resolve_prog_type` of a perf_event-attached kprobe program); this
program is type 2, so `__bpf_prog_map_compatible` returns false and `bpf_check_tail_call` returns `-EINVAL`
with no log text. `:3053-3101` already implements the intended remedy — reload without the prog arrays this
program does not itself use:

```
const std::vector<uint32_t> original_ids = options.original_prog_fd >= 0
    ? load_prog_map_ids(options.original_prog_fd) : std::vector<uint32_t>{};
const std::unordered_set<uint32_t> used(original_ids.begin(), original_ids.end());
const auto foreign_prog_array = [&](uint32_t id) {
    if (used.count(id)) return false;
    ScopedFd fd(bpf_map_get_fd_by_id(id));
    if (fd.get() < 0) return false;
    const bpf_map_info info = load_map_info(fd.get());
    return info.type == BPF_MAP_TYPE_PROG_ARRAY;
};
```

Two facts decide whether that retry can fire for this request:

- `used` is the original program's `map_ids` and id 204 is **outside** it — the original program uses
  `kprobe_progs` (id 210 post-ReJIT), not `perf_progs`. So `foreign_prog_array(204)` is true and the retry
  would drop it.
- Dropping it from `fd_array` is only half the story: the dropped fd also leaves `used_maps`, and the JIT's
  `bpf_native_relocate` (`arch/x86/net/bpf_jit_comp.c:3717-3780`) resolves `MAP_POINTER` by kernel id against
  `prog->aux->used_maps`, returning `-ENOENT` when the id is absent. For a direct-native load the verified
  program is the 4-insn stub, whose only map is the tail-call marker, so the native blob's `perf_progs` id has
  no `used_maps` entry to find.

Whether the second load then also fails in the JIT is what the guest run below measures.

The 08:31Z run that produced `request/verify.stderr` used loader
`b1ea15f385e74aa96b73b9890b4bf6145f61a694443955ac3ba305aef43f5336` (recorded in
`source-identities.json`), whose stderr texts carry neither the retry line nor the statistics suffix that
`:3010-3011` writes. The installed loader is
`202bf59aef552d08918c05f2f5aae564caad9da6ef31a1cad646ff60bcbf2776`, the same binary the kdata4 check mounts,
and it carries `native: reloading without foreign PROG_ARRAY map(s)`.

## 6. Guest re-run with the installed loader

Command, from `/workspaces/repository`:

```
make -C kprog/libnativeloader checked-corpus \
  CHECKED_OUTPUT=/workspaces/kprog-raw/omp/checked-otel-14f \
  CHECKED_APP=otelcol-ebpf-profiler/profiling CHECKED_HOST_CPUS=16-23 \
  CHECKED_LOADER=/workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
```

The run keeps `service.tar.gz`, so each request's `load-direct.stderr` can be read back. It finished with
`exit-code` 0 (the app ran both phases), 13 of the 14 requests at status 0, and request 14 still failing — but
for a new reason:

```
load-direct.stderr:
native: reloading without foreign PROG_ARRAY map(s) 223
trusted-native-loader: service simulator verification failed: Unknown error 524
processed 4 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0

verify.stderr (unchanged):
trusted-native-loader: service simulator verification failed before native compilation: Invalid argument
verification time 12965 usec
stack depth 248+0
processed 5717 insns (limit 1000000) max_states_per_insn 4 total_states 222 peak_states 222 mark_read 0
```

Three things follow, and they close the question.

1. **The retry fires and classifies correctly, in the load path that has one.** `223` is `perf_progs` in this
   run's `kernel.metadata.json`, and the original program's map set does not contain it, so
   `foreign_prog_array(223)` holds. The first load of `load-direct` therefore hit the same `-EINVAL` as
   `verify.stderr` and the retry replaced it. `verify.stderr` itself is unchanged because the verify-only load
   at `:3005` has no retry; only `:3084-3097` does.
2. **The second load fails in the JIT, exactly as the relocation gap predicts.** `524` is `ENOTSUPP`
   (`include/linux/errno.h:27`), raised at `kernel/bpf/core.c:2585` when `!fp->jited && jit_needed`. The JIT
   left `prog->jited` unset because `bpf_native_relocate` (`arch/x86/net/bpf_jit_comp.c:3752-3755`) looked for
   `perf_progs`'s kernel id among `prog->aux->used_maps` and found nothing: the map had just been dropped from
   `fd_array`, and with it from `used_maps`. `bpf_native_jit` swallows the `-ENOENT` (`:3815` `goto out`)
   and returns the program un-jited, so the syscall surface is `-ENOTSUPP`, not `-ENOENT`.
   `CONFIG_BPF_JIT_ALWAYS_ON=y` in `/workspaces/.agent-state/kprog-ck/build-x86/.config` means the interpreter
   cannot absorb it.
3. **The verified program is the 4-insn stub**, so nothing else could have kept `perf_progs` in `used_maps`:
   `processed 4 insns` on the failing load is the stub `native_stub_program`
   (`native_loader_trusted.cpp:425-444`), whose only map is the `native_tail_call_probe` marker
   (`:416-424`, `create_tail_call_marker_map`).

Map identity in this run, from `generated/kernel-link/*.map-patches.tsv`: `perf_progs` appears at two patch
offsets (1131, 1152), both from the proof's LDDW sites, and `kprobe_progs` appears nowhere. The native blob
holds `perf_progs`'s id, so the map P needs at relocation time is exactly the map the compatibility rule
requires be dropped.

### What the retry therefore needs

The two requirements are in direct conflict only because the dropped map is the same map the native image
relocates:

| requirement | source | satisfied by |
|---|---|---|
| `perf_progs` must not be a used map at `bpf_check_tail_call` (it is owned by type-7 programs) | `core.c:2421-2521` | dropping it from `fd_array` |
| the array's kernel id must be reachable when the JIT resolves `BPF_NATIVE_RELOC_MAP_POINTER` | `bpf_jit_comp.c:3752-3755` | keeping it in `fd_array` |

The conflict is in the *identity*, and `kprobe_progs` dissolves it: it is the map the loaded program actually
uses, it carries no owner (zero `MAP_UPDATE_ELEM` in both runs), so `__bpf_prog_map_compatible` accepts it
with any type-2 program, and it is the map the captured bytecode's LDDW already points at. Three shapes
follow, all of which keep a used map in `used_maps`:

- **Bind the ELF name to the loaded slot's fd before the metadata is written.** This is the composition the
  loader already has, applied to a path that does not run it: `bind_original_source_maps`
  (`native_loader_source_maps.hpp:254-274`) walks the *original object's* `R_BPF_64_64` `.maps` relocations
  against the *loaded* instructions (`:222-228`) and records `map_addr_ids[elf_name] = loaded_fd_identity`.
  For `custom__generic` the original ELF relocation at the tail-call site names `perf_progs`, the loaded slot
  holds `kprobe_progs`'s fd, so the entry would become `perf_progs → kprobe_progs`(id 186 in 14f). The order
  already supports it: `bind_original_source_maps` runs at `:3200`, before `add_native_data_symbol_addrs` at
  `:3202`, and `add_native_map_symbol_alias` returns immediately when `map_addrs` already holds the name
  (`:1535-1537`), so the bound identity survives. Only `source_bpf_object` gates it, and only the manifest
  branch sets it (`:3148`, `:3171`).
- **Give the metadata the loaded program's own map list.** The captured `used_maps` already holds
  `kprobe_progs`, so naming it in `metadata["maps"]` makes the reopen and the relocation agree without any
  name translation. This is the same output as the first shape, produced at the other end.
- **Keep `perf_progs` and make the JIT's relocation independent of `used_maps`.** This is a kernel-side
  change (`bpf_native_relocate` currently searches `prog->aux->used_maps` by kernel id) and therefore the
  largest of the three.

The first shape is the smallest: one condition in `load_bound_native` (`native_loader_trusted.cpp:3114`) that
also binds source map identities when the intercepted instructions are available. Whether they are available
on the checked path at `load-direct` time is the open question this record leaves to the coordinator's runtime
decision: `load_bound_native` reads them from `options.source_bpf_path`/`options.source_insns` (`:3127-3136`),
the loader's `load-direct` argv (`trusted_loader.cpp:44-72`) sets neither, and the service
(`trusted_service.py:155-167`) passes no such flag.

None of the three touches `vendor/bpf`, the application or the kernel's compatibility rule. This record states
the mechanism and the measurement; it does not choose between them.

## Files

- `/workspaces/kprog-raw/omp/r14/request/` — the failing request of the 08:31Z OTel pass: `error.json`,
  `verify.stderr`, `load-direct.stderr`, `kernel.facts.json`, `kernel.metadata.json`, `generated/` (B,
  proof, bounds and lowering artifacts), `kernel.native.o`, `simulator-failure.json`,
  `source-identities.json`.
- `/workspaces/kprog-raw/omp/checked-otel-14f/` — the guest re-run with the installed loader.
- `corpus/results/verified-captures-7c12opr9/` — the baseline and post-ReJIT bytecode captures surveyed in
  section 3.
- `corpus/results/x86_kvm_corpus_20261125_082733_452277/details/shim-logs/` — the baseline shim log with the
  map creates, the ten `perf_progs` updates and the `custom__generic` load.