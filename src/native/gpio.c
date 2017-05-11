#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <jni.h>

#define IN   0
#define LOW  0

JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIOExport
  (JNIEnv * env, jobject obj, jint pin)
{
	#define BUFFER_MAX 4
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;

    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (-1 == fd) {
	fprintf(stderr, "Failed to open export for writing!\n");
	return(-1);
    }

    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return(0);
}

JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIOUnexport
  (JNIEnv * env, jobject obj, jint pin)
{
    char buffer[BUFFER_MAX];
    ssize_t bytes_written;
    int fd;

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if (-1 == fd) {
	fprintf(stderr, "Failed to open unexport for writing!\n");
	return(-1);
    }

    bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
    write(fd, buffer, bytes_written);
    close(fd);
    return(0);
}

JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIODirection
  (JNIEnv * env, jobject obj, jint pin, jint dir)
{
    static const char s_directions_str[]  = "in\0out";

	#define DIRECTION_MAX 200
    char path[DIRECTION_MAX];
    int fd;
    snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(path, O_WRONLY);
    if (-1 == fd) {
	fprintf(stderr, "Failed to open gpio direction for writing!\n");
	return(-1);
    }

    if (-1 == write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3)) {
	fprintf(stderr, "Failed to set direction!\n");
	return(-1);
    }

    close(fd);
    return(0);
}
JNIEXPORT jboolean JNICALL Java_in_weargenius_gpio_gpio_isGPIOExported
  (JNIEnv *env, jobject obj, jint pin){

	#define DIRECTION_MAX 200
	
    char path[DIRECTION_MAX];
    int fd;
	// check for exported gpio directory
	snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
	fd = open(path, O_WRONLY);
    if (fd<0) {
		fprintf(stderr, "GPIO not Exported.\n");
		return (jboolean)0;
    }

    close(fd);
	// not exported
	return (jboolean)1;
	  
  }
