void delay(int iter);

void delay(int iter){
    int volatile counter;
    counter = 0;
	while (counter < iter)
	{
		++counter;
	}
}