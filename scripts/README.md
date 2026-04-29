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
BPFOPT_PASSES=map-inline,const-prop,dce scripts/per-pass-verify.sh 123 xdp
BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp
```

Dependencies:

- `bash`
- `diff`, `mktemp`, `cp`, `rm`
- `bpfget`
- `bpfopt`
- `bpfverify`
- `bpfrejit`

`BPFOPT_PASSES` accepts a comma-separated pass list. If unset, the script uses the v3 section 5 default order: `map-inline,const-prop,dce,skb-load-bytes,bounds-check-merge,wide-mem,bulk-memory,rotate,cond-select,extract,endian,branch-flip`.

Set `BPFOPT_DRY_RUN=1` to print the commands without executing the BPF CLI tools.
