# Descriptor-stable feature-probe classification

The existing raw-tracepoint feature-probe rule now uses the framework's descriptor-normalized policy identity. Its previous raw-byte hash captured map descriptor 7; another process received descriptor 6 and reached native manifest lookup. The same existing feature probe follows its ordinary kernel startup path across descriptor assignments.

The production change replaces one predicate field and its matching identity constant. Existing program-type, anonymous-name, attachment, instruction-count and feature-probe behavior remain in the common classifier. The normalized hashing mechanism is shared by every captured program.

The generic classifier matrix executes 33,094 checks per source version. The previous condition produces 257 descriptor-identity and 64 metadata-boundary mismatches; the updated condition produces zero mismatches. Four map pseudo kinds each span 4,096 descriptors, retaining normalized identity while preserving instruction offset distinctions. Both complete x86 and AArch64 shim builds exit 0 through the existing Makefile. Raw source snapshots, extracted-function harnesses, commands, logs and binaries are retained; the initial unused-function harness compilation diagnostic is archived. The full shim builds retain their recorded compiler warnings.

Existing application jobs keep their binary inputs. The staged Tetragon replay consumes the corrected common classifier after its predecessor jobs close. Runtime coverage and universal safety theorem responsibilities remain separately recorded in the common application results.
