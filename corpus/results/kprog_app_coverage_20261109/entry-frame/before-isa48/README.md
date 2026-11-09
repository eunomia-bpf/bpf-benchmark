Original-ABI complete ISA48 before cohort

Model9cbac28ec5d31bd689b5875820e2bf639af4fd25; driver829ba669b; kernel35ea2cde39fc original entry frame. Published case sources, assembly, manifests and expectations retain their bytes.

| Actual stage | Cases |
| --- | ---: |
| valid_executed | 10 |
| verifier_rejected | 34 |
| accepted_finding | 3 |
| specialization_rejected | 1 |

All48 per-name stages match the retained S17/x86-current outcomes. The three load-only accepted findings are uninitialized_stack, immediate_push_branch and stack_base_flags; unsafe native execution requests0. The existing checker returns1 after recording those findings; the guest returns1 and Make returns2. Complete raw outcomes, diagnostics, objects, input hashes, kernel config/build logs, loader/linker/module bytes and committed model headers/scripts are in raw.tar.gz. summary.json records exact runtime hashes and comparison rows.

Command, from repository master through bws.sh:

```sh
make -f corpus/results/kprog_app_coverage_20261109/entry-frame/Makefile isa48 REVISION=9cbac28ec5d31bd689b5875820e2bf639af4fd25 NATIVE_LINK=/var/tmp/kprog-tmp/C/stock-entry/native-link-before
```

The full315 upstream before cohort continues separately. The six-save candidate follows the matching patched kernel and stock-input declaration; this receipt records the original physical entry ABI.
