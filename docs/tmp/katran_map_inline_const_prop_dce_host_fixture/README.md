# Katran Host Fixture Code

This directory archives the temporary host fixture used for the Katran
`map_inline -> const_prop -> dce` investigation on 2026-05-13.

Files:

- `Cargo.toml`: standalone Cargo package for the fixture.
- `src/main.rs`: the Katran-specific chain runner.
- `loader_body.rs`: helper code extracted from `bpfopt/loader/src/main.rs` at
  the time of the experiment.
- `capture_chain_jit.gdb`: gdb script used to stop at `run_bpftestrun()` and dump
  the live host JIT image before the verifier-loaded fd is closed.

The runner hardcodes the repo path `/home/yunwei37/workspace/bpf-benchmark` and
writes its workdir to `/tmp/bpfopt-katran-mapinline-const-dce`. It loads
`bpfopt/testobject/katran_balancer.bpf.o`, populates Katran maps, applies the
four hardcoded inline hints, verifies the post-`map_inline` program with
`log_level=2`, then runs `const_prop` and `dce`.

Build and run from the repo root:

```sh
cargo build --manifest-path docs/tmp/katran_map_inline_const_prop_dce_host_fixture/Cargo.toml
sudo -n docs/tmp/katran_map_inline_const_prop_dce_host_fixture/target/debug/katran-chain-runner
```

To capture the live JIT:

```sh
sudo -n gdb -q -batch \
  -x docs/tmp/katran_map_inline_const_prop_dce_host_fixture/capture_chain_jit.gdb \
  --args docs/tmp/katran_map_inline_const_prop_dce_host_fixture/target/debug/katran-chain-runner
```

This is a developer fixture only. It is not the corpus benchmark path and does
not replace `make corpus`.
