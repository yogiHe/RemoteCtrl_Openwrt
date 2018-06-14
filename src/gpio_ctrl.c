/*
 * gpio_ctrl.c
 *
 *  Created on: Jun 12, 2018
 *      Author: root
 */
//https://www.unwireddevices.com/wiki/index.php/Working_with_GPIOs_(C/C%2B%2B)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>

//

int gpio_set_direction(int gpio_num, char io_mode)
{
	char buf[100]={0};
	int fd;
	sprintf(buf,"/sys/class/gpio/gpio%d/direction",gpio_num);
	fd=open(buf, O_WRONLY);
	if(io_mode)
	{
		write(fd,"out",3);
	}
	else
		write(fd,"in",2);
	close(fd);
	return 0;
}

void gpio_set_value(int gpio_num,int gpio_value)
{
	char buf[100]={0};
	int fd;
	sprintf(buf,"/sys/class/gpio/gpio%d/value",gpio_num);
	fd=open(buf,O_WRONLY);
	sprintf(buf,"%d",gpio_value);
	write(fd,buf,1);
	close(fd);
}
/*fast write gpio level*/

#define GPIO_ADDR 0x18040000
#define GPIO_BLOCK 48 // memory block size

volatile unsigned long *gpioADDress;

int gpiosetup(viod)
{
	int m_mfd;
	if((m_mfd=open("/dev/mem", O_RDWR)) < 0)
	{
		return -1;
	}
	gpioADDress = (unsigned long *)mmap(NULL, GPIO_BLOCK, PROT_READ | PROT_WRITE, MAP_SHARED, m_mfd, GPIO_ADDR);
	close(m_mfd);
	if(gpioADDress == MAP_FAILED)
		return -2;
	return 0;

}

void gpioDirection(int gpio, int direction)
{
	unsigned long value = *(gpioADDress+0);
	if(direction ==1)
		value |= (1<<gpio);
	else
		value &= ~(1<<gpio);
	*(gpioADDress+0) = value;

}
int gpioRead(int gpio)
{
    unsigned long value = *(gpioADDress + 1);
    return (value & (1 << gpio));
}
