# Original tenth FMOV call and imported native step

The source proof extracts the actual call after ORN and binds all nine
original arguments: op35,dst0,src7,src2=3,src3=255,flags8,aux0,imm0.
It validates the complete generic frame entry, true caller invocation and
return to the untouched afterFmov successor. Native destination D3 is
encoded by src2 in this actual source form.

The native proof checks the original imported decoder for0x9e6700e3 and
executes LNSym's actual general FMOV conversion semantics. It writes X7
into D3 and clears upper64 using the imported write_sfp operation. The
fetched reference-step theorem retains histories,PC+4 and no-fault outcome.

Focused build258 and nine public type/axiom queries pass at original
200000/512 caps,CPU17,one worker,32GiB and shared timing lock. Native
statements use standard logic only; original caller execution also uses
existing Clight external-function/assembly assumptions. This is original
caller/native preparation. Complete source handler, actual vector stores
and tenth-call/native composition follow in M5. V owns whole confirmation.
Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
