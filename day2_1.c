#include <stdio.h>

int main()
{
	
	unsigned long long int a=0x1234567890abcdef,z=0,d=0,i,m=0;
	
	unsigned long long int S[]={0x3,0xF,0xE,0x1,0x0,0xA,0x5,0x8,0xC,0x4,0xB,0x2,0x9,0x7,0x6,0xd};
	unsigned long long int p[]={16,17,18,19,20,21,22,23,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,24,25,26,27,28,29,30,31};
	

	for(i=0;i<32;i+=4)
		z|=S[((((a&0xffffffff00000000)>>32)>>(28-i))&0xf)]<<(28-i);
	printf(" S-BOX output is - %llx \n",z);
	
	for(i=0;i<32;i++)
		d|=(((a&0x00000000ffffffff)>>i)&0x1)<<(p[i]);
	printf(" P-BLOCK output is - %llx \n",d);
	
	// m=(((d&0xffff000000000000)>>16))|(((d&0x0000ffff00000000)<<(32-16)));
	// m|=(((d&0x0000000000ffffff)<<8))|(((d&0x00000000ff000000)>>(32-8)));
	m=(z)|(d<<32);
	printf(" c-BLOCK output is - %llx\n",m);
	//printf("%llx\n",h[1]);
	return 0;
}	