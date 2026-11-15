/* The compiler emits the same anonymous RELRO map table seen in OTel. */
struct map_definition { unsigned long opaque[4]; };
#define MAP(N) struct map_definition map##N __attribute__((section(".maps")));
MAP(0) MAP(1) MAP(2) MAP(3) MAP(4) MAP(5) MAP(6) MAP(7)

void *map_pointer_table(const unsigned int *context)
{
    switch (*context) {
    case 0: return &map0;
    case 1: return &map1;
    case 2: return &map2;
    case 3: return &map3;
    case 4: return &map4;
    case 5: return &map5;
    case 6: return &map6;
    case 7: return &map7;
    default: return (void *)0;
    }
}
