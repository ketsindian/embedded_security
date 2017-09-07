#include <stdio.h>

//ANU Design
/*
	Design of key generator

	--->>>>64 bit IP					128 bit	key IP<<<-----
	|		|_								|				 |
	|		|^|------last 64 bits-----------|				 |
	|		|								|				 |	
	^		|								|				 |
	^		S-BOX 						key	scheduler		 ^
	|		P-layer 						|				 ^
	|		|								|				 |
	|		|								|				 |
	---<<---64 bit IP 					128 bit key IP -------
*/


unsigned long long int S[]={0x2,0x9,0x7,0xE,0x1,0xC,0xA,0x0,0x4,0x3,0x8,0xD,0xF,0x6,0x5,0xB};
unsigned long long int p[]={20,16,28,24,17,21,25,29,22,18,30,26,19,23,27,31,11,15,3,7,14,10,6,2,9,13,1,5,12,8,4,0};



unsigned long long int s_block(unsigned long long int y,unsigned int size)
{
	unsigned long long int z=0;
	unsigned int i;
	if (size==64)
	{
		for(i=0;i<64;i+=4)
				z|=S[((y>>(60-i))&0xf)]<<(60-i);
			//printf(" S-BOX output is - %llx \n",z);
			return (z);
	}
	else if(size==32)
	{
		for(i=0;i<32;i+=4)
				z|=S[((y>>(28-i))&0xf)]<<(28-i);
			//printf(" S-BOX output is - %llx \n",z);	
			return (z);
	}
	else if(size==8)
	{
		for(i=0;i<8;i+=4)
				z|=S[((y>>(4-i))&0xf)]<<(4-i);
			//printf(" S-BOX output is - %llx \n",z);	
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
		printf(" cipher output is - %llx \n",d);
		return (d);
	}
	else if(size==32)
	{
		for(i=0;i<32;i++)
			d|=((x>>i)&0x1)<<(p[i]);
		printf(" cipher output is - %llx \n",d);
		return (d);
	}
	else if(size==8)
	{
		for(i=0;i<8;i++)
			d|=((x>>i)&0x1)<<(p[i]);
		printf(" cipher output is - %llx \n",d);
		return (d);
	}
}

void key_generator(unsigned long long int *k,unsigned long long int *h)
{
	//parallel key generation algorithm

		h[0]=(k[1]>>(64-13) | k[0]<<13);			//circ-shift buy 13
		h[1]=(k[0]>>(64-13) | k[1]<<13);


		h[1]=((h[1]&0xffffffffffffff00) | s_block((h[1]&0x00000000000000ff),8));				//apply s-block for last 2 nibbles of key[1]
		h[1]=(h[1]&0x07ffffffffffffff | (((h[1]&0xf800000000000000)>>59)^(i&0x1f))<<59);		//add round counter in 5 MSB bits of key[1]
		printf("updated key output is - %llx  ",h[0]);
		printf("%llx\n",h[1]);
		
		// //update key and input to the parallel blocks
		k[0]=h[0];		
		k[1]=h[1];
}


int main(void)
{
	unsigned long long int a0=0x12345678 ,a1=0x90abcdef,z=0,d=0,m=0,c=0,x1=0,x2=0;
	unsigned long long int k[]={0x1111222233334444,0x1111222233334444};
	unsigned long long int h[]={0x0000000000000000,0x0000000000000000};
	unsigned int i;
	for(i=0;i<25;i++)
	{
		printf("\n***************output of %d round is*************\n",i);

		//implementation for X-ORs
		x1=(s_block((a0<<3)|(a0>>(32-3)),32)^a1);
		x2=(s_block((a0>>8)|(a0<<(32-8)),32)^x1);
		x2=x2^(k[1]&0x00000000ffffffff);

		// call key generator
		key_generator(k,h);

		//update a1,a0
		a1=p_layer(a0,32);
		a0=p_layer(x2,32);
	}
	return 0;
}	