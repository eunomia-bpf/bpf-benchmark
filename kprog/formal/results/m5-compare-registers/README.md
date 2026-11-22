# Actual CMP call and complete register correspondence

`Arm64CompareRegisters` derives native X4/X1 from the same actual scalar/tag cells and the pre-call register relation. The actual returned source memory preserves every GPR/tag read, SP and all32 vector pairs, and its four actual flag bytes match the imported mature CMP update. The complete register relation retains pointer-origin/materialization bindings and uses either the current memory frontier or the original owned producer frontier.

`execute_caller_corresponds` joins one actual413-step call/body/free/return witness with the original417-step caller resumption and the same fetched/decoded mature native CMP step. Source permissions come from existing allocation-bound Storage; no extra native operands, flag readback or native-poststate assumptions are added. The result retains the original call's actual free/frame/release facts.

Exact source passed267 targeted jobs in 2.656312s and seven public type/axiom queries in 1.699310s, CPU17/nice0/j1/32GiB, default200000 heartbeats/depth512/async=false. Only logical axioms plus the existing imported CompCert external/assembly semantics. The intermediate register relation passed directly; caller wrappers exposed a world-name mismatch, fixed by naming the original linked-entry world, without raising limits. Full source snapshots/logs/history are in validation.json.

The complete original98input/setup/six-call entry and explicit cache/header integration remain open, as do W32/native, remaining families, physical memory/compiler correspondence, O1/O2/O4/M5 and M6. Complete ISA families remain zero. No runtime, loader, gate or benchmark change; this is not a new whole-library/root build claim.
