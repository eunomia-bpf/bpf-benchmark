BCC and Katran ARM public-helper replay

Shared loader dc120a8eb/ARM buildba6e31c1 uses the existing public helper-call relocation route for trusted native P. The native compiler is the optimization boundary; direct-native optimizer hints retain their own path. Runtime88-helper simulator8eac3b42a and paired88a Image/module remain captured. Complete original BCC/Katran native manifest rows and source objects are retained.

BCC reuses its existing23-program real-event two-start workload: original four stressors plus TCP/fsync/queued libaio, owned256MiB ext4 virtio disk,2GiB/two vCPU16-19. Katran follows serially on16-19/8GiB/eight vCPU with its original workload. Every raw per-program/work counter and service/verifier stage is retained. QEMU timings supply functional evidence. Runtime admission additions:0.
