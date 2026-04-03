from micro.catalog import DEFAULT_MICRO_MANIFEST, load_manifest


def test_tc_benchmarks_use_explicit_tc_program_names() -> None:
    manifest = load_manifest(DEFAULT_MICRO_MANIFEST)

    tc_bitcount = manifest.targets_by_name["tc_bitcount"]
    tc_checksum = manifest.targets_by_name["tc_checksum"]
    cgroup_hash_chain = manifest.targets_by_name["cgroup_hash_chain"]

    assert tc_bitcount.program_names == ("tc_bitcount_prog",)
    assert tc_checksum.program_names == ("tc_checksum_prog",)
    assert cgroup_hash_chain.program_names == ("cgroup_hash_chain_prog",)
