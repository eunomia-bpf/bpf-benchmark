# Captured ARM exclusive retry inventory

{
  "all": {
    "requests": 145,
    "requests_with_retry": 70,
    "retry_sites": 216,
    "simple_four_instruction_sites": 216,
    "distinct_sources_with_retry": 33
  },
  "apps": {
    "bcc/set": {
      "requests": 23,
      "requests_with_retry": 9,
      "retry_sites": 10,
      "simple_four_instruction_sites": 10,
      "distinct_sources_with_retry": 9
    },
    "cilium/agent": {
      "requests": 17,
      "requests_with_retry": 11,
      "retry_sites": 32,
      "simple_four_instruction_sites": 32,
      "distinct_sources_with_retry": 11
    },
    "katran": {
      "requests": 1,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    },
    "otelcol-ebpf-profiler/profiling": {
      "requests": 8,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    },
    "tetragon/observer": {
      "requests": 85,
      "requests_with_retry": 50,
      "retry_sites": 174,
      "simple_four_instruction_sites": 174,
      "distinct_sources_with_retry": 13
    },
    "tracee/monitor": {
      "requests": 11,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    }
  },
  "original_families": {
    "context layout": {
      "requests": 1,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    },
    "infinite loop": {
      "requests": 11,
      "requests_with_retry": 11,
      "retry_sites": 20,
      "simple_four_instruction_sites": 20,
      "distinct_sources_with_retry": 10
    },
    "modified context pointer": {
      "requests": 1,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    },
    "packet bounds": {
      "requests": 11,
      "requests_with_retry": 9,
      "retry_sites": 27,
      "simple_four_instruction_sites": 27,
      "distinct_sources_with_retry": 9
    },
    "read-only typed object store": {
      "requests": 3,
      "requests_with_retry": 2,
      "retry_sites": 5,
      "simple_four_instruction_sites": 5,
      "distinct_sources_with_retry": 2
    },
    "scalar memory access": {
      "requests": 63,
      "requests_with_retry": 38,
      "retry_sites": 150,
      "simple_four_instruction_sites": 150,
      "distinct_sources_with_retry": 10
    },
    "stack bounds": {
      "requests": 25,
      "requests_with_retry": 10,
      "retry_sites": 14,
      "simple_four_instruction_sites": 14,
      "distinct_sources_with_retry": 2
    },
    "typed field layout": {
      "requests": 1,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    },
    "unbounded memory access": {
      "requests": 1,
      "requests_with_retry": 0,
      "retry_sites": 0,
      "simple_four_instruction_sites": 0,
      "distinct_sources_with_retry": 0
    }
  }
}

All145 generatedB sources were checked by SHA against the original recovered-input receipt; no compiler, guest, source, flag or framework changed. Counts refer to requests and sites, with distinct C source hashes reported separately. The inventory recognizes native instruction structure; it does not establish a safe atomic-block replacement or infer the final verifier family. The actual Tetragon1 retry diagnosis remains f5d34434a. Full paired stock outcomes and queued Tetragon stage2 are collected separately.
