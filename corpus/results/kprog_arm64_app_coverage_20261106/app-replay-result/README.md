# Built application replay for Spark

AppReplay.mk exports the existing application image and runs its unchanged
QEMU init/driver launch environment, preserving the generation-bound setting.
Only application selector, sample count, duration and BPF stats are selected
at replay time. The copied kernel and image contain the upstream app loaders,
all modules, native linker/loader and packaged proof manifests.

The v7 image was actually loaded/exported through `make prepare`, and the
portable launcher ran OTel's full v8 attempt through baseline measurement and
the recorded native-start failure. Those complete raw results are retained in
../runtime-context-v8/. The invalid first OTel selector remains recorded there.
Before subsequent runs the launcher archives its previous serial/host files.
The v9 launcher/kernel/environment have now been built; exact Make output is
retained here. Its image uses T's matching context-v2-exclusive-choice ARM
kernel/stock/modules/loader bundle, and the published9962aec5e shim.

../DGX-SPARK.md contains the transfer and actual six-app KVM command sequence,
with raw status/serial preservation for both BPF-stats settings. Actual Spark
hardware execution has not occurred. These built commands do not claim every
application proof or native counter comparison has already passed; those
failures continue through the coverage/repair queue.

The duplicate v7 export and superseded v8 root/image were removed after their
collected raw results and exact inputs were archived. Retirement inventories
are retained; only v9 is the current application runtime root/image.
