# CMP actual C flag values and imported native flags

`Arm64CompareFlagBytes` proves all four original CMP X64 `Call.flagValue` expressions equal the imported `AddWithCarry` Z/N/C/V bits zero-extended to the C unsigned scalar value. The source store order Z,N,C,V is explicit. `native_bits` reads those bits from the actual mature-model `Native.after` update; `native_value` joins the two. Operands are arbitrary; no flag/readback/native-poststate premise is introduced.

The actual C equality, nonzero sign masks and unsigned comparison are normalized through `CC.Val.ofBool`, using the previously checked subtraction/N/Z/C/V arithmetic. This is a value correspondence, and does not yet establish the entire returned-memory/register representation or the original six-call entry.

The exact source passed the 266-job targeted build in 2.231014s and three public type/axiom queries in 1.466546s, CPU16-23/nice19/j1/32GiB. Default 200000 heartbeats/depth512 and async=false. Only logical axioms; no new axioms or native decision oracle. `validation.json` records source/dependency/query hashes, logs and the first failed attempt. Timing CPUs0-7 stayed free.

Full source-memory/native state framing, actual sixth fetched instruction and original input/setup/six-call entry remain open. M5/M6 remain open; complete ISA families remain zero. No runtime, checked loader or gate change.
