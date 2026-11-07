# Preserve the final service completion before shutdown

The service loader completes the kernel request before the service has
finished compressing its success archive and writing requests.jsonl. A
one-case native client returned16/retval2, after which immediate supervisor
termination discarded the final row and left the active request directory
in the enclosing archive. The original truncated archive is retained.

The worker now holds a private0600/CLOEXEC request.lock from request receipt
through specialization, kernel completion, archival and terminal logging.
After application exit the supervisor waits for that lock before terminating
the idle service. There is no polling, timeout, new application field,
capability handoff or relaxation of proof-upload rejection. Kernel/service
authorization and native/proof inputs are unchanged. Unexpected worker exit
releases the process-owned lock; the existing archive/error path remains.

12 existing metadata/lifecycle/ELF tests pass, with a worker fixture that
holds the lock through terminal compression/logging. The real same-input
one-case replay now preserves1 valid success archive,1 completed JSON row,
matching request/source/bound IDs, native16 and retval2. Both before/after
replays use the SAME private CMP candidate header; this validates teardown
durability, not canonical simulator admission or a performance improvement.
raw.tar.gz preserves both outcomes, exact scripts, header, source snapshots
and lifecycle checks. The separate CMP result owns its arithmetic/admission
evidence; this change modifies no simulator, workload, kernel or module.
