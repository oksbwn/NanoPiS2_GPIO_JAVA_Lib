/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class in_weargenius_gpio_gpio */

#ifndef _Included_in_weargenius_gpio_gpio
#define _Included_in_weargenius_gpio_gpio
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     in_weargenius_gpio_gpio
 * Method:    GPIOExport
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIOExport
  (JNIEnv *, jobject, jint);

/*
 * Class:     in_weargenius_gpio_gpio
 * Method:    GPIODirection
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIODirection
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     in_weargenius_gpio_gpio
 * Method:    isGPIOExported
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_in_weargenius_gpio_gpio_isGPIOExported
  (JNIEnv *, jobject, jint);

/*
 * Class:     in_weargenius_gpio_gpio
 * Method:    GPIOUnexport
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_in_weargenius_gpio_gpio_GPIOUnexport
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
