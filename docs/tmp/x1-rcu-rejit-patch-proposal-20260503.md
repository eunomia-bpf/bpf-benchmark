# X1 RCU prog-replacement REJIT patch proposal

Date: 2026-05-03
Kernel tree: `vendor/linux-framework/`
Kernel HEAD checked: `37166911e`
Scope: research and patch proposal only. No source edits were made under `vendor/linux-framework/`.

## 0. Executive summary

X1 is the right invariant-preserving direction: do not mutate a live JITed
`struct bpf_prog`; build a new program object and publish it by replacing
references under each owner subsystem's synchronization.

However, X1 is not a local rewrite of `kernel/bpf/syscall.c`. A live
`struct bpf_prog *` is stored in IDR, anonymous FDs, bpffs pins, `bpf_link`,
PROG_ARRAY maps, `bpf_prog_array` runtime arrays, cgroup lists, perf events,
trampolines, XDP netdev and driver private fields, sockmap/sk_psock state,
struct_ops maps/trampolines, classic tc, socket filters, flow dissector,
reuseport, LWT/seg6, devmap/cpumap, LIRC, netfilter, and BPF iterator links.
Some slots already have atomic/RCU replacement APIs; several do not.

The immediate crash is explained by the current fork mutating
`prog->bpf_func` in place while caller poke descriptors still name addresses
inside the previous JIT image. `prog_array_map_poke_run()` eventually calls
`bpf_arch_poke_desc_update()` with stale expectations and hits the observed
`-EBUSY` / `BUG_ON` path.

## 1. Evidence and problem statement

### 1.1 Observed panic evidence

Local artifact:

- `corpus/results/x86_kvm_corpus_20260503_212536_397107/details/daemon.stderr.log`
- `metadata.json` shows this was `x86_kvm_corpus`, `22` macro apps, all passes
  enabled, status still `running`.
- `progress.json` shows the run stopped at `apps_done = 11`, `last_app =
  calico/felix`, `total_apps = 22`.
- The daemon log reaches line 957 and ends without a matching exit for the last
  REJIT:
  - lines 814-829: many concurrent REJITs start, including `tid=23141
    REJIT_ENTER prog=120 pass=wide_mem`, then `prog=120` exits successfully.
  - lines 844-935: the same `tid=23141 prog=120` exits `rotate`,
    `cond_select`, `extract`, `endian_fusion`, and `map_inline`
    successfully while other programs `122..132` are concurrently REJITed.
  - line 950: `tid=23141 REJIT_ENTER prog=120 pass=const_prop`.
  - there is no `REJIT_EXIT prog=120 pass=const_prop`.

This matches the confirmed external panic report: PID/TID 23141, prog 120,
`const_prop`, six or more concurrent REJITed programs, panic in the
`prog_array_map_poke_run()` -> `bpf_arch_poke_desc_update()` path.

### 1.2 Upstream invariant being broken

Upstream BPF assumes a JITed program's executable image pointer is stable after
publication. In this fork, `BPF_PROG_REJIT` violates that by retaining the same
`struct bpf_prog *` identity but publishing a different JIT image through the
same object:

- `kernel/bpf/syscall.c:3490`:
  `smp_store_release(&prog->bpf_func, tmp->bpf_func);`

This means existing users of `prog`, especially tail-call direct-poke
descriptors, can hold addresses derived from the old `prog->bpf_func` while the
program object now names a new image.

`kernel/bpf/arraymap.c:1124-1141` explicitly documents why
`prog_array_map_poke_run()` uses `aux` and waits for
`poke->tailcall_target_stable`: the program pointer may be unstable/UAF, but
the poke descriptor itself is expected to describe a stable JIT target once
published. X1 restores that expectation by making both old and new JIT images
immutable for their respective program object lifetimes.

## 2. In-place mutation audit in `kernel/bpf/syscall.c`

This section lists every REJIT path found that mutates the live `prog` object
or live poke descriptors instead of publishing a new `struct bpf_prog`.

### 2.1 `bpf_prog_rejit_update_poke_tab()` lines 3218-3291

This mutates live `prog->aux->poke_tab[i]` descriptors to point from the old
JIT image to the temporary JIT image:

- `3273`: `WRITE_ONCE(old_poke->tailcall_target_stable, false)`
- `3279`: `old_poke->tailcall_target = new_poke->tailcall_target`
- `3280`: `old_poke->tailcall_bypass = new_poke->tailcall_bypass`
- `3281`: `old_poke->bypass_addr = new_poke->bypass_addr`
- `3282`: `old_poke->adj_off = new_poke->adj_off`
- `3285`: `WRITE_ONCE(old_poke->tailcall_target_stable, true)`

Impact: it changes caller patch metadata attached to the old live program
object, while other map poke paths can still race on expectations about the old
image.

### 2.2 `bpf_prog_rejit_untrack_tmp_pokes()` lines 3299-3308

This untracks `tmp->aux` from PROG_ARRAY maps after verifier/JIT, because the
current implementation intends to destroy `tmp` and mutate the old `prog` in
place. Under X1 this helper should disappear: the newly verified/JITed `tmp`
becomes the live program, so its `aux` map-poke tracking is the correct one.

### 2.3 `bpf_prog_rejit_poke_target_phase()` lines 3332-3379

This scans all PROG_ARRAY maps and calls `map_poke_run()` before and after the
in-place image swap:

- `3362`: lockless `array->ptrs[key] != prog` check
- `3366`: recheck under `array->aux->poke_mutex`
- `3371`: `map_poke_run(map, key, NULL, prog)`
- `3373`: `map_poke_run(map, key, prog, NULL)`

This is not a direct `prog->field` assignment, but it exists only to bracket the
in-place mutation of `prog->bpf_func`. X1 replaces the PROG_ARRAY slot from
`old_prog` to `new_prog` and calls `map_poke_run(map, key, old_prog, new_prog)`
once with both images immutable.

### 2.4 `bpf_prog_rejit_swap()` lines 3381-3497

This is the main invariant violation. It swaps or overwrites live fields inside
the existing `prog` object.

Top-level image/publication fields:

- `3448-3450`: swaps `prog->digest` with `tmp->digest`
- `3451`: `prog->jited = tmp->jited`
- `3452`: `prog->jit_requested = tmp->jit_requested`
- `3453`: `prog->jited_len = tmp->jited_len`
- `3486`: `memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp))`
- `3487`: `prog->len = tmp->len`
- `3490`: `smp_store_release(&prog->bpf_func, tmp->bpf_func)`

Top-level bitfields:

- `3454`: `gpl_compatible`
- `3455`: `cb_access`
- `3456`: `dst_needed`
- `3457`: `blinding_requested`
- `3458`: `blinded`
- `3459`: `kprobe_override`
- `3460-3461`: `enforce_expected_attach_type`
- `3462`: `call_get_stack`
- `3463`: `call_get_func_ip`
- `3464`: `call_session_cookie`
- `3465`: `tstamp_type_access`
- `3466`: `has_callchain_buf`

Auxiliary metadata swapped between `prog->aux` and `tmp->aux`:

- `3397`: `ctx_arg_info`
- `3398`: `ctx_arg_info_size`
- `3399`: `orig_insns`
- `3400`: `orig_prog_len`
- `3401`: `used_btfs`
- `3402`: `used_btf_cnt`
- `3403`: `btf`
- `3404`: `func_info`
- `3405`: `func_info_aux`
- `3406`: `func_info_cnt`
- `3407`: `linfo`
- `3408`: `jited_linfo`
- `3409`: `nr_linfo`
- `3410`: `linfo_idx`
- `3411`: `mod`
- `3412`: `num_exentries`
- `3413`: `extable`
- `3414`: `priv_stack_ptr`
- `3415`: `saved_dst_prog_type`
- `3416`: `saved_dst_attach_type`
- `3417`: `tail_call_reachable`
- `3418`: `exception_cb`
- `3419`: `jit_data`
- `3420`: `used_maps`
- `3421`: `used_map_cnt`
- `3422`: `kfunc_tab`
- `3423`: `kfunc_btf_tab`
- `3424`: `might_sleep`
- `3425`: `arena`
- `3426`: `attach_func_proto`
- `3427`: `attach_func_name`
- `3430`: `prog->aux->security` under `CONFIG_SECURITY`

Function/subprogram arrays and exception metadata:

- `3433`: `bpf_prog_kallsyms_del_all(prog)`
- `3436`: `prog->aux->func`
- `3437`: `prog->aux->func_cnt`
- `3438`: `prog->aux->real_func_cnt`
- `3439`: `prog->aux->bpf_exception_cb`
- `3440`: `prog->aux->exception_boundary`
- `3442-3446`: for every subprogram, mutates:
  - `func[i]->aux->main_prog_aux`
  - `func[i]->aux->poke_tab`
  - `func[i]->aux->size_poke_tab`

Verifier/runtime auxiliary fields:

- `3468`: `max_ctx_offset`
- `3469`: `max_pkt_offset`
- `3470`: `max_tp_access`
- `3471`: `stack_depth`
- `3472`: `max_rdonly_access`
- `3473`: `max_rdwr_access`
- `3474`: `verifier_zext`
- `3475`: `changes_pkt_data`
- `3476`: `kprobe_write_ctx`
- `3477`: `verified_insns`
- `3478`: `load_time = ktime_get_boottime_ns()`

Mutation of `tmp` back to the old image:

- `3491`: `tmp->jited = old_jited`
- `3492`: `tmp->jit_requested = old_jit_requested`
- `3493`: `tmp->jited_len = old_jited_len`
- `3494`: `WRITE_ONCE(tmp->bpf_func, old_bpf_func)`

X1 removes this function entirely.

### 2.5 Rollback helpers lines 3499-3591

`bpf_prog_rejit_prepare_rollback()` snapshots mutable live state:

- `3509`: captures `prog->len`
- `3510`: captures `prog->aux->load_time`
- `3511`: copies `prog->insnsi`

`bpf_prog_rejit_restore_rollback()` mutates the live program back:

- `3523`: `memcpy(prog->insnsi, state->insnsi, ...)`
- `3524`: `prog->len = state->len`
- `3525`: `prog->aux->load_time = state->load_time`

Callers:

- `bpf_prog_rejit_restore_rollback()` is called only by
  `bpf_prog_rejit_rollback()` at `3550`.
- `bpf_prog_rejit_rollback()` is called by `bpf_prog_rejit()` at `3850-3854`
  when struct_ops refresh fails after the in-place swap.

X1 should fail before publication or publish atomically enough that rollback is
reference replacement, not bytecode/image mutation.

### 2.6 `bpf_prog_rejit_rollback()` lines 3534-3591

Rollback reuses the same in-place machinery:

- `3547`: `bpf_prog_rejit_poke_target_phase(prog, false)`
- `3549`: `bpf_prog_rejit_swap(prog, tmp)`
- `3550`: `bpf_prog_rejit_restore_rollback(prog, state)`
- `3565`: `WRITE_ONCE(poke->tailcall_target_stable, false)`
- `3566`: restore `tailcall_target`
- `3567`: restore `tailcall_bypass`
- `3568`: restore `bypass_addr`
- `3569`: restore `adj_off`
- `3570`: `WRITE_ONCE(poke->tailcall_target_stable, true)`
- `3576`: `bpf_prog_rejit_poke_target_phase(prog, true)`
- `3578`: `bpf_trampoline_refresh_prog(prog)`
- `3582-3584`: `bpf_struct_ops_refresh_prog(prog, new_bpf_func)`
- `3588-3589`: `bpf_prog_change_xdp(prog, new_bpf_func)`

X1 should remove the rollback path and replace post-publication refresh helpers
with owner-level pointer replacement.

### 2.7 `bpf_prog_rejit()` lines 3598-3955

The function correctly allocates and verifies a temporary program, then throws
away that object identity and mutates the old program:

- `3664`: `tmp = bpf_prog_alloc(...)`
- `3669-3752`: copies load/attach/BTF metadata into `tmp`
- `3759`: `bpf_check(&tmp, ...)`
- `3764`: `tmp = bpf_prog_select_runtime(tmp, ...)`
- `3775-3778`: rejects if `tmp->len` no longer fits in the old allocation
- `3779-3787`: snapshots live `prog->aux->poke_tab`
- `3790`: prepares rollback snapshot of live `prog`
- `3803`: mutates live poke descriptors with `bpf_prog_rejit_update_poke_tab`
- `3814`: untracks `tmp` poke state because `tmp` will be freed
- `3820`: pre-swap PROG_ARRAY target phase
- `3822`: `bpf_prog_rejit_swap(prog, tmp)`
- `3827`: post-swap PROG_ARRAY target phase
- `3828`: reads `new_bpf_func = prog->bpf_func`
- `3830`: trampoline refresh after mutation
- `3844-3845`: struct_ops refresh after mutation
- `3865-3866`: XDP driver refresh after mutation
- `3872-3875`: synchronize after publishing the mutated image
- `3884-3888`: kallsyms relink
- `3891-3917`: frees `tmp` as the old image holder, with a
  `retain_old_image` workaround

X1 changes the final phase from "swap fields into `prog`" to "publish `tmp` as
the replacement program object".

### 2.8 Info path guard lines 5857-5860

`bpf_prog_get_info_by_fd()` takes `prog->aux->rejit_mutex` only in this fork to
avoid observing partially swapped in-place state. With X1, a program object is
immutable after publication; this lock should no longer be needed for
self-consistency. ABI questions remain for whether an existing FD points to the
old immutable program or a stable handle that resolves to the new one.

## 3. Reference owners and replacement requirements

This table is the key reason X1 is larger than `syscall.c`.

| Owner / slot | Evidence | Protection today | X1 replacement rule |
| --- | --- | --- | --- |
| Program IDR | `kernel/bpf/syscall.c:2328-2363`, `5584-5620` | `prog_idr_lock` spinlock | `idr_replace(&prog_idr, new, old_id)` while holding `prog_idr_lock`; set `new->aux->id = old_id`. Old ID handling is ABI-sensitive. |
| Program FD | `syscall.c:2534-2544`, `2602-2615` | file lifetime, no RCU | Existing `file->private_data` stores `struct bpf_prog *`. X1 cannot update all open FDs unless a stable handle object is introduced. |
| bpffs pin / obj get | `kernel/bpf/inode.c`, `bpf_obj_pin()`/`bpf_obj_get()` in `syscall.c:3959-3989` | inode/file ref | Pins ultimately retain the object pointer. Same handle problem as FDs. |
| `struct bpf_link::prog` | `include/linux/bpf.h:1877-1899` | link-specific locks/ops | `xchg()` under each link owner's lock plus backing runtime update. Existing `update_prog` covers only some link types. |
| PROG_ARRAY map entries | `kernel/bpf/arraymap.c:899-956` | `array->aux->poke_mutex` for poke maps; `xchg()` on `array->ptrs[k]` | Under `poke_mutex`, inc new, `xchg(old,new)`, call `map_poke_run(map,key,old,new)`, put old after publication. Also update `prog_array_member_cnt` under `old->aux->ext_mutex` / `new->aux->ext_mutex`. |
| PROG_ARRAY poke reverse index | `arraymap.c:1050-1154` | `poke_mutex`, `poke_progs` list stores `aux` | Do not untrack `new->aux`; it becomes live. Old aux remains until old program is put after grace period. |
| `bpf_prog_array` runtime arrays | `include/linux/bpf.h:2399-2569`, `kernel/bpf/core.c:2710-2762` | RCU readers, `WRITE_ONCE(item->prog, ...)` or copied array + RCU assign | Prefer copied array + `rcu_assign_pointer` when owner already uses it. Existing in-place `WRITE_ONCE(item->prog, new)` is acceptable only under the owner lock with refcount ordering. |
| Cgroup direct/list refs | `include/linux/bpf-cgroup.h:107`, `kernel/bpf/cgroup.c:432-500`, `785-904`, `924-1008` | `cgroup_mutex`, effective arrays under RCU | Replace `bpf_prog_list.prog` or `link->link.prog`, then rebuild/patch effective arrays under `cgroup_mutex`; put old after. |
| TCX multi-prog | `kernel/bpf/tcx.c:10-56`, `203-244`; `include/linux/bpf_mprog.h:95-132,316` | RTNL, active entry under RCU, `WRITE_ONCE(fp->prog)` | Reuse `bpf_mprog_attach()`/commit path or internal replacement under RTNL. |
| Netkit multi-prog | `drivers/net/netkit.c:529-568`, `678-718`, `767-778` | RTNL / netkit locks, `bpf_mprog` | Same as TCX. |
| Netns attach/run arrays | `kernel/bpf/net_namespace.c:300-360`, `420-474`, `163-201` | `netns_bpf_mutex`, RCU run arrays | Direct attach: replace `net->bpf.progs[type]` and run array slot. Link attach: `xchg(&link->prog,new)` plus `bpf_prog_array_update_at()`. |
| Perf event non-tracing | `kernel/events/core.c:10587-10659` | event context/perf locking, RCU readers use `READ_ONCE(event->prog)` | Replace `event->prog` under perf event owner lock, synchronize with overflow handler expectations, put old after. |
| Perf event tracing / tracepoints | `kernel/trace/bpf_trace.c:1920-2005` | `bpf_event_mutex`, tracepoint `prog_array` under RCU/tasks-trace | Copy tracepoint program array replacing old with new, `rcu_assign_pointer(event->tp_event->prog_array,new_array)`, update `event->prog`. |
| Tracing links / trampolines | `syscall.c:4375-4585`; `kernel/bpf/trampoline.c:767-870,903-954` | trampoline mutex, `prog->aux->rejit_mutex` in fork | Replace link prog and rebuild trampoline under `tr->mutex`. For EXT/freplace, update `tr->extension_prog` and text poke target through unlink/link semantics. |
| Raw tracepoint links | `syscall.c:5078` | link lifetime + tracepoint internals | No generic `update_prog` found. Needs new internal replace callback or detach/reattach under the raw tracepoint owner lock. |
| Kprobe multi / uprobe multi links | `kernel/trace/bpf_trace.c:2830-2831`, `3285` | link-specific trace locks | No `update_prog` found. Needs link-owner replacement support. |
| BPF iterator links | `kernel/bpf/bpf_iter.c:494,555` | has `.update_prog = bpf_iter_link_replace` | Can reuse internal replacement equivalent, not the userspace FD path. |
| XDP link/direct netdev state | `net/core/dev.c:10230-10680` | RTNL + netdev BPF op locking; generic XDP uses RCU | Use `dev_xdp_install()` under RTNL for direct attach and link update semantics; then replace `dev->xdp_state[mode].prog` or `link->prog`. |
| XDP driver private slots | many `ndo_bpf` users, e.g. `drivers/net/veth.c:1188`, `virtio_net.c:6026`, `ixgbe_main.c:10915`, `mlx5/core/en_main.c:5133` | driver-specific, usually RTNL plus xchg/RCU | Must go through each driver's `ndo_bpf` path via `dev_xdp_install()`. Directly rewriting `struct bpf_prog *` fields is not acceptable. |
| Sockmap map-level progs | `net/core/sock_map.c:1524-1552`, `1746-1799`; `include/linux/skmsg.h:518-537` | `sockmap_mutex`, `xchg()`/`cmpxchg()` | Replace map-level program pointer and link pointer under `sockmap_mutex`. |
| Sockmap per-socket psock progs | `net/core/sock_map.c:220-335`, `net/core/skmsg.c` | psock/sk callback locks and RCU | Hard part: many sockets may have copied refs from map-level progs. Need owner traversal and `psock_replace_prog()` for each live psock. |
| Struct_ops member links/trampolines | `kernel/bpf/bpf_struct_ops.c:720-905`, `1267-1315`, `1421-1466` | map update mutex, RCU map pointer, generated trampolines | Replacing `link->prog` is insufficient; member trampoline pages and registered ops need rebuild or map-level replacement. |
| Netfilter link | `net/netfilter/nf_bpf_link.c:14-30`, `165-177`, `228-257` | netfilter hook registration | `.update_prog` exists but returns `-EOPNOTSUPP`. X1 needs unregister/register or RCU-safe `hook_ops.priv` replacement. |
| LIRC program arrays | `drivers/media/rc/bpf-lirc.c:137-173`, `205`, `219-223` | `ir_raw_handler_lock`, RCU `raw->progs` | Copy array, replace old with new, `rcu_assign_pointer(raw->progs,new_array)`. |
| Classic tc action/classifier | `net/sched/act_bpf.c:26,41,361`; `net/sched/cls_bpf.c:39,259` | rtnl/tcf locks, RCU filter pointer | Replace `filter` under tc owner lock and RCU-publish as current attach/update paths do. |
| Socket filters | `net/core/filter.c:1498`; `net/packet/af_packet.c:1573`; `drivers/net/ppp/ppp_generic.c:155-156`; tun/KCM users | socket lock / RCU, owner-specific | Replace through each socket/filter owner path or reject unsupported owners. Existing FDs/pins still need handle semantics. |
| Reuseport | `net/core/sock_reuseport.c:707,738` | socket/reuseport locks, RCU | Use `rcu_replace_pointer(reuse->prog,new,held_lock)` and put old after grace. |
| Flow dissector | `include/net/flow_dissector.h:485`; `net/core/flow_dissector.c` | netns flow dissector lock + RCU | Replace under existing flow dissector attach lock. |
| LWT / seg6 | `net/core/lwt_bpf.c:19,341`; `net/ipv6/seg6_local.c:72,1903` | route/lwt state ownership | No generic link replacement. Needs owner callback or unsupported-owner handling. |
| Devmap/cpumap XDP programs | `kernel/bpf/devmap.c:62,70`; `kernel/bpf/cpumap.c:72,413` | map update locks + RCU | Replace through map value update semantics; driver redirect paths must see stable refs. |
| Helper callbacks holding prog | `kernel/bpf/helpers.c:1422` (`xchg(&cb->prog, prog)`) | callback object lock | Needs callback-owner replacement if REJITed program can be stored there. |
| Extension target refs | `prog->aux->dst_prog`, `dst_trampoline` in `include/linux/bpf.h:1729-1732`; tracing attach in `syscall.c:4466-4573` | `dst_mutex`, trampoline mutex | Replacing old target or extension program must update both link and trampoline state. |

Conclusion from this table: a fully correct X1 needs either:

1. a stable public handle object (`struct bpf_prog_handle`) so FDs, pins, IDR,
   and links can dereference `current` under RCU; or
2. an exhaustive owner registry/callback layer that updates every live owner
   slot where `old_prog` appears.

The "replace all references while holding `prog_idr_lock`" design is not enough
because `prog_idr_lock` does not protect existing FDs, bpffs pins, link backing
state, XDP driver private state, perf events, or per-socket psock copies.

## 4. Proposed X1 design

### 4.1 High-level flow

1. Enter `BPF_PROG_REJIT` and lock `old->aux->rejit_mutex` to serialize REJITs
   of the same logical program.
2. Build a fresh program object:
   - allocate `new = bpf_prog_alloc(bpf_prog_size(new_len), GFP_USER)`;
   - prepare a synthetic `union bpf_attr` / verifier environment from old
     immutable load metadata;
   - copy new instructions into `new->insnsi`;
   - copy attach/BTF/license/name metadata into `new`;
   - take fresh refs for maps/BTF/kfuncs/security state through the same paths
     as program load;
   - run `bpf_check(&new, ...)`;
   - run `bpf_prog_select_runtime(new, ...)` so `new->bpf_func` points to a
     freshly allocated JIT image.
3. Do not call `bpf_prog_rejit_update_poke_tab()` and do not untrack
   `new->aux` poke state. The new aux belongs to the new live program.
4. Lock a global replacement mutex, then call owner replacement callbacks:
   - IDR replacement under `prog_idr_lock`;
   - PROG_ARRAY map slots under each map's `poke_mutex`;
   - cgroup/netns/perf/trampoline/XDP/sockmap/struct_ops/etc. under their
     native locks;
   - link slots and backing runtime slots together, never just `link->prog`.
5. Publish each slot with `xchg()`, `WRITE_ONCE()`, `rcu_assign_pointer()`, or
   `rcu_replace_pointer()` matching the owner.
6. For every slot replaced:
   - take a ref on `new` before publishing;
   - remove a ref from `old` after the slot no longer publishes old;
   - preserve RCU/tasks-trace grace periods required by that owner.
7. Register new kallsyms after the new object is published; old kallsyms are
   removed by normal old program free.
8. Put the old program through the standard path:
   `bpf_prog_put(old)` -> deferred put -> ID free if appropriate ->
   `__bpf_prog_put_noref()` -> `call_rcu()` / tasks-trace free.

### 4.2 Program ID and ABI

The requested design says: hold `prog_idr_lock`, replace references, old prog ID
becomes alias, new prog occupies that ID.

The minimal in-kernel mechanics are plausible:

- `old_id = old->aux->id`
- `new->aux->id = old_id`
- `idr_replace(&prog_idr, new, old_id)`
- set `old->aux->id` to `0` or a tombstone after no user-visible owner can
  query it

But ABI semantics are not solved by IDR replacement alone:

- An existing program FD has `file->private_data = old`, not an ID lookup.
- A bpffs pin owns a ref to the pinned object, not an ID lookup.
- `BPF_OBJ_GET` on an old pin would return the old object unless bpffs is
  converted to hold a stable handle.
- `BPF_PROG_GET_FD_BY_ID(old_id)` after IDR replacement returns a new FD for
  `new`, while already-open FDs still refer to `old`. That split is surprising
  for a "replace this program" syscall.

Upstream-friendly X1 should therefore introduce a stable logical program
handle if it wants FDs and pins to observe replacement:

```c
struct bpf_prog_handle {
	refcount_t refcnt;
	u32 id;
	struct bpf_prog __rcu *prog;
	struct mutex replace_mutex;
};
```

Then FDs, pins, and IDR name the handle, while execution owners that need raw
`struct bpf_prog *` still hold direct refs to the currently published program.
This is a larger ABI-internal refactor, but it is the clean way to make
"same FD/logical ID, new immutable program object" coherent.

If no handle is introduced, X1 must document that old FDs/pins keep seeing the
old program and only future ID lookups/attachments see the new program. That is
probably not the intended `BPF_PROG_REJIT` ABI.

### 4.3 Tail calls and poke descriptors

For PROG_ARRAY slots:

1. Find every `array->ptrs[key] == old`.
2. Lock `array->aux->poke_mutex`.
3. Recheck the slot.
4. Increment `new` ref and update membership counters.
5. `replaced = xchg(array->ptrs + key, new)`.
6. Call `map_poke_run(map, key, old, new)`.
7. Drop old's map ref and membership count.

This uses upstream's intended synchronization:

- the PROG_ARRAY slot is atomically replaced;
- callers' direct jumps are updated by map-poke machinery;
- `old->bpf_func` and `new->bpf_func` are both immutable, so
  `bpf_arch_poke_desc_update()` never sees a descriptor whose target was moved
  underneath it.

### 4.4 Failure and rollback model

Before publication, failures simply free `new`.

After partial publication, rollback is owner-level replacement in the reverse
direction, not mutation of `old` or `new`. The practical patch should avoid
partial publication by doing a two-phase replace:

1. prepare/validate every owner replacement and pre-take refs;
2. publish all slots in a deterministic order.

If any owner cannot be prepared, abort before publishing.

This is another reason an owner registry is preferable to ad hoc scans in
`syscall.c`.

## 5. Unified diff draft

This is an RFC skeleton only. It is intentionally not applied to the source
tree. The full version needs per-owner callbacks in the files listed in section
3.

```diff
diff --git a/kernel/bpf/syscall.c b/kernel/bpf/syscall.c
index 000000000000..000000000000 100644
--- a/kernel/bpf/syscall.c
+++ b/kernel/bpf/syscall.c
@@
-static int bpf_prog_rejit_update_poke_tab(struct bpf_prog *prog,
-					  struct bpf_prog *tmp)
-{
-	...
-	WRITE_ONCE(old_poke->tailcall_target_stable, false);
-	old_poke->tailcall_target = new_poke->tailcall_target;
-	old_poke->tailcall_bypass = new_poke->tailcall_bypass;
-	old_poke->bypass_addr = new_poke->bypass_addr;
-	old_poke->adj_off = new_poke->adj_off;
-	WRITE_ONCE(old_poke->tailcall_target_stable, true);
-	...
-}
-
-static void bpf_prog_rejit_untrack_tmp_pokes(struct bpf_prog *tmp)
-{
-	...
-}
-
-static int bpf_prog_rejit_poke_target_phase(struct bpf_prog *prog, bool add)
-{
-	...
-}
-
-static void bpf_prog_rejit_swap(struct bpf_prog *prog, struct bpf_prog *tmp)
-{
-	...
-	memcpy(prog->insnsi, tmp->insnsi, bpf_prog_insn_size(tmp));
-	prog->len = tmp->len;
-	smp_store_release(&prog->bpf_func, tmp->bpf_func);
-	...
-}
-
-struct bpf_prog_rejit_rollback_state {
-	struct bpf_insn *insnsi;
-	u32 len;
-	u64 load_time;
-};
-
-static int bpf_prog_rejit_prepare_rollback(...)
-{
-	...
-}
-
-static void bpf_prog_rejit_restore_rollback(...)
-{
-	...
-}
-
-static int bpf_prog_rejit_rollback(...)
-{
-	...
-}
+struct bpf_prog_rejit_repl {
+	struct bpf_prog *old;
+	struct bpf_prog *new;
+	u32 old_id;
+	bool id_replaced;
+};
+
+static DEFINE_MUTEX(bpf_prog_rejit_replace_mutex);
+
+static int bpf_prog_rejit_replace_idr(struct bpf_prog_rejit_repl *r)
+{
+	unsigned long flags;
+	int err = 0;
+
+	spin_lock_irqsave(&prog_idr_lock, flags);
+	if (r->old->aux->id != r->old_id || idr_find(&prog_idr, r->old_id) != r->old) {
+		err = -ESTALE;
+		goto out;
+	}
+
+	r->new->aux->id = r->old_id;
+	idr_replace(&prog_idr, r->new, r->old_id);
+	r->id_replaced = true;
+out:
+	spin_unlock_irqrestore(&prog_idr_lock, flags);
+	return err;
+}
+
+static void bpf_prog_rejit_restore_idr(struct bpf_prog_rejit_repl *r)
+{
+	unsigned long flags;
+
+	if (!r->id_replaced)
+		return;
+
+	spin_lock_irqsave(&prog_idr_lock, flags);
+	if (idr_find(&prog_idr, r->old_id) == r->new)
+		idr_replace(&prog_idr, r->old, r->old_id);
+	r->old->aux->id = r->old_id;
+	r->new->aux->id = 0;
+	spin_unlock_irqrestore(&prog_idr_lock, flags);
+}
+
+static int bpf_prog_rejit_replace_prog_array_refs(struct bpf_prog_rejit_repl *r)
+{
+	struct bpf_map *map;
+	u32 id;
+	int err = 0;
+
+	mutex_lock(&map_idr_lock);
+	idr_for_each_entry(&map_idr, map, id) {
+		struct bpf_array *array;
+		u32 key;
+
+		if (map->map_type != BPF_MAP_TYPE_PROG_ARRAY)
+			continue;
+
+		array = container_of(map, struct bpf_array, map);
+		for (key = 0; key < map->max_entries; key++) {
+			struct bpf_prog *old;
+
+			if (READ_ONCE(array->ptrs[key]) != r->old)
+				continue;
+
+			mutex_lock(&array->aux->poke_mutex);
+			old = READ_ONCE(array->ptrs[key]);
+			if (old == r->old) {
+				bpf_prog_inc(r->new);
+				old = xchg(array->ptrs + key, r->new);
+				map_poke_run(map, key, old, r->new);
+				bpf_prog_put(old);
+			}
+			mutex_unlock(&array->aux->poke_mutex);
+		}
+	}
+	mutex_unlock(&map_idr_lock);
+	return err;
+}
+
+static int bpf_prog_rejit_replace_owner_refs(struct bpf_prog_rejit_repl *r)
+{
+	int err;
+
+	err = bpf_prog_rejit_replace_idr(r);
+	if (err)
+		return err;
+
+	err = bpf_prog_rejit_replace_prog_array_refs(r);
+	if (err)
+		goto restore_idr;
+
+	/*
+	 * TODO: call registered owner callbacks:
+	 * cgroup, netns, bpf_link, perf_event, tracepoints/trampolines,
+	 * XDP netdev/driver state, sockmap/sk_psock, struct_ops, tcx/netkit,
+	 * LIRC, netfilter, classic tc, socket filters, reuseport,
+	 * flow dissector, lwt/seg6, devmap/cpumap.
+	 */
+
+	return 0;
+
+restore_idr:
+	bpf_prog_rejit_restore_idr(r);
+	return err;
+}
@@
 static int bpf_prog_rejit(union bpf_attr *attr)
 {
 	struct bpf_prog *prog, *tmp;
+	struct bpf_prog_rejit_repl repl;
 	...
@@
-	err = bpf_prog_rejit_update_poke_tab(prog, tmp);
-	if (err)
-		goto out_free_saved_poke;
-
-	bpf_prog_rejit_untrack_tmp_pokes(tmp);
-
-	err = bpf_prog_rejit_poke_target_phase(prog, false);
-	if (err)
-		goto out_free_saved_poke;
-
-	bpf_prog_rejit_swap(prog, tmp);
-
-	err = bpf_prog_rejit_poke_target_phase(prog, true);
-	if (err)
-		goto out_rollback;
-
-	new_bpf_func = prog->bpf_func;
-	err = bpf_trampoline_refresh_prog(prog);
-	if (err)
-		goto out_rollback;
-
-	if (prog->aux->st_ops_assoc) {
-		err = bpf_struct_ops_refresh_prog(prog, new_bpf_func);
-		if (err)
-			goto out_rollback;
-	}
-
-	err = bpf_prog_change_xdp(prog, new_bpf_func);
-	if (err)
-		goto out_rollback;
+	repl = (struct bpf_prog_rejit_repl) {
+		.old = prog,
+		.new = tmp,
+		.old_id = prog->aux->id,
+	};
+
+	mutex_lock(&bpf_prog_rejit_replace_mutex);
+	err = bpf_prog_rejit_replace_owner_refs(&repl);
+	mutex_unlock(&bpf_prog_rejit_replace_mutex);
+	if (err)
+		goto out_free_tmp;
+
+	/*
+	 * tmp is now the live immutable program object. The old program leaves
+	 * through the standard put/free path after all replaced owner refs have
+	 * been dropped.
+	 */
+	tmp = NULL;
@@
-	__bpf_prog_put_noref(tmp, prog_free_deferred);
+	if (tmp)
+		__bpf_prog_put_noref(tmp, prog_free_deferred);
 	return err;
 }
diff --git a/include/linux/bpf.h b/include/linux/bpf.h
index 000000000000..000000000000 100644
--- a/include/linux/bpf.h
+++ b/include/linux/bpf.h
@@
 struct bpf_link_ops {
 	...
+	int (*replace_prog)(struct bpf_link *link,
+			    struct bpf_prog *old_prog,
+			    struct bpf_prog *new_prog);
 };
diff --git a/kernel/bpf/arraymap.c b/kernel/bpf/arraymap.c
index 000000000000..000000000000 100644
--- a/kernel/bpf/arraymap.c
+++ b/kernel/bpf/arraymap.c
@@
+int bpf_prog_array_map_replace_prog(struct bpf_map *map, u32 key,
+				    struct bpf_prog *old_prog,
+				    struct bpf_prog *new_prog)
+{
+	struct bpf_array *array = container_of(map, struct bpf_array, map);
+	struct bpf_prog *old;
+
+	mutex_lock(&array->aux->poke_mutex);
+	old = READ_ONCE(array->ptrs[key]);
+	if (old != old_prog) {
+		mutex_unlock(&array->aux->poke_mutex);
+		return 0;
+	}
+
+	bpf_prog_inc(new_prog);
+	old = xchg(array->ptrs + key, new_prog);
+	map_poke_run(map, key, old, new_prog);
+	mutex_unlock(&array->aux->poke_mutex);
+
+	bpf_prog_put(old);
+	return 1;
+}
diff --git a/kernel/bpf/cgroup.c b/kernel/bpf/cgroup.c
index 000000000000..000000000000 100644
--- a/kernel/bpf/cgroup.c
+++ b/kernel/bpf/cgroup.c
@@
+int bpf_cgroup_replace_prog_ref(struct bpf_prog *old_prog,
+				struct bpf_prog *new_prog)
+{
+	/*
+	 * Walk bpf_prog_list and cgroup links under cgroup_mutex, replace
+	 * matching direct/link refs, then rebuild effective arrays.
+	 */
+	return -EOPNOTSUPP;
+}
diff --git a/kernel/events/core.c b/kernel/events/core.c
index 000000000000..000000000000 100644
--- a/kernel/events/core.c
+++ b/kernel/events/core.c
@@
+int perf_event_replace_bpf_prog(struct bpf_prog *old_prog,
+				struct bpf_prog *new_prog)
+{
+	/*
+	 * Non-tracing: replace event->prog under perf event locking.
+	 * Tracing: defer to tracepoint array replacement in bpf_trace.c.
+	 */
+	return -EOPNOTSUPP;
+}
diff --git a/net/core/dev.c b/net/core/dev.c
index 000000000000..000000000000 100644
--- a/net/core/dev.c
+++ b/net/core/dev.c
@@
+int bpf_xdp_replace_prog_global(struct bpf_prog *old_prog,
+				struct bpf_prog *new_prog)
+{
+	/*
+	 * Walk netdevices under RTNL, find dev_xdp_prog(dev, mode) == old,
+	 * and call dev_xdp_install() so driver private state is updated by
+	 * the same ndo_bpf path as normal attach/update.
+	 */
+	return -EOPNOTSUPP;
+}
```

## 6. Size estimate

Concrete estimate for a full X1 implementation that attempts to handle all
owners listed above:

- Deleted lines: about `560` LOC.
  - `syscall.c` in-place REJIT/poke/rollback machinery: about `360` LOC.
  - fork-specific trampoline/struct_ops/XDP refresh helpers and reverse indexes:
    about `200` LOC.
- Added lines: about `1,720` LOC.
  - new REJIT publisher and ID/FD/owner scaffolding: about `520` LOC.
  - per-owner replacement callbacks and registration: about `900` LOC.
  - focused selftests/debug asserts: about `300` LOC.
- Net: about `+1,160` LOC.
- Files changed: about `18` kernel files for core owner coverage:
  - `kernel/bpf/syscall.c`
  - `include/linux/bpf.h`
  - `kernel/bpf/arraymap.c`
  - `kernel/bpf/core.c`
  - `kernel/bpf/cgroup.c`
  - `kernel/bpf/net_namespace.c`
  - `kernel/bpf/mprog.c`
  - `kernel/bpf/tcx.c`
  - `kernel/bpf/trampoline.c`
  - `kernel/bpf/bpf_struct_ops.c`
  - `kernel/bpf/bpf_iter.c`
  - `kernel/trace/bpf_trace.c`
  - `kernel/events/core.c`
  - `net/core/dev.c`
  - `net/core/sock_map.c`
  - `drivers/net/netkit.c`
  - `drivers/media/rc/bpf-lirc.c`
  - `net/netfilter/nf_bpf_link.c`

If XDP driver-private references are patched individually instead of routed
only through `dev_xdp_install()`, the touched file count can exceed `35`.

## 7. Risks and uncertainties

### 7.1 Program ID preservation

`prog_id` is user-visible ABI. Reusing the old ID for the new object is likely
required for `BPF_PROG_REJIT`, but it conflicts with current lifecycle code:

- `bpf_prog_free_id()` removes the ID when the old object is put.
- Existing FDs/pins do not consult IDR on every operation.
- `BPF_PROG_GET_FD_BY_ID(old_id)` and an already-open old FD can diverge.
- `map_get_elem()` on PROG_ARRAY returns `ptr->aux->id`, so the order of
  IDR/slot replacement matters. The new prog must have the visible ID before
  the PROG_ARRAY slot is published.

Recommendation: introduce a stable logical handle if the ABI requires old
FDs/pins to observe the new program.

### 7.2 Attached links may require detach+reattach

Some link types have `.update_prog` today: cgroup, XDP, tcx, netkit, netns,
sockmap, iterator. Some do not: tracing/fentry/fexit/freplace, raw tracepoint,
kprobe multi, uprobe multi, perf event, struct_ops member links. Netfilter has
an update callback but returns `-EOPNOTSUPP`.

For X1, "replace `link->prog`" is insufficient. The runtime attachment backing
the link must be changed in the same critical section.

### 7.3 Perf event replacement

Perf has two materially different storage paths:

- non-tracing `event->prog`, read by overflow handler under RCU;
- tracing `event->tp_event->prog_array`, replaced by copied arrays and
  tasks-trace grace periods.

Both need owner-native replacement. A single generic `link->prog = new` would
leave the actual event running the old program.

### 7.4 Struct_ops replacement

Struct_ops stores member programs through links, but the registered kernel ops
point at generated trampoline image addresses. Replacing the member
`struct bpf_prog *` without rebuilding or replacing the struct_ops map leaves
registered callbacks pointing at old code.

The current fork added `bpf_struct_ops_refresh_prog()` as an in-place image
patch. X1 should delete that and rebuild/replace the relevant struct_ops member
trampoline through the normal map/link owner path.

### 7.5 XDP driver-private state

Many drivers cache `struct bpf_prog *` in private fields or per-queue fields.
Examples found include veth, virtio_net, ixgbe, mlx5, bnxt, tun, mana, ice,
i40e, igb, ixgbevf, mvneta, stmmac, and others.

X1 must not rewrite those fields directly. It must call the netdev `ndo_bpf`
install path under RTNL so driver reference ownership and queue synchronization
remain correct.

### 7.6 `prog->aux` backpointers and reverse indexes

The current implementation swaps subprogram `main_prog_aux`, `poke_tab`, and
`size_poke_tab` fields because it keeps old object identity. X1 must instead
make sure the new object has internally consistent aux/subprog pointers from
the verifier/JIT path and keep the old object's aux valid until old readers
finish.

### 7.7 Unsupported direct owners

Classic socket filters, LWT/seg6, flow dissector, reuseport, classic tc,
devmap/cpumap, and LIRC all store direct `struct bpf_prog *` references outside
the main `bpf_link` abstraction. Full X1 must either implement owner callbacks
for these or define explicit unsupported-owner behavior. Silent partial
replacement is worse than rejection.

## 8. Alternatives

### 8.1 Global mutex

A global mutex can serialize REJIT calls and map updates, but it does not
restore the upstream invariant. Existing readers and direct-poke descriptors can
still name old JIT addresses while the live `prog` object is mutated. This is
low upstream acceptability.

### 8.2 X2: hold map `poke_mutex`

Holding every affected PROG_ARRAY `poke_mutex` across the in-place swap would
target the observed tail-call race more directly. It is smaller than X1, but it
still mutates `prog->bpf_func`, still requires complete map discovery, and does
not address non-tail-call owners. It is a fork workaround, not an
upstream-friendly design.

### 8.3 X3: change `BUG_ON` / `-EBUSY` into retry

Retrying or weakening `BUG_ON` can hide the immediate crash but leaves stale
patch targets and does not restore the invariant. It risks silent wrong-code or
missed direct-poke updates. Upstream acceptability is very low.

### 8.4 Disable REJIT on tail-call users

This would avoid the current panic but violates the benchmark/fork rule that
REJIT must not paper over bugs by filtering app/program classes. It also does
not solve the general in-place mutation problem.

## 9. Recommended path

For upstream-shaped work, X1 should be split into two stages:

1. Introduce stable logical program identity or an owner replacement registry,
   and convert FDs/pins/IDR/link info to coherent semantics.
2. Convert `BPF_PROG_REJIT` publication to create a new immutable `struct
   bpf_prog` and replace owner refs through the registry.

For the current fork, X1 is the only design in this set that actually restores
the `prog->bpf_func` immutability invariant. It is also the largest design
because all `struct bpf_prog *` owners become part of the correctness boundary.

Upstream acceptance assessment: low for the current in-place REJIT, moderate
for an X1-style immutable-object replacement if it comes with coherent
FD/pin/ID semantics and per-owner replacement callbacks.

Implementation estimate: `25-35` engineer-days for full X1 with focused
selftests; `8-12` engineer-days only for a narrow corpus-oriented subset, but
that subset would not satisfy the "all references" requirement.
