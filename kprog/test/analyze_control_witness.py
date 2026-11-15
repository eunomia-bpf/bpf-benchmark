"""Correlate finite-control hardware release events with complete raw states."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct


def digest(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def require(condition, message):
    if not condition:
        raise ValueError(message)


def main(a):
    code_path = a.run / 'native-code.json'
    codes = json.loads(code_path.read_text())['forms']
    old_codes = json.loads((a.before / 'native-code.json').read_text())['forms']
    require(codes == old_codes, 'native instruction bytes/addresses changed')
    witnesses = {}
    witness_path = a.run / 'input-witnesses.jsonl'
    for line in witness_path.read_text().splitlines():
        row = json.loads(line)
        key = row['form'], row['case']
        require(key not in witnesses, 'duplicate hardware witness')
        witnesses[key] = row
    binary = a.run / 'cpu-states.bin'
    raw = memoryview(binary.read_bytes())
    require(bytes(raw[:8]) == b'KPFID002', 'unexpected raw-state format')
    state_bytes, memory_bytes, forms, cases = struct.unpack_from('<4I', raw, 8)
    require(state_bytes == 344 and memory_bytes == 256, 'unexpected x86 control state ABI')
    require(forms == len(codes), 'code metadata/trace form count differs')
    record_bytes = 16 + 3 * state_bytes + 3 * memory_bytes
    require(len(raw) == 24 + forms * cases * record_bytes, 'incomplete raw recording')
    flag_xors = Counter()
    words = releases = 0
    by_form = []
    for form, code in enumerate(codes):
        form_words = form_releases = 0
        for case in range(cases):
            key = form, case
            offset = 24 + (form * cases + case) * record_bytes
            j, c, base = struct.unpack_from('<IIQ', raw, offset)
            require((j, c) == key, 'unexpected raw case order')
            witness = witnesses.pop(key)
            require((witness['entry'], witness['end'], witness['stack_base']) ==
                    (code['pc'], code['next_pc'], base), 'hardware event identity differs')
            offset += 16
            native, sim = [raw[offset + i * state_bytes:offset + (i + 1) * state_bytes]
                           for i in (1, 2)]
            require(native[:256] == sim[:256], 'register mismatch')
            require(native[264:] == sim[264:], 'vector/stack/padding mismatch')
            flags = struct.unpack_from('<Q', native, 256)[0] ^ struct.unpack_from('<Q', sim, 256)[0]
            require(flags & 0x8d5 == 0, 'ISA-defined flag mismatch')
            flag_xors[flags] += 1
            memory = offset + 3 * state_bytes
            require(raw[memory + memory_bytes:memory + 2 * memory_bytes] ==
                    raw[memory + 2 * memory_bytes:memory + 3 * memory_bytes], 'external memory mismatch')
            measured = 0
            for event in witness['releases']:
                # Independently check the finite corpus's RET event: its one
                # released word is exactly the target read by the native CPU.
                # No simulator result supplies this target or input value.
                pc = event['pc']
                require(code['pc'] <= pc < code['next_pc'] and
                        code['native_bytes'][pc - code['pc']] == 0xc3, 'release was not hardware RET')
                require(event['new_sp'] == event['old_sp'] + 8, 'unexpected RET stack delta')
                require(len(event['words']) == 1, 'RET did not release exactly one word')
                word = event['words'][0]
                require(word['address'] == event['old_sp'] and word['width'] == 8 and
                        word['value'] == event['next_pc'], 'hardware RET word/target differs')
                lane = word['address'] - (base - 64)
                require(0 <= lane <= 56, 'hardware release outside observed arena')
                observed = struct.unpack_from('<Q', native, 280 + lane)[0]
                require(observed == word['value'], 'released hardware bytes differ at final observation')
                measured += 1
            require(measured == witness['word_count'], 'hardware word count differs')
            form_words += measured
            form_releases += len(witness['releases'])
        words += form_words
        releases += form_releases
        by_form.append(dict(form=form, cases=cases, releases=form_releases, words=form_words))
    require(not witnesses, 'hardware witnesses without raw cases')
    require(not (a.run / 'mismatches.jsonl').read_bytes(), 'driver recorded counterexamples')
    old_failures = [json.loads(line) for line in (a.before / 'mismatches.jsonl').read_text().splitlines()]
    require(all(0 <= row['form'] < forms and 0 <= row['case'] < cases for row in old_failures),
            'prior counterexample not exercised')
    result = dict(forms=forms, cases_per_form=cases, cases=forms * cases, mismatches=0,
        hardware_release_events=releases, hardware_input_words=words,
        prior_counterexamples_exercised=len(old_failures), native_code_spans_unchanged=len(codes),
        raw_flag_xor_histogram={hex(k): v for k, v in sorted(flag_xors.items())},
        per_form=by_form,
        scope='Finite x86 control corpus. Explicit hardware input witness; no complete ISA/AST/formal claim.',
        files=[dict(path=str(path), bytes=path.stat().st_size, sha256=digest(path)) for path in
               [code_path, witness_path, binary, a.before / 'native-code.json',
                a.before / 'mismatches.jsonl', a.run / 'mismatches.jsonl']])
    a.output.mkdir(parents=True, exist_ok=True)
    (a.output / 'analysis.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({key: value for key, value in result.items() if key not in {'per_form', 'files'}}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['run', 'before', 'output']:
        parser.add_argument('--' + name, type=Path, required=True)
    main(parser.parse_args())
