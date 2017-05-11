#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <jni.h>

#define IN   0
#define LOW  0

#define BUFFER_MAX 4

JNIEXPORT jint JNICALL Java_in_weargenius_gpio_DigitalInputPin_GPIORead
  (JNIEnv *env, jobject obj, jint pin)
{
#define VALUE_MAX 30
    char path[VALUE_MAX];
    char value_str[3];
    int fd;

    snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(path, O_RDONLY);
    if (-1 == fd) {
	fprintf(stderr, "Failed to open gpio value for reading!\n");
	return(-1);
    }

    if (-1 == read(fd, value_str, 3)) {
	fprintf(stderr, "Failed to read value!\n");
	return(-1);
    }

    close(fd);

    return(atoi(value_str));
}

JNIEXPORT jint JNICALL Java_in_weargenius_gpio_DigitalInputPin_GPIOUnexport
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