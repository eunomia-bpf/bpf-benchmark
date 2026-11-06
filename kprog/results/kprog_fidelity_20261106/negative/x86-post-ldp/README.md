# Preserved mixed-binding-tuple attempt

This attempted17-case replay has10 infrastructure errors,6 specialization
rejections and1 loader rejection. The ten errors are binding-seal `EINVAL`
failures from pairing the old static F probe/loader with a newer mutable shared
module. They do not count as safety rejections. Exact commands and messages
remain in `outcomes.json`; complete logs are retained in
`../x86-post-ldp-matched/raw-evidence.tar.gz`.

The successful matched-tuple replacement and its reproducible commands are
documented in `../x86-post-ldp-matched/README.md`, with16/17 actual rejections
and one accepted stack-base finding. No shared module or kernel was replaced.
