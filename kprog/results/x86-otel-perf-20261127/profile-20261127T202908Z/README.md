# Repaired-image check: guest startup failure

The sole image was successfully rebuilt as c103a86a with unchanged kernel/P inputs. The profile released its timing window on 2026-11-27T20:50:19Z with guest exit255: QEMU could not allocate pc.ram. No guest, app, unwind snapshot or timing result exists.

The refresh controller set a 48GiB hard address-space cap on itself before the image build, then launched the 64GiB guest through a descendant profile controller. The cap was inherited by QEMU. `startup-failure.json` records a reproduction: reserving 64GiB of anonymous virtual memory (without touching pages) fails under that cap and succeeds in the fresh unlimited operator environment. This explains the startup failure independently of physical pressure. The host snapshot had approximately74GiB MemAvailable.

The cap is now applied only to the image-build subprocess. The separate profile launcher records its inherited address-space limit as evidence. Compiler caps remain48GiB; the frozen guest/settings/kernel/image are unchanged. Retry only the failed check directly from the original operator environment; do not rebuild the already successful image. Failure receipts remain preserved. There is no per-call result or performance acceptance for this attempt.
