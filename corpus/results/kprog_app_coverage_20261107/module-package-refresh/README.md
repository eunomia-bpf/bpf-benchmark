# Corpus runtime module package refresh

The incremental module build, installation, current shim build and image build
completed successfully. The refreshed canonical image is `sha256:a5b0b2b0db2ef3d5cd94a518a28992bbea976227a06ee3d935acc5367b459d6f`.
The boot image remains `2f127f70ddf3fce4b90c8ad38a3b83ced0a7de701ff55b55961291d7874218b6`; its current vmlinux SHA is
`76c6adc50151a4a7f8ab5591b353c27bcb1d404609fb7d56c00c861efc58bc02`. The image carries842 kernel modules and15 matching
native modules.

Image module dependency, alias, soft dependency and builtin metadata match a
fresh depmod of the exported module tree byte for byte. Module lookup succeeds
for tunnel4, ip_tunnel, ipip, ip6_tunnel, nf_tables and nfnetlink. The extracted
scsi_common and tunnel4 files match their package SHA records, and their BTF
sections equal the current built module BTF sections. Existing app startup
supplies the subsequent live BTF and module-loading observations.

The image includes A's descriptor-stable feature-probe classification through
the incremental shared x86 shim build. Its SHA is `57021180e83d81cce9a1009d277be2a0a1462a77121d906c0035b9f193d6666c`.
The existing corpus workloads and original native inputs retain their captured
sources; package-inputs.json records the full image input epoch.

R's current timing guest retains its image on a separate captured Docker disk.
Host image refresh advances the application queue independently. The original
idle scheduling controls and completed module build log remain in the archive;
replacement queue3653317 runs Katran, Tetragon, Tracee and Cilium serially on
20–23 with eight guest vCPUs,12GiB, one sample and duration two seconds.
Whole-OTel private generic stack replay3653318 follows that queue.

observations.json records image/module/index identities and raw lookup results.
raw.tar.gz records build and image logs, scheduling history, extracted image
metadata and two module files, and the complete package input manifest.
Its SHA is `cd42fb7a8edb672331577e98fe09dd5cc3c8cb4b63376cc1ec7d9d46c3de86df`. Application runtime coverage will be published from each
closed batch with its actual source and image identities.
