# Reader proof batch confirmation, 2026-11-23

The accepted owned modules have all focused checks and42 actual-root type/axiom
queries passing; the targeted root build passes408 jobs. Their receipts retain
each exact statement and domain. Source commits include e6a8856ed,41de07e11,
2ee0fa7ca,d16bd17d7,f14dc5b12,e8073310a,1993d7208,3183ef1b1,81ec2f960,
09174c280,af320def5 and the transitive root integration d9846481e.

The sole full `make check` attempt stopped in the default Lean build at the
concurrent untracked `Arm64CnegNumeric.lean:383`: its simplifier reached the
original recursion limit512. This is FORMAL's ongoing numeric proof, which V
preserved. The semantic oracles did not run in this attempt. The earlier DIV
fault/assume(false) regression therefore remains recorded and unrechecked;
its safety assertion was not changed. This is a failed full confirmation,
not a passed `make check`.

See [validation.json](validation.json) and the compressed complete log. The
command used shared timing/full-check locks, CPU12-15nice19, one Lean worker
and32GiB at the original proof budgets. Ordinary metadata records any concurrent
input changes without copying or hashing sources. All original metadata, failed
attempts and full logs remain under
`/workspaces/kprog-raw/V/x86-alu-read-site-20261122`.

Next: FORMAL fixes its numeric proof at the original caps, then the existing
DIV correspondence defect needs a runtime correction. V continues the actual
XOR read-gate branches and handler/flags/writeback composition. Full ISA families
and dispatcher-step refinements remain unfinished.
