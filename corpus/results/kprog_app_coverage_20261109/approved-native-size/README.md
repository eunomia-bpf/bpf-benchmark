# Approved native submission extent at copy time

Coordinator decision2026-11-09 06:55UTC authorizes E2BIG at native_size1GiB or greater. The shared SUBMIT/SUBMIT_RESOURCES path now returns that error after copying the request structure and before capsule allocation, source lookup and native-byte allocation/copy. The boundary is inclusive1U<<30 and the public u32 request field retains its wire layout. Both ISAs consume this shared header.

This is the explicit approved arithmetic boundary for S12 successful source cursor reasoning. S12 retains the complete ordinary-image and allocator arithmetic premises in its universal row. The submitted P and same-copy JIT path retain their definitions for smaller inputs. Existing application guest epochs retain their bytes; a private incremental x86 module build and boundary-ioctl guest follow. Added production predicates: exactly the approved native_size boundary.
