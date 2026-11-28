# Original caller volatile tag read-modify-write

This checks the exact original s80 pointer, volatile Mint64 read, copy and volatile Mint64 store. It uses the same linked caller environment and actual allocated8-byte stack_tag block2.

At the explicit s80 entry ti=0, ts=0, store_tag=10, a current numeric64-bit tag word is read using imported VolatileLoadSem.nonvol. The original expression computes (old & ~255) | 10; current allocation permissions derive the actual aligned store, readback, other-block/caller/access/frontier frames. Both builtins use their actual Step2 relations and compose with original sequence transitions in Star(E0). The exact pointer/t176/tv temporary updates are retained.

The current supplied tag-word resource is preserved through the SAME real return-cache, word and payload stores by actual allocation-name separation. Provider outcomes may change the heap; earlier zero initialization is not used to assume current numeric contents or provider purity.

The outer tag-loop/index/shift setup, its continuation and composition with the prior164internalprefix remain open. This result does not claim provider existence, native I-O/whole-state or whole-program refinement. Historical coverage counts remain unchanged. Full receipts/logs and public axiom queries are retained; Lean checks use the existing timingSH/CPU17/j1/nice0/32GiB/default proof budgets.

The first direct attempt failed because temporary environment definitions depended on exported noncomputable identifiers, followed by realization/frame errors; the address proof had a redundant rfl and load-argument specialization was unused. Full stage1.log.gz and stage1-failure.json retain actual source/receipt/log history. Stage2 marks those same definitions noncomputable and adjusts only these proof applications; no semantics, premises or proof budget changes.
