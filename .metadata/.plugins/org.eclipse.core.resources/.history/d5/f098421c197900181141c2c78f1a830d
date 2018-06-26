/*
 ============================================================================
 Name        : RemoteControlOpenwrt.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t event_lock;

int main(void) {
	pthread_mutex_init(&event_lock, NULL);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	pthread_mutex_destroy(&event_lock);
	return EXIT_SUCCESS;
}

