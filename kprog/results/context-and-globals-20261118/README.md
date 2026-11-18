# Context-only prototype lifetime and BCC data-folding coverage

The common-FD query draft in helper-fd-boundary-20261118 covers the normal
and registered source-ID routes. This review follows the remaining
context-only case before choosing another helper optimization.

The successful verification phase creates a real B program FD in
native_loader.cpp:4062–4072. trusted_loader.cpp:73–76 reads its ID, calls
close_loaded_program and then prints JSON. close_loaded_program at
native_loader.cpp:4336–4344 closes the descriptor. The later Python phase
retains checked-simulator-verification.json (trusted_service.py:191),
with an ID and status rather than an owned FD. That ID supplies a diagnostic
identity; its lifetime in a later link step has no ownership guarantee.

The direct-native branch at trusted_service.py:192–199 also executes when
generation or stock verification fails. A future context-only prototype
fix must cover it, preserving the operator's native-first behavior. Making
successful B verification a prototype prerequisite would change that flow.
For source ID zero, kernel_facts uses the captured envelope at lines83–91;
the capsule source is populated only for a positive ID
(native_lab_trusted.h:140–147). Its GET_CONTEXT implementation at355–372
reads the original aux fields when that source exists. A type-only fake
program or a closed B verification ID cannot replace the source contract.
Any ownership/metadata change belongs to the frozen loader/service owner.

The independent performance check inventories actual BCC executable-section
relocations bound in each captured kernel plan. This checks the produced
code, alongside the source's immutable-global folding implementation.
Only code relocations count: debug and BTF references can retain a variable
name after all executable reads disappear. Remaining bindings may be maps
or mutable data, so the reader retains names/types/offsets and avoids
claiming frozen values from a symbol name alone. Source, compiler flags,
canonical tools, guests and the image stay unchanged.

2026-11-18T00:58:47Z — Inventory342c63366 completed all25 selected BCC requests, exit0 at00:49:34Z. There are zero executable relocations to target_family, target_pid or targ_tgid among symbols bound in the actual plans. inet_sock_set_state retains birth/events/idents map references, while its upstream source still has target_family/target_pid branches (tcplife.bpf.c:59/100). This is produced-code evidence consistent with scalar folding in those selected paths. The inventory scope is bound executable relocations, with neither a complete frozen-map snapshot nor a general proof that every config value folded.

LINUX_KERNEL_VERSION remains at three code relocations in three selected inputs: block_rq_issue, block_rq_insert and kprobe__cap_capable_exit. Their source reads are biosnoop.bpf.c:114/133 and capable.bpf.c:122. The existing add_known_kconfig_symbol_addrs at native_loader.cpp:2555–2567 sets an address and map ID for that scalar, and emits zero immutable_globals facts. The ordinary data-symbol path emits such facts at3015–3023. The LTO compiler consumes those facts through foldImmutableGlobals; Kconfig's special address path therefore leaves a fact gap.

The actual loader translation-unit fixture810308f77 compiled successfully and returned1 as recorded: mutable case `frozen=0 scalar_fact=absent contract=1`, frozen case `frozen=1 scalar_fact=absent contract=0`. It checks actual bytes01020304, pointer5678 and map ID3, so a hard-coded build/kernel version would fail the contract. The wrapper completed0 after recording this expected regression and generating an unapplied owner patch. git apply --check on that draft passes; the patched source has yet to be compiled or executed. The current production core stays unchanged.

The draft adds the already captured four scalar bytes to immutable_globals when the existing map metadata contains an immutable snapshot. It reuses the existing global name/address convention and adds zero new module API, benchmark knob, runtime switch or refusal. Its offset-zero convention is the same as the current address binder; a general Kconfig layout resolver would need actual variable offsets and is a separate scope. The existing singleton-map selection already requires value_size>=4, and load_map_meta_from_fd sizes immutable_value to that full value. Kernel map query marks this snapshot immutable only for read-only-to-program, frozen maps with zero writers (kprog_stock.c:225–228). libbpf freezes internal rodata/kconfig during map creation (libbpf.c:5314–5322), before program load at9019. The mutable path keeps its live read.

This is a small remaining binding/optimization opportunity and stays below the original-FD prototype correctness fix in priority. The three remaining static reads give neither a dynamic frequency nor a per-call gain. Installed bytes, body/helpers/maps and app time remain the owner batch measurements. Source, native-link, P flags, guests, base/image and the frozen workload stayed unchanged in this turn.

The separate context-only boundary has an ownership consequence: native_loader.cpp:4062–4072 creates a verified B FD, trusted_loader.cpp:73–76 reads its ID and explicitly closes it before printing, and close_loaded_program at4336–4344 closes the descriptor. The Python continuation's JSON ID has no ownership guarantee for a later prototype query. This remains true even though a kernel reference might temporarily keep an ID alive. The direct-native branch at trusted_service.py:192–199 also runs when B generation/verification fails, so using successful B verification as a helper-query prerequisite would violate the native-first contract. The owner must preserve actual program/attach/aux semantics for source-ID-zero requests using an explicit lifetime, independently of the completed common-FD draft. This review adds zero request, FD, protocol or extra program.

Raw inventory: /workspaces/kprog-raw/perf/context-and-globals-20261118/host-20261118T004934Z-2839427. Raw contract/draft: /workspaces/kprog-raw/perf/context-and-globals-20261118/kconfig-20261118T005310Z-2840330. Hosts2839427 and2840330 are terminal and all own leases are released. The live checked guest and its raw evidence are preserved.
