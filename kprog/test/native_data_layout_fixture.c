/* Deliberate host padding differs from the test's loaded BPF DATASEC offsets. */
const volatile unsigned char enabled = 1;
const volatile unsigned int threshold __attribute__((aligned(32))) = 77;
const volatile unsigned short ports[3] __attribute__((aligned(16))) = {1, 2, 3};
volatile unsigned int counter = 3;
volatile unsigned int limit __attribute__((aligned(32))) = 9;
unsigned long tracker;
unsigned int generation __attribute__((aligned(32)));
