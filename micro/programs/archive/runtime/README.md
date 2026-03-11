Archived runtime-only benchmark programs.

These `.bpf.c` files were removed from the active micro suite because they
measure map lookup or helper-call runtime mechanisms rather than pure JIT code
generation quality, and llvmbpf/kernel do not implement those paths in a
directly comparable way.

The active build only compiles `micro/programs/*.bpf.c`, so files in this
directory are preserved for history but excluded from `make -C micro programs`
and `python3 micro/run_micro.py --list`.
