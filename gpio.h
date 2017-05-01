/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class gpio */

#ifndef _Included_gpio
#define _Included_gpio
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     gpio
 * Method:    GPIOExport
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_gpio_GPIOExport
  (JNIEnv *, jobject, jint);

/*
 * Class:     gpio
 * Method:    GPIOUnexport
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_gpio_GPIOUnexport
  (JNIEnv *, jobject, jint);

/*
 * Class:     gpio
 * Method:    GPIODirection
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_gpio_GPIODirection
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     gpio
 * Method:    GPIORead
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_gpio_GPIORead
  (JNIEnv *, jobject, jint);

/*
 * Class:     gpio
 * Method:    isGPIOExported
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_gpio_isGPIOExported
  (JNIEnv *, jobject, jint);

/*
 * Class:     gpio
 * Method:    GPIOWrite
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_gpio_GPIOWrite
  (JNIEnv *, jobject, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
