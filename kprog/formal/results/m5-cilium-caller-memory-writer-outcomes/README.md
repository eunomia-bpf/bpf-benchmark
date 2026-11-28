# Provider outcome through the original memory writer

The same actual 202-step SP/R30 prefix reaches the linked kind-3 external
call. For every supplied outcome satisfying the stated current resources,
the theorem resumes that call, performs both return-cache writes and the
original writer, and reaches the original caller statement following it.
The complete provider trace is retained. The cache, data-word, payload and
tag stores are the concrete witnesses from this single execution.

The final heap has the returned base in the data word, zero in the payload,
the original tag word with its low byte replaced by 10, and SP=-32. These
observations use the same final tag-store heap as the execution conclusion.

Supplied access, SP, ABI, tag-table slot, R30 tag and current tag-word loads
remain explicit after the external call. Initial width8 also remains
explicit. The theorem neither establishes provider existence/purity nor
transports those resources from the pre-provider heap. Whole-entry resource
composition, native/global refinement and O1/O2/O4 remain open; M6 follows M5.

The prior writer-tail index cleanup receipt is retained. Its already pushed
commit was audited, its index matched that commit and had no live users,
and the shared index bytes were identical before and after removal. Raw
proof sources, failures and logs remain.
