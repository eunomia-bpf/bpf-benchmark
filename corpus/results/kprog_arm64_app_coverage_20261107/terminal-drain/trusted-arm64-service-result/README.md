# ARM trusted-service terminal-request drain

The ARM QEMU supervisor now takes the same private `request.lock` that the published common service holds through native COMPLETE, archive creation and requests.jsonl logging. It signals the service while holding that lock, after the application returns. This closes the application-exit/archive race without changing kernel binding, native instructions, workload, simulator, compiler flags or service capabilities. A startup error still terminates the service; lock/open errors surface.

Actual existing control replay: QEMU0, guest0, native retval2, prebuilt_proof=false, one successful generation-bound request. The terminal JSON row points to a complete request archive; kernel ELF, generated native ELF and receipt identity agree. The request lock is private0600. Exact hashes and receipt data are in native-identity-audit.json; complete runtime/compiler/loader evidence is in the original run archive. All launch source hashes stayed unchanged during this control. Shared service dependency is 63a9fea5b.

The already running BCC guest used its old loaded supervisor and was preserved. Future queued application boots consume the fixed ARM teardown. This control is not full application or universal safety acceptance; all remaining application failures are retained separately.
