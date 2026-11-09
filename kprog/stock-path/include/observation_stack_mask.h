/* SPDX-License-Identifier: GPL-2.0 */
/* Slot-set storage for the coordinator's larger-stack observation kernel. */
#ifndef KPROG_OBSERVATION_STACK_MASK_H
#define KPROG_OBSERVATION_STACK_MASK_H

#define KPROG_OBS_STACK_SLOTS (MAX_BPF_STACK / 8)
#define KPROG_OBS_MASK_WORD_BITS (sizeof(unsigned long) * 8)
#define KPROG_OBS_MASK_WORDS \
	((KPROG_OBS_STACK_SLOTS + KPROG_OBS_MASK_WORD_BITS - 1) / KPROG_OBS_MASK_WORD_BITS)

typedef struct {
	unsigned long bits[KPROG_OBS_MASK_WORDS];
} kprog_obs_stack_mask;

#define KPROG_OBS_INLINE static inline __attribute__((always_inline))

KPROG_OBS_INLINE kprog_obs_stack_mask kprog_obs_mask_zero(void)
{
	kprog_obs_stack_mask result = {};
	return result;
}

KPROG_OBS_INLINE kprog_obs_stack_mask kprog_obs_mask_all(void)
{
	kprog_obs_stack_mask result;
	unsigned int i;

	for (i = 0; i < KPROG_OBS_MASK_WORDS; i++)
		result.bits[i] = ~0UL;
	return result;
}

#define KPROG_OBS_MASK_BINARY(NAME, EXPR) \
KPROG_OBS_INLINE kprog_obs_stack_mask NAME(kprog_obs_stack_mask a, \
					  kprog_obs_stack_mask b) \
{ \
	kprog_obs_stack_mask result; \
	unsigned int i; \
	for (i = 0; i < KPROG_OBS_MASK_WORDS; i++) \
		result.bits[i] = (EXPR); \
	return result; \
}

KPROG_OBS_MASK_BINARY(kprog_obs_mask_or, a.bits[i] | b.bits[i])
KPROG_OBS_MASK_BINARY(kprog_obs_mask_and, a.bits[i] & b.bits[i])
KPROG_OBS_MASK_BINARY(kprog_obs_mask_andnot, a.bits[i] & ~b.bits[i])
KPROG_OBS_MASK_BINARY(kprog_obs_mask_xor, a.bits[i] ^ b.bits[i])
#undef KPROG_OBS_MASK_BINARY

KPROG_OBS_INLINE int kprog_obs_mask_empty(kprog_obs_stack_mask mask)
{
	unsigned int i;

	for (i = 0; i < KPROG_OBS_MASK_WORDS; i++)
		if (mask.bits[i])
			return 0;
	return 1;
}

KPROG_OBS_INLINE int kprog_obs_mask_equal(kprog_obs_stack_mask a,
					 kprog_obs_stack_mask b)
{
	unsigned int i;

	for (i = 0; i < KPROG_OBS_MASK_WORDS; i++)
		if (a.bits[i] != b.bits[i])
			return 0;
	return 1;
}

KPROG_OBS_INLINE void kprog_obs_mask_set(kprog_obs_stack_mask *mask,
					unsigned int slot)
{
	mask->bits[slot / KPROG_OBS_MASK_WORD_BITS] |=
		1UL << (slot % KPROG_OBS_MASK_WORD_BITS);
}

KPROG_OBS_INLINE void kprog_obs_mask_clear(kprog_obs_stack_mask *mask,
					  unsigned int slot)
{
	mask->bits[slot / KPROG_OBS_MASK_WORD_BITS] &=
		~(1UL << (slot % KPROG_OBS_MASK_WORD_BITS));
}

KPROG_OBS_INLINE int kprog_obs_mask_test(const kprog_obs_stack_mask *mask,
					unsigned int slot)
{
	return !!(mask->bits[slot / KPROG_OBS_MASK_WORD_BITS] &
		  (1UL << (slot % KPROG_OBS_MASK_WORD_BITS)));
}

KPROG_OBS_INLINE kprog_obs_stack_mask kprog_obs_mask_bit(unsigned int slot)
{
	kprog_obs_stack_mask result = {};
	kprog_obs_mask_set(&result, slot);
	return result;
}

#undef KPROG_OBS_INLINE
#endif
