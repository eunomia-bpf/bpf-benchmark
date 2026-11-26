# Original memset selected tag-transfer stores

The actual s106 body executes at each selected transfer position, 64 and 72. Its original COPY-zero branch ladder executes in 25 transitions; the real tag packing and header-pointer setup executes in 13. The source's own volatile read into t78, copy into tv6 and volatile Mint64 store through tp6 execute at offset8 with shifts0 and8. Both real store equations remain explicit even when the observed zero tag word is written back as zero. Current Resources supply the actual writable range; imported allocation separation and store semantics retain all24 zero tag bytes, all16 previously written data bytes, current architectural Storage/SP and all31 register observations, header view, permissions, allocation frontier and outside-tag memory. Single-store transports use the actual tag store and original allocation names. Complete sequential transfer composition, original clobber/provider/free/caller execution and remaining M5/O1/O2/O4/recount/M6 follow. Original C, exports, imported ISA/specification and earlier public interfaces remain.

Focused build 342 and 9 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
