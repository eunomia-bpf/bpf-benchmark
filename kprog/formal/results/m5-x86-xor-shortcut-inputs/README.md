The genuine matched-register/lane XOR call reaches the flags stage in77
actual transitions and derives all six tail inputs, including result zero,
from the actual shortcut and ALU helper. It needs no register-reader call
or assumed numerical result. This holds for every effective width.

Focused build180 and two public type/axiom queries pass at original
200000/512 budgets, j1 and32GiB inside shared timing. Existing external
function/assembly assumptions remain. Byte-tail/canonical composition follows.
