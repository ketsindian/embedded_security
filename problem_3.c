#include <stdio.h>
/*

	64 bit IP					128 bit	key IP
	_|_								|
	|^|------last 64 bits-----------|
	 |								|
	 |								|
	S-BOX 						key	scheduler
	P-layer 						|
	 |								|
	 |								|
	64 bit IP 					128 bit key IP 
*/

	
unsigned long long int S[]={0x0,0x5,0x2,0xB,0x6,0x7,0xA,0x3,0x4,0x4,0xE,0x1,0x8,0x1,0x4,0x1};
//unsigned long long int S[]={0x6,0x3,0xA,0x5,0xC,0x8,0x1,0xB,0x0,0xD,0x9,0xE,0xF,0x2,0x7,0x4};
unsigned long long int p[]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};



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
		//printf(" cipher output is - %llx \n",d);
		return (d);
	}
	else if(size==32)
	{
		for(i=0;i<32;i++)
			d|=((x>>i)&0x1)<<(p[i]);
		//printf(" cipher output is - %llx \n",d);
		return (d);
	}
}



int main(void)
{
	unsigned long long int a=0x00000001,z=0,d=0,m=0,c=0;
	unsigned long long int k[]={0x1111222233334444,0x1111111155555555};
	unsigned long long int h[]={0x0000000000000000,0x0000000000000000};
	unsigned int i,j,x,mincount=10000,count=0,n;
	for(x=0;x<16;x++)
	{
		
	for(i=0;i<5;i++)
	{
		for(n=0;n<16;n++)
		{
			if(a==0x0000000f)
				a=0x00000001;
		d=(a<<(x*4));
			count=0;
		for(j=0;j<31;j++)
		{
			d=s_block(d,64);
			if(d)
				count++;
			d=p_layer(d,64);
		}
		if(mincount>count)
			mincount=count;
		printf("\n%d\t%d\n",mincount,count);

		// for(n=0;n<16;n++)
		// {

		// d=(a<<(x*4));
		// for(j=0;j<31;j++)
		// {
		// 	d=s_block(d,64);
		// 	if(d)
		// 		count++;
		// }
		
		// printf("\n%d\t%d\n",mincount,count);
		// a++;
		// }
		a++;
	}
	
		
	}
}
}	