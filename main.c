#include <stdio.h>      //für printf()
#include <stdlib.h>
#include <sys/types.h>  //für open()
#include <sys/stat.h>   //für open()
#include <fcntl.h>      //für open()
#include <unistd.h>     //für close()
#include <time.h>  

int main(void)
{
	int num;
	clock_t last,cnt;
	num = 0;
	
	int Wr_Led(int n){
		char str[2];
		int wr;
		int hdl = open("/dev/lms_ui",O_RDWR);
		sprintf(str,"%d",n);
		wr = write(hdl,str,2);	
		printf("open %d.\nwrite %d\n", hdl, wr); //to check the returned value of open() and write()
		close(hdl);
		return(0);
	}

	last = clock()/CLOCKS_PER_SEC;
	while(1){
		cnt = clock()/CLOCKS_PER_SEC;
		if(cnt - last == 2){//2 seconds
			printf("%d\n", cnt);
			last = cnt;
			if(num == 9)
				num = 1;
			else
				num ++;
			Wr_Led(num);
			}
		if(cnt == 120)//set length of the loop
			break;
	
	}

	return(0);
}
