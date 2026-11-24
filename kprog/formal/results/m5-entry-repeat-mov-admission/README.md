# Original thirteenth fetch after twelve imported steps and pointer setup

The original input setup and all twelve actual decoded/fetched instruction steps transport the original code, PC and error to the repeated MOV. The CNT and UADDLV transitions reuse their imported LNSym refinements, and the intervening actual pointer setup uses its existing imported GPR write. The reached PC is the original PC+48, its error stays None and its fetched word is exactly the original thirteenth encoding. All decoder, literal and original-fetch obligations stay explicit. No independent intermediate control, program or fetch premise is introduced.

Focused build 328 and 1 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
