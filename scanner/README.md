# bpf-jit-scanner

`bpf-jit-scanner` is the userspace front end for BpfReJIT's v5 policy format.
It scans post-verifier xlated BPF bytecode for optimization sites, serializes
the results into a binary policy blob, and can trigger `BPF_PROG_JIT_RECOMPILE`
to apply the specializations to live kernel programs.

## Build

```bash
cmake -S scanner -B scanner/build -DCMAKE_BUILD_TYPE=Release
cmake --build scanner/build --target bpf-jit-scanner -j
# run unit tests
ctest --test-dir scanner/build --output-on-failure
```

The binary is produced at `scanner/build/bpf-jit-scanner`.

## Subcommands

### `scan` — analyze a BPF program for optimization sites

```bash
# Scan a BPF ELF object (auto-detects; tries to load and fetch kernel xlated,
# falls back to raw ELF instructions if loading fails)
bpf-jit-scanner scan prog.bpf.o --all

# Offline scan from raw xlated dump, write v5 blob
bpf-jit-scanner scan --xlated dump.bin --all --output policy.blob

# Emit a JSON site manifest (prog metadata + per-site entries)
bpf-jit-scanner scan prog.bpf.o --all --json

# Scan a single live program by id
sudo bpf-jit-scanner enumerate --prog-id 42 --json
```

### `enumerate` — scan all live BPF programs in the kernel

```bash
# List every loaded program with its site counts
sudo bpf-jit-scanner enumerate

# Enumerate and immediately apply BPF_PROG_JIT_RECOMPILE (with cost-model filter)
sudo bpf-jit-scanner enumerate --recompile

# JSON output
sudo bpf-jit-scanner enumerate --json

# Apply per-program policy YAML from a directory
sudo bpf-jit-scanner enumerate --recompile --policy-dir micro/policies/

# Limit to a single program by id
sudo bpf-jit-scanner enumerate --recompile --prog-id 42
```

`enumerate --recompile` applies a built-in cost model by default (see below).

### `apply` — compile filtered sites into a v5 blob

```bash
# Write a filtered blob from an object file
bpf-jit-scanner apply prog.bpf.o --all --output policy.blob

# Apply an explicit policy to offline xlated input
bpf-jit-scanner apply --xlated dump.bin --config policy.yaml --output policy.blob
```

For live kernel programs, use `enumerate --recompile` and optionally
`--prog-id <id>` / `--policy-dir <dir>`.

### `generate-policy` — emit a v3 policy YAML from detected sites

```bash
# Write YAML to stdout (pipe or redirect)
bpf-jit-scanner generate-policy prog.bpf.o --all > policy.yaml

# Write to a file
bpf-jit-scanner generate-policy --xlated dump.bin --all --output policy.yaml \
    --program-name my_prog
```

The output is a version 3 policy file that can be edited, committed, and passed
back to `compile-policy`, `apply`, or `enumerate --recompile --policy-dir`.

### `compile-policy` — compile a v3 YAML into a binary blob

```bash
# Produce a blob that matches only the sites in the policy file
bpf-jit-scanner compile-policy prog.bpf.o --config policy.yaml --output policy.blob

# Stream to stdout
bpf-jit-scanner compile-policy --xlated dump.bin --config policy.yaml > policy.blob
```

### `dump` — dump xlated bytecode from a live program

```bash
sudo bpf-jit-scanner dump --prog-fd 5 --output dump.bin
```

## The 7 Canonical Optimization Forms

| Flag | Form | What it does |
|---|---|---|
| `--rotate` | ROTATE | Replaces 3-insn rotate-via-shifts with `ROR`/`RORX` |
| `--wide-mem` | WIDE\_MEM | Replaces a byte-ladder of 4–8 `ldx/stx` with a single wide load/store |
| `--lea` | ADDR\_CALC | Replaces `shift + add` address calculations with `LEA` |
| `--cmov` | COND\_SELECT | Replaces if-then-else branch pairs with `CMOVcc` |
| `--bitfield-extract` | BITFIELD\_EXTRACT | Replaces `and + shift` bit-field extraction with `BEXTR` |
| `--endian` | ENDIAN\_FUSION | Replaces `ldx + bswap` or `bswap + stx` pairs with `MOVBE` |
| `--branch-flip` | BRANCH\_FLIP | Inverts a branch condition to eliminate a unconditional jump |

Use `--all` to enable all seven families at once.  Use individual flags to
restrict scanning to a subset.  `--rorx` additionally prefers the BMI2 `RORX`
variant over `ROR` where available.

## v3 Policy Format

```yaml
version: 3
program: my-prog-name   # matched against BPF program name
sites:
  - insn: 12            # instruction index in the xlated stream
    family: wide        # one of: rotate wide lea cmov extract endian branch-flip
    pattern_kind: wide-load-4
  - insn: 44
    family: rotate
    pattern_kind: rotate-64
```

JSON is accepted too (yaml-cpp parses both).  `generate-policy` produces this
format; edit the file to add or remove sites, then pass it to `compile-policy`
or `apply --config`.

## Cost Model (enumerate --recompile)

Three default rules guard against net-negative rewrites when using
`enumerate --recompile`:

| Rule | Default | Flag to override |
|---|---|---|
| Skip same-size forms (`endian`, `branch-flip`) — I-cache flush cost >= benefit | ON | `--no-skip-same-size` |
| Skip COND\_SELECT (`cmov`) — predictable branches: CMOV adds latency | ON | `--no-skip-cmov` |
| Skip a family when site\_count > 128 per program — dense recompile I-cache overhead dominates | 128 | `--max-sites-per-form N` (0 = disable) |

## Family Flags Reference

```
--all                Enable all families (default when no family flag given)
--cmov               COND_SELECT sites
--wide-mem           WIDE_MEM byte-ladder sites
--rotate             ROTATE idioms
--lea                ADDR_CALC / LEA sites
--bitfield-extract   BITFIELD_EXTRACT sites (alias: --extract)
--endian             ENDIAN_FUSION sites
--branch-flip        BRANCH_FLIP sites
--rorx               Prefer RORX (BMI2) over ROR for rotate sites
--v5                 No-op compatibility alias (scanner is already v5-only)
```

## Layout

```
scanner/
├── CMakeLists.txt
├── include/bpf_jit_scanner/
│   ├── pattern_v5.hpp      # v5 scan API: scan_v5_builtin(), build_policy_blob_v5()
│   ├── policy_config.hpp   # v3 policy load/filter, JSON manifest builder
│   └── types.h             # ABI constants (magic, version, CF_* family ids)
├── src/
│   ├── cli.cpp             # all subcommand implementations
│   ├── pattern_v5.cpp      # pattern matching engine
│   └── policy_config.cpp   # YAML/JSON config parser
└── tests/
    └── test_scanner.cpp
```
