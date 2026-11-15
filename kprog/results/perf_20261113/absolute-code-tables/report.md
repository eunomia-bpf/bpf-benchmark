# Full-pointer code tables on the unified native flags

2026-11-15. a3bba686a compiles a label-address fixture with the common native
flags. It emits `LEA; JMP [base+index*8]` and eight `R_X86_64_64` entries in
`.data.rel.ro`. The existing c500 linker fails, treating the code pointers as
map/data capabilities. The original diagnostic and native disassembly are in
`before`. This is a standalone pipeline fixture, not an application result.

c3ae14b00 preserves each slot as a code identity tied to an actual rewritten
instruction. The proof retains eight full-pointer relocations. Kernel linking
emits eight image-pointer records, with byte offsets into the final image.
4c975b57b extends the existing finite CODE-target lowering to this form: it
captures the index into the private table-base register, retains the original
index and case bodies, and checks that eliminating the table-base value loses
no observable register/flag result. No optimization option is disabled.

Validation completed:

- 43 Rust tests pass, with one existing ignored test. They include all eight
  rewritten targets and rejection of a pointer into an instruction.
- 1,024 actual native host executions and 1,024 full shared-simulator executions
  match the independent case expressions. Native returns are checked at 64
  bits; the generated entry's 32-bit return is checked at its declared ABI.
  5b2f7829e additionally checks all 72 context bytes remain unchanged after
  each execution, and this run passes too. These are entry-output/context
  checks, not complete CPU-state observations. The normal bounds/MIR/all-pairs/
  llc B compile succeeds.
- Relative-table regression passes 320 native and 320 shared-C executions,
  plus both existing private-register/flag refusal cases. A separate sliced
  relative table passes normal B compilation and 64 shared-C cases.
- fab1c7550/9cf1eb8ad exercise the published CLI: its proof bytes equal the
  tested library proof and all eight image-pointer records match. Another
  1,024 native/shared-C/context set and normal B compile pass through those
  actual CLI outputs. The first invocation omitted the mandatory load-site
  ABI output argument; that failure remains in `cli-roundtrip`.

The first Python check failed to find the canonical specializer module;
470688882 fixes its import path. Both attempts remain recorded. Production P
flags, source producers, the shared simulator header and all LTO are unchanged.
The new dispatch form is supported directly, without an opt-in/off path.

d16064f1a updates the sole kernel pointer to **bdfa49b694e1**. Its x86 JIT
resolves kind12 to `image_base + target`, checks the target lies inside the
image, and uses the existing eight-byte slot bound check. The canonical
kernel/module rebuild and metadata boot finished successfully at12:23:57UTC.
The kernel config SHA is unchanged. Current boot image SHA starts7037d167;
`kernel/after-sha256.txt` records complete hashes. c53de8aad selects the new
boot's actual BTF/kallsyms for layout facts. The runtime container image was
not rebuilt by this work.

**Resource incident:** the kernel publisher held image EX but nevertheless
overlapped C's live timing guest from12:23:08 to12:23:57UTC, including the
4GiB metadata guest. Relying on the lock without explicit live-guest ordering
violated the resource contract. The process/lock observations and before/after
artifact hashes are retained in `resource-overlap.json` and adjacent files.
C's affected run carries this overlap caveat and its original kernel hash;
its raw data and processes were preserved. Subsequent publication961621 waited
for C's entire timing supervisor948426 to exit, then took image EX and completed
at12:38:50UTC. This does not establish that C's batch completed successfully.
The image-lease helper47fa5f7ca was invoked after that owner had already exited
and returned immediately; it did not protect the earlier live batch.

The canonical CLI is now **dbac8784**, with loader4e1a3af7, bounds5236d0ea
and checked compiler907b671d unchanged. The initial stock check961920 used
the older table-context client and failed its argument contract, before
  verification. 4bad0ac65 selects the existing production-input-map-aware client;
964453 then succeeds on the sole kernel: generated B program3/type2,
360 translated bytes/178 JIT bytes, private input map1. Both attempts remain
recorded. This is a stock load, without KPROBE execution or P installation.
Checked native installation using kind12, real applications and performance
remain pending. C owns the direct timing module; its kind12 image-base binding
requirement was sent through coordination.

The final B object SHA21e223e7 is byte-identical to the object actually accepted
in the stock guest; `accepted-byte-identity.json` binds both records. Runtime
image2aed63ff is unchanged. The new kernel BTF SHA9813a701 differs from the
earlier87b89a97; application CO-RE audits need the current BTF. The boot layout
measurements are retained; they do not substitute for the per-app audit.

Completed Make targets: `absolute-table-forms` (original failure),
`absolute-table-source`, `absolute-table-b`, `jump-table-check`,
`shared-table-b`, `absolute-image-kernel`, `publish-normal-pair` and
`absolute-table-stock`, in
`kprog/test/native-relocations.mk`. Exact commands, results, failures,
timestamps and hashes stay under
`/workspaces/kprog-raw/perf/20261115-absolute-code-tables`. Compiler products
remain in the single canonical build directories; this receipt archives only
observations and logs. The raw manifest is a timestamped snapshot. No
throughput, per-call or body-speed gain is claimed.
