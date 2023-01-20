#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, p, q, t, x1, x2;
	scanf("%lf%lf%lf", &a, &b, &c);
	t = b * b - 4 * a * c;
	if (t < 0)
		printf("没有实数根\n");

	else {
		p = -b / (2.0 * a);
		q = sqrt(t) / (2.0 * a);
		x1 = p + q;
		x2 = p - q;
		printf("有实根;x1=%5lf,x2=%5lf", x1, x2);
		return 0;
	}
}