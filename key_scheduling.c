#include <stdio.h>


	
unsigned long long int S[]={0x6,0x3,0xA,0x5,0xC,0x8,0x1,0xB,0x0,0xD,0x9,0xE,0xF,0x2,0x7,0x4};
unsigned long long int p[]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};



unsigned long long int s_block(unsigned long long int y,unsigned int size)
{
	unsigned long long int z=0;
	unsigned int i;
	if (size==64)
	{
		for(i=0;i<64;i+=4)
				z|=S[((y>>(60-i))&0xf)]<<(60-i);
			printf(" S-BOX output is - %llx \n",z);
			return (z);
	}
	else if(size==32)
	{
		for(i=0;i<32;i+=4)
				z|=S[((y>>(28-i))&0xf)]<<(28-i);
			printf(" S-BOX output is - %llx \n",z);	
			return (z);
	}
	else if(size==8)
	{
		for(i=0;i<8;i+=4)
				z|=S[((y>>(4-i))&0xf)]<<(4-i);
			printf(" S-BOX output is - %llx \n",z);	
			return (z);
	}

}

unsigned long long int p_layer(unsigned long long int x,unsigned int size)
{
	unsigned int i;
	unsigned long long int d=0;
	if(size==64)
	{
		for(i=0;i<64;i++)
			d|=((x>>i)&0x1)<<(p[i]);
		printf(" P-layer output is - %llx \n",d);
		return (d);
	}
	else if(size==32)
	{
		for(i=0;i<32;i++)
			d|=((x>>i)&0x1)<<(p[i]);
		printf(" P-layer output is - %llx \n",d);
		return (d);
	}
}



int main(void)
{
	unsigned long long int a=0x1234567890abcdef,z=0,d=0,m=0,c=0;
	unsigned long long int k[]={0x0000000000000000,0x0000000000000000};
	unsigned long long int h[]={0x0000000000000000,0x0000000000000000};
	unsigned int i;
	for(i=0;i<32;i++)
	{
		
		h[0]=(k[1]>>(64-13) | k[0]<<13);
		h[1]=(k[0]>>(64-13) | k[1]<<13);
		
		h[1]=((h[1]&0xffffffffffffff00) | s_block((h[1]&0x00000000000000ff),8));
		
		h[1]=(h[1]&0x07ffffffffffffff | (((h[1]&0xf800000000000000)>>59)^(i&0x1f))<<59);
		printf("  output is - %llx  ",h[0]);
		printf("%llx\n",h[1]);
		k[0]=h[0];
		k[1]=h[1];
	}
}	