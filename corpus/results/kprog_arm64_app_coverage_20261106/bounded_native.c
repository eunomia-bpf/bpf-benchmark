#include <stdint.h>
#include <stdio.h>
struct packet { void *data, *data_end; };
extern int bounded_dispatch(struct packet *);
extern int bounded_branch(struct packet *);
int main(void)
{
    for (unsigned kind = 0; kind < 2; kind++) {
      for (unsigned selector = 0; selector < 2; selector++) {
        uint64_t data[2] = {0, selector};
        struct packet packet = { data, (char *)data + sizeof(data) };
        int result = kind ? bounded_dispatch(&packet) : bounded_branch(&packet);
        printf("kind=%u selector=%u retval=%d result=%llu\n", kind, selector, result,
               (unsigned long long)data[0]);
        if (result != 2 || data[0] != 41 + selector)
            return 1;
      }
    }
    return 0;
}
