/* Exercise real ABI parsing, chunking and direct upload; no replacement loader. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

static void require(bool condition, const char *message)
{
    if (!condition) fail(message);
}

static void host(const std::filesystem::path &output)
{
    const auto abi = output / "fixture.abi.tsv";
    { std::ofstream f(abi); f << "version\tnative-link-abi-v2\ncallee_saved_mask\t3\n"
        "load_site\t127,3,11\nload_site\t250,4,65535\n"; }
    std::vector<native_lab_load_site> sites;
    require(read_link_abi_file(abi, &sites) == 3 && sites.size() == 2, "direct ABI dropped sites");
    const auto ordinary = plan_blob_chunks(384, {});
    const auto chunks = plan_blob_chunks(384, {}, sites);
    require(ordinary[0].len == 128 && chunks[0].len == 127, "fault instruction split across chunks");
    const auto encoded = encode_load_sites(sites, chunks);
    require(encoded[0].empty() && encoded[1].size() == 16, "wrong site chunk");
    const std::vector<uint8_t> expected{0,0,0,0,3,0,11,0,123,0,0,0,4,0,255,255};
    require(encoded[1] == expected, "wire offsets/length/destination changed");
    const auto moved = plan_blob_chunks(384, {{126, 0}}, sites);
    const auto moved_sites = encode_load_sites(sites, moved);
    require(moved[0].len == 126 && read_u32_le(moved_sites[1].data()) == 1 &&
        read_u32_le(moved_sites[1].data()+8) == 124, "relocation/site rebasing changed");
    bool rejected = false;
    try { encode_load_sites({{383,3,11}}, chunks); }
    catch (const std::runtime_error &) { rejected = true; }
    require(rejected, "out-of-image site accepted");
    { std::ofstream f(abi); f << "version\tnative-link-abi-v2\ncallee_saved_mask\t0\n"; }
    sites.clear();
    require(read_link_abi_file(abi, &sites) == 0 && sites.empty(), "empty/default ABI changed");
    std::cout << "direct recovery host PASS: ABI, wire, chunk edge, call relocation, bounds, default\n";
}

static void kernel(const std::filesystem::path &output)
{
    std::ofstream result(output / "kernel-results.jsonl");
    for (unsigned test = 0; test < 3; ++test) {
        const bool fault = test == 1;
        LinkedBlob linked{};
        linked.blob.assign(119, 0x90);
        // R11 is a separate recovery status; the faulting MOV writes RCX.
        const uint8_t code[] = {0x41,0xbb,1,0,0,0, 0x31,0xff,
            0x48,0x8b,0x0f, 0x44,0x89,0xd8};
        linked.blob.insert(linked.blob.end(), std::begin(code), std::end(code));
        if (fault) linked.load_sites.push_back({127,3,11});
        else { linked.blob[127]=0x4c; linked.blob[128]=0x89; linked.blob[129]=0xd9; }
        auto loaded = upload_and_load_stub(linked, BPF_PROG_TYPE_SOCKET_FILTER,
            StubLoadAttrs{}, false, "recover_test", {});
        ScopedFd fd(loaded.prog_fd);
        unsigned char packet[64] = {};
        LIBBPF_OPTS(bpf_test_run_opts, run, .data_in=packet, .data_size_in=sizeof(packet), .repeat=1);
        if (bpf_prog_test_run_opts(fd.get(), &run)) fail("direct recovery TEST_RUN: " + std::string(strerror(errno)));
        const unsigned expected = fault ? 0 : 1;
        result << "{\"case\":" << test << ",\"fault\":" << (fault?"true":"false")
            << ",\"retval\":" << run.retval << ",\"expected\":" << expected << "}\n";
        result.flush();
        require(bool(result), "write direct recovery result");
        require(run.retval == expected, "fault did not clear selected R11 status");
    }
    std::cout << "direct recovery kernel PASS: default, cross-chunk R11 fault, reupload\n";
}

int main(int argc, char **argv)
try {
    if (argc != 3) fail("usage: recovery host|kernel OUTPUT");
    if (std::string(argv[1]) == "host") host(argv[2]);
    else if (std::string(argv[1]) == "kernel") kernel(argv[2]);
    else fail("unknown recovery mode");
    return 0;
} catch (const std::exception &error) { std::cerr << error.what() << '\n'; return 1; }
