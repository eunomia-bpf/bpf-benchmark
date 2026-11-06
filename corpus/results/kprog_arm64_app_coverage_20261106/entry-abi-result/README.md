# ARM entry ABI and stack writeback

ARM native-link now honors the existing --preserve-entry-abi option. Kernel
linking keeps the preserved proof entry ABI. When ordinary proof production
removes a paired save/restore, it retains pre/post-index SP writeback as the
corresponding SP ADD/SUB, including tail-call cleanup. This closes the lost
private-frame adjustment; no runtime guard or new option is added.

All71 Rust tests pass, including all four indexed pair forms with boundary
positive/negative offsets, exact preserved entry words, and stripped tail
cleanup. Both host and ARM release builds pass. Two real source/simulator/
generation-bound QEMU cases use a32-byte indexed frame, a local slot at+16,
and a real helper call with the packet pointer held in X19. Both return37,
retval2, generation1. The exact selected native proof is packaged alongside
the raw native ELF and simulator; inherited lookup cannot substitute it.

Run `make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile entry-abi-build PHASE=NEW_NAME`,
then the same Makefile's `fmov-bank-check PHASE=NEW_NAME`.
The replay archive includes all compiled/frozen inputs and matched portable
kernel/initrd; extract and run `make -C runtime run`, or on Spark add
`ACCEL=kvm CPU=host`. This is a functional ABI regression; complete six-app
workload runs and per-program certificates remain active work.
