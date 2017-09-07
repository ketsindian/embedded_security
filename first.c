#include <stdio.h>

int main()
{
	//unsigned int i;
	unsigned long long int a=0x12,z=0,d=0,f=0,c=0,i;
	unsigned long long int k[]={0xfff1000000000000,0xfff1000000000000};
	unsigned long long int h[2];
	//unsigned int i;
	//long long int ref0[]={0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xA,0xB,0xC,0xD,0xE,0xF};
	unsigned long long int S[]={0x3,0xF,0xE,0x1,0x0,0xA,0x5,0x8,0xC,0x4,0xB,0x2,0x9,0x7,0x6,0xd};
	unsigned long long int p[]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
	//unsigned long long int b[]={3,4,0,1};
	for(i=0;i<64;i+=4)
		z|=S[((a>>(60-i))&0xf)]<<(60-i);
	printf(" S-BOX output is - %llx \n",z);
	
	for(i=0;i<64;i++)
		d|=((a>>i)&0x1)<<(p[i]);
	printf(" P-BLOCK output is - %llx \n",d);
	
	// a=0x12345678;
	// for(i=0;i<32;i+=8)
	// 	f|=((a>>(24-i))&0xff)<<((b[i/8])*8);
	f=((a&0xff000000)>>8|(a&0x00ff0000)<<8|(a&0x0000ff00)>>8|(a&0x000000ff)<<8);
	printf(" P-BLOCK output is - %llx \n",f);

	c=((a<<16)&0x0f)|((a>>(32-16))&0xf0);
	printf(" c-BLOCK output is - %llx \n",c);

	h[0]=(k[1]>>(64-12) | k[0]<<12);
	h[1]=(k[0]>>(64-12) | k[1]<<12);
	printf(" c-BLOCK output is - %llx",h[0]);
	printf("%llx\n",h[1]);
	return 0;
}	