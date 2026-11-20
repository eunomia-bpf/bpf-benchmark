# Existing frontend

`make clight-sources` uses the installed `external/clean/clightgen` and fails if it is absent. The automatic CompCert dependency, proof, extraction and frontend builds are removed under the 2026-11-20 operator instruction. Export commands and flags are unchanged.

The dry run and actual regeneration pass; all 23 generated Lean exports are byte-identical to their immediately preceding files. Hashes and commands are in validation.json; complete output stays in the raw directory recorded there. This checks source export, not M5 completion.
