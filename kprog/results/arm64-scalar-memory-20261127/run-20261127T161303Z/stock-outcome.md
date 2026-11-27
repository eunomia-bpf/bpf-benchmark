# ARM scalar-memory paired verifier outcomes

{
  "all": {
    "requests": 145,
    "before": {
      "accepted": 28,
      "refused": 117
    },
    "after": {
      "accepted": 45,
      "refused": 100
    },
    "transitions": {
      "accepted -> accepted": 28,
      "refused -> refused": 100,
      "refused -> accepted": 17
    },
    "after_families": {
      "infinite loop": 25,
      "context layout": 1,
      "typed field layout": 1,
      "modified context pointer": 1,
      "unbounded memory access": 1,
      "scalar memory access": 8,
      "packet bounds": 13,
      "unclassified": 1,
      "map value bounds": 12,
      "stack bounds": 26,
      "jump sequence complexity": 11
    },
    "fixture_before_disagreements": 0
  },
  "original_refused": {
    "requests": 117,
    "before": {
      "refused": 117
    },
    "after": {
      "refused": 100,
      "accepted": 17
    },
    "transitions": {
      "refused -> refused": 100,
      "refused -> accepted": 17
    },
    "after_families": {
      "infinite loop": 25,
      "context layout": 1,
      "typed field layout": 1,
      "modified context pointer": 1,
      "unbounded memory access": 1,
      "scalar memory access": 8,
      "packet bounds": 13,
      "unclassified": 1,
      "map value bounds": 12,
      "stack bounds": 26,
      "jump sequence complexity": 11
    },
    "fixture_before_disagreements": 0
  },
  "accepted_controls": {
    "requests": 28,
    "before": {
      "accepted": 28
    },
    "after": {
      "accepted": 28
    },
    "transitions": {
      "accepted -> accepted": 28
    },
    "after_families": {},
    "fixture_before_disagreements": 0
  },
  "apps": {
    "bcc/set": {
      "requests": 23,
      "before": {
        "accepted": 11,
        "refused": 12
      },
      "after": {
        "accepted": 11,
        "refused": 12
      },
      "transitions": {
        "accepted -> accepted": 11,
        "refused -> refused": 12
      },
      "after_families": {
        "infinite loop": 9,
        "context layout": 1,
        "typed field layout": 1,
        "modified context pointer": 1
      },
      "fixture_before_disagreements": 0
    },
    "cilium/agent": {
      "requests": 17,
      "before": {
        "accepted": 3,
        "refused": 14
      },
      "after": {
        "accepted": 3,
        "refused": 14
      },
      "transitions": {
        "accepted -> accepted": 3,
        "refused -> refused": 14
      },
      "after_families": {
        "packet bounds": 13,
        "unclassified": 1
      },
      "fixture_before_disagreements": 0
    },
    "katran": {
      "requests": 1,
      "before": {
        "accepted": 1
      },
      "after": {
        "accepted": 1
      },
      "transitions": {
        "accepted -> accepted": 1
      },
      "after_families": {},
      "fixture_before_disagreements": 0
    },
    "otelcol-ebpf-profiler/profiling": {
      "requests": 8,
      "before": {
        "refused": 7,
        "accepted": 1
      },
      "after": {
        "accepted": 6,
        "refused": 2
      },
      "transitions": {
        "refused -> accepted": 5,
        "refused -> refused": 2,
        "accepted -> accepted": 1
      },
      "after_families": {
        "unbounded memory access": 1,
        "scalar memory access": 1
      },
      "fixture_before_disagreements": 0
    },
    "tetragon/observer": {
      "requests": 85,
      "before": {
        "refused": 75,
        "accepted": 10
      },
      "after": {
        "refused": 65,
        "accepted": 20
      },
      "transitions": {
        "refused -> refused": 65,
        "accepted -> accepted": 10,
        "refused -> accepted": 10
      },
      "after_families": {
        "infinite loop": 16,
        "map value bounds": 12,
        "stack bounds": 24,
        "jump sequence complexity": 11,
        "scalar memory access": 2
      },
      "fixture_before_disagreements": 0
    },
    "tracee/monitor": {
      "requests": 11,
      "before": {
        "accepted": 2,
        "refused": 9
      },
      "after": {
        "accepted": 4,
        "refused": 7
      },
      "transitions": {
        "accepted -> accepted": 2,
        "refused -> refused": 7,
        "refused -> accepted": 2
      },
      "after_families": {
        "scalar memory access": 5,
        "stack bounds": 2
      },
      "fixture_before_disagreements": 0
    }
  }
}

145pairedloads:28beforeacceptances preserved,17newacceptances,100refusals,no preparationerrors or fixture-before disagreements. Classification refinement labels12explicit map-value bounds and11jump-sequence complexity diagnostics. All statuses are unchanged; initial_summary/initial_family preserve earlier labels, while controller.json and archived source snapshots retain the original experiment classifier. One Cilium typed store at physical sk_buff offset134 lacks a precise diagnostic and remains unclassified; no read-only cause is inferred. Fresh maps are verifier fixtures, not live binding/native/stage2 or startup/performance acceptance.
