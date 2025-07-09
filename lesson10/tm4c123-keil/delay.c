void delay(int volatile iter);

void delay(int volatile iter){
	while (iter > 0)
	{
		--iter;
	}
}