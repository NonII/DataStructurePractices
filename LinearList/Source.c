
#include <stdio.h>

void func (int a) {
	printf ("func 1: %d", a);
}

int main (int argc, const char* argv[]) {

	printf ("hello world\n");

	func (1, 1, 1);

	getchar ();

	return 0;
}
