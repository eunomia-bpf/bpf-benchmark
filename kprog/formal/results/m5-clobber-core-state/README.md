# Actual saved environment and initialized flag shared across clobber callers

The common Saved state contains the actual caller Env, current actual-R0/copied-byte Packet, its real live Cur Freeable ranges and the same initialized Flag. The real memcpy Caller projects directly; the completed memset heap supplies its actual R0=-32, copied0, original allocation env and local rights from its actual access map. The original cache frame transports one supplied heap and the same flag. Each caller retains its own actual temp metadata.

Focused build 452 and 3 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
