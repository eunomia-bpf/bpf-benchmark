# Scripts

## per-pass-verify.sh

`per-pass-verify.sh` is the bpfopt-suite v3 section 4.3 reference implementation for running optimization passes one at a time with verifier rollback. It reads a live program's original bytecode with `bpfget`, runs each `bpfopt` pass, verifies changed candidates with `bpfverify`, keeps only verifier-accepted candidates, and finally applies the result with `bpfrejit`.

Usage:

```bash
scripts/per-pass-verify.sh PROG_ID PROG_TYPE
```

Examples:

```bash
scripts/per-pass-verify.sh 123 xdp
BPFOPT_PASSES=const-prop BPFOPT_VERIFIER_STATES=states.json scripts/per-pass-verify.sh 123 xdp
BPFOPT_PASSES=map-inline BPFOPT_MAP_VALUES=map-values.json BPFOPT_MAP_IDS=7,9 scripts/per-pass-verify.sh 123 xdp
BPFOPT_PASSES=rotate,branch-flip BPFOPT_TARGET=target.json BPFOPT_PROFILE=profile.json scripts/per-pass-verify.sh 123 xdp
BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp
```

Dependencies:

- `bash`
- `diff`, `mktemp`, `cp`, `rm`
- `bpfget`
- `bpfopt`
- `bpfverify`
- `bpfrejit`

`BPFOPT_PASSES` accepts a comma-separated pass list. If unset, the script uses the zero-side-input default subset: `dce,skb-load-bytes,bounds-check-merge,wide-mem`.

To run passes that need side inputs, set `BPFOPT_PASSES` and the matching environment variables:

- `BPFOPT_TARGET` becomes `bpfopt --target`
- `BPFOPT_VERIFIER_STATES` becomes `bpfopt --verifier-states`
- `BPFOPT_MAP_VALUES` becomes `bpfopt --map-values`
- `BPFOPT_MAP_IDS` becomes `bpfopt --map-ids`
- `BPFOPT_PROFILE` becomes `bpfopt --profile`

For the current `bpfopt` implementation, `const-prop` requires `BPFOPT_VERIFIER_STATES`, `map-inline` requires both `BPFOPT_MAP_VALUES` and `BPFOPT_MAP_IDS`, kinsn-lowering passes such as `rotate`, `cond-select`, `extract`, `endian`, and `bulk-memory` require `BPFOPT_TARGET`, and `branch-flip` requires `BPFOPT_PROFILE`.

Set `BPFOPT_DRY_RUN=1` to print the commands without executing the BPF CLI tools.
