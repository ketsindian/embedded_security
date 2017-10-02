#include <stdio.h>

unsigned long long int a=0x1234567890abcdef,z=0,d=0,i,m=0,c=0;
	
unsigned long long int S[]={0x6,0x3,0xA,0x5,0xC,0x8,0x1,0xB,0x0,0xD,0x9,0xE,0xF,0x2,0x7,0x4};
unsigned long long int p[]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};

unsigned long long int s_block(unsigned long long int y,unsigned int size)
{
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

}

unsigned long long int p_layer(unsigned long long int x,unsigned int size)
{
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

unsigned long long int c_shift(unsigned long long int a,unsigned int size,unsigned int shift,unsigned int dir)
{
	if(size==64 && dir==0)
	{
		c=((a<<shift))|((a>>(64-shift)));
		printf(" c-BLOCK output is - %llx \n",c);
	}
	else if(size==64 && dir==1)
	{
		c=((a>>shift))|((a<<(64-shift)));
		printf(" c-BLOCK output is - %llx \n",c);
	}
	else if(size==32 && dir==0)
	{
		c=((a<<shift))|((a>>(32-shift)));
		printf(" c-BLOCK output is - %llx \n",c);
	}
	else if(size==32 && dir==1)
	{
		c=((a>>shift))|((a<<(32-shift)));
		printf(" c-BLOCK output is - %llx \n",c);

	}
}

int main(void)
{
	z=s_block(a,64);
	d=p_layer(z,64);

}	
