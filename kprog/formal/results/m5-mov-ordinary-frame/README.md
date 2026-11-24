# Full register and caller-frame refinement of ordinary MOV calls

The same203-transition original linked call now carries the full architectural register/SP/vector/NZCV relation through actual allocation, both stores and final free. Source-derived allocated storage, all released permission ranges, exact caller continuation and every previous call contract stay explicit. The original producer frontier supplies the bound for transporting the unchanged owned cells through deallocation. The complete source caller frame and all canonical cache locals outside the selected register are preserved, and the same producer Storage is reconstructed from those actual effects.

Focused build 202 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
