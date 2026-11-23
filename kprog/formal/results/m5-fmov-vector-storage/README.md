# Actual producer storage through FMOV writes

Typed original allocation separates the vector array from every differently named producer local. The two actual vector stores preserve every raw load of those locals. The actual Storage record retains the header, GPR/tag tables and cell permissions, SP, flag bindings and permissions, and all vector pointer slots. Every data/tag cell and each flag local keeps all successful and refused loads for every chunk and offset.

Focused build179 for actual vector storage transport and 5 public type/axiom queries pass at original200000/512 caps, shared timing, CPU17, one worker and32GiB. The query log records the exact imported axiom dependencies. V owns whole confirmation.
Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
