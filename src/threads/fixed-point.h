#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

/*
Convert n to fixed point: 	n * f
Convert x to integer (rounding toward zero): 	x / f
Convert x to integer (rounding to nearest): 	(x + f / 2) / f if x >= 0,
(x - f / 2) / f if x <= 0.
Add x and y: 	x + y
Subtract y from x: 	x - y
Add x and n: 	x + n * f
Subtract n from x: 	x - n * f
Multiply x by y: 	((int64_t) x) * y / f
Multiply x by n: 	x * n
Divide x by y: 	((int64_t) x) * f / y
Divide x by n: 	x / n */

typedef int fixed_t;

#define SHIFT 14

#define CONV(n) ((fixed_t)(n << SHIFT))
#define CONV_INT(x) (x >> SHIFT)
#define CONV_NEAR(x)                                                           \
  (x >= 0 ? ((x + (1 << (SHIFT - 1))) >> SHIFT)                                \
          : ((x - (1 << (SHIFT - 1))) >> SHIFT))
#define ADD(x, y) (x + y)
#define SUB(x, y) (x - y)
#define ADD_INT(x, n) (x + (n << SHIFT))
#define SUB_INT(x, n) (x - (n << SHIFT))
#define MULT(x, y) ((((int64_t)x) * y) >> SHIFT)
#define MULT_INT(x, n) (x * n)
#define DIV(x, y) ((((int64_t)x) << SHIFT) / y)
#define DIV_INT(x, n) (x / n)
#endif
