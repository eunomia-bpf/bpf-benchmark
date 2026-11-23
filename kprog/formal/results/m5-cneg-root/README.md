# CNEG components through the actual root

Three additive imports in KProgFormal expose the original CNEG caller,
imported native alias and condition-site module. The last import transitively
exposes the actual GE helper and scalar-reader entry/return composition. The
existing V and ARM root imports remain intact.

Targeted ROOT MODULE build400 and twenty-one type/axiom queries through actual
import KProgFormal pass. These are the thirteen accepted initial interfaces,
three scalar-reader/return interfaces and five GE call-site interfaces.
Resource limits are the original200000/512 caps, one worker and32GiB; root
checks run on CPUs16–23/nice19 under the shared timing lock. Module builds
also serialize on the existing formal-full-check lock.

The first root module build passed. Its following query encountered a missing
X86RegisterReadEntry.olean during V's concurrent rebuild of that dependency.
The diagnostic is retained. Once the dependency was present, the targeted
root was rebuilt and all21 queries passed; no source premise or proof limit
was weakened. This was focused root integration, not a default/full build or
make-check. V retains sole ownership of the next whole confirmation, and its
previous DIV fault correspondence failure stays recorded.

Arithmetic, scalar writeback, top-level CNEG dispatch, actual generic frame
allocation/free and original eighth source/native prefix composition remain
open. The complete program prefix still ends at the seventh CSEL call. These
component/query counts do not count completed ISA families. M5/O1/O2/O4/M6
remain open; completed ISA families0. Axioms are standard logic plus the
existing imported Clight assumptions, with no new semantic axiom.
Raw: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
