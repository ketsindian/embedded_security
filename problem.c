#include <stdio.h>

int main()
{
	
	unsigned long long int a=0x1234567890abcdef,z=0,d=0,i,m=0;
	
	unsigned long long int S[]={0x6,0x3,0xA,0x5,0xC,0x8,0x1,0xB,0x0,0xD,0x9,0xE,0xF,0x2,0x7,0x4};
	unsigned long long int p[]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
	
	for(i=0;i<64;i+=4)
		z|=S[((a>>(60-i))&0xf)]<<(60-i);
	printf(" S-BOX output is - %llx \n",z);
	
	for(i=0;i<64;i++)
		d|=((z>>i)&0x1)<<(p[i]);
	printf(" P-BLOCK output is - %llx \n",d);
	
	m=(((d&0xffff000000000000)>>16))|(((d&0x0000ffff00000000)<<(32-16)));
	m|=(((d&0x0000000000ffffff)<<8))|(((d&0x00000000ff000000)>>(32-8)));
	printf(" c-BLOCK output is - %llx\n",m);
	//printf("%llx\n",h[1]);
	return 0;
}	