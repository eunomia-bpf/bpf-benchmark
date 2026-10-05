# map_inline fix verification report (2026-03-26)

## Command

Ran:

```sh
make vm-static-test STATIC_VERIFY_ARGS='--mode macro' TARGET=x86
```

Exit status: `0`

## Artifact

- Result JSON: `daemon/tests/results/static_verify.json`
- Generated at: `2026-03-27T00:42:57.675836+00:00`
- Matcher fix commit under test: `d9e2ccd`

## Summary

From `daemon/tests/results/static_verify.json`:

- mode: `macro`
- objects: `477`
- programs: `1178`
- verifier_accepted: `215`
- programs_applied: `104`

## map_inline result

Checked the artifact in three ways:

1. Counted records with `map_inline` in `passes_applied`.
2. Counted records where the `map_inline` pass had `changed=true`.
3. Summed `map_inline.sites_applied` across successful program records.

Observed result:

- programs with `map_inline` applied: `0`
- records with `map_inline changed=true`: `0`
- total `map_inline` sites applied: `0`

For sanity, the run did apply other passes, including:

- `live_patch`: `80` programs
- `const_prop`: `42`
- `dangerous_helper_firewall`: `32`
- `endian_fusion`: `30`
- `dce`: `15`
- `wide_mem`: `15`
- `cond_select`: `10`
- `extract`: `2`

## Conclusion

The pattern-matcher fix in `d9e2ccd` did not make `map_inline` appear in macro corpus `vm-static-test`. The applied count remains **0**, so issue `#500` is still open.
