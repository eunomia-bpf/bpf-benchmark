import io, os

os.chdir('/workspaces/repository')


def edit(path, pairs):
    t = io.open(path, encoding='utf-8').read()
    for a, b, n in pairs:
        assert t.count(a) == n, (path, a, t.count(a))
        t = t.replace(a, b)
    io.open(path, 'w', encoding='utf-8').write(t)


# The leaf's other branches call the kernel's own ktime_get_mono_fast_ns; name them for that.
edit('kprog/x86/native_lab/native_link/src/x86_ktime.rs', [
    ('let mut fallback = vec![', 'let mut kernel_call = vec![', 1),
    ('fallback.push(', 'kernel_call.push(', 2),
    ('for branch in fallback {', 'for branch in kernel_call {', 1),
    ('fn ktime_leaf_follows_the_kernel_formula_and_falls_back()', 'fn ktime_leaf_follows_the_kernel_formula_and_calls_the_kernel()', 1),
])
edit('kprog/x86/native_lab/native_link/fixtures/ktime_driver.c', [
    ('static uint64_t fallback(void) { return SENTINEL; }', 'static uint64_t kernel_ktime(void) { return SENTINEL; } /* the kernel\'s own ktime_get_mono_fast_ns */', 1),
    ('(void *)fallback', '(void *)kernel_ktime', 1),
    ('kernel fallbacks, %u vectors PASS', 'kernel calls, %u vectors PASS', 1),
])
print('rename ok')
