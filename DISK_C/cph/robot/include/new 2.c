void tri(int x,int y,int di)
{
	switch(di)
	{
		case 1:
		{
			triangleleft(x,y,10,0);
			bar(x,y-5,x-20,y+5,0);
		}
		case 2:
		{
			triangleright(x,y,10,0);
			bar(x,y-5,x+20,y+5,0);
		}
		case 3:
		{
			triangle2(x,y,10,0);
			bar(x-5,y,x+5,y+20,0);
		}
		case 4:
		{
			triangledown(x,y,10,0);
			bar(x-5,y,x+5,y-20,0);
		}
	}
}