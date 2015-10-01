#include <stdio.h>
#define SAMPLERATE 44100.0
int main(int argc, char *argv[]) {
	float data, data2;
	int ct =0;
	FILE * f = fopen(argv[1],"r");

	while (!feof(f)) {
		fread(&data,sizeof(float), 1, f);
                fread(&data2,sizeof(float), 1, f);
		printf("%lf, %f\n", ct / SAMPLERATE, data);
		ct ++;
	}

	fclose(f);

}
