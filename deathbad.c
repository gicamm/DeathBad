#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void atom (char *prefix, int index, int deep, char alf[]);
int len(char str[]);

int main() {

	char alf[] = "abcdefghilmnopqrstuvzxjykw1234567890";
	//char alf[] = "abc";
	char more[] = "!@#$%^&*()-_=+/?.><,\";:[{]}";
	int index = 0;
	int deep = 5;

	char start[] = "";
	printf("--> %d\n", strlen(start));
	atom(start, index, deep, alf);
}

int len(char str[]) {
	return sizeof(str) / sizeof(char);

}


void atom (char *prefix, int index, int deep, char alf[]) {
	int i = 0;

	printf("processing %d \n", index);
	if (index > deep) {
		return;
	}

	//char *str = (char *) malloc (sizeof(char) * (len(prefix) + 1));

	char str[strlen(prefix) + 2];
	//printf("prefix: %s (%d)\n", prefix, len(prefix));
	//strncpy(str, prefix, len(prefix));
	strcpy(str, prefix);

	for (i = 0; i < strlen(alf); i++) {
		str[strlen(prefix)] = alf[i];
		str[strlen(prefix) + 1] = '\0';
		printf("%d: --> %s \n", index, str);
		atom (str, index + 1, deep, alf);
	}

	//free(str);

	return;
}
