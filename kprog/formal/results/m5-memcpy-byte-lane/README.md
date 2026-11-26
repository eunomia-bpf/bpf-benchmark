# Original memcpy lane-zero switch and full byte loop

The original lane0 setup, real selectSwitch0, both shift assignments and genuine switch/break sequencing take nineteen internal transitions to the actual byte-store statement. Its real volatile store and two original loop exits retain the exact memory effect, readback, access and frontier.

Focused build 391 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
