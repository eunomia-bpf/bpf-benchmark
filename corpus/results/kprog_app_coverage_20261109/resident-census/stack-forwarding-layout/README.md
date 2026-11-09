Whole-word forwarding layout selection

The existing x86 layout analysis records whole-word reads, POP and internal return words. The generator declares forwarding cells for those aligned locations. Unknown aliases and private helper-copy sources retain the complete cell layout. The raw stack byte arena and every simulator instruction body retain their source. The selection changes declarations through the existing optional forwarding-cell mechanism.

| Original resident ID | Entry | Complete cells | Selected cells | Other generated lines equal |
| ---: | --- | ---: | ---: | --- |
| 100 | generic_kprobe_process_filter | 35 | 33 | True |
| 101 | generic_kprobe_event | 23 | 19 | True |
| 102 | generic_kprobe_process_event | 63 | 63 | True |
| 103 | generic_kprobe_setup_event | 11 | 4 | True |
| 104 | generic_kprobe_actions | 29 | 18 | True |
| 105 | generic_kprobe_output | 21 | 19 | True |
| 106 | generic_kprobe_process_event | 63 | 63 | True |
| 107 | generic_kprobe_process_filter | 35 | 33 | True |

Eight captured native proof objects generate successfully; six rows use smaller forwarding layouts. The two compiler-failing process_event rows retain all63cells because their existing alias analysis reaches an unknown read. Their compiler storage frontier remains open. Four layout fixtures cover a direct stack load, POP, a stack alias and an unknown alias, retaining the prior stack extent in each case.

The generated macro-call counter in job.log includes the initial diagnostic offset; result.json counts each emitted M(index) call directly. Compilation and stock-verifier outcomes follow separately. The active275 model and queued274 model retain their captured revisions. Runtime admission predicates added:0.
