int funciondenteros(int intB)						//Prototipo de función
		{
		int intByL=0x000000ff&intB;
		int intByH=0x000000ff&(intB>>8);
		int tmpx=intByL;
		intByL=intByH;
		intByH=tmpx;
		return intByL|((intByH<<8)&0x0000ff00);
		}