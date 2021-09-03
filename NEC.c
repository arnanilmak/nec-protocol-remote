

#define time (TMR1H<<8 | TMR1L)
//===========================================================
//Variable definition
//===========================================================
char ir_data,ir_data_cnt;
//===========================================================

//===========================================================
void interrupt ISR(void)
{
    static char ir_frame_start_flag=0,cnt1=0,cnt2=0,buf[4];
    
    if(INTF)
	{
    TMR1ON=1;
		if(time<2300)
		{
       if(ir_frame_start_flag)
       {
				if(time<1250)//0 state
				{
					buf[cnt1]&=~(1<<(cnt2%8));
				}
				else   //1 state
				{
					buf[cnt1]|=1<<(cnt2%8);
				}
				cnt2++;
				if(cnt2==32)
                {               
                    ir_frame_start_flag=0;
                    TMR1ON=0;
                    if((buf[0]|buf[1])==0xFF)
                    {
                        ir_data=buf[2];
					}
                 }
				else if((cnt2%8)==0){cnt1++;}
            }
		}
		else if(time<11500)//repeat
		{
            TMR1ON=0;
		}
		else if(time<14000)//start
		{
            ir_data_cnt=0;
			ir_frame_start_flag=1;
			cnt1=0;
            cnt2=0;
		}
		INTF = 0;
		TMR1H=0;
        TMR1L=0;
	}
   
}

void init_NEC(void)
{
	T1CON = 0B00110000;//timer freq 1MHZ
  TMR1L=0;
  TMR1H=0;//init timer
  INTCON = 0B11010000;  //pc1 external interrupt 
	INTEDG=0;//falling edge
}
//===========================================================
//Funtion name£ºmain
//parameters£ºÎÞ
//returned value£ºÎÞ
//===========================================================
main()
{
    
    init();
    while(1)
    {
	  }
}
//===========================================================
