void delay(int iter);

void delay(int iter){
	int volatile counter = 0; //delay in any level of optimization
	while (counter < iter)
	{
		++counter;
	}
}