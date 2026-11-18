# Original program FD is shared by normal and registered loads

Phase1 prototype binding stays ahead of further helper optimization. The
normal FD entry calls the existing original-program helper query only when
the manifest opt-in is true. Registered source-ID loads reopen a real FD
and use the same common companion-loading function, which also omits it.

The smallest owner-applied change queries in
`load_from_loaded_program_fd` and deletes the obsolete manifest flag,
assignment and guarded call. The existing endpoint returns the kernel's
actual `get_func_proto` result for the original program, including EXT's
destination operations. The draft patch is a review artifact in results;
the frozen core and manifest stay unchanged in this step.

This closes both routes that have a source FD using the existing module
protocol. A context-only registered request is a separate case: it supplies
type/attach metadata and has no original program object. The current query
requires a valid FD. Constructing a type-only fake program would lose aux
metadata, including extension-program destination context. Keep this case
explicit in the owner implementation and native-first coverage.

The current verified module is inspected for its source origin and helper
endpoint. The historical kinsn source and the current stock module have
different endpoint inventories, so use the actual staged module as evidence.
The reader also retains completed rows of the live checked Tracee service
with an explicit partial-run scope. It preserves every raw row and starts
zero guest, build or image. Patch context validation is separate from C++
compilation and kernel execution; the owner applies and tests the change.

2026-11-18T00:30:22Z — Prepared by ec0811470 with reader correction dfce2f466. The draft original-fd-query.patch adds one line in the existing common FD loader and deletes six obsolete opt-in lines in the loader/manifest. git apply --check passes against this checkout. This validates patch context; C++ compilation, guest behavior and prototype targets still need the owner-applied source change. Core, manifest, modules, canonical CLI, base and image remain unchanged here.

The source path is concrete:

- trusted_service.py:160–171 passes request.source_prog_id in the existing loader argv and passes the service descriptor through the existing subprocess.
- trusted_loader.cpp:46–49 reopens that ID with bpf_prog_get_fd_by_id and fills FdLoadOptions.original_prog_fd.
- native_loader.cpp:3978–3982 calls load_from_loaded_program_fd when that FD exists; the ordinary FD entry calls the same function at4193–4199.
- The common function at3033–3043 currently constructs CompanionLoad without context_helpers. Moving the query there covers both callers with the same original program and existing query implementation.
- native_lab_helper_query_impl.h:55–81 obtains the actual program, uses its actual aux/destination for EXT and calls get_func_proto. It requires a valid FD; type metadata alone supplies a different contract.

The current staged verified module's recorded origin is kprog/stock-path/module/kprog_stock.c and it contains helper_targets/native_lab_helper_query_impl.h. That current provider registers the endpoint at kprog_stock.c:322, and the timed direct-native provider includes the same implementation at direct-native/bpf_x86_native_lab.c:35. The historical kinsn module source lacks that endpoint, which is distinct from the current staged verified provider. A positive-source-ID fix therefore reuses the current providers, with zero new module API.

At this snapshot, the still-running Tracee service has33 completed request records, all33 with positive source IDs. There are31 status0 records (13 checked-sim-c,18 direct-native) and2 status-5 records; both errors stay in service-fd-coverage.json. One separate readiness record remains under control_records. This is partial run coverage, with neither whole-app success nor B/stock totals claimed. The first audit counted readiness as a context-only request; the corrected reader separates it and retains the first raw run.

Context-only requests remain an explicit source path at trusted_loader.cpp:57–64 and load_trusted_worker:3976–3983. The current completed Tracee records contain zero such requests. The draft FD patch leaves this path as it is; the owner needs separate binding through actual pinned program/context when that path is exercised. It must preserve attach/aux/EXT target semantics and native-first execution. A type-only fabricated program or a second userspace helper catalogue would change the contract. This follow-up is separate from the shared-FD fix and adds zero new refusal or validation gate here.

The next owner step is to apply the small draft under the existing core ownership/freeze exception, compile the loader, check both source-ID callers and actual contextual helper targets, then publish in its frozen image/check/affected-app batch with all LTO on. Existing helper-context-query-20261117 already records six TP/rawTP target changes across four BCC programs when the original query is enabled. Keep the source-ID-zero case open and report actual prototype coverage. Loaded bytes/per-call and body/helper/map effects remain measurements; the query itself runs at load time.

Raw final: /workspaces/kprog-raw/perf/helper-fd-boundary-20261118/host-20261118T002900Z-2835341; initial: /workspaces/kprog-raw/perf/helper-fd-boundary-20261118/host-20261118T002728Z-2834989. Hosts2834989 and2835341 ended0 and released all leases. Peer checked Tracee2754970 remains in progress, with every raw record preserved.
