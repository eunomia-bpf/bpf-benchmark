"""Catch false partial-store reads and unsafe upper-byte/dead-store reuse."""
import json
from pathlib import Path
import tempfile
from analyze_spill_lifetimes import analyze


def main():
    cases = [
        ('partial_store_is_not_a_read', '''
    STD $r0, %stack.2, 0
    $r0 = LDD %stack.2, 0
    STW32 $w0, %stack.1, 0
    $w0 = LDW32 %stack.1, 0
''', True),
        ('upper_bytes_survive_partial_store', '''
    STD $r0, %stack.1, 0
    STD $r0, %stack.2, 0
    STW32 $w0, %stack.1, 0
    $r0 = LDD %stack.1, 0
    $r0 = LDD %stack.2, 0
''', False),
        ('dead_store_clobbers_live_slot', '''
    STD $r0, %stack.1, 0
    STD $r0, %stack.2, 0
    $r0 = LDD %stack.1, 0
''', False),
        ('upper_bytes_flow_across_branch', '''
    successors: %bb.1, %bb.2
    STD $r0, %stack.1, 0
  bb.1:
    successors: %bb.3
    STD $r0, %stack.2, 0
    STW32 $w0, %stack.1, 0
    $r0 = LDD %stack.2, 0
  bb.2:
    successors: %bb.3
  bb.3:
    $r0 = LDD %stack.1, 0
''', False),
    ]
    results = []
    with tempfile.TemporaryDirectory(prefix='spill-liveness-') as directory:
        path = Path(directory)/'fixture.mir'
        for name, body, pair in cases:
            path.write_text('''stack:
  - { id: 1, type: spill-slot, size: 8, alignment: 8, }
  - { id: 2, type: spill-slot, size: 8, alignment: 8, }
body:             |
  bb.0:
'''+body)
            result = analyze(path)
            if ([1, 2] in result['noninterfering_pairs']) != pair:
                raise ValueError('Wrong whole-slot reuse decision: '+name)
            results.append(dict(case=name, noninterfering=pair,
                                maximum_live_bytes=result['maximum_live_bytes']))
    print(json.dumps(results))


if __name__ == '__main__':
    main()
