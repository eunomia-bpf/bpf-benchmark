extern unsigned char counts[], other[];
void *selected(unsigned *key) {
    return ((void *(*)(void *, const void *))1)(counts, key);
}
void *unselected(unsigned *key) {
    return ((void *(*)(void *, const void *))1)(other, key);
}
void *dynamic(void *map, unsigned *key) {
    return ((void *(*)(void *, const void *))1)(map, key);
}
